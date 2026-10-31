#!/usr/bin/env python3
"""Sunday Organ's own tests: one presence test per defining feature of docs/brief.md (rule 13), the
instrument contracts (register, pedal, channels, controllers; rules 14-16) and one regression test
per fixed defect (docs/failures.md). Each was shown failing on a build with the defect or without
the feature (D.3.8). Label `render` (CTest suite_features). Run: HARNESS=... python3 tools/tests/test_features.py"""
import os
import subprocess
import sys
import tempfile
import time
import unittest

import numpy as np
import scipy.signal as s

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import organ as O  # noqa: E402

K = O.K
PROBE = os.environ.get("LESLIE_PROBE", str(O.ROOT / "build" / "SundayOrganDopplerCheck"))


def rms_db(x):
    return float(K.db(np.sqrt(np.mean(np.asarray(x, float) ** 2))))


class Timed(unittest.TestCase):
    def setUp(self):
        self._t0 = time.time()

    def tearDown(self):
        print("  [%.1f s]" % (time.time() - self._t0), end="", flush=True)


class Regressions(Timed):
    def test_crossover_sums_flat(self):                                     # F-3, brief response_error_db
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "ir.wav")
            subprocess.run([PROBE, p, "1", "48000", "impulse"], check=True)
            x, fs = K.read_wav(p)
        H = np.fft.rfft(K.as_2d(x)[:, 0]); f = np.fft.rfftfreq(len(x), 1 / fs)
        err = np.max(np.abs(K.db(np.abs(H[(f > 20) & (f < 20000)]))))
        self.assertLess(err, 0.5, "Leslie crossover sum deviates %.2f dB (the 200 Hz split's allpass must be matched on the horn band)" % err)

    def test_low_register_is_rate_invariant(self):                         # F-2: DC blocker in samples
        levels = {}
        for fs in (44100, 48000, 96000, 192000):
            x, fs, _ = O.render(dict(O.DRY, pedalBar16=8, pedalBar8=0), pedals="24", seconds=1.5, rate=fs)
            levels[fs] = rms_db(x[int(0.5 * fs):, 0])
        self.assertLess(max(levels.values()) - min(levels.values()), 0.2, "pedal C1 level depends on the rate: %r" % levels)

    def test_state_round_trip_bytewise_with_skewed_params(self):           # F-4 (D.5.3, rule 19)
        with tempfile.TemporaryDirectory() as d:
            a, b, c = (os.path.join(d, n) for n in ("a.state", "b.state", "c.state"))
            O.render({"drive": 30, "micSpread": 150, "pedalRelease": 0.3}, seconds=0.1, state_out=a)
            O.render(None, seconds=0.1, state_in=a, state_out=b)
            O.render(None, seconds=0.1, state_in=b, state_out=c)
            self.assertEqual(open(a, "rb").read(), open(b, "rb").read(), "state changed on the first load and save")
            self.assertEqual(open(b, "rb").read(), open(c, "rb").read(), "state drifts on every load and save")

    def test_idle_costs_little(self):                                      # brief cpu_budget idle_pct 2 (reported at 48 k/64)
        _, _, r = O.render(None, seconds=10.0, block=64, profile=1, warmup=200)
        # judged at the median here (this box is not the budget machine; perf.py reports the rest)
        self.assertLess(r["profile"]["p50_pct"], 2.0, "idle p50 %.1f %% of the deadline" % r["profile"]["p50_pct"])


def steady(plain, seconds=1.2, **flags):
    x, fs, res = O.render(plain, seconds=seconds, **flags)
    return x[int(0.4 * fs):], fs, res


def inst_cents(y, fs, f0):
    sos = s.butter(4, (f0 / 1.3, f0 * 1.3), "bp", fs=fs, output="sos")
    ph = np.unwrap(np.angle(s.hilbert(s.sosfilt(sos, y))))
    f = np.gradient(ph) * fs / (2 * np.pi)
    f = f[int(0.1 * fs):-int(0.1 * fs)]
    return 1200 * np.log2(f / np.median(f))


