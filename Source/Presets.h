#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#include "State.h"
#include <PresetData.h>

/*  The factory bank compiled into the plugin (presets.csv and the presets folder's .oberlipreset files as binary
    data, the same files the harness reads), and the player's own presets in the User folder
    (sound-design-bob D.6.4, D.6.5; ship-bob locations.md): one .oberlipreset per preset, an ASCII
    slug as the file name and the display name inside, written only on an explicit save, never by an
    update. Message thread only: the editor, the processor's state calls and the tests use it, never
    the audio thread. Loading a preset is State::fromXml (plain values, clamped; a newer or foreign
    file refused) followed by every note off (rule 16). "Modified" is a comparison of the current
    values with the loaded preset's, never a flag that goes stale. */
namespace sundayorgan::Presets
{
/** The seasonal section (Björn, 2026-11-15): the editor snows while one of its presets is loaded. */
inline constexpr const char* kSeasonalCategory = "Jingle Jam";
/** Preset names: 24 characters at most (plugin-ui-bob audio-plugins.md 8), any language for user presets. */
inline constexpr int kNameMax = 24;

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

inline int findFactory (const juce::String& slug)
{
    const auto& bank = factory();
    for (size_t i = 0; i < bank.size(); ++i)
        if (bank[i].slug == slug) return (int) i;
    return -1;
}

/** Applies a preset document (<OberliPreset> around the state, or a bare state). */
inline bool apply (const juce::XmlElement& doc, juce::AudioProcessorValueTreeState& apvts)
{
    auto* state = State::stateOf (doc);
    return state != nullptr && State::fromXml (*state, apvts);
}

/** True when any parameter differs from what `doc` sets (its missing values are the defaults). */
inline bool differs (const juce::XmlElement& doc, juce::AudioProcessorValueTreeState& apvts)
{
    auto* state = State::stateOf (doc);
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

//============================================================================== folders
/** SUNDAYORGAN_PRESET_ROOT (an absolute path) moves every folder below it, so the tests never touch
    the real ones. */
inline juce::File overrideRoot()
{
    const auto path = juce::SystemStats::getEnvironmentVariable ("SUNDAYORGAN_PRESET_ROOT", {});
    return path.isNotEmpty() && juce::File::isAbsolutePath (path) ? juce::File (path) : juce::File();
}

/** The VST3 convention, one folder for every format of the product (ship-bob locations.md):
    ~/Library/Audio/Presets/Oberli Audio/Sunday Organ, or Documents\VST3 Presets\Oberli Audio\Sunday Organ. */
inline juce::File presetRoot()
{
    if (auto root = overrideRoot(); root != juce::File()) return root;
   #if JUCE_MAC
    return juce::File::getSpecialLocation (juce::File::userHomeDirectory)
        .getChildFile ("Library/Audio/Presets").getChildFile ("Oberli Audio").getChildFile ("Sunday Organ");
   #elif JUCE_WINDOWS
    return juce::File::getSpecialLocation (juce::File::userDocumentsDirectory)
        .getChildFile ("VST3 Presets").getChildFile ("Oberli Audio").getChildFile ("Sunday Organ");
   #else
    return juce::File::getSpecialLocation (juce::File::userHomeDirectory)
        .getChildFile (".vst3/presets").getChildFile ("Oberli Audio").getChildFile ("Sunday Organ");
   #endif
}

inline juce::File userFolder() { return presetRoot().getChildFile ("User"); }

/** Machine-local settings (the editor scale, the snow): ~/Library/Application Support/Oberli Audio/
    Sunday Organ or %APPDATA%\Oberli Audio\Sunday Organ; under the override root's Settings when set. */
inline juce::File settingsFolder()
{
    if (auto root = overrideRoot(); root != juce::File()) return root.getChildFile ("Settings");
   #if JUCE_MAC
    return juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
        .getChildFile ("Application Support").getChildFile ("Oberli Audio").getChildFile ("Sunday Organ");
   #else
    return juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
        .getChildFile ("Oberli Audio").getChildFile ("Sunday Organ");
   #endif
}

//============================================================================== files
/** "Alpenglühen" -> "alpengluehen": ASCII, lowercase, '-' between words (rule 10). */
inline juce::String slugFor (const juce::String& name)
{
    const auto spelled = name.trim().toLowerCase()
                             .replace (juce::String::fromUTF8 ("\xc3\xa4"), "ae")
                             .replace (juce::String::fromUTF8 ("\xc3\xb6"), "oe")
                             .replace (juce::String::fromUTF8 ("\xc3\xbc"), "ue")
                             .replace (juce::String::fromUTF8 ("\xc3\x9f"), "ss");
    juce::String slug;
    bool gap = false;
    for (auto c : spelled)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            if (gap && slug.isNotEmpty()) slug << '-';
            slug << juce::String::charToString (c);
            gap = false;
        }
        else
            gap = true;
    }
    return slug.isNotEmpty() ? slug.substring (0, 48) : juce::String ("preset");
}

