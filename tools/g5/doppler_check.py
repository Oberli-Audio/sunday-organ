#!/usr/bin/env python3
"""G5 / brief: the Leslie horn's Doppler against the moving-source model (port of
`sound design/tests/doppler_check.py`). Renders the plugin's own horn path with
SundayOrganDopplerCheck (a 2 kHz tone, 6.67 Hz, mic at 0), measures the instantaneous frequency by
Hilbert phase, and compares it with the exact moving-source prediction (retarded time) and the
moving-listener one (what a plain modulated read gives). Pass: on the delay path p99 |error| vs moving
source < 1 cent (brief) and smaller than vs moving listener; the full path is reported. Optional: --faust <wav> nulls the plugin's
render against the prototype's doppler_test.dsp render.
Usage: python3 tools/g5/doppler_check.py <SundayOrganDopplerCheck> [--faust f.wav] [--rate 48000]"""
import argparse, os, subprocess, sys, tempfile
import numpy as np
import scipy.signal as s
sys.path.insert(0, os.environ.get("DSPKIT", os.path.join(os.path.dirname(__file__), "..", "..", "scripts", "dsp-kit")))
import dspkit as k

R, C, HZ, F0, BASE = 0.15, 343.0, 6.67, 2000.0, 0.0005


def analyse(x, fs):
    w = 2 * np.pi * HZ
    t = np.arange(len(x)) / fs
    sl = slice(int(0.5 * fs), int(2.5 * fs))
    te = np.arange(0, 3, 1 / (fs * 4))
    tr = te + BASE + (R / C) * (1 - np.cos(w * te))
    f_src_t = np.interp(t, tr, F0 / (1 + (R / C) * w * np.sin(w * te)))
    f_lis = F0 * (1 - (R / C) * w * np.sin(w * t))
    out = {}
    for name, y in (("delay_only", x[:, 0]), ("full_path", x[:, 1])):
        fm = (np.gradient(np.unwrap(np.angle(s.hilbert(y)))) * fs / (2 * np.pi))[sl]
        out[name] = dict(peak_cents=float(1200 * np.log2(fm.max() / F0)),
                         p99_err_source_cents=float(np.percentile(abs(1200 * np.log2(fm / f_src_t[sl])), 99)),
                         p99_err_listener_cents=float(np.percentile(abs(1200 * np.log2(fm / f_lis[sl])), 99)))
    out["design_peak_cents"] = float(1200 * np.log2(1 / (1 - R * w / C)))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("tool"); ap.add_argument("--faust"); ap.add_argument("--rate", type=int, default=48000)
    a = ap.parse_args()
    with tempfile.TemporaryDirectory() as d:
        wav = os.path.join(d, "doppler.wav")
        subprocess.run([a.tool, wav, "3", str(a.rate)], check=True)
        x, fs = k.read_wav(wav); x = k.as_2d(x)
    res = analyse(x, fs)
    # judged: the Doppler itself (the delay path). The full path adds the moving lowpass's phase
    # swing (3.5 c p99 in prototype and plugin alike): reported, carried as EX-3 in docs/status.md
    dp = res["delay_only"]
    ok = dp["p99_err_source_cents"] < 1.0 and dp["p99_err_source_cents"] < dp["p99_err_listener_cents"]
    if a.faust:
        y, _ = k.read_wav(a.faust); y = k.as_2d(y); n = min(len(x), len(y)); r = x[:n] - y[:n]
        res["null_vs_faust_peak_dbfs"] = float(20 * np.log10(max(np.abs(r).max(), 1e-30)))
    res["pass"] = bool(ok)
    import json; print(json.dumps(res, indent=1))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
