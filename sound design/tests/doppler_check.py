"""Doppler check: measured instantaneous frequency of a 2 kHz tone through the horn delay,
against the exact moving-source prediction and against the moving-listener (plain read)
prediction. Passes when the moving-source error is the smaller one and under 0.3 cents."""
import sys, numpy as np, scipy.signal as s
sys.path.insert(0, sys.argv[2]); import dspkit as k
x, fs = k.read_wav(sys.argv[1]); x = k.as_2d(x)
R, C, HZ, F0, BASE = 0.15, 343.0, 6.67, 2000.0, 0.0005
w = 2 * np.pi * HZ
def inst_f(y):
    ph = np.unwrap(np.angle(s.hilbert(y)))
    return np.gradient(ph) * fs / (2 * np.pi)
t = np.arange(len(x)) / fs
sl = slice(int(0.5 * fs), int(2.5 * fs))
te = np.arange(0, 3, 1 / (fs * 4))                       # emission times
tr = te + BASE + (R / C) * (1 - np.cos(w * te))          # reception times
f_src = F0 / (1 + (R / C) * w * np.sin(w * te))          # moving source, exact
f_src_t = np.interp(t, tr, f_src)
f_lis = F0 * (1 - (R / C) * w * np.sin(w * t))           # what a plain read gives
for name, y in (("delay only", x[:, 0]), ("full horn path", x[:, 1])):
    fm = inst_f(y)[sl]
    e_src = 1200 * np.log2(fm / f_src_t[sl]); e_lis = 1200 * np.log2(fm / f_lis[sl])
    dev = 1200 * np.log2(fm.max() / F0)
    print(f"{name:15s} peak deviation {dev:5.1f} cents (design {1200*np.log2(1/(1-R*w/C)):.1f}); "
          f"p99 |error| vs moving source {np.percentile(abs(e_src),99):.3f} c, vs moving listener {np.percentile(abs(e_lis),99):.3f} c")
