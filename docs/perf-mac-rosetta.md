## CPU (rule 20) - m3pro-rosetta, 3 runs, 20 s each

| arch | preset | fs/block | p50 | p99 | p99.9 | max | reading | first block | over (reported) |
|---|---|---|---|---|---|---|---|---|---|
| x86_64 | gospel-full | 48000/64 | 4.9 | 5.8 | 8.3 | 67.1 at 19.20 s | scheduling | 7 | 0 |
| x86_64 | gospel-full | 44100/32 | 4.5 | 5.5 | 7.9 | 30.5 at 17.82 s | scheduling | 8 | 0 |
| x86_64 | rock-drive | 48000/64 | 4.9 | 5.3 | 6.0 | 17.9 at 3.97 s | scheduling | 8 | 0 |
| x86_64 | rock-drive | 44100/32 | 4.5 | 5.1 | 5.7 | 6.7 at 7.19 s | scheduling | 8 | 0 |
| x86_64 | bass-split | 48000/64 | 4.6 | 5.1 | 5.6 | 12.1 at 13.39 s | scheduling | 7 | 0 |
| x86_64 | bass-split | 44100/32 | 4.3 | 5.0 | 5.7 | 11.3 at 17.44 s | scheduling | 8 | 0 |
| x86_64 | split-comping | 48000/64 | 4.9 | 5.7 | 7.9 | 15.5 at 9.16 s | scheduling | 7 | 0 |
| x86_64 | split-comping | 44100/32 | 4.5 | 5.5 | 6.0 | 19.7 at 19.29 s | scheduling | 8 | 0 |
| arm64 | idle | 48000/64 | 0.6 | 3.0 | - | - | idle | - | - |

Idle on the x86_64 slice (the row above ran native: `perf.py` measured idle outside `--arch`, fixed in the kit 2026-11-01): p50 0.8 %, p99 5.0 % (`perf.py run ... --arch x86_64 --presets gospel-full --config 48000/64 --seconds 10 --runs 1`, the fixed kit).
