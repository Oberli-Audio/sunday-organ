#pragma once

#include <cfloat>
#include <cmath>
#include <cstddef>

/*  Shared helpers of the Sunday Organ DSP, each the C++ twin of one Faust library function the
    prototype (`sound design/dsp/tonewheel.dsp` v0.5) uses, so G5 can null module by module.
    Everything here is double, like the prototype (`faust -double`). */
namespace sundayorgan::dsp
{
inline double frac (double x) noexcept { return x - std::floor (x); }                 // ma.frac / ma.decimal

/** The prototype's seeded constant: ma.frac(sin(a*12.9898 + b*78.233) * 43758.5453) : abs (rule 8). */
inline double hash (double a, double b) noexcept { return std::abs (frac (std::sin (a * 12.9898 + b * 78.233) * 43758.5453)); }

/** ba.tau2pole: the pole of a one-pole with time constant tau seconds (rule 12). */
inline double tau2pole (double tauSeconds, double sampleRate) noexcept
{
    return std::abs (tauSeconds) < DBL_EPSILON ? 0.0 : std::exp (-1.0 / (tauSeconds * sampleRate));
}

/** si.smooth(ba.tau2pole(tau)): y = (1 - s) x + s y. Starts where reset() puts it. */
struct OnePole
{
    double y = 0.0, s = 0.0, b = 1.0;
    void setTau (double tauSeconds, double sampleRate) noexcept { s = tau2pole (tauSeconds, sampleRate); b = 1.0 - s; }
    void reset (double v) noexcept { y = v; }
    double tick (double x) noexcept { y = b * x + s * y; return y; }
};

/** si.onePoleSwitching(att, rel): the Leslie's rotor inertia, its own time up and down. */
struct OnePoleSwitching
{
    double y = 0.0, up = 0.0, down = 0.0;
    void setTimes (double attackSeconds, double releaseSeconds, double sampleRate) noexcept
    {
        up = tau2pole (attackSeconds, sampleRate);
        down = tau2pole (releaseSeconds, sampleRate);
    }
    double tick (double x) noexcept
    {
        const double c = x > y ? up : down;
        y = (1.0 - c) * x + c * y;
        return y;
    }
};

/** Drawbar step to gain: about 3 dB per step, 0 silent (`step` in the prototype; 0.15 = 3/20). */
inline double drawbarGain (int step) noexcept { return step < 1 ? 0.0 : std::pow (10.0, 0.15 * ((double) step - 8.0)); }

/** Equal-power crossfade, sel 0 -> a, 1 -> b (rule 5; `xfade` in the prototype). */
inline double xfade (double sel, double a, double b) noexcept
{
    constexpr double halfPi = 1.5707963267948966;
    return a * std::cos (sel * halfPi) + b * std::sin (sel * halfPi);
}

/** fi.svf (Zavalishin TPT state-variable filter), the modes the organ uses: lp, hp, bell (rule 6). */
struct Svf
{
    double ic1 = 0.0, ic2 = 0.0;
    void reset() noexcept { ic1 = ic2 = 0.0; }
    // returns v1, v2 for g = tan(pi f / fs), k = 1/Q (bell: k = 1/(Q A))
    inline void tick (double v0, double g, double k, double& v1, double& v2) noexcept
    {
        v1 = (ic1 + g * (v0 - ic2)) / (1.0 + g * (g + k));
        v2 = ic2 + g * v1;
        ic1 = 2.0 * v1 - ic1;
        ic2 = 2.0 * v2 - ic2;
    }
    double lp (double x, double g, double k) noexcept { double v1, v2; tick (x, g, k, v1, v2); return v2; }
    double hp (double x, double g, double k) noexcept { double v1, v2; tick (x, g, k, v1, v2); return x - k * v1 - v2; }
};

/** de.fdelay3 (fdelayltv(3)): third-order Lagrange read from a power-of-two ring (rule 6). */
template <int Size>
struct LagrangeDelay
{
    static_assert ((Size & (Size - 1)) == 0, "power of two");
    double buf[Size] {};
    int w = 0;
    void reset() noexcept { for (auto& v : buf) v = 0.0; w = 0; }
    void push (double x) noexcept { w = (w + 1) & (Size - 1); buf[w] = x; }
    double tap (int d, int maxDelay) const noexcept
    {
        d = d < 0 ? 0 : (d > maxDelay ? maxDelay : d);       // de.delay: min(n, max(0, d))
        return buf[(std::size_t) ((w - d) & (Size - 1))];
    }
    /** Delay in samples (fractional), clamped to maxDelay like the prototype. Read after push(). */
    double read (double d, int maxDelay) const noexcept
    {
        constexpr double o = (3 - 1.00001) / 2;               // fdelayltv's centring offset
        const double dmo = d - o;
        const int id = (int) dmo;
        const double fd = o + frac (dmo);
        const double h0 = (fd - 1) / (0 - 1) * (fd - 2) / (0 - 2) * (fd - 3) / (0 - 3);
        const double h1 = (fd - 0) / (1 - 0) * (fd - 2) / (1 - 2) * (fd - 3) / (1 - 3);
        const double h2 = (fd - 0) / (2 - 0) * (fd - 1) / (2 - 1) * (fd - 3) / (2 - 3);
        const double h3 = (fd - 0) / (3 - 0) * (fd - 1) / (3 - 1) * (fd - 2) / (3 - 2);
        return tap (id, maxDelay) * h0 + tap (id + 1, maxDelay) * h1 + tap (id + 2, maxDelay) * h2 + tap (id + 3, maxDelay) * h3;
    }
};
} // namespace sundayorgan::dsp
