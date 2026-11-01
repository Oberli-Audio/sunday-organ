#pragma once

#include <algorithm>

#include "OrganMath.h"

#include <initializer_list>

namespace sundayorgan::dsp
{
/*  Scanner - vibrato V1-V3 and chorus C1-C3 (defining feature).
    Prototype: `sound design/dsp/scanner.lib`. A Lagrange-interpolated delay (rule 6) swept by a
    triangle at 6.87 Hz, rounded by a 40 Hz one-pole; the line's high-frequency loss a 7 kHz
    one-pole after it. V: wet only; C: the same depth, equal-power with dry (0.7071 each).
    Depths (peak delay swing, by ear, listening debt): V1 0.35 ms, V2 0.7 ms, V3 1.2 ms over a
    0.2 ms base. Gains and depth smoothed 20 ms, so switching modes never clicks. */
class Scanner
{
public:
    static constexpr double kRateHz = 6.87, kBaseS = 0.0002, kRoundHz = 40.0, kLineHz = 7000.0;
    static constexpr int kMaxDelay = 512;      // 1.4 ms at 192 kHz > base + V3

    static double depthOf (int v) noexcept { return v >= 2 ? (v >= 3 ? 0.0012 : 0.0007) : (v >= 1 ? 0.00035 : 0.0); }

    void prepare (double sampleRate) noexcept
    {
        fs = sampleRate;
        inc = kRateHz / fs;
        for (auto* s : { &gDry, &gWet, &depth }) s->setTau (0.02, fs);
        bilinear (kRoundHz, roundB, roundA);
        bilinear (kLineHz, lineB, lineA);
    }
    void reset (bool fromZero) noexcept
    {
        delay.reset();
        phase = 0.0; first = true;
        triPrev = 0.0; roundY = 0.0; wetPrev = 0.0; lineY = 0.0;
        gDry.reset (fromZero ? 0.0 : dryTarget);
        gWet.reset (fromZero ? 0.0 : wetTarget);
        depth.reset (fromZero ? 0.0 : depthTarget);
    }
    /** mode: 0 off, 1-3 V1-V3, 4-6 C1-C3 */
    void setMode (int mode) noexcept
    {
        const int v = mode > 3 ? mode - 3 : mode;
        dryTarget = 0.7071 * (mode >= 4 ? 1.0 : 0.0) + (mode == 0 ? 1.0 : 0.0);
        wetTarget = 0.7071 * (mode >= 4 ? 1.0 : 0.0) + ((mode >= 1 && mode <= 3) ? 1.0 : 0.0);
        depthTarget = depthOf (v);
    }

