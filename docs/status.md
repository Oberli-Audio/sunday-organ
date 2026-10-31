# Status - Sunday Organ 0.1.0 (2026-10-31)
Tier P, track I, at gate G1. Recipe D.8.1.

## Gates
| Gate | State | Evidence (command -> number, test name, log) |
|---|---|---|
| G0 | closed 2026-10-31 | `docs/brief.md` confirmed by Björn's answers: constants by ear, keyboard taper, expression pedal in v1, reference machine Apple M3 Pro |
| G1 | closed 2026-10-31 | Decisions, line "G1": family against the brief with S.1/S.2 (no organ row in S: family chosen by F.1 axes, row to be added in ~/bob-skills), trade-off, four departures each with the measurement that rejects it |
| G2 | closed 2026-10-31 (v0.4) | `sound design/dsp/*.dsp` + `.lib`, `python3 scores/make_scores.py && python3 scores/render_all.py && python3 harness/evidence.py ../scripts/dsp-kit` -> `sound design/evidence-v0.4.txt`: keyboard span 4.0 LU upper, 4.0 LU lower (every 3rd key, 888000000, dry; was 6.8), alias floor -120.5 dB at 48 and 192 kHz (was -99.9), side/mid < 150 Hz -30.8 to -34.0 dB, 24 renders 0 non-finite, expression 1 -> 0.1 = -29.5 dB with the crest rising 6.6 -> 10.2 dB (drive follows the swell), pedals on ch3 and by ch1 pedal split -37.1 / -36.2 dBFS below 100 Hz, bank median -17.8 LUFS spread 0.3 LU. Heard by nobody yet (listening debt) |
| G3 | - | template harness builds on Linux (Ubuntu 24.04, GCC, JUCE pinned) after the JucePlugin_* fix; `dspkit.py smoke` fails on `sample_rate=48000.0` vs `48000` (kit or harness echo type, to fix in ~/bob-skills) |
| G4 | - | C++ port; only open or ramping contacts run (the prototype's 549 always-on contacts are the CPU problem) |
| G5-G7 | - | |

## Listening debt
- 2026-10-31: rotor spin-up/down, percussion decay, scanner depths are set by ear (no reference recording, Björn's decision); judge them when the first build is playable.
- 2026-10-31: nothing in the prototype has been heard by anyone; renders in `sound design/renders/` (regenerate with the scores).

## Open exceptions
- EX-1 2026-10-31: rule 20 (CPU) on the Faust prototype, worst case 48 kHz / 64: p99.9 74 % vs 25 % on a 2-core cloud Xeon; acceptable for a prototype only; **unacceptable if** the C++ port's p99.9 exceeds 25 % on the reference machine, as `perf.py run`. Friends: none.

## Handoff
Task: Tier P from the v0.2 sketch. Plan: 1. [x] repo from template, init (code Suor, coral) 2. [x] brief draft, parameters.csv (37 rows, `paramgen.py check --kind instrument` OK) 3. [x] editor frame (Tier S, `sound design/ui-sketch/`) 4. [x] Björn confirms the brief 5. [ ] G1 decisions line (next) 5b. [ ] wheel taper + expression (CC11) in the prototype 6. [ ] harness + G3 battery 7. [ ] port.
Working tree: see git. Build: Linux harness rebuilding after the CMake fix. Tests: not run yet.
Open questions for the owner: none.
Next command: `cmake --preset release && cmake --build --preset release && ctest --preset fast`

## Decisions
- 2026-10-31: EX-2 (keyboard span 6.8 LU) resolved at G2 by a per-wheel taper of 1.0 dB/oct above wheel 36 (numpy pre-study 0 -> 5.8, 1.0 -> 2.8 LU on pure wheels; prototype 4.0 LU per manual).
- 2026-10-31: **G1.** Family: additive tonewheel generator - 91 shared, free-running sine wheels on the gear ratios, 9 contacts per key switching wheels onto 9 drawbar busses per manual, contacts closing staggered (the click), seeded leakage; the scanner as a Lagrange-interpolated modulated delay (rule 6); the preamp as one asymmetric soft clip with first-order ADAA (rule 3); the Leslie per S.2 "rotary speaker" (E.6.5): LR4 800 Hz split, horn = moving-source Doppler + AM + moving TPT lowpass + 2 kHz resonance, drum = AM, < 200 Hz mono and unmodulated, per-rotor spin-up/spin-down. Trade-off: shared wheels give the defining phase-coherent +6 dB sums and exact gear-ratio tuning and cost 91 oscillators whatever is played; per-key oscillators (S "Not" for this brief) would be cheaper at one note but break the defining feature; contacts cost per open key, so the port runs only open or ramping ones. Departures: (1) preamp = static asymmetric tanh, no bias-shift or sag (S.2 "tube preamp" says stateful) - rejected if Drive's level compensation leaves > 1 LU over 0-100 % or the alias floor at Drive 1 C7 rises above -80 dB, or the friend hears it as static against a B-3 recording; (2) scanner = one modulated delay, not the 9-section LC line (Werner WDF) - rejected if V1-V3 pitch swing is not strictly increasing or the rate is off 6.9 Hz by > 2 %; (3) leakage partners seeded, not measured crosstalk - rejected if Leakage 100 % raises any non-tapped wheel above -30 dB re the tapped one; (4) wheels as exact quadrature oscillators instead of the prototype's 64k truncated table (G2) - rejected if a single wheel's THD+N is above -100 dB.
- 2026-10-31: registry entry sunday-organ (code Suor, accent coral, bundle com.oberliaudio.sundayorgan) written to a local copy; must be committed to `~/bob-skills/ship-bob/registry/plugins.toml` before the first shared build.
- 2026-10-31: template defect: the harness compiled the plugin sources without JUCE 8's JucePlugin_* definitions; fixed here in CMakeLists.txt; the fix belongs in the template source in `~/bob-skills` too.
- 2026-10-31: editor layout: two rows (what the instrument is made of; what the player changes) plus the output column spanning both; accepted by Björn as brand round 13 (Design System artifact: PluginWindow and README, 2026-10-31). The mirror `plugin-ui-bob/references/oberli-audio-brand.md` in ~/bob-skills still says one row until the next skills release. The editor sketch predates round 12 values: build the editor from `tokens.json` (label 11 px, line-control #716B62).
