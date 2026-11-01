# Sonic brief (owner-confirmed 2026-10-31; amend below, never edit the YAML)

```yaml
name: Sunday Organ
track: instrument
stages: [control, generation, processing, output]
                 # control: MIDI channels 1-3, split points, sustain, mod wheel -> Leslie
                 # generation: tonewheels, contacts, drawbars, percussion
                 # processing: scanner vibrato/chorus, preamp drive, Leslie
                 # output: stereo, volume
type: acoustic-emulation
musical_role: harmonic-bed
tier: P
one_sentence: A tonewheel organ and rotary speaker for church, gospel and worship bands - drawbars, percussion, the scanner and a Leslie that speeds up and slows down like a real one.
references:
  - "Hammond B-3 with Leslie 122: the target sound and behaviour; differs: one plugin, 61-key split for one-keyboard players"
  - "setBfree (GPL): read for ideas only, no code taken; differs: modern editor, measured Leslie Doppler, loudness-matched bank"
  - "Native Instruments Vintage Organs / Arturia B-3 V: commercial references; differs: free, smaller, one sound done well"
must_do:
  - Upper and lower manual with 9 drawbars each, pedals with 16' and 8'
  - Play from one keyboard (split key) or three MIDI channels (1 upper, 2 lower, 3 pedals)
  - Leslie fast/slow on the mod wheel, brake, the speed change audible as the instrument's signature
  - Sustain pedal (CC64) latches keys (rule 14)
  - Expression pedal (CC11) as a swell before the preamp, so it also changes the drive
  - Load in Ableton Live 10.1 under Rosetta and Live on Windows, recall state exactly
defining_features:          # each one gets a presence test (rule 13)
  - "Shared tonewheels: two keys on the same wheel sum phase-coherently (+6 dB, not +3)"
  - "Drawbar steps of about 3 dB; 0 is silent"
  - "Key click from contact switching: audible transient at note-on that scales with Key Click"
  - "Percussion: single trigger, 2nd or 3rd harmonic, fast/slow, cuts the 1' drawbar while on"
  - "Scanner: V1-V3 pitch swing increasing, C1-C3 with dry mix, at about 6.9 Hz"
  - "Leslie: horn and drum at their own speeds, separate spin-up and spin-down, never locked; brake stops both"
  - "Leslie Doppler of a moving source: within 1 cent of the geometric model"
  - "Below about 150 Hz mono and unmodulated (rule 15)"
out_of_scope:
  - Velocity response (an organ has none), voice stealing, per-note pitch bend
  - Leslie cabinet impulse responses, other cabinets, tube-amp model of the 122 beyond the drive stage
  - Effects after the Leslie (reverb, EQ): the DAW does that
core_controls:
  - "Upper drawbars: the sound itself, from flute to full"
  - "Leslie Fast: slow chorale vs fast tremolo, and the ramp between them"
  - "Drive: clean church organ to growl"
  - "Vibrato/chorus: still vs the classic C3 shimmer"
  - "Percussion: the bright attack of jazz and gospel lines"
signal_flow: |
  MIDI ch1 + split ─┬─> upper keys ─┐
  MIDI ch2 ─────────┼─> lower keys ─┤   91 tonewheels (shared, free-running)
  MIDI ch3 + split ─┴─> pedal keys ─┤          │
                                     └─ contacts (9 per key) ─> drawbar busses
     upper ─> + percussion ─┐
     lower ──(vibrato lower)┼─> scanner V/C ─┐
                            └────────────────┼─> + pedals ─> preamp drive ─> Leslie ─> volume ─> L/R
                                              (horn > 800 Hz | drum 200-800 | mono < 200)
cpu_budget: { p999_pct: 25, max_pct: 50, idle_pct: 2, at: 48k/64, slice: x86_64-rosetta, preset: heaviest }
cpu_reference_machine: "Apple M3 Pro, Ableton Live 10.1 under Rosetta (x86_64 slice)"
instances_expected: 1 per project, 1 in a live rig
latency_budget: 0 samples (played live; no look-ahead, no oversampling latency)
sample_rates: [44100, 48000, 88200, 96000, 176400, 192000]
channels: stereo
register: "upper and lower C2-C7 (MIDI 36-96), pedals C1-C3 (MIDI 24-48) - set by listening at G2"
register_intent:
  - "pedals C1-C3: round, mono, foundation; no Leslie wobble below 200 Hz"
  - "below C3 on the manuals: warm, never muddy with 16' out"
  - "C3-C5: the voiced sound, where the Leslie and percussion are judged"
  - "above C5: bright with upper drawbars, foldback keeps the top from turning shrill"
presets:
  bank_size: 16
  categories: [Jazz, Gospel, Worship, Rock, Ballad, Split]
  reference_chord: C3-E3-G3-C4, 4 s hold, 2 s tail (no velocity)
  loudness_window: integrated over the hold
  edge_presets: [Gospel Full (loudest), Ballad (darkest), Rock Drive (most drive), Sanctuary (widest)]
  naming: English, plain, short; the registration digits in the preset notes, not the name
mix_context: "with acoustic guitar, piano, bass and group vocals in a worship band: the default leaves 1-4 kHz to the vocals (upper drawbars out), pedals off when a bass player is there"
quality_targets:
  alias_floor_db:     { target: "< -80 dB re fundamental", method: "C7, 8' only, Drive 1, Leslie off: largest non-harmonic peak below 20 kHz (harmonic output, so a spectral floor; sketch: -99.9 dB)" }
  thd_n_db:           { target: "< -60 dB at Drive 0", method: "C4 8' only, Leslie off, harmonic_profile; the organ itself is sine-pure" }
  response_error_db:  { target: "+/-0.5 dB", method: "Leslie with rotors braked, crossover sum of an impulse, both mics (E.6.6)" }
  loudness:           { target: "presets -18 LUFS +/-1 LU", method: "presetlint.py render on the reference chord, F.13.9 protocol" }
  keyboard_span_lu:   { target: "< 6 LU per manual over C2-C7 at 888000000", method: "register battery, every 3rd key, integrated per note; reached with a per-wheel level taper (sketch without taper: 6.8 LU)" }
  low_register:       { target: "side/mid below 150 Hz < -30 dB", method: "pedals + lower chord with Leslie fast (sketch: -33 dB)" }
  other:
    - { target: "Doppler within 1 cent of the moving-source model", method: "tests/doppler_check.py on the horn path, 2 kHz, fast (sketch: 0.22 cent)" }
    - { target: "rotor rates within 2 % of 0.83/6.67 Hz (horn), 0.67/5.67 Hz (drum)", method: "AM rate of a steady note per band after settling" }
    - { target: "no zipper on drawbar moves and split moves", method: "maximum-rate automation, max_click_db" }
open_questions:
  - "none at confirmation; constants without a reference (rotor times, percussion decay, scanner depths) are set by ear and carried as listening debt"
```

