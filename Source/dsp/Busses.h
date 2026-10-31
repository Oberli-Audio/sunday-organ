#pragma once

#include "OrganMath.h"

namespace sundayorgan::dsp
{
/*  Busses - the drawbars: 9 bus levels per manual, each step about 3 dB, 0 silent (defining
    feature), smoothed 15 ms so a drawbar move never zippers. Upper 1' is cut while percussion is
    on (B-3 behaviour), percussion is added to the upper manual here.
    Prototype: `upper`, `lower`, `ub`, `lb`, `step`, `upperSig`, `lowerSig` in tonewheel.dsp v0.5. */
class Busses
{
public:
    static constexpr int kBars = 9;
    static constexpr double kSmoothSeconds = 0.015;

    void prepare (double sampleRate) noexcept
    {
        for (int t = 0; t < kBars; ++t) { up[t].setTau (kSmoothSeconds, sampleRate); lo[t].setTau (kSmoothSeconds, sampleRate); }
        percOn.setTau (kSmoothSeconds, sampleRate);
    }
    void reset (bool fromZero) noexcept
    {
        for (int t = 0; t < kBars; ++t) { up[t].reset (fromZero ? 0.0 : upTarget[t]); lo[t].reset (fromZero ? 0.0 : loTarget[t]); }
        percOn.reset (fromZero ? 0.0 : percOnTarget);
    }
    void setDrawbars (const int* upperSteps, const int* lowerSteps, bool percussionOn) noexcept
    {
        for (int t = 0; t < kBars; ++t) { upTarget[t] = drawbarGain (upperSteps[t]); loTarget[t] = drawbarGain (lowerSteps[t]); }
        percOnTarget = percussionOn ? 1.0 : 0.0;
    }

    /** One sample: the upper and lower manual signals from the bus sums and the percussion bus. */
    inline void tick (const double* upperBus, const double* lowerBus, double percBus, double& upperSig, double& lowerSig) noexcept
    {
        double u = 0.0, l = 0.0;
        for (int t = 0; t < kBars - 1; ++t)
            u += up[t].tick (upTarget[t]) * upperBus[t];
        const double p = percOn.tick (percOnTarget);
        u += up[8].tick (upTarget[8]) * (1.0 - p) * upperBus[8] + p * percBus;
        for (int t = 0; t < kBars; ++t)
            l += lo[t].tick (loTarget[t]) * lowerBus[t];
        upperSig = u;
        lowerSig = l;
    }

private:
    OnePole up[kBars], lo[kBars], percOn;
    double upTarget[kBars] {}, loTarget[kBars] {}, percOnTarget = 0.0;
};

/*  Percussion - upper manual only, single trigger: fires when the first upper key goes down after
    all were released; the 2nd harmonic (4' bus) or the 3rd (2 2/3' bus), an exponential decay to
    -60 dB in 0.5 s or 1.5 s (Slow), Soft = -6 dB. Decay times by ear (listening debt).
    Prototype: `anyUpper`, `trig`, `percT60`, `percEnv`, `percBus`. */
class Percussion
{
public:
    void prepare (double sampleRate) noexcept
    {
        fs = sampleRate;
        third.setTau (0.015, fs);
        soft.setTau (0.015, fs);
    }
    void reset (bool fromZero) noexcept
    {
        env = 0.0; prevAny = false;
        third.reset (fromZero ? 0.0 : thirdTarget);
        soft.reset (fromZero ? 0.0 : softTarget);
    }
    void set (bool thirdHarmonic, bool slow, bool softer) noexcept
    {
        thirdTarget = thirdHarmonic ? 1.0 : 0.0;
        softTarget = softer ? 1.0 : 0.0;
        decay = std::exp (-((6.9078 / fs) / (slow ? 1.5 : 0.5)));   // 6.9078 = ln(1000): -60 dB
    }
    /** One sample: anyUpperDown = some upper key is down (after sustain, routing). */
    inline double tick (bool anyUpperDown, const double* upperBus) noexcept
    {
        const double trig = (anyUpperDown && ! prevAny) ? 1.0 : 0.0;
        prevAny = anyUpperDown;
        const double d = env * decay;
        env = trig > d ? trig : d;
        const double th = third.tick (thirdTarget);
        const double sf = soft.tick (softTarget);
        return xfade (th, upperBus[3], upperBus[4]) * env * (1.0 - 0.5 * sf);
    }

private:
    OnePole third, soft;
    double fs = 48000.0, env = 0.0, decay = 0.0, thirdTarget = 0.0, softTarget = 0.0;
    bool prevAny = false;
};
} // namespace sundayorgan::dsp
