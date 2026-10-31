# Status - Sunday Organ 0.1.0 (2026-10-31)
Tier P, track I, at gate G6 (what runs on the Linux cloud box is done; the Mac, the hosts and listening are open). Recipe D.8.1.

## Gates
| Gate | State | Evidence (command -> number, test name, log) |
|---|---|---|
| G0 | closed 2026-10-31 | `docs/brief.md` confirmed by Björn; amendments of 2026-10-31 beneath the YAML wait for his confirmation |
| G1 | closed 2026-10-31 | Decisions, line "G1": family against the brief (no organ row in S: chosen by the F.1 axes), trade-off, four departures with the measurement that rejects each |
| G2 | closed 2026-10-31 (prototype v0.6) | `cd "sound design" && python3 scores/make_scores.py && python3 scores/render_all.py && python3 harness/evidence.py ../scripts/dsp-kit` -> `evidence-v0.4.txt`: keyboard span 4.0 LU per manual (was 6.8), alias floor -120.5 dB (was -99.9), side/mid < 150 Hz -30.8 to -34.0 dB, 24 renders 0 non-finite. v0.5: DC blocker in seconds (F-2); v0.6: crossover allpass (F-3). Heard by nobody yet |
| G3 | closed 2026-10-31 | Harness contract v3 (`tools/harness/Main.cpp`): ch1 upper with split and pedal split, ch2 lower, ch3 pedals, CC1/CC11/CC64, `--events` plays the prototype's scores; `dspkit.py smoke` OK (16 presets, p99.9 8.0 %); `--list-params` = parameters.csv (`paramgen.py check --list-params`: 38 parameters, round trip at 101 points, 0 warnings). Metric table: `python3 tools/measure/metrics.py --md docs/metrics.md` -> every target of the brief passes (table below) |
| G4 | closed 2026-10-31 | `cmake --preset release -G Ninja && cmake --build --preset release`: VST3, Standalone, harness, clean of errors (warnings: JUCE-template float compares in the harness). One class per prototype module in `Source/dsp/` (Tonewheels, Contacts, Busses + Percussion, Scanner + Preamp, Leslie, Organ), constants beside the code; only open or ramping contacts run (fixed index list); seconds converted in prepare; seeded hashes |
| G5 | closed 2026-10-31 | `python3 tools/g5/null_test.py build/SundayOrganHarness_artefacts/Release/SundayOrganHarness --md docs/g5-null-test.md` (48 kHz, no alignment, F.8 row 1 < -120): whole plugin on 23 scores, worst residual peak -138.5 dBFS; module probes (upper, lower, pedals, voices, preamp, crossover) 42 rows, worst -138.7 dB re their peak. Doppler: `python3 tools/g5/doppler_check.py build/SundayOrganDopplerCheck --faust <doppler_test render>` -> 0.020 cent p99 vs moving source (1.83 vs moving listener), plugin vs prototype -144.5 dBFS. Bank loudness-matched: 16 presets -17.96 to -18.03 LUFS (Init -17.37, the defaults) |
| G6 | partly (this box) | See "G6 on this box" below. Not run here: the Steinberg validator and pluginval on macOS, the RTSan build (needs Homebrew LLVM), CPU on the M3 Pro under Rosetta, the two hosts |
| G7 | - | Bank and table final for 0.1.0 unless listening changes them; IDs not frozen (rule 19: at the first release, Björn's call) |

### Metric table (G3; `docs/metrics.md` has the methods)
| Target (brief) | Value | Pass |
|---|---|---|
| alias floor < -80 dB | -120.5 dB (C7 8', Drive 100 %) | yes |
| THD+N < -60 dB at Drive 0 | -70.5 dB (C4 8') | yes |
| response error +/-0.5 dB | 4e-7 dB (crossover sum) | yes |
| keyboard span < 6 LU per manual | 2.7 LU upper, 2.7 LU lower | yes |
| low register side/mid < 150 Hz < -30 dB | -30.9 dB (pedal C1 + lower chord, Leslie fast) | yes, 0.9 dB margin |
| Doppler < 1 cent | 0.020 cent (delay path) | yes; full path EX-3 |
| rotor rates within 2 % | worst 0.85 % (horn 0.82 / 6.67 Hz, drum 0.67 / 5.66 Hz) | yes |
| no zipper on drawbars and split | largest sample step -2.45 dB (drawbars), -1.60 dB (split) below the brightest static state | yes |
| presets -18 LUFS +/-1 LU | METRIC_LOUDNESS | METRIC_LOUDNESS_PASS |

### G6 on this box (Linux x86_64, 4 cores, GCC 13)
G6_TABLE

## Listening debt
- 2026-10-31: nothing has been heard by anyone - neither the prototype renders (`sound design/renders/`, regenerate with the scores) nor the plugin. Init patch and three presets (Gospel Full, Ballad, Bass Split) to the one friend (F.18.7).
- 2026-10-31: constants set by ear without a reference (Björn's decision): rotor spin-up/down (horn 0.35/0.55 s, drum 2.2/3.0 s), percussion decay (0.5/1.5 s), scanner depths (0.35/0.7/1.2 ms), horn resonance +10 dB at 2 kHz, horn level 0.3, reflections.
- 2026-10-31: Key Click at its default 50 % measures -90.5 dBFS above 4 kHz in the first 15 ms of a chord (-94.9 at 0 %, -75.8 at 100 %, `test_key_click_scales_with_key_click`): it may be too soft to hear; judge on the first play.
- 2026-10-31: the bank (16 presets) is registrations from the B-3 literature, calibrated by measurement only.

## Open exceptions
- EX-1 2026-10-31: rule 20 (CPU) on the Faust prototype, p99.9 74 % vs 25 % - the prototype only; the port: PERF_LINE. **Unacceptable if** the port's p99.9 exceeds 25 % on the M3 Pro under Rosetta, as `perf.py run`. Friends: none.
- EX-3 2026-10-31: the full horn path deviates 3.5 cents p99 from the moving-source model (the Doppler delay alone 0.02 cent): the moving lowpass's phase swings with its cutoff, in the prototype and the plugin alike. **Unacceptable if** the delay path exceeds 1 cent, or the full path 5 cents, or the friend hears a vibrato beyond the Doppler. Friends: none.
- EX-4 2026-10-31: the split parameters show numbers in the host (36, 60) - `paramgen.py` writes no value strings for `int` parameters, so `format_kind note` is lost (the editor shows C4 / Off through its own helper). **Unacceptable if** it reaches a release: the fix belongs in the kit (~/bob-skills), then regenerate `Source/Params.h`. Friends: an automation lane reads "60" instead of "C4".
- EX-5 2026-10-31: rule 13's "shown failing" is done for every regression test (F-2 to F-7) but not yet for the ten presence tests of the defining features (`test_features.py` DefiningFeatures): no knockout build of each feature was made. **Unacceptable if** G7 is closed without it. Friends: none.

## Handoff
Task: Tier P from G1 to a release-gate-ready build (Björn, 2026-10-31). Done: steps 1-8 of the task as far as this box allows (see Gates). Branch `g0-brief-and-sketch`, everything pushed.
Next commands (on the Mac): `cmake --preset release && cmake --build --preset release && ctest --preset all`; `python3 scripts/dsp-kit/perf.py run --harness build/SundayOrganHarness_artefacts/Release/SundayOrganHarness --arch x86_64`; `python3 scripts/dsp-kit/validate_plugin.py --profile full --plugin "build/SundayOrgan_artefacts/Release/VST3/Sunday Organ.vst3"`; the RTSan preset; the snapshot pass on a 1x display (`SundayOrganGuiSnapshot`, target not built by default).
Open questions for the owner: the brief amendments of 2026-10-31; when to freeze the IDs (rule 19).

## Decisions
- 2026-10-31: **G1.** Family: additive tonewheel generator - 91 shared, free-running sine wheels on the gear ratios, 9 contacts per key switching wheels onto 9 drawbar busses per manual, contacts closing staggered (the click), seeded leakage; the scanner as a Lagrange-interpolated modulated delay (rule 6); the preamp as one asymmetric soft clip with first-order ADAA (rule 3); the Leslie per S.2 "rotary speaker" (E.6.5): LR4 800 Hz split, horn = moving-source Doppler + AM + moving TPT lowpass + 2 kHz resonance, drum = AM, < 200 Hz mono and unmodulated, per-rotor spin-up/spin-down. Trade-off: shared wheels give the defining phase-coherent +6 dB sums and exact gear-ratio tuning and cost 91 oscillators whatever is played; per-key oscillators (S "Not" for this brief) would be cheaper at one note but break the defining feature; contacts cost per open key, so the port runs only open or ramping ones. Departures: (1) preamp = static asymmetric tanh, no bias-shift or sag (S.2 "tube preamp" says stateful) - rejected if Drive's level compensation leaves > 1 LU over 0-100 % or the alias floor at Drive 1 C7 rises above -80 dB (measured: -120.5 dB), or the friend hears it as static against a B-3 recording; (2) scanner = one modulated delay, not the 9-section LC line (Werner WDF) - rejected if V1-V3 pitch swing is not strictly increasing or the rate is off 6.9 Hz by > 2 % (`test_scanner_v1_v3_increasing_c_modes_with_dry` passes); (3) leakage partners seeded, not measured crosstalk - rejected if Leakage 100 % raises any non-tapped wheel above -30 dB re the tapped one (by construction -30 dB x hash < 1); (4) wheels as exact quadrature oscillators instead of the prototype's 64k truncated table (G2) - rejected if a single wheel's THD+N is above -100 dB.
- 2026-10-31: EX-2 (keyboard span 6.8 LU) resolved at G2 by a per-wheel taper of 1.0 dB/oct above wheel 36 (numpy pre-study 0 -> 5.8, 1.0 -> 2.8 LU on pure wheels; plugin 2.7 LU per manual).
- 2026-10-31: `scanner.lib` and `leslie.lib` were never in git (`.gitignore` `*.lib`); reconstructed from the compiled v0.3 and nulled against its binary at -140 to -172 dB re signal (F-1). The repo keeps the compiled prototype (`harness/render.cpp`, `render`) for exactly this reason.
- 2026-10-31: the `dspkit.py smoke` failure (`sample_rate` 48000.0 vs 48000) was the harness's echo (a double), fixed in `tools/harness/Main.cpp`; the kit is right. Template defects found here and fixed in this repo, to be carried to the template in ~/bob-skills: the harness work buffer on oversized blocks (F-5), int steps, block 0 and the tail off by one (F-6), the Linux malloc trap, `State.h`'s skewed-float round trip (F-4).
- 2026-10-31: kit observations for Björn (never edited here): `paramgen.py` emits no value strings for `int` parameters (EX-4); `presetlint.py` judges the spread around the median, the brief's absolute -18 LUFS is checked in `tools/measure/metrics.py`; `test_template.py`'s rule-20 assertion judges p99.9 on whatever machine runs it (here a cloud box, not the budget machine); S has no organ row (add "tonewheel organ" with G1's line).
- 2026-10-31: the editor is built in the family LookAndFeel taken over from Horizon Pad (tokens, Rubik, `drawKnob`, icons, marks), accent coral; round 13 layout; Expression appears as the SWELL wheel beside MOD; the on-screen MOD wheel acts like CC1. Not done at P yet: the drag readout bubble and the in-editor menu (the menu is JUCE's PopupMenu in the tokens).
- 2026-10-31: the Leslie idles (rotors turn, output silence) after 0.25 s below -180 dBFS: idle p50 4.6 % -> 1.2 % (F-7); G5 unchanged.
