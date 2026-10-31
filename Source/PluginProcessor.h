#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>

#include <array>
#include <atomic>
#include <cstring>

#include "Params.h"
#include "dsp/Organ.h"

/*  Sunday Organ - the processor.

    Thread model (sound-design-bob rule 1, D.1): the audio thread reads parameters through cached
    atomics, never by string lookup; nothing on the audio thread allocates, locks or logs; every
    parameter that reaches the audio path is smoothed with the table's tau (Params::smoothing).
    State is State.h's format. The editor reads what the processor publishes as atomics only.

    The DSP is dsp::Organ (Source/dsp/, one class per prototype module, G4). The processor turns the
    38 parameters into Organ::Settings at every sub-block and splits each block at every MIDI event
    (rule 16). Leslie Fast and Expression have two sources each - the parameter and the player's
    controller (CC1 mod wheel above half, CC11 swell): the one moved last wins, and the editor reads
    the result (leslieFastNow, expressionNow). */
class SundayOrganAudioProcessor final : public juce::AudioProcessor
{
public:
    SundayOrganAudioProcessor();
    ~SundayOrganAudioProcessor() override = default;

    // AudioProcessor
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    void processBlockBypassed (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return JucePlugin_Name; }
    bool acceptsMidi() const override { return PRODUCT_IS_INSTRUMENT != 0; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override;
    juce::AudioProcessorParameter* getBypassParameter() const override;

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int) override {}
    const juce::String getProgramName (int) override { return {}; }
    void changeProgramName (int, const juce::String&) override {}

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    /** setStateInformation's work, with a verdict: false when the bytes are not a state of this
        plugin (foreign, truncated, newer); the state is then unchanged. The harness reports it. */
    bool loadState (const void* data, int sizeInBytes);

    /** The parameter tree; the editor attaches to it, the harness sets values through it. */
    juce::AudioProcessorValueTreeState& parameters() { return apvts; }

    /** Every sounding note is released at the next block (rule 16: preset change). Any thread. */
    void requestAllNotesOff() noexcept { notesOffRequested.store (true); }

    /** Harness only (G5, rule 8): seed of the wheel phases (1 = the prototype's), the prototype's
        start (every smoother and both rotors from 0) and a probe point. Call before prepareToPlay. */
    void setTestOptions (int seedValue, bool fromZero, sundayorgan::dsp::Organ::Probe p) noexcept { seed = seedValue; prototypeStart = fromZero; probe = p; }

    /** What the editor reads (atomics, D.6.2): rotor speeds in rpm and angles in turns, the Leslie
        and expression state after the controllers, the number of sounding keys. */
    float hornSpeedRpm() const noexcept { return hornRpm.load (std::memory_order_relaxed); }
    float drumSpeedRpm() const noexcept { return drumRpm.load (std::memory_order_relaxed); }
    float hornAngleTurns() const noexcept { return hornTurn.load (std::memory_order_relaxed); }
    float drumAngleTurns() const noexcept { return drumTurn.load (std::memory_order_relaxed); }
    bool leslieFastNow() const noexcept { return fastNow.load (std::memory_order_relaxed); }
    float expressionNow() const noexcept { return exprNow.load (std::memory_order_relaxed); }

    /** What the editor may read from the audio thread: the 20 ms RMS per channel (D.6.2). */
    float outputLevel (int channel) const noexcept { return channel == 0 ? rmsL.load (std::memory_order_relaxed) : rmsR.load (std::memory_order_relaxed); }

private:
    juce::AudioProcessorValueTreeState apvts;

    // cached parameter pointers (never string lookups on the audio thread)
    std::array<std::atomic<float>*, 38> raw {};
    sundayorgan::dsp::Organ organ;
    sundayorgan::dsp::Organ::Settings readSettings() noexcept;
    float lastFastParam = -1.0f, lastExprParam = -1.0f;
    bool fastState = false, lastCcFast = false;
    double exprState = 1.0;
    std::atomic<bool> notesOffRequested { false };
    int seed = 1;
    bool prototypeStart = false;
    sundayorgan::dsp::Organ::Probe probe = sundayorgan::dsp::Organ::Probe::out;
    std::atomic<float> hornRpm { 0.0f }, drumRpm { 0.0f }, hornTurn { 0.0f }, drumTurn { 0.0f }, exprNow { 1.0f };
    std::atomic<bool> fastNow { false };
    std::atomic<int> activeKeyCount { 0 };
    double currentSampleRate = 48000.0;
    std::atomic<float> rmsL { 0.0f }, rmsR { 0.0f };
    juce::dsp::BallisticsFilter<float> rmsFilterL, rmsFilterR;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SundayOrganAudioProcessor)
};
