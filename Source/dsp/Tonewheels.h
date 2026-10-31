#pragma once

#include "OrganMath.h"

namespace sundayorgan::dsp
{
/*  Tonewheels - the generator: 91 free-running sine wheels shared by every key, manual and pedal
    (defining feature: two keys on one wheel sum phase-coherently, +6 dB).

    Prototype: `quad`, `wheelHz`, `taper`, `wheel` in tonewheel.dsp v0.5.
    - Frequencies: a 20 rev/s motor through the B-3 gear ratio of each pitch class, teeth doubling
      per octave: wheel 0 = 32.70 Hz (C1) ... wheel 90 = 5920 Hz. Not equal temperament.
    - Each wheel is an exact quadrature oscillator (one complex rotation per sample, double), started
      at its own seeded phase 2 pi hash(w, seed); seed 1 is the prototype's (rule 8).
    - Level taper (brief keyboard_span_lu): wheels above wheel 36 (C4) lose 1.0 dB per octave.
    Cost: 4 multiplies per wheel per sample, whatever is played. */
class Tonewheels
{
public:
    static constexpr int kWheels = 91;
    static constexpr int kTaperKnee = 36;          // wheel 36 = C4, 261.6 Hz
    static constexpr double kTaperDbPerOct = 1.0;  // G2: 0 -> 5.8 LU, 1.0 -> 2.8 LU span on pure wheels

    static double wheelHz (int w) noexcept
    {
        static constexpr double ratio[12] = { 85.0 / 104, 71.0 / 82, 67.0 / 73, 105.0 / 108, 103.0 / 100, 84.0 / 77,
                                              74.0 / 64, 98.0 / 80, 96.0 / 74, 88.0 / 64, 67.0 / 46, 108.0 / 70 };
        return 20.0 * ratio[w % 12] * std::pow (2.0, (double) (w / 12 + 1));
    }

    void prepare (double sampleRate, int seed) noexcept
    {
        for (int w = 0; w < kWheels; ++w)
        {
            const double wT = 2.0 * 3.141592653589793 * wheelHz (w) / sampleRate;
            c[w] = std::cos (wT);
            s[w] = std::sin (wT);
            const double p = 2.0 * 3.141592653589793 * hash ((double) w, (double) seed);
            cp[w] = std::cos (p);
            sp[w] = std::sin (p);
            const int above = w - kTaperKnee > 0 ? w - kTaperKnee : 0;
            taper[w] = std::pow (10.0, (-kTaperDbPerOct * (double) above / 12.0) / 20.0);
        }
        reset();
    }

    void reset() noexcept
    {
        for (int w = 0; w < kWheels; ++w) { x[w] = 0.0; y[w] = 0.0; }
        first = true;
    }

    /** Advances every wheel one sample; out[] holds the tapered values. */
    inline void tick() noexcept
    {
        if (first)
        {
            for (int w = 0; w < kWheels; ++w) { x[w] = cp[w]; y[w] = sp[w]; out[w] = y[w] * taper[w]; }
            first = false;
            return;
        }
        for (int w = 0; w < kWheels; ++w)
        {
            const double nx = c[w] * x[w] - s[w] * y[w];
            const double ny = s[w] * x[w] + c[w] * y[w];
            x[w] = nx;
            y[w] = ny;
            out[w] = ny * taper[w];
        }
    }

    double out[kWheels] {};

private:
    double c[kWheels] {}, s[kWheels] {}, cp[kWheels] {}, sp[kWheels] {}, taper[kWheels] {};
    double x[kWheels] {}, y[kWheels] {};
    bool first = true;
};
} // namespace sundayorgan::dsp
