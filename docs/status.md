# Status - Sunday Organ 0.1.0 (2026-11-01, evening)
Tier P, track I, at gate G6 again: Björn's first play reopened G2 (chords distorted, F-12); the drive stage is redesigned, a safety limiter added (G1), prototype v0.7, port, G5 and the Mac's unattended G6 re-run green. Björn's replay in Live is next. Recipe D.8.1.

## Gates
| Gate | State | Evidence (command -> number, test name, log) |
|---|---|---|
| G0 | closed 2026-10-31 | `docs/brief.md` confirmed by Björn; amendments beneath the YAML: 2026-10-31 wait for his confirmation; 2026-11-01 "Drive 0 clean on the fullest chord" and "quieter bank + safety limiter" are his decisions, the 1 LU reference for Drive is proposed |
| G1 | closed 2026-10-31, amended 2026-11-01 | Decisions, line "G1" (family, trade-off, four departures) and line "G1 2026-11-01" (the safety limiter, its latency) |
| G2 | closed 2026-11-01 (prototype v0.7) | `cd "sound design" && python3 scores/make_scores.py && python3 scores/render_all.py && python3 harness/evidence.py ../scripts/dsp-kit` -> `evidence-v0.7.txt`: keyboard span 2.7 LU per manual, alias floor -120.5 dB at Drive 1 (unchanged by design), side/mid < 150 Hz -31.0 to -34.4 dB, 25 renders 0 non-finite, highest -7.8 dBTP. v0.7: the preamp's operating point and makeup (F-12), the limiter, cutoffs capped below Nyquist (F-15). Build on the Mac: `SKETCH.md` "Run it" (faust 10 s, g++ 20 s) |
| G3 | closed 2026-11-01 | Harness contract v3; `dspkit.py smoke` OK; `paramgen.py check --list-params`: 38 parameters, 0 warnings. Metric table: `python3 tools/measure/metrics.py --md docs/metrics.md` -> 12 of 12 pass (table below) |
| G4 | closed 2026-11-01 | `cmake --preset release && cmake --build --preset release`: VST3, Standalone, harness, universal, no warnings from the product's code; one class per prototype module in `Source/dsp/`, the limiter in `Limiter.h` (allocates in prepare only), constants beside the code |
| G5 | closed 2026-11-01 | `python3 tools/g5/null_test.py build/SundayOrganHarness_artefacts/Release/SundayOrganHarness --md docs/g5-null-test.md` (48 kHz, no alignment, F.8 row 1 < -120): plugin vs prototype v0.7 on 23 scores, worst -136.5 dBFS; 37 probe rows with signal, worst -126.5 dB re their peak (preamp, full drawbars driven). Bank: `make_bank.py` -> 16 presets -23.04 to -22.95 LUFS, Init -23.00 at the defaults |
| G6 | unattended part green (Linux 2026-10-31, Mac re-run 2026-11-01) | "G6 on the Mac" below. Open: Björn plays the new build in Live 10.1, the second host (a friend on Windows), listening, the editor on a real 1x display |
| G7 | - | IDs not frozen (rule 19: at the first release, Björn's call); EX-4 and EX-5 must close first; the bank's Drive values were set for the old stage (Rock Drive, Power Chords now cleaner): to be re-voiced by ear |

### Metric table (G3; `docs/metrics.md` has the methods)
| Target (brief) | Value | Pass |
|---|---|---|
| alias floor < -80 dB | -120.5 dB (C7 8', Drive 100 %) | yes |
| THD+N < -60 dB at Drive 0 | -127.0 dB (C4 8'; was -70.5) | yes |
| fullest chord < -60 dB at Drive 0 (amendment 2026-11-01) | -63.8 dB (10 upper, 4 lower keys, 2 pedals, every drawbar, full expression; was -14.1) | yes |
| Drive holds the reference chord < 1 LU (amendment, proposed) | 0.13 LU over 0-100 % (was 7.9) | yes |
| output <= -1 dBTP (amendment) | -1.70 dBTP, fullest chord, Output +12 dB, Leslie fast (was +6.1) | yes |
| response error +/-0.5 dB | 4e-7 dB (crossover sum) | yes |
| keyboard span < 6 LU per manual | 2.7 LU upper, 2.7 LU lower | yes |
| low register side/mid < 150 Hz < -30 dB | -30.9 dB (pedal C1 + lower chord, Leslie fast) | yes, 0.9 dB margin |
| Doppler < 1 cent | 0.020 cent (delay path) | yes; full path EX-3 |
| rotor rates within 2 % | worst 0.85 % | yes |
| no zipper on drawbars and split | largest sample step -0.57 dB below the brightest static state | yes |
| presets -23 LUFS +/-1 LU (amendment; was -18) | -23.04 to -22.95 LUFS, worst 0.05 LU | yes |
| CPU (rule 20) p99.9 < 25 %, idle < 2 % | x86_64 under Rosetta on the M3 Pro: p99.9 5.7-12.8 %, idle p50 1.0 % | yes |

### G6 on the Mac (M3 Pro, macOS 26.6.2, Apple clang 21; re-run 2026-11-01 evening)
| Check | Command | Result |
|---|---|---|
| Install | `tools/install_plugin.sh` | universal (x86_64 arm64), signature verified, installed to `~/Library/Audio/Plug-Ins/VST3/` |
| Release bundles | CTest `release_bundles` (`check_bundles.py build`) | VST3 and Standalone: signature valid, both dSYM slices symbolicate (F-9, F-11) |
| CTest, every label | `ctest --preset all` | 9/9 pass; `suite_features` 21 tests (DriveAndHeadroom: F-12 to F-15, each shown failing on `0ad6190`) |
| Steinberg validator + pluginval | `validate_plugin.py --profile full --plugin <VST3> --no-build --test-cmd "ctest --preset all" --out build-validation/mac-full3`; pluginval under `arch -x86_64` | validator 47 passed, 0 failed, every rate from 1234.5678 Hz to 1.23 MHz after F-14 (`docs/validation/steinberg-validator-mac.log`); pluginval 1.0.4 L10, 6 rates x 8 blocks, seed 0x48505631: SUCCESS on arm64 and x86_64 (`pluginval-mac-*-L10.log`) |
| RealtimeSanitizer (rule 1) | `eval "$(python3 scripts/dsp-kit/toolchain.py env)" && cmake --preset rtsan && cmake --build --preset rtsan` | self-test aborts (the check is live); clean: `test_plugin.py --label fast`, `test_features.py` (21), all 16 presets with three manuals, CC1/CC11/CC64, random blocks to 1024 |
| CPU (rule 20), the budget machine | `perf.py run --harness <harness> --arch x86_64 --machine m3pro-rosetta --presets gospel-full,rock-drive,bass-split,split-comping --config 48000/64,44100/32 --seconds 20 --runs 3 --notes 36,43,48,52,55,60,64,67,72,79 --md docs/perf-mac-rosetta.md` | p50 4.6-5.2 % (the limiter about +0.3), p99.9 5.7-12.8 %, every max "scheduling" (the Mac was in use), idle on x86_64 p50 1.0 % |
| Sample rates | `test_any_sample_rate_finite_and_sane`; the harness at 1, 2, 8, 11.025, 16, 22.05, 32, 44.1 kHz and 1.23 MHz | finite, one key at -24.9 dBFS everywhere (F-15: NaN/Inf below 24 kHz before) |
| Parameter table | CTest `parameter_table` (`check_table.py`, with `Source/Params.h` against a fresh `paramgen.py juce`) | 38 parameters, 0 warnings, Params.h current |
| Editor snapshots, macOS rendering | `SundayOrganGuiSnapshot --scale=1|1.5|2`, `--state=drawer|about`, `--preset=init`; `snapshot_contrast.py --metrics --theme charcoal` | 0 metrics outside the limits in all six; no 1x display attached (built-in Retina only) |

### G6 on this box (Linux x86_64, 4 cores, GCC 13, 2026-10-31; before the drive-stage change)
| Check | Command | Result |
|---|---|---|
| ASan + UBSan, harness | `cmake --preset asan -G Ninja && cmake --build build-asan`; `test_features.py` and `test_plugin.py --label fast` against it, `halt_on_error=1` | no sanitizer report; only the time budgets fail (instrumented build). Not re-run after 2026-11-01 (the Mac has no from-source ASan pluginval yet) |
| ASan + UBSan, plugin in pluginval | libasan + libubsan preloaded into pluginval, L10, 6 rates x 7 blocks | SUCCESS, 168 runs (`docs/validation/pluginval-linux-L10-asan.log`) |
| pluginval L10, Linux VST3 | pluginval 2.0.0 from source, `xvfb-run pluginval --strictness-level 10 ...` | SUCCESS, 168 runs (`docs/validation/pluginval-linux-L10.log`) |
| Editor (plugin-ui-bob) | snapshots -> `docs/snapshots/`; `snapshot_contrast.py --metrics --theme charcoal` | smallest text 5.41:1, section notes 5.86:1, labels 8.55:1 |
| Code checklist (editor) | read in the code | as listed 2026-10-31; open: the drag readout bubble, the diagnostics fields on About |

## Listening debt
- 2026-11-01, Björn, first play in Live 10.1 (Init): one key good; more keys sounded like digital clipping; "more than 6 keys does not work". Cause measured and fixed (F-12): the drive stage clipped chords (-14 dB at 10 keys at Drive 0). **Replay needed** on the new build: chords at Drive 0 and 20 %, the growl from 30-40 %, the full organ against the limiter; the bank is 5 dB quieter (raise the track in Live by about 5 dB). The 6-key limit is not in the plugin (every key sounds in the harness); six is the computer keyboard's rollover - to confirm with Björn.
- 2026-11-01: the bank's Drive values were chosen for the old stage, where 50 % was already heavy; now Rock Drive (85 %) and Power Chords (70 %) growl, the 15-40 % presets are near clean. Re-voice by ear.
- 2026-10-31: constants set by ear without a reference: rotor spin-up/down (horn 0.35/0.55 s, drum 2.2/3.0 s), percussion decay (0.5/1.5 s), scanner depths (0.35/0.7/1.2 ms), horn resonance +10 dB at 2 kHz, horn level 0.3, reflections; since 2026-11-01 also the limiter's 150 ms release.
- 2026-10-31: Key Click at its default 50 % may be too soft to hear (`test_key_click_scales_with_key_click` holds the order 0 < 50 < 100 % and 12 dB between the ends); judge on the replay.
- 2026-10-31: the bank (16 presets) is registrations from the B-3 literature, calibrated by measurement only.

## Open exceptions
- EX-3 2026-10-31: the full horn path deviates 3.5 cents p99 from the moving-source model (the Doppler delay alone 0.02 cent): the moving lowpass's phase swings with its cutoff, in the prototype and the plugin alike. **Unacceptable if** the delay path exceeds 1 cent, or the full path 5 cents, or the friend hears a vibrato beyond the Doppler. Friends: none.
- EX-4 2026-10-31, narrowed 2026-11-01: the host shows note names for the splits, but their "no split" position (Split Key 36, Pedal Split 24) reads C2 / C1 in the host and "Off" in the editor. **Unacceptable if** it reaches a release: `format_kind custom` for the two splits with `Display::custom` / `Display::parse` (Off at the minimum), which the editor then uses too. Friends: an automation lane reads C2 where the editor says Off.
- EX-5 2026-10-31: rule 13's "shown failing" is done for every regression test (F-2 to F-15) but not yet for the ten presence tests of the defining features (`test_features.py` DefiningFeatures): no knockout build of each feature was made. **Unacceptable if** G7 is closed without it. Friends: none.

## Handoff
Task: Tier P from G1 to a release-gate-ready build (Björn, 2026-10-31). Done: Linux (cloud session, 2026-10-31); the Mac's G6 (2026-11-01); the drive stage and the limiter after Björn's first play (2026-11-01 evening). Branch `g0-brief-and-sketch`.
**Next:** Björn replays in Live 10.1 (the VST3 is replaced; restart Live or rescan): chords at Drive 0, 20 and 50 %, the full organ, Gospel Full, Rock Drive, Ballad, Bass Split; what he hears goes into the listening debt. Questions for him: the 1 LU reference for Drive (proposed); which keyboard played the 7+ keys. Then the bank's Drive values by ear, EX-4, EX-5, the second host, the editor on a 1x display, ASan on the Mac (pluginval from source), G7; for the release gate, `shipcheck.py docs .` still fails on the five Rubik fonts `notices.toml` does not list.
Open questions for the owner: the brief amendments of 2026-10-31; when to freeze the IDs (rule 19).

## Decisions
- 2026-10-31: **G1.** Family: additive tonewheel generator - 91 shared, free-running sine wheels on the gear ratios, 9 contacts per key switching wheels onto 9 drawbar busses per manual, contacts closing staggered (the click), seeded leakage; the scanner as a Lagrange-interpolated modulated delay (rule 6); the preamp as one asymmetric soft clip with first-order ADAA (rule 3); the Leslie per S.2 "rotary speaker" (E.6.5): LR4 800 Hz split, horn = moving-source Doppler + AM + moving TPT lowpass + 2 kHz resonance, drum = AM, < 200 Hz mono and unmodulated, per-rotor spin-up/spin-down. Trade-off: shared wheels give the defining phase-coherent +6 dB sums and exact gear-ratio tuning and cost 91 oscillators whatever is played; per-key oscillators would be cheaper at one note but break the defining feature. Departures: (1) preamp = static asymmetric tanh, no bias-shift or sag - rejected if Drive's level compensation leaves > 1 LU over 0-100 % on the reference chord (measured 2026-11-01: 0.13 LU) or the alias floor at Drive 1 C7 rises above -80 dB (-120.5 dB), or the friend hears it as static against a B-3 recording; (2) scanner = one modulated delay, not the 9-section LC line - rejected if V1-V3 pitch swing is not strictly increasing or the rate is off 6.9 Hz by > 2 %; (3) leakage partners seeded, not measured crosstalk - rejected if Leakage 100 % raises any non-tapped wheel above -30 dB re the tapped one; (4) wheels as exact quadrature oscillators - rejected if a single wheel's THD+N is above -100 dB.
- 2026-11-01: **G1 amended: the safety limiter** (Björn: "quieter bank + safety limiter"). A clean drive stage leaves the full organ about 18 dB louder than before; the limiter after the Leslie (S.2 "peak / true-peak limiter", "output safety stage") keeps the output at or below -1 dBTP: 4x true-peak detection at -1.7 dBFS, linked, sliding maximum -> 150 ms release -> moving average in the "1 - gain" domain, a clamp at -1 dBFS last. Trade-off: 1.5 ms of latency (reported to the host, compensated by Live) and audible compression only where the alternative was clipping; below the ceiling the gain is exactly 1. Rejected if a chord a player can reach with two hands at the default Drive and the bank's level engages it audibly (measured: 10-key chords on Init, Gospel Full, Rock Drive and Ballad peak at -8.3 to -13.7 dBFS, 6.6 dB or more below the -1.7 dBFS detection), or if the replay hears pumping on the full organ.
- 2026-11-01: **The drive stage** (F-12; brief amendment, Björn: Drive 0 clean on the fullest chord): input 0.06 x expression^2 x s (12/s)^drive with s = 0.035 (Drive 100 % unchanged, so G2's alias floor holds), makeup in dB a quartic in drive fitted to the reference chord, Init calibrated to -23 LUFS (`tools/measure/preamp_prestudy.py` for the model; the plugin's numbers in the metric table). No single compensation keeps every signal within 1 dB over 0-100 % (saturation compresses): at 100 % one key is +5.5 dB, the full organ -12.5 dB against Drive 0.
- 2026-10-31: EX-2 (keyboard span 6.8 LU) resolved at G2 by a per-wheel taper of 1.0 dB/oct above wheel 36 (plugin 2.7 LU per manual).
- 2026-10-31: `scanner.lib` and `leslie.lib` were never in git (`.gitignore` `*.lib`); reconstructed from the compiled v0.3 and nulled against its binary at -140 to -172 dB re signal (F-1).
- 2026-10-31: the `dspkit.py smoke` failure (`sample_rate` 48000.0 vs 48000) was the harness's echo (a double), fixed in `tools/harness/Main.cpp`; the kit is right.
- 2026-10-31: `presetlint.py` judges the bank's spread around the median; the brief's absolute target (-23 LUFS since 2026-11-01) is checked in `tools/measure/metrics.py`.
- 2026-10-31: the editor is built in the family LookAndFeel taken over from Horizon Pad (tokens, Rubik, `drawKnob`, icons, marks), accent coral (the registry's entry for Sunday Organ); Expression appears as the SWELL wheel beside MOD; the on-screen MOD wheel acts like CC1. Not done at P yet: the drag readout bubble and the in-editor menu.
- 2026-10-31: the Leslie idles (rotors turn, output silence) after 0.25 s below -180 dBFS (F-7).
- 2026-11-01: EX-1 (rule 20) closed on the budget machine (x86_64 under Rosetta on the M3 Pro); re-measured with the limiter: p99.9 5.7-12.8 %.
- 2026-11-01: defects only the Mac shows: F-9 (arm64 dSYM empty), F-10 (state round trip on arm64), F-11 (a fresh Standalone's seal). Linux x86_64 does not stand in for the Mac.
- 2026-11-01: F-13 (a step at every reset, -68.7 dBFS before, covered the key click once the makeup lifted it), F-14 (the limiter's window negative below 4 kHz: the validator aborted), F-15 (cutoffs above Nyquist below 24 kHz: NaN/Inf, the validator only checks for crashes) - each found while testing F-12, each with its regression test shown failing first.
- 2026-11-01: the harness's `impulse` is 0.5 (-6 dBFS), as the contract states; the scaffold's tail test rounds its start sample.
- 2026-11-01: the kit (`scripts/dsp-kit/`) refreshed from ~/bob-skills sound-design-bob 5.2.0; `tools/tests/test_plugin.py` regenerated from the scaffold. Björn decided all four B3 kit notes in; the template fixes found here are in skills-bob 1.3.0's template.
- 2026-11-01: Sunday Organ entered in the family registry (ship-bob 1.1.1: `Suor`, coral, `com.oberliaudio.sundayorgan`). A pasted note the same evening ("category accents: sage for mix tools, peacock for analysis; pull main") matched nothing on GitHub (main of this repo, ~/bob-skills, the template) and names no instrument category: coral stays; to clarify with Björn.
