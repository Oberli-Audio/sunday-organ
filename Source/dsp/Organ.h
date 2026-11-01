#pragma once

#include <initializer_list>

#include "Busses.h"
#include "Contacts.h"
#include "Leslie.h"
#include "Limiter.h"
#include "Scanner.h"
#include "Tonewheels.h"

namespace sundayorgan::dsp
{
/*  The whole instrument, one sample at a time, in the prototype's order (tonewheel.dsp v0.5,
    `process`):
        wheels -> contacts (ch1 keys, ch2 keys) -> busses + percussion -> scanner (upper, and
        lower when Vibrato Lower) -> + lower dry + pedals -> x 0.06 x expression^2 -> preamp
        -> x 0.35 x volume -> Leslie -> safety limiter (1.5 ms look-ahead, -1 dBTP) -> L/R
    MIDI routing (brief must_do; rule 14, rule 16):
        channel 2 = lower manual, channel 3 = pedals, every other channel = channel 1 (upper):
        keys below Split Key play the lower manual (crossfaded per key over 10 ms when the split
        moves, so it never clicks), keys below Pedal Split play the pedals at pitch (decided when
        the key goes down). C2-C7 on the manuals, C1-C3 on the pedals; outside, a key is ignored.
        CC64 latches the manual keys of its own channel (channel 1 or 2); the pedals do not latch.
    Every change arrives between two render() calls; the processor splits its block at each MIDI
    event (rule 16), so every event lands on its sample. No allocation anywhere (rule 1). */
class Organ
{
public:
    static constexpr int kLowestManual = 36, kHighestManual = 96, kLowestPedal = 24, kHighestPedal = 48;

    struct Settings
    {
        int upper[9] { 8, 8, 8, 0, 0, 0, 0, 0, 0 }, lower[9] { 0, 0, 8, 0, 8, 0, 0, 0, 0 };
        bool percOn = false, percThird = false, percSlow = false, percSoft = false;
        int vibratoMode = 0;
        bool vibratoLower = false, fast = false, brake = false, leslieOn = true;
        double micSpreadDeg = 120.0, drive = 0.2, click = 0.5, leakage = 0.3, expression = 1.0, volumeDb = 0.0;
        int pedal16 = 6, pedal8 = 3;
        double pedalRelease = 0.08;
        int splitKey = 36, pedalSplit = 24;
    };

    void prepare (double sampleRate, int seed)                     // allocates (the limiter's delay)
    {
        fs = sampleRate;
        wheels.prepare (fs, seed);
        upperKeys.prepare (fs, 0);
        lowerKeys.prepare (fs, ContactKeys::kKeys);
        pedals.prepare (fs);
        busses.prepare (fs);
        percussion.prepare (fs);
        scanner.prepare (fs);
        preamp.prepare (fs);
        leslie.prepare (fs);
        limiter.prepare (fs);
        for (auto& u : isUpper) u.setTau (0.01, fs);
        for (auto* s : { &leak, &expr, &vol, &vibLower }) s->setTau (0.02, fs);
        ped16.setTau (0.015, fs);
        ped8.setTau (0.015, fs);
    }

    /** Clears every state (rule 8). fromZero = the prototype's start (every smoother and both
        rotors at 0, for the G5 null test); otherwise they start at their targets. */
    void reset (bool fromZero = false) noexcept
    {
        wheels.reset();
        upperKeys.reset(); lowerKeys.reset(); pedals.reset();
        for (int k = 0; k < ContactKeys::kKeys; ++k) { key1[k] = held1[k] = isPed1[k] = false; key2[k] = held2[k] = false; }
        for (int j = 0; j < 12; ++j) { lowKey1[j] = isPedLow1[j] = false; }
        for (int p = 0; p < PedalContacts::kPedals; ++p) ped3[p] = false;
        sustain1 = sustain2 = false;
        apply (settings);
        busses.reset (fromZero);
        percussion.reset (fromZero);
        scanner.reset (fromZero);
        preamp.reset (fromZero);
        leslie.reset (fromZero);
        limiter.reset();
        for (int k = 0; k < ContactKeys::kKeys; ++k) isUpper[k].reset (fromZero ? 0.0 : upperTarget (k));
        leak.reset (fromZero ? 0.0 : settings.leakage);
        expr.reset (fromZero ? 0.0 : exprTarget());
        vol.reset (fromZero ? 0.0 : volTarget());
        vibLower.reset (fromZero ? 0.0 : (settings.vibratoLower ? 1.0 : 0.0));
        ped16.reset (fromZero ? 0.0 : drawbarGain (settings.pedal16));
        ped8.reset (fromZero ? 0.0 : drawbarGain (settings.pedal8));
    }

