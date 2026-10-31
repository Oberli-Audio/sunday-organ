"""Sketch evidence on the renders. Usage: python3 harness/evidence.py <dsp-kit dir>
Safety (peak, NaN/Inf, DC), loudness, keyboard span, mono bass, alias floor, preset spread, CPU."""
import sys, glob, os, numpy as np, scipy.signal as s
sys.path.insert(0, sys.argv[1]); import dspkit as k
R = "renders"
def load(p): x, fs = k.read_wav(p); return k.as_2d(x), fs

print("== safety and loudness (48 kHz unless named)")
for p in sorted(glob.glob(f"{R}/*.wav") + glob.glob(f"{R}/*/*.wav")):
    x, fs = load(p)
    print(f"{os.path.relpath(p, R):44s} peak {k.peak_dbfs(x):6.1f} dBFS  TP {k.true_peak_dbtp(x, fs):6.1f}  "
          f"nonfinite {int(np.count_nonzero(~np.isfinite(x)))}  DC {k.dc_offset_dbfs(x):7.1f}  {k.integrated_lufs(x, fs):6.1f} LUFS")

print("\n== keyboard span per manual (09/10_register_*, every 3rd key C2..C7, 888000000, dry)")
for name in ["09_register_upper", "10_register_lower"]:
    x, fs = load(f"{R}/{name}.wav"); keys = list(range(36, 97, 3)); lu = []
    for i, n in enumerate(keys):
        lu.append(k.integrated_lufs(x[int((0.25 + 0.7 * i) * fs):int((0.7 + 0.7 * i) * fs)], fs))
    print(f"  {name}: " + "  ".join(f"{n}:{v:.1f}" for n, v in zip(keys, lu)))
    print(f"  {name}: span {max(lu) - min(lu):.1f} LU (target < 6)")

print("\n== expression before the preamp (11_expression_swell, Drive 0.6): level and crest factor (lower crest = more drive)")
x, fs = load(f"{R}/11_expression_swell.wav"); m = x.mean(1)
for t0, lab in [(0.6, "e=1.0"), (3.5, "e~0.33"), (4.8, "e=0.1"), (7.3, "e=1.0 again")]:
    seg = m[int(t0 * fs):int((t0 + 0.3) * fs)]
    print(f"  {lab:12s} {k.db(np.sqrt(np.mean(seg**2))):6.1f} dBFS RMS  crest {k.db(np.abs(seg).max()/np.sqrt(np.mean(seg**2))):4.1f} dB")

print("\n== channels (12_three_channels_and_split): pedals present, per section")
x, fs = load(f"{R}/12_three_channels_and_split.wav"); sos = s.butter(8, 100, "lp", fs=fs, output="sos")
for t0, lab in [(0.6, "ch3 pedal F2 (87 Hz)"), (4.2, "ch1 pedal split F2")]:
    seg = s.sosfilt(sos, x.mean(1))[int(t0 * fs):int((t0 + 0.5) * fs)]
    print(f"  {lab:24s} below 100 Hz {k.db(np.sqrt(np.mean(seg**2))):6.1f} dBFS RMS")

print("\n== mono bass: side vs mid below 150 Hz")
for name in ["01_init_chord_slow", "05_full_drawbars_driven_fast", "07_split_lower_comp_upper_lead", "08_pedals_with_chords", "12_three_channels_and_split"]:
    x, fs = load(f"{R}/{name}.wav"); sos = s.butter(8, 150, "lp", fs=fs, output="sos")
    m = s.sosfilt(sos, (x[:, 0] + x[:, 1]) / 2); sd = s.sosfilt(sos, (x[:, 0] - x[:, 1]) / 2)
    print(f"  {name:36s} side/mid {k.db(np.sqrt(np.mean(sd**2)) / np.sqrt(np.mean(m**2))):6.1f} dB")

print("\n== alias floor: C7 8' only, drive 1, Leslie off (largest non-harmonic peak re fundamental, < 20 kHz)")
f0 = 20.0 * 85 / 104 * 2 ** 7
for name in ["x_alias_C7_8ft_drive1", "x_alias_192k"]:
    x, fs = load(f"{R}/evidence/{name}.wav"); y = x[int(0.5 * fs):int(2.5 * fs), 0]
    F = np.abs(np.fft.rfft(y * s.windows.blackmanharris(len(y)))); f = np.fft.rfftfreq(len(y), 1 / fs)
    Fd = k.db(F / F.max()); harm = np.zeros_like(f, bool)
    for h in range(1, int(fs / 2 / f0) + 1): harm |= abs(f - h * f0) < 15
    band = (f > 20) & (f < 20000) & ~harm
    print(f"  {name:24s} fs {fs:6d}  worst non-harmonic {Fd[band].max():6.1f} dB at {f[band][Fd[band].argmax()]:7.0f} Hz")

print("\n== presets on the reference chord (integrated over the hold, after the bank volume offsets)")
v = {}
for p in sorted(glob.glob(f"{R}/presets/*.wav")):
    x, fs = load(p); v[os.path.basename(p)[2:-4]] = k.integrated_lufs(x[int(0.5 * fs):int(4.5 * fs)], fs)
med = np.median(list(v.values()))
print("  " + "  ".join(f"{n} {l:.1f}" for n, l in v.items()))
print(f"  median {med:.1f} LUFS, spread {max(v.values()) - min(v.values()):.1f} LU, worst offset {max(abs(l - med) for l in v.values()):.1f} LU")

if os.path.exists("/tmp/times.txt"):
    t = np.loadtxt("/tmp/times.txt")
    print("\n== CPU, worst case (10 notes, all 18 drawbars at 8, C3, Leslie fast, drive 0.7), 48 kHz / 64, one run")
    print("  ", k.block_time_report(t, 64, 48000, warmup=50))
