# Sunday Organ prototype - Tier S sketch v0.2, Tier P G2 v0.4 (2026-10-31), v0.7 and v0.8 (2026-11-01)

**v0.4 (Tier P G2):** wheels as exact quadrature oscillators (the 64k truncated table of `os.oscp` set the old -99.9 dB alias floor), per-wheel level taper (1.0 dB/oct above C4 wheel), expression CC11 before the preamp (gain e^2), lower manual on channel 2 (`lkey n`), pedals on channel 3 (`pedal n`), channel-1 split key and pedal split (decided at key-down), sustain per channel. Evidence `evidence-v0.4.txt`. **Reconstruction:** `dsp/scanner.lib` and `dsp/leslie.lib` were never committed (`*.lib` in .gitignore, failures.md F-1) and were rebuilt from the compiled v0.3; the rebuilt v0.3 nulled against the old binary at -140 to -172 dB re signal.

**v0.7 (G2 reopened, 2026-11-01, failures.md F-12):** after Björn's first play (chords distorted): the preamp's input at Drive 0 scaled by s = 0.035 so the fullest chord stays clean (gain s (12/s)^drive, Drive 100 % unchanged), its makeup a quartic in drive holding the reference chord (Init -23 LUFS); the safety limiter after the Leslie (4x true peak, -1 dBTP, 1.5 ms look-ahead). Brief amendments 2026-11-01; design numbers from `tools/measure/preamp_prestudy.py`.

**v0.8 (2026-11-01, late evening):** Björn heard Drive 100 % as digital clipping and asked for "a lowpass after the drive that follows the Drive setting": the preamp ends in a speaker roll-off, LR4 whose cutoff goes from a wire at Drive 0 (200 kHz, analog domain, no prewarping, so never at Nyquist) to 6 kHz at Drive 100 %, exponential in Drive. Measured on the port (`tools/measure/drive_character.py`): the growl below 3 kHz unchanged, the fizz above 5 kHz 6-36 dB lower on big chords. Evidence: `evidence-v0.8.txt` (unchanged from v0.7 where Drive is below 75 %).

Run all: `python3 scores/make_scores.py && python3 scores/render_all.py && python3 harness/evidence.py ../scripts/dsp-kit` (faust needs `-t 0`: about 3.5 min on the Linux box, 10 s on the M3 Pro; g++ 20 s to 1.5 min).

---

## Sketch v0.2 (history)

Tier S, track I (instrument) with a second stage E (Leslie). Gates run: G0 as this paragraph, G2.
Promotable: the three decisions below carry over; promotion to P starts by confirming the brief with Björn.

## G0 - the three structural decisions

**1. Structure.** A tonewheel organ is additive synthesis, so the core is exact:

- **Tonewheels.** 91 free-running sine wheels on gear ratios (the organ's tuning, not equal
  temperament), shared by every key.
- **Two manuals on one keyboard.** 61 keys, C2-C7; keys below the split key play the lower manual's drawbars.
- **Contacts.** Each key has 9 contacts that close at slightly different moments and switch the wheels
  onto the drawbar busses; the click comes from that switching. Each contact also leaks two other wheels
  faintly (seeded stand-in for generator crosstalk).
- **Percussion.** Upper manual only, single trigger, 2nd or 3rd harmonic, cuts the 1' drawbar.
- **Scanner.** V1-V3 / C1-C3: a modulated delay with a rounded triangle sweep at 6.87 Hz; C = equal-power
  mix with dry. Upper always, lower switchable.
- **Preamp.** Asymmetric ADAA soft clip, before the Leslie.
- **Leslie.** 800 Hz split. Horn: moving-source Doppler (retarded time, two fixed-point steps), AM, moving
  lowpass, 2 kHz resonance, direct path plus two cabinet reflections per mic. Drum: AM 200-800 Hz. Below
  200 Hz mono and unmodulated. Each rotor has its own spin-up and spin-down, opposite directions, brake,
  mic spread.

Chosen against the "Not" column: no voice allocation or stealing (an organ has none), no per-note
oscillators, no single LFO and no instant speed change on the Leslie.

**2. Parameter table.** `parameters.csv`, 33 parameters. Init = upper 888000000, lower 008080000,
split off, percussion off, vibrato off, Leslie slow. Leslie fast on the mod wheel (CC1), sustain on CC64.

