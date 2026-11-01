#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "State.h"

#include <cmath>

namespace
{
// parameters.csv order; raw[i] is the cached atomic of ids[i] (never a string lookup on the audio thread)
constexpr const char* ids[38] = {
    Params::upperBar1, Params::upperBar2, Params::upperBar3, Params::upperBar4, Params::upperBar5,
    Params::upperBar6, Params::upperBar7, Params::upperBar8, Params::upperBar9,
    Params::percOn, Params::percThird, Params::percSlow, Params::percSoft,
    Params::vibratoMode, Params::vibratoLower, Params::leslieFast, Params::leslieBrake, Params::leslieOn,
    Params::micSpread, Params::drive, Params::keyClick, Params::leakage, Params::expression, Params::outGain,
    Params::lowerBar1, Params::lowerBar2, Params::lowerBar3, Params::lowerBar4, Params::lowerBar5,
    Params::lowerBar6, Params::lowerBar7, Params::lowerBar8, Params::lowerBar9,
    Params::pedalBar16, Params::pedalBar8, Params::pedalRelease, Params::splitKey, Params::pedalSplit };
enum Index { iUpper = 0, iPercOn = 9, iPercThird, iPercSlow, iPercSoft, iVibMode, iVibLower, iFast, iBrake, iLeslieOn,
             iSpread, iDrive, iClick, iLeak, iExpr, iOut, iLower, iPed16 = 33, iPed8, iPedRel, iSplit, iPedSplit };
} // namespace

SundayOrganAudioProcessor::SundayOrganAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      apvts (*this, nullptr, "PARAMETERS", Params::createParameterLayout())
{
    for (int i = 0; i < 38; ++i)
    {
        raw[(size_t) i] = apvts.getRawParameterValue (ids[i]);
        jassert (raw[(size_t) i] != nullptr);   // the table and the code disagree: parameters.csv is the source
    }
}

sundayorgan::dsp::Organ::Settings SundayOrganAudioProcessor::readSettings() noexcept
{
    auto v = [this] (int i) { return raw[(size_t) i]->load (std::memory_order_relaxed); };
    auto on = [&] (int i) { return v (i) >= 0.5f; };
    sundayorgan::dsp::Organ::Settings s;
    for (int t = 0; t < 9; ++t) { s.upper[t] = juce::roundToInt (v (iUpper + t)); s.lower[t] = juce::roundToInt (v (iLower + t)); }
    s.percOn = on (iPercOn); s.percThird = on (iPercThird); s.percSlow = on (iPercSlow); s.percSoft = on (iPercSoft);
    s.vibratoMode = juce::jlimit (0, 6, juce::roundToInt (v (iVibMode)));
    s.vibratoLower = on (iVibLower);
    // Leslie Fast and Expression: the parameter or the player's controller, the one moved last
    if (! juce::exactlyEqual (v (iFast), lastFastParam)) { lastFastParam = v (iFast); fastState = lastFastParam >= 0.5f; }
    if (! juce::exactlyEqual (v (iExpr), lastExprParam)) { lastExprParam = v (iExpr); exprState = (double) lastExprParam / 100.0; }
    s.fast = fastState;
    s.expression = exprState;
    s.brake = on (iBrake); s.leslieOn = on (iLeslieOn);
    s.micSpreadDeg = v (iSpread);
    s.drive = (double) v (iDrive) / 100.0;
    s.click = (double) v (iClick) / 100.0;
    s.leakage = (double) v (iLeak) / 100.0;
    s.volumeDb = v (iOut);
    s.pedal16 = juce::roundToInt (v (iPed16)); s.pedal8 = juce::roundToInt (v (iPed8));
    s.pedalRelease = v (iPedRel);
    s.splitKey = juce::roundToInt (v (iSplit)); s.pedalSplit = juce::roundToInt (v (iPedSplit));
    return s;
}

void SundayOrganAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;
    organ.prepare (sampleRate, seed);
    setLatencySamples (organ.latencySamples());   // the safety limiter's look-ahead (rule 7)
    lastFastParam = lastExprParam = -1.0f;
    organ.apply (readSettings());
    organ.reset (prototypeStart);
    organ.setProbe (probe);
    hornRpm.store ((float) (organ.hornHz() * 60.0));
    drumRpm.store ((float) (organ.drumHz() * 60.0));
    juce::dsp::ProcessSpec spec { sampleRate, (juce::uint32) juce::jmax (1, samplesPerBlock), 1 };
    for (auto* f : { &rmsFilterL, &rmsFilterR })
    {
        f->prepare (spec);
        f->setLevelCalculationType (juce::dsp::BallisticsFilterLevelCalculationType::RMS);
        f->setAttackTime (20.0f);
        f->setReleaseTime (20.0f);
    }
    rmsL.store (0.0f);
    rmsR.store (0.0f);
}

void SundayOrganAudioProcessor::releaseResources()
{
    organ.allNotesOff();   // rule 16: deactivation releases every note
}

bool SundayOrganAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