/** A file in `folder` named after `slug` that does not exist yet (slug, slug-2, slug-3 ...). */
inline juce::File freshFile (const juce::File& folder, const juce::String& slug)
{
    auto f = folder.getChildFile (slug + State::kPresetExtension);
    for (int n = 2; f.exists(); ++n)
        f = folder.getChildFile (slug + "-" + juce::String (n) + State::kPresetExtension);
    return f;
}

/** Reads a preset file of this plugin; nullptr and a sentence for the player in `error` otherwise
    (plugin-ui-bob plugin-copy.md: what failed and why). A newer file is refused, never half-loaded. */
inline std::unique_ptr<juce::XmlElement> read (const juce::File& file, juce::String& error)
{
    auto xml = file.existsAsFile() ? juce::parseXML (file) : nullptr;
    const auto* state = xml != nullptr ? State::stateOf (*xml) : nullptr;
    if (state == nullptr || state->getIntAttribute ("version", 0) < 1)
    {
        error = "Could not read " + file.getFileName() + ": the file is not a Sunday Organ preset.";
        return nullptr;
    }
    if (state->getIntAttribute ("version") > State::kStateVersion)
    {
        error = "Could not load " + file.getFileName() + ": a newer Sunday Organ saved it.";
        return nullptr;
    }
    return xml;
}

/** The name the file carries, or the file's own name when it carries none. */
inline juce::String nameOf (const juce::XmlElement& doc, const juce::File& file)
{
    const auto n = doc.getStringAttribute ("name").trim();
    return (n.isNotEmpty() ? n : file.getFileNameWithoutExtension()).substring (0, kNameMax);
}

/** The same sound: the two documents' parameter lists are equal. */
inline bool sameSound (const juce::XmlElement& a, const juce::XmlElement& b)
{
    const auto* sa = State::stateOf (a);
    const auto* sb = State::stateOf (b);
    const auto* pa = sa != nullptr ? sa->getChildByName ("PARAMETERS") : nullptr;
    const auto* pb = sb != nullptr ? sb->getChildByName ("PARAMETERS") : nullptr;
    return pa != nullptr && pb != nullptr && pa->isEquivalentTo (pb, false);
}

/** Who wrote a preset: the account's full name (D.6.5: a friend's file shows the friend). */
inline juce::String author() { return juce::SystemStats::getFullUserName(); }

//============================================================================== user presets
struct UserPreset { juce::File file; juce::String name; };

/** Every readable preset in the folder, by name (natural order, case ignored). Unreadable files are
    left where they are and not listed. */
inline std::vector<UserPreset> userPresets (const juce::File& folder = userFolder())
{
    std::vector<UserPreset> out;
    for (const auto& f : folder.findChildFiles (juce::File::findFiles, false, juce::String ("*") + State::kPresetExtension))
    {
        juce::String error;
        if (auto doc = read (f, error))
            out.push_back ({ f, nameOf (*doc, f) });
    }
    std::sort (out.begin(), out.end(), [] (const UserPreset& x, const UserPreset& y) { return x.name.compareNatural (y.name) < 0; });
    return out;
}

inline const UserPreset* findUser (const std::vector<UserPreset>& list, const juce::String& name)
{
    for (const auto& p : list)
        if (p.name.equalsIgnoreCase (name.trim())) return &p;
    return nullptr;
}

/** The name as it will be stored: trimmed, 24 characters at most. */
inline juce::String cleanName (const juce::String& name) { return name.trim().substring (0, kNameMax).trim(); }

/** Saves the current sound as the user preset `name`. A user preset of that name (case ignored) is
    replaced in its own file - the editor asks first; any other name gets a new file. Saving under a
    factory preset's name forks it to the User folder: the factory bank is never written. Returns the
    file, or {} with `error`. */
