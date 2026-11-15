// SundayOrganPresetTests - the user preset flow and the session's preset recall, without a host or
// an editor (sound-design-bob F.14.3: "the user flow is tested": save, load, rename, delete,
// overwrite, a factory name forking to User, deleting the loaded preset, a friend's file, a newer
// file refused). Runs in a temporary SUNDAYORGAN_PRESET_ROOT, never the real folders.
// Exit 0 when every check passes; each failure prints one line. CTest: preset_user_flow (fast).
#include "../../Source/PluginProcessor.h"
#include "../../Source/Presets.h"
#include "../../Source/State.h"

#include <cstdlib>
#include <iostream>

namespace
{
int failures = 0;
void check (bool ok, const juce::String& what)
{
    std::cout << (ok ? "ok    " : "FAIL  ") << what << std::endl;
    if (! ok) ++failures;
}

namespace P = sundayorgan::Presets;

void setPlain (SundayOrganAudioProcessor& p, const char* id, float plain)
{
    auto* r = p.parameters().getParameter (id);
    r->setValueNotifyingHost (r->convertTo0to1 (plain));
}

float plainOf (SundayOrganAudioProcessor& p, const char* id)
{
    auto* r = p.parameters().getParameter (id);
    return r->convertFrom0to1 (r->getValue());
}

juce::String text (const juce::File& f) { return f.loadFileAsString(); }
} // namespace

