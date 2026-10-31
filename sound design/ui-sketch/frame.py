"""Sunday Organ editor - Tier S static frame at 100 % (plugin-ui-bob), built from the brand's own
tokens and component CSS. Writes frame.html; render.py screenshots it at 1x and 2x.
The values shown are the Init patch, except Leslie fast mid-ramp to show the rotor display."""
import math, pathlib

HERE = pathlib.Path(__file__).parent

def arc(a0, a1, r=46):
    p = lambda a: (50 + r * math.sin(math.radians(a)), 50 - r * math.cos(math.radians(a)))
    (x0, y0), (x1, y1) = p(a0), p(a1)
    large = 1 if (a1 - a0) > 180 else 0
    return f"M{x0:.2f} {y0:.2f} A{r} {r} 0 {large} 1 {x1:.2f} {y1:.2f}"

def knob(label, value, v, size=48, zero=None):
    """zero: travel (0..1) of the neutral value for a bipolar knob; the arc runs from there."""
    ang = -135 + 270 * v
    z = -135 if zero is None else -135 + 270 * zero
    a0, a1 = (min(z, ang), max(z, ang))
    arc_d = arc(a0, a1) if abs(a1 - a0) > 0.5 else ""
    return f'''<div class="oa-knob"><svg width="{size}" height="{size}" viewBox="0 0 100 100" aria-hidden="true">
<path class="track" vector-effect="non-scaling-stroke" stroke-width="3" d="{arc(-135, 135)}"/>
{f'<path class="arc" vector-effect="non-scaling-stroke" stroke-width="3" d="{arc_d}"/>' if arc_d else ''}
<circle class="cap" vector-effect="non-scaling-stroke" stroke-width="1.5" cx="50" cy="50" r="36"/>
<rect class="ptr" x="43.88" y="19.4" width="12.24" height="24.48" rx="6.12" transform="rotate({ang:.1f} 50 50)"/></svg>
<div class="oa-label">{label}</div><div class="oa-value">{value}</div></div>'''

def bar(label, n, octave=True, h=112, shown=None):
    """Drawbar: the brand's upright slider (4 px track, accent fill from the bottom, 14 px thumb)."""
    y = h - 7 - (h - 14) * n / 8
    ticks = "".join(f'<div class="tick" style="bottom:{7 + (h - 14) * i / 8 - 0.5:.1f}px"></div>' for i in range(9))
    return f'''<div class="bar"><div class="rail" style="height:{h}px">{ticks}<div class="track"></div>
<div class="fill" style="height:{h - 7 - y:.1f}px"></div><div class="thumb" style="top:{y - 7:.1f}px"></div></div>
<div class="oa-label {'' if octave else 'dim'}">{label}</div><div class="oa-value">{n if shown is None else shown}</div></div>'''

def toggle(label, on): return f'<button class="oa-toggle" aria-pressed="{str(on).lower()}"><span class="led"></span>{label}</button>'

def rotor(name, rpm, angle, target):
    return f'''<div class="rotor"><svg width="56" height="56" viewBox="0 0 56 56" aria-hidden="true">
<circle cx="28" cy="28" r="25" fill="var(--surface-sunken)" stroke="var(--line-strong)" stroke-width="1.5"/>
<g transform="rotate({angle} 28 28)"><rect x="25.5" y="7" width="5" height="21" rx="2.5" fill="var(--accent)"/>
<rect x="25.5" y="28" width="5" height="13" rx="2.5" fill="var(--line-control)"/></g>
<circle cx="28" cy="28" r="4" fill="var(--surface-panel)" stroke="var(--line-control)" stroke-width="1.5"/></svg>
<div class="oa-label">{name}</div><div class="oa-value">{rpm} rpm</div><div class="meta sub">to {target}</div></div>'''

FEET = ["16'", "5 1/3'", "8'", "4'", "2 2/3'", "2'", "1 3/5'", "1 1/3'", "1'"]
OCT = [True, False, True, True, False, True, False, False, True]
upper = [8, 8, 8, 0, 0, 0, 0, 0, 0]
lower = [0, 0, 8, 0, 8, 0, 0, 0, 0]

