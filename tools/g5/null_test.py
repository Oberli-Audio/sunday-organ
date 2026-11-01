#!/usr/bin/env python3
"""G5 null test: the plugin against the Faust prototype, whole and module by module (F.8).

Every score in `sound design/scores/` is rendered by the prototype (`harness/render`, TW_BLOCK=1:
each event on its sample) and by the plugin's harness (`--events`, `--proto-init`: the prototype's
start state), at 48 kHz, and the residual is taken over the whole render, absolute dBFS, **no
alignment** (F.8 "Method"). Module probes tap the same points in both (`sound design/dsp/g5_*.dsp`
and the harness's --solo): upper and lower manual (Tonewheels, Contacts, Busses, Percussion),
pedals and voices (+ Scanner), preamp out and the Leslie crossover (Preamp, Leslie filters); the
whole plugin adds the rotors. Threshold: F.8 row 1, same structure and arithmetic order in double,
peak < -120 dBFS at the output (float32, so its own rounding is about -150); a probe runs at its
module's level (the upper bus near +28 dBFS) and is judged re its own peak, < -120 dB. A length
difference of one sample is the prototype harness truncating seconds x rate (8.2 x 48000).
Usage: python3 tools/g5/null_test.py <harness> [--md docs/g5-null-test.md] [--json out.json]"""
import argparse, glob, json, os, subprocess, sys, tempfile
import numpy as np
sys.path.insert(0, os.environ.get("DSPKIT", os.path.join(os.path.dirname(__file__), "..", "..", "scripts", "dsp-kit")))
import dspkit as k

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SD = os.path.join(ROOT, "sound design")
THRESHOLD = -120.0
PROBES = {"busses": ("upper", "lower"), "voices": ("pedals", "voices"), "preamp": ("preamp", "crossover")}
PROBE_SCORES = ["01_init_chord_slow", "03_percussion_riff", "05_full_drawbars_driven_fast", "06_scanner_off_V1_V2_V3_C1_C2_C3_dry",
                "07_split_lower_comp_upper_lead", "08_pedals_with_chords", "11_expression_swell", "12_three_channels_and_split"]


def db(v):
    return float(20 * np.log10(max(v, 1e-30)))


def faust(exe, score, dur, out):
    subprocess.run([exe, score, out, str(dur), "48000"], check=True, env=dict(os.environ, TW_BLOCK="1"), cwd=os.path.dirname(score))
    x, _ = k.read_wav(out)
    return k.as_2d(x)


def plugin(harness, score, dur, out, solo=None):
    cmd = [harness, "--events=" + score, "--proto-init", "--seconds=%s" % dur, "--block=512", "--out=" + out]
    if solo: cmd.append("--solo=" + solo)
    res = json.loads(subprocess.run(cmd, check=True, capture_output=True, text=True).stdout)
    if solo: assert res["applied"]["solo"] == solo, "harness did not echo --solo"   # rule 13
    x, _ = k.read_wav(out)
    return k.as_2d(x)


def residual(a, b):
    n = min(len(a), len(b))
    r = a[:n] - b[:n]
    return dict(ref_peak_dbfs=db(np.abs(b[:n]).max()), peak_dbfs=db(np.abs(r).max()), rms_dbfs=db(np.sqrt(np.mean(r ** 2))),
                worst_at_s=float(np.argmax(np.abs(r).max(1)) / 48000.0), length_diff=len(a) - len(b))


def judge(r):
    """Whole plugin: absolute dBFS. Probe: re its own peak. Silent on both sides (a score without
    pedals) is identical. One sample of length is the prototype harness truncating seconds x rate."""
    if abs(r["length_diff"]) > 1: return False
    if r["ref_peak_dbfs"] < -300.0: return r["peak_dbfs"] < -300.0
    return (r["peak_dbfs"] if r["part"] == "whole" else r["peak_dbfs"] - r["ref_peak_dbfs"]) < THRESHOLD


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("harness"); ap.add_argument("--md"); ap.add_argument("--json")
    ap.add_argument("--rows", help="re-judge a saved --json instead of rendering")
    a = ap.parse_args()
    rows, ok = [], True
    if a.rows:
        rows = json.load(open(a.rows))
        for r in rows:
            r["passed"] = judge(r); ok &= r["passed"]
    else:
      with tempfile.TemporaryDirectory() as d:
          for sc in sorted(glob.glob(os.path.join(SD, "scores", "*.txt"))):
              name = os.path.basename(sc)[:-4]
              dur = open(sc).readline().split()[2]
              r = residual(plugin(a.harness, sc, dur, os.path.join(d, "p.wav")), faust(os.path.join(SD, "harness", "render"), sc, dur, os.path.join(d, "f.wav")))
              r.update(score=name, part="whole"); r["passed"] = judge(r)
              ok &= r["passed"]; rows.append(r); print(json.dumps(r), flush=True)
          for probe, parts in PROBES.items():
              exe = os.path.join(SD, "harness", "g5", probe)
              if not os.path.exists(exe):
                  print("missing probe build", exe, "(sound design/dsp/g5_%s.dsp)" % probe, file=sys.stderr); ok = False; continue
              for name in PROBE_SCORES:
                  sc = os.path.join(SD, "scores", name + ".txt"); dur = open(sc).readline().split()[2]
                  f = faust(exe, sc, dur, os.path.join(d, "f.wav"))
                  for ch, part in enumerate(parts):
                      p = plugin(a.harness, sc, dur, os.path.join(d, "p.wav"), part)
                      r = residual(p[:, :1], f[:, ch:ch + 1])
                      r.update(score=name, part=part); r["passed"] = judge(r)   # a probe at its module's level: re its peak
                      ok &= r["passed"]; rows.append(r); print(json.dumps(r), flush=True)
    if a.json:
        json.dump(rows, open(a.json, "w"), indent=1)
    if a.md:
        with open(a.md, "w") as f:
            f.write("# G5 null test - plugin vs prototype v0.7\n\n`python3 tools/g5/null_test.py build/SundayOrganHarness_artefacts/Release/SundayOrganHarness --md docs/g5-null-test.md` "
                    "(48 kHz, no alignment, whole render; threshold F.8 row 1: peak < %d dBFS). Doppler: `python3 tools/g5/doppler_check.py build/SundayOrganDopplerCheck`.\n\n" % THRESHOLD)
            f.write("| Score | Part | Ref peak dBFS | Residual peak dBFS | Residual re ref peak dB | Residual RMS dBFS | Pass |\n|---|---|---|---|---|---|---|\n")
            for r in rows:
                f.write("| %s | %s | %.1f | %.1f | %.1f | %.1f | %s |\n" % (r["score"], r["part"], r["ref_peak_dbfs"], r["peak_dbfs"], r["peak_dbfs"] - r["ref_peak_dbfs"], r["rms_dbfs"], "yes" if r["passed"] else "**no**"))
    print("G5 null test:", "PASS" if ok else "FAIL", "(%d rows)" % len(rows))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
