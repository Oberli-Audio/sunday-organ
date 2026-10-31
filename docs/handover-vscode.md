# Handover: cloud session -> Claude Code in VS Code on Björn's Mac (2026-10-31)

Done 2026-11-01 by Claude Code on the Mac, except A.3 (Björn plays): `docs/status.md` has the
numbers, F-9 and F-10 the two Mac-only defects; part B is sound-design-bob 5.2.0 and skills-bob
1.3.0 in ~/bob-skills (Björn decided all four B3 notes in).

Written by the cloud session that took Sunday Organ from G1 to G6 on Linux (branch
`g0-brief-and-sketch`). Read `CLAUDE.md`, `docs/status.md` (Gates, Open exceptions, Handoff) and
this file; then do part A, then part B. Part B edits `~/bob-skills`, not this repo.

## A. Sunday Organ on the Mac (this repo)

1. `git pull` (the branch must be at `ee45a69` or later: the macOS signing fix and the Apple clang
   fix are in it).
2. `tools/install_plugin.sh`: builds the release preset (universal), verifies the signature,
   installs the VST3 to `~/Library/Audio/Plug-Ins/VST3/`. If the build or `codesign --verify`
   fails, fix it here (the cloud box had no Mac to try `ee45a69` on: the release preset now runs
   `dsymutil`, `strip -x`, then `codesign --force --sign -` per bundle, and links with
   `-object_path_lto` so the dSYM has symbols). A fix that is a defect gets its row in
   `docs/failures.md` and a check that fails without it.
3. Björn rescans in Ableton Live 10.1 (Rosetta) and plays: init patch, Gospel Full, Ballad, Bass
   Split. What he hears goes into the listening debt in `docs/status.md`.
4. The Mac-only part of G6 (`docs/status.md`, Handoff, "Next commands"): `ctest --preset all`;
   `perf.py run ... --arch x86_64` under Rosetta (the budget machine: closes or confirms EX-1);
   `validate_plugin.py --profile full` (Steinberg validator + pluginval on macOS); the RTSan
   preset; the snapshot pass on a 1x display (`SundayOrganGuiSnapshot`, not built by default).
5. Rewrite `docs/status.md` with the numbers, commit, push to `g0-brief-and-sketch`.

## B. Skill updates in ~/bob-skills (skills-bob release procedure)

One coordinator session edits `~/bob-skills`; Björn runs the printed git line at the end.

### B1. sound-design-bob: hand-over from a cloud session (minor: 5.1.0 -> 5.2.0)

In `plugins/sound-design-bob/skills/sound-design-bob/SKILL.md`, section "Where you are running",
add after the claude.ai/Cowork bullet:

```markdown
- **Claude Code in a cloud session (a Linux container, no Mac):** the harness, Faust, the
  Linux VST3, pluginval and the sanitizers run there; macOS builds, Rosetta CPU, the hosts and
  listening do not. Push the branch, then hand over in this order: if the session can reach
  Björn's Mac (Remote Control), use it; otherwise give him the commands, each in its own block:
  a clone when `~/Developer/oberli-audio/<slug>` is not one yet (`git clone --branch <branch>
  https://github.com/Oberli-Audio/<slug>.git`; an existing non-clone folder is moved aside, never
  deleted), `git pull`, then `tools/install_plugin.sh` (build, verify the signature, install,
  rescan). The work continues in a Claude Code session on the Mac (VS Code or the terminal) from
  a handover file in `docs/` that names what was run where and what only the Mac can close.
```

### B2. Template fixes (tools/template-src and the skills that generate template/)

Each was found in Sunday Organ; the commit there shows the code. Port them generically (no
product names), then `tools/test_template.py` (effect and instrument):

| # | File in the template | Defect | Fix (Sunday Organ commit) |
|---|---|---|---|
| 1 | `.gitignore` | `*.lib` (MSVC) also drops Faust libraries | `!/sound design/**/*.lib` (`c107476`) and a check that every `library()`/`import()` of a tracked `.dsp`/`.lib` is in git (`tools/tests/check_sources.py`, CTest `design_sources_in_git`) |
| 2 | harness `Main.cpp` | `sample_rate` echoed as a double: `dspkit.py smoke` fails (it compares text) | echo an integral rate as an int (`2490698`) |
| 3 | harness `Main.cpp` | work buffer only `--max-block` long: heap overflow on an oversized block | `jmax (maxBlock, block)` (`8a8cc78`, F-5) |
| 4 | harness `Main.cpp` | `--list-params` reports steps 0 for `AudioParameterInt` (not `isDiscrete()`): `paramgen check` fails on any int | steps when `getNumSteps()` differs from the default (`8a8cc78`, F-6) |
| 5 | harness `Main.cpp` | `--block=0` refused, though the contract and `test_template.py` require a zero-length block | block 0 = a zero-length `processBlock` before each `--max-block` block (`8a8cc78`) |
| 6 | harness `Main.cpp` | tail measured to the start of the last audible sample: the tail test reads -89.99 dBFS | `(lastAudible + 1) / rate` (`8a8cc78`) |
| 7 | harness `Main.cpp` | the malloc trap exists on macOS only | Linux variant on `__libc_malloc` and friends; off under ASan (`2490698`) |
| 8 | `State.h` | a skewed float drifts on every save/load (`convertFrom0to1 (getValue())`); the template's round-trip test uses `outGain` (linear) and misses it | write a float's `get()` rounded to 6 significant digits, load through the nearest normalised float (`58132a0`, F-4); test with a skewed parameter |
| 9 | `PluginProcessor.h` | `getProgramName` returns "": the Steinberg validator fails "Scan Programs" inside pluginval L10 | return "Default" (`8a8cc78`, F-8) |
| 10 | `CMakeLists.txt` | macOS release: `strip` after JUCE's ad-hoc signature breaks it; LTO deletes `/tmp/lto.o` before `dsymutil` | `-object_path_lto` per format, `codesign --force --sign -` after `strip` (`ee45a69`; confirm on the Mac first, part A) |
| 11 | `tools/` | no install script | `tools/install_plugin.sh` from this repo |

### B3. Kit and playbook notes (sound-design-bob; decide each with Björn)

- `paramgen.py juce`: `int` parameters get no `stringFromValue`, so `format_kind note` (and
  every other kind) is lost for ints - Sunday Organ's EX-4. Emit the value strings for ints too.
- `test_template.py` Health: p99.9 < 25 % is asserted on whatever machine runs it; on a cloud VM
  it fails now and then on a scheduling spike. Judge it only on the budget machine (an env flag),
  report elsewhere - as rule 20 already says for `over_deadline`.
- `dsp-selection.md` S.1 has no organ row; proposed: "tonewheel organ | shared free-running
  wheels (exact quadrature oscillators), contacts per key with staggered closing, drawbar busses,
  scanner as modulated Lagrange delay, rotary speaker per S.2 | per-key oscillators (breaks the
  shared-wheel sums), a sine table with a truncated index".
- Faust prototypes: `fi.dcblocker` is a fixed pole (38 Hz at 48 kHz, 153 Hz at 192 kHz): rule 12;
  `os.osc`/`os.oscp` are a 64k table with a truncated index (about -100 dB of their own
  error): prototypes should use `fi.dcblockerat(f)` and an exact oscillator. A line in F.8's
  "Why Faust first" list.

### B4. Release

Bump sound-design-bob (and any other changed skill), `CHANGELOG.md` entries, `sh publish.sh`
(runs every check, rebuilds and tests `template/`), then Björn runs the printed git line and the
template sync line.
