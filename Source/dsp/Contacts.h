#pragma once

#include "OrganMath.h"
#include "Tonewheels.h"

#include <cstdint>

namespace sundayorgan::dsp
{
/*  Contacts - what a key does: 9 contacts per key switch 9 wheels onto the 9 drawbar busses.

    Prototype: `contact`, `tapWheel`, `fold`, `leakWheel`, `tap`, `c1`, `c2` in tonewheel.dsp v0.5.
    - Each contact closes D_t = int(0.004 s * click * hash(kk, t + 2) * fs) samples after the key
      (up to 4 ms between contacts at Key Click 100 %) and ramps linearly over
      0.2 ms + 4 ms (1 - click): switching a running sine mid-cycle is the key click (defining
      feature). The ramp is en.asr's: counters, so a re-press restarts the ramp from 0.
    - Drawbar t taps wheel fold(k + 12 + offset[t]); above wheel 90 the top octave folds back.
    - Leakage: each contact also picks up two other wheels (+-1 or 2 octaves, seeded), at
      0.0316 (-30 dB) x Leakage x hash.
    - kk is the contact set: 0-60 the channel-1 keys, 61-121 the channel-2 (lower) keys, so the two
      manuals' contacts differ like two real manuals.
    Key Click is read at note-on (parameters.csv, control_rate event); the prototype reads it per
    block - the two agree unless Key Click moves while a key is down.
    Real time: only keys that are down or still ramping are visited (an index list, fixed size,
    no allocation); a key's contacts cost about 25 flops per sample while it is active. */
class ContactKeys
{
public:
    static constexpr int kKeys = 61;     // C2-C7, MIDI 36-96
    static constexpr int kBars = 9;
    static constexpr int kHistory = 8;   // gate transitions remembered inside the 4 ms window

    static int offset (int t) noexcept { static constexpr int o[kBars] = { -12, 7, 0, 12, 19, 24, 28, 31, 36 }; return o[t]; }
    static int fold (int w) noexcept { const int up = (w - 90 + 11) / 12; return w - 12 * (up > 0 ? up : 0); }
    static int tapWheel (int k, int t) noexcept { return fold (k + 12 + offset (t)); }

    void prepare (double sampleRate, int setOffset) noexcept
    {
        fs = sampleRate;
        for (int k = 0; k < kKeys; ++k)
        {
            Key& key = keys[k];
            const double kk = (double) (k + setOffset);
            for (int t = 0; t < kBars; ++t)
            {
                static constexpr int partner[4] = { -24, -12, 12, 24 };
                key.wheel[t] = tapWheel (k, t);
                for (int j = 1; j <= 2; ++j)
                {
                    const int pick = (int) (4.0 * hash (kk * 9 + t, (double) (j + 7)));
                    const int lw = key.wheel[t] + partner[pick];
                    (j == 1 ? key.leak1[t] : key.leak2[t]) = fold (lw > 0 ? lw : 0);
                }
                key.h1[t] = hash (kk, (double) (t + 30));
                key.h2[t] = hash (kk, (double) (t + 40));
                key.hDelay[t] = hash (kk, (double) (t + 2));
            }
        }
        maxDelay = (int) (0.004 * fs) + 1;
        reset();
    }

    void reset() noexcept
    {
        for (auto& key : keys)
        {
            key.gate = false; key.base = false; key.nEv = 0; key.active = false;
            for (int t = 0; t < kBars; ++t) { key.a[t] = 0.0; key.r[t] = 0; key.g[t] = false; key.D[t] = 0; }
        }
        numActive = 0;
        now = 0;
    }

    /** Contact timing from Key Click (0-1); read at the next note-on. */
    void setClick (double click) noexcept { clickNow = click; }

    /** The key's gate (after sustain and pedal-split routing) changes at this sample. */
    void setGate (int k, bool on) noexcept
    {
        Key& key = keys[k];
        if (key.gate == on)
            return;
        if (on)
        {
            const double spread = 0.004 * clickNow;          // s between contacts
            const double ramp = 0.0002 + 0.004 * (1.0 - clickNow);
            for (int t = 0; t < kBars; ++t)
                key.D[t] = (int) (spread * key.hDelay[t] * fs);
            key.delta = 1.0 / (ramp * fs > 1.0 ? ramp * fs : 1.0);
        }
        if (key.nEv == kHistory)                               // fold the oldest into the base value
        {
            key.base = key.ev[0].v;
            for (int i = 1; i < kHistory; ++i) key.ev[i - 1] = key.ev[i];
            --key.nEv;
        }
        key.ev[key.nEv++] = { now, on };
        key.gate = on;
        if (! key.active)
        {
            key.active = true;
            active[numActive++] = k;
        }
    }

    bool gate (int k) const noexcept { return keys[k].gate; }
    int activeKeys() const noexcept { return numActive; }

