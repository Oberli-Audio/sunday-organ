#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#include "State.h"
#include <PresetData.h>

/*  The factory bank compiled into the plugin (presets.csv and the presets folder's .oberlipreset files as binary
    data, the same files the harness reads), plus user presets saved by the editor. Message thread
    only: the editor and the harness call it, never the audio thread. Loading a preset is
    State::fromXml (plain values, clamped; a newer or foreign file refused) followed by every note
    off (rule 16). "Modified" is a comparison of the current values with the loaded preset's,
    never a flag that goes stale. */
namespace sundayorgan::Presets
{
struct Entry { juce::String slug, name, category; std::unique_ptr<juce::XmlElement> doc; };

inline const std::vector<Entry>& factory()
{
    static const std::vector<Entry> bank = []
    {
        std::vector<Entry> out;
        int csvSize = 0;
        const char* csv = PresetData::getNamedResource ("presets_csv", csvSize);
        juce::StringArray lines;
        lines.addLines (juce::String::fromUTF8 (csv, csvSize));
        for (int i = 1; i < lines.size(); ++i)
        {
            auto cells = juce::StringArray::fromTokens (lines[i], ",", "\"");
            if (cells.size() < 3) continue;
            Entry e { cells[0], cells[1], cells[2], nullptr };
            const auto resource = cells[0].removeCharacters ("-") + "_oberlipreset";   // JUCE drops the hyphens
            int size = 0;
            if (const char* data = PresetData::getNamedResource (resource.toRawUTF8(), size))
                e.doc = juce::parseXML (juce::String::fromUTF8 (data, size));
            if (e.doc != nullptr) out.push_back (std::move (e));
        }
        return out;
    }();
    return bank;
}

/** Applies a preset document (<OberliPreset> around the state, or a bare state). */
inline bool apply (const juce::XmlElement& doc, juce::AudioProcessorValueTreeState& apvts)
{
    auto* state = doc.hasTagName (State::kStateTag) ? &doc : doc.getChildByName (State::kStateTag);
    return state != nullptr && State::fromXml (*state, apvts);
}

/** True when any parameter differs from what `doc` sets (its missing values are the defaults). */
inline bool differs (const juce::XmlElement& doc, juce::AudioProcessorValueTreeState& apvts)
{
    auto* state = doc.hasTagName (State::kStateTag) ? &doc : doc.getChildByName (State::kStateTag);
    if (state == nullptr) return true;
    auto* params = state->getChildByName ("PARAMETERS");
    for (auto* p : apvts.processor.getParameters())
    {
        auto* r = dynamic_cast<juce::RangedAudioParameter*> (p);
        if (r == nullptr) continue;
        double want = r->convertFrom0to1 (r->getDefaultValue());
        if (params != nullptr)
            for (auto* e : params->getChildWithTagNameIterator ("PARAM"))
                if (e->getStringAttribute ("id") == r->paramID) want = e->getDoubleAttribute ("value", want);
        const auto range = r->getNormalisableRange();
        want = juce::jlimit ((double) range.start, (double) range.end, want);
        const double have = r->convertFrom0to1 (r->getValue());
        if (std::abs (have - want) > 1.0e-3 * std::max (1.0, std::abs (want))) return true;
    }
    return false;
}

inline juce::File userFolder()
{
    return juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
        .getChildFile ("Oberli Audio").getChildFile ("Sunday Organ").getChildFile ("Presets");
}
} // namespace sundayorgan::Presets
