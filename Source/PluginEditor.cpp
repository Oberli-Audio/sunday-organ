#include "PluginEditor.h"
#include "Presets.h"

using namespace sundayorgan::ui;

namespace
{
juce::RangedAudioParameter& P (SundayOrganAudioProcessor& p, const char* id) { return *p.parameters().getParameter (id); }

juce::File settingsFile()
{
    return juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
        .getChildFile ("Oberli Audio").getChildFile ("Sunday Organ").getChildFile ("EditorSettings.xml");
}

float loadScale()
{
    if (auto xml = juce::parseXML (settingsFile()))
        return (float) juce::jlimit (0.75, 2.0, xml->getDoubleAttribute ("guiScale", 1.0));
    return 1.0f;
}

void saveScale (float s)
{
    juce::XmlElement xml ("EditorSettings");
    xml.setAttribute ("guiScale", s);
    settingsFile().getParentDirectory().createDirectory();
    xml.writeTo (settingsFile());
}

// one sentence of sonic effect plus range and default, from the parameter table (Params::tooltipFor)
juce::String tip (const char* id) { return Params::tooltipFor (id); }

/** A section: caps title, an optional note on the right, its area. */
struct Section
{
    juce::String title; juce::Rectangle<int> area; juce::String note; bool noteAccent = false;
    juce::Rectangle<int> titleRow() const { return area.withHeight (14); }   // the title left, the note right-aligned to its end
};
} // namespace

//==============================================================================
/** A header hit area: the header paints the icon or the preset name; focus shows the ink ring. */
class HitArea final : public juce::Button
{
public:
    HitArea() : juce::Button ({}) { setMouseClickGrabsKeyboardFocus (false); }
    void paintButton (juce::Graphics& g, bool, bool) override
    {
        if (hasKeyboardFocus (false)) drawFocusRing (g, getLocalBounds().toFloat().reduced (3.0f), Tokens::radiusMd);
    }
};

//==============================================================================
/** The on-screen mod wheel: not a parameter (a performance control, like CC1), drawn as a wheel. */
class ModWheel final : public juce::Slider
{
public:
    explicit ModWheel (SundayOrganAudioProcessor& p) : juce::Slider (LinearVertical, NoTextBox), processor (p)
    {
        setRange (0.0, 1.0);
        setSliderSnapsToMousePosition (false);
        setDoubleClickReturnValue (true, 0.0);
        setMouseClickGrabsKeyboardFocus (false);
        setWantsKeyboardFocus (true);
        setTitle ("Mod wheel");
        setTooltip ("Mod wheel, like CC1: above half the Leslie runs fast. 0 to 100 %.");
        onValueChange = [this] { if (! following) processor.setScreenModWheel ((float) getValue()); repaint(); };
    }
    void follow (float v) { if (isMouseButtonDown()) return; following = true; setValue (v, juce::dontSendNotification); following = false; repaint(); }
    void paint (juce::Graphics& g) override
    {
        auto b = getLocalBounds().toFloat();
        auto caption = b.removeFromBottom (36.0f);
        b.removeFromBottom (6.0f);
        drawLinear (g, b, (float) getValue(), true, hasKeyboardFocus (false));
        drawCaption (g, caption, "Mod", juce::String (juce::roundToInt (getValue() * 100.0)) + " %");
    }
private:
    SundayOrganAudioProcessor& processor;
    bool following = false;
};

