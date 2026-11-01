#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

namespace sundayorgan::dsp
{
/*  Safety limiter - the last stage (brief amendment 2026-11-01): the output never above -1 dBTP,
    so the clean preamp's full organ (up to +13 dBFS before it) does not clip in the host. S.2
    "peak / true-peak limiter" and "output safety stage" (E.1, F.6.1):
      - true-peak detection: the sample and three 4x points of each interval from a 12-tap
        Kaiser-windowed sinc (within 0.012 dB of the true peak up to 15 kHz, -0.3 dB at 20 kHz),
        judged against -1.7 dBFS (the 0.7 dB margin for the 4x under-read); channels linked
      - gain path in the "1 - gain" domain (zero = no limiting, so empty buffers start
        transparent): sliding maximum over W samples -> instant attack, 150 ms release ->
        moving average over the same W samples: the gain at each output sample is at most the
        gain its interval needed (a guaranteed ceiling)
      - the audio delayed by the look-ahead, 1.5 ms in seconds (rule 12): 6 samples of
        interpolator plus W - 1, reported to the host (rule 7)
      - a clamp at -1 dBFS last; below the ceiling the gain is exactly 1 (a pure delay).
    Prototype: `limiter` in tonewheel.dsp v0.7. prepare() allocates, tick() does not (rule 1). */
class Limiter
{
public:
    static constexpr double kLookaheadSeconds = 0.0015, kReleaseSeconds = 0.15;
    static constexpr double kDetectCeilingDb = -1.7, kClampDb = -1.0;
    static constexpr int kTaps = 12, kInterpDelay = 6;

    void prepare (double sampleRate)
    {
        // Faust: max(6, int(x + 0.5)) and max(1, LA - 6 + 1); the bounds only matter below 4 kHz, where the
        // window went negative and the allocation threw (the Steinberg validator's low rates, F-14)
        latency = std::max (kInterpDelay, (int) (kLookaheadSeconds * sampleRate + 0.5));
        window = std::max (1, latency - kInterpDelay + 1);
        release = 1.0 - std::exp (-1.0 / (kReleaseSeconds * sampleRate));
        ceiling = std::pow (10.0, kDetectCeilingDb / 20.0);
        clamp = std::pow (10.0, kClampDb / 20.0);
        delayL.assign ((size_t) latency + 1, 0.0);
        delayR.assign ((size_t) latency + 1, 0.0);
        dHistory.assign ((size_t) window, 0.0);
        maxIndex.assign ((size_t) window + 1, 0);
        maxValue.assign ((size_t) window + 1, 0.0);
        reset();
    }

    void reset() noexcept
    {
        std::fill (std::begin (histL), std::end (histL), 0.0);
        std::fill (std::begin (histR), std::end (histR), 0.0);
        std::fill (delayL.begin(), delayL.end(), 0.0);
        std::fill (delayR.begin(), delayR.end(), 0.0);
        std::fill (dHistory.begin(), dHistory.end(), 0.0);
        qPrevL = qPrevR = dPrev = sumD = 0.0;
        n = 0; head = tail = 0; delayPos = dPos = 0; resync = 0;
    }

    int latencySamples() const noexcept { return latency; }

    inline void tick (double& l, double& r) noexcept
    {
        // the interpolator's input: x(n - k) = hist[k]
        for (int k = kTaps - 1; k > 0; --k) { histL[k] = histL[k - 1]; histR[k] = histR[k - 1]; }
        histL[0] = l;
        histR[0] = r;
        const double qL = intervalPeak (histL), qR = intervalPeak (histR);
        const double p = std::max (std::max (qL, qPrevL), std::max (qR, qPrevR));
        qPrevL = qL;
        qPrevR = qR;
        const double need = p > ceiling ? ceiling / p : 1.0;
        const double hold = slidingMax (1.0 - need);
        const double d = hold > dPrev ? hold : dPrev + (hold - dPrev) * release;
        dPrev = d;
        sumD += d - dHistory[(size_t) dPos];
        dHistory[(size_t) dPos] = d;
        dPos = dPos + 1 == window ? 0 : dPos + 1;
        if (++resync == window * 64)                                   // bound the running sum's rounding
        {
            resync = 0;
            sumD = 0.0;
            for (double v : dHistory) sumD += v;
        }
        const double gain = 1.0 - sumD / (double) window;
        // the audio, delayed by the look-ahead
        delayL[(size_t) delayPos] = l;
        delayR[(size_t) delayPos] = r;
        delayPos = delayPos == latency ? 0 : delayPos + 1;
        l = std::clamp (delayL[(size_t) delayPos] * gain, -clamp, clamp);
        r = std::clamp (delayR[(size_t) delayPos] * gain, -clamp, clamp);
        ++n;
    }

private:
    // the 4x points between x(m) and x(m + 1), m = n - 6: y(m + f) = sum_j h_f[j] x(m - 5 + j)
    static constexpr double kH25[kTaps] = { -0.0032106803241792226, 0.011168525649608463, -0.02924934558578925, 0.06713438411781004,
                                            -0.15966649564914037, 0.8965575014528838, 0.28757505015099777, -0.10135271132555973,
                                            0.04468577126295041, -0.01852237924615813, 0.006288334920380892, -0.0014079554238045431 };
    static constexpr double kH50[kTaps] = { -0.003081207136115268, 0.011973239254107928, -0.03308989616403061, 0.07754320866066451,
                                            -0.17833143278877375, 0.6249860881741472, 0.6249860881741472, -0.17833143278877375,
                                            0.07754320866066451, -0.03308989616403061, 0.011973239254107928, -0.003081207136115268 };
    static constexpr double kH75[kTaps] = { -0.001407955423804543, 0.006288334920380891, -0.018522379246158127, 0.04468577126295041,
                                            -0.10135271132555972, 0.2875750501509977, 0.8965575014528837, -0.15966649564914034,
                                            0.06713438411781003, -0.029249345585789246, 0.011168525649608461, -0.003210680324179222 };

    static double interpolate (const double* h, const double* hist) noexcept
    {
        double y = 0.0;
        for (int j = 0; j < kTaps; ++j) y += h[j] * hist[kTaps - 1 - j];
        return y;
    }

    static double intervalPeak (const double* hist) noexcept
    {
        return std::max (std::abs (hist[kInterpDelay]),
                         std::max (std::abs (interpolate (kH25, hist)), std::max (std::abs (interpolate (kH50, hist)), std::abs (interpolate (kH75, hist)))));
    }

    // the maximum of the last `window` values: a monotonic queue in fixed arrays
    double slidingMax (double v) noexcept
    {
        const int cap = window + 1;
        while (head != tail && maxValue[(size_t) (tail == 0 ? cap - 1 : tail - 1)] <= v)
            tail = tail == 0 ? cap - 1 : tail - 1;
        maxIndex[(size_t) tail] = n;
        maxValue[(size_t) tail] = v;
        tail = tail + 1 == cap ? 0 : tail + 1;
        if (maxIndex[(size_t) head] <= n - window)
            head = head + 1 == cap ? 0 : head + 1;
        return maxValue[(size_t) head];
    }

    double histL[kTaps] {}, histR[kTaps] {};
    std::vector<double> delayL, delayR, dHistory, maxValue;
    std::vector<long long> maxIndex;
    double qPrevL = 0.0, qPrevR = 0.0, dPrev = 0.0, sumD = 0.0;
    double release = 0.0, ceiling = 1.0, clamp = 1.0;
    long long n = 0;
    int latency = 0, window = 1, head = 0, tail = 0, delayPos = 0, dPos = 0, resync = 0;
};
} // namespace sundayorgan::dsp
