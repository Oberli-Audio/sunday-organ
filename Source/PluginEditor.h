#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "PluginProcessor.h"
#include "gui/OberliLookAndFeel.h"
#include "gui/SnowOverlay.h"
#include "gui/Snowfall.h"
#include "gui/Widgets.h"

/*  Sunday Organ - the editor (plugin-ui-bob, Tier P), from the Oberli Audio design system
    (tokens.json read 2026-11-01: Charcoal, tangerine since round 14, Rubik, label 11 px, line-control #716B62) and
    brand round 13: two rows - what the instrument is made of (WHEELS with MOD and SWELL, UPPER,
    LOWER, PEDALS, KEYBOARD) and what the player changes (PERCUSSION, VIBRATO, LESLIE, VOICE) -
    and the OUTPUT column spanning both on the right. Drawbars are upright sliders with nine
    stops; the Leslie is the hero: horn and drum seen from above at their real angles, with rpm.
    1280 x 474 at 100 %; the GUI scale (75-200 %) is a transform on the content, a machine-local
    preference (EditorSettings.xml), never in the session. Overlays are drawn inside the editor:
    the menu, the preset drawer (380 px from the left: the factory bank by category and the
    player's own presets under USER, with Save current sound; one click loads and it stays open,
    a click outside, its close button, a double-click or Escape closes it) and About on the back
    of the panel in Bone. The menu loads a preset file and shares the current sound as one; a
    preset file dropped on the editor is added to USER and loaded. A Jingle Jam preset brings
    snow (gui/Snowfall.h). One 30 Hz timer drives everything that moves; each widget repaints
    only what changed. */
class SundayOrganAudioProcessorEditor final : public juce::AudioProcessorEditor,
                                              public juce::FileDragAndDropTarget,
                                              private juce::Timer
{
public:
    static constexpr int kWidth = 1280, kHeight = 474;

    explicit SundayOrganAudioProcessorEditor (SundayOrganAudioProcessor&);
    ~SundayOrganAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    // FileDragAndDropTarget: a .oberlipreset dropped on the editor
    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;

    /** Loading. Each remembers the sound before it for "Back to ..." in the menu. */
    bool loadFactory (int index);
    bool loadUser (const juce::File& file);
    /** Adds a preset file from elsewhere to USER (Presets::importFile) and loads it. */
    bool importAndLoad (const juce::File& file);
    /** Makes a user file the loaded preset without loading it (the sound is already this one: after a save or rename). */
    void adoptUser (const juce::File& file);
    /** Back to the sound before the last load (one step, and back again). */
    void back();

    /** Share: writes the current sound, or copies a user preset's file, to a place the player picks. */
    void sharePreset();
    void shareFile (const juce::File& userFile);

    /** A line in the header for a few seconds: what was saved, shared or refused, and why. */
    void notify (const juce::String& text);

    /** Snapshot tool hooks (tools/gui_snapshot): open an overlay, set the scale, run frames. */
    void showDrawer (bool);
    void showAbout (bool);
    void showMenu();
    void showSave();
    void setGuiScale (float);
    void advance() { timerCallback(); }
    /** True while there is snow (falling, fading or melting). */
    bool snowShowing() const;
    /** True when the snow is on its own native layer (macOS, on screen; F-21). */
    bool snowOnOwnLayer() const;
    /** Repaints the snow has asked of the editor so far (zero while it has its own layer). */
    int snowEditorRepaints() const;
    /** Draws the snow's own layer over an editor snapshot (the snapshot tool's --onscreen render). */
    bool renderSnowOverlayOver (juce::Image& image) const { return snowOverlay.renderOver (image); }
    void parentHierarchyChanged() override;
    /** The snow's repaint rectangles of the last frame, in editor coordinates (the benchmark). */
    std::vector<juce::Rectangle<int>> snowRepaints() const;

    class Content;

private:
    void timerCallback() override;
    bool loadDoc (std::unique_ptr<juce::XmlElement>, SundayOrganAudioProcessor::PresetRef);
    void loadFromFile();
    void saveSettings() const;

    SundayOrganAudioProcessor& organ;
    sundayorgan::ui::OberliLookAndFeel lookAndFeel;
    std::unique_ptr<Content> content;
    juce::TooltipWindow tooltips { this, 600 };
    float scale = 1.0f;
    bool snowOn = true;
    juce::File lastFolder;
    std::unique_ptr<juce::FileChooser> chooser;
    sundayorgan::ui::SnowOverlay snowOverlay;
    std::unique_ptr<juce::XmlElement> previousState;
    SundayOrganAudioProcessor::PresetRef previousPreset;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SundayOrganAudioProcessorEditor)
};
