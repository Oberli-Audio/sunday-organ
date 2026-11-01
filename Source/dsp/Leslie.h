#pragma once

#include <algorithm>

#include "OrganMath.h"

#include <initializer_list>

namespace sundayorgan::dsp
{
/*  Leslie 122 - rotary speaker (S.2 "rotary speaker", E.6.5; defining features).
    Prototype: `sound design/dsp/leslie.lib`, constants hand-matched below.
    - Crossover: LR4 (two TPT SVF Butterworth stages) at 800 Hz; the low band again at 200 Hz, and
      the horn band through the matching 200 Hz allpass, so the bands sum flat (F-3).
      Below 200 Hz mono and unmodulated (rule 15).
    - Horn (> 800 Hz): +10 dB TPT bell at 2 kHz (Q 1.5), level 0.3; per mic three paths - direct,
      and two cabinet reflections (angle +2.2 / -2.2 rad, 2.8 / 1.6 ms, gain 0.25 / 0.35). Each path:
      a moving-source Doppler delay solved by retarded time (two fixed-point steps from the
      geometric distance R/c (1 - cos)), Lagrange-read (rule 6); a TPT lowpass that opens from 3 kHz
      to 12 kHz as the horn faces the mic (Q 0.707); AM down to 0.55.
    - Drum (200-800 Hz): AM to 0.5, turning the other way, offset 0.63 turn.
    - Rotor speeds: horn 0.83 / 6.67 Hz, drum 0.67 / 5.67 Hz; inertia as one-poles with their own
      spin-up and spin-down (horn 0.35 / 0.55 s, drum 2.2 / 3.0 s; by ear, listening debt); brake =
      target 0; the rotors never lock to each other.
    - Mic spread: the two mics at +-spread/2 on the horn's circle (smoothed 50 ms).
    The rotors keep turning while Leslie is off; on/off is an equal-power crossfade (15 ms). */
class Leslie
{
public:
    static constexpr double kRadius = 0.15, kSpeedOfSound = 343.0, kRc = kRadius / kSpeedOfSound;
    static constexpr double kHornLevel = 0.3;
    static constexpr int kMaxDelay = 2048;
    static constexpr double kPathAngle[3] = { 0.0, 2.2, -2.2 };
    static constexpr double kPathBase[3] = { 0.0005, 0.0028, 0.0016 };   // s
    static constexpr double kPathGain[3] = { 1.0, 0.25, 0.35 };

    void prepare (double sampleRate) noexcept
    {
        fs = sampleRate;
        hornSpeed.setTimes (0.35, 0.55, fs);
        drumSpeed.setTimes (2.2, 3.0, fs);
        spread.setTau (0.05, fs);
        mixOn.setTau (0.015, fs);
        // every cutoff below Nyquist (leslie.lib cap): the horn's lowpass opens to 12 kHz, above Nyquist
        // below 24 kHz, where tan() turned negative and the filter ran away (failures.md F-15)
        capHz = 0.45 * fs;
        g800 = std::tan (3.141592653589793 * std::min (800.0, capHz) / fs);
        g200 = std::tan (3.141592653589793 * std::min (200.0, capHz) / fs);
        // svf.bell(2000, 1.5, 10): A = 10^(10/40), k = 1/(Q A), v1 gain k (A^2 - 1)
        const double A = std::pow (10.0, 10.0 / 40.0);
        gBell = std::tan (3.141592653589793 * std::min (2000.0, capHz) / fs);
        kBell = 1.0 / (1.5 * A);
        mBell = kBell * (A * A - 1.0);
        piOverFs = 3.141592653589793 / fs;
        invFs = 1.0 / fs;
        quietLimit = (long) (0.25 * fs);
    }

