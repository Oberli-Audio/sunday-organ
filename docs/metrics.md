# Metric table (G3) - Sunday Organ

Every quality target of `docs/brief.md`, measured on the plugin's harness: `python3 tools/measure/metrics.py --md docs/metrics.md` (48 kHz, seed 1).

| Metric | Target | Value | Pass | Method |
|---|---|---|---|---|
| alias_floor_db | < -80 dB re fundamental | -120.50 | yes | C7 8' only, Drive 100 %, Leslie off, leakage and click 0; largest non-harmonic peak < 20 kHz re the fundamental (f0 2092.3 Hz), at 2111 Hz |
| thd_n_db | < -60 dB at Drive 0 | -70.47 | yes | C4 8' only, Leslie off, Drive 0, leakage 0: dspkit.thd_db (10 harmonics) at f0 261.54 Hz |
| response_error_db | +/-0.5 dB | 0.00 | yes | impulse through the Leslie crossover (LR4 800 + 200 Hz, rotors braked, no horn voicing), 20 Hz-20 kHz max |dB|, braked full Leslie (characterised, horn voicing included): L -2.7..2.0 dB |
| keyboard_span_lu | < 6 LU per manual | 2.72 | yes | every 3rd key C2-C7, 888000000, dry, integrated 0.2-0.7 s per note: upper 2.7 LU, lower 2.7 LU |
| low_register | side/mid < 150 Hz < -30 dB | -30.93 | yes | pedal C1 + lower C3-E3-G3, defaults, Leslie fast (settled from 2 s): side/mid below 150 Hz (8th-order LP) |
| doppler_cents | < 1 cent vs moving source | 0.02 | yes | tools/g5/doppler_check.py: 2 kHz through the horn's Doppler delay at 6.67 Hz, p99 |error| vs moving source (vs moving listener 1.83 c; full path with moving LP and AM 3.54 c, EX-3) |
| rotor_rate_error_pct | within 2 % | 0.85 | yes | rate per rotor, 12 s after 8 s settling: horn by its Doppler FM on C6 (its AM has two maxima per turn from the cabinet reflections), drum by the AM of C4 (envelope FFT) after settling: horn 0.82 / 6.67 Hz, drum 0.67 / 5.66 Hz (slow / fast); worst error % |
| zipper_db | no zipper: < +1 dB over static | -1.60 | yes | largest sample step at maximum-rate automation (5 upper drawbars full swings every 0.25 s; split key end to end every 0.5 s; block 64) re the brightest static state: drawbars -2.45 dB, split -1.60 dB |
| loudness_lufs | presets -18 LUFS +/-1 LU | 0.63 | yes | presetlint.py render presets.csv --tier P on C3-E3-G3-C4, 4 s hold: 16 presets, -18.03 to -17.37 LUFS; value = worst distance from -18 LU |
