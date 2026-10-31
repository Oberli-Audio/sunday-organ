// Offline render harness for the sketch: scripted events -> stereo float WAV.
// Events are applied at block starts (TW_BLOCK, default 32 samples = 0.67 ms at 48 kHz),
// documented quantisation. TW_TIMES=<file> writes the compute time of every block.
#define FAUSTFLOAT double
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "faust/gui/MapUI.h"
#include "faust/gui/meta.h"
#include "faust/dsp/dsp.h"

<<includeIntrinsic>>
<<includeclass>>

struct Ev { double t; std::string label; double v; };

static void wavWrite(const char* path, const std::vector<float>& d, int sr) {
    FILE* f = fopen(path, "wb");
    uint32_t dataBytes = d.size() * 4, riff = 36 + dataBytes, fmt = 16, sr32 = sr, br = sr * 8;
    uint16_t fmtTag = 3, ch = 2, ba = 8, bits = 32;
    fwrite("RIFF", 1, 4, f); fwrite(&riff, 4, 1, f); fwrite("WAVEfmt ", 1, 8, f);
    fwrite(&fmt, 4, 1, f); fwrite(&fmtTag, 2, 1, f); fwrite(&ch, 2, 1, f);
    fwrite(&sr32, 4, 1, f); fwrite(&br, 4, 1, f); fwrite(&ba, 2, 1, f); fwrite(&bits, 2, 1, f);
    fwrite("data", 1, 4, f); fwrite(&dataBytes, 4, 1, f); fwrite(d.data(), 4, d.size(), f);
    fclose(f);
}

int main(int argc, char** argv) {
    if (argc < 5) { fprintf(stderr, "usage: render events.txt out.wav seconds sr\n"); return 1; }
    double secs = atof(argv[3]); int sr = atoi(argv[4]);
    std::vector<Ev> ev; std::ifstream in(argv[1]); std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        // format: time|label|value
        std::stringstream ss(line); std::string a, b, c;
        std::getline(ss, a, '|'); std::getline(ss, b, '|'); std::getline(ss, c, '|');
        ev.push_back({atof(a.c_str()), b, atof(c.c_str())});
    }
    std::sort(ev.begin(), ev.end(), [](const Ev& x, const Ev& y){ return x.t < y.t; });
    Tonewheel dsp; MapUI ui; dsp.buildUserInterface(&ui); dsp.init(sr);
    const char* bs = getenv("TW_BLOCK"); const int B = bs ? atoi(bs) : 32;
    const char* tp = getenv("TW_TIMES"); std::vector<double> times; long N = (long)(secs * sr);
    std::vector<double> l(B), r(B); double* outs[2] = { l.data(), r.data() };
    std::vector<float> out; out.reserve(N * 2); size_t ei = 0;
    for (long n = 0; n < N; n += B) {
        while (ei < ev.size() && ev[ei].t * sr <= n) {
            ui.setParamValue(ev[ei].label, ev[ei].v); ei++;
        }
        int b = (int)std::min<long>(B, N - n);
        auto t0 = std::chrono::steady_clock::now();
        dsp.compute(b, nullptr, outs);
        if (tp) times.push_back(std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count());
        for (int i = 0; i < b; i++) { out.push_back((float)l[i]); out.push_back((float)r[i]); }
    }
    wavWrite(argv[2], out, sr);
    if (tp) { FILE* f = fopen(tp, "w"); for (double t : times) fprintf(f, "%.9f\n", t); fclose(f); }
    return 0;
}