**3. Shape for the port.** Modules: `dsp/tonewheel.dsp` (wheels, contacts, busses, percussion,
preamp), `dsp/scanner.lib`, `dsp/leslie.lib`. Smoothing on every drawbar, switch, level and on the split
(15-50 ms). Nonlinearity in one place (preamp). Everything in seconds; every random value is a hash of
its index, so renders are bit-identical. **The port only runs contacts that are open or ramping**: the
Faust prototype computes all 549 every sample, which is why its CPU number below is over budget.

## Departures

- **Closed:** Doppler was read-side in v0.1, and its depth was half the geometry. Now moving-source;
  `tests/doppler_check.py` measures it (below).
- **Open, by ear, unconfirmed:** rotor speed lags (horn 0.35/0.55 s, drum 2.2/3.0 s tau), percussion
  decay (0.5 / 1.5 s to -60 dB), horn radius 0.15 m, scanner rate and depths, cabinet reflection angles
  and delays, leakage partners, the gear ratios. Check each against recordings of a real B-3/122.
- **Keyboard span 6.8 LU** (top louder, mostly K-weighting on brighter wheels). Brief target is
  usually < 6 LU; decide by listening whether to taper or keep it organ-flat.

## Not in the sketch

Pedals, the real scanner's line response (WDF, Werner et al.), measured crosstalk, cabinet IRs,
tube-amp model of the 122, editor (plugin-ui-bob), CPU-aware port.

## Evidence

Commands: `python3 harness/evidence.py <dsp-kit>` (full output in `renders/evidence/evidence.txt`),
`python3 tests/doppler_check.py <render> <dsp-kit>`, `tests/scanner_test.dsp`.

| Check | Result |
|---|---|
| Safety, 19 renders at 48/96/192 kHz | peaks -6.6 to -20 dBFS, 0 non-finite, DC below -135 dBFS |
| Reproducibility | two runs from reset bit-identical |
| Leslie rotor rate (v0.1 method) | 6.67 Hz fast, 0.82 Hz slow (design 6.67 / 0.83) |
| Doppler, 2 kHz tone, fast | peak 32.2 cents (geometry 32.0); p99 error 0.22 cents vs moving source, 1.9 cents vs moving listener |
| Scanner, 1 kHz tone | V1 17.5, V2 33.8, V3 57.7 cents peak-to-peak at 6.89 Hz |
| Alias floor, C7 8' at drive 1 | worst non-harmonic -99.9 dB at 48 kHz (-111.8 dB at 192 kHz) |
| Mono bass, side/mid < 150 Hz | -33 to -34 dB with the Leslie on |
| Keyboard span, C2-C7 every 6th key | 6.8 LU |
| Bank, 8 presets on the reference chord | median -17.8 LUFS, spread 0.2 LU after volume offsets |
| CPU, worst case, 48 kHz / 64, 2-core cloud Xeon, one run | p50 33 %, p99.9 74 %, 2 blocks over deadline: over the rule-20 budget (p99.9 < 25 %), by design of the prototype; reported, not judged |

**Not measured:** register battery in chords, key-click level, zipper at maximum automation rate,
speed-change curves against a recording, translation. **Not listened to by anyone yet.**

## Run it

```
cd dsp && faust -t 0 -lang cpp -double -cn Tonewheel -a ../harness/arch.cpp -o ../harness/render.cpp tonewheel.dsp
cd ../harness && g++ -O2 -std=c++17 -I"$(faust --includedir)" -o render render.cpp   # the include dir: macOS (Homebrew)
cd ../dsp && for p in busses voices preamp; do faust -t 0 -lang cpp -double -cn Tonewheel -a ../harness/arch.cpp -o ../harness/g5/$p.cpp g5_$p.dsp && g++ -O2 -std=c++17 -I"$(faust --includedir)" -o ../harness/g5/$p ../harness/g5/$p.cpp; done   # G5 probes
cd .. && python3 scores/make_scores.py
cd scores && ../harness/render 02_leslie_fast_slow_brake.txt ../renders/02.wav 15.5 48000
```

Live: paste the three files into the Faust IDE (faustide.grame.fr), MIDI on. The sketch is heavy for a
browser; drop `NKEYS` to 37 for a lighter test.