    void reset (bool fromZero) noexcept
    {
        for (auto* f : { &lo1, &lo2, &hi1, &hi2, &hiAp, &bass1, &bass2, &drum1, &drum2, &bell }) f->reset();
        for (auto& p : paths) p.lp.reset();
        delay.reset();
        hornPhase = drumPhase = 0.0;
        quiet = 0; idle = false;
        hornSpeed.y = fromZero ? 0.0 : hornTarget();
        drumSpeed.y = fromZero ? 0.0 : drumTarget();
        spread.reset (fromZero ? 0.0 : spreadTarget);
        mixOn.reset (fromZero ? 0.0 : onTarget);
    }

    void set (bool fastOn, bool brakeOn, double spreadDegrees, bool leslieOn) noexcept
    {
        fast = fastOn; brake = brakeOn;
        spreadTarget = spreadDegrees * 0.017453292519943295;
        onTarget = leslieOn ? 1.0 : 0.0;
    }
    double hornHz() const noexcept { return hornSpeed.y; }
    double drumHz() const noexcept { return drumSpeed.y; }
    double hornAngle() const noexcept { return hornPhase; }   // turns, for the editor
    double drumAngle() const noexcept { return drumPhase; }

    /** One sample, mono in, stereo out. */
    inline void tick (double x, double& outL, double& outR) noexcept
    {
        constexpr double twoPi = 6.283185307179586, sqrtHalfK = 1.4142135623730951;   // k = 1/Q, Q = 1/sqrt 2
        const double hz = hornSpeed.tick (hornTarget());
        hornPhase = frac (hornPhase + invFs * hz);
        const double m = 0.5 * spread.tick (spreadTarget);

        // Idle (brief: idle_pct 2): after the input has been below -180 dBFS for longer than the
        // delay line and the filters take to settle (0.25 s), only the rotors turn; the output is
        // silence, as the filters' would be. The first sound back starts from cleared states.
        quiet = std::abs (x) < 1.0e-9 ? quiet + 1 : 0;
        if (quiet > quietLimit)
        {
            if (! idle) { for (auto* f : { &lo1, &lo2, &hi1, &hi2, &hiAp, &bass1, &bass2, &drum1, &drum2, &bell }) f->reset(); for (auto& p : paths) p.lp.reset(); delay.reset(); idle = true; }
            drumPhase = frac (drumPhase + invFs * drumSpeed.tick (drumTarget()));
            mixOn.tick (onTarget);
            outL = outR = 0.0;
            return;
        }
        idle = false;

        const double lo = lo2.lp (lo1.lp (x, g800, sqrtHalfK), g800, sqrtHalfK);
        double hi = allpass (hiAp, hi2.hp (hi1.hp (x, g800, sqrtHalfK), g800, sqrtHalfK), g200, sqrtHalfK);
        { double v1, v2; bell.tick (hi, gBell, kBell, v1, v2); hi = hi + mBell * v1; }
        const double bass = bass2.lp (bass1.lp (lo, g200, sqrtHalfK), g200, sqrtHalfK);
        const double drum = drum2.hp (drum1.hp (lo, g200, sqrtHalfK), g200, sqrtHalfK);

        const double dhz = drumSpeed.tick (drumTarget());
        drumPhase = frac (drumPhase + invFs * dhz);
        const double dang = twoPi * frac (0.63 - drumPhase);       // the drum turns the other way

        delay.push (hi);
        double side[2];
        for (int c = 0; c < 2; ++c)
        {
            const double mm = c == 0 ? m : -m;
            double horn = 0.0;
            for (int k = 0; k < 3; ++k)
                horn += kPathGain[k] * hornPath (c * 3 + k, k, mm, hz, nullptr);
            side[c] = bass + drum * (1.0 - 0.25 * (1.0 - std::cos (dang + mm))) + horn;
        }
        const double on = mixOn.tick (onTarget);
        outL = xfade (on, x, side[0]);
        outR = xfade (on, x, side[1]);
    }

