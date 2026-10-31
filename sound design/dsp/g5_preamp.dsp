// G5 probe (preamp): taps the prototype at the plugin's --solo points; imports tonewheel.dsp, copies nothing.
import("stdfaust.lib");
tw = library("tonewheel.dsp");
ls = library("leslie.lib");
process = tw.voices * 0.06 * tw.expr : tw.preamp : *(0.35 * tw.volume) <: _, ls.crossover;