//==============================================================================
class SundayOrganAudioProcessorEditor::Content final : public juce::Component
{
public:
    Content (SundayOrganAudioProcessorEditor& e, SundayOrganAudioProcessor& p)
        : editor (e), processor (p), modWheel (p),
          swell (e, P (p, Params::expression), ParamSlider::Kind::wheel, "Swell"),
          release (e, P (p, Params::pedalRelease), ParamSlider::Kind::knob, "Release"),
          split (e, P (p, Params::splitKey)), pedalSplit (e, P (p, Params::pedalSplit)),
          percOn (e, P (p, Params::percOn), "On"), percThird (e, P (p, Params::percThird), "Third"),
          percSlow (e, P (p, Params::percSlow), "Slow"), percSoft (e, P (p, Params::percSoft), "Soft"),
          vibrato (e, P (p, Params::vibratoMode), { "Off", "V1", "V2", "V3", "C1", "C2", "C3" }),
          vibLower (e, P (p, Params::vibratoLower), "Lower"),
          horn ("Horn", true), drum ("Drum", false),
          fast (e, P (p, Params::leslieFast), "Fast"), brake (e, P (p, Params::leslieBrake), "Brake"),
          leslieOn (e, P (p, Params::leslieOn), "Leslie"),
          spread (e, P (p, Params::micSpread), ParamSlider::Kind::knob, "Spread"),
          drive (e, P (p, Params::drive), ParamSlider::Kind::knob),
          click (e, P (p, Params::keyClick), ParamSlider::Kind::knob, "Click"),
          leak (e, P (p, Params::leakage), ParamSlider::Kind::knob, "Leakage"),
          output (e, P (p, Params::outGain), ParamSlider::Kind::knob, "Output")
    {
        static const char* footage[9] = { "16'", "5 1/3'", "8'", "4'", "2 2/3'", "2'", "1 3/5'", "1 1/3'", "1'" };
        static const char* up[9] = { Params::upperBar1, Params::upperBar2, Params::upperBar3, Params::upperBar4, Params::upperBar5,
                                     Params::upperBar6, Params::upperBar7, Params::upperBar8, Params::upperBar9 };
        static const char* lo[9] = { Params::lowerBar1, Params::lowerBar2, Params::lowerBar3, Params::lowerBar4, Params::lowerBar5,
                                     Params::lowerBar6, Params::lowerBar7, Params::lowerBar8, Params::lowerBar9 };
        for (int i = 0; i < 9; ++i)
        {
            upper.push_back (std::make_unique<ParamSlider> (e, P (p, up[i]), ParamSlider::Kind::drawbar, footage[i]));
            lower.push_back (std::make_unique<ParamSlider> (e, P (p, lo[i]), ParamSlider::Kind::drawbar, footage[i]));
        }
        ped16 = std::make_unique<ParamSlider> (e, P (p, Params::pedalBar16), ParamSlider::Kind::drawbar, "16'");
        ped8 = std::make_unique<ParamSlider> (e, P (p, Params::pedalBar8), ParamSlider::Kind::drawbar, "8'");

        for (auto* c : all())
            addAndMakeVisible (c);
        for (auto* c : { (juce::Component*) &horn, (juce::Component*) &drum })
            addAndMakeVisible (c);
        auto tips = [] (juce::Component& c, const char* id) { if (auto* t = dynamic_cast<juce::SettableTooltipClient*> (&c)) t->setTooltip (tip (id)); };
        for (int i = 0; i < 9; ++i) { tips (*upper[(size_t) i], up[i]); tips (*lower[(size_t) i], lo[i]); }
        tips (*ped16, Params::pedalBar16); tips (*ped8, Params::pedalBar8); tips (release, Params::pedalRelease);
        tips (swell, Params::expression); tips (split, Params::splitKey); tips (pedalSplit, Params::pedalSplit);
        tips (percOn, Params::percOn); tips (percThird, Params::percThird); tips (percSlow, Params::percSlow); tips (percSoft, Params::percSoft);
        tips (vibrato, Params::vibratoMode); tips (vibLower, Params::vibratoLower); tips (fast, Params::leslieFast);
        tips (brake, Params::leslieBrake); tips (leslieOn, Params::leslieOn); tips (spread, Params::micSpread);
        tips (drive, Params::drive); tips (click, Params::keyClick); tips (leak, Params::leakage); tips (output, Params::outGain);

        // header
        mark = logo::nameOnBone();
        for (auto* b : { &prevButton, &nextButton, &menuButton, &pillButton })
        {
            addAndMakeVisible (b);
            b->setMouseClickGrabsKeyboardFocus (false);
        }
        prevButton.setTitle ("Previous preset"); nextButton.setTitle ("Next preset");
        menuButton.setTitle ("Menu"); pillButton.setTitle ("Presets");
        prevButton.onClick = [this] { step (-1); };
        nextButton.onClick = [this] { step (1); };
        pillButton.onClick = [this] { editor.showDrawer (! drawer.isVisible()); };
        menuButton.onClick = [this] { editor.showMenu(); };
        addChildComponent (drawer);
        addChildComponent (about);
        drawer.content = this;
        about.content = this;
    }

