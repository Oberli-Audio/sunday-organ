#!/usr/bin/env python3
"""G3 metric table: every quality target of docs/brief.md, measured on the plugin's harness with the
method the brief names. Writes docs/metrics.md (and --json). Each row: target, method, command
detail, number, pass. Usage: python3 tools/measure/metrics.py [--md docs/metrics.md] [--json f]
(HARNESS, DOPPLER = SundayOrganDopplerCheck and LESLIE_PROBE paths from the environment, defaults
in build/)."""
import argparse, json, os, subprocess, sys, tempfile
import numpy as np
import scipy.signal as s
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tests"))
import organ as O  # noqa: E402
K = O.K
ROOT = O.ROOT
HZ = lambda w: 20 * [85/104, 71/82, 67/73, 105/108, 103/100, 84/77, 74/64, 98/80, 96/74, 88/64, 67/46, 108/70][w % 12] * 2 ** (w // 12 + 1)


def wheel_of(note, offset=0):   # 8' of manual key `note`
    w = note - 36 + 12 + offset
    up = max(0, int((w - 79) / 12))
    return w - 12 * up


def alias_floor():
    x, fs, _ = O.render(dict(O.DRY, drive=100, **O.bars("008000000")), notes="96", seconds=3.0)
    y = x[int(0.5 * fs):int(2.5 * fs), 0]
    f0 = HZ(wheel_of(96))
    F = np.abs(np.fft.rfft(y * s.windows.blackmanharris(len(y)))); f = np.fft.rfftfreq(len(y), 1 / fs)
    Fd = K.db(F / F.max()); harm = np.zeros_like(f, bool)
    for h in range(1, int(fs / 2 / f0) + 1): harm |= abs(f - h * f0) < 15
    band = (f > 20) & (f < 20000) & ~harm
    v = float(Fd[band].max())
    return v, v < -80, "C7 8' only, Drive 100 %%, Leslie off, leakage and click 0; largest non-harmonic peak < 20 kHz re the fundamental (f0 %.1f Hz), at %.0f Hz" % (f0, f[band][Fd[band].argmax()])


def thd_n():
    x, fs, _ = O.render(dict(O.DRY, **O.bars("008000000")), notes="60", seconds=2.0)
    y = x[int(0.5 * fs):, 0]; f0 = HZ(wheel_of(60))
    v = float(K.thd_db(y, fs, f0))
    return v, v < -60, "C4 8' only, Leslie off, Drive 0, leakage 0: dspkit.thd_db (10 harmonics) at f0 %.2f Hz" % f0


def response_error():
    tool = os.environ.get("LESLIE_PROBE", str(ROOT / "build" / "SundayOrganDopplerCheck"))
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "ir.wav")
        subprocess.run([tool, p, "1", "48000", "impulse"], check=True)
        x, fs = K.read_wav(p); x = K.as_2d(x)
    H = np.fft.rfft(x[:, 0]); f = np.fft.rfftfreq(len(x), 1 / fs); band = (f > 20) & (f < 20000)
    err = float(np.max(np.abs(K.db(np.abs(H[band])))))
    Hb = [np.fft.rfft(x[:, c]) for c in (1, 2)] if x.shape[1] > 2 else []
    braked = ", braked full Leslie (characterised, horn voicing included): L %.1f..%.1f dB" % (
        K.db(np.abs(Hb[0][band])).min(), K.db(np.abs(Hb[0][band])).max()) if Hb else ""
    return err, err <= 0.5, "impulse through the Leslie crossover (LR4 800 + 200 Hz, rotors braked, no horn voicing), 20 Hz-20 kHz max |dB|" + braked


def keyboard_span():
    out = {}
    for manual, flag in (("upper", "notes"), ("lower", "lower")):
        lu = []
        for n in range(36, 97, 3):
            x, fs, _ = O.render(dict(O.DRY, **O.bars("888000000", manual)), seconds=0.9, gate=0.7, **{flag: str(n)})
            lu.append(K.integrated_lufs(x[int(0.2 * fs):int(0.7 * fs)], fs))
        out[manual] = (max(lu) - min(lu), lu)
    v = max(out["upper"][0], out["lower"][0])
    return v, v < 6, "every 3rd key C2-C7, 888000000, dry, integrated 0.2-0.7 s per note: upper %.1f LU, lower %.1f LU" % (out["upper"][0], out["lower"][0])


def low_register():
    x, fs, _ = O.render({"leslieFast": 1}, pedals="24", lower="48,52,55", seconds=6.0)
    x = x[int(2 * fs):]
    sos = s.butter(8, 150, "lp", fs=fs, output="sos")
    m = s.sosfilt(sos, (x[:, 0] + x[:, 1]) / 2); sd = s.sosfilt(sos, (x[:, 0] - x[:, 1]) / 2)
    v = float(K.db(np.sqrt(np.mean(sd ** 2)) / np.sqrt(np.mean(m ** 2))))
    return v, v < -30, "pedal C1 + lower C3-E3-G3, defaults, Leslie fast (settled from 2 s): side/mid below 150 Hz (8th-order LP)"


def doppler():
    tool = os.environ.get("DOPPLER", str(ROOT / "build" / "SundayOrganDopplerCheck"))
    r = json.loads(subprocess.run([sys.executable, str(ROOT / "tools/g5/doppler_check.py"), tool], capture_output=True, text=True).stdout)
    v = r["delay_only"]["p99_err_source_cents"]
    return v, v < 1.0, "tools/g5/doppler_check.py: 2 kHz through the horn's Doppler delay at 6.67 Hz, p99 |error| vs moving source (vs moving listener %.2f c; full path with moving LP and AM %.2f c, EX-3)" % (r["delay_only"]["p99_err_listener_cents"], r["full_path"]["p99_err_source_cents"])


