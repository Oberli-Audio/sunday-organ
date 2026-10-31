"""Render every score with the compiled prototype: python3 scores/render_all.py (from 'sound design').
Listening scores -> renders/, p_* -> renders/presets/, x_* -> renders/evidence/, plus the
192 kHz alias render and a 96 kHz init render."""
import glob, os, subprocess, sys
here = os.path.dirname(os.path.abspath(__file__)); root = os.path.dirname(here)
R = os.path.join(root, "renders"); exe = os.path.join(root, "harness", "render")
for d in ("", "presets", "evidence"): os.makedirs(os.path.join(R, d), exist_ok=True)
jobs = []
for sc in sorted(glob.glob(os.path.join(here, "*.txt"))):
    name = os.path.basename(sc)[:-4]; dur = open(sc).readline().split()[2]
    sub = "presets" if name.startswith("p_") else "evidence" if name.startswith("x_") else ""
    jobs.append((sc, os.path.join(R, sub, name + ".wav"), dur, "48000"))
jobs.append((os.path.join(here, "x_alias_C7_8ft_drive1.txt"), os.path.join(R, "evidence", "x_alias_192k.wav"), "3", "192000"))
jobs.append((os.path.join(here, "01_init_chord_slow.txt"), os.path.join(R, "evidence", "x_init_96k.wav"), "6", "96000"))
env = dict(os.environ)
procs = []
for sc, out, dur, sr in jobs:
    e = dict(env)
    if "x_cpu" in sc: e.update(TW_TIMES="/tmp/times.txt", TW_BLOCK="64")
    procs.append(subprocess.Popen([exe, sc, out, dur, sr], cwd=here, env=e))
    if len(procs) >= os.cpu_count(): procs.pop(0).wait()
for p in procs: p.wait()
print(len(jobs), "renders")