    std::vector<juce::Component*> all()
    {
        std::vector<juce::Component*> v { &modWheel, &swell, &release, &split, &pedalSplit, &percOn, &percThird, &percSlow, &percSoft,
                                          &vibrato, &vibLower, &fast, &brake, &leslieOn, &spread, &drive, &click, &leak, &output, ped16.get(), ped8.get() };
        for (auto& u : upper) v.push_back (u.get());
        for (auto& l : lower) v.push_back (l.get());
        return v;
    }

    // ------------------------------------------------------------------ layout (px at 100 %)
    void resized() override
    {
        constexpr int top = 76, rowH = 186, row2 = 292;
        auto bars = [] (std::vector<std::unique_ptr<ParamSlider>>& v, int x0) { for (size_t i = 0; i < v.size(); ++i) v[i]->setBounds (x0 + (int) i * 37, top + 24, 37, rowH - 24); };
        modWheel.setBounds (28, top + 24, 40, rowH - 24);
        swell.setBounds (70, top + 24, 46, rowH - 24);
        bars (upper, 140);
        bars (lower, 498);
        ped16->setBounds (856, top + 24, 37, rowH - 24);
        ped8->setBounds (893, top + 24, 37, rowH - 24);
        release.setBounds (936, top + 46, 64, 90);
        split.setBounds (1024, top + 46, 120, 28);
        pedalSplit.setBounds (1024, top + 112, 120, 28);

        percOn.setBounds (28, row2 + 32, 76, 28);  percThird.setBounds (112, row2 + 32, 88, 28);
        percSlow.setBounds (28, row2 + 68, 76, 28); percSoft.setBounds (112, row2 + 68, 88, 28);
        vibrato.setBounds (236, row2 + 32, 266, 32);
        vibLower.setBounds (236, row2 + 76, 92, 28);
        horn.setBounds (536, row2 + 26, 80, 124);
        drum.setBounds (620, row2 + 26, 80, 124);
        fast.setBounds (712, row2 + 30, 96, 28); brake.setBounds (712, row2 + 66, 96, 28); leslieOn.setBounds (712, row2 + 102, 96, 28);
        spread.setBounds (814, row2 + 34, 62, 90);
        drive.setBounds (904, row2 + 30, 80, 106);                    // the hero knob (64)
        click.setBounds (990, row2 + 46, 72, 90);
        leak.setBounds (1066, row2 + 46, 76, 90);
        output.setBounds (1172, top + 22, 92, 106);                   // 64
        meterArea = { 1192, top + 144, 52, kHeight - 12 - (top + 144) };

        prevButton.setBounds (pillArea.getX(), pillArea.getY(), 28, pillArea.getHeight());
        nextButton.setBounds (pillArea.getRight() - 28, pillArea.getY(), 28, pillArea.getHeight());
        pillButton.setBounds (pillArea.reduced (28, 0));
        menuButton.setBounds (kWidth - 16 - 28, 10, 28, 28);
        drawer.setBounds (0, 48, 380, kHeight - 48);
        about.setBounds (0, 48, kWidth, kHeight - 48);
    }

