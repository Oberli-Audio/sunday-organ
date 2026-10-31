// SundayOrganGuiSnapshot - the real editor rendered offscreen to PNG (plugin-ui-bob audio-plugins.md
// 15; Horizon Pad's HorizonPadGuiSnapshot is the model). Links the processor and the editor with the
// release's LookAndFeel and binary data; no window, no second drawing path.
//   SundayOrganGuiSnapshot --out=editor@1x.png [--scale=1|1.5|2] [--preset=<slug>] [--param=<id>=<plain>]...
//                          [--notes=<n,...>] [--seconds=<s>] [--state=default|modified|drawer|about] [--list]
// --notes and --seconds play the instrument first (offline, 48 kHz / 512) so the rotors, the
// meter and the Leslie status show a real state. Exit 0 on success, 2 for an unknown preset,
// parameter or state.
#include "../../Source/PluginEditor.h"
#include "../../Source/PluginProcessor.h"
#include "../../Source/Presets.h"

#include <iostream>

int main (int argc, char* argv[])
{
    juce::ScopedJuceInitialiser_GUI init;
    juce::String out = "editor@1x.png", preset, state = "default";
    float scale = 1.0f, seconds = 0.0f;
    juce::StringArray params, notes;
    for (int i = 1; i < argc; ++i)
    {
        const juce::String a (argv[i]);
        const auto v = a.fromFirstOccurrenceOf ("=", false, false);
        if (a == "--list") { std::cout << "states: default modified drawer about\n"; return 0; }
        if (a.startsWith ("--out=")) out = v;
        else if (a.startsWith ("--scale=")) scale = v.getFloatValue();
        else if (a.startsWith ("--preset=")) preset = v;
        else if (a.startsWith ("--param=")) params.add (v);
        else if (a.startsWith ("--notes=")) notes.addTokens (v, ",", "");
        else if (a.startsWith ("--seconds=")) seconds = v.getFloatValue();
        else if (a.startsWith ("--state=")) state = v;
        else { std::cerr << "unknown argument " << a << "\n"; return 2; }
    }
    if (! juce::StringArray { "default", "modified", "drawer", "about" }.contains (state)) { std::cerr << "unknown state " << state << "\n"; return 2; }

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
    if (state == "drawer") editor->showDrawer (true);
    if (state == "about") editor->showAbout (true);
    editor->advance();
    auto image = editor->createComponentSnapshot (editor->getLocalBounds(), true, 1.0f);
    juce::File file = juce::File::getCurrentWorkingDirectory().getChildFile (out);
    file.deleteFile();
    juce::FileOutputStream stream (file);
    juce::PNGImageFormat png;
    if (! stream.openedOk() || ! png.writeImageToStream (image, stream)) { std::cerr << "cannot write " << out << "\n"; return 2; }
    std::cout << file.getFullPathName() << " " << image.getWidth() << "x" << image.getHeight() << "\n";
    editor.reset();
    return 0;
}
