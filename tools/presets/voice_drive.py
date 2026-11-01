#!/usr/bin/env python3
"""The bank's Drive values, voiced by measurement (2026-11-01, Björn: "revoice yourself"). The values
in make_bank.py were chosen for the old drive stage (F-12), where 50 % was already heavy. Each preset's
own words name a character; each character is a distortion level on the preset's own registration:
the preamp probe on the brief's reference chord (C3-E3-G3-C4) at full expression against the same
Drive at expression 0.05, where the stage is linear (residual re signal, as drive_character.py).
Bisection finds the Drive (whole percent) that reaches the level; copy the result into make_bank.py
and run it (the Output calibration follows the Drive).

    HARNESS=build/SundayOrganHarness_artefacts/Release/SundayOrganHarness python3 tools/presets/voice_drive.py
"""
import os
import sys

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tests"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import organ as O  # noqa: E402
from make_bank import BANK, plain_of  # noqa: E402

CHORD = "48,52,55,60"
# character: distortion re signal on the reference chord, dB (-60: inaudible, -40: a thickening,
# -30: grit on chords, -20: clear overdrive, -12: heavy)
CHARACTER = {"light": -50.0, "worn": -45.0, "warm": -40.0, "grit": -30.0, "driven": -20.0, "heavy": -12.0}
VOICE = {
    "jazz-trio": "light",          # "light drive"
    "smoky-club": "worn",          # "worn"
    "sunday-morning": "warm",      # "warm drive"
    "gospel-full": "grit",         # every drawbar, Leslie fast: a gospel full organ breaks up
    "shout-chorus": "grit",        # the gospel shout
    "power-chords": "driven",      # "driven"
    "rock-drive": "heavy",         # "heavy drive (most drive)"
}


def distortion_db(plain, drive):
    p = dict(plain, drive=drive)
    y, fs, _ = O.render(p, seconds=1.5, solo="preamp", expr="0:1", notes=CHORD)
    r, fs, _ = O.render(p, seconds=1.5, solo="preamp", expr="0:0.05", notes=CHORD)
    y, r = y[int(0.4 * fs):int(1.4 * fs), 0], r[int(0.4 * fs):int(1.4 * fs), 0]
    y, r = y - y.mean(), r - r.mean()
    e = y - np.dot(y, r) / np.dot(r, r) * r
    return float(10 * np.log10(np.sum(e ** 2) / np.sum(y ** 2)))


def main():
    print(f"{'preset':16s} {'character':9s} {'target':>7s} {'old':>4s} {'old dB':>7s} {'new':>4s} {'new dB':>7s}")
    for entry in BANK:
        slug, settings = entry[0], entry[6]
        plain = plain_of(entry, None)
        old = settings.get("drive", 20)
        if slug not in VOICE:
            print(f"{slug:16s} {'clean':9s} {'< -60':>7s} {old:4d} {distortion_db(plain, old):7.1f}    -       -")
            continue
        target = CHARACTER[VOICE[slug]]
        lo, hi = 0, 100                                        # distortion rises with Drive
        while hi - lo > 1:
            mid = (lo + hi) // 2
            lo, hi = (mid, hi) if distortion_db(plain, mid) < target else (lo, mid)
        new = lo if abs(distortion_db(plain, lo) - target) <= abs(distortion_db(plain, hi) - target) else hi
        print(f"{slug:16s} {VOICE[slug]:9s} {target:7.0f} {old:4d} {distortion_db(plain, old):7.1f} {new:4d} {distortion_db(plain, new):7.1f}")


if __name__ == "__main__":
    main()
