#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "OberliLookAndFeel.h"

namespace sundayorgan::ui
{
/*  The Sunday Organ editor's controls, each bound to one parameter of parameters.csv and drawn
    from the family tokens (OberliLookAndFeel.h). Every control: double-click resets to the
    table's default, Shift drags finely, right-click asks the host for its parameter menu, an
    accessible name and the table's tooltip, Tab and arrow keys, and a click never takes the
    keyboard focus (the space bar keeps reaching the host). */

/** Caption under a control: caps label (11 px 600, ink-muted) and the value (12 px 500 tnum, ink). */
void drawCaption (juce::Graphics&, juce::Rectangle<float> area, const juce::String& label, const juce::String& value, bool tight = false);
/** A note parameter's text: C4, or Off at its lowest value (paramgen.py writes no value strings for
    int parameters yet - logged in docs/status.md for the kit; the host shows the number until then). */
juce::String noteText (const juce::RangedAudioParameter&, float value);
juce::String shortLabel (const juce::RangedAudioParameter&);
/** The track, accent fill and 14 px thumb of a drawbar (9 stops) or a wheel (a sunken 8 px well). */
void drawLinear (juce::Graphics&, juce::Rectangle<float> area, float proportion, bool wheel, bool focused);

/** A slider bound to a parameter: Knob (the logo's knob), Drawbar (upright, 9 steps), Wheel. */
class ParamSlider final : public juce::Slider
{
public:
    enum class Kind { knob, drawbar, wheel };
    ParamSlider (juce::AudioProcessorEditor&, juce::RangedAudioParameter&, Kind, juce::String label = {});

    void paint (juce::Graphics&) override;
    void mouseDown (const juce::MouseEvent&) override;
    juce::RangedAudioParameter& parameter() { return param; }

    /** The part of the bounds the control draws in (the rest is its caption). */
    juce::Rectangle<float> controlArea() const;

private:
    juce::AudioProcessorEditor& editor;
    juce::RangedAudioParameter& param;
    Kind kind;
    juce::String label;
    juce::SliderParameterAttachment attachment;
};

/** A pill toggle with an accent LED (brand sheet: toggles are pills). */
class PillToggle final : public juce::Button
{
public:
    PillToggle (juce::AudioProcessorEditor&, juce::RangedAudioParameter&, juce::String caption);
    void paintButton (juce::Graphics&, bool over, bool down) override;
    void mouseDown (const juce::MouseEvent&) override;

private:
    juce::AudioProcessorEditor& editor;
    juce::RangedAudioParameter& param;
    juce::ButtonParameterAttachment attachment;
};

/** Exclusive modes as one segmented control (Vibrato: Off V1 V2 V3 C1 C2 C3). */
class Segmented final : public juce::Component, public juce::SettableTooltipClient
{
public:
    Segmented (juce::AudioProcessorEditor&, juce::RangedAudioParameter&, juce::StringArray labels);
    void paint (juce::Graphics&) override;
    void mouseDown (const juce::MouseEvent&) override;
    bool keyPressed (const juce::KeyPress&) override;

private:
    juce::AudioProcessorEditor& editor;
    juce::RangedAudioParameter& param;
    juce::StringArray labels;
    int index = 0;
    juce::ParameterAttachment attachment;
    int segmentAt (float x) const;
};

/** A note field with arrows (Split Key, Pedal Split): the value text is the parameter's own. */
class Stepper final : public juce::Component, public juce::SettableTooltipClient
{
public:
    Stepper (juce::AudioProcessorEditor&, juce::RangedAudioParameter&);
    void paint (juce::Graphics&) override;
    void mouseDown (const juce::MouseEvent&) override;
    void mouseDrag (const juce::MouseEvent&) override;
    void mouseDoubleClick (const juce::MouseEvent&) override;
    bool keyPressed (const juce::KeyPress&) override;

private:
    juce::AudioProcessorEditor& editor;
    juce::RangedAudioParameter& param;
    float value = 0.0f, dragStart = 0.0f;
    juce::ParameterAttachment attachment;
    void step (int delta);
};

/** One rotor seen from above (the Leslie hero): horn or drum at its real angle, its speed in rpm
    and where it is heading ("to 400"). Fed by the editor's frame callback. */
class RotorView final : public juce::Component
{
public:
    RotorView (juce::String name, bool horn);
    void set (float angleTurns, float rpm, float targetRpm);
    void paint (juce::Graphics&) override;

private:
    juce::String name;
    bool horn;
    float angle = 0.0f, rpm = 0.0f, target = 0.0f;
    int shownRpm = -1, shownTarget = -1;
};

/** The output meter: 20 ms RMS per channel in its own well (meter-level, meter-hot above -6 dBFS)
    and a CLIP LED with the word, lit 1 s after a sample reached full scale. */
class OutputMeter final : public juce::Component
{
public:
    void set (float rmsL, float rmsR, bool clipNow);
    void paint (juce::Graphics&) override;

private:
    float level[2] {};
    int clipFrames = 0;
};
} // namespace sundayorgan::ui
