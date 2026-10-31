// Sunday Organ - Tier P G2 prototype v0.4 (from the Tier S sketch v0.2/v0.3)
// Structure = the port's structure (F.8), one block per module, one C++ class each:
//   Tonewheels (91, shared, tapered) -> Contacts (9 per key, with leakage) -> Busses (9 per
//   manual) -> Percussion (upper) -> Scanner -> + pedals -> expression -> Preamp -> Leslie
// MIDI as the plugin: channel 1 = upper, keys below "Split key" play the lower manual and
// keys below "Pedal split" the pedals; channel 2 = lower; channel 3 = pedals. CC1 Leslie
// fast, CC11 expression, CC64 sustain (per channel, manuals only).
// v0.4 (2026-10-31): wheels as exact quadrature oscillators (was a 64k truncated table),
// per-wheel level taper, expression before the preamp, lower manual and pedals on their
// own channels, ch1 pedal split.
// Every time constant is in seconds (rule 12). Every "random" value is a compile-time
// hash of its index, so two runs from reset are bit-identical (rule 8).

declare name "Sunday Organ (prototype)";
declare version "0.0.5";
declare author "Oberli Audio";
import("stdfaust.lib");
sc = library("scanner.lib");
ls = library("leslie.lib");

// ---------------------------------------------------------------- helpers
hash(a, b) = ma.frac(sin(a * 12.9898 + b * 78.233) * 43758.5453) : abs;   // 0..1, constant
smooth(t)  = si.smooth(ba.tau2pole(t));
xfade(sel, a, b) = a * cos(sel * ma.PI / 2) + b * sin(sel * ma.PI / 2);   // equal power
step(n)    = ba.if(n < 0.5, 0, ba.db2linear(-3 * (8 - n)));             // ~3 dB per drawbar step

// ---------------------------------------------------------------- controls (parameters.csv)
upper = (
    hslider("h:Upper/[1]16'", 8, 0, 8, 1),     hslider("h:Upper/[2]5 1/3'", 8, 0, 8, 1),
    hslider("h:Upper/[3]8'", 8, 0, 8, 1),      hslider("h:Upper/[4]4'", 0, 0, 8, 1),
    hslider("h:Upper/[5]2 2/3'", 0, 0, 8, 1),  hslider("h:Upper/[6]2'", 0, 0, 8, 1),
    hslider("h:Upper/[7]1 3/5'", 0, 0, 8, 1),  hslider("h:Upper/[8]1 1/3'", 0, 0, 8, 1),
    hslider("h:Upper/[9]1'", 0, 0, 8, 1)
) : par(i, 9, step : smooth(0.015));
lower = (
    hslider("h:Lower/[1]L 16'", 0, 0, 8, 1),     hslider("h:Lower/[2]L 5 1/3'", 0, 0, 8, 1),
    hslider("h:Lower/[3]L 8'", 8, 0, 8, 1),      hslider("h:Lower/[4]L 4'", 0, 0, 8, 1),
    hslider("h:Lower/[5]L 2 2/3'", 8, 0, 8, 1),  hslider("h:Lower/[6]L 2'", 0, 0, 8, 1),
    hslider("h:Lower/[7]L 1 3/5'", 0, 0, 8, 1),  hslider("h:Lower/[8]L 1 1/3'", 0, 0, 8, 1),
    hslider("h:Lower/[9]L 1'", 0, 0, 8, 1)
) : par(i, 9, step : smooth(0.015));
ub(t) = upper : ba.selector(t, 9);
lb(t) = lower : ba.selector(t, 9);

