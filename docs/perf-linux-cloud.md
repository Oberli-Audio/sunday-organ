## CPU (rule 20) - vm, 3 runs, 20 s each

| arch | preset | fs/block | p50 | p99 | p99.9 | max | reading | first block | over (reported) |
|---|---|---|---|---|---|---|---|---|---|
| x86_64 | gospel-full | 48000/64 | 6.7 | 12.8 | 20.1 | 195.4 at 19.42 s | scheduling | 9 | 3 |
| x86_64 | gospel-full | 44100/32 | 6.4 | 12.8 | 22.1 | 341.5 at 4.12 s | scheduling | 6 | 4 |
| x86_64 | rock-drive | 48000/64 | 6.4 | 12.1 | 26.6 | 371.3 at 11.01 s | scheduling | 10 | 8 |
| x86_64 | rock-drive | 44100/32 | 6.4 | 12.9 | 25.2 | 340.5 at 11.12 s | scheduling | 6 | 12 |
| x86_64 | bass-split | 48000/64 | 6.3 | 11.5 | 29.3 | 238.4 at 0.39 s | scheduling | 8 | 4 |
| x86_64 | bass-split | 44100/32 | 6.1 | 12.4 | 23.9 | 290.7 at 1.58 s | scheduling | 7 | 4 |
| x86_64 | split-comping | 48000/64 | 6.4 | 11.8 | 26.7 | 791.9 at 12.38 s | scheduling | 8 | 3 |
| x86_64 | split-comping | 44100/32 | 6.3 | 12.7 | 29.7 | 343.7 at 4.07 s | scheduling | 7 | 12 |
| x86_64 | idle | 48000/64 | 1.3 | 8.0 | - | - | idle | - | - |