LOGO = open(HERE / "logo-name-charcoal.svg").read()
chev_l = '<svg width="14" height="14" viewBox="0 0 16 16"><path d="M10 3.5 5.5 8l4.5 4.5" fill="none" stroke="currentColor" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/></svg>'
chev_r = '<svg width="14" height="14" viewBox="0 0 16 16"><path d="M6 3.5 10.5 8 6 12.5" fill="none" stroke="currentColor" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/></svg>'
menu = '<svg width="16" height="16" viewBox="0 0 16 16"><path d="M2.5 4.5h11M2.5 8h11M2.5 11.5h11" fill="none" stroke="currentColor" stroke-width="1.5" stroke-linecap="round"/></svg>'

html = f'''<!DOCTYPE html><html><head><meta charset="utf-8">
<link rel="stylesheet" href="tokens.css"><link rel="stylesheet" href="bundle.css">
<style>
html,body {{ margin:0; background:var(--ground); }}
.oa-plugin {{ width:1280px; border-radius:0; border:0; }}
.body {{ display:grid; grid-template-columns:1fr auto; padding:28px; gap:0; }}
.rows {{ display:flex; flex-direction:column; gap:28px; padding-right:28px; }}
.row {{ display:flex; gap:24px; align-items:flex-start; }}
.group {{ display:flex; flex-direction:column; gap:14px; }}
.group + .group.sep {{ border-left:1px solid var(--line); padding-left:24px; }}
.head {{ display:flex; justify-content:space-between; align-items:center; gap:16px; min-height:28px; }}
.section {{ color:var(--ink-muted); }}
.bars {{ display:flex; gap:6px; }}
.bar {{ display:flex; flex-direction:column; align-items:center; width:30px; }}
.bar .oa-label {{ letter-spacing:0.02em; white-space:nowrap; }}
.bar .oa-label.dim {{ color:var(--ink-subtle); }}
.rail {{ position:relative; width:30px; }}
.rail .track {{ position:absolute; left:13px; top:7px; bottom:7px; width:4px; border-radius:2px; background:var(--line-strong); }}
.rail .fill {{ position:absolute; left:13px; bottom:7px; width:4px; border-radius:2px; background:var(--accent); }}
.rail .tick {{ position:absolute; left:5px; width:5px; height:1px; background:var(--line); }}
.rail .thumb {{ position:absolute; left:8px; width:14px; height:14px; box-sizing:border-box; border-radius:50%; background:var(--surface-panel); border:1.5px solid var(--line-control); }}
.rail .thumb::after {{ content:""; position:absolute; left:2px; top:50%; width:5px; height:2px; margin-top:-1px; border-radius:1px; background:var(--accent); }}
.knobs {{ display:flex; gap:20px; align-items:flex-end; }}
.grid2 {{ display:grid; grid-template-columns:auto auto; gap:8px; }}
.rotor {{ display:flex; flex-direction:column; align-items:center; gap:4px; width:76px; }}
.rotor .sub {{ color:var(--ink-subtle); }}
.state {{ font:500 11px/14px var(--font-sans); color:var(--ink-subtle); }}
.state b {{ color:var(--accent); font-weight:600; }}
.field {{ display:flex; flex-direction:column; gap:4px; }}
.field .box {{ height:28px; box-sizing:border-box; padding:0 10px; display:flex; align-items:center; justify-content:space-between; gap:12px; min-width:96px;
  border-radius:var(--radius-md); border:1px solid var(--line-control); background:var(--surface-sunken); font:500 12px/16px var(--font-sans); font-feature-settings:"tnum" 1; }}
.field .box span {{ color:var(--ink-subtle); }}
.output {{ border-left:1px solid var(--line); padding-left:28px; display:flex; flex-direction:column; justify-content:flex-end; align-items:center; gap:24px; }}
.ghost {{ width:28px; height:28px; display:grid; place-items:center; color:var(--ink-muted); }}
</style></head><body>
<div class="oa-root"><div class="oa-plugin" data-accent="coral">
 <div class="oa-header">
  <div class="oa-header-left">{LOGO}<div class="oa-divider"></div><div class="plugin-name">Sunday Organ</div></div>
  <div class="oa-header-right"><div class="oa-pill"><span class="arrow">{chev_l}</span><span class="name">Init</span><span class="arrow">{chev_r}</span></div>
   <span class="meta" style="color:var(--ink-subtle);">0.1.0</span><span class="ghost">{menu}</span></div>
 </div>
 <div class="body"><div class="rows">
  <div class="row">
   <div class="group"><div class="head"><div class="section">WHEELS</div></div><div class="bars">{bar("MOD", 3, shown="38 %")}</div></div>
   <div class="group sep"><div class="head"><div class="section">UPPER</div><div class="state">channel 1, from C4 up</div></div>
     <div class="bars">{"".join(bar(f, n, o) for f, n, o in zip(FEET, upper, OCT))}</div></div>
   <div class="group sep"><div class="head"><div class="section">LOWER</div><div class="state">channel 2, below C4</div></div>
     <div class="bars">{"".join(bar(f, n, o) for f, n, o in zip(FEET, lower, OCT))}</div></div>
   <div class="group sep"><div class="head"><div class="section">PEDALS</div><div class="state">channel 3</div></div>
     <div class="knobs" style="align-items:flex-start"><div class="bars">{bar("16'", 6)}{bar("8'", 3)}</div>{knob("Release", "0.08 s", 0.5, 32)}</div></div>
   <div class="group sep"><div class="head"><div class="section">KEYBOARD</div></div>
     <div class="field"><div class="oa-label" style="margin:0">Split</div><div class="box">C4<span>{chev_r}</span></div></div>
     <div class="field"><div class="oa-label" style="margin:0">Pedal split</div><div class="box">Off<span>{chev_r}</span></div></div></div>
  </div>
  <div class="row">
   <div class="group"><div class="head"><div class="section">PERCUSSION</div></div>
     <div class="grid2">{toggle("On", True)}{toggle("Third", True)}{toggle("Slow", False)}{toggle("Soft", False)}</div>
     <div class="state">upper only, cuts 1'</div></div>
   <div class="group sep"><div class="head"><div class="section">VIBRATO</div></div>
     <div class="oa-seg" role="radiogroup" style="align-self:flex-start"><button aria-checked="false">Off</button><button aria-checked="false">V1</button><button aria-checked="false">V2</button><button aria-checked="false">V3</button><button aria-checked="false">C1</button><button aria-checked="false">C2</button><button aria-checked="true">C3</button></div><div>{toggle("Lower", False)}</div></div>
   <div class="group sep"><div class="head"><div class="section">LESLIE</div><div class="state"><b>Fast</b>, spinning up</div></div>
     <div class="knobs" style="align-items:flex-start; gap:16px">{rotor("Horn", 312, 128, "400")}{rotor("Drum", 141, 301, "340")}
       <div style="display:flex; flex-direction:column; gap:8px">{toggle("Fast", True)}{toggle("Brake", False)}{toggle("Leslie", True)}</div>{knob("Spread", "120°", 120 / 180)}</div></div>
   <div class="group sep"><div class="head"><div class="section">VOICE</div></div>
     <div class="knobs">{knob("Drive", "20 %", 0.38, 64)}{knob("Click", "50 %", 0.5, 32)}{knob("Leakage", "30 %", 0.3, 32)}</div></div>
  </div>
 </div>
 <div class="output">{knob("Output", "0.0 dB", 24 / 36, 64, zero=24 / 36)}
  <div class="oa-meter"><div style="display:flex; gap:3px;"><div class="well"><div class="bar" style="height:54%; background:var(--meter-level);"></div></div><div class="well"><div class="bar" style="height:58%; background:var(--meter-level);"></div></div></div><span class="clipled">CLIP</span></div>
 </div></div>
</div></div></body></html>'''
(HERE / "frame.html").write_text(html)
print("wrote frame.html")
