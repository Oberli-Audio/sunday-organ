// SundayOrganGuiSnapshot - the real editor rendered offscreen to PNG (plugin-ui-bob audio-plugins.md
// 15; Horizon Pad's HorizonPadGuiSnapshot is the model). Links the processor and the editor with the
// release's LookAndFeel and binary data; no window, no second drawing path.
//   SundayOrganGuiSnapshot --out=editor@1x.png [--scale=1|1.5|2] [--preset=<slug>] [--param=<id>=<plain>]...
//                          [--notes=<n,...>] [--seconds=<s>] [--frames=<n>] [--state=default|modified|drawer|save|about] [--list]
// --notes and --seconds play the instrument first (offline, 48 kHz / 512) so the rotors, the
// meter and the Leslie status show a real state; --frames runs that many frames of the editor's
// 30 Hz timer before the render (the snow of a Jingle Jam preset: --frames=900 is 30 s of it).
// SUNDAYORGAN_PRESET_ROOT points the User folder somewhere else (the drawer with user presets).
// --bench=<n> then runs n more frames, compositing the whole editor after each, and prints the time
// per frame as JSON (F-20: what the screen pays when moving snow dirties the panel); --leave=<slug>
// loads that preset after them and reports how long the snow takes to be gone. Each benchmark frame
// is painted the way JUCE's macOS renderer does it: one pass per dirty rectangle the snow asked for;
// --snow-repaints=flakes asks per flake again (F-21, the defect) for comparison. Exit 0 on success, 2 for an unknown preset,
// parameter or state.
#include "../../Source/PluginEditor.h"
#include "../../Source/PluginProcessor.h"
#include "../../Source/Presets.h"

#include <algorithm>
#include <functional>
#include <iostream>