    std::vector<Section> sections()
    {
        const int top = 76, row2 = 292;
        const auto fastNow = processor.leslieFastNow();
        const float hornRpm = processor.hornSpeedRpm();
        const float target = processor.parameters().getRawParameterValue (Params::leslieBrake)->load() >= 0.5f ? 0.0f : (fastNow ? 400.2f : 49.8f);
        juce::String status = juce::exactlyEqual (target, 0.0f) ? (hornRpm > 1.0f ? "Braking" : "Stopped") : (fastNow ? "Fast" : "Slow");
        const float drumRpm = processor.drumSpeedRpm(), drumTarget = juce::exactlyEqual (target, 0.0f) ? 0.0f : (fastNow ? 340.2f : 40.2f);
        if (target > 0.0f && (std::abs (hornRpm - target) > 4.0f || std::abs (drumRpm - drumTarget) > 4.0f))
            status << (drumRpm < drumTarget ? ", spinning up" : ", slowing down");
        const int splitNote = juce::roundToInt (processor.parameters().getRawParameterValue (Params::splitKey)->load());
        return { { "Wheels", { 28, top, 88, 186 }, {} },
                 { "Upper", { 140, top, 333, 186 }, splitNote > 36 ? "channel 1, from " + noteText (P (processor, Params::splitKey), (float) splitNote) + " up" : "channel 1" },
                 { "Lower", { 498, top, 333, 186 }, splitNote > 36 ? "channel 2, ch 1 below " + noteText (P (processor, Params::splitKey), (float) splitNote) : "channel 2" },
                 { "Pedals", { 856, top, 144, 186 }, "channel 3" },
                 { "Keyboard", { 1024, top, 120, 186 }, {} },
                 { "Percussion", { 28, row2, 170, 150 }, {} },
                 { "Vibrato", { 236, row2, 266, 150 }, {} },
                 { "Leslie", { 536, row2, 340, 150 }, status, true },
                 { "Voice", { 904, row2, 240, 150 }, {} } };
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (Tokens::ground);
        // header: the Oberli mark (name only), a divider, the plugin name; right: preset pill, version, menu
        auto header = getLocalBounds().removeFromTop (48).toFloat();
        g.setColour (Tokens::surfaceRaised);
        g.fillRect (header);
        g.setColour (Tokens::line);
        g.fillRect (header.removeFromBottom (1.0f));
        if (mark != nullptr)
            mark->drawWithin (g, { 16.0f, 15.0f, 70.0f, 18.0f }, juce::RectanglePlacement::xLeft | juce::RectanglePlacement::yMid, 1.0f);
        g.setColour (Tokens::line);
        g.fillRect (96.0f, 14.0f, 1.0f, 20.0f);
        type::draw (g, "Sunday Organ", { 110.0f, 14.0f, 200.0f, 20.0f }, type::pluginName(), Tokens::ink);
        const auto pill = pillArea.toFloat().reduced (0.5f);
        g.setColour (Tokens::lineControl);
        g.drawRoundedRectangle (pill, pill.getHeight() / 2, 1.0f);
        icons::draw (g, icons::Id::chevronLeft, prevButton.getBounds().toFloat().reduced (6.0f, 8.0f), Tokens::ink);
        icons::draw (g, icons::Id::chevronRight, nextButton.getBounds().toFloat().reduced (6.0f, 8.0f), Tokens::ink);
        const auto& bank = sundayorgan::Presets::factory();
        const auto name = juce::isPositiveAndBelow (processor.currentPreset, (int) bank.size()) ? bank[(size_t) processor.currentPreset].name : juce::String ("Init");
        auto nameBox = pillButton.getBounds().toFloat();
        const float nw = type::width (type::control(), name), sw = modified ? type::width (type::control(), " *") : 0.0f;
        const float x0 = nameBox.getCentreX() - (nw + sw) / 2;
        type::draw (g, name, nameBox.withX (x0).withWidth (nw + 1.0f), type::control(), Tokens::ink);
        if (modified)
            type::draw (g, " *", nameBox.withX (x0 + nw).withWidth (sw + 1.0f), type::control(), Tokens::accentInk);
        type::draw (g, JucePlugin_VersionString, { (float) pillArea.getRight() + 12.0f, 14.0f, 40.0f, 20.0f }, type::meta(), Tokens::inkSubtle);
        icons::draw (g, icons::Id::menu, menuButton.getBounds().toFloat().reduced (6.0f), Tokens::ink);

        // section titles, notes and the hairlines between groups
        for (const auto& s : sections())
        {
            const auto t = s.titleRow().toFloat();
            type::draw (g, s.title.toUpperCase(), t, type::section(), Tokens::inkMuted);
            if (s.note.isNotEmpty())
                type::draw (g, s.note, t, type::meta(), s.noteAccent ? Tokens::accentInk : Tokens::inkSubtle, juce::Justification::centredRight);
        }
        g.setColour (Tokens::line);
        for (int x : { 128, 486, 844, 1012 }) g.fillRect ((float) x, 80.0f, 1.0f, 176.0f);
        type::draw (g, "SPLIT", { 1024.0f, 76.0f + 26.0f, 120.0f, 14.0f }, type::label(), Tokens::inkMuted);
        type::draw (g, "PEDAL SPLIT", { 1024.0f, 76.0f + 92.0f, 120.0f, 14.0f }, type::label(), Tokens::inkMuted);
        for (int x : { 216, 520, 888 }) g.fillRect ((float) x, 296.0f, 1.0f, 140.0f);
        g.fillRect (28.0f, 274.0f, 1128.0f, 1.0f);                     // between the two rows
        g.fillRect (1158.0f, 64.0f, 1.0f, 394.0f);                     // the output column
        type::draw (g, "upper only, cuts 1'", { 28.0f, 402.0f, 170.0f, 14.0f }, type::meta(), Tokens::inkSubtle);
        meter.setBounds (meterArea);
    }