split     = hslider("h:Voice/[1]Split key", 36, 36, 96, 1);   // keys below play the lower manual
percOn    = checkbox("h:Percussion/[1]On") : smooth(0.015);
percThird = checkbox("h:Percussion/[2]Third") : smooth(0.015);    // off = 2nd, on = 3rd
percSlow  = checkbox("h:Percussion/[3]Slow");
percSoft  = checkbox("h:Percussion/[4]Soft") : smooth(0.015);
vibMode   = hslider("h:Vibrato/[1]Mode", 0, 0, 6, 1);              // 0 off, 1-3 V1-V3, 4-6 C1-C3
vibLower  = checkbox("h:Vibrato/[2]Lower") : smooth(0.02);
click     = hslider("h:Voice/[2]Key click", 0.5, 0, 1, 0.01);
leak      = hslider("h:Voice/[3]Leakage", 0.3, 0, 1, 0.01) : smooth(0.02);
drive     = hslider("h:Voice/[4]Drive", 0.2, 0, 1, 0.01) : smooth(0.02);
volume    = hslider("h:Voice/[5]Volume [unit:dB]", 0, -24, 12, 0.1) : ba.db2linear : smooth(0.02);
pedal     = hslider("h:Voice/[6]Sustain [midi:ctrl 64 1]", 0, 0, 1, 1) > 0.5;    // channel 1
pedal2    = hslider("h:Voice/[7]Sustain 2 [midi:ctrl 64 2]", 0, 0, 1, 1) > 0.5;  // channel 2
// Expression (swell) pedal, CC11: gain = e^2 (half travel -12 dB, 10 % -40 dB, 0 silent),
// before the preamp so it also changes the drive (brief, must_do).
expr      = hslider("h:Voice/[8]Expression [midi:ctrl 11]", 1, 0, 1, 0.01) : ^(2) : smooth(0.02);
psplit    = hslider("h:Voice/[9]Pedal split", 24, 24, 48, 1);   // ch1 keys below play the pedals
pBar16    = hslider("h:Pedals/[1]P 16'", 6, 0, 8, 1) : step : smooth(0.015);
pBar8     = hslider("h:Pedals/[2]P 8'", 3, 0, 8, 1) : step : smooth(0.015);
pRelease  = hslider("h:Pedals/[3]Pedal release [unit:s]", 0.08, 0.01, 1.5, 0.01);
fast      = hslider("h:Leslie/[1]Fast [midi:ctrl 1]", 0, 0, 1, 1) > 0.5;   // mod wheel
brake     = checkbox("h:Leslie/[2]Brake");
leslieOn  = hslider("h:Leslie/[3]Leslie on", 1, 0, 1, 1) : smooth(0.015);
spread    = hslider("h:Leslie/[4]Mic spread [unit:deg]", 120, 0, 180, 1) * ma.PI / 180 : smooth(0.05);

// ---------------------------------------------------------------- tonewheels
// Gear ratios per pitch class (C..B), 20 rev/s motor, teeth doubling per octave:
// wheel 0 = 32.70 Hz ... wheel 90 = 5920 Hz. From Hammond service data - verify at G3.
ratio(pc)  = ba.take(pc + 1, (85/104, 71/82, 67/73, 105/108, 103/100, 84/77,
                              74/64, 98/80, 96/74, 88/64, 67/46, 108/70));
wheelHz(w) = 20.0 * ratio(w % 12) * pow(2, int(w / 12) + 1);
// Exact quadrature oscillator: one complex rotation per sample, started at the wheel's own
// seeded phase. Bit-reproducible in C++ (same operations, double), no table, no truncation.
quad(f, p) = (loop ~ (_, _)) : (!, _)
    with {
        wT = 2 * ma.PI * f / ma.SR;  c = cos(wT);  s = sin(wT);  imp = 1 - 1';
        loop(x, y) = c * x - s * y + imp * cos(p), s * x + c * y + imp * sin(p);
    };
// Per-wheel level taper (the generator's own output curve): wheels above KNEE lose TAPER dB
// per octave, so the keyboard span stays < 6 LU per manual (brief, keyboard_span_lu).
KNEE  = 36;      // wheel 36 = C4 (261.6 Hz)
TAPER = 1.0;     // dB per octave above the knee (numpy pre-study: 0 -> 5.8 LU, 1.0 -> 2.8 LU on pure wheels)
taper(w)   = ba.db2linear(-TAPER * max(0, w - KNEE) / 12);
wheel(w)   = quad(wheelHz(w), 2 * ma.PI * hash(w, 1.0)) * taper(w);   // free-running

// ---------------------------------------------------------------- keys and contacts
NKEYS = 61;                                  // C2 (MIDI 36) .. C7 (MIDI 96); silent outside
offset(t) = ba.take(t + 1, (-12, 7, 0, 12, 19, 24, 28, 31, 36));   // semitones per drawbar
fold(w)   = w - 12 * max(0, int((w - 90 + 11) / 12));              // top foldback
tapWheel(k, t) = fold(k + 12 + offset(t));

// Channel 1: 61 manual keys C2-C7 plus C1-B1 (MIDI 24-35) that only reach the pedals.
key(k)    = button("h:Keys/key %n [midi:key %n 1]") with { n = k + 36; };
lowKey(j) = button("h:Keys/key %n [midi:key %n 1]") with { n = j + 24; };
lkey(k)   = button("h:Lower/lkey %n [midi:key %n 2]") with { n = k + 36; };   // channel 2
latch(g, sus) = (\(prev).(max(g, sus * prev))) ~ _;              // CC64 latch (rule 14)
held(k)  = latch(key(k), pedal);
held2(k) = latch(lkey(k), pedal2);
// Pedal split: decided when the key goes down, so moving it never moves a sounding note.
rise(g)    = g > g';
isPed(k)   = (k + 36 < psplit) : ba.sAndH(rise(key(k)));
isPedLow(j)= (j + 24 < psplit) : ba.sAndH(rise(lowKey(j)));
gate1(k)   = held(k) * (1 - isPed(k));                            // ch1 key on a manual
isUpper(k) = (k + 36) >= split : smooth(0.01);                     // moving the split never clicks

