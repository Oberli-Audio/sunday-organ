// G5 probe (voices): taps the prototype at the plugin's --solo points; imports tonewheel.dsp, copies nothing.
import("stdfaust.lib");
tw = library("tonewheel.dsp");
ls = library("leslie.lib");
process = tw.pedalSig, tw.voices;