def am_rate(x, fs, band):
    sos = s.butter(4, band, "bp", fs=fs, output="sos")
    env = np.abs(s.hilbert(s.sosfilt(sos, x[:, 0])))
    env = s.decimate(s.decimate(env, 10), 10); efs = fs / 100
    env = env - env.mean(); env *= np.hanning(len(env))
    F = np.abs(np.fft.rfft(env, 16 * len(env))); f = np.fft.rfftfreq(16 * len(env), 1 / efs)
    sel = (f > 0.3) & (f < 12)
    return float(f[sel][F[sel].argmax()])


def rotor_rates():
    res = {}
    for fast in (0, 1):
        # horn: C6 8' (1 kHz, horn band); drum: C4 8' (262 Hz, drum band); settled (speeds start at target)
        x, fs, _ = O.render(dict(O.DRY, leslieOn=1, leslieFast=fast, micSpread=0, **O.bars("008000000")), notes="84", seconds=12.0)
        res[("horn", fast)] = am_rate(x[int(2 * fs):], fs, (900, 4000))
        x, fs, _ = O.render(dict(O.DRY, leslieOn=1, leslieFast=fast, micSpread=0, **O.bars("008000000")), notes="60", seconds=12.0)
        res[("drum", fast)] = am_rate(x[int(2 * fs):], fs, (220, 300))
    design = {("horn", 0): 0.83, ("horn", 1): 6.67, ("drum", 0): 0.67, ("drum", 1): 5.67}
    errs = {k: abs(res[k] / design[k] - 1) * 100 for k in design}
    v = max(errs.values())
    return v, v < 2.0, "AM rate (envelope FFT, 10 s, 0.03 Hz bins) per band after settling: horn %.2f / %.2f Hz, drum %.2f / %.2f Hz (slow / fast); worst error %%" % (res[("horn", 0)], res[("horn", 1)], res[("drum", 0)], res[("drum", 1)])


def zipper():
    rows = []
    base = dict(O.DRY, **O.bars("888000000"))
    x0, fs, r0 = O.render(base, notes="48,55,60,64", seconds=2.0, block=64)
    ref = r0["health"]["max_click_db"]
    auto = ["upperBar%d:0=0,0.25=1,0.5=0,0.75=1,1=0,1.25=1,1.5=0,1.75=1,2=0" % i for i in (1, 3, 4, 6, 9)]
    x1, fs, r1 = O.render(base, notes="48,55,60,64", seconds=2.0, block=64, automate=auto)
    x2, fs, r2 = O.render(base, notes="48,55,60,64", seconds=2.0, block=64, automate=["splitKey:0=0,0.5=1,1=0,1.5=1,2=0"])
    worst = max(r1["health"]["max_click_db"], r2["health"]["max_click_db"])
    return worst - ref, worst - ref < 3.0, "max_click_db at maximum-rate automation (5 drawbars full swings every 0.25 s; split key end to end every 0.5 s; block 64) minus the static render (%.1f dB): drawbars %.1f, split %.1f dB" % (ref, r1["health"]["max_click_db"], r2["health"]["max_click_db"])


def loudness():
    p = subprocess.run([sys.executable, str(ROOT / "scripts/dsp-kit/presetlint.py"), "render", str(ROOT / "presets.csv"), "--tier", "P",
                        "--harness", O.HARNESS, "--json"], capture_output=True, text=True)
    try:
        r = json.loads(p.stdout)
        spread = r.get("spread_lu"); med = r.get("median_lufs")
        return med, bool(r.get("pass")), "presetlint.py render presets.csv --tier P (reference chord, integrated over the hold): median %.1f LUFS, spread %.2f LU" % (med, spread)
    except Exception:
        return None, False, "presetlint.py render: " + (p.stdout + p.stderr).strip().splitlines()[-1] if (p.stdout + p.stderr).strip() else "no output"


ROWS = [("alias_floor_db", "< -80 dB re fundamental", alias_floor), ("thd_n_db", "< -60 dB at Drive 0", thd_n),
        ("response_error_db", "+/-0.5 dB", response_error), ("keyboard_span_lu", "< 6 LU per manual", keyboard_span),
        ("low_register", "side/mid < 150 Hz < -30 dB", low_register), ("doppler_cents", "< 1 cent vs moving source", doppler),
        ("rotor_rate_error_pct", "within 2 %", rotor_rates), ("zipper_db", "no zipper: < 3 dB over static", zipper),
        ("loudness_lufs", "presets -18 LUFS +/-1 LU", loudness)]


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--md"); ap.add_argument("--json"); ap.add_argument("--only")
    a = ap.parse_args()
    out = []
    for name, target, fn in ROWS:
        if a.only and name not in a.only.split(","): continue
        v, ok, method = fn()
        out.append(dict(metric=name, target=target, value=v, passed=ok, method=method)); print(json.dumps(out[-1]), flush=True)
    if a.json: json.dump(out, open(a.json, "w"), indent=1)
    if a.md:
        with open(a.md, "w") as f:
            f.write("# Metric table (G3) - Sunday Organ\n\nEvery quality target of `docs/brief.md`, measured on the plugin's harness: "
                    "`python3 tools/measure/metrics.py --md docs/metrics.md` (48 kHz, seed 1).\n\n| Metric | Target | Value | Pass | Method |\n|---|---|---|---|---|\n")
            for r in out:
                v = "-" if r["value"] is None else "%.2f" % r["value"]
                f.write("| %s | %s | %s | %s | %s |\n" % (r["metric"], r["target"], v, "yes" if r["passed"] else "**no**", r["method"]))
    return 0 if all(r["passed"] for r in out) else 1


if __name__ == "__main__":
    sys.exit(main())