int main (int argc, char* argv[])
{
    juce::ScopedJuceInitialiser_GUI init;
    juce::String out = "editor@1x.png", preset, state = "default";
    float scale = 1.0f, seconds = 0.0f;
    int frames = 1, bench = 0;
    bool onscreen = false;
    juce::String leave;
    juce::StringArray params, notes;
    for (int i = 1; i < argc; ++i)
    {
        const juce::String a (argv[i]);
        const auto v = a.fromFirstOccurrenceOf ("=", false, false);
        if (a == "--list") { std::cout << "states: default modified drawer save about\n"; return 0; }
        if (a.startsWith ("--out=")) out = v;
        else if (a.startsWith ("--scale=")) scale = v.getFloatValue();
        else if (a.startsWith ("--preset=")) preset = v;
        else if (a.startsWith ("--param=")) params.add (v);
        else if (a.startsWith ("--notes=")) notes.addTokens (v, ",", "");
        else if (a.startsWith ("--seconds=")) seconds = v.getFloatValue();
        else if (a.startsWith ("--state=")) state = v;
        else if (a.startsWith ("--frames=")) frames = juce::jmax (1, v.getIntValue());
        else if (a.startsWith ("--bench=")) bench = juce::jmax (1, v.getIntValue());
        else if (a.startsWith ("--leave=")) leave = v;
        else if (a == "--snow-repaints=flakes") sundayorgan::ui::Snowfall::perFlakeRepaints = true;
        else if (a == "--onscreen") onscreen = true;
        else if (a == "--no-overlay") sundayorgan::ui::SnowOverlay::enabled = false;   // the F-21 defect, for comparison
        else { std::cerr << "unknown argument " << a << "\n"; return 2; }
    }
    if (! juce::StringArray { "default", "modified", "drawer", "save", "about" }.contains (state)) { std::cerr << "unknown state " << state << "\n"; return 2; }

    SundayOrganAudioProcessor processor;
    processor.prepareToPlay (48000.0, 512);
    std::unique_ptr<SundayOrganAudioProcessorEditor> editor (dynamic_cast<SundayOrganAudioProcessorEditor*> (processor.createEditor()));
    if (preset.isNotEmpty())
    {
        int index = -1;
        const auto& bank = sundayorgan::Presets::factory();
        for (size_t i = 0; i < bank.size(); ++i) if (bank[i].slug == preset) index = (int) i;
        if (index < 0 || ! editor->loadFactory (index)) { std::cerr << "no factory preset " << preset << "\n"; return 2; }
    }
    for (auto p : params)
    {
        auto* param = processor.parameters().getParameter (p.upToFirstOccurrenceOf ("=", false, false));
        if (param == nullptr) { std::cerr << "unknown parameter " << p << "\n"; return 2; }
        param->setValueNotifyingHost (param->convertTo0to1 (p.fromFirstOccurrenceOf ("=", false, false).getFloatValue()));
    }
    if (state == "modified" && params.isEmpty())
        if (auto* d = processor.parameters().getParameter ("drive")) d->setValueNotifyingHost (d->getValue() + 0.1f);

    // play: the rotors, meter and status show a real state
    juce::AudioBuffer<float> buffer (2, 512);
    juce::MidiBuffer midi;
    for (int b = 0; b < (int) (seconds * 48000.0f / 512.0f); ++b)
    {
        midi.clear();
        if (b == 0) for (auto n : notes) midi.addEvent (juce::MidiMessage::noteOn (1, n.getIntValue(), 1.0f), 0);
        processor.processBlock (buffer, midi);
    }

    editor->setGuiScale (scale);
    if (onscreen)                                            // a real window: the snow attaches its own layer as in a host
    {
        editor->setTopLeftPosition (80, 80);
        editor->addToDesktop (juce::ComponentPeer::windowHasTitleBar);
        editor->setVisible (true);
    }
    if (state == "drawer") editor->showDrawer (true);
    if (state == "about") editor->showAbout (true);
    if (state == "save") editor->showSave();
    for (int f = 0; f < frames; ++f) editor->advance();
    if (bench > 0)
    {
        // each frame as JUCE's macOS renderer paints it: one pass over the component tree per dirty
        // rectangle the snow asked for (F-21), plus the frame itself
        std::vector<double> ms;
        double rects = 0.0;
        for (int f = 0; f < bench; ++f)
        {
            const auto t0 = juce::Time::getMillisecondCounterHiRes();
            editor->advance();
            const auto dirty = editor->snowRepaints();
            rects += (double) dirty.size();
            for (const auto& r : dirty)
                if (! r.getIntersection (editor->getLocalBounds()).isEmpty())
                    auto img = editor->createComponentSnapshot (r.getIntersection (editor->getLocalBounds()), true, 1.0f);
            ms.push_back (juce::Time::getMillisecondCounterHiRes() - t0);
        }
        // the yardstick: the same frame with every component drawn again from scratch (no cache valid)
        std::function<void (juce::Component&)> invalidate = [&] (juce::Component& c) { c.repaint(); for (auto* k : c.getChildren()) invalidate (*k); };
        double full = 0.0;
        for (int f = 0; f < 20; ++f)
        {
            editor->advance();
            invalidate (*editor);
            const auto t0 = juce::Time::getMillisecondCounterHiRes();
            auto img = editor->createComponentSnapshot (editor->getLocalBounds(), true, 1.0f);
            full += juce::Time::getMillisecondCounterHiRes() - t0;
        }
        std::sort (ms.begin(), ms.end());
        double sum = 0.0;
        for (auto v : ms) sum += v;
        std::cout << "{\"frames\": " << bench << ", \"ms_mean\": " << sum / (double) ms.size()
                  << ", \"ms_p95\": " << ms[(size_t) (0.95 * (double) (ms.size() - 1))] << ", \"ms_max\": " << ms.back() << ", \"rects_per_frame\": " << rects / (double) bench << ", \"ms_full_redraw\": " << full / 20.0
                  << ", \"snow\": " << (editor->snowShowing() ? "true" : "false")
                  << ", \"own_layer\": " << (editor->snowOnOwnLayer() ? "true" : "false")
                  << ", \"editor_repaints_from_snow\": " << editor->snowEditorRepaints();
        if (leave.isNotEmpty())
        {
            const auto& bank = sundayorgan::Presets::factory();
            int index = -1;
            for (size_t i = 0; i < bank.size(); ++i) if (bank[i].slug == leave) index = (int) i;
            if (index < 0 || ! editor->loadFactory (index)) { std::cerr << "no factory preset " << leave << "\n"; return 2; }
            int gone = 0;
            while (editor->snowShowing() && gone < 30 * 60) { editor->advance(); ++gone; }
            std::cout << ", \"snow_gone_ms\": " << gone * 1000 / 30;
        }
        std::cout << "}" << std::endl;
        return 0;
    }
    auto image = editor->createComponentSnapshot (editor->getLocalBounds(), true, 1.0f);
    editor->renderSnowOverlayOver (image);                   // --onscreen: the snow's own layer on top, as seen
    juce::File file = juce::File::getCurrentWorkingDirectory().getChildFile (out);
    file.deleteFile();
    juce::FileOutputStream stream (file);
    juce::PNGImageFormat png;
    if (! stream.openedOk() || ! png.writeImageToStream (image, stream)) { std::cerr << "cannot write " << out << "\n"; return 2; }
    std::cout << file.getFullPathName() << " " << image.getWidth() << "x" << image.getHeight() << "\n";
    editor.reset();
    return 0;
}
