"""Scripted scores for the sketch renders. Format per line: time|label|value.
The first line carries the duration and sample rate: '# duration <s> <sr>'."""
import json, os
here = os.path.dirname(os.path.abspath(__file__))
UP = ["16'", "5 1/3'", "8'", "4'", "2 2/3'", "2'", "1 3/5'", "1 1/3'", "1'"]
LO = ["L " + b for b in UP]
REF = [48, 52, 55, 60]                                   # C3-E3-G3-C4, reference chord

def note(ev, t0, t1, n): ev += [(t0, f"key {n}", 1), (t1, f"key {n}", 0)]
def chord(ev, t0, t1, ns):
    for n in ns: note(ev, t0, t1, n)
def bars(s, names=UP): return [(0, l, int(c)) for l, c in zip(names, s)]

S = {}
ev = []; chord(ev, 0.5, 4.5, REF); S["01_init_chord_slow"] = (ev, 6)

ev = [(3.0, "Fast", 1), (7.0, "Fast", 0), (10.5, "Brake", 1), (12.5, "Brake", 0)]
chord(ev, 0.5, 14.5, REF); S["02_leslie_fast_slow_brake"] = (ev, 15.5)

ev = [(0, "On", 1), (0, "Third", 1), (0, "Drive", 0.4), (0, "Mode", 6)]
for i, n in enumerate([60, 63, 65, 66, 67, 70, 72, 67]): note(ev, 0.3 + 0.25 * i, 0.45 + 0.25 * i, n)
chord(ev, 2.6, 4.0, [55, 60, 63, 67]); S["03_percussion_riff"] = (ev, 5)

ev = [(0, "Leslie on", 0)]
for i, n in enumerate(range(36, 97, 6)): note(ev, 0.2 + 0.7 * i, 0.7 + 0.7 * i, n)
S["04_register_dry"] = (ev, 8.2)

ev = bars("888888888") + [(0, "Drive", 0.7), (0, "Fast", 1), (0, "Mode", 6)]
for i in range(4): chord(ev, 0.3 + i * 0.9, 0.8 + i * 0.9, [n + (5 if i % 2 else 0) for n in [43, 50, 55, 59, 62]])
S["05_full_drawbars_driven_fast"] = (ev, 4.5)

ev = [(0, "Leslie on", 0)]
for m in range(7): ev.append((m * 2.0, "Mode", m))
chord(ev, 0.1, 13.9, REF); S["06_scanner_off_V1_V2_V3_C1_C2_C3_dry"] = (ev, 14.5)

ev = [(0, "Split key", 60), (0, "On", 1), (0, "Third", 1), (0, "Mode", 6)]
for i in range(4): chord(ev, 0.2 + i * 1.0, 1.0 + i * 1.0, [41, 45, 48, 52] if i % 2 else [43, 47, 50, 53])
for i, n in enumerate([72, 74, 76, 79, 76, 74, 72, 71]): note(ev, 0.2 + 0.5 * i, 0.55 + 0.5 * i, n)
S["07_split_lower_comp_upper_lead"] = (ev, 5)

# register battery per manual (brief keyboard_span_lu): every 3rd key C2..C7 at 888000000, dry
ev = [(0, "Leslie on", 0)]
for i, n in enumerate(range(36, 97, 3)): note(ev, 0.2 + 0.7 * i, 0.7 + 0.7 * i, n)
S["09_register_upper"] = (ev, 15.2)
ev = [(0, "Leslie on", 0)] + bars("888000000", LO)
for i, n in enumerate(range(36, 97, 3)): ev += [(0.2 + 0.7 * i, f"lkey {n}", 1), (0.7 + 0.7 * i, f"lkey {n}", 0)]
S["10_register_lower"] = (ev, 15.2)

# expression (CC11) before the preamp: a held chord, swell down and up, Drive 0.6
ev = [(0, "Drive", 0.6)]
chord(ev, 0.3, 7.7, REF)
for i in range(41):
    # CC11 has 7 bits: the score's values are n/127 so the plugin (MIDI) and the prototype see the same
    ev.append((1.0 + 0.1 * i, "Expression", round(127 * (1 - 0.9 * i / 40)) / 127))
    ev.append((5.0 + 0.05 * i, "Expression", round(127 * (0.1 + 0.9 * i / 40)) / 127))
S["11_expression_swell"] = (ev, 8)

# three channels: ch2 lower chord, ch3 pedal, ch1 lead; then one keyboard with split C4 and pedal split C3
ev = [(0, "Mode", 6), (0, "On", 1), (0, "Third", 1)]
for i, (lo, ped) in enumerate([([53, 57, 60], 29), ([55, 59, 62], 31)]):
    for n in lo: ev += [(0.3 + 1.6 * i, f"lkey {n}", 1), (1.8 + 1.6 * i, f"lkey {n}", 0)]
    ev += [(0.3 + 1.6 * i, f"pedal {ped}", 1), (1.7 + 1.6 * i, f"pedal {ped}", 0)]
for i, n in enumerate([72, 74, 76, 77, 79, 77, 76, 74]): note(ev, 0.3 + 0.4 * i, 0.6 + 0.4 * i, n)
ev += [(3.6, "Split key", 60), (3.6, "Pedal split", 48)]
for i, (ch, ped) in enumerate([([53, 57, 60], 41), ([55, 59, 62], 43)]):
    chord(ev, 3.8 + 1.6 * i, 5.3 + 1.6 * i, ch + [ped])
for i, n in enumerate([72, 74, 76, 77, 79, 77, 76, 74]): note(ev, 3.8 + 0.4 * i, 4.1 + 0.4 * i, n)
S["12_three_channels_and_split"] = (ev, 7.6)

# evidence-only scores (not for listening)
ev = bars("008000000") + [(0, "Leslie on", 0), (0, "Drive", 1), (0, "Leakage", 0), (0, "Key click", 0)]
note(ev, 0.05, 2.95, 96); S["x_alias_C7_8ft_drive1"] = (ev, 3)
ev = bars("888888888") + bars("888888888", LO) + [(0, "Split key", 60), (0, "Mode", 6), (0, "Fast", 1), (0, "Drive", 0.7)]
chord(ev, 0.5, 9.5, [36, 43, 48, 52, 55, 60, 64, 67, 72, 79]); S["x_cpu_worst_case"] = (ev, 10)

presets = json.load(open(os.path.join(here, "..", "presets", "presets.json")))["presets"]
for p in presets:
    ev = bars(p["upper"]) + [(0, k, v) for k, v in p["params"].items()]
    chord(ev, 0.5, 4.5, REF)
    S["p_" + p["name"].lower().replace(" ", "_")] = (ev, 6)

for name, (ev, dur) in S.items():
    with open(os.path.join(here, name + ".txt"), "w") as f:
        f.write(f"# duration {dur}\n")
        for t, l, v in sorted(ev, key=lambda e: e[0]): f.write(f"{t}|{l}|{v}\n")
print(len(S), "scores")
