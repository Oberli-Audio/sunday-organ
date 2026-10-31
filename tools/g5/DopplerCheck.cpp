// G5 Doppler render (rule 13, defining feature "Leslie Doppler of a moving source"): a 2 kHz tone
// through the plugin's own horn path (dsp::Leslie::dopplerProbe) at a constant 6.67 Hz, as
// `sound design/tests/doppler_test.dsp` renders the prototype. Left = delay only, right = the full
// path. Usage: SundayOrganDopplerCheck <out.wav> [seconds] [rate] [doppler|impulse]; then
// tools/g5/doppler_check.py. `impulse` (tools/measure/metrics.py, response_error_db): channel 1 =
// the crossover alone (Leslie::crossoverOnly), 2 and 3 = the whole Leslie, rotors braked from rest.
#include "../../Source/dsp/Leslie.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

int main (int argc, char** argv)
{
    if (argc < 2) { std::fprintf (stderr, "usage: SundayOrganDopplerCheck out.wav [seconds] [rate]\n"); return 2; }
    const double seconds = argc > 2 ? std::atof (argv[2]) : 3.0, fs = argc > 3 ? std::atof (argv[3]) : 48000.0;
    const bool impulse = argc > 4 && std::string (argv[4]) == "impulse";
    const int nch = impulse ? 3 : 2;
    sundayorgan::dsp::Leslie leslie, braked;
    leslie.prepare (fs);
    leslie.reset (true);
    braked.prepare (fs);
    braked.set (false, true, 120.0, true);
    braked.reset (true);
    const auto n = (long) (seconds * fs);
    std::vector<float> out ((size_t) n * (size_t) nch);
    for (long i = 0; i < n; ++i)
    {
        if (impulse)
        {
            const double x = i == 0 ? 1.0 : 0.0;
            double l, r;
            out[(size_t) i * 3] = (float) leslie.crossoverOnly (x);
            braked.tick (x, l, r);
            out[(size_t) i * 3 + 1] = (float) l;
            out[(size_t) i * 3 + 2] = (float) r;
            continue;
        }
        const double x = std::sin (2.0 * 3.141592653589793 * 2000.0 * (double) i / fs);
        double d, f;
        leslie.dopplerProbe (x, 6.67, d, f);
        out[(size_t) i * 2] = (float) d;
        out[(size_t) i * 2 + 1] = (float) f;
    }
    FILE* fp = std::fopen (argv[1], "wb");
    if (fp == nullptr) return 2;
    const uint32_t data = (uint32_t) (out.size() * 4), riff = 36 + data, fmtLen = 16, rate = (uint32_t) fs, bytesPerSec = rate * 4 * (uint32_t) nch;
    const uint16_t fmt = 3, ch = (uint16_t) nch, align = (uint16_t) (4 * nch), bits = 32;
    std::fwrite ("RIFF", 1, 4, fp); std::fwrite (&riff, 4, 1, fp); std::fwrite ("WAVEfmt ", 1, 8, fp);
    std::fwrite (&fmtLen, 4, 1, fp); std::fwrite (&fmt, 2, 1, fp); std::fwrite (&ch, 2, 1, fp); std::fwrite (&rate, 4, 1, fp);
    std::fwrite (&bytesPerSec, 4, 1, fp); std::fwrite (&align, 2, 1, fp); std::fwrite (&bits, 2, 1, fp);
    std::fwrite ("data", 1, 4, fp); std::fwrite (&data, 4, 1, fp); std::fwrite (out.data(), 4, out.size(), fp);
    std::fclose (fp);
    return 0;
}