    inline double tick (double x) noexcept
    {
        // os.hs_phasor(1, 6.87, 1 - 1'): 0 at the first sample, then frac(prev + inc)
        phase = first ? 0.0 : frac (inc + phase);
        first = false;
        const double tri = 1.0 - std::abs (2.0 * phase - 1.0);
        roundY = -(roundA * (roundB * roundY - (tri + triPrev)));      // fi.lowpass(1, 40), bilinear
        triPrev = tri;
        const double gd = gDry.tick (dryTarget), gw = gWet.tick (wetTarget), dp = depth.tick (depthTarget);
        delay.push (x);
        const double d = delay.read (fs * (dp * roundY + kBaseS), kMaxDelay);
        lineY = -(lineA * (lineB * lineY - (d + wetPrev)));              // fi.lowpass(1, 7000)
        wetPrev = d;
        return x * gd + lineY * gw;
    }

private:
    // fi.lowpass(1, fc) as Faust generates it: c = 1 / tan(pi fc / fs), b = 1 - c, a = 1 / (c + 1)
    void bilinear (double fc, double& b, double& a) const noexcept
    {
        // below Nyquist (scanner.lib cap): 7 kHz crossed it below 14 kHz and the filter ran away (F-15)
        const double c = 1.0 / std::tan (3.141592653589793 * std::min (fc, 0.45 * fs) / fs);
        b = 1.0 - c;
        a = 1.0 / (c + 1.0);
    }
    LagrangeDelay<1024> delay;
    OnePole gDry, gWet, depth;
    double fs = 48000.0, inc = 0.0, phase = 0.0, triPrev = 0.0, roundY = 0.0, wetPrev = 0.0, lineY = 0.0;
    double roundA = 0.0, roundB = 0.0, lineA = 0.0, lineB = 0.0;
    double dryTarget = 1.0, wetTarget = 0.0, depthTarget = 0.0;
    bool first = true;
};

/*  Preamp - the drive stage before the Leslie: one asymmetric soft clip, tanh with first-order
    ADAA (rule 3; the ill-conditioned fallback at |x - x'| <= 1/fs), the bias removed, a DC blocker
    at 5 Hz in seconds (rule 4, rule 12), then the makeup gain (rule 5).
    Operating point (brief amendment 2026-11-01, failures.md F-12): the input is the organ at
    0.06 x expression^2, the gain s (12 / s)^drive with s = 0.035, so Drive 0 keeps the fullest
    chord at -63 dB of distortion and Drive 100 % is the old gain 12; bias 0.15 drive. The makeup
    in dB is a quartic in drive fitted to the reference chord (C3-E3-G3-C4, 888000000, measured on
    the static stage by tools/measure/preamp_prestudy.py): it holds that chord's loudness over
    0-100 %; one key and bigger chords move with the saturation. Departure from S.2 (no bias
    shift or sag): G1. ADAA's half-sample delay is not compensated: there is no parallel dry path.
    Prototype: `preamp` in tonewheel.dsp v0.7. */
class Preamp
{
public:
    static constexpr double kDcHz = 5.0;
    static constexpr double kInputAtDrive0 = 0.035, kGainAtDrive1 = 12.0;
    static constexpr double kMakeupDb[5] = { 27.5789, -27.9510, 9.4812, -51.6762, 29.8631 };   // d^4 .. d^0
    void prepare (double sampleRate) noexcept
    {
        fs = sampleRate;
        eps = 1.0 / fs;
        drive.setTau (0.02, fs);
        const double wn = 3.141592653589793 * kDcHz / fs;          // fi.dcblockerat
        b0 = 1.0 / (1.0 + wn);
        pole = (1.0 - wn) * b0;
    }
    void reset (bool fromZero) noexcept
    {
        // at rest the stage's input is the bias: start the ADAA there, or the first sample is a
        // step that the 5 Hz blocker drains for 30 ms (a thump at every reset, failures.md F-13)
        const double d = fromZero ? 0.0 : driveTarget;
        drive.reset (d);
        xPrev = 0.15 * d; wPrev = 0.0; y = 0.0;
    }
    void setDrive (double d01) noexcept { driveTarget = d01; }

    static double logcosh (double x) noexcept { const double c = std::cosh (x); return std::log (c < DBL_MAX ? c : DBL_MAX); }

    inline double tick (double x) noexcept
    {
        const double d = drive.tick (driveTarget);
        const double u = kInputAtDrive0 * std::pow (kGainAtDrive1 / kInputAtDrive0, d) * x + 0.15 * d;
        const double diff = u - xPrev;
        const double t = std::abs (diff) <= eps ? std::tanh (0.5 * (u + xPrev)) : (logcosh (u) - logcosh (xPrev)) / diff;
        xPrev = u;
        const double w = b0 * (t - std::tanh (0.15 * d));
        y = w - wPrev + pole * y;
        wPrev = w;
        const double makeupDb = (((kMakeupDb[0] * d + kMakeupDb[1]) * d + kMakeupDb[2]) * d + kMakeupDb[3]) * d + kMakeupDb[4];
        return y * std::pow (10.0, makeupDb / 20.0);
    }

private:
    OnePole drive;
    double fs = 48000.0, eps = 1.0 / 48000.0, b0 = 1.0, pole = 0.0, xPrev = 0.0, wPrev = 0.0, y = 0.0, driveTarget = 0.2;
};
} // namespace sundayorgan::dsp
