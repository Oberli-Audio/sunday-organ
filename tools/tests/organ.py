"""Sunday Organ helpers for the tests and tools/measure: plain parameter values (the table's
units) to the harness's normalised --param, registrations as drawbar strings, renders that
return the audio. Every render asserts the harness's echo (rule 13)."""
import csv
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, os.environ.get("DSPKIT", str(ROOT / "scripts" / "dsp-kit")))
import dspkit as K  # noqa: E402

HARNESS = os.environ.get("HARNESS", str(ROOT / "build/SundayOrganHarness_artefacts/Release/SundayOrganHarness"))
TABLE = {r["id"]: r for r in csv.DictReader(open(ROOT / "parameters.csv", encoding="utf-8"))}
UPPER = ["upperBar%d" % i for i in range(1, 10)]
LOWER = ["lowerBar%d" % i for i in range(1, 10)]


def norm(pid, plain):
    """The table's plain value -> JUCE's normalised one, skew included (a `centre` sits at 0.5)."""
    import math
    r = TABLE[pid]
    lo, hi = float(r["min"]), float(r["max"])
    p = (float(plain) - lo) / (hi - lo)
    if r.get("centre"):
        skew = math.log(0.5) / math.log((float(r["centre"]) - lo) / (hi - lo))
        p = p ** skew if p > 0 else 0.0
    return p


def bars(reg, manual="upper"):
    """'888000000' -> {upperBar1: 8, ...} in plain units."""
    ids = UPPER if manual == "upper" else LOWER
    return {i: int(c) for i, c in zip(ids, reg)}


def render(plain=None, seconds=2.0, rate=48000, block=512, seed=1, check_params=True, **flags):
    """plain: {id: value in the table's units}. flags: harness flags (notes, lower, pedals, gate,
    solo, events, automate, expr, sustain, mod ...). Returns (x [n, 2], fs, json)."""
    params = {pid: norm(pid, v) for pid, v in (plain or {}).items()}
    with tempfile.TemporaryDirectory() as d:
        out = os.path.join(d, "o.wav")
        res = K.render(HARNESS, params, seed=seed, sample_rate=rate, block=block, seconds=seconds, out=out, **flags)
        K.assert_echo(res, params if check_params else None, seed=seed, sample_rate=rate, block=block)   # automated ones end elsewhere
        x, fs = K.read_wav(out)
    return K.as_2d(x), fs, res


DRY = {"leslieOn": 0, "leakage": 0, "keyClick": 0, "drive": 0}   # the organ alone: no Leslie, no leakage, no click, clean