    void apply (const Settings& s) noexcept
    {
        settings = s;
        busses.setDrawbars (s.upper, s.lower, s.percOn);
        percussion.set (s.percThird, s.percSlow, s.percSoft);
        scanner.setMode (s.vibratoMode);
        preamp.setDrive (s.drive);
        leslie.set (s.fast, s.brake, s.micSpreadDeg, s.leslieOn);
        upperKeys.setClick (s.click);
        lowerKeys.setClick (s.click);
        pedals.setRelease (s.pedalRelease);
    }
    const Settings& current() const noexcept { return settings; }

    // ---------------------------------------------------------------- MIDI (channels 1-16)
    void noteOn (int channel, int note) noexcept
    {
        if (channel == 3)
        {
            if (note >= kLowestPedal && note <= kHighestPedal) { ped3[note - kLowestPedal] = true; updatePedal (note - kLowestPedal); }
            return;
        }
        if (channel == 2)
        {
            if (note < kLowestManual || note > kHighestManual) return;
            const int k = note - kLowestManual;
            key2[k] = held2[k] = true;
            lowerKeys.setGate (k, true);
            return;
        }
        if (note >= kLowestPedal && note < kLowestManual)      // channel 1 below C2: pedals only
        {
            const int j = note - kLowestPedal;
            lowKey1[j] = true;
            isPedLow1[j] = note < settings.pedalSplit;
            updatePedal (j);
            return;
        }
        if (note < kLowestManual || note > kHighestManual) return;
        const int k = note - kLowestManual;
        key1[k] = held1[k] = true;
        isPed1[k] = note < settings.pedalSplit;               // ba.sAndH at the key's rising edge
        update1 (k);
        if (note - kLowestPedal < PedalContacts::kPedals) updatePedal (note - kLowestPedal);
    }

    void noteOff (int channel, int note) noexcept
    {
        if (channel == 3)
        {
            if (note >= kLowestPedal && note <= kHighestPedal) { ped3[note - kLowestPedal] = false; updatePedal (note - kLowestPedal); }
            return;
        }
        if (channel == 2)
        {
            if (note < kLowestManual || note > kHighestManual) return;
            const int k = note - kLowestManual;
            key2[k] = false;
            held2[k] = sustain2 && held2[k];
            lowerKeys.setGate (k, held2[k]);
            return;
        }
        if (note >= kLowestPedal && note < kLowestManual) { lowKey1[note - kLowestPedal] = false; updatePedal (note - kLowestPedal); return; }
        if (note < kLowestManual || note > kHighestManual) return;
        const int k = note - kLowestManual;
        key1[k] = false;
        held1[k] = sustain1 && held1[k];
        update1 (k);
        if (note - kLowestPedal < PedalContacts::kPedals) updatePedal (note - kLowestPedal);
    }

    void sustain (int channel, bool down) noexcept
    {
        if (channel == 3) return;                               // the pedals do not latch
        if (channel == 2)
        {
            sustain2 = down;
            if (! down) for (int k = 0; k < ContactKeys::kKeys; ++k) { held2[k] = key2[k]; lowerKeys.setGate (k, held2[k]); }
            return;
        }
        sustain1 = down;
        if (! down) for (int k = 0; k < ContactKeys::kKeys; ++k) { held1[k] = key1[k]; update1 (k); }
    }

    /** Every note off, sustain up (rule 16: stop, preset change, deactivation). The contacts
        release with their ramps; nothing is cut. */
    void allNotesOff() noexcept
    {
        sustain1 = sustain2 = false;
        for (int k = 0; k < ContactKeys::kKeys; ++k)
        {
            key1[k] = held1[k] = false; update1 (k);
            key2[k] = held2[k] = false; lowerKeys.setGate (k, false);
        }
        for (int j = 0; j < 12; ++j) lowKey1[j] = false;
        for (int p = 0; p < PedalContacts::kPedals; ++p) { ped3[p] = false; updatePedal (p); }
    }

    // ---------------------------------------------------------------- render
    /** Probe points for G5's module null tests (harness --solo); Out is the instrument. */
    enum class Probe { out, upper, lower, pedals, voices, preamp, crossover };
    void setProbe (Probe p) noexcept { probe = p; }