    /** One sample: adds every active contact into the busses. upperShare[k] = share of key k on
        the upper busses (1 for an upper key; nullptr: everything to `lower`). */
    inline void tick (const double* wheel, double leak, const double* upperShare, double* upper, double* lower) noexcept
    {
        for (int i = 0; i < numActive;)
        {
            Key& key = keys[active[i]];
            bool sounding = false;
            for (int t = 0; t < kBars; ++t)
            {
                const bool gd = key.gateAt (now - key.D[t]);
                key.a[t] = (key.g[t] >= gd ? key.a[t] : 0.0) + (gd ? 1.0 : 0.0);
                key.r[t] = gd ? 0 : key.r[t] + 1;
                key.g[t] = gd;
                double env = (key.delta * key.a[t] < 1.0 ? key.delta * key.a[t] : 1.0) - key.delta * (double) key.r[t];
                if (env <= 0.0)
                    continue;
                sounding = true;
                const double tap = wheel[key.wheel[t]]
                                 + leak * 0.0316 * (wheel[key.leak1[t]] * key.h1[t] + wheel[key.leak2[t]] * key.h2[t]);
                const double c = env * tap;
                if (upperShare != nullptr)
                {
                    const double u = upperShare[active[i]];
                    upper[t] += u * c;
                    lower[t] += (1.0 - u) * c;
                }
                else
                    lower[t] += c;
            }
            if (! sounding && ! key.gate && now - key.lastEvent() > (int64_t) maxDelay + 1)
            {
                for (int t = 0; t < kBars; ++t) key.a[t] = 0.0;   // never revives: env = -delta r <= 0
                key.active = false;
                key.nEv = 0;
                key.base = false;
                active[i] = active[--numActive];
                continue;
            }
            ++i;
        }
        ++now;
    }

private:
    struct Event { int64_t t; bool v; };
    struct Key
    {
        int wheel[kBars] {}, leak1[kBars] {}, leak2[kBars] {};
        double h1[kBars] {}, h2[kBars] {}, hDelay[kBars] {};
        int D[kBars] {};
        double delta = 1.0;
        Event ev[kHistory] {};
        int nEv = 0;
        bool base = false, gate = false, active = false;
        double a[kBars] {};
        int r[kBars] {};
        bool g[kBars] {};

        bool gateAt (int64_t m) const noexcept
        {
            for (int i = nEv - 1; i >= 0; --i)
                if (ev[i].t <= m)
                    return ev[i].v;
            return base;
        }
        int64_t lastEvent() const noexcept { return nEv > 0 ? ev[nEv - 1].t : INT64_MIN / 2; }
    };

    Key keys[kKeys];
    int active[kKeys] {};
    int numActive = 0;
    int maxDelay = 0;
    int64_t now = 0;
    double fs = 48000.0, clickNow = 0.5;
};

/*  Pedal contacts: 25 keys C1-C3 (MIDI 24-48). 16' = the key's own wheel, 8' an octave up; the
    contacts close together (not staggered), en.asr(2 ms, 1, Pedal Release). Prototype: `pcontact`,
    `pedalSig`. No sustain latch on the pedals. */
class PedalContacts
{
public:
    static constexpr int kPedals = 25;

    void prepare (double sampleRate) noexcept { fs = sampleRate; attackDelta = 1.0 / (0.002 * fs > 1.0 ? 0.002 * fs : 1.0); reset(); }
    void reset() noexcept
    {
        for (auto& p : pedals) p = Pedal {};
        numActive = 0;
    }
    void setRelease (double seconds) noexcept { releaseDelta = 1.0 / (seconds * fs > 1.0 ? seconds * fs : 1.0); }

    void setGate (int p, bool on) noexcept
    {
        Pedal& ped = pedals[p];
        ped.gate = on;
        if (on && ! ped.active) { ped.active = true; active[numActive++] = p; }
    }

    /** One sample: the pedal signal for the drawbar gains g16, g8. */
    inline double tick (const double* wheel, double g16, double g8) noexcept
    {
        double sum = 0.0;
        for (int i = 0; i < numActive;)
        {
            const int p = active[i];
            Pedal& ped = pedals[p];
            const bool gd = ped.gate;
            ped.a = (ped.g >= gd ? ped.a : 0.0) + (gd ? 1.0 : 0.0);
            ped.r = gd ? 0 : ped.r + 1;
            ped.g = gd;
            const double env = (attackDelta * ped.a < 1.0 ? attackDelta * ped.a : 1.0) - releaseDelta * (double) ped.r;
            if (env > 0.0)
                sum += env * (g16 * wheel[p] + g8 * wheel[p + 12]);
            else if (! gd)
            {
                ped.a = 0.0;
                ped.active = false;
                active[i] = active[--numActive];
                continue;
            }
            ++i;
        }
        return sum;
    }

private:
    struct Pedal { double a = 0.0; int r = 0; bool g = false, gate = false, active = false; };
    Pedal pedals[kPedals];
    int active[kPedals] {};
    int numActive = 0;
    double fs = 48000.0, attackDelta = 1.0, releaseDelta = 1.0;
};
} // namespace sundayorgan::dsp
