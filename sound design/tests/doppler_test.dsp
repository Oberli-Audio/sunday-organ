// Doppler presence/accuracy test: 2 kHz tone through the horn's direct path at constant
// fast speed. Left = delay only, right = full path (delay, moving LP, AM).
import("stdfaust.lib");
ls = library("../dsp/leslie.lib");
HZ = 6.67;
ph = ls.rotor(HZ, 0.0);
tone = os.osc(2000);
process = tone : de.fdelay3(ls.MAXD, ls.hornDelay(ph, HZ, 0, 0) * ma.SR), ls.hornPath(ph, HZ, 0, 0, 1, tone);
