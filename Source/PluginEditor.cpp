#include "PluginEditor.h"
#include "Presets.h"

using namespace sundayorgan::ui;

namespace
{
juce::RangedAudioParameter& P (SundayOrganAudioProcessor& p, const char* id) { return *p.parameters().getParameter (id); }

namespace Presets = sundayorgan::Presets;
using PresetRef = SundayOrganAudioProcessor::PresetRef;

// machine-local (ship-bob locations.md: Application Support, not ~/Library itself): scale, snow, the last folder
juce::File settingsFile() { return Presets::settingsFolder().getChildFile ("EditorSettings.xml"); }

/** The name the header shows: the preset's, or what an unnamed sound is called. */
juce::String shownName (const PresetRef& ref) { return ref.name.isNotEmpty() ? ref.name : juce::String ("Unsaved sound"); }

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
        addAndMakeVisible (backdrop);
        backdrop.toBack();
        addChildComponent (snow);                      // above the controls, below the drawer and About; shown while it snows
        addChildComponent (drawer);
        addChildComponent (about);
        drawer.content = this;
        about.content = this;
        outside.content = this;
        addMouseListener (&outside, true);             // a click anywhere outside the drawer closes it
    }

    ~Content() override { removeMouseListener (&outside); }

    /** Closes the drawer on a click outside it, except on the header's preset pill and arrows
        (they step and toggle it) and while the drawer's own menu is open. The click still does
        what it does where it lands: nothing is swallowed. */
    struct OutsideClick final : public juce::MouseListener
    {
        Content* content = nullptr;
        void mouseDown (const juce::MouseEvent& e) override
        {
            auto& c = *content;
            auto* hit = e.eventComponent;
            if (! c.drawer.isVisible() || c.drawer.menuOpen || hit == nullptr) return;
            if (hit == &c.drawer || c.drawer.isParentOf (hit)) return;
            for (auto* keep : { (juce::Component*) &c.pillButton, (juce::Component*) &c.prevButton, (juce::Component*) &c.nextButton })
                if (hit == keep) return;
            c.editor.showDrawer (false);
        }
    };

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
        snow.setBounds (0, 0, kWidth, kHeight);
        backdrop.setBounds (0, 0, kWidth, kHeight);
        meter.setBounds (meterArea);
        snow.setLedge (274.0f, 28.0f, 1156.0f);                        // the hairline between the two rows
    }

    /** The panel itself - header, section titles and notes, hairlines - as the bottom child, redrawn
        where frame() says something it shows has changed. (F-20 gave it and every control a cached
        image; in the real macOS renderer every copy of a cached image is a pixel-format conversion, so
        F-21 took the caches out again and moved the snow onto its own layer instead.) */
    struct Backdrop final : public juce::Component
    {
        Content& owner;
        explicit Backdrop (Content& o) : owner (o)
        {
            setInterceptsMouseClicks (false, false);
            setAccessible (false);
            setOpaque (true);
        }
        void paint (juce::Graphics& g) override { owner.paintPanel (g); }
    };

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

    void paint (juce::Graphics&) override {}                           // the backdrop paints the panel

    void paintPanel (juce::Graphics& g)
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
        const auto ref = processor.currentPreset();
        const auto name = shownName (ref);
        auto nameBox = pillButton.getBounds().toFloat();
        const float nw = type::width (type::control(), name), sw = modified ? type::width (type::control(), " *") : 0.0f;
        const float x0 = nameBox.getCentreX() - (nw + sw) / 2;
        type::draw (g, name, nameBox.withX (x0).withWidth (nw + 1.0f), type::control(), ref.name.isNotEmpty() ? Tokens::ink : Tokens::inkMuted);
        if (notice.isNotEmpty())                                       // what was saved, shared or refused
            type::draw (g, notice, noticeBox().toFloat(), type::meta(), Tokens::inkMuted, juce::Justification::centredRight);
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
    }

    void frame()
    {
        horn.set (processor.hornAngleTurns(), processor.hornSpeedRpm(), processor.parameters().getRawParameterValue (Params::leslieBrake)->load() >= 0.5f ? 0.0f : (processor.leslieFastNow() ? 400.0f : 50.0f));
        drum.set (processor.drumAngleTurns(), processor.drumSpeedRpm(), processor.parameters().getRawParameterValue (Params::leslieBrake)->load() >= 0.5f ? 0.0f : (processor.leslieFastNow() ? 340.0f : 40.0f));
        meter.set (processor.outputLevel (0), processor.outputLevel (1), processor.takeLimiting());
        modWheel.follow (processor.modWheelNow());
        const auto ref = processor.currentPreset();
        const bool m = ref.doc != nullptr && Presets::differs (*ref.doc, processor.parameters());
        // the Leslie status: repaint the title row it is drawn in, to its right edge where the note
        // ends (a hand-typed region 6 px short left the last letter's stale end: "Fasn", F-16)
        if (m != modified || ref.name != lastName || ref.source != lastSource)
        {
            if (ref.source != lastSource || m != modified) drawer.repaint();
            modified = m; lastName = ref.name; lastSource = ref.source;
            backdrop.repaint (0, 0, kWidth, 48);
        }
        // every section note (the Leslie status, the split notes): redraw the title rows that changed
        const auto secs = sections();
        if (lastNotes.size() != secs.size()) lastNotes.resize (secs.size());
        for (size_t i = 0; i < secs.size(); ++i)
            if (secs[i].note != lastNotes[i])
            {
                lastNotes[i] = secs[i].note;
                backdrop.repaint (secs[i].titleRow().expanded (2));     // to the row's end (F-16)
            }
        if (noticeFrames > 0 && --noticeFrames == 0) { notice.clear(); backdrop.repaint (noticeBox()); }
        drawer.frame();

        // snow while a Jingle Jam preset is loaded: the horn's speed is the wind, its centre the whirl.
        // Leaving, it fades and melts in about a second, then the layer hides and costs nothing (F-20).
        const bool falling = editor.snowOn && ref.category == Presets::kSeasonalCategory && ! about.isVisible();
        snowActive = snowActive || falling;
        if (! snowActive) return;
        snow.step (falling, processor.hornSpeedRpm() / 400.0f, horn.getBounds().toFloat().getCentre());
        // on its own layer where there is one (macOS, on screen: F-21), so the panel is never redrawn
        // for a flake; drawn by the editor otherwise (the snapshot tool, Windows)
        auto& overlay = editor.snowOverlay;
        if (! overlay.attached() && editor.isShowing() && editor.getPeer() != nullptr)
            overlay.attach (editor);
        if (overlay.attached())
        {
            if (snow.isVisible()) snow.setVisible (false);
            const auto frameInPeer = editor.getPeer()->getComponent().getLocalArea (&editor, editor.getLocalBounds());
            const auto exclude = drawer.isVisible() ? drawer.getBounds().toFloat() : juce::Rectangle<float>();
            if (about.isVisible()) overlay.hide();
            else overlay.show (snow, editor.scale, frameInPeer, exclude);
        }
        else if (! snow.isVisible() && ! about.isVisible())
            snow.setVisible (true);
        if (about.isVisible()) snow.setVisible (false);
        if (! falling && snow.idle())
        {
            snowActive = false;
            snow.setVisible (false);
            overlay.hide();
        }
    }

    /** Redraws the panel's image (after a load: the header and every note). */
    void refreshPanel() { backdrop.repaint(); }

    void notify (const juce::String& text)
    {
        notice = text;
        noticeFrames = 30 * 5;                                         // five seconds
        backdrop.repaint (noticeBox());
    }

    /** The header's free space between the plugin name and the preset pill. */
    juce::Rectangle<int> noticeBox() const { return { 320, 14, pillArea.getX() - 16 - 320, 20 }; }

    /** Every preset the arrows step through, in the drawer's order: the bank, then the player's own. */
    struct Stop { int factoryIndex; juce::File file; juce::String source; };
    std::vector<Stop> stops() const
    {
        std::vector<Stop> out;
        const auto& bank = Presets::factory();
        for (size_t i = 0; i < bank.size(); ++i) out.push_back ({ (int) i, {}, "factory:" + bank[i].slug });
        for (const auto& u : Presets::userPresets()) out.push_back ({ -1, u.file, "user:" + u.file.getFileName() });
        return out;
    }

    void step (int d)
    {
        const auto list = stops();
        if (list.empty()) return;
        const auto source = processor.currentPreset().source;
        int at = -1;
        for (size_t i = 0; i < list.size(); ++i) if (list[i].source == source) at = (int) i;
        const int n = (int) list.size();
        const int next = at < 0 ? (d > 0 ? 0 : n - 1) : (at + d + n) % n;
        const auto& s = list[(size_t) next];
        if (s.factoryIndex >= 0) editor.loadFactory (s.factoryIndex);
        else editor.loadUser (s.file);
    }

    // ------------------------------------------------------------------ the preset drawer
    /*  The factory bank by category in two columns and, under the first, the player's own presets
        (USER) with "Save current sound" (Björn, 2026-11-15: saving lives here, with the presets).
        The list scrolls when it outgrows the panel. One click loads and the drawer stays open;
        a double-click loads and closes it; so do the close button, Escape and any click outside.
        Saving and renaming name the preset in place (24 characters, any language); a name that
        exists asks for a second Enter before it is replaced. A user preset's right-click menu
        renames, shares or deletes it (to the Trash; the sound stays, the name goes). */
    struct Drawer final : public juce::Component
    {
        Content* content = nullptr;
        juce::TextEditor search, nameField;
        HitArea closeButton;
        std::vector<Presets::UserPreset> users;
        float scroll = 0.0f;
        enum class Edit { none, save, rename } edit = Edit::none;
        int editIndex = -1;
        bool confirmReplace = false, menuOpen = false, noteWarn = false;
        juce::String note;
        int noteFrames = 0;
        static constexpr float listTop = 52.0f, rowH = 24.0f;

        Drawer()
        {
            addAndMakeVisible (search);
            search.setTextToShowWhenEmpty ("Search presets", Tokens::inkSubtle);
            search.setFont (type::control());
            search.onTextChange = [this] { scroll = 0.0f; cancelEdit(); repaint(); };
            search.onEscapeKey = [this] { if (search.getText().isNotEmpty()) search.clear(); else close(); };
            search.setTitle ("Search presets");
            addAndMakeVisible (closeButton);
            closeButton.setTitle ("Close presets");
            closeButton.setTooltip ("Close the presets (Esc)");
            closeButton.onClick = [this] { close(); };
            addChildComponent (nameField);
            nameField.setFont (type::control());
            nameField.setInputRestrictions (Presets::kNameMax);
            nameField.setTitle ("Preset name");
            nameField.onReturnKey = [this] { commit(); };
            nameField.onEscapeKey = [this] { cancelEdit(); };
            nameField.onFocusLost = [this] { cancelEdit(); };
            nameField.onTextChange = [this] { if (confirmReplace) { confirmReplace = false; setNote ({}, false); } };
            setWantsKeyboardFocus (true);
            setMouseClickGrabsKeyboardFocus (false);
        }

        void resized() override
        {
            search.setBounds (16, 16, getWidth() - 32 - 36, 28);
            closeButton.setBounds (getWidth() - 16 - 28, 16, 28, 28);
        }

        void close() { cancelEdit(); if (content != nullptr) content->editor.showDrawer (false); }
        void refresh() { users = Presets::userPresets(); scroll = juce::jlimit (0.0f, maxScroll(), scroll); repaint(); }
        void frame() { if (noteFrames > 0 && --noteFrames == 0) { note.clear(); repaint(); } }
        void setNote (const juce::String& text, bool warn) { note = text; noteWarn = warn; noteFrames = text.isNotEmpty() ? 30 * 5 : 0; repaint(); }

        struct Item { enum class Kind { heading, factory, user, save } kind; int index; juce::String text; juce::Rectangle<float> box; };

        std::vector<Item> layout() const
        {
            std::vector<Item> out;
            const auto& bank = Presets::factory();
            const auto query = search.getText().trim();
            const float colW = (float) (getWidth() - 40) / 2.0f;
            const float xs[2] = { 16.0f, 16.0f + colW + 8.0f };
            float ys[2] = { listTop, listTop };
            auto add = [&] (int c, Item::Kind k, int index, const juce::String& text)
            {
                out.push_back ({ k, index, text, { xs[c], ys[c], colW, rowH } });
                ys[c] += rowH;
            };
            const std::vector<juce::String> columns[2] = { { "Worship", "Gospel", "Jazz" },
                                                           { "Ballad", "Rock", "Split", Presets::kSeasonalCategory } };
            for (int c = 0; c < 2; ++c)
                for (const auto& cat : columns[c])
                {
                    bool any = false;
                    for (size_t i = 0; i < bank.size(); ++i)
                        if (bank[i].category == cat && bank[i].name.containsIgnoreCase (query))
                        {
                            if (! any) { add (c, Item::Kind::heading, -1, cat); any = true; }
                            add (c, Item::Kind::factory, (int) i, bank[i].name);
                        }
                }
            add (0, Item::Kind::heading, -1, "User");
            add (0, Item::Kind::save, -1, "Save current sound");
            for (size_t i = 0; i < users.size(); ++i)
                if (users[i].name.containsIgnoreCase (query))
                    add (0, Item::Kind::user, (int) i, users[i].name);
            return out;
        }

        float contentBottom() const
        {
            float b = listTop;
            for (const auto& it : layout()) b = std::max (b, it.box.getBottom());
            return b;
        }
        float viewBottom() const { return (float) getHeight() - 8.0f; }
        float maxScroll() const { return std::max (0.0f, contentBottom() - viewBottom()); }

        bool isCurrent (const Item& it, const PresetRef& ref) const
        {
            if (it.kind == Item::Kind::factory) return ref.source == "factory:" + Presets::factory()[(size_t) it.index].slug;
            if (it.kind == Item::Kind::user) return ref.source == "user:" + users[(size_t) it.index].file.getFileName();
            return false;
        }

        void paint (juce::Graphics& g) override
        {
            drawPopCard (g, getLocalBounds().toFloat().withTrimmedTop (-1.0f), 0.0f, Tokens::surfaceRaised, Tokens::line);
            icons::draw (g, icons::Id::close, closeButton.getBounds().toFloat().reduced (7.0f), Tokens::ink);
            const auto ref = content != nullptr ? content->processor.currentPreset() : PresetRef {};
            const bool edited = content != nullptr && content->modified;
            juce::Graphics::ScopedSaveState clip (g);
            g.reduceClipRegion (juce::Rectangle<float> (0.0f, listTop, (float) getWidth(), viewBottom() - listTop).toNearestInt());
            for (const auto& it : layout())
            {
                const auto box = it.box.translated (0.0f, -scroll);
                if (box.getBottom() < listTop || box.getY() > viewBottom()) continue;
                switch (it.kind)
                {
                    case Item::Kind::heading:
                    {
                        type::draw (g, it.text.toUpperCase(), box.withTrimmedTop (6.0f), type::section(), Tokens::inkMuted);
                        if (it.text == "User" && note.isNotEmpty())
                        {
                            const auto row = box.withTrimmedTop (6.0f).withRight ((float) getWidth() - 16.0f).withLeft (box.getX() + 44.0f);
                            type::draw (g, note, row, type::meta(), noteWarn ? Tokens::accentInk : Tokens::inkSubtle, juce::Justification::centredLeft);
                        }
                        break;
                    }
                    case Item::Kind::save:
                        if (edit == Edit::save) break;                  // the name field sits here
                        icons::draw (g, icons::Id::save, box.withWidth (16.0f).withSizeKeepingCentre (14.0f, 14.0f).translated (8.0f, 0.0f), Tokens::ink);
                        type::draw (g, it.text, box.withTrimmedLeft (30.0f), type::control(), Tokens::ink);
                        break;
                    case Item::Kind::factory:
                    case Item::Kind::user:
                    {
                        if (it.kind == Item::Kind::user && edit == Edit::rename && it.index == editIndex) break;
                        const bool current = isCurrent (it, ref);
                        if (current) { g.setColour (Tokens::surfacePanel); g.fillRoundedRectangle (box, Tokens::radiusSm); }
                        type::draw (g, it.text, box.withTrimmedLeft (8.0f), type::control(), Tokens::ink);
                        // the loaded preset's bar; at half strength once its sound was changed (compare, not track)
                        if (current) { g.setColour (Tokens::accent.withAlpha (edited ? 0.5f : 1.0f)); g.fillRoundedRectangle (box.withWidth (3.0f).reduced (0.0f, 5.0f), 1.5f); }
                        break;
                    }
                }
            }
            if (const float ms = maxScroll(); ms > 0.0f)                // where in the list you are
            {
                const float track = viewBottom() - listTop, thumb = std::max (24.0f, track * track / (track + ms));
                const float y = listTop + (track - thumb) * (scroll / ms);
                g.setColour (Tokens::lineStrong);
                g.fillRoundedRectangle ((float) getWidth() - 7.0f, y, 3.0f, thumb, 1.5f);
            }
        }

        const Item* hit (const std::vector<Item>& items, juce::Point<float> p) const
        {
            if (p.y < listTop || p.y > viewBottom()) return nullptr;
            for (const auto& it : items)
                if (it.kind != Item::Kind::heading && it.box.translated (0.0f, -scroll).contains (p)) return &it;
            return nullptr;
        }

        void mouseDown (const juce::MouseEvent& e) override
        {
            if (content == nullptr) return;
            const auto items = layout();
            const auto* it = hit (items, e.position);
            if (it == nullptr) return;
            switch (it->kind)
            {
                case Item::Kind::factory:
                    if (! e.mods.isPopupMenu()) content->editor.loadFactory (it->index);   // one click loads; the drawer stays open
                    break;
                case Item::Kind::user:
                    if (e.mods.isPopupMenu()) userMenu (it->index);
                    else content->editor.loadUser (users[(size_t) it->index].file);
                    break;
                case Item::Kind::save: beginSave(); break;
                case Item::Kind::heading: break;
            }
            repaint();
        }

        void mouseDoubleClick (const juce::MouseEvent& e) override
        {
            const auto items = layout();
            if (const auto* it = hit (items, e.position); it != nullptr && (it->kind == Item::Kind::factory || it->kind == Item::Kind::user))
                close();                                                // the first click loaded it
        }

        void mouseWheelMove (const juce::MouseEvent&, const juce::MouseWheelDetails& w) override
        {
            const float before = scroll;
            scroll = juce::jlimit (0.0f, maxScroll(), scroll - w.deltaY * 224.0f);   // JUCE Viewport's step
            if (! juce::exactlyEqual (before, scroll)) { cancelEdit(); repaint(); }
        }

        bool keyPressed (const juce::KeyPress& k) override
        {
            if (k == juce::KeyPress::escapeKey) { close(); return true; }
            return false;                                               // everything else reaches the host
        }

        /** Scrolls so the row for `file` (a user preset) or the save row is in view. */
        void reveal (const juce::File& file)
        {
            for (const auto& it : layout())
                if ((file == juce::File() && it.kind == Item::Kind::save)
                    || (it.kind == Item::Kind::user && users[(size_t) it.index].file == file))
                {
                    if (it.box.getBottom() - scroll > viewBottom()) scroll = it.box.getBottom() - viewBottom();
                    if (it.box.getY() - scroll < listTop) scroll = it.box.getY() - listTop;
                    scroll = juce::jlimit (0.0f, maxScroll(), scroll);
                }
            repaint();
        }

        void placeField (Item::Kind kind, int index)
        {
            for (const auto& it : layout())
                if (it.kind == kind && (kind == Item::Kind::save || it.index == index))
                    nameField.setBounds (it.box.translated (0.0f, -scroll).reduced (0.0f, 1.0f).toNearestInt());
        }

        void beginSave()
        {
            if (content == nullptr) return;
            edit = Edit::save; editIndex = -1; confirmReplace = false;
            reveal ({});
            const auto ref = content->processor.currentPreset();
            nameField.setText (ref.name.isNotEmpty() ? ref.name : juce::String ("My sound"), false);
            placeField (Item::Kind::save, -1);
            setNote ("Enter saves, Esc cancels", false);
            nameField.setVisible (true);
            nameField.grabKeyboardFocus();
            nameField.selectAll();
            repaint();
        }

        void beginRename (int index)
        {
            edit = Edit::rename; editIndex = index; confirmReplace = false;
            reveal (users[(size_t) index].file);
            nameField.setText (users[(size_t) index].name, false);
            placeField (Item::Kind::user, index);
            setNote ("Enter renames, Esc cancels", false);
            nameField.setVisible (true);
            nameField.grabKeyboardFocus();
            nameField.selectAll();
            repaint();
        }

        void cancelEdit()
        {
            if (edit == Edit::none) return;
            edit = Edit::none; editIndex = -1; confirmReplace = false;
            nameField.setVisible (false);
            if (! noteWarn) setNote ({}, false);
            repaint();
        }

        void finishEdit (const juce::File& file, const juce::String& done)
        {
            edit = Edit::none; editIndex = -1; confirmReplace = false;
            nameField.setVisible (false);
            refresh();
            reveal (file);
            setNote (done, false);
        }

        void commit()
        {
            if (content == nullptr || edit == Edit::none) return;
            const auto name = Presets::cleanName (nameField.getText());
            if (name.isEmpty()) { setNote ("Give the preset a name.", true); return; }
            juce::String error;
            if (edit == Edit::save)
            {
                if (const auto* same = Presets::findUser (users, name); same != nullptr && ! confirmReplace)
                {
                    confirmReplace = true;
                    setNote ("Enter again replaces " + same->name, true);
                    return;
                }
                const auto file = Presets::saveUser (content->processor.parameters(), name, error);
                if (file == juce::File()) { setNote (error, true); return; }
                content->editor.adoptUser (file);                       // the saved preset is now the loaded one
                finishEdit (file, "Saved");
            }
            else
            {
                const auto old = users[(size_t) editIndex];
                const auto file = Presets::renameUser (old, name, error);
                if (file == juce::File()) { setNote (error, true); return; }
                if (content->processor.currentPreset().source == "user:" + old.file.getFileName())
                    content->editor.adoptUser (file);                   // the loaded preset keeps up with its name
                finishEdit (file, "Renamed");
            }
        }

        void userMenu (int index)
        {
            juce::PopupMenu m;
            m.addItem ("Rename", [this, index] { menuOpen = false; beginRename (index); });
            m.addItem ("Share...", [this, index]
            {
                menuOpen = false;
                if (content != nullptr) content->editor.shareFile (users[(size_t) index].file);
            });
            m.addSeparator();
            m.addItem ("Delete (to the Trash)", [this, index]
            {
                menuOpen = false;
                if (content == nullptr) return;
                const auto p = users[(size_t) index];
                if (! Presets::removeUser (p)) { setNote ("Could not delete " + p.file.getFileName(), true); return; }
                if (content->processor.currentPreset().source == "user:" + p.file.getFileName())
                    content->processor.setCurrentPreset ({});           // the sound stays, its name goes
                refresh();
                setNote ("Moved " + p.name + " to the Trash", false);
            });
            menuOpen = true;
            m.showMenuAsync (juce::PopupMenu::Options().withParentComponent (content).withMousePosition(),
                             [this] (int) { juce::MessageManager::callAsync ([safe = juce::Component::SafePointer<Drawer> (this)] { if (safe) safe->menuOpen = false; }); });
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
    Backdrop backdrop { *this };
    sundayorgan::ui::Snowfall snow;
    Drawer drawer;
    About about;
    OutsideClick outside;
    bool modified = false, snowActive = false;
    juce::String lastName, lastSource, notice;
    std::vector<juce::String> lastNotes;
    int noticeFrames = 0;
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
    float s = 1.0f;
    if (auto xml = juce::parseXML (settingsFile()))
    {
        s = (float) juce::jlimit (0.75, 2.0, xml->getDoubleAttribute ("guiScale", 1.0));
        snowOn = xml->getBoolAttribute ("snow", true);
        lastFolder = juce::File (xml->getStringAttribute ("lastFolder"));
    }
    setGuiScale (s);
    startTimerHz (30);
}

SundayOrganAudioProcessorEditor::~SundayOrganAudioProcessorEditor()
{
    snowOverlay.detach();
    setLookAndFeel (nullptr);
}

void SundayOrganAudioProcessorEditor::saveSettings() const
{
    juce::XmlElement xml ("EditorSettings");
    xml.setAttribute ("guiScale", scale);
    xml.setAttribute ("snow", snowOn);
    if (lastFolder.isDirectory()) xml.setAttribute ("lastFolder", lastFolder.getFullPathName());
    settingsFile().getParentDirectory().createDirectory();
    xml.writeTo (settingsFile());
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
bool SundayOrganAudioProcessorEditor::snowShowing() const { return content->snowActive; }
bool SundayOrganAudioProcessorEditor::snowOnOwnLayer() const { return snowOverlay.attached(); }
int SundayOrganAudioProcessorEditor::snowEditorRepaints() const { return content->snow.editorRepaints(); }

void SundayOrganAudioProcessorEditor::parentHierarchyChanged()
{
    snowOverlay.detach();                                        // a new native parent: attach again on the next frame
}
std::vector<juce::Rectangle<int>> SundayOrganAudioProcessorEditor::snowRepaints() const
{
    std::vector<juce::Rectangle<int>> out;
    for (auto r : content->snow.lastRepaints())
        out.push_back (r.toFloat().transformedBy (content->getTransform()).getSmallestIntegerContainer());
    return out;
}

void SundayOrganAudioProcessorEditor::notify (const juce::String& text) { content->notify (text); }

//------------------------------------------------------------------------------ loading
bool SundayOrganAudioProcessorEditor::loadDoc (std::unique_ptr<juce::XmlElement> doc, PresetRef ref)
{
    if (doc == nullptr) return false;
    auto before = sundayorgan::State::toXml (organ.parameters());
    auto beforeRef = organ.currentPreset();
    if (! Presets::apply (*doc, organ.parameters())) return false;
    organ.requestAllNotesOff();                                  // rule 16: a preset change releases every note
    ref.doc = std::shared_ptr<const juce::XmlElement> (doc.release());
    organ.setCurrentPreset (std::move (ref));
    previousState = std::move (before);                          // "Back to ..." returns here
    previousPreset = std::move (beforeRef);
    content->frame();
    content->refreshPanel();
    return true;
}

bool SundayOrganAudioProcessorEditor::loadFactory (int index)
{
    const auto& bank = Presets::factory();
    if (! juce::isPositiveAndBelow (index, (int) bank.size())) return false;
    const auto& e = bank[(size_t) index];
    return loadDoc (std::make_unique<juce::XmlElement> (*e.doc), { e.name, e.category, "factory:" + e.slug, {} });
}

bool SundayOrganAudioProcessorEditor::loadUser (const juce::File& file)
{
    juce::String error;
    auto doc = Presets::read (file, error);
    if (doc == nullptr) { notify (error); return false; }
    const auto name = Presets::nameOf (*doc, file);
    return loadDoc (std::move (doc), { name, "User", "user:" + file.getFileName(), {} });
}

void SundayOrganAudioProcessorEditor::adoptUser (const juce::File& file)
{
    juce::String error;
    if (auto doc = Presets::read (file, error))
    {
        const auto name = Presets::nameOf (*doc, file);
        organ.setCurrentPreset ({ name, "User", "user:" + file.getFileName(), std::shared_ptr<const juce::XmlElement> (doc.release()) });
    }
    content->frame();
    content->refreshPanel();
}

bool SundayOrganAudioProcessorEditor::importAndLoad (const juce::File& file)
{
    juce::String error;
    const auto user = Presets::importFile (file, error);
    if (user == juce::File()) { notify (error); return false; }
    content->drawer.refresh();
    if (! loadUser (user)) return false;
    notify ("Added to your presets: " + organ.currentPreset().name);
    return true;
}

void SundayOrganAudioProcessorEditor::back()
{
    if (previousState == nullptr) return;
    auto now = sundayorgan::State::toXml (organ.parameters());
    auto nowRef = organ.currentPreset();
    if (! sundayorgan::State::fromXml (*previousState, organ.parameters())) return;
    organ.requestAllNotesOff();
    organ.setCurrentPreset (previousPreset);
    previousState = std::move (now);                              // and back again
    previousPreset = std::move (nowRef);
    content->frame();
    content->refreshPanel();
}

//------------------------------------------------------------------------------ files
void SundayOrganAudioProcessorEditor::loadFromFile()
{
    const auto start = lastFolder.isDirectory() ? lastFolder : juce::File::getSpecialLocation (juce::File::userDesktopDirectory);
    chooser = std::make_unique<juce::FileChooser> ("Load a Sunday Organ preset", start, juce::String ("*") + sundayorgan::State::kPresetExtension);
    chooser->launchAsync (juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
                          [safe = juce::Component::SafePointer<SundayOrganAudioProcessorEditor> (this)] (const juce::FileChooser& fc)
    {
        if (safe == nullptr || fc.getResult() == juce::File()) return;
        safe->lastFolder = fc.getResult().getParentDirectory();
        safe->saveSettings();
        safe->importAndLoad (fc.getResult());
    });
}

namespace
{
void chooseDestination (std::unique_ptr<juce::FileChooser>& chooser, const juce::File& folder, const juce::String& name,
                        std::function<void (const juce::File&)> done)
{
    const auto start = (folder.isDirectory() ? folder : juce::File::getSpecialLocation (juce::File::userDesktopDirectory))
                           .getChildFile (Presets::slugFor (name) + sundayorgan::State::kPresetExtension);
    chooser = std::make_unique<juce::FileChooser> ("Share " + name + " as a preset file", start, juce::String ("*") + sundayorgan::State::kPresetExtension);
    chooser->launchAsync (juce::FileBrowserComponent::saveMode | juce::FileBrowserComponent::canSelectFiles | juce::FileBrowserComponent::warnAboutOverwriting,
                          [then = std::move (done)] (const juce::FileChooser& fc)
    {
        auto f = fc.getResult();
        if (f == juce::File()) return;
        if (! f.hasFileExtension (sundayorgan::State::kPresetExtension)) f = f.withFileExtension (sundayorgan::State::kPresetExtension);
        then (f);
    });
}
} // namespace

void SundayOrganAudioProcessorEditor::sharePreset()
{
    const auto name = organ.currentPreset().name.isNotEmpty() ? organ.currentPreset().name : juce::String ("My sound");
    chooseDestination (chooser, lastFolder, name, [safe = juce::Component::SafePointer<SundayOrganAudioProcessorEditor> (this), name] (const juce::File& f)
    {
        if (safe == nullptr) return;
        juce::String error;
        if (! Presets::shareTo (safe->organ.parameters(), name, f, error)) { safe->notify (error); return; }
        safe->lastFolder = f.getParentDirectory();
        safe->saveSettings();
        safe->notify ("Shared as " + f.getFileName() + ": send that file");
    });
}

void SundayOrganAudioProcessorEditor::shareFile (const juce::File& userFile)
{
    juce::String error;
    auto doc = Presets::read (userFile, error);
    if (doc == nullptr) { notify (error); return; }
    const auto name = Presets::nameOf (*doc, userFile);
    chooseDestination (chooser, lastFolder, name, [safe = juce::Component::SafePointer<SundayOrganAudioProcessorEditor> (this), userFile] (const juce::File& f)
    {
        if (safe == nullptr) return;
        if (! userFile.copyFileTo (f)) { safe->notify ("Could not write " + f.getFullPathName()); return; }
        safe->lastFolder = f.getParentDirectory();
        safe->saveSettings();
        safe->notify ("Shared as " + f.getFileName() + ": send that file");
    });
}

bool SundayOrganAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray& files)
{
    for (const auto& f : files)
        if (f.endsWithIgnoreCase (sundayorgan::State::kPresetExtension)) return true;
    return false;
}

void SundayOrganAudioProcessorEditor::filesDropped (const juce::StringArray& files, int, int)
{
    juce::File last;
    int added = 0;
    for (const auto& path : files)
        if (path.endsWithIgnoreCase (sundayorgan::State::kPresetExtension))
        {
            juce::String error;
            const auto user = Presets::importFile (juce::File (path), error);
            if (user == juce::File()) { notify (error); continue; }
            last = user;
            ++added;
        }
    content->drawer.refresh();
    if (last != juce::File() && loadUser (last))
        notify (added == 1 ? "Added to your presets: " + organ.currentPreset().name
                           : "Added " + juce::String (added) + " presets; loaded " + organ.currentPreset().name);
}

//------------------------------------------------------------------------------ overlays and the menu
void SundayOrganAudioProcessorEditor::showDrawer (bool on)
{
    if (! on) content->drawer.cancelEdit();
    content->drawer.setVisible (on);
    if (on)
    {
        content->drawer.refresh();                               // re-scanned whenever it opens (D.6.5)
        content->drawer.toFront (false);
    }
}

void SundayOrganAudioProcessorEditor::showSave()
{
    showDrawer (true);
    content->drawer.beginSave();
}

void SundayOrganAudioProcessorEditor::showAbout (bool on)
{
    content->about.setVisible (on);
    if (on) { content->drawer.setVisible (false); content->about.toFront (false); }
}

void SundayOrganAudioProcessorEditor::showMenu()
{
    juce::PopupMenu m, scales;
    if (previousState != nullptr)
        m.addItem ("Back to " + shownName (previousPreset), [this] { back(); });
    m.addItem ("Load preset from file...", [this] { loadFromFile(); });
    m.addItem ("Share preset...", [this] { sharePreset(); });
    m.addSeparator();
    for (float s : { 0.75f, 1.0f, 1.5f, 2.0f })
        scales.addItem (juce::String (juce::roundToInt (s * 100.0f)) + " %", true, std::abs (s - scale) < 0.01f, [this, s] { setGuiScale (s); saveSettings(); });
    m.addSubMenu ("GUI scale", scales);
    m.addItem ("Snow on Jingle Jam presets", true, snowOn, [this] { snowOn = ! snowOn; saveSettings(); });
    m.addSeparator();
    m.addItem ("Report a problem...", [this]
    {
        juce::String d;
        d << "Sunday Organ " << JucePlugin_VersionString << ", sound version 1\n"
          << juce::SystemStats::getOperatingSystemName() << ", " << juce::SystemStats::getCpuModel() << "\n"
          << "Host: " << juce::PluginHostType().getHostDescription() << ", " << organ.getSampleRate() << " Hz\n"
          << "Preset: " << shownName (organ.currentPreset()) << "\n";
        juce::SystemClipboard::copyTextToClipboard (d);
    });
    m.addItem ("About Sunday Organ", [this] { showAbout (true); });
    m.showMenuAsync (juce::PopupMenu::Options().withTargetComponent (&content->menuButton).withParentComponent (content.get()));
}
