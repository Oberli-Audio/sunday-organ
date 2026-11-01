#include "Widgets.h"

namespace sundayorgan::ui
{
namespace
{
constexpr float kCaptionH = 36.0f;   // label 14 + gap 4 + value 16 + 2

void hostMenu (juce::AudioProcessorEditor& editor, juce::RangedAudioParameter& param, const juce::MouseEvent& e)
{
    if (auto* host = editor.getHostContext())                      // null outside a host
        if (auto menu = host->getContextMenuForParameter (&param))
            menu->showNativeMenu (e.getEventRelativeTo (&editor).getPosition());
}

void common (juce::Component& c, juce::RangedAudioParameter& p, const juce::String& title)
{
    c.setTitle (title.isNotEmpty() ? title : p.getName (64));
    if (auto* withId = dynamic_cast<juce::AudioProcessorParameterWithID*> (&p))
        c.setHelpText (withId->getName (64));
    c.setMouseClickGrabsKeyboardFocus (false);
    c.setWantsKeyboardFocus (true);
}
} // namespace

juce::String shortLabel (const juce::RangedAudioParameter& p) { return p.getName (64); }

juce::String noteText (const juce::RangedAudioParameter& p, float v)
{
    if (v <= p.getNormalisableRange().start + 0.5f) return "Off";       // the lowest value means no split
    static const char* names[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    const int m = juce::roundToInt (v);
    return juce::String (names[m % 12]) + juce::String (m / 12 - 1);
}

void drawCaption (juce::Graphics& g, juce::Rectangle<float> area, const juce::String& label, const juce::String& value, bool tight)
{
    auto a = area;
    // footages are not words: no caps tracking, so 5 1/3' fits a drawbar's 37 px
    type::draw (g, label.toUpperCase(), a.removeFromTop (14.0f), tight ? type::font (type::Weight::semibold, 11.0f) : type::label(), Tokens::inkMuted, juce::Justification::centred);
    a.removeFromTop (4.0f);
    type::draw (g, value, a.removeFromTop (16.0f), type::value(), Tokens::ink, juce::Justification::centred);
}

//==============================================================================
ParamSlider::ParamSlider (juce::AudioProcessorEditor& e, juce::RangedAudioParameter& p, Kind k, juce::String l)
    : juce::Slider (k == Kind::knob ? RotaryHorizontalVerticalDrag : LinearVertical, NoTextBox),
      editor (e), param (p), kind (k), label (std::move (l)), attachment (p, *this)
{
    common (*this, p, {});
    setDoubleClickReturnValue (true, p.convertFrom0to1 (p.getDefaultValue()));
    setVelocityModeParameters (0.4, 1, 0.0, true, juce::ModifierKeys::shiftModifier);   // Shift: fine
    if (k == Kind::knob)
    {
        setRotaryParameters (juce::MathConstants<float>::pi * 1.25f, juce::MathConstants<float>::pi * 2.75f, true);
        setMouseDragSensitivity (200);
    }
    else
        setSliderSnapsToMousePosition (false);                    // a drag moves it, a click never jumps
    setTooltip (dynamic_cast<juce::AudioProcessorParameterWithID&> (p).getName (64));
    onValueChange = [this] { repaint(); };
}

juce::Rectangle<float> ParamSlider::controlArea() const
{
    auto b = getLocalBounds().toFloat();
    b.removeFromBottom (kCaptionH + 6.0f);
    if (kind == Kind::knob)
    {
        const float d = juce::jmin (b.getWidth(), b.getHeight());
        return { b.getCentreX() - d / 2, b.getY(), d, d };
    }
    return b;
}

void drawLinear (juce::Graphics& g, juce::Rectangle<float> area, float prop, bool wheel, bool focused)
{
    {
        const float trackW = wheel ? 8.0f : 4.0f, thumbD = 14.0f;
        const float top = area.getY() + thumbD / 2, bottom = area.getBottom() - thumbD / 2;
        const float cx = area.getCentreX();
        const auto track = juce::Rectangle<float> (cx - trackW / 2, top, trackW, bottom - top);
        g.setColour (wheel ? Tokens::surfaceSunken : Tokens::lineStrong);
        g.fillRoundedRectangle (track, trackW / 2);
        if (wheel) { g.setColour (Tokens::line); g.drawRoundedRectangle (track, trackW / 2, 1.0f); }
        if (! wheel)                                              // the drawbar's 9 stops
        {
            g.setColour (Tokens::line);
            for (int i = 0; i <= 8; ++i)
            {
                const float y = bottom - (bottom - top) * (float) i / 8.0f;
                g.fillRect (cx - 13.0f, y - 0.5f, 5.0f, 1.0f);
            }
        }
        const float y = bottom - (bottom - top) * prop;
        if (prop > 0.0f)
        {
            g.setColour (Tokens::accent);
            g.fillRoundedRectangle (juce::Rectangle<float> (cx - trackW / 2, y, trackW, bottom - y), trackW / 2);
        }
        const auto thumb = juce::Rectangle<float> (thumbD, thumbD).withCentre ({ cx, y });
        g.setColour (Tokens::surfacePanel);
        g.fillEllipse (thumb);
        g.setColour (Tokens::lineControl);
        g.drawEllipse (thumb.reduced (0.75f), 1.5f);
        g.setColour (prop > 0.0f ? Tokens::accent : Tokens::inkSubtle);
        g.fillRoundedRectangle (juce::Rectangle<float> (6.0f, 2.0f).withCentre ({ cx, y }), 1.0f);
        if (focused)
            drawFocusRing (g, thumb, thumbD / 2);
    }
}

void ParamSlider::paint (juce::Graphics& g)
{
    const float prop = (float) valueToProportionOfLength (getValue());
    const auto area = controlArea();
    if (kind == Kind::knob)
        drawKnob (g, area, prop, hasKeyboardFocus (false));
    else
        drawLinear (g, area, prop, kind == Kind::wheel, hasKeyboardFocus (false));
    auto caption = getLocalBounds().toFloat().removeFromBottom (kCaptionH);
    drawCaption (g, caption, label.isNotEmpty() ? label : shortLabel (param), param.getCurrentValueAsText(), kind == Kind::drawbar);
}

void ParamSlider::mouseDown (const juce::MouseEvent& e)
{
    if (e.mods.isPopupMenu()) { hostMenu (editor, param, e); return; }
    juce::Slider::mouseDown (e);
}

//==============================================================================
PillToggle::PillToggle (juce::AudioProcessorEditor& e, juce::RangedAudioParameter& p, juce::String caption)
    : juce::Button (caption), editor (e), param (p), attachment (p, *this)
{
    common (*this, p, caption);
    setClickingTogglesState (true);
    setTooltip (dynamic_cast<juce::AudioProcessorParameterWithID&> (p).getName (64));
}

void PillToggle::paintButton (juce::Graphics& g, bool over, bool)
{
    auto b = getLocalBounds().toFloat().reduced (0.5f);
    const float r = b.getHeight() / 2;
    g.setColour (over ? Tokens::surfacePanel : Tokens::ground);
    g.fillRoundedRectangle (b, r);
    g.setColour (Tokens::lineControl);
    g.drawRoundedRectangle (b, r, 1.0f);
    const auto led = juce::Rectangle<float> (8.0f, 8.0f).withCentre ({ b.getX() + 16.0f, b.getCentreY() });
    g.setColour (getToggleState() ? Tokens::accent : Tokens::lineStrong);
    g.fillEllipse (led);
    type::draw (g, getButtonText().toUpperCase(), b.withTrimmedLeft (28.0f).withTrimmedRight (12.0f), type::label(), Tokens::ink, juce::Justification::centredLeft);
    if (hasKeyboardFocus (false)) drawFocusRing (g, b, r);
}

void PillToggle::mouseDown (const juce::MouseEvent& e)
{
    if (e.mods.isPopupMenu()) { hostMenu (editor, param, e); return; }
    juce::Button::mouseDown (e);
}

//==============================================================================
Segmented::Segmented (juce::AudioProcessorEditor& e, juce::RangedAudioParameter& p, juce::StringArray l)
    : editor (e), param (p), labels (std::move (l)),
      attachment (p, [this] (float v) { index = juce::roundToInt (v); repaint(); })
{
    common (*this, p, {});
    setTooltip (dynamic_cast<juce::AudioProcessorParameterWithID&> (p).getName (64));
    attachment.sendInitialUpdate();
}

int Segmented::segmentAt (float x) const
{
    return juce::jlimit (0, labels.size() - 1, (int) (x / ((float) getWidth() / (float) labels.size())));
}

void Segmented::paint (juce::Graphics& g)
{
    auto b = getLocalBounds().toFloat().reduced (0.5f);
    g.setColour (Tokens::lineControl);
    g.drawRoundedRectangle (b, Tokens::radiusMd, 1.0f);
    const float w = b.getWidth() / (float) labels.size();
    for (int i = 0; i < labels.size(); ++i)
    {
        auto seg = juce::Rectangle<float> (b.getX() + w * (float) i, b.getY(), w, b.getHeight()).reduced (3.0f);
        if (i == index)
        {
            g.setColour (Tokens::accent);
            g.fillRoundedRectangle (seg, Tokens::radiusMd - 3.0f);
        }
        type::draw (g, labels[i], seg, type::control(), i == index ? Tokens::onAccent : Tokens::ink, juce::Justification::centred);
    }
    if (hasKeyboardFocus (false)) drawFocusRing (g, b, Tokens::radiusMd);
}

void Segmented::mouseDown (const juce::MouseEvent& e)
{
    if (e.mods.isPopupMenu()) { hostMenu (editor, param, e); return; }
    attachment.setValueAsCompleteGesture ((float) segmentAt ((float) e.x));
}

bool Segmented::keyPressed (const juce::KeyPress& k)
{
    const int d = k == juce::KeyPress::leftKey ? -1 : (k == juce::KeyPress::rightKey ? 1 : 0);
    if (d == 0) return false;
    attachment.setValueAsCompleteGesture ((float) juce::jlimit (0, labels.size() - 1, index + d));
    return true;
}

//==============================================================================
Stepper::Stepper (juce::AudioProcessorEditor& e, juce::RangedAudioParameter& p)
    : editor (e), param (p), attachment (p, [this] (float v) { value = v; repaint(); })
{
    common (*this, p, {});
    setTooltip (dynamic_cast<juce::AudioProcessorParameterWithID&> (p).getName (64));
    attachment.sendInitialUpdate();
}

void Stepper::paint (juce::Graphics& g)
{
    auto b = getLocalBounds().toFloat().reduced (0.5f);
    g.setColour (Tokens::surfaceSunken);
    g.fillRoundedRectangle (b, Tokens::radiusMd);
    g.setColour (Tokens::lineControl);
    g.drawRoundedRectangle (b, Tokens::radiusMd, 1.0f);
    const auto range = param.getNormalisableRange();
    const float side = b.getHeight();
    icons::draw (g, icons::Id::chevronLeft, b.withWidth (side).reduced (side * 0.25f), value > range.start ? Tokens::ink : Tokens::lineStrong);
    icons::draw (g, icons::Id::chevronRight, b.withLeft (b.getRight() - side).reduced (side * 0.25f), value < range.end ? Tokens::ink : Tokens::lineStrong);
    type::draw (g, noteText (param, value), b, type::value(), Tokens::ink, juce::Justification::centred);
    if (hasKeyboardFocus (false)) drawFocusRing (g, b, Tokens::radiusMd);
}

void Stepper::step (int delta)
{
    const auto range = param.getNormalisableRange();
    attachment.setValueAsCompleteGesture (juce::jlimit (range.start, range.end, value + (float) delta));
}

void Stepper::mouseDown (const juce::MouseEvent& e)
{
    if (e.mods.isPopupMenu()) { hostMenu (editor, param, e); return; }
    dragStart = value;
    if (e.x < getHeight()) step (-1);
    else if (e.x > getWidth() - getHeight()) step (1);
}

void Stepper::mouseDrag (const juce::MouseEvent& e)
{
    const float x = e.mouseDownPosition.x, h = (float) getHeight(), w = (float) getWidth();
    if (x < h || x > w - h) return;
    const auto range = param.getNormalisableRange();
    const float pxPerStep = e.mods.isShiftDown() ? 16.0f : 6.0f;
    attachment.setValueAsCompleteGesture (juce::jlimit (range.start, range.end, dragStart + (float) juce::roundToInt ((float) -e.getDistanceFromDragStartY() / pxPerStep)));
}

void Stepper::mouseDoubleClick (const juce::MouseEvent&)
{
    attachment.setValueAsCompleteGesture (param.convertFrom0to1 (param.getDefaultValue()));
}

bool Stepper::keyPressed (const juce::KeyPress& k)
{
    if (k == juce::KeyPress::leftKey || k == juce::KeyPress::downKey) { step (-1); return true; }
    if (k == juce::KeyPress::rightKey || k == juce::KeyPress::upKey) { step (1); return true; }
    return false;
}

//==============================================================================
RotorView::RotorView (juce::String n, bool h) : name (std::move (n)), horn (h)
{
    setTitle (name);
    setInterceptsMouseClicks (false, false);
}

void RotorView::set (float a, float r, float t)
{
    const bool textChanged = juce::roundToInt (r) != shownRpm || juce::roundToInt (t) != shownTarget;
    if (std::abs (a - angle) < 0.002f && ! textChanged) return;   // repaint only for visible steps
    angle = a; rpm = r; target = t;
    shownRpm = juce::roundToInt (r); shownTarget = juce::roundToInt (t);
    setDescription (juce::String (shownRpm) + " rpm");
    repaint();
}

void RotorView::paint (juce::Graphics& g)
{
    auto b = getLocalBounds().toFloat();
    const float d = juce::jmin (b.getWidth(), b.getHeight() - 52.0f);
    const auto well = juce::Rectangle<float> (d, d).withCentre ({ b.getCentreX(), b.getY() + d / 2 });
    g.setColour (Tokens::surfaceSunken);
    g.fillEllipse (well);
    g.setColour (Tokens::line);
    g.drawEllipse (well.reduced (0.5f), 1.0f);
    const auto c = well.getCentre();
    const float rad = d * 0.36f;
    const float th = juce::MathConstants<float>::twoPi * angle;
    const juce::Point<float> dir { std::sin (th), -std::cos (th) };
    juce::Path p;
    if (horn)
    {
        // the horn: a bar through the axis, its mouth (the end that sounds) in the accent
        p.startNewSubPath (c - dir * rad); p.lineTo (c);
        g.setColour (Tokens::inkSubtle);
        g.strokePath (p, juce::PathStrokeType (3.0f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
        juce::Path mouth; mouth.startNewSubPath (c); mouth.lineTo (c + dir * rad);
        g.setColour (Tokens::accent);
        g.strokePath (mouth, juce::PathStrokeType (6.0f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
    else
    {
        // the drum: a rotating half disc (the baffle's open side) in the accent
        p.addPieSegment (well.reduced (d * 0.18f), th - juce::MathConstants<float>::halfPi, th + juce::MathConstants<float>::halfPi, 0.0f);
        g.setColour (Tokens::accent.withAlpha (0.85f));
        g.fillPath (p);
    }
    g.setColour (Tokens::surfacePanel);
    g.fillEllipse (juce::Rectangle<float> (8.0f, 8.0f).withCentre (c));
    auto text = b.withTop (well.getBottom() + 6.0f);
    type::draw (g, name.toUpperCase(), text.removeFromTop (14.0f), type::label(), Tokens::inkMuted, juce::Justification::centred);
    text.removeFromTop (4.0f);
    type::draw (g, juce::String (shownRpm) + " rpm", text.removeFromTop (16.0f), type::value(), Tokens::ink, juce::Justification::centred);
    type::draw (g, "to " + juce::String (shownTarget), text.removeFromTop (14.0f), type::meta(), Tokens::inkSubtle, juce::Justification::centred);
}

//==============================================================================
void OutputMeter::set (float l, float r, bool limitingNow)
{
    auto toProp = [] (float rms) { const float db = juce::Decibels::gainToDecibels (rms, -100.0f); return juce::jlimit (0.0f, 1.0f, (db + 60.0f) / 60.0f); };
    const float nl = toProp (l), nr = toProp (r);
    const int newLimit = limitingNow ? 30 : juce::jmax (0, limitFrames - 1);   // 1 s at 30 frames
    if (std::abs (nl - level[0]) < 0.004f && std::abs (nr - level[1]) < 0.004f && (newLimit > 0) == (limitFrames > 0)) { limitFrames = newLimit; return; }
    level[0] = nl; level[1] = nr; limitFrames = newLimit;
    repaint();
}

void OutputMeter::paint (juce::Graphics& g)
{
    auto b = getLocalBounds().toFloat();
    auto led = b.removeFromBottom (18.0f);
    b.removeFromBottom (6.0f);
    const float w = 8.0f, gap = 6.0f;
    const float x0 = b.getCentreX() - w - gap / 2;
    const float hot = 54.0f / 60.0f;                             // -6 dBFS
    for (int ch = 0; ch < 2; ++ch)
    {
        auto well = juce::Rectangle<float> (x0 + (float) ch * (w + gap), b.getY(), w, b.getHeight());
        g.setColour (Tokens::surfaceSunken);
        g.fillRoundedRectangle (well, Tokens::radiusXs);
        g.setColour (Tokens::line);
        g.drawRoundedRectangle (well, Tokens::radiusXs, 1.0f);
        auto inner = well.reduced (2.0f);
        const float h = inner.getHeight();
        const float lv = level[ch] * h, hotY = hot * h;
        g.setColour (Tokens::meterLevel);
        g.fillRect (inner.withTop (inner.getBottom() - juce::jmin (lv, hotY)));
        if (lv > hotY)
        {
            g.setColour (Tokens::meterHot);
            g.fillRect (juce::Rectangle<float> (inner.getX(), inner.getBottom() - lv, inner.getWidth(), lv - hotY));
        }
    }
    const auto pill = juce::Rectangle<float> (std::ceil (type::width (type::label(), "LIMIT")) + 10.0f, 16.0f).withCentre (led.getCentre());
    if (limitFrames > 0)
    {
        g.setColour (Tokens::meterHot);
        g.fillRoundedRectangle (pill, Tokens::radiusXs);
    }
    else
    {
        g.setColour (Tokens::lineControl);
        g.drawRoundedRectangle (pill.reduced (0.5f), Tokens::radiusXs - 0.5f, 1.0f);
    }
    type::draw (g, "LIMIT", pill, type::label(), limitFrames > 0 ? Tokens::ground : Tokens::inkSubtle, juce::Justification::centred);
}
} // namespace sundayorgan::ui
