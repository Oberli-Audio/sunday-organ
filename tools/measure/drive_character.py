#!/usr/bin/env python3
"""What Drive does at the top of its range (listening debt 2026-11-01: "Drive 100 % sounds like digital
clipping"). Three numbers per signal, so the cause is named before the stage is touched:

  - distortion over Drive: the preamp probe against the same render at Drive 0 (best gain fit),
    residual re signal, full expression
  - aliasing: the preamp probe at 48 kHz against the same render at 192 kHz, where the stage's
    aliases fold far above 20 kHz: power the 192 k spectrum lacks (> 6 dB above it), 20 Hz-20 kHz
  - the safety limiter: the full chain's highest sample at Drive 100 %, Leslie fast (it acts from
    -1.7 dBTP)

    HARNESS=build/SundayOrganHarness_artefacts/Release/SundayOrganHarness python3 tools/measure/drive_character.py
"""
import sys
from pathlib import Path

import numpy as np
from scipy import signal as s

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "tests"))
import organ as O  # noqa: E402

UPPER10 = "48,52,55,60,64,67,72,76,79,84"
CASES = {
    "1 key": (dict(O.DRY, **O.bars("888000000")), dict(notes="60")),
    "4 keys (ref)": (dict(O.DRY, **O.bars("888000000")), dict(notes="48,52,55,60")),
    "10 keys": (dict(O.DRY, **O.bars("888000000")), dict(notes=UPPER10)),
    "full organ": (dict(O.DRY, **O.bars("888888888"), **O.bars("888888888", "lower"), pedalBar16=8, pedalBar8=8),
                   dict(notes=UPPER10, lower="48,52,55,59", pedals="24,31")),
}
DRIVES = (20, 30, 50, 75, 100)


def cut(x, fs):
    y = x[int(0.4 * fs):int(1.4 * fs), 0]
    return y - y.mean()


def distortion_db(params, flags, d, ref):
    y, fs, _ = O.render(dict(params, drive=d), seconds=1.5, solo="preamp", expr="0:1", **flags)
    y = cut(y, fs)
    e = y - np.dot(y, ref) / np.dot(ref, ref) * ref
    return 10 * np.log10(np.sum(e ** 2) / np.sum(y ** 2))


def alias_db(params, flags, d):
    P = []
    for rate in (48000, 192000):
        x, fs, _ = O.render(dict(params, drive=d), seconds=1.5, rate=rate, solo="preamp", expr="0:1", **flags)
        y = cut(x, fs)
        P.append((np.fft.rfftfreq(len(y), 1 / fs), np.abs(np.fft.rfft(y * s.windows.blackmanharris(len(y)))) ** 2))
    (f, a), (g, b) = P
    band = (f > 20) & (f < 20000)
    a = a[band] / a[band].sum()
    b = np.interp(f, g, b)[band]                                    # 1 s at either rate: the same 1 Hz grid
    b = b / b.sum()
    return 10 * np.log10(np.clip(a - 4 * b, 0, None).sum() + 1e-30)


def main():
    print("distortion re signal at Drive " + "/".join(map(str, DRIVES)) + " %, aliasing at 100 %, highest output sample at 100 %")
    for name, (params, flags) in CASES.items():
        r, fs, _ = O.render(dict(params, drive=0), seconds=1.5, solo="preamp", expr="0:1", **flags)
        ref = cut(r, fs)
        dist = " ".join(f"{distortion_db(params, flags, d, ref):6.1f}" for d in DRIVES)
        out, fs, _ = O.render(dict(params, drive=100, leslieOn=1, leslieFast=1), seconds=2.0, expr="0:1", **flags)
        print(f"  {name:13s} {dist} dB | alias {alias_db(params, flags, 100):6.1f} dB | out {20 * np.log10(np.abs(out).max()):6.1f} dBFS")


if __name__ == "__main__":
    main()
