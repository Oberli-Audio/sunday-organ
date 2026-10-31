// G5 probe (busses): taps the prototype at the plugin's --solo points; imports tonewheel.dsp, copies nothing.
import("stdfaust.lib");
tw = library("tonewheel.dsp");
ls = library("leslie.lib");
process = tw.upperSig, tw.lowerSig;
