// Scanner presence test: 1 kHz tone through V1, V2, V3 (three outputs).
import("stdfaust.lib");
sc = library("../dsp/scanner.lib");
process = os.osc(1000) <: sc.scanner(1), sc.scanner(2), sc.scanner(3);