    void frame()
    {
        horn.set (processor.hornAngleTurns(), processor.hornSpeedRpm(), processor.parameters().getRawParameterValue (Params::leslieBrake)->load() >= 0.5f ? 0.0f : (processor.leslieFastNow() ? 400.0f : 50.0f));
        drum.set (processor.drumAngleTurns(), processor.drumSpeedRpm(), processor.parameters().getRawParameterValue (Params::leslieBrake)->load() >= 0.5f ? 0.0f : (processor.leslieFastNow() ? 340.0f : 40.0f));
        meter.set (processor.outputLevel (0), processor.outputLevel (1), processor.takeClip());
        modWheel.follow (processor.modWheelNow());
        const auto& bank = sundayorgan::Presets::factory();
        const bool m = juce::isPositiveAndBelow (processor.currentPreset, (int) bank.size())
                       && sundayorgan::Presets::differs (*bank[(size_t) processor.currentPreset].doc, processor.parameters());
        // the Leslie status: repaint the title row it is drawn in, to its right edge where the note
        // ends (a hand-typed region 6 px short left the last letter's stale end: "Fasn", F-16)
        const auto leslie = sections()[7];
        if (m != modified || leslie.note != lastStatus) { modified = m; lastStatus = leslie.note; repaint (0, 0, kWidth, 48); repaint (leslie.titleRow().expanded (2)); }
    }

    void step (int d)
    {
        const int n = (int) sundayorgan::Presets::factory().size();
        editor.loadFactory ((processor.currentPreset + d + n) % n);
    }

    // ------------------------------------------------------------------ the preset drawer
    struct Drawer final : public juce::Component
    {
        Content* content = nullptr;
        juce::TextEditor search;
        Drawer()
        {
            addAndMakeVisible (search);
            search.setTextToShowWhenEmpty ("Search presets", Tokens::inkSubtle);
            search.setFont (type::control());
            search.onTextChange = [this] { repaint(); };
            search.setTitle ("Search presets");
        }
        void resized() override { search.setBounds (16, 16, getWidth() - 32, 28); }
        struct Row { int index; juce::String text; bool heading; };
        std::vector<Row> rows() const
        {
            std::vector<Row> out;
            const auto& bank = sundayorgan::Presets::factory();
            for (const char* cat : { "Worship", "Gospel", "Jazz", "Ballad", "Rock", "Split" })
            {
                bool any = false;
                for (size_t i = 0; i < bank.size(); ++i)
                    if (bank[i].category == cat && bank[i].name.containsIgnoreCase (search.getText()))
                    {
                        if (! any) { out.push_back ({ -1, cat, true }); any = true; }
                        out.push_back ({ (int) i, bank[i].name, false });
                    }
            }
            return out;
        }
        /** A new column before a category heading whose rows would not fit below it. */
        bool breakBefore (const std::vector<Row>& r, size_t i, float y) const
        {
            if (! r[i].heading) return y + 24.0f > (float) getHeight() - 8.0f;
            size_t n = 1;
            while (i + n < r.size() && ! r[i + n].heading) ++n;
            return y > 56.0f && y + 24.0f * (float) n > (float) getHeight() - 8.0f;
        }
        void paint (juce::Graphics& g) override
        {
            drawPopCard (g, getLocalBounds().toFloat().withTrimmedTop (-1.0f), 0.0f, Tokens::surfaceRaised, Tokens::line);
            // two columns so the bank fits the panel's height without scrolling
            const auto r = rows();
            float x = 16.0f, y = 56.0f;
            const float colW = (float) (getWidth() - 40) / 2.0f;
            for (size_t i = 0; i < r.size(); ++i)
            {
                const auto& row = r[i];
                const float h = 24.0f;
                if (breakBefore (r, i, y)) { x += colW + 8.0f; y = 56.0f; }
                const auto box = juce::Rectangle<float> (x, y, colW, h);
                if (row.heading)
                    type::draw (g, row.text.toUpperCase(), box.withTrimmedTop (6.0f), type::section(), Tokens::inkMuted);
                else
                {
                    const bool current = content != nullptr && row.index == content->processor.currentPreset;
                    if (current) { g.setColour (Tokens::surfacePanel); g.fillRoundedRectangle (box, Tokens::radiusSm); }
                    type::draw (g, row.text, box.withTrimmedLeft (8.0f), type::control(), Tokens::ink);
                    if (current) { g.setColour (Tokens::accent); g.fillRoundedRectangle (box.withWidth (3.0f).reduced (0.0f, 5.0f), 1.5f); }
                }
                y += h;
            }
        }
        void mouseDown (const juce::MouseEvent& e) override
        {
            const auto r = rows();
            float x = 16.0f, y = 56.0f;
            const float colW = (float) (getWidth() - 40) / 2.0f;
            for (size_t i = 0; i < r.size(); ++i)
            {
                const auto& row = r[i];
                if (breakBefore (r, i, y)) { x += colW + 8.0f; y = 56.0f; }
                if (! row.heading && juce::Rectangle<float> (x, y, colW, 24.0f).contains (e.position) && content != nullptr)
                {
                    content->editor.loadFactory (row.index);                // one click loads; the drawer stays open
                    repaint();
                    return;
                }
                y += 24.0f;
            }
        }
    };