class DefiningFeatures(Timed):
    def test_shared_wheels_sum_phase_coherently(self):                     # +6 dB, not +3
        reg = dict(O.DRY, **O.bars("008000000"), **O.bars("008000000", "lower"))
        one, _, _ = steady(reg, notes="60")
        two, _, _ = steady(reg, notes="60", lower="60")
        gain = rms_db(two[:, 0]) - rms_db(one[:, 0])
        self.assertAlmostEqual(gain, 6.02, delta=0.3, msg="C4 on both manuals = one wheel twice: %.2f dB" % gain)

    def test_drawbar_steps_about_3_db_and_0_silent(self):
        lv = []
        for step in range(8, 0, -1):
            x, _, _ = steady(dict(O.DRY, **O.bars("00%d000000" % step)), notes="60")
            lv.append(rms_db(x[:, 0]))
        d = np.diff(lv)
        self.assertTrue(np.all(np.abs(d + 3.0) < 0.1), "drawbar steps: %s dB" % np.round(d, 2))
        x, _, _ = steady(dict(O.DRY, **O.bars("000000000")), notes="60")
        self.assertLess(K.peak_dbfs(x), -140.0)

    def test_key_click_scales_with_key_click(self):
        hf = []
        for click in (0, 50, 100):
            x, fs, _ = O.render(dict(O.DRY, keyClick=click, **O.bars("888000000")), seconds=0.3, notes="48,55,60")
            sos = s.butter(6, 4000, "hp", fs=fs, output="sos")
            hf.append(rms_db(s.sosfilt(sos, x[:, 0])[: int(0.015 * fs)]))
        msg = "click energy > 4 kHz in the first 15 ms at Key Click 0/50/100 %%: %s dB" % np.round(hf, 1)
        self.assertTrue(hf[0] < hf[1] < hf[2], msg)
        self.assertGreater(hf[2] - hf[0], 12.0, msg)

    def _perc(self, extra, notes="60", seconds=1.6, **flags):
        return O.render(dict(O.DRY, percOn=1, **O.bars("008000000"), **extra), notes=notes, seconds=seconds, **flags)

    def test_percussion_harmonic_decay_single_trigger_and_cut(self):
        f0 = 261.54
        def partial(x, fs, f, t0, t1):
            y = x[int(t0 * fs):int(t1 * fs), 0]
            F = np.abs(np.fft.rfft(y * np.hanning(len(y)))); fr = np.fft.rfftfreq(len(y), 1 / fs)
            return float(K.db(F[np.abs(fr - f) < 6].max()))
        x, fs, _ = self._perc({})
        x3, _, _ = self._perc({"percThird": 1})
        self.assertGreater(partial(x, fs, 2 * f0, 0.02, 0.2) - partial(x, fs, 2 * f0, 1.2, 1.5), 20, "2nd harmonic decays")
        self.assertGreater(partial(x3, fs, 3 * f0, 0.02, 0.2) - partial(x, fs, 3 * f0, 0.02, 0.2), 30, "Third puts it on the 3rd")
        xs, _, _ = self._perc({"percSlow": 1})
        fast_drop = partial(x, fs, 2 * f0, 0.02, 0.2) - partial(x, fs, 2 * f0, 0.4, 0.58)
        slow_drop = partial(xs, fs, 2 * f0, 0.02, 0.2) - partial(xs, fs, 2 * f0, 0.4, 0.58)
        self.assertGreater(fast_drop, 2.2 * slow_drop, "Slow decays about 3x slower: %.1f vs %.1f dB" % (fast_drop, slow_drop))
        # single trigger: a legato second key (E4 while C4 is held) gets no percussion of its own
        ev = os.path.join(tempfile.mkdtemp(), "legato.txt")
        open(ev, "w").write("0|key 60|1\n0.8|key 64|1\n")
        xl, _, _ = O.render(dict(O.DRY, percOn=1, **O.bars("008000000")), events=ev, seconds=1.4)
        f2e = 2 * 329.6
        self.assertLess(partial(xl, fs, f2e, 0.82, 1.0), partial(x, fs, 2 * f0, 0.02, 0.2) - 30, "legato key retriggered percussion")
        # cuts 1' while on
        x1, _, _ = O.render(dict(O.DRY, **O.bars("008000008")), notes="60", seconds=1.0)
        x1p, _, _ = O.render(dict(O.DRY, percOn=1, **O.bars("008000008")), notes="60", seconds=1.0)
        self.assertGreater(partial(x1, fs, 8 * f0, 0.5, 0.9) - partial(x1p, fs, 8 * f0, 0.5, 0.9), 40, "1' cut by percussion")

    def test_scanner_v1_v3_increasing_c_modes_with_dry(self):
        swing, rate = [], []
        for mode in (1, 2, 3):
            x, fs, _ = O.render(dict(O.DRY, vibratoMode=mode, **O.bars("008000000")), notes="84", seconds=2.0, solo="voices")
            c = inst_cents(x[int(0.5 * fs):, 0], fs, 1046.2)
            swing.append(float(np.percentile(c, 99) - np.percentile(c, 1)))
            F = np.abs(np.fft.rfft((c - c.mean()) * np.hanning(len(c)), 8 * len(c))); fr = np.fft.rfftfreq(8 * len(c), 1 / fs)
            sel = (fr > 2) & (fr < 20); rate.append(float(fr[sel][F[sel].argmax()]))
        self.assertTrue(swing[0] < swing[1] < swing[2], "V1-V3 swings %s cents" % np.round(swing[:3], 1))
        # C modes mix the dry sound in: wet and dry beat (amplitude moves), a V mode is pure vibrato
        ripple = {}
        for mode in (3, 6):
            x, fs, _ = O.render(dict(O.DRY, vibratoMode=mode, **O.bars("008000000")), notes="84", seconds=2.0, solo="voices")
            sos = s.butter(4, (800, 1400), "bp", fs=fs, output="sos")
            env = np.abs(s.hilbert(s.sosfilt(sos, x[int(0.5 * fs):, 0])))[int(0.1 * fs):-int(0.1 * fs)]
            ripple[mode] = float(K.db(env.max() / env.min()))
        self.assertLess(ripple[3], 1.0, "V3 envelope ripple %.2f dB" % ripple[3])
        self.assertGreater(ripple[6], 3.0, "C3 envelope ripple %.2f dB (dry mixed in)" % ripple[6])
        for r in rate[:3]:
            self.assertAlmostEqual(r, 6.87, delta=0.14)

    def test_leslie_rotors_own_speeds_spin_up_down_brake(self):
        horn = lambda res: res["product"]["horn_rpm"] / 60.0
        drum = lambda res: res["product"]["drum_rpm"] / 60.0
        # from slow: the mod wheel goes up at 0; after one horn time constant (0.35 s) 63 % of the way
        _, _, r = O.render({}, notes="60", seconds=0.35, mod="0:1", block=32)
        self.assertAlmostEqual((horn(r) - 0.83) / (6.67 - 0.83), 0.632, delta=0.03)
        _, _, r = O.render({}, notes="60", seconds=2.2, mod="0:1", block=32)
        self.assertAlmostEqual((drum(r) - 0.67) / (5.67 - 0.67), 0.632, delta=0.03)
        # down from fast: their own (slower) times, 0.55 s and 3.0 s
        _, _, r = O.render({"leslieFast": 1}, notes="60", seconds=4.55, mod="0:1,4:0", block=32)   # settled fast, wheel down at 4 s
        self.assertAlmostEqual((6.67 - horn(r)) / (6.67 - 0.83), 0.632, delta=0.03)
        _, _, r = O.render({"leslieFast": 1}, notes="60", seconds=24.0, mod="0:1,21:0", block=512)
        self.assertAlmostEqual((5.67 - drum(r)) / (5.67 - 0.67), 0.632, delta=0.03)
        # brake stops both
        _, _, r = O.render({"leslieFast": 1}, notes="60", seconds=20.0, automate=["leslieBrake:0=0,1=0,1.001=1,20=1"], block=512)
        self.assertLess(horn(r), 0.02); self.assertLess(drum(r), 0.02)

    def test_mono_and_unmodulated_below_150_hz(self):                       # rule 15
        x, fs, _ = O.render({"leslieFast": 1}, pedals="24", lower="48,52,55", seconds=5.0)
        x = x[int(1.5 * fs):]
        sos = s.butter(8, 150, "lp", fs=fs, output="sos")
        m = s.sosfilt(sos, x.mean(1)); sd = s.sosfilt(sos, (x[:, 0] - x[:, 1]) / 2)
        self.assertLess(rms_db(sd) - rms_db(m), -30)
        ripple = []
        for on in (1, 0):   # pedal C1 16' alone in its band: its envelope with the Leslie fast vs off
            y, fs, _ = O.render({"leslieFast": 1, "leslieOn": on, "leakage": 0, "pedalBar8": 0}, pedals="24", lower="48,52,55", seconds=5.0)
            env = np.abs(s.hilbert(s.sosfilt(s.butter(4, (25, 40), "bp", fs=fs, output="sos"), y[int(1.5 * fs):, 0])))[int(0.3 * fs):-int(0.3 * fs)]
            ripple.append(float(K.db(env.max() / env.min())))
        self.assertLess(ripple[0] - ripple[1], 0.2, "pedal C1 envelope ripple, Leslie fast %.2f dB vs off %.2f dB" % tuple(ripple))


