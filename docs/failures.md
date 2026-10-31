# Failures - the product's own rows (D.9.3)

| ID | Symptom | Cause | Confirming measurement | Fixed in | Regression test |
|---|---|---|---|---|---|
| F-1 | `sound design/dsp/tonewheel.dsp` does not compile from a fresh clone: `scanner.lib` and `leslie.lib` missing | `.gitignore` excludes `*.lib` (MSVC import libraries) and so silently dropped the two Faust libraries; only their compiled form in `harness/render.cpp` survived | `python3 tools/tests/check_sources.py`: 4 references not in git (2026-10-31) | 2026-10-31: libraries reconstructed from `render.cpp`; nulls against the v0.3 binary at -140 to -172 dB re signal (float32 LSB), the scanner score bit-identical; `.gitignore` exception `!/sound design/**/*.lib` | `design_sources_in_git` (`check_sources.py`, label fast) |
