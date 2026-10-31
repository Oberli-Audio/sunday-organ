// Doppler presence/accuracy test: 2 kHz tone through the horn's direct path at constant
// fast speed. Left = delay only, right = full path (delay, moving LP, AM).
import("stdfaust.lib");
ls = library("../dsp/leslie.lib");
HZ = 6.67;
ph = ls.rotor(HZ, 0.0);
tone = sin(2 * ma.PI * 2000 * ba.time / ma.SR);   // exact sine (os.osc is a 64k truncated table: 0.2 cent of its own error)
process = tone : de.fdelay3(ls.MAXD, ls.hornDelay(ph, HZ, 0, 0) * ma.SR), ls.hornPath(ph, HZ, 0, 0, 1, tone);