inline juce::File saveUser (const juce::AudioProcessorValueTreeState& apvts, const juce::String& rawName, juce::String& error,
                            const juce::File& folder = userFolder())
{
    const auto name = cleanName (rawName);
    if (name.isEmpty()) { error = "Give the preset a name."; return {}; }
    if (! folder.createDirectory()) { error = "Could not create the folder " + folder.getFullPathName() + "."; return {}; }
    const auto list = userPresets (folder);
    const auto* existing = findUser (list, name);
    const auto file = existing != nullptr ? existing->file : freshFile (folder, slugFor (name));
    auto doc = State::presetXml (apvts, name, author(), "User", {}, false);
    if (! doc->writeTo (file)) { error = "Could not write " + file.getFullPathName() + "."; return {}; }
    return file;
}

/** Renames a user preset: the name inside and the file's slug. Refused when another user preset has
    that name. Returns the new file, or {} with `error`. */
inline juce::File renameUser (const UserPreset& preset, const juce::String& rawName, juce::String& error,
                              const juce::File& folder = userFolder())
{
    const auto name = cleanName (rawName);
    if (name.isEmpty()) { error = "Give the preset a name."; return {}; }
    const auto list = userPresets (folder);
    if (const auto* other = findUser (list, name); other != nullptr && other->file != preset.file)
    {
        error = "There is already a preset called " + other->name + ".";
        return {};
    }
    auto doc = read (preset.file, error);
    if (doc == nullptr) return {};
    doc->setAttribute ("name", name);
    const bool sameSlug = slugFor (name) == slugFor (preset.name);
    const auto file = sameSlug ? preset.file : freshFile (folder, slugFor (name));
    if (! doc->writeTo (file)) { error = "Could not write " + file.getFullPathName() + "."; return {}; }
    if (file != preset.file) preset.file.deleteFile();
    return file;
}

/** Deletes a user preset: to the Trash, so a slip can be undone there (the tests delete outright). */
inline bool removeUser (const UserPreset& preset, bool toTrash = true)
{
    return toTrash ? preset.file.moveToTrash() : preset.file.deleteFile();
}

/** Brings a preset file from elsewhere (a friend's, a shared one, a drop on the editor) into the User
    folder; its name and author come from the file (D.6.5). A user preset with that name and the same
    sound is reused; a different sound under that name becomes "Name 2". A file already in the folder
    is itself. Returns the user file, or {} with `error`. */
inline juce::File importFile (const juce::File& source, juce::String& error, const juce::File& folder = userFolder())
{
    auto doc = read (source, error);
    if (doc == nullptr) return {};
    if (source.getParentDirectory() == folder) return source;
    if (! folder.createDirectory()) { error = "Could not create the folder " + folder.getFullPathName() + "."; return {}; }
    if (! doc->hasTagName (State::kPresetTag))                       // a bare state: wrap it
    {
        auto wrapped = std::make_unique<juce::XmlElement> (State::kPresetTag);
        wrapped->setAttribute ("name", source.getFileNameWithoutExtension());
        wrapped->addChildElement (doc.release());
        doc = std::move (wrapped);
    }
    const auto base = nameOf (*doc, source);
    const auto list = userPresets (folder);
    auto name = base;
    for (int n = 2; const auto* same = findUser (list, name); ++n)
    {
        juce::String ignored;
        if (auto other = read (same->file, ignored); other != nullptr && sameSound (*other, *doc))
            return same->file;
        const auto suffix = " " + juce::String (n);
        name = base.substring (0, kNameMax - suffix.length()).trim() + suffix;
    }
    doc->setAttribute ("name", name);
    doc->setAttribute ("factory", false);
    const auto file = freshFile (folder, slugFor (name));
    if (! doc->writeTo (file)) { error = "Could not write " + file.getFullPathName() + "."; return {}; }
    return file;
}

/** Writes the current sound to `destination` for someone else (Share preset...). */
inline bool shareTo (const juce::AudioProcessorValueTreeState& apvts, const juce::String& name, const juce::File& destination,
                     juce::String& error)
{
    auto doc = State::presetXml (apvts, cleanName (name).isNotEmpty() ? cleanName (name) : juce::String ("My sound"), author(), "User", {}, false);
    if (! doc->writeTo (destination)) { error = "Could not write " + destination.getFullPathName() + "."; return false; }
    return true;
}
} // namespace sundayorgan::Presets
