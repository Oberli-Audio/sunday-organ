#!/usr/bin/env python3
"""The factory bank, from one table: writes presets.csv and presets/<slug>.oberlipreset, with each
preset's Output calibrated so the brief's reference chord (C3-E3-G3-C4, 4 s hold, no velocity)
integrates to -18 LUFS over the hold (brief presets, quality target loudness). Registrations are
the presets' notes (brief: the digits in the notes, not the name). Run after a sound change:
    python3 tools/presets/make_bank.py            (HARNESS from the environment or build/)"""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tests"))
import organ as O  # noqa: E402

TARGET = -18.0
REF = dict(notes="48,52,55,60", gate=4.0, seconds=6.0)
# slug, name, category, edge, upper, lower, settings (plain units), notes
BANK = [
    ("init", "Init", "Worship", "N", None, None, {}, "the parameter table's defaults"),
    ("jazz-trio", "Jazz Trio", "Jazz", "N", "888000000", None, dict(percOn=1, percThird=1, vibratoMode=6, drive=15), "third percussion, C3, light drive"),
    ("smoky-club", "Smoky Club", "Jazz", "N", "838000000", None, dict(percOn=1, percSoft=1, vibratoMode=6, drive=28, leakage=45), "second percussion soft, C3, worn"),
    ("bebop-lines", "Bebop Lines", "Jazz", "N", "888000000", None, dict(percOn=1, percThird=1, vibratoMode=0, keyClick=70), "dry, fast third percussion, sharp click"),
    ("gospel-full", "Gospel Full", "Gospel", "Y", "888888888", None, dict(vibratoMode=6, leslieFast=1, drive=50), "every drawbar out, C3, Leslie fast (loudest)"),
    ("shout-chorus", "Shout Chorus", "Gospel", "N", "888800000", None, dict(vibratoMode=6, leslieFast=1, drive=40, keyClick=60), "888800000, C3, fast"),
    ("sunday-morning", "Sunday Morning", "Gospel", "N", "888000000", "008080000", dict(percOn=1, percThird=1, vibratoMode=6, drive=30), "third percussion, C3, warm drive"),
    ("sanctuary", "Sanctuary", "Worship", "Y", "886000000", None, dict(vibratoMode=5, micSpread=180, drive=5, keyClick=15), "C2, mics opposite (widest)"),
    ("swell-pad", "Swell Pad", "Worship", "N", "008400000", None, dict(vibratoMode=6, drive=0, keyClick=10), "soft flutes, C3, for swells on CC11"),
    ("quiet-prayer", "Quiet Prayer", "Worship", "N", "008500000", "006000000", dict(vibratoMode=4, drive=0, keyClick=5, micSpread=150), "very soft flutes, C1"),
    ("rock-drive", "Rock Drive", "Rock", "Y", "888000000", None, dict(vibratoMode=3, leslieFast=1, drive=85), "V3, fast, heavy drive (most drive)"),
    ("power-chords", "Power Chords", "Rock", "N", "888800000", None, dict(vibratoMode=0, drive=70, keyClick=80), "dry, slow, driven"),
    ("ballad", "Ballad", "Ballad", "Y", "008000000", None, dict(vibratoMode=6, drive=0, keyClick=20), "8' alone, C3, clean (darkest)"),
    ("warm-ballad", "Warm Ballad", "Ballad", "N", "808000000", None, dict(vibratoMode=5, drive=8, keyClick=25), "16' and 8', C2"),
    ("split-comping", "Split Comping", "Split", "N", "888000000", "008080000", dict(splitKey=60, percOn=1, percThird=1, vibratoMode=6), "split at C4: lower comping, upper lead with percussion"),
    ("bass-split", "Bass Split", "Split", "N", "888000000", None, dict(pedalSplit=48, pedalBar16=8, pedalBar8=4, percOn=1, vibratoMode=6, drive=20), "C2-B2 play the pedals, the rest the upper manual"),
]


def plain_of(entry, out_gain):
    _, _, _, _, upper, lower, settings, _ = entry
    p = dict(settings)
    if upper: p.update(O.bars(upper))
    if lower: p.update(O.bars(lower, "lower"))
    if out_gain is not None: p["outGain"] = out_gain
    return p


def lufs(plain):
    x, fs, res = O.render(plain, **REF)
    return O.K.integrated_lufs(x[:int(REF['gate'] * fs)], fs)   # the hold, as presetlint.py render measures it


def xml(entry, plain):
    slug, name, cat, _, _, _, _, note = entry
    rows = "\n".join('      <PARAM id="%s" value="%s"/>' % (k, ("%g" % v)) for k, v in plain.items())
    return ('<?xml version="1.0" encoding="UTF-8"?>\n\n<OberliPreset name="%s" author="Oberli Audio" category="%s"\n'
            '              description="%s."\n              pluginVersion="0.1.0" created="2026-10-31" factory="true">\n'
            '  <SundayOrganState version="1" dspVersion="1">\n    <PARAMETERS>\n%s\n    </PARAMETERS>\n    <Extra/>\n  </SundayOrganState>\n</OberliPreset>\n'
            % (name, cat, note[0].upper() + note[1:], rows))


def main():
    root = O.ROOT
    with open(root / "presets.csv", "w") as f:
        f.write("slug,name,category,tags,edge,author,notes\n")
        for e in BANK:
            slug, name, cat, edge, upper, lower, _, note = e
            reg = "upper %s" % (upper or "888000000") + ("; lower %s" % lower if lower else "")
            f.write('%s,%s,%s,,%s,Oberli Audio,"%s; %s"\n' % (slug, name, cat, edge, note, reg))
    for e in BANK:
        if e[0] == "init":
            (root / "presets" / "init.oberlipreset").write_text(xml(e, {}))   # Init = the defaults, nothing stored
            print("init  %.2f LUFS (defaults, not calibrated)" % lufs({}))
            continue
        gain = 0.0
        for _ in range(2):   # Output is after the preamp, so the level is linear in it; two passes settle rounding
            gain = max(-24.0, min(12.0, round(gain + TARGET - lufs(plain_of(e, gain)), 1)))
        (root / "presets" / (e[0] + ".oberlipreset")).write_text(xml(e, plain_of(e, gain)))
        print("%-16s Output %+.1f dB -> %.2f LUFS" % (e[0], gain, lufs(plain_of(e, gain))))


if __name__ == "__main__":
    main()