## Amendments
Each dated, beneath the confirmed YAML; for Björn to confirm or reject at the next review.
- 2026-10-31 (G2): keyboard taper decided as 1.0 dB per octave above the C4 wheel (the generator's own curve); span 2.7 LU per manual measured on the plugin.
- 2026-10-31 (G2): Expression (CC11 and the parameter) is gain = e^2 before the preamp: half travel -12 dB, 10 % -40 dB, 0 silent. CC11 and the parameter: the one moved last wins; the same for CC1 and Leslie Fast.
- 2026-10-31 (G3): MIDI channels other than 2 and 3 play like channel 1 (a keyboard on any channel works); CC64 latches the manual keys of its own channel; the pedals do not latch. Channel 1 keys below Pedal Split play the pedals at pitch (C2-B2 on a 61-key board), decided when the key goes down; channel 1 C1-B1 reach the pedals only below Pedal Split.
- 2026-10-31 (G3): response_error_db is measured on the crossover (the three bands' sum, rotors braked, no horn voicing): 4e-7 dB. The braked full Leslie, horn resonance and reflections included, is characterised, not judged (-2.7 to +2.0 dB).
- 2026-10-31 (G3): the Doppler target is judged on the horn's Doppler delay (0.02 cent); the full horn path adds the moving lowpass's phase swing, 3.5 cents p99 (EX-3 in status.md).
- 2026-11-01 (G2 reopened, after Björn's first play: chords distort): **Drive 0 is clean on the fullest chord** (Björn, 2026-11-01): distortion re signal < -60 dB at Drive 0 and full expression for 10 upper keys (48-84) with all drawbars, 4 lower keys with all drawbars and both pedal drawbars (`tools/measure/preamp_prestudy.py`, "full organ"); the default Drive 20 % stays near clean on Init's 10 keys (< -50 dB); chords growl from about 30-40 %. Proposed with it, for Björn to confirm: Drive holds the loudness of the reference chord (Init, 48/52/55/60) within 1 LU over 0-100 %; one key and bigger chords move with the saturation and are reported (pre-study: one key +5.5 dB, the full organ -12.5 dB at 100 %). The THD+N target at Drive 0 now applies to that chord as well (rule 3).
- 2026-11-01 (G1/G3, Björn: "quieter bank + safety limiter"): the clean stage needs headroom (a clean 10-key chord would peak at about +3 dBFS and the full organ at +13 dBFS with the bank at -18 LUFS). The bank's loudness target moves to **-23 LUFS +/-1 LU** on the reference chord (Init -23.00 at the defaults), and a **safety limiter** ends the chain after the Leslie: the output never above -1 dBTP, 1.5 ms look-ahead reported to the host, transparent (gain exactly 1) below its -1.7 dBFS detection ceiling (S.2 "peak / true-peak limiter", "output safety stage"). Targets: `true_peak_dbtp` <= -1 dBTP on the fullest chord at Output +12 dB; `loudness_lufs` -23 +/-1 LU.
- 2026-11-01 late evening (Björn, after the replay: "drive ok"): the 1 LU reference for Drive (the amendment above) is confirmed.
- 2026-11-01 late evening (G1/G2, Björn: "a lowpass after the drive that follows the Drive setting, like the 122's amplifier and speakers: take off the fizz and keep the growl"): the preamp ends in a **speaker roll-off**, LR4 (24 dB/oct), its cutoff following Drive from a wire at Drive 0 (200 kHz, analog domain, no prewarping) to 6 kHz at Drive 100 %, exponential in Drive: above the highest wheel (5.92 kHz) up to 75 %, so only a hard-driven organ darkens. Measured at Drive 100 % (`tools/measure/drive_character.py`): the distortion below 3 kHz (the growl) unchanged; 10 upper keys lose 6 dB at 5-8 kHz, 18 dB at 8-12 kHz, 36 dB at 12-20 kHz. Presence test: `test_speaker_lowpass_follows_drive`.
- 2026-11-01 late evening (Björn: "revoice yourself"): the bank's Drive values voiced by measurement, each preset's words as a distortion level on its own registration and the reference chord at full expression (`tools/presets/voice_drive.py`): clean < -60 dB, light -50, worn -45, warm -40, grit -30, driven -20, heavy -12 dB.
