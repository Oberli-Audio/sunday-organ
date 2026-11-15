#!/usr/bin/env python3
"""F-20 and F-21: the editor stays usable while it snows, and the snow goes when the section is left.

    check_snow_cost.py <SundayOrganGuiSnapshot> [--no-overlay]

On macOS the editor is one CoreAnimation layer: whatever the snow marks dirty in it is redrawn, and
the layer's backing store is copied and converted on every update, so snow drawn by the editor cost
the Standalone 128 % CPU under Rosetta against 47 % without snow (F-21; Live's audio meter shows
none of it). The fix puts the snow on a layer of its own above the editor. The snapshot tool opens
the editor in a real window (--onscreen) so the overlay attaches as in a host, plays 300 frames of
Sleigh Bells and reports where the snow went:
  editor_repaints_from_snow == 0 and own_layer   (macOS)   snow_is_on_its_own_layer
  snow gone <= 1.5 s after loading Jazz Trio                snow_leaves_with_the_section (F-20: 37 s)
--no-overlay passes the tool's switch that keeps the snow in the editor: the defect, to show the test
failing. Exit 0 pass, 1 fail."""
import json
import os
import subprocess
import sys
import tempfile


def main():
    tool = sys.argv[1]
    extra = ["--no-overlay"] if "--no-overlay" in sys.argv[2:] else []
    env = dict(os.environ, SUNDAYORGAN_PRESET_ROOT=tempfile.mkdtemp(prefix="sundayorgan-snow-"))
    out = subprocess.run([tool, "--onscreen", "--preset=sleigh-bells", "--frames=300", "--bench=60", "--leave=jazz-trio", *extra],
                         capture_output=True, text=True, env=env, timeout=300)
    if out.returncode != 0:
        sys.exit("snapshot tool failed: %s" % out.stderr.strip())
    r = json.loads(out.stdout.strip().splitlines()[-1])
    ok = True
    if not r["snow"]:
        print("FAIL: no snow on Sleigh Bells"); ok = False
    if sys.platform == "darwin":
        print("own layer: %s, repaints the snow asked of the editor: %d (limit 0)" % (r["own_layer"], r["editor_repaints_from_snow"]))
        if not r["own_layer"] or r["editor_repaints_from_snow"] > 0:
            print("FAIL: the snow is drawn by the editor (snow_is_on_its_own_layer)"); ok = False
    print("snow gone %d ms after leaving Jingle Jam (limit 1500)" % r["snow_gone_ms"])
    if r["snow_gone_ms"] > 1500:
        print("FAIL: the snow outlives the section (snow_leaves_with_the_section)"); ok = False
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
