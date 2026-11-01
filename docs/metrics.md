# Metric table (G3) - Sunday Organ

Every quality target of `docs/brief.md`, measured on the plugin's harness: `python3 tools/measure/metrics.py --md docs/metrics.md` (48 kHz, seed 1).

| Metric | Target | Value | Pass | Method |
|---|---|---|---|---|
| alias_floor_db | < -80 dB re fundamental | -120.47 | yes | C7 8' only, Drive 100 %, Leslie off, leakage and click 0; largest non-harmonic peak < 20 kHz re the fundamental (f0 2092.3 Hz), at 2111 Hz |
| thd_n_db | < -60 dB at Drive 0 | -126.96 | yes | C4 8' only, Leslie off, Drive 0, leakage 0: dspkit.thd_db (10 harmonics) at f0 261.54 Hz |
| response_error_db | +/-0.5 dB | 0.00 | yes | impulse through the Leslie crossover (LR4 800 + 200 Hz, rotors braked, no horn voicing), 20 Hz-20 kHz max |dB|, braked full Leslie (characterised, horn voicing included): L -2.7..2.0 dB |
| keyboard_span_lu | < 6 LU per manual | 2.69 | yes | every 3rd key C2-C7, 888000000, dry, integrated 0.2-0.7 s per note: upper 2.7 LU, lower 2.7 LU |
| low_register | side/mid < 150 Hz < -30 dB | -30.92 | yes | pedal C1 + lower C3-E3-G3, defaults, Leslie fast (settled from 2 s): side/mid below 150 Hz (8th-order LP) |
| doppler_cents | < 1 cent vs moving source | 0.02 | yes | tools/g5/doppler_check.py: 2 kHz through the horn's Doppler delay at 6.67 Hz, p99 |error| vs moving source (vs moving listener 1.83 c; full path with moving LP and AM 3.54 c, EX-3) |
| rotor_rate_error_pct | within 2 % | 0.85 | yes | rate per rotor, 12 s after 8 s settling: horn by its Doppler FM on C6 (its AM has two maxima per turn from the cabinet reflections), drum by the AM of C4 (envelope FFT) after settling: horn 0.82 / 6.67 Hz, drum 0.67 / 5.66 Hz (slow / fast); worst error % |
| zipper_db | no zipper: < +1 dB over static | -0.58 | yes | largest sample step at maximum-rate automation (5 upper drawbars full swings every 0.25 s; split key end to end every 0.5 s; block 64) re the brightest static state: drawbars -1.72 dB, split -0.58 dB |
| chord_thd_db | < -60 dB at Drive 0, fullest chord | -63.81 | yes | preamp probe, Drive 0, expression 1 vs 0.5, 0.4-1.4 s: residual re signal |
| drive_level_lu | reference chord < 1 LU over Drive | 0.13 | yes | C3-E3-G3-C4, 888000000, Leslie off, Drive 0/25/50/75/100 %: -22.10 -22.10 -22.16 -22.16 -22.04 LUFS |
| true_peak_dbtp | <= -1 dBTP at the output | -1.70 | yes | fullest chord, Leslie fast, Output +12 dB, Drive 0 / 100 %: -1.70 / -3.10 dBTP (dspkit 4x) |
| loudness_lufs | presets -23 LUFS +/-1 LU | 0.04 | yes | presetlint.py render presets.csv --tier P on C3-E3-G3-C4, 4 s hold: 16 presets, -23.04 to -22.96 LUFS; value = worst distance from -23 LU |