    void render (float* outL, float* outR, int n) noexcept
    {
        bool anyUpper = false;
        for (int k = 0; k < ContactKeys::kKeys; ++k)
            if (upperKeys.gate (k) && k + kLowestManual >= settings.splitKey) { anyUpper = true; break; }
        const double exprT = exprTarget(), volT = volTarget(), vlT = settings.vibratoLower ? 1.0 : 0.0;
        const double p16T = drawbarGain (settings.pedal16), p8T = drawbarGain (settings.pedal8);
        double upperTargets[ContactKeys::kKeys];
        for (int k = 0; k < ContactKeys::kKeys; ++k) upperTargets[k] = upperTarget (k);

        for (int i = 0; i < n; ++i)
        {
            wheels.tick();
            for (int k = 0; k < ContactKeys::kKeys; ++k) upperShare[k] = isUpper[k].tick (upperTargets[k]);
            double ub[9] {}, lb[9] {};
            const double lk = leak.tick (settings.leakage);
            upperKeys.tick (wheels.out, lk, upperShare, ub, lb);
            lowerKeys.tick (wheels.out, lk, nullptr, ub, lb);
            const double perc = percussion.tick (anyUpper, ub);
            double upperSig, lowerSig;
            busses.tick (ub, lb, perc, upperSig, lowerSig);
            const double pedalSig = pedals.tick (wheels.out, ped16.tick (p16T), ped8.tick (p8T));
            const double vl = vibLower.tick (vlT);
            const double voices = scanner.tick (upperSig + vl * lowerSig) + (1.0 - vl) * lowerSig + pedalSig;
            const double x = voices * 0.06 * expr.tick (exprT);
            const double y = preamp.tick (x) * (0.35 * vol.tick (volT));
            double l, r;
            switch (probe)
            {
                case Probe::upper:     l = r = upperSig; break;
                case Probe::lower:     l = r = lowerSig; break;
                case Probe::pedals:    l = r = pedalSig; break;
                case Probe::voices:    l = r = voices; break;
                case Probe::preamp:    l = r = y; break;
                case Probe::crossover: l = r = leslie.crossoverOnly (y); break;
                case Probe::out:
                default:               leslie.tick (y, l, r); limiter.tick (l, r); break;
            }
            outL[i] = (float) l;
            outR[i] = (float) r;
        }
    }

    double hornHz() const noexcept { return leslie.hornHz(); }
    double drumHz() const noexcept { return leslie.drumHz(); }
    double hornAngle() const noexcept { return leslie.hornAngle(); }
    double drumAngle() const noexcept { return leslie.drumAngle(); }
    int latencySamples() const noexcept { return limiter.latencySamples(); }
    int activeKeys() const noexcept { return upperKeys.activeKeys() + lowerKeys.activeKeys(); }

private:
    double upperTarget (int k) const noexcept { return k + kLowestManual >= settings.splitKey ? 1.0 : 0.0; }
    double exprTarget() const noexcept { return settings.expression * settings.expression; }   // e^2: half travel -12 dB
    double volTarget() const noexcept { return std::pow (10.0, settings.volumeDb / 20.0); }
    void update1 (int k) noexcept { upperKeys.setGate (k, held1[k] && ! isPed1[k]); }
    void updatePedal (int p) noexcept
    {
        bool g = ped3[p];
        if (p < 12) g = g || (lowKey1[p] && isPedLow1[p]);
        else if (p < 24) g = g || (key1[p - 12] && isPed1[p - 12]);
        pedals.setGate (p, g);
    }

    Settings settings;
    Tonewheels wheels;
    ContactKeys upperKeys, lowerKeys;
    PedalContacts pedals;
    Busses busses;
    Percussion percussion;
    Scanner scanner;
    Preamp preamp;
    Leslie leslie;
    Limiter limiter;
    OnePole isUpper[ContactKeys::kKeys], leak, expr, vol, vibLower, ped16, ped8;
    double upperShare[ContactKeys::kKeys] {};
    bool key1[ContactKeys::kKeys] {}, held1[ContactKeys::kKeys] {}, isPed1[ContactKeys::kKeys] {};
    bool key2[ContactKeys::kKeys] {}, held2[ContactKeys::kKeys] {};
    bool lowKey1[12] {}, isPedLow1[12] {}, ped3[PedalContacts::kPedals] {};
    bool sustain1 = false, sustain2 = false;
    double fs = 48000.0;
    Probe probe = Probe::out;
};
} // namespace sundayorgan::dsp