double SundayOrganAudioProcessor::getTailLengthSeconds() const
{
    return 1.6;   // the longest release (Pedal Release 1.5 s) plus the contact ramps (D.2.5)
}

juce::AudioProcessorParameter* SundayOrganAudioProcessor::getBypassParameter() const
{
    return nullptr;   // rule 7 does not apply to an instrument
}

void SundayOrganAudioProcessor::processBlockBypassed (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    organ.allNotesOff();
    buffer.clear();
}

void SundayOrganAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi)
{
    juce::ScopedNoDenormals noDenormals;
    const int numSamples = buffer.getNumSamples();
    buffer.clear();
    if (numSamples == 0 || buffer.getNumChannels() < 2)   // a zero-length block is legal (harness contract, D.5.1)
        return;
    if (notesOffRequested.exchange (false))
        organ.allNotesOff();

    auto* l = buffer.getWritePointer (0);
    auto* r = buffer.getWritePointer (1);
    organ.apply (readSettings());
    auto modWheel = [this] (int value)                         // CC1, or the on-screen wheel
    {
        modNow.store ((float) value / 127.0f, std::memory_order_relaxed);
        const bool f = value >= 64;                            // mod wheel above half = fast
        if (f != lastCcFast) { lastCcFast = f; fastState = f; auto s = organ.current(); s.fast = f; organ.apply (s); }
    };
    if (const float sm = screenMod.load(); sm >= 0.0f && ! juce::exactlyEqual (sm, lastScreenMod))
    {
        lastScreenMod = sm;
        modWheel (juce::jlimit (0, 127, juce::roundToInt (sm * 127.0f)));   // at the block start, no MIDI buffer touched (rule 1)
    }

    // MIDI at sample offsets (rule 16): split the block at every event
    int pos = 0;
    for (const auto metadata : midi)
    {
        const auto msg = metadata.getMessage();
        const int at = juce::jlimit (0, numSamples, metadata.samplePosition);
        if (at > pos)
        {
            organ.render (l + pos, r + pos, at - pos);
            pos = at;
        }
        const int ch = msg.getChannel();
        if (msg.isNoteOn())                organ.noteOn (ch, msg.getNoteNumber());   // an organ has no velocity (brief)
        else if (msg.isNoteOff())          organ.noteOff (ch, msg.getNoteNumber());
        else if (msg.isSustainPedalOn())   organ.sustain (ch, true);
        else if (msg.isSustainPedalOff())  organ.sustain (ch, false);
        else if (msg.isAllNotesOff() || msg.isAllSoundOff()) organ.allNotesOff();
        else if (msg.isController() && msg.getControllerNumber() == 1)
            modWheel (msg.getControllerValue());
        else if (msg.isController() && msg.getControllerNumber() == 11)
        {
            exprState = (double) msg.getControllerValue() / 127.0;
            auto s = organ.current(); s.expression = exprState; organ.apply (s);
        }
    }
    if (pos < numSamples)
        organ.render (l + pos, r + pos, numSamples - pos);
    midi.clear();

    // what the editor reads
    hornRpm.store ((float) (organ.hornHz() * 60.0), std::memory_order_relaxed);
    drumRpm.store ((float) (organ.drumHz() * 60.0), std::memory_order_relaxed);
    hornTurn.store ((float) organ.hornAngle(), std::memory_order_relaxed);
    drumTurn.store ((float) organ.drumAngle(), std::memory_order_relaxed);
    fastNow.store (fastState, std::memory_order_relaxed);
    exprNow.store ((float) exprState, std::memory_order_relaxed);
    activeKeyCount.store (organ.activeKeys(), std::memory_order_relaxed);
    float lastL = 0.0f, lastR = 0.0f;
    for (int i = 0; i < numSamples; ++i)
    {
        if (std::abs (l[i]) >= 1.0f || std::abs (r[i]) >= 1.0f) clipped.store (true, std::memory_order_relaxed);
        lastL = rmsFilterL.processSample (0, l[i]);
        lastR = rmsFilterR.processSample (0, r[i]);
    }
    rmsL.store (lastL, std::memory_order_relaxed);
    rmsR.store (lastR, std::memory_order_relaxed);
}

juce::AudioProcessorEditor* SundayOrganAudioProcessor::createEditor()
{
    return new SundayOrganAudioProcessorEditor (*this);
}

void SundayOrganAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    copyXmlToBinary (*sundayorgan::State::toXml (apvts), destData);
}

void SundayOrganAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    loadState (data, sizeInBytes);
}

bool SundayOrganAudioProcessor::loadState (const void* data, int sizeInBytes)
{
    // arbitrary bytes are refused, never crashed on (D.5.3): a foreign or newer blob leaves the state as it is
    if (data == nullptr || sizeInBytes <= 0)
        return false;
    auto xml = getXmlFromBinary (data, sizeInBytes);
    if (xml == nullptr)
        return false;
    auto* state = sundayorgan::State::stateOf (*xml);
    return state != nullptr && sundayorgan::State::fromXml (*state, apvts);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SundayOrganAudioProcessor();
}