    /** --solo=crossover: the crossover's sum with no rotor, horn voicing or AM (the brief's
        response_error_db target); the same filters as tick(). */
    inline double crossoverOnly (double x) noexcept
    {
        constexpr double sqrtHalfK = 1.4142135623730951;
        const double lo = lo2.lp (lo1.lp (x, g800, sqrtHalfK), g800, sqrtHalfK);
        const double hi = allpass (hiAp, hi2.hp (hi1.hp (x, g800, sqrtHalfK), g800, sqrtHalfK), g200, sqrtHalfK);
        const double bass = bass2.lp (bass1.lp (lo, g200, sqrtHalfK), g200, sqrtHalfK);
        const double drum = drum2.hp (drum1.hp (lo, g200, sqrtHalfK), g200, sqrtHalfK);
        return bass + drum + hi;
    }

    /** G5 Doppler probe (sound design/tests/doppler_test.dsp): x straight into the direct path
        of mic 1 at a constant rotor speed hz, mics at 0; delayOnly = the Doppler delay read,
        full = delay, moving lowpass and AM. The same code as tick(). */
    inline void dopplerProbe (double x, double hz, double& delayOnly, double& full) noexcept
    {
        hornPhase = probeStarted ? frac (hornPhase + invFs * hz) : 0.0;   // os.lf_sawpos with a constant rate: 0 first
        probeStarted = true;
        delay.push (x);
        full = hornPath (0, 0, 0.0, hz, &delayOnly);
    }

private:
    double hornTarget() const noexcept { return brake ? 0.0 : (fast ? 6.67 : 0.83); }
    double drumTarget() const noexcept { return brake ? 0.0 : (fast ? 5.67 : 0.67); }

    // one horn path: retarded-time Doppler delay, horn level, moving TPT lowpass, AM
    inline double hornPath (int slot, int k, double mm, double hz, double* delayOnly) noexcept
    {
        constexpr double twoPi = 6.283185307179586;
        auto dist = [&] (double p) { return kRc * (1.0 - std::cos (twoPi * p + mm + kPathAngle[k])) + kPathBase[k]; };
        const double d0 = dist (hornPhase);
        const double d1 = dist (hornPhase - hz * d0);       // retarded time, fixed-point steps
        const double d2 = dist (hornPhase - hz * d1);
        const double th = twoPi * (hornPhase - hz * d2) + mm + kPathAngle[k];
        const double cth = std::cos (th);
        const double fc = 4500.0 * (cth + 1.0) + 3000.0;
        const double read = delay.read (fs * d2, kMaxDelay);
        if (delayOnly != nullptr) *delayOnly = read;
        const double y = paths[slot].lp.lp (read * kHornLevel, std::tan (piOverFs * std::min (fc, capHz)), 1.0 / 0.707);
        return y * (1.0 - 0.225 * (1.0 - cth));
    }

    // svf.ap(f, q): v0 - 2k v1, the 2nd-order allpass an LR4 split leaves on its own band; on the
    // horn band it matches the 200 Hz split of the low band, so the three bands sum flat (F-3)
    static double allpass (Svf& f, double x, double g, double k) noexcept { double v1, v2; f.tick (x, g, k, v1, v2); return x - 2.0 * k * v1; }

    struct Path { Svf lp; };
    Svf lo1, lo2, hi1, hi2, hiAp, bass1, bass2, drum1, drum2, bell;
    Path paths[6];
    LagrangeDelay<4096> delay;
    OnePoleSwitching hornSpeed, drumSpeed;
    OnePole spread, mixOn;
    double fs = 48000.0, invFs = 1.0 / 48000.0, piOverFs = 0.0, capHz = 21600.0, g800 = 0.0, g200 = 0.0, gBell = 0.0, kBell = 0.0, mBell = 0.0;
    double hornPhase = 0.0, drumPhase = 0.0, spreadTarget = 120.0 * 0.017453292519943295, onTarget = 1.0;
    bool fast = false, brake = false, probeStarted = false, idle = false;
    long quiet = 0, quietLimit = 12000;
};
} // namespace sundayorgan::dsp