int main()
{
    juce::ScopedJuceInitialiser_GUI init;
    const auto root = juce::File::getSpecialLocation (juce::File::tempDirectory).getNonexistentChildFile ("sundayorgan-presets", "", false);
    root.createDirectory();
    setenv ("SUNDAYORGAN_PRESET_ROOT", root.getFullPathName().toRawUTF8(), 1);
    const auto user = P::userFolder();

    // ------------------------------------------------------------------ the bank (Björn, 2026-11-15)
    const auto& bank = P::factory();
    bool noInit = true;
    int jam = 0;
    for (const auto& e : bank) { noInit = noInit && ! e.name.trim().equalsIgnoreCase ("Init"); jam += e.category == P::kSeasonalCategory ? 1 : 0; }
    check (noInit, "no factory preset is named Init (bank_has_no_preset_named_init)");
    check (bank.size() > 0 && bank[0].slug == "init" && bank[0].name == "Clean Slate", "the defaults' preset is first and called Clean Slate");
    check (jam >= 5, "the Jingle Jam section has at least five presets (" + juce::String (jam) + ")");

    // ------------------------------------------------------------------ folders
    check (user == root.getChildFile ("User"), "user presets live in <root>/User");
    check (P::settingsFolder() == root.getChildFile ("Settings"), "settings live in <root>/Settings");
    unsetenv ("SUNDAYORGAN_PRESET_ROOT");
   #if JUCE_MAC
    check (P::presetRoot().getFullPathName().endsWith ("Library/Audio/Presets/Oberli Audio/Sunday Organ"), "macOS presets: ~/Library/Audio/Presets/Oberli Audio/Sunday Organ (locations.md)");
    check (P::settingsFolder().getFullPathName().endsWith ("Library/Application Support/Oberli Audio/Sunday Organ"), "macOS settings: ~/Library/Application Support/Oberli Audio/Sunday Organ (editor_settings_in_application_support)");
   #endif
    setenv ("SUNDAYORGAN_PRESET_ROOT", root.getFullPathName().toRawUTF8(), 1);

    // ------------------------------------------------------------------ slugs (rule 10)
    check (P::slugFor (juce::String::fromUTF8 ("Alpengl\xc3\xbc" "hen")) == "alpengluehen", "slug: Alpengluehen, ASCII");
    check (P::slugFor ("  Late Night / Jam #2 ") == "late-night-jam-2", "slug: words joined by '-'");
    check (P::slugFor ("***") == "preset", "slug: a name with no letters");

    SundayOrganAudioProcessor organ;
    juce::String error;

    // ------------------------------------------------------------------ save
    check (P::saveUser (organ.parameters(), "   ", error) == juce::File() && error.isNotEmpty(), "an empty name is refused");
    setPlain (organ, Params::drive, 61.0f);
    const auto mine = P::saveUser (organ.parameters(), juce::String::fromUTF8 ("M\xc3\xa4" "rli Abend"), error);
    check (mine.existsAsFile() && mine.getFileName() == "maerli-abend.oberlipreset", "save writes <slug>.oberlipreset");
    auto list = P::userPresets();
    check (list.size() == 1 && list[0].name == juce::String::fromUTF8 ("M\xc3\xa4" "rli Abend"), "the saved preset is listed under its own name");
    {
        auto doc = P::read (mine, error);
        check (doc != nullptr && doc->getStringAttribute ("category") == "User" && ! doc->getBoolAttribute ("factory"), "a user file: category User, not factory");
    }

    // overwrite: the same name (any case) replaces that file, nothing new
    setPlain (organ, Params::drive, 12.0f);
    const auto again = P::saveUser (organ.parameters(), juce::String::fromUTF8 ("m\xc3\xa4" "rli abend"), error);
    list = P::userPresets();
    check (again == mine && list.size() == 1, "saving under an existing name replaces it in its own file");
    {
        SundayOrganAudioProcessor other;
        auto doc = P::read (mine, error);
        P::apply (*doc, other.parameters());
        check (std::abs (plainOf (other, Params::drive) - 12.0f) < 1.0e-3f, "the replaced file holds the new sound");
    }

    // a factory name forks into User; the bank is untouched
    const auto factoryBefore = bank[1].doc->toString();
    const auto fork = P::saveUser (organ.parameters(), bank[1].name, error);
    check (fork.getParentDirectory() == user && bank[1].doc->toString() == factoryBefore, "saving under a factory name forks to User");
    check (P::saveUser (organ.parameters(), "A name far longer than twenty-four", error).getFileNameWithoutExtension() == "a-name-far-longer-than-t",
           "names are cut to 24 characters");

    // ------------------------------------------------------------------ rename
    list = P::userPresets();
    const auto* m = P::findUser (list, juce::String::fromUTF8 ("M\xc3\xa4" "rli Abend"));
    check (P::renameUser (*m, bank[1].name, error) == juce::File() && error.contains ("already"), "rename to a taken name is refused");
    const auto renamed = P::renameUser (*m, "Silvester", error);
    check (renamed.getFileName() == "silvester.oberlipreset" && ! mine.exists(), "rename moves the file to the new slug");
    check (P::findUser (P::userPresets(), "Silvester") != nullptr, "the renamed preset is listed under its new name");

    // ------------------------------------------------------------------ a friend's file
    const auto elsewhere = root.getChildFile ("Downloads");
    elsewhere.createDirectory();
    setPlain (organ, Params::leakage, 77.0f);
    auto friendDoc = sundayorgan::State::presetXml (organ.parameters(), "Snow Pad", "A Friend", "User", {}, false);
    const auto friendFile = elsewhere.getChildFile ("snow-pad.oberlipreset");
    friendDoc->writeTo (friendFile);
    const auto imported = P::importFile (friendFile, error);
    {
        auto doc = P::read (imported, error);
        check (imported.getParentDirectory() == user && doc != nullptr && doc->getStringAttribute ("author") == "A Friend"
               && P::nameOf (*doc, imported) == "Snow Pad", "a friend's file comes into User with its name and author");
    }
    const int before = (int) P::userPresets().size();
    check (P::importFile (friendFile, error) == imported && (int) P::userPresets().size() == before, "the same file again is not duplicated");
    setPlain (organ, Params::leakage, 5.0f);
    sundayorgan::State::presetXml (organ.parameters(), "Snow Pad", "A Friend", "User", {}, false)->writeTo (elsewhere.getChildFile ("other.oberlipreset"));
    const auto second = P::importFile (elsewhere.getChildFile ("other.oberlipreset"), error);
    check (P::findUser (P::userPresets(), "Snow Pad 2") != nullptr && second != imported, "another sound under a taken name becomes \"Snow Pad 2\"");

    // refused, never half-loaded
    elsewhere.getChildFile ("junk.oberlipreset").replaceWithText ("not a preset");
    check (P::importFile (elsewhere.getChildFile ("junk.oberlipreset"), error) == juce::File() && error.contains ("not a Sunday Organ preset"),
           "a file that is not a preset is refused with a reason");
    auto newer = sundayorgan::State::presetXml (organ.parameters(), "Future", "A Friend", "User", {}, false);
    newer->getChildByName (sundayorgan::State::kStateTag)->setAttribute ("version", sundayorgan::State::kStateVersion + 1);
    newer->writeTo (elsewhere.getChildFile ("future.oberlipreset"));
    check (P::importFile (elsewhere.getChildFile ("future.oberlipreset"), error) == juce::File() && error.contains ("newer"),
           "a file from a newer version is refused with a reason");
    check (P::findUser (P::userPresets(), "Future") == nullptr, "nothing of a refused file reaches User");

    // ------------------------------------------------------------------ share
    const auto shared = elsewhere.getChildFile ("for-a-friend.oberlipreset");
    check (P::shareTo (organ.parameters(), "Silvester", shared, error) && P::read (shared, error) != nullptr, "share writes a readable preset file");

    // ------------------------------------------------------------------ delete (outright here; the editor uses the Trash)
    const auto remaining = P::userPresets();
    const auto* s = P::findUser (remaining, "Silvester");
    const auto sFile = s != nullptr ? s->file : juce::File();
    check (s != nullptr && P::removeUser (*s, false) && ! sFile.exists() && P::findUser (P::userPresets(), "Silvester") == nullptr, "delete removes the file and the row");

    // ------------------------------------------------------------------ the session remembers the preset (session_recalls_preset_name)
    {
        SundayOrganAudioProcessor fresh;
        check (fresh.currentPreset().name == "Clean Slate" && fresh.currentPreset().source == "factory:init", "a fresh instance is Clean Slate");

        SundayOrganAudioProcessor a;
        const int i = P::findFactory ("sleigh-bells");
        P::apply (*bank[(size_t) i].doc, a.parameters());
        a.setCurrentPreset ({ bank[(size_t) i].name, bank[(size_t) i].category, "factory:sleigh-bells", std::make_shared<juce::XmlElement> (*bank[(size_t) i].doc) });
        juce::MemoryBlock blob;
        a.getStateInformation (blob);
        SundayOrganAudioProcessor b;
        b.setStateInformation (blob.getData(), (int) blob.getSize());
        const auto ref = b.currentPreset();
        check (ref.name == "Sleigh Bells" && ref.category == P::kSeasonalCategory && ref.doc != nullptr, "a reopened session shows the factory preset it was saved with");
        check (ref.doc != nullptr && ! P::differs (*ref.doc, b.parameters()), "and is not marked modified");
        juce::MemoryBlock blob2;
        b.getStateInformation (blob2);
        check (blob == blob2, "the state round-trips bytewise with the preset name in it");

        const auto userFile = P::saveUser (a.parameters(), "Jam Opener", error);
        a.setCurrentPreset ({ "Jam Opener", "User", "user:" + userFile.getFileName(), {} });
        a.getStateInformation (blob);
        SundayOrganAudioProcessor c;
        c.setStateInformation (blob.getData(), (int) blob.getSize());
        check (c.currentPreset().name == "Jam Opener" && c.currentPreset().doc != nullptr, "a reopened session shows the user preset it was saved with");

        // a state without a name (written before 2026-11-15) loads, with no name
        auto bare = sundayorgan::State::toXml (a.parameters());
        juce::MemoryBlock old;
        juce::AudioProcessor::copyXmlToBinary (*bare, old);
        SundayOrganAudioProcessor d;
        check (d.loadState (old.getData(), (int) old.getSize()) && d.currentPreset().name.isEmpty(), "an older state without a name loads unnamed");
    }

    root.deleteRecursively();
    std::cout << (failures == 0 ? "preset tests: all passed\n" : "preset tests: " + juce::String (failures).toStdString() + " failed\n");
    return failures == 0 ? 0 : 1;
}