class InstrumentContracts(Timed):
    def test_register_and_channels(self):                                  # rule 14, brief must_do
        only_lower = dict(O.DRY, **O.bars("000000000"), **O.bars("008000000", "lower"), pedalBar16=0, pedalBar8=0)
        x, _, _ = steady(only_lower, lower="60"); self.assertGreater(K.peak_dbfs(x), -40, "channel 2 plays the lower manual")
        x, _, _ = steady(only_lower, notes="60"); self.assertLess(K.peak_dbfs(x), -140, "channel 1 above the split is the upper manual")
        x, _, _ = steady(dict(only_lower, splitKey=61), notes="60"); self.assertGreater(K.peak_dbfs(x), -40, "below Split Key: lower manual")
        only_ped = dict(O.DRY, **O.bars("000000000"), pedalBar16=8, pedalBar8=0)
        x, _, _ = steady(only_ped, pedals="36"); self.assertGreater(K.peak_dbfs(x), -40, "channel 3 plays the pedals")
        x, _, _ = steady(dict(only_ped, pedalSplit=48), notes="40"); self.assertGreater(K.peak_dbfs(x), -40, "below Pedal Split: pedals")
        x, _, _ = steady(dict(only_ped, pedalSplit=48), notes="30"); self.assertGreater(K.peak_dbfs(x), -40, "C1-B1 on channel 1 below Pedal Split")
        reg = dict(O.DRY, **O.bars("888888888"))
        for flag, note in (("notes", 35), ("notes", 97), ("lower", 35), ("lower", 97), ("pedals", 23), ("pedals", 49)):
            x, _, _ = steady(dict(reg, pedalBar16=8), **{flag: str(note)})
            self.assertLess(K.peak_dbfs(x), -140, "outside the register: %s %d must be silent" % (flag, note))

    def test_sustain_latches_manual_keys(self):                             # rule 14
        reg = dict(O.DRY, **O.bars("008000000"))
        x, fs, _ = O.render(reg, notes="60", gate=0.5, sustain="0.2:1,2.0:0", seconds=2.5)
        self.assertGreater(rms_db(x[int(1.4 * fs):int(1.9 * fs), 0]), -45, "held by CC64 after the key went up")
        self.assertLess(K.peak_dbfs(x[int(2.1 * fs):]), -120, "released at pedal up (what is left is the 5 Hz DC blocker's tail)")

    def test_expression_cc11_square_law_before_preamp(self):
        reg = dict(O.DRY, **O.bars("008000000"))
        full, _, _ = steady(reg, notes="60", expr="0:1")
        half, _, _ = steady(reg, notes="60", expr="0:0.5039")      # CC11 = 64
        d = rms_db(half[:, 0]) - rms_db(full[:, 0])
        self.assertAlmostEqual(d, 40 * np.log10(64 / 127), delta=0.3)
        hot, fs, _ = steady(dict(reg, drive=100), notes="60", expr="0:1")
        soft, fs, _ = steady(dict(reg, drive=100), notes="60", expr="0:0.1")
        self.assertLess(K.thd_db(soft[:, 0], fs, 261.54) - K.thd_db(hot[:, 0], fs, 261.54), -10, "less swell, less drive")

    def test_mod_wheel_switches_leslie_fast(self):                          # rule 16 mapping
        _, _, r = O.render({}, notes="60", seconds=6.0, mod="0:0.6")
        self.assertTrue(r["product"]["leslie_fast"]); self.assertGreater(r["product"]["horn_rpm"], 390)
        _, _, r = O.render({}, notes="60", seconds=0.2, mod="0:0.4")
        self.assertFalse(r["product"]["leslie_fast"])


if __name__ == "__main__":
    unittest.main(verbosity=2)