    // ------------------------------------------------------------------ About, the back of the panel (Bone)
    struct About final : public juce::Component
    {
        Content* content = nullptr;
        std::unique_ptr<juce::Drawable> lockup = logo::lockupOnCharcoal();
        void paint (juce::Graphics& g) override
        {
            g.fillAll (Tokens::Bone::ground);
            auto b = getLocalBounds().toFloat().reduced (48.0f, 32.0f);
            if (lockup != nullptr)
                lockup->drawWithin (g, b.removeFromTop (48.0f).withWidth (240.0f), juce::RectanglePlacement::xLeft | juce::RectanglePlacement::yMid, 1.0f);
            b.removeFromTop (24.0f);
            type::draw (g, "Sunday Organ", b.removeFromTop (28.0f), type::title(), Tokens::Bone::ink);
            type::draw (g, "Version " JucePlugin_VersionString ", sound version 1", b.removeFromTop (20.0f), type::small(), Tokens::Bone::inkMuted);
            b.removeFromTop (16.0f);
            for (const char* line : { "A tonewheel organ and a Leslie for church, gospel and worship bands.",
                                      "Channel 1 plays the upper manual, channel 2 the lower, channel 3 the pedals;",
                                      "the mod wheel speeds the Leslie up, CC11 is the swell pedal, CC64 holds the keys.",
                                      "", "Turn it and listen.", "",
                                      "Rubik by Hubert and Fischer (SIL Open Font License 1.1). Built with JUCE and the VST 3 SDK.",
                                      "Third-party notices: THIRD_PARTY_NOTICES.md beside the plugin." })
                type::draw (g, line, b.removeFromTop (23.0f), type::body(), Tokens::Bone::ink);
            type::draw (g, "Click anywhere to turn the panel back.", getLocalBounds().toFloat().removeFromBottom (40.0f).reduced (48.0f, 0.0f), type::meta(), Tokens::Bone::inkSubtle);
        }
        void mouseDown (const juce::MouseEvent&) override { if (content != nullptr) content->editor.showAbout (false); }
    };

    SundayOrganAudioProcessorEditor& editor;
    SundayOrganAudioProcessor& processor;
    ModWheel modWheel;
    ParamSlider swell;
    std::vector<std::unique_ptr<ParamSlider>> upper, lower;
    std::unique_ptr<ParamSlider> ped16, ped8;
    ParamSlider release;
    Stepper split, pedalSplit;
    PillToggle percOn, percThird, percSlow, percSoft;
    Segmented vibrato;
    PillToggle vibLower;
    RotorView horn, drum;
    PillToggle fast, brake, leslieOn;
    ParamSlider spread, drive, click, leak, output;
    OutputMeter meter;
    juce::Rectangle<int> meterArea;
    std::unique_ptr<juce::Drawable> mark;
    juce::Rectangle<int> pillArea { kWidth - 16 - 28 - 12 - 40 - 12 - 240, 10, 240, 28 };
    HitArea prevButton, nextButton, menuButton, pillButton;
    Drawer drawer;
    About about;
    bool modified = false;
    juce::String lastStatus;
};

