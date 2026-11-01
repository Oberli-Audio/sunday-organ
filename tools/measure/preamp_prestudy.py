#!/usr/bin/env python3
"""Pre-study for the preamp's gain staging (listening debt 2026-11-01, brief amendment 2026-11-01).

Renders the organ sum before the preamp (--solo=voices, Leslie, leakage and click off) for one key,
Init's 4- and 10-key chords and the full organ, then models the stage in numpy: the static tanh with
its bias, no ADAA (it changes the result by tenths of a dB). Prints the input scale s that keeps the
full organ below -60 dB at Drive 0, the distortion over Drive for the proposed curve
g(d) = s (12 / s)^d (Drive 100 % keeps today's gain 12), today's stage beside it, and a cubic
loudness compensation fitted to the reference chord with the level it leaves for the other signals.

    HARNESS=build/SundayOrganHarness_artefacts/Release/SundayOrganHarness python3 tools/measure/preamp_prestudy.py
"""
import sys
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "tests"))
import organ as O  # noqa: E402

UPPER10 = "48,52,55,60,64,67,72,76,79,84"
CASES = {
    "1 key": (dict(O.DRY, **O.bars("888000000")), dict(notes="60")),
    "Init 4 keys (reference)": (dict(O.DRY, **O.bars("888000000")), dict(notes="48,52,55,60")),
    "Init 10 keys": (dict(O.DRY, **O.bars("888000000")), dict(notes=UPPER10)),
    "full organ": (dict(O.DRY, **O.bars("888888888"), **O.bars("888888888", "lower"), pedalBar16=8, pedalBar8=8),
                   dict(notes=UPPER10, lower="48,52,55,59", pedals="24,31")),
}
REF = "Init 4 keys (reference)"


def stage(x, d, s):
    g = s * (12.0 / s) ** d
    b = 0.15 * d
    y = np.tanh(g * x + b) - np.tanh(b)
    return y - y.mean()


def today(x, d):
    y = np.tanh((1 + 11 * d) * x + 0.15 * d) - np.tanh(0.15 * d)
    return y - y.mean()


def dist_db(y, x):
    x = x - x.mean()
    g = np.dot(y, x) / np.dot(x, x)
    e = y - g * x
    return 10 * np.log10(np.sum(e ** 2) / np.sum((g * x) ** 2) + 1e-30)


def rms_db(y):
    return 20 * np.log10(np.sqrt(np.mean(y ** 2)))


def main():
    V = {}
    for name, (params, flags) in CASES.items():
        x, fs, _ = O.render(params, seconds=1.5, solo="voices", **flags)
        V[name] = 0.06 * x[int(0.4 * fs):int(1.4 * fs), 0]          # the stage's input at full expression
        print(f"{name:24s} input at Drive 0 today: peak {np.max(np.abs(V[name])):.3f}")
    lo, hi = 1e-3, 1.0
    for _ in range(40):
        s = (lo * hi) ** 0.5
        lo, hi = (s, hi) if dist_db(stage(V["full organ"], 0, s), V["full organ"]) < -60 else (lo, s)
    s = round(lo, 3)
    print(f"\ns = {s} ({20 * np.log10(s):.1f} dB): the full organ at Drive 0 below -60 dB")
    print("Drive | distortion dB: " + ", ".join(V) + " | today, Init 10 keys")
    for d in (0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.7, 1.0):
        row = " ".join(f"{dist_db(stage(x, d, s), x):6.1f}" for x in V.values())
        print(f" {int(d * 100):3d} % | {row} | {dist_db(today(V['Init 10 keys'], d), V['Init 10 keys']):6.1f}")
    ds = np.linspace(0, 1, 41)
    need = np.array([rms_db(stage(V[REF], d, s)) for d in ds])
    need -= need[0]
    c = np.polyfit(ds, need, 3)
    print("\ncompensation (dB) = %.3f d^3 %+.3f d^2 %+.3f d %+.3f, fitted to the reference" % tuple(c))
    for name, x in V.items():
        lvl = np.array([rms_db(stage(x, d, s)) - np.polyval(c, d) for d in ds])
        lvl -= lvl[0]
        print(f"  {name:24s} level vs Drive 0: 20 % {lvl[8]:+5.1f}  50 % {lvl[20]:+5.1f}  100 % {lvl[40]:+5.1f} dB  (span {lvl.max() - lvl.min():.1f})")


if __name__ == "__main__":
    main()
