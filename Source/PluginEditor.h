#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "PluginProcessor.h"
#include "gui/OberliLookAndFeel.h"
#include "gui/Widgets.h"

/*  Sunday Organ - the editor (plugin-ui-bob, Tier P), from the Oberli Audio design system
    (tokens.json read 2026-10-31: Charcoal, coral, Rubik, label 11 px, line-control #716B62) and
    brand round 13: two rows - what the instrument is made of (WHEELS with MOD and SWELL, UPPER,
    LOWER, PEDALS, KEYBOARD) and what the player changes (PERCUSSION, VIBRATO, LESLIE, VOICE) -
    and the OUTPUT column spanning both on the right. Drawbars are upright sliders with nine
    stops; the Leslie is the hero: horn and drum seen from above at their real angles, with rpm.
    1280 x 474 at 100 %; the GUI scale (75-200 %) is a transform on the content, a machine-local
    preference (EditorSettings.xml), never in the session. Overlays are drawn inside the editor:
    the menu, the preset drawer (380 px from the left; one click loads and it stays open) and
    About on the back of the panel in Bone. One 30 Hz timer drives everything that moves; each
    widget repaints only what changed. */
class SundayOrganAudioProcessorEditor final : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    static constexpr int kWidth = 1280, kHeight = 474;

    explicit SundayOrganAudioProcessorEditor (SundayOrganAudioProcessor&);
    ~SundayOrganAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    /** Snapshot tool hooks (tools/gui_snapshot): open an overlay, set the scale, load a preset. */
    void showDrawer (bool);
    void showAbout (bool);
    void showMenu();
    void setGuiScale (float);
    bool loadFactory (int index);
    void advance() { timerCallback(); }

    class Content;

private:
    void timerCallback() override;

    SundayOrganAudioProcessor& organ;
    sundayorgan::ui::OberliLookAndFeel lookAndFeel;
    std::unique_ptr<Content> content;
    juce::TooltipWindow tooltips { this, 600 };
    float scale = 1.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SundayOrganAudioProcessorEditor)
};