//==============================================================================
SundayOrganAudioProcessorEditor::SundayOrganAudioProcessorEditor (SundayOrganAudioProcessor& p)
    : AudioProcessorEditor (&p), organ (p)
{
    setLookAndFeel (&lookAndFeel);
    content = std::make_unique<Content> (*this, p);
    addAndMakeVisible (*content);
    content->addAndMakeVisible (content->meter);
    content->setBounds (0, 0, kWidth, kHeight);
    setGuiScale (loadScale());
    startTimerHz (30);
}

SundayOrganAudioProcessorEditor::~SundayOrganAudioProcessorEditor()
{
    setLookAndFeel (nullptr);
}

void SundayOrganAudioProcessorEditor::setGuiScale (float s)
{
    scale = s;
    content->setTransform (juce::AffineTransform::scale (s));
    setSize (juce::roundToInt ((float) kWidth * s), juce::roundToInt ((float) kHeight * s));
}

void SundayOrganAudioProcessorEditor::paint (juce::Graphics& g) { g.fillAll (Tokens::ground); }
void SundayOrganAudioProcessorEditor::resized() {}

void SundayOrganAudioProcessorEditor::timerCallback() { content->frame(); }

bool SundayOrganAudioProcessorEditor::loadFactory (int index)
{
    const auto& bank = sundayorgan::Presets::factory();
    if (! juce::isPositiveAndBelow (index, (int) bank.size())) return false;
    if (! sundayorgan::Presets::apply (*bank[(size_t) index].doc, organ.parameters())) return false;
    organ.requestAllNotesOff();                                  // rule 16: a preset change releases every note
    organ.currentPreset = index;
    content->frame();
    content->repaint();
    return true;
}

void SundayOrganAudioProcessorEditor::showDrawer (bool on)
{
    content->drawer.setVisible (on);
    if (on) content->drawer.toFront (false);
}

void SundayOrganAudioProcessorEditor::showAbout (bool on)
{
    content->about.setVisible (on);
    if (on) { content->drawer.setVisible (false); content->about.toFront (false); }
}

void SundayOrganAudioProcessorEditor::showMenu()
{
    juce::PopupMenu m, scales;
    m.addItem ("Load preset...", [this] { showDrawer (true); });
    m.addItem ("Save preset...", [this]
    {
        auto folder = sundayorgan::Presets::userFolder();
        folder.createDirectory();
        auto file = folder.getNonexistentChildFile ("My preset", sundayorgan::State::kPresetExtension, false);
        if (auto doc = sundayorgan::State::presetXml (organ.parameters(), file.getFileNameWithoutExtension(), "You", "Yours", {}, false))
            doc->writeTo (file);
    });
    m.addSeparator();
    for (float s : { 0.75f, 1.0f, 1.5f, 2.0f })
        scales.addItem (juce::String (juce::roundToInt (s * 100.0f)) + " %", true, std::abs (s - scale) < 0.01f, [this, s] { setGuiScale (s); saveScale (s); });
    m.addSubMenu ("GUI scale", scales);
    m.addSeparator();
    m.addItem ("Report a problem...", [this]
    {
        juce::String d;
        d << "Sunday Organ " << JucePlugin_VersionString << ", sound version 1\n"
          << juce::SystemStats::getOperatingSystemName() << ", " << juce::SystemStats::getCpuModel() << "\n"
          << "Host: " << juce::PluginHostType().getHostDescription() << ", " << organ.getSampleRate() << " Hz\n"
          << "Preset: " << sundayorgan::Presets::factory()[(size_t) juce::jmax (0, organ.currentPreset)].name << "\n";
        juce::SystemClipboard::copyTextToClipboard (d);
    });
    m.addItem ("About Sunday Organ", [this] { showAbout (true); });
    m.showMenuAsync (juce::PopupMenu::Options().withTargetComponent (&content->menuButton).withParentComponent (content.get()));
}
