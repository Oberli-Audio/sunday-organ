# Status - Sunday Organ 0.1.0 (2026-10-31)
Tier P, track I, at gate G1. Recipe D.8.1.

## Gates
| Gate | State | Evidence (command -> number, test name, log) |
|---|---|---|
| G0 | closed 2026-10-31 | `docs/brief.md` confirmed by Björn's answers: constants by ear, keyboard taper, expression pedal in v1, reference machine Apple M3 Pro |
| G1 | drafted | see Decisions; closes with G0 |
| G2 | prototype v0.3 | `sound design/dsp/*.dsp` (Faust 2.70.3), renders by `sound design/scores/make_scores.py`; evidence `sound design/evidence-v0.2.txt`; pedals added in v0.3 (`08_pedals_with_chords`: peak -8.5 dBFS, 0 non-finite, side/mid < 150 Hz -34.0 dB) |
| G3 | - | template harness builds on Linux (Ubuntu 24.04, GCC, JUCE pinned) after the JucePlugin_* fix; `dspkit.py smoke` fails on `sample_rate=48000.0` vs `48000` (kit or harness echo type, to fix in ~/bob-skills) |
| G4 | - | C++ port; only open or ramping contacts run (the prototype's 549 always-on contacts are the CPU problem) |
| G5-G7 | - | |

## Listening debt
- 2026-10-31: rotor spin-up/down, percussion decay, scanner depths are set by ear (no reference recording, Björn's decision); judge them when the first build is playable.
- 2026-10-31: nothing in the prototype has been heard by anyone; renders in `sound design/renders/` (regenerate with the scores).

## Open exceptions
- EX-1 2026-10-31: rule 20 (CPU) on the Faust prototype, worst case 48 kHz / 64: p99.9 74 % vs 25 % on a 2-core cloud Xeon; acceptable for a prototype only; **unacceptable if** the C++ port's p99.9 exceeds 25 % on the reference machine, as `perf.py run`. Friends: none.
- EX-2 2026-10-31: keyboard span 6.8 LU vs < 6 LU (brief) on the untapered prototype; fix decided: per-wheel level taper (G2/G4). Friends: none.

## Handoff
Task: Tier P from the v0.2 sketch. Plan: 1. [x] repo from template, init (code Suor, coral) 2. [x] brief draft, parameters.csv (37 rows, `paramgen.py check --kind instrument` OK) 3. [x] editor frame (Tier S, `sound design/ui-sketch/`) 4. [x] Björn confirms the brief 5. [ ] G1 decisions line (next) 5b. [ ] wheel taper + expression (CC11) in the prototype 6. [ ] harness + G3 battery 7. [ ] port.
Working tree: see git. Build: Linux harness rebuilding after the CMake fix. Tests: not run yet.
Open questions for the owner: the editor's two-row layout (a brand-sheet line, below).
Next command: `cmake --preset release && cmake --build --preset release && ctest --preset fast`

## Decisions
- 2026-10-31: G1 family (draft) additive tonewheel generator, 91 shared free-running wheels on gear ratios, 9 contacts per key with staggered closing; scanner as modulated Lagrange delay; Leslie per S row "rotary speaker" with moving-source Doppler by retarded time (measured 0.22 cent vs the model). Departures from S: none open; the unconfirmed constants are listed in the brief's open questions.
- 2026-10-31: registry entry sunday-organ (code Suor, accent coral, bundle com.oberliaudio.sundayorgan) written to a local copy; must be committed to `~/bob-skills/ship-bob/registry/plugins.toml` before the first shared build.
- 2026-10-31: template defect: the harness compiled the plugin sources without JUCE 8's JucePlugin_* definitions; fixed here in CMakeLists.txt; the fix belongs in the template source in `~/bob-skills` too.
- 2026-10-31: editor layout proposal: two rows (drawbars; performance) plus the output column. The brand's PluginWindow says one row; needs a line in the brand sheet if accepted.