// Each of the 9 contacts closes at its own moment during key travel; switching a running
// sine mid-cycle is where the click comes from. kk = contact set (0-60 ch1, 61-121 ch2).
contact(g, kk, t) = g @ int(spread_s * hash(kk, t + 2) * ma.SR) : en.asr(ramp, 1, ramp)
    with {
        spread_s = 0.004 * click;                    // up to 4 ms between contacts
        ramp     = 0.0002 + 0.004 * (1 - click);     // 0.2 .. 4.2 ms contact ramp
    };

// Leakage: each contact also picks up two other wheels, faintly (-30 dB at Leakage = 1).
// Which wheels leak is a seeded stand-in until crosstalk is measured on a real generator.
leakWheel(k, kk, t, j) = fold(max(0, tapWheel(k, t) + ba.take(1 + int(4 * hash(kk * 9 + t, j + 7)), (-24, -12, 12, 24))));
tap(k, kk, t) = wheel(tapWheel(k, t))
          + leak * 0.0316 * (wheel(leakWheel(k, kk, t, 1)) * hash(kk, t + 30) + wheel(leakWheel(k, kk, t, 2)) * hash(kk, t + 40));

c1(k, t) = contact(gate1(k), k, t) * tap(k, k, t);
c2(k, t) = contact(held2(k), k + 61, t) * tap(k, k + 61, t);
upperBus(t) = sum(k, NKEYS, isUpper(k) * c1(k, t));
lowerBus(t) = sum(k, NKEYS, (1 - isUpper(k)) * c1(k, t)) + sum(k, NKEYS, c2(k, t));

// ---------------------------------------------------------------- percussion (upper only)
// Single trigger: fires only when the first upper key goes down after all were released.
anyUpper = sum(k, NKEYS, gate1(k) * ((k + 36) >= split)) > 0.5;
trig     = anyUpper > anyUpper';
percT60  = ba.if(percSlow > 0.5, 1.5, 0.5);         // seconds to -60 dB, by ear: unconfirmed
percEnv  = trig : max ~ *(exp(-6.9078 / (percT60 * ma.SR)));
percBus  = xfade(percThird, upperBus(3), upperBus(4)) * percEnv * (1 - 0.5 * percSoft);

// 1' is cut while percussion is on (B-3 behaviour)
upperSig = sum(t, 8, ub(t) * upperBus(t)) + ub(8) * (1 - percOn) * upperBus(8) + percOn * percBus;
lowerSig = sum(t, 9, lb(t) * lowerBus(t));

// ---------------------------------------------------------------- pedals
// 25 pedal keys C1-C3 (MIDI 24-48) on channel 3, or channel 1 below the pedal split (at
// pitch). 16' = the key's own wheel, 8' = an octave up. Contacts close together (pedal
// contacts are not staggered); release in seconds. No sustain latch on the pedals.
NPED = 25;
pkey(p) = button("h:Pedalboard/pedal %n [midi:key %n 3]") with { n = p + 24; };
fromCh1(p) = ba.if(p < 12, lowKey(min(p, 11)) * isPedLow(min(p, 11)),
             ba.if(p < 24, key(max(0, p - 12)) * isPed(max(0, p - 12)), 0));
pgate(p) = max(pkey(p), fromCh1(p));
pcontact(p) = pgate(p) : en.asr(0.002, 1, pRelease);
pedalSig = sum(p, NPED, pcontact(p) * (pBar16 * wheel(p) + pBar8 * wheel(p + 12)));

// ---------------------------------------------------------------- scanner
// Upper always through the scanner; lower when "Vibrato Lower" is on (both crossfaded).
voices = (upperSig + vibLower * lowerSig) : sc.scanner(vibMode) : +((1 - vibLower) * lowerSig) : +(pedalSig);

// ---------------------------------------------------------------- preamp
// Asymmetric soft clip, first-order ADAA (rule 3), DC blocker after it (rule 4) at 5 Hz in
// seconds (v0.4: fi.dcblocker was a fixed pole 0.995, 38 Hz at 48 kHz and 153 Hz at 192 kHz,
// failures.md F-2),
// rough level compensation (rule 5; measured at P, not here).
preamp(x) = (g * x + bias) : aa.tanh1 : -(ma.tanh(bias)) : fi.dcblockerat(DCHZ) : /(comp)
    with {
        g    = 1 + 11 * drive;
        bias = 0.15 * drive;
        comp = 1 + 1.2 * drive;
        DCHZ = 5;
    };

// ---------------------------------------------------------------- output
// Leslie on/off crossfaded (rule 2); the rotors keep turning while it is off.
mix(x) = ls.leslie(fast, brake, spread, x) : par(c, 2, xfade(leslieOn, x, _));

process = voices * 0.06 * expr : preamp : *(0.35 * volume) : mix;     // 0.06 / 0.35: gain staging
