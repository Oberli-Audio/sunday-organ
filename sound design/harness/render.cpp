/* ------------------------------------------------------------
author: "Oberli Audio"
name: "Oberli Tonewheel (sketch)"
version: "0.0.3"
Code generated with Faust 2.70.3 (https://faust.grame.fr)
Compilation options: -a ../harness/arch.cpp -lang cpp -ct 1 -cn Tonewheel -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0
------------------------------------------------------------ */

#ifndef  __Tonewheel_H__
#define  __Tonewheel_H__

// Offline render harness for the sketch: scripted events -> stereo float WAV.
// Events are applied at block starts (TW_BLOCK, default 32 samples = 0.67 ms at 48 kHz),
// documented quantisation. TW_TIMES=<file> writes the compute time of every block.
#define FAUSTFLOAT double
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "faust/gui/MapUI.h"
#include "faust/gui/meta.h"
#include "faust/dsp/dsp.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS Tonewheel
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class TonewheelSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec17[2];
	
  public:
	
	int getNumInputsTonewheelSIG0() {
		return 0;
	}
	int getNumOutputsTonewheelSIG0() {
		return 1;
	}
	
	void instanceInitTonewheelSIG0(int sample_rate) {
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iVec1[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec17[l7] = 0;
		}
	}
	
	void fillTonewheelSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec1[0] = 1;
			iRec17[0] = (iVec1[1] + iRec17[1]) % 65536;
			table[i1] = std::cos(9.587379924285257e-05 * double(iRec17[0]));
			iVec1[1] = iVec1[0];
			iRec17[1] = iRec17[0];
		}
	}

};

static TonewheelSIG0* newTonewheelSIG0() { return (TonewheelSIG0*)new TonewheelSIG0(); }
static void deleteTonewheelSIG0(TonewheelSIG0* dsp) { delete dsp; }

class TonewheelSIG1 {
	
  private:
	
	int iVec2[2];
	int iRec19[2];
	
  public:
	
	int getNumInputsTonewheelSIG1() {
		return 0;
	}
	int getNumOutputsTonewheelSIG1() {
		return 1;
	}
	
	void instanceInitTonewheelSIG1(int sample_rate) {
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iVec2[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec19[l10] = 0;
		}
	}
	
	void fillTonewheelSIG1(int count, double* table) {
		for (int i2 = 0; i2 < count; i2 = i2 + 1) {
			iVec2[0] = 1;
			iRec19[0] = (iVec2[1] + iRec19[1]) % 65536;
			table[i2] = std::sin(9.587379924285257e-05 * double(iRec19[0]));
			iVec2[1] = iVec2[0];
			iRec19[1] = iRec19[0];
		}
	}

};

static TonewheelSIG1* newTonewheelSIG1() { return (TonewheelSIG1*)new TonewheelSIG1(); }
static void deleteTonewheelSIG1(TonewheelSIG1* dsp) { delete dsp; }

static double ftbl0TonewheelSIG0[65536];
static double ftbl1TonewheelSIG1[65536];

class Tonewheel : public dsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec1[2];
	double fConst3;
	double fRec0[2];
	double fConst4;
	FAUSTFLOAT fHslider1;
	double fConst5;
	double fRec2[2];
	double fConst6;
	double fConst7;
	FAUSTFLOAT fHslider2;
	double fConst8;
	double fRec14[2];
	FAUSTFLOAT fHslider3;
	double fRec15[2];
	double fConst9;
	double fRec18[2];
	double fConst10;
	FAUSTFLOAT fHslider4;
	double fConst11;
	double fRec20[2];
	double fConst12;
	double fRec21[2];
	FAUSTFLOAT fHslider5;
	double fRec22[2];
	FAUSTFLOAT fButton0;
	double fVec3[2];
	int iRec23[2];
	FAUSTFLOAT fHslider6;
	double fRec24[2];
	double fConst13;
	double fConst14;
	double fRec25[2];
	double fConst15;
	double fRec26[2];
	FAUSTFLOAT fButton1;
	double fVec4[2];
	int iRec27[2];
	double fRec28[2];
	double fConst16;
	double fRec29[2];
	FAUSTFLOAT fButton2;
	double fVec5[2];
	int iRec30[2];
	double fRec31[2];
	double fConst17;
	double fRec32[2];
	double fConst18;
	double fRec33[2];
	FAUSTFLOAT fButton3;
	double fVec6[2];
	int iRec34[2];
	double fRec35[2];
	double fConst19;
	double fRec36[2];
	double fConst20;
	double fRec37[2];
	FAUSTFLOAT fHslider7;
	double fRec38[2];
	FAUSTFLOAT fButton4;
	int IOTA0;
	FAUSTFLOAT fHslider8;
	double fRec40[1024];
	FAUSTFLOAT fHslider9;
	double fConst21;
	double fVec7[2];
	int iRec39[2];
	double fRec41[2];
	double fConst22;
	FAUSTFLOAT fHslider10;
	double fConst23;
	double fRec42[2];
	FAUSTFLOAT fButton5;
	double fRec44[1024];
	double fConst24;
	double fVec8[2];
	int iRec43[2];
	double fRec45[2];
	double fRec46[2];
	double fConst25;
	double fRec47[2];
	double fConst26;
	double fRec48[2];
	FAUSTFLOAT fButton6;
	double fRec50[1024];
	double fConst27;
	double fVec9[2];
	int iRec49[2];
	double fRec51[2];
	double fRec52[2];
	double fConst28;
	double fRec53[2];
	double fConst29;
	double fRec54[2];
	FAUSTFLOAT fButton7;
	double fRec56[1024];
	double fConst30;
	double fVec10[2];
	int iRec55[2];
	double fRec57[2];
	double fRec58[2];
	double fConst31;
	double fRec59[2];
	double fConst32;
	double fRec60[2];
	FAUSTFLOAT fButton8;
	double fRec62[1024];
	double fConst33;
	double fVec11[2];
	int iRec61[2];
	double fRec63[2];
	double fRec64[2];
	double fConst34;
	double fRec65[2];
	double fConst35;
	double fRec66[2];
	FAUSTFLOAT fButton9;
	double fRec68[1024];
	double fConst36;
	double fVec12[2];
	int iRec67[2];
	double fRec69[2];
	double fRec70[2];
	double fConst37;
	double fRec71[2];
	double fConst38;
	double fRec72[2];
	FAUSTFLOAT fButton10;
	double fRec74[1024];
	double fConst39;
	double fVec13[2];
	int iRec73[2];
	double fRec75[2];
	double fRec76[2];
	double fConst40;
	double fRec77[2];
	double fConst41;
	double fRec78[2];
	FAUSTFLOAT fButton11;
	double fRec80[1024];
	double fConst42;
	double fVec14[2];
	int iRec79[2];
	double fRec81[2];
	double fRec82[2];
	FAUSTFLOAT fButton12;
	double fRec84[1024];
	double fConst43;
	double fVec15[2];
	int iRec83[2];
	double fRec85[2];
	double fRec86[2];
	double fConst44;
	double fRec87[2];
	FAUSTFLOAT fButton13;
	double fRec89[1024];
	double fConst45;
	double fVec16[2];
	int iRec88[2];
	double fRec90[2];
	double fRec91[2];
	double fConst46;
	double fRec92[2];
	FAUSTFLOAT fButton14;
	double fRec94[1024];
	double fConst47;
	double fVec17[2];
	int iRec93[2];
	double fRec95[2];
	double fRec96[2];
	double fConst48;
	double fRec97[2];
	double fConst49;
	double fRec98[2];
	FAUSTFLOAT fButton15;
	double fRec100[1024];
	double fConst50;
	double fVec18[2];
	int iRec99[2];
	double fRec101[2];
	double fRec102[2];
	double fConst51;
	double fRec103[2];
	double fConst52;
	double fRec104[2];
	FAUSTFLOAT fButton16;
	double fRec106[1024];
	double fConst53;
	double fVec19[2];
	int iRec105[2];
	double fRec107[2];
	double fRec108[2];
	double fConst54;
	double fRec109[2];
	double fConst55;
	double fRec110[2];
	FAUSTFLOAT fButton17;
	double fRec112[1024];
	double fConst56;
	double fVec20[2];
	int iRec111[2];
	double fRec113[2];
	double fRec114[2];
	double fConst57;
	double fRec115[2];
	double fConst58;
	double fRec116[2];
	double fConst59;
	double fRec117[2];
	FAUSTFLOAT fButton18;
	double fRec119[1024];
	double fConst60;
	double fVec21[2];
	int iRec118[2];
	double fRec120[2];
	double fRec121[2];
	double fConst61;
	double fRec122[2];
	double fConst62;
	double fRec123[2];
	FAUSTFLOAT fButton19;
	double fRec125[1024];
	double fConst63;
	double fVec22[2];
	int iRec124[2];
	double fRec126[2];
	double fRec127[2];
	double fConst64;
	double fRec128[2];
	double fConst65;
	double fRec129[2];
	double fConst66;
	double fRec130[2];
	FAUSTFLOAT fButton20;
	double fRec132[1024];
	double fConst67;
	double fVec23[2];
	int iRec131[2];
	double fRec133[2];
	double fRec134[2];
	double fConst68;
	double fRec135[2];
	FAUSTFLOAT fButton21;
	double fRec137[1024];
	double fConst69;
	double fVec24[2];
	int iRec136[2];
	double fRec138[2];
	double fRec139[2];
	double fConst70;
	double fRec140[2];
	double fConst71;
	double fRec141[2];
	double fConst72;
	double fRec142[2];
	FAUSTFLOAT fButton22;
	double fRec144[1024];
	double fConst73;
	double fVec25[2];
	int iRec143[2];
	double fRec145[2];
	double fRec146[2];
	double fConst74;
	double fRec147[2];
	double fConst75;
	double fRec148[2];
	FAUSTFLOAT fButton23;
	double fRec150[1024];
	double fConst76;
	double fVec26[2];
	int iRec149[2];
	double fRec151[2];
	double fRec152[2];
	double fConst77;
	double fRec153[2];
	double fConst78;
	double fRec154[2];
	double fConst79;
	double fRec155[2];
	FAUSTFLOAT fButton24;
	double fRec157[1024];
	double fConst80;
	double fVec27[2];
	int iRec156[2];
	double fRec158[2];
	double fRec159[2];
	double fConst81;
	double fRec160[2];
	double fConst82;
	double fRec161[2];
	double fConst83;
	double fRec162[2];
	FAUSTFLOAT fButton25;
	double fRec164[1024];
	double fConst84;
	double fVec28[2];
	int iRec163[2];
	double fRec165[2];
	double fRec166[2];
	FAUSTFLOAT fButton26;
	double fRec168[1024];
	double fConst85;
	double fVec29[2];
	int iRec167[2];
	double fRec169[2];
	double fRec170[2];
	double fConst86;
	double fRec171[2];
	double fConst87;
	double fRec172[2];
	FAUSTFLOAT fButton27;
	double fRec174[1024];
	double fConst88;
	double fVec30[2];
	int iRec173[2];
	double fRec175[2];
	double fRec176[2];
	double fConst89;
	double fRec177[2];
	FAUSTFLOAT fButton28;
	double fRec179[1024];
	double fConst90;
	double fVec31[2];
	int iRec178[2];
	double fRec180[2];
	double fRec181[2];
	double fConst91;
	double fRec182[2];
	FAUSTFLOAT fButton29;
	double fRec184[1024];
	double fConst92;
	double fVec32[2];
	int iRec183[2];
	double fRec185[2];
	double fRec186[2];
	FAUSTFLOAT fButton30;
	double fRec188[1024];
	double fConst93;
	double fVec33[2];
	int iRec187[2];
	double fRec189[2];
	double fRec190[2];
	double fConst94;
	double fRec191[2];
	FAUSTFLOAT fButton31;
	double fRec193[1024];
	double fConst95;
	double fVec34[2];
	int iRec192[2];
	double fRec194[2];
	double fRec195[2];
	double fConst96;
	double fRec196[2];
	FAUSTFLOAT fButton32;
	double fRec198[1024];
	double fConst97;
	double fVec35[2];
	int iRec197[2];
	double fRec199[2];
	double fRec200[2];
	double fConst98;
	double fRec201[2];
	double fConst99;
	double fRec202[2];
	FAUSTFLOAT fButton33;
	double fRec204[1024];
	double fConst100;
	double fVec36[2];
	int iRec203[2];
	double fRec205[2];
	double fRec206[2];
	double fConst101;
	double fRec207[2];
	FAUSTFLOAT fButton34;
	double fRec209[1024];
	double fConst102;
	double fVec37[2];
	int iRec208[2];
	double fRec210[2];
	double fRec211[2];
	FAUSTFLOAT fButton35;
	double fRec213[1024];
	double fConst103;
	double fVec38[2];
	int iRec212[2];
	double fRec214[2];
	double fRec215[2];
	FAUSTFLOAT fButton36;
	double fRec217[1024];
	double fConst104;
	double fVec39[2];
	int iRec216[2];
	double fRec218[2];
	double fRec219[2];
	FAUSTFLOAT fButton37;
	double fRec221[1024];
	double fConst105;
	double fVec40[2];
	int iRec220[2];
	double fRec222[2];
	double fRec223[2];
	double fConst106;
	double fRec224[2];
	FAUSTFLOAT fButton38;
	double fRec226[1024];
	double fConst107;
	double fVec41[2];
	int iRec225[2];
	double fRec227[2];
	double fRec228[2];
	FAUSTFLOAT fButton39;
	double fRec230[1024];
	double fConst108;
	double fVec42[2];
	int iRec229[2];
	double fRec231[2];
	double fRec232[2];
	double fConst109;
	double fRec233[2];
	FAUSTFLOAT fButton40;
	double fRec235[1024];
	double fConst110;
	double fVec43[2];
	int iRec234[2];
	double fRec236[2];
	double fRec237[2];
	FAUSTFLOAT fButton41;
	double fRec239[1024];
	double fConst111;
	double fVec44[2];
	int iRec238[2];
	double fRec240[2];
	double fRec241[2];
	FAUSTFLOAT fButton42;
	double fRec243[1024];
	double fConst112;
	double fVec45[2];
	int iRec242[2];
	double fRec244[2];
	double fRec245[2];
	FAUSTFLOAT fButton43;
	double fRec247[1024];
	double fConst113;
	double fVec46[2];
	int iRec246[2];
	double fRec248[2];
	double fRec249[2];
	double fConst114;
	double fRec250[2];
	FAUSTFLOAT fButton44;
	double fRec252[1024];
	double fConst115;
	double fVec47[2];
	int iRec251[2];
	double fRec253[2];
	double fRec254[2];
	FAUSTFLOAT fButton45;
	double fRec256[1024];
	double fConst116;
	double fVec48[2];
	int iRec255[2];
	double fRec257[2];
	double fRec258[2];
	FAUSTFLOAT fButton46;
	double fRec260[1024];
	double fConst117;
	double fVec49[2];
	int iRec259[2];
	double fRec261[2];
	double fRec262[2];
	FAUSTFLOAT fButton47;
	double fRec264[1024];
	double fConst118;
	double fVec50[2];
	int iRec263[2];
	double fRec265[2];
	double fRec266[2];
	FAUSTFLOAT fButton48;
	double fRec268[1024];
	double fConst119;
	double fVec51[2];
	int iRec267[2];
	double fRec269[2];
	double fRec270[2];
	double fConst120;
	double fRec271[2];
	FAUSTFLOAT fButton49;
	double fRec273[1024];
	double fConst121;
	double fVec52[2];
	int iRec272[2];
	double fRec274[2];
	double fRec275[2];
	FAUSTFLOAT fButton50;
	double fRec277[1024];
	double fConst122;
	double fVec53[2];
	int iRec276[2];
	double fRec278[2];
	double fRec279[2];
	FAUSTFLOAT fButton51;
	double fRec281[1024];
	double fConst123;
	double fVec54[2];
	int iRec280[2];
	double fRec282[2];
	double fConst124;
	double fRec283[2];
	double fRec284[2];
	FAUSTFLOAT fButton52;
	double fRec286[1024];
	double fConst125;
	double fVec55[2];
	int iRec285[2];
	double fRec287[2];
	double fRec288[2];
	FAUSTFLOAT fButton53;
	double fRec290[1024];
	double fConst126;
	double fVec56[2];
	int iRec289[2];
	double fRec291[2];
	double fRec292[2];
	FAUSTFLOAT fButton54;
	double fRec294[1024];
	double fConst127;
	double fVec57[2];
	int iRec293[2];
	double fRec295[2];
	double fRec296[2];
	FAUSTFLOAT fButton55;
	double fRec298[1024];
	double fConst128;
	double fVec58[2];
	int iRec297[2];
	double fRec299[2];
	double fRec300[2];
	FAUSTFLOAT fButton56;
	double fRec302[1024];
	double fConst129;
	double fVec59[2];
	int iRec301[2];
	double fRec303[2];
	double fRec304[2];
	FAUSTFLOAT fButton57;
	double fRec306[1024];
	double fConst130;
	double fVec60[2];
	int iRec305[2];
	double fRec307[2];
	double fRec308[2];
	FAUSTFLOAT fButton58;
	double fRec310[1024];
	double fConst131;
	double fVec61[2];
	int iRec309[2];
	double fRec311[2];
	double fRec312[2];
	FAUSTFLOAT fButton59;
	double fRec314[1024];
	double fConst132;
	double fVec62[2];
	int iRec313[2];
	double fRec315[2];
	double fRec316[2];
	FAUSTFLOAT fButton60;
	double fRec318[1024];
	double fConst133;
	double fVec63[2];
	int iRec317[2];
	double fRec319[2];
	double fRec320[2];
	FAUSTFLOAT fButton61;
	double fRec322[1024];
	double fConst134;
	double fVec64[2];
	int iRec321[2];
	double fRec323[2];
	double fRec324[2];
	FAUSTFLOAT fButton62;
	double fRec326[1024];
	double fConst135;
	double fVec65[2];
	int iRec325[2];
	double fRec327[2];
	double fRec328[2];
	FAUSTFLOAT fButton63;
	double fRec330[1024];
	double fConst136;
	double fVec66[2];
	int iRec329[2];
	double fRec331[2];
	double fRec332[2];
	FAUSTFLOAT fButton64;
	double fRec334[1024];
	double fConst137;
	double fVec67[2];
	int iRec333[2];
	double fRec335[2];
	double fRec336[2];
	FAUSTFLOAT fHslider11;
	double fRec337[2];
	double fConst138;
	double fVec68[2];
	int iRec338[2];
	double fRec339[2];
	double fConst139;
	double fVec69[2];
	int iRec340[2];
	double fRec341[2];
	double fConst140;
	double fVec70[2];
	int iRec342[2];
	double fRec343[2];
	double fConst141;
	double fVec71[2];
	int iRec344[2];
	double fRec345[2];
	double fConst142;
	double fVec72[2];
	int iRec346[2];
	double fRec347[2];
	double fConst143;
	double fVec73[2];
	int iRec348[2];
	double fRec349[2];
	double fConst144;
	double fVec74[2];
	int iRec350[2];
	double fRec351[2];
	double fConst145;
	double fVec75[2];
	int iRec352[2];
	double fRec353[2];
	double fConst146;
	double fVec76[2];
	int iRec354[2];
	double fRec355[2];
	double fConst147;
	double fVec77[2];
	int iRec356[2];
	double fRec357[2];
	double fConst148;
	double fRec358[2];
	double fConst149;
	double fVec78[2];
	int iRec359[2];
	double fRec360[2];
	double fConst150;
	double fRec361[2];
	double fConst151;
	double fVec79[2];
	int iRec362[2];
	double fRec363[2];
	double fConst152;
	double fRec364[2];
	double fConst153;
	double fVec80[2];
	int iRec365[2];
	double fRec366[2];
	double fConst154;
	double fVec81[2];
	int iRec367[2];
	double fRec368[2];
	double fConst155;
	double fVec82[2];
	int iRec369[2];
	double fRec370[2];
	double fConst156;
	double fVec83[2];
	int iRec371[2];
	double fRec372[2];
	double fConst157;
	double fRec373[2];
	double fConst158;
	double fVec84[2];
	int iRec374[2];
	double fRec375[2];
	double fConst159;
	double fVec85[2];
	int iRec376[2];
	double fRec377[2];
	double fConst160;
	double fVec86[2];
	int iRec378[2];
	double fRec379[2];
	double fConst161;
	double fRec380[2];
	double fConst162;
	double fVec87[2];
	int iRec381[2];
	double fRec382[2];
	double fConst163;
	double fVec88[2];
	int iRec383[2];
	double fRec384[2];
	double fConst164;
	double fVec89[2];
	int iRec385[2];
	double fRec386[2];
	double fConst165;
	double fVec90[2];
	int iRec387[2];
	double fRec388[2];
	double fConst166;
	double fVec91[2];
	int iRec389[2];
	double fRec390[2];
	double fConst167;
	double fRec391[2];
	double fConst168;
	double fVec92[2];
	int iRec392[2];
	double fRec393[2];
	double fConst169;
	double fVec93[2];
	int iRec394[2];
	double fRec395[2];
	double fConst170;
	double fVec94[2];
	int iRec396[2];
	double fRec397[2];
	double fConst171;
	double fVec95[2];
	int iRec398[2];
	double fRec399[2];
	double fConst172;
	double fVec96[2];
	int iRec400[2];
	double fRec401[2];
	double fConst173;
	double fVec97[2];
	int iRec402[2];
	double fRec403[2];
	double fConst174;
	double fVec98[2];
	int iRec404[2];
	double fRec405[2];
	double fConst175;
	double fVec99[2];
	int iRec406[2];
	double fRec407[2];
	double fConst176;
	double fVec100[2];
	int iRec408[2];
	double fRec409[2];
	double fConst177;
	double fVec101[2];
	int iRec410[2];
	double fRec411[2];
	double fConst178;
	double fVec102[2];
	int iRec412[2];
	double fRec413[2];
	double fConst179;
	double fVec103[2];
	int iRec414[2];
	double fRec415[2];
	double fConst180;
	double fVec104[2];
	int iRec416[2];
	double fRec417[2];
	double fConst181;
	double fVec105[2];
	int iRec418[2];
	double fRec419[2];
	double fConst182;
	double fVec106[2];
	int iRec420[2];
	double fRec421[2];
	double fConst183;
	double fVec107[2];
	int iRec422[2];
	double fRec423[2];
	double fConst184;
	double fVec108[2];
	int iRec424[2];
	double fRec425[2];
	double fConst185;
	double fVec109[2];
	int iRec426[2];
	double fRec427[2];
	double fConst186;
	double fVec110[2];
	int iRec428[2];
	double fRec429[2];
	double fConst187;
	double fVec111[2];
	int iRec430[2];
	double fRec431[2];
	double fConst188;
	double fVec112[2];
	int iRec432[2];
	double fRec433[2];
	double fConst189;
	double fVec113[2];
	int iRec434[2];
	double fRec435[2];
	double fConst190;
	double fVec114[2];
	int iRec436[2];
	double fRec437[2];
	double fConst191;
	double fVec115[2];
	int iRec438[2];
	double fRec439[2];
	double fConst192;
	double fVec116[2];
	int iRec440[2];
	double fRec441[2];
	double fConst193;
	double fVec117[2];
	int iRec442[2];
	double fRec443[2];
	double fConst194;
	double fVec118[2];
	int iRec444[2];
	double fRec445[2];
	double fConst195;
	double fVec119[2];
	int iRec446[2];
	double fRec447[2];
	double fConst196;
	double fVec120[2];
	int iRec448[2];
	double fRec449[2];
	double fConst197;
	double fVec121[2];
	int iRec450[2];
	double fRec451[2];
	double fConst198;
	double fVec122[2];
	int iRec452[2];
	double fRec453[2];
	double fConst199;
	double fVec123[2];
	int iRec454[2];
	double fRec455[2];
	double fConst200;
	double fVec124[2];
	int iRec456[2];
	double fRec457[2];
	double fConst201;
	double fVec125[2];
	int iRec458[2];
	double fRec459[2];
	double fConst202;
	double fVec126[2];
	int iRec460[2];
	double fRec461[2];
	double fConst203;
	double fVec127[2];
	int iRec462[2];
	double fRec463[2];
	double fConst204;
	double fVec128[2];
	int iRec464[2];
	double fRec465[2];
	FAUSTFLOAT fHslider12;
	double fRec466[2];
	double fConst205;
	double fVec129[2];
	int iRec467[2];
	double fRec468[2];
	double fConst206;
	double fVec130[2];
	int iRec469[2];
	double fRec470[2];
	double fConst207;
	double fVec131[2];
	int iRec471[2];
	double fRec472[2];
	double fConst208;
	double fVec132[2];
	int iRec473[2];
	double fRec474[2];
	double fConst209;
	double fVec133[2];
	int iRec475[2];
	double fRec476[2];
	double fConst210;
	double fVec134[2];
	int iRec477[2];
	double fRec478[2];
	double fConst211;
	double fVec135[2];
	int iRec479[2];
	double fRec480[2];
	double fConst212;
	double fVec136[2];
	int iRec481[2];
	double fRec482[2];
	double fConst213;
	double fVec137[2];
	int iRec483[2];
	double fRec484[2];
	double fConst214;
	double fVec138[2];
	int iRec485[2];
	double fRec486[2];
	double fConst215;
	double fVec139[2];
	int iRec487[2];
	double fRec488[2];
	double fConst216;
	double fVec140[2];
	int iRec489[2];
	double fRec490[2];
	double fConst217;
	double fVec141[2];
	int iRec491[2];
	double fRec492[2];
	double fConst218;
	double fRec493[2];
	double fConst219;
	double fVec142[2];
	int iRec494[2];
	double fRec495[2];
	double fConst220;
	double fVec143[2];
	int iRec496[2];
	double fRec497[2];
	double fConst221;
	double fVec144[2];
	int iRec498[2];
	double fRec499[2];
	double fConst222;
	double fVec145[2];
	int iRec500[2];
	double fRec501[2];
	double fConst223;
	double fVec146[2];
	int iRec502[2];
	double fRec503[2];
	double fConst224;
	double fVec147[2];
	int iRec504[2];
	double fRec505[2];
	double fConst225;
	double fVec148[2];
	int iRec506[2];
	double fRec507[2];
	double fConst226;
	double fVec149[2];
	int iRec508[2];
	double fRec509[2];
	double fConst227;
	double fVec150[2];
	int iRec510[2];
	double fRec511[2];
	double fConst228;
	double fVec151[2];
	int iRec512[2];
	double fRec513[2];
	double fConst229;
	double fVec152[2];
	int iRec514[2];
	double fRec515[2];
	double fConst230;
	double fVec153[2];
	int iRec516[2];
	double fRec517[2];
	double fConst231;
	double fVec154[2];
	int iRec518[2];
	double fRec519[2];
	double fConst232;
	double fVec155[2];
	int iRec520[2];
	double fRec521[2];
	double fConst233;
	double fVec156[2];
	int iRec522[2];
	double fRec523[2];
	double fConst234;
	double fVec157[2];
	int iRec524[2];
	double fRec525[2];
	double fConst235;
	double fRec526[2];
	double fConst236;
	double fVec158[2];
	int iRec527[2];
	double fRec528[2];
	double fConst237;
	double fVec159[2];
	int iRec529[2];
	double fRec530[2];
	double fConst238;
	double fVec160[2];
	int iRec531[2];
	double fRec532[2];
	double fConst239;
	double fRec533[2];
	double fConst240;
	double fVec161[2];
	int iRec534[2];
	double fRec535[2];
	double fConst241;
	double fVec162[2];
	int iRec536[2];
	double fRec537[2];
	double fConst242;
	double fRec538[2];
	double fConst243;
	double fVec163[2];
	int iRec539[2];
	double fRec540[2];
	double fConst244;
	double fVec164[2];
	int iRec541[2];
	double fRec542[2];
	double fConst245;
	double fVec165[2];
	int iRec543[2];
	double fRec544[2];
	double fConst246;
	double fVec166[2];
	int iRec545[2];
	double fRec546[2];
	double fConst247;
	double fVec167[2];
	int iRec547[2];
	double fRec548[2];
	double fConst248;
	double fVec168[2];
	int iRec549[2];
	double fRec550[2];
	double fConst249;
	double fVec169[2];
	int iRec551[2];
	double fRec552[2];
	double fConst250;
	double fVec170[2];
	int iRec553[2];
	double fRec554[2];
	double fConst251;
	double fVec171[2];
	int iRec555[2];
	double fRec556[2];
	double fConst252;
	double fVec172[2];
	int iRec557[2];
	double fRec558[2];
	double fConst253;
	double fVec173[2];
	int iRec559[2];
	double fRec560[2];
	double fConst254;
	double fVec174[2];
	int iRec561[2];
	double fRec562[2];
	double fConst255;
	double fVec175[2];
	int iRec563[2];
	double fRec564[2];
	double fConst256;
	double fVec176[2];
	int iRec565[2];
	double fRec566[2];
	double fConst257;
	double fVec177[2];
	int iRec567[2];
	double fRec568[2];
	double fConst258;
	double fVec178[2];
	int iRec569[2];
	double fRec570[2];
	double fConst259;
	double fVec179[2];
	int iRec571[2];
	double fRec572[2];
	double fConst260;
	double fVec180[2];
	int iRec573[2];
	double fRec574[2];
	double fConst261;
	double fVec181[2];
	int iRec575[2];
	double fRec576[2];
	double fConst262;
	double fVec182[2];
	int iRec577[2];
	double fRec578[2];
	double fConst263;
	double fVec183[2];
	int iRec579[2];
	double fRec580[2];
	double fConst264;
	double fVec184[2];
	int iRec581[2];
	double fRec582[2];
	double fConst265;
	double fVec185[2];
	int iRec583[2];
	double fRec584[2];
	double fConst266;
	double fVec186[2];
	int iRec585[2];
	double fRec586[2];
	double fConst267;
	double fVec187[2];
	int iRec587[2];
	double fRec588[2];
	double fConst268;
	double fVec188[2];
	int iRec589[2];
	double fRec590[2];
	double fConst269;
	double fVec189[2];
	int iRec591[2];
	double fRec592[2];
	FAUSTFLOAT fHslider13;
	double fRec593[2];
	double fConst270;
	double fVec190[2];
	int iRec594[2];
	double fRec595[2];
	double fConst271;
	double fVec191[2];
	int iRec596[2];
	double fRec597[2];
	double fConst272;
	double fVec192[2];
	int iRec598[2];
	double fRec599[2];
	double fConst273;
	double fVec193[2];
	int iRec600[2];
	double fRec601[2];
	double fConst274;
	double fVec194[2];
	int iRec602[2];
	double fRec603[2];
	double fConst275;
	double fVec195[2];
	int iRec604[2];
	double fRec605[2];
	double fConst276;
	double fVec196[2];
	int iRec606[2];
	double fRec607[2];
	double fConst277;
	double fVec197[2];
	int iRec608[2];
	double fRec609[2];
	double fConst278;
	double fVec198[2];
	int iRec610[2];
	double fRec611[2];
	double fConst279;
	double fVec199[2];
	int iRec612[2];
	double fRec613[2];
	double fConst280;
	double fVec200[2];
	int iRec614[2];
	double fRec615[2];
	double fConst281;
	double fVec201[2];
	int iRec616[2];
	double fRec617[2];
	double fConst282;
	double fVec202[2];
	int iRec618[2];
	double fRec619[2];
	double fConst283;
	double fVec203[2];
	int iRec620[2];
	double fRec621[2];
	double fConst284;
	double fVec204[2];
	int iRec622[2];
	double fRec623[2];
	double fConst285;
	double fVec205[2];
	int iRec624[2];
	double fRec625[2];
	double fConst286;
	double fVec206[2];
	int iRec626[2];
	double fRec627[2];
	double fConst287;
	double fVec207[2];
	int iRec628[2];
	double fRec629[2];
	double fConst288;
	double fVec208[2];
	int iRec630[2];
	double fRec631[2];
	double fConst289;
	double fRec632[2];
	double fConst290;
	double fVec209[2];
	int iRec633[2];
	double fRec634[2];
	double fConst291;
	double fVec210[2];
	int iRec635[2];
	double fRec636[2];
	double fConst292;
	double fRec637[2];
	double fConst293;
	double fVec211[2];
	int iRec638[2];
	double fRec639[2];
	double fConst294;
	double fRec640[2];
	double fConst295;
	double fVec212[2];
	int iRec641[2];
	double fRec642[2];
	double fConst296;
	double fVec213[2];
	int iRec643[2];
	double fRec644[2];
	double fConst297;
	double fRec645[2];
	double fConst298;
	double fVec214[2];
	int iRec646[2];
	double fRec647[2];
	double fConst299;
	double fVec215[2];
	int iRec648[2];
	double fRec649[2];
	double fConst300;
	double fVec216[2];
	int iRec650[2];
	double fRec651[2];
	double fConst301;
	double fVec217[2];
	int iRec652[2];
	double fRec653[2];
	double fConst302;
	double fVec218[2];
	int iRec654[2];
	double fRec655[2];
	double fConst303;
	double fVec219[2];
	int iRec656[2];
	double fRec657[2];
	double fConst304;
	double fVec220[2];
	int iRec658[2];
	double fRec659[2];
	double fConst305;
	double fVec221[2];
	int iRec660[2];
	double fRec661[2];
	double fConst306;
	double fVec222[2];
	int iRec662[2];
	double fRec663[2];
	double fConst307;
	double fVec223[2];
	int iRec664[2];
	double fRec665[2];
	double fConst308;
	double fVec224[2];
	int iRec666[2];
	double fRec667[2];
	double fConst309;
	double fVec225[2];
	int iRec668[2];
	double fRec669[2];
	double fConst310;
	double fVec226[2];
	int iRec670[2];
	double fRec671[2];
	double fConst311;
	double fVec227[2];
	int iRec672[2];
	double fRec673[2];
	double fConst312;
	double fVec228[2];
	int iRec674[2];
	double fRec675[2];
	double fConst313;
	double fVec229[2];
	int iRec676[2];
	double fRec677[2];
	double fConst314;
	double fVec230[2];
	int iRec678[2];
	double fRec679[2];
	double fConst315;
	double fVec231[2];
	int iRec680[2];
	double fRec681[2];
	double fConst316;
	double fVec232[2];
	int iRec682[2];
	double fRec683[2];
	double fConst317;
	double fVec233[2];
	int iRec684[2];
	double fRec685[2];
	double fConst318;
	double fVec234[2];
	int iRec686[2];
	double fRec687[2];
	double fConst319;
	double fVec235[2];
	int iRec688[2];
	double fRec689[2];
	double fConst320;
	double fVec236[2];
	int iRec690[2];
	double fRec691[2];
	double fConst321;
	double fVec237[2];
	int iRec692[2];
	double fRec693[2];
	double fConst322;
	double fVec238[2];
	int iRec694[2];
	double fRec695[2];
	double fConst323;
	double fVec239[2];
	int iRec696[2];
	double fRec697[2];
	double fConst324;
	double fVec240[2];
	int iRec698[2];
	double fRec699[2];
	double fConst325;
	double fVec241[2];
	int iRec700[2];
	double fRec701[2];
	double fConst326;
	double fVec242[2];
	int iRec702[2];
	double fRec703[2];
	double fConst327;
	double fVec243[2];
	int iRec704[2];
	double fRec705[2];
	double fConst328;
	double fVec244[2];
	int iRec706[2];
	double fRec707[2];
	double fConst329;
	double fVec245[2];
	int iRec708[2];
	double fRec709[2];
	double fConst330;
	double fVec246[2];
	int iRec710[2];
	double fRec711[2];
	double fConst331;
	double fVec247[2];
	int iRec712[2];
	double fRec713[2];
	double fConst332;
	double fVec248[2];
	int iRec714[2];
	double fRec715[2];
	double fConst333;
	double fVec249[2];
	int iRec716[2];
	double fRec717[2];
	double fConst334;
	double fVec250[2];
	int iRec718[2];
	double fRec719[2];
	FAUSTFLOAT fHslider14;
	double fRec720[2];
	double fConst335;
	double fVec251[2];
	int iRec721[2];
	double fRec722[2];
	double fConst336;
	double fVec252[2];
	int iRec723[2];
	double fRec724[2];
	double fConst337;
	double fVec253[2];
	int iRec725[2];
	double fRec726[2];
	double fConst338;
	double fVec254[2];
	int iRec727[2];
	double fRec728[2];
	double fConst339;
	double fVec255[2];
	int iRec729[2];
	double fRec730[2];
	double fConst340;
	double fVec256[2];
	int iRec731[2];
	double fRec732[2];
	double fConst341;
	double fVec257[2];
	int iRec733[2];
	double fRec734[2];
	double fConst342;
	double fVec258[2];
	int iRec735[2];
	double fRec736[2];
	double fConst343;
	double fVec259[2];
	int iRec737[2];
	double fRec738[2];
	double fConst344;
	double fVec260[2];
	int iRec739[2];
	double fRec740[2];
	double fConst345;
	double fVec261[2];
	int iRec741[2];
	double fRec742[2];
	double fConst346;
	double fVec262[2];
	int iRec743[2];
	double fRec744[2];
	double fConst347;
	double fVec263[2];
	int iRec745[2];
	double fRec746[2];
	double fConst348;
	double fVec264[2];
	int iRec747[2];
	double fRec748[2];
	double fConst349;
	double fVec265[2];
	int iRec749[2];
	double fRec750[2];
	double fConst350;
	double fVec266[2];
	int iRec751[2];
	double fRec752[2];
	double fConst351;
	double fVec267[2];
	int iRec753[2];
	double fRec754[2];
	double fConst352;
	double fVec268[2];
	int iRec755[2];
	double fRec756[2];
	double fConst353;
	double fVec269[2];
	int iRec757[2];
	double fRec758[2];
	double fConst354;
	double fVec270[2];
	int iRec759[2];
	double fRec760[2];
	double fConst355;
	double fVec271[2];
	int iRec761[2];
	double fRec762[2];
	double fConst356;
	double fVec272[2];
	int iRec763[2];
	double fRec764[2];
	double fConst357;
	double fVec273[2];
	int iRec765[2];
	double fRec766[2];
	double fConst358;
	double fVec274[2];
	int iRec767[2];
	double fRec768[2];
	double fConst359;
	double fRec769[2];
	double fConst360;
	double fVec275[2];
	int iRec770[2];
	double fRec771[2];
	double fConst361;
	double fVec276[2];
	int iRec772[2];
	double fRec773[2];
	double fConst362;
	double fRec774[2];
	double fConst363;
	double fVec277[2];
	int iRec775[2];
	double fRec776[2];
	double fConst364;
	double fVec278[2];
	int iRec777[2];
	double fRec778[2];
	double fConst365;
	double fRec779[2];
	double fConst366;
	double fVec279[2];
	int iRec780[2];
	double fRec781[2];
	double fConst367;
	double fRec782[2];
	double fConst368;
	double fVec280[2];
	int iRec783[2];
	double fRec784[2];
	double fConst369;
	double fVec281[2];
	int iRec785[2];
	double fRec786[2];
	double fConst370;
	double fVec282[2];
	int iRec787[2];
	double fRec788[2];
	double fConst371;
	double fVec283[2];
	int iRec789[2];
	double fRec790[2];
	double fConst372;
	double fVec284[2];
	int iRec791[2];
	double fRec792[2];
	double fConst373;
	double fVec285[2];
	int iRec793[2];
	double fRec794[2];
	double fConst374;
	double fVec286[2];
	int iRec795[2];
	double fRec796[2];
	double fConst375;
	double fVec287[2];
	int iRec797[2];
	double fRec798[2];
	double fConst376;
	double fVec288[2];
	int iRec799[2];
	double fRec800[2];
	double fConst377;
	double fVec289[2];
	int iRec801[2];
	double fRec802[2];
	double fConst378;
	double fVec290[2];
	int iRec803[2];
	double fRec804[2];
	double fConst379;
	double fVec291[2];
	int iRec805[2];
	double fRec806[2];
	double fConst380;
	double fVec292[2];
	int iRec807[2];
	double fRec808[2];
	double fConst381;
	double fVec293[2];
	int iRec809[2];
	double fRec810[2];
	double fConst382;
	double fVec294[2];
	int iRec811[2];
	double fRec812[2];
	double fConst383;
	double fVec295[2];
	int iRec813[2];
	double fRec814[2];
	double fConst384;
	double fVec296[2];
	int iRec815[2];
	double fRec816[2];
	double fConst385;
	double fVec297[2];
	int iRec817[2];
	double fRec818[2];
	double fConst386;
	double fVec298[2];
	int iRec819[2];
	double fRec820[2];
	double fConst387;
	double fVec299[2];
	int iRec821[2];
	double fRec822[2];
	double fConst388;
	double fVec300[2];
	int iRec823[2];
	double fRec824[2];
	double fConst389;
	double fVec301[2];
	int iRec825[2];
	double fRec826[2];
	double fConst390;
	double fVec302[2];
	int iRec827[2];
	double fRec828[2];
	double fConst391;
	double fVec303[2];
	int iRec829[2];
	double fRec830[2];
	double fConst392;
	double fVec304[2];
	int iRec831[2];
	double fRec832[2];
	double fConst393;
	double fVec305[2];
	int iRec833[2];
	double fRec834[2];
	double fConst394;
	double fVec306[2];
	int iRec835[2];
	double fRec836[2];
	double fConst395;
	double fVec307[2];
	int iRec837[2];
	double fRec838[2];
	double fConst396;
	double fVec308[2];
	int iRec839[2];
	double fRec840[2];
	double fConst397;
	double fVec309[2];
	int iRec841[2];
	double fRec842[2];
	double fConst398;
	double fVec310[2];
	int iRec843[2];
	double fRec844[2];
	double fConst399;
	double fVec311[2];
	int iRec845[2];
	double fRec846[2];
	FAUSTFLOAT fHslider15;
	double fRec847[2];
	double fConst400;
	double fVec312[2];
	int iRec848[2];
	double fRec849[2];
	double fConst401;
	double fVec313[2];
	int iRec850[2];
	double fRec851[2];
	double fConst402;
	double fVec314[2];
	int iRec852[2];
	double fRec853[2];
	double fConst403;
	double fVec315[2];
	int iRec854[2];
	double fRec855[2];
	double fConst404;
	double fVec316[2];
	int iRec856[2];
	double fRec857[2];
	double fConst405;
	double fVec317[2];
	int iRec858[2];
	double fRec859[2];
	double fConst406;
	double fVec318[2];
	int iRec860[2];
	double fRec861[2];
	double fConst407;
	double fVec319[2];
	int iRec862[2];
	double fRec863[2];
	double fConst408;
	double fVec320[2];
	int iRec864[2];
	double fRec865[2];
	double fConst409;
	double fVec321[2];
	int iRec866[2];
	double fRec867[2];
	double fConst410;
	double fVec322[2];
	int iRec868[2];
	double fRec869[2];
	double fConst411;
	double fVec323[2];
	int iRec870[2];
	double fRec871[2];
	double fConst412;
	double fVec324[2];
	int iRec872[2];
	double fRec873[2];
	double fConst413;
	double fVec325[2];
	int iRec874[2];
	double fRec875[2];
	double fConst414;
	double fVec326[2];
	int iRec876[2];
	double fRec877[2];
	double fConst415;
	double fVec327[2];
	int iRec878[2];
	double fRec879[2];
	double fConst416;
	double fVec328[2];
	int iRec880[2];
	double fRec881[2];
	double fConst417;
	double fVec329[2];
	int iRec882[2];
	double fRec883[2];
	double fConst418;
	double fVec330[2];
	int iRec884[2];
	double fRec885[2];
	double fConst419;
	double fVec331[2];
	int iRec886[2];
	double fRec887[2];
	double fConst420;
	double fVec332[2];
	int iRec888[2];
	double fRec889[2];
	double fConst421;
	double fVec333[2];
	int iRec890[2];
	double fRec891[2];
	double fConst422;
	double fVec334[2];
	int iRec892[2];
	double fRec893[2];
	double fConst423;
	double fVec335[2];
	int iRec894[2];
	double fRec895[2];
	double fConst424;
	double fVec336[2];
	int iRec896[2];
	double fRec897[2];
	double fConst425;
	double fVec337[2];
	int iRec898[2];
	double fRec899[2];
	double fConst426;
	double fVec338[2];
	int iRec900[2];
	double fRec901[2];
	double fConst427;
	double fVec339[2];
	int iRec902[2];
	double fRec903[2];
	double fConst428;
	double fVec340[2];
	int iRec904[2];
	double fRec905[2];
	double fConst429;
	double fRec906[2];
	double fConst430;
	double fRec907[2];
	double fConst431;
	double fVec341[2];
	int iRec908[2];
	double fRec909[2];
	double fConst432;
	double fVec342[2];
	int iRec910[2];
	double fRec911[2];
	double fConst433;
	double fVec343[2];
	int iRec912[2];
	double fRec913[2];
	double fConst434;
	double fVec344[2];
	int iRec914[2];
	double fRec915[2];
	double fConst435;
	double fVec345[2];
	int iRec916[2];
	double fRec917[2];
	double fConst436;
	double fRec918[2];
	double fConst437;
	double fVec346[2];
	int iRec919[2];
	double fRec920[2];
	double fConst438;
	double fVec347[2];
	int iRec921[2];
	double fRec922[2];
	double fConst439;
	double fVec348[2];
	int iRec923[2];
	double fRec924[2];
	double fConst440;
	double fVec349[2];
	int iRec925[2];
	double fRec926[2];
	double fConst441;
	double fVec350[2];
	int iRec927[2];
	double fRec928[2];
	double fConst442;
	double fVec351[2];
	int iRec929[2];
	double fRec930[2];
	double fConst443;
	double fVec352[2];
	int iRec931[2];
	double fRec932[2];
	double fConst444;
	double fVec353[2];
	int iRec933[2];
	double fRec934[2];
	double fConst445;
	double fVec354[2];
	int iRec935[2];
	double fRec936[2];
	double fConst446;
	double fVec355[2];
	int iRec937[2];
	double fRec938[2];
	double fConst447;
	double fVec356[2];
	int iRec939[2];
	double fRec940[2];
	double fConst448;
	double fVec357[2];
	int iRec941[2];
	double fRec942[2];
	double fConst449;
	double fVec358[2];
	int iRec943[2];
	double fRec944[2];
	double fConst450;
	double fVec359[2];
	int iRec945[2];
	double fRec946[2];
	double fConst451;
	double fVec360[2];
	int iRec947[2];
	double fRec948[2];
	double fConst452;
	double fVec361[2];
	int iRec949[2];
	double fRec950[2];
	double fConst453;
	double fVec362[2];
	int iRec951[2];
	double fRec952[2];
	double fConst454;
	double fVec363[2];
	int iRec953[2];
	double fRec954[2];
	double fConst455;
	double fVec364[2];
	int iRec955[2];
	double fRec956[2];
	double fConst456;
	double fVec365[2];
	int iRec957[2];
	double fRec958[2];
	double fConst457;
	double fVec366[2];
	int iRec959[2];
	double fRec960[2];
	double fConst458;
	double fVec367[2];
	int iRec961[2];
	double fRec962[2];
	double fConst459;
	double fVec368[2];
	int iRec963[2];
	double fRec964[2];
	double fConst460;
	double fVec369[2];
	int iRec965[2];
	double fRec966[2];
	double fConst461;
	double fVec370[2];
	int iRec967[2];
	double fRec968[2];
	double fConst462;
	double fVec371[2];
	int iRec969[2];
	double fRec970[2];
	double fConst463;
	double fVec372[2];
	int iRec971[2];
	double fRec972[2];
	FAUSTFLOAT fHslider16;
	double fRec973[2];
	double fConst464;
	double fVec373[2];
	int iRec974[2];
	double fRec975[2];
	double fConst465;
	double fVec374[2];
	int iRec976[2];
	double fRec977[2];
	double fConst466;
	double fVec375[2];
	int iRec978[2];
	double fRec979[2];
	double fConst467;
	double fVec376[2];
	int iRec980[2];
	double fRec981[2];
	double fConst468;
	double fVec377[2];
	int iRec982[2];
	double fRec983[2];
	double fConst469;
	double fVec378[2];
	int iRec984[2];
	double fRec985[2];
	double fConst470;
	double fVec379[2];
	int iRec986[2];
	double fRec987[2];
	double fConst471;
	double fVec380[2];
	int iRec988[2];
	double fRec989[2];
	double fConst472;
	double fVec381[2];
	int iRec990[2];
	double fRec991[2];
	double fConst473;
	double fVec382[2];
	int iRec992[2];
	double fRec993[2];
	double fConst474;
	double fVec383[2];
	int iRec994[2];
	double fRec995[2];
	double fConst475;
	double fVec384[2];
	int iRec996[2];
	double fRec997[2];
	double fConst476;
	double fVec385[2];
	int iRec998[2];
	double fRec999[2];
	double fConst477;
	double fVec386[2];
	int iRec1000[2];
	double fRec1001[2];
	double fConst478;
	double fVec387[2];
	int iRec1002[2];
	double fRec1003[2];
	double fConst479;
	double fVec388[2];
	int iRec1004[2];
	double fRec1005[2];
	double fConst480;
	double fVec389[2];
	int iRec1006[2];
	double fRec1007[2];
	double fConst481;
	double fVec390[2];
	int iRec1008[2];
	double fRec1009[2];
	double fConst482;
	double fVec391[2];
	int iRec1010[2];
	double fRec1011[2];
	double fConst483;
	double fVec392[2];
	int iRec1012[2];
	double fRec1013[2];
	double fConst484;
	double fVec393[2];
	int iRec1014[2];
	double fRec1015[2];
	double fConst485;
	double fVec394[2];
	int iRec1016[2];
	double fRec1017[2];
	double fConst486;
	double fVec395[2];
	int iRec1018[2];
	double fRec1019[2];
	double fConst487;
	double fVec396[2];
	int iRec1020[2];
	double fRec1021[2];
	double fConst488;
	double fVec397[2];
	int iRec1022[2];
	double fRec1023[2];
	double fConst489;
	double fVec398[2];
	int iRec1024[2];
	double fRec1025[2];
	double fConst490;
	double fVec399[2];
	int iRec1026[2];
	double fRec1027[2];
	double fConst491;
	double fVec400[2];
	int iRec1028[2];
	double fRec1029[2];
	double fConst492;
	double fRec1030[2];
	double fConst493;
	double fVec401[2];
	int iRec1031[2];
	double fRec1032[2];
	double fConst494;
	double fVec402[2];
	int iRec1033[2];
	double fRec1034[2];
	double fConst495;
	double fRec1035[2];
	double fConst496;
	double fRec1036[2];
	double fConst497;
	double fVec403[2];
	int iRec1037[2];
	double fRec1038[2];
	double fConst498;
	double fVec404[2];
	int iRec1039[2];
	double fRec1040[2];
	double fConst499;
	double fVec405[2];
	int iRec1041[2];
	double fRec1042[2];
	double fConst500;
	double fVec406[2];
	int iRec1043[2];
	double fRec1044[2];
	double fConst501;
	double fRec1045[2];
	double fConst502;
	double fVec407[2];
	int iRec1046[2];
	double fRec1047[2];
	double fConst503;
	double fVec408[2];
	int iRec1048[2];
	double fRec1049[2];
	double fConst504;
	double fVec409[2];
	int iRec1050[2];
	double fRec1051[2];
	double fConst505;
	double fVec410[2];
	int iRec1052[2];
	double fRec1053[2];
	double fConst506;
	double fVec411[2];
	int iRec1054[2];
	double fRec1055[2];
	double fConst507;
	double fVec412[2];
	int iRec1056[2];
	double fRec1057[2];
	double fConst508;
	double fVec413[2];
	int iRec1058[2];
	double fRec1059[2];
	double fConst509;
	double fRec1060[2];
	double fConst510;
	double fVec414[2];
	int iRec1061[2];
	double fRec1062[2];
	double fConst511;
	double fVec415[2];
	int iRec1063[2];
	double fRec1064[2];
	double fConst512;
	double fRec1065[2];
	double fConst513;
	double fVec416[2];
	int iRec1066[2];
	double fRec1067[2];
	double fConst514;
	double fVec417[2];
	int iRec1068[2];
	double fRec1069[2];
	double fConst515;
	double fVec418[2];
	int iRec1070[2];
	double fRec1071[2];
	double fConst516;
	double fVec419[2];
	int iRec1072[2];
	double fRec1073[2];
	double fConst517;
	double fVec420[2];
	int iRec1074[2];
	double fRec1075[2];
	double fConst518;
	double fVec421[2];
	int iRec1076[2];
	double fRec1077[2];
	double fConst519;
	double fVec422[2];
	int iRec1078[2];
	double fRec1079[2];
	double fConst520;
	double fVec423[2];
	int iRec1080[2];
	double fRec1081[2];
	double fConst521;
	double fVec424[2];
	int iRec1082[2];
	double fRec1083[2];
	double fConst522;
	double fVec425[2];
	int iRec1084[2];
	double fRec1085[2];
	double fConst523;
	double fVec426[2];
	int iRec1086[2];
	double fRec1087[2];
	double fConst524;
	double fVec427[2];
	int iRec1088[2];
	double fRec1089[2];
	double fConst525;
	double fVec428[2];
	int iRec1090[2];
	double fRec1091[2];
	double fConst526;
	double fVec429[2];
	int iRec1092[2];
	double fRec1093[2];
	double fConst527;
	double fVec430[2];
	int iRec1094[2];
	double fRec1095[2];
	double fConst528;
	double fVec431[2];
	int iRec1096[2];
	double fRec1097[2];
	double fConst529;
	double fVec432[2];
	int iRec1098[2];
	double fRec1099[2];
	double fConst530;
	double fVec433[2];
	int iRec1100[2];
	double fRec1101[2];
	FAUSTFLOAT fHslider17;
	double fRec1102[2];
	double fConst531;
	double fVec434[2];
	int iRec1103[2];
	double fRec1104[2];
	double fConst532;
	double fVec435[2];
	int iRec1105[2];
	double fRec1106[2];
	double fConst533;
	double fVec436[2];
	int iRec1107[2];
	double fRec1108[2];
	double fConst534;
	double fVec437[2];
	int iRec1109[2];
	double fRec1110[2];
	double fConst535;
	double fVec438[2];
	int iRec1111[2];
	double fRec1112[2];
	double fConst536;
	double fVec439[2];
	int iRec1113[2];
	double fRec1114[2];
	double fConst537;
	double fVec440[2];
	int iRec1115[2];
	double fRec1116[2];
	double fConst538;
	double fVec441[2];
	int iRec1117[2];
	double fRec1118[2];
	double fConst539;
	double fVec442[2];
	int iRec1119[2];
	double fRec1120[2];
	double fConst540;
	double fVec443[2];
	int iRec1121[2];
	double fRec1122[2];
	double fConst541;
	double fVec444[2];
	int iRec1123[2];
	double fRec1124[2];
	double fConst542;
	double fVec445[2];
	int iRec1125[2];
	double fRec1126[2];
	double fConst543;
	double fVec446[2];
	int iRec1127[2];
	double fRec1128[2];
	double fConst544;
	double fVec447[2];
	int iRec1129[2];
	double fRec1130[2];
	double fConst545;
	double fVec448[2];
	int iRec1131[2];
	double fRec1132[2];
	double fConst546;
	double fVec449[2];
	int iRec1133[2];
	double fRec1134[2];
	double fConst547;
	double fVec450[2];
	int iRec1135[2];
	double fRec1136[2];
	double fConst548;
	double fVec451[2];
	int iRec1137[2];
	double fRec1138[2];
	double fConst549;
	double fVec452[2];
	int iRec1139[2];
	double fRec1140[2];
	double fConst550;
	double fVec453[2];
	int iRec1141[2];
	double fRec1142[2];
	double fConst551;
	double fVec454[2];
	int iRec1143[2];
	double fRec1144[2];
	double fConst552;
	double fVec455[2];
	int iRec1145[2];
	double fRec1146[2];
	double fConst553;
	double fVec456[2];
	int iRec1147[2];
	double fRec1148[2];
	double fConst554;
	double fVec457[2];
	int iRec1149[2];
	double fRec1150[2];
	double fConst555;
	double fVec458[2];
	int iRec1151[2];
	double fRec1152[2];
	double fConst556;
	double fVec459[2];
	int iRec1153[2];
	double fRec1154[2];
	double fConst557;
	double fVec460[2];
	int iRec1155[2];
	double fRec1156[2];
	double fConst558;
	double fVec461[2];
	int iRec1157[2];
	double fRec1158[2];
	double fConst559;
	double fVec462[2];
	int iRec1159[2];
	double fRec1160[2];
	double fConst560;
	double fVec463[2];
	int iRec1161[2];
	double fRec1162[2];
	double fConst561;
	double fVec464[2];
	int iRec1163[2];
	double fRec1164[2];
	double fConst562;
	double fVec465[2];
	int iRec1165[2];
	double fRec1166[2];
	double fConst563;
	double fVec466[2];
	int iRec1167[2];
	double fRec1168[2];
	double fConst564;
	double fVec467[2];
	int iRec1169[2];
	double fRec1170[2];
	double fConst565;
	double fVec468[2];
	int iRec1171[2];
	double fRec1172[2];
	double fConst566;
	double fVec469[2];
	int iRec1173[2];
	double fRec1174[2];
	double fConst567;
	double fVec470[2];
	int iRec1175[2];
	double fRec1176[2];
	double fConst568;
	double fVec471[2];
	int iRec1177[2];
	double fRec1178[2];
	double fConst569;
	double fVec472[2];
	int iRec1179[2];
	double fRec1180[2];
	double fConst570;
	double fVec473[2];
	int iRec1181[2];
	double fRec1182[2];
	double fConst571;
	double fVec474[2];
	int iRec1183[2];
	double fRec1184[2];
	double fConst572;
	double fVec475[2];
	int iRec1185[2];
	double fRec1186[2];
	double fConst573;
	double fVec476[2];
	int iRec1187[2];
	double fRec1188[2];
	double fConst574;
	double fVec477[2];
	int iRec1189[2];
	double fRec1190[2];
	double fConst575;
	double fVec478[2];
	int iRec1191[2];
	double fRec1192[2];
	double fConst576;
	double fVec479[2];
	int iRec1193[2];
	double fRec1194[2];
	double fConst577;
	double fVec480[2];
	int iRec1195[2];
	double fRec1196[2];
	double fConst578;
	double fVec481[2];
	int iRec1197[2];
	double fRec1198[2];
	double fConst579;
	double fVec482[2];
	int iRec1199[2];
	double fRec1200[2];
	double fConst580;
	double fVec483[2];
	int iRec1201[2];
	double fRec1202[2];
	double fConst581;
	double fVec484[2];
	int iRec1203[2];
	double fRec1204[2];
	double fConst582;
	double fVec485[2];
	int iRec1205[2];
	double fRec1206[2];
	double fConst583;
	double fVec486[2];
	int iRec1207[2];
	double fRec1208[2];
	double fConst584;
	double fVec487[2];
	int iRec1209[2];
	double fRec1210[2];
	double fConst585;
	double fVec488[2];
	int iRec1211[2];
	double fRec1212[2];
	double fConst586;
	double fVec489[2];
	int iRec1213[2];
	double fRec1214[2];
	double fConst587;
	double fVec490[2];
	int iRec1215[2];
	double fRec1216[2];
	double fConst588;
	double fVec491[2];
	int iRec1217[2];
	double fRec1218[2];
	double fConst589;
	double fVec492[2];
	int iRec1219[2];
	double fRec1220[2];
	double fConst590;
	double fVec493[2];
	int iRec1221[2];
	double fRec1222[2];
	double fConst591;
	double fVec494[2];
	int iRec1223[2];
	double fRec1224[2];
	FAUSTFLOAT fHslider18;
	double fRec1225[2];
	double fConst592;
	double fVec495[2];
	int iRec1226[2];
	double fRec1227[2];
	double fConst593;
	double fVec496[2];
	int iRec1228[2];
	double fRec1229[2];
	double fConst594;
	double fVec497[2];
	int iRec1230[2];
	double fRec1231[2];
	double fConst595;
	double fVec498[2];
	int iRec1232[2];
	double fRec1233[2];
	double fConst596;
	double fVec499[2];
	int iRec1234[2];
	double fRec1235[2];
	double fConst597;
	double fVec500[2];
	int iRec1236[2];
	double fRec1237[2];
	double fConst598;
	double fVec501[2];
	int iRec1238[2];
	double fRec1239[2];
	double fConst599;
	double fVec502[2];
	int iRec1240[2];
	double fRec1241[2];
	double fConst600;
	double fVec503[2];
	int iRec1242[2];
	double fRec1243[2];
	double fConst601;
	double fVec504[2];
	int iRec1244[2];
	double fRec1245[2];
	double fConst602;
	double fVec505[2];
	int iRec1246[2];
	double fRec1247[2];
	double fConst603;
	double fVec506[2];
	int iRec1248[2];
	double fRec1249[2];
	double fConst604;
	double fVec507[2];
	int iRec1250[2];
	double fRec1251[2];
	double fConst605;
	double fVec508[2];
	int iRec1252[2];
	double fRec1253[2];
	double fConst606;
	double fVec509[2];
	int iRec1254[2];
	double fRec1255[2];
	double fConst607;
	double fVec510[2];
	int iRec1256[2];
	double fRec1257[2];
	double fConst608;
	double fVec511[2];
	int iRec1258[2];
	double fRec1259[2];
	double fConst609;
	double fVec512[2];
	int iRec1260[2];
	double fRec1261[2];
	double fConst610;
	double fVec513[2];
	int iRec1262[2];
	double fRec1263[2];
	double fConst611;
	double fVec514[2];
	int iRec1264[2];
	double fRec1265[2];
	double fConst612;
	double fVec515[2];
	int iRec1266[2];
	double fRec1267[2];
	double fConst613;
	double fVec516[2];
	int iRec1268[2];
	double fRec1269[2];
	double fConst614;
	double fRec1270[2];
	double fConst615;
	double fVec517[2];
	int iRec1271[2];
	double fRec1272[2];
	double fConst616;
	double fVec518[2];
	int iRec1273[2];
	double fRec1274[2];
	double fConst617;
	double fVec519[2];
	int iRec1275[2];
	double fRec1276[2];
	double fConst618;
	double fVec520[2];
	int iRec1277[2];
	double fRec1278[2];
	double fConst619;
	double fVec521[2];
	int iRec1279[2];
	double fRec1280[2];
	double fConst620;
	double fVec522[2];
	int iRec1281[2];
	double fRec1282[2];
	double fConst621;
	double fVec523[2];
	int iRec1283[2];
	double fRec1284[2];
	double fConst622;
	double fVec524[2];
	int iRec1285[2];
	double fRec1286[2];
	double fConst623;
	double fVec525[2];
	int iRec1287[2];
	double fRec1288[2];
	double fConst624;
	double fVec526[2];
	int iRec1289[2];
	double fRec1290[2];
	double fConst625;
	double fVec527[2];
	int iRec1291[2];
	double fRec1292[2];
	double fConst626;
	double fVec528[2];
	int iRec1293[2];
	double fRec1294[2];
	double fConst627;
	double fVec529[2];
	int iRec1295[2];
	double fRec1296[2];
	double fConst628;
	double fVec530[2];
	int iRec1297[2];
	double fRec1298[2];
	double fConst629;
	double fVec531[2];
	int iRec1299[2];
	double fRec1300[2];
	double fConst630;
	double fVec532[2];
	int iRec1301[2];
	double fRec1302[2];
	double fConst631;
	double fVec533[2];
	int iRec1303[2];
	double fRec1304[2];
	double fConst632;
	double fVec534[2];
	int iRec1305[2];
	double fRec1306[2];
	double fConst633;
	double fVec535[2];
	int iRec1307[2];
	double fRec1308[2];
	double fConst634;
	double fVec536[2];
	int iRec1309[2];
	double fRec1310[2];
	double fConst635;
	double fVec537[2];
	int iRec1311[2];
	double fRec1312[2];
	double fConst636;
	double fVec538[2];
	int iRec1313[2];
	double fRec1314[2];
	double fConst637;
	double fVec539[2];
	int iRec1315[2];
	double fRec1316[2];
	double fConst638;
	double fVec540[2];
	int iRec1317[2];
	double fRec1318[2];
	double fConst639;
	double fVec541[2];
	int iRec1319[2];
	double fRec1320[2];
	double fConst640;
	double fVec542[2];
	int iRec1321[2];
	double fRec1322[2];
	double fConst641;
	double fVec543[2];
	int iRec1323[2];
	double fRec1324[2];
	double fConst642;
	double fVec544[2];
	int iRec1325[2];
	double fRec1326[2];
	double fConst643;
	double fVec545[2];
	int iRec1327[2];
	double fRec1328[2];
	double fConst644;
	double fVec546[2];
	int iRec1329[2];
	double fRec1330[2];
	double fConst645;
	double fVec547[2];
	int iRec1331[2];
	double fRec1332[2];
	double fConst646;
	double fVec548[2];
	int iRec1333[2];
	double fRec1334[2];
	double fConst647;
	double fVec549[2];
	int iRec1335[2];
	double fRec1336[2];
	double fConst648;
	double fVec550[2];
	int iRec1337[2];
	double fRec1338[2];
	double fConst649;
	double fVec551[2];
	int iRec1339[2];
	double fRec1340[2];
	double fConst650;
	double fVec552[2];
	int iRec1341[2];
	double fRec1342[2];
	double fConst651;
	double fVec553[2];
	int iRec1343[2];
	double fRec1344[2];
	double fConst652;
	double fVec554[2];
	int iRec1345[2];
	double fRec1346[2];
	double fConst653;
	double fVec555[2];
	int iRec1347[2];
	double fRec1348[2];
	FAUSTFLOAT fHslider19;
	double fRec1349[2];
	FAUSTFLOAT fCheckbox1;
	double fRec1350[2];
	FAUSTFLOAT fCheckbox2;
	double fRec1351[2];
	FAUSTFLOAT fCheckbox3;
	double fRec1352[2];
	FAUSTFLOAT fCheckbox4;
	double fConst654;
	int iVec556[2];
	double fRec1353[2];
	FAUSTFLOAT fCheckbox5;
	double fRec1354[2];
	FAUSTFLOAT fHslider20;
	double fRec1355[2];
	FAUSTFLOAT fHslider21;
	double fRec1356[2];
	FAUSTFLOAT fHslider22;
	double fRec1357[2];
	FAUSTFLOAT fHslider23;
	double fRec1358[2];
	FAUSTFLOAT fHslider24;
	double fRec1359[2];
	FAUSTFLOAT fHslider25;
	double fRec1360[2];
	FAUSTFLOAT fHslider26;
	double fRec1361[2];
	FAUSTFLOAT fHslider27;
	double fRec1362[2];
	FAUSTFLOAT fHslider28;
	double fRec1363[2];
	double fVec557[1024];
	FAUSTFLOAT fHslider29;
	double fRec1364[2];
	double fRec1365[2];
	double fConst655;
	double fRec1368[2];
	double fVec558[2];
	double fConst657;
	double fConst658;
	double fRec1367[2];
	double fRec1369[2];
	double fVec559[2];
	double fConst660;
	double fConst661;
	double fRec1366[2];
	FAUSTFLOAT fButton65;
	double fVec560[2];
	int iRec1370[2];
	double fRec1371[2];
	FAUSTFLOAT fButton66;
	double fVec561[2];
	int iRec1372[2];
	double fRec1373[2];
	FAUSTFLOAT fButton67;
	double fVec562[2];
	int iRec1374[2];
	double fRec1375[2];
	FAUSTFLOAT fButton68;
	double fVec563[2];
	int iRec1376[2];
	double fRec1377[2];
	FAUSTFLOAT fButton69;
	double fVec564[2];
	int iRec1378[2];
	double fRec1379[2];
	FAUSTFLOAT fButton70;
	double fVec565[2];
	int iRec1380[2];
	double fRec1381[2];
	FAUSTFLOAT fButton71;
	double fVec566[2];
	int iRec1382[2];
	double fRec1383[2];
	FAUSTFLOAT fButton72;
	double fVec567[2];
	int iRec1384[2];
	double fRec1385[2];
	FAUSTFLOAT fButton73;
	double fVec568[2];
	int iRec1386[2];
	double fRec1387[2];
	FAUSTFLOAT fButton74;
	double fVec569[2];
	int iRec1388[2];
	double fRec1389[2];
	FAUSTFLOAT fButton75;
	double fVec570[2];
	int iRec1390[2];
	double fRec1391[2];
	FAUSTFLOAT fButton76;
	double fVec571[2];
	int iRec1392[2];
	double fRec1393[2];
	FAUSTFLOAT fButton77;
	double fVec572[2];
	int iRec1394[2];
	double fRec1395[2];
	FAUSTFLOAT fButton78;
	double fVec573[2];
	int iRec1396[2];
	double fRec1397[2];
	FAUSTFLOAT fButton79;
	double fVec574[2];
	int iRec1398[2];
	double fRec1399[2];
	FAUSTFLOAT fButton80;
	double fVec575[2];
	int iRec1400[2];
	double fRec1401[2];
	FAUSTFLOAT fButton81;
	double fVec576[2];
	int iRec1402[2];
	double fRec1403[2];
	FAUSTFLOAT fButton82;
	double fVec577[2];
	int iRec1404[2];
	double fRec1405[2];
	FAUSTFLOAT fButton83;
	double fVec578[2];
	int iRec1406[2];
	double fRec1407[2];
	FAUSTFLOAT fButton84;
	double fVec579[2];
	int iRec1408[2];
	double fRec1409[2];
	FAUSTFLOAT fButton85;
	double fVec580[2];
	int iRec1410[2];
	double fRec1411[2];
	double fVec581[2];
	double fVec582[2];
	double fRec16[2];
	double fConst662;
	double fConst664;
	double fRec10[2];
	double fConst665;
	double fRec11[2];
	double fConst666;
	double fRec6[2];
	double fRec7[2];
	double fConst667;
	double fConst669;
	double fRec1412[2];
	double fConst670;
	double fRec1413[2];
	double fConst671;
	double fVec583[1024];
	double fRec3[2];
	double fRec4[2];
	double fConst672;
	double fConst673;
	double fRec1416[2];
	double fRec1415[2];
	double fRec1425[2];
	double fRec1426[2];
	double fConst674;
	double fConst676;
	double fRec1421[2];
	double fConst677;
	double fRec1422[2];
	double fConst678;
	double fRec1417[2];
	double fRec1418[2];
	double fRec1428[2];
	double fRec1429[2];
	double fRec1431[2];
	double fRec1432[2];
	double fRec1434[2];
	double fRec1435[2];
	FAUSTFLOAT fHslider30;
	double fRec1437[2];
	double fRec1438[2];
	double fRec1439[2];
	double fRec1441[2];
	double fRec1442[2];
	double fRec1444[2];
	double fRec1445[2];
	
 public:
	Tonewheel() {}

	void metadata(Meta* m) { 
		m->declare("aanl.lib/ADAA1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/ADAA1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/ADAA1:license", "LGPL v3.0 license");
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/tanh1:author", "Dario Sanfilippo");
		m->declare("aanl.lib/tanh1:copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl.lib/tanh1:license", "LGPL v3.0 license");
		m->declare("aanl.lib/version", "1.3.0");
		m->declare("author", "Oberli Audio");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.12.0");
		m->declare("compile_options", "-a ../harness/arch.cpp -lang cpp -ct 1 -cn Tonewheel -es 1 -mcd 16 -mdd 1024 -mdy 33 -double -ftz 0");
		m->declare("delays.lib/fdelay3:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "tonewheel.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpassLR4:author", "Dario Sanfilippo");
		m->declare("filters.lib/highpassLR4:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("filters.lib/highpassLR4:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpassLR4:author", "Dario Sanfilippo");
		m->declare("filters.lib/lowpassLR4:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("filters.lib/lowpassLR4:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.7.0");
		m->declare("name", "Oberli Tonewheel (sketch)");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw1:author", "Bart Brouns");
		m->declare("oscillators.lib/saw1:licence", "STK-4.3");
		m->declare("oscillators.lib/version", "1.5.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "1.5.0");
		m->declare("version", "0.0.3");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		TonewheelSIG0* sig0 = newTonewheelSIG0();
		sig0->instanceInitTonewheelSIG0(sample_rate);
		sig0->fillTonewheelSIG0(65536, ftbl0TonewheelSIG0);
		TonewheelSIG1* sig1 = newTonewheelSIG1();
		sig1->instanceInitTonewheelSIG1(sample_rate);
		sig1->fillTonewheelSIG1(65536, ftbl1TonewheelSIG1);
		deleteTonewheelSIG0(sig0);
		deleteTonewheelSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = std::exp(-(1.8181818181818181 / fConst0));
		fConst2 = std::exp(-(2.857142857142857 / fConst0));
		fConst3 = 1.0 / fConst0;
		fConst4 = std::exp(-(2e+01 / fConst0));
		fConst5 = 0.017453292519943295 * (1.0 - fConst4);
		fConst6 = 3.141592653589793 / fConst0;
		fConst7 = std::exp(-(5e+01 / fConst0));
		fConst8 = 1.0 - fConst7;
		fConst9 = 196.0 / fConst0;
		fConst10 = std::exp(-(66.66666666666667 / fConst0));
		fConst11 = 1.0 - fConst10;
		fConst12 = 98.0 / fConst0;
		fConst13 = 1.0 / std::max<double>(1.0, 0.002 * fConst0);
		fConst14 = 123.42857142857143 / fConst0;
		fConst15 = 61.714285714285715 / fConst0;
		fConst16 = 49.0 / fConst0;
		fConst17 = 65.38461538461539 / fConst0;
		fConst18 = 32.69230769230769 / fConst0;
		fConst19 = 987.4285714285714 / fConst0;
		fConst20 = 3949.714285714286 / fConst0;
		fConst21 = 0.0005167610332955519 * fConst0;
		fConst22 = std::exp(-(1e+02 / fConst0));
		fConst23 = 1.0 - fConst22;
		fConst24 = 0.0002205683279898949 * fConst0;
		fConst25 = 4699.178082191781 / fConst0;
		fConst26 = 2349.5890410958905 / fConst0;
		fConst27 = 0.0039547513837751465 * fConst0;
		fConst28 = 466.0869565217391 / fConst0;
		fConst29 = 1864.3478260869565 / fConst0;
		fConst30 = 0.001234144873196783 * fConst0;
		fConst31 = 4184.615384615385 / fConst0;
		fConst32 = 1046.1538461538462 / fConst0;
		fConst33 = 0.001047345749582746 * fConst0;
		fConst34 = 3728.695652173913 / fConst0;
		fConst35 = 932.1739130434783 / fConst0;
		fConst36 = 0.0024606448926351734 * fConst0;
		fConst37 = 3.52e+03 / fConst0;
		fConst38 = 1.76e+03 / fConst0;
		fConst39 = 0.0033236140964727386 * fConst0;
		fConst40 = 5273.6 / fConst0;
		fConst41 = 1318.4 / fConst0;
		fConst42 = 0.00270431364455726 * fConst0;
		fConst43 = 0.0031920052779314573 * fConst0;
		fConst44 = 3136.0 / fConst0;
		fConst45 = 0.0035457576590561075 * fConst0;
		fConst46 = 4.4e+02 / fConst0;
		fConst47 = 0.002754716523064417 * fConst0;
		fConst48 = 261.53846153846155 / fConst0;
		fConst49 = 2092.3076923076924 / fConst0;
		fConst50 = 0.0025962755550572184 * fConst0;
		fConst51 = 8.8e+02 / fConst0;
		fConst52 = 2.2e+02 / fConst0;
		fConst53 = 0.00013482408657728229 * fConst0;
		fConst54 = 784.0 / fConst0;
		fConst55 = 1568.0 / fConst0;
		fConst56 = 0.0017891873018379557 * fConst0;
		fConst57 = 3.7e+02 / fConst0;
		fConst58 = 2.96e+03 / fConst0;
		fConst59 = 7.4e+02 / fConst0;
		fConst60 = 0.0030431816763593815 * fConst0;
		fConst61 = 698.1818181818181 / fConst0;
		fConst62 = 2792.7272727272725 / fConst0;
		fConst63 = 0.001065483629819937 * fConst0;
		fConst64 = 554.1463414634146 / fConst0;
		fConst65 = 138.53658536585365 / fConst0;
		fConst66 = 2216.5853658536585 / fConst0;
		fConst67 = 0.0030910958941531134 * fConst0;
		fConst68 = 523.0769230769231 / fConst0;
		fConst69 = 0.0029170824782686396 * fConst0;
		fConst70 = 587.3972602739726 / fConst0;
		fConst71 = 293.6986301369863 / fConst0;
		fConst72 = 146.84931506849315 / fConst0;
		fConst73 = 0.00398544471184141 * fConst0;
		fConst74 = 659.2 / fConst0;
		fConst75 = 2636.8 / fConst0;
		fConst76 = 0.0010833050514629577 * fConst0;
		fConst77 = 622.2222222222222 / fConst0;
		fConst78 = 1244.4444444444443 / fConst0;
		fConst79 = 155.55555555555554 / fConst0;
		fConst80 = 0.0032644345470471308 * fConst0;
		fConst81 = 830.2702702702703 / fConst0;
		fConst82 = 1660.5405405405406 / fConst0;
		fConst83 = 415.13513513513516 / fConst0;
		fConst84 = 0.002877673320188478 * fConst0;
		fConst85 = 0.0013705559573718347 * fConst0;
		fConst86 = 1974.857142857143 / fConst0;
		fConst87 = 493.7142857142857 / fConst0;
		fConst88 = 0.003369996869470924 * fConst0;
		fConst89 = 1108.2926829268292 / fConst0;
		fConst90 = 0.003269652874208987 * fConst0;
		fConst91 = 1174.7945205479452 / fConst0;
		fConst92 = 0.0010919996577431449 * fConst0;
		fConst93 = 0.0032191907185842865 * fConst0;
		fConst94 = 329.6 / fConst0;
		fConst95 = 0.003061195766655146 * fConst0;
		fConst96 = 1396.3636363636363 / fConst0;
		fConst97 = 0.0029135751349385827 * fConst0;
		fConst98 = 5.92e+03 / fConst0;
		fConst99 = 1.48e+03 / fConst0;
		fConst100 = 0.0007905957648181356 * fConst0;
		fConst101 = 392.0 / fConst0;
		fConst102 = 0.0017729478206601926 * fConst0;
		fConst103 = 0.002951280225941446 * fConst0;
		fConst104 = 0.0014359184715285664 * fConst0;
		fConst105 = 0.0023965897164453056 * fConst0;
		fConst106 = 4433.170731707317 / fConst0;
		fConst107 = 0.0027587749185040596 * fConst0;
		fConst108 = 0.0038931295854272322 * fConst0;
		fConst109 = 2488.8888888888887 / fConst0;
		fConst110 = 0.0017918210133793765 * fConst0;
		fConst111 = 0.0005033260781492573 * fConst0;
		fConst112 = 0.000692323880692129 * fConst0;
		fConst113 = 0.002627390943292994 * fConst0;
		fConst114 = 3321.0810810810813 / fConst0;
		fConst115 = 0.002663167956110556 * fConst0;
		fConst116 = 0.0012268411756958812 * fConst0;
		fConst117 = 0.0025244841811945663 * fConst0;
		fConst118 = 0.0038553880917752397 * fConst0;
		fConst119 = 0.001937954139323665 * fConst0;
		fConst120 = 4977.777777777777 / fConst0;
		fConst121 = 0.0017295537222234997 * fConst0;
		fConst122 = 0.0002741083253204124 * fConst0;
		fConst123 = 0.00036604717327281834 * fConst0;
		fConst124 = 5585.454545454545 / fConst0;
		fConst125 = 0.0017617114507302177 * fConst0;
		fConst126 = 0.0013870983488741332 * fConst0;
		fConst127 = 0.0009593989308632444 * fConst0;
		fConst128 = 0.0035891702719200113 * fConst0;
		fConst129 = 0.003910780031881586 * fConst0;
		fConst130 = 0.002479190481331898 * fConst0;
		fConst131 = 0.0030735101129394024 * fConst0;
		fConst132 = 0.003015397130366182 * fConst0;
		fConst133 = 0.003671891283876903 * fConst0;
		fConst134 = 0.0036797505689464744 * fConst0;
		fConst135 = 0.001216112374648219 * fConst0;
		fConst136 = 0.0006471274717478082 * fConst0;
		fConst137 = 0.0035112578120315447 * fConst0;
		fConst138 = 0.0021702410137440895 * fConst0;
		fConst139 = 0.002037300020951079 * fConst0;
		fConst140 = 0.0030410771146707704 * fConst0;
		fConst141 = 0.00027025447793857895 * fConst0;
		fConst142 = 0.0038649083492928184 * fConst0;
		fConst143 = 0.001921603293012595 * fConst0;
		fConst144 = 0.0012936557553184685 * fConst0;
		fConst145 = 0.0038996516849001636 * fConst0;
		fConst146 = 0.0015115700727910736 * fConst0;
		fConst147 = 0.00046747605830751125 * fConst0;
		fConst148 = 185.0 / fConst0;
		fConst149 = 0.001167133032955462 * fConst0;
		fConst150 = 174.54545454545453 / fConst0;
		fConst151 = 0.0030854661937919445 * fConst0;
		fConst152 = 164.8 / fConst0;
		fConst153 = 0.0013330653042939958 * fConst0;
		fConst154 = 0.0015971272469760152 * fConst0;
		fConst155 = 0.001286959877375921 * fConst0;
		fConst156 = 0.0023650674932287077 * fConst0;
		fConst157 = 246.85714285714286 / fConst0;
		fConst158 = 0.0004296493350993842 * fConst0;
		fConst159 = 0.0016610863496898673 * fConst0;
		fConst160 = 0.003679829021501064 * fConst0;
		fConst161 = 207.56756756756758 / fConst0;
		fConst162 = 0.0011418717877386372 * fConst0;
		fConst163 = 0.002122683608082298 * fConst0;
		fConst164 = 0.0032935435354884248 * fConst0;
		fConst165 = 0.0033383771157969025 * fConst0;
		fConst166 = 0.0039425879119817184 * fConst0;
		fConst167 = 233.04347826086956 / fConst0;
		fConst168 = 0.0015063066912116483 * fConst0;
		fConst169 = 0.0013247471716604196 * fConst0;
		fConst170 = 0.0005443899617239368 * fConst0;
		fConst171 = 0.000886572737043025 * fConst0;
		fConst172 = 0.002957865136762848 * fConst0;
		fConst173 = 0.0003922295904485509 * fConst0;
		fConst174 = 1.1938368395931321e-05 * fConst0;
		fConst175 = 0.0026955311812416768 * fConst0;
		fConst176 = 0.002939439325564308 * fConst0;
		fConst177 = 0.001884543353226036 * fConst0;
		fConst178 = 0.002461359657958383 * fConst0;
		fConst179 = 0.0017161645553715062 * fConst0;
		fConst180 = 0.0023679494469688507 * fConst0;
		fConst181 = 0.003740744127177095 * fConst0;
		fConst182 = 0.0018779630712233485 * fConst0;
		fConst183 = 0.0014632158691238147 * fConst0;
		fConst184 = 0.0030184080417384393 * fConst0;
		fConst185 = 0.003849877411936177 * fConst0;
		fConst186 = 0.0024749002575845227 * fConst0;
		fConst187 = 0.002897870146416608 * fConst0;
		fConst188 = 0.0014084166246902897 * fConst0;
		fConst189 = 0.0018708887963875896 * fConst0;
		fConst190 = 0.0033461838205403184 * fConst0;
		fConst191 = 0.0029963421820721125 * fConst0;
		fConst192 = 0.003172487923540757 * fConst0;
		fConst193 = 0.0018140504288021476 * fConst0;
		fConst194 = 0.0035750948669920034 * fConst0;
		fConst195 = 0.003521988619264448 * fConst0;
		fConst196 = 0.0003442084415291902 * fConst0;
		fConst197 = 0.0032438439957913944 * fConst0;
		fConst198 = 0.0037898500224982853 * fConst0;
		fConst199 = 0.0019871332639595494 * fConst0;
		fConst200 = 0.002769144075224176 * fConst0;
		fConst201 = 0.0002724506063386798 * fConst0;
		fConst202 = 0.0011819844734545768 * fConst0;
		fConst203 = 0.0033198981726454803 * fConst0;
		fConst204 = 0.0006148204318305944 * fConst0;
		fConst205 = 5.947113908041502e-05 * fConst0;
		fConst206 = 0.002342514919771929 * fConst0;
		fConst207 = 0.001058233395277057 * fConst0;
		fConst208 = 0.00339075615008187 * fConst0;
		fConst209 = 0.0017444164348999038 * fConst0;
		fConst210 = 0.0021556120464083506 * fConst0;
		fConst211 = 0.0019048534659086727 * fConst0;
		fConst212 = 0.0019533308696118184 * fConst0;
		fConst213 = 0.003239761072793044 * fConst0;
		fConst214 = 0.003410935872965638 * fConst0;
		fConst215 = 0.0033680500179034427 * fConst0;
		fConst216 = 0.0030500225180148848 * fConst0;
		fConst217 = 0.0023918052442750194 * fConst0;
		fConst218 = 277.0731707317073 / fConst0;
		fConst219 = 0.0009182455766858766 * fConst0;
		fConst220 = 0.00394657613398158 * fConst0;
		fConst221 = 0.003325374031948741 * fConst0;
		fConst222 = 0.002946099184860941 * fConst0;
		fConst223 = 0.003989410445850808 * fConst0;
		fConst224 = 0.0020277746209467298 * fConst0;
		fConst225 = 0.0026036298076651293 * fConst0;
		fConst226 = 0.0008571446617424954 * fConst0;
		fConst227 = 0.0004979321061455266 * fConst0;
		fConst228 = 0.00197736006352352 * fConst0;
		fConst229 = 0.0009305134135356638 * fConst0;
		fConst230 = 0.0024475413635664154 * fConst0;
		fConst231 = 0.003491030647797743 * fConst0;
		fConst232 = 0.0002712363976097549 * fConst0;
		fConst233 = 7.038521446520463e-05 * fConst0;
		fConst234 = 0.0009288329796399922 * fConst0;
		fConst235 = 349.09090909090907 / fConst0;
		fConst236 = 0.0038928659642406276 * fConst0;
		fConst237 = 0.0013380982055095957 * fConst0;
		fConst238 = 0.0008120474416355137 * fConst0;
		fConst239 = 130.76923076923077 / fConst0;
		fConst240 = 0.002214766777760815 * fConst0;
		fConst241 = 0.0003076647697889712 * fConst0;
		fConst242 = 311.1111111111111 / fConst0;
		fConst243 = 0.0037738321006472687 * fConst0;
		fConst244 = 0.0027010363009467254 * fConst0;
		fConst245 = 0.0032651602910773363 * fConst0;
		fConst246 = 1.4659481355920435e-05 * fConst0;
		fConst247 = 0.003722678854421247 * fConst0;
		fConst248 = 0.0034567460327107257 * fConst0;
		fConst249 = 0.0033445667749474523 * fConst0;
		fConst250 = 0.0026599928148352773 * fConst0;
		fConst251 = 0.00145121841688524 * fConst0;
		fConst252 = 0.0018999686119204853 * fConst0;
		fConst253 = 0.0012352318729099351 * fConst0;
		fConst254 = 0.00035902707198692954 * fConst0;
		fConst255 = 0.0022163523400740813 * fConst0;
		fConst256 = 0.00012795593870396261 * fConst0;
		fConst257 = 0.002910517639887985 * fConst0;
		fConst258 = 0.002656774412287632 * fConst0;
		fConst259 = 7.063919934444129e-05 * fConst0;
		fConst260 = 0.003991900311448262 * fConst0;
		fConst261 = 0.0013254432095127413 * fConst0;
		fConst262 = 0.0034361506949180695 * fConst0;
		fConst263 = 0.0006816236176236998 * fConst0;
		fConst264 = 0.0016507777766382788 * fConst0;
		fConst265 = 0.002902363083063392 * fConst0;
		fConst266 = 0.0016691046649939382 * fConst0;
		fConst267 = 0.0032462602521118244 * fConst0;
		fConst268 = 0.003594845107247238 * fConst0;
		fConst269 = 0.003164548065076815 * fConst0;
		fConst270 = 0.0006739630438678432 * fConst0;
		fConst271 = 0.000588477683311794 * fConst0;
		fConst272 = 0.001739128953224281 * fConst0;
		fConst273 = 0.0027022906296915606 * fConst0;
		fConst274 = 0.002635796960181324 * fConst0;
		fConst275 = 0.002990261915127576 * fConst0;
		fConst276 = 8.779258686990943e-05 * fConst0;
		fConst277 = 0.0037497717626101806 * fConst0;
		fConst278 = 0.0005890509546734393 * fConst0;
		fConst279 = 0.0031905969053914306 * fConst0;
		fConst280 = 0.002700292354275007 * fConst0;
		fConst281 = 0.000868511302684965 * fConst0;
		fConst282 = 0.002780912987975171 * fConst0;
		fConst283 = 0.002263619958423078 * fConst0;
		fConst284 = 0.003628109537487035 * fConst0;
		fConst285 = 0.002114024775371945 * fConst0;
		fConst286 = 0.00039950006068102087 * fConst0;
		fConst287 = 0.0036598732876300345 * fConst0;
		fConst288 = 0.003740745061339112 * fConst0;
		fConst289 = 103.78378378378379 / fConst0;
		fConst290 = 0.003356458859547274 * fConst0;
		fConst291 = 0.0002283034611173207 * fConst0;
		fConst292 = 92.5 / fConst0;
		fConst293 = 0.002984455072786659 * fConst0;
		fConst294 = 87.27272727272727 / fConst0;
		fConst295 = 0.0015154227540924695 * fConst0;
		fConst296 = 0.003163684652579832 * fConst0;
		fConst297 = 69.26829268292683 / fConst0;
		fConst298 = 0.0004307481319119688 * fConst0;
		fConst299 = 0.0036170321825193244 * fConst0;
		fConst300 = 0.0004887465074425564 * fConst0;
		fConst301 = 0.0021659621295693795 * fConst0;
		fConst302 = 0.0033133646578062327 * fConst0;
		fConst303 = 0.002889506001549307 * fConst0;
		fConst304 = 0.003932088717599981 * fConst0;
		fConst305 = 0.0002943784645467531 * fConst0;
		fConst306 = 0.002502300405933056 * fConst0;
		fConst307 = 0.003034995846799575 * fConst0;
		fConst308 = 0.002048762348975288 * fConst0;
		fConst309 = 0.0007035049505939242 * fConst0;
		fConst310 = 0.0012671400496474235 * fConst0;
		fConst311 = 0.0011158079797169195 * fConst0;
		fConst312 = 0.00010277698098798283 * fConst0;
		fConst313 = 0.0009556462575856131 * fConst0;
		fConst314 = 0.0011094802899751812 * fConst0;
		fConst315 = 0.0016878651073056973 * fConst0;
		fConst316 = 0.0020093004103182467 * fConst0;
		fConst317 = 0.0029351388944378414 * fConst0;
		fConst318 = 0.0037304078029992524 * fConst0;
		fConst319 = 0.00037599450105335564 * fConst0;
		fConst320 = 0.0019075965430238285 * fConst0;
		fConst321 = 0.0015014066351868678 * fConst0;
		fConst322 = 0.0020057314877194587 * fConst0;
		fConst323 = 0.002672332844864286 * fConst0;
		fConst324 = 0.00038891951259574856 * fConst0;
		fConst325 = 0.0011530927675485146 * fConst0;
		fConst326 = 0.00011336313028004952 * fConst0;
		fConst327 = 5.913021913147531e-05 * fConst0;
		fConst328 = 0.0023001746042136803 * fConst0;
		fConst329 = 0.0016185779779116275 * fConst0;
		fConst330 = 0.0031985143251185948 * fConst0;
		fConst331 = 0.003155201939793187 * fConst0;
		fConst332 = 0.003155980692827143 * fConst0;
		fConst333 = 0.0002120876790722832 * fConst0;
		fConst334 = 0.0031924149166443387 * fConst0;
		fConst335 = 0.0014413664427847834 * fConst0;
		fConst336 = 0.003342160813335795 * fConst0;
		fConst337 = 0.003899787775560981 * fConst0;
		fConst338 = 0.0025651064214180226 * fConst0;
		fConst339 = 0.0007314411671104609 * fConst0;
		fConst340 = 0.0030893094160419424 * fConst0;
		fConst341 = 0.001835674090194516 * fConst0;
		fConst342 = 0.003607071621634532 * fConst0;
		fConst343 = 0.00029066172905731945 * fConst0;
		fConst344 = 0.0024834805453720038 * fConst0;
		fConst345 = 0.0008047218689753208 * fConst0;
		fConst346 = 0.0008275284256669692 * fConst0;
		fConst347 = 0.003559214006163529 * fConst0;
		fConst348 = 0.0023303950482659276 * fConst0;
		fConst349 = 0.003761746417756513 * fConst0;
		fConst350 = 0.0027234964800300077 * fConst0;
		fConst351 = 0.0035458832508302295 * fConst0;
		fConst352 = 0.0012757117087894585 * fConst0;
		fConst353 = 0.001966574662248604 * fConst0;
		fConst354 = 0.00351477929406974 * fConst0;
		fConst355 = 0.003377009549498325 * fConst0;
		fConst356 = 0.0016682678188662977 * fConst0;
		fConst357 = 0.0003432467361635645 * fConst0;
		fConst358 = 0.0032901736690728284 * fConst0;
		fConst359 = 116.52173913043478 / fConst0;
		fConst360 = 9.074479893024546e-05 * fConst0;
		fConst361 = 0.0001430669659166597 * fConst0;
		fConst362 = 51.891891891891895 / fConst0;
		fConst363 = 0.003263288296322571 * fConst0;
		fConst364 = 0.0010391554239176913 * fConst0;
		fConst365 = 73.42465753424658 / fConst0;
		fConst366 = 0.0005708639260556083 * fConst0;
		fConst367 = 77.77777777777777 / fConst0;
		fConst368 = 0.002678808989294339 * fConst0;
		fConst369 = 0.002956125833123224 * fConst0;
		fConst370 = 0.002792176095681498 * fConst0;
		fConst371 = 0.0032261350593726095 * fConst0;
		fConst372 = 0.00337030848224822 * fConst0;
		fConst373 = 0.0009997337887180037 * fConst0;
		fConst374 = 0.0013702611089393031 * fConst0;
		fConst375 = 0.0024931885480182245 * fConst0;
		fConst376 = 0.0023163380736368707 * fConst0;
		fConst377 = 0.0005010531743885168 * fConst0;
		fConst378 = 0.0010220020335400476 * fConst0;
		fConst379 = 0.0038457939892832657 * fConst0;
		fConst380 = 0.00392636316845892 * fConst0;
		fConst381 = 0.0005849294597283005 * fConst0;
		fConst382 = 0.0036026589488610625 * fConst0;
		fConst383 = 0.0015140161382587395 * fConst0;
		fConst384 = 0.0011114851035672474 * fConst0;
		fConst385 = 0.0010308289313143177 * fConst0;
		fConst386 = 0.0009697666718711844 * fConst0;
		fConst387 = 0.003946932290913537 * fConst0;
		fConst388 = 0.003270019337447593 * fConst0;
		fConst389 = 0.000845903682144126 * fConst0;
		fConst390 = 0.0030386497290455735 * fConst0;
		fConst391 = 0.0037877733486893703 * fConst0;
		fConst392 = 0.001937305814057254 * fConst0;
		fConst393 = 0.003225818087463267 * fConst0;
		fConst394 = 0.0023607809889072085 * fConst0;
		fConst395 = 0.0019050356558254862 * fConst0;
		fConst396 = 0.0037704091943742244 * fConst0;
		fConst397 = 0.001842570276654442 * fConst0;
		fConst398 = 0.0008878850725013763 * fConst0;
		fConst399 = 0.002587431613705121 * fConst0;
		fConst400 = 0.0034868654518359107 * fConst0;
		fConst401 = 0.0009885943388508167 * fConst0;
		fConst402 = 0.00014774394486448728 * fConst0;
		fConst403 = 0.0026889051033649595 * fConst0;
		fConst404 = 0.0024911461907613556 * fConst0;
		fConst405 = 0.0011991703004860029 * fConst0;
		fConst406 = 0.0018207348349533277 * fConst0;
		fConst407 = 0.00341366234159068 * fConst0;
		fConst408 = 0.0017631721157467838 * fConst0;
		fConst409 = 0.0030070128059887795 * fConst0;
		fConst410 = 0.0035395263384853026 * fConst0;
		fConst411 = 0.0008950945727992803 * fConst0;
		fConst412 = 0.00036874521800200454 * fConst0;
		fConst413 = 0.0018339055498945527 * fConst0;
		fConst414 = 0.0034428917219156575 * fConst0;
		fConst415 = 0.0002112872201105347 * fConst0;
		fConst416 = 0.0010609229911060537 * fConst0;
		fConst417 = 0.002349153939940152 * fConst0;
		fConst418 = 0.0037739171796420125 * fConst0;
		fConst419 = 0.0030902761151519373 * fConst0;
		fConst420 = 0.0036006482162629257 * fConst0;
		fConst421 = 0.00015660938151995651 * fConst0;
		fConst422 = 0.0018658758804231184 * fConst0;
		fConst423 = 0.002157640704594087 * fConst0;
		fConst424 = 0.0027397620534757154 * fConst0;
		fConst425 = 0.0012788154222071171 * fConst0;
		fConst426 = 0.002102299727630452 * fConst0;
		fConst427 = 0.003685441336449003 * fConst0;
		fConst428 = 0.0021108611452859806 * fConst0;
		fConst429 = 55.0 / fConst0;
		fConst430 = 1.1e+02 / fConst0;
		fConst431 = 0.0039010674560267943 * fConst0;
		fConst432 = 0.00268736314837588 * fConst0;
		fConst433 = 0.0007513920197816333 * fConst0;
		fConst434 = 0.0032410287962920848 * fConst0;
		fConst435 = 0.00022457097977166996 * fConst0;
		fConst436 = 36.71232876712329 / fConst0;
		fConst437 = 0.00044606458609632683 * fConst0;
		fConst438 = 0.0006228472843649797 * fConst0;
		fConst439 = 0.0007956479632739502 * fConst0;
		fConst440 = 0.0027210843509237748 * fConst0;
		fConst441 = 0.003726235678739613 * fConst0;
		fConst442 = 0.003755657042216626 * fConst0;
		fConst443 = 0.0024726786799146795 * fConst0;
		fConst444 = 0.0031117473613412588 * fConst0;
		fConst445 = 0.0024881650840106887 * fConst0;
		fConst446 = 0.003279728692068602 * fConst0;
		fConst447 = 0.0012706429095687781 * fConst0;
		fConst448 = 0.0006967485342902365 * fConst0;
		fConst449 = 0.003963363865506836 * fConst0;
		fConst450 = 0.0026072097650321666 * fConst0;
		fConst451 = 0.00372999827406602 * fConst0;
		fConst452 = 0.002696144386456581 * fConst0;
		fConst453 = 0.0025639862960379106 * fConst0;
		fConst454 = 0.0009248319015168817 * fConst0;
		fConst455 = 0.003111610382969957 * fConst0;
		fConst456 = 0.0034835088163672483 * fConst0;
		fConst457 = 0.00377670276191202 * fConst0;
		fConst458 = 0.0002773857699794462 * fConst0;
		fConst459 = 0.0033214241270761707 * fConst0;
		fConst460 = 0.001428781377908308 * fConst0;
		fConst461 = 0.002982009566272609 * fConst0;
		fConst462 = 0.001664979509980185 * fConst0;
		fConst463 = 0.001585963482997613 * fConst0;
		fConst464 = 0.003314102009579074 * fConst0;
		fConst465 = 0.0011132979873364093 * fConst0;
		fConst466 = 0.003359234185132664 * fConst0;
		fConst467 = 0.003161239848661353 * fConst0;
		fConst468 = 0.0038220198872732 * fConst0;
		fConst469 = 0.0017219687213364523 * fConst0;
		fConst470 = 0.003783600417082198 * fConst0;
		fConst471 = 0.002767124236212112 * fConst0;
		fConst472 = 5.9400650468887765e-05 * fConst0;
		fConst473 = 0.0022927054444298847 * fConst0;
		fConst474 = 0.00113239277399407 * fConst0;
		fConst475 = 0.00120376450427284 * fConst0;
		fConst476 = 0.003002452973742038 * fConst0;
		fConst477 = 0.0005974903185851872 * fConst0;
		fConst478 = 0.000881746843457222 * fConst0;
		fConst479 = 0.00279324895197351 * fConst0;
		fConst480 = 0.0027256709131906975 * fConst0;
		fConst481 = 0.0035170062405231873 * fConst0;
		fConst482 = 0.0006150076176563744 * fConst0;
		fConst483 = 0.0010503342124575283 * fConst0;
		fConst484 = 0.001610316508464166 * fConst0;
		fConst485 = 0.0038912883006269115 * fConst0;
		fConst486 = 0.0017819922773524013 * fConst0;
		fConst487 = 0.0017148698161181528 * fConst0;
		fConst488 = 0.0017134514841309282 * fConst0;
		fConst489 = 0.002948477161182382 * fConst0;
		fConst490 = 1.258268314995803e-05 * fConst0;
		fConst491 = 0.00171204087373917 * fConst0;
		fConst492 = 46.25 / fConst0;
		fConst493 = 0.0038965639443485998 * fConst0;
		fConst494 = 0.0010687532741576434 * fConst0;
		fConst495 = 82.4 / fConst0;
		fConst496 = 41.2 / fConst0;
		fConst497 = 0.0004281847811798798 * fConst0;
		fConst498 = 0.00013732770250771863 * fConst0;
		fConst499 = 0.0021546751180139836 * fConst0;
		fConst500 = 0.000845677117962623 * fConst0;
		fConst501 = 34.63414634146341 / fConst0;
		fConst502 = 0.0033016342749178874 * fConst0;
		fConst503 = 0.001999312150088372 * fConst0;
		fConst504 = 0.0023091952907125235 * fConst0;
		fConst505 = 0.0025247527425235603 * fConst0;
		fConst506 = 7.996327249566093e-05 * fConst0;
		fConst507 = 0.003585709794017021 * fConst0;
		fConst508 = 0.0016823130872217007 * fConst0;
		fConst509 = 38.888888888888886 / fConst0;
		fConst510 = 0.0014045478165498936 * fConst0;
		fConst511 = 0.0009711507128813537 * fConst0;
		fConst512 = 43.63636363636363 / fConst0;
		fConst513 = 0.0018646035606507212 * fConst0;
		fConst514 = 0.001328851266163838 * fConst0;
		fConst515 = 0.0032630022601515523 * fConst0;
		fConst516 = 0.0016310239196463954 * fConst0;
		fConst517 = 0.002195782072696602 * fConst0;
		fConst518 = 0.0022343623149499764 * fConst0;
		fConst519 = 0.0009585896194039379 * fConst0;
		fConst520 = 0.0039076357658850615 * fConst0;
		fConst521 = 6.999347533565015e-07 * fConst0;
		fConst522 = 0.0025780298231111373 * fConst0;
		fConst523 = 0.0029464990194537676 * fConst0;
		fConst524 = 0.0022840294552006527 * fConst0;
		fConst525 = 0.0008881758407806047 * fConst0;
		fConst526 = 0.0032438979855245976 * fConst0;
		fConst527 = 0.0017872300604649355 * fConst0;
		fConst528 = 0.0023232935540145262 * fConst0;
		fConst529 = 0.0012182084981759544 * fConst0;
		fConst530 = 0.0001446452102100011 * fConst0;
		fConst531 = 0.0002887991952884477 * fConst0;
		fConst532 = 0.0017627607210301903 * fConst0;
		fConst533 = 0.0014453986677399372 * fConst0;
		fConst534 = 0.003993956372549292 * fConst0;
		fConst535 = 0.00211929123691516 * fConst0;
		fConst536 = 0.0024745777854695917 * fConst0;
		fConst537 = 0.00045605770364636557 * fConst0;
		fConst538 = 0.0028546430384521954 * fConst0;
		fConst539 = 0.0034448737933225858 * fConst0;
		fConst540 = 0.0024097474614391103 * fConst0;
		fConst541 = 0.0014744429537895485 * fConst0;
		fConst542 = 0.001552611292077927 * fConst0;
		fConst543 = 0.0032088401125511157 * fConst0;
		fConst544 = 0.0007726953801029595 * fConst0;
		fConst545 = 0.003156709041330032 * fConst0;
		fConst546 = 0.00296449012766243 * fConst0;
		fConst547 = 0.0011450046524987556 * fConst0;
		fConst548 = 0.0002356338834943017 * fConst0;
		fConst549 = 0.0033782447781122754 * fConst0;
		fConst550 = 0.00048376771435141566 * fConst0;
		fConst551 = 0.0027523372865689453 * fConst0;
		fConst552 = 0.0036258762155193837 * fConst0;
		fConst553 = 0.0024710297523270128 * fConst0;
		fConst554 = 0.0016796000347821974 * fConst0;
		fConst555 = 0.0010777405892149546 * fConst0;
		fConst556 = 0.0011858862432254681 * fConst0;
		fConst557 = 0.0036131699198813294 * fConst0;
		fConst558 = 0.0025282871433882975 * fConst0;
		fConst559 = 0.000532590274931863 * fConst0;
		fConst560 = 0.0002528428570658434 * fConst0;
		fConst561 = 0.0008310909123101737 * fConst0;
		fConst562 = 0.0019610496970999523 * fConst0;
		fConst563 = 0.0006343399347970262 * fConst0;
		fConst564 = 0.00010544447001302615 * fConst0;
		fConst565 = 0.0005452475240454078 * fConst0;
		fConst566 = 0.00248655607533874 * fConst0;
		fConst567 = 0.003970699242068804 * fConst0;
		fConst568 = 0.0007003566692837922 * fConst0;
		fConst569 = 0.00039040000001114094 * fConst0;
		fConst570 = 0.0015469868895597756 * fConst0;
		fConst571 = 0.0030112735081638674 * fConst0;
		fConst572 = 0.0033526618520190823 * fConst0;
		fConst573 = 0.0019911003783236085 * fConst0;
		fConst574 = 0.0006163576935650781 * fConst0;
		fConst575 = 0.00277155922120437 * fConst0;
		fConst576 = 0.0037264988306269517 * fConst0;
		fConst577 = 0.0005514952993253246 * fConst0;
		fConst578 = 0.0026901601907593433 * fConst0;
		fConst579 = 0.0014407543033121328 * fConst0;
		fConst580 = 0.00147425941479014 * fConst0;
		fConst581 = 0.0026728337830863895 * fConst0;
		fConst582 = 0.0003244598258170299 * fConst0;
		fConst583 = 0.00021742494250065648 * fConst0;
		fConst584 = 0.0009484368550765794 * fConst0;
		fConst585 = 0.001646525722651859 * fConst0;
		fConst586 = 0.001205371327298053 * fConst0;
		fConst587 = 0.0015941339678538498 * fConst0;
		fConst588 = 0.002441168305114843 * fConst0;
		fConst589 = 0.001234105061768787 * fConst0;
		fConst590 = 0.002065159943769686 * fConst0;
		fConst591 = 0.002365411799371941 * fConst0;
		fConst592 = 0.0036056118913402315 * fConst0;
		fConst593 = 0.0008324459085706622 * fConst0;
		fConst594 = 0.0007741658109298442 * fConst0;
		fConst595 = 0.00358504149622604 * fConst0;
		fConst596 = 0.002546544112759875 * fConst0;
		fConst597 = 0.0036192911825783085 * fConst0;
		fConst598 = 0.002594117165688658 * fConst0;
		fConst599 = 0.0015171180208926672 * fConst0;
		fConst600 = 0.0005144283368499601 * fConst0;
		fConst601 = 0.001587086131796241 * fConst0;
		fConst602 = 0.0025417953235446476 * fConst0;
		fConst603 = 0.0030095599395863247 * fConst0;
		fConst604 = 0.002598791690572398 * fConst0;
		fConst605 = 0.00351105511507194 * fConst0;
		fConst606 = 0.0019913687020598446 * fConst0;
		fConst607 = 0.0018234194962642506 * fConst0;
		fConst608 = 0.003829112961073406 * fConst0;
		fConst609 = 0.0026621803744346834 * fConst0;
		fConst610 = 0.002991629311116412 * fConst0;
		fConst611 = 0.0007900869360310026 * fConst0;
		fConst612 = 0.0032488047464576085 * fConst0;
		fConst613 = 0.0036638237681472677 * fConst0;
		fConst614 = 58.26086956521739 / fConst0;
		fConst615 = 0.0015110374262876575 * fConst0;
		fConst616 = 0.0022730450774161 * fConst0;
		fConst617 = 0.0022992356527975063 * fConst0;
		fConst618 = 0.002266073589838925 * fConst0;
		fConst619 = 0.0022750083041610195 * fConst0;
		fConst620 = 0.002151437266060384 * fConst0;
		fConst621 = 0.003763107758393744 * fConst0;
		fConst622 = 0.001340806404929026 * fConst0;
		fConst623 = 0.0014569291291481933 * fConst0;
		fConst624 = 0.00029561641556210817 * fConst0;
		fConst625 = 0.00010841917604557239 * fConst0;
		fConst626 = 0.003702702421549475 * fConst0;
		fConst627 = 0.0020044996303331575 * fConst0;
		fConst628 = 0.002098277011915343 * fConst0;
		fConst629 = 0.0017474801163552911 * fConst0;
		fConst630 = 0.00040690220486430917 * fConst0;
		fConst631 = 0.000337742045885534 * fConst0;
		fConst632 = 0.0016439594068615407 * fConst0;
		fConst633 = 0.0005937910841894336 * fConst0;
		fConst634 = 0.00230043566643144 * fConst0;
		fConst635 = 0.002001693343365332 * fConst0;
		fConst636 = 0.002179853624489624 * fConst0;
		fConst637 = 0.0030741403703577817 * fConst0;
		fConst638 = 5.930462449032348e-05 * fConst0;
		fConst639 = 0.00014772214975528186 * fConst0;
		fConst640 = 0.00252028702757525 * fConst0;
		fConst641 = 0.00157435739581706 * fConst0;
		fConst642 = 0.0029110110842157154 * fConst0;
		fConst643 = 0.0028880448003765196 * fConst0;
		fConst644 = 0.0032464027712849203 * fConst0;
		fConst645 = 0.0018498480823254796 * fConst0;
		fConst646 = 0.001710327143809991 * fConst0;
		fConst647 = 0.0016768102809437552 * fConst0;
		fConst648 = 0.000393301311560208 * fConst0;
		fConst649 = 0.0019525820929993643 * fConst0;
		fConst650 = 0.003785955034021754 * fConst0;
		fConst651 = 0.0009569127538979955 * fConst0;
		fConst652 = 0.0039066608555440325 * fConst0;
		fConst653 = 0.0017275360815838213 * fConst0;
		fConst654 = 6.9078 / fConst0;
		fConst655 = 6.87 / fConst0;
		double fConst656 = 1.0 / std::tan(125.66370614359172 / fConst0);
		fConst657 = 1.0 - fConst656;
		fConst658 = 1.0 / (fConst656 + 1.0);
		double fConst659 = 1.0 / std::tan(21991.14857512855 / fConst0);
		fConst660 = 1.0 - fConst659;
		fConst661 = 1.0 / (fConst659 + 1.0);
		fConst662 = std::tan(2513.2741228718346 / fConst0);
		double fConst663 = fConst662 * (fConst662 + 1.4142135623730951) + 1.0;
		fConst664 = 2.0 / fConst663;
		fConst665 = fConst662 / fConst663;
		fConst666 = 1.0 / fConst663;
		fConst667 = std::tan(6283.185307179586 / fConst0);
		double fConst668 = fConst667 * (fConst667 + 0.3748942167935661) + 1.0;
		fConst669 = 2.0 / fConst668;
		fConst670 = fConst667 / fConst668;
		fConst671 = 1.0 / fConst668;
		fConst672 = std::exp(-(0.3333333333333333 / fConst0));
		fConst673 = std::exp(-(0.45454545454545453 / fConst0));
		fConst674 = std::tan(628.3185307179587 / fConst0);
		double fConst675 = fConst674 * (fConst674 + 1.4142135623730951) + 1.0;
		fConst676 = 2.0 / fConst675;
		fConst677 = fConst674 / fConst675;
		fConst678 = 1.0 / fConst675;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider0 = FAUSTFLOAT(0.0);
		fHslider1 = FAUSTFLOAT(1.2e+02);
		fHslider2 = FAUSTFLOAT(0.2);
		fHslider3 = FAUSTFLOAT(0.0);
		fHslider4 = FAUSTFLOAT(3.0);
		fHslider5 = FAUSTFLOAT(6.0);
		fButton0 = FAUSTFLOAT(0.0);
		fHslider6 = FAUSTFLOAT(0.08);
		fButton1 = FAUSTFLOAT(0.0);
		fButton2 = FAUSTFLOAT(0.0);
		fButton3 = FAUSTFLOAT(0.0);
		fHslider7 = FAUSTFLOAT(0.3);
		fButton4 = FAUSTFLOAT(0.0);
		fHslider8 = FAUSTFLOAT(0.0);
		fHslider9 = FAUSTFLOAT(0.5);
		fHslider10 = FAUSTFLOAT(36.0);
		fButton5 = FAUSTFLOAT(0.0);
		fButton6 = FAUSTFLOAT(0.0);
		fButton7 = FAUSTFLOAT(0.0);
		fButton8 = FAUSTFLOAT(0.0);
		fButton9 = FAUSTFLOAT(0.0);
		fButton10 = FAUSTFLOAT(0.0);
		fButton11 = FAUSTFLOAT(0.0);
		fButton12 = FAUSTFLOAT(0.0);
		fButton13 = FAUSTFLOAT(0.0);
		fButton14 = FAUSTFLOAT(0.0);
		fButton15 = FAUSTFLOAT(0.0);
		fButton16 = FAUSTFLOAT(0.0);
		fButton17 = FAUSTFLOAT(0.0);
		fButton18 = FAUSTFLOAT(0.0);
		fButton19 = FAUSTFLOAT(0.0);
		fButton20 = FAUSTFLOAT(0.0);
		fButton21 = FAUSTFLOAT(0.0);
		fButton22 = FAUSTFLOAT(0.0);
		fButton23 = FAUSTFLOAT(0.0);
		fButton24 = FAUSTFLOAT(0.0);
		fButton25 = FAUSTFLOAT(0.0);
		fButton26 = FAUSTFLOAT(0.0);
		fButton27 = FAUSTFLOAT(0.0);
		fButton28 = FAUSTFLOAT(0.0);
		fButton29 = FAUSTFLOAT(0.0);
		fButton30 = FAUSTFLOAT(0.0);
		fButton31 = FAUSTFLOAT(0.0);
		fButton32 = FAUSTFLOAT(0.0);
		fButton33 = FAUSTFLOAT(0.0);
		fButton34 = FAUSTFLOAT(0.0);
		fButton35 = FAUSTFLOAT(0.0);
		fButton36 = FAUSTFLOAT(0.0);
		fButton37 = FAUSTFLOAT(0.0);
		fButton38 = FAUSTFLOAT(0.0);
		fButton39 = FAUSTFLOAT(0.0);
		fButton40 = FAUSTFLOAT(0.0);
		fButton41 = FAUSTFLOAT(0.0);
		fButton42 = FAUSTFLOAT(0.0);
		fButton43 = FAUSTFLOAT(0.0);
		fButton44 = FAUSTFLOAT(0.0);
		fButton45 = FAUSTFLOAT(0.0);
		fButton46 = FAUSTFLOAT(0.0);
		fButton47 = FAUSTFLOAT(0.0);
		fButton48 = FAUSTFLOAT(0.0);
		fButton49 = FAUSTFLOAT(0.0);
		fButton50 = FAUSTFLOAT(0.0);
		fButton51 = FAUSTFLOAT(0.0);
		fButton52 = FAUSTFLOAT(0.0);
		fButton53 = FAUSTFLOAT(0.0);
		fButton54 = FAUSTFLOAT(0.0);
		fButton55 = FAUSTFLOAT(0.0);
		fButton56 = FAUSTFLOAT(0.0);
		fButton57 = FAUSTFLOAT(0.0);
		fButton58 = FAUSTFLOAT(0.0);
		fButton59 = FAUSTFLOAT(0.0);
		fButton60 = FAUSTFLOAT(0.0);
		fButton61 = FAUSTFLOAT(0.0);
		fButton62 = FAUSTFLOAT(0.0);
		fButton63 = FAUSTFLOAT(0.0);
		fButton64 = FAUSTFLOAT(0.0);
		fHslider11 = FAUSTFLOAT(0.0);
		fHslider12 = FAUSTFLOAT(0.0);
		fHslider13 = FAUSTFLOAT(0.0);
		fHslider14 = FAUSTFLOAT(0.0);
		fHslider15 = FAUSTFLOAT(8.0);
		fHslider16 = FAUSTFLOAT(0.0);
		fHslider17 = FAUSTFLOAT(8.0);
		fHslider18 = FAUSTFLOAT(0.0);
		fHslider19 = FAUSTFLOAT(0.0);
		fCheckbox1 = FAUSTFLOAT(0.0);
		fCheckbox2 = FAUSTFLOAT(0.0);
		fCheckbox3 = FAUSTFLOAT(0.0);
		fCheckbox4 = FAUSTFLOAT(0.0);
		fCheckbox5 = FAUSTFLOAT(0.0);
		fHslider20 = FAUSTFLOAT(0.0);
		fHslider21 = FAUSTFLOAT(0.0);
		fHslider22 = FAUSTFLOAT(0.0);
		fHslider23 = FAUSTFLOAT(0.0);
		fHslider24 = FAUSTFLOAT(0.0);
		fHslider25 = FAUSTFLOAT(0.0);
		fHslider26 = FAUSTFLOAT(8.0);
		fHslider27 = FAUSTFLOAT(8.0);
		fHslider28 = FAUSTFLOAT(8.0);
		fHslider29 = FAUSTFLOAT(0.0);
		fButton65 = FAUSTFLOAT(0.0);
		fButton66 = FAUSTFLOAT(0.0);
		fButton67 = FAUSTFLOAT(0.0);
		fButton68 = FAUSTFLOAT(0.0);
		fButton69 = FAUSTFLOAT(0.0);
		fButton70 = FAUSTFLOAT(0.0);
		fButton71 = FAUSTFLOAT(0.0);
		fButton72 = FAUSTFLOAT(0.0);
		fButton73 = FAUSTFLOAT(0.0);
		fButton74 = FAUSTFLOAT(0.0);
		fButton75 = FAUSTFLOAT(0.0);
		fButton76 = FAUSTFLOAT(0.0);
		fButton77 = FAUSTFLOAT(0.0);
		fButton78 = FAUSTFLOAT(0.0);
		fButton79 = FAUSTFLOAT(0.0);
		fButton80 = FAUSTFLOAT(0.0);
		fButton81 = FAUSTFLOAT(0.0);
		fButton82 = FAUSTFLOAT(0.0);
		fButton83 = FAUSTFLOAT(0.0);
		fButton84 = FAUSTFLOAT(0.0);
		fButton85 = FAUSTFLOAT(0.0);
		fHslider30 = FAUSTFLOAT(1.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec0[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec14[l4] = 0.0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec15[l5] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec18[l8] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec20[l11] = 0.0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec21[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec22[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fVec3[l14] = 0.0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec23[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec24[l16] = 0.0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec25[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec26[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fVec4[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iRec27[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec28[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec29[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fVec5[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec30[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec31[l25] = 0.0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec32[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec33[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fVec6[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iRec34[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec35[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec36[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec37[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec38[l33] = 0.0;
		}
		IOTA0 = 0;
		for (int l34 = 0; l34 < 1024; l34 = l34 + 1) {
			fRec40[l34] = 0.0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fVec7[l35] = 0.0;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			iRec39[l36] = 0;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec41[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec42[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 1024; l39 = l39 + 1) {
			fRec44[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec8[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			iRec43[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec45[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec46[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec47[l44] = 0.0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec48[l45] = 0.0;
		}
		for (int l46 = 0; l46 < 1024; l46 = l46 + 1) {
			fRec50[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fVec9[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			iRec49[l48] = 0;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec51[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec52[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec53[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec54[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 1024; l53 = l53 + 1) {
			fRec56[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fVec10[l54] = 0.0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iRec55[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec57[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec58[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec59[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec60[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 1024; l60 = l60 + 1) {
			fRec62[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fVec11[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			iRec61[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec63[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec64[l64] = 0.0;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec65[l65] = 0.0;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec66[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 1024; l67 = l67 + 1) {
			fRec68[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fVec12[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			iRec67[l69] = 0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec69[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec70[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec71[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec72[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 1024; l74 = l74 + 1) {
			fRec74[l74] = 0.0;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			fVec13[l75] = 0.0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			iRec73[l76] = 0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec75[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec76[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec77[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fRec78[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 1024; l81 = l81 + 1) {
			fRec80[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fVec14[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			iRec79[l83] = 0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec81[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fRec82[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 1024; l86 = l86 + 1) {
			fRec84[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fVec15[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			iRec83[l88] = 0;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec85[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fRec86[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec87[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 1024; l92 = l92 + 1) {
			fRec89[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fVec16[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			iRec88[l94] = 0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fRec90[l95] = 0.0;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec91[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec92[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 1024; l98 = l98 + 1) {
			fRec94[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fVec17[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			iRec93[l100] = 0;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec95[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec96[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec97[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec98[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 1024; l105 = l105 + 1) {
			fRec100[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fVec18[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			iRec99[l107] = 0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec101[l108] = 0.0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec102[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fRec103[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec104[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 1024; l112 = l112 + 1) {
			fRec106[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fVec19[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			iRec105[l114] = 0;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec107[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec108[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec109[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec110[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 1024; l119 = l119 + 1) {
			fRec112[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fVec20[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			iRec111[l121] = 0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec113[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			fRec114[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec115[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec116[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec117[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 1024; l127 = l127 + 1) {
			fRec119[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fVec21[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			iRec118[l129] = 0;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			fRec120[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec121[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec122[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec123[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 1024; l134 = l134 + 1) {
			fRec125[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 2; l135 = l135 + 1) {
			fVec22[l135] = 0.0;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			iRec124[l136] = 0;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fRec126[l137] = 0.0;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fRec127[l138] = 0.0;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			fRec128[l139] = 0.0;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			fRec129[l140] = 0.0;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			fRec130[l141] = 0.0;
		}
		for (int l142 = 0; l142 < 1024; l142 = l142 + 1) {
			fRec132[l142] = 0.0;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fVec23[l143] = 0.0;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			iRec131[l144] = 0;
		}
		for (int l145 = 0; l145 < 2; l145 = l145 + 1) {
			fRec133[l145] = 0.0;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec134[l146] = 0.0;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			fRec135[l147] = 0.0;
		}
		for (int l148 = 0; l148 < 1024; l148 = l148 + 1) {
			fRec137[l148] = 0.0;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fVec24[l149] = 0.0;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			iRec136[l150] = 0;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fRec138[l151] = 0.0;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			fRec139[l152] = 0.0;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			fRec140[l153] = 0.0;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fRec141[l154] = 0.0;
		}
		for (int l155 = 0; l155 < 2; l155 = l155 + 1) {
			fRec142[l155] = 0.0;
		}
		for (int l156 = 0; l156 < 1024; l156 = l156 + 1) {
			fRec144[l156] = 0.0;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			fVec25[l157] = 0.0;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			iRec143[l158] = 0;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			fRec145[l159] = 0.0;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec146[l160] = 0.0;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fRec147[l161] = 0.0;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec148[l162] = 0.0;
		}
		for (int l163 = 0; l163 < 1024; l163 = l163 + 1) {
			fRec150[l163] = 0.0;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			fVec26[l164] = 0.0;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			iRec149[l165] = 0;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec151[l166] = 0.0;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec152[l167] = 0.0;
		}
		for (int l168 = 0; l168 < 2; l168 = l168 + 1) {
			fRec153[l168] = 0.0;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fRec154[l169] = 0.0;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			fRec155[l170] = 0.0;
		}
		for (int l171 = 0; l171 < 1024; l171 = l171 + 1) {
			fRec157[l171] = 0.0;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fVec27[l172] = 0.0;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			iRec156[l173] = 0;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fRec158[l174] = 0.0;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec159[l175] = 0.0;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec160[l176] = 0.0;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			fRec161[l177] = 0.0;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec162[l178] = 0.0;
		}
		for (int l179 = 0; l179 < 1024; l179 = l179 + 1) {
			fRec164[l179] = 0.0;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fVec28[l180] = 0.0;
		}
		for (int l181 = 0; l181 < 2; l181 = l181 + 1) {
			iRec163[l181] = 0;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fRec165[l182] = 0.0;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fRec166[l183] = 0.0;
		}
		for (int l184 = 0; l184 < 1024; l184 = l184 + 1) {
			fRec168[l184] = 0.0;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fVec29[l185] = 0.0;
		}
		for (int l186 = 0; l186 < 2; l186 = l186 + 1) {
			iRec167[l186] = 0;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			fRec169[l187] = 0.0;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec170[l188] = 0.0;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec171[l189] = 0.0;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec172[l190] = 0.0;
		}
		for (int l191 = 0; l191 < 1024; l191 = l191 + 1) {
			fRec174[l191] = 0.0;
		}
		for (int l192 = 0; l192 < 2; l192 = l192 + 1) {
			fVec30[l192] = 0.0;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			iRec173[l193] = 0;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fRec175[l194] = 0.0;
		}
		for (int l195 = 0; l195 < 2; l195 = l195 + 1) {
			fRec176[l195] = 0.0;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			fRec177[l196] = 0.0;
		}
		for (int l197 = 0; l197 < 1024; l197 = l197 + 1) {
			fRec179[l197] = 0.0;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			fVec31[l198] = 0.0;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			iRec178[l199] = 0;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			fRec180[l200] = 0.0;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			fRec181[l201] = 0.0;
		}
		for (int l202 = 0; l202 < 2; l202 = l202 + 1) {
			fRec182[l202] = 0.0;
		}
		for (int l203 = 0; l203 < 1024; l203 = l203 + 1) {
			fRec184[l203] = 0.0;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fVec32[l204] = 0.0;
		}
		for (int l205 = 0; l205 < 2; l205 = l205 + 1) {
			iRec183[l205] = 0;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			fRec185[l206] = 0.0;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			fRec186[l207] = 0.0;
		}
		for (int l208 = 0; l208 < 1024; l208 = l208 + 1) {
			fRec188[l208] = 0.0;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			fVec33[l209] = 0.0;
		}
		for (int l210 = 0; l210 < 2; l210 = l210 + 1) {
			iRec187[l210] = 0;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			fRec189[l211] = 0.0;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fRec190[l212] = 0.0;
		}
		for (int l213 = 0; l213 < 2; l213 = l213 + 1) {
			fRec191[l213] = 0.0;
		}
		for (int l214 = 0; l214 < 1024; l214 = l214 + 1) {
			fRec193[l214] = 0.0;
		}
		for (int l215 = 0; l215 < 2; l215 = l215 + 1) {
			fVec34[l215] = 0.0;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			iRec192[l216] = 0;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			fRec194[l217] = 0.0;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			fRec195[l218] = 0.0;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			fRec196[l219] = 0.0;
		}
		for (int l220 = 0; l220 < 1024; l220 = l220 + 1) {
			fRec198[l220] = 0.0;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			fVec35[l221] = 0.0;
		}
		for (int l222 = 0; l222 < 2; l222 = l222 + 1) {
			iRec197[l222] = 0;
		}
		for (int l223 = 0; l223 < 2; l223 = l223 + 1) {
			fRec199[l223] = 0.0;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fRec200[l224] = 0.0;
		}
		for (int l225 = 0; l225 < 2; l225 = l225 + 1) {
			fRec201[l225] = 0.0;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			fRec202[l226] = 0.0;
		}
		for (int l227 = 0; l227 < 1024; l227 = l227 + 1) {
			fRec204[l227] = 0.0;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			fVec36[l228] = 0.0;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			iRec203[l229] = 0;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			fRec205[l230] = 0.0;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			fRec206[l231] = 0.0;
		}
		for (int l232 = 0; l232 < 2; l232 = l232 + 1) {
			fRec207[l232] = 0.0;
		}
		for (int l233 = 0; l233 < 1024; l233 = l233 + 1) {
			fRec209[l233] = 0.0;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			fVec37[l234] = 0.0;
		}
		for (int l235 = 0; l235 < 2; l235 = l235 + 1) {
			iRec208[l235] = 0;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fRec210[l236] = 0.0;
		}
		for (int l237 = 0; l237 < 2; l237 = l237 + 1) {
			fRec211[l237] = 0.0;
		}
		for (int l238 = 0; l238 < 1024; l238 = l238 + 1) {
			fRec213[l238] = 0.0;
		}
		for (int l239 = 0; l239 < 2; l239 = l239 + 1) {
			fVec38[l239] = 0.0;
		}
		for (int l240 = 0; l240 < 2; l240 = l240 + 1) {
			iRec212[l240] = 0;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			fRec214[l241] = 0.0;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			fRec215[l242] = 0.0;
		}
		for (int l243 = 0; l243 < 1024; l243 = l243 + 1) {
			fRec217[l243] = 0.0;
		}
		for (int l244 = 0; l244 < 2; l244 = l244 + 1) {
			fVec39[l244] = 0.0;
		}
		for (int l245 = 0; l245 < 2; l245 = l245 + 1) {
			iRec216[l245] = 0;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			fRec218[l246] = 0.0;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			fRec219[l247] = 0.0;
		}
		for (int l248 = 0; l248 < 1024; l248 = l248 + 1) {
			fRec221[l248] = 0.0;
		}
		for (int l249 = 0; l249 < 2; l249 = l249 + 1) {
			fVec40[l249] = 0.0;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			iRec220[l250] = 0;
		}
		for (int l251 = 0; l251 < 2; l251 = l251 + 1) {
			fRec222[l251] = 0.0;
		}
		for (int l252 = 0; l252 < 2; l252 = l252 + 1) {
			fRec223[l252] = 0.0;
		}
		for (int l253 = 0; l253 < 2; l253 = l253 + 1) {
			fRec224[l253] = 0.0;
		}
		for (int l254 = 0; l254 < 1024; l254 = l254 + 1) {
			fRec226[l254] = 0.0;
		}
		for (int l255 = 0; l255 < 2; l255 = l255 + 1) {
			fVec41[l255] = 0.0;
		}
		for (int l256 = 0; l256 < 2; l256 = l256 + 1) {
			iRec225[l256] = 0;
		}
		for (int l257 = 0; l257 < 2; l257 = l257 + 1) {
			fRec227[l257] = 0.0;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec228[l258] = 0.0;
		}
		for (int l259 = 0; l259 < 1024; l259 = l259 + 1) {
			fRec230[l259] = 0.0;
		}
		for (int l260 = 0; l260 < 2; l260 = l260 + 1) {
			fVec42[l260] = 0.0;
		}
		for (int l261 = 0; l261 < 2; l261 = l261 + 1) {
			iRec229[l261] = 0;
		}
		for (int l262 = 0; l262 < 2; l262 = l262 + 1) {
			fRec231[l262] = 0.0;
		}
		for (int l263 = 0; l263 < 2; l263 = l263 + 1) {
			fRec232[l263] = 0.0;
		}
		for (int l264 = 0; l264 < 2; l264 = l264 + 1) {
			fRec233[l264] = 0.0;
		}
		for (int l265 = 0; l265 < 1024; l265 = l265 + 1) {
			fRec235[l265] = 0.0;
		}
		for (int l266 = 0; l266 < 2; l266 = l266 + 1) {
			fVec43[l266] = 0.0;
		}
		for (int l267 = 0; l267 < 2; l267 = l267 + 1) {
			iRec234[l267] = 0;
		}
		for (int l268 = 0; l268 < 2; l268 = l268 + 1) {
			fRec236[l268] = 0.0;
		}
		for (int l269 = 0; l269 < 2; l269 = l269 + 1) {
			fRec237[l269] = 0.0;
		}
		for (int l270 = 0; l270 < 1024; l270 = l270 + 1) {
			fRec239[l270] = 0.0;
		}
		for (int l271 = 0; l271 < 2; l271 = l271 + 1) {
			fVec44[l271] = 0.0;
		}
		for (int l272 = 0; l272 < 2; l272 = l272 + 1) {
			iRec238[l272] = 0;
		}
		for (int l273 = 0; l273 < 2; l273 = l273 + 1) {
			fRec240[l273] = 0.0;
		}
		for (int l274 = 0; l274 < 2; l274 = l274 + 1) {
			fRec241[l274] = 0.0;
		}
		for (int l275 = 0; l275 < 1024; l275 = l275 + 1) {
			fRec243[l275] = 0.0;
		}
		for (int l276 = 0; l276 < 2; l276 = l276 + 1) {
			fVec45[l276] = 0.0;
		}
		for (int l277 = 0; l277 < 2; l277 = l277 + 1) {
			iRec242[l277] = 0;
		}
		for (int l278 = 0; l278 < 2; l278 = l278 + 1) {
			fRec244[l278] = 0.0;
		}
		for (int l279 = 0; l279 < 2; l279 = l279 + 1) {
			fRec245[l279] = 0.0;
		}
		for (int l280 = 0; l280 < 1024; l280 = l280 + 1) {
			fRec247[l280] = 0.0;
		}
		for (int l281 = 0; l281 < 2; l281 = l281 + 1) {
			fVec46[l281] = 0.0;
		}
		for (int l282 = 0; l282 < 2; l282 = l282 + 1) {
			iRec246[l282] = 0;
		}
		for (int l283 = 0; l283 < 2; l283 = l283 + 1) {
			fRec248[l283] = 0.0;
		}
		for (int l284 = 0; l284 < 2; l284 = l284 + 1) {
			fRec249[l284] = 0.0;
		}
		for (int l285 = 0; l285 < 2; l285 = l285 + 1) {
			fRec250[l285] = 0.0;
		}
		for (int l286 = 0; l286 < 1024; l286 = l286 + 1) {
			fRec252[l286] = 0.0;
		}
		for (int l287 = 0; l287 < 2; l287 = l287 + 1) {
			fVec47[l287] = 0.0;
		}
		for (int l288 = 0; l288 < 2; l288 = l288 + 1) {
			iRec251[l288] = 0;
		}
		for (int l289 = 0; l289 < 2; l289 = l289 + 1) {
			fRec253[l289] = 0.0;
		}
		for (int l290 = 0; l290 < 2; l290 = l290 + 1) {
			fRec254[l290] = 0.0;
		}
		for (int l291 = 0; l291 < 1024; l291 = l291 + 1) {
			fRec256[l291] = 0.0;
		}
		for (int l292 = 0; l292 < 2; l292 = l292 + 1) {
			fVec48[l292] = 0.0;
		}
		for (int l293 = 0; l293 < 2; l293 = l293 + 1) {
			iRec255[l293] = 0;
		}
		for (int l294 = 0; l294 < 2; l294 = l294 + 1) {
			fRec257[l294] = 0.0;
		}
		for (int l295 = 0; l295 < 2; l295 = l295 + 1) {
			fRec258[l295] = 0.0;
		}
		for (int l296 = 0; l296 < 1024; l296 = l296 + 1) {
			fRec260[l296] = 0.0;
		}
		for (int l297 = 0; l297 < 2; l297 = l297 + 1) {
			fVec49[l297] = 0.0;
		}
		for (int l298 = 0; l298 < 2; l298 = l298 + 1) {
			iRec259[l298] = 0;
		}
		for (int l299 = 0; l299 < 2; l299 = l299 + 1) {
			fRec261[l299] = 0.0;
		}
		for (int l300 = 0; l300 < 2; l300 = l300 + 1) {
			fRec262[l300] = 0.0;
		}
		for (int l301 = 0; l301 < 1024; l301 = l301 + 1) {
			fRec264[l301] = 0.0;
		}
		for (int l302 = 0; l302 < 2; l302 = l302 + 1) {
			fVec50[l302] = 0.0;
		}
		for (int l303 = 0; l303 < 2; l303 = l303 + 1) {
			iRec263[l303] = 0;
		}
		for (int l304 = 0; l304 < 2; l304 = l304 + 1) {
			fRec265[l304] = 0.0;
		}
		for (int l305 = 0; l305 < 2; l305 = l305 + 1) {
			fRec266[l305] = 0.0;
		}
		for (int l306 = 0; l306 < 1024; l306 = l306 + 1) {
			fRec268[l306] = 0.0;
		}
		for (int l307 = 0; l307 < 2; l307 = l307 + 1) {
			fVec51[l307] = 0.0;
		}
		for (int l308 = 0; l308 < 2; l308 = l308 + 1) {
			iRec267[l308] = 0;
		}
		for (int l309 = 0; l309 < 2; l309 = l309 + 1) {
			fRec269[l309] = 0.0;
		}
		for (int l310 = 0; l310 < 2; l310 = l310 + 1) {
			fRec270[l310] = 0.0;
		}
		for (int l311 = 0; l311 < 2; l311 = l311 + 1) {
			fRec271[l311] = 0.0;
		}
		for (int l312 = 0; l312 < 1024; l312 = l312 + 1) {
			fRec273[l312] = 0.0;
		}
		for (int l313 = 0; l313 < 2; l313 = l313 + 1) {
			fVec52[l313] = 0.0;
		}
		for (int l314 = 0; l314 < 2; l314 = l314 + 1) {
			iRec272[l314] = 0;
		}
		for (int l315 = 0; l315 < 2; l315 = l315 + 1) {
			fRec274[l315] = 0.0;
		}
		for (int l316 = 0; l316 < 2; l316 = l316 + 1) {
			fRec275[l316] = 0.0;
		}
		for (int l317 = 0; l317 < 1024; l317 = l317 + 1) {
			fRec277[l317] = 0.0;
		}
		for (int l318 = 0; l318 < 2; l318 = l318 + 1) {
			fVec53[l318] = 0.0;
		}
		for (int l319 = 0; l319 < 2; l319 = l319 + 1) {
			iRec276[l319] = 0;
		}
		for (int l320 = 0; l320 < 2; l320 = l320 + 1) {
			fRec278[l320] = 0.0;
		}
		for (int l321 = 0; l321 < 2; l321 = l321 + 1) {
			fRec279[l321] = 0.0;
		}
		for (int l322 = 0; l322 < 1024; l322 = l322 + 1) {
			fRec281[l322] = 0.0;
		}
		for (int l323 = 0; l323 < 2; l323 = l323 + 1) {
			fVec54[l323] = 0.0;
		}
		for (int l324 = 0; l324 < 2; l324 = l324 + 1) {
			iRec280[l324] = 0;
		}
		for (int l325 = 0; l325 < 2; l325 = l325 + 1) {
			fRec282[l325] = 0.0;
		}
		for (int l326 = 0; l326 < 2; l326 = l326 + 1) {
			fRec283[l326] = 0.0;
		}
		for (int l327 = 0; l327 < 2; l327 = l327 + 1) {
			fRec284[l327] = 0.0;
		}
		for (int l328 = 0; l328 < 1024; l328 = l328 + 1) {
			fRec286[l328] = 0.0;
		}
		for (int l329 = 0; l329 < 2; l329 = l329 + 1) {
			fVec55[l329] = 0.0;
		}
		for (int l330 = 0; l330 < 2; l330 = l330 + 1) {
			iRec285[l330] = 0;
		}
		for (int l331 = 0; l331 < 2; l331 = l331 + 1) {
			fRec287[l331] = 0.0;
		}
		for (int l332 = 0; l332 < 2; l332 = l332 + 1) {
			fRec288[l332] = 0.0;
		}
		for (int l333 = 0; l333 < 1024; l333 = l333 + 1) {
			fRec290[l333] = 0.0;
		}
		for (int l334 = 0; l334 < 2; l334 = l334 + 1) {
			fVec56[l334] = 0.0;
		}
		for (int l335 = 0; l335 < 2; l335 = l335 + 1) {
			iRec289[l335] = 0;
		}
		for (int l336 = 0; l336 < 2; l336 = l336 + 1) {
			fRec291[l336] = 0.0;
		}
		for (int l337 = 0; l337 < 2; l337 = l337 + 1) {
			fRec292[l337] = 0.0;
		}
		for (int l338 = 0; l338 < 1024; l338 = l338 + 1) {
			fRec294[l338] = 0.0;
		}
		for (int l339 = 0; l339 < 2; l339 = l339 + 1) {
			fVec57[l339] = 0.0;
		}
		for (int l340 = 0; l340 < 2; l340 = l340 + 1) {
			iRec293[l340] = 0;
		}
		for (int l341 = 0; l341 < 2; l341 = l341 + 1) {
			fRec295[l341] = 0.0;
		}
		for (int l342 = 0; l342 < 2; l342 = l342 + 1) {
			fRec296[l342] = 0.0;
		}
		for (int l343 = 0; l343 < 1024; l343 = l343 + 1) {
			fRec298[l343] = 0.0;
		}
		for (int l344 = 0; l344 < 2; l344 = l344 + 1) {
			fVec58[l344] = 0.0;
		}
		for (int l345 = 0; l345 < 2; l345 = l345 + 1) {
			iRec297[l345] = 0;
		}
		for (int l346 = 0; l346 < 2; l346 = l346 + 1) {
			fRec299[l346] = 0.0;
		}
		for (int l347 = 0; l347 < 2; l347 = l347 + 1) {
			fRec300[l347] = 0.0;
		}
		for (int l348 = 0; l348 < 1024; l348 = l348 + 1) {
			fRec302[l348] = 0.0;
		}
		for (int l349 = 0; l349 < 2; l349 = l349 + 1) {
			fVec59[l349] = 0.0;
		}
		for (int l350 = 0; l350 < 2; l350 = l350 + 1) {
			iRec301[l350] = 0;
		}
		for (int l351 = 0; l351 < 2; l351 = l351 + 1) {
			fRec303[l351] = 0.0;
		}
		for (int l352 = 0; l352 < 2; l352 = l352 + 1) {
			fRec304[l352] = 0.0;
		}
		for (int l353 = 0; l353 < 1024; l353 = l353 + 1) {
			fRec306[l353] = 0.0;
		}
		for (int l354 = 0; l354 < 2; l354 = l354 + 1) {
			fVec60[l354] = 0.0;
		}
		for (int l355 = 0; l355 < 2; l355 = l355 + 1) {
			iRec305[l355] = 0;
		}
		for (int l356 = 0; l356 < 2; l356 = l356 + 1) {
			fRec307[l356] = 0.0;
		}
		for (int l357 = 0; l357 < 2; l357 = l357 + 1) {
			fRec308[l357] = 0.0;
		}
		for (int l358 = 0; l358 < 1024; l358 = l358 + 1) {
			fRec310[l358] = 0.0;
		}
		for (int l359 = 0; l359 < 2; l359 = l359 + 1) {
			fVec61[l359] = 0.0;
		}
		for (int l360 = 0; l360 < 2; l360 = l360 + 1) {
			iRec309[l360] = 0;
		}
		for (int l361 = 0; l361 < 2; l361 = l361 + 1) {
			fRec311[l361] = 0.0;
		}
		for (int l362 = 0; l362 < 2; l362 = l362 + 1) {
			fRec312[l362] = 0.0;
		}
		for (int l363 = 0; l363 < 1024; l363 = l363 + 1) {
			fRec314[l363] = 0.0;
		}
		for (int l364 = 0; l364 < 2; l364 = l364 + 1) {
			fVec62[l364] = 0.0;
		}
		for (int l365 = 0; l365 < 2; l365 = l365 + 1) {
			iRec313[l365] = 0;
		}
		for (int l366 = 0; l366 < 2; l366 = l366 + 1) {
			fRec315[l366] = 0.0;
		}
		for (int l367 = 0; l367 < 2; l367 = l367 + 1) {
			fRec316[l367] = 0.0;
		}
		for (int l368 = 0; l368 < 1024; l368 = l368 + 1) {
			fRec318[l368] = 0.0;
		}
		for (int l369 = 0; l369 < 2; l369 = l369 + 1) {
			fVec63[l369] = 0.0;
		}
		for (int l370 = 0; l370 < 2; l370 = l370 + 1) {
			iRec317[l370] = 0;
		}
		for (int l371 = 0; l371 < 2; l371 = l371 + 1) {
			fRec319[l371] = 0.0;
		}
		for (int l372 = 0; l372 < 2; l372 = l372 + 1) {
			fRec320[l372] = 0.0;
		}
		for (int l373 = 0; l373 < 1024; l373 = l373 + 1) {
			fRec322[l373] = 0.0;
		}
		for (int l374 = 0; l374 < 2; l374 = l374 + 1) {
			fVec64[l374] = 0.0;
		}
		for (int l375 = 0; l375 < 2; l375 = l375 + 1) {
			iRec321[l375] = 0;
		}
		for (int l376 = 0; l376 < 2; l376 = l376 + 1) {
			fRec323[l376] = 0.0;
		}
		for (int l377 = 0; l377 < 2; l377 = l377 + 1) {
			fRec324[l377] = 0.0;
		}
		for (int l378 = 0; l378 < 1024; l378 = l378 + 1) {
			fRec326[l378] = 0.0;
		}
		for (int l379 = 0; l379 < 2; l379 = l379 + 1) {
			fVec65[l379] = 0.0;
		}
		for (int l380 = 0; l380 < 2; l380 = l380 + 1) {
			iRec325[l380] = 0;
		}
		for (int l381 = 0; l381 < 2; l381 = l381 + 1) {
			fRec327[l381] = 0.0;
		}
		for (int l382 = 0; l382 < 2; l382 = l382 + 1) {
			fRec328[l382] = 0.0;
		}
		for (int l383 = 0; l383 < 1024; l383 = l383 + 1) {
			fRec330[l383] = 0.0;
		}
		for (int l384 = 0; l384 < 2; l384 = l384 + 1) {
			fVec66[l384] = 0.0;
		}
		for (int l385 = 0; l385 < 2; l385 = l385 + 1) {
			iRec329[l385] = 0;
		}
		for (int l386 = 0; l386 < 2; l386 = l386 + 1) {
			fRec331[l386] = 0.0;
		}
		for (int l387 = 0; l387 < 2; l387 = l387 + 1) {
			fRec332[l387] = 0.0;
		}
		for (int l388 = 0; l388 < 1024; l388 = l388 + 1) {
			fRec334[l388] = 0.0;
		}
		for (int l389 = 0; l389 < 2; l389 = l389 + 1) {
			fVec67[l389] = 0.0;
		}
		for (int l390 = 0; l390 < 2; l390 = l390 + 1) {
			iRec333[l390] = 0;
		}
		for (int l391 = 0; l391 < 2; l391 = l391 + 1) {
			fRec335[l391] = 0.0;
		}
		for (int l392 = 0; l392 < 2; l392 = l392 + 1) {
			fRec336[l392] = 0.0;
		}
		for (int l393 = 0; l393 < 2; l393 = l393 + 1) {
			fRec337[l393] = 0.0;
		}
		for (int l394 = 0; l394 < 2; l394 = l394 + 1) {
			fVec68[l394] = 0.0;
		}
		for (int l395 = 0; l395 < 2; l395 = l395 + 1) {
			iRec338[l395] = 0;
		}
		for (int l396 = 0; l396 < 2; l396 = l396 + 1) {
			fRec339[l396] = 0.0;
		}
		for (int l397 = 0; l397 < 2; l397 = l397 + 1) {
			fVec69[l397] = 0.0;
		}
		for (int l398 = 0; l398 < 2; l398 = l398 + 1) {
			iRec340[l398] = 0;
		}
		for (int l399 = 0; l399 < 2; l399 = l399 + 1) {
			fRec341[l399] = 0.0;
		}
		for (int l400 = 0; l400 < 2; l400 = l400 + 1) {
			fVec70[l400] = 0.0;
		}
		for (int l401 = 0; l401 < 2; l401 = l401 + 1) {
			iRec342[l401] = 0;
		}
		for (int l402 = 0; l402 < 2; l402 = l402 + 1) {
			fRec343[l402] = 0.0;
		}
		for (int l403 = 0; l403 < 2; l403 = l403 + 1) {
			fVec71[l403] = 0.0;
		}
		for (int l404 = 0; l404 < 2; l404 = l404 + 1) {
			iRec344[l404] = 0;
		}
		for (int l405 = 0; l405 < 2; l405 = l405 + 1) {
			fRec345[l405] = 0.0;
		}
		for (int l406 = 0; l406 < 2; l406 = l406 + 1) {
			fVec72[l406] = 0.0;
		}
		for (int l407 = 0; l407 < 2; l407 = l407 + 1) {
			iRec346[l407] = 0;
		}
		for (int l408 = 0; l408 < 2; l408 = l408 + 1) {
			fRec347[l408] = 0.0;
		}
		for (int l409 = 0; l409 < 2; l409 = l409 + 1) {
			fVec73[l409] = 0.0;
		}
		for (int l410 = 0; l410 < 2; l410 = l410 + 1) {
			iRec348[l410] = 0;
		}
		for (int l411 = 0; l411 < 2; l411 = l411 + 1) {
			fRec349[l411] = 0.0;
		}
		for (int l412 = 0; l412 < 2; l412 = l412 + 1) {
			fVec74[l412] = 0.0;
		}
		for (int l413 = 0; l413 < 2; l413 = l413 + 1) {
			iRec350[l413] = 0;
		}
		for (int l414 = 0; l414 < 2; l414 = l414 + 1) {
			fRec351[l414] = 0.0;
		}
		for (int l415 = 0; l415 < 2; l415 = l415 + 1) {
			fVec75[l415] = 0.0;
		}
		for (int l416 = 0; l416 < 2; l416 = l416 + 1) {
			iRec352[l416] = 0;
		}
		for (int l417 = 0; l417 < 2; l417 = l417 + 1) {
			fRec353[l417] = 0.0;
		}
		for (int l418 = 0; l418 < 2; l418 = l418 + 1) {
			fVec76[l418] = 0.0;
		}
		for (int l419 = 0; l419 < 2; l419 = l419 + 1) {
			iRec354[l419] = 0;
		}
		for (int l420 = 0; l420 < 2; l420 = l420 + 1) {
			fRec355[l420] = 0.0;
		}
		for (int l421 = 0; l421 < 2; l421 = l421 + 1) {
			fVec77[l421] = 0.0;
		}
		for (int l422 = 0; l422 < 2; l422 = l422 + 1) {
			iRec356[l422] = 0;
		}
		for (int l423 = 0; l423 < 2; l423 = l423 + 1) {
			fRec357[l423] = 0.0;
		}
		for (int l424 = 0; l424 < 2; l424 = l424 + 1) {
			fRec358[l424] = 0.0;
		}
		for (int l425 = 0; l425 < 2; l425 = l425 + 1) {
			fVec78[l425] = 0.0;
		}
		for (int l426 = 0; l426 < 2; l426 = l426 + 1) {
			iRec359[l426] = 0;
		}
		for (int l427 = 0; l427 < 2; l427 = l427 + 1) {
			fRec360[l427] = 0.0;
		}
		for (int l428 = 0; l428 < 2; l428 = l428 + 1) {
			fRec361[l428] = 0.0;
		}
		for (int l429 = 0; l429 < 2; l429 = l429 + 1) {
			fVec79[l429] = 0.0;
		}
		for (int l430 = 0; l430 < 2; l430 = l430 + 1) {
			iRec362[l430] = 0;
		}
		for (int l431 = 0; l431 < 2; l431 = l431 + 1) {
			fRec363[l431] = 0.0;
		}
		for (int l432 = 0; l432 < 2; l432 = l432 + 1) {
			fRec364[l432] = 0.0;
		}
		for (int l433 = 0; l433 < 2; l433 = l433 + 1) {
			fVec80[l433] = 0.0;
		}
		for (int l434 = 0; l434 < 2; l434 = l434 + 1) {
			iRec365[l434] = 0;
		}
		for (int l435 = 0; l435 < 2; l435 = l435 + 1) {
			fRec366[l435] = 0.0;
		}
		for (int l436 = 0; l436 < 2; l436 = l436 + 1) {
			fVec81[l436] = 0.0;
		}
		for (int l437 = 0; l437 < 2; l437 = l437 + 1) {
			iRec367[l437] = 0;
		}
		for (int l438 = 0; l438 < 2; l438 = l438 + 1) {
			fRec368[l438] = 0.0;
		}
		for (int l439 = 0; l439 < 2; l439 = l439 + 1) {
			fVec82[l439] = 0.0;
		}
		for (int l440 = 0; l440 < 2; l440 = l440 + 1) {
			iRec369[l440] = 0;
		}
		for (int l441 = 0; l441 < 2; l441 = l441 + 1) {
			fRec370[l441] = 0.0;
		}
		for (int l442 = 0; l442 < 2; l442 = l442 + 1) {
			fVec83[l442] = 0.0;
		}
		for (int l443 = 0; l443 < 2; l443 = l443 + 1) {
			iRec371[l443] = 0;
		}
		for (int l444 = 0; l444 < 2; l444 = l444 + 1) {
			fRec372[l444] = 0.0;
		}
		for (int l445 = 0; l445 < 2; l445 = l445 + 1) {
			fRec373[l445] = 0.0;
		}
		for (int l446 = 0; l446 < 2; l446 = l446 + 1) {
			fVec84[l446] = 0.0;
		}
		for (int l447 = 0; l447 < 2; l447 = l447 + 1) {
			iRec374[l447] = 0;
		}
		for (int l448 = 0; l448 < 2; l448 = l448 + 1) {
			fRec375[l448] = 0.0;
		}
		for (int l449 = 0; l449 < 2; l449 = l449 + 1) {
			fVec85[l449] = 0.0;
		}
		for (int l450 = 0; l450 < 2; l450 = l450 + 1) {
			iRec376[l450] = 0;
		}
		for (int l451 = 0; l451 < 2; l451 = l451 + 1) {
			fRec377[l451] = 0.0;
		}
		for (int l452 = 0; l452 < 2; l452 = l452 + 1) {
			fVec86[l452] = 0.0;
		}
		for (int l453 = 0; l453 < 2; l453 = l453 + 1) {
			iRec378[l453] = 0;
		}
		for (int l454 = 0; l454 < 2; l454 = l454 + 1) {
			fRec379[l454] = 0.0;
		}
		for (int l455 = 0; l455 < 2; l455 = l455 + 1) {
			fRec380[l455] = 0.0;
		}
		for (int l456 = 0; l456 < 2; l456 = l456 + 1) {
			fVec87[l456] = 0.0;
		}
		for (int l457 = 0; l457 < 2; l457 = l457 + 1) {
			iRec381[l457] = 0;
		}
		for (int l458 = 0; l458 < 2; l458 = l458 + 1) {
			fRec382[l458] = 0.0;
		}
		for (int l459 = 0; l459 < 2; l459 = l459 + 1) {
			fVec88[l459] = 0.0;
		}
		for (int l460 = 0; l460 < 2; l460 = l460 + 1) {
			iRec383[l460] = 0;
		}
		for (int l461 = 0; l461 < 2; l461 = l461 + 1) {
			fRec384[l461] = 0.0;
		}
		for (int l462 = 0; l462 < 2; l462 = l462 + 1) {
			fVec89[l462] = 0.0;
		}
		for (int l463 = 0; l463 < 2; l463 = l463 + 1) {
			iRec385[l463] = 0;
		}
		for (int l464 = 0; l464 < 2; l464 = l464 + 1) {
			fRec386[l464] = 0.0;
		}
		for (int l465 = 0; l465 < 2; l465 = l465 + 1) {
			fVec90[l465] = 0.0;
		}
		for (int l466 = 0; l466 < 2; l466 = l466 + 1) {
			iRec387[l466] = 0;
		}
		for (int l467 = 0; l467 < 2; l467 = l467 + 1) {
			fRec388[l467] = 0.0;
		}
		for (int l468 = 0; l468 < 2; l468 = l468 + 1) {
			fVec91[l468] = 0.0;
		}
		for (int l469 = 0; l469 < 2; l469 = l469 + 1) {
			iRec389[l469] = 0;
		}
		for (int l470 = 0; l470 < 2; l470 = l470 + 1) {
			fRec390[l470] = 0.0;
		}
		for (int l471 = 0; l471 < 2; l471 = l471 + 1) {
			fRec391[l471] = 0.0;
		}
		for (int l472 = 0; l472 < 2; l472 = l472 + 1) {
			fVec92[l472] = 0.0;
		}
		for (int l473 = 0; l473 < 2; l473 = l473 + 1) {
			iRec392[l473] = 0;
		}
		for (int l474 = 0; l474 < 2; l474 = l474 + 1) {
			fRec393[l474] = 0.0;
		}
		for (int l475 = 0; l475 < 2; l475 = l475 + 1) {
			fVec93[l475] = 0.0;
		}
		for (int l476 = 0; l476 < 2; l476 = l476 + 1) {
			iRec394[l476] = 0;
		}
		for (int l477 = 0; l477 < 2; l477 = l477 + 1) {
			fRec395[l477] = 0.0;
		}
		for (int l478 = 0; l478 < 2; l478 = l478 + 1) {
			fVec94[l478] = 0.0;
		}
		for (int l479 = 0; l479 < 2; l479 = l479 + 1) {
			iRec396[l479] = 0;
		}
		for (int l480 = 0; l480 < 2; l480 = l480 + 1) {
			fRec397[l480] = 0.0;
		}
		for (int l481 = 0; l481 < 2; l481 = l481 + 1) {
			fVec95[l481] = 0.0;
		}
		for (int l482 = 0; l482 < 2; l482 = l482 + 1) {
			iRec398[l482] = 0;
		}
		for (int l483 = 0; l483 < 2; l483 = l483 + 1) {
			fRec399[l483] = 0.0;
		}
		for (int l484 = 0; l484 < 2; l484 = l484 + 1) {
			fVec96[l484] = 0.0;
		}
		for (int l485 = 0; l485 < 2; l485 = l485 + 1) {
			iRec400[l485] = 0;
		}
		for (int l486 = 0; l486 < 2; l486 = l486 + 1) {
			fRec401[l486] = 0.0;
		}
		for (int l487 = 0; l487 < 2; l487 = l487 + 1) {
			fVec97[l487] = 0.0;
		}
		for (int l488 = 0; l488 < 2; l488 = l488 + 1) {
			iRec402[l488] = 0;
		}
		for (int l489 = 0; l489 < 2; l489 = l489 + 1) {
			fRec403[l489] = 0.0;
		}
		for (int l490 = 0; l490 < 2; l490 = l490 + 1) {
			fVec98[l490] = 0.0;
		}
		for (int l491 = 0; l491 < 2; l491 = l491 + 1) {
			iRec404[l491] = 0;
		}
		for (int l492 = 0; l492 < 2; l492 = l492 + 1) {
			fRec405[l492] = 0.0;
		}
		for (int l493 = 0; l493 < 2; l493 = l493 + 1) {
			fVec99[l493] = 0.0;
		}
		for (int l494 = 0; l494 < 2; l494 = l494 + 1) {
			iRec406[l494] = 0;
		}
		for (int l495 = 0; l495 < 2; l495 = l495 + 1) {
			fRec407[l495] = 0.0;
		}
		for (int l496 = 0; l496 < 2; l496 = l496 + 1) {
			fVec100[l496] = 0.0;
		}
		for (int l497 = 0; l497 < 2; l497 = l497 + 1) {
			iRec408[l497] = 0;
		}
		for (int l498 = 0; l498 < 2; l498 = l498 + 1) {
			fRec409[l498] = 0.0;
		}
		for (int l499 = 0; l499 < 2; l499 = l499 + 1) {
			fVec101[l499] = 0.0;
		}
		for (int l500 = 0; l500 < 2; l500 = l500 + 1) {
			iRec410[l500] = 0;
		}
		for (int l501 = 0; l501 < 2; l501 = l501 + 1) {
			fRec411[l501] = 0.0;
		}
		for (int l502 = 0; l502 < 2; l502 = l502 + 1) {
			fVec102[l502] = 0.0;
		}
		for (int l503 = 0; l503 < 2; l503 = l503 + 1) {
			iRec412[l503] = 0;
		}
		for (int l504 = 0; l504 < 2; l504 = l504 + 1) {
			fRec413[l504] = 0.0;
		}
		for (int l505 = 0; l505 < 2; l505 = l505 + 1) {
			fVec103[l505] = 0.0;
		}
		for (int l506 = 0; l506 < 2; l506 = l506 + 1) {
			iRec414[l506] = 0;
		}
		for (int l507 = 0; l507 < 2; l507 = l507 + 1) {
			fRec415[l507] = 0.0;
		}
		for (int l508 = 0; l508 < 2; l508 = l508 + 1) {
			fVec104[l508] = 0.0;
		}
		for (int l509 = 0; l509 < 2; l509 = l509 + 1) {
			iRec416[l509] = 0;
		}
		for (int l510 = 0; l510 < 2; l510 = l510 + 1) {
			fRec417[l510] = 0.0;
		}
		for (int l511 = 0; l511 < 2; l511 = l511 + 1) {
			fVec105[l511] = 0.0;
		}
		for (int l512 = 0; l512 < 2; l512 = l512 + 1) {
			iRec418[l512] = 0;
		}
		for (int l513 = 0; l513 < 2; l513 = l513 + 1) {
			fRec419[l513] = 0.0;
		}
		for (int l514 = 0; l514 < 2; l514 = l514 + 1) {
			fVec106[l514] = 0.0;
		}
		for (int l515 = 0; l515 < 2; l515 = l515 + 1) {
			iRec420[l515] = 0;
		}
		for (int l516 = 0; l516 < 2; l516 = l516 + 1) {
			fRec421[l516] = 0.0;
		}
		for (int l517 = 0; l517 < 2; l517 = l517 + 1) {
			fVec107[l517] = 0.0;
		}
		for (int l518 = 0; l518 < 2; l518 = l518 + 1) {
			iRec422[l518] = 0;
		}
		for (int l519 = 0; l519 < 2; l519 = l519 + 1) {
			fRec423[l519] = 0.0;
		}
		for (int l520 = 0; l520 < 2; l520 = l520 + 1) {
			fVec108[l520] = 0.0;
		}
		for (int l521 = 0; l521 < 2; l521 = l521 + 1) {
			iRec424[l521] = 0;
		}
		for (int l522 = 0; l522 < 2; l522 = l522 + 1) {
			fRec425[l522] = 0.0;
		}
		for (int l523 = 0; l523 < 2; l523 = l523 + 1) {
			fVec109[l523] = 0.0;
		}
		for (int l524 = 0; l524 < 2; l524 = l524 + 1) {
			iRec426[l524] = 0;
		}
		for (int l525 = 0; l525 < 2; l525 = l525 + 1) {
			fRec427[l525] = 0.0;
		}
		for (int l526 = 0; l526 < 2; l526 = l526 + 1) {
			fVec110[l526] = 0.0;
		}
		for (int l527 = 0; l527 < 2; l527 = l527 + 1) {
			iRec428[l527] = 0;
		}
		for (int l528 = 0; l528 < 2; l528 = l528 + 1) {
			fRec429[l528] = 0.0;
		}
		for (int l529 = 0; l529 < 2; l529 = l529 + 1) {
			fVec111[l529] = 0.0;
		}
		for (int l530 = 0; l530 < 2; l530 = l530 + 1) {
			iRec430[l530] = 0;
		}
		for (int l531 = 0; l531 < 2; l531 = l531 + 1) {
			fRec431[l531] = 0.0;
		}
		for (int l532 = 0; l532 < 2; l532 = l532 + 1) {
			fVec112[l532] = 0.0;
		}
		for (int l533 = 0; l533 < 2; l533 = l533 + 1) {
			iRec432[l533] = 0;
		}
		for (int l534 = 0; l534 < 2; l534 = l534 + 1) {
			fRec433[l534] = 0.0;
		}
		for (int l535 = 0; l535 < 2; l535 = l535 + 1) {
			fVec113[l535] = 0.0;
		}
		for (int l536 = 0; l536 < 2; l536 = l536 + 1) {
			iRec434[l536] = 0;
		}
		for (int l537 = 0; l537 < 2; l537 = l537 + 1) {
			fRec435[l537] = 0.0;
		}
		for (int l538 = 0; l538 < 2; l538 = l538 + 1) {
			fVec114[l538] = 0.0;
		}
		for (int l539 = 0; l539 < 2; l539 = l539 + 1) {
			iRec436[l539] = 0;
		}
		for (int l540 = 0; l540 < 2; l540 = l540 + 1) {
			fRec437[l540] = 0.0;
		}
		for (int l541 = 0; l541 < 2; l541 = l541 + 1) {
			fVec115[l541] = 0.0;
		}
		for (int l542 = 0; l542 < 2; l542 = l542 + 1) {
			iRec438[l542] = 0;
		}
		for (int l543 = 0; l543 < 2; l543 = l543 + 1) {
			fRec439[l543] = 0.0;
		}
		for (int l544 = 0; l544 < 2; l544 = l544 + 1) {
			fVec116[l544] = 0.0;
		}
		for (int l545 = 0; l545 < 2; l545 = l545 + 1) {
			iRec440[l545] = 0;
		}
		for (int l546 = 0; l546 < 2; l546 = l546 + 1) {
			fRec441[l546] = 0.0;
		}
		for (int l547 = 0; l547 < 2; l547 = l547 + 1) {
			fVec117[l547] = 0.0;
		}
		for (int l548 = 0; l548 < 2; l548 = l548 + 1) {
			iRec442[l548] = 0;
		}
		for (int l549 = 0; l549 < 2; l549 = l549 + 1) {
			fRec443[l549] = 0.0;
		}
		for (int l550 = 0; l550 < 2; l550 = l550 + 1) {
			fVec118[l550] = 0.0;
		}
		for (int l551 = 0; l551 < 2; l551 = l551 + 1) {
			iRec444[l551] = 0;
		}
		for (int l552 = 0; l552 < 2; l552 = l552 + 1) {
			fRec445[l552] = 0.0;
		}
		for (int l553 = 0; l553 < 2; l553 = l553 + 1) {
			fVec119[l553] = 0.0;
		}
		for (int l554 = 0; l554 < 2; l554 = l554 + 1) {
			iRec446[l554] = 0;
		}
		for (int l555 = 0; l555 < 2; l555 = l555 + 1) {
			fRec447[l555] = 0.0;
		}
		for (int l556 = 0; l556 < 2; l556 = l556 + 1) {
			fVec120[l556] = 0.0;
		}
		for (int l557 = 0; l557 < 2; l557 = l557 + 1) {
			iRec448[l557] = 0;
		}
		for (int l558 = 0; l558 < 2; l558 = l558 + 1) {
			fRec449[l558] = 0.0;
		}
		for (int l559 = 0; l559 < 2; l559 = l559 + 1) {
			fVec121[l559] = 0.0;
		}
		for (int l560 = 0; l560 < 2; l560 = l560 + 1) {
			iRec450[l560] = 0;
		}
		for (int l561 = 0; l561 < 2; l561 = l561 + 1) {
			fRec451[l561] = 0.0;
		}
		for (int l562 = 0; l562 < 2; l562 = l562 + 1) {
			fVec122[l562] = 0.0;
		}
		for (int l563 = 0; l563 < 2; l563 = l563 + 1) {
			iRec452[l563] = 0;
		}
		for (int l564 = 0; l564 < 2; l564 = l564 + 1) {
			fRec453[l564] = 0.0;
		}
		for (int l565 = 0; l565 < 2; l565 = l565 + 1) {
			fVec123[l565] = 0.0;
		}
		for (int l566 = 0; l566 < 2; l566 = l566 + 1) {
			iRec454[l566] = 0;
		}
		for (int l567 = 0; l567 < 2; l567 = l567 + 1) {
			fRec455[l567] = 0.0;
		}
		for (int l568 = 0; l568 < 2; l568 = l568 + 1) {
			fVec124[l568] = 0.0;
		}
		for (int l569 = 0; l569 < 2; l569 = l569 + 1) {
			iRec456[l569] = 0;
		}
		for (int l570 = 0; l570 < 2; l570 = l570 + 1) {
			fRec457[l570] = 0.0;
		}
		for (int l571 = 0; l571 < 2; l571 = l571 + 1) {
			fVec125[l571] = 0.0;
		}
		for (int l572 = 0; l572 < 2; l572 = l572 + 1) {
			iRec458[l572] = 0;
		}
		for (int l573 = 0; l573 < 2; l573 = l573 + 1) {
			fRec459[l573] = 0.0;
		}
		for (int l574 = 0; l574 < 2; l574 = l574 + 1) {
			fVec126[l574] = 0.0;
		}
		for (int l575 = 0; l575 < 2; l575 = l575 + 1) {
			iRec460[l575] = 0;
		}
		for (int l576 = 0; l576 < 2; l576 = l576 + 1) {
			fRec461[l576] = 0.0;
		}
		for (int l577 = 0; l577 < 2; l577 = l577 + 1) {
			fVec127[l577] = 0.0;
		}
		for (int l578 = 0; l578 < 2; l578 = l578 + 1) {
			iRec462[l578] = 0;
		}
		for (int l579 = 0; l579 < 2; l579 = l579 + 1) {
			fRec463[l579] = 0.0;
		}
		for (int l580 = 0; l580 < 2; l580 = l580 + 1) {
			fVec128[l580] = 0.0;
		}
		for (int l581 = 0; l581 < 2; l581 = l581 + 1) {
			iRec464[l581] = 0;
		}
		for (int l582 = 0; l582 < 2; l582 = l582 + 1) {
			fRec465[l582] = 0.0;
		}
		for (int l583 = 0; l583 < 2; l583 = l583 + 1) {
			fRec466[l583] = 0.0;
		}
		for (int l584 = 0; l584 < 2; l584 = l584 + 1) {
			fVec129[l584] = 0.0;
		}
		for (int l585 = 0; l585 < 2; l585 = l585 + 1) {
			iRec467[l585] = 0;
		}
		for (int l586 = 0; l586 < 2; l586 = l586 + 1) {
			fRec468[l586] = 0.0;
		}
		for (int l587 = 0; l587 < 2; l587 = l587 + 1) {
			fVec130[l587] = 0.0;
		}
		for (int l588 = 0; l588 < 2; l588 = l588 + 1) {
			iRec469[l588] = 0;
		}
		for (int l589 = 0; l589 < 2; l589 = l589 + 1) {
			fRec470[l589] = 0.0;
		}
		for (int l590 = 0; l590 < 2; l590 = l590 + 1) {
			fVec131[l590] = 0.0;
		}
		for (int l591 = 0; l591 < 2; l591 = l591 + 1) {
			iRec471[l591] = 0;
		}
		for (int l592 = 0; l592 < 2; l592 = l592 + 1) {
			fRec472[l592] = 0.0;
		}
		for (int l593 = 0; l593 < 2; l593 = l593 + 1) {
			fVec132[l593] = 0.0;
		}
		for (int l594 = 0; l594 < 2; l594 = l594 + 1) {
			iRec473[l594] = 0;
		}
		for (int l595 = 0; l595 < 2; l595 = l595 + 1) {
			fRec474[l595] = 0.0;
		}
		for (int l596 = 0; l596 < 2; l596 = l596 + 1) {
			fVec133[l596] = 0.0;
		}
		for (int l597 = 0; l597 < 2; l597 = l597 + 1) {
			iRec475[l597] = 0;
		}
		for (int l598 = 0; l598 < 2; l598 = l598 + 1) {
			fRec476[l598] = 0.0;
		}
		for (int l599 = 0; l599 < 2; l599 = l599 + 1) {
			fVec134[l599] = 0.0;
		}
		for (int l600 = 0; l600 < 2; l600 = l600 + 1) {
			iRec477[l600] = 0;
		}
		for (int l601 = 0; l601 < 2; l601 = l601 + 1) {
			fRec478[l601] = 0.0;
		}
		for (int l602 = 0; l602 < 2; l602 = l602 + 1) {
			fVec135[l602] = 0.0;
		}
		for (int l603 = 0; l603 < 2; l603 = l603 + 1) {
			iRec479[l603] = 0;
		}
		for (int l604 = 0; l604 < 2; l604 = l604 + 1) {
			fRec480[l604] = 0.0;
		}
		for (int l605 = 0; l605 < 2; l605 = l605 + 1) {
			fVec136[l605] = 0.0;
		}
		for (int l606 = 0; l606 < 2; l606 = l606 + 1) {
			iRec481[l606] = 0;
		}
		for (int l607 = 0; l607 < 2; l607 = l607 + 1) {
			fRec482[l607] = 0.0;
		}
		for (int l608 = 0; l608 < 2; l608 = l608 + 1) {
			fVec137[l608] = 0.0;
		}
		for (int l609 = 0; l609 < 2; l609 = l609 + 1) {
			iRec483[l609] = 0;
		}
		for (int l610 = 0; l610 < 2; l610 = l610 + 1) {
			fRec484[l610] = 0.0;
		}
		for (int l611 = 0; l611 < 2; l611 = l611 + 1) {
			fVec138[l611] = 0.0;
		}
		for (int l612 = 0; l612 < 2; l612 = l612 + 1) {
			iRec485[l612] = 0;
		}
		for (int l613 = 0; l613 < 2; l613 = l613 + 1) {
			fRec486[l613] = 0.0;
		}
		for (int l614 = 0; l614 < 2; l614 = l614 + 1) {
			fVec139[l614] = 0.0;
		}
		for (int l615 = 0; l615 < 2; l615 = l615 + 1) {
			iRec487[l615] = 0;
		}
		for (int l616 = 0; l616 < 2; l616 = l616 + 1) {
			fRec488[l616] = 0.0;
		}
		for (int l617 = 0; l617 < 2; l617 = l617 + 1) {
			fVec140[l617] = 0.0;
		}
		for (int l618 = 0; l618 < 2; l618 = l618 + 1) {
			iRec489[l618] = 0;
		}
		for (int l619 = 0; l619 < 2; l619 = l619 + 1) {
			fRec490[l619] = 0.0;
		}
		for (int l620 = 0; l620 < 2; l620 = l620 + 1) {
			fVec141[l620] = 0.0;
		}
		for (int l621 = 0; l621 < 2; l621 = l621 + 1) {
			iRec491[l621] = 0;
		}
		for (int l622 = 0; l622 < 2; l622 = l622 + 1) {
			fRec492[l622] = 0.0;
		}
		for (int l623 = 0; l623 < 2; l623 = l623 + 1) {
			fRec493[l623] = 0.0;
		}
		for (int l624 = 0; l624 < 2; l624 = l624 + 1) {
			fVec142[l624] = 0.0;
		}
		for (int l625 = 0; l625 < 2; l625 = l625 + 1) {
			iRec494[l625] = 0;
		}
		for (int l626 = 0; l626 < 2; l626 = l626 + 1) {
			fRec495[l626] = 0.0;
		}
		for (int l627 = 0; l627 < 2; l627 = l627 + 1) {
			fVec143[l627] = 0.0;
		}
		for (int l628 = 0; l628 < 2; l628 = l628 + 1) {
			iRec496[l628] = 0;
		}
		for (int l629 = 0; l629 < 2; l629 = l629 + 1) {
			fRec497[l629] = 0.0;
		}
		for (int l630 = 0; l630 < 2; l630 = l630 + 1) {
			fVec144[l630] = 0.0;
		}
		for (int l631 = 0; l631 < 2; l631 = l631 + 1) {
			iRec498[l631] = 0;
		}
		for (int l632 = 0; l632 < 2; l632 = l632 + 1) {
			fRec499[l632] = 0.0;
		}
		for (int l633 = 0; l633 < 2; l633 = l633 + 1) {
			fVec145[l633] = 0.0;
		}
		for (int l634 = 0; l634 < 2; l634 = l634 + 1) {
			iRec500[l634] = 0;
		}
		for (int l635 = 0; l635 < 2; l635 = l635 + 1) {
			fRec501[l635] = 0.0;
		}
		for (int l636 = 0; l636 < 2; l636 = l636 + 1) {
			fVec146[l636] = 0.0;
		}
		for (int l637 = 0; l637 < 2; l637 = l637 + 1) {
			iRec502[l637] = 0;
		}
		for (int l638 = 0; l638 < 2; l638 = l638 + 1) {
			fRec503[l638] = 0.0;
		}
		for (int l639 = 0; l639 < 2; l639 = l639 + 1) {
			fVec147[l639] = 0.0;
		}
		for (int l640 = 0; l640 < 2; l640 = l640 + 1) {
			iRec504[l640] = 0;
		}
		for (int l641 = 0; l641 < 2; l641 = l641 + 1) {
			fRec505[l641] = 0.0;
		}
		for (int l642 = 0; l642 < 2; l642 = l642 + 1) {
			fVec148[l642] = 0.0;
		}
		for (int l643 = 0; l643 < 2; l643 = l643 + 1) {
			iRec506[l643] = 0;
		}
		for (int l644 = 0; l644 < 2; l644 = l644 + 1) {
			fRec507[l644] = 0.0;
		}
		for (int l645 = 0; l645 < 2; l645 = l645 + 1) {
			fVec149[l645] = 0.0;
		}
		for (int l646 = 0; l646 < 2; l646 = l646 + 1) {
			iRec508[l646] = 0;
		}
		for (int l647 = 0; l647 < 2; l647 = l647 + 1) {
			fRec509[l647] = 0.0;
		}
		for (int l648 = 0; l648 < 2; l648 = l648 + 1) {
			fVec150[l648] = 0.0;
		}
		for (int l649 = 0; l649 < 2; l649 = l649 + 1) {
			iRec510[l649] = 0;
		}
		for (int l650 = 0; l650 < 2; l650 = l650 + 1) {
			fRec511[l650] = 0.0;
		}
		for (int l651 = 0; l651 < 2; l651 = l651 + 1) {
			fVec151[l651] = 0.0;
		}
		for (int l652 = 0; l652 < 2; l652 = l652 + 1) {
			iRec512[l652] = 0;
		}
		for (int l653 = 0; l653 < 2; l653 = l653 + 1) {
			fRec513[l653] = 0.0;
		}
		for (int l654 = 0; l654 < 2; l654 = l654 + 1) {
			fVec152[l654] = 0.0;
		}
		for (int l655 = 0; l655 < 2; l655 = l655 + 1) {
			iRec514[l655] = 0;
		}
		for (int l656 = 0; l656 < 2; l656 = l656 + 1) {
			fRec515[l656] = 0.0;
		}
		for (int l657 = 0; l657 < 2; l657 = l657 + 1) {
			fVec153[l657] = 0.0;
		}
		for (int l658 = 0; l658 < 2; l658 = l658 + 1) {
			iRec516[l658] = 0;
		}
		for (int l659 = 0; l659 < 2; l659 = l659 + 1) {
			fRec517[l659] = 0.0;
		}
		for (int l660 = 0; l660 < 2; l660 = l660 + 1) {
			fVec154[l660] = 0.0;
		}
		for (int l661 = 0; l661 < 2; l661 = l661 + 1) {
			iRec518[l661] = 0;
		}
		for (int l662 = 0; l662 < 2; l662 = l662 + 1) {
			fRec519[l662] = 0.0;
		}
		for (int l663 = 0; l663 < 2; l663 = l663 + 1) {
			fVec155[l663] = 0.0;
		}
		for (int l664 = 0; l664 < 2; l664 = l664 + 1) {
			iRec520[l664] = 0;
		}
		for (int l665 = 0; l665 < 2; l665 = l665 + 1) {
			fRec521[l665] = 0.0;
		}
		for (int l666 = 0; l666 < 2; l666 = l666 + 1) {
			fVec156[l666] = 0.0;
		}
		for (int l667 = 0; l667 < 2; l667 = l667 + 1) {
			iRec522[l667] = 0;
		}
		for (int l668 = 0; l668 < 2; l668 = l668 + 1) {
			fRec523[l668] = 0.0;
		}
		for (int l669 = 0; l669 < 2; l669 = l669 + 1) {
			fVec157[l669] = 0.0;
		}
		for (int l670 = 0; l670 < 2; l670 = l670 + 1) {
			iRec524[l670] = 0;
		}
		for (int l671 = 0; l671 < 2; l671 = l671 + 1) {
			fRec525[l671] = 0.0;
		}
		for (int l672 = 0; l672 < 2; l672 = l672 + 1) {
			fRec526[l672] = 0.0;
		}
		for (int l673 = 0; l673 < 2; l673 = l673 + 1) {
			fVec158[l673] = 0.0;
		}
		for (int l674 = 0; l674 < 2; l674 = l674 + 1) {
			iRec527[l674] = 0;
		}
		for (int l675 = 0; l675 < 2; l675 = l675 + 1) {
			fRec528[l675] = 0.0;
		}
		for (int l676 = 0; l676 < 2; l676 = l676 + 1) {
			fVec159[l676] = 0.0;
		}
		for (int l677 = 0; l677 < 2; l677 = l677 + 1) {
			iRec529[l677] = 0;
		}
		for (int l678 = 0; l678 < 2; l678 = l678 + 1) {
			fRec530[l678] = 0.0;
		}
		for (int l679 = 0; l679 < 2; l679 = l679 + 1) {
			fVec160[l679] = 0.0;
		}
		for (int l680 = 0; l680 < 2; l680 = l680 + 1) {
			iRec531[l680] = 0;
		}
		for (int l681 = 0; l681 < 2; l681 = l681 + 1) {
			fRec532[l681] = 0.0;
		}
		for (int l682 = 0; l682 < 2; l682 = l682 + 1) {
			fRec533[l682] = 0.0;
		}
		for (int l683 = 0; l683 < 2; l683 = l683 + 1) {
			fVec161[l683] = 0.0;
		}
		for (int l684 = 0; l684 < 2; l684 = l684 + 1) {
			iRec534[l684] = 0;
		}
		for (int l685 = 0; l685 < 2; l685 = l685 + 1) {
			fRec535[l685] = 0.0;
		}
		for (int l686 = 0; l686 < 2; l686 = l686 + 1) {
			fVec162[l686] = 0.0;
		}
		for (int l687 = 0; l687 < 2; l687 = l687 + 1) {
			iRec536[l687] = 0;
		}
		for (int l688 = 0; l688 < 2; l688 = l688 + 1) {
			fRec537[l688] = 0.0;
		}
		for (int l689 = 0; l689 < 2; l689 = l689 + 1) {
			fRec538[l689] = 0.0;
		}
		for (int l690 = 0; l690 < 2; l690 = l690 + 1) {
			fVec163[l690] = 0.0;
		}
		for (int l691 = 0; l691 < 2; l691 = l691 + 1) {
			iRec539[l691] = 0;
		}
		for (int l692 = 0; l692 < 2; l692 = l692 + 1) {
			fRec540[l692] = 0.0;
		}
		for (int l693 = 0; l693 < 2; l693 = l693 + 1) {
			fVec164[l693] = 0.0;
		}
		for (int l694 = 0; l694 < 2; l694 = l694 + 1) {
			iRec541[l694] = 0;
		}
		for (int l695 = 0; l695 < 2; l695 = l695 + 1) {
			fRec542[l695] = 0.0;
		}
		for (int l696 = 0; l696 < 2; l696 = l696 + 1) {
			fVec165[l696] = 0.0;
		}
		for (int l697 = 0; l697 < 2; l697 = l697 + 1) {
			iRec543[l697] = 0;
		}
		for (int l698 = 0; l698 < 2; l698 = l698 + 1) {
			fRec544[l698] = 0.0;
		}
		for (int l699 = 0; l699 < 2; l699 = l699 + 1) {
			fVec166[l699] = 0.0;
		}
		for (int l700 = 0; l700 < 2; l700 = l700 + 1) {
			iRec545[l700] = 0;
		}
		for (int l701 = 0; l701 < 2; l701 = l701 + 1) {
			fRec546[l701] = 0.0;
		}
		for (int l702 = 0; l702 < 2; l702 = l702 + 1) {
			fVec167[l702] = 0.0;
		}
		for (int l703 = 0; l703 < 2; l703 = l703 + 1) {
			iRec547[l703] = 0;
		}
		for (int l704 = 0; l704 < 2; l704 = l704 + 1) {
			fRec548[l704] = 0.0;
		}
		for (int l705 = 0; l705 < 2; l705 = l705 + 1) {
			fVec168[l705] = 0.0;
		}
		for (int l706 = 0; l706 < 2; l706 = l706 + 1) {
			iRec549[l706] = 0;
		}
		for (int l707 = 0; l707 < 2; l707 = l707 + 1) {
			fRec550[l707] = 0.0;
		}
		for (int l708 = 0; l708 < 2; l708 = l708 + 1) {
			fVec169[l708] = 0.0;
		}
		for (int l709 = 0; l709 < 2; l709 = l709 + 1) {
			iRec551[l709] = 0;
		}
		for (int l710 = 0; l710 < 2; l710 = l710 + 1) {
			fRec552[l710] = 0.0;
		}
		for (int l711 = 0; l711 < 2; l711 = l711 + 1) {
			fVec170[l711] = 0.0;
		}
		for (int l712 = 0; l712 < 2; l712 = l712 + 1) {
			iRec553[l712] = 0;
		}
		for (int l713 = 0; l713 < 2; l713 = l713 + 1) {
			fRec554[l713] = 0.0;
		}
		for (int l714 = 0; l714 < 2; l714 = l714 + 1) {
			fVec171[l714] = 0.0;
		}
		for (int l715 = 0; l715 < 2; l715 = l715 + 1) {
			iRec555[l715] = 0;
		}
		for (int l716 = 0; l716 < 2; l716 = l716 + 1) {
			fRec556[l716] = 0.0;
		}
		for (int l717 = 0; l717 < 2; l717 = l717 + 1) {
			fVec172[l717] = 0.0;
		}
		for (int l718 = 0; l718 < 2; l718 = l718 + 1) {
			iRec557[l718] = 0;
		}
		for (int l719 = 0; l719 < 2; l719 = l719 + 1) {
			fRec558[l719] = 0.0;
		}
		for (int l720 = 0; l720 < 2; l720 = l720 + 1) {
			fVec173[l720] = 0.0;
		}
		for (int l721 = 0; l721 < 2; l721 = l721 + 1) {
			iRec559[l721] = 0;
		}
		for (int l722 = 0; l722 < 2; l722 = l722 + 1) {
			fRec560[l722] = 0.0;
		}
		for (int l723 = 0; l723 < 2; l723 = l723 + 1) {
			fVec174[l723] = 0.0;
		}
		for (int l724 = 0; l724 < 2; l724 = l724 + 1) {
			iRec561[l724] = 0;
		}
		for (int l725 = 0; l725 < 2; l725 = l725 + 1) {
			fRec562[l725] = 0.0;
		}
		for (int l726 = 0; l726 < 2; l726 = l726 + 1) {
			fVec175[l726] = 0.0;
		}
		for (int l727 = 0; l727 < 2; l727 = l727 + 1) {
			iRec563[l727] = 0;
		}
		for (int l728 = 0; l728 < 2; l728 = l728 + 1) {
			fRec564[l728] = 0.0;
		}
		for (int l729 = 0; l729 < 2; l729 = l729 + 1) {
			fVec176[l729] = 0.0;
		}
		for (int l730 = 0; l730 < 2; l730 = l730 + 1) {
			iRec565[l730] = 0;
		}
		for (int l731 = 0; l731 < 2; l731 = l731 + 1) {
			fRec566[l731] = 0.0;
		}
		for (int l732 = 0; l732 < 2; l732 = l732 + 1) {
			fVec177[l732] = 0.0;
		}
		for (int l733 = 0; l733 < 2; l733 = l733 + 1) {
			iRec567[l733] = 0;
		}
		for (int l734 = 0; l734 < 2; l734 = l734 + 1) {
			fRec568[l734] = 0.0;
		}
		for (int l735 = 0; l735 < 2; l735 = l735 + 1) {
			fVec178[l735] = 0.0;
		}
		for (int l736 = 0; l736 < 2; l736 = l736 + 1) {
			iRec569[l736] = 0;
		}
		for (int l737 = 0; l737 < 2; l737 = l737 + 1) {
			fRec570[l737] = 0.0;
		}
		for (int l738 = 0; l738 < 2; l738 = l738 + 1) {
			fVec179[l738] = 0.0;
		}
		for (int l739 = 0; l739 < 2; l739 = l739 + 1) {
			iRec571[l739] = 0;
		}
		for (int l740 = 0; l740 < 2; l740 = l740 + 1) {
			fRec572[l740] = 0.0;
		}
		for (int l741 = 0; l741 < 2; l741 = l741 + 1) {
			fVec180[l741] = 0.0;
		}
		for (int l742 = 0; l742 < 2; l742 = l742 + 1) {
			iRec573[l742] = 0;
		}
		for (int l743 = 0; l743 < 2; l743 = l743 + 1) {
			fRec574[l743] = 0.0;
		}
		for (int l744 = 0; l744 < 2; l744 = l744 + 1) {
			fVec181[l744] = 0.0;
		}
		for (int l745 = 0; l745 < 2; l745 = l745 + 1) {
			iRec575[l745] = 0;
		}
		for (int l746 = 0; l746 < 2; l746 = l746 + 1) {
			fRec576[l746] = 0.0;
		}
		for (int l747 = 0; l747 < 2; l747 = l747 + 1) {
			fVec182[l747] = 0.0;
		}
		for (int l748 = 0; l748 < 2; l748 = l748 + 1) {
			iRec577[l748] = 0;
		}
		for (int l749 = 0; l749 < 2; l749 = l749 + 1) {
			fRec578[l749] = 0.0;
		}
		for (int l750 = 0; l750 < 2; l750 = l750 + 1) {
			fVec183[l750] = 0.0;
		}
		for (int l751 = 0; l751 < 2; l751 = l751 + 1) {
			iRec579[l751] = 0;
		}
		for (int l752 = 0; l752 < 2; l752 = l752 + 1) {
			fRec580[l752] = 0.0;
		}
		for (int l753 = 0; l753 < 2; l753 = l753 + 1) {
			fVec184[l753] = 0.0;
		}
		for (int l754 = 0; l754 < 2; l754 = l754 + 1) {
			iRec581[l754] = 0;
		}
		for (int l755 = 0; l755 < 2; l755 = l755 + 1) {
			fRec582[l755] = 0.0;
		}
		for (int l756 = 0; l756 < 2; l756 = l756 + 1) {
			fVec185[l756] = 0.0;
		}
		for (int l757 = 0; l757 < 2; l757 = l757 + 1) {
			iRec583[l757] = 0;
		}
		for (int l758 = 0; l758 < 2; l758 = l758 + 1) {
			fRec584[l758] = 0.0;
		}
		for (int l759 = 0; l759 < 2; l759 = l759 + 1) {
			fVec186[l759] = 0.0;
		}
		for (int l760 = 0; l760 < 2; l760 = l760 + 1) {
			iRec585[l760] = 0;
		}
		for (int l761 = 0; l761 < 2; l761 = l761 + 1) {
			fRec586[l761] = 0.0;
		}
		for (int l762 = 0; l762 < 2; l762 = l762 + 1) {
			fVec187[l762] = 0.0;
		}
		for (int l763 = 0; l763 < 2; l763 = l763 + 1) {
			iRec587[l763] = 0;
		}
		for (int l764 = 0; l764 < 2; l764 = l764 + 1) {
			fRec588[l764] = 0.0;
		}
		for (int l765 = 0; l765 < 2; l765 = l765 + 1) {
			fVec188[l765] = 0.0;
		}
		for (int l766 = 0; l766 < 2; l766 = l766 + 1) {
			iRec589[l766] = 0;
		}
		for (int l767 = 0; l767 < 2; l767 = l767 + 1) {
			fRec590[l767] = 0.0;
		}
		for (int l768 = 0; l768 < 2; l768 = l768 + 1) {
			fVec189[l768] = 0.0;
		}
		for (int l769 = 0; l769 < 2; l769 = l769 + 1) {
			iRec591[l769] = 0;
		}
		for (int l770 = 0; l770 < 2; l770 = l770 + 1) {
			fRec592[l770] = 0.0;
		}
		for (int l771 = 0; l771 < 2; l771 = l771 + 1) {
			fRec593[l771] = 0.0;
		}
		for (int l772 = 0; l772 < 2; l772 = l772 + 1) {
			fVec190[l772] = 0.0;
		}
		for (int l773 = 0; l773 < 2; l773 = l773 + 1) {
			iRec594[l773] = 0;
		}
		for (int l774 = 0; l774 < 2; l774 = l774 + 1) {
			fRec595[l774] = 0.0;
		}
		for (int l775 = 0; l775 < 2; l775 = l775 + 1) {
			fVec191[l775] = 0.0;
		}
		for (int l776 = 0; l776 < 2; l776 = l776 + 1) {
			iRec596[l776] = 0;
		}
		for (int l777 = 0; l777 < 2; l777 = l777 + 1) {
			fRec597[l777] = 0.0;
		}
		for (int l778 = 0; l778 < 2; l778 = l778 + 1) {
			fVec192[l778] = 0.0;
		}
		for (int l779 = 0; l779 < 2; l779 = l779 + 1) {
			iRec598[l779] = 0;
		}
		for (int l780 = 0; l780 < 2; l780 = l780 + 1) {
			fRec599[l780] = 0.0;
		}
		for (int l781 = 0; l781 < 2; l781 = l781 + 1) {
			fVec193[l781] = 0.0;
		}
		for (int l782 = 0; l782 < 2; l782 = l782 + 1) {
			iRec600[l782] = 0;
		}
		for (int l783 = 0; l783 < 2; l783 = l783 + 1) {
			fRec601[l783] = 0.0;
		}
		for (int l784 = 0; l784 < 2; l784 = l784 + 1) {
			fVec194[l784] = 0.0;
		}
		for (int l785 = 0; l785 < 2; l785 = l785 + 1) {
			iRec602[l785] = 0;
		}
		for (int l786 = 0; l786 < 2; l786 = l786 + 1) {
			fRec603[l786] = 0.0;
		}
		for (int l787 = 0; l787 < 2; l787 = l787 + 1) {
			fVec195[l787] = 0.0;
		}
		for (int l788 = 0; l788 < 2; l788 = l788 + 1) {
			iRec604[l788] = 0;
		}
		for (int l789 = 0; l789 < 2; l789 = l789 + 1) {
			fRec605[l789] = 0.0;
		}
		for (int l790 = 0; l790 < 2; l790 = l790 + 1) {
			fVec196[l790] = 0.0;
		}
		for (int l791 = 0; l791 < 2; l791 = l791 + 1) {
			iRec606[l791] = 0;
		}
		for (int l792 = 0; l792 < 2; l792 = l792 + 1) {
			fRec607[l792] = 0.0;
		}
		for (int l793 = 0; l793 < 2; l793 = l793 + 1) {
			fVec197[l793] = 0.0;
		}
		for (int l794 = 0; l794 < 2; l794 = l794 + 1) {
			iRec608[l794] = 0;
		}
		for (int l795 = 0; l795 < 2; l795 = l795 + 1) {
			fRec609[l795] = 0.0;
		}
		for (int l796 = 0; l796 < 2; l796 = l796 + 1) {
			fVec198[l796] = 0.0;
		}
		for (int l797 = 0; l797 < 2; l797 = l797 + 1) {
			iRec610[l797] = 0;
		}
		for (int l798 = 0; l798 < 2; l798 = l798 + 1) {
			fRec611[l798] = 0.0;
		}
		for (int l799 = 0; l799 < 2; l799 = l799 + 1) {
			fVec199[l799] = 0.0;
		}
		for (int l800 = 0; l800 < 2; l800 = l800 + 1) {
			iRec612[l800] = 0;
		}
		for (int l801 = 0; l801 < 2; l801 = l801 + 1) {
			fRec613[l801] = 0.0;
		}
		for (int l802 = 0; l802 < 2; l802 = l802 + 1) {
			fVec200[l802] = 0.0;
		}
		for (int l803 = 0; l803 < 2; l803 = l803 + 1) {
			iRec614[l803] = 0;
		}
		for (int l804 = 0; l804 < 2; l804 = l804 + 1) {
			fRec615[l804] = 0.0;
		}
		for (int l805 = 0; l805 < 2; l805 = l805 + 1) {
			fVec201[l805] = 0.0;
		}
		for (int l806 = 0; l806 < 2; l806 = l806 + 1) {
			iRec616[l806] = 0;
		}
		for (int l807 = 0; l807 < 2; l807 = l807 + 1) {
			fRec617[l807] = 0.0;
		}
		for (int l808 = 0; l808 < 2; l808 = l808 + 1) {
			fVec202[l808] = 0.0;
		}
		for (int l809 = 0; l809 < 2; l809 = l809 + 1) {
			iRec618[l809] = 0;
		}
		for (int l810 = 0; l810 < 2; l810 = l810 + 1) {
			fRec619[l810] = 0.0;
		}
		for (int l811 = 0; l811 < 2; l811 = l811 + 1) {
			fVec203[l811] = 0.0;
		}
		for (int l812 = 0; l812 < 2; l812 = l812 + 1) {
			iRec620[l812] = 0;
		}
		for (int l813 = 0; l813 < 2; l813 = l813 + 1) {
			fRec621[l813] = 0.0;
		}
		for (int l814 = 0; l814 < 2; l814 = l814 + 1) {
			fVec204[l814] = 0.0;
		}
		for (int l815 = 0; l815 < 2; l815 = l815 + 1) {
			iRec622[l815] = 0;
		}
		for (int l816 = 0; l816 < 2; l816 = l816 + 1) {
			fRec623[l816] = 0.0;
		}
		for (int l817 = 0; l817 < 2; l817 = l817 + 1) {
			fVec205[l817] = 0.0;
		}
		for (int l818 = 0; l818 < 2; l818 = l818 + 1) {
			iRec624[l818] = 0;
		}
		for (int l819 = 0; l819 < 2; l819 = l819 + 1) {
			fRec625[l819] = 0.0;
		}
		for (int l820 = 0; l820 < 2; l820 = l820 + 1) {
			fVec206[l820] = 0.0;
		}
		for (int l821 = 0; l821 < 2; l821 = l821 + 1) {
			iRec626[l821] = 0;
		}
		for (int l822 = 0; l822 < 2; l822 = l822 + 1) {
			fRec627[l822] = 0.0;
		}
		for (int l823 = 0; l823 < 2; l823 = l823 + 1) {
			fVec207[l823] = 0.0;
		}
		for (int l824 = 0; l824 < 2; l824 = l824 + 1) {
			iRec628[l824] = 0;
		}
		for (int l825 = 0; l825 < 2; l825 = l825 + 1) {
			fRec629[l825] = 0.0;
		}
		for (int l826 = 0; l826 < 2; l826 = l826 + 1) {
			fVec208[l826] = 0.0;
		}
		for (int l827 = 0; l827 < 2; l827 = l827 + 1) {
			iRec630[l827] = 0;
		}
		for (int l828 = 0; l828 < 2; l828 = l828 + 1) {
			fRec631[l828] = 0.0;
		}
		for (int l829 = 0; l829 < 2; l829 = l829 + 1) {
			fRec632[l829] = 0.0;
		}
		for (int l830 = 0; l830 < 2; l830 = l830 + 1) {
			fVec209[l830] = 0.0;
		}
		for (int l831 = 0; l831 < 2; l831 = l831 + 1) {
			iRec633[l831] = 0;
		}
		for (int l832 = 0; l832 < 2; l832 = l832 + 1) {
			fRec634[l832] = 0.0;
		}
		for (int l833 = 0; l833 < 2; l833 = l833 + 1) {
			fVec210[l833] = 0.0;
		}
		for (int l834 = 0; l834 < 2; l834 = l834 + 1) {
			iRec635[l834] = 0;
		}
		for (int l835 = 0; l835 < 2; l835 = l835 + 1) {
			fRec636[l835] = 0.0;
		}
		for (int l836 = 0; l836 < 2; l836 = l836 + 1) {
			fRec637[l836] = 0.0;
		}
		for (int l837 = 0; l837 < 2; l837 = l837 + 1) {
			fVec211[l837] = 0.0;
		}
		for (int l838 = 0; l838 < 2; l838 = l838 + 1) {
			iRec638[l838] = 0;
		}
		for (int l839 = 0; l839 < 2; l839 = l839 + 1) {
			fRec639[l839] = 0.0;
		}
		for (int l840 = 0; l840 < 2; l840 = l840 + 1) {
			fRec640[l840] = 0.0;
		}
		for (int l841 = 0; l841 < 2; l841 = l841 + 1) {
			fVec212[l841] = 0.0;
		}
		for (int l842 = 0; l842 < 2; l842 = l842 + 1) {
			iRec641[l842] = 0;
		}
		for (int l843 = 0; l843 < 2; l843 = l843 + 1) {
			fRec642[l843] = 0.0;
		}
		for (int l844 = 0; l844 < 2; l844 = l844 + 1) {
			fVec213[l844] = 0.0;
		}
		for (int l845 = 0; l845 < 2; l845 = l845 + 1) {
			iRec643[l845] = 0;
		}
		for (int l846 = 0; l846 < 2; l846 = l846 + 1) {
			fRec644[l846] = 0.0;
		}
		for (int l847 = 0; l847 < 2; l847 = l847 + 1) {
			fRec645[l847] = 0.0;
		}
		for (int l848 = 0; l848 < 2; l848 = l848 + 1) {
			fVec214[l848] = 0.0;
		}
		for (int l849 = 0; l849 < 2; l849 = l849 + 1) {
			iRec646[l849] = 0;
		}
		for (int l850 = 0; l850 < 2; l850 = l850 + 1) {
			fRec647[l850] = 0.0;
		}
		for (int l851 = 0; l851 < 2; l851 = l851 + 1) {
			fVec215[l851] = 0.0;
		}
		for (int l852 = 0; l852 < 2; l852 = l852 + 1) {
			iRec648[l852] = 0;
		}
		for (int l853 = 0; l853 < 2; l853 = l853 + 1) {
			fRec649[l853] = 0.0;
		}
		for (int l854 = 0; l854 < 2; l854 = l854 + 1) {
			fVec216[l854] = 0.0;
		}
		for (int l855 = 0; l855 < 2; l855 = l855 + 1) {
			iRec650[l855] = 0;
		}
		for (int l856 = 0; l856 < 2; l856 = l856 + 1) {
			fRec651[l856] = 0.0;
		}
		for (int l857 = 0; l857 < 2; l857 = l857 + 1) {
			fVec217[l857] = 0.0;
		}
		for (int l858 = 0; l858 < 2; l858 = l858 + 1) {
			iRec652[l858] = 0;
		}
		for (int l859 = 0; l859 < 2; l859 = l859 + 1) {
			fRec653[l859] = 0.0;
		}
		for (int l860 = 0; l860 < 2; l860 = l860 + 1) {
			fVec218[l860] = 0.0;
		}
		for (int l861 = 0; l861 < 2; l861 = l861 + 1) {
			iRec654[l861] = 0;
		}
		for (int l862 = 0; l862 < 2; l862 = l862 + 1) {
			fRec655[l862] = 0.0;
		}
		for (int l863 = 0; l863 < 2; l863 = l863 + 1) {
			fVec219[l863] = 0.0;
		}
		for (int l864 = 0; l864 < 2; l864 = l864 + 1) {
			iRec656[l864] = 0;
		}
		for (int l865 = 0; l865 < 2; l865 = l865 + 1) {
			fRec657[l865] = 0.0;
		}
		for (int l866 = 0; l866 < 2; l866 = l866 + 1) {
			fVec220[l866] = 0.0;
		}
		for (int l867 = 0; l867 < 2; l867 = l867 + 1) {
			iRec658[l867] = 0;
		}
		for (int l868 = 0; l868 < 2; l868 = l868 + 1) {
			fRec659[l868] = 0.0;
		}
		for (int l869 = 0; l869 < 2; l869 = l869 + 1) {
			fVec221[l869] = 0.0;
		}
		for (int l870 = 0; l870 < 2; l870 = l870 + 1) {
			iRec660[l870] = 0;
		}
		for (int l871 = 0; l871 < 2; l871 = l871 + 1) {
			fRec661[l871] = 0.0;
		}
		for (int l872 = 0; l872 < 2; l872 = l872 + 1) {
			fVec222[l872] = 0.0;
		}
		for (int l873 = 0; l873 < 2; l873 = l873 + 1) {
			iRec662[l873] = 0;
		}
		for (int l874 = 0; l874 < 2; l874 = l874 + 1) {
			fRec663[l874] = 0.0;
		}
		for (int l875 = 0; l875 < 2; l875 = l875 + 1) {
			fVec223[l875] = 0.0;
		}
		for (int l876 = 0; l876 < 2; l876 = l876 + 1) {
			iRec664[l876] = 0;
		}
		for (int l877 = 0; l877 < 2; l877 = l877 + 1) {
			fRec665[l877] = 0.0;
		}
		for (int l878 = 0; l878 < 2; l878 = l878 + 1) {
			fVec224[l878] = 0.0;
		}
		for (int l879 = 0; l879 < 2; l879 = l879 + 1) {
			iRec666[l879] = 0;
		}
		for (int l880 = 0; l880 < 2; l880 = l880 + 1) {
			fRec667[l880] = 0.0;
		}
		for (int l881 = 0; l881 < 2; l881 = l881 + 1) {
			fVec225[l881] = 0.0;
		}
		for (int l882 = 0; l882 < 2; l882 = l882 + 1) {
			iRec668[l882] = 0;
		}
		for (int l883 = 0; l883 < 2; l883 = l883 + 1) {
			fRec669[l883] = 0.0;
		}
		for (int l884 = 0; l884 < 2; l884 = l884 + 1) {
			fVec226[l884] = 0.0;
		}
		for (int l885 = 0; l885 < 2; l885 = l885 + 1) {
			iRec670[l885] = 0;
		}
		for (int l886 = 0; l886 < 2; l886 = l886 + 1) {
			fRec671[l886] = 0.0;
		}
		for (int l887 = 0; l887 < 2; l887 = l887 + 1) {
			fVec227[l887] = 0.0;
		}
		for (int l888 = 0; l888 < 2; l888 = l888 + 1) {
			iRec672[l888] = 0;
		}
		for (int l889 = 0; l889 < 2; l889 = l889 + 1) {
			fRec673[l889] = 0.0;
		}
		for (int l890 = 0; l890 < 2; l890 = l890 + 1) {
			fVec228[l890] = 0.0;
		}
		for (int l891 = 0; l891 < 2; l891 = l891 + 1) {
			iRec674[l891] = 0;
		}
		for (int l892 = 0; l892 < 2; l892 = l892 + 1) {
			fRec675[l892] = 0.0;
		}
		for (int l893 = 0; l893 < 2; l893 = l893 + 1) {
			fVec229[l893] = 0.0;
		}
		for (int l894 = 0; l894 < 2; l894 = l894 + 1) {
			iRec676[l894] = 0;
		}
		for (int l895 = 0; l895 < 2; l895 = l895 + 1) {
			fRec677[l895] = 0.0;
		}
		for (int l896 = 0; l896 < 2; l896 = l896 + 1) {
			fVec230[l896] = 0.0;
		}
		for (int l897 = 0; l897 < 2; l897 = l897 + 1) {
			iRec678[l897] = 0;
		}
		for (int l898 = 0; l898 < 2; l898 = l898 + 1) {
			fRec679[l898] = 0.0;
		}
		for (int l899 = 0; l899 < 2; l899 = l899 + 1) {
			fVec231[l899] = 0.0;
		}
		for (int l900 = 0; l900 < 2; l900 = l900 + 1) {
			iRec680[l900] = 0;
		}
		for (int l901 = 0; l901 < 2; l901 = l901 + 1) {
			fRec681[l901] = 0.0;
		}
		for (int l902 = 0; l902 < 2; l902 = l902 + 1) {
			fVec232[l902] = 0.0;
		}
		for (int l903 = 0; l903 < 2; l903 = l903 + 1) {
			iRec682[l903] = 0;
		}
		for (int l904 = 0; l904 < 2; l904 = l904 + 1) {
			fRec683[l904] = 0.0;
		}
		for (int l905 = 0; l905 < 2; l905 = l905 + 1) {
			fVec233[l905] = 0.0;
		}
		for (int l906 = 0; l906 < 2; l906 = l906 + 1) {
			iRec684[l906] = 0;
		}
		for (int l907 = 0; l907 < 2; l907 = l907 + 1) {
			fRec685[l907] = 0.0;
		}
		for (int l908 = 0; l908 < 2; l908 = l908 + 1) {
			fVec234[l908] = 0.0;
		}
		for (int l909 = 0; l909 < 2; l909 = l909 + 1) {
			iRec686[l909] = 0;
		}
		for (int l910 = 0; l910 < 2; l910 = l910 + 1) {
			fRec687[l910] = 0.0;
		}
		for (int l911 = 0; l911 < 2; l911 = l911 + 1) {
			fVec235[l911] = 0.0;
		}
		for (int l912 = 0; l912 < 2; l912 = l912 + 1) {
			iRec688[l912] = 0;
		}
		for (int l913 = 0; l913 < 2; l913 = l913 + 1) {
			fRec689[l913] = 0.0;
		}
		for (int l914 = 0; l914 < 2; l914 = l914 + 1) {
			fVec236[l914] = 0.0;
		}
		for (int l915 = 0; l915 < 2; l915 = l915 + 1) {
			iRec690[l915] = 0;
		}
		for (int l916 = 0; l916 < 2; l916 = l916 + 1) {
			fRec691[l916] = 0.0;
		}
		for (int l917 = 0; l917 < 2; l917 = l917 + 1) {
			fVec237[l917] = 0.0;
		}
		for (int l918 = 0; l918 < 2; l918 = l918 + 1) {
			iRec692[l918] = 0;
		}
		for (int l919 = 0; l919 < 2; l919 = l919 + 1) {
			fRec693[l919] = 0.0;
		}
		for (int l920 = 0; l920 < 2; l920 = l920 + 1) {
			fVec238[l920] = 0.0;
		}
		for (int l921 = 0; l921 < 2; l921 = l921 + 1) {
			iRec694[l921] = 0;
		}
		for (int l922 = 0; l922 < 2; l922 = l922 + 1) {
			fRec695[l922] = 0.0;
		}
		for (int l923 = 0; l923 < 2; l923 = l923 + 1) {
			fVec239[l923] = 0.0;
		}
		for (int l924 = 0; l924 < 2; l924 = l924 + 1) {
			iRec696[l924] = 0;
		}
		for (int l925 = 0; l925 < 2; l925 = l925 + 1) {
			fRec697[l925] = 0.0;
		}
		for (int l926 = 0; l926 < 2; l926 = l926 + 1) {
			fVec240[l926] = 0.0;
		}
		for (int l927 = 0; l927 < 2; l927 = l927 + 1) {
			iRec698[l927] = 0;
		}
		for (int l928 = 0; l928 < 2; l928 = l928 + 1) {
			fRec699[l928] = 0.0;
		}
		for (int l929 = 0; l929 < 2; l929 = l929 + 1) {
			fVec241[l929] = 0.0;
		}
		for (int l930 = 0; l930 < 2; l930 = l930 + 1) {
			iRec700[l930] = 0;
		}
		for (int l931 = 0; l931 < 2; l931 = l931 + 1) {
			fRec701[l931] = 0.0;
		}
		for (int l932 = 0; l932 < 2; l932 = l932 + 1) {
			fVec242[l932] = 0.0;
		}
		for (int l933 = 0; l933 < 2; l933 = l933 + 1) {
			iRec702[l933] = 0;
		}
		for (int l934 = 0; l934 < 2; l934 = l934 + 1) {
			fRec703[l934] = 0.0;
		}
		for (int l935 = 0; l935 < 2; l935 = l935 + 1) {
			fVec243[l935] = 0.0;
		}
		for (int l936 = 0; l936 < 2; l936 = l936 + 1) {
			iRec704[l936] = 0;
		}
		for (int l937 = 0; l937 < 2; l937 = l937 + 1) {
			fRec705[l937] = 0.0;
		}
		for (int l938 = 0; l938 < 2; l938 = l938 + 1) {
			fVec244[l938] = 0.0;
		}
		for (int l939 = 0; l939 < 2; l939 = l939 + 1) {
			iRec706[l939] = 0;
		}
		for (int l940 = 0; l940 < 2; l940 = l940 + 1) {
			fRec707[l940] = 0.0;
		}
		for (int l941 = 0; l941 < 2; l941 = l941 + 1) {
			fVec245[l941] = 0.0;
		}
		for (int l942 = 0; l942 < 2; l942 = l942 + 1) {
			iRec708[l942] = 0;
		}
		for (int l943 = 0; l943 < 2; l943 = l943 + 1) {
			fRec709[l943] = 0.0;
		}
		for (int l944 = 0; l944 < 2; l944 = l944 + 1) {
			fVec246[l944] = 0.0;
		}
		for (int l945 = 0; l945 < 2; l945 = l945 + 1) {
			iRec710[l945] = 0;
		}
		for (int l946 = 0; l946 < 2; l946 = l946 + 1) {
			fRec711[l946] = 0.0;
		}
		for (int l947 = 0; l947 < 2; l947 = l947 + 1) {
			fVec247[l947] = 0.0;
		}
		for (int l948 = 0; l948 < 2; l948 = l948 + 1) {
			iRec712[l948] = 0;
		}
		for (int l949 = 0; l949 < 2; l949 = l949 + 1) {
			fRec713[l949] = 0.0;
		}
		for (int l950 = 0; l950 < 2; l950 = l950 + 1) {
			fVec248[l950] = 0.0;
		}
		for (int l951 = 0; l951 < 2; l951 = l951 + 1) {
			iRec714[l951] = 0;
		}
		for (int l952 = 0; l952 < 2; l952 = l952 + 1) {
			fRec715[l952] = 0.0;
		}
		for (int l953 = 0; l953 < 2; l953 = l953 + 1) {
			fVec249[l953] = 0.0;
		}
		for (int l954 = 0; l954 < 2; l954 = l954 + 1) {
			iRec716[l954] = 0;
		}
		for (int l955 = 0; l955 < 2; l955 = l955 + 1) {
			fRec717[l955] = 0.0;
		}
		for (int l956 = 0; l956 < 2; l956 = l956 + 1) {
			fVec250[l956] = 0.0;
		}
		for (int l957 = 0; l957 < 2; l957 = l957 + 1) {
			iRec718[l957] = 0;
		}
		for (int l958 = 0; l958 < 2; l958 = l958 + 1) {
			fRec719[l958] = 0.0;
		}
		for (int l959 = 0; l959 < 2; l959 = l959 + 1) {
			fRec720[l959] = 0.0;
		}
		for (int l960 = 0; l960 < 2; l960 = l960 + 1) {
			fVec251[l960] = 0.0;
		}
		for (int l961 = 0; l961 < 2; l961 = l961 + 1) {
			iRec721[l961] = 0;
		}
		for (int l962 = 0; l962 < 2; l962 = l962 + 1) {
			fRec722[l962] = 0.0;
		}
		for (int l963 = 0; l963 < 2; l963 = l963 + 1) {
			fVec252[l963] = 0.0;
		}
		for (int l964 = 0; l964 < 2; l964 = l964 + 1) {
			iRec723[l964] = 0;
		}
		for (int l965 = 0; l965 < 2; l965 = l965 + 1) {
			fRec724[l965] = 0.0;
		}
		for (int l966 = 0; l966 < 2; l966 = l966 + 1) {
			fVec253[l966] = 0.0;
		}
		for (int l967 = 0; l967 < 2; l967 = l967 + 1) {
			iRec725[l967] = 0;
		}
		for (int l968 = 0; l968 < 2; l968 = l968 + 1) {
			fRec726[l968] = 0.0;
		}
		for (int l969 = 0; l969 < 2; l969 = l969 + 1) {
			fVec254[l969] = 0.0;
		}
		for (int l970 = 0; l970 < 2; l970 = l970 + 1) {
			iRec727[l970] = 0;
		}
		for (int l971 = 0; l971 < 2; l971 = l971 + 1) {
			fRec728[l971] = 0.0;
		}
		for (int l972 = 0; l972 < 2; l972 = l972 + 1) {
			fVec255[l972] = 0.0;
		}
		for (int l973 = 0; l973 < 2; l973 = l973 + 1) {
			iRec729[l973] = 0;
		}
		for (int l974 = 0; l974 < 2; l974 = l974 + 1) {
			fRec730[l974] = 0.0;
		}
		for (int l975 = 0; l975 < 2; l975 = l975 + 1) {
			fVec256[l975] = 0.0;
		}
		for (int l976 = 0; l976 < 2; l976 = l976 + 1) {
			iRec731[l976] = 0;
		}
		for (int l977 = 0; l977 < 2; l977 = l977 + 1) {
			fRec732[l977] = 0.0;
		}
		for (int l978 = 0; l978 < 2; l978 = l978 + 1) {
			fVec257[l978] = 0.0;
		}
		for (int l979 = 0; l979 < 2; l979 = l979 + 1) {
			iRec733[l979] = 0;
		}
		for (int l980 = 0; l980 < 2; l980 = l980 + 1) {
			fRec734[l980] = 0.0;
		}
		for (int l981 = 0; l981 < 2; l981 = l981 + 1) {
			fVec258[l981] = 0.0;
		}
		for (int l982 = 0; l982 < 2; l982 = l982 + 1) {
			iRec735[l982] = 0;
		}
		for (int l983 = 0; l983 < 2; l983 = l983 + 1) {
			fRec736[l983] = 0.0;
		}
		for (int l984 = 0; l984 < 2; l984 = l984 + 1) {
			fVec259[l984] = 0.0;
		}
		for (int l985 = 0; l985 < 2; l985 = l985 + 1) {
			iRec737[l985] = 0;
		}
		for (int l986 = 0; l986 < 2; l986 = l986 + 1) {
			fRec738[l986] = 0.0;
		}
		for (int l987 = 0; l987 < 2; l987 = l987 + 1) {
			fVec260[l987] = 0.0;
		}
		for (int l988 = 0; l988 < 2; l988 = l988 + 1) {
			iRec739[l988] = 0;
		}
		for (int l989 = 0; l989 < 2; l989 = l989 + 1) {
			fRec740[l989] = 0.0;
		}
		for (int l990 = 0; l990 < 2; l990 = l990 + 1) {
			fVec261[l990] = 0.0;
		}
		for (int l991 = 0; l991 < 2; l991 = l991 + 1) {
			iRec741[l991] = 0;
		}
		for (int l992 = 0; l992 < 2; l992 = l992 + 1) {
			fRec742[l992] = 0.0;
		}
		for (int l993 = 0; l993 < 2; l993 = l993 + 1) {
			fVec262[l993] = 0.0;
		}
		for (int l994 = 0; l994 < 2; l994 = l994 + 1) {
			iRec743[l994] = 0;
		}
		for (int l995 = 0; l995 < 2; l995 = l995 + 1) {
			fRec744[l995] = 0.0;
		}
		for (int l996 = 0; l996 < 2; l996 = l996 + 1) {
			fVec263[l996] = 0.0;
		}
		for (int l997 = 0; l997 < 2; l997 = l997 + 1) {
			iRec745[l997] = 0;
		}
		for (int l998 = 0; l998 < 2; l998 = l998 + 1) {
			fRec746[l998] = 0.0;
		}
		for (int l999 = 0; l999 < 2; l999 = l999 + 1) {
			fVec264[l999] = 0.0;
		}
		for (int l1000 = 0; l1000 < 2; l1000 = l1000 + 1) {
			iRec747[l1000] = 0;
		}
		for (int l1001 = 0; l1001 < 2; l1001 = l1001 + 1) {
			fRec748[l1001] = 0.0;
		}
		for (int l1002 = 0; l1002 < 2; l1002 = l1002 + 1) {
			fVec265[l1002] = 0.0;
		}
		for (int l1003 = 0; l1003 < 2; l1003 = l1003 + 1) {
			iRec749[l1003] = 0;
		}
		for (int l1004 = 0; l1004 < 2; l1004 = l1004 + 1) {
			fRec750[l1004] = 0.0;
		}
		for (int l1005 = 0; l1005 < 2; l1005 = l1005 + 1) {
			fVec266[l1005] = 0.0;
		}
		for (int l1006 = 0; l1006 < 2; l1006 = l1006 + 1) {
			iRec751[l1006] = 0;
		}
		for (int l1007 = 0; l1007 < 2; l1007 = l1007 + 1) {
			fRec752[l1007] = 0.0;
		}
		for (int l1008 = 0; l1008 < 2; l1008 = l1008 + 1) {
			fVec267[l1008] = 0.0;
		}
		for (int l1009 = 0; l1009 < 2; l1009 = l1009 + 1) {
			iRec753[l1009] = 0;
		}
		for (int l1010 = 0; l1010 < 2; l1010 = l1010 + 1) {
			fRec754[l1010] = 0.0;
		}
		for (int l1011 = 0; l1011 < 2; l1011 = l1011 + 1) {
			fVec268[l1011] = 0.0;
		}
		for (int l1012 = 0; l1012 < 2; l1012 = l1012 + 1) {
			iRec755[l1012] = 0;
		}
		for (int l1013 = 0; l1013 < 2; l1013 = l1013 + 1) {
			fRec756[l1013] = 0.0;
		}
		for (int l1014 = 0; l1014 < 2; l1014 = l1014 + 1) {
			fVec269[l1014] = 0.0;
		}
		for (int l1015 = 0; l1015 < 2; l1015 = l1015 + 1) {
			iRec757[l1015] = 0;
		}
		for (int l1016 = 0; l1016 < 2; l1016 = l1016 + 1) {
			fRec758[l1016] = 0.0;
		}
		for (int l1017 = 0; l1017 < 2; l1017 = l1017 + 1) {
			fVec270[l1017] = 0.0;
		}
		for (int l1018 = 0; l1018 < 2; l1018 = l1018 + 1) {
			iRec759[l1018] = 0;
		}
		for (int l1019 = 0; l1019 < 2; l1019 = l1019 + 1) {
			fRec760[l1019] = 0.0;
		}
		for (int l1020 = 0; l1020 < 2; l1020 = l1020 + 1) {
			fVec271[l1020] = 0.0;
		}
		for (int l1021 = 0; l1021 < 2; l1021 = l1021 + 1) {
			iRec761[l1021] = 0;
		}
		for (int l1022 = 0; l1022 < 2; l1022 = l1022 + 1) {
			fRec762[l1022] = 0.0;
		}
		for (int l1023 = 0; l1023 < 2; l1023 = l1023 + 1) {
			fVec272[l1023] = 0.0;
		}
		for (int l1024 = 0; l1024 < 2; l1024 = l1024 + 1) {
			iRec763[l1024] = 0;
		}
		for (int l1025 = 0; l1025 < 2; l1025 = l1025 + 1) {
			fRec764[l1025] = 0.0;
		}
		for (int l1026 = 0; l1026 < 2; l1026 = l1026 + 1) {
			fVec273[l1026] = 0.0;
		}
		for (int l1027 = 0; l1027 < 2; l1027 = l1027 + 1) {
			iRec765[l1027] = 0;
		}
		for (int l1028 = 0; l1028 < 2; l1028 = l1028 + 1) {
			fRec766[l1028] = 0.0;
		}
		for (int l1029 = 0; l1029 < 2; l1029 = l1029 + 1) {
			fVec274[l1029] = 0.0;
		}
		for (int l1030 = 0; l1030 < 2; l1030 = l1030 + 1) {
			iRec767[l1030] = 0;
		}
		for (int l1031 = 0; l1031 < 2; l1031 = l1031 + 1) {
			fRec768[l1031] = 0.0;
		}
		for (int l1032 = 0; l1032 < 2; l1032 = l1032 + 1) {
			fRec769[l1032] = 0.0;
		}
		for (int l1033 = 0; l1033 < 2; l1033 = l1033 + 1) {
			fVec275[l1033] = 0.0;
		}
		for (int l1034 = 0; l1034 < 2; l1034 = l1034 + 1) {
			iRec770[l1034] = 0;
		}
		for (int l1035 = 0; l1035 < 2; l1035 = l1035 + 1) {
			fRec771[l1035] = 0.0;
		}
		for (int l1036 = 0; l1036 < 2; l1036 = l1036 + 1) {
			fVec276[l1036] = 0.0;
		}
		for (int l1037 = 0; l1037 < 2; l1037 = l1037 + 1) {
			iRec772[l1037] = 0;
		}
		for (int l1038 = 0; l1038 < 2; l1038 = l1038 + 1) {
			fRec773[l1038] = 0.0;
		}
		for (int l1039 = 0; l1039 < 2; l1039 = l1039 + 1) {
			fRec774[l1039] = 0.0;
		}
		for (int l1040 = 0; l1040 < 2; l1040 = l1040 + 1) {
			fVec277[l1040] = 0.0;
		}
		for (int l1041 = 0; l1041 < 2; l1041 = l1041 + 1) {
			iRec775[l1041] = 0;
		}
		for (int l1042 = 0; l1042 < 2; l1042 = l1042 + 1) {
			fRec776[l1042] = 0.0;
		}
		for (int l1043 = 0; l1043 < 2; l1043 = l1043 + 1) {
			fVec278[l1043] = 0.0;
		}
		for (int l1044 = 0; l1044 < 2; l1044 = l1044 + 1) {
			iRec777[l1044] = 0;
		}
		for (int l1045 = 0; l1045 < 2; l1045 = l1045 + 1) {
			fRec778[l1045] = 0.0;
		}
		for (int l1046 = 0; l1046 < 2; l1046 = l1046 + 1) {
			fRec779[l1046] = 0.0;
		}
		for (int l1047 = 0; l1047 < 2; l1047 = l1047 + 1) {
			fVec279[l1047] = 0.0;
		}
		for (int l1048 = 0; l1048 < 2; l1048 = l1048 + 1) {
			iRec780[l1048] = 0;
		}
		for (int l1049 = 0; l1049 < 2; l1049 = l1049 + 1) {
			fRec781[l1049] = 0.0;
		}
		for (int l1050 = 0; l1050 < 2; l1050 = l1050 + 1) {
			fRec782[l1050] = 0.0;
		}
		for (int l1051 = 0; l1051 < 2; l1051 = l1051 + 1) {
			fVec280[l1051] = 0.0;
		}
		for (int l1052 = 0; l1052 < 2; l1052 = l1052 + 1) {
			iRec783[l1052] = 0;
		}
		for (int l1053 = 0; l1053 < 2; l1053 = l1053 + 1) {
			fRec784[l1053] = 0.0;
		}
		for (int l1054 = 0; l1054 < 2; l1054 = l1054 + 1) {
			fVec281[l1054] = 0.0;
		}
		for (int l1055 = 0; l1055 < 2; l1055 = l1055 + 1) {
			iRec785[l1055] = 0;
		}
		for (int l1056 = 0; l1056 < 2; l1056 = l1056 + 1) {
			fRec786[l1056] = 0.0;
		}
		for (int l1057 = 0; l1057 < 2; l1057 = l1057 + 1) {
			fVec282[l1057] = 0.0;
		}
		for (int l1058 = 0; l1058 < 2; l1058 = l1058 + 1) {
			iRec787[l1058] = 0;
		}
		for (int l1059 = 0; l1059 < 2; l1059 = l1059 + 1) {
			fRec788[l1059] = 0.0;
		}
		for (int l1060 = 0; l1060 < 2; l1060 = l1060 + 1) {
			fVec283[l1060] = 0.0;
		}
		for (int l1061 = 0; l1061 < 2; l1061 = l1061 + 1) {
			iRec789[l1061] = 0;
		}
		for (int l1062 = 0; l1062 < 2; l1062 = l1062 + 1) {
			fRec790[l1062] = 0.0;
		}
		for (int l1063 = 0; l1063 < 2; l1063 = l1063 + 1) {
			fVec284[l1063] = 0.0;
		}
		for (int l1064 = 0; l1064 < 2; l1064 = l1064 + 1) {
			iRec791[l1064] = 0;
		}
		for (int l1065 = 0; l1065 < 2; l1065 = l1065 + 1) {
			fRec792[l1065] = 0.0;
		}
		for (int l1066 = 0; l1066 < 2; l1066 = l1066 + 1) {
			fVec285[l1066] = 0.0;
		}
		for (int l1067 = 0; l1067 < 2; l1067 = l1067 + 1) {
			iRec793[l1067] = 0;
		}
		for (int l1068 = 0; l1068 < 2; l1068 = l1068 + 1) {
			fRec794[l1068] = 0.0;
		}
		for (int l1069 = 0; l1069 < 2; l1069 = l1069 + 1) {
			fVec286[l1069] = 0.0;
		}
		for (int l1070 = 0; l1070 < 2; l1070 = l1070 + 1) {
			iRec795[l1070] = 0;
		}
		for (int l1071 = 0; l1071 < 2; l1071 = l1071 + 1) {
			fRec796[l1071] = 0.0;
		}
		for (int l1072 = 0; l1072 < 2; l1072 = l1072 + 1) {
			fVec287[l1072] = 0.0;
		}
		for (int l1073 = 0; l1073 < 2; l1073 = l1073 + 1) {
			iRec797[l1073] = 0;
		}
		for (int l1074 = 0; l1074 < 2; l1074 = l1074 + 1) {
			fRec798[l1074] = 0.0;
		}
		for (int l1075 = 0; l1075 < 2; l1075 = l1075 + 1) {
			fVec288[l1075] = 0.0;
		}
		for (int l1076 = 0; l1076 < 2; l1076 = l1076 + 1) {
			iRec799[l1076] = 0;
		}
		for (int l1077 = 0; l1077 < 2; l1077 = l1077 + 1) {
			fRec800[l1077] = 0.0;
		}
		for (int l1078 = 0; l1078 < 2; l1078 = l1078 + 1) {
			fVec289[l1078] = 0.0;
		}
		for (int l1079 = 0; l1079 < 2; l1079 = l1079 + 1) {
			iRec801[l1079] = 0;
		}
		for (int l1080 = 0; l1080 < 2; l1080 = l1080 + 1) {
			fRec802[l1080] = 0.0;
		}
		for (int l1081 = 0; l1081 < 2; l1081 = l1081 + 1) {
			fVec290[l1081] = 0.0;
		}
		for (int l1082 = 0; l1082 < 2; l1082 = l1082 + 1) {
			iRec803[l1082] = 0;
		}
		for (int l1083 = 0; l1083 < 2; l1083 = l1083 + 1) {
			fRec804[l1083] = 0.0;
		}
		for (int l1084 = 0; l1084 < 2; l1084 = l1084 + 1) {
			fVec291[l1084] = 0.0;
		}
		for (int l1085 = 0; l1085 < 2; l1085 = l1085 + 1) {
			iRec805[l1085] = 0;
		}
		for (int l1086 = 0; l1086 < 2; l1086 = l1086 + 1) {
			fRec806[l1086] = 0.0;
		}
		for (int l1087 = 0; l1087 < 2; l1087 = l1087 + 1) {
			fVec292[l1087] = 0.0;
		}
		for (int l1088 = 0; l1088 < 2; l1088 = l1088 + 1) {
			iRec807[l1088] = 0;
		}
		for (int l1089 = 0; l1089 < 2; l1089 = l1089 + 1) {
			fRec808[l1089] = 0.0;
		}
		for (int l1090 = 0; l1090 < 2; l1090 = l1090 + 1) {
			fVec293[l1090] = 0.0;
		}
		for (int l1091 = 0; l1091 < 2; l1091 = l1091 + 1) {
			iRec809[l1091] = 0;
		}
		for (int l1092 = 0; l1092 < 2; l1092 = l1092 + 1) {
			fRec810[l1092] = 0.0;
		}
		for (int l1093 = 0; l1093 < 2; l1093 = l1093 + 1) {
			fVec294[l1093] = 0.0;
		}
		for (int l1094 = 0; l1094 < 2; l1094 = l1094 + 1) {
			iRec811[l1094] = 0;
		}
		for (int l1095 = 0; l1095 < 2; l1095 = l1095 + 1) {
			fRec812[l1095] = 0.0;
		}
		for (int l1096 = 0; l1096 < 2; l1096 = l1096 + 1) {
			fVec295[l1096] = 0.0;
		}
		for (int l1097 = 0; l1097 < 2; l1097 = l1097 + 1) {
			iRec813[l1097] = 0;
		}
		for (int l1098 = 0; l1098 < 2; l1098 = l1098 + 1) {
			fRec814[l1098] = 0.0;
		}
		for (int l1099 = 0; l1099 < 2; l1099 = l1099 + 1) {
			fVec296[l1099] = 0.0;
		}
		for (int l1100 = 0; l1100 < 2; l1100 = l1100 + 1) {
			iRec815[l1100] = 0;
		}
		for (int l1101 = 0; l1101 < 2; l1101 = l1101 + 1) {
			fRec816[l1101] = 0.0;
		}
		for (int l1102 = 0; l1102 < 2; l1102 = l1102 + 1) {
			fVec297[l1102] = 0.0;
		}
		for (int l1103 = 0; l1103 < 2; l1103 = l1103 + 1) {
			iRec817[l1103] = 0;
		}
		for (int l1104 = 0; l1104 < 2; l1104 = l1104 + 1) {
			fRec818[l1104] = 0.0;
		}
		for (int l1105 = 0; l1105 < 2; l1105 = l1105 + 1) {
			fVec298[l1105] = 0.0;
		}
		for (int l1106 = 0; l1106 < 2; l1106 = l1106 + 1) {
			iRec819[l1106] = 0;
		}
		for (int l1107 = 0; l1107 < 2; l1107 = l1107 + 1) {
			fRec820[l1107] = 0.0;
		}
		for (int l1108 = 0; l1108 < 2; l1108 = l1108 + 1) {
			fVec299[l1108] = 0.0;
		}
		for (int l1109 = 0; l1109 < 2; l1109 = l1109 + 1) {
			iRec821[l1109] = 0;
		}
		for (int l1110 = 0; l1110 < 2; l1110 = l1110 + 1) {
			fRec822[l1110] = 0.0;
		}
		for (int l1111 = 0; l1111 < 2; l1111 = l1111 + 1) {
			fVec300[l1111] = 0.0;
		}
		for (int l1112 = 0; l1112 < 2; l1112 = l1112 + 1) {
			iRec823[l1112] = 0;
		}
		for (int l1113 = 0; l1113 < 2; l1113 = l1113 + 1) {
			fRec824[l1113] = 0.0;
		}
		for (int l1114 = 0; l1114 < 2; l1114 = l1114 + 1) {
			fVec301[l1114] = 0.0;
		}
		for (int l1115 = 0; l1115 < 2; l1115 = l1115 + 1) {
			iRec825[l1115] = 0;
		}
		for (int l1116 = 0; l1116 < 2; l1116 = l1116 + 1) {
			fRec826[l1116] = 0.0;
		}
		for (int l1117 = 0; l1117 < 2; l1117 = l1117 + 1) {
			fVec302[l1117] = 0.0;
		}
		for (int l1118 = 0; l1118 < 2; l1118 = l1118 + 1) {
			iRec827[l1118] = 0;
		}
		for (int l1119 = 0; l1119 < 2; l1119 = l1119 + 1) {
			fRec828[l1119] = 0.0;
		}
		for (int l1120 = 0; l1120 < 2; l1120 = l1120 + 1) {
			fVec303[l1120] = 0.0;
		}
		for (int l1121 = 0; l1121 < 2; l1121 = l1121 + 1) {
			iRec829[l1121] = 0;
		}
		for (int l1122 = 0; l1122 < 2; l1122 = l1122 + 1) {
			fRec830[l1122] = 0.0;
		}
		for (int l1123 = 0; l1123 < 2; l1123 = l1123 + 1) {
			fVec304[l1123] = 0.0;
		}
		for (int l1124 = 0; l1124 < 2; l1124 = l1124 + 1) {
			iRec831[l1124] = 0;
		}
		for (int l1125 = 0; l1125 < 2; l1125 = l1125 + 1) {
			fRec832[l1125] = 0.0;
		}
		for (int l1126 = 0; l1126 < 2; l1126 = l1126 + 1) {
			fVec305[l1126] = 0.0;
		}
		for (int l1127 = 0; l1127 < 2; l1127 = l1127 + 1) {
			iRec833[l1127] = 0;
		}
		for (int l1128 = 0; l1128 < 2; l1128 = l1128 + 1) {
			fRec834[l1128] = 0.0;
		}
		for (int l1129 = 0; l1129 < 2; l1129 = l1129 + 1) {
			fVec306[l1129] = 0.0;
		}
		for (int l1130 = 0; l1130 < 2; l1130 = l1130 + 1) {
			iRec835[l1130] = 0;
		}
		for (int l1131 = 0; l1131 < 2; l1131 = l1131 + 1) {
			fRec836[l1131] = 0.0;
		}
		for (int l1132 = 0; l1132 < 2; l1132 = l1132 + 1) {
			fVec307[l1132] = 0.0;
		}
		for (int l1133 = 0; l1133 < 2; l1133 = l1133 + 1) {
			iRec837[l1133] = 0;
		}
		for (int l1134 = 0; l1134 < 2; l1134 = l1134 + 1) {
			fRec838[l1134] = 0.0;
		}
		for (int l1135 = 0; l1135 < 2; l1135 = l1135 + 1) {
			fVec308[l1135] = 0.0;
		}
		for (int l1136 = 0; l1136 < 2; l1136 = l1136 + 1) {
			iRec839[l1136] = 0;
		}
		for (int l1137 = 0; l1137 < 2; l1137 = l1137 + 1) {
			fRec840[l1137] = 0.0;
		}
		for (int l1138 = 0; l1138 < 2; l1138 = l1138 + 1) {
			fVec309[l1138] = 0.0;
		}
		for (int l1139 = 0; l1139 < 2; l1139 = l1139 + 1) {
			iRec841[l1139] = 0;
		}
		for (int l1140 = 0; l1140 < 2; l1140 = l1140 + 1) {
			fRec842[l1140] = 0.0;
		}
		for (int l1141 = 0; l1141 < 2; l1141 = l1141 + 1) {
			fVec310[l1141] = 0.0;
		}
		for (int l1142 = 0; l1142 < 2; l1142 = l1142 + 1) {
			iRec843[l1142] = 0;
		}
		for (int l1143 = 0; l1143 < 2; l1143 = l1143 + 1) {
			fRec844[l1143] = 0.0;
		}
		for (int l1144 = 0; l1144 < 2; l1144 = l1144 + 1) {
			fVec311[l1144] = 0.0;
		}
		for (int l1145 = 0; l1145 < 2; l1145 = l1145 + 1) {
			iRec845[l1145] = 0;
		}
		for (int l1146 = 0; l1146 < 2; l1146 = l1146 + 1) {
			fRec846[l1146] = 0.0;
		}
		for (int l1147 = 0; l1147 < 2; l1147 = l1147 + 1) {
			fRec847[l1147] = 0.0;
		}
		for (int l1148 = 0; l1148 < 2; l1148 = l1148 + 1) {
			fVec312[l1148] = 0.0;
		}
		for (int l1149 = 0; l1149 < 2; l1149 = l1149 + 1) {
			iRec848[l1149] = 0;
		}
		for (int l1150 = 0; l1150 < 2; l1150 = l1150 + 1) {
			fRec849[l1150] = 0.0;
		}
		for (int l1151 = 0; l1151 < 2; l1151 = l1151 + 1) {
			fVec313[l1151] = 0.0;
		}
		for (int l1152 = 0; l1152 < 2; l1152 = l1152 + 1) {
			iRec850[l1152] = 0;
		}
		for (int l1153 = 0; l1153 < 2; l1153 = l1153 + 1) {
			fRec851[l1153] = 0.0;
		}
		for (int l1154 = 0; l1154 < 2; l1154 = l1154 + 1) {
			fVec314[l1154] = 0.0;
		}
		for (int l1155 = 0; l1155 < 2; l1155 = l1155 + 1) {
			iRec852[l1155] = 0;
		}
		for (int l1156 = 0; l1156 < 2; l1156 = l1156 + 1) {
			fRec853[l1156] = 0.0;
		}
		for (int l1157 = 0; l1157 < 2; l1157 = l1157 + 1) {
			fVec315[l1157] = 0.0;
		}
		for (int l1158 = 0; l1158 < 2; l1158 = l1158 + 1) {
			iRec854[l1158] = 0;
		}
		for (int l1159 = 0; l1159 < 2; l1159 = l1159 + 1) {
			fRec855[l1159] = 0.0;
		}
		for (int l1160 = 0; l1160 < 2; l1160 = l1160 + 1) {
			fVec316[l1160] = 0.0;
		}
		for (int l1161 = 0; l1161 < 2; l1161 = l1161 + 1) {
			iRec856[l1161] = 0;
		}
		for (int l1162 = 0; l1162 < 2; l1162 = l1162 + 1) {
			fRec857[l1162] = 0.0;
		}
		for (int l1163 = 0; l1163 < 2; l1163 = l1163 + 1) {
			fVec317[l1163] = 0.0;
		}
		for (int l1164 = 0; l1164 < 2; l1164 = l1164 + 1) {
			iRec858[l1164] = 0;
		}
		for (int l1165 = 0; l1165 < 2; l1165 = l1165 + 1) {
			fRec859[l1165] = 0.0;
		}
		for (int l1166 = 0; l1166 < 2; l1166 = l1166 + 1) {
			fVec318[l1166] = 0.0;
		}
		for (int l1167 = 0; l1167 < 2; l1167 = l1167 + 1) {
			iRec860[l1167] = 0;
		}
		for (int l1168 = 0; l1168 < 2; l1168 = l1168 + 1) {
			fRec861[l1168] = 0.0;
		}
		for (int l1169 = 0; l1169 < 2; l1169 = l1169 + 1) {
			fVec319[l1169] = 0.0;
		}
		for (int l1170 = 0; l1170 < 2; l1170 = l1170 + 1) {
			iRec862[l1170] = 0;
		}
		for (int l1171 = 0; l1171 < 2; l1171 = l1171 + 1) {
			fRec863[l1171] = 0.0;
		}
		for (int l1172 = 0; l1172 < 2; l1172 = l1172 + 1) {
			fVec320[l1172] = 0.0;
		}
		for (int l1173 = 0; l1173 < 2; l1173 = l1173 + 1) {
			iRec864[l1173] = 0;
		}
		for (int l1174 = 0; l1174 < 2; l1174 = l1174 + 1) {
			fRec865[l1174] = 0.0;
		}
		for (int l1175 = 0; l1175 < 2; l1175 = l1175 + 1) {
			fVec321[l1175] = 0.0;
		}
		for (int l1176 = 0; l1176 < 2; l1176 = l1176 + 1) {
			iRec866[l1176] = 0;
		}
		for (int l1177 = 0; l1177 < 2; l1177 = l1177 + 1) {
			fRec867[l1177] = 0.0;
		}
		for (int l1178 = 0; l1178 < 2; l1178 = l1178 + 1) {
			fVec322[l1178] = 0.0;
		}
		for (int l1179 = 0; l1179 < 2; l1179 = l1179 + 1) {
			iRec868[l1179] = 0;
		}
		for (int l1180 = 0; l1180 < 2; l1180 = l1180 + 1) {
			fRec869[l1180] = 0.0;
		}
		for (int l1181 = 0; l1181 < 2; l1181 = l1181 + 1) {
			fVec323[l1181] = 0.0;
		}
		for (int l1182 = 0; l1182 < 2; l1182 = l1182 + 1) {
			iRec870[l1182] = 0;
		}
		for (int l1183 = 0; l1183 < 2; l1183 = l1183 + 1) {
			fRec871[l1183] = 0.0;
		}
		for (int l1184 = 0; l1184 < 2; l1184 = l1184 + 1) {
			fVec324[l1184] = 0.0;
		}
		for (int l1185 = 0; l1185 < 2; l1185 = l1185 + 1) {
			iRec872[l1185] = 0;
		}
		for (int l1186 = 0; l1186 < 2; l1186 = l1186 + 1) {
			fRec873[l1186] = 0.0;
		}
		for (int l1187 = 0; l1187 < 2; l1187 = l1187 + 1) {
			fVec325[l1187] = 0.0;
		}
		for (int l1188 = 0; l1188 < 2; l1188 = l1188 + 1) {
			iRec874[l1188] = 0;
		}
		for (int l1189 = 0; l1189 < 2; l1189 = l1189 + 1) {
			fRec875[l1189] = 0.0;
		}
		for (int l1190 = 0; l1190 < 2; l1190 = l1190 + 1) {
			fVec326[l1190] = 0.0;
		}
		for (int l1191 = 0; l1191 < 2; l1191 = l1191 + 1) {
			iRec876[l1191] = 0;
		}
		for (int l1192 = 0; l1192 < 2; l1192 = l1192 + 1) {
			fRec877[l1192] = 0.0;
		}
		for (int l1193 = 0; l1193 < 2; l1193 = l1193 + 1) {
			fVec327[l1193] = 0.0;
		}
		for (int l1194 = 0; l1194 < 2; l1194 = l1194 + 1) {
			iRec878[l1194] = 0;
		}
		for (int l1195 = 0; l1195 < 2; l1195 = l1195 + 1) {
			fRec879[l1195] = 0.0;
		}
		for (int l1196 = 0; l1196 < 2; l1196 = l1196 + 1) {
			fVec328[l1196] = 0.0;
		}
		for (int l1197 = 0; l1197 < 2; l1197 = l1197 + 1) {
			iRec880[l1197] = 0;
		}
		for (int l1198 = 0; l1198 < 2; l1198 = l1198 + 1) {
			fRec881[l1198] = 0.0;
		}
		for (int l1199 = 0; l1199 < 2; l1199 = l1199 + 1) {
			fVec329[l1199] = 0.0;
		}
		for (int l1200 = 0; l1200 < 2; l1200 = l1200 + 1) {
			iRec882[l1200] = 0;
		}
		for (int l1201 = 0; l1201 < 2; l1201 = l1201 + 1) {
			fRec883[l1201] = 0.0;
		}
		for (int l1202 = 0; l1202 < 2; l1202 = l1202 + 1) {
			fVec330[l1202] = 0.0;
		}
		for (int l1203 = 0; l1203 < 2; l1203 = l1203 + 1) {
			iRec884[l1203] = 0;
		}
		for (int l1204 = 0; l1204 < 2; l1204 = l1204 + 1) {
			fRec885[l1204] = 0.0;
		}
		for (int l1205 = 0; l1205 < 2; l1205 = l1205 + 1) {
			fVec331[l1205] = 0.0;
		}
		for (int l1206 = 0; l1206 < 2; l1206 = l1206 + 1) {
			iRec886[l1206] = 0;
		}
		for (int l1207 = 0; l1207 < 2; l1207 = l1207 + 1) {
			fRec887[l1207] = 0.0;
		}
		for (int l1208 = 0; l1208 < 2; l1208 = l1208 + 1) {
			fVec332[l1208] = 0.0;
		}
		for (int l1209 = 0; l1209 < 2; l1209 = l1209 + 1) {
			iRec888[l1209] = 0;
		}
		for (int l1210 = 0; l1210 < 2; l1210 = l1210 + 1) {
			fRec889[l1210] = 0.0;
		}
		for (int l1211 = 0; l1211 < 2; l1211 = l1211 + 1) {
			fVec333[l1211] = 0.0;
		}
		for (int l1212 = 0; l1212 < 2; l1212 = l1212 + 1) {
			iRec890[l1212] = 0;
		}
		for (int l1213 = 0; l1213 < 2; l1213 = l1213 + 1) {
			fRec891[l1213] = 0.0;
		}
		for (int l1214 = 0; l1214 < 2; l1214 = l1214 + 1) {
			fVec334[l1214] = 0.0;
		}
		for (int l1215 = 0; l1215 < 2; l1215 = l1215 + 1) {
			iRec892[l1215] = 0;
		}
		for (int l1216 = 0; l1216 < 2; l1216 = l1216 + 1) {
			fRec893[l1216] = 0.0;
		}
		for (int l1217 = 0; l1217 < 2; l1217 = l1217 + 1) {
			fVec335[l1217] = 0.0;
		}
		for (int l1218 = 0; l1218 < 2; l1218 = l1218 + 1) {
			iRec894[l1218] = 0;
		}
		for (int l1219 = 0; l1219 < 2; l1219 = l1219 + 1) {
			fRec895[l1219] = 0.0;
		}
		for (int l1220 = 0; l1220 < 2; l1220 = l1220 + 1) {
			fVec336[l1220] = 0.0;
		}
		for (int l1221 = 0; l1221 < 2; l1221 = l1221 + 1) {
			iRec896[l1221] = 0;
		}
		for (int l1222 = 0; l1222 < 2; l1222 = l1222 + 1) {
			fRec897[l1222] = 0.0;
		}
		for (int l1223 = 0; l1223 < 2; l1223 = l1223 + 1) {
			fVec337[l1223] = 0.0;
		}
		for (int l1224 = 0; l1224 < 2; l1224 = l1224 + 1) {
			iRec898[l1224] = 0;
		}
		for (int l1225 = 0; l1225 < 2; l1225 = l1225 + 1) {
			fRec899[l1225] = 0.0;
		}
		for (int l1226 = 0; l1226 < 2; l1226 = l1226 + 1) {
			fVec338[l1226] = 0.0;
		}
		for (int l1227 = 0; l1227 < 2; l1227 = l1227 + 1) {
			iRec900[l1227] = 0;
		}
		for (int l1228 = 0; l1228 < 2; l1228 = l1228 + 1) {
			fRec901[l1228] = 0.0;
		}
		for (int l1229 = 0; l1229 < 2; l1229 = l1229 + 1) {
			fVec339[l1229] = 0.0;
		}
		for (int l1230 = 0; l1230 < 2; l1230 = l1230 + 1) {
			iRec902[l1230] = 0;
		}
		for (int l1231 = 0; l1231 < 2; l1231 = l1231 + 1) {
			fRec903[l1231] = 0.0;
		}
		for (int l1232 = 0; l1232 < 2; l1232 = l1232 + 1) {
			fVec340[l1232] = 0.0;
		}
		for (int l1233 = 0; l1233 < 2; l1233 = l1233 + 1) {
			iRec904[l1233] = 0;
		}
		for (int l1234 = 0; l1234 < 2; l1234 = l1234 + 1) {
			fRec905[l1234] = 0.0;
		}
		for (int l1235 = 0; l1235 < 2; l1235 = l1235 + 1) {
			fRec906[l1235] = 0.0;
		}
		for (int l1236 = 0; l1236 < 2; l1236 = l1236 + 1) {
			fRec907[l1236] = 0.0;
		}
		for (int l1237 = 0; l1237 < 2; l1237 = l1237 + 1) {
			fVec341[l1237] = 0.0;
		}
		for (int l1238 = 0; l1238 < 2; l1238 = l1238 + 1) {
			iRec908[l1238] = 0;
		}
		for (int l1239 = 0; l1239 < 2; l1239 = l1239 + 1) {
			fRec909[l1239] = 0.0;
		}
		for (int l1240 = 0; l1240 < 2; l1240 = l1240 + 1) {
			fVec342[l1240] = 0.0;
		}
		for (int l1241 = 0; l1241 < 2; l1241 = l1241 + 1) {
			iRec910[l1241] = 0;
		}
		for (int l1242 = 0; l1242 < 2; l1242 = l1242 + 1) {
			fRec911[l1242] = 0.0;
		}
		for (int l1243 = 0; l1243 < 2; l1243 = l1243 + 1) {
			fVec343[l1243] = 0.0;
		}
		for (int l1244 = 0; l1244 < 2; l1244 = l1244 + 1) {
			iRec912[l1244] = 0;
		}
		for (int l1245 = 0; l1245 < 2; l1245 = l1245 + 1) {
			fRec913[l1245] = 0.0;
		}
		for (int l1246 = 0; l1246 < 2; l1246 = l1246 + 1) {
			fVec344[l1246] = 0.0;
		}
		for (int l1247 = 0; l1247 < 2; l1247 = l1247 + 1) {
			iRec914[l1247] = 0;
		}
		for (int l1248 = 0; l1248 < 2; l1248 = l1248 + 1) {
			fRec915[l1248] = 0.0;
		}
		for (int l1249 = 0; l1249 < 2; l1249 = l1249 + 1) {
			fVec345[l1249] = 0.0;
		}
		for (int l1250 = 0; l1250 < 2; l1250 = l1250 + 1) {
			iRec916[l1250] = 0;
		}
		for (int l1251 = 0; l1251 < 2; l1251 = l1251 + 1) {
			fRec917[l1251] = 0.0;
		}
		for (int l1252 = 0; l1252 < 2; l1252 = l1252 + 1) {
			fRec918[l1252] = 0.0;
		}
		for (int l1253 = 0; l1253 < 2; l1253 = l1253 + 1) {
			fVec346[l1253] = 0.0;
		}
		for (int l1254 = 0; l1254 < 2; l1254 = l1254 + 1) {
			iRec919[l1254] = 0;
		}
		for (int l1255 = 0; l1255 < 2; l1255 = l1255 + 1) {
			fRec920[l1255] = 0.0;
		}
		for (int l1256 = 0; l1256 < 2; l1256 = l1256 + 1) {
			fVec347[l1256] = 0.0;
		}
		for (int l1257 = 0; l1257 < 2; l1257 = l1257 + 1) {
			iRec921[l1257] = 0;
		}
		for (int l1258 = 0; l1258 < 2; l1258 = l1258 + 1) {
			fRec922[l1258] = 0.0;
		}
		for (int l1259 = 0; l1259 < 2; l1259 = l1259 + 1) {
			fVec348[l1259] = 0.0;
		}
		for (int l1260 = 0; l1260 < 2; l1260 = l1260 + 1) {
			iRec923[l1260] = 0;
		}
		for (int l1261 = 0; l1261 < 2; l1261 = l1261 + 1) {
			fRec924[l1261] = 0.0;
		}
		for (int l1262 = 0; l1262 < 2; l1262 = l1262 + 1) {
			fVec349[l1262] = 0.0;
		}
		for (int l1263 = 0; l1263 < 2; l1263 = l1263 + 1) {
			iRec925[l1263] = 0;
		}
		for (int l1264 = 0; l1264 < 2; l1264 = l1264 + 1) {
			fRec926[l1264] = 0.0;
		}
		for (int l1265 = 0; l1265 < 2; l1265 = l1265 + 1) {
			fVec350[l1265] = 0.0;
		}
		for (int l1266 = 0; l1266 < 2; l1266 = l1266 + 1) {
			iRec927[l1266] = 0;
		}
		for (int l1267 = 0; l1267 < 2; l1267 = l1267 + 1) {
			fRec928[l1267] = 0.0;
		}
		for (int l1268 = 0; l1268 < 2; l1268 = l1268 + 1) {
			fVec351[l1268] = 0.0;
		}
		for (int l1269 = 0; l1269 < 2; l1269 = l1269 + 1) {
			iRec929[l1269] = 0;
		}
		for (int l1270 = 0; l1270 < 2; l1270 = l1270 + 1) {
			fRec930[l1270] = 0.0;
		}
		for (int l1271 = 0; l1271 < 2; l1271 = l1271 + 1) {
			fVec352[l1271] = 0.0;
		}
		for (int l1272 = 0; l1272 < 2; l1272 = l1272 + 1) {
			iRec931[l1272] = 0;
		}
		for (int l1273 = 0; l1273 < 2; l1273 = l1273 + 1) {
			fRec932[l1273] = 0.0;
		}
		for (int l1274 = 0; l1274 < 2; l1274 = l1274 + 1) {
			fVec353[l1274] = 0.0;
		}
		for (int l1275 = 0; l1275 < 2; l1275 = l1275 + 1) {
			iRec933[l1275] = 0;
		}
		for (int l1276 = 0; l1276 < 2; l1276 = l1276 + 1) {
			fRec934[l1276] = 0.0;
		}
		for (int l1277 = 0; l1277 < 2; l1277 = l1277 + 1) {
			fVec354[l1277] = 0.0;
		}
		for (int l1278 = 0; l1278 < 2; l1278 = l1278 + 1) {
			iRec935[l1278] = 0;
		}
		for (int l1279 = 0; l1279 < 2; l1279 = l1279 + 1) {
			fRec936[l1279] = 0.0;
		}
		for (int l1280 = 0; l1280 < 2; l1280 = l1280 + 1) {
			fVec355[l1280] = 0.0;
		}
		for (int l1281 = 0; l1281 < 2; l1281 = l1281 + 1) {
			iRec937[l1281] = 0;
		}
		for (int l1282 = 0; l1282 < 2; l1282 = l1282 + 1) {
			fRec938[l1282] = 0.0;
		}
		for (int l1283 = 0; l1283 < 2; l1283 = l1283 + 1) {
			fVec356[l1283] = 0.0;
		}
		for (int l1284 = 0; l1284 < 2; l1284 = l1284 + 1) {
			iRec939[l1284] = 0;
		}
		for (int l1285 = 0; l1285 < 2; l1285 = l1285 + 1) {
			fRec940[l1285] = 0.0;
		}
		for (int l1286 = 0; l1286 < 2; l1286 = l1286 + 1) {
			fVec357[l1286] = 0.0;
		}
		for (int l1287 = 0; l1287 < 2; l1287 = l1287 + 1) {
			iRec941[l1287] = 0;
		}
		for (int l1288 = 0; l1288 < 2; l1288 = l1288 + 1) {
			fRec942[l1288] = 0.0;
		}
		for (int l1289 = 0; l1289 < 2; l1289 = l1289 + 1) {
			fVec358[l1289] = 0.0;
		}
		for (int l1290 = 0; l1290 < 2; l1290 = l1290 + 1) {
			iRec943[l1290] = 0;
		}
		for (int l1291 = 0; l1291 < 2; l1291 = l1291 + 1) {
			fRec944[l1291] = 0.0;
		}
		for (int l1292 = 0; l1292 < 2; l1292 = l1292 + 1) {
			fVec359[l1292] = 0.0;
		}
		for (int l1293 = 0; l1293 < 2; l1293 = l1293 + 1) {
			iRec945[l1293] = 0;
		}
		for (int l1294 = 0; l1294 < 2; l1294 = l1294 + 1) {
			fRec946[l1294] = 0.0;
		}
		for (int l1295 = 0; l1295 < 2; l1295 = l1295 + 1) {
			fVec360[l1295] = 0.0;
		}
		for (int l1296 = 0; l1296 < 2; l1296 = l1296 + 1) {
			iRec947[l1296] = 0;
		}
		for (int l1297 = 0; l1297 < 2; l1297 = l1297 + 1) {
			fRec948[l1297] = 0.0;
		}
		for (int l1298 = 0; l1298 < 2; l1298 = l1298 + 1) {
			fVec361[l1298] = 0.0;
		}
		for (int l1299 = 0; l1299 < 2; l1299 = l1299 + 1) {
			iRec949[l1299] = 0;
		}
		for (int l1300 = 0; l1300 < 2; l1300 = l1300 + 1) {
			fRec950[l1300] = 0.0;
		}
		for (int l1301 = 0; l1301 < 2; l1301 = l1301 + 1) {
			fVec362[l1301] = 0.0;
		}
		for (int l1302 = 0; l1302 < 2; l1302 = l1302 + 1) {
			iRec951[l1302] = 0;
		}
		for (int l1303 = 0; l1303 < 2; l1303 = l1303 + 1) {
			fRec952[l1303] = 0.0;
		}
		for (int l1304 = 0; l1304 < 2; l1304 = l1304 + 1) {
			fVec363[l1304] = 0.0;
		}
		for (int l1305 = 0; l1305 < 2; l1305 = l1305 + 1) {
			iRec953[l1305] = 0;
		}
		for (int l1306 = 0; l1306 < 2; l1306 = l1306 + 1) {
			fRec954[l1306] = 0.0;
		}
		for (int l1307 = 0; l1307 < 2; l1307 = l1307 + 1) {
			fVec364[l1307] = 0.0;
		}
		for (int l1308 = 0; l1308 < 2; l1308 = l1308 + 1) {
			iRec955[l1308] = 0;
		}
		for (int l1309 = 0; l1309 < 2; l1309 = l1309 + 1) {
			fRec956[l1309] = 0.0;
		}
		for (int l1310 = 0; l1310 < 2; l1310 = l1310 + 1) {
			fVec365[l1310] = 0.0;
		}
		for (int l1311 = 0; l1311 < 2; l1311 = l1311 + 1) {
			iRec957[l1311] = 0;
		}
		for (int l1312 = 0; l1312 < 2; l1312 = l1312 + 1) {
			fRec958[l1312] = 0.0;
		}
		for (int l1313 = 0; l1313 < 2; l1313 = l1313 + 1) {
			fVec366[l1313] = 0.0;
		}
		for (int l1314 = 0; l1314 < 2; l1314 = l1314 + 1) {
			iRec959[l1314] = 0;
		}
		for (int l1315 = 0; l1315 < 2; l1315 = l1315 + 1) {
			fRec960[l1315] = 0.0;
		}
		for (int l1316 = 0; l1316 < 2; l1316 = l1316 + 1) {
			fVec367[l1316] = 0.0;
		}
		for (int l1317 = 0; l1317 < 2; l1317 = l1317 + 1) {
			iRec961[l1317] = 0;
		}
		for (int l1318 = 0; l1318 < 2; l1318 = l1318 + 1) {
			fRec962[l1318] = 0.0;
		}
		for (int l1319 = 0; l1319 < 2; l1319 = l1319 + 1) {
			fVec368[l1319] = 0.0;
		}
		for (int l1320 = 0; l1320 < 2; l1320 = l1320 + 1) {
			iRec963[l1320] = 0;
		}
		for (int l1321 = 0; l1321 < 2; l1321 = l1321 + 1) {
			fRec964[l1321] = 0.0;
		}
		for (int l1322 = 0; l1322 < 2; l1322 = l1322 + 1) {
			fVec369[l1322] = 0.0;
		}
		for (int l1323 = 0; l1323 < 2; l1323 = l1323 + 1) {
			iRec965[l1323] = 0;
		}
		for (int l1324 = 0; l1324 < 2; l1324 = l1324 + 1) {
			fRec966[l1324] = 0.0;
		}
		for (int l1325 = 0; l1325 < 2; l1325 = l1325 + 1) {
			fVec370[l1325] = 0.0;
		}
		for (int l1326 = 0; l1326 < 2; l1326 = l1326 + 1) {
			iRec967[l1326] = 0;
		}
		for (int l1327 = 0; l1327 < 2; l1327 = l1327 + 1) {
			fRec968[l1327] = 0.0;
		}
		for (int l1328 = 0; l1328 < 2; l1328 = l1328 + 1) {
			fVec371[l1328] = 0.0;
		}
		for (int l1329 = 0; l1329 < 2; l1329 = l1329 + 1) {
			iRec969[l1329] = 0;
		}
		for (int l1330 = 0; l1330 < 2; l1330 = l1330 + 1) {
			fRec970[l1330] = 0.0;
		}
		for (int l1331 = 0; l1331 < 2; l1331 = l1331 + 1) {
			fVec372[l1331] = 0.0;
		}
		for (int l1332 = 0; l1332 < 2; l1332 = l1332 + 1) {
			iRec971[l1332] = 0;
		}
		for (int l1333 = 0; l1333 < 2; l1333 = l1333 + 1) {
			fRec972[l1333] = 0.0;
		}
		for (int l1334 = 0; l1334 < 2; l1334 = l1334 + 1) {
			fRec973[l1334] = 0.0;
		}
		for (int l1335 = 0; l1335 < 2; l1335 = l1335 + 1) {
			fVec373[l1335] = 0.0;
		}
		for (int l1336 = 0; l1336 < 2; l1336 = l1336 + 1) {
			iRec974[l1336] = 0;
		}
		for (int l1337 = 0; l1337 < 2; l1337 = l1337 + 1) {
			fRec975[l1337] = 0.0;
		}
		for (int l1338 = 0; l1338 < 2; l1338 = l1338 + 1) {
			fVec374[l1338] = 0.0;
		}
		for (int l1339 = 0; l1339 < 2; l1339 = l1339 + 1) {
			iRec976[l1339] = 0;
		}
		for (int l1340 = 0; l1340 < 2; l1340 = l1340 + 1) {
			fRec977[l1340] = 0.0;
		}
		for (int l1341 = 0; l1341 < 2; l1341 = l1341 + 1) {
			fVec375[l1341] = 0.0;
		}
		for (int l1342 = 0; l1342 < 2; l1342 = l1342 + 1) {
			iRec978[l1342] = 0;
		}
		for (int l1343 = 0; l1343 < 2; l1343 = l1343 + 1) {
			fRec979[l1343] = 0.0;
		}
		for (int l1344 = 0; l1344 < 2; l1344 = l1344 + 1) {
			fVec376[l1344] = 0.0;
		}
		for (int l1345 = 0; l1345 < 2; l1345 = l1345 + 1) {
			iRec980[l1345] = 0;
		}
		for (int l1346 = 0; l1346 < 2; l1346 = l1346 + 1) {
			fRec981[l1346] = 0.0;
		}
		for (int l1347 = 0; l1347 < 2; l1347 = l1347 + 1) {
			fVec377[l1347] = 0.0;
		}
		for (int l1348 = 0; l1348 < 2; l1348 = l1348 + 1) {
			iRec982[l1348] = 0;
		}
		for (int l1349 = 0; l1349 < 2; l1349 = l1349 + 1) {
			fRec983[l1349] = 0.0;
		}
		for (int l1350 = 0; l1350 < 2; l1350 = l1350 + 1) {
			fVec378[l1350] = 0.0;
		}
		for (int l1351 = 0; l1351 < 2; l1351 = l1351 + 1) {
			iRec984[l1351] = 0;
		}
		for (int l1352 = 0; l1352 < 2; l1352 = l1352 + 1) {
			fRec985[l1352] = 0.0;
		}
		for (int l1353 = 0; l1353 < 2; l1353 = l1353 + 1) {
			fVec379[l1353] = 0.0;
		}
		for (int l1354 = 0; l1354 < 2; l1354 = l1354 + 1) {
			iRec986[l1354] = 0;
		}
		for (int l1355 = 0; l1355 < 2; l1355 = l1355 + 1) {
			fRec987[l1355] = 0.0;
		}
		for (int l1356 = 0; l1356 < 2; l1356 = l1356 + 1) {
			fVec380[l1356] = 0.0;
		}
		for (int l1357 = 0; l1357 < 2; l1357 = l1357 + 1) {
			iRec988[l1357] = 0;
		}
		for (int l1358 = 0; l1358 < 2; l1358 = l1358 + 1) {
			fRec989[l1358] = 0.0;
		}
		for (int l1359 = 0; l1359 < 2; l1359 = l1359 + 1) {
			fVec381[l1359] = 0.0;
		}
		for (int l1360 = 0; l1360 < 2; l1360 = l1360 + 1) {
			iRec990[l1360] = 0;
		}
		for (int l1361 = 0; l1361 < 2; l1361 = l1361 + 1) {
			fRec991[l1361] = 0.0;
		}
		for (int l1362 = 0; l1362 < 2; l1362 = l1362 + 1) {
			fVec382[l1362] = 0.0;
		}
		for (int l1363 = 0; l1363 < 2; l1363 = l1363 + 1) {
			iRec992[l1363] = 0;
		}
		for (int l1364 = 0; l1364 < 2; l1364 = l1364 + 1) {
			fRec993[l1364] = 0.0;
		}
		for (int l1365 = 0; l1365 < 2; l1365 = l1365 + 1) {
			fVec383[l1365] = 0.0;
		}
		for (int l1366 = 0; l1366 < 2; l1366 = l1366 + 1) {
			iRec994[l1366] = 0;
		}
		for (int l1367 = 0; l1367 < 2; l1367 = l1367 + 1) {
			fRec995[l1367] = 0.0;
		}
		for (int l1368 = 0; l1368 < 2; l1368 = l1368 + 1) {
			fVec384[l1368] = 0.0;
		}
		for (int l1369 = 0; l1369 < 2; l1369 = l1369 + 1) {
			iRec996[l1369] = 0;
		}
		for (int l1370 = 0; l1370 < 2; l1370 = l1370 + 1) {
			fRec997[l1370] = 0.0;
		}
		for (int l1371 = 0; l1371 < 2; l1371 = l1371 + 1) {
			fVec385[l1371] = 0.0;
		}
		for (int l1372 = 0; l1372 < 2; l1372 = l1372 + 1) {
			iRec998[l1372] = 0;
		}
		for (int l1373 = 0; l1373 < 2; l1373 = l1373 + 1) {
			fRec999[l1373] = 0.0;
		}
		for (int l1374 = 0; l1374 < 2; l1374 = l1374 + 1) {
			fVec386[l1374] = 0.0;
		}
		for (int l1375 = 0; l1375 < 2; l1375 = l1375 + 1) {
			iRec1000[l1375] = 0;
		}
		for (int l1376 = 0; l1376 < 2; l1376 = l1376 + 1) {
			fRec1001[l1376] = 0.0;
		}
		for (int l1377 = 0; l1377 < 2; l1377 = l1377 + 1) {
			fVec387[l1377] = 0.0;
		}
		for (int l1378 = 0; l1378 < 2; l1378 = l1378 + 1) {
			iRec1002[l1378] = 0;
		}
		for (int l1379 = 0; l1379 < 2; l1379 = l1379 + 1) {
			fRec1003[l1379] = 0.0;
		}
		for (int l1380 = 0; l1380 < 2; l1380 = l1380 + 1) {
			fVec388[l1380] = 0.0;
		}
		for (int l1381 = 0; l1381 < 2; l1381 = l1381 + 1) {
			iRec1004[l1381] = 0;
		}
		for (int l1382 = 0; l1382 < 2; l1382 = l1382 + 1) {
			fRec1005[l1382] = 0.0;
		}
		for (int l1383 = 0; l1383 < 2; l1383 = l1383 + 1) {
			fVec389[l1383] = 0.0;
		}
		for (int l1384 = 0; l1384 < 2; l1384 = l1384 + 1) {
			iRec1006[l1384] = 0;
		}
		for (int l1385 = 0; l1385 < 2; l1385 = l1385 + 1) {
			fRec1007[l1385] = 0.0;
		}
		for (int l1386 = 0; l1386 < 2; l1386 = l1386 + 1) {
			fVec390[l1386] = 0.0;
		}
		for (int l1387 = 0; l1387 < 2; l1387 = l1387 + 1) {
			iRec1008[l1387] = 0;
		}
		for (int l1388 = 0; l1388 < 2; l1388 = l1388 + 1) {
			fRec1009[l1388] = 0.0;
		}
		for (int l1389 = 0; l1389 < 2; l1389 = l1389 + 1) {
			fVec391[l1389] = 0.0;
		}
		for (int l1390 = 0; l1390 < 2; l1390 = l1390 + 1) {
			iRec1010[l1390] = 0;
		}
		for (int l1391 = 0; l1391 < 2; l1391 = l1391 + 1) {
			fRec1011[l1391] = 0.0;
		}
		for (int l1392 = 0; l1392 < 2; l1392 = l1392 + 1) {
			fVec392[l1392] = 0.0;
		}
		for (int l1393 = 0; l1393 < 2; l1393 = l1393 + 1) {
			iRec1012[l1393] = 0;
		}
		for (int l1394 = 0; l1394 < 2; l1394 = l1394 + 1) {
			fRec1013[l1394] = 0.0;
		}
		for (int l1395 = 0; l1395 < 2; l1395 = l1395 + 1) {
			fVec393[l1395] = 0.0;
		}
		for (int l1396 = 0; l1396 < 2; l1396 = l1396 + 1) {
			iRec1014[l1396] = 0;
		}
		for (int l1397 = 0; l1397 < 2; l1397 = l1397 + 1) {
			fRec1015[l1397] = 0.0;
		}
		for (int l1398 = 0; l1398 < 2; l1398 = l1398 + 1) {
			fVec394[l1398] = 0.0;
		}
		for (int l1399 = 0; l1399 < 2; l1399 = l1399 + 1) {
			iRec1016[l1399] = 0;
		}
		for (int l1400 = 0; l1400 < 2; l1400 = l1400 + 1) {
			fRec1017[l1400] = 0.0;
		}
		for (int l1401 = 0; l1401 < 2; l1401 = l1401 + 1) {
			fVec395[l1401] = 0.0;
		}
		for (int l1402 = 0; l1402 < 2; l1402 = l1402 + 1) {
			iRec1018[l1402] = 0;
		}
		for (int l1403 = 0; l1403 < 2; l1403 = l1403 + 1) {
			fRec1019[l1403] = 0.0;
		}
		for (int l1404 = 0; l1404 < 2; l1404 = l1404 + 1) {
			fVec396[l1404] = 0.0;
		}
		for (int l1405 = 0; l1405 < 2; l1405 = l1405 + 1) {
			iRec1020[l1405] = 0;
		}
		for (int l1406 = 0; l1406 < 2; l1406 = l1406 + 1) {
			fRec1021[l1406] = 0.0;
		}
		for (int l1407 = 0; l1407 < 2; l1407 = l1407 + 1) {
			fVec397[l1407] = 0.0;
		}
		for (int l1408 = 0; l1408 < 2; l1408 = l1408 + 1) {
			iRec1022[l1408] = 0;
		}
		for (int l1409 = 0; l1409 < 2; l1409 = l1409 + 1) {
			fRec1023[l1409] = 0.0;
		}
		for (int l1410 = 0; l1410 < 2; l1410 = l1410 + 1) {
			fVec398[l1410] = 0.0;
		}
		for (int l1411 = 0; l1411 < 2; l1411 = l1411 + 1) {
			iRec1024[l1411] = 0;
		}
		for (int l1412 = 0; l1412 < 2; l1412 = l1412 + 1) {
			fRec1025[l1412] = 0.0;
		}
		for (int l1413 = 0; l1413 < 2; l1413 = l1413 + 1) {
			fVec399[l1413] = 0.0;
		}
		for (int l1414 = 0; l1414 < 2; l1414 = l1414 + 1) {
			iRec1026[l1414] = 0;
		}
		for (int l1415 = 0; l1415 < 2; l1415 = l1415 + 1) {
			fRec1027[l1415] = 0.0;
		}
		for (int l1416 = 0; l1416 < 2; l1416 = l1416 + 1) {
			fVec400[l1416] = 0.0;
		}
		for (int l1417 = 0; l1417 < 2; l1417 = l1417 + 1) {
			iRec1028[l1417] = 0;
		}
		for (int l1418 = 0; l1418 < 2; l1418 = l1418 + 1) {
			fRec1029[l1418] = 0.0;
		}
		for (int l1419 = 0; l1419 < 2; l1419 = l1419 + 1) {
			fRec1030[l1419] = 0.0;
		}
		for (int l1420 = 0; l1420 < 2; l1420 = l1420 + 1) {
			fVec401[l1420] = 0.0;
		}
		for (int l1421 = 0; l1421 < 2; l1421 = l1421 + 1) {
			iRec1031[l1421] = 0;
		}
		for (int l1422 = 0; l1422 < 2; l1422 = l1422 + 1) {
			fRec1032[l1422] = 0.0;
		}
		for (int l1423 = 0; l1423 < 2; l1423 = l1423 + 1) {
			fVec402[l1423] = 0.0;
		}
		for (int l1424 = 0; l1424 < 2; l1424 = l1424 + 1) {
			iRec1033[l1424] = 0;
		}
		for (int l1425 = 0; l1425 < 2; l1425 = l1425 + 1) {
			fRec1034[l1425] = 0.0;
		}
		for (int l1426 = 0; l1426 < 2; l1426 = l1426 + 1) {
			fRec1035[l1426] = 0.0;
		}
		for (int l1427 = 0; l1427 < 2; l1427 = l1427 + 1) {
			fRec1036[l1427] = 0.0;
		}
		for (int l1428 = 0; l1428 < 2; l1428 = l1428 + 1) {
			fVec403[l1428] = 0.0;
		}
		for (int l1429 = 0; l1429 < 2; l1429 = l1429 + 1) {
			iRec1037[l1429] = 0;
		}
		for (int l1430 = 0; l1430 < 2; l1430 = l1430 + 1) {
			fRec1038[l1430] = 0.0;
		}
		for (int l1431 = 0; l1431 < 2; l1431 = l1431 + 1) {
			fVec404[l1431] = 0.0;
		}
		for (int l1432 = 0; l1432 < 2; l1432 = l1432 + 1) {
			iRec1039[l1432] = 0;
		}
		for (int l1433 = 0; l1433 < 2; l1433 = l1433 + 1) {
			fRec1040[l1433] = 0.0;
		}
		for (int l1434 = 0; l1434 < 2; l1434 = l1434 + 1) {
			fVec405[l1434] = 0.0;
		}
		for (int l1435 = 0; l1435 < 2; l1435 = l1435 + 1) {
			iRec1041[l1435] = 0;
		}
		for (int l1436 = 0; l1436 < 2; l1436 = l1436 + 1) {
			fRec1042[l1436] = 0.0;
		}
		for (int l1437 = 0; l1437 < 2; l1437 = l1437 + 1) {
			fVec406[l1437] = 0.0;
		}
		for (int l1438 = 0; l1438 < 2; l1438 = l1438 + 1) {
			iRec1043[l1438] = 0;
		}
		for (int l1439 = 0; l1439 < 2; l1439 = l1439 + 1) {
			fRec1044[l1439] = 0.0;
		}
		for (int l1440 = 0; l1440 < 2; l1440 = l1440 + 1) {
			fRec1045[l1440] = 0.0;
		}
		for (int l1441 = 0; l1441 < 2; l1441 = l1441 + 1) {
			fVec407[l1441] = 0.0;
		}
		for (int l1442 = 0; l1442 < 2; l1442 = l1442 + 1) {
			iRec1046[l1442] = 0;
		}
		for (int l1443 = 0; l1443 < 2; l1443 = l1443 + 1) {
			fRec1047[l1443] = 0.0;
		}
		for (int l1444 = 0; l1444 < 2; l1444 = l1444 + 1) {
			fVec408[l1444] = 0.0;
		}
		for (int l1445 = 0; l1445 < 2; l1445 = l1445 + 1) {
			iRec1048[l1445] = 0;
		}
		for (int l1446 = 0; l1446 < 2; l1446 = l1446 + 1) {
			fRec1049[l1446] = 0.0;
		}
		for (int l1447 = 0; l1447 < 2; l1447 = l1447 + 1) {
			fVec409[l1447] = 0.0;
		}
		for (int l1448 = 0; l1448 < 2; l1448 = l1448 + 1) {
			iRec1050[l1448] = 0;
		}
		for (int l1449 = 0; l1449 < 2; l1449 = l1449 + 1) {
			fRec1051[l1449] = 0.0;
		}
		for (int l1450 = 0; l1450 < 2; l1450 = l1450 + 1) {
			fVec410[l1450] = 0.0;
		}
		for (int l1451 = 0; l1451 < 2; l1451 = l1451 + 1) {
			iRec1052[l1451] = 0;
		}
		for (int l1452 = 0; l1452 < 2; l1452 = l1452 + 1) {
			fRec1053[l1452] = 0.0;
		}
		for (int l1453 = 0; l1453 < 2; l1453 = l1453 + 1) {
			fVec411[l1453] = 0.0;
		}
		for (int l1454 = 0; l1454 < 2; l1454 = l1454 + 1) {
			iRec1054[l1454] = 0;
		}
		for (int l1455 = 0; l1455 < 2; l1455 = l1455 + 1) {
			fRec1055[l1455] = 0.0;
		}
		for (int l1456 = 0; l1456 < 2; l1456 = l1456 + 1) {
			fVec412[l1456] = 0.0;
		}
		for (int l1457 = 0; l1457 < 2; l1457 = l1457 + 1) {
			iRec1056[l1457] = 0;
		}
		for (int l1458 = 0; l1458 < 2; l1458 = l1458 + 1) {
			fRec1057[l1458] = 0.0;
		}
		for (int l1459 = 0; l1459 < 2; l1459 = l1459 + 1) {
			fVec413[l1459] = 0.0;
		}
		for (int l1460 = 0; l1460 < 2; l1460 = l1460 + 1) {
			iRec1058[l1460] = 0;
		}
		for (int l1461 = 0; l1461 < 2; l1461 = l1461 + 1) {
			fRec1059[l1461] = 0.0;
		}
		for (int l1462 = 0; l1462 < 2; l1462 = l1462 + 1) {
			fRec1060[l1462] = 0.0;
		}
		for (int l1463 = 0; l1463 < 2; l1463 = l1463 + 1) {
			fVec414[l1463] = 0.0;
		}
		for (int l1464 = 0; l1464 < 2; l1464 = l1464 + 1) {
			iRec1061[l1464] = 0;
		}
		for (int l1465 = 0; l1465 < 2; l1465 = l1465 + 1) {
			fRec1062[l1465] = 0.0;
		}
		for (int l1466 = 0; l1466 < 2; l1466 = l1466 + 1) {
			fVec415[l1466] = 0.0;
		}
		for (int l1467 = 0; l1467 < 2; l1467 = l1467 + 1) {
			iRec1063[l1467] = 0;
		}
		for (int l1468 = 0; l1468 < 2; l1468 = l1468 + 1) {
			fRec1064[l1468] = 0.0;
		}
		for (int l1469 = 0; l1469 < 2; l1469 = l1469 + 1) {
			fRec1065[l1469] = 0.0;
		}
		for (int l1470 = 0; l1470 < 2; l1470 = l1470 + 1) {
			fVec416[l1470] = 0.0;
		}
		for (int l1471 = 0; l1471 < 2; l1471 = l1471 + 1) {
			iRec1066[l1471] = 0;
		}
		for (int l1472 = 0; l1472 < 2; l1472 = l1472 + 1) {
			fRec1067[l1472] = 0.0;
		}
		for (int l1473 = 0; l1473 < 2; l1473 = l1473 + 1) {
			fVec417[l1473] = 0.0;
		}
		for (int l1474 = 0; l1474 < 2; l1474 = l1474 + 1) {
			iRec1068[l1474] = 0;
		}
		for (int l1475 = 0; l1475 < 2; l1475 = l1475 + 1) {
			fRec1069[l1475] = 0.0;
		}
		for (int l1476 = 0; l1476 < 2; l1476 = l1476 + 1) {
			fVec418[l1476] = 0.0;
		}
		for (int l1477 = 0; l1477 < 2; l1477 = l1477 + 1) {
			iRec1070[l1477] = 0;
		}
		for (int l1478 = 0; l1478 < 2; l1478 = l1478 + 1) {
			fRec1071[l1478] = 0.0;
		}
		for (int l1479 = 0; l1479 < 2; l1479 = l1479 + 1) {
			fVec419[l1479] = 0.0;
		}
		for (int l1480 = 0; l1480 < 2; l1480 = l1480 + 1) {
			iRec1072[l1480] = 0;
		}
		for (int l1481 = 0; l1481 < 2; l1481 = l1481 + 1) {
			fRec1073[l1481] = 0.0;
		}
		for (int l1482 = 0; l1482 < 2; l1482 = l1482 + 1) {
			fVec420[l1482] = 0.0;
		}
		for (int l1483 = 0; l1483 < 2; l1483 = l1483 + 1) {
			iRec1074[l1483] = 0;
		}
		for (int l1484 = 0; l1484 < 2; l1484 = l1484 + 1) {
			fRec1075[l1484] = 0.0;
		}
		for (int l1485 = 0; l1485 < 2; l1485 = l1485 + 1) {
			fVec421[l1485] = 0.0;
		}
		for (int l1486 = 0; l1486 < 2; l1486 = l1486 + 1) {
			iRec1076[l1486] = 0;
		}
		for (int l1487 = 0; l1487 < 2; l1487 = l1487 + 1) {
			fRec1077[l1487] = 0.0;
		}
		for (int l1488 = 0; l1488 < 2; l1488 = l1488 + 1) {
			fVec422[l1488] = 0.0;
		}
		for (int l1489 = 0; l1489 < 2; l1489 = l1489 + 1) {
			iRec1078[l1489] = 0;
		}
		for (int l1490 = 0; l1490 < 2; l1490 = l1490 + 1) {
			fRec1079[l1490] = 0.0;
		}
		for (int l1491 = 0; l1491 < 2; l1491 = l1491 + 1) {
			fVec423[l1491] = 0.0;
		}
		for (int l1492 = 0; l1492 < 2; l1492 = l1492 + 1) {
			iRec1080[l1492] = 0;
		}
		for (int l1493 = 0; l1493 < 2; l1493 = l1493 + 1) {
			fRec1081[l1493] = 0.0;
		}
		for (int l1494 = 0; l1494 < 2; l1494 = l1494 + 1) {
			fVec424[l1494] = 0.0;
		}
		for (int l1495 = 0; l1495 < 2; l1495 = l1495 + 1) {
			iRec1082[l1495] = 0;
		}
		for (int l1496 = 0; l1496 < 2; l1496 = l1496 + 1) {
			fRec1083[l1496] = 0.0;
		}
		for (int l1497 = 0; l1497 < 2; l1497 = l1497 + 1) {
			fVec425[l1497] = 0.0;
		}
		for (int l1498 = 0; l1498 < 2; l1498 = l1498 + 1) {
			iRec1084[l1498] = 0;
		}
		for (int l1499 = 0; l1499 < 2; l1499 = l1499 + 1) {
			fRec1085[l1499] = 0.0;
		}
		for (int l1500 = 0; l1500 < 2; l1500 = l1500 + 1) {
			fVec426[l1500] = 0.0;
		}
		for (int l1501 = 0; l1501 < 2; l1501 = l1501 + 1) {
			iRec1086[l1501] = 0;
		}
		for (int l1502 = 0; l1502 < 2; l1502 = l1502 + 1) {
			fRec1087[l1502] = 0.0;
		}
		for (int l1503 = 0; l1503 < 2; l1503 = l1503 + 1) {
			fVec427[l1503] = 0.0;
		}
		for (int l1504 = 0; l1504 < 2; l1504 = l1504 + 1) {
			iRec1088[l1504] = 0;
		}
		for (int l1505 = 0; l1505 < 2; l1505 = l1505 + 1) {
			fRec1089[l1505] = 0.0;
		}
		for (int l1506 = 0; l1506 < 2; l1506 = l1506 + 1) {
			fVec428[l1506] = 0.0;
		}
		for (int l1507 = 0; l1507 < 2; l1507 = l1507 + 1) {
			iRec1090[l1507] = 0;
		}
		for (int l1508 = 0; l1508 < 2; l1508 = l1508 + 1) {
			fRec1091[l1508] = 0.0;
		}
		for (int l1509 = 0; l1509 < 2; l1509 = l1509 + 1) {
			fVec429[l1509] = 0.0;
		}
		for (int l1510 = 0; l1510 < 2; l1510 = l1510 + 1) {
			iRec1092[l1510] = 0;
		}
		for (int l1511 = 0; l1511 < 2; l1511 = l1511 + 1) {
			fRec1093[l1511] = 0.0;
		}
		for (int l1512 = 0; l1512 < 2; l1512 = l1512 + 1) {
			fVec430[l1512] = 0.0;
		}
		for (int l1513 = 0; l1513 < 2; l1513 = l1513 + 1) {
			iRec1094[l1513] = 0;
		}
		for (int l1514 = 0; l1514 < 2; l1514 = l1514 + 1) {
			fRec1095[l1514] = 0.0;
		}
		for (int l1515 = 0; l1515 < 2; l1515 = l1515 + 1) {
			fVec431[l1515] = 0.0;
		}
		for (int l1516 = 0; l1516 < 2; l1516 = l1516 + 1) {
			iRec1096[l1516] = 0;
		}
		for (int l1517 = 0; l1517 < 2; l1517 = l1517 + 1) {
			fRec1097[l1517] = 0.0;
		}
		for (int l1518 = 0; l1518 < 2; l1518 = l1518 + 1) {
			fVec432[l1518] = 0.0;
		}
		for (int l1519 = 0; l1519 < 2; l1519 = l1519 + 1) {
			iRec1098[l1519] = 0;
		}
		for (int l1520 = 0; l1520 < 2; l1520 = l1520 + 1) {
			fRec1099[l1520] = 0.0;
		}
		for (int l1521 = 0; l1521 < 2; l1521 = l1521 + 1) {
			fVec433[l1521] = 0.0;
		}
		for (int l1522 = 0; l1522 < 2; l1522 = l1522 + 1) {
			iRec1100[l1522] = 0;
		}
		for (int l1523 = 0; l1523 < 2; l1523 = l1523 + 1) {
			fRec1101[l1523] = 0.0;
		}
		for (int l1524 = 0; l1524 < 2; l1524 = l1524 + 1) {
			fRec1102[l1524] = 0.0;
		}
		for (int l1525 = 0; l1525 < 2; l1525 = l1525 + 1) {
			fVec434[l1525] = 0.0;
		}
		for (int l1526 = 0; l1526 < 2; l1526 = l1526 + 1) {
			iRec1103[l1526] = 0;
		}
		for (int l1527 = 0; l1527 < 2; l1527 = l1527 + 1) {
			fRec1104[l1527] = 0.0;
		}
		for (int l1528 = 0; l1528 < 2; l1528 = l1528 + 1) {
			fVec435[l1528] = 0.0;
		}
		for (int l1529 = 0; l1529 < 2; l1529 = l1529 + 1) {
			iRec1105[l1529] = 0;
		}
		for (int l1530 = 0; l1530 < 2; l1530 = l1530 + 1) {
			fRec1106[l1530] = 0.0;
		}
		for (int l1531 = 0; l1531 < 2; l1531 = l1531 + 1) {
			fVec436[l1531] = 0.0;
		}
		for (int l1532 = 0; l1532 < 2; l1532 = l1532 + 1) {
			iRec1107[l1532] = 0;
		}
		for (int l1533 = 0; l1533 < 2; l1533 = l1533 + 1) {
			fRec1108[l1533] = 0.0;
		}
		for (int l1534 = 0; l1534 < 2; l1534 = l1534 + 1) {
			fVec437[l1534] = 0.0;
		}
		for (int l1535 = 0; l1535 < 2; l1535 = l1535 + 1) {
			iRec1109[l1535] = 0;
		}
		for (int l1536 = 0; l1536 < 2; l1536 = l1536 + 1) {
			fRec1110[l1536] = 0.0;
		}
		for (int l1537 = 0; l1537 < 2; l1537 = l1537 + 1) {
			fVec438[l1537] = 0.0;
		}
		for (int l1538 = 0; l1538 < 2; l1538 = l1538 + 1) {
			iRec1111[l1538] = 0;
		}
		for (int l1539 = 0; l1539 < 2; l1539 = l1539 + 1) {
			fRec1112[l1539] = 0.0;
		}
		for (int l1540 = 0; l1540 < 2; l1540 = l1540 + 1) {
			fVec439[l1540] = 0.0;
		}
		for (int l1541 = 0; l1541 < 2; l1541 = l1541 + 1) {
			iRec1113[l1541] = 0;
		}
		for (int l1542 = 0; l1542 < 2; l1542 = l1542 + 1) {
			fRec1114[l1542] = 0.0;
		}
		for (int l1543 = 0; l1543 < 2; l1543 = l1543 + 1) {
			fVec440[l1543] = 0.0;
		}
		for (int l1544 = 0; l1544 < 2; l1544 = l1544 + 1) {
			iRec1115[l1544] = 0;
		}
		for (int l1545 = 0; l1545 < 2; l1545 = l1545 + 1) {
			fRec1116[l1545] = 0.0;
		}
		for (int l1546 = 0; l1546 < 2; l1546 = l1546 + 1) {
			fVec441[l1546] = 0.0;
		}
		for (int l1547 = 0; l1547 < 2; l1547 = l1547 + 1) {
			iRec1117[l1547] = 0;
		}
		for (int l1548 = 0; l1548 < 2; l1548 = l1548 + 1) {
			fRec1118[l1548] = 0.0;
		}
		for (int l1549 = 0; l1549 < 2; l1549 = l1549 + 1) {
			fVec442[l1549] = 0.0;
		}
		for (int l1550 = 0; l1550 < 2; l1550 = l1550 + 1) {
			iRec1119[l1550] = 0;
		}
		for (int l1551 = 0; l1551 < 2; l1551 = l1551 + 1) {
			fRec1120[l1551] = 0.0;
		}
		for (int l1552 = 0; l1552 < 2; l1552 = l1552 + 1) {
			fVec443[l1552] = 0.0;
		}
		for (int l1553 = 0; l1553 < 2; l1553 = l1553 + 1) {
			iRec1121[l1553] = 0;
		}
		for (int l1554 = 0; l1554 < 2; l1554 = l1554 + 1) {
			fRec1122[l1554] = 0.0;
		}
		for (int l1555 = 0; l1555 < 2; l1555 = l1555 + 1) {
			fVec444[l1555] = 0.0;
		}
		for (int l1556 = 0; l1556 < 2; l1556 = l1556 + 1) {
			iRec1123[l1556] = 0;
		}
		for (int l1557 = 0; l1557 < 2; l1557 = l1557 + 1) {
			fRec1124[l1557] = 0.0;
		}
		for (int l1558 = 0; l1558 < 2; l1558 = l1558 + 1) {
			fVec445[l1558] = 0.0;
		}
		for (int l1559 = 0; l1559 < 2; l1559 = l1559 + 1) {
			iRec1125[l1559] = 0;
		}
		for (int l1560 = 0; l1560 < 2; l1560 = l1560 + 1) {
			fRec1126[l1560] = 0.0;
		}
		for (int l1561 = 0; l1561 < 2; l1561 = l1561 + 1) {
			fVec446[l1561] = 0.0;
		}
		for (int l1562 = 0; l1562 < 2; l1562 = l1562 + 1) {
			iRec1127[l1562] = 0;
		}
		for (int l1563 = 0; l1563 < 2; l1563 = l1563 + 1) {
			fRec1128[l1563] = 0.0;
		}
		for (int l1564 = 0; l1564 < 2; l1564 = l1564 + 1) {
			fVec447[l1564] = 0.0;
		}
		for (int l1565 = 0; l1565 < 2; l1565 = l1565 + 1) {
			iRec1129[l1565] = 0;
		}
		for (int l1566 = 0; l1566 < 2; l1566 = l1566 + 1) {
			fRec1130[l1566] = 0.0;
		}
		for (int l1567 = 0; l1567 < 2; l1567 = l1567 + 1) {
			fVec448[l1567] = 0.0;
		}
		for (int l1568 = 0; l1568 < 2; l1568 = l1568 + 1) {
			iRec1131[l1568] = 0;
		}
		for (int l1569 = 0; l1569 < 2; l1569 = l1569 + 1) {
			fRec1132[l1569] = 0.0;
		}
		for (int l1570 = 0; l1570 < 2; l1570 = l1570 + 1) {
			fVec449[l1570] = 0.0;
		}
		for (int l1571 = 0; l1571 < 2; l1571 = l1571 + 1) {
			iRec1133[l1571] = 0;
		}
		for (int l1572 = 0; l1572 < 2; l1572 = l1572 + 1) {
			fRec1134[l1572] = 0.0;
		}
		for (int l1573 = 0; l1573 < 2; l1573 = l1573 + 1) {
			fVec450[l1573] = 0.0;
		}
		for (int l1574 = 0; l1574 < 2; l1574 = l1574 + 1) {
			iRec1135[l1574] = 0;
		}
		for (int l1575 = 0; l1575 < 2; l1575 = l1575 + 1) {
			fRec1136[l1575] = 0.0;
		}
		for (int l1576 = 0; l1576 < 2; l1576 = l1576 + 1) {
			fVec451[l1576] = 0.0;
		}
		for (int l1577 = 0; l1577 < 2; l1577 = l1577 + 1) {
			iRec1137[l1577] = 0;
		}
		for (int l1578 = 0; l1578 < 2; l1578 = l1578 + 1) {
			fRec1138[l1578] = 0.0;
		}
		for (int l1579 = 0; l1579 < 2; l1579 = l1579 + 1) {
			fVec452[l1579] = 0.0;
		}
		for (int l1580 = 0; l1580 < 2; l1580 = l1580 + 1) {
			iRec1139[l1580] = 0;
		}
		for (int l1581 = 0; l1581 < 2; l1581 = l1581 + 1) {
			fRec1140[l1581] = 0.0;
		}
		for (int l1582 = 0; l1582 < 2; l1582 = l1582 + 1) {
			fVec453[l1582] = 0.0;
		}
		for (int l1583 = 0; l1583 < 2; l1583 = l1583 + 1) {
			iRec1141[l1583] = 0;
		}
		for (int l1584 = 0; l1584 < 2; l1584 = l1584 + 1) {
			fRec1142[l1584] = 0.0;
		}
		for (int l1585 = 0; l1585 < 2; l1585 = l1585 + 1) {
			fVec454[l1585] = 0.0;
		}
		for (int l1586 = 0; l1586 < 2; l1586 = l1586 + 1) {
			iRec1143[l1586] = 0;
		}
		for (int l1587 = 0; l1587 < 2; l1587 = l1587 + 1) {
			fRec1144[l1587] = 0.0;
		}
		for (int l1588 = 0; l1588 < 2; l1588 = l1588 + 1) {
			fVec455[l1588] = 0.0;
		}
		for (int l1589 = 0; l1589 < 2; l1589 = l1589 + 1) {
			iRec1145[l1589] = 0;
		}
		for (int l1590 = 0; l1590 < 2; l1590 = l1590 + 1) {
			fRec1146[l1590] = 0.0;
		}
		for (int l1591 = 0; l1591 < 2; l1591 = l1591 + 1) {
			fVec456[l1591] = 0.0;
		}
		for (int l1592 = 0; l1592 < 2; l1592 = l1592 + 1) {
			iRec1147[l1592] = 0;
		}
		for (int l1593 = 0; l1593 < 2; l1593 = l1593 + 1) {
			fRec1148[l1593] = 0.0;
		}
		for (int l1594 = 0; l1594 < 2; l1594 = l1594 + 1) {
			fVec457[l1594] = 0.0;
		}
		for (int l1595 = 0; l1595 < 2; l1595 = l1595 + 1) {
			iRec1149[l1595] = 0;
		}
		for (int l1596 = 0; l1596 < 2; l1596 = l1596 + 1) {
			fRec1150[l1596] = 0.0;
		}
		for (int l1597 = 0; l1597 < 2; l1597 = l1597 + 1) {
			fVec458[l1597] = 0.0;
		}
		for (int l1598 = 0; l1598 < 2; l1598 = l1598 + 1) {
			iRec1151[l1598] = 0;
		}
		for (int l1599 = 0; l1599 < 2; l1599 = l1599 + 1) {
			fRec1152[l1599] = 0.0;
		}
		for (int l1600 = 0; l1600 < 2; l1600 = l1600 + 1) {
			fVec459[l1600] = 0.0;
		}
		for (int l1601 = 0; l1601 < 2; l1601 = l1601 + 1) {
			iRec1153[l1601] = 0;
		}
		for (int l1602 = 0; l1602 < 2; l1602 = l1602 + 1) {
			fRec1154[l1602] = 0.0;
		}
		for (int l1603 = 0; l1603 < 2; l1603 = l1603 + 1) {
			fVec460[l1603] = 0.0;
		}
		for (int l1604 = 0; l1604 < 2; l1604 = l1604 + 1) {
			iRec1155[l1604] = 0;
		}
		for (int l1605 = 0; l1605 < 2; l1605 = l1605 + 1) {
			fRec1156[l1605] = 0.0;
		}
		for (int l1606 = 0; l1606 < 2; l1606 = l1606 + 1) {
			fVec461[l1606] = 0.0;
		}
		for (int l1607 = 0; l1607 < 2; l1607 = l1607 + 1) {
			iRec1157[l1607] = 0;
		}
		for (int l1608 = 0; l1608 < 2; l1608 = l1608 + 1) {
			fRec1158[l1608] = 0.0;
		}
		for (int l1609 = 0; l1609 < 2; l1609 = l1609 + 1) {
			fVec462[l1609] = 0.0;
		}
		for (int l1610 = 0; l1610 < 2; l1610 = l1610 + 1) {
			iRec1159[l1610] = 0;
		}
		for (int l1611 = 0; l1611 < 2; l1611 = l1611 + 1) {
			fRec1160[l1611] = 0.0;
		}
		for (int l1612 = 0; l1612 < 2; l1612 = l1612 + 1) {
			fVec463[l1612] = 0.0;
		}
		for (int l1613 = 0; l1613 < 2; l1613 = l1613 + 1) {
			iRec1161[l1613] = 0;
		}
		for (int l1614 = 0; l1614 < 2; l1614 = l1614 + 1) {
			fRec1162[l1614] = 0.0;
		}
		for (int l1615 = 0; l1615 < 2; l1615 = l1615 + 1) {
			fVec464[l1615] = 0.0;
		}
		for (int l1616 = 0; l1616 < 2; l1616 = l1616 + 1) {
			iRec1163[l1616] = 0;
		}
		for (int l1617 = 0; l1617 < 2; l1617 = l1617 + 1) {
			fRec1164[l1617] = 0.0;
		}
		for (int l1618 = 0; l1618 < 2; l1618 = l1618 + 1) {
			fVec465[l1618] = 0.0;
		}
		for (int l1619 = 0; l1619 < 2; l1619 = l1619 + 1) {
			iRec1165[l1619] = 0;
		}
		for (int l1620 = 0; l1620 < 2; l1620 = l1620 + 1) {
			fRec1166[l1620] = 0.0;
		}
		for (int l1621 = 0; l1621 < 2; l1621 = l1621 + 1) {
			fVec466[l1621] = 0.0;
		}
		for (int l1622 = 0; l1622 < 2; l1622 = l1622 + 1) {
			iRec1167[l1622] = 0;
		}
		for (int l1623 = 0; l1623 < 2; l1623 = l1623 + 1) {
			fRec1168[l1623] = 0.0;
		}
		for (int l1624 = 0; l1624 < 2; l1624 = l1624 + 1) {
			fVec467[l1624] = 0.0;
		}
		for (int l1625 = 0; l1625 < 2; l1625 = l1625 + 1) {
			iRec1169[l1625] = 0;
		}
		for (int l1626 = 0; l1626 < 2; l1626 = l1626 + 1) {
			fRec1170[l1626] = 0.0;
		}
		for (int l1627 = 0; l1627 < 2; l1627 = l1627 + 1) {
			fVec468[l1627] = 0.0;
		}
		for (int l1628 = 0; l1628 < 2; l1628 = l1628 + 1) {
			iRec1171[l1628] = 0;
		}
		for (int l1629 = 0; l1629 < 2; l1629 = l1629 + 1) {
			fRec1172[l1629] = 0.0;
		}
		for (int l1630 = 0; l1630 < 2; l1630 = l1630 + 1) {
			fVec469[l1630] = 0.0;
		}
		for (int l1631 = 0; l1631 < 2; l1631 = l1631 + 1) {
			iRec1173[l1631] = 0;
		}
		for (int l1632 = 0; l1632 < 2; l1632 = l1632 + 1) {
			fRec1174[l1632] = 0.0;
		}
		for (int l1633 = 0; l1633 < 2; l1633 = l1633 + 1) {
			fVec470[l1633] = 0.0;
		}
		for (int l1634 = 0; l1634 < 2; l1634 = l1634 + 1) {
			iRec1175[l1634] = 0;
		}
		for (int l1635 = 0; l1635 < 2; l1635 = l1635 + 1) {
			fRec1176[l1635] = 0.0;
		}
		for (int l1636 = 0; l1636 < 2; l1636 = l1636 + 1) {
			fVec471[l1636] = 0.0;
		}
		for (int l1637 = 0; l1637 < 2; l1637 = l1637 + 1) {
			iRec1177[l1637] = 0;
		}
		for (int l1638 = 0; l1638 < 2; l1638 = l1638 + 1) {
			fRec1178[l1638] = 0.0;
		}
		for (int l1639 = 0; l1639 < 2; l1639 = l1639 + 1) {
			fVec472[l1639] = 0.0;
		}
		for (int l1640 = 0; l1640 < 2; l1640 = l1640 + 1) {
			iRec1179[l1640] = 0;
		}
		for (int l1641 = 0; l1641 < 2; l1641 = l1641 + 1) {
			fRec1180[l1641] = 0.0;
		}
		for (int l1642 = 0; l1642 < 2; l1642 = l1642 + 1) {
			fVec473[l1642] = 0.0;
		}
		for (int l1643 = 0; l1643 < 2; l1643 = l1643 + 1) {
			iRec1181[l1643] = 0;
		}
		for (int l1644 = 0; l1644 < 2; l1644 = l1644 + 1) {
			fRec1182[l1644] = 0.0;
		}
		for (int l1645 = 0; l1645 < 2; l1645 = l1645 + 1) {
			fVec474[l1645] = 0.0;
		}
		for (int l1646 = 0; l1646 < 2; l1646 = l1646 + 1) {
			iRec1183[l1646] = 0;
		}
		for (int l1647 = 0; l1647 < 2; l1647 = l1647 + 1) {
			fRec1184[l1647] = 0.0;
		}
		for (int l1648 = 0; l1648 < 2; l1648 = l1648 + 1) {
			fVec475[l1648] = 0.0;
		}
		for (int l1649 = 0; l1649 < 2; l1649 = l1649 + 1) {
			iRec1185[l1649] = 0;
		}
		for (int l1650 = 0; l1650 < 2; l1650 = l1650 + 1) {
			fRec1186[l1650] = 0.0;
		}
		for (int l1651 = 0; l1651 < 2; l1651 = l1651 + 1) {
			fVec476[l1651] = 0.0;
		}
		for (int l1652 = 0; l1652 < 2; l1652 = l1652 + 1) {
			iRec1187[l1652] = 0;
		}
		for (int l1653 = 0; l1653 < 2; l1653 = l1653 + 1) {
			fRec1188[l1653] = 0.0;
		}
		for (int l1654 = 0; l1654 < 2; l1654 = l1654 + 1) {
			fVec477[l1654] = 0.0;
		}
		for (int l1655 = 0; l1655 < 2; l1655 = l1655 + 1) {
			iRec1189[l1655] = 0;
		}
		for (int l1656 = 0; l1656 < 2; l1656 = l1656 + 1) {
			fRec1190[l1656] = 0.0;
		}
		for (int l1657 = 0; l1657 < 2; l1657 = l1657 + 1) {
			fVec478[l1657] = 0.0;
		}
		for (int l1658 = 0; l1658 < 2; l1658 = l1658 + 1) {
			iRec1191[l1658] = 0;
		}
		for (int l1659 = 0; l1659 < 2; l1659 = l1659 + 1) {
			fRec1192[l1659] = 0.0;
		}
		for (int l1660 = 0; l1660 < 2; l1660 = l1660 + 1) {
			fVec479[l1660] = 0.0;
		}
		for (int l1661 = 0; l1661 < 2; l1661 = l1661 + 1) {
			iRec1193[l1661] = 0;
		}
		for (int l1662 = 0; l1662 < 2; l1662 = l1662 + 1) {
			fRec1194[l1662] = 0.0;
		}
		for (int l1663 = 0; l1663 < 2; l1663 = l1663 + 1) {
			fVec480[l1663] = 0.0;
		}
		for (int l1664 = 0; l1664 < 2; l1664 = l1664 + 1) {
			iRec1195[l1664] = 0;
		}
		for (int l1665 = 0; l1665 < 2; l1665 = l1665 + 1) {
			fRec1196[l1665] = 0.0;
		}
		for (int l1666 = 0; l1666 < 2; l1666 = l1666 + 1) {
			fVec481[l1666] = 0.0;
		}
		for (int l1667 = 0; l1667 < 2; l1667 = l1667 + 1) {
			iRec1197[l1667] = 0;
		}
		for (int l1668 = 0; l1668 < 2; l1668 = l1668 + 1) {
			fRec1198[l1668] = 0.0;
		}
		for (int l1669 = 0; l1669 < 2; l1669 = l1669 + 1) {
			fVec482[l1669] = 0.0;
		}
		for (int l1670 = 0; l1670 < 2; l1670 = l1670 + 1) {
			iRec1199[l1670] = 0;
		}
		for (int l1671 = 0; l1671 < 2; l1671 = l1671 + 1) {
			fRec1200[l1671] = 0.0;
		}
		for (int l1672 = 0; l1672 < 2; l1672 = l1672 + 1) {
			fVec483[l1672] = 0.0;
		}
		for (int l1673 = 0; l1673 < 2; l1673 = l1673 + 1) {
			iRec1201[l1673] = 0;
		}
		for (int l1674 = 0; l1674 < 2; l1674 = l1674 + 1) {
			fRec1202[l1674] = 0.0;
		}
		for (int l1675 = 0; l1675 < 2; l1675 = l1675 + 1) {
			fVec484[l1675] = 0.0;
		}
		for (int l1676 = 0; l1676 < 2; l1676 = l1676 + 1) {
			iRec1203[l1676] = 0;
		}
		for (int l1677 = 0; l1677 < 2; l1677 = l1677 + 1) {
			fRec1204[l1677] = 0.0;
		}
		for (int l1678 = 0; l1678 < 2; l1678 = l1678 + 1) {
			fVec485[l1678] = 0.0;
		}
		for (int l1679 = 0; l1679 < 2; l1679 = l1679 + 1) {
			iRec1205[l1679] = 0;
		}
		for (int l1680 = 0; l1680 < 2; l1680 = l1680 + 1) {
			fRec1206[l1680] = 0.0;
		}
		for (int l1681 = 0; l1681 < 2; l1681 = l1681 + 1) {
			fVec486[l1681] = 0.0;
		}
		for (int l1682 = 0; l1682 < 2; l1682 = l1682 + 1) {
			iRec1207[l1682] = 0;
		}
		for (int l1683 = 0; l1683 < 2; l1683 = l1683 + 1) {
			fRec1208[l1683] = 0.0;
		}
		for (int l1684 = 0; l1684 < 2; l1684 = l1684 + 1) {
			fVec487[l1684] = 0.0;
		}
		for (int l1685 = 0; l1685 < 2; l1685 = l1685 + 1) {
			iRec1209[l1685] = 0;
		}
		for (int l1686 = 0; l1686 < 2; l1686 = l1686 + 1) {
			fRec1210[l1686] = 0.0;
		}
		for (int l1687 = 0; l1687 < 2; l1687 = l1687 + 1) {
			fVec488[l1687] = 0.0;
		}
		for (int l1688 = 0; l1688 < 2; l1688 = l1688 + 1) {
			iRec1211[l1688] = 0;
		}
		for (int l1689 = 0; l1689 < 2; l1689 = l1689 + 1) {
			fRec1212[l1689] = 0.0;
		}
		for (int l1690 = 0; l1690 < 2; l1690 = l1690 + 1) {
			fVec489[l1690] = 0.0;
		}
		for (int l1691 = 0; l1691 < 2; l1691 = l1691 + 1) {
			iRec1213[l1691] = 0;
		}
		for (int l1692 = 0; l1692 < 2; l1692 = l1692 + 1) {
			fRec1214[l1692] = 0.0;
		}
		for (int l1693 = 0; l1693 < 2; l1693 = l1693 + 1) {
			fVec490[l1693] = 0.0;
		}
		for (int l1694 = 0; l1694 < 2; l1694 = l1694 + 1) {
			iRec1215[l1694] = 0;
		}
		for (int l1695 = 0; l1695 < 2; l1695 = l1695 + 1) {
			fRec1216[l1695] = 0.0;
		}
		for (int l1696 = 0; l1696 < 2; l1696 = l1696 + 1) {
			fVec491[l1696] = 0.0;
		}
		for (int l1697 = 0; l1697 < 2; l1697 = l1697 + 1) {
			iRec1217[l1697] = 0;
		}
		for (int l1698 = 0; l1698 < 2; l1698 = l1698 + 1) {
			fRec1218[l1698] = 0.0;
		}
		for (int l1699 = 0; l1699 < 2; l1699 = l1699 + 1) {
			fVec492[l1699] = 0.0;
		}
		for (int l1700 = 0; l1700 < 2; l1700 = l1700 + 1) {
			iRec1219[l1700] = 0;
		}
		for (int l1701 = 0; l1701 < 2; l1701 = l1701 + 1) {
			fRec1220[l1701] = 0.0;
		}
		for (int l1702 = 0; l1702 < 2; l1702 = l1702 + 1) {
			fVec493[l1702] = 0.0;
		}
		for (int l1703 = 0; l1703 < 2; l1703 = l1703 + 1) {
			iRec1221[l1703] = 0;
		}
		for (int l1704 = 0; l1704 < 2; l1704 = l1704 + 1) {
			fRec1222[l1704] = 0.0;
		}
		for (int l1705 = 0; l1705 < 2; l1705 = l1705 + 1) {
			fVec494[l1705] = 0.0;
		}
		for (int l1706 = 0; l1706 < 2; l1706 = l1706 + 1) {
			iRec1223[l1706] = 0;
		}
		for (int l1707 = 0; l1707 < 2; l1707 = l1707 + 1) {
			fRec1224[l1707] = 0.0;
		}
		for (int l1708 = 0; l1708 < 2; l1708 = l1708 + 1) {
			fRec1225[l1708] = 0.0;
		}
		for (int l1709 = 0; l1709 < 2; l1709 = l1709 + 1) {
			fVec495[l1709] = 0.0;
		}
		for (int l1710 = 0; l1710 < 2; l1710 = l1710 + 1) {
			iRec1226[l1710] = 0;
		}
		for (int l1711 = 0; l1711 < 2; l1711 = l1711 + 1) {
			fRec1227[l1711] = 0.0;
		}
		for (int l1712 = 0; l1712 < 2; l1712 = l1712 + 1) {
			fVec496[l1712] = 0.0;
		}
		for (int l1713 = 0; l1713 < 2; l1713 = l1713 + 1) {
			iRec1228[l1713] = 0;
		}
		for (int l1714 = 0; l1714 < 2; l1714 = l1714 + 1) {
			fRec1229[l1714] = 0.0;
		}
		for (int l1715 = 0; l1715 < 2; l1715 = l1715 + 1) {
			fVec497[l1715] = 0.0;
		}
		for (int l1716 = 0; l1716 < 2; l1716 = l1716 + 1) {
			iRec1230[l1716] = 0;
		}
		for (int l1717 = 0; l1717 < 2; l1717 = l1717 + 1) {
			fRec1231[l1717] = 0.0;
		}
		for (int l1718 = 0; l1718 < 2; l1718 = l1718 + 1) {
			fVec498[l1718] = 0.0;
		}
		for (int l1719 = 0; l1719 < 2; l1719 = l1719 + 1) {
			iRec1232[l1719] = 0;
		}
		for (int l1720 = 0; l1720 < 2; l1720 = l1720 + 1) {
			fRec1233[l1720] = 0.0;
		}
		for (int l1721 = 0; l1721 < 2; l1721 = l1721 + 1) {
			fVec499[l1721] = 0.0;
		}
		for (int l1722 = 0; l1722 < 2; l1722 = l1722 + 1) {
			iRec1234[l1722] = 0;
		}
		for (int l1723 = 0; l1723 < 2; l1723 = l1723 + 1) {
			fRec1235[l1723] = 0.0;
		}
		for (int l1724 = 0; l1724 < 2; l1724 = l1724 + 1) {
			fVec500[l1724] = 0.0;
		}
		for (int l1725 = 0; l1725 < 2; l1725 = l1725 + 1) {
			iRec1236[l1725] = 0;
		}
		for (int l1726 = 0; l1726 < 2; l1726 = l1726 + 1) {
			fRec1237[l1726] = 0.0;
		}
		for (int l1727 = 0; l1727 < 2; l1727 = l1727 + 1) {
			fVec501[l1727] = 0.0;
		}
		for (int l1728 = 0; l1728 < 2; l1728 = l1728 + 1) {
			iRec1238[l1728] = 0;
		}
		for (int l1729 = 0; l1729 < 2; l1729 = l1729 + 1) {
			fRec1239[l1729] = 0.0;
		}
		for (int l1730 = 0; l1730 < 2; l1730 = l1730 + 1) {
			fVec502[l1730] = 0.0;
		}
		for (int l1731 = 0; l1731 < 2; l1731 = l1731 + 1) {
			iRec1240[l1731] = 0;
		}
		for (int l1732 = 0; l1732 < 2; l1732 = l1732 + 1) {
			fRec1241[l1732] = 0.0;
		}
		for (int l1733 = 0; l1733 < 2; l1733 = l1733 + 1) {
			fVec503[l1733] = 0.0;
		}
		for (int l1734 = 0; l1734 < 2; l1734 = l1734 + 1) {
			iRec1242[l1734] = 0;
		}
		for (int l1735 = 0; l1735 < 2; l1735 = l1735 + 1) {
			fRec1243[l1735] = 0.0;
		}
		for (int l1736 = 0; l1736 < 2; l1736 = l1736 + 1) {
			fVec504[l1736] = 0.0;
		}
		for (int l1737 = 0; l1737 < 2; l1737 = l1737 + 1) {
			iRec1244[l1737] = 0;
		}
		for (int l1738 = 0; l1738 < 2; l1738 = l1738 + 1) {
			fRec1245[l1738] = 0.0;
		}
		for (int l1739 = 0; l1739 < 2; l1739 = l1739 + 1) {
			fVec505[l1739] = 0.0;
		}
		for (int l1740 = 0; l1740 < 2; l1740 = l1740 + 1) {
			iRec1246[l1740] = 0;
		}
		for (int l1741 = 0; l1741 < 2; l1741 = l1741 + 1) {
			fRec1247[l1741] = 0.0;
		}
		for (int l1742 = 0; l1742 < 2; l1742 = l1742 + 1) {
			fVec506[l1742] = 0.0;
		}
		for (int l1743 = 0; l1743 < 2; l1743 = l1743 + 1) {
			iRec1248[l1743] = 0;
		}
		for (int l1744 = 0; l1744 < 2; l1744 = l1744 + 1) {
			fRec1249[l1744] = 0.0;
		}
		for (int l1745 = 0; l1745 < 2; l1745 = l1745 + 1) {
			fVec507[l1745] = 0.0;
		}
		for (int l1746 = 0; l1746 < 2; l1746 = l1746 + 1) {
			iRec1250[l1746] = 0;
		}
		for (int l1747 = 0; l1747 < 2; l1747 = l1747 + 1) {
			fRec1251[l1747] = 0.0;
		}
		for (int l1748 = 0; l1748 < 2; l1748 = l1748 + 1) {
			fVec508[l1748] = 0.0;
		}
		for (int l1749 = 0; l1749 < 2; l1749 = l1749 + 1) {
			iRec1252[l1749] = 0;
		}
		for (int l1750 = 0; l1750 < 2; l1750 = l1750 + 1) {
			fRec1253[l1750] = 0.0;
		}
		for (int l1751 = 0; l1751 < 2; l1751 = l1751 + 1) {
			fVec509[l1751] = 0.0;
		}
		for (int l1752 = 0; l1752 < 2; l1752 = l1752 + 1) {
			iRec1254[l1752] = 0;
		}
		for (int l1753 = 0; l1753 < 2; l1753 = l1753 + 1) {
			fRec1255[l1753] = 0.0;
		}
		for (int l1754 = 0; l1754 < 2; l1754 = l1754 + 1) {
			fVec510[l1754] = 0.0;
		}
		for (int l1755 = 0; l1755 < 2; l1755 = l1755 + 1) {
			iRec1256[l1755] = 0;
		}
		for (int l1756 = 0; l1756 < 2; l1756 = l1756 + 1) {
			fRec1257[l1756] = 0.0;
		}
		for (int l1757 = 0; l1757 < 2; l1757 = l1757 + 1) {
			fVec511[l1757] = 0.0;
		}
		for (int l1758 = 0; l1758 < 2; l1758 = l1758 + 1) {
			iRec1258[l1758] = 0;
		}
		for (int l1759 = 0; l1759 < 2; l1759 = l1759 + 1) {
			fRec1259[l1759] = 0.0;
		}
		for (int l1760 = 0; l1760 < 2; l1760 = l1760 + 1) {
			fVec512[l1760] = 0.0;
		}
		for (int l1761 = 0; l1761 < 2; l1761 = l1761 + 1) {
			iRec1260[l1761] = 0;
		}
		for (int l1762 = 0; l1762 < 2; l1762 = l1762 + 1) {
			fRec1261[l1762] = 0.0;
		}
		for (int l1763 = 0; l1763 < 2; l1763 = l1763 + 1) {
			fVec513[l1763] = 0.0;
		}
		for (int l1764 = 0; l1764 < 2; l1764 = l1764 + 1) {
			iRec1262[l1764] = 0;
		}
		for (int l1765 = 0; l1765 < 2; l1765 = l1765 + 1) {
			fRec1263[l1765] = 0.0;
		}
		for (int l1766 = 0; l1766 < 2; l1766 = l1766 + 1) {
			fVec514[l1766] = 0.0;
		}
		for (int l1767 = 0; l1767 < 2; l1767 = l1767 + 1) {
			iRec1264[l1767] = 0;
		}
		for (int l1768 = 0; l1768 < 2; l1768 = l1768 + 1) {
			fRec1265[l1768] = 0.0;
		}
		for (int l1769 = 0; l1769 < 2; l1769 = l1769 + 1) {
			fVec515[l1769] = 0.0;
		}
		for (int l1770 = 0; l1770 < 2; l1770 = l1770 + 1) {
			iRec1266[l1770] = 0;
		}
		for (int l1771 = 0; l1771 < 2; l1771 = l1771 + 1) {
			fRec1267[l1771] = 0.0;
		}
		for (int l1772 = 0; l1772 < 2; l1772 = l1772 + 1) {
			fVec516[l1772] = 0.0;
		}
		for (int l1773 = 0; l1773 < 2; l1773 = l1773 + 1) {
			iRec1268[l1773] = 0;
		}
		for (int l1774 = 0; l1774 < 2; l1774 = l1774 + 1) {
			fRec1269[l1774] = 0.0;
		}
		for (int l1775 = 0; l1775 < 2; l1775 = l1775 + 1) {
			fRec1270[l1775] = 0.0;
		}
		for (int l1776 = 0; l1776 < 2; l1776 = l1776 + 1) {
			fVec517[l1776] = 0.0;
		}
		for (int l1777 = 0; l1777 < 2; l1777 = l1777 + 1) {
			iRec1271[l1777] = 0;
		}
		for (int l1778 = 0; l1778 < 2; l1778 = l1778 + 1) {
			fRec1272[l1778] = 0.0;
		}
		for (int l1779 = 0; l1779 < 2; l1779 = l1779 + 1) {
			fVec518[l1779] = 0.0;
		}
		for (int l1780 = 0; l1780 < 2; l1780 = l1780 + 1) {
			iRec1273[l1780] = 0;
		}
		for (int l1781 = 0; l1781 < 2; l1781 = l1781 + 1) {
			fRec1274[l1781] = 0.0;
		}
		for (int l1782 = 0; l1782 < 2; l1782 = l1782 + 1) {
			fVec519[l1782] = 0.0;
		}
		for (int l1783 = 0; l1783 < 2; l1783 = l1783 + 1) {
			iRec1275[l1783] = 0;
		}
		for (int l1784 = 0; l1784 < 2; l1784 = l1784 + 1) {
			fRec1276[l1784] = 0.0;
		}
		for (int l1785 = 0; l1785 < 2; l1785 = l1785 + 1) {
			fVec520[l1785] = 0.0;
		}
		for (int l1786 = 0; l1786 < 2; l1786 = l1786 + 1) {
			iRec1277[l1786] = 0;
		}
		for (int l1787 = 0; l1787 < 2; l1787 = l1787 + 1) {
			fRec1278[l1787] = 0.0;
		}
		for (int l1788 = 0; l1788 < 2; l1788 = l1788 + 1) {
			fVec521[l1788] = 0.0;
		}
		for (int l1789 = 0; l1789 < 2; l1789 = l1789 + 1) {
			iRec1279[l1789] = 0;
		}
		for (int l1790 = 0; l1790 < 2; l1790 = l1790 + 1) {
			fRec1280[l1790] = 0.0;
		}
		for (int l1791 = 0; l1791 < 2; l1791 = l1791 + 1) {
			fVec522[l1791] = 0.0;
		}
		for (int l1792 = 0; l1792 < 2; l1792 = l1792 + 1) {
			iRec1281[l1792] = 0;
		}
		for (int l1793 = 0; l1793 < 2; l1793 = l1793 + 1) {
			fRec1282[l1793] = 0.0;
		}
		for (int l1794 = 0; l1794 < 2; l1794 = l1794 + 1) {
			fVec523[l1794] = 0.0;
		}
		for (int l1795 = 0; l1795 < 2; l1795 = l1795 + 1) {
			iRec1283[l1795] = 0;
		}
		for (int l1796 = 0; l1796 < 2; l1796 = l1796 + 1) {
			fRec1284[l1796] = 0.0;
		}
		for (int l1797 = 0; l1797 < 2; l1797 = l1797 + 1) {
			fVec524[l1797] = 0.0;
		}
		for (int l1798 = 0; l1798 < 2; l1798 = l1798 + 1) {
			iRec1285[l1798] = 0;
		}
		for (int l1799 = 0; l1799 < 2; l1799 = l1799 + 1) {
			fRec1286[l1799] = 0.0;
		}
		for (int l1800 = 0; l1800 < 2; l1800 = l1800 + 1) {
			fVec525[l1800] = 0.0;
		}
		for (int l1801 = 0; l1801 < 2; l1801 = l1801 + 1) {
			iRec1287[l1801] = 0;
		}
		for (int l1802 = 0; l1802 < 2; l1802 = l1802 + 1) {
			fRec1288[l1802] = 0.0;
		}
		for (int l1803 = 0; l1803 < 2; l1803 = l1803 + 1) {
			fVec526[l1803] = 0.0;
		}
		for (int l1804 = 0; l1804 < 2; l1804 = l1804 + 1) {
			iRec1289[l1804] = 0;
		}
		for (int l1805 = 0; l1805 < 2; l1805 = l1805 + 1) {
			fRec1290[l1805] = 0.0;
		}
		for (int l1806 = 0; l1806 < 2; l1806 = l1806 + 1) {
			fVec527[l1806] = 0.0;
		}
		for (int l1807 = 0; l1807 < 2; l1807 = l1807 + 1) {
			iRec1291[l1807] = 0;
		}
		for (int l1808 = 0; l1808 < 2; l1808 = l1808 + 1) {
			fRec1292[l1808] = 0.0;
		}
		for (int l1809 = 0; l1809 < 2; l1809 = l1809 + 1) {
			fVec528[l1809] = 0.0;
		}
		for (int l1810 = 0; l1810 < 2; l1810 = l1810 + 1) {
			iRec1293[l1810] = 0;
		}
		for (int l1811 = 0; l1811 < 2; l1811 = l1811 + 1) {
			fRec1294[l1811] = 0.0;
		}
		for (int l1812 = 0; l1812 < 2; l1812 = l1812 + 1) {
			fVec529[l1812] = 0.0;
		}
		for (int l1813 = 0; l1813 < 2; l1813 = l1813 + 1) {
			iRec1295[l1813] = 0;
		}
		for (int l1814 = 0; l1814 < 2; l1814 = l1814 + 1) {
			fRec1296[l1814] = 0.0;
		}
		for (int l1815 = 0; l1815 < 2; l1815 = l1815 + 1) {
			fVec530[l1815] = 0.0;
		}
		for (int l1816 = 0; l1816 < 2; l1816 = l1816 + 1) {
			iRec1297[l1816] = 0;
		}
		for (int l1817 = 0; l1817 < 2; l1817 = l1817 + 1) {
			fRec1298[l1817] = 0.0;
		}
		for (int l1818 = 0; l1818 < 2; l1818 = l1818 + 1) {
			fVec531[l1818] = 0.0;
		}
		for (int l1819 = 0; l1819 < 2; l1819 = l1819 + 1) {
			iRec1299[l1819] = 0;
		}
		for (int l1820 = 0; l1820 < 2; l1820 = l1820 + 1) {
			fRec1300[l1820] = 0.0;
		}
		for (int l1821 = 0; l1821 < 2; l1821 = l1821 + 1) {
			fVec532[l1821] = 0.0;
		}
		for (int l1822 = 0; l1822 < 2; l1822 = l1822 + 1) {
			iRec1301[l1822] = 0;
		}
		for (int l1823 = 0; l1823 < 2; l1823 = l1823 + 1) {
			fRec1302[l1823] = 0.0;
		}
		for (int l1824 = 0; l1824 < 2; l1824 = l1824 + 1) {
			fVec533[l1824] = 0.0;
		}
		for (int l1825 = 0; l1825 < 2; l1825 = l1825 + 1) {
			iRec1303[l1825] = 0;
		}
		for (int l1826 = 0; l1826 < 2; l1826 = l1826 + 1) {
			fRec1304[l1826] = 0.0;
		}
		for (int l1827 = 0; l1827 < 2; l1827 = l1827 + 1) {
			fVec534[l1827] = 0.0;
		}
		for (int l1828 = 0; l1828 < 2; l1828 = l1828 + 1) {
			iRec1305[l1828] = 0;
		}
		for (int l1829 = 0; l1829 < 2; l1829 = l1829 + 1) {
			fRec1306[l1829] = 0.0;
		}
		for (int l1830 = 0; l1830 < 2; l1830 = l1830 + 1) {
			fVec535[l1830] = 0.0;
		}
		for (int l1831 = 0; l1831 < 2; l1831 = l1831 + 1) {
			iRec1307[l1831] = 0;
		}
		for (int l1832 = 0; l1832 < 2; l1832 = l1832 + 1) {
			fRec1308[l1832] = 0.0;
		}
		for (int l1833 = 0; l1833 < 2; l1833 = l1833 + 1) {
			fVec536[l1833] = 0.0;
		}
		for (int l1834 = 0; l1834 < 2; l1834 = l1834 + 1) {
			iRec1309[l1834] = 0;
		}
		for (int l1835 = 0; l1835 < 2; l1835 = l1835 + 1) {
			fRec1310[l1835] = 0.0;
		}
		for (int l1836 = 0; l1836 < 2; l1836 = l1836 + 1) {
			fVec537[l1836] = 0.0;
		}
		for (int l1837 = 0; l1837 < 2; l1837 = l1837 + 1) {
			iRec1311[l1837] = 0;
		}
		for (int l1838 = 0; l1838 < 2; l1838 = l1838 + 1) {
			fRec1312[l1838] = 0.0;
		}
		for (int l1839 = 0; l1839 < 2; l1839 = l1839 + 1) {
			fVec538[l1839] = 0.0;
		}
		for (int l1840 = 0; l1840 < 2; l1840 = l1840 + 1) {
			iRec1313[l1840] = 0;
		}
		for (int l1841 = 0; l1841 < 2; l1841 = l1841 + 1) {
			fRec1314[l1841] = 0.0;
		}
		for (int l1842 = 0; l1842 < 2; l1842 = l1842 + 1) {
			fVec539[l1842] = 0.0;
		}
		for (int l1843 = 0; l1843 < 2; l1843 = l1843 + 1) {
			iRec1315[l1843] = 0;
		}
		for (int l1844 = 0; l1844 < 2; l1844 = l1844 + 1) {
			fRec1316[l1844] = 0.0;
		}
		for (int l1845 = 0; l1845 < 2; l1845 = l1845 + 1) {
			fVec540[l1845] = 0.0;
		}
		for (int l1846 = 0; l1846 < 2; l1846 = l1846 + 1) {
			iRec1317[l1846] = 0;
		}
		for (int l1847 = 0; l1847 < 2; l1847 = l1847 + 1) {
			fRec1318[l1847] = 0.0;
		}
		for (int l1848 = 0; l1848 < 2; l1848 = l1848 + 1) {
			fVec541[l1848] = 0.0;
		}
		for (int l1849 = 0; l1849 < 2; l1849 = l1849 + 1) {
			iRec1319[l1849] = 0;
		}
		for (int l1850 = 0; l1850 < 2; l1850 = l1850 + 1) {
			fRec1320[l1850] = 0.0;
		}
		for (int l1851 = 0; l1851 < 2; l1851 = l1851 + 1) {
			fVec542[l1851] = 0.0;
		}
		for (int l1852 = 0; l1852 < 2; l1852 = l1852 + 1) {
			iRec1321[l1852] = 0;
		}
		for (int l1853 = 0; l1853 < 2; l1853 = l1853 + 1) {
			fRec1322[l1853] = 0.0;
		}
		for (int l1854 = 0; l1854 < 2; l1854 = l1854 + 1) {
			fVec543[l1854] = 0.0;
		}
		for (int l1855 = 0; l1855 < 2; l1855 = l1855 + 1) {
			iRec1323[l1855] = 0;
		}
		for (int l1856 = 0; l1856 < 2; l1856 = l1856 + 1) {
			fRec1324[l1856] = 0.0;
		}
		for (int l1857 = 0; l1857 < 2; l1857 = l1857 + 1) {
			fVec544[l1857] = 0.0;
		}
		for (int l1858 = 0; l1858 < 2; l1858 = l1858 + 1) {
			iRec1325[l1858] = 0;
		}
		for (int l1859 = 0; l1859 < 2; l1859 = l1859 + 1) {
			fRec1326[l1859] = 0.0;
		}
		for (int l1860 = 0; l1860 < 2; l1860 = l1860 + 1) {
			fVec545[l1860] = 0.0;
		}
		for (int l1861 = 0; l1861 < 2; l1861 = l1861 + 1) {
			iRec1327[l1861] = 0;
		}
		for (int l1862 = 0; l1862 < 2; l1862 = l1862 + 1) {
			fRec1328[l1862] = 0.0;
		}
		for (int l1863 = 0; l1863 < 2; l1863 = l1863 + 1) {
			fVec546[l1863] = 0.0;
		}
		for (int l1864 = 0; l1864 < 2; l1864 = l1864 + 1) {
			iRec1329[l1864] = 0;
		}
		for (int l1865 = 0; l1865 < 2; l1865 = l1865 + 1) {
			fRec1330[l1865] = 0.0;
		}
		for (int l1866 = 0; l1866 < 2; l1866 = l1866 + 1) {
			fVec547[l1866] = 0.0;
		}
		for (int l1867 = 0; l1867 < 2; l1867 = l1867 + 1) {
			iRec1331[l1867] = 0;
		}
		for (int l1868 = 0; l1868 < 2; l1868 = l1868 + 1) {
			fRec1332[l1868] = 0.0;
		}
		for (int l1869 = 0; l1869 < 2; l1869 = l1869 + 1) {
			fVec548[l1869] = 0.0;
		}
		for (int l1870 = 0; l1870 < 2; l1870 = l1870 + 1) {
			iRec1333[l1870] = 0;
		}
		for (int l1871 = 0; l1871 < 2; l1871 = l1871 + 1) {
			fRec1334[l1871] = 0.0;
		}
		for (int l1872 = 0; l1872 < 2; l1872 = l1872 + 1) {
			fVec549[l1872] = 0.0;
		}
		for (int l1873 = 0; l1873 < 2; l1873 = l1873 + 1) {
			iRec1335[l1873] = 0;
		}
		for (int l1874 = 0; l1874 < 2; l1874 = l1874 + 1) {
			fRec1336[l1874] = 0.0;
		}
		for (int l1875 = 0; l1875 < 2; l1875 = l1875 + 1) {
			fVec550[l1875] = 0.0;
		}
		for (int l1876 = 0; l1876 < 2; l1876 = l1876 + 1) {
			iRec1337[l1876] = 0;
		}
		for (int l1877 = 0; l1877 < 2; l1877 = l1877 + 1) {
			fRec1338[l1877] = 0.0;
		}
		for (int l1878 = 0; l1878 < 2; l1878 = l1878 + 1) {
			fVec551[l1878] = 0.0;
		}
		for (int l1879 = 0; l1879 < 2; l1879 = l1879 + 1) {
			iRec1339[l1879] = 0;
		}
		for (int l1880 = 0; l1880 < 2; l1880 = l1880 + 1) {
			fRec1340[l1880] = 0.0;
		}
		for (int l1881 = 0; l1881 < 2; l1881 = l1881 + 1) {
			fVec552[l1881] = 0.0;
		}
		for (int l1882 = 0; l1882 < 2; l1882 = l1882 + 1) {
			iRec1341[l1882] = 0;
		}
		for (int l1883 = 0; l1883 < 2; l1883 = l1883 + 1) {
			fRec1342[l1883] = 0.0;
		}
		for (int l1884 = 0; l1884 < 2; l1884 = l1884 + 1) {
			fVec553[l1884] = 0.0;
		}
		for (int l1885 = 0; l1885 < 2; l1885 = l1885 + 1) {
			iRec1343[l1885] = 0;
		}
		for (int l1886 = 0; l1886 < 2; l1886 = l1886 + 1) {
			fRec1344[l1886] = 0.0;
		}
		for (int l1887 = 0; l1887 < 2; l1887 = l1887 + 1) {
			fVec554[l1887] = 0.0;
		}
		for (int l1888 = 0; l1888 < 2; l1888 = l1888 + 1) {
			iRec1345[l1888] = 0;
		}
		for (int l1889 = 0; l1889 < 2; l1889 = l1889 + 1) {
			fRec1346[l1889] = 0.0;
		}
		for (int l1890 = 0; l1890 < 2; l1890 = l1890 + 1) {
			fVec555[l1890] = 0.0;
		}
		for (int l1891 = 0; l1891 < 2; l1891 = l1891 + 1) {
			iRec1347[l1891] = 0;
		}
		for (int l1892 = 0; l1892 < 2; l1892 = l1892 + 1) {
			fRec1348[l1892] = 0.0;
		}
		for (int l1893 = 0; l1893 < 2; l1893 = l1893 + 1) {
			fRec1349[l1893] = 0.0;
		}
		for (int l1894 = 0; l1894 < 2; l1894 = l1894 + 1) {
			fRec1350[l1894] = 0.0;
		}
		for (int l1895 = 0; l1895 < 2; l1895 = l1895 + 1) {
			fRec1351[l1895] = 0.0;
		}
		for (int l1896 = 0; l1896 < 2; l1896 = l1896 + 1) {
			fRec1352[l1896] = 0.0;
		}
		for (int l1897 = 0; l1897 < 2; l1897 = l1897 + 1) {
			iVec556[l1897] = 0;
		}
		for (int l1898 = 0; l1898 < 2; l1898 = l1898 + 1) {
			fRec1353[l1898] = 0.0;
		}
		for (int l1899 = 0; l1899 < 2; l1899 = l1899 + 1) {
			fRec1354[l1899] = 0.0;
		}
		for (int l1900 = 0; l1900 < 2; l1900 = l1900 + 1) {
			fRec1355[l1900] = 0.0;
		}
		for (int l1901 = 0; l1901 < 2; l1901 = l1901 + 1) {
			fRec1356[l1901] = 0.0;
		}
		for (int l1902 = 0; l1902 < 2; l1902 = l1902 + 1) {
			fRec1357[l1902] = 0.0;
		}
		for (int l1903 = 0; l1903 < 2; l1903 = l1903 + 1) {
			fRec1358[l1903] = 0.0;
		}
		for (int l1904 = 0; l1904 < 2; l1904 = l1904 + 1) {
			fRec1359[l1904] = 0.0;
		}
		for (int l1905 = 0; l1905 < 2; l1905 = l1905 + 1) {
			fRec1360[l1905] = 0.0;
		}
		for (int l1906 = 0; l1906 < 2; l1906 = l1906 + 1) {
			fRec1361[l1906] = 0.0;
		}
		for (int l1907 = 0; l1907 < 2; l1907 = l1907 + 1) {
			fRec1362[l1907] = 0.0;
		}
		for (int l1908 = 0; l1908 < 2; l1908 = l1908 + 1) {
			fRec1363[l1908] = 0.0;
		}
		for (int l1909 = 0; l1909 < 1024; l1909 = l1909 + 1) {
			fVec557[l1909] = 0.0;
		}
		for (int l1910 = 0; l1910 < 2; l1910 = l1910 + 1) {
			fRec1364[l1910] = 0.0;
		}
		for (int l1911 = 0; l1911 < 2; l1911 = l1911 + 1) {
			fRec1365[l1911] = 0.0;
		}
		for (int l1912 = 0; l1912 < 2; l1912 = l1912 + 1) {
			fRec1368[l1912] = 0.0;
		}
		for (int l1913 = 0; l1913 < 2; l1913 = l1913 + 1) {
			fVec558[l1913] = 0.0;
		}
		for (int l1914 = 0; l1914 < 2; l1914 = l1914 + 1) {
			fRec1367[l1914] = 0.0;
		}
		for (int l1915 = 0; l1915 < 2; l1915 = l1915 + 1) {
			fRec1369[l1915] = 0.0;
		}
		for (int l1916 = 0; l1916 < 2; l1916 = l1916 + 1) {
			fVec559[l1916] = 0.0;
		}
		for (int l1917 = 0; l1917 < 2; l1917 = l1917 + 1) {
			fRec1366[l1917] = 0.0;
		}
		for (int l1918 = 0; l1918 < 2; l1918 = l1918 + 1) {
			fVec560[l1918] = 0.0;
		}
		for (int l1919 = 0; l1919 < 2; l1919 = l1919 + 1) {
			iRec1370[l1919] = 0;
		}
		for (int l1920 = 0; l1920 < 2; l1920 = l1920 + 1) {
			fRec1371[l1920] = 0.0;
		}
		for (int l1921 = 0; l1921 < 2; l1921 = l1921 + 1) {
			fVec561[l1921] = 0.0;
		}
		for (int l1922 = 0; l1922 < 2; l1922 = l1922 + 1) {
			iRec1372[l1922] = 0;
		}
		for (int l1923 = 0; l1923 < 2; l1923 = l1923 + 1) {
			fRec1373[l1923] = 0.0;
		}
		for (int l1924 = 0; l1924 < 2; l1924 = l1924 + 1) {
			fVec562[l1924] = 0.0;
		}
		for (int l1925 = 0; l1925 < 2; l1925 = l1925 + 1) {
			iRec1374[l1925] = 0;
		}
		for (int l1926 = 0; l1926 < 2; l1926 = l1926 + 1) {
			fRec1375[l1926] = 0.0;
		}
		for (int l1927 = 0; l1927 < 2; l1927 = l1927 + 1) {
			fVec563[l1927] = 0.0;
		}
		for (int l1928 = 0; l1928 < 2; l1928 = l1928 + 1) {
			iRec1376[l1928] = 0;
		}
		for (int l1929 = 0; l1929 < 2; l1929 = l1929 + 1) {
			fRec1377[l1929] = 0.0;
		}
		for (int l1930 = 0; l1930 < 2; l1930 = l1930 + 1) {
			fVec564[l1930] = 0.0;
		}
		for (int l1931 = 0; l1931 < 2; l1931 = l1931 + 1) {
			iRec1378[l1931] = 0;
		}
		for (int l1932 = 0; l1932 < 2; l1932 = l1932 + 1) {
			fRec1379[l1932] = 0.0;
		}
		for (int l1933 = 0; l1933 < 2; l1933 = l1933 + 1) {
			fVec565[l1933] = 0.0;
		}
		for (int l1934 = 0; l1934 < 2; l1934 = l1934 + 1) {
			iRec1380[l1934] = 0;
		}
		for (int l1935 = 0; l1935 < 2; l1935 = l1935 + 1) {
			fRec1381[l1935] = 0.0;
		}
		for (int l1936 = 0; l1936 < 2; l1936 = l1936 + 1) {
			fVec566[l1936] = 0.0;
		}
		for (int l1937 = 0; l1937 < 2; l1937 = l1937 + 1) {
			iRec1382[l1937] = 0;
		}
		for (int l1938 = 0; l1938 < 2; l1938 = l1938 + 1) {
			fRec1383[l1938] = 0.0;
		}
		for (int l1939 = 0; l1939 < 2; l1939 = l1939 + 1) {
			fVec567[l1939] = 0.0;
		}
		for (int l1940 = 0; l1940 < 2; l1940 = l1940 + 1) {
			iRec1384[l1940] = 0;
		}
		for (int l1941 = 0; l1941 < 2; l1941 = l1941 + 1) {
			fRec1385[l1941] = 0.0;
		}
		for (int l1942 = 0; l1942 < 2; l1942 = l1942 + 1) {
			fVec568[l1942] = 0.0;
		}
		for (int l1943 = 0; l1943 < 2; l1943 = l1943 + 1) {
			iRec1386[l1943] = 0;
		}
		for (int l1944 = 0; l1944 < 2; l1944 = l1944 + 1) {
			fRec1387[l1944] = 0.0;
		}
		for (int l1945 = 0; l1945 < 2; l1945 = l1945 + 1) {
			fVec569[l1945] = 0.0;
		}
		for (int l1946 = 0; l1946 < 2; l1946 = l1946 + 1) {
			iRec1388[l1946] = 0;
		}
		for (int l1947 = 0; l1947 < 2; l1947 = l1947 + 1) {
			fRec1389[l1947] = 0.0;
		}
		for (int l1948 = 0; l1948 < 2; l1948 = l1948 + 1) {
			fVec570[l1948] = 0.0;
		}
		for (int l1949 = 0; l1949 < 2; l1949 = l1949 + 1) {
			iRec1390[l1949] = 0;
		}
		for (int l1950 = 0; l1950 < 2; l1950 = l1950 + 1) {
			fRec1391[l1950] = 0.0;
		}
		for (int l1951 = 0; l1951 < 2; l1951 = l1951 + 1) {
			fVec571[l1951] = 0.0;
		}
		for (int l1952 = 0; l1952 < 2; l1952 = l1952 + 1) {
			iRec1392[l1952] = 0;
		}
		for (int l1953 = 0; l1953 < 2; l1953 = l1953 + 1) {
			fRec1393[l1953] = 0.0;
		}
		for (int l1954 = 0; l1954 < 2; l1954 = l1954 + 1) {
			fVec572[l1954] = 0.0;
		}
		for (int l1955 = 0; l1955 < 2; l1955 = l1955 + 1) {
			iRec1394[l1955] = 0;
		}
		for (int l1956 = 0; l1956 < 2; l1956 = l1956 + 1) {
			fRec1395[l1956] = 0.0;
		}
		for (int l1957 = 0; l1957 < 2; l1957 = l1957 + 1) {
			fVec573[l1957] = 0.0;
		}
		for (int l1958 = 0; l1958 < 2; l1958 = l1958 + 1) {
			iRec1396[l1958] = 0;
		}
		for (int l1959 = 0; l1959 < 2; l1959 = l1959 + 1) {
			fRec1397[l1959] = 0.0;
		}
		for (int l1960 = 0; l1960 < 2; l1960 = l1960 + 1) {
			fVec574[l1960] = 0.0;
		}
		for (int l1961 = 0; l1961 < 2; l1961 = l1961 + 1) {
			iRec1398[l1961] = 0;
		}
		for (int l1962 = 0; l1962 < 2; l1962 = l1962 + 1) {
			fRec1399[l1962] = 0.0;
		}
		for (int l1963 = 0; l1963 < 2; l1963 = l1963 + 1) {
			fVec575[l1963] = 0.0;
		}
		for (int l1964 = 0; l1964 < 2; l1964 = l1964 + 1) {
			iRec1400[l1964] = 0;
		}
		for (int l1965 = 0; l1965 < 2; l1965 = l1965 + 1) {
			fRec1401[l1965] = 0.0;
		}
		for (int l1966 = 0; l1966 < 2; l1966 = l1966 + 1) {
			fVec576[l1966] = 0.0;
		}
		for (int l1967 = 0; l1967 < 2; l1967 = l1967 + 1) {
			iRec1402[l1967] = 0;
		}
		for (int l1968 = 0; l1968 < 2; l1968 = l1968 + 1) {
			fRec1403[l1968] = 0.0;
		}
		for (int l1969 = 0; l1969 < 2; l1969 = l1969 + 1) {
			fVec577[l1969] = 0.0;
		}
		for (int l1970 = 0; l1970 < 2; l1970 = l1970 + 1) {
			iRec1404[l1970] = 0;
		}
		for (int l1971 = 0; l1971 < 2; l1971 = l1971 + 1) {
			fRec1405[l1971] = 0.0;
		}
		for (int l1972 = 0; l1972 < 2; l1972 = l1972 + 1) {
			fVec578[l1972] = 0.0;
		}
		for (int l1973 = 0; l1973 < 2; l1973 = l1973 + 1) {
			iRec1406[l1973] = 0;
		}
		for (int l1974 = 0; l1974 < 2; l1974 = l1974 + 1) {
			fRec1407[l1974] = 0.0;
		}
		for (int l1975 = 0; l1975 < 2; l1975 = l1975 + 1) {
			fVec579[l1975] = 0.0;
		}
		for (int l1976 = 0; l1976 < 2; l1976 = l1976 + 1) {
			iRec1408[l1976] = 0;
		}
		for (int l1977 = 0; l1977 < 2; l1977 = l1977 + 1) {
			fRec1409[l1977] = 0.0;
		}
		for (int l1978 = 0; l1978 < 2; l1978 = l1978 + 1) {
			fVec580[l1978] = 0.0;
		}
		for (int l1979 = 0; l1979 < 2; l1979 = l1979 + 1) {
			iRec1410[l1979] = 0;
		}
		for (int l1980 = 0; l1980 < 2; l1980 = l1980 + 1) {
			fRec1411[l1980] = 0.0;
		}
		for (int l1981 = 0; l1981 < 2; l1981 = l1981 + 1) {
			fVec581[l1981] = 0.0;
		}
		for (int l1982 = 0; l1982 < 2; l1982 = l1982 + 1) {
			fVec582[l1982] = 0.0;
		}
		for (int l1983 = 0; l1983 < 2; l1983 = l1983 + 1) {
			fRec16[l1983] = 0.0;
		}
		for (int l1984 = 0; l1984 < 2; l1984 = l1984 + 1) {
			fRec10[l1984] = 0.0;
		}
		for (int l1985 = 0; l1985 < 2; l1985 = l1985 + 1) {
			fRec11[l1985] = 0.0;
		}
		for (int l1986 = 0; l1986 < 2; l1986 = l1986 + 1) {
			fRec6[l1986] = 0.0;
		}
		for (int l1987 = 0; l1987 < 2; l1987 = l1987 + 1) {
			fRec7[l1987] = 0.0;
		}
		for (int l1988 = 0; l1988 < 2; l1988 = l1988 + 1) {
			fRec1412[l1988] = 0.0;
		}
		for (int l1989 = 0; l1989 < 2; l1989 = l1989 + 1) {
			fRec1413[l1989] = 0.0;
		}
		for (int l1990 = 0; l1990 < 1024; l1990 = l1990 + 1) {
			fVec583[l1990] = 0.0;
		}
		for (int l1991 = 0; l1991 < 2; l1991 = l1991 + 1) {
			fRec3[l1991] = 0.0;
		}
		for (int l1992 = 0; l1992 < 2; l1992 = l1992 + 1) {
			fRec4[l1992] = 0.0;
		}
		for (int l1993 = 0; l1993 < 2; l1993 = l1993 + 1) {
			fRec1416[l1993] = 0.0;
		}
		for (int l1994 = 0; l1994 < 2; l1994 = l1994 + 1) {
			fRec1415[l1994] = 0.0;
		}
		for (int l1995 = 0; l1995 < 2; l1995 = l1995 + 1) {
			fRec1425[l1995] = 0.0;
		}
		for (int l1996 = 0; l1996 < 2; l1996 = l1996 + 1) {
			fRec1426[l1996] = 0.0;
		}
		for (int l1997 = 0; l1997 < 2; l1997 = l1997 + 1) {
			fRec1421[l1997] = 0.0;
		}
		for (int l1998 = 0; l1998 < 2; l1998 = l1998 + 1) {
			fRec1422[l1998] = 0.0;
		}
		for (int l1999 = 0; l1999 < 2; l1999 = l1999 + 1) {
			fRec1417[l1999] = 0.0;
		}
		for (int l2000 = 0; l2000 < 2; l2000 = l2000 + 1) {
			fRec1418[l2000] = 0.0;
		}
		for (int l2001 = 0; l2001 < 2; l2001 = l2001 + 1) {
			fRec1428[l2001] = 0.0;
		}
		for (int l2002 = 0; l2002 < 2; l2002 = l2002 + 1) {
			fRec1429[l2002] = 0.0;
		}
		for (int l2003 = 0; l2003 < 2; l2003 = l2003 + 1) {
			fRec1431[l2003] = 0.0;
		}
		for (int l2004 = 0; l2004 < 2; l2004 = l2004 + 1) {
			fRec1432[l2004] = 0.0;
		}
		for (int l2005 = 0; l2005 < 2; l2005 = l2005 + 1) {
			fRec1434[l2005] = 0.0;
		}
		for (int l2006 = 0; l2006 < 2; l2006 = l2006 + 1) {
			fRec1435[l2006] = 0.0;
		}
		for (int l2007 = 0; l2007 < 2; l2007 = l2007 + 1) {
			fRec1437[l2007] = 0.0;
		}
		for (int l2008 = 0; l2008 < 2; l2008 = l2008 + 1) {
			fRec1438[l2008] = 0.0;
		}
		for (int l2009 = 0; l2009 < 2; l2009 = l2009 + 1) {
			fRec1439[l2009] = 0.0;
		}
		for (int l2010 = 0; l2010 < 2; l2010 = l2010 + 1) {
			fRec1441[l2010] = 0.0;
		}
		for (int l2011 = 0; l2011 < 2; l2011 = l2011 + 1) {
			fRec1442[l2011] = 0.0;
		}
		for (int l2012 = 0; l2012 < 2; l2012 = l2012 + 1) {
			fRec1444[l2012] = 0.0;
		}
		for (int l2013 = 0; l2013 < 2; l2013 = l2013 + 1) {
			fRec1445[l2013] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual Tonewheel* clone() {
		return new Tonewheel();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Oberli Tonewheel (sketch)");
		ui_interface->openHorizontalBox("Keys");
		ui_interface->declare(&fButton21, "midi", "key 36");
		ui_interface->addButton("key 36", &fButton21);
		ui_interface->declare(&fButton20, "midi", "key 37");
		ui_interface->addButton("key 37", &fButton20);
		ui_interface->declare(&fButton22, "midi", "key 38");
		ui_interface->addButton("key 38", &fButton22);
		ui_interface->declare(&fButton24, "midi", "key 39");
		ui_interface->addButton("key 39", &fButton24);
		ui_interface->declare(&fButton23, "midi", "key 40");
		ui_interface->addButton("key 40", &fButton23);
		ui_interface->declare(&fButton19, "midi", "key 41");
		ui_interface->addButton("key 41", &fButton19);
		ui_interface->declare(&fButton18, "midi", "key 42");
		ui_interface->addButton("key 42", &fButton18);
		ui_interface->declare(&fButton17, "midi", "key 43");
		ui_interface->addButton("key 43", &fButton17);
		ui_interface->declare(&fButton25, "midi", "key 44");
		ui_interface->addButton("key 44", &fButton25);
		ui_interface->declare(&fButton16, "midi", "key 45");
		ui_interface->addButton("key 45", &fButton16);
		ui_interface->declare(&fButton26, "midi", "key 46");
		ui_interface->addButton("key 46", &fButton26);
		ui_interface->declare(&fButton27, "midi", "key 47");
		ui_interface->addButton("key 47", &fButton27);
		ui_interface->declare(&fButton15, "midi", "key 48");
		ui_interface->addButton("key 48", &fButton15);
		ui_interface->declare(&fButton28, "midi", "key 49");
		ui_interface->addButton("key 49", &fButton28);
		ui_interface->declare(&fButton29, "midi", "key 50");
		ui_interface->addButton("key 50", &fButton29);
		ui_interface->declare(&fButton30, "midi", "key 51");
		ui_interface->addButton("key 51", &fButton30);
		ui_interface->declare(&fButton31, "midi", "key 52");
		ui_interface->addButton("key 52", &fButton31);
		ui_interface->declare(&fButton32, "midi", "key 53");
		ui_interface->addButton("key 53", &fButton32);
		ui_interface->declare(&fButton33, "midi", "key 54");
		ui_interface->addButton("key 54", &fButton33);
		ui_interface->declare(&fButton34, "midi", "key 55");
		ui_interface->addButton("key 55", &fButton34);
		ui_interface->declare(&fButton35, "midi", "key 56");
		ui_interface->addButton("key 56", &fButton35);
		ui_interface->declare(&fButton14, "midi", "key 57");
		ui_interface->addButton("key 57", &fButton14);
		ui_interface->declare(&fButton7, "midi", "key 58");
		ui_interface->addButton("key 58", &fButton7);
		ui_interface->declare(&fButton36, "midi", "key 59");
		ui_interface->addButton("key 59", &fButton36);
		ui_interface->declare(&fButton37, "midi", "key 60");
		ui_interface->addButton("key 60", &fButton37);
		ui_interface->declare(&fButton38, "midi", "key 61");
		ui_interface->addButton("key 61", &fButton38);
		ui_interface->declare(&fButton39, "midi", "key 62");
		ui_interface->addButton("key 62", &fButton39);
		ui_interface->declare(&fButton40, "midi", "key 63");
		ui_interface->addButton("key 63", &fButton40);
		ui_interface->declare(&fButton41, "midi", "key 64");
		ui_interface->addButton("key 64", &fButton41);
		ui_interface->declare(&fButton42, "midi", "key 65");
		ui_interface->addButton("key 65", &fButton42);
		ui_interface->declare(&fButton43, "midi", "key 66");
		ui_interface->addButton("key 66", &fButton43);
		ui_interface->declare(&fButton13, "midi", "key 67");
		ui_interface->addButton("key 67", &fButton13);
		ui_interface->declare(&fButton44, "midi", "key 68");
		ui_interface->addButton("key 68", &fButton44);
		ui_interface->declare(&fButton12, "midi", "key 69");
		ui_interface->addButton("key 69", &fButton12);
		ui_interface->declare(&fButton45, "midi", "key 70");
		ui_interface->addButton("key 70", &fButton45);
		ui_interface->declare(&fButton46, "midi", "key 71");
		ui_interface->addButton("key 71", &fButton46);
		ui_interface->declare(&fButton47, "midi", "key 72");
		ui_interface->addButton("key 72", &fButton47);
		ui_interface->declare(&fButton48, "midi", "key 73");
		ui_interface->addButton("key 73", &fButton48);
		ui_interface->declare(&fButton6, "midi", "key 74");
		ui_interface->addButton("key 74", &fButton6);
		ui_interface->declare(&fButton49, "midi", "key 75");
		ui_interface->addButton("key 75", &fButton49);
		ui_interface->declare(&fButton11, "midi", "key 76");
		ui_interface->addButton("key 76", &fButton11);
		ui_interface->declare(&fButton51, "midi", "key 77");
		ui_interface->addButton("key 77", &fButton51);
		ui_interface->declare(&fButton52, "midi", "key 78");
		ui_interface->addButton("key 78", &fButton52);
		ui_interface->declare(&fButton54, "midi", "key 79");
		ui_interface->addButton("key 79", &fButton54);
		ui_interface->declare(&fButton55, "midi", "key 80");
		ui_interface->addButton("key 80", &fButton55);
		ui_interface->declare(&fButton56, "midi", "key 81");
		ui_interface->addButton("key 81", &fButton56);
		ui_interface->declare(&fButton57, "midi", "key 82");
		ui_interface->addButton("key 82", &fButton57);
		ui_interface->declare(&fButton5, "midi", "key 83");
		ui_interface->addButton("key 83", &fButton5);
		ui_interface->declare(&fButton53, "midi", "key 84");
		ui_interface->addButton("key 84", &fButton53);
		ui_interface->declare(&fButton58, "midi", "key 85");
		ui_interface->addButton("key 85", &fButton58);
		ui_interface->declare(&fButton59, "midi", "key 86");
		ui_interface->addButton("key 86", &fButton59);
		ui_interface->declare(&fButton60, "midi", "key 87");
		ui_interface->addButton("key 87", &fButton60);
		ui_interface->declare(&fButton50, "midi", "key 88");
		ui_interface->addButton("key 88", &fButton50);
		ui_interface->declare(&fButton61, "midi", "key 89");
		ui_interface->addButton("key 89", &fButton61);
		ui_interface->declare(&fButton62, "midi", "key 90");
		ui_interface->addButton("key 90", &fButton62);
		ui_interface->declare(&fButton63, "midi", "key 91");
		ui_interface->addButton("key 91", &fButton63);
		ui_interface->declare(&fButton64, "midi", "key 92");
		ui_interface->addButton("key 92", &fButton64);
		ui_interface->declare(&fButton10, "midi", "key 93");
		ui_interface->addButton("key 93", &fButton10);
		ui_interface->declare(&fButton9, "midi", "key 94");
		ui_interface->addButton("key 94", &fButton9);
		ui_interface->declare(&fButton4, "midi", "key 95");
		ui_interface->addButton("key 95", &fButton4);
		ui_interface->declare(&fButton8, "midi", "key 96");
		ui_interface->addButton("key 96", &fButton8);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Leslie");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "midi", "ctrl 1");
		ui_interface->addHorizontalSlider("Fast", &fHslider0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fCheckbox0, "2", "");
		ui_interface->addCheckButton("Brake", &fCheckbox0);
		ui_interface->declare(&fHslider30, "3", "");
		ui_interface->addHorizontalSlider("Leslie on", &fHslider30, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider1, "4", "");
		ui_interface->declare(&fHslider1, "unit", "deg");
		ui_interface->addHorizontalSlider("Mic spread", &fHslider1, FAUSTFLOAT(1.2e+02), FAUSTFLOAT(0.0), FAUSTFLOAT(1.8e+02), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lower");
		ui_interface->declare(&fHslider19, "1", "");
		ui_interface->addHorizontalSlider("L 16'", &fHslider19, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider18, "2", "");
		ui_interface->addHorizontalSlider("L 5 1/3'", &fHslider18, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider17, "3", "");
		ui_interface->addHorizontalSlider("L 8'", &fHslider17, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider16, "4", "");
		ui_interface->addHorizontalSlider("L 4'", &fHslider16, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider15, "5", "");
		ui_interface->addHorizontalSlider("L 2 2/3'", &fHslider15, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider14, "6", "");
		ui_interface->addHorizontalSlider("L 2'", &fHslider14, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider13, "7", "");
		ui_interface->addHorizontalSlider("L 1 3/5'", &fHslider13, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider12, "8", "");
		ui_interface->addHorizontalSlider("L 1 1/3'", &fHslider12, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider11, "9", "");
		ui_interface->addHorizontalSlider("L 1'", &fHslider11, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Pedalboard");
		ui_interface->addButton("pedal 24", &fButton3);
		ui_interface->addButton("pedal 25", &fButton65);
		ui_interface->addButton("pedal 26", &fButton66);
		ui_interface->addButton("pedal 27", &fButton67);
		ui_interface->addButton("pedal 28", &fButton68);
		ui_interface->addButton("pedal 29", &fButton69);
		ui_interface->addButton("pedal 30", &fButton70);
		ui_interface->addButton("pedal 31", &fButton2);
		ui_interface->addButton("pedal 32", &fButton71);
		ui_interface->addButton("pedal 33", &fButton72);
		ui_interface->addButton("pedal 34", &fButton73);
		ui_interface->addButton("pedal 35", &fButton1);
		ui_interface->addButton("pedal 36", &fButton74);
		ui_interface->addButton("pedal 37", &fButton75);
		ui_interface->addButton("pedal 38", &fButton76);
		ui_interface->addButton("pedal 39", &fButton77);
		ui_interface->addButton("pedal 40", &fButton78);
		ui_interface->addButton("pedal 41", &fButton79);
		ui_interface->addButton("pedal 42", &fButton80);
		ui_interface->addButton("pedal 43", &fButton0);
		ui_interface->addButton("pedal 44", &fButton81);
		ui_interface->addButton("pedal 45", &fButton82);
		ui_interface->addButton("pedal 46", &fButton83);
		ui_interface->addButton("pedal 47", &fButton84);
		ui_interface->addButton("pedal 48", &fButton85);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Pedals");
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->addHorizontalSlider("P 16'", &fHslider5, FAUSTFLOAT(6.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->addHorizontalSlider("P 8'", &fHslider4, FAUSTFLOAT(3.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->declare(&fHslider6, "unit", "s");
		ui_interface->addHorizontalSlider("Pedal release", &fHslider6, FAUSTFLOAT(0.08), FAUSTFLOAT(0.01), FAUSTFLOAT(1.5), FAUSTFLOAT(0.01));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Percussion");
		ui_interface->declare(&fCheckbox5, "1", "");
		ui_interface->addCheckButton("On", &fCheckbox5);
		ui_interface->declare(&fCheckbox2, "2", "");
		ui_interface->addCheckButton("Third", &fCheckbox2);
		ui_interface->declare(&fCheckbox4, "3", "");
		ui_interface->addCheckButton("Slow", &fCheckbox4);
		ui_interface->declare(&fCheckbox3, "4", "");
		ui_interface->addCheckButton("Soft", &fCheckbox3);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Upper");
		ui_interface->declare(&fHslider28, "1", "");
		ui_interface->addHorizontalSlider("16'", &fHslider28, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider27, "2", "");
		ui_interface->addHorizontalSlider("5 1/3'", &fHslider27, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider26, "3", "");
		ui_interface->addHorizontalSlider("8'", &fHslider26, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider25, "4", "");
		ui_interface->addHorizontalSlider("4'", &fHslider25, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider24, "5", "");
		ui_interface->addHorizontalSlider("2 2/3'", &fHslider24, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider23, "6", "");
		ui_interface->addHorizontalSlider("2'", &fHslider23, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider22, "7", "");
		ui_interface->addHorizontalSlider("1 3/5'", &fHslider22, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider21, "8", "");
		ui_interface->addHorizontalSlider("1 1/3'", &fHslider21, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider20, "9", "");
		ui_interface->addHorizontalSlider("1'", &fHslider20, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(8.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Vibrato");
		ui_interface->declare(&fHslider29, "1", "");
		ui_interface->addHorizontalSlider("Mode", &fHslider29, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(6.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fCheckbox1, "2", "");
		ui_interface->addCheckButton("Lower", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Voice");
		ui_interface->declare(&fHslider10, "1", "");
		ui_interface->addHorizontalSlider("Split key", &fHslider10, FAUSTFLOAT(36.0), FAUSTFLOAT(36.0), FAUSTFLOAT(96.0), FAUSTFLOAT(1.0));
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->addHorizontalSlider("Key click", &fHslider9, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider7, "3", "");
		ui_interface->addHorizontalSlider("Leakage", &fHslider7, FAUSTFLOAT(0.3), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->addHorizontalSlider("Drive", &fHslider2, FAUSTFLOAT(0.2), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.01));
		ui_interface->declare(&fHslider3, "5", "");
		ui_interface->declare(&fHslider3, "unit", "dB");
		ui_interface->addHorizontalSlider("Volume", &fHslider3, FAUSTFLOAT(0.0), FAUSTFLOAT(-24.0), FAUSTFLOAT(12.0), FAUSTFLOAT(0.1));
		ui_interface->declare(&fHslider8, "6", "");
		ui_interface->declare(&fHslider8, "midi", "ctrl 64");
		ui_interface->addHorizontalSlider("Sustain", &fHslider8, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = int(double(fCheckbox0));
		int iSlow1 = double(fHslider0) > 0.5;
		double fSlow2 = ((iSlow0) ? 0.0 : ((iSlow1) ? 6.67 : 0.83));
		double fSlow3 = fConst5 * double(fHslider1);
		double fSlow4 = fConst8 * double(fHslider2);
		double fSlow5 = fConst8 * std::pow(1e+01, 0.05 * double(fHslider3));
		double fSlow6 = double(fHslider4);
		double fSlow7 = fConst11 * ((fSlow6 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow6 - 8.0)));
		double fSlow8 = double(fHslider5);
		double fSlow9 = fConst11 * ((fSlow8 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow8 - 8.0)));
		double fSlow10 = double(fButton0);
		int iSlow11 = fSlow10 == 0.0;
		double fSlow12 = 1.0 / std::max<double>(1.0, fConst0 * double(fHslider6));
		double fSlow13 = double(fButton1);
		int iSlow14 = fSlow13 == 0.0;
		double fSlow15 = double(fButton2);
		int iSlow16 = fSlow15 == 0.0;
		double fSlow17 = double(fButton3);
		int iSlow18 = fSlow17 == 0.0;
		double fSlow19 = fConst8 * double(fHslider7);
		double fSlow20 = double(fButton4);
		double fSlow21 = double(double(fHslider8) > 0.5);
		double fSlow22 = double(fHslider9);
		int iSlow23 = int(fConst21 * fSlow22);
		double fSlow24 = 1.0 / std::max<double>(1.0, fConst0 * (0.004 * (1.0 - fSlow22) + 0.0002));
		double fSlow25 = double(fHslider10);
		double fSlow26 = double(95.0 >= fSlow25);
		double fSlow27 = fConst23 * fSlow26;
		double fSlow28 = double(fButton5);
		int iSlow29 = int(fConst24 * fSlow22);
		double fSlow30 = double(83.0 >= fSlow25);
		double fSlow31 = fConst23 * fSlow30;
		double fSlow32 = double(fButton6);
		int iSlow33 = int(fConst27 * fSlow22);
		double fSlow34 = double(74.0 >= fSlow25);
		double fSlow35 = fConst23 * fSlow34;
		double fSlow36 = double(fButton7);
		int iSlow37 = int(fConst30 * fSlow22);
		double fSlow38 = double(58.0 >= fSlow25);
		double fSlow39 = fConst23 * fSlow38;
		double fSlow40 = double(fButton8);
		int iSlow41 = int(fConst33 * fSlow22);
		double fSlow42 = double(96.0 >= fSlow25);
		double fSlow43 = fConst23 * fSlow42;
		double fSlow44 = double(fButton9);
		int iSlow45 = int(fConst36 * fSlow22);
		double fSlow46 = double(94.0 >= fSlow25);
		double fSlow47 = fConst23 * fSlow46;
		double fSlow48 = double(fButton10);
		int iSlow49 = int(fConst39 * fSlow22);
		double fSlow50 = double(93.0 >= fSlow25);
		double fSlow51 = fConst23 * fSlow50;
		double fSlow52 = double(fButton11);
		int iSlow53 = int(fConst42 * fSlow22);
		double fSlow54 = double(76.0 >= fSlow25);
		double fSlow55 = fConst23 * fSlow54;
		double fSlow56 = double(fButton12);
		int iSlow57 = int(fConst43 * fSlow22);
		double fSlow58 = double(69.0 >= fSlow25);
		double fSlow59 = fConst23 * fSlow58;
		double fSlow60 = double(fButton13);
		int iSlow61 = int(fConst45 * fSlow22);
		double fSlow62 = double(67.0 >= fSlow25);
		double fSlow63 = fConst23 * fSlow62;
		double fSlow64 = double(fButton14);
		int iSlow65 = int(fConst47 * fSlow22);
		double fSlow66 = double(57.0 >= fSlow25);
		double fSlow67 = fConst23 * fSlow66;
		double fSlow68 = double(fButton15);
		int iSlow69 = int(fConst50 * fSlow22);
		double fSlow70 = double(48.0 >= fSlow25);
		double fSlow71 = fConst23 * fSlow70;
		double fSlow72 = double(fButton16);
		int iSlow73 = int(fConst53 * fSlow22);
		double fSlow74 = double(45.0 >= fSlow25);
		double fSlow75 = fConst23 * fSlow74;
		double fSlow76 = double(fButton17);
		int iSlow77 = int(fConst56 * fSlow22);
		double fSlow78 = double(43.0 >= fSlow25);
		double fSlow79 = fConst23 * fSlow78;
		double fSlow80 = double(fButton18);
		int iSlow81 = int(fConst60 * fSlow22);
		double fSlow82 = double(42.0 >= fSlow25);
		double fSlow83 = fConst23 * fSlow82;
		double fSlow84 = double(fButton19);
		int iSlow85 = int(fConst63 * fSlow22);
		double fSlow86 = double(41.0 >= fSlow25);
		double fSlow87 = fConst23 * fSlow86;
		double fSlow88 = double(fButton20);
		int iSlow89 = int(fConst67 * fSlow22);
		double fSlow90 = double(37.0 >= fSlow25);
		double fSlow91 = fConst23 * fSlow90;
		double fSlow92 = double(fButton21);
		int iSlow93 = int(fConst69 * fSlow22);
		double fSlow94 = double(36.0 >= fSlow25);
		double fSlow95 = fConst23 * fSlow94;
		double fSlow96 = double(fButton22);
		int iSlow97 = int(fConst73 * fSlow22);
		double fSlow98 = double(38.0 >= fSlow25);
		double fSlow99 = fConst23 * fSlow98;
		double fSlow100 = double(fButton23);
		int iSlow101 = int(fConst76 * fSlow22);
		double fSlow102 = double(4e+01 >= fSlow25);
		double fSlow103 = fConst23 * fSlow102;
		double fSlow104 = double(fButton24);
		int iSlow105 = int(fConst80 * fSlow22);
		double fSlow106 = double(39.0 >= fSlow25);
		double fSlow107 = fConst23 * fSlow106;
		double fSlow108 = double(fButton25);
		int iSlow109 = int(fConst84 * fSlow22);
		double fSlow110 = double(44.0 >= fSlow25);
		double fSlow111 = fConst23 * fSlow110;
		double fSlow112 = double(fButton26);
		int iSlow113 = int(fConst85 * fSlow22);
		double fSlow114 = double(46.0 >= fSlow25);
		double fSlow115 = fConst23 * fSlow114;
		double fSlow116 = double(fButton27);
		int iSlow117 = int(fConst88 * fSlow22);
		double fSlow118 = double(47.0 >= fSlow25);
		double fSlow119 = fConst23 * fSlow118;
		double fSlow120 = double(fButton28);
		int iSlow121 = int(fConst90 * fSlow22);
		double fSlow122 = double(49.0 >= fSlow25);
		double fSlow123 = fConst23 * fSlow122;
		double fSlow124 = double(fButton29);
		int iSlow125 = int(fConst92 * fSlow22);
		double fSlow126 = double(5e+01 >= fSlow25);
		double fSlow127 = fConst23 * fSlow126;
		double fSlow128 = double(fButton30);
		int iSlow129 = int(fConst93 * fSlow22);
		double fSlow130 = double(51.0 >= fSlow25);
		double fSlow131 = fConst23 * fSlow130;
		double fSlow132 = double(fButton31);
		int iSlow133 = int(fConst95 * fSlow22);
		double fSlow134 = double(52.0 >= fSlow25);
		double fSlow135 = fConst23 * fSlow134;
		double fSlow136 = double(fButton32);
		int iSlow137 = int(fConst97 * fSlow22);
		double fSlow138 = double(53.0 >= fSlow25);
		double fSlow139 = fConst23 * fSlow138;
		double fSlow140 = double(fButton33);
		int iSlow141 = int(fConst100 * fSlow22);
		double fSlow142 = double(54.0 >= fSlow25);
		double fSlow143 = fConst23 * fSlow142;
		double fSlow144 = double(fButton34);
		int iSlow145 = int(fConst102 * fSlow22);
		double fSlow146 = double(55.0 >= fSlow25);
		double fSlow147 = fConst23 * fSlow146;
		double fSlow148 = double(fButton35);
		int iSlow149 = int(fConst103 * fSlow22);
		double fSlow150 = double(56.0 >= fSlow25);
		double fSlow151 = fConst23 * fSlow150;
		double fSlow152 = double(fButton36);
		int iSlow153 = int(fConst104 * fSlow22);
		double fSlow154 = double(59.0 >= fSlow25);
		double fSlow155 = fConst23 * fSlow154;
		double fSlow156 = double(fButton37);
		int iSlow157 = int(fConst105 * fSlow22);
		double fSlow158 = double(6e+01 >= fSlow25);
		double fSlow159 = fConst23 * fSlow158;
		double fSlow160 = double(fButton38);
		int iSlow161 = int(fConst107 * fSlow22);
		double fSlow162 = double(61.0 >= fSlow25);
		double fSlow163 = fConst23 * fSlow162;
		double fSlow164 = double(fButton39);
		int iSlow165 = int(fConst108 * fSlow22);
		double fSlow166 = double(62.0 >= fSlow25);
		double fSlow167 = fConst23 * fSlow166;
		double fSlow168 = double(fButton40);
		int iSlow169 = int(fConst110 * fSlow22);
		double fSlow170 = double(63.0 >= fSlow25);
		double fSlow171 = fConst23 * fSlow170;
		double fSlow172 = double(fButton41);
		int iSlow173 = int(fConst111 * fSlow22);
		double fSlow174 = double(64.0 >= fSlow25);
		double fSlow175 = fConst23 * fSlow174;
		double fSlow176 = double(fButton42);
		int iSlow177 = int(fConst112 * fSlow22);
		double fSlow178 = double(65.0 >= fSlow25);
		double fSlow179 = fConst23 * fSlow178;
		double fSlow180 = double(fButton43);
		int iSlow181 = int(fConst113 * fSlow22);
		double fSlow182 = double(66.0 >= fSlow25);
		double fSlow183 = fConst23 * fSlow182;
		double fSlow184 = double(fButton44);
		int iSlow185 = int(fConst115 * fSlow22);
		double fSlow186 = double(68.0 >= fSlow25);
		double fSlow187 = fConst23 * fSlow186;
		double fSlow188 = double(fButton45);
		int iSlow189 = int(fConst116 * fSlow22);
		double fSlow190 = double(7e+01 >= fSlow25);
		double fSlow191 = fConst23 * fSlow190;
		double fSlow192 = double(fButton46);
		int iSlow193 = int(fConst117 * fSlow22);
		double fSlow194 = double(71.0 >= fSlow25);
		double fSlow195 = fConst23 * fSlow194;
		double fSlow196 = double(fButton47);
		int iSlow197 = int(fConst118 * fSlow22);
		double fSlow198 = double(72.0 >= fSlow25);
		double fSlow199 = fConst23 * fSlow198;
		double fSlow200 = double(fButton48);
		int iSlow201 = int(fConst119 * fSlow22);
		double fSlow202 = double(73.0 >= fSlow25);
		double fSlow203 = fConst23 * fSlow202;
		double fSlow204 = double(fButton49);
		int iSlow205 = int(fConst121 * fSlow22);
		double fSlow206 = double(75.0 >= fSlow25);
		double fSlow207 = fConst23 * fSlow206;
		double fSlow208 = double(fButton50);
		int iSlow209 = int(fConst122 * fSlow22);
		double fSlow210 = double(88.0 >= fSlow25);
		double fSlow211 = fConst23 * fSlow210;
		double fSlow212 = double(fButton51);
		int iSlow213 = int(fConst123 * fSlow22);
		double fSlow214 = double(77.0 >= fSlow25);
		double fSlow215 = fConst23 * fSlow214;
		double fSlow216 = double(fButton52);
		int iSlow217 = int(fConst125 * fSlow22);
		double fSlow218 = double(78.0 >= fSlow25);
		double fSlow219 = fConst23 * fSlow218;
		double fSlow220 = double(fButton53);
		int iSlow221 = int(fConst126 * fSlow22);
		double fSlow222 = double(84.0 >= fSlow25);
		double fSlow223 = fConst23 * fSlow222;
		double fSlow224 = double(fButton54);
		int iSlow225 = int(fConst127 * fSlow22);
		double fSlow226 = double(79.0 >= fSlow25);
		double fSlow227 = fConst23 * fSlow226;
		double fSlow228 = double(fButton55);
		int iSlow229 = int(fConst128 * fSlow22);
		double fSlow230 = double(8e+01 >= fSlow25);
		double fSlow231 = fConst23 * fSlow230;
		double fSlow232 = double(fButton56);
		int iSlow233 = int(fConst129 * fSlow22);
		double fSlow234 = double(81.0 >= fSlow25);
		double fSlow235 = fConst23 * fSlow234;
		double fSlow236 = double(fButton57);
		int iSlow237 = int(fConst130 * fSlow22);
		double fSlow238 = double(82.0 >= fSlow25);
		double fSlow239 = fConst23 * fSlow238;
		double fSlow240 = double(fButton58);
		int iSlow241 = int(fConst131 * fSlow22);
		double fSlow242 = double(85.0 >= fSlow25);
		double fSlow243 = fConst23 * fSlow242;
		double fSlow244 = double(fButton59);
		int iSlow245 = int(fConst132 * fSlow22);
		double fSlow246 = double(86.0 >= fSlow25);
		double fSlow247 = fConst23 * fSlow246;
		double fSlow248 = double(fButton60);
		int iSlow249 = int(fConst133 * fSlow22);
		double fSlow250 = double(87.0 >= fSlow25);
		double fSlow251 = fConst23 * fSlow250;
		double fSlow252 = double(fButton61);
		int iSlow253 = int(fConst134 * fSlow22);
		double fSlow254 = double(89.0 >= fSlow25);
		double fSlow255 = fConst23 * fSlow254;
		double fSlow256 = double(fButton62);
		int iSlow257 = int(fConst135 * fSlow22);
		double fSlow258 = double(9e+01 >= fSlow25);
		double fSlow259 = fConst23 * fSlow258;
		double fSlow260 = double(fButton63);
		int iSlow261 = int(fConst136 * fSlow22);
		double fSlow262 = double(91.0 >= fSlow25);
		double fSlow263 = fConst23 * fSlow262;
		double fSlow264 = double(fButton64);
		int iSlow265 = int(fConst137 * fSlow22);
		double fSlow266 = double(92.0 >= fSlow25);
		double fSlow267 = fConst23 * fSlow266;
		double fSlow268 = double(fHslider11);
		double fSlow269 = fConst11 * ((fSlow268 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow268 - 8.0)));
		int iSlow270 = int(fConst138 * fSlow22);
		int iSlow271 = int(fConst139 * fSlow22);
		int iSlow272 = int(fConst140 * fSlow22);
		int iSlow273 = int(fConst141 * fSlow22);
		int iSlow274 = int(fConst142 * fSlow22);
		int iSlow275 = int(fConst143 * fSlow22);
		int iSlow276 = int(fConst144 * fSlow22);
		int iSlow277 = int(fConst145 * fSlow22);
		int iSlow278 = int(fConst146 * fSlow22);
		int iSlow279 = int(fConst147 * fSlow22);
		int iSlow280 = int(fConst149 * fSlow22);
		int iSlow281 = int(fConst151 * fSlow22);
		int iSlow282 = int(fConst153 * fSlow22);
		int iSlow283 = int(fConst154 * fSlow22);
		int iSlow284 = int(fConst155 * fSlow22);
		int iSlow285 = int(fConst156 * fSlow22);
		int iSlow286 = int(fConst158 * fSlow22);
		int iSlow287 = int(fConst159 * fSlow22);
		int iSlow288 = int(fConst160 * fSlow22);
		int iSlow289 = int(fConst162 * fSlow22);
		int iSlow290 = int(fConst163 * fSlow22);
		int iSlow291 = int(fConst164 * fSlow22);
		int iSlow292 = int(fConst165 * fSlow22);
		int iSlow293 = int(fConst166 * fSlow22);
		int iSlow294 = int(fConst168 * fSlow22);
		int iSlow295 = int(fConst169 * fSlow22);
		int iSlow296 = int(fConst170 * fSlow22);
		int iSlow297 = int(fConst171 * fSlow22);
		int iSlow298 = int(fConst172 * fSlow22);
		int iSlow299 = int(fConst173 * fSlow22);
		int iSlow300 = int(fConst174 * fSlow22);
		int iSlow301 = int(fConst175 * fSlow22);
		int iSlow302 = int(fConst176 * fSlow22);
		int iSlow303 = int(fConst177 * fSlow22);
		int iSlow304 = int(fConst178 * fSlow22);
		int iSlow305 = int(fConst179 * fSlow22);
		int iSlow306 = int(fConst180 * fSlow22);
		int iSlow307 = int(fConst181 * fSlow22);
		int iSlow308 = int(fConst182 * fSlow22);
		int iSlow309 = int(fConst183 * fSlow22);
		int iSlow310 = int(fConst184 * fSlow22);
		int iSlow311 = int(fConst185 * fSlow22);
		int iSlow312 = int(fConst186 * fSlow22);
		int iSlow313 = int(fConst187 * fSlow22);
		int iSlow314 = int(fConst188 * fSlow22);
		int iSlow315 = int(fConst189 * fSlow22);
		int iSlow316 = int(fConst190 * fSlow22);
		int iSlow317 = int(fConst191 * fSlow22);
		int iSlow318 = int(fConst192 * fSlow22);
		int iSlow319 = int(fConst193 * fSlow22);
		int iSlow320 = int(fConst194 * fSlow22);
		int iSlow321 = int(fConst195 * fSlow22);
		int iSlow322 = int(fConst196 * fSlow22);
		int iSlow323 = int(fConst197 * fSlow22);
		int iSlow324 = int(fConst198 * fSlow22);
		int iSlow325 = int(fConst199 * fSlow22);
		int iSlow326 = int(fConst200 * fSlow22);
		int iSlow327 = int(fConst201 * fSlow22);
		int iSlow328 = int(fConst202 * fSlow22);
		int iSlow329 = int(fConst203 * fSlow22);
		int iSlow330 = int(fConst204 * fSlow22);
		double fSlow331 = double(fHslider12);
		double fSlow332 = fConst11 * ((fSlow331 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow331 - 8.0)));
		int iSlow333 = int(fConst205 * fSlow22);
		int iSlow334 = int(fConst206 * fSlow22);
		int iSlow335 = int(fConst207 * fSlow22);
		int iSlow336 = int(fConst208 * fSlow22);
		int iSlow337 = int(fConst209 * fSlow22);
		int iSlow338 = int(fConst210 * fSlow22);
		int iSlow339 = int(fConst211 * fSlow22);
		int iSlow340 = int(fConst212 * fSlow22);
		int iSlow341 = int(fConst213 * fSlow22);
		int iSlow342 = int(fConst214 * fSlow22);
		int iSlow343 = int(fConst215 * fSlow22);
		int iSlow344 = int(fConst216 * fSlow22);
		int iSlow345 = int(fConst217 * fSlow22);
		int iSlow346 = int(fConst219 * fSlow22);
		int iSlow347 = int(fConst220 * fSlow22);
		int iSlow348 = int(fConst221 * fSlow22);
		int iSlow349 = int(fConst222 * fSlow22);
		int iSlow350 = int(fConst223 * fSlow22);
		int iSlow351 = int(fConst224 * fSlow22);
		int iSlow352 = int(fConst225 * fSlow22);
		int iSlow353 = int(fConst226 * fSlow22);
		int iSlow354 = int(fConst227 * fSlow22);
		int iSlow355 = int(fConst228 * fSlow22);
		int iSlow356 = int(fConst229 * fSlow22);
		int iSlow357 = int(fConst230 * fSlow22);
		int iSlow358 = int(fConst231 * fSlow22);
		int iSlow359 = int(fConst232 * fSlow22);
		int iSlow360 = int(fConst233 * fSlow22);
		int iSlow361 = int(fConst234 * fSlow22);
		int iSlow362 = int(fConst236 * fSlow22);
		int iSlow363 = int(fConst237 * fSlow22);
		int iSlow364 = int(fConst238 * fSlow22);
		int iSlow365 = int(fConst240 * fSlow22);
		int iSlow366 = int(fConst241 * fSlow22);
		int iSlow367 = int(fConst243 * fSlow22);
		int iSlow368 = int(fConst244 * fSlow22);
		int iSlow369 = int(fConst245 * fSlow22);
		int iSlow370 = int(fConst246 * fSlow22);
		int iSlow371 = int(fConst247 * fSlow22);
		int iSlow372 = int(fConst248 * fSlow22);
		int iSlow373 = int(fConst249 * fSlow22);
		int iSlow374 = int(fConst250 * fSlow22);
		int iSlow375 = int(fConst251 * fSlow22);
		int iSlow376 = int(fConst252 * fSlow22);
		int iSlow377 = int(fConst253 * fSlow22);
		int iSlow378 = int(fConst254 * fSlow22);
		int iSlow379 = int(fConst255 * fSlow22);
		int iSlow380 = int(fConst256 * fSlow22);
		int iSlow381 = int(fConst257 * fSlow22);
		int iSlow382 = int(fConst258 * fSlow22);
		int iSlow383 = int(fConst259 * fSlow22);
		int iSlow384 = int(fConst260 * fSlow22);
		int iSlow385 = int(fConst261 * fSlow22);
		int iSlow386 = int(fConst262 * fSlow22);
		int iSlow387 = int(fConst263 * fSlow22);
		int iSlow388 = int(fConst264 * fSlow22);
		int iSlow389 = int(fConst265 * fSlow22);
		int iSlow390 = int(fConst266 * fSlow22);
		int iSlow391 = int(fConst267 * fSlow22);
		int iSlow392 = int(fConst268 * fSlow22);
		int iSlow393 = int(fConst269 * fSlow22);
		double fSlow394 = double(fHslider13);
		double fSlow395 = fConst11 * ((fSlow394 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow394 - 8.0)));
		int iSlow396 = int(fConst270 * fSlow22);
		int iSlow397 = int(fConst271 * fSlow22);
		int iSlow398 = int(fConst272 * fSlow22);
		int iSlow399 = int(fConst273 * fSlow22);
		int iSlow400 = int(fConst274 * fSlow22);
		int iSlow401 = int(fConst275 * fSlow22);
		int iSlow402 = int(fConst276 * fSlow22);
		int iSlow403 = int(fConst277 * fSlow22);
		int iSlow404 = int(fConst278 * fSlow22);
		int iSlow405 = int(fConst279 * fSlow22);
		int iSlow406 = int(fConst280 * fSlow22);
		int iSlow407 = int(fConst281 * fSlow22);
		int iSlow408 = int(fConst282 * fSlow22);
		int iSlow409 = int(fConst283 * fSlow22);
		int iSlow410 = int(fConst284 * fSlow22);
		int iSlow411 = int(fConst285 * fSlow22);
		int iSlow412 = int(fConst286 * fSlow22);
		int iSlow413 = int(fConst287 * fSlow22);
		int iSlow414 = int(fConst288 * fSlow22);
		int iSlow415 = int(fConst290 * fSlow22);
		int iSlow416 = int(fConst291 * fSlow22);
		int iSlow417 = int(fConst293 * fSlow22);
		int iSlow418 = int(fConst295 * fSlow22);
		int iSlow419 = int(fConst296 * fSlow22);
		int iSlow420 = int(fConst298 * fSlow22);
		int iSlow421 = int(fConst299 * fSlow22);
		int iSlow422 = int(fConst300 * fSlow22);
		int iSlow423 = int(fConst301 * fSlow22);
		int iSlow424 = int(fConst302 * fSlow22);
		int iSlow425 = int(fConst303 * fSlow22);
		int iSlow426 = int(fConst304 * fSlow22);
		int iSlow427 = int(fConst305 * fSlow22);
		int iSlow428 = int(fConst306 * fSlow22);
		int iSlow429 = int(fConst307 * fSlow22);
		int iSlow430 = int(fConst308 * fSlow22);
		int iSlow431 = int(fConst309 * fSlow22);
		int iSlow432 = int(fConst310 * fSlow22);
		int iSlow433 = int(fConst311 * fSlow22);
		int iSlow434 = int(fConst312 * fSlow22);
		int iSlow435 = int(fConst313 * fSlow22);
		int iSlow436 = int(fConst314 * fSlow22);
		int iSlow437 = int(fConst315 * fSlow22);
		int iSlow438 = int(fConst316 * fSlow22);
		int iSlow439 = int(fConst317 * fSlow22);
		int iSlow440 = int(fConst318 * fSlow22);
		int iSlow441 = int(fConst319 * fSlow22);
		int iSlow442 = int(fConst320 * fSlow22);
		int iSlow443 = int(fConst321 * fSlow22);
		int iSlow444 = int(fConst322 * fSlow22);
		int iSlow445 = int(fConst323 * fSlow22);
		int iSlow446 = int(fConst324 * fSlow22);
		int iSlow447 = int(fConst325 * fSlow22);
		int iSlow448 = int(fConst326 * fSlow22);
		int iSlow449 = int(fConst327 * fSlow22);
		int iSlow450 = int(fConst328 * fSlow22);
		int iSlow451 = int(fConst329 * fSlow22);
		int iSlow452 = int(fConst330 * fSlow22);
		int iSlow453 = int(fConst331 * fSlow22);
		int iSlow454 = int(fConst332 * fSlow22);
		int iSlow455 = int(fConst333 * fSlow22);
		int iSlow456 = int(fConst334 * fSlow22);
		double fSlow457 = double(fHslider14);
		double fSlow458 = fConst11 * ((fSlow457 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow457 - 8.0)));
		int iSlow459 = int(fConst335 * fSlow22);
		int iSlow460 = int(fConst336 * fSlow22);
		int iSlow461 = int(fConst337 * fSlow22);
		int iSlow462 = int(fConst338 * fSlow22);
		int iSlow463 = int(fConst339 * fSlow22);
		int iSlow464 = int(fConst340 * fSlow22);
		int iSlow465 = int(fConst341 * fSlow22);
		int iSlow466 = int(fConst342 * fSlow22);
		int iSlow467 = int(fConst343 * fSlow22);
		int iSlow468 = int(fConst344 * fSlow22);
		int iSlow469 = int(fConst345 * fSlow22);
		int iSlow470 = int(fConst346 * fSlow22);
		int iSlow471 = int(fConst347 * fSlow22);
		int iSlow472 = int(fConst348 * fSlow22);
		int iSlow473 = int(fConst349 * fSlow22);
		int iSlow474 = int(fConst350 * fSlow22);
		int iSlow475 = int(fConst351 * fSlow22);
		int iSlow476 = int(fConst352 * fSlow22);
		int iSlow477 = int(fConst353 * fSlow22);
		int iSlow478 = int(fConst354 * fSlow22);
		int iSlow479 = int(fConst355 * fSlow22);
		int iSlow480 = int(fConst356 * fSlow22);
		int iSlow481 = int(fConst357 * fSlow22);
		int iSlow482 = int(fConst358 * fSlow22);
		int iSlow483 = int(fConst360 * fSlow22);
		int iSlow484 = int(fConst361 * fSlow22);
		int iSlow485 = int(fConst363 * fSlow22);
		int iSlow486 = int(fConst364 * fSlow22);
		int iSlow487 = int(fConst366 * fSlow22);
		int iSlow488 = int(fConst368 * fSlow22);
		int iSlow489 = int(fConst369 * fSlow22);
		int iSlow490 = int(fConst370 * fSlow22);
		int iSlow491 = int(fConst371 * fSlow22);
		int iSlow492 = int(fConst372 * fSlow22);
		int iSlow493 = int(fConst373 * fSlow22);
		int iSlow494 = int(fConst374 * fSlow22);
		int iSlow495 = int(fConst375 * fSlow22);
		int iSlow496 = int(fConst376 * fSlow22);
		int iSlow497 = int(fConst377 * fSlow22);
		int iSlow498 = int(fConst378 * fSlow22);
		int iSlow499 = int(fConst379 * fSlow22);
		int iSlow500 = int(fConst380 * fSlow22);
		int iSlow501 = int(fConst381 * fSlow22);
		int iSlow502 = int(fConst382 * fSlow22);
		int iSlow503 = int(fConst383 * fSlow22);
		int iSlow504 = int(fConst384 * fSlow22);
		int iSlow505 = int(fConst385 * fSlow22);
		int iSlow506 = int(fConst386 * fSlow22);
		int iSlow507 = int(fConst387 * fSlow22);
		int iSlow508 = int(fConst388 * fSlow22);
		int iSlow509 = int(fConst389 * fSlow22);
		int iSlow510 = int(fConst390 * fSlow22);
		int iSlow511 = int(fConst391 * fSlow22);
		int iSlow512 = int(fConst392 * fSlow22);
		int iSlow513 = int(fConst393 * fSlow22);
		int iSlow514 = int(fConst394 * fSlow22);
		int iSlow515 = int(fConst395 * fSlow22);
		int iSlow516 = int(fConst396 * fSlow22);
		int iSlow517 = int(fConst397 * fSlow22);
		int iSlow518 = int(fConst398 * fSlow22);
		int iSlow519 = int(fConst399 * fSlow22);
		double fSlow520 = double(fHslider15);
		double fSlow521 = fConst11 * ((fSlow520 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow520 - 8.0)));
		int iSlow522 = int(fConst400 * fSlow22);
		int iSlow523 = int(fConst401 * fSlow22);
		int iSlow524 = int(fConst402 * fSlow22);
		int iSlow525 = int(fConst403 * fSlow22);
		int iSlow526 = int(fConst404 * fSlow22);
		int iSlow527 = int(fConst405 * fSlow22);
		int iSlow528 = int(fConst406 * fSlow22);
		int iSlow529 = int(fConst407 * fSlow22);
		int iSlow530 = int(fConst408 * fSlow22);
		int iSlow531 = int(fConst409 * fSlow22);
		int iSlow532 = int(fConst410 * fSlow22);
		int iSlow533 = int(fConst411 * fSlow22);
		int iSlow534 = int(fConst412 * fSlow22);
		int iSlow535 = int(fConst413 * fSlow22);
		int iSlow536 = int(fConst414 * fSlow22);
		int iSlow537 = int(fConst415 * fSlow22);
		int iSlow538 = int(fConst416 * fSlow22);
		int iSlow539 = int(fConst417 * fSlow22);
		int iSlow540 = int(fConst418 * fSlow22);
		int iSlow541 = int(fConst419 * fSlow22);
		int iSlow542 = int(fConst420 * fSlow22);
		int iSlow543 = int(fConst421 * fSlow22);
		int iSlow544 = int(fConst422 * fSlow22);
		int iSlow545 = int(fConst423 * fSlow22);
		int iSlow546 = int(fConst424 * fSlow22);
		int iSlow547 = int(fConst425 * fSlow22);
		int iSlow548 = int(fConst426 * fSlow22);
		int iSlow549 = int(fConst427 * fSlow22);
		int iSlow550 = int(fConst428 * fSlow22);
		int iSlow551 = int(fConst431 * fSlow22);
		int iSlow552 = int(fConst432 * fSlow22);
		int iSlow553 = int(fConst433 * fSlow22);
		int iSlow554 = int(fConst434 * fSlow22);
		int iSlow555 = int(fConst435 * fSlow22);
		int iSlow556 = int(fConst437 * fSlow22);
		int iSlow557 = int(fConst438 * fSlow22);
		int iSlow558 = int(fConst439 * fSlow22);
		int iSlow559 = int(fConst440 * fSlow22);
		int iSlow560 = int(fConst441 * fSlow22);
		int iSlow561 = int(fConst442 * fSlow22);
		int iSlow562 = int(fConst443 * fSlow22);
		int iSlow563 = int(fConst444 * fSlow22);
		int iSlow564 = int(fConst445 * fSlow22);
		int iSlow565 = int(fConst446 * fSlow22);
		int iSlow566 = int(fConst447 * fSlow22);
		int iSlow567 = int(fConst448 * fSlow22);
		int iSlow568 = int(fConst449 * fSlow22);
		int iSlow569 = int(fConst450 * fSlow22);
		int iSlow570 = int(fConst451 * fSlow22);
		int iSlow571 = int(fConst452 * fSlow22);
		int iSlow572 = int(fConst453 * fSlow22);
		int iSlow573 = int(fConst454 * fSlow22);
		int iSlow574 = int(fConst455 * fSlow22);
		int iSlow575 = int(fConst456 * fSlow22);
		int iSlow576 = int(fConst457 * fSlow22);
		int iSlow577 = int(fConst458 * fSlow22);
		int iSlow578 = int(fConst459 * fSlow22);
		int iSlow579 = int(fConst460 * fSlow22);
		int iSlow580 = int(fConst461 * fSlow22);
		int iSlow581 = int(fConst462 * fSlow22);
		int iSlow582 = int(fConst463 * fSlow22);
		double fSlow583 = double(fHslider16);
		double fSlow584 = fConst11 * ((fSlow583 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow583 - 8.0)));
		int iSlow585 = int(fConst464 * fSlow22);
		int iSlow586 = int(fConst465 * fSlow22);
		int iSlow587 = int(fConst466 * fSlow22);
		int iSlow588 = int(fConst467 * fSlow22);
		int iSlow589 = int(fConst468 * fSlow22);
		int iSlow590 = int(fConst469 * fSlow22);
		int iSlow591 = int(fConst470 * fSlow22);
		int iSlow592 = int(fConst471 * fSlow22);
		int iSlow593 = int(fConst472 * fSlow22);
		int iSlow594 = int(fConst473 * fSlow22);
		int iSlow595 = int(fConst474 * fSlow22);
		int iSlow596 = int(fConst475 * fSlow22);
		int iSlow597 = int(fConst476 * fSlow22);
		int iSlow598 = int(fConst477 * fSlow22);
		int iSlow599 = int(fConst478 * fSlow22);
		int iSlow600 = int(fConst479 * fSlow22);
		int iSlow601 = int(fConst480 * fSlow22);
		int iSlow602 = int(fConst481 * fSlow22);
		int iSlow603 = int(fConst482 * fSlow22);
		int iSlow604 = int(fConst483 * fSlow22);
		int iSlow605 = int(fConst484 * fSlow22);
		int iSlow606 = int(fConst485 * fSlow22);
		int iSlow607 = int(fConst486 * fSlow22);
		int iSlow608 = int(fConst487 * fSlow22);
		int iSlow609 = int(fConst488 * fSlow22);
		int iSlow610 = int(fConst489 * fSlow22);
		int iSlow611 = int(fConst490 * fSlow22);
		int iSlow612 = int(fConst491 * fSlow22);
		int iSlow613 = int(fConst493 * fSlow22);
		int iSlow614 = int(fConst494 * fSlow22);
		int iSlow615 = int(fConst497 * fSlow22);
		int iSlow616 = int(fConst498 * fSlow22);
		int iSlow617 = int(fConst499 * fSlow22);
		int iSlow618 = int(fConst500 * fSlow22);
		int iSlow619 = int(fConst502 * fSlow22);
		int iSlow620 = int(fConst503 * fSlow22);
		int iSlow621 = int(fConst504 * fSlow22);
		int iSlow622 = int(fConst505 * fSlow22);
		int iSlow623 = int(fConst506 * fSlow22);
		int iSlow624 = int(fConst507 * fSlow22);
		int iSlow625 = int(fConst508 * fSlow22);
		int iSlow626 = int(fConst510 * fSlow22);
		int iSlow627 = int(fConst511 * fSlow22);
		int iSlow628 = int(fConst513 * fSlow22);
		int iSlow629 = int(fConst514 * fSlow22);
		int iSlow630 = int(fConst515 * fSlow22);
		int iSlow631 = int(fConst516 * fSlow22);
		int iSlow632 = int(fConst517 * fSlow22);
		int iSlow633 = int(fConst518 * fSlow22);
		int iSlow634 = int(fConst519 * fSlow22);
		int iSlow635 = int(fConst520 * fSlow22);
		int iSlow636 = int(fConst521 * fSlow22);
		int iSlow637 = int(fConst522 * fSlow22);
		int iSlow638 = int(fConst523 * fSlow22);
		int iSlow639 = int(fConst524 * fSlow22);
		int iSlow640 = int(fConst525 * fSlow22);
		int iSlow641 = int(fConst526 * fSlow22);
		int iSlow642 = int(fConst527 * fSlow22);
		int iSlow643 = int(fConst528 * fSlow22);
		int iSlow644 = int(fConst529 * fSlow22);
		int iSlow645 = int(fConst530 * fSlow22);
		double fSlow646 = double(fHslider17);
		double fSlow647 = fConst11 * ((fSlow646 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow646 - 8.0)));
		int iSlow648 = int(fConst531 * fSlow22);
		int iSlow649 = int(fConst532 * fSlow22);
		int iSlow650 = int(fConst533 * fSlow22);
		int iSlow651 = int(fConst534 * fSlow22);
		int iSlow652 = int(fConst535 * fSlow22);
		int iSlow653 = int(fConst536 * fSlow22);
		int iSlow654 = int(fConst537 * fSlow22);
		int iSlow655 = int(fConst538 * fSlow22);
		int iSlow656 = int(fConst539 * fSlow22);
		int iSlow657 = int(fConst540 * fSlow22);
		int iSlow658 = int(fConst541 * fSlow22);
		int iSlow659 = int(fConst542 * fSlow22);
		int iSlow660 = int(fConst543 * fSlow22);
		int iSlow661 = int(fConst544 * fSlow22);
		int iSlow662 = int(fConst545 * fSlow22);
		int iSlow663 = int(fConst546 * fSlow22);
		int iSlow664 = int(fConst547 * fSlow22);
		int iSlow665 = int(fConst548 * fSlow22);
		int iSlow666 = int(fConst549 * fSlow22);
		int iSlow667 = int(fConst550 * fSlow22);
		int iSlow668 = int(fConst551 * fSlow22);
		int iSlow669 = int(fConst552 * fSlow22);
		int iSlow670 = int(fConst553 * fSlow22);
		int iSlow671 = int(fConst554 * fSlow22);
		int iSlow672 = int(fConst555 * fSlow22);
		int iSlow673 = int(fConst556 * fSlow22);
		int iSlow674 = int(fConst557 * fSlow22);
		int iSlow675 = int(fConst558 * fSlow22);
		int iSlow676 = int(fConst559 * fSlow22);
		int iSlow677 = int(fConst560 * fSlow22);
		int iSlow678 = int(fConst561 * fSlow22);
		int iSlow679 = int(fConst562 * fSlow22);
		int iSlow680 = int(fConst563 * fSlow22);
		int iSlow681 = int(fConst564 * fSlow22);
		int iSlow682 = int(fConst565 * fSlow22);
		int iSlow683 = int(fConst566 * fSlow22);
		int iSlow684 = int(fConst567 * fSlow22);
		int iSlow685 = int(fConst568 * fSlow22);
		int iSlow686 = int(fConst569 * fSlow22);
		int iSlow687 = int(fConst570 * fSlow22);
		int iSlow688 = int(fConst571 * fSlow22);
		int iSlow689 = int(fConst572 * fSlow22);
		int iSlow690 = int(fConst573 * fSlow22);
		int iSlow691 = int(fConst574 * fSlow22);
		int iSlow692 = int(fConst575 * fSlow22);
		int iSlow693 = int(fConst576 * fSlow22);
		int iSlow694 = int(fConst577 * fSlow22);
		int iSlow695 = int(fConst578 * fSlow22);
		int iSlow696 = int(fConst579 * fSlow22);
		int iSlow697 = int(fConst580 * fSlow22);
		int iSlow698 = int(fConst581 * fSlow22);
		int iSlow699 = int(fConst582 * fSlow22);
		int iSlow700 = int(fConst583 * fSlow22);
		int iSlow701 = int(fConst584 * fSlow22);
		int iSlow702 = int(fConst585 * fSlow22);
		int iSlow703 = int(fConst586 * fSlow22);
		int iSlow704 = int(fConst587 * fSlow22);
		int iSlow705 = int(fConst588 * fSlow22);
		int iSlow706 = int(fConst589 * fSlow22);
		int iSlow707 = int(fConst590 * fSlow22);
		int iSlow708 = int(fConst591 * fSlow22);
		double fSlow709 = double(fHslider18);
		double fSlow710 = fConst11 * ((fSlow709 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow709 - 8.0)));
		int iSlow711 = int(fConst592 * fSlow22);
		int iSlow712 = int(fConst593 * fSlow22);
		int iSlow713 = int(fConst594 * fSlow22);
		int iSlow714 = int(fConst595 * fSlow22);
		int iSlow715 = int(fConst596 * fSlow22);
		int iSlow716 = int(fConst597 * fSlow22);
		int iSlow717 = int(fConst598 * fSlow22);
		int iSlow718 = int(fConst599 * fSlow22);
		int iSlow719 = int(fConst600 * fSlow22);
		int iSlow720 = int(fConst601 * fSlow22);
		int iSlow721 = int(fConst602 * fSlow22);
		int iSlow722 = int(fConst603 * fSlow22);
		int iSlow723 = int(fConst604 * fSlow22);
		int iSlow724 = int(fConst605 * fSlow22);
		int iSlow725 = int(fConst606 * fSlow22);
		int iSlow726 = int(fConst607 * fSlow22);
		int iSlow727 = int(fConst608 * fSlow22);
		int iSlow728 = int(fConst609 * fSlow22);
		int iSlow729 = int(fConst610 * fSlow22);
		int iSlow730 = int(fConst611 * fSlow22);
		int iSlow731 = int(fConst612 * fSlow22);
		int iSlow732 = int(fConst613 * fSlow22);
		int iSlow733 = int(fConst615 * fSlow22);
		int iSlow734 = int(fConst616 * fSlow22);
		int iSlow735 = int(fConst617 * fSlow22);
		int iSlow736 = int(fConst618 * fSlow22);
		int iSlow737 = int(fConst619 * fSlow22);
		int iSlow738 = int(fConst620 * fSlow22);
		int iSlow739 = int(fConst621 * fSlow22);
		int iSlow740 = int(fConst622 * fSlow22);
		int iSlow741 = int(fConst623 * fSlow22);
		int iSlow742 = int(fConst624 * fSlow22);
		int iSlow743 = int(fConst625 * fSlow22);
		int iSlow744 = int(fConst626 * fSlow22);
		int iSlow745 = int(fConst627 * fSlow22);
		int iSlow746 = int(fConst628 * fSlow22);
		int iSlow747 = int(fConst629 * fSlow22);
		int iSlow748 = int(fConst630 * fSlow22);
		int iSlow749 = int(fConst631 * fSlow22);
		int iSlow750 = int(fConst632 * fSlow22);
		int iSlow751 = int(fConst633 * fSlow22);
		int iSlow752 = int(fConst634 * fSlow22);
		int iSlow753 = int(fConst635 * fSlow22);
		int iSlow754 = int(fConst636 * fSlow22);
		int iSlow755 = int(fConst637 * fSlow22);
		int iSlow756 = int(fConst638 * fSlow22);
		int iSlow757 = int(fConst639 * fSlow22);
		int iSlow758 = int(fConst640 * fSlow22);
		int iSlow759 = int(fConst641 * fSlow22);
		int iSlow760 = int(fConst642 * fSlow22);
		int iSlow761 = int(fConst643 * fSlow22);
		int iSlow762 = int(fConst644 * fSlow22);
		int iSlow763 = int(fConst645 * fSlow22);
		int iSlow764 = int(fConst646 * fSlow22);
		int iSlow765 = int(fConst647 * fSlow22);
		int iSlow766 = int(fConst648 * fSlow22);
		int iSlow767 = int(fConst649 * fSlow22);
		int iSlow768 = int(fConst650 * fSlow22);
		int iSlow769 = int(fConst651 * fSlow22);
		int iSlow770 = int(fConst652 * fSlow22);
		int iSlow771 = int(fConst653 * fSlow22);
		double fSlow772 = double(fHslider19);
		double fSlow773 = fConst11 * ((fSlow772 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow772 - 8.0)));
		double fSlow774 = fConst8 * double(fCheckbox1);
		double fSlow775 = fConst11 * double(fCheckbox2);
		double fSlow776 = fConst11 * double(fCheckbox3);
		double fSlow777 = std::exp(-(fConst654 / ((double(fCheckbox4) > 0.5) ? 1.5 : 0.5)));
		double fSlow778 = fConst11 * double(fCheckbox5);
		double fSlow779 = double(fHslider20);
		double fSlow780 = fConst11 * ((fSlow779 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow779 - 8.0)));
		double fSlow781 = double(fHslider21);
		double fSlow782 = fConst11 * ((fSlow781 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow781 - 8.0)));
		double fSlow783 = double(fHslider22);
		double fSlow784 = fConst11 * ((fSlow783 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow783 - 8.0)));
		double fSlow785 = double(fHslider23);
		double fSlow786 = fConst11 * ((fSlow785 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow785 - 8.0)));
		double fSlow787 = double(fHslider24);
		double fSlow788 = fConst11 * ((fSlow787 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow787 - 8.0)));
		double fSlow789 = double(fHslider25);
		double fSlow790 = fConst11 * ((fSlow789 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow789 - 8.0)));
		double fSlow791 = double(fHslider26);
		double fSlow792 = fConst11 * ((fSlow791 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow791 - 8.0)));
		double fSlow793 = double(fHslider27);
		double fSlow794 = fConst11 * ((fSlow793 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow793 - 8.0)));
		double fSlow795 = double(fHslider28);
		double fSlow796 = fConst11 * ((fSlow795 < 0.5) ? 0.0 : std::pow(1e+01, 0.15 * (fSlow795 - 8.0)));
		int iSlow797 = int(double(fHslider29));
		double fSlow798 = 0.7071 * double(iSlow797 >= 4);
		double fSlow799 = fConst8 * (fSlow798 + double(iSlow797 == 0));
		double fSlow800 = fConst8 * (fSlow798 + double((iSlow797 >= 1) & (iSlow797 <= 3)));
		int iSlow801 = ((iSlow797 > 3) ? iSlow797 + -3 : iSlow797);
		double fSlow802 = fConst8 * ((iSlow801 >= 2) ? ((iSlow801 >= 3) ? 0.0012 : 0.0007) : ((iSlow801 >= 1) ? 0.00035 : 0.0));
		double fSlow803 = double(fButton65);
		int iSlow804 = fSlow803 == 0.0;
		double fSlow805 = double(fButton66);
		int iSlow806 = fSlow805 == 0.0;
		double fSlow807 = double(fButton67);
		int iSlow808 = fSlow807 == 0.0;
		double fSlow809 = double(fButton68);
		int iSlow810 = fSlow809 == 0.0;
		double fSlow811 = double(fButton69);
		int iSlow812 = fSlow811 == 0.0;
		double fSlow813 = double(fButton70);
		int iSlow814 = fSlow813 == 0.0;
		double fSlow815 = double(fButton71);
		int iSlow816 = fSlow815 == 0.0;
		double fSlow817 = double(fButton72);
		int iSlow818 = fSlow817 == 0.0;
		double fSlow819 = double(fButton73);
		int iSlow820 = fSlow819 == 0.0;
		double fSlow821 = double(fButton74);
		int iSlow822 = fSlow821 == 0.0;
		double fSlow823 = double(fButton75);
		int iSlow824 = fSlow823 == 0.0;
		double fSlow825 = double(fButton76);
		int iSlow826 = fSlow825 == 0.0;
		double fSlow827 = double(fButton77);
		int iSlow828 = fSlow827 == 0.0;
		double fSlow829 = double(fButton78);
		int iSlow830 = fSlow829 == 0.0;
		double fSlow831 = double(fButton79);
		int iSlow832 = fSlow831 == 0.0;
		double fSlow833 = double(fButton80);
		int iSlow834 = fSlow833 == 0.0;
		double fSlow835 = double(fButton81);
		int iSlow836 = fSlow835 == 0.0;
		double fSlow837 = double(fButton82);
		int iSlow838 = fSlow837 == 0.0;
		double fSlow839 = double(fButton83);
		int iSlow840 = fSlow839 == 0.0;
		double fSlow841 = double(fButton84);
		int iSlow842 = fSlow841 == 0.0;
		double fSlow843 = double(fButton85);
		int iSlow844 = fSlow843 == 0.0;
		double fSlow845 = ((iSlow0) ? 0.0 : ((iSlow1) ? 5.67 : 0.67));
		double fSlow846 = fConst11 * double(fHslider30);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			double fTemp0 = ((fSlow2 > fRec1[1]) ? fConst2 : fConst1);
			fRec1[0] = fSlow2 * (1.0 - fTemp0) + fRec1[1] * fTemp0;
			double fTemp1 = fRec0[1] + fConst3 * fRec1[0];
			fRec0[0] = fTemp1 - std::floor(fTemp1);
			double fTemp2 = std::floor(fRec0[0]);
			double fTemp3 = fRec0[0] - fTemp2;
			double fTemp4 = 6.283185307179586 * fTemp3;
			fRec2[0] = fSlow3 + fConst4 * fRec2[1];
			double fTemp5 = 0.5 * fRec2[0];
			double fTemp6 = fTemp5 + fTemp4;
			double fTemp7 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp6 + 2.2)) + 0.0028);
			double fTemp8 = 0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fTemp7) + 2.2)) + 0.0028)) + 2.2)) + 0.0028;
			double fTemp9 = std::tan(fConst6 * (4.5e+03 * (std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * fTemp8) + 2.2) + 1.0) + 3e+03));
			double fTemp10 = fTemp9 * (fTemp9 + 1.4144271570014144) + 1.0;
			fRec14[0] = fSlow4 + fConst7 * fRec14[1];
			double fTemp11 = 1.2 * fRec14[0] + 1.0;
			fRec15[0] = fSlow5 + fConst7 * fRec15[1];
			double fTemp12 = 0.15 * fRec14[0];
			double fTemp13 = tanh(fTemp12);
			int iTemp14 = 1 - iVec0[1];
			double fTemp15 = ((iTemp14) ? 0.0 : fConst9 + fRec18[1]);
			fRec18[0] = fTemp15 - std::floor(fTemp15);
			int iTemp16 = std::max<int>(0, std::min<int>(int(65536.0 * fRec18[0]), 65535));
			double fTemp17 = 0.9210131670420774 * ftbl1TonewheelSIG1[iTemp16] + 0.38953144434708037 * ftbl0TonewheelSIG0[iTemp16];
			fRec20[0] = fSlow7 + fConst10 * fRec20[1];
			double fTemp18 = ((iTemp14) ? 0.0 : fConst12 + fRec21[1]);
			fRec21[0] = fTemp18 - std::floor(fTemp18);
			int iTemp19 = std::max<int>(0, std::min<int>(int(65536.0 * fRec21[0]), 65535));
			double fTemp20 = 0.24879714771347183 * ftbl1TonewheelSIG1[iTemp19] + 0.9685556149698585 * ftbl0TonewheelSIG0[iTemp19];
			fRec22[0] = fSlow9 + fConst10 * fRec22[1];
			fVec3[0] = fSlow10;
			iRec23[0] = iSlow11 * (iRec23[1] + 1);
			fRec24[0] = fSlow10 + fRec24[1] * double(fVec3[1] >= fSlow10);
			double fTemp21 = ((iTemp14) ? 0.0 : fConst14 + fRec25[1]);
			fRec25[0] = fTemp21 - std::floor(fTemp21);
			int iTemp22 = std::max<int>(0, std::min<int>(int(65536.0 * fRec25[0]), 65535));
			double fTemp23 = 0.6933767894910843 * ftbl1TonewheelSIG1[iTemp22] + 0.7205752062033751 * ftbl0TonewheelSIG0[iTemp22];
			double fTemp24 = ((iTemp14) ? 0.0 : fConst15 + fRec26[1]);
			fRec26[0] = fTemp24 - std::floor(fTemp24);
			int iTemp25 = std::max<int>(0, std::min<int>(int(65536.0 * fRec26[0]), 65535));
			double fTemp26 = 0.8363600749035475 * ftbl1TonewheelSIG1[iTemp25] + 0.5481804676448555 * ftbl0TonewheelSIG0[iTemp25];
			fVec4[0] = fSlow13;
			iRec27[0] = iSlow14 * (iRec27[1] + 1);
			fRec28[0] = fSlow13 + fRec28[1] * double(fVec4[1] >= fSlow13);
			double fTemp27 = ((iTemp14) ? 0.0 : fConst16 + fRec29[1]);
			fRec29[0] = fTemp27 - std::floor(fTemp27);
			int iTemp28 = std::max<int>(0, std::min<int>(int(65536.0 * fRec29[0]), 65535));
			double fTemp29 = 0.9997215575568095 * ftbl1TonewheelSIG1[iTemp28] + 0.02359676579929795 * ftbl0TonewheelSIG0[iTemp28];
			fVec5[0] = fSlow15;
			iRec30[0] = iSlow16 * (iRec30[1] + 1);
			fRec31[0] = fSlow15 + fRec31[1] * double(fVec5[1] >= fSlow15);
			double fTemp30 = ((iTemp14) ? 0.0 : fConst17 + fRec32[1]);
			fRec32[0] = fTemp30 - std::floor(fTemp30);
			int iTemp31 = std::max<int>(0, std::min<int>(int(65536.0 * fRec32[0]), 65535));
			double fTemp32 = 0.7660177082608002 * ftbl1TonewheelSIG1[iTemp31] + 0.6428194697042644 * ftbl0TonewheelSIG0[iTemp31];
			double fTemp33 = ((iTemp14) ? 0.0 : fConst18 + fRec33[1]);
			fRec33[0] = fTemp33 - std::floor(fTemp33);
			int iTemp34 = std::max<int>(0, std::min<int>(int(65536.0 * fRec33[0]), 65535));
			double fTemp35 = 0.40912870738115825 * ftbl1TonewheelSIG1[iTemp34] + 0.912476685070157 * ftbl0TonewheelSIG0[iTemp34];
			fVec6[0] = fSlow17;
			iRec34[0] = iSlow18 * (iRec34[1] + 1);
			fRec35[0] = fSlow17 + fRec35[1] * double(fVec6[1] >= fSlow17);
			double fTemp36 = ((iTemp14) ? 0.0 : fConst19 + fRec36[1]);
			fRec36[0] = fTemp36 - std::floor(fTemp36);
			int iTemp37 = std::max<int>(0, std::min<int>(int(65536.0 * fRec36[0]), 65535));
			double fTemp38 = 0.8286053801114699 * ftbl1TonewheelSIG1[iTemp37] + 0.5598331216088652 * ftbl0TonewheelSIG0[iTemp37];
			double fTemp39 = ((iTemp14) ? 0.0 : fConst20 + fRec37[1]);
			fRec37[0] = fTemp39 - std::floor(fTemp39);
			int iTemp40 = std::max<int>(0, std::min<int>(int(65536.0 * fRec37[0]), 65535));
			double fTemp41 = 0.4073223050061108 * ftbl1TonewheelSIG1[iTemp40] + 0.9132844791435519 * ftbl0TonewheelSIG0[iTemp40];
			fRec38[0] = fSlow19 + fConst7 * fRec38[1];
			double fTemp42 = fTemp41 + 0.0316 * fRec38[0] * (0.07377968281070935 * fTemp41 + 0.22837877339406987 * fTemp38);
			fRec40[IOTA0 & 1023] = std::max<double>(fSlow20, fSlow21 * fRec40[(IOTA0 - 1) & 1023]);
			double fTemp43 = fRec40[(IOTA0 - iSlow23) & 1023];
			fVec7[0] = fTemp43;
			iRec39[0] = (iRec39[1] + 1) * (fTemp43 == 0.0);
			fRec41[0] = fTemp43 + fRec41[1] * double(fVec7[1] >= fTemp43);
			double fTemp44 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec41[0], 1.0) - fSlow24 * double(iRec39[0]));
			fRec42[0] = fSlow27 + fConst22 * fRec42[1];
			double fTemp45 = 1.0 - fRec42[0];
			double fTemp46 = fTemp41 + 0.0316 * fRec38[0] * (0.9098672301042825 * fTemp38 + 0.3315466704952996 * fTemp41);
			fRec44[IOTA0 & 1023] = std::max<double>(fSlow28, fSlow21 * fRec44[(IOTA0 - 1) & 1023]);
			double fTemp47 = fRec44[(IOTA0 - iSlow29) & 1023];
			fVec8[0] = fTemp47;
			iRec43[0] = (iRec43[1] + 1) * (fTemp47 == 0.0);
			fRec45[0] = fTemp47 + fRec45[1] * double(fVec8[1] >= fTemp47);
			double fTemp48 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec45[0], 1.0) - fSlow24 * double(iRec43[0]));
			fRec46[0] = fSlow31 + fConst22 * fRec46[1];
			double fTemp49 = 1.0 - fRec46[0];
			double fTemp50 = ((iTemp14) ? 0.0 : fConst25 + fRec47[1]);
			fRec47[0] = fTemp50 - std::floor(fTemp50);
			int iTemp51 = std::max<int>(0, std::min<int>(int(65536.0 * fRec47[0]), 65535));
			double fTemp52 = 0.7549170619630726 * ftbl1TonewheelSIG1[iTemp51] + 0.6558202722980149 * ftbl0TonewheelSIG0[iTemp51];
			double fTemp53 = ((iTemp14) ? 0.0 : fConst26 + fRec48[1]);
			fRec48[0] = fTemp53 - std::floor(fTemp53);
			int iTemp54 = std::max<int>(0, std::min<int>(int(65536.0 * fRec48[0]), 65535));
			double fTemp55 = 0.13139046189553466 * ftbl1TonewheelSIG1[iTemp54] + 0.9913306948354207 * ftbl0TonewheelSIG0[iTemp54];
			double fTemp56 = fTemp52 + 0.0316 * fRec38[0] * (0.8576160447846632 * fTemp55 + 0.40223915005481103 * fTemp52);
			fRec50[IOTA0 & 1023] = std::max<double>(fSlow32, fSlow21 * fRec50[(IOTA0 - 1) & 1023]);
			double fTemp57 = fRec50[(IOTA0 - iSlow33) & 1023];
			fVec9[0] = fTemp57;
			iRec49[0] = (iRec49[1] + 1) * (fTemp57 == 0.0);
			fRec51[0] = fTemp57 + fRec51[1] * double(fVec9[1] >= fTemp57);
			double fTemp58 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec51[0], 1.0) - fSlow24 * double(iRec49[0]));
			fRec52[0] = fSlow35 + fConst22 * fRec52[1];
			double fTemp59 = 1.0 - fRec52[0];
			double fTemp60 = ((iTemp14) ? 0.0 : fConst28 + fRec53[1]);
			fRec53[0] = fTemp60 - std::floor(fTemp60);
			int iTemp61 = std::max<int>(0, std::min<int>(int(65536.0 * fRec53[0]), 65535));
			double fTemp62 = 0.07272789223883858 * ftbl1TonewheelSIG1[iTemp61] + 0.9973518204176979 * ftbl0TonewheelSIG0[iTemp61];
			double fTemp63 = fRec38[0] * fTemp62;
			double fTemp64 = ((iTemp14) ? 0.0 : fConst29 + fRec54[1]);
			fRec54[0] = fTemp64 - std::floor(fTemp64);
			int iTemp65 = std::max<int>(0, std::min<int>(int(65536.0 * fRec54[0]), 65535));
			double fTemp66 = 0.818484717880944 * ftbl1TonewheelSIG1[iTemp65] + 0.5745282992119286 * ftbl0TonewheelSIG0[iTemp65];
			double fTemp67 = fTemp66 + 0.02373730798177276 * fTemp63;
			fRec56[IOTA0 & 1023] = std::max<double>(fSlow36, fSlow21 * fRec56[(IOTA0 - 1) & 1023]);
			double fTemp68 = fRec56[(IOTA0 - iSlow37) & 1023];
			fVec10[0] = fTemp68;
			iRec55[0] = (iRec55[1] + 1) * (fTemp68 == 0.0);
			fRec57[0] = fTemp68 + fRec57[1] * double(fVec10[1] >= fTemp68);
			double fTemp69 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec57[0], 1.0) - fSlow24 * double(iRec55[0]));
			fRec58[0] = fSlow39 + fConst22 * fRec58[1];
			double fTemp70 = 1.0 - fRec58[0];
			double fTemp71 = ((iTemp14) ? 0.0 : fConst31 + fRec59[1]);
			fRec59[0] = fTemp71 - std::floor(fTemp71);
			int iTemp72 = std::max<int>(0, std::min<int>(int(65536.0 * fRec59[0]), 65535));
			double fTemp73 = 0.995506980683957 * ftbl0TonewheelSIG0[iTemp72];
			double fTemp74 = ((iTemp14) ? 0.0 : fConst32 + fRec60[1]);
			fRec60[0] = fTemp74 - std::floor(fTemp74);
			int iTemp75 = std::max<int>(0, std::min<int>(int(65536.0 * fRec60[0]), 65535));
			double fTemp76 = 0.9963335109847169 * ftbl1TonewheelSIG1[iTemp75] + 0.08555428036554946 * ftbl0TonewheelSIG0[iTemp75];
			double fTemp77 = 0.09468817988276852 * ftbl1TonewheelSIG1[iTemp72];
			double fTemp78 = fTemp77 - fTemp73;
			double fTemp79 = fTemp77 + 0.0316 * fRec38[0] * (0.6690419375081547 * fTemp78 - 0.6056095568856108 * fTemp76) - fTemp73;
			fRec62[IOTA0 & 1023] = std::max<double>(fSlow40, fSlow21 * fRec62[(IOTA0 - 1) & 1023]);
			double fTemp80 = fRec62[(IOTA0 - iSlow41) & 1023];
			fVec11[0] = fTemp80;
			iRec61[0] = (iRec61[1] + 1) * (fTemp80 == 0.0);
			fRec63[0] = fTemp80 + fRec63[1] * double(fVec11[1] >= fTemp80);
			double fTemp81 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec63[0], 1.0) - fSlow24 * double(iRec61[0]));
			fRec64[0] = fSlow43 + fConst22 * fRec64[1];
			double fTemp82 = 1.0 - fRec64[0];
			double fTemp83 = ((iTemp14) ? 0.0 : fConst34 + fRec65[1]);
			fRec65[0] = fTemp83 - std::floor(fTemp83);
			int iTemp84 = std::max<int>(0, std::min<int>(int(65536.0 * fRec65[0]), 65535));
			double fTemp85 = 0.7269301301362892 * ftbl1TonewheelSIG1[iTemp84];
			double fTemp86 = ((iTemp14) ? 0.0 : fConst35 + fRec66[1]);
			fRec66[0] = fTemp86 - std::floor(fTemp86);
			int iTemp87 = std::max<int>(0, std::min<int>(int(65536.0 * fRec66[0]), 65535));
			double fTemp88 = 0.7428793430587783 * ftbl1TonewheelSIG1[iTemp87] + 0.6694253368797434 * ftbl0TonewheelSIG0[iTemp87];
			double fTemp89 = 0.6867114284035455 * ftbl0TonewheelSIG0[iTemp84];
			double fTemp90 = fTemp89 - fTemp85;
			double fTemp91 = fTemp89 + 0.0316 * fRec38[0] * (0.23633264518502983 * fTemp90 - 0.9864247085442912 * fTemp88) - fTemp85;
			fRec68[IOTA0 & 1023] = std::max<double>(fSlow44, fSlow21 * fRec68[(IOTA0 - 1) & 1023]);
			double fTemp92 = fRec68[(IOTA0 - iSlow45) & 1023];
			fVec12[0] = fTemp92;
			iRec67[0] = (iRec67[1] + 1) * (fTemp92 == 0.0);
			fRec69[0] = fTemp92 + fRec69[1] * double(fVec12[1] >= fTemp92);
			double fTemp93 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec69[0], 1.0) - fSlow24 * double(iRec67[0]));
			fRec70[0] = fSlow47 + fConst22 * fRec70[1];
			double fTemp94 = 1.0 - fRec70[0];
			double fTemp95 = ((iTemp14) ? 0.0 : fConst37 + fRec71[1]);
			fRec71[0] = fTemp95 - std::floor(fTemp95);
			int iTemp96 = std::max<int>(0, std::min<int>(int(65536.0 * fRec71[0]), 65535));
			double fTemp97 = 0.9814828556252776 * ftbl1TonewheelSIG1[iTemp96] + 0.1915500042120868 * ftbl0TonewheelSIG0[iTemp96];
			double fTemp98 = ((iTemp14) ? 0.0 : fConst38 + fRec72[1]);
			fRec72[0] = fTemp98 - std::floor(fTemp98);
			int iTemp99 = std::max<int>(0, std::min<int>(int(65536.0 * fRec72[0]), 65535));
			double fTemp100 = 0.8087781497648324 * ftbl1TonewheelSIG1[iTemp99];
			double fTemp101 = 0.5881138533166639 * ftbl0TonewheelSIG0[iTemp99];
			double fTemp102 = fTemp101 - fTemp100;
			double fTemp103 = 0.0316 * fRec38[0] * (0.42700942829515043 * fTemp102 - 0.6826176900922292 * fTemp97) - fTemp97;
			fRec74[IOTA0 & 1023] = std::max<double>(fSlow48, fSlow21 * fRec74[(IOTA0 - 1) & 1023]);
			double fTemp104 = fRec74[(IOTA0 - iSlow49) & 1023];
			fVec13[0] = fTemp104;
			iRec73[0] = (iRec73[1] + 1) * (fTemp104 == 0.0);
			fRec75[0] = fTemp104 + fRec75[1] * double(fVec13[1] >= fTemp104);
			double fTemp105 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec75[0], 1.0) - fSlow24 * double(iRec73[0]));
			fRec76[0] = fSlow51 + fConst22 * fRec76[1];
			double fTemp106 = 1.0 - fRec76[0];
			double fTemp107 = ((iTemp14) ? 0.0 : fConst40 + fRec77[1]);
			fRec77[0] = fTemp107 - std::floor(fTemp107);
			int iTemp108 = std::max<int>(0, std::min<int>(int(65536.0 * fRec77[0]), 65535));
			double fTemp109 = 0.9661067579285627 * ftbl1TonewheelSIG1[iTemp108];
			double fTemp110 = 0.25814285247661123 * ftbl0TonewheelSIG0[iTemp108];
			double fTemp111 = fTemp110 - fTemp109;
			double fTemp112 = ((iTemp14) ? 0.0 : fConst41 + fRec78[1]);
			fRec78[0] = fTemp112 - std::floor(fTemp112);
			int iTemp113 = std::max<int>(0, std::min<int>(int(65536.0 * fRec78[0]), 65535));
			double fTemp114 = 0.6397458095827049 * ftbl1TonewheelSIG1[iTemp113] + 0.7685865592900838 * ftbl0TonewheelSIG0[iTemp113];
			double fTemp115 = fTemp110 + 0.0316 * fRec38[0] * (0.978027683129767 * fTemp114 + 0.5742202290639398 * fTemp111) - fTemp109;
			fRec80[IOTA0 & 1023] = std::max<double>(fSlow52, fSlow21 * fRec80[(IOTA0 - 1) & 1023]);
			double fTemp116 = fRec80[(IOTA0 - iSlow53) & 1023];
			fVec14[0] = fTemp116;
			iRec79[0] = (iRec79[1] + 1) * (fTemp116 == 0.0);
			fRec81[0] = fTemp116 + fRec81[1] * double(fVec14[1] >= fTemp116);
			double fTemp117 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec81[0], 1.0) - fSlow24 * double(iRec79[0]));
			fRec82[0] = fSlow55 + fConst22 * fRec82[1];
			double fTemp118 = 1.0 - fRec82[0];
			double fTemp119 = 0.0316 * fRec38[0] * (0.1827186906375573 * fTemp102 - 0.21040578571046353 * fTemp97) - fTemp97;
			fRec84[IOTA0 & 1023] = std::max<double>(fSlow56, fSlow21 * fRec84[(IOTA0 - 1) & 1023]);
			double fTemp120 = fRec84[(IOTA0 - iSlow57) & 1023];
			fVec15[0] = fTemp120;
			iRec83[0] = (iRec83[1] + 1) * (fTemp120 == 0.0);
			fRec85[0] = fTemp120 + fRec85[1] * double(fVec15[1] >= fTemp120);
			double fTemp121 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec85[0], 1.0) - fSlow24 * double(iRec83[0]));
			fRec86[0] = fSlow59 + fConst22 * fRec86[1];
			double fTemp122 = 1.0 - fRec86[0];
			double fTemp123 = ((iTemp14) ? 0.0 : fConst44 + fRec87[1]);
			fRec87[0] = fTemp123 - std::floor(fTemp123);
			int iTemp124 = std::max<int>(0, std::min<int>(int(65536.0 * fRec87[0]), 65535));
			double fTemp125 = 0.11657035729520294 * ftbl1TonewheelSIG1[iTemp124];
			double fTemp126 = 0.9931824363127193 * ftbl0TonewheelSIG0[iTemp124];
			double fTemp127 = fTemp126 - fTemp125;
			double fTemp128 = fRec38[0] * fTemp127;
			double fTemp129 = fTemp126 + 0.01882124041950447 * fTemp128 - fTemp125;
			fRec89[IOTA0 & 1023] = std::max<double>(fSlow60, fSlow21 * fRec89[(IOTA0 - 1) & 1023]);
			double fTemp130 = fRec89[(IOTA0 - iSlow61) & 1023];
			fVec16[0] = fTemp130;
			iRec88[0] = (iRec88[1] + 1) * (fTemp130 == 0.0);
			fRec90[0] = fTemp130 + fRec90[1] * double(fVec16[1] >= fTemp130);
			double fTemp131 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec90[0], 1.0) - fSlow24 * double(iRec88[0]));
			fRec91[0] = fSlow63 + fConst22 * fRec91[1];
			double fTemp132 = 1.0 - fRec91[0];
			double fTemp133 = ((iTemp14) ? 0.0 : fConst46 + fRec92[1]);
			fRec92[0] = fTemp133 - std::floor(fTemp133);
			int iTemp134 = std::max<int>(0, std::min<int>(int(65536.0 * fRec92[0]), 65535));
			double fTemp135 = 0.9327969301778017 * ftbl0TonewheelSIG0[iTemp134];
			double fTemp136 = 0.36040239601155444 * ftbl1TonewheelSIG1[iTemp134];
			double fTemp137 = fTemp136 - fTemp135;
			double fTemp138 = fTemp101 + 0.0316 * fRec38[0] * (0.3302852450979117 * fTemp137 - 0.18970014847582206 * fTemp97) - fTemp100;
			fRec94[IOTA0 & 1023] = std::max<double>(fSlow64, fSlow21 * fRec94[(IOTA0 - 1) & 1023]);
			double fTemp139 = fRec94[(IOTA0 - iSlow65) & 1023];
			fVec17[0] = fTemp139;
			iRec93[0] = (iRec93[1] + 1) * (fTemp139 == 0.0);
			fRec95[0] = fTemp139 + fRec95[1] * double(fVec17[1] >= fTemp139);
			double fTemp140 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec95[0], 1.0) - fSlow24 * double(iRec93[0]));
			fRec96[0] = fSlow67 + fConst22 * fRec96[1];
			double fTemp141 = 1.0 - fRec96[0];
			double fTemp142 = ((iTemp14) ? 0.0 : fConst48 + fRec97[1]);
			fRec97[0] = fTemp142 - std::floor(fTemp142);
			int iTemp143 = std::max<int>(0, std::min<int>(int(65536.0 * fRec97[0]), 65535));
			double fTemp144 = 0.6392241359814809 * ftbl1TonewheelSIG1[iTemp143] + 0.7690204834584897 * ftbl0TonewheelSIG0[iTemp143];
			double fTemp145 = ((iTemp14) ? 0.0 : fConst49 + fRec98[1]);
			fRec98[0] = fTemp145 - std::floor(fTemp145);
			int iTemp146 = std::max<int>(0, std::min<int>(int(65536.0 * fRec98[0]), 65535));
			double fTemp147 = 0.9747384917056648 * ftbl1TonewheelSIG1[iTemp146];
			double fTemp148 = 0.22334921711831787 * ftbl0TonewheelSIG0[iTemp146];
			double fTemp149 = fTemp148 - fTemp147;
			double fTemp150 = 0.0316 * fRec38[0] * (0.9210070500848815 * fTemp149 - 0.9419724692397722 * fTemp144) - fTemp76;
			fRec100[IOTA0 & 1023] = std::max<double>(fSlow68, fSlow21 * fRec100[(IOTA0 - 1) & 1023]);
			double fTemp151 = fRec100[(IOTA0 - iSlow69) & 1023];
			fVec18[0] = fTemp151;
			iRec99[0] = (iRec99[1] + 1) * (fTemp151 == 0.0);
			fRec101[0] = fTemp151 + fRec101[1] * double(fVec18[1] >= fTemp151);
			double fTemp152 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec101[0], 1.0) - fSlow24 * double(iRec99[0]));
			fRec102[0] = fSlow71 + fConst22 * fRec102[1];
			double fTemp153 = 1.0 - fRec102[0];
			double fTemp154 = ((iTemp14) ? 0.0 : fConst51 + fRec103[1]);
			fRec103[0] = fTemp154 - std::floor(fTemp154);
			int iTemp155 = std::max<int>(0, std::min<int>(int(65536.0 * fRec103[0]), 65535));
			double fTemp156 = 0.5418499283306758 * ftbl1TonewheelSIG1[iTemp155];
			double fTemp157 = ((iTemp14) ? 0.0 : fConst52 + fRec104[1]);
			fRec104[0] = fTemp157 - std::floor(fTemp157);
			int iTemp158 = std::max<int>(0, std::min<int>(int(65536.0 * fRec104[0]), 65535));
			double fTemp159 = 0.8246768240003958 * ftbl1TonewheelSIG1[iTemp158];
			double fTemp160 = 0.5656042220109573 * ftbl0TonewheelSIG0[iTemp158];
			double fTemp161 = fTemp160 - fTemp159;
			double fTemp162 = 0.8404752555358435 * ftbl0TonewheelSIG0[iTemp155];
			double fTemp163 = fTemp162 + 0.0316 * fRec38[0] * (0.19712485813943204 * fTemp161 + 0.18764716228906764 * fTemp102) - fTemp156;
			fRec106[IOTA0 & 1023] = std::max<double>(fSlow72, fSlow21 * fRec106[(IOTA0 - 1) & 1023]);
			double fTemp164 = fRec106[(IOTA0 - iSlow73) & 1023];
			fVec19[0] = fTemp164;
			iRec105[0] = (iRec105[1] + 1) * (fTemp164 == 0.0);
			fRec107[0] = fTemp164 + fRec107[1] * double(fVec19[1] >= fTemp164);
			double fTemp165 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec107[0], 1.0) - fSlow24 * double(iRec105[0]));
			fRec108[0] = fSlow75 + fConst22 * fRec108[1];
			double fTemp166 = 1.0 - fRec108[0];
			double fTemp167 = ((iTemp14) ? 0.0 : fConst54 + fRec109[1]);
			fRec109[0] = fTemp167 - std::floor(fTemp167);
			int iTemp168 = std::max<int>(0, std::min<int>(int(65536.0 * fRec109[0]), 65535));
			double fTemp169 = 0.5336302476011494 * ftbl0TonewheelSIG0[iTemp168];
			double fTemp170 = ((iTemp14) ? 0.0 : fConst55 + fRec110[1]);
			fRec110[0] = fTemp170 - std::floor(fTemp170);
			int iTemp171 = std::max<int>(0, std::min<int>(int(65536.0 * fRec110[0]), 65535));
			double fTemp172 = 0.07930359643407214 * ftbl0TonewheelSIG0[iTemp171];
			double fTemp173 = 0.9968505101531633 * ftbl1TonewheelSIG1[iTemp171];
			double fTemp174 = fTemp173 - fTemp172;
			double fTemp175 = 0.8457178955450428 * ftbl1TonewheelSIG1[iTemp168];
			double fTemp176 = fTemp175 + 0.0316 * fRec38[0] * (0.49187842959872796 * fTemp174 - 0.6131990938629315 * fTemp17) - fTemp169;
			fRec112[IOTA0 & 1023] = std::max<double>(fSlow76, fSlow21 * fRec112[(IOTA0 - 1) & 1023]);
			double fTemp177 = fRec112[(IOTA0 - iSlow77) & 1023];
			fVec20[0] = fTemp177;
			iRec111[0] = (iRec111[1] + 1) * (fTemp177 == 0.0);
			fRec113[0] = fTemp177 + fRec113[1] * double(fVec20[1] >= fTemp177);
			double fTemp178 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec113[0], 1.0) - fSlow24 * double(iRec111[0]));
			fRec114[0] = fSlow79 + fConst22 * fRec114[1];
			double fTemp179 = 1.0 - fRec114[0];
			double fTemp180 = ((iTemp14) ? 0.0 : fConst57 + fRec115[1]);
			fRec115[0] = fTemp180 - std::floor(fTemp180);
			int iTemp181 = std::max<int>(0, std::min<int>(int(65536.0 * fRec115[0]), 65535));
			double fTemp182 = 0.6382226054723966 * ftbl1TonewheelSIG1[iTemp181] + 0.7698518726768323 * ftbl0TonewheelSIG0[iTemp181];
			double fTemp183 = ((iTemp14) ? 0.0 : fConst58 + fRec116[1]);
			fRec116[0] = fTemp183 - std::floor(fTemp183);
			int iTemp184 = std::max<int>(0, std::min<int>(int(65536.0 * fRec116[0]), 65535));
			double fTemp185 = 0.12496018495733502 * ftbl0TonewheelSIG0[iTemp184];
			double fTemp186 = 0.9921617570615331 * ftbl1TonewheelSIG1[iTemp184];
			double fTemp187 = fTemp186 - fTemp185;
			double fTemp188 = ((iTemp14) ? 0.0 : fConst59 + fRec117[1]);
			fRec117[0] = fTemp188 - std::floor(fTemp188);
			int iTemp189 = std::max<int>(0, std::min<int>(int(65536.0 * fRec117[0]), 65535));
			double fTemp190 = 0.8863728711773318 * ftbl1TonewheelSIG1[iTemp189] + 0.46297206529212237 * ftbl0TonewheelSIG0[iTemp189];
			double fTemp191 = fTemp190 + 0.0316 * fRec38[0] * (0.9659536165763711 * fTemp187 - 0.2933104145049583 * fTemp182);
			fRec119[IOTA0 & 1023] = std::max<double>(fSlow80, fSlow21 * fRec119[(IOTA0 - 1) & 1023]);
			double fTemp192 = fRec119[(IOTA0 - iSlow81) & 1023];
			fVec21[0] = fTemp192;
			iRec118[0] = (iRec118[1] + 1) * (fTemp192 == 0.0);
			fRec120[0] = fTemp192 + fRec120[1] * double(fVec21[1] >= fTemp192);
			double fTemp193 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec120[0], 1.0) - fSlow24 * double(iRec118[0]));
			fRec121[0] = fSlow83 + fConst22 * fRec121[1];
			double fTemp194 = 1.0 - fRec121[0];
			double fTemp195 = ((iTemp14) ? 0.0 : fConst61 + fRec122[1]);
			fRec122[0] = fTemp195 - std::floor(fTemp195);
			int iTemp196 = std::max<int>(0, std::min<int>(int(65536.0 * fRec122[0]), 65535));
			double fTemp197 = 0.9984106487118631 * ftbl1TonewheelSIG1[iTemp196];
			double fTemp198 = ((iTemp14) ? 0.0 : fConst62 + fRec123[1]);
			fRec123[0] = fTemp198 - std::floor(fTemp198);
			int iTemp199 = std::max<int>(0, std::min<int>(int(65536.0 * fRec123[0]), 65535));
			double fTemp200 = 0.9058210008103694 * ftbl0TonewheelSIG0[iTemp199];
			double fTemp201 = 0.42366061239027253 * ftbl1TonewheelSIG1[iTemp199];
			double fTemp202 = fTemp201 - fTemp200;
			double fTemp203 = fRec38[0] * fTemp202;
			double fTemp204 = 0.05635757747416629 * ftbl0TonewheelSIG0[iTemp196];
			double fTemp205 = fTemp204 + 0.03359562768725328 * fTemp203 - fTemp197;
			fRec125[IOTA0 & 1023] = std::max<double>(fSlow84, fSlow21 * fRec125[(IOTA0 - 1) & 1023]);
			double fTemp206 = fRec125[(IOTA0 - iSlow85) & 1023];
			fVec22[0] = fTemp206;
			iRec124[0] = (iRec124[1] + 1) * (fTemp206 == 0.0);
			fRec126[0] = fTemp206 + fRec126[1] * double(fVec22[1] >= fTemp206);
			double fTemp207 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec126[0], 1.0) - fSlow24 * double(iRec124[0]));
			fRec127[0] = fSlow87 + fConst22 * fRec127[1];
			double fTemp208 = 1.0 - fRec127[0];
			double fTemp209 = ((iTemp14) ? 0.0 : fConst64 + fRec128[1]);
			fRec128[0] = fTemp209 - std::floor(fTemp209);
			int iTemp210 = std::max<int>(0, std::min<int>(int(65536.0 * fRec128[0]), 65535));
			double fTemp211 = 0.09275053863723011 * ftbl0TonewheelSIG0[iTemp210];
			double fTemp212 = ((iTemp14) ? 0.0 : fConst65 + fRec129[1]);
			fRec129[0] = fTemp212 - std::floor(fTemp212);
			int iTemp213 = std::max<int>(0, std::min<int>(int(65536.0 * fRec129[0]), 65535));
			double fTemp214 = 0.13684555600193227 * ftbl1TonewheelSIG1[iTemp213] + 0.9905923953890026 * ftbl0TonewheelSIG0[iTemp213];
			double fTemp215 = ((iTemp14) ? 0.0 : fConst66 + fRec130[1]);
			fRec130[0] = fTemp215 - std::floor(fTemp215);
			int iTemp216 = std::max<int>(0, std::min<int>(int(65536.0 * fRec130[0]), 65535));
			double fTemp217 = 0.999553264293708 * ftbl1TonewheelSIG1[iTemp216] + 0.029887653634782373 * ftbl0TonewheelSIG0[iTemp216];
			double fTemp218 = 0.9956893780604992 * ftbl1TonewheelSIG1[iTemp210];
			double fTemp219 = fTemp218 + 0.0316 * fRec38[0] * (0.15747581639880082 * fTemp217 + 0.2356540010587196 * fTemp214) - fTemp211;
			fRec132[IOTA0 & 1023] = std::max<double>(fSlow88, fSlow21 * fRec132[(IOTA0 - 1) & 1023]);
			double fTemp220 = fRec132[(IOTA0 - iSlow89) & 1023];
			fVec23[0] = fTemp220;
			iRec131[0] = (iRec131[1] + 1) * (fTemp220 == 0.0);
			fRec133[0] = fTemp220 + fRec133[1] * double(fVec23[1] >= fTemp220);
			double fTemp221 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec133[0], 1.0) - fSlow24 * double(iRec131[0]));
			fRec134[0] = fSlow91 + fConst22 * fRec134[1];
			double fTemp222 = 1.0 - fRec134[0];
			double fTemp223 = ((iTemp14) ? 0.0 : fConst68 + fRec135[1]);
			fRec135[0] = fTemp223 - std::floor(fTemp223);
			int iTemp224 = std::max<int>(0, std::min<int>(int(65536.0 * fRec135[0]), 65535));
			double fTemp225 = 0.913212223099466 * ftbl1TonewheelSIG1[iTemp224];
			double fTemp226 = 0.4074842764840517 * ftbl0TonewheelSIG0[iTemp224];
			double fTemp227 = fTemp226 - (fTemp225 + 0.0316 * fRec38[0] * (0.2359148234463646 * fTemp76 + 0.6674568160742638 * fTemp144));
			fRec137[IOTA0 & 1023] = std::max<double>(fSlow92, fSlow21 * fRec137[(IOTA0 - 1) & 1023]);
			double fTemp228 = fRec137[(IOTA0 - iSlow93) & 1023];
			fVec24[0] = fTemp228;
			iRec136[0] = (iRec136[1] + 1) * (fTemp228 == 0.0);
			fRec138[0] = fTemp228 + fRec138[1] * double(fVec24[1] >= fTemp228);
			double fTemp229 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec138[0], 1.0) - fSlow24 * double(iRec136[0]));
			fRec139[0] = fSlow95 + fConst22 * fRec139[1];
			double fTemp230 = 1.0 - fRec139[0];
			double fTemp231 = ((iTemp14) ? 0.0 : fConst70 + fRec140[1]);
			fRec140[0] = fTemp231 - std::floor(fTemp231);
			int iTemp232 = std::max<int>(0, std::min<int>(int(65536.0 * fRec140[0]), 65535));
			double fTemp233 = 0.5480098351559395 * ftbl0TonewheelSIG0[iTemp232];
			double fTemp234 = ((iTemp14) ? 0.0 : fConst71 + fRec141[1]);
			fRec141[0] = fTemp234 - std::floor(fTemp234);
			int iTemp235 = std::max<int>(0, std::min<int>(int(65536.0 * fRec141[0]), 65535));
			double fTemp236 = 0.0073342839809826905 * ftbl1TonewheelSIG1[iTemp235] + 0.9999731037775398 * ftbl0TonewheelSIG0[iTemp235];
			double fTemp237 = ((iTemp14) ? 0.0 : fConst72 + fRec142[1]);
			fRec142[0] = fTemp237 - std::floor(fTemp237);
			int iTemp238 = std::max<int>(0, std::min<int>(int(65536.0 * fRec142[0]), 65535));
			double fTemp239 = 0.9950440568066843 * ftbl0TonewheelSIG0[iTemp238];
			double fTemp240 = 0.09943502910793538 * ftbl1TonewheelSIG1[iTemp238];
			double fTemp241 = fTemp240 - fTemp239;
			double fTemp242 = 0.8364718886922381 * ftbl1TonewheelSIG1[iTemp232];
			double fTemp243 = fTemp242 + 0.0316 * fRec38[0] * (0.5872084543007077 * fTemp241 + 0.8588438748192857 * fTemp236) - fTemp233;
			fRec144[IOTA0 & 1023] = std::max<double>(fSlow96, fSlow21 * fRec144[(IOTA0 - 1) & 1023]);
			double fTemp244 = fRec144[(IOTA0 - iSlow97) & 1023];
			fVec25[0] = fTemp244;
			iRec143[0] = (iRec143[1] + 1) * (fTemp244 == 0.0);
			fRec145[0] = fTemp244 + fRec145[1] * double(fVec25[1] >= fTemp244);
			double fTemp245 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec145[0], 1.0) - fSlow24 * double(iRec143[0]));
			fRec146[0] = fSlow99 + fConst22 * fRec146[1];
			double fTemp246 = 1.0 - fRec146[0];
			double fTemp247 = ((iTemp14) ? 0.0 : fConst74 + fRec147[1]);
			fRec147[0] = fTemp247 - std::floor(fTemp247);
			int iTemp248 = std::max<int>(0, std::min<int>(int(65536.0 * fRec147[0]), 65535));
			double fTemp249 = 0.5938463051574933 * ftbl1TonewheelSIG1[iTemp248];
			double fTemp250 = ((iTemp14) ? 0.0 : fConst75 + fRec148[1]);
			fRec148[0] = fTemp250 - std::floor(fTemp250);
			int iTemp251 = std::max<int>(0, std::min<int>(int(65536.0 * fRec148[0]), 65535));
			double fTemp252 = 0.08886478321532126 * ftbl1TonewheelSIG1[iTemp251] + 0.9960436989932189 * ftbl0TonewheelSIG0[iTemp251];
			double fTemp253 = 0.8045785019814993 * ftbl0TonewheelSIG0[iTemp248];
			double fTemp254 = fTemp253 + 0.04069908438572748 * fRec38[0] * fTemp252 - fTemp249;
			fRec150[IOTA0 & 1023] = std::max<double>(fSlow100, fSlow21 * fRec150[(IOTA0 - 1) & 1023]);
			double fTemp255 = fRec150[(IOTA0 - iSlow101) & 1023];
			fVec26[0] = fTemp255;
			iRec149[0] = (iRec149[1] + 1) * (fTemp255 == 0.0);
			fRec151[0] = fTemp255 + fRec151[1] * double(fVec26[1] >= fTemp255);
			double fTemp256 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec151[0], 1.0) - fSlow24 * double(iRec149[0]));
			fRec152[0] = fSlow103 + fConst22 * fRec152[1];
			double fTemp257 = 1.0 - fRec152[0];
			double fTemp258 = ((iTemp14) ? 0.0 : fConst77 + fRec153[1]);
			fRec153[0] = fTemp258 - std::floor(fTemp258);
			int iTemp259 = std::max<int>(0, std::min<int>(int(65536.0 * fRec153[0]), 65535));
			double fTemp260 = 0.9932514251598912 * ftbl1TonewheelSIG1[iTemp259];
			double fTemp261 = ((iTemp14) ? 0.0 : fConst78 + fRec154[1]);
			fRec154[0] = fTemp261 - std::floor(fTemp261);
			int iTemp262 = std::max<int>(0, std::min<int>(int(65536.0 * fRec154[0]), 65535));
			double fTemp263 = 0.27527530028210756 * ftbl0TonewheelSIG0[iTemp262];
			double fTemp264 = 0.9613654399106489 * ftbl1TonewheelSIG1[iTemp262];
			double fTemp265 = fTemp264 - fTemp263;
			double fTemp266 = ((iTemp14) ? 0.0 : fConst79 + fRec155[1]);
			fRec155[0] = fTemp266 - std::floor(fTemp266);
			int iTemp267 = std::max<int>(0, std::min<int>(int(65536.0 * fRec155[0]), 65535));
			double fTemp268 = 0.562949355782946 * ftbl1TonewheelSIG1[iTemp267] + 0.8264913930728899 * ftbl0TonewheelSIG0[iTemp267];
			double fTemp269 = 0.11598106059975914 * ftbl0TonewheelSIG0[iTemp259];
			double fTemp270 = fTemp269 + 0.0316 * fRec38[0] * (0.6018234146831674 * fTemp268 + 0.0010241132185910828 * fTemp265) - fTemp260;
			fRec157[IOTA0 & 1023] = std::max<double>(fSlow104, fSlow21 * fRec157[(IOTA0 - 1) & 1023]);
			double fTemp271 = fRec157[(IOTA0 - iSlow105) & 1023];
			fVec27[0] = fTemp271;
			iRec156[0] = (iRec156[1] + 1) * (fTemp271 == 0.0);
			fRec158[0] = fTemp271 + fRec158[1] * double(fVec27[1] >= fTemp271);
			double fTemp272 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec158[0], 1.0) - fSlow24 * double(iRec156[0]));
			fRec159[0] = fSlow107 + fConst22 * fRec159[1];
			double fTemp273 = 1.0 - fRec159[0];
			double fTemp274 = ((iTemp14) ? 0.0 : fConst81 + fRec160[1]);
			fRec160[0] = fTemp274 - std::floor(fTemp274);
			int iTemp275 = std::max<int>(0, std::min<int>(int(65536.0 * fRec160[0]), 65535));
			double fTemp276 = 0.27142166069894946 * ftbl1TonewheelSIG1[iTemp275];
			double fTemp277 = ((iTemp14) ? 0.0 : fConst82 + fRec161[1]);
			fRec161[0] = fTemp277 - std::floor(fTemp277);
			int iTemp278 = std::max<int>(0, std::min<int>(int(65536.0 * fRec161[0]), 65535));
			double fTemp279 = 0.9804395561935539 * ftbl1TonewheelSIG1[iTemp278] + 0.19682041726148986 * ftbl0TonewheelSIG0[iTemp278];
			double fTemp280 = ((iTemp14) ? 0.0 : fConst83 + fRec162[1]);
			fRec162[0] = fTemp280 - std::floor(fTemp280);
			int iTemp281 = std::max<int>(0, std::min<int>(int(65536.0 * fRec162[0]), 65535));
			double fTemp282 = 0.9999237627631137 * ftbl1TonewheelSIG1[iTemp281];
			double fTemp283 = 0.012347820117591283 * ftbl0TonewheelSIG0[iTemp281];
			double fTemp284 = fTemp283 - fTemp282;
			double fTemp285 = 0.9624605353485536 * ftbl0TonewheelSIG0[iTemp275];
			double fTemp286 = fTemp285 + 0.0316 * fRec38[0] * (0.9225267971633002 * fTemp284 - 0.28893750924180495 * fTemp279) - fTemp276;
			fRec164[IOTA0 & 1023] = std::max<double>(fSlow108, fSlow21 * fRec164[(IOTA0 - 1) & 1023]);
			double fTemp287 = fRec164[(IOTA0 - iSlow109) & 1023];
			fVec28[0] = fTemp287;
			iRec163[0] = (iRec163[1] + 1) * (fTemp287 == 0.0);
			fRec165[0] = fTemp287 + fRec165[1] * double(fVec28[1] >= fTemp287);
			double fTemp288 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec165[0], 1.0) - fSlow24 * double(iRec163[0]));
			fRec166[0] = fSlow111 + fConst22 * fRec166[1];
			double fTemp289 = 1.0 - fRec166[0];
			double fTemp290 = 0.0316 * fRec38[0] * (0.2939493716112338 * fTemp90 - 0.39442181052436354 * fTemp66) - fTemp88;
			fRec168[IOTA0 & 1023] = std::max<double>(fSlow112, fSlow21 * fRec168[(IOTA0 - 1) & 1023]);
			double fTemp291 = fRec168[(IOTA0 - iSlow113) & 1023];
			fVec29[0] = fTemp291;
			iRec167[0] = (iRec167[1] + 1) * (fTemp291 == 0.0);
			fRec169[0] = fTemp291 + fRec169[1] * double(fVec29[1] >= fTemp291);
			double fTemp292 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec169[0], 1.0) - fSlow24 * double(iRec167[0]));
			fRec170[0] = fSlow115 + fConst22 * fRec170[1];
			double fTemp293 = 1.0 - fRec170[0];
			double fTemp294 = ((iTemp14) ? 0.0 : fConst86 + fRec171[1]);
			fRec171[0] = fTemp294 - std::floor(fTemp294);
			int iTemp295 = std::max<int>(0, std::min<int>(int(65536.0 * fRec171[0]), 65535));
			double fTemp296 = 0.9454774629266786 * ftbl1TonewheelSIG1[iTemp295];
			double fTemp297 = 0.3256875298468322 * ftbl0TonewheelSIG0[iTemp295];
			double fTemp298 = fTemp297 - fTemp296;
			double fTemp299 = ((iTemp14) ? 0.0 : fConst87 + fRec172[1]);
			fRec172[0] = fTemp299 - std::floor(fTemp299);
			int iTemp300 = std::max<int>(0, std::min<int>(int(65536.0 * fRec172[0]), 65535));
			double fTemp301 = 0.8492743565182271 * ftbl1TonewheelSIG1[iTemp300] + 0.5279517661307245 * ftbl0TonewheelSIG0[iTemp300];
			double fTemp302 = 0.0316 * fRec38[0] * (0.43673391723496024 * fTemp301 + 0.4867749553231988 * fTemp298) - fTemp38;
			fRec174[IOTA0 & 1023] = std::max<double>(fSlow116, fSlow21 * fRec174[(IOTA0 - 1) & 1023]);
			double fTemp303 = fRec174[(IOTA0 - iSlow117) & 1023];
			fVec30[0] = fTemp303;
			iRec173[0] = (iRec173[1] + 1) * (fTemp303 == 0.0);
			fRec175[0] = fTemp303 + fRec175[1] * double(fVec30[1] >= fTemp303);
			double fTemp304 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec175[0], 1.0) - fSlow24 * double(iRec173[0]));
			fRec176[0] = fSlow119 + fConst22 * fRec176[1];
			double fTemp305 = 1.0 - fRec176[0];
			double fTemp306 = ((iTemp14) ? 0.0 : fConst89 + fRec177[1]);
			fRec177[0] = fTemp306 - std::floor(fTemp306);
			int iTemp307 = std::max<int>(0, std::min<int>(int(65536.0 * fRec177[0]), 65535));
			double fTemp308 = 0.20859599908583948 * ftbl1TonewheelSIG1[iTemp307];
			double fTemp309 = fTemp218 - fTemp211;
			double fTemp310 = 0.9780018962994809 * ftbl0TonewheelSIG0[iTemp307];
			double fTemp311 = fTemp310 + 0.0316 * fRec38[0] * (0.20466811506321392 * fTemp217 + 0.23348462382091384 * fTemp309) - fTemp308;
			fRec179[IOTA0 & 1023] = std::max<double>(fSlow120, fSlow21 * fRec179[(IOTA0 - 1) & 1023]);
			double fTemp312 = fRec179[(IOTA0 - iSlow121) & 1023];
			fVec31[0] = fTemp312;
			iRec178[0] = (iRec178[1] + 1) * (fTemp312 == 0.0);
			fRec180[0] = fTemp312 + fRec180[1] * double(fVec31[1] >= fTemp312);
			double fTemp313 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec180[0], 1.0) - fSlow24 * double(iRec178[0]));
			fRec181[0] = fSlow123 + fConst22 * fRec181[1];
			double fTemp314 = 1.0 - fRec181[0];
			double fTemp315 = ((iTemp14) ? 0.0 : fConst91 + fRec182[1]);
			fRec182[0] = fTemp315 - std::floor(fTemp315);
			int iTemp316 = std::max<int>(0, std::min<int>(int(65536.0 * fRec182[0]), 65535));
			double fTemp317 = 0.36692462610448245 * ftbl0TonewheelSIG0[iTemp316];
			double fTemp318 = fTemp242 - fTemp233;
			double fTemp319 = 0.9302506752258155 * ftbl1TonewheelSIG1[iTemp316];
			double fTemp320 = fTemp319 + 0.0316 * fRec38[0] * (0.14715265659833676 * fTemp318 - 0.5279473174596205 * fTemp55) - fTemp317;
			fRec184[IOTA0 & 1023] = std::max<double>(fSlow124, fSlow21 * fRec184[(IOTA0 - 1) & 1023]);
			double fTemp321 = fRec184[(IOTA0 - iSlow125) & 1023];
			fVec32[0] = fTemp321;
			iRec183[0] = (iRec183[1] + 1) * (fTemp321 == 0.0);
			fRec185[0] = fTemp321 + fRec185[1] * double(fVec32[1] >= fTemp321);
			double fTemp322 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec185[0], 1.0) - fSlow24 * double(iRec183[0]));
			fRec186[0] = fSlow127 + fConst22 * fRec186[1];
			double fTemp323 = 1.0 - fRec186[0];
			double fTemp324 = fTemp269 - fTemp260;
			double fTemp325 = fRec38[0] * fTemp324;
			double fTemp326 = fTemp264 + 0.0552072235821106 * fTemp325 - fTemp263;
			fRec188[IOTA0 & 1023] = std::max<double>(fSlow128, fSlow21 * fRec188[(IOTA0 - 1) & 1023]);
			double fTemp327 = fRec188[(IOTA0 - iSlow129) & 1023];
			fVec33[0] = fTemp327;
			iRec187[0] = (iRec187[1] + 1) * (fTemp327 == 0.0);
			fRec189[0] = fTemp327 + fRec189[1] * double(fVec33[1] >= fTemp327);
			double fTemp328 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec189[0], 1.0) - fSlow24 * double(iRec187[0]));
			fRec190[0] = fSlow131 + fConst22 * fRec190[1];
			double fTemp329 = 1.0 - fRec190[0];
			double fTemp330 = ((iTemp14) ? 0.0 : fConst94 + fRec191[1]);
			fRec191[0] = fTemp330 - std::floor(fTemp330);
			int iTemp331 = std::max<int>(0, std::min<int>(int(65536.0 * fRec191[0]), 65535));
			double fTemp332 = 0.9795659786663815 * ftbl0TonewheelSIG0[iTemp331];
			double fTemp333 = 0.2011230803248953 * ftbl1TonewheelSIG1[iTemp331];
			double fTemp334 = fTemp333 - fTemp332;
			double fTemp335 = fTemp253 - fTemp249;
			double fTemp336 = fTemp114 + 0.0316 * fRec38[0] * (0.6461342227412388 * fTemp335 + 0.8411288327479269 * fTemp334);
			fRec193[IOTA0 & 1023] = std::max<double>(fSlow132, fSlow21 * fRec193[(IOTA0 - 1) & 1023]);
			double fTemp337 = fRec193[(IOTA0 - iSlow133) & 1023];
			fVec34[0] = fTemp337;
			iRec192[0] = (iRec192[1] + 1) * (fTemp337 == 0.0);
			fRec194[0] = fTemp337 + fRec194[1] * double(fVec34[1] >= fTemp337);
			double fTemp338 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec194[0], 1.0) - fSlow24 * double(iRec192[0]));
			fRec195[0] = fSlow135 + fConst22 * fRec195[1];
			double fTemp339 = 1.0 - fRec195[0];
			double fTemp340 = ((iTemp14) ? 0.0 : fConst96 + fRec196[1]);
			fRec196[0] = fTemp340 - std::floor(fTemp340);
			int iTemp341 = std::max<int>(0, std::min<int>(int(65536.0 * fRec196[0]), 65535));
			double fTemp342 = 0.3127253812548464 * ftbl1TonewheelSIG1[iTemp341] + 0.949843584975448 * ftbl0TonewheelSIG0[iTemp341];
			double fTemp343 = fTemp204 - fTemp197;
			double fTemp344 = 0.0316 * fRec38[0] * (0.08537023544340627 * fTemp202 + 0.5366384213921265 * fTemp343) - fTemp342;
			fRec198[IOTA0 & 1023] = std::max<double>(fSlow136, fSlow21 * fRec198[(IOTA0 - 1) & 1023]);
			double fTemp345 = fRec198[(IOTA0 - iSlow137) & 1023];
			fVec35[0] = fTemp345;
			iRec197[0] = (iRec197[1] + 1) * (fTemp345 == 0.0);
			fRec199[0] = fTemp345 + fRec199[1] * double(fVec35[1] >= fTemp345);
			double fTemp346 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec199[0], 1.0) - fSlow24 * double(iRec197[0]));
			fRec200[0] = fSlow139 + fConst22 * fRec200[1];
			double fTemp347 = 1.0 - fRec200[0];
			double fTemp348 = ((iTemp14) ? 0.0 : fConst98 + fRec201[1]);
			fRec201[0] = fTemp348 - std::floor(fTemp348);
			int iTemp349 = std::max<int>(0, std::min<int>(int(65536.0 * fRec201[0]), 65535));
			double fTemp350 = 0.4603356004271961 * ftbl1TonewheelSIG1[iTemp349] + 0.8877449718130387 * ftbl0TonewheelSIG0[iTemp349];
			double fTemp351 = ((iTemp14) ? 0.0 : fConst99 + fRec202[1]);
			fRec202[0] = fTemp351 - std::floor(fTemp351);
			int iTemp352 = std::max<int>(0, std::min<int>(int(65536.0 * fRec202[0]), 65535));
			double fTemp353 = 0.8711733990857894 * ftbl1TonewheelSIG1[iTemp352] + 0.49097546652079466 * ftbl0TonewheelSIG0[iTemp352];
			double fTemp354 = fTemp353 + 0.0316 * fRec38[0] * (0.9475827902642777 * fTemp350 + 0.4364923823850404 * fTemp187);
			fRec204[IOTA0 & 1023] = std::max<double>(fSlow140, fSlow21 * fRec204[(IOTA0 - 1) & 1023]);
			double fTemp355 = fRec204[(IOTA0 - iSlow141) & 1023];
			fVec36[0] = fTemp355;
			iRec203[0] = (iRec203[1] + 1) * (fTemp355 == 0.0);
			fRec205[0] = fTemp355 + fRec205[1] * double(fVec36[1] >= fTemp355);
			double fTemp356 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec205[0], 1.0) - fSlow24 * double(iRec203[0]));
			fRec206[0] = fSlow143 + fConst22 * fRec206[1];
			double fTemp357 = 1.0 - fRec206[0];
			double fTemp358 = ((iTemp14) ? 0.0 : fConst101 + fRec207[1]);
			fRec207[0] = fTemp358 - std::floor(fTemp358);
			int iTemp359 = std::max<int>(0, std::min<int>(int(65536.0 * fRec207[0]), 65535));
			double fTemp360 = 0.8764209335457853 * ftbl1TonewheelSIG1[iTemp359] + 0.481545789352097 * ftbl0TonewheelSIG0[iTemp359];
			double fTemp361 = fTemp175 - fTemp169;
			double fTemp362 = fTemp173 + 0.0316 * fRec38[0] * (0.15232359267611173 * fTemp361 + 0.3571031785577361 * fTemp360) - fTemp172;
			fRec209[IOTA0 & 1023] = std::max<double>(fSlow144, fSlow21 * fRec209[(IOTA0 - 1) & 1023]);
			double fTemp363 = fRec209[(IOTA0 - iSlow145) & 1023];
			fVec37[0] = fTemp363;
			iRec208[0] = (iRec208[1] + 1) * (fTemp363 == 0.0);
			fRec210[0] = fTemp363 + fRec210[1] * double(fVec37[1] >= fTemp363);
			double fTemp364 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec210[0], 1.0) - fSlow24 * double(iRec208[0]));
			fRec211[0] = fSlow147 + fConst22 * fRec211[1];
			double fTemp365 = 1.0 - fRec211[0];
			double fTemp366 = fTemp285 - fTemp276;
			double fTemp367 = fRec38[0] * fTemp366;
			double fTemp368 = 0.03790223836369624 * fTemp367 - fTemp279;
			fRec213[IOTA0 & 1023] = std::max<double>(fSlow148, fSlow21 * fRec213[(IOTA0 - 1) & 1023]);
			double fTemp369 = fRec213[(IOTA0 - iSlow149) & 1023];
			fVec38[0] = fTemp369;
			iRec212[0] = (iRec212[1] + 1) * (fTemp369 == 0.0);
			fRec214[0] = fTemp369 + fRec214[1] * double(fVec38[1] >= fTemp369);
			double fTemp370 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec214[0], 1.0) - fSlow24 * double(iRec212[0]));
			fRec215[0] = fSlow151 + fConst22 * fRec215[1];
			double fTemp371 = 1.0 - fRec215[0];
			double fTemp372 = fRec38[0] * fTemp41;
			double fTemp373 = fTemp297 - (fTemp296 + 0.03274717975388631 * fTemp372);
			fRec217[IOTA0 & 1023] = std::max<double>(fSlow152, fSlow21 * fRec217[(IOTA0 - 1) & 1023]);
			double fTemp374 = fRec217[(IOTA0 - iSlow153) & 1023];
			fVec39[0] = fTemp374;
			iRec216[0] = (iRec216[1] + 1) * (fTemp374 == 0.0);
			fRec218[0] = fTemp374 + fRec218[1] * double(fVec39[1] >= fTemp374);
			double fTemp375 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec218[0], 1.0) - fSlow24 * double(iRec216[0]));
			fRec219[0] = fSlow155 + fConst22 * fRec219[1];
			double fTemp376 = 1.0 - fRec219[0];
			double fTemp377 = fTemp226 - fTemp225;
			double fTemp378 = fRec38[0] * fTemp377;
			double fTemp379 = fTemp148 + 0.025437380887975453 * fTemp378 - fTemp147;
			fRec221[IOTA0 & 1023] = std::max<double>(fSlow156, fSlow21 * fRec221[(IOTA0 - 1) & 1023]);
			double fTemp380 = fRec221[(IOTA0 - iSlow157) & 1023];
			fVec40[0] = fTemp380;
			iRec220[0] = (iRec220[1] + 1) * (fTemp380 == 0.0);
			fRec222[0] = fTemp380 + fRec222[1] * double(fVec40[1] >= fTemp380);
			double fTemp381 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec222[0], 1.0) - fSlow24 * double(iRec220[0]));
			fRec223[0] = fSlow159 + fConst22 * fRec223[1];
			double fTemp382 = 1.0 - fRec223[0];
			double fTemp383 = ((iTemp14) ? 0.0 : fConst106 + fRec224[1]);
			fRec224[0] = fTemp383 - std::floor(fTemp383);
			int iTemp384 = std::max<int>(0, std::min<int>(int(65536.0 * fRec224[0]), 65535));
			double fTemp385 = 0.7217975809549547 * ftbl1TonewheelSIG1[iTemp384] + 0.6921042205676653 * ftbl0TonewheelSIG0[iTemp384];
			double fTemp386 = fTemp310 - fTemp308;
			double fTemp387 = fTemp217 + 0.0316 * fRec38[0] * (0.16521510682650842 * fTemp386 - 0.14639256503869547 * fTemp385);
			fRec226[IOTA0 & 1023] = std::max<double>(fSlow160, fSlow21 * fRec226[(IOTA0 - 1) & 1023]);
			double fTemp388 = fRec226[(IOTA0 - iSlow161) & 1023];
			fVec41[0] = fTemp388;
			iRec225[0] = (iRec225[1] + 1) * (fTemp388 == 0.0);
			fRec227[0] = fTemp388 + fRec227[1] * double(fVec41[1] >= fTemp388);
			double fTemp389 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec227[0], 1.0) - fSlow24 * double(iRec225[0]));
			fRec228[0] = fSlow163 + fConst22 * fRec228[1];
			double fTemp390 = 1.0 - fRec228[0];
			double fTemp391 = fTemp319 - fTemp317;
			double fTemp392 = 0.0316 * fRec38[0] * (0.9090463096035819 * fTemp318 + 0.8201556554122362 * fTemp391) - fTemp55;
			fRec230[IOTA0 & 1023] = std::max<double>(fSlow164, fSlow21 * fRec230[(IOTA0 - 1) & 1023]);
			double fTemp393 = fRec230[(IOTA0 - iSlow165) & 1023];
			fVec42[0] = fTemp393;
			iRec229[0] = (iRec229[1] + 1) * (fTemp393 == 0.0);
			fRec231[0] = fTemp393 + fRec231[1] * double(fVec42[1] >= fTemp393);
			double fTemp394 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec231[0], 1.0) - fSlow24 * double(iRec229[0]));
			fRec232[0] = fSlow167 + fConst22 * fRec232[1];
			double fTemp395 = 1.0 - fRec232[0];
			double fTemp396 = ((iTemp14) ? 0.0 : fConst109 + fRec233[1]);
			fRec233[0] = fTemp396 - std::floor(fTemp396);
			int iTemp397 = std::max<int>(0, std::min<int>(int(65536.0 * fRec233[0]), 65535));
			double fTemp398 = 0.4989758889373821 * ftbl1TonewheelSIG1[iTemp397];
			double fTemp399 = fRec38[0] * fTemp265;
			double fTemp400 = 0.8666158677633068 * ftbl0TonewheelSIG0[iTemp397];
			double fTemp401 = fTemp400 + 0.03793754359382729 * fTemp399 - fTemp398;
			fRec235[IOTA0 & 1023] = std::max<double>(fSlow168, fSlow21 * fRec235[(IOTA0 - 1) & 1023]);
			double fTemp402 = fRec235[(IOTA0 - iSlow169) & 1023];
			fVec43[0] = fTemp402;
			iRec234[0] = (iRec234[1] + 1) * (fTemp402 == 0.0);
			fRec236[0] = fTemp402 + fRec236[1] * double(fVec43[1] >= fTemp402);
			double fTemp403 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec236[0], 1.0) - fSlow24 * double(iRec234[0]));
			fRec237[0] = fSlow171 + fConst22 * fRec237[1];
			double fTemp404 = 1.0 - fRec237[0];
			double fTemp405 = fTemp252 + 0.0316 * fRec38[0] * (0.8641231547662755 * fTemp335 + 0.03871181118483946 * fTemp111);
			fRec239[IOTA0 & 1023] = std::max<double>(fSlow172, fSlow21 * fRec239[(IOTA0 - 1) & 1023]);
			double fTemp406 = fRec239[(IOTA0 - iSlow173) & 1023];
			fVec44[0] = fTemp406;
			iRec238[0] = (iRec238[1] + 1) * (fTemp406 == 0.0);
			fRec240[0] = fTemp406 + fRec240[1] * double(fVec44[1] >= fTemp406);
			double fTemp407 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec240[0], 1.0) - fSlow24 * double(iRec238[0]));
			fRec241[0] = fSlow175 + fConst22 * fRec241[1];
			double fTemp408 = 1.0 - fRec241[0];
			double fTemp409 = fTemp201 + 0.0316 * fRec38[0] * (0.9792857020147494 * fTemp343 - 0.6104541297936521 * fTemp342) - fTemp200;
			fRec243[IOTA0 & 1023] = std::max<double>(fSlow176, fSlow21 * fRec243[(IOTA0 - 1) & 1023]);
			double fTemp410 = fRec243[(IOTA0 - iSlow177) & 1023];
			fVec45[0] = fTemp410;
			iRec242[0] = (iRec242[1] + 1) * (fTemp410 == 0.0);
			fRec244[0] = fTemp410 + fRec244[1] * double(fVec45[1] >= fTemp410);
			double fTemp411 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec244[0], 1.0) - fSlow24 * double(iRec242[0]));
			fRec245[0] = fSlow179 + fConst22 * fRec245[1];
			double fTemp412 = 1.0 - fRec245[0];
			double fTemp413 = fRec38[0] * fTemp350;
			double fTemp414 = fTemp186 + 0.04797358306808456 * fTemp413 - fTemp185;
			fRec247[IOTA0 & 1023] = std::max<double>(fSlow180, fSlow21 * fRec247[(IOTA0 - 1) & 1023]);
			double fTemp415 = fRec247[(IOTA0 - iSlow181) & 1023];
			fVec46[0] = fTemp415;
			iRec246[0] = (iRec246[1] + 1) * (fTemp415 == 0.0);
			fRec248[0] = fTemp415 + fRec248[1] * double(fVec46[1] >= fTemp415);
			double fTemp416 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec248[0], 1.0) - fSlow24 * double(iRec246[0]));
			fRec249[0] = fSlow183 + fConst22 * fRec249[1];
			double fTemp417 = 1.0 - fRec249[0];
			double fTemp418 = ((iTemp14) ? 0.0 : fConst114 + fRec250[1]);
			fRec250[0] = fTemp418 - std::floor(fTemp418);
			int iTemp419 = std::max<int>(0, std::min<int>(int(65536.0 * fRec250[0]), 65535));
			double fTemp420 = 0.5210393437157135 * ftbl0TonewheelSIG0[iTemp419];
			double fTemp421 = 0.8535326603594607 * ftbl1TonewheelSIG1[iTemp419];
			double fTemp422 = fTemp421 + fTemp420;
			double fTemp423 = fTemp422 + 0.0316 * fRec38[0] * (0.32382628897903487 * fTemp422 - 0.21939938457217067 * fTemp279);
			fRec252[IOTA0 & 1023] = std::max<double>(fSlow184, fSlow21 * fRec252[(IOTA0 - 1) & 1023]);
			double fTemp424 = fRec252[(IOTA0 - iSlow185) & 1023];
			fVec47[0] = fTemp424;
			iRec251[0] = (iRec251[1] + 1) * (fTemp424 == 0.0);
			fRec253[0] = fTemp424 + fRec253[1] * double(fVec47[1] >= fTemp424);
			double fTemp425 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec253[0], 1.0) - fSlow24 * double(iRec251[0]));
			fRec254[0] = fSlow187 + fConst22 * fRec254[1];
			double fTemp426 = 1.0 - fRec254[0];
			double fTemp427 = fTemp89 + 0.0316 * fRec38[0] * (0.12527926880102314 * fTemp90 - 0.04206698763300665 * fTemp66) - fTemp85;
			fRec256[IOTA0 & 1023] = std::max<double>(fSlow188, fSlow21 * fRec256[(IOTA0 - 1) & 1023]);
			double fTemp428 = fRec256[(IOTA0 - iSlow189) & 1023];
			fVec48[0] = fTemp428;
			iRec255[0] = (iRec255[1] + 1) * (fTemp428 == 0.0);
			fRec257[0] = fTemp428 + fRec257[1] * double(fVec48[1] >= fTemp428);
			double fTemp429 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec257[0], 1.0) - fSlow24 * double(iRec255[0]));
			fRec258[0] = fSlow191 + fConst22 * fRec258[1];
			double fTemp430 = 1.0 - fRec258[0];
			double fTemp431 = -1.0 - 0.04349754534344498 * fRec38[0];
			fRec260[IOTA0 & 1023] = std::max<double>(fSlow192, fSlow21 * fRec260[(IOTA0 - 1) & 1023]);
			double fTemp432 = fRec260[(IOTA0 - iSlow193) & 1023];
			fVec49[0] = fTemp432;
			iRec259[0] = (iRec259[1] + 1) * (fTemp432 == 0.0);
			fRec261[0] = fTemp432 + fRec261[1] * double(fVec49[1] >= fTemp432);
			double fTemp433 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec261[0], 1.0) - fSlow24 * double(iRec259[0]));
			fRec262[0] = fSlow195 + fConst22 * fRec262[1];
			double fTemp434 = 1.0 - fRec262[0];
			double fTemp435 = fTemp77 + 0.0316 * fRec38[0] * (0.09225336559393327 * fTemp78 - 0.9758186214457965 * fTemp76) - fTemp73;
			fRec264[IOTA0 & 1023] = std::max<double>(fSlow196, fSlow21 * fRec264[(IOTA0 - 1) & 1023]);
			double fTemp436 = fRec264[(IOTA0 - iSlow197) & 1023];
			fVec50[0] = fTemp436;
			iRec263[0] = (iRec263[1] + 1) * (fTemp436 == 0.0);
			fRec265[0] = fTemp436 + fRec265[1] * double(fVec50[1] >= fTemp436);
			double fTemp437 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec265[0], 1.0) - fSlow24 * double(iRec263[0]));
			fRec266[0] = fSlow199 + fConst22 * fRec266[1];
			double fTemp438 = 1.0 - fRec266[0];
			double fTemp439 = 0.0316 * fRec38[0] * (0.9000975246963208 * fTemp217 - 0.4531921357411193 * fTemp385) - fTemp385;
			fRec268[IOTA0 & 1023] = std::max<double>(fSlow200, fSlow21 * fRec268[(IOTA0 - 1) & 1023]);
			double fTemp440 = fRec268[(IOTA0 - iSlow201) & 1023];
			fVec51[0] = fTemp440;
			iRec267[0] = (iRec267[1] + 1) * (fTemp440 == 0.0);
			fRec269[0] = fTemp440 + fRec269[1] * double(fVec51[1] >= fTemp440);
			double fTemp441 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec269[0], 1.0) - fSlow24 * double(iRec267[0]));
			fRec270[0] = fSlow203 + fConst22 * fRec270[1];
			double fTemp442 = 1.0 - fRec270[0];
			double fTemp443 = ((iTemp14) ? 0.0 : fConst120 + fRec271[1]);
			fRec271[0] = fTemp443 - std::floor(fTemp443);
			int iTemp444 = std::max<int>(0, std::min<int>(int(65536.0 * fRec271[0]), 65535));
			double fTemp445 = 0.6857083132517509 * ftbl1TonewheelSIG1[iTemp444] + 0.7278764380974553 * ftbl0TonewheelSIG0[iTemp444];
			double fTemp446 = fTemp400 - fTemp398;
			double fTemp447 = fTemp445 + 0.0316 * fRec38[0] * (0.971703339186206 * fTemp446 + 0.9076292914251098 * fTemp445);
			fRec273[IOTA0 & 1023] = std::max<double>(fSlow204, fSlow21 * fRec273[(IOTA0 - 1) & 1023]);
			double fTemp448 = fRec273[(IOTA0 - iSlow205) & 1023];
			fVec52[0] = fTemp448;
			iRec272[0] = (iRec272[1] + 1) * (fTemp448 == 0.0);
			fRec274[0] = fTemp448 + fRec274[1] * double(fVec52[1] >= fTemp448);
			double fTemp449 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec274[0], 1.0) - fSlow24 * double(iRec272[0]));
			fRec275[0] = fSlow207 + fConst22 * fRec275[1];
			double fTemp450 = 1.0 - fRec275[0];
			double fTemp451 = fTemp110 + 0.0316 * fRec38[0] * (0.15271918596408796 * fTemp114 + 0.5382577445343486 * fTemp111) - fTemp109;
			fRec277[IOTA0 & 1023] = std::max<double>(fSlow208, fSlow21 * fRec277[(IOTA0 - 1) & 1023]);
			double fTemp452 = fRec277[(IOTA0 - iSlow209) & 1023];
			fVec53[0] = fTemp452;
			iRec276[0] = (iRec276[1] + 1) * (fTemp452 == 0.0);
			fRec278[0] = fTemp452 + fRec278[1] * double(fVec53[1] >= fTemp452);
			double fTemp453 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec278[0], 1.0) - fSlow24 * double(iRec276[0]));
			fRec279[0] = fSlow211 + fConst22 * fRec279[1];
			double fTemp454 = 1.0 - fRec279[0];
			double fTemp455 = -1.0 - 0.024335154243305443 * fRec38[0];
			fRec281[IOTA0 & 1023] = std::max<double>(fSlow212, fSlow21 * fRec281[(IOTA0 - 1) & 1023]);
			double fTemp456 = fRec281[(IOTA0 - iSlow213) & 1023];
			fVec54[0] = fTemp456;
			iRec280[0] = (iRec280[1] + 1) * (fTemp456 == 0.0);
			fRec282[0] = fTemp456 + fRec282[1] * double(fVec54[1] >= fTemp456);
			double fTemp457 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec282[0], 1.0) - fSlow24 * double(iRec280[0]));
			double fTemp458 = ((iTemp14) ? 0.0 : fConst124 + fRec283[1]);
			fRec283[0] = fTemp458 - std::floor(fTemp458);
			int iTemp459 = std::max<int>(0, std::min<int>(int(65536.0 * fRec283[0]), 65535));
			double fTemp460 = 0.8707837682205855 * ftbl1TonewheelSIG1[iTemp459] + 0.49166617638755444 * ftbl0TonewheelSIG0[iTemp459];
			fRec284[0] = fSlow215 + fConst22 * fRec284[1];
			double fTemp461 = 1.0 - fRec284[0];
			double fTemp462 = fTemp350 + 0.03886918424008418 * fRec38[0] * fTemp187;
			fRec286[IOTA0 & 1023] = std::max<double>(fSlow216, fSlow21 * fRec286[(IOTA0 - 1) & 1023]);
			double fTemp463 = fRec286[(IOTA0 - iSlow217) & 1023];
			fVec55[0] = fTemp463;
			iRec285[0] = (iRec285[1] + 1) * (fTemp463 == 0.0);
			fRec287[0] = fTemp463 + fRec287[1] * double(fVec55[1] >= fTemp463);
			double fTemp464 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec287[0], 1.0) - fSlow24 * double(iRec285[0]));
			fRec288[0] = fSlow219 + fConst22 * fRec288[1];
			double fTemp465 = 1.0 - fRec288[0];
			double fTemp466 = fTemp77 + 0.0316 * fRec38[0] * (0.4469368527388724 * fTemp78 - 0.4332391171810741 * fTemp76) - fTemp73;
			fRec290[IOTA0 & 1023] = std::max<double>(fSlow220, fSlow21 * fRec290[(IOTA0 - 1) & 1023]);
			double fTemp467 = fRec290[(IOTA0 - iSlow221) & 1023];
			fVec56[0] = fTemp467;
			iRec289[0] = (iRec289[1] + 1) * (fTemp467 == 0.0);
			fRec291[0] = fTemp467 + fRec291[1] * double(fVec56[1] >= fTemp467);
			double fTemp468 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec291[0], 1.0) - fSlow24 * double(iRec289[0]));
			fRec292[0] = fSlow223 + fConst22 * fRec292[1];
			double fTemp469 = 1.0 - fRec292[0];
			double fTemp470 = fTemp126 + 0.029106767724272505 * fTemp128 - fTemp125;
			fRec294[IOTA0 & 1023] = std::max<double>(fSlow224, fSlow21 * fRec294[(IOTA0 - 1) & 1023]);
			double fTemp471 = fRec294[(IOTA0 - iSlow225) & 1023];
			fVec57[0] = fTemp471;
			iRec293[0] = (iRec293[1] + 1) * (fTemp471 == 0.0);
			fRec295[0] = fTemp471 + fRec295[1] * double(fVec57[1] >= fTemp471);
			double fTemp472 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec295[0], 1.0) - fSlow24 * double(iRec293[0]));
			fRec296[0] = fSlow227 + fConst22 * fRec296[1];
			double fTemp473 = 1.0 - fRec296[0];
			double fTemp474 = fTemp422 + 0.0316 * fRec38[0] * (0.7522581298326259 * fTemp422 - 0.5967876449758478 * fTemp279);
			fRec298[IOTA0 & 1023] = std::max<double>(fSlow228, fSlow21 * fRec298[(IOTA0 - 1) & 1023]);
			double fTemp475 = fRec298[(IOTA0 - iSlow229) & 1023];
			fVec58[0] = fTemp475;
			iRec297[0] = (iRec297[1] + 1) * (fTemp475 == 0.0);
			fRec299[0] = fTemp475 + fRec299[1] * double(fVec58[1] >= fTemp475);
			double fTemp476 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec299[0], 1.0) - fSlow24 * double(iRec297[0]));
			fRec300[0] = fSlow231 + fConst22 * fRec300[1];
			double fTemp477 = 1.0 - fRec300[0];
			double fTemp478 = fTemp162 - fTemp156;
			double fTemp479 = 0.0316 * fRec38[0] * (0.7739112714116345 * fTemp478 - 0.5589580835003289 * fTemp97) - fTemp97;
			fRec302[IOTA0 & 1023] = std::max<double>(fSlow232, fSlow21 * fRec302[(IOTA0 - 1) & 1023]);
			double fTemp480 = fRec302[(IOTA0 - iSlow233) & 1023];
			fVec59[0] = fTemp480;
			iRec301[0] = (iRec301[1] + 1) * (fTemp480 == 0.0);
			fRec303[0] = fTemp480 + fRec303[1] * double(fVec59[1] >= fTemp480);
			double fTemp481 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec303[0], 1.0) - fSlow24 * double(iRec301[0]));
			fRec304[0] = fSlow235 + fConst22 * fRec304[1];
			double fTemp482 = 1.0 - fRec304[0];
			double fTemp483 = fRec38[0] * fTemp90;
			double fTemp484 = fTemp89 + 0.022196987789592823 * fTemp483 - fTemp85;
			fRec306[IOTA0 & 1023] = std::max<double>(fSlow236, fSlow21 * fRec306[(IOTA0 - 1) & 1023]);
			double fTemp485 = fRec306[(IOTA0 - iSlow237) & 1023];
			fVec60[0] = fTemp485;
			iRec305[0] = (iRec305[1] + 1) * (fTemp485 == 0.0);
			fRec307[0] = fTemp485 + fRec307[1] * double(fVec60[1] >= fTemp485);
			double fTemp486 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec307[0], 1.0) - fSlow24 * double(iRec305[0]));
			fRec308[0] = fSlow239 + fConst22 * fRec308[1];
			double fTemp487 = 1.0 - fRec308[0];
			double fTemp488 = 0.0316 * fRec38[0] * (0.8218700289435219 * fTemp217 - 0.040925127468653955 * fTemp385) - fTemp385;
			fRec310[IOTA0 & 1023] = std::max<double>(fSlow240, fSlow21 * fRec310[(IOTA0 - 1) & 1023]);
			double fTemp489 = fRec310[(IOTA0 - iSlow241) & 1023];
			fVec61[0] = fTemp489;
			iRec309[0] = (iRec309[1] + 1) * (fTemp489 == 0.0);
			fRec311[0] = fTemp489 + fRec311[1] * double(fVec61[1] >= fTemp489);
			double fTemp490 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec311[0], 1.0) - fSlow24 * double(iRec309[0]));
			fRec312[0] = fSlow243 + fConst22 * fRec312[1];
			double fTemp491 = 1.0 - fRec312[0];
			double fTemp492 = -1.0 - 0.019491297554154883 * fRec38[0];
			fRec314[IOTA0 & 1023] = std::max<double>(fSlow244, fSlow21 * fRec314[(IOTA0 - 1) & 1023]);
			double fTemp493 = fRec314[(IOTA0 - iSlow245) & 1023];
			fVec62[0] = fTemp493;
			iRec313[0] = (iRec313[1] + 1) * (fTemp493 == 0.0);
			fRec315[0] = fTemp493 + fRec315[1] * double(fVec62[1] >= fTemp493);
			double fTemp494 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec315[0], 1.0) - fSlow24 * double(iRec313[0]));
			fRec316[0] = fSlow247 + fConst22 * fRec316[1];
			double fTemp495 = 1.0 - fRec316[0];
			double fTemp496 = fTemp495 * fTemp52;
			double fTemp497 = fTemp445 + 0.0316 * fRec38[0] * (0.08548989844712196 * fTemp445 + 0.25789658795838477 * fTemp265);
			fRec318[IOTA0 & 1023] = std::max<double>(fSlow248, fSlow21 * fRec318[(IOTA0 - 1) & 1023]);
			double fTemp498 = fRec318[(IOTA0 - iSlow249) & 1023];
			fVec63[0] = fTemp498;
			iRec317[0] = (iRec317[1] + 1) * (fTemp498 == 0.0);
			fRec319[0] = fTemp498 + fRec319[1] * double(fVec63[1] >= fTemp498);
			double fTemp499 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec319[0], 1.0) - fSlow24 * double(iRec317[0]));
			fRec320[0] = fSlow251 + fConst22 * fRec320[1];
			double fTemp500 = 1.0 - fRec320[0];
			double fTemp501 = 0.0316 * fRec38[0] * (0.8479572224678122 * fTemp202 - 0.015749484053230844 * fTemp342) - fTemp460;
			fRec322[IOTA0 & 1023] = std::max<double>(fSlow252, fSlow21 * fRec322[(IOTA0 - 1) & 1023]);
			double fTemp502 = fRec322[(IOTA0 - iSlow253) & 1023];
			fVec64[0] = fTemp502;
			iRec321[0] = (iRec321[1] + 1) * (fTemp502 == 0.0);
			fRec323[0] = fTemp502 + fRec323[1] * double(fVec64[1] >= fTemp502);
			double fTemp503 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec323[0], 1.0) - fSlow24 * double(iRec321[0]));
			fRec324[0] = fSlow255 + fConst22 * fRec324[1];
			double fTemp504 = 1.0 - fRec324[0];
			double fTemp505 = fTemp350 + 0.0316 * fRec38[0] * (0.19416401491616853 * fTemp353 + 0.42388780108012725 * fTemp350);
			fRec326[IOTA0 & 1023] = std::max<double>(fSlow256, fSlow21 * fRec326[(IOTA0 - 1) & 1023]);
			double fTemp506 = fRec326[(IOTA0 - iSlow257) & 1023];
			fVec65[0] = fTemp506;
			iRec325[0] = (iRec325[1] + 1) * (fTemp506 == 0.0);
			fRec327[0] = fTemp506 + fRec327[1] * double(fVec65[1] >= fTemp506);
			double fTemp507 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec327[0], 1.0) - fSlow24 * double(iRec325[0]));
			fRec328[0] = fSlow259 + fConst22 * fRec328[1];
			double fTemp508 = 1.0 - fRec328[0];
			double fTemp509 = fTemp126 + 0.04015464248991339 * fTemp128 - fTemp125;
			fRec330[IOTA0 & 1023] = std::max<double>(fSlow260, fSlow21 * fRec330[(IOTA0 - 1) & 1023]);
			double fTemp510 = fRec330[(IOTA0 - iSlow261) & 1023];
			fVec66[0] = fTemp510;
			iRec329[0] = (iRec329[1] + 1) * (fTemp510 == 0.0);
			fRec331[0] = fTemp510 + fRec331[1] * double(fVec66[1] >= fTemp510);
			double fTemp511 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec331[0], 1.0) - fSlow24 * double(iRec329[0]));
			fRec332[0] = fSlow263 + fConst22 * fRec332[1];
			double fTemp512 = 1.0 - fRec332[0];
			double fTemp513 = fTemp420 + fTemp421 + 0.019113329474651258 * fTemp367;
			fRec334[IOTA0 & 1023] = std::max<double>(fSlow264, fSlow21 * fRec334[(IOTA0 - 1) & 1023]);
			double fTemp514 = fRec334[(IOTA0 - iSlow265) & 1023];
			fVec67[0] = fTemp514;
			iRec333[0] = (iRec333[1] + 1) * (fTemp514 == 0.0);
			fRec335[0] = fTemp514 + fRec335[1] * double(fVec67[1] >= fTemp514);
			double fTemp515 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec335[0], 1.0) - fSlow24 * double(iRec333[0]));
			fRec336[0] = fSlow267 + fConst22 * fRec336[1];
			double fTemp516 = 1.0 - fRec336[0];
			fRec337[0] = fSlow269 + fConst10 * fRec337[1];
			double fTemp517 = fTemp460 + 0.0316 * fRec38[0] * (0.043824706383020384 * fTemp460 + 0.8189192212630587 * fTemp342);
			double fTemp518 = fRec68[(IOTA0 - iSlow270) & 1023];
			fVec68[0] = fTemp518;
			iRec338[0] = (iRec338[1] + 1) * (fTemp518 == 0.0);
			fRec339[0] = fTemp518 + fRec339[1] * double(fVec68[1] >= fTemp518);
			double fTemp519 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec339[0], 1.0) - fSlow24 * double(iRec338[0]));
			double fTemp520 = fTemp62 + 0.03979020352059015 * fRec38[0] * fTemp66;
			double fTemp521 = fRec157[(IOTA0 - iSlow271) & 1023];
			fVec69[0] = fTemp521;
			iRec340[0] = (iRec340[1] + 1) * (fTemp521 == 0.0);
			fRec341[0] = fTemp521 + fRec341[1] * double(fVec69[1] >= fTemp521);
			double fTemp522 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec341[0], 1.0) - fSlow24 * double(iRec340[0]));
			double fTemp523 = fTemp126 + 0.0316 * fRec38[0] * (0.30962039682344766 * fTemp174 + 0.2783113112382125 * fTemp127) - fTemp125;
			double fTemp524 = fRec62[(IOTA0 - iSlow272) & 1023];
			fVec70[0] = fTemp524;
			iRec342[0] = (iRec342[1] + 1) * (fTemp524 == 0.0);
			fRec343[0] = fTemp524 + fRec343[1] * double(fVec70[1] >= fTemp524);
			double fTemp525 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec343[0], 1.0) - fSlow24 * double(iRec342[0]));
			double fTemp526 = fTemp350 + 0.0316 * fRec38[0] * (0.8583999944239622 * fTemp187 + 0.9350352595793083 * fTemp353);
			double fTemp527 = fRec40[(IOTA0 - iSlow273) & 1023];
			fVec71[0] = fTemp527;
			iRec344[0] = (iRec344[1] + 1) * (fTemp527 == 0.0);
			fRec345[0] = fTemp527 + fRec345[1] * double(fVec71[1] >= fTemp527);
			double fTemp528 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec345[0], 1.0) - fSlow24 * double(iRec344[0]));
			double fTemp529 = fRec38[0] * fTemp114;
			double fTemp530 = fTemp110 + 0.021355515117923645 * fTemp529 - fTemp109;
			double fTemp531 = fRec74[(IOTA0 - iSlow274) & 1023];
			fVec72[0] = fTemp531;
			iRec346[0] = (iRec346[1] + 1) * (fTemp531 == 0.0);
			fRec347[0] = fTemp531 + fRec347[1] * double(fVec72[1] >= fTemp531);
			double fTemp532 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec347[0], 1.0) - fSlow24 * double(iRec346[0]));
			double fTemp533 = fTemp445 + 0.0316 * fRec38[0] * (0.3234305531332211 * fTemp446 + 0.9046833237644023 * fTemp445);
			double fTemp534 = fRec334[(IOTA0 - iSlow275) & 1023];
			fVec73[0] = fTemp534;
			iRec348[0] = (iRec348[1] + 1) * (fTemp534 == 0.0);
			fRec349[0] = fTemp534 + fRec349[1] * double(fVec73[1] >= fTemp534);
			double fTemp535 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec349[0], 1.0) - fSlow24 * double(iRec348[0]));
			double fTemp536 = fRec38[0] * fTemp391;
			double fTemp537 = 0.04837494533625868 * fTemp536 - fTemp52;
			double fTemp538 = fRec330[(IOTA0 - iSlow276) & 1023];
			fVec74[0] = fTemp538;
			iRec350[0] = (iRec350[1] + 1) * (fTemp538 == 0.0);
			fRec351[0] = fTemp538 + fRec351[1] * double(fVec74[1] >= fTemp538);
			double fTemp539 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec351[0], 1.0) - fSlow24 * double(iRec350[0]));
			double fTemp540 = fTemp77 + 0.0316 * fRec38[0] * (0.45032058421202237 * fTemp78 - 0.19901344494428486 * fTemp76) - fTemp73;
			double fTemp541 = fRec322[(IOTA0 - iSlow277) & 1023];
			fVec75[0] = fTemp541;
			iRec352[0] = (iRec352[1] + 1) * (fTemp541 == 0.0);
			fRec353[0] = fTemp541 + fRec353[1] * double(fVec75[1] >= fTemp541);
			double fTemp542 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec353[0], 1.0) - fSlow24 * double(iRec352[0]));
			double fTemp543 = fRec38[0] * fTemp111;
			double fTemp544 = fTemp252 + 0.04462596646234452 * fTemp543;
			double fTemp545 = fRec84[(IOTA0 - iSlow278) & 1023];
			fVec76[0] = fTemp545;
			iRec354[0] = (iRec354[1] + 1) * (fTemp545 == 0.0);
			fRec355[0] = fTemp545 + fRec355[1] * double(fVec76[1] >= fTemp545);
			double fTemp546 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec355[0], 1.0) - fSlow24 * double(iRec354[0]));
			double fTemp547 = fTemp297 - (fTemp296 + 0.0316 * fRec38[0] * (0.5625706842220097 * fTemp38 + 0.8908696530706948 * fTemp41));
			double fTemp548 = fRec239[(IOTA0 - iSlow279) & 1023];
			fVec77[0] = fTemp548;
			iRec356[0] = (iRec356[1] + 1) * (fTemp548 == 0.0);
			fRec357[0] = fTemp548 + fRec357[1] * double(fVec77[1] >= fTemp548);
			double fTemp549 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec357[0], 1.0) - fSlow24 * double(iRec356[0]));
			double fTemp550 = ((iTemp14) ? 0.0 : fConst148 + fRec358[1]);
			fRec358[0] = fTemp550 - std::floor(fTemp550);
			int iTemp551 = std::max<int>(0, std::min<int>(int(65536.0 * fRec358[0]), 65535));
			double fTemp552 = 0.5553332765714494 * ftbl1TonewheelSIG1[iTemp551];
			double fTemp553 = 0.8316278927094847 * ftbl0TonewheelSIG0[iTemp551];
			double fTemp554 = fTemp553 - fTemp552;
			double fTemp555 = fTemp190 + 0.0316 * fRec38[0] * (0.5614356710102584 * fTemp554 + 0.12666620927666372 * fTemp353);
			double fTemp556 = fRec174[(IOTA0 - iSlow280) & 1023];
			fVec78[0] = fTemp556;
			iRec359[0] = (iRec359[1] + 1) * (fTemp556 == 0.0);
			fRec360[0] = fTemp556 + fRec360[1] * double(fVec78[1] >= fTemp556);
			double fTemp557 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec360[0], 1.0) - fSlow24 * double(iRec359[0]));
			double fTemp558 = ((iTemp14) ? 0.0 : fConst150 + fRec361[1]);
			fRec361[0] = fTemp558 - std::floor(fTemp558);
			int iTemp559 = std::max<int>(0, std::min<int>(int(65536.0 * fRec361[0]), 65535));
			double fTemp560 = 0.4371504488583116 * ftbl1TonewheelSIG1[iTemp559] + 0.899388395001279 * ftbl0TonewheelSIG0[iTemp559];
			double fTemp561 = fTemp204 + 0.0316 * fRec38[0] * (0.9910352180304471 * fTemp560 - 0.7140572901043925 * fTemp342) - fTemp197;
			double fTemp562 = fRec168[(IOTA0 - iSlow281) & 1023];
			fVec79[0] = fTemp562;
			iRec362[0] = (iRec362[1] + 1) * (fTemp562 == 0.0);
			fRec363[0] = fTemp562 + fRec363[1] * double(fVec79[1] >= fTemp562);
			double fTemp563 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec363[0], 1.0) - fSlow24 * double(iRec362[0]));
			double fTemp564 = ((iTemp14) ? 0.0 : fConst152 + fRec364[1]);
			fRec364[0] = fTemp564 - std::floor(fTemp564);
			int iTemp565 = std::max<int>(0, std::min<int>(int(65536.0 * fRec364[0]), 65535));
			double fTemp566 = 0.5257235453218585 * ftbl0TonewheelSIG0[iTemp565];
			double fTemp567 = 0.8506554848434329 * ftbl1TonewheelSIG1[iTemp565];
			double fTemp568 = fTemp567 - fTemp566;
			double fTemp569 = fTemp253 + 0.0316 * fRec38[0] * (0.3246754774081637 * fTemp568 + 0.2693308923044242 * fTemp114) - fTemp249;
			double fTemp570 = fRec106[(IOTA0 - iSlow282) & 1023];
			fVec80[0] = fTemp570;
			iRec365[0] = (iRec365[1] + 1) * (fTemp570 == 0.0);
			fRec366[0] = fTemp570 + fRec366[1] * double(fVec80[1] >= fTemp570);
			double fTemp571 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec366[0], 1.0) - fSlow24 * double(iRec365[0]));
			double fTemp572 = fTemp269 + 0.0316 * fRec38[0] * (0.2748078649965464 * fTemp265 + 0.9872759227800998 * fTemp268) - fTemp260;
			double fTemp573 = fRec164[(IOTA0 - iSlow283) & 1023];
			fVec81[0] = fTemp573;
			iRec367[0] = (iRec367[1] + 1) * (fTemp573 == 0.0);
			fRec368[0] = fTemp573 + fRec368[1] * double(fVec81[1] >= fTemp573);
			double fTemp574 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec368[0], 1.0) - fSlow24 * double(iRec367[0]));
			double fTemp575 = fTemp218 + 0.0316 * fRec38[0] * (0.6913635090313619 * fTemp386 + 0.6769622229912784 * fTemp217) - fTemp211;
			double fTemp576 = fRec119[(IOTA0 - iSlow284) & 1023];
			fVec82[0] = fTemp576;
			iRec369[0] = (iRec369[1] + 1) * (fTemp576 == 0.0);
			fRec370[0] = fTemp576 + fRec370[1] * double(fVec82[1] >= fTemp576);
			double fTemp577 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec370[0], 1.0) - fSlow24 * double(iRec369[0]));
			double fTemp578 = fRec38[0] * fTemp149;
			double fTemp579 = fTemp226 + 0.017960467591922498 * fTemp578 - fTemp225;
			double fTemp580 = fRec125[(IOTA0 - iSlow285) & 1023];
			fVec83[0] = fTemp580;
			iRec371[0] = (iRec371[1] + 1) * (fTemp580 == 0.0);
			fRec372[0] = fTemp580 + fRec372[1] * double(fVec83[1] >= fTemp580);
			double fTemp581 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec372[0], 1.0) - fSlow24 * double(iRec371[0]));
			double fTemp582 = ((iTemp14) ? 0.0 : fConst157 + fRec373[1]);
			fRec373[0] = fTemp582 - std::floor(fTemp582);
			int iTemp583 = std::max<int>(0, std::min<int>(int(65536.0 * fRec373[0]), 65535));
			double fTemp584 = 0.7518682878650857 * ftbl1TonewheelSIG1[iTemp583] + 0.6593133380289106 * ftbl0TonewheelSIG0[iTemp583];
			double fTemp585 = fTemp301 + 0.0316 * fRec38[0] * (0.07483886430054554 * fTemp298 + 0.6204234410542995 * fTemp584);
			double fTemp586 = fRec150[(IOTA0 - iSlow286) & 1023];
			fVec84[0] = fTemp586;
			iRec374[0] = (iRec374[1] + 1) * (fTemp586 == 0.0);
			fRec375[0] = fTemp586 + fRec375[1] * double(fVec84[1] >= fTemp586);
			double fTemp587 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec375[0], 1.0) - fSlow24 * double(iRec374[0]));
			double fTemp588 = fTemp136 + 0.0316 * fRec38[0] * (0.10411054788710317 * fTemp102 + 0.38295830215065507 * fTemp478) - fTemp135;
			double fTemp589 = fRec144[(IOTA0 - iSlow287) & 1023];
			fVec85[0] = fTemp589;
			iRec376[0] = (iRec376[1] + 1) * (fTemp589 == 0.0);
			fRec377[0] = fTemp589 + fRec377[1] * double(fVec85[1] >= fTemp589);
			double fTemp590 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec377[0], 1.0) - fSlow24 * double(iRec376[0]));
			double fTemp591 = fTemp360 + 0.0316 * fRec38[0] * (0.8048417170139146 * fTemp174 + 0.4627773647735012 * fTemp361);
			double fTemp592 = fRec137[(IOTA0 - iSlow288) & 1023];
			fVec86[0] = fTemp592;
			iRec378[0] = (iRec378[1] + 1) * (fTemp592 == 0.0);
			fRec379[0] = fTemp592 + fRec379[1] * double(fVec86[1] >= fTemp592);
			double fTemp593 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec379[0], 1.0) - fSlow24 * double(iRec378[0]));
			double fTemp594 = ((iTemp14) ? 0.0 : fConst161 + fRec380[1]);
			fRec380[0] = fTemp594 - std::floor(fTemp594);
			int iTemp595 = std::max<int>(0, std::min<int>(int(65536.0 * fRec380[0]), 65535));
			double fTemp596 = 0.6741817124163315 * ftbl1TonewheelSIG1[iTemp595];
			double fTemp597 = 0.7385655141173211 * ftbl0TonewheelSIG0[iTemp595];
			double fTemp598 = fTemp597 - fTemp596;
			double fTemp599 = fTemp283 + 0.0316 * fRec38[0] * (0.046345677772478666 * fTemp366 + 0.01599199997872347 * fTemp598) - fTemp282;
			double fTemp600 = fRec132[(IOTA0 - iSlow289) & 1023];
			fVec87[0] = fTemp600;
			iRec381[0] = (iRec381[1] + 1) * (fTemp600 == 0.0);
			fRec382[0] = fTemp600 + fRec382[1] * double(fVec87[1] >= fTemp600);
			double fTemp601 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec382[0], 1.0) - fSlow24 * double(iRec381[0]));
			double fTemp602 = fTemp242 + 0.0316 * fRec38[0] * (0.5556137031744584 * fTemp236 + 0.36609772379597416 * fTemp241) - fTemp233;
			double fTemp603 = fRec112[(IOTA0 - iSlow290) & 1023];
			fVec88[0] = fTemp603;
			iRec383[0] = (iRec383[1] + 1) * (fTemp603 == 0.0);
			fRec384[0] = fTemp603 + fRec384[1] * double(fVec88[1] >= fTemp603);
			double fTemp604 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec384[0], 1.0) - fSlow24 * double(iRec383[0]));
			double fTemp605 = fTemp175 + 0.01907796941538177 * fTemp128 - fTemp169;
			double fTemp606 = fRec100[(IOTA0 - iSlow291) & 1023];
			fVec89[0] = fTemp606;
			iRec385[0] = (iRec385[1] + 1) * (fTemp606 == 0.0);
			fRec386[0] = fTemp606 + fRec386[1] * double(fVec89[1] >= fTemp606);
			double fTemp607 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec386[0], 1.0) - fSlow24 * double(iRec385[0]));
			double fTemp608 = fTemp285 + 0.0316 * fRec38[0] * (0.3650000449961226 * fTemp598 + 0.420008654891717 * fTemp422) - fTemp276;
			double fTemp609 = fRec179[(IOTA0 - iSlow292) & 1023];
			fVec90[0] = fTemp609;
			iRec387[0] = (iRec387[1] + 1) * (fTemp609 == 0.0);
			fRec388[0] = fTemp609 + fRec388[1] * double(fVec90[1] >= fTemp609);
			double fTemp610 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec388[0], 1.0) - fSlow24 * double(iRec387[0]));
			double fTemp611 = fTemp162 + 0.0316 * fRec38[0] * (0.7029603692208184 * fTemp137 + 0.9640460340524442 * fTemp161) - fTemp156;
			double fTemp612 = fRec184[(IOTA0 - iSlow293) & 1023];
			fVec91[0] = fTemp612;
			iRec389[0] = (iRec389[1] + 1) * (fTemp612 == 0.0);
			fRec390[0] = fTemp612 + fRec390[1] * double(fVec91[1] >= fTemp612);
			double fTemp613 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec390[0], 1.0) - fSlow24 * double(iRec389[0]));
			double fTemp614 = ((iTemp14) ? 0.0 : fConst167 + fRec391[1]);
			fRec391[0] = fTemp614 - std::floor(fTemp614);
			int iTemp615 = std::max<int>(0, std::min<int>(int(65536.0 * fRec391[0]), 65535));
			double fTemp616 = 0.9044156940371227 * ftbl1TonewheelSIG1[iTemp615] + 0.4266523788511551 * ftbl0TonewheelSIG0[iTemp615];
			double fTemp617 = 0.0316 * fRec38[0] * (0.36152986345405225 * fTemp90 - 0.574077818171645 * fTemp616) - fTemp88;
			double fTemp618 = fRec188[(IOTA0 - iSlow294) & 1023];
			fVec92[0] = fTemp618;
			iRec392[0] = (iRec392[1] + 1) * (fTemp618 == 0.0);
			fRec393[0] = fTemp618 + fRec393[1] * double(fVec92[1] >= fTemp618);
			double fTemp619 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec393[0], 1.0) - fSlow24 * double(iRec392[0]));
			double fTemp620 = 0.0316 * fRec38[0] * (0.9207233202832867 * fTemp298 + 0.9911887333146296 * fTemp584) - fTemp38;
			double fTemp621 = fRec193[(IOTA0 - iSlow295) & 1023];
			fVec93[0] = fTemp621;
			iRec394[0] = (iRec394[1] + 1) * (fTemp621 == 0.0);
			fRec395[0] = fTemp621 + fRec395[1] * double(fVec93[1] >= fTemp621);
			double fTemp622 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec395[0], 1.0) - fSlow24 * double(iRec394[0]));
			double fTemp623 = 0.0316 * fRec38[0] * (0.15286027816182468 * fTemp377 + 0.7205589631121256 * fTemp78) - fTemp76;
			double fTemp624 = fRec198[(IOTA0 - iSlow296) & 1023];
			fVec94[0] = fTemp624;
			iRec396[0] = (iRec396[1] + 1) * (fTemp624 == 0.0);
			fRec397[0] = fTemp624 + fRec397[1] * double(fVec94[1] >= fTemp624);
			double fTemp625 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec397[0], 1.0) - fSlow24 * double(iRec396[0]));
			double fTemp626 = fTemp310 + 0.0316 * fRec38[0] * (0.0820127468687133 * fTemp309 - 0.8851597931534343 * fTemp385) - fTemp308;
			double fTemp627 = fRec204[(IOTA0 - iSlow297) & 1023];
			fVec95[0] = fTemp627;
			iRec398[0] = (iRec398[1] + 1) * (fTemp627 == 0.0);
			fRec399[0] = fTemp627 + fRec399[1] * double(fVec95[1] >= fTemp627);
			double fTemp628 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec399[0], 1.0) - fSlow24 * double(iRec398[0]));
			double fTemp629 = fTemp319 + 0.0316 * fRec38[0] * (0.9788185898514712 * fTemp236 + 0.16982905973145535 * fTemp318) - fTemp317;
			double fTemp630 = fRec209[(IOTA0 - iSlow298) & 1023];
			fVec96[0] = fTemp630;
			iRec400[0] = (iRec400[1] + 1) * (fTemp630 == 0.0);
			fRec401[0] = fTemp630 + fRec401[1] * double(fVec96[1] >= fTemp630);
			double fTemp631 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec401[0], 1.0) - fSlow24 * double(iRec400[0]));
			double fTemp632 = fTemp264 + 0.0316 * fRec38[0] * (0.8488072791933519 * fTemp445 + 0.1969276579347934 * fTemp446) - fTemp263;
			double fTemp633 = fRec213[(IOTA0 - iSlow299) & 1023];
			fVec97[0] = fTemp633;
			iRec402[0] = (iRec402[1] + 1) * (fTemp633 == 0.0);
			fRec403[0] = fTemp633 + fRec403[1] * double(fVec97[1] >= fTemp633);
			double fTemp634 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec403[0], 1.0) - fSlow24 * double(iRec402[0]));
			double fTemp635 = fTemp114 + 0.0316 * fRec38[0] * (0.8527793175780971 * fTemp252 + 0.041318646566651296 * fTemp111);
			double fTemp636 = fRec94[(IOTA0 - iSlow300) & 1023];
			fVec98[0] = fTemp636;
			iRec404[0] = (iRec404[1] + 1) * (fTemp636 == 0.0);
			fRec405[0] = fTemp636 + fRec405[1] * double(fVec98[1] >= fTemp636);
			double fTemp637 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec405[0], 1.0) - fSlow24 * double(iRec404[0]));
			double fTemp638 = fRec38[0] * fTemp343;
			double fTemp639 = 0.0324892267361196 * fTemp638 - fTemp342;
			double fTemp640 = fRec56[(IOTA0 - iSlow301) & 1023];
			fVec99[0] = fTemp640;
			iRec406[0] = (iRec406[1] + 1) * (fTemp640 == 0.0);
			fRec407[0] = fTemp640 + fRec407[1] * double(fVec99[1] >= fTemp640);
			double fTemp641 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec407[0], 1.0) - fSlow24 * double(iRec406[0]));
			double fTemp642 = fTemp353 + 0.0316 * fRec38[0] * (0.9715999200270744 * fTemp350 - 0.3393712353135925 * fTemp182);
			double fTemp643 = fRec217[(IOTA0 - iSlow302) & 1023];
			fVec100[0] = fTemp643;
			iRec408[0] = (iRec408[1] + 1) * (fTemp643 == 0.0);
			fRec409[0] = fTemp643 + fRec409[1] * double(fVec100[1] >= fTemp643);
			double fTemp644 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec409[0], 1.0) - fSlow24 * double(iRec408[0]));
			double fTemp645 = fTemp173 + 0.028276871003332784 * fTemp128 - fTemp172;
			double fTemp646 = fRec221[(IOTA0 - iSlow303) & 1023];
			fVec101[0] = fTemp646;
			iRec410[0] = (iRec410[1] + 1) * (fTemp646 == 0.0);
			fRec411[0] = fTemp646 + fRec411[1] * double(fVec101[1] >= fTemp646);
			double fTemp647 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec411[0], 1.0) - fSlow24 * double(iRec410[0]));
			double fTemp648 = fRec38[0] * fTemp422;
			double fTemp649 = 0.04262605147013383 * fTemp648 - fTemp279;
			double fTemp650 = fRec226[(IOTA0 - iSlow304) & 1023];
			fVec102[0] = fTemp650;
			iRec412[0] = (iRec412[1] + 1) * (fTemp650 == 0.0);
			fRec413[0] = fTemp650 + fRec413[1] * double(fVec102[1] >= fTemp650);
			double fTemp651 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec413[0], 1.0) - fSlow24 * double(iRec412[0]));
			double fTemp652 = fTemp101 + 0.0316 * fRec38[0] * (0.6144701560624526 * fTemp478 - 0.27567895436732215 * fTemp97) - fTemp100;
			double fTemp653 = fRec230[(IOTA0 - iSlow305) & 1023];
			fVec103[0] = fTemp653;
			iRec414[0] = (iRec414[1] + 1) * (fTemp653 == 0.0);
			fRec415[0] = fTemp653 + fRec415[1] * double(fVec103[1] >= fTemp653);
			double fTemp654 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec415[0], 1.0) - fSlow24 * double(iRec414[0]));
			double fTemp655 = 0.0316 * fRec38[0] * (0.08877899026811065 * fTemp90 - 0.34556805526244716 * fTemp88) - fTemp66;
			double fTemp656 = fRec235[(IOTA0 - iSlow306) & 1023];
			fVec104[0] = fTemp656;
			iRec416[0] = (iRec416[1] + 1) * (fTemp656 == 0.0);
			fRec417[0] = fTemp656 + fRec417[1] * double(fVec104[1] >= fTemp656);
			double fTemp657 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec417[0], 1.0) - fSlow24 * double(iRec416[0]));
			double fTemp658 = fTemp148 + 0.03016400008411147 * fTemp378 - fTemp147;
			double fTemp659 = fRec243[(IOTA0 - iSlow307) & 1023];
			fVec105[0] = fTemp659;
			iRec418[0] = (iRec418[1] + 1) * (fTemp659 == 0.0);
			fRec419[0] = fTemp659 + fRec419[1] * double(fVec105[1] >= fTemp659);
			double fTemp660 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec419[0], 1.0) - fSlow24 * double(iRec418[0]));
			double fTemp661 = fRec38[0] * fTemp385;
			double fTemp662 = fTemp217 - 0.02775411382065795 * fTemp661;
			double fTemp663 = fRec247[(IOTA0 - iSlow308) & 1023];
			fVec106[0] = fTemp663;
			iRec420[0] = (iRec420[1] + 1) * (fTemp663 == 0.0);
			fRec421[0] = fTemp663 + fRec421[1] * double(fVec106[1] >= fTemp663);
			double fTemp664 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec421[0], 1.0) - fSlow24 * double(iRec420[0]));
			double fTemp665 = 0.0316 * fRec38[0] * (0.5955236837689881 * fTemp318 - 0.723066945138271 * fTemp52) - fTemp55;
			double fTemp666 = fRec89[(IOTA0 - iSlow309) & 1023];
			fVec107[0] = fTemp666;
			iRec422[0] = (iRec422[1] + 1) * (fTemp666 == 0.0);
			fRec423[0] = fTemp666 + fRec423[1] * double(fVec107[1] >= fTemp666);
			double fTemp667 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec423[0], 1.0) - fSlow24 * double(iRec422[0]));
			double fTemp668 = fTemp400 + 0.020464770127102384 * fTemp325 - fTemp398;
			double fTemp669 = fRec252[(IOTA0 - iSlow310) & 1023];
			fVec108[0] = fTemp669;
			iRec424[0] = (iRec424[1] + 1) * (fTemp669 == 0.0);
			fRec425[0] = fTemp669 + fRec425[1] * double(fVec108[1] >= fTemp669);
			double fTemp670 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec425[0], 1.0) - fSlow24 * double(iRec424[0]));
			double fTemp671 = fTemp201 + 0.0316 * fRec38[0] * (0.4459087215564068 * fTemp343 - 0.9926396824926087 * fTemp342) - fTemp200;
			double fTemp672 = fRec256[(IOTA0 - iSlow311) & 1023];
			fVec109[0] = fTemp672;
			iRec426[0] = (iRec426[1] + 1) * (fTemp672 == 0.0);
			fRec427[0] = fTemp672 + fRec427[1] * double(fVec109[1] >= fTemp672);
			double fTemp673 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec427[0], 1.0) - fSlow24 * double(iRec426[0]));
			double fTemp674 = fTemp186 + 0.026496950875671613 * fTemp413 - fTemp185;
			double fTemp675 = fRec260[(IOTA0 - iSlow312) & 1023];
			fVec110[0] = fTemp675;
			iRec428[0] = (iRec428[1] + 1) * (fTemp675 == 0.0);
			fRec429[0] = fTemp675 + fRec429[1] * double(fVec110[1] >= fTemp675);
			double fTemp676 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec429[0], 1.0) - fSlow24 * double(iRec428[0]));
			double fTemp677 = fRec38[0] * fTemp361;
			double fTemp678 = fTemp126 + 0.021666560602102255 * fTemp677 - fTemp125;
			double fTemp679 = fRec264[(IOTA0 - iSlow313) & 1023];
			fVec111[0] = fTemp679;
			iRec430[0] = (iRec430[1] + 1) * (fTemp679 == 0.0);
			fRec431[0] = fTemp679 + fRec431[1] * double(fVec111[1] >= fTemp679);
			double fTemp680 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec431[0], 1.0) - fSlow24 * double(iRec430[0]));
			double fTemp681 = fTemp422 + 0.0316 * fRec38[0] * (0.2689954012821545 * fTemp422 + 0.09185367206373485 * fTemp366);
			double fTemp682 = fRec268[(IOTA0 - iSlow314) & 1023];
			fVec112[0] = fTemp682;
			iRec432[0] = (iRec432[1] + 1) * (fTemp682 == 0.0);
			fRec433[0] = fTemp682 + fRec433[1] * double(fVec112[1] >= fTemp682);
			double fTemp683 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec433[0], 1.0) - fSlow24 * double(iRec432[0]));
			double fTemp684 = 0.0316 * fRec38[0] * (0.06906380424334202 * fTemp102 - 0.37782955763395876 * fTemp97) - fTemp97;
			double fTemp685 = fRec50[(IOTA0 - iSlow315) & 1023];
			fVec113[0] = fTemp685;
			iRec434[0] = (iRec434[1] + 1) * (fTemp685 == 0.0);
			fRec435[0] = fTemp685 + fRec435[1] * double(fVec113[1] >= fTemp685);
			double fTemp686 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec435[0], 1.0) - fSlow24 * double(iRec434[0]));
			double fTemp687 = fTemp89 + 0.0316 * fRec38[0] * (0.7558546882282826 * fTemp90 - 0.3722307553252904 * fTemp66) - fTemp85;
			double fTemp688 = fRec273[(IOTA0 - iSlow316) & 1023];
			fVec114[0] = fTemp688;
			iRec436[0] = (iRec436[1] + 1) * (fTemp688 == 0.0);
			fRec437[0] = fTemp688 + fRec437[1] * double(fVec114[1] >= fTemp688);
			double fTemp689 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec437[0], 1.0) - fSlow24 * double(iRec436[0]));
			double fTemp690 = fTemp77 + 0.0316 * fRec38[0] * (0.44688635249985964 * fTemp149 - 0.38142513863931526 * fTemp76) - fTemp73;
			double fTemp691 = fRec281[(IOTA0 - iSlow317) & 1023];
			fVec115[0] = fTemp691;
			iRec438[0] = (iRec438[1] + 1) * (fTemp691 == 0.0);
			fRec439[0] = fTemp691 + fRec439[1] * double(fVec115[1] >= fTemp691);
			double fTemp692 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec439[0], 1.0) - fSlow24 * double(iRec438[0]));
			double fTemp693 = fRec38[0] * fTemp386;
			double fTemp694 = 0.044464438271794283 * fTemp693 - fTemp385;
			double fTemp695 = fRec286[(IOTA0 - iSlow318) & 1023];
			fVec116[0] = fTemp695;
			iRec440[0] = (iRec440[1] + 1) * (fTemp695 == 0.0);
			fRec441[0] = fTemp695 + fRec441[1] * double(fVec116[1] >= fTemp695);
			double fTemp696 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec441[0], 1.0) - fSlow24 * double(iRec440[0]));
			double fTemp697 = -1.0 - 0.009302326095485479 * fRec38[0];
			double fTemp698 = fRec294[(IOTA0 - iSlow319) & 1023];
			fVec117[0] = fTemp698;
			iRec442[0] = (iRec442[1] + 1) * (fTemp698 == 0.0);
			fRec443[0] = fTemp698 + fRec443[1] * double(fVec117[1] >= fTemp698);
			double fTemp699 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec443[0], 1.0) - fSlow24 * double(iRec442[0]));
			double fTemp700 = fTemp445 + 0.0316 * fRec38[0] * (0.14546589087694883 * fTemp265 + 0.5652260201386525 * fTemp446);
			double fTemp701 = fRec298[(IOTA0 - iSlow320) & 1023];
			fVec118[0] = fTemp701;
			iRec444[0] = (iRec444[1] + 1) * (fTemp701 == 0.0);
			fRec445[0] = fTemp701 + fRec445[1] * double(fVec118[1] >= fTemp701);
			double fTemp702 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec445[0], 1.0) - fSlow24 * double(iRec444[0]));
			double fTemp703 = fTemp110 + 0.0316 * fRec38[0] * (0.07922520418651402 * fTemp111 + 0.013320338846824598 * fTemp114) - fTemp109;
			double fTemp704 = fRec302[(IOTA0 - iSlow321) & 1023];
			fVec119[0] = fTemp704;
			iRec446[0] = (iRec446[1] + 1) * (fTemp704 == 0.0);
			fRec447[0] = fTemp704 + fRec447[1] * double(fVec119[1] >= fTemp704);
			double fTemp705 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec447[0], 1.0) - fSlow24 * double(iRec446[0]));
			double fTemp706 = -1.0 - 0.043457395825709684 * fRec38[0];
			double fTemp707 = fRec326[(IOTA0 - iSlow322) & 1023];
			fVec120[0] = fTemp707;
			iRec448[0] = (iRec448[1] + 1) * (fTemp707 == 0.0);
			fRec449[0] = fTemp707 + fRec449[1] * double(fVec120[1] >= fTemp707);
			double fTemp708 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec449[0], 1.0) - fSlow24 * double(iRec448[0]));
			double fTemp709 = -1.0 - 0.008902822382334854 * fRec38[0];
			double fTemp710 = fRec306[(IOTA0 - iSlow323) & 1023];
			fVec121[0] = fTemp710;
			iRec450[0] = (iRec450[1] + 1) * (fTemp710 == 0.0);
			fRec451[0] = fTemp710 + fRec451[1] * double(fVec121[1] >= fTemp710);
			double fTemp711 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec451[0], 1.0) - fSlow24 * double(iRec450[0]));
			double fTemp712 = fRec38[0] * fTemp353;
			double fTemp713 = fTemp350 + 0.05166631335114508 * fTemp712;
			double fTemp714 = fRec44[(IOTA0 - iSlow324) & 1023];
			fVec122[0] = fTemp714;
			iRec452[0] = (iRec452[1] + 1) * (fTemp714 == 0.0);
			fRec453[0] = fTemp714 + fRec453[1] * double(fVec122[1] >= fTemp714);
			double fTemp715 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec453[0], 1.0) - fSlow24 * double(iRec452[0]));
			double fTemp716 = fTemp126 + 0.0316 * fRec38[0] * (0.13164493352451245 * fTemp174 + 0.9682041736705287 * fTemp127) - fTemp125;
			double fTemp717 = fRec290[(IOTA0 - iSlow325) & 1023];
			fVec123[0] = fTemp717;
			iRec454[0] = (iRec454[1] + 1) * (fTemp717 == 0.0);
			fRec455[0] = fTemp717 + fRec455[1] * double(fVec123[1] >= fTemp717);
			double fTemp718 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec455[0], 1.0) - fSlow24 * double(iRec454[0]));
			double fTemp719 = fTemp422 + 0.0316 * fRec38[0] * (0.6892087575104142 * fTemp422 + 0.9722027006307599 * fTemp366);
			double fTemp720 = fRec310[(IOTA0 - iSlow326) & 1023];
			fVec124[0] = fTemp720;
			iRec456[0] = (iRec456[1] + 1) * (fTemp720 == 0.0);
			fRec457[0] = fTemp720 + fRec457[1] * double(fVec124[1] >= fTemp720);
			double fTemp721 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec457[0], 1.0) - fSlow24 * double(iRec456[0]));
			double fTemp722 = 0.0316 * fRec38[0] * (0.9147260708887188 * fTemp102 - 0.702289571370784 * fTemp97) - fTemp97;
			double fTemp723 = fRec314[(IOTA0 - iSlow327) & 1023];
			fVec125[0] = fTemp723;
			iRec458[0] = (iRec458[1] + 1) * (fTemp723 == 0.0);
			fRec459[0] = fTemp723 + fRec459[1] * double(fVec125[1] >= fTemp723);
			double fTemp724 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec459[0], 1.0) - fSlow24 * double(iRec458[0]));
			double fTemp725 = fTemp89 + 0.0316 * fRec38[0] * (0.44651202124077827 * fTemp90 - 0.5988922905780782 * fTemp88) - fTemp85;
			double fTemp726 = fRec318[(IOTA0 - iSlow328) & 1023];
			fVec126[0] = fTemp726;
			iRec460[0] = (iRec460[1] + 1) * (fTemp726 == 0.0);
			fRec461[0] = fTemp726 + fRec461[1] * double(fVec126[1] >= fTemp726);
			double fTemp727 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec461[0], 1.0) - fSlow24 * double(iRec460[0]));
			double fTemp728 = -1.0 - 0.03089135661556211 * fRec38[0];
			double fTemp729 = fRec277[(IOTA0 - iSlow329) & 1023];
			fVec127[0] = fTemp729;
			iRec462[0] = (iRec462[1] + 1) * (fTemp729 == 0.0);
			fRec463[0] = fTemp729 + fRec463[1] * double(fVec127[1] >= fTemp729);
			double fTemp730 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec463[0], 1.0) - fSlow24 * double(iRec462[0]));
			double fTemp731 = -1.0 - 0.026615784080994492 * fRec38[0];
			double fTemp732 = fRec80[(IOTA0 - iSlow330) & 1023];
			fVec128[0] = fTemp732;
			iRec464[0] = (iRec464[1] + 1) * (fTemp732 == 0.0);
			fRec465[0] = fTemp732 + fRec465[1] * double(fVec128[1] >= fTemp732);
			double fTemp733 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec465[0], 1.0) - fSlow24 * double(iRec464[0]));
			fRec466[0] = fSlow332 + fConst10 * fRec466[1];
			double fTemp734 = fTemp52 + 0.0316 * fRec38[0] * (0.07754459822899662 * fTemp52 + 0.8352657734139939 * fTemp55);
			double fTemp735 = fRec68[(IOTA0 - iSlow333) & 1023];
			fVec129[0] = fTemp735;
			iRec467[0] = (iRec467[1] + 1) * (fTemp735 == 0.0);
			fRec468[0] = fTemp735 + fRec468[1] * double(fVec129[1] >= fTemp735);
			double fTemp736 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec468[0], 1.0) - fSlow24 * double(iRec467[0]));
			double fTemp737 = fTemp62 + 0.0316 * fRec38[0] * (0.5306613149368786 * fTemp616 + 0.590343614545418 * fTemp66);
			double fTemp738 = fRec119[(IOTA0 - iSlow334) & 1023];
			fVec130[0] = fTemp738;
			iRec469[0] = (iRec469[1] + 1) * (fTemp738 == 0.0);
			fRec470[0] = fTemp738 + fRec470[1] * double(fVec130[1] >= fTemp738);
			double fTemp739 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec470[0], 1.0) - fSlow24 * double(iRec469[0]));
			double fTemp740 = fTemp110 + 0.0316 * fRec38[0] * (0.9988737821258837 * fTemp252 + 0.6155406975522055 * fTemp111) - fTemp109;
			double fTemp741 = fRec62[(IOTA0 - iSlow335) & 1023];
			fVec131[0] = fTemp741;
			iRec471[0] = (iRec471[1] + 1) * (fTemp741 == 0.0);
			fRec472[0] = fTemp741 + fRec472[1] * double(fVec131[1] >= fTemp741);
			double fTemp742 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec472[0], 1.0) - fSlow24 * double(iRec471[0]));
			double fTemp743 = fTemp445 + 0.0316 * fRec38[0] * (0.36178898406069493 * fTemp265 + 0.7204489678188111 * fTemp446);
			double fTemp744 = fRec40[(IOTA0 - iSlow336) & 1023];
			fVec132[0] = fTemp744;
			iRec473[0] = (iRec473[1] + 1) * (fTemp744 == 0.0);
			fRec474[0] = fTemp744 + fRec474[1] * double(fVec132[1] >= fTemp744);
			double fTemp745 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec474[0], 1.0) - fSlow24 * double(iRec473[0]));
			double fTemp746 = 0.0316 * fRec38[0] * (0.7200039055423986 * fTemp386 - 0.26281638371074223 * fTemp385) - fTemp385;
			double fTemp747 = fRec74[(IOTA0 - iSlow337) & 1023];
			fVec133[0] = fTemp747;
			iRec475[0] = (iRec475[1] + 1) * (fTemp747 == 0.0);
			fRec476[0] = fTemp747 + fRec476[1] * double(fVec133[1] >= fTemp747);
			double fTemp748 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec476[0], 1.0) - fSlow24 * double(iRec475[0]));
			double fTemp749 = fRec38[0] * fTemp78;
			double fTemp750 = fTemp77 + 0.02101317741732892 * fTemp749 - fTemp73;
			double fTemp751 = fRec334[(IOTA0 - iSlow338) & 1023];
			fVec134[0] = fTemp751;
			iRec477[0] = (iRec477[1] + 1) * (fTemp751 == 0.0);
			fRec478[0] = fTemp751 + fRec478[1] * double(fVec134[1] >= fTemp751);
			double fTemp752 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec478[0], 1.0) - fSlow24 * double(iRec477[0]));
			double fTemp753 = 0.0316 * fRec38[0] * (0.5569616625652998 * fTemp298 - 0.8846908973027894 * fTemp41) - fTemp41;
			double fTemp754 = fRec330[(IOTA0 - iSlow339) & 1023];
			fVec135[0] = fTemp754;
			iRec479[0] = (iRec479[1] + 1) * (fTemp754 == 0.0);
			fRec480[0] = fTemp754 + fRec480[1] * double(fVec135[1] >= fTemp754);
			double fTemp755 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec480[0], 1.0) - fSlow24 * double(iRec479[0]));
			double fTemp756 = fTemp89 + 0.0316 * fRec38[0] * (0.10242128455865895 * fTemp90 - 0.41029152449118556 * fTemp88) - fTemp85;
			double fTemp757 = fRec326[(IOTA0 - iSlow340) & 1023];
			fVec136[0] = fTemp757;
			iRec481[0] = (iRec481[1] + 1) * (fTemp757 == 0.0);
			fRec482[0] = fTemp757 + fRec482[1] * double(fVec136[1] >= fTemp757);
			double fTemp758 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec482[0], 1.0) - fSlow24 * double(iRec481[0]));
			double fTemp759 = 0.0316 * fRec38[0] * (0.670267505767697 * fTemp478 - 0.26925153970660176 * fTemp97) - fTemp97;
			double fTemp760 = fRec322[(IOTA0 - iSlow341) & 1023];
			fVec137[0] = fTemp760;
			iRec483[0] = (iRec483[1] + 1) * (fTemp760 == 0.0);
			fRec484[0] = fTemp760 + fRec484[1] * double(fVec137[1] >= fTemp760);
			double fTemp761 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec484[0], 1.0) - fSlow24 * double(iRec483[0]));
			double fTemp762 = fTemp350 + 0.018070899783665665 * fTemp413;
			double fTemp763 = fRec314[(IOTA0 - iSlow342) & 1023];
			fVec138[0] = fTemp763;
			iRec485[0] = (iRec485[1] + 1) * (fTemp763 == 0.0);
			fRec486[0] = fTemp763 + fRec486[1] * double(fVec138[1] >= fTemp763);
			double fTemp764 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec486[0], 1.0) - fSlow24 * double(iRec485[0]));
			double fTemp765 = fTemp77 + 0.035579393829690525 * fTemp578 - fTemp73;
			double fTemp766 = fRec298[(IOTA0 - iSlow343) & 1023];
			fVec139[0] = fTemp766;
			iRec487[0] = (iRec487[1] + 1) * (fTemp766 == 0.0);
			fRec488[0] = fTemp766 + fRec488[1] * double(fVec139[1] >= fTemp766);
			double fTemp767 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec488[0], 1.0) - fSlow24 * double(iRec487[0]));
			double fTemp768 = 0.0316 * fRec38[0] * (0.4374965384522511 * fTemp318 + 0.024868297172361054 * fTemp391) - fTemp55;
			double fTemp769 = fRec256[(IOTA0 - iSlow344) & 1023];
			fVec140[0] = fTemp769;
			iRec489[0] = (iRec489[1] + 1) * (fTemp769 == 0.0);
			fRec490[0] = fTemp769 + fRec490[1] * double(fVec140[1] >= fTemp769);
			double fTemp770 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec490[0], 1.0) - fSlow24 * double(iRec489[0]));
			double fTemp771 = fTemp319 + 0.0316 * fRec38[0] * (0.4282410444575362 * fTemp236 + 0.8909794368009898 * fTemp318) - fTemp317;
			double fTemp772 = fRec56[(IOTA0 - iSlow345) & 1023];
			fVec141[0] = fTemp772;
			iRec491[0] = (iRec491[1] + 1) * (fTemp772 == 0.0);
			fRec492[0] = fTemp772 + fRec492[1] * double(fVec141[1] >= fTemp772);
			double fTemp773 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec492[0], 1.0) - fSlow24 * double(iRec491[0]));
			double fTemp774 = ((iTemp14) ? 0.0 : fConst218 + fRec493[1]);
			fRec493[0] = fTemp774 - std::floor(fTemp774);
			int iTemp775 = std::max<int>(0, std::min<int>(int(65536.0 * fRec493[0]), 65535));
			double fTemp776 = 0.24468341913096522 * ftbl0TonewheelSIG0[iTemp775];
			double fTemp777 = 0.9696030241301749 * ftbl1TonewheelSIG1[iTemp775];
			double fTemp778 = fTemp777 - fTemp776;
			double fTemp779 = fTemp310 + 0.0316 * fRec38[0] * (0.4782213192738709 * fTemp217 + 0.2688401395716937 * fTemp778) - fTemp308;
			double fTemp780 = fRec94[(IOTA0 - iSlow346) & 1023];
			fVec142[0] = fTemp780;
			iRec494[0] = (iRec494[1] + 1) * (fTemp780 == 0.0);
			fRec495[0] = fTemp780 + fRec495[1] * double(fVec142[1] >= fTemp780);
			double fTemp781 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec495[0], 1.0) - fSlow24 * double(iRec494[0]));
			double fTemp782 = 0.0316 * fRec38[0] * (0.6655130780854961 * fTemp78 + 0.9359128049582068 * fTemp149) - fTemp76;
			double fTemp783 = fRec213[(IOTA0 - iSlow347) & 1023];
			fVec143[0] = fTemp783;
			iRec496[0] = (iRec496[1] + 1) * (fTemp783 == 0.0);
			fRec497[0] = fTemp783 + fRec497[1] * double(fVec143[1] >= fTemp783);
			double fTemp784 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec497[0], 1.0) - fSlow24 * double(iRec496[0]));
			double fTemp785 = 0.0316 * fRec38[0] * (0.7534684774182097 * fTemp301 - 0.8809428801559989 * fTemp41) - fTemp38;
			double fTemp786 = fRec209[(IOTA0 - iSlow348) & 1023];
			fVec144[0] = fTemp786;
			iRec498[0] = (iRec498[1] + 1) * (fTemp786 == 0.0);
			fRec499[0] = fTemp786 + fRec499[1] * double(fVec144[1] >= fTemp786);
			double fTemp787 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec499[0], 1.0) - fSlow24 * double(iRec498[0]));
			double fTemp788 = 0.03884312976411093 * fTemp483 - fTemp88;
			double fTemp789 = fRec204[(IOTA0 - iSlow349) & 1023];
			fVec145[0] = fTemp789;
			iRec500[0] = (iRec500[1] + 1) * (fTemp789 == 0.0);
			fRec501[0] = fTemp789 + fRec501[1] * double(fVec145[1] >= fTemp789);
			double fTemp790 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec501[0], 1.0) - fSlow24 * double(iRec500[0]));
			double fTemp791 = fRec38[0] * fTemp137;
			double fTemp792 = fTemp162 + 0.044421137560835634 * fTemp791 - fTemp156;
			double fTemp793 = fRec198[(IOTA0 - iSlow350) & 1023];
			fVec146[0] = fTemp793;
			iRec502[0] = (iRec502[1] + 1) * (fTemp793 == 0.0);
			fRec503[0] = fTemp793 + fRec503[1] * double(fVec146[1] >= fTemp793);
			double fTemp794 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec503[0], 1.0) - fSlow24 * double(iRec502[0]));
			double fTemp795 = fTemp285 + 0.04436719193097961 * fTemp648 - fTemp276;
			double fTemp796 = fRec193[(IOTA0 - iSlow351) & 1023];
			fVec147[0] = fTemp796;
			iRec504[0] = (iRec504[1] + 1) * (fTemp796 == 0.0);
			fRec505[0] = fTemp796 + fRec505[1] * double(fVec147[1] >= fTemp796);
			double fTemp797 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec505[0], 1.0) - fSlow24 * double(iRec504[0]));
			double fTemp798 = fTemp175 + 0.0316 * fRec38[0] * (0.10458503947302233 * fTemp174 + 0.9912092714803293 * fTemp127) - fTemp169;
			double fTemp799 = fRec188[(IOTA0 - iSlow352) & 1023];
			fVec148[0] = fTemp799;
			iRec506[0] = (iRec506[1] + 1) * (fTemp799 == 0.0);
			fRec507[0] = fTemp799 + fRec507[1] * double(fVec148[1] >= fTemp799);
			double fTemp800 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec507[0], 1.0) - fSlow24 * double(iRec506[0]));
			double fTemp801 = fTemp190 + 0.0316 * fRec38[0] * (0.7933401227201102 * fTemp353 + 0.7138662297438714 * fTemp554);
			double fTemp802 = fRec184[(IOTA0 - iSlow353) & 1023];
			fVec149[0] = fTemp802;
			iRec508[0] = (iRec508[1] + 1) * (fTemp802 == 0.0);
			fRec509[0] = fTemp802 + fRec509[1] * double(fVec149[1] >= fTemp802);
			double fTemp803 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec509[0], 1.0) - fSlow24 * double(iRec508[0]));
			double fTemp804 = fTemp204 + 0.0316 * fRec38[0] * (0.6531928465155943 * fTemp202 - 0.5362713549075124 * fTemp342) - fTemp197;
			double fTemp805 = fRec179[(IOTA0 - iSlow354) & 1023];
			fVec150[0] = fTemp805;
			iRec510[0] = (iRec510[1] + 1) * (fTemp805 == 0.0);
			fRec511[0] = fTemp805 + fRec511[1] * double(fVec150[1] >= fTemp805);
			double fTemp806 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec511[0], 1.0) - fSlow24 * double(iRec510[0]));
			double fTemp807 = fTemp253 + 0.0316 * fRec38[0] * (0.3411965949253499 * fTemp568 + 0.272298913965642 * fTemp252) - fTemp249;
			double fTemp808 = fRec100[(IOTA0 - iSlow355) & 1023];
			fVec151[0] = fTemp808;
			iRec512[0] = (iRec512[1] + 1) * (fTemp808 == 0.0);
			fRec513[0] = fTemp808 + fRec513[1] * double(fVec151[1] >= fTemp808);
			double fTemp809 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec513[0], 1.0) - fSlow24 * double(iRec512[0]));
			double fTemp810 = fTemp269 + 0.0316 * fRec38[0] * (0.43435634609249973 * fTemp265 + 0.5031284304072869 * fTemp446) - fTemp260;
			double fTemp811 = fRec174[(IOTA0 - iSlow356) & 1023];
			fVec152[0] = fTemp811;
			iRec514[0] = (iRec514[1] + 1) * (fTemp811 == 0.0);
			fRec515[0] = fTemp811 + fRec515[1] * double(fVec152[1] >= fTemp811);
			double fTemp812 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec515[0], 1.0) - fSlow24 * double(iRec514[0]));
			double fTemp813 = fTemp242 + 0.0316 * fRec38[0] * (0.7821099121247244 * fTemp241 - 0.5882360955547483 * fTemp55) - fTemp233;
			double fTemp814 = fRec168[(IOTA0 - iSlow357) & 1023];
			fVec153[0] = fTemp814;
			iRec516[0] = (iRec516[1] + 1) * (fTemp814 == 0.0);
			fRec517[0] = fTemp814 + fRec517[1] * double(fVec153[1] >= fTemp814);
			double fTemp815 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec517[0], 1.0) - fSlow24 * double(iRec516[0]));
			double fTemp816 = fTemp301 + 0.0316 * fRec38[0] * (0.871489568889956 * fTemp298 - 0.99032934326533 * fTemp38);
			double fTemp817 = fRec112[(IOTA0 - iSlow358) & 1023];
			fVec154[0] = fTemp817;
			iRec518[0] = (iRec518[1] + 1) * (fTemp817 == 0.0);
			fRec519[0] = fTemp817 + fRec519[1] * double(fVec154[1] >= fTemp817);
			double fTemp818 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec519[0], 1.0) - fSlow24 * double(iRec518[0]));
			double fTemp819 = fTemp136 + 0.0316 * fRec38[0] * (0.1597436107986141 * fTemp102 + 0.2577066731573723 * fTemp161) - fTemp135;
			double fTemp820 = fRec125[(IOTA0 - iSlow359) & 1023];
			fVec155[0] = fTemp820;
			iRec520[0] = (iRec520[1] + 1) * (fTemp820 == 0.0);
			fRec521[0] = fTemp820 + fRec521[1] * double(fVec155[1] >= fTemp820);
			double fTemp821 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec521[0], 1.0) - fSlow24 * double(iRec520[0]));
			double fTemp822 = fTemp283 + 0.0316 * fRec38[0] * (0.7810044329289667 * fTemp598 - 0.30171639334275824 * fTemp279) - fTemp282;
			double fTemp823 = fRec150[(IOTA0 - iSlow360) & 1023];
			fVec156[0] = fTemp823;
			iRec522[0] = (iRec522[1] + 1) * (fTemp823 == 0.0);
			fRec523[0] = fTemp823 + fRec523[1] * double(fVec156[1] >= fTemp823);
			double fTemp824 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec523[0], 1.0) - fSlow24 * double(iRec522[0]));
			double fTemp825 = fTemp360 - 0.05546133551992971 * fRec38[0] * fTemp17;
			double fTemp826 = fRec157[(IOTA0 - iSlow361) & 1023];
			fVec157[0] = fTemp826;
			iRec524[0] = (iRec524[1] + 1) * (fTemp826 == 0.0);
			fRec525[0] = fTemp826 + fRec525[1] * double(fVec157[1] >= fTemp826);
			double fTemp827 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec525[0], 1.0) - fSlow24 * double(iRec524[0]));
			double fTemp828 = ((iTemp14) ? 0.0 : fConst235 + fRec526[1]);
			fRec526[0] = fTemp828 - std::floor(fTemp828);
			int iTemp829 = std::max<int>(0, std::min<int>(int(65536.0 * fRec526[0]), 65535));
			double fTemp830 = 0.7940166421942698 * ftbl0TonewheelSIG0[iTemp829];
			double fTemp831 = 0.607896020647065 * ftbl1TonewheelSIG1[iTemp829];
			double fTemp832 = fTemp831 + 0.0316 * fRec38[0] * (0.8119610257999739 * fTemp343 + 0.6672196526415064 * fTemp560) - fTemp830;
			double fTemp833 = fRec132[(IOTA0 - iSlow362) & 1023];
			fVec158[0] = fTemp833;
			iRec527[0] = (iRec527[1] + 1) * (fTemp833 == 0.0);
			fRec528[0] = fTemp833 + fRec528[1] * double(fVec158[1] >= fTemp833);
			double fTemp834 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec528[0], 1.0) - fSlow24 * double(iRec527[0]));
			double fTemp835 = fTemp333 + 0.0316 * fRec38[0] * (0.26466546896699583 * fTemp335 + 0.6558314288122347 * fTemp568) - fTemp332;
			double fTemp836 = fRec137[(IOTA0 - iSlow363) & 1023];
			fVec159[0] = fTemp836;
			iRec529[0] = (iRec529[1] + 1) * (fTemp836 == 0.0);
			fRec530[0] = fTemp836 + fRec530[1] * double(fVec159[1] >= fTemp836);
			double fTemp837 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec530[0], 1.0) - fSlow24 * double(iRec529[0]));
			double fTemp838 = 0.0316 * fRec38[0] * (0.5030497962288791 * fTemp190 + 0.18767479595771874 * fTemp554) - fTemp182;
			double fTemp839 = fRec144[(IOTA0 - iSlow364) & 1023];
			fVec160[0] = fTemp839;
			iRec531[0] = (iRec531[1] + 1) * (fTemp839 == 0.0);
			fRec532[0] = fTemp839 + fRec532[1] * double(fVec160[1] >= fTemp839);
			double fTemp840 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec532[0], 1.0) - fSlow24 * double(iRec531[0]));
			double fTemp841 = ((iTemp14) ? 0.0 : fConst239 + fRec533[1]);
			fRec533[0] = fTemp841 - std::floor(fTemp841);
			int iTemp842 = std::max<int>(0, std::min<int>(int(65536.0 * fRec533[0]), 65535));
			double fTemp843 = 0.40564755447114914 * ftbl0TonewheelSIG0[iTemp842];
			double fTemp844 = 0.9140295736744933 * ftbl1TonewheelSIG1[iTemp842];
			double fTemp845 = fTemp844 - fTemp843;
			double fTemp846 = fTemp226 + 0.0316 * fRec38[0] * (0.5243062499939697 * fTemp845 - 0.5353143494285177 * fTemp144) - fTemp225;
			double fTemp847 = fRec164[(IOTA0 - iSlow365) & 1023];
			fVec161[0] = fTemp847;
			iRec534[0] = (iRec534[1] + 1) * (fTemp847 == 0.0);
			fRec535[0] = fTemp847 + fRec535[1] * double(fVec161[1] >= fTemp847);
			double fTemp848 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec535[0], 1.0) - fSlow24 * double(iRec534[0]));
			double fTemp849 = fTemp218 + 0.004089555771320011 * fRec38[0] * fTemp778 - fTemp211;
			double fTemp850 = fRec106[(IOTA0 - iSlow366) & 1023];
			fVec162[0] = fTemp850;
			iRec536[0] = (iRec536[1] + 1) * (fTemp850 == 0.0);
			fRec537[0] = fTemp850 + fRec537[1] * double(fVec162[1] >= fTemp850);
			double fTemp851 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec537[0], 1.0) - fSlow24 * double(iRec536[0]));
			double fTemp852 = ((iTemp14) ? 0.0 : fConst242 + fRec538[1]);
			fRec538[0] = fTemp852 - std::floor(fTemp852);
			int iTemp853 = std::max<int>(0, std::min<int>(int(65536.0 * fRec538[0]), 65535));
			double fTemp854 = 0.07630559216571971 * ftbl1TonewheelSIG1[iTemp853];
			double fTemp855 = 0.997084478168344 * ftbl0TonewheelSIG0[iTemp853];
			double fTemp856 = fTemp855 - fTemp854;
			double fTemp857 = fTemp264 + 0.0316 * fRec38[0] * (0.7606050587855862 * fTemp445 + 0.835592124829418 * fTemp856) - fTemp263;
			double fTemp858 = fRec217[(IOTA0 - iSlow367) & 1023];
			fVec163[0] = fTemp858;
			iRec539[0] = (iRec539[1] + 1) * (fTemp858 == 0.0);
			fRec540[0] = fTemp858 + fRec540[1] * double(fVec163[1] >= fTemp858);
			double fTemp859 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec540[0], 1.0) - fSlow24 * double(iRec539[0]));
			double fTemp860 = fTemp114 + 0.0316 * fRec38[0] * (0.7924259171049925 * fTemp252 + 0.30343937388897757 * fTemp111);
			double fTemp861 = fRec221[(IOTA0 - iSlow368) & 1023];
			fVec164[0] = fTemp861;
			iRec541[0] = (iRec541[1] + 1) * (fTemp861 == 0.0);
			fRec542[0] = fTemp861 + fRec542[1] * double(fVec164[1] >= fTemp861);
			double fTemp862 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec542[0], 1.0) - fSlow24 * double(iRec541[0]));
			double fTemp863 = fTemp831 - fTemp830;
			double fTemp864 = 0.0316 * fRec38[0] * (0.06054402187874075 * fTemp863 + 0.5624498442375625 * fTemp343) - fTemp342;
			double fTemp865 = fRec226[(IOTA0 - iSlow369) & 1023];
			fVec165[0] = fTemp865;
			iRec543[0] = (iRec543[1] + 1) * (fTemp865 == 0.0);
			fRec544[0] = fTemp865 + fRec544[1] * double(fVec165[1] >= fTemp865);
			double fTemp866 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec544[0], 1.0) - fSlow24 * double(iRec543[0]));
			double fTemp867 = fTemp353 + 0.0316 * fRec38[0] * (0.22816245917897504 * fTemp350 + 0.3366140243958853 * fTemp187);
			double fTemp868 = fRec230[(IOTA0 - iSlow370) & 1023];
			fVec166[0] = fTemp868;
			iRec545[0] = (iRec545[1] + 1) * (fTemp868 == 0.0);
			fRec546[0] = fTemp868 + fRec546[1] * double(fVec166[1] >= fTemp868);
			double fTemp869 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec546[0], 1.0) - fSlow24 * double(iRec545[0]));
			double fTemp870 = fTemp173 + 0.02899835602027743 * fTemp128 - fTemp172;
			double fTemp871 = fRec235[(IOTA0 - iSlow371) & 1023];
			fVec167[0] = fTemp871;
			iRec547[0] = (iRec547[1] + 1) * (fTemp871 == 0.0);
			fRec548[0] = fTemp871 + fRec548[1] * double(fVec167[1] >= fTemp871);
			double fTemp872 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec548[0], 1.0) - fSlow24 * double(iRec547[0]));
			double fTemp873 = 0.0460266173718017 * fTemp367 - fTemp279;
			double fTemp874 = fRec239[(IOTA0 - iSlow372) & 1023];
			fVec168[0] = fTemp874;
			iRec549[0] = (iRec549[1] + 1) * (fTemp874 == 0.0);
			fRec550[0] = fTemp874 + fRec550[1] * double(fVec168[1] >= fTemp874);
			double fTemp875 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec550[0], 1.0) - fSlow24 * double(iRec549[0]));
			double fTemp876 = fRec38[0] * fTemp478;
			double fTemp877 = fTemp101 + 0.01914654352649814 * fTemp876 - fTemp100;
			double fTemp878 = fRec243[(IOTA0 - iSlow373) & 1023];
			fVec169[0] = fTemp878;
			iRec551[0] = (iRec551[1] + 1) * (fTemp878 == 0.0);
			fRec552[0] = fTemp878 + fRec552[1] * double(fVec169[1] >= fTemp878);
			double fTemp879 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec552[0], 1.0) - fSlow24 * double(iRec551[0]));
			double fTemp880 = 0.014104858919599794 * fTemp483 - fTemp66;
			double fTemp881 = fRec247[(IOTA0 - iSlow374) & 1023];
			fVec170[0] = fTemp881;
			iRec553[0] = (iRec553[1] + 1) * (fTemp881 == 0.0);
			fRec554[0] = fTemp881 + fRec554[1] * double(fVec170[1] >= fTemp881);
			double fTemp882 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec554[0], 1.0) - fSlow24 * double(iRec553[0]));
			double fTemp883 = fTemp297 - (fTemp296 + 0.013881320320456872 * fTemp372);
			double fTemp884 = fRec89[(IOTA0 - iSlow375) & 1023];
			fVec171[0] = fTemp884;
			iRec555[0] = (iRec555[1] + 1) * (fTemp884 == 0.0);
			fRec556[0] = fTemp884 + fRec556[1] * double(fVec171[1] >= fTemp884);
			double fTemp885 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec556[0], 1.0) - fSlow24 * double(iRec555[0]));
			double fTemp886 = fTemp148 + 0.0316 * fRec38[0] * (0.9316931571556779 * fTemp78 - 0.4515126954865991 * fTemp76) - fTemp147;
			double fTemp887 = fRec252[(IOTA0 - iSlow376) & 1023];
			fVec172[0] = fTemp887;
			iRec557[0] = (iRec557[1] + 1) * (fTemp887 == 0.0);
			fRec558[0] = fTemp887 + fRec558[1] * double(fVec172[1] >= fTemp887);
			double fTemp888 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec558[0], 1.0) - fSlow24 * double(iRec557[0]));
			double fTemp889 = fTemp217 + 0.0316 * fRec38[0] * (0.9422689709954284 * fTemp386 - 0.24876644482446864 * fTemp385);
			double fTemp890 = fRec84[(IOTA0 - iSlow377) & 1023];
			fVec173[0] = fTemp890;
			iRec559[0] = (iRec559[1] + 1) * (fTemp890 == 0.0);
			fRec560[0] = fTemp890 + fRec560[1] * double(fVec173[1] >= fTemp890);
			double fTemp891 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec560[0], 1.0) - fSlow24 * double(iRec559[0]));
			double fTemp892 = fRec38[0] * fTemp445;
			double fTemp893 = fTemp400 + 0.014247174423922844 * fTemp892 - fTemp398;
			double fTemp894 = fRec260[(IOTA0 - iSlow378) & 1023];
			fVec174[0] = fTemp894;
			iRec561[0] = (iRec561[1] + 1) * (fTemp894 == 0.0);
			fRec562[0] = fTemp894 + fRec562[1] * double(fVec174[1] >= fTemp894);
			double fTemp895 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec562[0], 1.0) - fSlow24 * double(iRec561[0]));
			double fTemp896 = fTemp252 + 0.0316 * fRec38[0] * (0.5950559735065326 * fTemp335 + 0.01136099705036031 * fTemp114);
			double fTemp897 = fRec264[(IOTA0 - iSlow379) & 1023];
			fVec175[0] = fTemp897;
			iRec563[0] = (iRec563[1] + 1) * (fTemp897 == 0.0);
			fRec564[0] = fTemp897 + fRec564[1] * double(fVec175[1] >= fTemp897);
			double fTemp898 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec564[0], 1.0) - fSlow24 * double(iRec563[0]));
			double fTemp899 = fRec38[0] * fTemp460;
			double fTemp900 = fTemp201 - (fTemp200 + 0.03000706752050319 * fTemp899);
			double fTemp901 = fRec268[(IOTA0 - iSlow380) & 1023];
			fVec176[0] = fTemp901;
			iRec565[0] = (iRec565[1] + 1) * (fTemp901 == 0.0);
			fRec566[0] = fTemp901 + fRec566[1] * double(fVec176[1] >= fTemp901);
			double fTemp902 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec566[0], 1.0) - fSlow24 * double(iRec565[0]));
			double fTemp903 = fTemp186 + 0.04955259049965244 * fTemp413 - fTemp185;
			double fTemp904 = fRec50[(IOTA0 - iSlow381) & 1023];
			fVec177[0] = fTemp904;
			iRec567[0] = (iRec567[1] + 1) * (fTemp904 == 0.0);
			fRec568[0] = fTemp904 + fRec568[1] * double(fVec177[1] >= fTemp904);
			double fTemp905 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec568[0], 1.0) - fSlow24 * double(iRec567[0]));
			double fTemp906 = fRec38[0] * fTemp174;
			double fTemp907 = fTemp126 + 0.030861337380115587 * fTemp906 - fTemp125;
			double fTemp908 = fRec273[(IOTA0 - iSlow382) & 1023];
			fVec178[0] = fTemp908;
			iRec569[0] = (iRec569[1] + 1) * (fTemp908 == 0.0);
			fRec570[0] = fTemp908 + fRec570[1] * double(fVec178[1] >= fTemp908);
			double fTemp909 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec570[0], 1.0) - fSlow24 * double(iRec569[0]));
			double fTemp910 = fTemp422 + 0.04796107789657618 * fTemp648;
			double fTemp911 = fRec80[(IOTA0 - iSlow383) & 1023];
			fVec179[0] = fTemp911;
			iRec571[0] = (iRec571[1] + 1) * (fTemp911 == 0.0);
			fRec572[0] = fTemp911 + fRec572[1] * double(fVec179[1] >= fTemp911);
			double fTemp912 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec572[0], 1.0) - fSlow24 * double(iRec571[0]));
			double fTemp913 = -1.0 - 0.03641535640055191 * fRec38[0];
			double fTemp914 = fRec281[(IOTA0 - iSlow384) & 1023];
			fVec180[0] = fTemp914;
			iRec573[0] = (iRec573[1] + 1) * (fTemp914 == 0.0);
			fRec574[0] = fTemp914 + fRec574[1] * double(fVec180[1] >= fTemp914);
			double fTemp915 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec574[0], 1.0) - fSlow24 * double(iRec573[0]));
			double fTemp916 = fTemp89 + 0.0316 * fRec38[0] * (0.3364593563528615 * fTemp90 - 0.5214687396437512 * fTemp88) - fTemp85;
			double fTemp917 = fRec286[(IOTA0 - iSlow385) & 1023];
			fVec181[0] = fTemp917;
			iRec575[0] = (iRec575[1] + 1) * (fTemp917 == 0.0);
			fRec576[0] = fTemp917 + fRec576[1] * double(fVec181[1] >= fTemp917);
			double fTemp918 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec576[0], 1.0) - fSlow24 * double(iRec575[0]));
			double fTemp919 = 0.0316 * fRec38[0] * (0.18200544462160906 * fTemp298 - 0.44492407023062697 * fTemp38) - fTemp41;
			double fTemp920 = fRec294[(IOTA0 - iSlow386) & 1023];
			fVec182[0] = fTemp920;
			iRec577[0] = (iRec577[1] + 1) * (fTemp920 == 0.0);
			fRec578[0] = fTemp920 + fRec578[1] * double(fVec182[1] >= fTemp920);
			double fTemp921 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec578[0], 1.0) - fSlow24 * double(iRec577[0]));
			double fTemp922 = 0.0316 * fRec38[0] * (0.6870885975513374 * fTemp386 - 0.26823529665125534 * fTemp385) - fTemp385;
			double fTemp923 = fRec302[(IOTA0 - iSlow387) & 1023];
			fVec183[0] = fTemp923;
			iRec579[0] = (iRec579[1] + 1) * (fTemp923 == 0.0);
			fRec580[0] = fTemp923 + fRec580[1] * double(fVec183[1] >= fTemp923);
			double fTemp924 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec580[0], 1.0) - fSlow24 * double(iRec579[0]));
			double fTemp925 = -1.0 - 0.021971505261780114 * fRec38[0];
			double fTemp926 = fRec306[(IOTA0 - iSlow388) & 1023];
			fVec184[0] = fTemp926;
			iRec581[0] = (iRec581[1] + 1) * (fTemp926 == 0.0);
			fRec582[0] = fTemp926 + fRec582[1] * double(fVec184[1] >= fTemp926);
			double fTemp927 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec582[0], 1.0) - fSlow24 * double(iRec581[0]));
			double fTemp928 = fTemp445 + 0.0316 * fRec38[0] * (0.110775443023158 * fTemp445 + 0.9070647939988703 * fTemp265);
			double fTemp929 = fRec44[(IOTA0 - iSlow389) & 1023];
			fVec185[0] = fTemp929;
			iRec583[0] = (iRec583[1] + 1) * (fTemp929 == 0.0);
			fRec584[0] = fTemp929 + fRec584[1] * double(fVec185[1] >= fTemp929);
			double fTemp930 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec584[0], 1.0) - fSlow24 * double(iRec583[0]));
			double fTemp931 = fTemp110 + 0.04507830352158654 * fTemp543 - fTemp109;
			double fTemp932 = fRec290[(IOTA0 - iSlow390) & 1023];
			fVec186[0] = fTemp932;
			iRec585[0] = (iRec585[1] + 1) * (fTemp932 == 0.0);
			fRec586[0] = fTemp932 + fRec586[1] * double(fVec186[1] >= fTemp932);
			double fTemp933 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec586[0], 1.0) - fSlow24 * double(iRec585[0]));
			double fTemp934 = 0.0316 * fRec38[0] * (0.2554592392334598 * fTemp202 - 0.526145324072786 * fTemp460) - fTemp460;
			double fTemp935 = fRec310[(IOTA0 - iSlow391) & 1023];
			fVec187[0] = fTemp935;
			iRec587[0] = (iRec587[1] + 1) * (fTemp935 == 0.0);
			fRec588[0] = fTemp935 + fRec588[1] * double(fVec187[1] >= fTemp935);
			double fTemp936 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec588[0], 1.0) - fSlow24 * double(iRec587[0]));
			double fTemp937 = fTemp126 + 0.0316 * fRec38[0] * (0.13157291529205395 * fTemp174 + 0.4576408594439272 * fTemp127) - fTemp125;
			double fTemp938 = fRec318[(IOTA0 - iSlow392) & 1023];
			fVec188[0] = fTemp938;
			iRec589[0] = (iRec589[1] + 1) * (fTemp938 == 0.0);
			fRec590[0] = fTemp938 + fRec590[1] * double(fVec188[1] >= fTemp938);
			double fTemp939 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec590[0], 1.0) - fSlow24 * double(iRec589[0]));
			double fTemp940 = fTemp422 + 0.0316 * fRec38[0] * (0.6633887195566786 * fTemp422 - 0.10648873710306361 * fTemp279);
			double fTemp941 = fRec277[(IOTA0 - iSlow393) & 1023];
			fVec189[0] = fTemp941;
			iRec591[0] = (iRec591[1] + 1) * (fTemp941 == 0.0);
			fRec592[0] = fTemp941 + fRec592[1] * double(fVec189[1] >= fTemp941);
			double fTemp942 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec592[0], 1.0) - fSlow24 * double(iRec591[0]));
			fRec593[0] = fSlow395 + fConst10 * fRec593[1];
			double fTemp943 = fTemp88 + 0.030844042165949943 * fTemp63;
			double fTemp944 = fRec56[(IOTA0 - iSlow396) & 1023];
			fVec190[0] = fTemp944;
			iRec594[0] = (iRec594[1] + 1) * (fTemp944 == 0.0);
			fRec595[0] = fTemp944 + fRec595[1] * double(fVec190[1] >= fTemp944);
			double fTemp945 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec595[0], 1.0) - fSlow24 * double(iRec594[0]));
			double fTemp946 = fTemp62 + 0.0316 * fRec38[0] * (0.06881027639610693 * fTemp616 + 0.9174840379209854 * fTemp88);
			double fTemp947 = fRec168[(IOTA0 - iSlow397) & 1023];
			fVec191[0] = fTemp947;
			iRec596[0] = (iRec596[1] + 1) * (fTemp947 == 0.0);
			fRec597[0] = fTemp947 + fRec597[1] * double(fVec191[1] >= fTemp947);
			double fTemp948 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec597[0], 1.0) - fSlow24 * double(iRec596[0]));
			double fTemp949 = fTemp77 + 0.040944639198191 * fTemp749 - fTemp73;
			double fTemp950 = fRec62[(IOTA0 - iSlow398) & 1023];
			fVec192[0] = fTemp950;
			iRec598[0] = (iRec598[1] + 1) * (fTemp950 == 0.0);
			fRec599[0] = fTemp950 + fRec599[1] * double(fVec192[1] >= fTemp950);
			double fTemp951 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec599[0], 1.0) - fSlow24 * double(iRec598[0]));
			double fTemp952 = 0.037967791038352884 * fRec38[0] * fTemp298 - fTemp41;
			double fTemp953 = fRec40[(IOTA0 - iSlow399) & 1023];
			fVec193[0] = fTemp953;
			iRec600[0] = (iRec600[1] + 1) * (fTemp953 == 0.0);
			fRec601[0] = fTemp953 + fRec601[1] * double(fVec193[1] >= fTemp953);
			double fTemp954 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec601[0], 1.0) - fSlow24 * double(iRec600[0]));
			double fTemp955 = fTemp89 + 0.03617240018915036 * fTemp483 - fTemp85;
			double fTemp956 = fRec68[(IOTA0 - iSlow400) & 1023];
			fVec194[0] = fTemp956;
			iRec602[0] = (iRec602[1] + 1) * (fTemp956 == 0.0);
			fRec603[0] = fTemp956 + fRec603[1] * double(fVec194[1] >= fTemp956);
			double fTemp957 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec603[0], 1.0) - fSlow24 * double(iRec602[0]));
			double fTemp958 = 0.0316 * fRec38[0] * (0.47638612502487376 * fTemp102 - 0.7388620457422803 * fTemp97) - fTemp97;
			double fTemp959 = fRec74[(IOTA0 - iSlow401) & 1023];
			fVec195[0] = fTemp959;
			iRec604[0] = (iRec604[1] + 1) * (fTemp959 == 0.0);
			fRec605[0] = fTemp959 + fRec605[1] * double(fVec195[1] >= fTemp959);
			double fTemp960 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec605[0], 1.0) - fSlow24 * double(iRec604[0]));
			double fTemp961 = fTemp422 + 0.0316 * fRec38[0] * (0.7670974876928085 * fTemp366 + 0.4443993132808828 * fTemp422);
			double fTemp962 = fRec334[(IOTA0 - iSlow402) & 1023];
			fVec196[0] = fTemp962;
			iRec606[0] = (iRec606[1] + 1) * (fTemp962 == 0.0);
			fRec607[0] = fTemp962 + fRec607[1] * double(fVec196[1] >= fTemp962);
			double fTemp963 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec607[0], 1.0) - fSlow24 * double(iRec606[0]));
			double fTemp964 = fTemp126 + 0.024267337357319778 * fTemp677 - fTemp125;
			double fTemp965 = fRec330[(IOTA0 - iSlow403) & 1023];
			fVec197[0] = fTemp965;
			iRec608[0] = (iRec608[1] + 1) * (fTemp965 == 0.0);
			fRec609[0] = fTemp965 + fRec609[1] * double(fVec197[1] >= fTemp965);
			double fTemp966 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec609[0], 1.0) - fSlow24 * double(iRec608[0]));
			double fTemp967 = 0.0316 * fRec38[0] * (0.46971096290508285 * fTemp102 + 0.6837902502593352 * fTemp478) - fTemp97;
			double fTemp968 = fRec302[(IOTA0 - iSlow404) & 1023];
			fVec198[0] = fTemp968;
			iRec610[0] = (iRec610[1] + 1) * (fTemp968 == 0.0);
			fRec611[0] = fTemp968 + fRec611[1] * double(fVec198[1] >= fTemp968);
			double fTemp969 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec611[0], 1.0) - fSlow24 * double(iRec610[0]));
			double fTemp970 = fTemp319 + 0.0316 * fRec38[0] * (0.6883625654973002 * fTemp318 - 0.25013223732275947 * fTemp55) - fTemp317;
			double fTemp971 = fRec230[(IOTA0 - iSlow405) & 1023];
			fVec199[0] = fTemp971;
			iRec612[0] = (iRec612[1] + 1) * (fTemp971 == 0.0);
			fRec613[0] = fTemp971 + fRec613[1] * double(fVec199[1] >= fTemp971);
			double fTemp972 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec613[0], 1.0) - fSlow24 * double(iRec612[0]));
			double fTemp973 = fTemp162 + 0.0316 * fRec38[0] * (0.30202631800057134 * fTemp102 + 0.07751172785356175 * fTemp161) - fTemp156;
			double fTemp974 = fRec94[(IOTA0 - iSlow406) & 1023];
			fVec200[0] = fTemp974;
			iRec614[0] = (iRec614[1] + 1) * (fTemp974 == 0.0);
			fRec615[0] = fTemp974 + fRec615[1] * double(fVec200[1] >= fTemp974);
			double fTemp975 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec615[0], 1.0) - fSlow24 * double(iRec614[0]));
			double fTemp976 = fTemp285 + 0.03574205587628822 * fRec38[0] * fTemp598 - fTemp276;
			double fTemp977 = fRec213[(IOTA0 - iSlow407) & 1023];
			fVec201[0] = fTemp977;
			iRec616[0] = (iRec616[1] + 1) * (fTemp977 == 0.0);
			fRec617[0] = fTemp977 + fRec617[1] * double(fVec201[1] >= fTemp977);
			double fTemp978 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec617[0], 1.0) - fSlow24 * double(iRec616[0]));
			double fTemp979 = fRec38[0] * fTemp334;
			double fTemp980 = fTemp253 + 0.014426551563794784 * fTemp979 - fTemp249;
			double fTemp981 = fRec193[(IOTA0 - iSlow408) & 1023];
			fVec202[0] = fTemp981;
			iRec618[0] = (iRec618[1] + 1) * (fTemp981 == 0.0);
			fRec619[0] = fTemp981 + fRec619[1] * double(fVec202[1] >= fTemp981);
			double fTemp982 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec619[0], 1.0) - fSlow24 * double(iRec618[0]));
			double fTemp983 = fRec38[0] * fTemp268;
			double fTemp984 = fTemp269 + 0.04466882333704271 * fTemp983 - fTemp260;
			double fTemp985 = fRec188[(IOTA0 - iSlow409) & 1023];
			fVec203[0] = fTemp985;
			iRec620[0] = (iRec620[1] + 1) * (fTemp985 == 0.0);
			fRec621[0] = fTemp985 + fRec621[1] * double(fVec203[1] >= fTemp985);
			double fTemp986 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec621[0], 1.0) - fSlow24 * double(iRec620[0]));
			double fTemp987 = fTemp242 + 0.0316 * fRec38[0] * (0.1519474193046335 * fTemp391 - 0.15007937652262626 * fTemp55) - fTemp233;
			double fTemp988 = fRec184[(IOTA0 - iSlow410) & 1023];
			fVec204[0] = fTemp988;
			iRec622[0] = (iRec622[1] + 1) * (fTemp988 == 0.0);
			fRec623[0] = fTemp988 + fRec623[1] * double(fVec204[1] >= fTemp988);
			double fTemp989 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec623[0], 1.0) - fSlow24 * double(iRec622[0]));
			double fTemp990 = fTemp218 + 0.0316 * fRec38[0] * (0.3516750540875364 * fTemp214 + 0.9894324491906445 * fTemp386) - fTemp211;
			double fTemp991 = fRec179[(IOTA0 - iSlow411) & 1023];
			fVec205[0] = fTemp991;
			iRec624[0] = (iRec624[1] + 1) * (fTemp991 == 0.0);
			fRec625[0] = fTemp991 + fRec625[1] * double(fVec205[1] >= fTemp991);
			double fTemp992 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec625[0], 1.0) - fSlow24 * double(iRec624[0]));
			double fTemp993 = fTemp226 + 0.0316 * fRec38[0] * (0.8177278098773968 * fTemp149 - 0.087717307938874 * fTemp144) - fTemp225;
			double fTemp994 = fRec100[(IOTA0 - iSlow412) & 1023];
			fVec206[0] = fTemp994;
			iRec626[0] = (iRec626[1] + 1) * (fTemp994 == 0.0);
			fRec627[0] = fTemp994 + fRec627[1] * double(fVec206[1] >= fTemp994);
			double fTemp995 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec627[0], 1.0) - fSlow24 * double(iRec626[0]));
			double fTemp996 = fTemp301 + 0.0316 * fRec38[0] * (0.332318739461698 * fTemp584 - 0.7514184729170665 * fTemp38);
			double fTemp997 = fRec174[(IOTA0 - iSlow413) & 1023];
			fVec207[0] = fTemp997;
			iRec628[0] = (iRec628[1] + 1) * (fTemp997 == 0.0);
			fRec629[0] = fTemp997 + fRec629[1] * double(fVec207[1] >= fTemp997);
			double fTemp998 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec629[0], 1.0) - fSlow24 * double(iRec628[0]));
			double fTemp999 = fRec38[0] * fTemp102;
			double fTemp1000 = fTemp136 + 0.03460304157767387 * fTemp999 - fTemp135;
			double fTemp1001 = fRec106[(IOTA0 - iSlow414) & 1023];
			fVec208[0] = fTemp1001;
			iRec630[0] = (iRec630[1] + 1) * (fTemp1001 == 0.0);
			fRec631[0] = fTemp1001 + fRec631[1] * double(fVec208[1] >= fTemp1001);
			double fTemp1002 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec631[0], 1.0) - fSlow24 * double(iRec630[0]));
			double fTemp1003 = ((iTemp14) ? 0.0 : fConst289 + fRec632[1]);
			fRec632[0] = fTemp1003 - std::floor(fTemp1003);
			int iTemp1004 = std::max<int>(0, std::min<int>(int(65536.0 * fRec632[0]), 65535));
			double fTemp1005 = 0.7477978959844837 * ftbl0TonewheelSIG0[iTemp1004];
			double fTemp1006 = 0.6639264317386222 * ftbl1TonewheelSIG1[iTemp1004];
			double fTemp1007 = fTemp1006 - fTemp1005;
			double fTemp1008 = fTemp283 + 0.0316 * fRec38[0] * (0.8994307556058629 * fTemp1007 + 0.51533134708734 * fTemp598) - fTemp282;
			double fTemp1009 = fRec164[(IOTA0 - iSlow415) & 1023];
			fVec209[0] = fTemp1009;
			iRec633[0] = (iRec633[1] + 1) * (fTemp1009 == 0.0);
			fRec634[0] = fTemp1009 + fRec634[1] * double(fVec209[1] >= fTemp1009);
			double fTemp1010 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec634[0], 1.0) - fSlow24 * double(iRec633[0]));
			double fTemp1011 = fTemp360 + 0.03862820612682263 * fTemp906;
			double fTemp1012 = fRec112[(IOTA0 - iSlow416) & 1023];
			fVec210[0] = fTemp1012;
			iRec635[0] = (iRec635[1] + 1) * (fTemp1012 == 0.0);
			fRec636[0] = fTemp1012 + fRec636[1] * double(fVec210[1] >= fTemp1012);
			double fTemp1013 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec636[0], 1.0) - fSlow24 * double(iRec635[0]));
			double fTemp1014 = ((iTemp14) ? 0.0 : fConst292 + fRec637[1]);
			fRec637[0] = fTemp1014 - std::floor(fTemp1014);
			int iTemp1015 = std::max<int>(0, std::min<int>(int(65536.0 * fRec637[0]), 65535));
			double fTemp1016 = 0.07963612106483207 * ftbl0TonewheelSIG0[iTemp1015];
			double fTemp1017 = 0.9968240006248582 * ftbl1TonewheelSIG1[iTemp1015];
			double fTemp1018 = fTemp1017 - fTemp1016;
			double fTemp1019 = 0.0316 * fRec38[0] * (0.6654499202340958 * fTemp353 + 0.6191199006570969 * fTemp1018) - fTemp182;
			double fTemp1020 = fRec119[(IOTA0 - iSlow417) & 1023];
			fVec211[0] = fTemp1020;
			iRec638[0] = (iRec638[1] + 1) * (fTemp1020 == 0.0);
			fRec639[0] = fTemp1020 + fRec639[1] * double(fVec211[1] >= fTemp1020);
			double fTemp1021 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec639[0], 1.0) - fSlow24 * double(iRec638[0]));
			double fTemp1022 = ((iTemp14) ? 0.0 : fConst294 + fRec640[1]);
			fRec640[0] = fTemp1022 - std::floor(fTemp1022);
			int iTemp1023 = std::max<int>(0, std::min<int>(int(65536.0 * fRec640[0]), 65535));
			double fTemp1024 = 0.07654514202148248 * ftbl1TonewheelSIG1[iTemp1023] + 0.9970661167810844 * ftbl0TonewheelSIG0[iTemp1023];
			double fTemp1025 = fTemp831 + 0.0316 * fRec38[0] * (0.4756526037599542 * fTemp1024 - 0.5047716558001412 * fTemp342) - fTemp830;
			double fTemp1026 = fRec125[(IOTA0 - iSlow418) & 1023];
			fVec212[0] = fTemp1026;
			iRec641[0] = (iRec641[1] + 1) * (fTemp1026 == 0.0);
			fRec642[0] = fTemp1026 + fRec642[1] * double(fVec212[1] >= fTemp1026);
			double fTemp1027 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec642[0], 1.0) - fSlow24 * double(iRec641[0]));
			double fTemp1028 = fTemp333 + 0.0316 * fRec38[0] * (0.8359466805140983 * fTemp114 + 0.5376266019011382 * fTemp335) - fTemp332;
			double fTemp1029 = fRec150[(IOTA0 - iSlow419) & 1023];
			fVec213[0] = fTemp1029;
			iRec643[0] = (iRec643[1] + 1) * (fTemp1029 == 0.0);
			fRec644[0] = fTemp1029 + fRec644[1] * double(fVec213[1] >= fTemp1029);
			double fTemp1030 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec644[0], 1.0) - fSlow24 * double(iRec643[0]));
			double fTemp1031 = ((iTemp14) ? 0.0 : fConst297 + fRec645[1]);
			fRec645[0] = fTemp1031 - std::floor(fTemp1031);
			int iTemp1032 = std::max<int>(0, std::min<int>(int(65536.0 * fRec645[0]), 65535));
			double fTemp1033 = 0.8138741886615695 * ftbl1TonewheelSIG1[iTemp1032];
			double fTemp1034 = 0.5810411388451527 * ftbl0TonewheelSIG0[iTemp1032];
			double fTemp1035 = fTemp1034 - fTemp1033;
			double fTemp1036 = fTemp777 + 0.0316 * fRec38[0] * (0.43264875422028126 * fTemp1035 + 0.23694859946408542 * fTemp386) - fTemp776;
			double fTemp1037 = fRec132[(IOTA0 - iSlow420) & 1023];
			fVec214[0] = fTemp1037;
			iRec646[0] = (iRec646[1] + 1) * (fTemp1037 == 0.0);
			fRec647[0] = fTemp1037 + fRec647[1] * double(fVec214[1] >= fTemp1037);
			double fTemp1038 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec647[0], 1.0) - fSlow24 * double(iRec646[0]));
			double fTemp1039 = fTemp236 + 0.0316 * fRec38[0] * (0.01873692142908112 * fTemp391 + 0.282720284692914 * fTemp318);
			double fTemp1040 = fRec144[(IOTA0 - iSlow421) & 1023];
			fVec215[0] = fTemp1040;
			iRec648[0] = (iRec648[1] + 1) * (fTemp1040 == 0.0);
			fRec649[0] = fTemp1040 + fRec649[1] * double(fVec215[1] >= fTemp1040);
			double fTemp1041 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec649[0], 1.0) - fSlow24 * double(iRec648[0]));
			double fTemp1042 = 0.0316 * fRec38[0] * (0.312204550311435 * fTemp377 - 0.6489523554846528 * fTemp32) - fTemp144;
			double fTemp1043 = fRec137[(IOTA0 - iSlow422) & 1023];
			fVec216[0] = fTemp1043;
			iRec650[0] = (iRec650[1] + 1) * (fTemp1043 == 0.0);
			fRec651[0] = fTemp1043 + fRec651[1] * double(fVec216[1] >= fTemp1043);
			double fTemp1044 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec651[0], 1.0) - fSlow24 * double(iRec650[0]));
			double fTemp1045 = fTemp855 + 0.0316 * fRec38[0] * (0.8511423739680595 * fTemp268 + 0.7873257346516311 * fTemp265) - fTemp854;
			double fTemp1046 = fRec157[(IOTA0 - iSlow423) & 1023];
			fVec217[0] = fTemp1046;
			iRec652[0] = (iRec652[1] + 1) * (fTemp1046 == 0.0);
			fRec653[0] = fTemp1046 + fRec653[1] * double(fVec217[1] >= fTemp1046);
			double fTemp1047 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec653[0], 1.0) - fSlow24 * double(iRec652[0]));
			double fTemp1048 = fTemp204 + 0.0316 * fRec38[0] * (0.8491599874396343 * fTemp202 - 0.8721289030600019 * fTemp342) - fTemp197;
			double fTemp1049 = fRec198[(IOTA0 - iSlow424) & 1023];
			fVec218[0] = fTemp1049;
			iRec654[0] = (iRec654[1] + 1) * (fTemp1049 == 0.0);
			fRec655[0] = fTemp1049 + fRec655[1] * double(fVec218[1] >= fTemp1049);
			double fTemp1050 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec655[0], 1.0) - fSlow24 * double(iRec654[0]));
			double fTemp1051 = fTemp190 + 0.0316 * fRec38[0] * (0.9004834706511247 * fTemp353 + 0.7300692102498942 * fTemp187);
			double fTemp1052 = fRec204[(IOTA0 - iSlow425) & 1023];
			fVec219[0] = fTemp1052;
			iRec656[0] = (iRec656[1] + 1) * (fTemp1052 == 0.0);
			fRec657[0] = fTemp1052 + fRec657[1] * double(fVec219[1] >= fTemp1052);
			double fTemp1053 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec657[0], 1.0) - fSlow24 * double(iRec656[0]));
			double fTemp1054 = fTemp175 + 0.0316 * fRec38[0] * (0.679540564880881 * fTemp174 - 0.1999907482349954 * fTemp17) - fTemp169;
			double fTemp1055 = fRec209[(IOTA0 - iSlow426) & 1023];
			fVec220[0] = fTemp1055;
			iRec658[0] = (iRec658[1] + 1) * (fTemp1055 == 0.0);
			fRec659[0] = fTemp1055 + fRec659[1] * double(fVec220[1] >= fTemp1055);
			double fTemp1056 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec659[0], 1.0) - fSlow24 * double(iRec658[0]));
			double fTemp1057 = 0.0316 * fRec38[0] * (0.1844282755846507 * fTemp301 - 0.35758630272903247 * fTemp41) - fTemp38;
			double fTemp1058 = fRec217[(IOTA0 - iSlow427) & 1023];
			fVec221[0] = fTemp1058;
			iRec660[0] = (iRec660[1] + 1) * (fTemp1058 == 0.0);
			fRec661[0] = fTemp1058 + fRec661[1] * double(fVec221[1] >= fTemp1058);
			double fTemp1059 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec661[0], 1.0) - fSlow24 * double(iRec660[0]));
			double fTemp1060 = 0.033924225800721616 * fTemp378 - fTemp76;
			double fTemp1061 = fRec221[(IOTA0 - iSlow428) & 1023];
			fVec222[0] = fTemp1061;
			iRec662[0] = (iRec662[1] + 1) * (fTemp1061 == 0.0);
			fRec663[0] = fTemp1061 + fRec663[1] * double(fVec222[1] >= fTemp1061);
			double fTemp1062 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec663[0], 1.0) - fSlow24 * double(iRec662[0]));
			double fTemp1063 = fTemp310 + 0.0316 * fRec38[0] * (0.8723277062322268 * fTemp778 - 0.9286243914348233 * fTemp385) - fTemp308;
			double fTemp1064 = fRec226[(IOTA0 - iSlow429) & 1023];
			fVec223[0] = fTemp1064;
			iRec664[0] = (iRec664[1] + 1) * (fTemp1064 == 0.0);
			fRec665[0] = fTemp1064 + fRec665[1] * double(fVec223[1] >= fTemp1064);
			double fTemp1065 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec665[0], 1.0) - fSlow24 * double(iRec664[0]));
			double fTemp1066 = 0.03577283854759008 * fTemp648 - fTemp279;
			double fTemp1067 = fRec252[(IOTA0 - iSlow430) & 1023];
			fVec224[0] = fTemp1067;
			iRec666[0] = (iRec666[1] + 1) * (fTemp1067 == 0.0);
			fRec667[0] = fTemp1067 + fRec667[1] * double(fVec224[1] >= fTemp1067);
			double fTemp1068 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec667[0], 1.0) - fSlow24 * double(iRec666[0]));
			double fTemp1069 = fTemp264 + 0.0316 * fRec38[0] * (0.56375159131494 * fTemp856 + 0.6833507299343182 * fTemp445) - fTemp263;
			double fTemp1070 = fRec235[(IOTA0 - iSlow431) & 1023];
			fVec225[0] = fTemp1070;
			iRec668[0] = (iRec668[1] + 1) * (fTemp1070 == 0.0);
			fRec669[0] = fTemp1070 + fRec669[1] * double(fVec225[1] >= fTemp1070);
			double fTemp1071 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec669[0], 1.0) - fSlow24 * double(iRec668[0]));
			double fTemp1072 = fTemp114 + 0.032045227404718754 * fTemp543;
			double fTemp1073 = fRec239[(IOTA0 - iSlow432) & 1023];
			fVec226[0] = fTemp1073;
			iRec670[0] = (iRec670[1] + 1) * (fTemp1073 == 0.0);
			fRec671[0] = fTemp1073 + fRec671[1] * double(fVec226[1] >= fTemp1073);
			double fTemp1074 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec671[0], 1.0) - fSlow24 * double(iRec670[0]));
			double fTemp1075 = 0.0050599010987876685 * fTemp203 - fTemp342;
			double fTemp1076 = fRec243[(IOTA0 - iSlow433) & 1023];
			fVec227[0] = fTemp1076;
			iRec672[0] = (iRec672[1] + 1) * (fTemp1076 == 0.0);
			fRec673[0] = fTemp1076 + fRec673[1] * double(fVec227[1] >= fTemp1076);
			double fTemp1077 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec673[0], 1.0) - fSlow24 * double(iRec672[0]));
			double fTemp1078 = fTemp353 + 0.0316 * fRec38[0] * (0.024517131510947365 * fTemp350 + 0.139208699176379 * fTemp187);
			double fTemp1079 = fRec247[(IOTA0 - iSlow434) & 1023];
			fVec228[0] = fTemp1079;
			iRec674[0] = (iRec674[1] + 1) * (fTemp1079 == 0.0);
			fRec675[0] = fTemp1079 + fRec675[1] * double(fVec228[1] >= fTemp1079);
			double fTemp1080 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec675[0], 1.0) - fSlow24 * double(iRec674[0]));
			double fTemp1081 = fTemp173 + 0.025977015830784513 * fTemp128 - fTemp172;
			double fTemp1082 = fRec89[(IOTA0 - iSlow435) & 1023];
			fVec229[0] = fTemp1082;
			iRec676[0] = (iRec676[1] + 1) * (fTemp1082 == 0.0);
			fRec677[0] = fTemp1082 + fRec677[1] * double(fVec229[1] >= fTemp1082);
			double fTemp1083 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec677[0], 1.0) - fSlow24 * double(iRec676[0]));
			double fTemp1084 = fTemp148 + 0.0316 * fRec38[0] * (0.8541366025674506 * fTemp377 + 0.16258050526084844 * fTemp78) - fTemp147;
			double fTemp1085 = fRec264[(IOTA0 - iSlow436) & 1023];
			fVec230[0] = fTemp1085;
			iRec678[0] = (iRec678[1] + 1) * (fTemp1085 == 0.0);
			fRec679[0] = fTemp1085 + fRec679[1] * double(fVec230[1] >= fTemp1085);
			double fTemp1086 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec679[0], 1.0) - fSlow24 * double(iRec678[0]));
			double fTemp1087 = fRec38[0] * fTemp97;
			double fTemp1088 = fTemp101 - (fTemp100 + 0.04912869215473948 * fTemp1087);
			double fTemp1089 = fRec84[(IOTA0 - iSlow437) & 1023];
			fVec231[0] = fTemp1089;
			iRec680[0] = (iRec680[1] + 1) * (fTemp1089 == 0.0);
			fRec681[0] = fTemp1089 + fRec681[1] * double(fVec231[1] >= fTemp1089);
			double fTemp1090 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec681[0], 1.0) - fSlow24 * double(iRec680[0]));
			double fTemp1091 = 0.0316 * fRec38[0] * (0.40269015427838895 * fTemp90 - 0.21855924587725895 * fTemp88) - fTemp66;
			double fTemp1092 = fRec256[(IOTA0 - iSlow438) & 1023];
			fVec232[0] = fTemp1092;
			iRec682[0] = (iRec682[1] + 1) * (fTemp1092 == 0.0);
			fRec683[0] = fTemp1092 + fRec683[1] * double(fVec232[1] >= fTemp1092);
			double fTemp1093 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec683[0], 1.0) - fSlow24 * double(iRec682[0]));
			double fTemp1094 = fTemp297 - (fTemp296 + 0.015274057413745323 * fTemp372);
			double fTemp1095 = fRec260[(IOTA0 - iSlow439) & 1023];
			fVec233[0] = fTemp1095;
			iRec684[0] = (iRec684[1] + 1) * (fTemp1095 == 0.0);
			fRec685[0] = fTemp1095 + fRec685[1] * double(fVec233[1] >= fTemp1095);
			double fTemp1096 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec685[0], 1.0) - fSlow24 * double(iRec684[0]));
			double fTemp1097 = fTemp217 - 0.031185418983647836 * fTemp661;
			double fTemp1098 = fRec268[(IOTA0 - iSlow440) & 1023];
			fVec234[0] = fTemp1098;
			iRec686[0] = (iRec686[1] + 1) * (fTemp1098 == 0.0);
			fRec687[0] = fTemp1098 + fRec687[1] * double(fVec234[1] >= fTemp1098);
			double fTemp1099 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec687[0], 1.0) - fSlow24 * double(iRec686[0]));
			double fTemp1100 = 0.0316 * fRec38[0] * (0.3712133590815938 * fTemp391 + 0.7545882850608905 * fTemp318) - fTemp55;
			double fTemp1101 = fRec50[(IOTA0 - iSlow441) & 1023];
			fVec235[0] = fTemp1101;
			iRec688[0] = (iRec688[1] + 1) * (fTemp1101 == 0.0);
			fRec689[0] = fTemp1101 + fRec689[1] * double(fVec235[1] >= fTemp1101);
			double fTemp1102 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec689[0], 1.0) - fSlow24 * double(iRec688[0]));
			double fTemp1103 = fTemp400 + 0.0316 * fRec38[0] * (0.9300477794313338 * fTemp445 + 0.28698274699854665 * fTemp265) - fTemp398;
			double fTemp1104 = fRec273[(IOTA0 - iSlow442) & 1023];
			fVec236[0] = fTemp1104;
			iRec690[0] = (iRec690[1] + 1) * (fTemp1104 == 0.0);
			fRec691[0] = fTemp1104 + fRec691[1] * double(fVec236[1] >= fTemp1104);
			double fTemp1105 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec691[0], 1.0) - fSlow24 * double(iRec690[0]));
			double fTemp1106 = fTemp252 + 0.05549099659837639 * fTemp543;
			double fTemp1107 = fRec80[(IOTA0 - iSlow443) & 1023];
			fVec237[0] = fTemp1107;
			iRec692[0] = (iRec692[1] + 1) * (fTemp1107 == 0.0);
			fRec693[0] = fTemp1107 + fRec693[1] * double(fVec237[1] >= fTemp1107);
			double fTemp1108 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec693[0], 1.0) - fSlow24 * double(iRec692[0]));
			double fTemp1109 = fTemp201 - (fTemp200 + 0.0316 * fRec38[0] * (0.639730604192664 * fTemp342 + 0.8940687963222445 * fTemp460));
			double fTemp1110 = fRec281[(IOTA0 - iSlow444) & 1023];
			fVec238[0] = fTemp1110;
			iRec694[0] = (iRec694[1] + 1) * (fTemp1110 == 0.0);
			fRec695[0] = fTemp1110 + fRec695[1] * double(fVec238[1] >= fTemp1110);
			double fTemp1111 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec695[0], 1.0) - fSlow24 * double(iRec694[0]));
			double fTemp1112 = fTemp186 + 0.0316 * fRec38[0] * (0.6566295679695031 * fTemp353 + 0.7914309653533564 * fTemp350) - fTemp185;
			double fTemp1113 = fRec286[(IOTA0 - iSlow445) & 1023];
			fVec239[0] = fTemp1113;
			iRec696[0] = (iRec696[1] + 1) * (fTemp1113 == 0.0);
			fRec697[0] = fTemp1113 + fRec697[1] * double(fVec239[1] >= fTemp1113);
			double fTemp1114 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec697[0], 1.0) - fSlow24 * double(iRec696[0]));
			double fTemp1115 = fTemp126 + 0.0316 * fRec38[0] * (0.12707171978399856 * fTemp174 + 0.5058318081792095 * fTemp127) - fTemp125;
			double fTemp1116 = fRec294[(IOTA0 - iSlow446) & 1023];
			fVec240[0] = fTemp1116;
			iRec698[0] = (iRec698[1] + 1) * (fTemp1116 == 0.0);
			fRec699[0] = fTemp1116 + fRec699[1] * double(fVec240[1] >= fTemp1116);
			double fTemp1117 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec699[0], 1.0) - fSlow24 * double(iRec698[0]));
			double fTemp1118 = fTemp422 + 0.0316 * fRec38[0] * (0.5085425655706786 * fTemp422 - 0.611385888827499 * fTemp279);
			double fTemp1119 = fRec298[(IOTA0 - iSlow447) & 1023];
			fVec241[0] = fTemp1119;
			iRec700[0] = (iRec700[1] + 1) * (fTemp1119 == 0.0);
			fRec701[0] = fTemp1119 + fRec701[1] * double(fVec241[1] >= fTemp1119);
			double fTemp1120 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec701[0], 1.0) - fSlow24 * double(iRec700[0]));
			double fTemp1121 = fTemp89 + 0.0316 * fRec38[0] * (0.5771930705523118 * fTemp90 - 0.8858153809851501 * fTemp66) - fTemp85;
			double fTemp1122 = fRec306[(IOTA0 - iSlow448) & 1023];
			fVec242[0] = fTemp1122;
			iRec702[0] = (iRec702[1] + 1) * (fTemp1122 == 0.0);
			fRec703[0] = fTemp1122 + fRec703[1] * double(fVec242[1] >= fTemp1122);
			double fTemp1123 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec703[0], 1.0) - fSlow24 * double(iRec702[0]));
			double fTemp1124 = 0.0316 * fRec38[0] * (0.8448270718563435 * fTemp298 - 0.01765322359642596 * fTemp38) - fTemp41;
			double fTemp1125 = fRec44[(IOTA0 - iSlow449) & 1023];
			fVec243[0] = fTemp1125;
			iRec704[0] = (iRec704[1] + 1) * (fTemp1125 == 0.0);
			fRec705[0] = fTemp1125 + fRec705[1] * double(fVec243[1] >= fTemp1125);
			double fTemp1126 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec705[0], 1.0) - fSlow24 * double(iRec704[0]));
			double fTemp1127 = fTemp77 + 0.0316 * fRec38[0] * (0.9874057494062072 * fTemp78 - 0.3260768634663691 * fTemp76) - fTemp73;
			double fTemp1128 = fRec290[(IOTA0 - iSlow450) & 1023];
			fVec244[0] = fTemp1128;
			iRec706[0] = (iRec706[1] + 1) * (fTemp1128 == 0.0);
			fRec707[0] = fTemp1128 + fRec707[1] * double(fVec244[1] >= fTemp1128);
			double fTemp1129 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec707[0], 1.0) - fSlow24 * double(iRec706[0]));
			double fTemp1130 = 0.0316 * fRec38[0] * (0.13272281141325948 * fTemp386 - 0.9595943575586716 * fTemp385) - fTemp385;
			double fTemp1131 = fRec310[(IOTA0 - iSlow451) & 1023];
			fVec245[0] = fTemp1131;
			iRec708[0] = (iRec708[1] + 1) * (fTemp1131 == 0.0);
			fRec709[0] = fTemp1131 + fRec709[1] * double(fVec245[1] >= fTemp1131);
			double fTemp1132 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec709[0], 1.0) - fSlow24 * double(iRec708[0]));
			double fTemp1133 = -1.0 - 0.03827802712256962 * fRec38[0];
			double fTemp1134 = fRec314[(IOTA0 - iSlow452) & 1023];
			fVec246[0] = fTemp1134;
			iRec710[0] = (iRec710[1] + 1) * (fTemp1134 == 0.0);
			fRec711[0] = fTemp1134 + fRec711[1] * double(fVec246[1] >= fTemp1134);
			double fTemp1135 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec711[0], 1.0) - fSlow24 * double(iRec710[0]));
			double fTemp1136 = fTemp445 + 0.0316 * fRec38[0] * (0.9941103403107263 * fTemp265 + 0.20243094763281988 * fTemp445);
			double fTemp1137 = fRec318[(IOTA0 - iSlow453) & 1023];
			fVec247[0] = fTemp1137;
			iRec712[0] = (iRec712[1] + 1) * (fTemp1137 == 0.0);
			fRec713[0] = fTemp1137 + fRec713[1] * double(fVec247[1] >= fTemp1137);
			double fTemp1138 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec713[0], 1.0) - fSlow24 * double(iRec712[0]));
			double fTemp1139 = fTemp110 + 0.0316 * fRec38[0] * (0.44927494963485515 * fTemp111 + 0.8088971364632016 * fTemp252) - fTemp109;
			double fTemp1140 = fRec277[(IOTA0 - iSlow454) & 1023];
			fVec248[0] = fTemp1140;
			iRec714[0] = (iRec714[1] + 1) * (fTemp1140 == 0.0);
			fRec715[0] = fTemp1140 + fRec715[1] * double(fVec248[1] >= fTemp1140);
			double fTemp1141 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec715[0], 1.0) - fSlow24 * double(iRec714[0]));
			double fTemp1142 = 0.0316 * fRec38[0] * (0.49593480947442004 * fTemp202 - 0.8524944821256213 * fTemp460) - fTemp460;
			double fTemp1143 = fRec322[(IOTA0 - iSlow455) & 1023];
			fVec249[0] = fTemp1143;
			iRec716[0] = (iRec716[1] + 1) * (fTemp1143 == 0.0);
			fRec717[0] = fTemp1143 + fRec717[1] * double(fVec249[1] >= fTemp1143);
			double fTemp1144 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec717[0], 1.0) - fSlow24 * double(iRec716[0]));
			double fTemp1145 = fTemp350 + 0.0316 * fRec38[0] * (0.8180740965872246 * fTemp187 + 0.21308570862856868 * fTemp350);
			double fTemp1146 = fRec326[(IOTA0 - iSlow456) & 1023];
			fVec250[0] = fTemp1146;
			iRec718[0] = (iRec718[1] + 1) * (fTemp1146 == 0.0);
			fRec719[0] = fTemp1146 + fRec719[1] * double(fVec250[1] >= fTemp1146);
			double fTemp1147 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec719[0], 1.0) - fSlow24 * double(iRec718[0]));
			fRec720[0] = fSlow458 + fConst10 * fRec720[1];
			double fTemp1148 = fTemp460 + 0.0316 * fRec38[0] * (0.34945254012563964 * fTemp460 + 0.4011569504364161 * fTemp342);
			double fTemp1149 = fRec68[(IOTA0 - iSlow459) & 1023];
			fVec251[0] = fTemp1149;
			iRec721[0] = (iRec721[1] + 1) * (fTemp1149 == 0.0);
			fRec722[0] = fTemp1149 + fRec722[1] * double(fVec251[1] >= fTemp1149);
			double fTemp1150 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec722[0], 1.0) - fSlow24 * double(iRec721[0]));
			double fTemp1151 = fTemp62 + 0.02611320919268765 * fRec38[0] * fTemp88;
			double fTemp1152 = fRec188[(IOTA0 - iSlow460) & 1023];
			fVec252[0] = fTemp1152;
			iRec723[0] = (iRec723[1] + 1) * (fTemp1152 == 0.0);
			fRec724[0] = fTemp1152 + fRec724[1] * double(fVec252[1] >= fTemp1152);
			double fTemp1153 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec724[0], 1.0) - fSlow24 * double(iRec723[0]));
			double fTemp1154 = fTemp17 + 0.040810107541171606 * fRec38[0] * fTemp29;
			double fTemp1155 = fRec137[(IOTA0 - iSlow461) & 1023];
			fVec253[0] = fTemp1155;
			iRec725[0] = (iRec725[1] + 1) * (fTemp1155 == 0.0);
			fRec726[0] = fTemp1155 + fRec726[1] * double(fVec253[1] >= fTemp1155);
			double fTemp1156 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec726[0], 1.0) - fSlow24 * double(iRec725[0]));
			double fTemp1157 = fTemp126 + 0.0316 * fRec38[0] * (0.002333788863325026 * fTemp127 + 0.704249159887695 * fTemp361) - fTemp125;
			double fTemp1158 = fRec62[(IOTA0 - iSlow462) & 1023];
			fVec254[0] = fTemp1158;
			iRec727[0] = (iRec727[1] + 1) * (fTemp1158 == 0.0);
			fRec728[0] = fTemp1158 + fRec728[1] * double(fVec254[1] >= fTemp1158);
			double fTemp1159 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec728[0], 1.0) - fSlow24 * double(iRec727[0]));
			double fTemp1160 = 0.0316 * fRec38[0] * (0.9762518711504526 * fTemp102 - 0.3945851921234862 * fTemp97) - fTemp97;
			double fTemp1161 = fRec314[(IOTA0 - iSlow463) & 1023];
			fVec255[0] = fTemp1161;
			iRec729[0] = (iRec729[1] + 1) * (fTemp1161 == 0.0);
			fRec730[0] = fTemp1161 + fRec730[1] * double(fVec255[1] >= fTemp1161);
			double fTemp1162 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec730[0], 1.0) - fSlow24 * double(iRec729[0]));
			double fTemp1163 = fTemp217 - 0.047527853922636136 * fTemp661;
			double fTemp1164 = fRec286[(IOTA0 - iSlow464) & 1023];
			fVec256[0] = fTemp1164;
			iRec731[0] = (iRec731[1] + 1) * (fTemp1164 == 0.0);
			fRec732[0] = fTemp1164 + fRec732[1] * double(fVec256[1] >= fTemp1164);
			double fTemp1165 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec732[0], 1.0) - fSlow24 * double(iRec731[0]));
			double fTemp1166 = fTemp114 + 0.0316 * fRec38[0] * (0.8135586400676402 * fTemp335 + 0.3650543369658408 * fTemp334);
			double fTemp1167 = fRec84[(IOTA0 - iSlow465) & 1023];
			fVec257[0] = fTemp1167;
			iRec733[0] = (iRec733[1] + 1) * (fTemp1167 == 0.0);
			fRec734[0] = fTemp1167 + fRec734[1] * double(fVec257[1] >= fTemp1167);
			double fTemp1168 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec734[0], 1.0) - fSlow24 * double(iRec733[0]));
			double fTemp1169 = fTemp162 + 0.0316 * fRec38[0] * (0.7938493485271465 * fTemp137 - 0.7497765989392065 * fTemp97) - fTemp156;
			double fTemp1170 = fRec230[(IOTA0 - iSlow466) & 1023];
			fVec258[0] = fTemp1170;
			iRec735[0] = (iRec735[1] + 1) * (fTemp1170 == 0.0);
			fRec736[0] = fTemp1170 + fRec736[1] * double(fVec258[1] >= fTemp1170);
			double fTemp1171 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec736[0], 1.0) - fSlow24 * double(iRec735[0]));
			double fTemp1172 = fTemp285 + 0.0316 * fRec38[0] * (0.30707316955249553 * fTemp598 + 0.4891884838216356 * fTemp422) - fTemp276;
			double fTemp1173 = fRec226[(IOTA0 - iSlow467) & 1023];
			fVec259[0] = fTemp1173;
			iRec737[0] = (iRec737[1] + 1) * (fTemp1173 == 0.0);
			fRec738[0] = fTemp1173 + fRec738[1] * double(fVec259[1] >= fTemp1173);
			double fTemp1174 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec738[0], 1.0) - fSlow24 * double(iRec737[0]));
			double fTemp1175 = fTemp175 + 0.0316 * fRec38[0] * (0.7697115867904358 * fTemp127 - 0.40489292482561723 * fTemp17) - fTemp169;
			double fTemp1176 = fRec221[(IOTA0 - iSlow468) & 1023];
			fVec260[0] = fTemp1176;
			iRec739[0] = (iRec739[1] + 1) * (fTemp1176 == 0.0);
			fRec740[0] = fTemp1176 + fRec740[1] * double(fVec260[1] >= fTemp1176);
			double fTemp1177 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec740[0], 1.0) - fSlow24 * double(iRec739[0]));
			double fTemp1178 = fTemp190 + 0.0316 * fRec38[0] * (0.6769308884940983 * fTemp187 - 0.9892686069688352 * fTemp182);
			double fTemp1179 = fRec217[(IOTA0 - iSlow469) & 1023];
			fVec261[0] = fTemp1179;
			iRec741[0] = (iRec741[1] + 1) * (fTemp1179 == 0.0);
			fRec742[0] = fTemp1179 + fRec742[1] * double(fVec261[1] >= fTemp1179);
			double fTemp1180 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec742[0], 1.0) - fSlow24 * double(iRec741[0]));
			double fTemp1181 = fTemp204 + 0.02335414811735391 * fTemp203 - fTemp197;
			double fTemp1182 = fRec56[(IOTA0 - iSlow470) & 1023];
			fVec262[0] = fTemp1182;
			iRec743[0] = (iRec743[1] + 1) * (fTemp1182 == 0.0);
			fRec744[0] = fTemp1182 + fRec744[1] * double(fVec262[1] >= fTemp1182);
			double fTemp1183 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec744[0], 1.0) - fSlow24 * double(iRec743[0]));
			double fTemp1184 = fTemp253 + 0.0316 * fRec38[0] * (0.5575647596197086 * fTemp114 + 0.8942629225421115 * fTemp334) - fTemp249;
			double fTemp1185 = fRec94[(IOTA0 - iSlow471) & 1023];
			fVec263[0] = fTemp1185;
			iRec745[0] = (iRec745[1] + 1) * (fTemp1185 == 0.0);
			fRec746[0] = fTemp1185 + fRec746[1] * double(fVec263[1] >= fTemp1185);
			double fTemp1186 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec746[0], 1.0) - fSlow24 * double(iRec745[0]));
			double fTemp1187 = fTemp269 + 0.0316 * fRec38[0] * (0.8924149574668263 * fTemp265 + 0.6976291608734755 * fTemp268) - fTemp260;
			double fTemp1188 = fRec213[(IOTA0 - iSlow472) & 1023];
			fVec264[0] = fTemp1188;
			iRec747[0] = (iRec747[1] + 1) * (fTemp1188 == 0.0);
			fRec748[0] = fTemp1188 + fRec748[1] * double(fVec264[1] >= fTemp1188);
			double fTemp1189 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec748[0], 1.0) - fSlow24 * double(iRec747[0]));
			double fTemp1190 = fTemp242 + 0.0316 * fRec38[0] * (0.9104043234983692 * fTemp236 + 0.24175746153559885 * fTemp241) - fTemp233;
			double fTemp1191 = fRec209[(IOTA0 - iSlow473) & 1023];
			fVec265[0] = fTemp1191;
			iRec749[0] = (iRec749[1] + 1) * (fTemp1191 == 0.0);
			fRec750[0] = fTemp1191 + fRec750[1] * double(fVec265[1] >= fTemp1191);
			double fTemp1192 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec750[0], 1.0) - fSlow24 * double(iRec749[0]));
			double fTemp1193 = fTemp218 + 0.0316 * fRec38[0] * (0.5356778987134021 * fTemp217 + 0.49874489220019314 * fTemp386) - fTemp211;
			double fTemp1194 = fRec204[(IOTA0 - iSlow474) & 1023];
			fVec266[0] = fTemp1194;
			iRec751[0] = (iRec751[1] + 1) * (fTemp1194 == 0.0);
			fRec752[0] = fTemp1194 + fRec752[1] * double(fVec266[1] >= fTemp1194);
			double fTemp1195 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec752[0], 1.0) - fSlow24 * double(iRec751[0]));
			double fTemp1196 = fTemp226 + 0.0316 * fRec38[0] * (0.1548177000031501 * fTemp845 - 0.39691041694800333 * fTemp76) - fTemp225;
			double fTemp1197 = fRec198[(IOTA0 - iSlow475) & 1023];
			fVec267[0] = fTemp1197;
			iRec753[0] = (iRec753[1] + 1) * (fTemp1197 == 0.0);
			fRec754[0] = fTemp1197 + fRec754[1] * double(fVec267[1] >= fTemp1197);
			double fTemp1198 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec754[0], 1.0) - fSlow24 * double(iRec753[0]));
			double fTemp1199 = fTemp301 - 0.0316 * fRec38[0] * (0.7554453812335851 * fTemp38 + 0.7650474495676463 * fTemp23);
			double fTemp1200 = fRec193[(IOTA0 - iSlow476) & 1023];
			fVec268[0] = fTemp1200;
			iRec755[0] = (iRec755[1] + 1) * (fTemp1200 == 0.0);
			fRec756[0] = fTemp1200 + fRec756[1] * double(fVec268[1] >= fTemp1200);
			double fTemp1201 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec756[0], 1.0) - fSlow24 * double(iRec755[0]));
			double fTemp1202 = fTemp136 + 0.0316 * fRec38[0] * (0.5325304772777599 * fTemp102 + 0.7842405722476542 * fTemp161) - fTemp135;
			double fTemp1203 = fRec184[(IOTA0 - iSlow477) & 1023];
			fVec269[0] = fTemp1203;
			iRec757[0] = (iRec757[1] + 1) * (fTemp1203 == 0.0);
			fRec758[0] = fTemp1203 + fRec758[1] * double(fVec269[1] >= fTemp1203);
			double fTemp1204 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec758[0], 1.0) - fSlow24 * double(iRec757[0]));
			double fTemp1205 = fTemp283 + 0.0316 * fRec38[0] * (0.0761320453020744 * fTemp1007 + 0.904012801576755 * fTemp366) - fTemp282;
			double fTemp1206 = fRec179[(IOTA0 - iSlow478) & 1023];
			fVec270[0] = fTemp1206;
			iRec759[0] = (iRec759[1] + 1) * (fTemp1206 == 0.0);
			fRec760[0] = fTemp1206 + fRec760[1] * double(fVec270[1] >= fTemp1206);
			double fTemp1207 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec760[0], 1.0) - fSlow24 * double(iRec759[0]));
			double fTemp1208 = 0.0316 * fRec38[0] * (0.5714778684050543 * fTemp554 + 0.8331271103561448 * fTemp353) - fTemp182;
			double fTemp1209 = fRec174[(IOTA0 - iSlow479) & 1023];
			fVec271[0] = fTemp1209;
			iRec761[0] = (iRec761[1] + 1) * (fTemp1209 == 0.0);
			fRec762[0] = fTemp1209 + fRec762[1] * double(fVec271[1] >= fTemp1209);
			double fTemp1210 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec762[0], 1.0) - fSlow24 * double(iRec761[0]));
			double fTemp1211 = fRec38[0] * fTemp335;
			double fTemp1212 = fTemp333 + 0.031141286496628895 * fTemp1211 - fTemp332;
			double fTemp1213 = fRec106[(IOTA0 - iSlow480) & 1023];
			fVec272[0] = fTemp1213;
			iRec763[0] = (iRec763[1] + 1) * (fTemp1213 == 0.0);
			fRec764[0] = fTemp1213 + fRec764[1] * double(fVec272[1] >= fTemp1213);
			double fTemp1214 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec764[0], 1.0) - fSlow24 * double(iRec763[0]));
			double fTemp1215 = 0.0316 * fRec38[0] * (0.13591576983162668 * fTemp377 - 0.23412134464160772 * fTemp76) - fTemp144;
			double fTemp1216 = fRec125[(IOTA0 - iSlow481) & 1023];
			fVec273[0] = fTemp1216;
			iRec765[0] = (iRec765[1] + 1) * (fTemp1216 == 0.0);
			fRec766[0] = fTemp1216 + fRec766[1] * double(fVec273[1] >= fTemp1216);
			double fTemp1217 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec766[0], 1.0) - fSlow24 * double(iRec765[0]));
			double fTemp1218 = fTemp584 - 0.02513784417584975 * fRec38[0] * fTemp26;
			double fTemp1219 = fRec150[(IOTA0 - iSlow482) & 1023];
			fVec274[0] = fTemp1219;
			iRec767[0] = (iRec767[1] + 1) * (fTemp1219 == 0.0);
			fRec768[0] = fTemp1219 + fRec768[1] * double(fVec274[1] >= fTemp1219);
			double fTemp1220 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec768[0], 1.0) - fSlow24 * double(iRec767[0]));
			double fTemp1221 = ((iTemp14) ? 0.0 : fConst359 + fRec769[1]);
			fRec769[0] = fTemp1221 - std::floor(fTemp1221);
			int iTemp1222 = std::max<int>(0, std::min<int>(int(65536.0 * fRec769[0]), 65535));
			double fTemp1223 = 0.962955084917349 * ftbl1TonewheelSIG1[iTemp1222] + 0.2696618334726312 * ftbl0TonewheelSIG0[iTemp1222];
			double fTemp1224 = 0.029484000497802483 * fRec38[0] * fTemp1223 - fTemp616;
			double fTemp1225 = fRec157[(IOTA0 - iSlow483) & 1023];
			fVec275[0] = fTemp1225;
			iRec770[0] = (iRec770[1] + 1) * (fTemp1225 == 0.0);
			fRec771[0] = fTemp1225 + fRec771[1] * double(fVec275[1] >= fTemp1225);
			double fTemp1226 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec771[0], 1.0) - fSlow24 * double(iRec770[0]));
			double fTemp1227 = fTemp160 + 0.031795797203534495 * fTemp791 - fTemp159;
			double fTemp1228 = fRec144[(IOTA0 - iSlow484) & 1023];
			fVec276[0] = fTemp1228;
			iRec772[0] = (iRec772[1] + 1) * (fTemp1228 == 0.0);
			fRec773[0] = fTemp1228 + fRec773[1] * double(fVec276[1] >= fTemp1228);
			double fTemp1229 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec773[0], 1.0) - fSlow24 * double(iRec772[0]));
			double fTemp1230 = ((iTemp14) ? 0.0 : fConst362 + fRec774[1]);
			fRec774[0] = fTemp1230 - std::floor(fTemp1230);
			int iTemp1231 = std::max<int>(0, std::min<int>(int(65536.0 * fRec774[0]), 65535));
			double fTemp1232 = 0.9891760234281969 * ftbl1TonewheelSIG1[iTemp1231] + 0.14673375438112166 * ftbl0TonewheelSIG0[iTemp1231];
			double fTemp1233 = fTemp597 + 0.0316 * fRec38[0] * (0.5313217916009307 * fTemp366 - 0.4518111008728738 * fTemp1232) - fTemp596;
			double fTemp1234 = fRec132[(IOTA0 - iSlow485) & 1023];
			fVec277[0] = fTemp1234;
			iRec775[0] = (iRec775[1] + 1) * (fTemp1234 == 0.0);
			fRec776[0] = fTemp1234 + fRec776[1] * double(fVec277[1] >= fTemp1234);
			double fTemp1235 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec776[0], 1.0) - fSlow24 * double(iRec775[0]));
			double fTemp1236 = fTemp777 + 0.0316 * fRec38[0] * (0.7247212012662203 * fTemp1035 + 0.8268062207207549 * fTemp309) - fTemp776;
			double fTemp1237 = fRec119[(IOTA0 - iSlow486) & 1023];
			fVec278[0] = fTemp1237;
			iRec777[0] = (iRec777[1] + 1) * (fTemp1237 == 0.0);
			fRec778[0] = fTemp1237 + fRec778[1] * double(fVec278[1] >= fTemp1237);
			double fTemp1238 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec778[0], 1.0) - fSlow24 * double(iRec777[0]));
			double fTemp1239 = ((iTemp14) ? 0.0 : fConst365 + fRec779[1]);
			fRec779[0] = fTemp1239 - std::floor(fTemp1239);
			int iTemp1240 = std::max<int>(0, std::min<int>(int(65536.0 * fRec779[0]), 65535));
			double fTemp1241 = 0.8124608230194709 * ftbl0TonewheelSIG0[iTemp1240];
			double fTemp1242 = 0.5830157897163027 * ftbl1TonewheelSIG1[iTemp1240];
			double fTemp1243 = fTemp1242 - fTemp1241;
			double fTemp1244 = fTemp236 + 0.04610351768544934 * fRec38[0] * fTemp1243;
			double fTemp1245 = fRec112[(IOTA0 - iSlow487) & 1023];
			fVec279[0] = fTemp1245;
			iRec780[0] = (iRec780[1] + 1) * (fTemp1245 == 0.0);
			fRec781[0] = fTemp1245 + fRec781[1] * double(fVec279[1] >= fTemp1245);
			double fTemp1246 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec781[0], 1.0) - fSlow24 * double(iRec780[0]));
			double fTemp1247 = ((iTemp14) ? 0.0 : fConst367 + fRec782[1]);
			fRec782[0] = fTemp1247 - std::floor(fTemp1247);
			int iTemp1248 = std::max<int>(0, std::min<int>(int(65536.0 * fRec782[0]), 65535));
			double fTemp1249 = 0.5400810669449504 * ftbl1TonewheelSIG1[iTemp1248];
			double fTemp1250 = 0.8416129996189484 * ftbl0TonewheelSIG0[iTemp1248];
			double fTemp1251 = fTemp1250 - fTemp1249;
			double fTemp1252 = fTemp855 + 0.0316 * fRec38[0] * (0.8144547300944396 * fTemp1251 + 0.4453206880862126 * fTemp268) - fTemp854;
			double fTemp1253 = fRec164[(IOTA0 - iSlow488) & 1023];
			fVec280[0] = fTemp1253;
			iRec783[0] = (iRec783[1] + 1) * (fTemp1253 == 0.0);
			fRec784[0] = fTemp1253 + fRec784[1] * double(fVec280[1] >= fTemp1253);
			double fTemp1254 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec784[0], 1.0) - fSlow24 * double(iRec783[0]));
			double fTemp1255 = fTemp831 + 0.0316 * fRec38[0] * (0.5480252947277222 * fTemp343 + 0.06530713925531018 * fTemp560) - fTemp830;
			double fTemp1256 = fRec168[(IOTA0 - iSlow489) & 1023];
			fVec281[0] = fTemp1256;
			iRec785[0] = (iRec785[1] + 1) * (fTemp1256 == 0.0);
			fRec786[0] = fTemp1256 + fRec786[1] * double(fVec281[1] >= fTemp1256);
			double fTemp1257 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec786[0], 1.0) - fSlow24 * double(iRec785[0]));
			double fTemp1258 = fTemp360 + 0.0316 * fRec38[0] * (0.9877557660875027 * fTemp361 - 0.16150552488397807 * fTemp17);
			double fTemp1259 = fRec100[(IOTA0 - iSlow490) & 1023];
			fVec282[0] = fTemp1259;
			iRec787[0] = (iRec787[1] + 1) * (fTemp1259 == 0.0);
			fRec788[0] = fTemp1259 + fRec788[1] * double(fVec282[1] >= fTemp1259);
			double fTemp1260 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec788[0], 1.0) - fSlow24 * double(iRec787[0]));
			double fTemp1261 = 0.0316 * fRec38[0] * (0.3426959723510663 * fTemp90 - 0.6815722454848583 * fTemp616) - fTemp88;
			double fTemp1262 = fRec235[(IOTA0 - iSlow491) & 1023];
			fVec283[0] = fTemp1262;
			iRec789[0] = (iRec789[1] + 1) * (fTemp1262 == 0.0);
			fRec790[0] = fTemp1262 + fRec790[1] * double(fVec283[1] >= fTemp1262);
			double fTemp1263 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec790[0], 1.0) - fSlow24 * double(iRec789[0]));
			double fTemp1264 = 0.0316 * fRec38[0] * (0.6203564098395873 * fTemp298 - 0.31638499342807336 * fTemp41) - fTemp38;
			double fTemp1265 = fRec239[(IOTA0 - iSlow492) & 1023];
			fVec284[0] = fTemp1265;
			iRec791[0] = (iRec791[1] + 1) * (fTemp1265 == 0.0);
			fRec792[0] = fTemp1265 + fRec792[1] * double(fVec284[1] >= fTemp1265);
			double fTemp1266 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec792[0], 1.0) - fSlow24 * double(iRec791[0]));
			double fTemp1267 = 0.0316 * fRec38[0] * (0.36379954079166055 * fTemp78 - 0.6702034074842231 * fTemp144) - fTemp76;
			double fTemp1268 = fRec243[(IOTA0 - iSlow493) & 1023];
			fVec285[0] = fTemp1268;
			iRec793[0] = (iRec793[1] + 1) * (fTemp1268 == 0.0);
			fRec794[0] = fTemp1268 + fRec794[1] * double(fVec285[1] >= fTemp1268);
			double fTemp1269 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec794[0], 1.0) - fSlow24 * double(iRec793[0]));
			double fTemp1270 = fTemp310 + 0.0316 * fRec38[0] * (0.08567908123222878 * fTemp778 + 0.9996576567064039 * fTemp217) - fTemp308;
			double fTemp1271 = fRec247[(IOTA0 - iSlow494) & 1023];
			fVec286[0] = fTemp1271;
			iRec795[0] = (iRec795[1] + 1) * (fTemp1271 == 0.0);
			fRec796[0] = fTemp1271 + fRec796[1] * double(fVec286[1] >= fTemp1271);
			double fTemp1272 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec796[0], 1.0) - fSlow24 * double(iRec795[0]));
			double fTemp1273 = fTemp319 + 0.0316 * fRec38[0] * (0.636632360969088 * fTemp318 - 0.14168440419780381 * fTemp52) - fTemp317;
			double fTemp1274 = fRec89[(IOTA0 - iSlow495) & 1023];
			fVec287[0] = fTemp1274;
			iRec797[0] = (iRec797[1] + 1) * (fTemp1274 == 0.0);
			fRec798[0] = fTemp1274 + fRec798[1] * double(fVec287[1] >= fTemp1274);
			double fTemp1275 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec798[0], 1.0) - fSlow24 * double(iRec797[0]));
			double fTemp1276 = fTemp264 + 0.0316 * fRec38[0] * (0.9498486592974587 * fTemp324 + 0.2098373820363122 * fTemp446) - fTemp263;
			double fTemp1277 = fRec252[(IOTA0 - iSlow496) & 1023];
			fVec288[0] = fTemp1277;
			iRec799[0] = (iRec799[1] + 1) * (fTemp1277 == 0.0);
			fRec800[0] = fTemp1277 + fRec800[1] * double(fVec288[1] >= fTemp1277);
			double fTemp1278 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec800[0], 1.0) - fSlow24 * double(iRec799[0]));
			double fTemp1279 = 0.0316 * fRec38[0] * (0.24197412003195495 * fTemp343 + 0.7552864369936287 * fTemp202) - fTemp342;
			double fTemp1280 = fRec256[(IOTA0 - iSlow497) & 1023];
			fVec289[0] = fTemp1280;
			iRec801[0] = (iRec801[1] + 1) * (fTemp1280 == 0.0);
			fRec802[0] = fTemp1280 + fRec802[1] * double(fVec289[1] >= fTemp1280);
			double fTemp1281 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec802[0], 1.0) - fSlow24 * double(iRec801[0]));
			double fTemp1282 = fTemp353 + 0.0316 * fRec38[0] * (0.8477621959173121 * fTemp350 + 0.7530131083767628 * fTemp190);
			double fTemp1283 = fRec260[(IOTA0 - iSlow498) & 1023];
			fVec290[0] = fTemp1283;
			iRec803[0] = (iRec803[1] + 1) * (fTemp1283 == 0.0);
			fRec804[0] = fTemp1283 + fRec804[1] * double(fVec290[1] >= fTemp1283);
			double fTemp1284 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec804[0], 1.0) - fSlow24 * double(iRec803[0]));
			double fTemp1285 = fTemp173 + 0.0316 * fRec38[0] * (0.07575520013779169 * fTemp127 + 0.2894949674519012 * fTemp361) - fTemp172;
			double fTemp1286 = fRec264[(IOTA0 - iSlow499) & 1023];
			fVec291[0] = fTemp1286;
			iRec805[0] = (iRec805[1] + 1) * (fTemp1286 == 0.0);
			fRec806[0] = fTemp1286 + fRec806[1] * double(fVec291[1] >= fTemp1286);
			double fTemp1287 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec806[0], 1.0) - fSlow24 * double(iRec805[0]));
			double fTemp1288 = 0.0316 * fRec38[0] * (0.2725231242729933 * fTemp284 + 0.8031883391304291 * fTemp422) - fTemp279;
			double fTemp1289 = fRec268[(IOTA0 - iSlow500) & 1023];
			fVec292[0] = fTemp1289;
			iRec807[0] = (iRec807[1] + 1) * (fTemp1289 == 0.0);
			fRec808[0] = fTemp1289 + fRec808[1] * double(fVec292[1] >= fTemp1289);
			double fTemp1290 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec808[0], 1.0) - fSlow24 * double(iRec807[0]));
			double fTemp1291 = fTemp101 + 0.029269424826549952 * fTemp876 - fTemp100;
			double fTemp1292 = fRec50[(IOTA0 - iSlow501) & 1023];
			fVec293[0] = fTemp1292;
			iRec809[0] = (iRec809[1] + 1) * (fTemp1292 == 0.0);
			fRec810[0] = fTemp1292 + fRec810[1] * double(fVec293[1] >= fTemp1292);
			double fTemp1293 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec810[0], 1.0) - fSlow24 * double(iRec809[0]));
			double fTemp1294 = 0.02909410915370245 * fTemp483 - fTemp66;
			double fTemp1295 = fRec273[(IOTA0 - iSlow502) & 1023];
			fVec294[0] = fTemp1295;
			iRec811[0] = (iRec811[1] + 1) * (fTemp1295 == 0.0);
			fRec812[0] = fTemp1295 + fRec812[1] * double(fVec294[1] >= fTemp1295);
			double fTemp1296 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec812[0], 1.0) - fSlow24 * double(iRec811[0]));
			double fTemp1297 = fTemp186 + 0.0316 * fRec38[0] * (0.934430343932263 * fTemp353 + 0.8741802550748616 * fTemp350) - fTemp185;
			double fTemp1298 = fRec44[(IOTA0 - iSlow503) & 1023];
			fVec295[0] = fTemp1298;
			iRec813[0] = (iRec813[1] + 1) * (fTemp1298 == 0.0);
			fRec814[0] = fTemp1298 + fRec814[1] * double(fVec295[1] >= fTemp1298);
			double fTemp1299 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec814[0], 1.0) - fSlow24 * double(iRec813[0]));
			double fTemp1300 = fTemp297 - (fTemp296 + 0.05271901529480238 * fTemp372);
			double fTemp1301 = fRec80[(IOTA0 - iSlow504) & 1023];
			fVec296[0] = fTemp1301;
			iRec815[0] = (iRec815[1] + 1) * (fTemp1301 == 0.0);
			fRec816[0] = fTemp1301 + fRec816[1] * double(fVec296[1] >= fTemp1301);
			double fTemp1302 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec816[0], 1.0) - fSlow24 * double(iRec815[0]));
			double fTemp1303 = fTemp148 + 0.0316 * fRec38[0] * (0.12936534684195067 * fTemp78 - 0.7800365522998618 * fTemp76) - fTemp147;
			double fTemp1304 = fRec281[(IOTA0 - iSlow505) & 1023];
			fVec297[0] = fTemp1304;
			iRec817[0] = (iRec817[1] + 1) * (fTemp1304 == 0.0);
			fRec818[0] = fTemp1304 + fRec818[1] * double(fVec297[1] >= fTemp1304);
			double fTemp1305 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec818[0], 1.0) - fSlow24 * double(iRec817[0]));
			double fTemp1306 = 0.0316 * fRec38[0] * (0.5647421087269322 * fTemp391 + 0.9681550711684395 * fTemp318) - fTemp55;
			double fTemp1307 = fRec294[(IOTA0 - iSlow506) & 1023];
			fVec298[0] = fTemp1307;
			iRec819[0] = (iRec819[1] + 1) * (fTemp1307 == 0.0);
			fRec820[0] = fTemp1307 + fRec820[1] * double(fVec298[1] >= fTemp1307);
			double fTemp1308 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec820[0], 1.0) - fSlow24 * double(iRec819[0]));
			double fTemp1309 = fTemp400 + 0.03589721254408069 * fTemp892 - fTemp398;
			double fTemp1310 = fRec298[(IOTA0 - iSlow507) & 1023];
			fVec299[0] = fTemp1310;
			iRec821[0] = (iRec821[1] + 1) * (fTemp1310 == 0.0);
			fRec822[0] = fTemp1310 + fRec822[1] * double(fVec299[1] >= fTemp1310);
			double fTemp1311 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec822[0], 1.0) - fSlow24 * double(iRec821[0]));
			double fTemp1312 = fTemp252 + 0.040746362787636464 * fTemp1211;
			double fTemp1313 = fRec302[(IOTA0 - iSlow508) & 1023];
			fVec300[0] = fTemp1313;
			iRec823[0] = (iRec823[1] + 1) * (fTemp1313 == 0.0);
			fRec824[0] = fTemp1313 + fRec824[1] * double(fVec300[1] >= fTemp1313);
			double fTemp1314 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec824[0], 1.0) - fSlow24 * double(iRec823[0]));
			double fTemp1315 = fTemp201 + 0.0316 * fRec38[0] * (0.8946368384749803 * fTemp343 - 0.4230090591045155 * fTemp460) - fTemp200;
			double fTemp1316 = fRec306[(IOTA0 - iSlow509) & 1023];
			fVec301[0] = fTemp1316;
			iRec825[0] = (iRec825[1] + 1) * (fTemp1316 == 0.0);
			fRec826[0] = fTemp1316 + fRec826[1] * double(fVec301[1] >= fTemp1316);
			double fTemp1317 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec826[0], 1.0) - fSlow24 * double(iRec825[0]));
			double fTemp1318 = 0.0316 * fRec38[0] * (0.7873611177201383 * fTemp298 - 0.5648419091303367 * fTemp38) - fTemp41;
			double fTemp1319 = fRec277[(IOTA0 - iSlow510) & 1023];
			fVec302[0] = fTemp1319;
			iRec827[0] = (iRec827[1] + 1) * (fTemp1319 == 0.0);
			fRec828[0] = fTemp1319 + fRec828[1] * double(fVec302[1] >= fTemp1319);
			double fTemp1320 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec828[0], 1.0) - fSlow24 * double(iRec827[0]));
			double fTemp1321 = fTemp126 + 0.0316 * fRec38[0] * (0.41501878742928966 * fTemp361 + 0.3504204185810522 * fTemp127) - fTemp125;
			double fTemp1322 = fRec290[(IOTA0 - iSlow511) & 1023];
			fVec303[0] = fTemp1322;
			iRec829[0] = (iRec829[1] + 1) * (fTemp1322 == 0.0);
			fRec830[0] = fTemp1322 + fRec830[1] * double(fVec303[1] >= fTemp1322);
			double fTemp1323 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec830[0], 1.0) - fSlow24 * double(iRec829[0]));
			double fTemp1324 = fTemp422 + 0.0316 * fRec38[0] * (0.020260891418729443 * fTemp366 + 0.06103548414830584 * fTemp422);
			double fTemp1325 = fRec310[(IOTA0 - iSlow512) & 1023];
			fVec304[0] = fTemp1325;
			iRec831[0] = (iRec831[1] + 1) * (fTemp1325 == 0.0);
			fRec832[0] = fTemp1325 + fRec832[1] * double(fVec304[1] >= fTemp1325);
			double fTemp1326 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec832[0], 1.0) - fSlow24 * double(iRec831[0]));
			double fTemp1327 = fTemp89 + 0.0316 * fRec38[0] * (0.9340034850538359 * fTemp90 - 0.3734209680114873 * fTemp88) - fTemp85;
			double fTemp1328 = fRec318[(IOTA0 - iSlow513) & 1023];
			fVec305[0] = fTemp1328;
			iRec833[0] = (iRec833[1] + 1) * (fTemp1328 == 0.0);
			fRec834[0] = fTemp1328 + fRec834[1] * double(fVec305[1] >= fTemp1328);
			double fTemp1329 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec834[0], 1.0) - fSlow24 * double(iRec833[0]));
			double fTemp1330 = fRec38[0] * fTemp76;
			double fTemp1331 = fTemp77 - (fTemp73 + 0.05165983633278084 * fTemp1330);
			double fTemp1332 = fRec322[(IOTA0 - iSlow514) & 1023];
			fVec306[0] = fTemp1332;
			iRec835[0] = (iRec835[1] + 1) * (fTemp1332 == 0.0);
			fRec836[0] = fTemp1332 + fRec836[1] * double(fVec306[1] >= fTemp1332);
			double fTemp1333 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec836[0], 1.0) - fSlow24 * double(iRec835[0]));
			double fTemp1334 = fTemp445 + 0.02798196421158937 * fTemp892;
			double fTemp1335 = fRec334[(IOTA0 - iSlow515) & 1023];
			fVec307[0] = fTemp1335;
			iRec837[0] = (iRec837[1] + 1) * (fTemp1335 == 0.0);
			fRec838[0] = fTemp1335 + fRec838[1] * double(fVec307[1] >= fTemp1335);
			double fTemp1336 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec838[0], 1.0) - fSlow24 * double(iRec837[0]));
			double fTemp1337 = 0.0316 * fRec38[0] * (0.8872166126811862 * fTemp386 - 0.5379861427177275 * fTemp385) - fTemp385;
			double fTemp1338 = fRec326[(IOTA0 - iSlow516) & 1023];
			fVec308[0] = fTemp1338;
			iRec839[0] = (iRec839[1] + 1) * (fTemp1338 == 0.0);
			fRec840[0] = fTemp1338 + fRec840[1] * double(fVec308[1] >= fTemp1338);
			double fTemp1339 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec840[0], 1.0) - fSlow24 * double(iRec839[0]));
			double fTemp1340 = 0.0316 * fRec38[0] * (0.6017933762323082 * fTemp391 - 0.40012660735010286 * fTemp55) - fTemp52;
			double fTemp1341 = fRec330[(IOTA0 - iSlow517) & 1023];
			fVec309[0] = fTemp1341;
			iRec841[0] = (iRec841[1] + 1) * (fTemp1341 == 0.0);
			fRec842[0] = fTemp1341 + fRec842[1] * double(fVec309[1] >= fTemp1341);
			double fTemp1342 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec842[0], 1.0) - fSlow24 * double(iRec841[0]));
			double fTemp1343 = fTemp110 + 0.0316 * fRec38[0] * (0.8943662136225612 * fTemp111 + 0.7978498156953719 * fTemp114) - fTemp109;
			double fTemp1344 = fRec74[(IOTA0 - iSlow518) & 1023];
			fVec310[0] = fTemp1344;
			iRec843[0] = (iRec843[1] + 1) * (fTemp1344 == 0.0);
			fRec844[0] = fTemp1344 + fRec844[1] * double(fVec310[1] >= fTemp1344);
			double fTemp1345 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec844[0], 1.0) - fSlow24 * double(iRec843[0]));
			double fTemp1346 = fTemp350 + 0.0316 * fRec38[0] * (0.1385574110172456 * fTemp353 + 0.5243506951155723 * fTemp187);
			double fTemp1347 = fRec40[(IOTA0 - iSlow519) & 1023];
			fVec311[0] = fTemp1347;
			iRec845[0] = (iRec845[1] + 1) * (fTemp1347 == 0.0);
			fRec846[0] = fTemp1347 + fRec846[1] * double(fVec311[1] >= fTemp1347);
			double fTemp1348 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec846[0], 1.0) - fSlow24 * double(iRec845[0]));
			fRec847[0] = fSlow521 + fConst10 * fRec847[1];
			double fTemp1349 = fTemp616 + 0.03132746479851776 * fTemp63;
			double fTemp1350 = fRec168[(IOTA0 - iSlow522) & 1023];
			fVec312[0] = fTemp1350;
			iRec848[0] = (iRec848[1] + 1) * (fTemp1350 == 0.0);
			fRec849[0] = fTemp1350 + fRec849[1] * double(fVec312[1] >= fTemp1350);
			double fTemp1351 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec849[0], 1.0) - fSlow24 * double(iRec848[0]));
			double fTemp1352 = fTemp77 + 0.009738592608660111 * fTemp749 - fTemp73;
			double fTemp1353 = fRec62[(IOTA0 - iSlow523) & 1023];
			fVec313[0] = fTemp1353;
			iRec850[0] = (iRec850[1] + 1) * (fTemp1353 == 0.0);
			fRec851[0] = fTemp1353 + fRec851[1] * double(fVec313[1] >= fTemp1353);
			double fTemp1354 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec851[0], 1.0) - fSlow24 * double(iRec850[0]));
			double fTemp1355 = 0.0316 * fRec38[0] * (0.37163659449652187 * fTemp298 - 0.6429041208102717 * fTemp38) - fTemp41;
			double fTemp1356 = fRec40[(IOTA0 - iSlow524) & 1023];
			fVec314[0] = fTemp1356;
			iRec852[0] = (iRec852[1] + 1) * (fTemp1356 == 0.0);
			fRec853[0] = fTemp1356 + fRec853[1] * double(fVec314[1] >= fTemp1356);
			double fTemp1357 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec853[0], 1.0) - fSlow24 * double(iRec852[0]));
			double fTemp1358 = fTemp89 + 0.04307715687874297 * fTemp483 - fTemp85;
			double fTemp1359 = fRec68[(IOTA0 - iSlow525) & 1023];
			fVec315[0] = fTemp1359;
			iRec854[0] = (iRec854[1] + 1) * (fTemp1359 == 0.0);
			fRec855[0] = fTemp1359 + fRec855[1] * double(fVec315[1] >= fTemp1359);
			double fTemp1360 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec855[0], 1.0) - fSlow24 * double(iRec854[0]));
			double fTemp1361 = 0.046200345954523075 * fTemp999 - fTemp97;
			double fTemp1362 = fRec74[(IOTA0 - iSlow526) & 1023];
			fVec316[0] = fTemp1362;
			iRec856[0] = (iRec856[1] + 1) * (fTemp1362 == 0.0);
			fRec857[0] = fTemp1362 + fRec857[1] * double(fVec316[1] >= fTemp1362);
			double fTemp1363 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec857[0], 1.0) - fSlow24 * double(iRec856[0]));
			double fTemp1364 = fTemp422 + 0.0316 * fRec38[0] * (0.15220867991592968 * fTemp422 - 0.4577320267126197 * fTemp279);
			double fTemp1365 = fRec334[(IOTA0 - iSlow527) & 1023];
			fVec317[0] = fTemp1365;
			iRec858[0] = (iRec858[1] + 1) * (fTemp1365 == 0.0);
			fRec859[0] = fTemp1365 + fRec859[1] * double(fVec317[1] >= fTemp1365);
			double fTemp1366 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec859[0], 1.0) - fSlow24 * double(iRec858[0]));
			double fTemp1367 = fTemp126 + 0.0316 * fRec38[0] * (0.4375064988962549 * fTemp127 + 0.6677446085814154 * fTemp174) - fTemp125;
			double fTemp1368 = fRec330[(IOTA0 - iSlow528) & 1023];
			fVec318[0] = fTemp1368;
			iRec860[0] = (iRec860[1] + 1) * (fTemp1368 == 0.0);
			fRec861[0] = fTemp1368 + fRec861[1] * double(fVec318[1] >= fTemp1368);
			double fTemp1369 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec861[0], 1.0) - fSlow24 * double(iRec860[0]));
			double fTemp1370 = fTemp217 + 0.0316 * fRec38[0] * (0.5259902848920319 * fTemp386 - 0.02190456070820801 * fTemp385);
			double fTemp1371 = fRec310[(IOTA0 - iSlow529) & 1023];
			fVec319[0] = fTemp1371;
			iRec862[0] = (iRec862[1] + 1) * (fTemp1371 == 0.0);
			fRec863[0] = fTemp1371 + fRec863[1] * double(fVec319[1] >= fTemp1371);
			double fTemp1372 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec863[0], 1.0) - fSlow24 * double(iRec862[0]));
			double fTemp1373 = fTemp148 + 0.024484950362757083 * fTemp749 - fTemp147;
			double fTemp1374 = fRec290[(IOTA0 - iSlow530) & 1023];
			fVec320[0] = fTemp1374;
			iRec864[0] = (iRec864[1] + 1) * (fTemp1374 == 0.0);
			fRec865[0] = fTemp1374 + fRec865[1] * double(fVec320[1] >= fTemp1374);
			double fTemp1375 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec865[0], 1.0) - fSlow24 * double(iRec864[0]));
			double fTemp1376 = 0.0316 * fRec38[0] * (0.6148547018879071 * fTemp90 - 0.9452459556851807 * fTemp88) - fTemp66;
			double fTemp1377 = fRec306[(IOTA0 - iSlow531) & 1023];
			fVec321[0] = fTemp1377;
			iRec866[0] = (iRec866[1] + 1) * (fTemp1377 == 0.0);
			fRec867[0] = fTemp1377 + fRec867[1] * double(fVec321[1] >= fTemp1377);
			double fTemp1378 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec867[0], 1.0) - fSlow24 * double(iRec866[0]));
			double fTemp1379 = fTemp101 - (fTemp100 + 0.019253995273628973 * fTemp1087);
			double fTemp1380 = fRec302[(IOTA0 - iSlow532) & 1023];
			fVec322[0] = fTemp1380;
			iRec868[0] = (iRec868[1] + 1) * (fTemp1380 == 0.0);
			fRec869[0] = fTemp1380 + fRec869[1] * double(fVec322[1] >= fTemp1380);
			double fTemp1381 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec869[0], 1.0) - fSlow24 * double(iRec868[0]));
			double fTemp1382 = 0.044895035180429116 * fTemp648 - fTemp279;
			double fTemp1383 = fRec298[(IOTA0 - iSlow533) & 1023];
			fVec323[0] = fTemp1383;
			iRec870[0] = (iRec870[1] + 1) * (fTemp1383 == 0.0);
			fRec871[0] = fTemp1383 + fRec871[1] * double(fVec323[1] >= fTemp1383);
			double fTemp1384 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec871[0], 1.0) - fSlow24 * double(iRec870[0]));
			double fTemp1385 = fTemp173 + 0.026400537031487332 * fTemp128 - fTemp172;
			double fTemp1386 = fRec294[(IOTA0 - iSlow534) & 1023];
			fVec324[0] = fTemp1386;
			iRec872[0] = (iRec872[1] + 1) * (fTemp1386 == 0.0);
			fRec873[0] = fTemp1386 + fRec873[1] * double(fVec324[1] >= fTemp1386);
			double fTemp1387 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec873[0], 1.0) - fSlow24 * double(iRec872[0]));
			double fTemp1388 = fRec38[0] * fTemp182;
			double fTemp1389 = fTemp353 - 0.03164319491795032 * fTemp1388;
			double fTemp1390 = fRec286[(IOTA0 - iSlow535) & 1023];
			fVec325[0] = fTemp1390;
			iRec874[0] = (iRec874[1] + 1) * (fTemp1390 == 0.0);
			fRec875[0] = fTemp1390 + fRec875[1] * double(fVec325[1] >= fTemp1390);
			double fTemp1391 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec875[0], 1.0) - fSlow24 * double(iRec874[0]));
			double fTemp1392 = 0.0316 * fRec38[0] * (0.6945140525640454 * fTemp202 - 0.09794674285512883 * fTemp460) - fTemp342;
			double fTemp1393 = fRec281[(IOTA0 - iSlow536) & 1023];
			fVec326[0] = fTemp1393;
			iRec876[0] = (iRec876[1] + 1) * (fTemp1393 == 0.0);
			fRec877[0] = fTemp1393 + fRec877[1] * double(fVec326[1] >= fTemp1393);
			double fTemp1394 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec877[0], 1.0) - fSlow24 * double(iRec876[0]));
			double fTemp1395 = fTemp114 + 0.0316 * fRec38[0] * (0.439530031690083 * fTemp252 + 0.42945916190728894 * fTemp335);
			double fTemp1396 = fRec80[(IOTA0 - iSlow537) & 1023];
			fVec327[0] = fTemp1396;
			iRec878[0] = (iRec878[1] + 1) * (fTemp1396 == 0.0);
			fRec879[0] = fTemp1396 + fRec879[1] * double(fVec327[1] >= fTemp1396);
			double fTemp1397 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec879[0], 1.0) - fSlow24 * double(iRec878[0]));
			double fTemp1398 = fTemp264 + 0.0316 * fRec38[0] * (0.7445625357668177 * fTemp856 + 0.20465245868490456 * fTemp445) - fTemp263;
			double fTemp1399 = fRec273[(IOTA0 - iSlow538) & 1023];
			fVec328[0] = fTemp1399;
			iRec880[0] = (iRec880[1] + 1) * (fTemp1399 == 0.0);
			fRec881[0] = fTemp1399 + fRec881[1] * double(fVec328[1] >= fTemp1399);
			double fTemp1400 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec881[0], 1.0) - fSlow24 * double(iRec880[0]));
			double fTemp1401 = fTemp285 + 0.0316 * fRec38[0] * (0.7891575183020905 * fTemp284 + 0.7754864353901212 * fTemp422) - fTemp276;
			double fTemp1402 = fRec252[(IOTA0 - iSlow539) & 1023];
			fVec329[0] = fTemp1402;
			iRec882[0] = (iRec882[1] + 1) * (fTemp1402 == 0.0);
			fRec883[0] = fTemp1402 + fRec883[1] * double(fVec329[1] >= fTemp1402);
			double fTemp1403 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec883[0], 1.0) - fSlow24 * double(iRec882[0]));
			double fTemp1404 = fTemp253 + 0.0316 * fRec38[0] * (0.3746209133823868 * fTemp252 + 0.8550597390421899 * fTemp114) - fTemp249;
			double fTemp1405 = fRec239[(IOTA0 - iSlow540) & 1023];
			fVec330[0] = fTemp1405;
			iRec884[0] = (iRec884[1] + 1) * (fTemp1405 == 0.0);
			fRec885[0] = fTemp1405 + fRec885[1] * double(fVec330[1] >= fTemp1405);
			double fTemp1406 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec885[0], 1.0) - fSlow24 * double(iRec884[0]));
			double fTemp1407 = fTemp226 - (fTemp225 + 0.0316 * fRec38[0] * (0.296742861834673 * fTemp144 + 0.328061007483484 * fTemp76));
			double fTemp1408 = fRec221[(IOTA0 - iSlow541) & 1023];
			fVec331[0] = fTemp1408;
			iRec886[0] = (iRec886[1] + 1) * (fTemp1408 == 0.0);
			fRec887[0] = fTemp1408 + fRec887[1] * double(fVec331[1] >= fTemp1408);
			double fTemp1409 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec887[0], 1.0) - fSlow24 * double(iRec886[0]));
			double fTemp1410 = fTemp360 - 0.05164720516261296 * fRec38[0] * fTemp20;
			double fTemp1411 = fRec209[(IOTA0 - iSlow542) & 1023];
			fVec332[0] = fTemp1411;
			iRec888[0] = (iRec888[1] + 1) * (fTemp1411 == 0.0);
			fRec889[0] = fTemp1411 + fRec889[1] * double(fVec332[1] >= fTemp1411);
			double fTemp1412 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec889[0], 1.0) - fSlow24 * double(iRec888[0]));
			double fTemp1413 = 0.03867670571547788 * fRec38[0] * fTemp554 - fTemp182;
			double fTemp1414 = fRec204[(IOTA0 - iSlow543) & 1023];
			fVec333[0] = fTemp1414;
			iRec890[0] = (iRec890[1] + 1) * (fTemp1414 == 0.0);
			fRec891[0] = fTemp1414 + fRec891[1] * double(fVec333[1] >= fTemp1414);
			double fTemp1415 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec891[0], 1.0) - fSlow24 * double(iRec890[0]));
			double fTemp1416 = fTemp831 + 0.0316 * fRec38[0] * (0.9972330294367566 * fTemp343 - 0.7637059584376402 * fTemp342) - fTemp830;
			double fTemp1417 = fRec198[(IOTA0 - iSlow544) & 1023];
			fVec334[0] = fTemp1417;
			iRec892[0] = (iRec892[1] + 1) * (fTemp1417 == 0.0);
			fRec893[0] = fTemp1417 + fRec893[1] * double(fVec334[1] >= fTemp1417);
			double fTemp1418 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec893[0], 1.0) - fSlow24 * double(iRec892[0]));
			double fTemp1419 = fTemp333 + 0.02637985327674869 * fTemp1211 - fTemp332;
			double fTemp1420 = fRec193[(IOTA0 - iSlow545) & 1023];
			fVec335[0] = fTemp1420;
			iRec894[0] = (iRec894[1] + 1) * (fTemp1420 == 0.0);
			fRec895[0] = fTemp1420 + fRec895[1] * double(fVec335[1] >= fTemp1420);
			double fTemp1421 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec895[0], 1.0) - fSlow24 * double(iRec894[0]));
			double fTemp1422 = fTemp855 + 0.0316 * fRec38[0] * (0.5447369410576357 * fTemp324 + 0.42575967795346514 * fTemp265) - fTemp854;
			double fTemp1423 = fRec188[(IOTA0 - iSlow546) & 1023];
			fVec336[0] = fTemp1423;
			iRec896[0] = (iRec896[1] + 1) * (fTemp1423 == 0.0);
			fRec897[0] = fTemp1423 + fRec897[1] * double(fVec336[1] >= fTemp1423);
			double fTemp1424 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec897[0], 1.0) - fSlow24 * double(iRec896[0]));
			double fTemp1425 = fTemp236 + 0.029896865092215015 * fTemp536;
			double fTemp1426 = fRec184[(IOTA0 - iSlow547) & 1023];
			fVec337[0] = fTemp1426;
			iRec898[0] = (iRec898[1] + 1) * (fTemp1426 == 0.0);
			fRec899[0] = fTemp1426 + fRec899[1] * double(fVec337[1] >= fTemp1426);
			double fTemp1427 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec899[0], 1.0) - fSlow24 * double(iRec898[0]));
			double fTemp1428 = fTemp777 + 0.0316 * fRec38[0] * (0.6380722582980525 * fTemp386 + 0.9140135032721446 * fTemp214) - fTemp776;
			double fTemp1429 = fRec179[(IOTA0 - iSlow548) & 1023];
			fVec338[0] = fTemp1429;
			iRec900[0] = (iRec900[1] + 1) * (fTemp1429 == 0.0);
			fRec901[0] = fTemp1429 + fRec901[1] * double(fVec338[1] >= fTemp1429);
			double fTemp1430 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec901[0], 1.0) - fSlow24 * double(iRec900[0]));
			double fTemp1431 = 0.0316 * fRec38[0] * (0.5873634781964938 * fTemp377 - 0.4212099336218671 * fTemp76) - fTemp144;
			double fTemp1432 = fRec100[(IOTA0 - iSlow549) & 1023];
			fVec339[0] = fTemp1432;
			iRec902[0] = (iRec902[1] + 1) * (fTemp1432 == 0.0);
			fRec903[0] = fTemp1432 + fRec903[1] * double(fVec339[1] >= fTemp1432);
			double fTemp1433 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec903[0], 1.0) - fSlow24 * double(iRec902[0]));
			double fTemp1434 = fTemp584 - 0.0316 * fRec38[0] * (0.7090467131347395 * fTemp23 + 0.9590943131042877 * fTemp26);
			double fTemp1435 = fRec174[(IOTA0 - iSlow550) & 1023];
			fVec340[0] = fTemp1435;
			iRec904[0] = (iRec904[1] + 1) * (fTemp1435 == 0.0);
			fRec905[0] = fTemp1435 + fRec905[1] * double(fVec340[1] >= fTemp1435);
			double fTemp1436 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec905[0], 1.0) - fSlow24 * double(iRec904[0]));
			double fTemp1437 = ((iTemp14) ? 0.0 : fConst429 + fRec906[1]);
			fRec906[0] = fTemp1437 - std::floor(fTemp1437);
			int iTemp1438 = std::max<int>(0, std::min<int>(int(65536.0 * fRec906[0]), 65535));
			double fTemp1439 = 0.9906534850748874 * ftbl1TonewheelSIG1[iTemp1438] + 0.13640261181143049 * ftbl0TonewheelSIG0[iTemp1438];
			double fTemp1440 = ((iTemp14) ? 0.0 : fConst430 + fRec907[1]);
			fRec907[0] = fTemp1440 - std::floor(fTemp1440);
			int iTemp1441 = std::max<int>(0, std::min<int>(int(65536.0 * fRec907[0]), 65535));
			double fTemp1442 = 0.8017191674543389 * ftbl0TonewheelSIG0[iTemp1441];
			double fTemp1443 = 0.5977009089304798 * ftbl1TonewheelSIG1[iTemp1441];
			double fTemp1444 = fTemp1443 - fTemp1442;
			double fTemp1445 = fTemp160 + 0.0316 * fRec38[0] * (0.9193672070252887 * fTemp1444 - 0.4617391516121643 * fTemp1439) - fTemp159;
			double fTemp1446 = fRec106[(IOTA0 - iSlow551) & 1023];
			fVec341[0] = fTemp1446;
			iRec908[0] = (iRec908[1] + 1) * (fTemp1446 == 0.0);
			fRec909[0] = fTemp1446 + fRec909[1] * double(fVec341[1] >= fTemp1446);
			double fTemp1447 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec909[0], 1.0) - fSlow24 * double(iRec908[0]));
			double fTemp1448 = fTemp597 + 0.0316 * fRec38[0] * (0.45221132982260315 * fTemp1007 + 0.9170742171463644 * fTemp366) - fTemp596;
			double fTemp1449 = fRec164[(IOTA0 - iSlow552) & 1023];
			fVec342[0] = fTemp1449;
			iRec910[0] = (iRec910[1] + 1) * (fTemp1449 == 0.0);
			fRec911[0] = fTemp1449 + fRec911[1] * double(fVec342[1] >= fTemp1449);
			double fTemp1450 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec911[0], 1.0) - fSlow24 * double(iRec910[0]));
			double fTemp1451 = fTemp560 + 0.053581221565767195 * fRec38[0] * fTemp1024;
			double fTemp1452 = fRec125[(IOTA0 - iSlow553) & 1023];
			fVec343[0] = fTemp1452;
			iRec912[0] = (iRec912[1] + 1) * (fTemp1452 == 0.0);
			fRec913[0] = fTemp1452 + fRec913[1] * double(fVec343[1] >= fTemp1452);
			double fTemp1453 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec913[0], 1.0) - fSlow24 * double(iRec912[0]));
			double fTemp1454 = fTemp268 + 0.0316 * fRec38[0] * (0.18852682528813602 * fTemp856 + 0.9456122970223078 * fTemp1251);
			double fTemp1455 = fRec157[(IOTA0 - iSlow554) & 1023];
			fVec344[0] = fTemp1455;
			iRec914[0] = (iRec914[1] + 1) * (fTemp1455 == 0.0);
			fRec915[0] = fTemp1455 + fRec915[1] * double(fVec344[1] >= fTemp1455);
			double fTemp1456 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec915[0], 1.0) - fSlow24 * double(iRec914[0]));
			double fTemp1457 = fTemp844 + 0.0316 * fRec38[0] * (0.5747128537077515 * fTemp35 - 0.4296339331413037 * fTemp144) - fTemp843;
			double fTemp1458 = fRec137[(IOTA0 - iSlow555) & 1023];
			fVec345[0] = fTemp1458;
			iRec916[0] = (iRec916[1] + 1) * (fTemp1458 == 0.0);
			fRec917[0] = fTemp1458 + fRec917[1] * double(fVec345[1] >= fTemp1458);
			double fTemp1459 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec917[0], 1.0) - fSlow24 * double(iRec916[0]));
			double fTemp1460 = ((iTemp14) ? 0.0 : fConst436 + fRec918[1]);
			fRec918[0] = fTemp1460 - std::floor(fTemp1460);
			int iTemp1461 = std::max<int>(0, std::min<int>(int(65536.0 * fRec918[0]), 65535));
			double fTemp1462 = 0.91925736486387 * ftbl1TonewheelSIG1[iTemp1461] + 0.39365708064701915 * ftbl0TonewheelSIG0[iTemp1461];
			double fTemp1463 = fTemp240 - (fTemp239 + 0.014102442936498484 * fRec38[0] * fTemp1462);
			double fTemp1464 = fRec144[(IOTA0 - iSlow556) & 1023];
			fVec346[0] = fTemp1464;
			iRec919[0] = (iRec919[1] + 1) * (fTemp1464 == 0.0);
			fRec920[0] = fTemp1464 + fRec920[1] * double(fVec346[1] >= fTemp1464);
			double fTemp1465 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec920[0], 1.0) - fSlow24 * double(iRec919[0]));
			double fTemp1466 = fTemp214 + 0.0316 * fRec38[0] * (0.5825791457809828 * fTemp1035 + 0.06988405934134789 * fTemp309);
			double fTemp1467 = fRec132[(IOTA0 - iSlow557) & 1023];
			fVec347[0] = fTemp1467;
			iRec921[0] = (iRec921[1] + 1) * (fTemp1467 == 0.0);
			fRec922[0] = fTemp1467 + fRec922[1] * double(fVec347[1] >= fTemp1467);
			double fTemp1468 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec922[0], 1.0) - fSlow24 * double(iRec921[0]));
			double fTemp1469 = fTemp567 + 0.0316 * fRec38[0] * (0.43524170254386263 * fTemp334 + 0.4885468137144926 * fTemp335) - fTemp566;
			double fTemp1470 = fRec150[(IOTA0 - iSlow558) & 1023];
			fVec348[0] = fTemp1470;
			iRec923[0] = (iRec923[1] + 1) * (fTemp1470 == 0.0);
			fRec924[0] = fTemp1470 + fRec924[1] * double(fVec348[1] >= fTemp1470);
			double fTemp1471 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec924[0], 1.0) - fSlow24 * double(iRec923[0]));
			double fTemp1472 = fTemp553 + 0.0316 * fRec38[0] * (0.6593887416165671 * fTemp1018 + 0.09789942535280716 * fTemp190) - fTemp552;
			double fTemp1473 = fRec119[(IOTA0 - iSlow559) & 1023];
			fVec349[0] = fTemp1473;
			iRec925[0] = (iRec925[1] + 1) * (fTemp1473 == 0.0);
			fRec926[0] = fTemp1473 + fRec926[1] * double(fVec349[1] >= fTemp1473);
			double fTemp1474 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec926[0], 1.0) - fSlow24 * double(iRec925[0]));
			double fTemp1475 = 0.0316 * fRec38[0] * (0.544828934056568 * fTemp361 + 0.16293832615338033 * fTemp360) - fTemp17;
			double fTemp1476 = fRec112[(IOTA0 - iSlow560) & 1023];
			fVec350[0] = fTemp1476;
			iRec927[0] = (iRec927[1] + 1) * (fTemp1476 == 0.0);
			fRec928[0] = fTemp1476 + fRec928[1] * double(fVec350[1] >= fTemp1476);
			double fTemp1477 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec928[0], 1.0) - fSlow24 * double(iRec927[0]));
			double fTemp1478 = fTemp283 + 0.0316 * fRec38[0] * (0.4935257133693085 * fTemp1007 - 0.6717414544691565 * fTemp279) - fTemp282;
			double fTemp1479 = fRec213[(IOTA0 - iSlow561) & 1023];
			fVec351[0] = fTemp1479;
			iRec929[0] = (iRec929[1] + 1) * (fTemp1479 == 0.0);
			fRec930[0] = fTemp1479 + fRec930[1] * double(fVec351[1] >= fTemp1479);
			double fTemp1480 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec930[0], 1.0) - fSlow24 * double(iRec929[0]));
			double fTemp1481 = fTemp136 + 0.0316 * fRec38[0] * (0.500911806266231 * fTemp161 + 0.8968715672090184 * fTemp102) - fTemp135;
			double fTemp1482 = fRec94[(IOTA0 - iSlow562) & 1023];
			fVec352[0] = fTemp1482;
			iRec931[0] = (iRec931[1] + 1) * (fTemp1482 == 0.0);
			fRec932[0] = fTemp1482 + fRec932[1] * double(fVec352[1] >= fTemp1482);
			double fTemp1483 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec932[0], 1.0) - fSlow24 * double(iRec931[0]));
			double fTemp1484 = 0.0316 * fRec38[0] * (0.5763671276472451 * fTemp1223 - 0.4439060952900036 * fTemp66) - fTemp62;
			double fTemp1485 = fRec56[(IOTA0 - iSlow563) & 1023];
			fVec353[0] = fTemp1485;
			iRec933[0] = (iRec933[1] + 1) * (fTemp1485 == 0.0);
			fRec934[0] = fTemp1485 + fRec934[1] * double(fVec353[1] >= fTemp1485);
			double fTemp1486 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec934[0], 1.0) - fSlow24 * double(iRec933[0]));
			double fTemp1487 = fTemp301 + 0.0316 * fRec38[0] * (0.03640094202637556 * fTemp584 - 0.35472860330082767 * fTemp23);
			double fTemp1488 = fRec217[(IOTA0 - iSlow564) & 1023];
			fVec354[0] = fTemp1488;
			iRec935[0] = (iRec935[1] + 1) * (fTemp1488 == 0.0);
			fRec936[0] = fTemp1488 + fRec936[1] * double(fVec354[1] >= fTemp1488);
			double fTemp1489 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec936[0], 1.0) - fSlow24 * double(iRec935[0]));
			double fTemp1490 = fTemp218 + 0.0316 * fRec38[0] * (0.2940477887786983 * fTemp386 + 0.7095008052856429 * fTemp778) - fTemp211;
			double fTemp1491 = fRec226[(IOTA0 - iSlow565) & 1023];
			fVec355[0] = fTemp1491;
			iRec937[0] = (iRec937[1] + 1) * (fTemp1491 == 0.0);
			fRec938[0] = fTemp1491 + fRec938[1] * double(fVec355[1] >= fTemp1491);
			double fTemp1492 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec938[0], 1.0) - fSlow24 * double(iRec937[0]));
			double fTemp1493 = fTemp242 + 0.0316 * fRec38[0] * (0.09794080699066399 * fTemp391 + 0.6583984605022124 * fTemp241) - fTemp233;
			double fTemp1494 = fRec230[(IOTA0 - iSlow566) & 1023];
			fVec356[0] = fTemp1494;
			iRec939[0] = (iRec939[1] + 1) * (fTemp1494 == 0.0);
			fRec940[0] = fTemp1494 + fRec940[1] * double(fVec356[1] >= fTemp1494);
			double fTemp1495 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec940[0], 1.0) - fSlow24 * double(iRec939[0]));
			double fTemp1496 = fTemp269 + 0.0316 * fRec38[0] * (0.7363149401571718 * fTemp268 + 0.4479333905255771 * fTemp446) - fTemp260;
			double fTemp1497 = fRec235[(IOTA0 - iSlow567) & 1023];
			fVec357[0] = fTemp1497;
			iRec941[0] = (iRec941[1] + 1) * (fTemp1497 == 0.0);
			fRec942[0] = fTemp1497 + fRec942[1] * double(fVec357[1] >= fTemp1497);
			double fTemp1498 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec942[0], 1.0) - fSlow24 * double(iRec941[0]));
			double fTemp1499 = fTemp204 + 0.042171953849363494 * fRec38[0] * fTemp560 - fTemp197;
			double fTemp1500 = fRec243[(IOTA0 - iSlow568) & 1023];
			fVec358[0] = fTemp1500;
			iRec943[0] = (iRec943[1] + 1) * (fTemp1500 == 0.0);
			fRec944[0] = fTemp1500 + fRec944[1] * double(fVec358[1] >= fTemp1500);
			double fTemp1501 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec944[0], 1.0) - fSlow24 * double(iRec943[0]));
			double fTemp1502 = fTemp190 - 0.04185131050605705 * fTemp1388;
			double fTemp1503 = fRec247[(IOTA0 - iSlow569) & 1023];
			fVec359[0] = fTemp1503;
			iRec945[0] = (iRec945[1] + 1) * (fTemp1503 == 0.0);
			fRec946[0] = fTemp1503 + fRec946[1] * double(fVec359[1] >= fTemp1503);
			double fTemp1504 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec946[0], 1.0) - fSlow24 * double(iRec945[0]));
			double fTemp1505 = fTemp175 + 0.023931554643478195 * fTemp906 - fTemp169;
			double fTemp1506 = fRec89[(IOTA0 - iSlow570) & 1023];
			fVec360[0] = fTemp1506;
			iRec947[0] = (iRec947[1] + 1) * (fTemp1506 == 0.0);
			fRec948[0] = fTemp1506 + fRec948[1] * double(fVec360[1] >= fTemp1506);
			double fTemp1507 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec948[0], 1.0) - fSlow24 * double(iRec947[0]));
			double fTemp1508 = fTemp162 + 0.0316 * fRec38[0] * (0.5646412480637082 * fTemp161 + 0.42782991863350617 * fTemp102) - fTemp156;
			double fTemp1509 = fRec84[(IOTA0 - iSlow571) & 1023];
			fVec361[0] = fTemp1509;
			iRec949[0] = (iRec949[1] + 1) * (fTemp1509 == 0.0);
			fRec950[0] = fTemp1509 + fRec950[1] * double(fVec361[1] >= fTemp1509);
			double fTemp1510 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec950[0], 1.0) - fSlow24 * double(iRec949[0]));
			double fTemp1511 = 0.004759089564922033 * fTemp483 - fTemp88;
			double fTemp1512 = fRec256[(IOTA0 - iSlow572) & 1023];
			fVec362[0] = fTemp1512;
			iRec951[0] = (iRec951[1] + 1) * (fTemp1512 == 0.0);
			fRec952[0] = fTemp1512 + fRec952[1] * double(fVec362[1] >= fTemp1512);
			double fTemp1513 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec952[0], 1.0) - fSlow24 * double(iRec951[0]));
			double fTemp1514 = 0.0316 * fRec38[0] * (0.3678586519890814 * fTemp584 - 0.9974470363231376 * fTemp41) - fTemp38;
			double fTemp1515 = fRec260[(IOTA0 - iSlow573) & 1023];
			fVec363[0] = fTemp1515;
			iRec953[0] = (iRec953[1] + 1) * (fTemp1515 == 0.0);
			fRec954[0] = fTemp1515 + fRec954[1] * double(fVec363[1] >= fTemp1515);
			double fTemp1516 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec954[0], 1.0) - fSlow24 * double(iRec953[0]));
			double fTemp1517 = 0.0316 * fRec38[0] * (0.48400800607487326 * fTemp377 - 0.08044101366976975 * fTemp144) - fTemp76;
			double fTemp1518 = fRec264[(IOTA0 - iSlow574) & 1023];
			fVec364[0] = fTemp1518;
			iRec955[0] = (iRec955[1] + 1) * (fTemp1518 == 0.0);
			fRec956[0] = fTemp1518 + fRec956[1] * double(fVec364[1] >= fTemp1518);
			double fTemp1519 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec956[0], 1.0) - fSlow24 * double(iRec955[0]));
			double fTemp1520 = fTemp310 + 0.0316 * fRec38[0] * (0.8164138675492723 * fTemp309 - 0.8051668332445843 * fTemp385) - fTemp308;
			double fTemp1521 = fRec268[(IOTA0 - iSlow575) & 1023];
			fVec365[0] = fTemp1521;
			iRec957[0] = (iRec957[1] + 1) * (fTemp1521 == 0.0);
			fRec958[0] = fTemp1521 + fRec958[1] * double(fVec365[1] >= fTemp1521);
			double fTemp1522 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec958[0], 1.0) - fSlow24 * double(iRec957[0]));
			double fTemp1523 = fTemp319 + 0.0316 * fRec38[0] * (0.8870028715300577 * fTemp236 - 0.46931783559739415 * fTemp52) - fTemp317;
			double fTemp1524 = fRec50[(IOTA0 - iSlow576) & 1023];
			fVec366[0] = fTemp1524;
			iRec959[0] = (iRec959[1] + 1) * (fTemp1524 == 0.0);
			fRec960[0] = fTemp1524 + fRec960[1] * double(fVec366[1] >= fTemp1524);
			double fTemp1525 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec960[0], 1.0) - fSlow24 * double(iRec959[0]));
			double fTemp1526 = fTemp297 - (fTemp296 + 0.0316 * fRec38[0] * (0.869773296331914 * fTemp38 + 0.6998014765740663 * fTemp41));
			double fTemp1527 = fRec44[(IOTA0 - iSlow577) & 1023];
			fVec367[0] = fTemp1527;
			iRec961[0] = (iRec961[1] + 1) * (fTemp1527 == 0.0);
			fRec962[0] = fTemp1527 + fRec962[1] * double(fVec367[1] >= fTemp1527);
			double fTemp1528 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec962[0], 1.0) - fSlow24 * double(iRec961[0]));
			double fTemp1529 = 0.0316 * fRec38[0] * (0.526670107836253 * fTemp318 - 0.7482387604395626 * fTemp52) - fTemp55;
			double fTemp1530 = fRec314[(IOTA0 - iSlow578) & 1023];
			fVec368[0] = fTemp1530;
			iRec963[0] = (iRec963[1] + 1) * (fTemp1530 == 0.0);
			fRec964[0] = fTemp1530 + fRec964[1] * double(fVec368[1] >= fTemp1530);
			double fTemp1531 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec964[0], 1.0) - fSlow24 * double(iRec963[0]));
			double fTemp1532 = fTemp400 + 0.0316 * fRec38[0] * (0.4527814042448881 * fTemp324 + 0.8676701860167668 * fTemp265) - fTemp398;
			double fTemp1533 = fRec318[(IOTA0 - iSlow579) & 1023];
			fVec369[0] = fTemp1533;
			iRec965[0] = (iRec965[1] + 1) * (fTemp1533 == 0.0);
			fRec966[0] = fTemp1533 + fRec966[1] * double(fVec369[1] >= fTemp1533);
			double fTemp1534 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec966[0], 1.0) - fSlow24 * double(iRec965[0]));
			double fTemp1535 = fTemp252 + 0.0316 * fRec38[0] * (0.5940022875038267 * fTemp111 + 0.2303078539807757 * fTemp335);
			double fTemp1536 = fRec277[(IOTA0 - iSlow580) & 1023];
			fVec370[0] = fTemp1536;
			iRec967[0] = (iRec967[1] + 1) * (fTemp1536 == 0.0);
			fRec968[0] = fTemp1536 + fRec968[1] * double(fVec370[1] >= fTemp1536);
			double fTemp1537 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec968[0], 1.0) - fSlow24 * double(iRec967[0]));
			double fTemp1538 = fTemp201 + 0.029967702558067324 * fTemp638 - fTemp200;
			double fTemp1539 = fRec322[(IOTA0 - iSlow581) & 1023];
			fVec371[0] = fTemp1539;
			iRec969[0] = (iRec969[1] + 1) * (fTemp1539 == 0.0);
			fRec970[0] = fTemp1539 + fRec970[1] * double(fVec371[1] >= fTemp1539);
			double fTemp1540 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec970[0], 1.0) - fSlow24 * double(iRec969[0]));
			double fTemp1541 = fTemp186 + 0.046281264999801355 * fTemp712 - fTemp185;
			double fTemp1542 = fRec326[(IOTA0 - iSlow582) & 1023];
			fVec372[0] = fTemp1542;
			iRec971[0] = (iRec971[1] + 1) * (fTemp1542 == 0.0);
			fRec972[0] = fTemp1542 + fRec972[1] * double(fVec372[1] >= fTemp1542);
			double fTemp1543 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec972[0], 1.0) - fSlow24 * double(iRec971[0]));
			fRec973[0] = fSlow584 + fConst10 * fRec973[1];
			double fTemp1544 = fTemp66 + 0.041079858978270205 * fTemp63;
			double fTemp1545 = fRec68[(IOTA0 - iSlow585) & 1023];
			fVec373[0] = fTemp1545;
			iRec974[0] = (iRec974[1] + 1) * (fTemp1545 == 0.0);
			fRec975[0] = fTemp1545 + fRec975[1] * double(fVec373[1] >= fTemp1545);
			double fTemp1546 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec975[0], 1.0) - fSlow24 * double(iRec974[0]));
			double fTemp1547 = fTemp76 + 0.03653615261829982 * fRec38[0] * fTemp144;
			double fTemp1548 = fRec290[(IOTA0 - iSlow586) & 1023];
			fVec374[0] = fTemp1548;
			iRec976[0] = (iRec976[1] + 1) * (fTemp1548 == 0.0);
			fRec977[0] = fTemp1548 + fRec977[1] * double(fVec374[1] >= fTemp1548);
			double fTemp1549 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec977[0], 1.0) - fSlow24 * double(iRec976[0]));
			double fTemp1550 = fTemp62 + 0.0316 * fRec38[0] * (0.22145142344379565 * fTemp66 + 0.5298074063903186 * fTemp88);
			double fTemp1551 = fRec256[(IOTA0 - iSlow587) & 1023];
			fVec375[0] = fTemp1551;
			iRec978[0] = (iRec978[1] + 1) * (fTemp1551 == 0.0);
			fRec979[0] = fTemp1551 + fRec979[1] * double(fVec375[1] >= fTemp1551);
			double fTemp1552 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec979[0], 1.0) - fSlow24 * double(iRec978[0]));
			double fTemp1553 = fTemp144 + 0.0316 * fRec38[0] * (0.32015738124209747 * fTemp76 + 0.4745392668337445 * fTemp32);
			double fTemp1554 = fRec221[(IOTA0 - iSlow588) & 1023];
			fVec376[0] = fTemp1554;
			iRec980[0] = (iRec980[1] + 1) * (fTemp1554 == 0.0);
			fRec981[0] = fTemp1554 + fRec981[1] * double(fVec376[1] >= fTemp1554);
			double fTemp1555 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec981[0], 1.0) - fSlow24 * double(iRec980[0]));
			double fTemp1556 = fTemp616 + 0.0316 * fRec38[0] * (0.3331743119597377 * fTemp62 + 0.7093703177342832 * fTemp88);
			double fTemp1557 = fRec56[(IOTA0 - iSlow589) & 1023];
			fVec377[0] = fTemp1557;
			iRec982[0] = (iRec982[1] + 1) * (fTemp1557 == 0.0);
			fRec983[0] = fTemp1557 + fRec983[1] * double(fVec377[1] >= fTemp1557);
			double fTemp1558 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec983[0], 1.0) - fSlow24 * double(iRec982[0]));
			double fTemp1559 = fTemp148 + 0.0316 * fRec38[0] * (0.46419737040650944 * fTemp377 + 0.7499107706948962 * fTemp78) - fTemp147;
			double fTemp1560 = fRec62[(IOTA0 - iSlow590) & 1023];
			fVec378[0] = fTemp1560;
			iRec984[0] = (iRec984[1] + 1) * (fTemp1560 == 0.0);
			fRec985[0] = fTemp1560 + fRec985[1] * double(fVec378[1] >= fTemp1560);
			double fTemp1561 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec985[0], 1.0) - fSlow24 * double(iRec984[0]));
			double fTemp1562 = fTemp297 + 0.0316 * fRec38[0] * (0.5192652206133062 * fTemp301 - 0.749460824757989 * fTemp41) - fTemp296;
			double fTemp1563 = fRec40[(IOTA0 - iSlow591) & 1023];
			fVec379[0] = fTemp1563;
			iRec986[0] = (iRec986[1] + 1) * (fTemp1563 == 0.0);
			fRec987[0] = fTemp1563 + fRec987[1] * double(fVec379[1] >= fTemp1563);
			double fTemp1564 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec987[0], 1.0) - fSlow24 * double(iRec986[0]));
			double fTemp1565 = fTemp101 + 0.0316 * fRec38[0] * (0.11743695472978288 * fTemp137 - 0.20866038210806437 * fTemp97) - fTemp100;
			double fTemp1566 = fRec74[(IOTA0 - iSlow592) & 1023];
			fVec380[0] = fTemp1566;
			iRec988[0] = (iRec988[1] + 1) * (fTemp1566 == 0.0);
			fRec989[0] = fTemp1566 + fRec989[1] * double(fVec380[1] >= fTemp1566);
			double fTemp1567 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec989[0], 1.0) - fSlow24 * double(iRec988[0]));
			double fTemp1568 = fRec38[0] * fTemp284;
			double fTemp1569 = 0.03929634773830185 * fTemp1568 - fTemp279;
			double fTemp1570 = fRec334[(IOTA0 - iSlow593) & 1023];
			fVec381[0] = fTemp1570;
			iRec990[0] = (iRec990[1] + 1) * (fTemp1570 == 0.0);
			fRec991[0] = fTemp1570 + fRec991[1] * double(fVec381[1] >= fTemp1570);
			double fTemp1571 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec991[0], 1.0) - fSlow24 * double(iRec990[0]));
			double fTemp1572 = fTemp173 + 0.01633381175294344 * fRec38[0] * fTemp360 - fTemp172;
			double fTemp1573 = fRec330[(IOTA0 - iSlow594) & 1023];
			fVec382[0] = fTemp1573;
			iRec992[0] = (iRec992[1] + 1) * (fTemp1573 == 0.0);
			fRec993[0] = fTemp1573 + fRec993[1] * double(fVec382[1] >= fTemp1573);
			double fTemp1574 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec993[0], 1.0) - fSlow24 * double(iRec992[0]));
			double fTemp1575 = fTemp353 + 0.0316 * fRec38[0] * (0.6910774508978648 * fTemp187 + 0.36766454750249977 * fTemp190);
			double fTemp1576 = fRec326[(IOTA0 - iSlow595) & 1023];
			fVec383[0] = fTemp1576;
			iRec994[0] = (iRec994[1] + 1) * (fTemp1576 == 0.0);
			fRec995[0] = fTemp1576 + fRec995[1] * double(fVec383[1] >= fTemp1576);
			double fTemp1577 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec995[0], 1.0) - fSlow24 * double(iRec994[0]));
			double fTemp1578 = 0.0316 * fRec38[0] * (0.4180162005391139 * fTemp202 - 0.3220094771922959 * fTemp460) - fTemp342;
			double fTemp1579 = fRec322[(IOTA0 - iSlow596) & 1023];
			fVec384[0] = fTemp1579;
			iRec996[0] = (iRec996[1] + 1) * (fTemp1579 == 0.0);
			fRec997[0] = fTemp1579 + fRec997[1] * double(fVec384[1] >= fTemp1579);
			double fTemp1580 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec997[0], 1.0) - fSlow24 * double(iRec996[0]));
			double fTemp1581 = fTemp264 + 0.025696339704337882 * fTemp892 - fTemp263;
			double fTemp1582 = fRec318[(IOTA0 - iSlow597) & 1023];
			fVec385[0] = fTemp1582;
			iRec998[0] = (iRec998[1] + 1) * (fTemp1582 == 0.0);
			fRec999[0] = fTemp1582 + fRec999[1] * double(fVec385[1] >= fTemp1582);
			double fTemp1583 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec999[0], 1.0) - fSlow24 * double(iRec998[0]));
			double fTemp1584 = fTemp319 + 0.0316 * fRec38[0] * (0.27536108208005317 * fTemp236 - 0.07509153235150734 * fTemp55) - fTemp317;
			double fTemp1585 = fRec314[(IOTA0 - iSlow598) & 1023];
			fVec386[0] = fTemp1585;
			iRec1000[0] = (iRec1000[1] + 1) * (fTemp1585 == 0.0);
			fRec1001[0] = fTemp1585 + fRec1001[1] * double(fVec386[1] >= fTemp1585);
			double fTemp1586 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1001[0], 1.0) - fSlow24 * double(iRec1000[0]));
			double fTemp1587 = fTemp310 + 0.0316 * fRec38[0] * (0.7396571990684606 * fTemp309 - 0.22371374924841803 * fTemp385) - fTemp308;
			double fTemp1588 = fRec310[(IOTA0 - iSlow599) & 1023];
			fVec387[0] = fTemp1588;
			iRec1002[0] = (iRec1002[1] + 1) * (fTemp1588 == 0.0);
			fRec1003[0] = fTemp1588 + fRec1003[1] * double(fVec387[1] >= fTemp1588);
			double fTemp1589 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1003[0], 1.0) - fSlow24 * double(iRec1002[0]));
			double fTemp1590 = 0.0316 * fRec38[0] * (0.3865162602305645 * fTemp301 - 0.9469949523481773 * fTemp41) - fTemp38;
			double fTemp1591 = fRec44[(IOTA0 - iSlow600) & 1023];
			fVec388[0] = fTemp1591;
			iRec1004[0] = (iRec1004[1] + 1) * (fTemp1591 == 0.0);
			fRec1005[0] = fTemp1591 + fRec1005[1] * double(fVec388[1] >= fTemp1591);
			double fTemp1592 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1005[0], 1.0) - fSlow24 * double(iRec1004[0]));
			double fTemp1593 = 0.0316 * fRec38[0] * (0.4745630421075475 * fTemp90 - 0.23215017964321305 * fTemp616) - fTemp88;
			double fTemp1594 = fRec306[(IOTA0 - iSlow601) & 1023];
			fVec389[0] = fTemp1594;
			iRec1006[0] = (iRec1006[1] + 1) * (fTemp1594 == 0.0);
			fRec1007[0] = fTemp1594 + fRec1007[1] * double(fVec389[1] >= fTemp1594);
			double fTemp1595 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1007[0], 1.0) - fSlow24 * double(iRec1006[0]));
			double fTemp1596 = fTemp162 + 0.0316 * fRec38[0] * (0.09788377775839763 * fTemp137 + 0.36525934384098946 * fTemp161) - fTemp156;
			double fTemp1597 = fRec302[(IOTA0 - iSlow602) & 1023];
			fVec390[0] = fTemp1597;
			iRec1008[0] = (iRec1008[1] + 1) * (fTemp1597 == 0.0);
			fRec1009[0] = fTemp1597 + fRec1009[1] * double(fVec390[1] >= fTemp1597);
			double fTemp1598 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1009[0], 1.0) - fSlow24 * double(iRec1008[0]));
			double fTemp1599 = fTemp285 + 0.04230690033851861 * fTemp1568 - fTemp276;
			double fTemp1600 = fRec298[(IOTA0 - iSlow603) & 1023];
			fVec391[0] = fTemp1600;
			iRec1010[0] = (iRec1010[1] + 1) * (fTemp1600 == 0.0);
			fRec1011[0] = fTemp1600 + fRec1011[1] * double(fVec391[1] >= fTemp1600);
			double fTemp1601 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1011[0], 1.0) - fSlow24 * double(iRec1010[0]));
			double fTemp1602 = fTemp218 + 0.04074035930154496 * fTemp693 - fTemp211;
			double fTemp1603 = fRec268[(IOTA0 - iSlow604) & 1023];
			fVec392[0] = fTemp1603;
			iRec1012[0] = (iRec1012[1] + 1) * (fTemp1603 == 0.0);
			fRec1013[0] = fTemp1603 + fRec1013[1] * double(fVec392[1] >= fTemp1603);
			double fTemp1604 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1013[0], 1.0) - fSlow24 * double(iRec1012[0]));
			double fTemp1605 = fTemp360 + 0.040163946599036354 * fTemp906;
			double fTemp1606 = fRec89[(IOTA0 - iSlow605) & 1023];
			fVec393[0] = fTemp1606;
			iRec1014[0] = (iRec1014[1] + 1) * (fTemp1606 == 0.0);
			fRec1015[0] = fTemp1606 + fRec1015[1] * double(fVec393[1] >= fTemp1606);
			double fTemp1607 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1015[0], 1.0) - fSlow24 * double(iRec1014[0]));
			double fTemp1608 = fTemp236 + 0.0316 * fRec38[0] * (0.9860955809781444 * fTemp1243 + 0.5046557220339309 * fTemp241);
			double fTemp1609 = fRec230[(IOTA0 - iSlow606) & 1023];
			fVec394[0] = fTemp1609;
			iRec1016[0] = (iRec1016[1] + 1) * (fTemp1609 == 0.0);
			fRec1017[0] = fTemp1609 + fRec1017[1] * double(fVec394[1] >= fTemp1609);
			double fTemp1610 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1017[0], 1.0) - fSlow24 * double(iRec1016[0]));
			double fTemp1611 = fTemp777 + 0.0316 * fRec38[0] * (0.7529559367758338 * fTemp386 + 0.11252702784986468 * fTemp309) - fTemp776;
			double fTemp1612 = fRec226[(IOTA0 - iSlow607) & 1023];
			fVec395[0] = fTemp1612;
			iRec1018[0] = (iRec1018[1] + 1) * (fTemp1612 == 0.0);
			fRec1019[0] = fTemp1612 + fRec1019[1] * double(fVec395[1] >= fTemp1612);
			double fTemp1613 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1019[0], 1.0) - fSlow24 * double(iRec1018[0]));
			double fTemp1614 = fTemp584 + 0.0316 * fRec38[0] * (0.5746637886577446 * fTemp301 - 0.894940963917179 * fTemp23);
			double fTemp1615 = fRec217[(IOTA0 - iSlow608) & 1023];
			fVec396[0] = fTemp1615;
			iRec1020[0] = (iRec1020[1] + 1) * (fTemp1615 == 0.0);
			fRec1021[0] = fTemp1615 + fRec1021[1] * double(fVec396[1] >= fTemp1615);
			double fTemp1616 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1021[0], 1.0) - fSlow24 * double(iRec1020[0]));
			double fTemp1617 = fTemp160 + 0.01690245357734675 * fTemp791 - fTemp159;
			double fTemp1618 = fRec94[(IOTA0 - iSlow609) & 1023];
			fVec397[0] = fTemp1618;
			iRec1022[0] = (iRec1022[1] + 1) * (fTemp1618 == 0.0);
			fRec1023[0] = fTemp1618 + fRec1023[1] * double(fVec397[1] >= fTemp1618);
			double fTemp1619 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1023[0], 1.0) - fSlow24 * double(iRec1022[0]));
			double fTemp1620 = 0.0316 * fRec38[0] * (0.0415492069296306 * fTemp584 + 0.634400512521097 * fTemp301) - fTemp23;
			double fTemp1621 = fRec174[(IOTA0 - iSlow610) & 1023];
			fVec398[0] = fTemp1621;
			iRec1024[0] = (iRec1024[1] + 1) * (fTemp1621 == 0.0);
			fRec1025[0] = fTemp1621 + fRec1025[1] * double(fVec398[1] >= fTemp1621);
			double fTemp1622 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1025[0], 1.0) - fSlow24 * double(iRec1024[0]));
			double fTemp1623 = fTemp1006 + 0.0316 * fRec38[0] * (0.8856705389744093 * fTemp35 + 0.37319705613163023 * fTemp284) - fTemp1005;
			double fTemp1624 = fRec164[(IOTA0 - iSlow611) & 1023];
			fVec399[0] = fTemp1624;
			iRec1026[0] = (iRec1026[1] + 1) * (fTemp1624 == 0.0);
			fRec1027[0] = fTemp1624 + fRec1027[1] * double(fVec399[1] >= fTemp1624);
			double fTemp1625 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1027[0], 1.0) - fSlow24 * double(iRec1026[0]));
			double fTemp1626 = 0.0316 * fRec38[0] * (0.994676674989023 * fTemp360 - 0.16655765965697356 * fTemp17) - fTemp20;
			double fTemp1627 = fRec112[(IOTA0 - iSlow612) & 1023];
			fVec400[0] = fTemp1627;
			iRec1028[0] = (iRec1028[1] + 1) * (fTemp1627 == 0.0);
			fRec1029[0] = fTemp1627 + fRec1029[1] * double(fVec400[1] >= fTemp1627);
			double fTemp1628 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1029[0], 1.0) - fSlow24 * double(iRec1028[0]));
			double fTemp1629 = ((iTemp14) ? 0.0 : fConst492 + fRec1030[1]);
			fRec1030[0] = fTemp1629 - std::floor(fTemp1629);
			int iTemp1630 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1030[0]), 65535));
			double fTemp1631 = 0.9998405404980119 * ftbl0TonewheelSIG0[iTemp1630];
			double fTemp1632 = 0.01785759156895031 * ftbl1TonewheelSIG1[iTemp1630];
			double fTemp1633 = fTemp1632 - fTemp1631;
			double fTemp1634 = fTemp1017 + 0.0316 * fRec38[0] * (0.35452562619320815 * fTemp554 + 0.061407847540976945 * fTemp1633) - fTemp1016;
			double fTemp1635 = fRec119[(IOTA0 - iSlow613) & 1023];
			fVec401[0] = fTemp1635;
			iRec1031[0] = (iRec1031[1] + 1) * (fTemp1635 == 0.0);
			fRec1032[0] = fTemp1635 + fRec1032[1] * double(fVec401[1] >= fTemp1635);
			double fTemp1636 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1032[0], 1.0) - fSlow24 * double(iRec1031[0]));
			double fTemp1637 = fTemp1024 + 0.0316 * fRec38[0] * (0.6662028496430139 * fTemp560 + 0.5190720386162866 * fTemp863);
			double fTemp1638 = fRec125[(IOTA0 - iSlow614) & 1023];
			fVec402[0] = fTemp1638;
			iRec1033[0] = (iRec1033[1] + 1) * (fTemp1638 == 0.0);
			fRec1034[0] = fTemp1638 + fRec1034[1] * double(fVec402[1] >= fTemp1638);
			double fTemp1639 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1034[0], 1.0) - fSlow24 * double(iRec1033[0]));
			double fTemp1640 = ((iTemp14) ? 0.0 : fConst495 + fRec1035[1]);
			fRec1035[0] = fTemp1640 - std::floor(fTemp1640);
			int iTemp1641 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1035[0]), 65535));
			double fTemp1642 = 0.8834879963743414 * ftbl1TonewheelSIG1[iTemp1641];
			double fTemp1643 = ((iTemp14) ? 0.0 : fConst496 + fRec1036[1]);
			fRec1036[0] = fTemp1643 - std::floor(fTemp1643);
			int iTemp1644 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1036[0]), 65535));
			double fTemp1645 = 0.1402837399469276 * ftbl1TonewheelSIG1[iTemp1644];
			double fTemp1646 = 0.990111343388461 * ftbl0TonewheelSIG0[iTemp1644];
			double fTemp1647 = fTemp1646 - fTemp1645;
			double fTemp1648 = 0.46845379736154535 * ftbl0TonewheelSIG0[iTemp1641];
			double fTemp1649 = fTemp1648 + 0.0316 * fRec38[0] * (0.7366359677762375 * fTemp568 + 0.22278571008791914 * fTemp1647) - fTemp1642;
			double fTemp1650 = fRec150[(IOTA0 - iSlow615) & 1023];
			fVec403[0] = fTemp1650;
			iRec1037[0] = (iRec1037[1] + 1) * (fTemp1650 == 0.0);
			fRec1038[0] = fTemp1650 + fRec1038[1] * double(fVec403[1] >= fTemp1650);
			double fTemp1651 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1038[0], 1.0) - fSlow24 * double(iRec1037[0]));
			double fTemp1652 = fTemp1250 + 0.04197498268624186 * fRec38[0] * fTemp856 - fTemp1249;
			double fTemp1653 = fRec157[(IOTA0 - iSlow616) & 1023];
			fVec404[0] = fTemp1653;
			iRec1039[0] = (iRec1039[1] + 1) * (fTemp1653 == 0.0);
			fRec1040[0] = fTemp1653 + fRec1040[1] * double(fVec404[1] >= fTemp1653);
			double fTemp1654 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1040[0], 1.0) - fSlow24 * double(iRec1039[0]));
			double fTemp1655 = fTemp1242 + 0.0316 * fRec38[0] * (0.20474413077681675 * fTemp236 + 0.8872353517799638 * fTemp35) - fTemp1241;
			double fTemp1656 = fRec144[(IOTA0 - iSlow617) & 1023];
			fVec405[0] = fTemp1656;
			iRec1041[0] = (iRec1041[1] + 1) * (fTemp1656 == 0.0);
			fRec1042[0] = fTemp1656 + fRec1042[1] * double(fVec405[1] >= fTemp1656);
			double fTemp1657 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1042[0], 1.0) - fSlow24 * double(iRec1041[0]));
			double fTemp1658 = fRec38[0] * fTemp35;
			double fTemp1659 = 0.04122457146505549 * fTemp1658 - fTemp32;
			double fTemp1660 = fRec137[(IOTA0 - iSlow618) & 1023];
			fVec406[0] = fTemp1660;
			iRec1043[0] = (iRec1043[1] + 1) * (fTemp1660 == 0.0);
			fRec1044[0] = fTemp1660 + fRec1044[1] * double(fVec406[1] >= fTemp1660);
			double fTemp1661 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1044[0], 1.0) - fSlow24 * double(iRec1043[0]));
			double fTemp1662 = ((iTemp14) ? 0.0 : fConst501 + fRec1045[1]);
			fRec1045[0] = fTemp1662 - std::floor(fTemp1662);
			int iTemp1663 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1045[0]), 65535));
			double fTemp1664 = 0.062258597094402374 * ftbl1TonewheelSIG1[iTemp1663] + 0.9980600518444954 * ftbl0TonewheelSIG0[iTemp1663];
			double fTemp1665 = fTemp1034 + 0.0316 * fRec38[0] * (0.7457290273500803 * fTemp35 - 0.5254086700570042 * fTemp1664) - fTemp1033;
			double fTemp1666 = fRec132[(IOTA0 - iSlow619) & 1023];
			fVec407[0] = fTemp1666;
			iRec1046[0] = (iRec1046[1] + 1) * (fTemp1666 == 0.0);
			fRec1047[0] = fTemp1666 + fRec1047[1] * double(fVec407[1] >= fTemp1666);
			double fTemp1667 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1047[0], 1.0) - fSlow24 * double(iRec1046[0]));
			double fTemp1668 = fTemp1443 + 0.0316 * fRec38[0] * (0.5298585852015094 * fTemp161 - 0.7591934616139042 * fTemp1439) - fTemp1442;
			double fTemp1669 = fRec106[(IOTA0 - iSlow620) & 1023];
			fVec408[0] = fTemp1669;
			iRec1048[0] = (iRec1048[1] + 1) * (fTemp1669 == 0.0);
			fRec1049[0] = fTemp1669 + fRec1049[1] * double(fVec408[1] >= fTemp1669);
			double fTemp1670 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1049[0], 1.0) - fSlow24 * double(iRec1048[0]));
			double fTemp1671 = fTemp1223 - 0.0316 * fRec38[0] * (0.4791379615526239 * fTemp62 + 0.7456942775497737 * fTemp616);
			double fTemp1672 = fRec168[(IOTA0 - iSlow621) & 1023];
			fVec409[0] = fTemp1672;
			iRec1050[0] = (iRec1050[1] + 1) * (fTemp1672 == 0.0);
			fRec1051[0] = fTemp1672 + fRec1051[1] * double(fVec409[1] >= fTemp1672);
			double fTemp1673 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1051[0], 1.0) - fSlow24 * double(iRec1050[0]));
			double fTemp1674 = fTemp844 - (fTemp843 + 0.0316 * fRec38[0] * (0.32566617058910197 * fTemp144 + 0.6510290431979229 * fTemp32));
			double fTemp1675 = fRec100[(IOTA0 - iSlow622) & 1023];
			fVec410[0] = fTemp1675;
			iRec1052[0] = (iRec1052[1] + 1) * (fTemp1675 == 0.0);
			fRec1053[0] = fTemp1675 + fRec1053[1] * double(fVec410[1] >= fTemp1675);
			double fTemp1676 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1053[0], 1.0) - fSlow24 * double(iRec1052[0]));
			double fTemp1677 = fTemp214 + 0.0316 * fRec38[0] * (0.5020745626607095 * fTemp778 - 0.8909285248737433 * fTemp1664);
			double fTemp1678 = fRec179[(IOTA0 - iSlow623) & 1023];
			fVec411[0] = fTemp1678;
			iRec1054[0] = (iRec1054[1] + 1) * (fTemp1678 == 0.0);
			fRec1055[0] = fTemp1678 + fRec1055[1] * double(fVec411[1] >= fTemp1678);
			double fTemp1679 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1055[0], 1.0) - fSlow24 * double(iRec1054[0]));
			double fTemp1680 = 0.0316 * fRec38[0] * (0.6624101565685123 * fTemp361 - 0.4249103917100001 * fTemp20) - fTemp17;
			double fTemp1681 = fRec209[(IOTA0 - iSlow624) & 1023];
			fVec412[0] = fTemp1681;
			iRec1056[0] = (iRec1056[1] + 1) * (fTemp1681 == 0.0);
			fRec1057[0] = fTemp1681 + fRec1057[1] * double(fVec412[1] >= fTemp1681);
			double fTemp1682 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1057[0], 1.0) - fSlow24 * double(iRec1056[0]));
			double fTemp1683 = fTemp240 + 0.0316 * fRec38[0] * (0.3428583157219691 * fTemp318 - 0.06394476769855828 * fTemp1462) - fTemp239;
			double fTemp1684 = fRec184[(IOTA0 - iSlow625) & 1023];
			fVec413[0] = fTemp1684;
			iRec1058[0] = (iRec1058[1] + 1) * (fTemp1684 == 0.0);
			fRec1059[0] = fTemp1684 + fRec1059[1] * double(fVec413[1] >= fTemp1684);
			double fTemp1685 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1059[0], 1.0) - fSlow24 * double(iRec1058[0]));
			double fTemp1686 = ((iTemp14) ? 0.0 : fConst509 + fRec1060[1]);
			fRec1060[0] = fTemp1686 - std::floor(fTemp1686);
			int iTemp1687 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1060[0]), 65535));
			double fTemp1688 = 0.9598529599928808 * ftbl1TonewheelSIG1[iTemp1687];
			double fTemp1689 = 0.28050364559646124 * ftbl0TonewheelSIG0[iTemp1687];
			double fTemp1690 = fTemp1689 - fTemp1688;
			double fTemp1691 = fTemp268 + 0.0316 * fRec38[0] * (0.1965322328178445 * fTemp324 + 0.5890590773924487 * fTemp1690);
			double fTemp1692 = fRec188[(IOTA0 - iSlow626) & 1023];
			fVec414[0] = fTemp1692;
			iRec1061[0] = (iRec1061[1] + 1) * (fTemp1692 == 0.0);
			fRec1062[0] = fTemp1692 + fRec1062[1] * double(fVec414[1] >= fTemp1692);
			double fTemp1693 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1062[0], 1.0) - fSlow24 * double(iRec1061[0]));
			double fTemp1694 = fTemp1648 - fTemp1642;
			double fTemp1695 = fTemp567 + 0.0316 * fRec38[0] * (0.7192827366579877 * fTemp1647 + 0.4638363076173846 * fTemp1694) - fTemp566;
			double fTemp1696 = fRec193[(IOTA0 - iSlow627) & 1023];
			fVec415[0] = fTemp1696;
			iRec1063[0] = (iRec1063[1] + 1) * (fTemp1696 == 0.0);
			fRec1064[0] = fTemp1696 + fRec1064[1] * double(fVec415[1] >= fTemp1696);
			double fTemp1697 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1064[0], 1.0) - fSlow24 * double(iRec1063[0]));
			double fTemp1698 = ((iTemp14) ? 0.0 : fConst512 + fRec1065[1]);
			fRec1065[0] = fTemp1698 - std::floor(fTemp1698);
			int iTemp1699 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1065[0]), 65535));
			double fTemp1700 = 0.8953891923762586 * ftbl0TonewheelSIG0[iTemp1699];
			double fTemp1701 = 0.44528439695973115 * ftbl1TonewheelSIG1[iTemp1699];
			double fTemp1702 = fTemp1701 - fTemp1700;
			double fTemp1703 = fTemp560 + 0.01062782418724528 * fRec38[0] * fTemp1702;
			double fTemp1704 = fRec198[(IOTA0 - iSlow628) & 1023];
			fVec416[0] = fTemp1704;
			iRec1066[0] = (iRec1066[1] + 1) * (fTemp1704 == 0.0);
			fRec1067[0] = fTemp1704 + fRec1067[1] * double(fVec416[1] >= fTemp1704);
			double fTemp1705 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1067[0], 1.0) - fSlow24 * double(iRec1066[0]));
			double fTemp1706 = fTemp553 + 0.0316 * fRec38[0] * (0.7403800724714529 * fTemp190 + 0.5507452527963324 * fTemp1018) - fTemp552;
			double fTemp1707 = fRec204[(IOTA0 - iSlow629) & 1023];
			fVec417[0] = fTemp1707;
			iRec1068[0] = (iRec1068[1] + 1) * (fTemp1707 == 0.0);
			fRec1069[0] = fTemp1707 + fRec1069[1] * double(fVec417[1] >= fTemp1707);
			double fTemp1708 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1069[0], 1.0) - fSlow24 * double(iRec1068[0]));
			double fTemp1709 = fTemp597 + 0.0316 * fRec38[0] * (0.22462254614947597 * fTemp366 + 0.20641771704686107 * fTemp284) - fTemp596;
			double fTemp1710 = fRec213[(IOTA0 - iSlow630) & 1023];
			fVec418[0] = fTemp1710;
			iRec1070[0] = (iRec1070[1] + 1) * (fTemp1710 == 0.0);
			fRec1071[0] = fTemp1710 + fRec1071[1] * double(fVec418[1] >= fTemp1710);
			double fTemp1711 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1071[0], 1.0) - fSlow24 * double(iRec1070[0]));
			double fTemp1712 = fTemp855 + 0.03052317305025936 * fTemp399 - fTemp854;
			double fTemp1713 = fRec235[(IOTA0 - iSlow631) & 1023];
			fVec419[0] = fTemp1713;
			iRec1072[0] = (iRec1072[1] + 1) * (fTemp1713 == 0.0);
			fRec1073[0] = fTemp1713 + fRec1073[1] * double(fVec419[1] >= fTemp1713);
			double fTemp1714 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1073[0], 1.0) - fSlow24 * double(iRec1072[0]));
			double fTemp1715 = fTemp333 + 0.0316 * fRec38[0] * (0.967441807842988 * fTemp1694 + 0.9092385212643421 * fTemp114) - fTemp332;
			double fTemp1716 = fRec239[(IOTA0 - iSlow632) & 1023];
			fVec420[0] = fTemp1716;
			iRec1074[0] = (iRec1074[1] + 1) * (fTemp1716 == 0.0);
			fRec1075[0] = fTemp1716 + fRec1075[1] * double(fVec420[1] >= fTemp1716);
			double fTemp1717 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1075[0], 1.0) - fSlow24 * double(iRec1074[0]));
			double fTemp1718 = fTemp831 + 0.0316 * fRec38[0] * (0.02739654640754452 * fTemp1024 - 0.8293316430608684 * fTemp342) - fTemp830;
			double fTemp1719 = fRec243[(IOTA0 - iSlow633) & 1023];
			fVec421[0] = fTemp1719;
			iRec1076[0] = (iRec1076[1] + 1) * (fTemp1719 == 0.0);
			fRec1077[0] = fTemp1719 + fRec1077[1] * double(fVec421[1] >= fTemp1719);
			double fTemp1720 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1077[0], 1.0) - fSlow24 * double(iRec1076[0]));
			double fTemp1721 = 0.0316 * fRec38[0] * (0.5297288316378399 * fTemp190 + 0.3943117887702101 * fTemp353) - fTemp182;
			double fTemp1722 = fRec247[(IOTA0 - iSlow634) & 1023];
			fVec422[0] = fTemp1722;
			iRec1078[0] = (iRec1078[1] + 1) * (fTemp1722 == 0.0);
			fRec1079[0] = fTemp1722 + fRec1079[1] * double(fVec422[1] >= fTemp1722);
			double fTemp1723 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1079[0], 1.0) - fSlow24 * double(iRec1078[0]));
			double fTemp1724 = fTemp283 + 0.0316 * fRec38[0] * (0.5486880723037757 * fTemp598 + 0.34474046107789036 * fTemp366) - fTemp282;
			double fTemp1725 = fRec252[(IOTA0 - iSlow635) & 1023];
			fVec423[0] = fTemp1725;
			iRec1080[0] = (iRec1080[1] + 1) * (fTemp1725 == 0.0);
			fRec1081[0] = fTemp1725 + fRec1081[1] * double(fVec423[1] >= fTemp1725);
			double fTemp1726 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1081[0], 1.0) - fSlow24 * double(iRec1080[0]));
			double fTemp1727 = fTemp136 + 0.0316 * fRec38[0] * (0.7004202045791317 * fTemp102 + 0.24406127953261603 * fTemp161) - fTemp135;
			double fTemp1728 = fRec84[(IOTA0 - iSlow636) & 1023];
			fVec424[0] = fTemp1728;
			iRec1082[0] = (iRec1082[1] + 1) * (fTemp1728 == 0.0);
			fRec1083[0] = fTemp1728 + fRec1083[1] * double(fVec424[1] >= fTemp1728);
			double fTemp1729 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1083[0], 1.0) - fSlow24 * double(iRec1082[0]));
			double fTemp1730 = fTemp301 + 0.0316 * fRec38[0] * (0.8948239439996541 * fTemp584 - 0.5987157897252473 * fTemp23);
			double fTemp1731 = fRec260[(IOTA0 - iSlow637) & 1023];
			fVec425[0] = fTemp1731;
			iRec1084[0] = (iRec1084[1] + 1) * (fTemp1731 == 0.0);
			fRec1085[0] = fTemp1731 + fRec1085[1] * double(fVec425[1] >= fTemp1731);
			double fTemp1732 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1085[0], 1.0) - fSlow24 * double(iRec1084[0]));
			double fTemp1733 = fTemp226 - (fTemp225 + 0.03403707673843165 * fTemp1330);
			double fTemp1734 = fRec264[(IOTA0 - iSlow638) & 1023];
			fVec426[0] = fTemp1734;
			iRec1086[0] = (iRec1086[1] + 1) * (fTemp1734 == 0.0);
			fRec1087[0] = fTemp1734 + fRec1087[1] * double(fVec426[1] >= fTemp1734);
			double fTemp1735 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1087[0], 1.0) - fSlow24 * double(iRec1086[0]));
			double fTemp1736 = fTemp242 - (fTemp233 + 0.019817328383920904 * fRec38[0] * fTemp55);
			double fTemp1737 = fRec50[(IOTA0 - iSlow639) & 1023];
			fVec427[0] = fTemp1737;
			iRec1088[0] = (iRec1088[1] + 1) * (fTemp1737 == 0.0);
			fRec1089[0] = fTemp1737 + fRec1089[1] * double(fVec427[1] >= fTemp1737);
			double fTemp1738 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1089[0], 1.0) - fSlow24 * double(iRec1088[0]));
			double fTemp1739 = fTemp269 + 0.03755586147072318 * fTemp399 - fTemp260;
			double fTemp1740 = fRec273[(IOTA0 - iSlow640) & 1023];
			fVec428[0] = fTemp1740;
			iRec1090[0] = (iRec1090[1] + 1) * (fTemp1740 == 0.0);
			fRec1091[0] = fTemp1740 + fRec1091[1] * double(fVec428[1] >= fTemp1740);
			double fTemp1741 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1091[0], 1.0) - fSlow24 * double(iRec1090[0]));
			double fTemp1742 = fTemp253 + 0.027888898629196048 * fTemp529 - fTemp249;
			double fTemp1743 = fRec80[(IOTA0 - iSlow641) & 1023];
			fVec429[0] = fTemp1743;
			iRec1092[0] = (iRec1092[1] + 1) * (fTemp1743 == 0.0);
			fRec1093[0] = fTemp1743 + fRec1093[1] * double(fVec429[1] >= fTemp1743);
			double fTemp1744 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1093[0], 1.0) - fSlow24 * double(iRec1092[0]));
			double fTemp1745 = fTemp204 + 0.0316 * fRec38[0] * (0.6654977227008203 * fTemp202 + 0.6719886473147199 * fTemp863) - fTemp197;
			double fTemp1746 = fRec281[(IOTA0 - iSlow642) & 1023];
			fVec430[0] = fTemp1746;
			iRec1094[0] = (iRec1094[1] + 1) * (fTemp1746 == 0.0);
			fRec1095[0] = fTemp1746 + fRec1095[1] * double(fVec430[1] >= fTemp1746);
			double fTemp1747 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1095[0], 1.0) - fSlow24 * double(iRec1094[0]));
			double fTemp1748 = fTemp190 + 0.0316 * fRec38[0] * (0.722232876563794 * fTemp353 - 0.031570544037094805 * fTemp182);
			double fTemp1749 = fRec286[(IOTA0 - iSlow643) & 1023];
			fVec431[0] = fTemp1749;
			iRec1096[0] = (iRec1096[1] + 1) * (fTemp1749 == 0.0);
			fRec1097[0] = fTemp1749 + fRec1097[1] * double(fVec431[1] >= fTemp1749);
			double fTemp1750 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1097[0], 1.0) - fSlow24 * double(iRec1096[0]));
			double fTemp1751 = fTemp175 + 0.0316 * fRec38[0] * (0.09039050813589711 * fTemp360 - 0.04753161681583151 * fTemp17) - fTemp169;
			double fTemp1752 = fRec294[(IOTA0 - iSlow644) & 1023];
			fVec432[0] = fTemp1752;
			iRec1098[0] = (iRec1098[1] + 1) * (fTemp1752 == 0.0);
			fRec1099[0] = fTemp1752 + fRec1099[1] * double(fVec432[1] >= fTemp1752);
			double fTemp1753 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1099[0], 1.0) - fSlow24 * double(iRec1098[0]));
			double fTemp1754 = fTemp114 + 0.0316 * fRec38[0] * (0.7906322491726314 * fTemp252 + 0.5380190743544517 * fTemp334);
			double fTemp1755 = fRec277[(IOTA0 - iSlow645) & 1023];
			fVec433[0] = fTemp1755;
			iRec1100[0] = (iRec1100[1] + 1) * (fTemp1755 == 0.0);
			fRec1101[0] = fTemp1755 + fRec1101[1] * double(fVec433[1] >= fTemp1755);
			double fTemp1756 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1101[0], 1.0) - fSlow24 * double(iRec1100[0]));
			fRec1102[0] = fSlow647 + fConst10 * fRec1102[1];
			double fTemp1757 = fTemp62 + 0.0316 * fRec38[0] * (0.7821482675353764 * fTemp616 + 0.1958025878338958 * fTemp66);
			double fTemp1758 = fRec235[(IOTA0 - iSlow648) & 1023];
			fVec434[0] = fTemp1758;
			iRec1103[0] = (iRec1103[1] + 1) * (fTemp1758 == 0.0);
			fRec1104[0] = fTemp1758 + fRec1104[1] * double(fVec434[1] >= fTemp1758);
			double fTemp1759 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1104[0], 1.0) - fSlow24 * double(iRec1103[0]));
			double fTemp1760 = fTemp144 + 0.0316 * fRec38[0] * (0.003865820741339121 * fTemp32 + 0.01586023689742433 * fTemp76);
			double fTemp1761 = fRec198[(IOTA0 - iSlow649) & 1023];
			fVec435[0] = fTemp1761;
			iRec1105[0] = (iRec1105[1] + 1) * (fTemp1761 == 0.0);
			fRec1106[0] = fTemp1761 + fRec1106[1] * double(fVec435[1] >= fTemp1761);
			double fTemp1762 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1106[0], 1.0) - fSlow24 * double(iRec1105[0]));
			double fTemp1763 = fTemp126 + 0.0316 * fRec38[0] * (0.4549844932753331 * fTemp361 + 0.8023655663128011 * fTemp127) - fTemp125;
			double fTemp1764 = fRec62[(IOTA0 - iSlow650) & 1023];
			fVec436[0] = fTemp1764;
			iRec1107[0] = (iRec1107[1] + 1) * (fTemp1764 == 0.0);
			fRec1108[0] = fTemp1764 + fRec1108[1] * double(fVec436[1] >= fTemp1764);
			double fTemp1765 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1108[0], 1.0) - fSlow24 * double(iRec1107[0]));
			double fTemp1766 = fTemp186 + 0.05500343299296874 * fTemp712 - fTemp185;
			double fTemp1767 = fRec40[(IOTA0 - iSlow651) & 1023];
			fVec437[0] = fTemp1767;
			iRec1109[0] = (iRec1109[1] + 1) * (fTemp1767 == 0.0);
			fRec1110[0] = fTemp1767 + fRec1110[1] * double(fVec437[1] >= fTemp1767);
			double fTemp1768 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1110[0], 1.0) - fSlow24 * double(iRec1109[0]));
			double fTemp1769 = fTemp201 - (fTemp200 + 0.009468572401214626 * fTemp899);
			double fTemp1770 = fRec68[(IOTA0 - iSlow652) & 1023];
			fVec438[0] = fTemp1770;
			iRec1111[0] = (iRec1111[1] + 1) * (fTemp1770 == 0.0);
			fRec1112[0] = fTemp1770 + fRec1112[1] * double(fVec438[1] >= fTemp1770);
			double fTemp1771 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1112[0], 1.0) - fSlow24 * double(iRec1111[0]));
			double fTemp1772 = fTemp252 + 0.0460002006872528 * fTemp543;
			double fTemp1773 = fRec74[(IOTA0 - iSlow653) & 1023];
			fVec439[0] = fTemp1773;
			iRec1113[0] = (iRec1113[1] + 1) * (fTemp1773 == 0.0);
			fRec1114[0] = fTemp1773 + fRec1114[1] * double(fVec439[1] >= fTemp1773);
			double fTemp1774 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1114[0], 1.0) - fSlow24 * double(iRec1113[0]));
			double fTemp1775 = fTemp400 + 0.0316 * fRec38[0] * (0.8481402414399781 * fTemp445 + 0.5268840688731871 * fTemp324) - fTemp398;
			double fTemp1776 = fRec334[(IOTA0 - iSlow654) & 1023];
			fVec440[0] = fTemp1776;
			iRec1115[0] = (iRec1115[1] + 1) * (fTemp1776 == 0.0);
			fRec1116[0] = fTemp1776 + fRec1116[1] * double(fVec440[1] >= fTemp1776);
			double fTemp1777 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1116[0], 1.0) - fSlow24 * double(iRec1115[0]));
			double fTemp1778 = 0.03484952428036777 * fRec38[0] * fTemp318 - fTemp55;
			double fTemp1779 = fRec330[(IOTA0 - iSlow655) & 1023];
			fVec441[0] = fTemp1779;
			iRec1117[0] = (iRec1117[1] + 1) * (fTemp1779 == 0.0);
			fRec1118[0] = fTemp1779 + fRec1118[1] * double(fVec441[1] >= fTemp1779);
			double fTemp1780 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1118[0], 1.0) - fSlow24 * double(iRec1117[0]));
			double fTemp1781 = fTemp217 + 0.05214943428602565 * fTemp693;
			double fTemp1782 = fRec326[(IOTA0 - iSlow656) & 1023];
			fVec442[0] = fTemp1782;
			iRec1119[0] = (iRec1119[1] + 1) * (fTemp1782 == 0.0);
			fRec1120[0] = fTemp1782 + fRec1120[1] * double(fVec442[1] >= fTemp1782);
			double fTemp1783 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1120[0], 1.0) - fSlow24 * double(iRec1119[0]));
			double fTemp1784 = fTemp297 + 0.0316 * fRec38[0] * (0.1070933869283408 * fTemp301 - 0.5056556684899078 * fTemp41) - fTemp296;
			double fTemp1785 = fRec277[(IOTA0 - iSlow657) & 1023];
			fVec443[0] = fTemp1785;
			iRec1121[0] = (iRec1121[1] + 1) * (fTemp1785 == 0.0);
			fRec1122[0] = fTemp1785 + fRec1122[1] * double(fVec443[1] >= fTemp1785);
			double fTemp1786 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1122[0], 1.0) - fSlow24 * double(iRec1121[0]));
			double fTemp1787 = fTemp353 + 0.0316 * fRec38[0] * (0.07235150332417106 * fTemp190 + 0.140272507116606 * fTemp350);
			double fTemp1788 = fRec44[(IOTA0 - iSlow658) & 1023];
			fVec444[0] = fTemp1788;
			iRec1123[0] = (iRec1123[1] + 1) * (fTemp1788 == 0.0);
			fRec1124[0] = fTemp1788 + fRec1124[1] * double(fVec444[1] >= fTemp1788);
			double fTemp1789 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1124[0], 1.0) - fSlow24 * double(iRec1123[0]));
			double fTemp1790 = fTemp204 + 0.0316 * fRec38[0] * (0.07804802084865514 * fTemp202 - 0.3864320757202222 * fTemp342) - fTemp197;
			double fTemp1791 = fRec256[(IOTA0 - iSlow659) & 1023];
			fVec445[0] = fTemp1791;
			iRec1125[0] = (iRec1125[1] + 1) * (fTemp1791 == 0.0);
			fRec1126[0] = fTemp1791 + fRec1126[1] * double(fVec445[1] >= fTemp1791);
			double fTemp1792 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1126[0], 1.0) - fSlow24 * double(iRec1125[0]));
			double fTemp1793 = fTemp301 - 0.0590607518624558 * fRec38[0] * fTemp38;
			double fTemp1794 = fRec239[(IOTA0 - iSlow660) & 1023];
			fVec446[0] = fTemp1794;
			iRec1127[0] = (iRec1127[1] + 1) * (fTemp1794 == 0.0);
			fRec1128[0] = fTemp1794 + fRec1128[1] * double(fVec446[1] >= fTemp1794);
			double fTemp1795 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1128[0], 1.0) - fSlow24 * double(iRec1127[0]));
			double fTemp1796 = 0.0316 * fRec38[0] * (0.6259237404483429 * fTemp554 + 0.2732454075339774 * fTemp353) - fTemp182;
			double fTemp1797 = fRec217[(IOTA0 - iSlow661) & 1023];
			fVec447[0] = fTemp1797;
			iRec1129[0] = (iRec1129[1] + 1) * (fTemp1797 == 0.0);
			fRec1130[0] = fTemp1797 + fRec1130[1] * double(fVec447[1] >= fTemp1797);
			double fTemp1798 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1130[0], 1.0) - fSlow24 * double(iRec1129[0]));
			double fTemp1799 = fTemp831 + 0.0316 * fRec38[0] * (0.8597458483236551 * fTemp1024 + 0.980549807857642 * fTemp560) - fTemp830;
			double fTemp1800 = fRec56[(IOTA0 - iSlow662) & 1023];
			fVec448[0] = fTemp1800;
			iRec1131[0] = (iRec1131[1] + 1) * (fTemp1800 == 0.0);
			fRec1132[0] = fTemp1800 + fRec1132[1] * double(fVec448[1] >= fTemp1800);
			double fTemp1801 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1132[0], 1.0) - fSlow24 * double(iRec1131[0]));
			double fTemp1802 = fTemp553 + 0.0316 * fRec38[0] * (0.9120719714264851 * fTemp1633 + 0.11188005812437041 * fTemp190) - fTemp552;
			double fTemp1803 = fRec174[(IOTA0 - iSlow663) & 1023];
			fVec449[0] = fTemp1803;
			iRec1133[0] = (iRec1133[1] + 1) * (fTemp1803 == 0.0);
			fRec1134[0] = fTemp1803 + fRec1134[1] * double(fVec449[1] >= fTemp1803);
			double fTemp1804 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1134[0], 1.0) - fSlow24 * double(iRec1133[0]));
			double fTemp1805 = fTemp560 + 0.0316 * fRec38[0] * (0.21763605691376142 * fTemp343 + 0.9766615726912278 * fTemp863);
			double fTemp1806 = fRec168[(IOTA0 - iSlow664) & 1023];
			fVec450[0] = fTemp1806;
			iRec1135[0] = (iRec1135[1] + 1) * (fTemp1806 == 0.0);
			fRec1136[0] = fTemp1806 + fRec1136[1] * double(fVec450[1] >= fTemp1806);
			double fTemp1807 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1136[0], 1.0) - fSlow24 * double(iRec1135[0]));
			double fTemp1808 = fTemp567 + 0.04877936975615303 * fTemp979 - fTemp566;
			double fTemp1809 = fRec106[(IOTA0 - iSlow665) & 1023];
			fVec451[0] = fTemp1809;
			iRec1137[0] = (iRec1137[1] + 1) * (fTemp1809 == 0.0);
			fRec1138[0] = fTemp1809 + fRec1138[1] * double(fVec451[1] >= fTemp1809);
			double fTemp1810 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1138[0], 1.0) - fSlow24 * double(iRec1137[0]));
			double fTemp1811 = fTemp268 + 0.0316 * fRec38[0] * (0.1096621244405469 * fTemp1690 + 0.8009443516584724 * fTemp324);
			double fTemp1812 = fRec164[(IOTA0 - iSlow666) & 1023];
			fVec452[0] = fTemp1812;
			iRec1139[0] = (iRec1139[1] + 1) * (fTemp1812 == 0.0);
			fRec1140[0] = fTemp1812 + fRec1140[1] * double(fVec452[1] >= fTemp1812);
			double fTemp1813 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1140[0], 1.0) - fSlow24 * double(iRec1139[0]));
			double fTemp1814 = fTemp240 + 0.0316 * fRec38[0] * (0.411812170772464 * fTemp1243 + 0.32170721418333414 * fTemp236) - fTemp239;
			double fTemp1815 = fRec112[(IOTA0 - iSlow667) & 1023];
			fVec453[0] = fTemp1815;
			iRec1141[0] = (iRec1141[1] + 1) * (fTemp1815 == 0.0);
			fRec1142[0] = fTemp1815 + fRec1142[1] * double(fVec453[1] >= fTemp1815);
			double fTemp1816 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1142[0], 1.0) - fSlow24 * double(iRec1141[0]));
			double fTemp1817 = fTemp214 + 0.0237913188761042 * fRec38[0] * fTemp1035;
			double fTemp1818 = fRec119[(IOTA0 - iSlow668) & 1023];
			fVec454[0] = fTemp1818;
			iRec1143[0] = (iRec1143[1] + 1) * (fTemp1818 == 0.0);
			fRec1144[0] = fTemp1818 + fRec1144[1] * double(fVec454[1] >= fTemp1818);
			double fTemp1819 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1144[0], 1.0) - fSlow24 * double(iRec1143[0]));
			double fTemp1820 = fTemp844 + 0.0316 * fRec38[0] * (0.9401602134967106 * fTemp377 - 0.41051980839984026 * fTemp32) - fTemp843;
			double fTemp1821 = fRec125[(IOTA0 - iSlow669) & 1023];
			fVec455[0] = fTemp1821;
			iRec1145[0] = (iRec1145[1] + 1) * (fTemp1821 == 0.0);
			fRec1146[0] = fTemp1821 + fRec1146[1] * double(fVec455[1] >= fTemp1821);
			double fTemp1822 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1146[0], 1.0) - fSlow24 * double(iRec1145[0]));
			double fTemp1823 = 0.0316 * fRec38[0] * (0.5710517928964691 * fTemp35 - 0.07220811977458652 * fTemp26) - fTemp23;
			double fTemp1824 = fRec150[(IOTA0 - iSlow670) & 1023];
			fVec456[0] = fTemp1824;
			iRec1147[0] = (iRec1147[1] + 1) * (fTemp1824 == 0.0);
			fRec1148[0] = fTemp1824 + fRec1148[1] * double(fVec456[1] >= fTemp1824);
			double fTemp1825 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1148[0], 1.0) - fSlow24 * double(iRec1147[0]));
			double fTemp1826 = fTemp1006 + 0.0316 * fRec38[0] * (0.9876691695226327 * fTemp598 + 0.19026889036467765 * fTemp284) - fTemp1005;
			double fTemp1827 = fRec132[(IOTA0 - iSlow671) & 1023];
			fVec457[0] = fTemp1827;
			iRec1149[0] = (iRec1149[1] + 1) * (fTemp1827 == 0.0);
			fRec1150[0] = fTemp1827 + fRec1150[1] * double(fVec457[1] >= fTemp1827);
			double fTemp1828 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1150[0], 1.0) - fSlow24 * double(iRec1149[0]));
			double fTemp1829 = 0.0316 * fRec38[0] * (0.3586975762450493 * fTemp360 - 0.19058381428180837 * fTemp29) - fTemp20;
			double fTemp1830 = fRec137[(IOTA0 - iSlow672) & 1023];
			fVec458[0] = fTemp1830;
			iRec1151[0] = (iRec1151[1] + 1) * (fTemp1830 == 0.0);
			fRec1152[0] = fTemp1830 + fRec1152[1] * double(fVec458[1] >= fTemp1830);
			double fTemp1831 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1152[0], 1.0) - fSlow24 * double(iRec1151[0]));
			double fTemp1832 = fTemp1443 + 0.0316 * fRec38[0] * (0.6718266073912673 * fTemp137 + 0.402437064309197 * fTemp161) - fTemp1442;
			double fTemp1833 = fRec144[(IOTA0 - iSlow673) & 1023];
			fVec459[0] = fTemp1833;
			iRec1153[0] = (iRec1153[1] + 1) * (fTemp1833 == 0.0);
			fRec1154[0] = fTemp1833 + fRec1154[1] * double(fVec459[1] >= fTemp1833);
			double fTemp1834 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1154[0], 1.0) - fSlow24 * double(iRec1153[0]));
			double fTemp1835 = fTemp1223 + 0.0316 * fRec38[0] * (0.6954372357213288 * fTemp35 - 0.795460215449566 * fTemp62);
			double fTemp1836 = fRec157[(IOTA0 - iSlow674) & 1023];
			fVec460[0] = fTemp1836;
			iRec1155[0] = (iRec1155[1] + 1) * (fTemp1836 == 0.0);
			fRec1156[0] = fTemp1836 + fRec1156[1] * double(fVec460[1] >= fTemp1836);
			double fTemp1837 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1156[0], 1.0) - fSlow24 * double(iRec1155[0]));
			double fTemp1838 = 0.05303945519856935 * fTemp677 - fTemp17;
			double fTemp1839 = fRec100[(IOTA0 - iSlow675) & 1023];
			fVec461[0] = fTemp1839;
			iRec1157[0] = (iRec1157[1] + 1) * (fTemp1839 == 0.0);
			fRec1158[0] = fTemp1839 + fRec1158[1] * double(fVec461[1] >= fTemp1839);
			double fTemp1840 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1158[0], 1.0) - fSlow24 * double(iRec1157[0]));
			double fTemp1841 = fTemp597 + 0.0316 * fRec38[0] * (0.8359169972245581 * fTemp284 - 0.4198465649460559 * fTemp1232) - fTemp596;
			double fTemp1842 = fRec179[(IOTA0 - iSlow676) & 1023];
			fVec462[0] = fTemp1842;
			iRec1159[0] = (iRec1159[1] + 1) * (fTemp1842 == 0.0);
			fRec1160[0] = fTemp1842 + fRec1160[1] * double(fVec462[1] >= fTemp1842);
			double fTemp1843 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1160[0], 1.0) - fSlow24 * double(iRec1159[0]));
			double fTemp1844 = fTemp160 + 0.0316 * fRec38[0] * (0.1334523004552466 * fTemp478 - 0.2939010376958322 * fTemp1439) - fTemp159;
			double fTemp1845 = fRec184[(IOTA0 - iSlow677) & 1023];
			fVec463[0] = fTemp1845;
			iRec1161[0] = (iRec1161[1] + 1) * (fTemp1845 == 0.0);
			fRec1162[0] = fTemp1845 + fRec1162[1] * double(fVec463[1] >= fTemp1845);
			double fTemp1846 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1162[0], 1.0) - fSlow24 * double(iRec1161[0]));
			double fTemp1847 = 0.0316 * fRec38[0] * (0.440491375993588 * fTemp1223 - 0.670142213140025 * fTemp62) - fTemp616;
			double fTemp1848 = fRec188[(IOTA0 - iSlow678) & 1023];
			fVec464[0] = fTemp1848;
			iRec1163[0] = (iRec1163[1] + 1) * (fTemp1848 == 0.0);
			fRec1164[0] = fTemp1848 + fRec1164[1] * double(fVec464[1] >= fTemp1848);
			double fTemp1849 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1164[0], 1.0) - fSlow24 * double(iRec1163[0]));
			double fTemp1850 = fTemp584 + 0.0316 * fRec38[0] * (0.13521259820845444 * fTemp301 - 0.973397119436413 * fTemp23);
			double fTemp1851 = fRec193[(IOTA0 - iSlow679) & 1023];
			fVec465[0] = fTemp1851;
			iRec1165[0] = (iRec1165[1] + 1) * (fTemp1851 == 0.0);
			fRec1166[0] = fTemp1851 + fRec1166[1] * double(fVec465[1] >= fTemp1851);
			double fTemp1852 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1166[0], 1.0) - fSlow24 * double(iRec1165[0]));
			double fTemp1853 = fTemp777 + 0.0316 * fRec38[0] * (0.906064420218172 * fTemp309 + 0.9407258278588415 * fTemp214) - fTemp776;
			double fTemp1854 = fRec204[(IOTA0 - iSlow680) & 1023];
			fVec466[0] = fTemp1854;
			iRec1167[0] = (iRec1167[1] + 1) * (fTemp1854 == 0.0);
			fRec1168[0] = fTemp1854 + fRec1168[1] * double(fVec466[1] >= fTemp1854);
			double fTemp1855 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1168[0], 1.0) - fSlow24 * double(iRec1167[0]));
			double fTemp1856 = fTemp236 + 0.0316 * fRec38[0] * (0.158950060402276 * fTemp391 + 0.4488175318692811 * fTemp1243);
			double fTemp1857 = fRec209[(IOTA0 - iSlow681) & 1023];
			fVec467[0] = fTemp1857;
			iRec1169[0] = (iRec1169[1] + 1) * (fTemp1857 == 0.0);
			fRec1170[0] = fTemp1857 + fRec1170[1] * double(fVec467[1] >= fTemp1857);
			double fTemp1858 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1170[0], 1.0) - fSlow24 * double(iRec1169[0]));
			double fTemp1859 = fTemp855 + 0.0316 * fRec38[0] * (0.6407150119921425 * fTemp268 + 0.7841063546220539 * fTemp324) - fTemp854;
			double fTemp1860 = fRec213[(IOTA0 - iSlow682) & 1023];
			fVec468[0] = fTemp1860;
			iRec1171[0] = (iRec1171[1] + 1) * (fTemp1860 == 0.0);
			fRec1172[0] = fTemp1860 + fRec1172[1] * double(fVec468[1] >= fTemp1860);
			double fTemp1861 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1172[0], 1.0) - fSlow24 * double(iRec1171[0]));
			double fTemp1862 = fTemp333 + 0.0316 * fRec38[0] * (0.940768537857366 * fTemp568 + 0.5998086022009375 * fTemp1694) - fTemp332;
			double fTemp1863 = fRec94[(IOTA0 - iSlow683) & 1023];
			fVec469[0] = fTemp1863;
			iRec1173[0] = (iRec1173[1] + 1) * (fTemp1863 == 0.0);
			fRec1174[0] = fTemp1863 + fRec1174[1] * double(fVec469[1] >= fTemp1863);
			double fTemp1864 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1174[0], 1.0) - fSlow24 * double(iRec1173[0]));
			double fTemp1865 = fTemp136 + 0.0316 * fRec38[0] * (0.8024378037589486 * fTemp161 + 0.5400376932739164 * fTemp102) - fTemp135;
			double fTemp1866 = fRec230[(IOTA0 - iSlow684) & 1023];
			fVec470[0] = fTemp1866;
			iRec1175[0] = (iRec1175[1] + 1) * (fTemp1866 == 0.0);
			fRec1176[0] = fTemp1866 + fRec1176[1] * double(fVec470[1] >= fTemp1866);
			double fTemp1867 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1176[0], 1.0) - fSlow24 * double(iRec1175[0]));
			double fTemp1868 = fTemp360 + 0.0316 * fRec38[0] * (0.10203111438750057 * fTemp174 - 0.14546851078921463 * fTemp20);
			double fTemp1869 = fRec221[(IOTA0 - iSlow685) & 1023];
			fVec471[0] = fTemp1869;
			iRec1177[0] = (iRec1177[1] + 1) * (fTemp1869 == 0.0);
			fRec1178[0] = fTemp1869 + fRec1178[1] * double(fVec471[1] >= fTemp1869);
			double fTemp1870 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1178[0], 1.0) - fSlow24 * double(iRec1177[0]));
			double fTemp1871 = fTemp283 + 0.036576260941362126 * fTemp367 - fTemp282;
			double fTemp1872 = fRec226[(IOTA0 - iSlow686) & 1023];
			fVec472[0] = fTemp1872;
			iRec1179[0] = (iRec1179[1] + 1) * (fTemp1872 == 0.0);
			fRec1180[0] = fTemp1872 + fRec1180[1] * double(fVec472[1] >= fTemp1872);
			double fTemp1873 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1180[0], 1.0) - fSlow24 * double(iRec1179[0]));
			double fTemp1874 = fTemp226 + 0.0316 * fRec38[0] * (0.700686612213758 * fTemp845 + 0.2762024549429043 * fTemp149) - fTemp225;
			double fTemp1875 = fRec243[(IOTA0 - iSlow687) & 1023];
			fVec473[0] = fTemp1875;
			iRec1181[0] = (iRec1181[1] + 1) * (fTemp1875 == 0.0);
			fRec1182[0] = fTemp1875 + fRec1182[1] * double(fVec473[1] >= fTemp1875);
			double fTemp1876 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1182[0], 1.0) - fSlow24 * double(iRec1181[0]));
			double fTemp1877 = fTemp218 + 0.0316 * fRec38[0] * (0.24583520363739808 * fTemp778 + 0.3839250519276902 * fTemp214) - fTemp211;
			double fTemp1878 = fRec247[(IOTA0 - iSlow688) & 1023];
			fVec474[0] = fTemp1878;
			iRec1183[0] = (iRec1183[1] + 1) * (fTemp1878 == 0.0);
			fRec1184[0] = fTemp1878 + fRec1184[1] * double(fVec474[1] >= fTemp1878);
			double fTemp1879 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1184[0], 1.0) - fSlow24 * double(iRec1183[0]));
			double fTemp1880 = fTemp242 + 0.0316 * fRec38[0] * (0.9274263118786621 * fTemp391 - 0.635282393435773 * fTemp55) - fTemp233;
			double fTemp1881 = fRec89[(IOTA0 - iSlow689) & 1023];
			fVec475[0] = fTemp1881;
			iRec1185[0] = (iRec1185[1] + 1) * (fTemp1881 == 0.0);
			fRec1186[0] = fTemp1881 + fRec1186[1] * double(fVec475[1] >= fTemp1881);
			double fTemp1882 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1186[0], 1.0) - fSlow24 * double(iRec1185[0]));
			double fTemp1883 = fTemp269 + 0.021033948117506227 * fTemp983 - fTemp260;
			double fTemp1884 = fRec252[(IOTA0 - iSlow690) & 1023];
			fVec476[0] = fTemp1884;
			iRec1187[0] = (iRec1187[1] + 1) * (fTemp1884 == 0.0);
			fRec1188[0] = fTemp1884 + fRec1188[1] * double(fVec476[1] >= fTemp1884);
			double fTemp1885 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1188[0], 1.0) - fSlow24 * double(iRec1187[0]));
			double fTemp1886 = fTemp253 + 0.0316 * fRec38[0] * (0.5000544820795767 * fTemp114 + 0.8667016429099021 * fTemp334) - fTemp249;
			double fTemp1887 = fRec84[(IOTA0 - iSlow691) & 1023];
			fVec477[0] = fTemp1887;
			iRec1189[0] = (iRec1189[1] + 1) * (fTemp1887 == 0.0);
			fRec1190[0] = fTemp1887 + fRec1190[1] * double(fVec477[1] >= fTemp1887);
			double fTemp1888 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1190[0], 1.0) - fSlow24 * double(iRec1189[0]));
			double fTemp1889 = fTemp190 + 0.0316 * fRec38[0] * (0.8472304536917363 * fTemp187 + 0.644367820561456 * fTemp353);
			double fTemp1890 = fRec260[(IOTA0 - iSlow692) & 1023];
			fVec478[0] = fTemp1890;
			iRec1191[0] = (iRec1191[1] + 1) * (fTemp1890 == 0.0);
			fRec1192[0] = fTemp1890 + fRec1192[1] * double(fVec478[1] >= fTemp1890);
			double fTemp1891 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1192[0], 1.0) - fSlow24 * double(iRec1191[0]));
			double fTemp1892 = fTemp175 + 0.0316 * fRec38[0] * (0.592529027024284 * fTemp360 - 0.24313919574706233 * fTemp17) - fTemp169;
			double fTemp1893 = fRec264[(IOTA0 - iSlow693) & 1023];
			fVec479[0] = fTemp1893;
			iRec1193[0] = (iRec1193[1] + 1) * (fTemp1893 == 0.0);
			fRec1194[0] = fTemp1893 + fRec1194[1] * double(fVec479[1] >= fTemp1893);
			double fTemp1894 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1194[0], 1.0) - fSlow24 * double(iRec1193[0]));
			double fTemp1895 = fTemp285 + 0.0316 * fRec38[0] * (0.649305587843628 * fTemp422 - 0.5265004653870164 * fTemp279) - fTemp276;
			double fTemp1896 = fRec268[(IOTA0 - iSlow694) & 1023];
			fVec480[0] = fTemp1896;
			iRec1195[0] = (iRec1195[1] + 1) * (fTemp1896 == 0.0);
			fRec1196[0] = fTemp1896 + fRec1196[1] * double(fVec480[1] >= fTemp1896);
			double fTemp1897 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1196[0], 1.0) - fSlow24 * double(iRec1195[0]));
			double fTemp1898 = fTemp162 + 0.014120110363314599 * fTemp791 - fTemp156;
			double fTemp1899 = fRec50[(IOTA0 - iSlow695) & 1023];
			fVec481[0] = fTemp1899;
			iRec1197[0] = (iRec1197[1] + 1) * (fTemp1899 == 0.0);
			fRec1198[0] = fTemp1899 + fRec1198[1] * double(fVec481[1] >= fTemp1899);
			double fTemp1900 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1198[0], 1.0) - fSlow24 * double(iRec1197[0]));
			double fTemp1901 = 0.04397194644888805 * fTemp483 - fTemp88;
			double fTemp1902 = fRec273[(IOTA0 - iSlow696) & 1023];
			fVec482[0] = fTemp1902;
			iRec1199[0] = (iRec1199[1] + 1) * (fTemp1902 == 0.0);
			fRec1200[0] = fTemp1902 + fRec1200[1] * double(fVec482[1] >= fTemp1902);
			double fTemp1903 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1200[0], 1.0) - fSlow24 * double(iRec1199[0]));
			double fTemp1904 = 0.0316 * fRec38[0] * (0.6251742428066791 * fTemp301 - 0.8585204577975674 * fTemp41) - fTemp38;
			double fTemp1905 = fRec80[(IOTA0 - iSlow697) & 1023];
			fVec483[0] = fTemp1905;
			iRec1201[0] = (iRec1201[1] + 1) * (fTemp1905 == 0.0);
			fRec1202[0] = fTemp1905 + fRec1202[1] * double(fVec483[1] >= fTemp1905);
			double fTemp1906 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1202[0], 1.0) - fSlow24 * double(iRec1201[0]));
			double fTemp1907 = 0.0316 * fRec38[0] * (0.9345949778580689 * fTemp149 + 0.18459687365975697 * fTemp78) - fTemp76;
			double fTemp1908 = fRec281[(IOTA0 - iSlow698) & 1023];
			fVec484[0] = fTemp1908;
			iRec1203[0] = (iRec1203[1] + 1) * (fTemp1908 == 0.0);
			fRec1204[0] = fTemp1908 + fRec1204[1] * double(fVec484[1] >= fTemp1908);
			double fTemp1909 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1204[0], 1.0) - fSlow24 * double(iRec1203[0]));
			double fTemp1910 = fTemp310 + 0.0316 * fRec38[0] * (0.713398630519805 * fTemp778 - 0.21308514874544926 * fTemp385) - fTemp308;
			double fTemp1911 = fRec286[(IOTA0 - iSlow699) & 1023];
			fVec485[0] = fTemp1911;
			iRec1205[0] = (iRec1205[1] + 1) * (fTemp1911 == 0.0);
			fRec1206[0] = fTemp1911 + fRec1206[1] * double(fVec485[1] >= fTemp1911);
			double fTemp1912 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1206[0], 1.0) - fSlow24 * double(iRec1205[0]));
			double fTemp1913 = fTemp319 - (fTemp317 + 0.0316 * fRec38[0] * (0.7516120487780427 * fTemp52 + 0.5727567962421745 * fTemp55));
			double fTemp1914 = fRec294[(IOTA0 - iSlow700) & 1023];
			fVec486[0] = fTemp1914;
			iRec1207[0] = (iRec1207[1] + 1) * (fTemp1914 == 0.0);
			fRec1208[0] = fTemp1914 + fRec1208[1] * double(fVec486[1] >= fTemp1914);
			double fTemp1915 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1208[0], 1.0) - fSlow24 * double(iRec1207[0]));
			double fTemp1916 = fTemp264 + 0.0316 * fRec38[0] * (0.6136910817458556 * fTemp445 + 0.03287071242084494 * fTemp324) - fTemp263;
			double fTemp1917 = fRec298[(IOTA0 - iSlow701) & 1023];
			fVec487[0] = fTemp1917;
			iRec1209[0] = (iRec1209[1] + 1) * (fTemp1917 == 0.0);
			fRec1210[0] = fTemp1917 + fRec1210[1] * double(fVec487[1] >= fTemp1917);
			double fTemp1918 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1210[0], 1.0) - fSlow24 * double(iRec1209[0]));
			double fTemp1919 = fTemp114 + 0.0316 * fRec38[0] * (0.8698283245712446 * fTemp334 + 0.18318847209593514 * fTemp335);
			double fTemp1920 = fRec302[(IOTA0 - iSlow702) & 1023];
			fVec488[0] = fTemp1920;
			iRec1211[0] = (iRec1211[1] + 1) * (fTemp1920 == 0.0);
			fRec1212[0] = fTemp1920 + fRec1212[1] * double(fVec488[1] >= fTemp1920);
			double fTemp1921 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1212[0], 1.0) - fSlow24 * double(iRec1211[0]));
			double fTemp1922 = 0.0316 * fRec38[0] * (0.6853963171161013 * fTemp343 - 0.3870238411218452 * fTemp460) - fTemp342;
			double fTemp1923 = fRec306[(IOTA0 - iSlow703) & 1023];
			fVec489[0] = fTemp1923;
			iRec1213[0] = (iRec1213[1] + 1) * (fTemp1923 == 0.0);
			fRec1214[0] = fTemp1923 + fRec1214[1] * double(fVec489[1] >= fTemp1923);
			double fTemp1924 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1214[0], 1.0) - fSlow24 * double(iRec1213[0]));
			double fTemp1925 = fTemp173 + 0.0316 * fRec38[0] * (0.6720967152577941 * fTemp360 + 0.3889925120092812 * fTemp127) - fTemp172;
			double fTemp1926 = fRec290[(IOTA0 - iSlow704) & 1023];
			fVec490[0] = fTemp1926;
			iRec1215[0] = (iRec1215[1] + 1) * (fTemp1926 == 0.0);
			fRec1216[0] = fTemp1926 + fRec1216[1] * double(fVec490[1] >= fTemp1926);
			double fTemp1927 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1216[0], 1.0) - fSlow24 * double(iRec1215[0]));
			double fTemp1928 = 0.038177613682960514 * fTemp367 - fTemp279;
			double fTemp1929 = fRec310[(IOTA0 - iSlow705) & 1023];
			fVec491[0] = fTemp1929;
			iRec1217[0] = (iRec1217[1] + 1) * (fTemp1929 == 0.0);
			fRec1218[0] = fTemp1929 + fRec1218[1] * double(fVec491[1] >= fTemp1929);
			double fTemp1930 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1218[0], 1.0) - fSlow24 * double(iRec1217[0]));
			double fTemp1931 = fTemp101 + 0.0316 * fRec38[0] * (0.2647312236476864 * fTemp478 - 0.44305123139201896 * fTemp97) - fTemp100;
			double fTemp1932 = fRec314[(IOTA0 - iSlow706) & 1023];
			fVec492[0] = fTemp1932;
			iRec1219[0] = (iRec1219[1] + 1) * (fTemp1932 == 0.0);
			fRec1220[0] = fTemp1932 + fRec1220[1] * double(fVec492[1] >= fTemp1932);
			double fTemp1933 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1220[0], 1.0) - fSlow24 * double(iRec1219[0]));
			double fTemp1934 = 0.0316 * fRec38[0] * (0.5496195154410088 * fTemp90 - 0.5562711304701224 * fTemp62) - fTemp66;
			double fTemp1935 = fRec318[(IOTA0 - iSlow707) & 1023];
			fVec493[0] = fTemp1935;
			iRec1221[0] = (iRec1221[1] + 1) * (fTemp1935 == 0.0);
			fRec1222[0] = fTemp1935 + fRec1222[1] * double(fVec493[1] >= fTemp1935);
			double fTemp1936 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1222[0], 1.0) - fSlow24 * double(iRec1221[0]));
			double fTemp1937 = fTemp148 + 0.026979144544210434 * fTemp378 - fTemp147;
			double fTemp1938 = fRec322[(IOTA0 - iSlow708) & 1023];
			fVec494[0] = fTemp1938;
			iRec1223[0] = (iRec1223[1] + 1) * (fTemp1938 == 0.0);
			fRec1224[0] = fTemp1938 + fRec1224[1] * double(fVec494[1] >= fTemp1938);
			double fTemp1939 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1224[0], 1.0) - fSlow24 * double(iRec1223[0]));
			fRec1225[0] = fSlow710 + fConst10 * fRec1225[1];
			double fTemp1940 = fTemp38 + 0.03799177213426993 * fTemp372;
			double fTemp1941 = fRec40[(IOTA0 - iSlow711) & 1023];
			fVec495[0] = fTemp1941;
			iRec1226[0] = (iRec1226[1] + 1) * (fTemp1941 == 0.0);
			fRec1227[0] = fTemp1941 + fRec1227[1] * double(fVec495[1] >= fTemp1941);
			double fTemp1942 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1227[0], 1.0) - fSlow24 * double(iRec1226[0]));
			double fTemp1943 = fTemp88 + 0.01710278069769047 * fTemp63;
			double fTemp1944 = fRec68[(IOTA0 - iSlow712) & 1023];
			fVec496[0] = fTemp1944;
			iRec1228[0] = (iRec1228[1] + 1) * (fTemp1944 == 0.0);
			fRec1229[0] = fTemp1944 + fRec1229[1] * double(fVec496[1] >= fTemp1944);
			double fTemp1945 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1229[0], 1.0) - fSlow24 * double(iRec1228[0]));
			double fTemp1946 = fTemp616 + 0.023840206772834063 * fTemp63;
			double fTemp1947 = fRec256[(IOTA0 - iSlow713) & 1023];
			fVec497[0] = fTemp1947;
			iRec1230[0] = (iRec1230[1] + 1) * (fTemp1947 == 0.0);
			fRec1231[0] = fTemp1947 + fRec1231[1] * double(fVec497[1] >= fTemp1947);
			double fTemp1948 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1231[0], 1.0) - fSlow24 * double(iRec1230[0]));
			double fTemp1949 = 0.0316 * fRec38[0] * (0.4234212453884538 * fTemp149 + 0.2492625098420831 * fTemp78) - fTemp76;
			double fTemp1950 = fRec62[(IOTA0 - iSlow714) & 1023];
			fVec498[0] = fTemp1950;
			iRec1232[0] = (iRec1232[1] + 1) * (fTemp1950 == 0.0);
			fRec1233[0] = fTemp1950 + fRec1233[1] * double(fVec498[1] >= fTemp1950);
			double fTemp1951 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1233[0], 1.0) - fSlow24 * double(iRec1232[0]));
			double fTemp1952 = fTemp162 + 0.02247023914785241 * fRec38[0] * fTemp161 - fTemp156;
			double fTemp1953 = fRec74[(IOTA0 - iSlow715) & 1023];
			fVec499[0] = fTemp1953;
			iRec1234[0] = (iRec1234[1] + 1) * (fTemp1953 == 0.0);
			fRec1235[0] = fTemp1953 + fRec1235[1] * double(fVec499[1] >= fTemp1953);
			double fTemp1954 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1235[0], 1.0) - fSlow24 * double(iRec1234[0]));
			double fTemp1955 = fTemp285 + 0.03054418002641178 * fTemp648 - fTemp276;
			double fTemp1956 = fRec334[(IOTA0 - iSlow716) & 1023];
			fVec500[0] = fTemp1956;
			iRec1236[0] = (iRec1236[1] + 1) * (fTemp1956 == 0.0);
			fRec1237[0] = fTemp1956 + fRec1237[1] * double(fVec500[1] >= fTemp1956);
			double fTemp1957 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1237[0], 1.0) - fSlow24 * double(iRec1236[0]));
			double fTemp1958 = fTemp175 + 0.0316 * fRec38[0] * (0.0059067872643936425 * fTemp360 + 0.5492511081465636 * fTemp174) - fTemp169;
			double fTemp1959 = fRec330[(IOTA0 - iSlow717) & 1023];
			fVec501[0] = fTemp1959;
			iRec1238[0] = (iRec1238[1] + 1) * (fTemp1959 == 0.0);
			fRec1239[0] = fTemp1959 + fRec1239[1] * double(fVec501[1] >= fTemp1959);
			double fTemp1960 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1239[0], 1.0) - fSlow24 * double(iRec1238[0]));
			double fTemp1961 = fTemp190 + 0.0316 * fRec38[0] * (0.6892867331043817 * fTemp353 + 0.7177519435135764 * fTemp187);
			double fTemp1962 = fRec326[(IOTA0 - iSlow718) & 1023];
			fVec502[0] = fTemp1962;
			iRec1240[0] = (iRec1240[1] + 1) * (fTemp1962 == 0.0);
			fRec1241[0] = fTemp1962 + fRec1241[1] * double(fVec502[1] >= fTemp1962);
			double fTemp1963 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1241[0], 1.0) - fSlow24 * double(iRec1240[0]));
			double fTemp1964 = fTemp204 + 0.0316 * fRec38[0] * (0.18601377961749677 * fTemp863 - 0.6302871528969263 * fTemp342) - fTemp197;
			double fTemp1965 = fRec322[(IOTA0 - iSlow719) & 1023];
			fVec503[0] = fTemp1965;
			iRec1242[0] = (iRec1242[1] + 1) * (fTemp1965 == 0.0);
			fRec1243[0] = fTemp1965 + fRec1243[1] * double(fVec503[1] >= fTemp1965);
			double fTemp1966 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1243[0], 1.0) - fSlow24 * double(iRec1242[0]));
			double fTemp1967 = fTemp269 + 0.0316 * fRec38[0] * (0.825943083551465 * fTemp446 + 0.8325091829756275 * fTemp856) - fTemp260;
			double fTemp1968 = fRec318[(IOTA0 - iSlow720) & 1023];
			fVec504[0] = fTemp1968;
			iRec1244[0] = (iRec1244[1] + 1) * (fTemp1968 == 0.0);
			fRec1245[0] = fTemp1968 + fRec1245[1] * double(fVec504[1] >= fTemp1968);
			double fTemp1969 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1245[0], 1.0) - fSlow24 * double(iRec1244[0]));
			double fTemp1970 = fTemp242 + 0.026073706645249335 * fRec38[0] * fTemp236 - fTemp233;
			double fTemp1971 = fRec314[(IOTA0 - iSlow721) & 1023];
			fVec505[0] = fTemp1971;
			iRec1246[0] = (iRec1246[1] + 1) * (fTemp1971 == 0.0);
			fRec1247[0] = fTemp1971 + fRec1247[1] * double(fVec505[1] >= fTemp1971);
			double fTemp1972 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1247[0], 1.0) - fSlow24 * double(iRec1246[0]));
			double fTemp1973 = fTemp218 + 0.0316 * fRec38[0] * (0.5372292527899845 * fTemp778 + 0.38803346188069554 * fTemp214) - fTemp211;
			double fTemp1974 = fRec310[(IOTA0 - iSlow722) & 1023];
			fVec506[0] = fTemp1974;
			iRec1248[0] = (iRec1248[1] + 1) * (fTemp1974 == 0.0);
			fRec1249[0] = fTemp1974 + fRec1249[1] * double(fVec506[1] >= fTemp1974);
			double fTemp1975 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1249[0], 1.0) - fSlow24 * double(iRec1248[0]));
			double fTemp1976 = fTemp226 + 0.0316 * fRec38[0] * (0.4012386845133733 * fTemp149 - 0.8016299982555211 * fTemp76) - fTemp225;
			double fTemp1977 = fRec290[(IOTA0 - iSlow723) & 1023];
			fVec507[0] = fTemp1977;
			iRec1250[0] = (iRec1250[1] + 1) * (fTemp1977 == 0.0);
			fRec1251[0] = fTemp1977 + fRec1251[1] * double(fVec507[1] >= fTemp1977);
			double fTemp1978 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1251[0], 1.0) - fSlow24 * double(iRec1250[0]));
			double fTemp1979 = fTemp214 + 0.0316 * fRec38[0] * (0.15357177444093395 * fTemp309 - 0.7758570643636631 * fTemp1664);
			double fTemp1980 = fRec226[(IOTA0 - iSlow724) & 1023];
			fVec508[0] = fTemp1980;
			iRec1252[0] = (iRec1252[1] + 1) * (fTemp1980 == 0.0);
			fRec1253[0] = fTemp1980 + fRec1253[1] * double(fVec508[1] >= fTemp1980);
			double fTemp1981 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1253[0], 1.0) - fSlow24 * double(iRec1252[0]));
			double fTemp1982 = fTemp1443 - (fTemp1442 + 0.029499953384662516 * fRec38[0] * fTemp1439);
			double fTemp1983 = fRec94[(IOTA0 - iSlow725) & 1023];
			fVec509[0] = fTemp1983;
			iRec1254[0] = (iRec1254[1] + 1) * (fTemp1983 == 0.0);
			fRec1255[0] = fTemp1983 + fRec1255[1] * double(fVec509[1] >= fTemp1983);
			double fTemp1984 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1255[0], 1.0) - fSlow24 * double(iRec1254[0]));
			double fTemp1985 = fTemp1024 + 0.0316 * fRec38[0] * (0.960448391509999 * fTemp1702 + 0.11318930982088204 * fTemp560);
			double fTemp1986 = fRec198[(IOTA0 - iSlow726) & 1023];
			fVec510[0] = fTemp1986;
			iRec1256[0] = (iRec1256[1] + 1) * (fTemp1986 == 0.0);
			fRec1257[0] = fTemp1986 + fRec1257[1] * double(fVec510[1] >= fTemp1986);
			double fTemp1987 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1257[0], 1.0) - fSlow24 * double(iRec1256[0]));
			double fTemp1988 = fTemp1648 + 0.0316 * fRec38[0] * (0.2965347018907778 * fTemp35 + 0.07935165087110363 * fTemp568) - fTemp1642;
			double fTemp1989 = fRec193[(IOTA0 - iSlow727) & 1023];
			fVec511[0] = fTemp1989;
			iRec1258[0] = (iRec1258[1] + 1) * (fTemp1989 == 0.0);
			fRec1259[0] = fTemp1989 + fRec1259[1] * double(fVec511[1] >= fTemp1989);
			double fTemp1990 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1259[0], 1.0) - fSlow24 * double(iRec1258[0]));
			double fTemp1991 = fTemp1250 + 0.031673359577041996 * fTemp1658 - fTemp1249;
			double fTemp1992 = fRec188[(IOTA0 - iSlow728) & 1023];
			fVec512[0] = fTemp1992;
			iRec1260[0] = (iRec1260[1] + 1) * (fTemp1992 == 0.0);
			fRec1261[0] = fTemp1992 + fRec1261[1] * double(fVec512[1] >= fTemp1992);
			double fTemp1993 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1261[0], 1.0) - fSlow24 * double(iRec1260[0]));
			double fTemp1994 = fTemp1242 + 0.0316 * fRec38[0] * (0.5391583607679422 * fTemp236 + 0.4287220129185698 * fTemp35) - fTemp1241;
			double fTemp1995 = fRec184[(IOTA0 - iSlow729) & 1023];
			fVec513[0] = fTemp1995;
			iRec1262[0] = (iRec1262[1] + 1) * (fTemp1995 == 0.0);
			fRec1263[0] = fTemp1995 + fRec1263[1] * double(fVec513[1] >= fTemp1995);
			double fTemp1996 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1263[0], 1.0) - fSlow24 * double(iRec1262[0]));
			double fTemp1997 = fTemp1034 + 0.0316 * fRec38[0] * (0.45104990408435697 * fTemp214 + 0.8032693931781978 * fTemp35) - fTemp1033;
			double fTemp1998 = fRec179[(IOTA0 - iSlow730) & 1023];
			fVec514[0] = fTemp1998;
			iRec1264[0] = (iRec1264[1] + 1) * (fTemp1998 == 0.0);
			fRec1265[0] = fTemp1998 + fRec1265[1] * double(fVec514[1] >= fTemp1998);
			double fTemp1999 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1265[0], 1.0) - fSlow24 * double(iRec1264[0]));
			double fTemp2000 = 0.0316 * fRec38[0] * (0.8327904843026772 * fTemp845 + 0.7496445077413227 * fTemp35) - fTemp32;
			double fTemp2001 = fRec100[(IOTA0 - iSlow731) & 1023];
			fVec515[0] = fTemp2001;
			iRec1266[0] = (iRec1266[1] + 1) * (fTemp2001 == 0.0);
			fRec1267[0] = fTemp2001 + fRec1267[1] * double(fVec515[1] >= fTemp2001);
			double fTemp2002 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1267[0], 1.0) - fSlow24 * double(iRec1266[0]));
			double fTemp2003 = 0.0316 * fRec38[0] * (0.8142891520474222 * fTemp35 - 0.7531310285849031 * fTemp23) - fTemp26;
			double fTemp2004 = fRec174[(IOTA0 - iSlow732) & 1023];
			fVec516[0] = fTemp2004;
			iRec1268[0] = (iRec1268[1] + 1) * (fTemp2004 == 0.0);
			fRec1269[0] = fTemp2004 + fRec1269[1] * double(fVec516[1] >= fTemp2004);
			double fTemp2005 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1269[0], 1.0) - fSlow24 * double(iRec1268[0]));
			double fTemp2006 = ((iTemp14) ? 0.0 : fConst614 + fRec1270[1]);
			fRec1270[0] = fTemp2006 - std::floor(fTemp2006);
			int iTemp2007 = std::max<int>(0, std::min<int>(int(65536.0 * fRec1270[0]), 65535));
			double fTemp2008 = 0.9921970955168659 * ftbl1TonewheelSIG1[iTemp2007] + 0.12467928315440088 * ftbl0TonewheelSIG0[iTemp2007];
			double fTemp2009 = fTemp2008 + 0.0316 * fRec38[0] * (0.1420451709709596 * fTemp35 - 0.3840526678832248 * fTemp616);
			double fTemp2010 = fRec168[(IOTA0 - iSlow733) & 1023];
			fVec517[0] = fTemp2010;
			iRec1271[0] = (iRec1271[1] + 1) * (fTemp2010 == 0.0);
			fRec1272[0] = fTemp2010 + fRec1272[1] * double(fVec517[1] >= fTemp2010);
			double fTemp2011 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1272[0], 1.0) - fSlow24 * double(iRec1271[0]));
			double fTemp2012 = 0.0316 * fRec38[0] * (0.39600668635830516 * fTemp35 + 0.5197039897466311 * fTemp1444) - fTemp1439;
			double fTemp2013 = fRec106[(IOTA0 - iSlow734) & 1023];
			fVec518[0] = fTemp2013;
			iRec1273[0] = (iRec1273[1] + 1) * (fTemp2013 == 0.0);
			fRec1274[0] = fTemp2013 + fRec1274[1] * double(fVec518[1] >= fTemp2013);
			double fTemp2014 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1274[0], 1.0) - fSlow24 * double(iRec1273[0]));
			double fTemp2015 = 0.03840400378295017 * fTemp1658 - fTemp1232;
			double fTemp2016 = fRec164[(IOTA0 - iSlow735) & 1023];
			fVec519[0] = fTemp2016;
			iRec1275[0] = (iRec1275[1] + 1) * (fTemp2016 == 0.0);
			fRec1276[0] = fTemp2016 + fRec1276[1] * double(fVec519[1] >= fTemp2016);
			double fTemp2017 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1276[0], 1.0) - fSlow24 * double(iRec1275[0]));
			double fTemp2018 = 0.0316 * fRec38[0] * (0.73144448432231 * fTemp35 - 0.9577372708458824 * fTemp20) - fTemp29;
			double fTemp2019 = fRec112[(IOTA0 - iSlow736) & 1023];
			fVec520[0] = fTemp2019;
			iRec1277[0] = (iRec1277[1] + 1) * (fTemp2019 == 0.0);
			fRec1278[0] = fTemp2019 + fRec1278[1] * double(fVec520[1] >= fTemp2019);
			double fTemp2020 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1278[0], 1.0) - fSlow24 * double(iRec1277[0]));
			double fTemp2021 = fTemp1632 + 0.024834054321892476 * fTemp1658 - fTemp1631;
			double fTemp2022 = fRec119[(IOTA0 - iSlow737) & 1023];
			fVec521[0] = fTemp2022;
			iRec1279[0] = (iRec1279[1] + 1) * (fTemp2022 == 0.0);
			fRec1280[0] = fTemp2022 + fRec1280[1] * double(fVec521[1] >= fTemp2022);
			double fTemp2023 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1280[0], 1.0) - fSlow24 * double(iRec1279[0]));
			double fTemp2024 = fTemp1701 + 0.0316 * fRec38[0] * (0.049611582046054536 * fTemp35 + 0.9986752791010076 * fTemp560) - fTemp1700;
			double fTemp2025 = fRec125[(IOTA0 - iSlow738) & 1023];
			fVec522[0] = fTemp2025;
			iRec1281[0] = (iRec1281[1] + 1) * (fTemp2025 == 0.0);
			fRec1282[0] = fTemp2025 + fRec1282[1] * double(fVec522[1] >= fTemp2025);
			double fTemp2026 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1282[0], 1.0) - fSlow24 * double(iRec1281[0]));
			double fTemp2027 = fTemp1646 + 0.02116456686691381 * fRec38[0] * fTemp1694 - fTemp1645;
			double fTemp2028 = fRec150[(IOTA0 - iSlow739) & 1023];
			fVec523[0] = fTemp2028;
			iRec1283[0] = (iRec1283[1] + 1) * (fTemp2028 == 0.0);
			fRec1284[0] = fTemp2028 + fRec1284[1] * double(fVec523[1] >= fTemp2028);
			double fTemp2029 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1284[0], 1.0) - fSlow24 * double(iRec1283[0]));
			double fTemp2030 = fTemp1689 + 0.0316 * fRec38[0] * (0.17917206822312437 * fTemp268 + 0.5362393812611117 * fTemp1251) - fTemp1688;
			double fTemp2031 = fRec157[(IOTA0 - iSlow740) & 1023];
			fVec524[0] = fTemp2031;
			iRec1285[0] = (iRec1285[1] + 1) * (fTemp2031 == 0.0);
			fRec1286[0] = fTemp2031 + fRec1286[1] * double(fVec524[1] >= fTemp2031);
			double fTemp2032 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1286[0], 1.0) - fSlow24 * double(iRec1285[0]));
			double fTemp2033 = 0.0316 * fRec38[0] * (0.08806695305247558 * fTemp1243 + 0.9951155932722031 * fTemp35) - fTemp1462;
			double fTemp2034 = fRec144[(IOTA0 - iSlow741) & 1023];
			fVec525[0] = fTemp2034;
			iRec1287[0] = (iRec1287[1] + 1) * (fTemp2034 == 0.0);
			fRec1288[0] = fTemp2034 + fRec1288[1] * double(fVec525[1] >= fTemp2034);
			double fTemp2035 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1288[0], 1.0) - fSlow24 * double(iRec1287[0]));
			double fTemp2036 = 0.03254410445707909 * fTemp1658 - fTemp1664;
			double fTemp2037 = fRec132[(IOTA0 - iSlow742) & 1023];
			fVec526[0] = fTemp2037;
			iRec1289[0] = (iRec1289[1] + 1) * (fTemp2037 == 0.0);
			fRec1290[0] = fTemp2037 + fRec1290[1] * double(fVec526[1] >= fTemp2037);
			double fTemp2038 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1290[0], 1.0) - fSlow24 * double(iRec1289[0]));
			double fTemp2039 = fTemp35 + 0.0316 * fRec38[0] * (0.30072774367727106 * fTemp35 + 0.6264845057503408 * fTemp845);
			double fTemp2040 = fRec137[(IOTA0 - iSlow743) & 1023];
			fVec527[0] = fTemp2040;
			iRec1291[0] = (iRec1291[1] + 1) * (fTemp2040 == 0.0);
			fRec1292[0] = fTemp2040 + fRec1292[1] * double(fVec527[1] >= fTemp2040);
			double fTemp2041 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1292[0], 1.0) - fSlow24 * double(iRec1291[0]));
			double fTemp2042 = fTemp1017 + 0.0474406396736129 * fTemp1658 - fTemp1016;
			double fTemp2043 = fRec204[(IOTA0 - iSlow744) & 1023];
			fVec528[0] = fTemp2043;
			iRec1293[0] = (iRec1293[1] + 1) * (fTemp2043 == 0.0);
			fRec1294[0] = fTemp2043 + fRec1294[1] * double(fVec528[1] >= fTemp2043);
			double fTemp2044 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1294[0], 1.0) - fSlow24 * double(iRec1293[0]));
			double fTemp2045 = 0.0316 * fRec38[0] * (0.25683896501141135 * fTemp35 - 0.7139205645726179 * fTemp17) - fTemp20;
			double fTemp2046 = fRec209[(IOTA0 - iSlow745) & 1023];
			fVec529[0] = fTemp2046;
			iRec1295[0] = (iRec1295[1] + 1) * (fTemp2046 == 0.0);
			fRec1296[0] = fTemp2046 + fRec1296[1] * double(fVec529[1] >= fTemp2046);
			double fTemp2047 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1296[0], 1.0) - fSlow24 * double(iRec1295[0]));
			double fTemp2048 = fTemp1006 + 0.0316 * fRec38[0] * (0.7977460485017218 * fTemp284 + 0.5160383406728215 * fTemp598) - fTemp1005;
			double fTemp2049 = fRec213[(IOTA0 - iSlow746) & 1023];
			fVec530[0] = fTemp2049;
			iRec1297[0] = (iRec1297[1] + 1) * (fTemp2049 == 0.0);
			fRec1298[0] = fTemp2049 + fRec1298[1] * double(fVec530[1] >= fTemp2049);
			double fTemp2050 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1298[0], 1.0) - fSlow24 * double(iRec1297[0]));
			double fTemp2051 = fTemp855 + 0.0316 * fRec38[0] * (0.3454818871541647 * fTemp1251 + 0.9956316082243575 * fTemp268) - fTemp854;
			double fTemp2052 = fRec273[(IOTA0 - iSlow747) & 1023];
			fVec531[0] = fTemp2052;
			iRec1299[0] = (iRec1299[1] + 1) * (fTemp2052 == 0.0);
			fRec1300[0] = fTemp2052 + fRec1300[1] * double(fVec531[1] >= fTemp2052);
			double fTemp2053 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1300[0], 1.0) - fSlow24 * double(iRec1299[0]));
			double fTemp2054 = fTemp1223 + 0.0316 * fRec38[0] * (0.3295705856880886 * fTemp35 - 0.1975258658239909 * fTemp616);
			double fTemp2055 = fRec56[(IOTA0 - iSlow748) & 1023];
			fVec532[0] = fTemp2055;
			iRec1301[0] = (iRec1301[1] + 1) * (fTemp2055 == 0.0);
			fRec1302[0] = fTemp2055 + fRec1302[1] * double(fVec532[1] >= fTemp2055);
			double fTemp2056 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1302[0], 1.0) - fSlow24 * double(iRec1301[0]));
			double fTemp2057 = 0.0316 * fRec38[0] * (0.5839929188477981 * fTemp584 - 0.7723873725408339 * fTemp26) - fTemp23;
			double fTemp2058 = fRec217[(IOTA0 - iSlow749) & 1023];
			fVec533[0] = fTemp2058;
			iRec1303[0] = (iRec1303[1] + 1) * (fTemp2058 == 0.0);
			fRec1304[0] = fTemp2058 + fRec1304[1] * double(fVec533[1] >= fTemp2058);
			double fTemp2059 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1304[0], 1.0) - fSlow24 * double(iRec1303[0]));
			double fTemp2060 = fTemp844 - (fTemp843 + 0.04905879515064008 * fRec38[0] * fTemp32);
			double fTemp2061 = fRec221[(IOTA0 - iSlow750) & 1023];
			fVec534[0] = fTemp2061;
			iRec1305[0] = (iRec1305[1] + 1) * (fTemp2061 == 0.0);
			fRec1306[0] = fTemp2061 + fRec1306[1] * double(fVec534[1] >= fTemp2061);
			double fTemp2062 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1306[0], 1.0) - fSlow24 * double(iRec1305[0]));
			double fTemp2063 = fTemp268 + 0.0316 * fRec38[0] * (0.03903703541436698 * fTemp1690 + 0.7427452806150541 * fTemp324);
			double fTemp2064 = fRec235[(IOTA0 - iSlow751) & 1023];
			fVec535[0] = fTemp2064;
			iRec1307[0] = (iRec1307[1] + 1) * (fTemp2064 == 0.0);
			fRec1308[0] = fTemp2064 + fRec1308[1] * double(fVec535[1] >= fTemp2064);
			double fTemp2065 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1308[0], 1.0) - fSlow24 * double(iRec1307[0]));
			double fTemp2066 = fTemp240 + 0.0316 * fRec38[0] * (0.22297807142604142 * fTemp1243 + 0.4677196360862581 * fTemp318) - fTemp239;
			double fTemp2067 = fRec230[(IOTA0 - iSlow752) & 1023];
			fVec536[0] = fTemp2067;
			iRec1309[0] = (iRec1309[1] + 1) * (fTemp2067 == 0.0);
			fRec1310[0] = fTemp2067 + fRec1310[1] * double(fVec536[1] >= fTemp2067);
			double fTemp2068 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1310[0], 1.0) - fSlow24 * double(iRec1309[0]));
			double fTemp2069 = fTemp360 + 0.0316 * fRec38[0] * (0.07758243321222835 * fTemp174 - 0.09418179361637158 * fTemp17);
			double fTemp2070 = fRec294[(IOTA0 - iSlow753) & 1023];
			fVec537[0] = fTemp2070;
			iRec1311[0] = (iRec1311[1] + 1) * (fTemp2070 == 0.0);
			fRec1312[0] = fTemp2070 + fRec1312[1] * double(fVec537[1] >= fTemp2070);
			double fTemp2071 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1312[0], 1.0) - fSlow24 * double(iRec1311[0]));
			double fTemp2072 = fTemp567 + 0.0316 * fRec38[0] * (0.22263883054984035 * fTemp335 + 0.7149682065246452 * fTemp1694) - fTemp566;
			double fTemp2073 = fRec239[(IOTA0 - iSlow754) & 1023];
			fVec538[0] = fTemp2073;
			iRec1313[0] = (iRec1313[1] + 1) * (fTemp2073 == 0.0);
			fRec1314[0] = fTemp2073 + fRec1314[1] * double(fVec538[1] >= fTemp2073);
			double fTemp2074 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1314[0], 1.0) - fSlow24 * double(iRec1313[0]));
			double fTemp2075 = fTemp560 + 0.0316 * fRec38[0] * (0.5039190763495753 * fTemp1702 + 0.49428263390745997 * fTemp1024);
			double fTemp2076 = fRec243[(IOTA0 - iSlow755) & 1023];
			fVec539[0] = fTemp2076;
			iRec1315[0] = (iRec1315[1] + 1) * (fTemp2076 == 0.0);
			fRec1316[0] = fTemp2076 + fRec1316[1] * double(fVec539[1] >= fTemp2076);
			double fTemp2077 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1316[0], 1.0) - fSlow24 * double(iRec1315[0]));
			double fTemp2078 = fTemp553 + 0.02848760729167916 * fRec38[0] * fTemp190 - fTemp552;
			double fTemp2079 = fRec247[(IOTA0 - iSlow756) & 1023];
			fVec540[0] = fTemp2079;
			iRec1317[0] = (iRec1317[1] + 1) * (fTemp2079 == 0.0);
			fRec1318[0] = fTemp2079 + fRec1318[1] * double(fVec540[1] >= fTemp2079);
			double fTemp2080 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1318[0], 1.0) - fSlow24 * double(iRec1317[0]));
			double fTemp2081 = fTemp597 + 0.0316 * fRec38[0] * (0.6042162822777755 * fTemp1007 + 0.6522524332685862 * fTemp366) - fTemp596;
			double fTemp2082 = fRec252[(IOTA0 - iSlow757) & 1023];
			fVec541[0] = fTemp2082;
			iRec1319[0] = (iRec1319[1] + 1) * (fTemp2082 == 0.0);
			fRec1320[0] = fTemp2082 + fRec1320[1] * double(fVec541[1] >= fTemp2082);
			double fTemp2083 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1320[0], 1.0) - fSlow24 * double(iRec1319[0]));
			double fTemp2084 = 0.024086161840488788 * fTemp677 - fTemp17;
			double fTemp2085 = fRec89[(IOTA0 - iSlow758) & 1023];
			fVec542[0] = fTemp2085;
			iRec1321[0] = (iRec1321[1] + 1) * (fTemp2085 == 0.0);
			fRec1322[0] = fTemp2085 + fRec1322[1] * double(fVec542[1] >= fTemp2085);
			double fTemp2086 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1322[0], 1.0) - fSlow24 * double(iRec1321[0]));
			double fTemp2087 = fTemp160 + 0.0316 * fRec38[0] * (0.7636369440806448 * fTemp478 - 0.8937493907360476 * fTemp1439) - fTemp159;
			double fTemp2088 = fRec84[(IOTA0 - iSlow759) & 1023];
			fVec543[0] = fTemp2088;
			iRec1323[0] = (iRec1323[1] + 1) * (fTemp2088 == 0.0);
			fRec1324[0] = fTemp2088 + fRec1324[1] * double(fVec543[1] >= fTemp2088);
			double fTemp2089 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1324[0], 1.0) - fSlow24 * double(iRec1323[0]));
			double fTemp2090 = fTemp584 - 0.0316 * fRec38[0] * (0.3369354481837945 * fTemp23 + 0.6924525286740391 * fTemp38);
			double fTemp2091 = fRec260[(IOTA0 - iSlow760) & 1023];
			fVec544[0] = fTemp2091;
			iRec1325[0] = (iRec1325[1] + 1) * (fTemp2091 == 0.0);
			fRec1326[0] = fTemp2091 + fRec1326[1] * double(fVec544[1] >= fTemp2091);
			double fTemp2092 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1326[0], 1.0) - fSlow24 * double(iRec1325[0]));
			double fTemp2093 = 0.015051074570671336 * fTemp378 - fTemp144;
			double fTemp2094 = fRec264[(IOTA0 - iSlow761) & 1023];
			fVec545[0] = fTemp2094;
			iRec1327[0] = (iRec1327[1] + 1) * (fTemp2094 == 0.0);
			fRec1328[0] = fTemp2094 + fRec1328[1] * double(fVec545[1] >= fTemp2094);
			double fTemp2095 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1328[0], 1.0) - fSlow24 * double(iRec1327[0]));
			double fTemp2096 = fTemp777 + 0.0316 * fRec38[0] * (0.1366955286475786 * fTemp1035 + 0.025812558758843807 * fTemp386) - fTemp776;
			double fTemp2097 = fRec268[(IOTA0 - iSlow762) & 1023];
			fVec546[0] = fTemp2097;
			iRec1329[0] = (iRec1329[1] + 1) * (fTemp2097 == 0.0);
			fRec1330[0] = fTemp2097 + fRec1330[1] * double(fVec546[1] >= fTemp2097);
			double fTemp2098 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1330[0], 1.0) - fSlow24 * double(iRec1329[0]));
			double fTemp2099 = fTemp236 + 0.03424366016167915 * fRec38[0] * fTemp241;
			double fTemp2100 = fRec50[(IOTA0 - iSlow763) & 1023];
			fVec547[0] = fTemp2100;
			iRec1331[0] = (iRec1331[1] + 1) * (fTemp2100 == 0.0);
			fRec1332[0] = fTemp2100 + fRec1332[1] * double(fVec547[1] >= fTemp2100);
			double fTemp2101 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1332[0], 1.0) - fSlow24 * double(iRec1331[0]));
			double fTemp2102 = fTemp333 + 0.0316 * fRec38[0] * (0.03405418709735386 * fTemp114 + 0.5763081691547995 * fTemp1694) - fTemp332;
			double fTemp2103 = fRec80[(IOTA0 - iSlow764) & 1023];
			fVec548[0] = fTemp2103;
			iRec1333[0] = (iRec1333[1] + 1) * (fTemp2103 == 0.0);
			fRec1334[0] = fTemp2103 + fRec1334[1] * double(fVec548[1] >= fTemp2103);
			double fTemp2104 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1334[0], 1.0) - fSlow24 * double(iRec1333[0]));
			double fTemp2105 = fTemp831 + 0.0316 * fRec38[0] * (0.35785881231277017 * fTemp560 - 0.4571923206676729 * fTemp342) - fTemp830;
			double fTemp2106 = fRec281[(IOTA0 - iSlow765) & 1023];
			fVec549[0] = fTemp2106;
			iRec1335[0] = (iRec1335[1] + 1) * (fTemp2106 == 0.0);
			fRec1336[0] = fTemp2106 + fRec1336[1] * double(fVec549[1] >= fTemp2106);
			double fTemp2107 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1336[0], 1.0) - fSlow24 * double(iRec1335[0]));
			double fTemp2108 = 0.044619428767908545 * fRec38[0] * fTemp1018 - fTemp182;
			double fTemp2109 = fRec286[(IOTA0 - iSlow766) & 1023];
			fVec550[0] = fTemp2109;
			iRec1337[0] = (iRec1337[1] + 1) * (fTemp2109 == 0.0);
			fRec1338[0] = fTemp2109 + fRec1338[1] * double(fVec550[1] >= fTemp2109);
			double fTemp2110 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1338[0], 1.0) - fSlow24 * double(iRec1337[0]));
			double fTemp2111 = fTemp283 + 0.03396680001089188 * fTemp367 - fTemp282;
			double fTemp2112 = fRec298[(IOTA0 - iSlow767) & 1023];
			fVec551[0] = fTemp2112;
			iRec1339[0] = (iRec1339[1] + 1) * (fTemp2112 == 0.0);
			fRec1340[0] = fTemp2112 + fRec1340[1] * double(fVec551[1] >= fTemp2112);
			double fTemp2113 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1340[0], 1.0) - fSlow24 * double(iRec1339[0]));
			double fTemp2114 = fTemp136 + 0.0316 * fRec38[0] * (0.2816690641484456 * fTemp478 + 0.702156978793937 * fTemp1444) - fTemp135;
			double fTemp2115 = fRec302[(IOTA0 - iSlow768) & 1023];
			fVec552[0] = fTemp2115;
			iRec1341[0] = (iRec1341[1] + 1) * (fTemp2115 == 0.0);
			fRec1342[0] = fTemp2115 + fRec1342[1] * double(fVec552[1] >= fTemp2115);
			double fTemp2116 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1342[0], 1.0) - fSlow24 * double(iRec1341[0]));
			double fTemp2117 = 0.0316 * fRec38[0] * (0.8940177866097656 * fTemp1223 - 0.014896930355462246 * fTemp66) - fTemp62;
			double fTemp2118 = fRec306[(IOTA0 - iSlow769) & 1023];
			fVec553[0] = fTemp2118;
			iRec1343[0] = (iRec1343[1] + 1) * (fTemp2118 == 0.0);
			fRec1344[0] = fTemp2118 + fRec1344[1] * double(fVec553[1] >= fTemp2118);
			double fTemp2119 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1344[0], 1.0) - fSlow24 * double(iRec1343[0]));
			double fTemp2120 = fTemp301 + 0.0316 * fRec38[0] * (0.45109367364057107 * fTemp584 - 0.13441583539679414 * fTemp23);
			double fTemp2121 = fRec44[(IOTA0 - iSlow770) & 1023];
			fVec554[0] = fTemp2121;
			iRec1345[0] = (iRec1345[1] + 1) * (fTemp2121 == 0.0);
			fRec1346[0] = fTemp2121 + fRec1346[1] * double(fVec554[1] >= fTemp2121);
			double fTemp2122 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1346[0], 1.0) - fSlow24 * double(iRec1345[0]));
			double fTemp2123 = fTemp253 + 0.0316 * fRec38[0] * (0.6185700464466208 * fTemp114 + 0.7922644336958911 * fTemp252) - fTemp249;
			double fTemp2124 = fRec277[(IOTA0 - iSlow771) & 1023];
			fVec555[0] = fTemp2124;
			iRec1347[0] = (iRec1347[1] + 1) * (fTemp2124 == 0.0);
			fRec1348[0] = fTemp2124 + fRec1348[1] * double(fVec555[1] >= fTemp2124);
			double fTemp2125 = std::max<double>(0.0, std::min<double>(fSlow24 * fRec1348[0], 1.0) - fSlow24 * double(iRec1347[0]));
			fRec1349[0] = fSlow773 + fConst10 * fRec1349[1];
			double fTemp2126 = fRec1349[0] * (fTemp454 * fTemp2125 * fTemp2123 + fTemp49 * fTemp2122 * fTemp2120 + fTemp487 * fTemp2119 * fTemp2117 + fTemp482 * fTemp2116 * fTemp2114 + fTemp477 * fTemp2113 * fTemp2111 + fTemp465 * fTemp2110 * fTemp2108 + fTemp461 * fTemp2107 * fTemp2105 + fTemp118 * fTemp2104 * fTemp2102 + fTemp59 * fTemp2101 * fTemp2099 + fTemp442 * fTemp2098 * fTemp2096 + fTemp438 * fTemp2095 * fTemp2093 + fTemp434 * fTemp2092 * fTemp2090 + fTemp122 * fTemp2089 * fTemp2087 + fTemp132 * fTemp2086 * fTemp2084 + fTemp426 * fTemp2083 * fTemp2081 + fTemp417 * fTemp2080 * fTemp2078 + fTemp412 * fTemp2077 * fTemp2075 + fTemp408 * fTemp2074 * fTemp2072 + fTemp473 * fTemp2071 * fTemp2069 + fTemp395 * fTemp2068 * fTemp2066 + fTemp404 * fTemp2065 * fTemp2063 + fTemp382 * fTemp2062 * fTemp2060 + fTemp376 * fTemp2059 * fTemp2057 + fTemp70 * fTemp2056 * fTemp2054 + fTemp450 * fTemp2053 * fTemp2051 + fTemp371 * fTemp2050 * fTemp2048 + fTemp365 * fTemp2047 * fTemp2045 + fTemp357 * fTemp2044 * fTemp2042 + fTemp230 * fTemp2041 * fTemp2039 + fTemp222 * fTemp2038 * fTemp2036 + fTemp246 * fTemp2035 * fTemp2033 + fTemp273 * fTemp2032 * fTemp2030 + fTemp257 * fTemp2029 * fTemp2027 + fTemp208 * fTemp2026 * fTemp2024 + fTemp194 * fTemp2023 * fTemp2021 + fTemp179 * fTemp2020 * fTemp2018 + fTemp289 * fTemp2017 * fTemp2015 + fTemp166 * fTemp2014 * fTemp2012 + fTemp293 * fTemp2011 * fTemp2009 + fTemp305 * fTemp2005 * fTemp2003 + fTemp153 * fTemp2002 * fTemp2000 + fTemp314 * fTemp1999 * fTemp1997 + fTemp323 * fTemp1996 * fTemp1994 + fTemp329 * fTemp1993 * fTemp1991 + fTemp339 * fTemp1990 * fTemp1988 + fTemp347 * fTemp1987 * fTemp1985 + fTemp141 * fTemp1984 * fTemp1982 + fTemp390 * fTemp1981 * fTemp1979 + fTemp469 * fTemp1978 * fTemp1976 + fTemp491 * fTemp1975 * fTemp1973 + fTemp495 * fTemp1972 * fTemp1970 + fTemp500 * fTemp1969 * fTemp1967 + fTemp504 * fTemp1966 * fTemp1964 + fTemp508 * fTemp1963 * fTemp1961 + fTemp512 * fTemp1960 * fTemp1958 + fTemp516 * fTemp1957 * fTemp1955 + fTemp106 * fTemp1954 * fTemp1952 + fTemp82 * fTemp1951 * fTemp1949 - (fTemp430 * fTemp1948 * fTemp1946 + fTemp94 * fTemp1945 * fTemp1943 + fTemp45 * fTemp1942 * fTemp1940)) + fRec1225[0] * (fTemp504 * fTemp1939 * fTemp1937 + fTemp500 * fTemp1936 * fTemp1934 + fTemp495 * fTemp1933 * fTemp1931 + fTemp491 * fTemp1930 * fTemp1928 + fTemp469 * fTemp1927 * fTemp1925 + fTemp487 * fTemp1924 * fTemp1922 + fTemp482 * fTemp1921 * fTemp1919 + fTemp477 * fTemp1918 * fTemp1916 + fTemp473 * fTemp1915 * fTemp1913 + fTemp465 * fTemp1912 * fTemp1910 + fTemp461 * fTemp1909 * fTemp1907 + fTemp118 * fTemp1906 * fTemp1904 + fTemp450 * fTemp1903 * fTemp1901 + fTemp59 * fTemp1900 * fTemp1898 + fTemp442 * fTemp1897 * fTemp1895 + fTemp438 * fTemp1894 * fTemp1892 + fTemp434 * fTemp1891 * fTemp1889 + fTemp122 * fTemp1888 * fTemp1886 + fTemp426 * fTemp1885 * fTemp1883 + fTemp132 * fTemp1882 * fTemp1880 + fTemp417 * fTemp1879 * fTemp1877 + fTemp412 * fTemp1876 * fTemp1874 + fTemp390 * fTemp1873 * fTemp1871 + fTemp382 * fTemp1870 * fTemp1868 + fTemp395 * fTemp1867 * fTemp1865 + fTemp141 * fTemp1864 * fTemp1862 + fTemp371 * fTemp1861 * fTemp1859 + fTemp365 * fTemp1858 * fTemp1856 + fTemp357 * fTemp1855 * fTemp1853 + fTemp339 * fTemp1852 * fTemp1850 + fTemp329 * fTemp1849 * fTemp1847 + fTemp323 * fTemp1846 * fTemp1844 + fTemp314 * fTemp1843 * fTemp1841 + fTemp153 * fTemp1840 * fTemp1838 + fTemp273 * fTemp1837 * fTemp1835 + fTemp246 * fTemp1834 * fTemp1832 + fTemp230 * fTemp1831 * fTemp1829 + fTemp222 * fTemp1828 * fTemp1826 + fTemp257 * fTemp1825 * fTemp1823 + fTemp208 * fTemp1822 * fTemp1820 + fTemp194 * fTemp1819 * fTemp1817 + fTemp179 * fTemp1816 * fTemp1814 + fTemp289 * fTemp1813 * fTemp1811 + fTemp166 * fTemp1810 * fTemp1808 + fTemp293 * fTemp1807 * fTemp1805 + fTemp305 * fTemp1804 * fTemp1802 + fTemp70 * fTemp1801 * fTemp1799 + fTemp376 * fTemp1798 * fTemp1796 + fTemp408 * fTemp1795 * fTemp1793 + fTemp430 * fTemp1792 * fTemp1790 + fTemp49 * fTemp1789 * fTemp1787 + fTemp454 * fTemp1786 * fTemp1784 + fTemp508 * fTemp1783 * fTemp1781 + fTemp512 * fTemp1780 * fTemp1778 + fTemp516 * fTemp1777 * fTemp1775 + fTemp106 * fTemp1774 * fTemp1772 + fTemp94 * fTemp1771 * fTemp1769 + fTemp45 * fTemp1768 * fTemp1766 + fTemp82 * fTemp1765 * fTemp1763 - (fTemp347 * fTemp1762 * fTemp1760 + fTemp404 * fTemp1759 * fTemp1757)) + fRec1102[0] * (fTemp454 * fTemp1756 * fTemp1754 + fTemp473 * fTemp1753 * fTemp1751 + fTemp465 * fTemp1750 * fTemp1748 + fTemp461 * fTemp1747 * fTemp1745 + fTemp118 * fTemp1744 * fTemp1742 + fTemp450 * fTemp1741 * fTemp1739 + fTemp59 * fTemp1738 * fTemp1736 + fTemp438 * fTemp1735 * fTemp1733 + fTemp434 * fTemp1732 * fTemp1730 + fTemp122 * fTemp1729 * fTemp1727 + fTemp426 * fTemp1726 * fTemp1724 + fTemp417 * fTemp1723 * fTemp1721 + fTemp412 * fTemp1720 * fTemp1718 + fTemp408 * fTemp1717 * fTemp1715 + fTemp404 * fTemp1714 * fTemp1712 + fTemp371 * fTemp1711 * fTemp1709 + fTemp357 * fTemp1708 * fTemp1706 + fTemp347 * fTemp1705 * fTemp1703 + fTemp339 * fTemp1697 * fTemp1695 + fTemp329 * fTemp1693 * fTemp1691 + fTemp323 * fTemp1685 * fTemp1683 + fTemp365 * fTemp1682 * fTemp1680 + fTemp314 * fTemp1679 * fTemp1677 + fTemp153 * fTemp1676 * fTemp1674 + fTemp293 * fTemp1673 * fTemp1671 + fTemp166 * fTemp1670 * fTemp1668 + fTemp222 * fTemp1667 * fTemp1665 + fTemp230 * fTemp1661 * fTemp1659 + fTemp246 * fTemp1657 * fTemp1655 + fTemp273 * fTemp1654 * fTemp1652 + fTemp257 * fTemp1651 * fTemp1649 + fTemp208 * fTemp1639 * fTemp1637 + fTemp194 * fTemp1636 * fTemp1634 + fTemp179 * fTemp1628 * fTemp1626 + fTemp289 * fTemp1625 * fTemp1623 + fTemp305 * fTemp1622 * fTemp1620 + fTemp141 * fTemp1619 * fTemp1617 + fTemp376 * fTemp1616 * fTemp1614 + fTemp390 * fTemp1613 * fTemp1611 + fTemp395 * fTemp1610 * fTemp1608 + fTemp132 * fTemp1607 * fTemp1605 + fTemp442 * fTemp1604 * fTemp1602 + fTemp477 * fTemp1601 * fTemp1599 + fTemp482 * fTemp1598 * fTemp1596 + fTemp487 * fTemp1595 * fTemp1593 + fTemp49 * fTemp1592 * fTemp1590 + fTemp491 * fTemp1589 * fTemp1587 + fTemp495 * fTemp1586 * fTemp1584 + fTemp500 * fTemp1583 * fTemp1581 + fTemp504 * fTemp1580 * fTemp1578 + fTemp508 * fTemp1577 * fTemp1575 + fTemp512 * fTemp1574 * fTemp1572 + fTemp516 * fTemp1571 * fTemp1569 + fTemp106 * fTemp1567 * fTemp1565 + fTemp45 * fTemp1564 * fTemp1562 + fTemp82 * fTemp1561 * fTemp1559 - (fTemp70 * fTemp1558 * fTemp1556 + fTemp382 * fTemp1555 * fTemp1553 + fTemp430 * fTemp1552 * fTemp1550 + fTemp469 * fTemp1549 * fTemp1547 + fTemp94 * fTemp1546 * fTemp1544)) + fRec973[0] * (fTemp508 * fTemp1543 * fTemp1541 + fTemp504 * fTemp1540 * fTemp1538 + fTemp454 * fTemp1537 * fTemp1535 + fTemp500 * fTemp1534 * fTemp1532 + fTemp495 * fTemp1531 * fTemp1529 + fTemp49 * fTemp1528 * fTemp1526 + fTemp59 * fTemp1525 * fTemp1523 + fTemp442 * fTemp1522 * fTemp1520 + fTemp438 * fTemp1519 * fTemp1517 + fTemp434 * fTemp1516 * fTemp1514 + fTemp430 * fTemp1513 * fTemp1511 + fTemp122 * fTemp1510 * fTemp1508 + fTemp132 * fTemp1507 * fTemp1505 + fTemp417 * fTemp1504 * fTemp1502 + fTemp412 * fTemp1501 * fTemp1499 + fTemp404 * fTemp1498 * fTemp1496 + fTemp395 * fTemp1495 * fTemp1493 + fTemp390 * fTemp1492 * fTemp1490 + fTemp376 * fTemp1489 * fTemp1487 + fTemp70 * fTemp1486 * fTemp1484 + fTemp141 * fTemp1483 * fTemp1481 + fTemp371 * fTemp1480 * fTemp1478 + fTemp179 * fTemp1477 * fTemp1475 + fTemp194 * fTemp1474 * fTemp1472 + fTemp257 * fTemp1471 * fTemp1469 + fTemp222 * fTemp1468 * fTemp1466 + fTemp246 * fTemp1465 * fTemp1463 + fTemp230 * fTemp1459 * fTemp1457 + fTemp273 * fTemp1456 * fTemp1454 + fTemp208 * fTemp1453 * fTemp1451 + fTemp289 * fTemp1450 * fTemp1448 + fTemp166 * fTemp1447 * fTemp1445 + fTemp305 * fTemp1436 * fTemp1434 + fTemp153 * fTemp1433 * fTemp1431 + fTemp314 * fTemp1430 * fTemp1428 + fTemp323 * fTemp1427 * fTemp1425 + fTemp329 * fTemp1424 * fTemp1422 + fTemp339 * fTemp1421 * fTemp1419 + fTemp347 * fTemp1418 * fTemp1416 + fTemp357 * fTemp1415 * fTemp1413 + fTemp365 * fTemp1412 * fTemp1410 + fTemp382 * fTemp1409 * fTemp1407 + fTemp408 * fTemp1406 * fTemp1404 + fTemp426 * fTemp1403 * fTemp1401 + fTemp450 * fTemp1400 * fTemp1398 + fTemp118 * fTemp1397 * fTemp1395 + fTemp461 * fTemp1394 * fTemp1392 + fTemp465 * fTemp1391 * fTemp1389 + fTemp473 * fTemp1387 * fTemp1385 + fTemp477 * fTemp1384 * fTemp1382 + fTemp482 * fTemp1381 * fTemp1379 + fTemp487 * fTemp1378 * fTemp1376 + fTemp469 * fTemp1375 * fTemp1373 + fTemp491 * fTemp1372 * fTemp1370 + fTemp512 * fTemp1369 * fTemp1367 + fTemp516 * fTemp1366 * fTemp1364 + fTemp106 * fTemp1363 * fTemp1361 + fTemp94 * fTemp1360 * fTemp1358 + fTemp45 * fTemp1357 * fTemp1355 + fTemp82 * fTemp1354 * fTemp1352 - fTemp293 * fTemp1351 * fTemp1349) + fRec847[0] * (fTemp45 * fTemp1348 * fTemp1346 + fTemp106 * fTemp1345 * fTemp1343 + fTemp512 * fTemp1342 * fTemp1340 + fTemp508 * fTemp1339 * fTemp1337 + fTemp516 * fTemp1336 * fTemp1334 + fTemp504 * fTemp1333 * fTemp1331 + fTemp500 * fTemp1329 * fTemp1327 + fTemp491 * fTemp1326 * fTemp1324 + fTemp469 * fTemp1323 * fTemp1321 + fTemp454 * fTemp1320 * fTemp1318 + fTemp487 * fTemp1317 * fTemp1315 + fTemp482 * fTemp1314 * fTemp1312 + fTemp477 * fTemp1311 * fTemp1309 + fTemp473 * fTemp1308 * fTemp1306 + fTemp461 * fTemp1305 * fTemp1303 + fTemp118 * fTemp1302 * fTemp1300 + fTemp49 * fTemp1299 * fTemp1297 + fTemp450 * fTemp1296 * fTemp1294 + fTemp59 * fTemp1293 * fTemp1291 + fTemp442 * fTemp1290 * fTemp1288 + fTemp438 * fTemp1287 * fTemp1285 + fTemp434 * fTemp1284 * fTemp1282 + fTemp430 * fTemp1281 * fTemp1279 + fTemp426 * fTemp1278 * fTemp1276 + fTemp132 * fTemp1275 * fTemp1273 + fTemp417 * fTemp1272 * fTemp1270 + fTemp412 * fTemp1269 * fTemp1267 + fTemp408 * fTemp1266 * fTemp1264 + fTemp404 * fTemp1263 * fTemp1261 + fTemp153 * fTemp1260 * fTemp1258 + fTemp293 * fTemp1257 * fTemp1255 + fTemp289 * fTemp1254 * fTemp1252 + fTemp179 * fTemp1246 * fTemp1244 + fTemp194 * fTemp1238 * fTemp1236 + fTemp222 * fTemp1235 * fTemp1233 + fTemp246 * fTemp1229 * fTemp1227 + fTemp273 * fTemp1226 * fTemp1224 + fTemp257 * fTemp1220 * fTemp1218 + fTemp208 * fTemp1217 * fTemp1215 + fTemp166 * fTemp1214 * fTemp1212 + fTemp305 * fTemp1210 * fTemp1208 + fTemp314 * fTemp1207 * fTemp1205 + fTemp323 * fTemp1204 * fTemp1202 + fTemp339 * fTemp1201 * fTemp1199 + fTemp347 * fTemp1198 * fTemp1196 + fTemp357 * fTemp1195 * fTemp1193 + fTemp365 * fTemp1192 * fTemp1190 + fTemp371 * fTemp1189 * fTemp1187 + fTemp141 * fTemp1186 * fTemp1184 + fTemp70 * fTemp1183 * fTemp1181 + fTemp376 * fTemp1180 * fTemp1178 + fTemp382 * fTemp1177 * fTemp1175 + fTemp390 * fTemp1174 * fTemp1172 + fTemp395 * fTemp1171 * fTemp1169 + fTemp122 * fTemp1168 * fTemp1166 + fTemp465 * fTemp1165 * fTemp1163 + fTemp495 * fTemp1162 * fTemp1160 + fTemp82 * fTemp1159 * fTemp1157 - (fTemp230 * fTemp1156 * fTemp1154 + fTemp329 * fTemp1153 * fTemp1151 + fTemp94 * fTemp1150 * fTemp1148)) + fRec720[0] * (fTemp508 * fTemp1147 * fTemp1145 + fTemp504 * fTemp1144 * fTemp1142 + fTemp454 * fTemp1141 * fTemp1139 + fTemp500 * fTemp1138 * fTemp1136 + fTemp496 * fTemp1135 * fTemp1133 + fTemp491 * fTemp1132 * fTemp1130 + fTemp469 * fTemp1129 * fTemp1127 + fTemp49 * fTemp1126 * fTemp1124 + fTemp487 * fTemp1123 * fTemp1121 + fTemp477 * fTemp1120 * fTemp1118 + fTemp473 * fTemp1117 * fTemp1115 + fTemp465 * fTemp1114 * fTemp1112 + fTemp461 * fTemp1111 * fTemp1109 + fTemp118 * fTemp1108 * fTemp1106 + fTemp450 * fTemp1105 * fTemp1103 + fTemp59 * fTemp1102 * fTemp1100 + fTemp442 * fTemp1099 * fTemp1097 + fTemp434 * fTemp1096 * fTemp1094 + fTemp430 * fTemp1093 * fTemp1091 + fTemp122 * fTemp1090 * fTemp1088 + fTemp438 * fTemp1086 * fTemp1084 + fTemp132 * fTemp1083 * fTemp1081 + fTemp417 * fTemp1080 * fTemp1078 + fTemp412 * fTemp1077 * fTemp1075 + fTemp408 * fTemp1074 * fTemp1072 + fTemp404 * fTemp1071 * fTemp1069 + fTemp426 * fTemp1068 * fTemp1066 + fTemp390 * fTemp1065 * fTemp1063 + fTemp382 * fTemp1062 * fTemp1060 + fTemp376 * fTemp1059 * fTemp1057 + fTemp365 * fTemp1056 * fTemp1054 + fTemp357 * fTemp1053 * fTemp1051 + fTemp347 * fTemp1050 * fTemp1048 + fTemp273 * fTemp1047 * fTemp1045 + fTemp230 * fTemp1044 * fTemp1042 + fTemp246 * fTemp1041 * fTemp1039 + fTemp222 * fTemp1038 * fTemp1036 + fTemp257 * fTemp1030 * fTemp1028 + fTemp208 * fTemp1027 * fTemp1025 + fTemp194 * fTemp1021 * fTemp1019 + fTemp179 * fTemp1013 * fTemp1011 + fTemp289 * fTemp1010 * fTemp1008 + fTemp166 * fTemp1002 * fTemp1000 + fTemp305 * fTemp998 * fTemp996 + fTemp153 * fTemp995 * fTemp993 + fTemp314 * fTemp992 * fTemp990 + fTemp323 * fTemp989 * fTemp987 + fTemp329 * fTemp986 * fTemp984 + fTemp339 * fTemp982 * fTemp980 + fTemp371 * fTemp978 * fTemp976 + fTemp141 * fTemp975 * fTemp973 + fTemp395 * fTemp972 * fTemp970 + fTemp482 * fTemp969 * fTemp967 + fTemp512 * fTemp966 * fTemp964 + fTemp516 * fTemp963 * fTemp961 + fTemp106 * fTemp960 * fTemp958 + fTemp94 * fTemp957 * fTemp955 + fTemp45 * fTemp954 * fTemp952 + fTemp82 * fTemp951 * fTemp949 - (fTemp293 * fTemp948 * fTemp946 + fTemp70 * fTemp945 * fTemp943)) + fRec593[0] * (fTemp454 * fTemp942 * fTemp940 + fTemp500 * fTemp939 * fTemp937 + fTemp491 * fTemp936 * fTemp934 + fTemp469 * fTemp933 * fTemp931 + fTemp49 * fTemp930 * fTemp928 + fTemp487 * fTemp52 * fTemp927 * fTemp925 + fTemp482 * fTemp924 * fTemp922 + fTemp473 * fTemp921 * fTemp919 + fTemp465 * fTemp918 * fTemp916 + fTemp461 * fTemp97 * fTemp915 * fTemp913 + fTemp118 * fTemp912 * fTemp910 + fTemp450 * fTemp909 * fTemp907 + fTemp59 * fTemp905 * fTemp903 + fTemp442 * fTemp902 * fTemp900 + fTemp438 * fTemp898 * fTemp896 + fTemp434 * fTemp895 * fTemp893 + fTemp122 * fTemp891 * fTemp889 + fTemp426 * fTemp888 * fTemp886 + fTemp132 * fTemp885 * fTemp883 + fTemp417 * fTemp882 * fTemp880 + fTemp412 * fTemp879 * fTemp877 + fTemp408 * fTemp875 * fTemp873 + fTemp404 * fTemp872 * fTemp870 + fTemp395 * fTemp869 * fTemp867 + fTemp390 * fTemp866 * fTemp864 + fTemp382 * fTemp862 * fTemp860 + fTemp376 * fTemp859 * fTemp857 + fTemp166 * fTemp851 * fTemp849 + fTemp289 * fTemp848 * fTemp846 + fTemp246 * fTemp840 * fTemp838 + fTemp230 * fTemp837 * fTemp835 + fTemp222 * fTemp834 * fTemp832 + fTemp273 * fTemp827 * fTemp825 + fTemp257 * fTemp824 * fTemp822 + fTemp208 * fTemp821 * fTemp819 + fTemp179 * fTemp818 * fTemp816 + fTemp293 * fTemp815 * fTemp813 + fTemp305 * fTemp812 * fTemp810 + fTemp153 * fTemp809 * fTemp807 + fTemp314 * fTemp806 * fTemp804 + fTemp323 * fTemp803 * fTemp801 + fTemp329 * fTemp800 * fTemp798 + fTemp339 * fTemp797 * fTemp795 + fTemp347 * fTemp794 * fTemp792 + fTemp357 * fTemp790 * fTemp788 + fTemp365 * fTemp787 * fTemp785 + fTemp371 * fTemp784 * fTemp782 + fTemp141 * fTemp781 * fTemp779 + fTemp70 * fTemp773 * fTemp771 + fTemp430 * fTemp770 * fTemp768 + fTemp477 * fTemp767 * fTemp765 + fTemp495 * fTemp764 * fTemp762 + fTemp504 * fTemp761 * fTemp759 + fTemp508 * fTemp758 * fTemp756 + fTemp512 * fTemp755 * fTemp753 + fTemp516 * fTemp752 * fTemp750 + fTemp106 * fTemp748 * fTemp746 + fTemp45 * fTemp745 * fTemp743 + fTemp82 * fTemp742 * fTemp740 - (fTemp194 * fTemp739 * fTemp737 + fTemp94 * fTemp736 * fTemp734)) + fRec466[0] * (fTemp41 * (fTemp118 * fTemp733 * fTemp731 + fTemp454 * fTemp730 * fTemp728) + fTemp500 * fTemp727 * fTemp725 + fTemp495 * fTemp724 * fTemp722 + fTemp491 * fTemp721 * fTemp719 + fTemp469 * fTemp718 * fTemp716 + fTemp49 * fTemp715 * fTemp713 + fTemp487 * fTemp460 * fTemp711 * fTemp709 + fTemp508 * fTemp385 * fTemp708 * fTemp706 + fTemp482 * fTemp705 * fTemp703 + fTemp477 * fTemp702 * fTemp700 + fTemp473 * fTemp52 * fTemp699 * fTemp697 + fTemp465 * fTemp696 * fTemp694 + fTemp461 * fTemp692 * fTemp690 + fTemp450 * fTemp689 * fTemp687 + fTemp59 * fTemp686 * fTemp684 + fTemp442 * fTemp683 * fTemp681 + fTemp438 * fTemp680 * fTemp678 + fTemp434 * fTemp676 * fTemp674 + fTemp430 * fTemp673 * fTemp671 + fTemp426 * fTemp670 * fTemp668 + fTemp132 * fTemp667 * fTemp665 + fTemp417 * fTemp664 * fTemp662 + fTemp412 * fTemp660 * fTemp658 + fTemp404 * fTemp657 * fTemp655 + fTemp395 * fTemp654 * fTemp652 + fTemp390 * fTemp651 * fTemp649 + fTemp382 * fTemp647 * fTemp645 + fTemp376 * fTemp644 * fTemp642 + fTemp70 * fTemp641 * fTemp639 + fTemp141 * fTemp637 * fTemp635 + fTemp371 * fTemp634 * fTemp632 + fTemp365 * fTemp631 * fTemp629 + fTemp357 * fTemp628 * fTemp626 + fTemp347 * fTemp625 * fTemp623 + fTemp339 * fTemp622 * fTemp620 + fTemp329 * fTemp619 * fTemp617 + fTemp323 * fTemp613 * fTemp611 + fTemp314 * fTemp610 * fTemp608 + fTemp153 * fTemp607 * fTemp605 + fTemp179 * fTemp604 * fTemp602 + fTemp222 * fTemp601 * fTemp599 + fTemp230 * fTemp593 * fTemp591 + fTemp246 * fTemp590 * fTemp588 + fTemp257 * fTemp587 * fTemp585 + fTemp208 * fTemp581 * fTemp579 + fTemp194 * fTemp577 * fTemp575 + fTemp289 * fTemp574 * fTemp572 + fTemp166 * fTemp571 * fTemp569 + fTemp293 * fTemp563 * fTemp561 + fTemp305 * fTemp557 * fTemp555 + fTemp408 * fTemp549 * fTemp547 + fTemp122 * fTemp546 * fTemp544 + fTemp504 * fTemp542 * fTemp540 + fTemp512 * fTemp539 * fTemp537 + fTemp516 * fTemp535 * fTemp533 + fTemp106 * fTemp532 * fTemp530 + fTemp45 * fTemp528 * fTemp526 + fTemp82 * fTemp525 * fTemp523 - (fTemp273 * fTemp522 * fTemp520 + fTemp94 * fTemp519 * fTemp517)) + fRec337[0] * (fTemp516 * fTemp515 * fTemp513 + fTemp512 * fTemp511 * fTemp509 + fTemp508 * fTemp507 * fTemp505 + fTemp504 * fTemp503 * fTemp501 + fTemp500 * fTemp499 * fTemp497 + fTemp496 * fTemp494 * fTemp492 + fTemp491 * fTemp490 * fTemp488 + fTemp487 * fTemp486 * fTemp484 + fTemp482 * fTemp481 * fTemp479 + fTemp477 * fTemp476 * fTemp474 + fTemp473 * fTemp472 * fTemp470 + fTemp469 * fTemp468 * fTemp466 + fTemp465 * fTemp464 * fTemp462 + fTemp461 * fTemp460 * fTemp457 * fTemp455 + fTemp454 * fTemp453 * fTemp451 + fTemp450 * fTemp449 * fTemp447 + fTemp442 * fTemp441 * fTemp439 + fTemp438 * fTemp437 * fTemp435 + fTemp434 * fTemp41 * fTemp433 * fTemp431 + fTemp430 * fTemp429 * fTemp427 + fTemp426 * fTemp425 * fTemp423 + fTemp417 * fTemp416 * fTemp414 + fTemp412 * fTemp411 * fTemp409 + fTemp408 * fTemp407 * fTemp405 + fTemp404 * fTemp403 * fTemp401 + fTemp395 * fTemp394 * fTemp392 + fTemp390 * fTemp389 * fTemp387 + fTemp382 * fTemp381 * fTemp379 + fTemp376 * fTemp375 * fTemp373 + fTemp371 * fTemp370 * fTemp368 + fTemp365 * fTemp364 * fTemp362 + fTemp357 * fTemp356 * fTemp354 + fTemp347 * fTemp346 * fTemp344 + fTemp339 * fTemp338 * fTemp336 + fTemp329 * fTemp328 * fTemp326 + fTemp323 * fTemp322 * fTemp320 + fTemp314 * fTemp313 * fTemp311 + fTemp305 * fTemp304 * fTemp302 + fTemp293 * fTemp292 * fTemp290 + fTemp289 * fTemp288 * fTemp286 + fTemp273 * fTemp272 * fTemp270 + fTemp257 * fTemp256 * fTemp254 + fTemp246 * fTemp245 * fTemp243 + fTemp230 * fTemp229 * fTemp227 + fTemp222 * fTemp221 * fTemp219 + fTemp208 * fTemp207 * fTemp205 + fTemp194 * fTemp193 * fTemp191 + fTemp179 * fTemp178 * fTemp176 + fTemp166 * fTemp165 * fTemp163 + fTemp153 * fTemp152 * fTemp150 + fTemp141 * fTemp140 * fTemp138 + fTemp132 * fTemp131 * fTemp129 + fTemp122 * fTemp121 * fTemp119 + fTemp118 * fTemp117 * fTemp115 + fTemp106 * fTemp105 * fTemp103 + fTemp94 * fTemp93 * fTemp91 + fTemp82 * fTemp81 * fTemp79 - (fTemp70 * fTemp69 * fTemp67 + fTemp59 * fTemp58 * fTemp56 + fTemp49 * fTemp48 * fTemp46 + fTemp45 * fTemp44 * fTemp42));
			fRec1350[0] = fSlow774 + fConst7 * fRec1350[1];
			fRec1351[0] = fSlow775 + fConst10 * fRec1351[1];
			double fTemp2127 = 1.5707963267948966 * fRec1351[0];
			double fTemp2128 = fRec134[0] * fTemp1235 * fTemp1233 + fRec146[0] * fTemp1229 * fTemp1227 + fRec159[0] * fTemp1226 * fTemp1224 + fRec152[0] * fTemp1220 * fTemp1218 + fRec127[0] * fTemp1217 * fTemp1215 + fRec121[0] * fTemp1238 * fTemp1236 + fRec114[0] * fTemp1246 * fTemp1244 + fRec166[0] * fTemp1254 * fTemp1252 + fRec108[0] * fTemp1214 * fTemp1212 + fRec170[0] * fTemp1257 * fTemp1255 + fRec176[0] * fTemp1210 * fTemp1208 + fRec102[0] * fTemp1260 * fTemp1258 + fRec181[0] * fTemp1207 * fTemp1205 + fRec186[0] * fTemp1204 * fTemp1202 + fRec195[0] * fTemp1201 * fTemp1199 + fRec200[0] * fTemp1198 * fTemp1196 + fRec206[0] * fTemp1195 * fTemp1193 + fRec211[0] * fTemp1192 * fTemp1190 + fRec215[0] * fTemp1189 * fTemp1187 + fRec96[0] * fTemp1186 * fTemp1184 + fRec58[0] * fTemp1183 * fTemp1181 + fRec219[0] * fTemp1180 * fTemp1178 + fRec223[0] * fTemp1177 * fTemp1175 + fRec228[0] * fTemp1174 * fTemp1172 + fRec232[0] * fTemp1171 * fTemp1169 + fRec237[0] * fTemp1263 * fTemp1261 + fRec241[0] * fTemp1266 * fTemp1264 + fRec245[0] * fTemp1269 * fTemp1267 + fRec249[0] * fTemp1272 * fTemp1270 + fRec91[0] * fTemp1275 * fTemp1273 + fRec254[0] * fTemp1278 * fTemp1276 + fRec86[0] * fTemp1168 * fTemp1166 + fRec258[0] * fTemp1281 * fTemp1279 + fRec262[0] * fTemp1284 * fTemp1282 + fRec266[0] * fTemp1287 * fTemp1285 + fRec270[0] * fTemp1290 * fTemp1288 + fRec52[0] * fTemp1293 * fTemp1291 + fRec275[0] * fTemp1296 * fTemp1294 + fRec82[0] * fTemp1302 * fTemp1300 + fRec284[0] * fTemp1305 * fTemp1303 + fRec288[0] * fTemp1165 * fTemp1163 + fRec296[0] * fTemp1308 * fTemp1306 + fRec300[0] * fTemp1311 * fTemp1309 + fRec304[0] * fTemp1314 * fTemp1312 + fRec308[0] * fTemp1317 * fTemp1315 + fRec46[0] * fTemp1299 * fTemp1297 + fRec292[0] * fTemp1323 * fTemp1321 + fRec312[0] * fTemp1326 * fTemp1324 + fRec316[0] * fTemp1162 * fTemp1160 + fRec320[0] * fTemp1329 * fTemp1327 + fRec279[0] * fTemp1320 * fTemp1318 + fRec324[0] * fTemp1333 * fTemp1331 + fRec328[0] * fTemp1339 * fTemp1337 + fRec332[0] * fTemp1342 * fTemp1340 + fRec336[0] * fTemp1336 * fTemp1334 + fRec76[0] * fTemp1345 * fTemp1343 + fRec42[0] * fTemp1348 * fTemp1346 + fRec64[0] * fTemp1159 * fTemp1157 - (fRec139[0] * fTemp1156 * fTemp1154 + fRec190[0] * fTemp1153 * fTemp1151 + fRec70[0] * fTemp1150 * fTemp1148);
			double fTemp2129 = fRec139[0] * fTemp1459 * fTemp1457 + fRec134[0] * fTemp1468 * fTemp1466 + fRec146[0] * fTemp1465 * fTemp1463 + fRec159[0] * fTemp1456 * fTemp1454 + fRec152[0] * fTemp1471 * fTemp1469 + fRec127[0] * fTemp1453 * fTemp1451 + fRec121[0] * fTemp1474 * fTemp1472 + fRec114[0] * fTemp1477 * fTemp1475 + fRec166[0] * fTemp1450 * fTemp1448 + fRec108[0] * fTemp1447 * fTemp1445 + fRec176[0] * fTemp1436 * fTemp1434 + fRec102[0] * fTemp1433 * fTemp1431 + fRec181[0] * fTemp1430 * fTemp1428 + fRec186[0] * fTemp1427 * fTemp1425 + fRec190[0] * fTemp1424 * fTemp1422 + fRec195[0] * fTemp1421 * fTemp1419 + fRec200[0] * fTemp1418 * fTemp1416 + fRec206[0] * fTemp1415 * fTemp1413 + fRec211[0] * fTemp1412 * fTemp1410 + fRec215[0] * fTemp1480 * fTemp1478 + fRec96[0] * fTemp1483 * fTemp1481 + fRec58[0] * fTemp1486 * fTemp1484 + fRec219[0] * fTemp1489 * fTemp1487 + fRec223[0] * fTemp1409 * fTemp1407 + fRec228[0] * fTemp1492 * fTemp1490 + fRec232[0] * fTemp1495 * fTemp1493 + fRec237[0] * fTemp1498 * fTemp1496 + fRec241[0] * fTemp1406 * fTemp1404 + fRec245[0] * fTemp1501 * fTemp1499 + fRec249[0] * fTemp1504 * fTemp1502 + fRec91[0] * fTemp1507 * fTemp1505 + fRec254[0] * fTemp1403 * fTemp1401 + fRec86[0] * fTemp1510 * fTemp1508 + fRec258[0] * fTemp1513 * fTemp1511 + fRec262[0] * fTemp1516 * fTemp1514 + fRec266[0] * fTemp1519 * fTemp1517 + fRec270[0] * fTemp1522 * fTemp1520 + fRec52[0] * fTemp1525 * fTemp1523 + fRec275[0] * fTemp1400 * fTemp1398 + fRec82[0] * fTemp1397 * fTemp1395 + fRec284[0] * fTemp1394 * fTemp1392 + fRec288[0] * fTemp1391 * fTemp1389 + fRec296[0] * fTemp1387 * fTemp1385 + fRec300[0] * fTemp1384 * fTemp1382 + fRec304[0] * fTemp1381 * fTemp1379 + fRec308[0] * fTemp1378 * fTemp1376 + fRec46[0] * fTemp1528 * fTemp1526 + fRec292[0] * fTemp1375 * fTemp1373 + fRec312[0] * fTemp1372 * fTemp1370 + fRec316[0] * fTemp1531 * fTemp1529 + fRec320[0] * fTemp1534 * fTemp1532 + fRec279[0] * fTemp1537 * fTemp1535 + fRec324[0] * fTemp1540 * fTemp1538 + fRec328[0] * fTemp1543 * fTemp1541 + fRec332[0] * fTemp1369 * fTemp1367 + fRec336[0] * fTemp1366 * fTemp1364 + fRec76[0] * fTemp1363 * fTemp1361 + fRec70[0] * fTemp1360 * fTemp1358 + fRec42[0] * fTemp1357 * fTemp1355 + fRec64[0] * fTemp1354 * fTemp1352 - fRec170[0] * fTemp1351 * fTemp1349;
			fRec1352[0] = fSlow776 + fConst10 * fRec1352[1];
			int iTemp2130 = (fSlow262 * fRec330[IOTA0 & 1023] + fSlow258 * fRec326[IOTA0 & 1023] + fSlow210 * fRec277[IOTA0 & 1023] + fSlow250 * fRec318[IOTA0 & 1023] + fSlow246 * fRec314[IOTA0 & 1023] + fSlow242 * fRec310[IOTA0 & 1023] + fSlow222 * fRec290[IOTA0 & 1023] + fSlow238 * fRec306[IOTA0 & 1023] + fSlow234 * fRec302[IOTA0 & 1023] + fSlow230 * fRec298[IOTA0 & 1023] + fSlow226 * fRec294[IOTA0 & 1023] + fSlow218 * fRec286[IOTA0 & 1023] + fSlow214 * fRec281[IOTA0 & 1023] + fSlow54 * fRec80[IOTA0 & 1023] + fSlow34 * fRec50[IOTA0 & 1023] + fSlow202 * fRec268[IOTA0 & 1023] + fSlow206 * fRec273[IOTA0 & 1023] + fSlow30 * fRec44[IOTA0 & 1023] + fSlow194 * fRec260[IOTA0 & 1023] + fSlow190 * fRec256[IOTA0 & 1023] + fSlow186 * fRec252[IOTA0 & 1023] + fSlow182 * fRec247[IOTA0 & 1023] + fSlow198 * fRec264[IOTA0 & 1023] + fSlow178 * fRec243[IOTA0 & 1023] + fSlow58 * fRec84[IOTA0 & 1023] + fSlow170 * fRec235[IOTA0 & 1023] + fSlow166 * fRec230[IOTA0 & 1023] + fSlow162 * fRec226[IOTA0 & 1023] + fSlow174 * fRec239[IOTA0 & 1023] + fSlow158 * fRec221[IOTA0 & 1023] + fSlow154 * fRec217[IOTA0 & 1023] + fSlow66 * fRec94[IOTA0 & 1023] + fSlow150 * fRec213[IOTA0 & 1023] + fSlow146 * fRec209[IOTA0 & 1023] + fSlow142 * fRec204[IOTA0 & 1023] + fSlow138 * fRec198[IOTA0 & 1023] + fSlow134 * fRec193[IOTA0 & 1023] + fSlow126 * fRec184[IOTA0 & 1023] + fSlow122 * fRec179[IOTA0 & 1023] + fSlow70 * fRec100[IOTA0 & 1023] + fSlow130 * fRec188[IOTA0 & 1023] + fSlow118 * fRec174[IOTA0 & 1023] + fSlow106 * fRec157[IOTA0 & 1023] + fSlow98 * fRec144[IOTA0 & 1023] + fSlow90 * fRec132[IOTA0 & 1023] + fSlow94 * fRec137[IOTA0 & 1023] + fSlow102 * fRec150[IOTA0 & 1023] + fSlow86 * fRec125[IOTA0 & 1023] + fSlow82 * fRec119[IOTA0 & 1023] + fSlow78 * fRec112[IOTA0 & 1023] + fSlow110 * fRec164[IOTA0 & 1023] + fSlow74 * fRec106[IOTA0 & 1023] + fSlow114 * fRec168[IOTA0 & 1023] + fSlow38 * fRec56[IOTA0 & 1023] + fSlow62 * fRec89[IOTA0 & 1023] + fSlow254 * fRec322[IOTA0 & 1023] + fSlow266 * fRec334[IOTA0 & 1023] + fSlow50 * fRec74[IOTA0 & 1023] + fSlow46 * fRec68[IOTA0 & 1023] + fSlow26 * fRec40[IOTA0 & 1023] + fSlow42 * fRec62[IOTA0 & 1023]) > 0.5;
			iVec556[0] = iTemp2130;
			fRec1353[0] = std::max<double>(fRec1353[1] * fSlow777, double(iTemp2130 > iVec556[1]));
			fRec1354[0] = fSlow778 + fConst10 * fRec1354[1];
			double fTemp2131 = fRec316[0] * fTemp52;
			fRec1355[0] = fSlow780 + fConst10 * fRec1355[1];
			fRec1356[0] = fSlow782 + fConst10 * fRec1356[1];
			fRec1357[0] = fSlow784 + fConst10 * fRec1357[1];
			fRec1358[0] = fSlow786 + fConst10 * fRec1358[1];
			fRec1359[0] = fSlow788 + fConst10 * fRec1359[1];
			fRec1360[0] = fSlow790 + fConst10 * fRec1360[1];
			fRec1361[0] = fSlow792 + fConst10 * fRec1361[1];
			fRec1362[0] = fSlow794 + fConst10 * fRec1362[1];
			fRec1363[0] = fSlow796 + fConst10 * fRec1363[1];
			double fTemp2132 = fRec1363[0] * (fRec139[0] * fTemp2041 * fTemp2039 + fRec134[0] * fTemp2038 * fTemp2036 + fRec146[0] * fTemp2035 * fTemp2033 + fRec159[0] * fTemp2032 * fTemp2030 + fRec152[0] * fTemp2029 * fTemp2027 + fRec127[0] * fTemp2026 * fTemp2024 + fRec121[0] * fTemp2023 * fTemp2021 + fRec114[0] * fTemp2020 * fTemp2018 + fRec166[0] * fTemp2017 * fTemp2015 + fRec108[0] * fTemp2014 * fTemp2012 + fRec170[0] * fTemp2011 * fTemp2009 + fRec176[0] * fTemp2005 * fTemp2003 + fRec102[0] * fTemp2002 * fTemp2000 + fRec181[0] * fTemp1999 * fTemp1997 + fRec186[0] * fTemp1996 * fTemp1994 + fRec190[0] * fTemp1993 * fTemp1991 + fRec195[0] * fTemp1990 * fTemp1988 + fRec200[0] * fTemp1987 * fTemp1985 + fRec206[0] * fTemp2044 * fTemp2042 + fRec211[0] * fTemp2047 * fTemp2045 + fRec215[0] * fTemp2050 * fTemp2048 + fRec96[0] * fTemp1984 * fTemp1982 + fRec58[0] * fTemp2056 * fTemp2054 + fRec219[0] * fTemp2059 * fTemp2057 + fRec223[0] * fTemp2062 * fTemp2060 + fRec228[0] * fTemp1981 * fTemp1979 + fRec232[0] * fTemp2068 * fTemp2066 + fRec237[0] * fTemp2065 * fTemp2063 + fRec241[0] * fTemp2074 * fTemp2072 + fRec245[0] * fTemp2077 * fTemp2075 + fRec249[0] * fTemp2080 * fTemp2078 + fRec91[0] * fTemp2086 * fTemp2084 + fRec254[0] * fTemp2083 * fTemp2081 + fRec86[0] * fTemp2089 * fTemp2087 + fRec262[0] * fTemp2092 * fTemp2090 + fRec266[0] * fTemp2095 * fTemp2093 + fRec270[0] * fTemp2098 * fTemp2096 + fRec52[0] * fTemp2101 * fTemp2099 + fRec275[0] * fTemp2053 * fTemp2051 + fRec82[0] * fTemp2104 * fTemp2102 + fRec284[0] * fTemp2107 * fTemp2105 + fRec288[0] * fTemp2110 * fTemp2108 + fRec296[0] * fTemp2071 * fTemp2069 + fRec300[0] * fTemp2113 * fTemp2111 + fRec304[0] * fTemp2116 * fTemp2114 + fRec308[0] * fTemp2119 * fTemp2117 + fRec46[0] * fTemp2122 * fTemp2120 + fRec292[0] * fTemp1978 * fTemp1976 + fRec312[0] * fTemp1975 * fTemp1973 + fRec316[0] * fTemp1972 * fTemp1970 + fRec320[0] * fTemp1969 * fTemp1967 + fRec279[0] * fTemp2125 * fTemp2123 + fRec324[0] * fTemp1966 * fTemp1964 + fRec328[0] * fTemp1963 * fTemp1961 + fRec332[0] * fTemp1960 * fTemp1958 + fRec336[0] * fTemp1957 * fTemp1955 + fRec76[0] * fTemp1954 * fTemp1952 + fRec64[0] * fTemp1951 * fTemp1949 - (fRec258[0] * fTemp1948 * fTemp1946 + fRec70[0] * fTemp1945 * fTemp1943 + fRec42[0] * fTemp1942 * fTemp1940)) + fRec1362[0] * (fRec139[0] * fTemp1831 * fTemp1829 + fRec134[0] * fTemp1828 * fTemp1826 + fRec146[0] * fTemp1834 * fTemp1832 + fRec159[0] * fTemp1837 * fTemp1835 + fRec152[0] * fTemp1825 * fTemp1823 + fRec127[0] * fTemp1822 * fTemp1820 + fRec121[0] * fTemp1819 * fTemp1817 + fRec114[0] * fTemp1816 * fTemp1814 + fRec166[0] * fTemp1813 * fTemp1811 + fRec108[0] * fTemp1810 * fTemp1808 + fRec170[0] * fTemp1807 * fTemp1805 + fRec176[0] * fTemp1804 * fTemp1802 + fRec102[0] * fTemp1840 * fTemp1838 + fRec181[0] * fTemp1843 * fTemp1841 + fRec186[0] * fTemp1846 * fTemp1844 + fRec190[0] * fTemp1849 * fTemp1847 + fRec195[0] * fTemp1852 * fTemp1850 + fRec206[0] * fTemp1855 * fTemp1853 + fRec211[0] * fTemp1858 * fTemp1856 + fRec215[0] * fTemp1861 * fTemp1859 + fRec96[0] * fTemp1864 * fTemp1862 + fRec58[0] * fTemp1801 * fTemp1799 + fRec219[0] * fTemp1798 * fTemp1796 + fRec223[0] * fTemp1870 * fTemp1868 + fRec228[0] * fTemp1873 * fTemp1871 + fRec232[0] * fTemp1867 * fTemp1865 + fRec241[0] * fTemp1795 * fTemp1793 + fRec245[0] * fTemp1876 * fTemp1874 + fRec249[0] * fTemp1879 * fTemp1877 + fRec91[0] * fTemp1882 * fTemp1880 + fRec254[0] * fTemp1885 * fTemp1883 + fRec86[0] * fTemp1888 * fTemp1886 + fRec258[0] * fTemp1792 * fTemp1790 + fRec262[0] * fTemp1891 * fTemp1889 + fRec266[0] * fTemp1894 * fTemp1892 + fRec270[0] * fTemp1897 * fTemp1895 + fRec52[0] * fTemp1900 * fTemp1898 + fRec275[0] * fTemp1903 * fTemp1901 + fRec82[0] * fTemp1906 * fTemp1904 + fRec284[0] * fTemp1909 * fTemp1907 + fRec288[0] * fTemp1912 * fTemp1910 + fRec296[0] * fTemp1915 * fTemp1913 + fRec300[0] * fTemp1918 * fTemp1916 + fRec304[0] * fTemp1921 * fTemp1919 + fRec308[0] * fTemp1924 * fTemp1922 + fRec46[0] * fTemp1789 * fTemp1787 + fRec292[0] * fTemp1927 * fTemp1925 + fRec312[0] * fTemp1930 * fTemp1928 + fRec316[0] * fTemp1933 * fTemp1931 + fRec320[0] * fTemp1936 * fTemp1934 + fRec279[0] * fTemp1786 * fTemp1784 + fRec324[0] * fTemp1939 * fTemp1937 + fRec328[0] * fTemp1783 * fTemp1781 + fRec332[0] * fTemp1780 * fTemp1778 + fRec336[0] * fTemp1777 * fTemp1775 + fRec76[0] * fTemp1774 * fTemp1772 + fRec70[0] * fTemp1771 * fTemp1769 + fRec42[0] * fTemp1768 * fTemp1766 + fRec64[0] * fTemp1765 * fTemp1763 - (fRec200[0] * fTemp1762 * fTemp1760 + fRec237[0] * fTemp1759 * fTemp1757)) + fRec1361[0] * (fRec139[0] * fTemp1661 * fTemp1659 + fRec134[0] * fTemp1667 * fTemp1665 + fRec146[0] * fTemp1657 * fTemp1655 + fRec159[0] * fTemp1654 * fTemp1652 + fRec152[0] * fTemp1651 * fTemp1649 + fRec127[0] * fTemp1639 * fTemp1637 + fRec121[0] * fTemp1636 * fTemp1634 + fRec114[0] * fTemp1628 * fTemp1626 + fRec166[0] * fTemp1625 * fTemp1623 + fRec108[0] * fTemp1670 * fTemp1668 + fRec170[0] * fTemp1673 * fTemp1671 + fRec176[0] * fTemp1622 * fTemp1620 + fRec102[0] * fTemp1676 * fTemp1674 + fRec181[0] * fTemp1679 * fTemp1677 + fRec186[0] * fTemp1685 * fTemp1683 + fRec190[0] * fTemp1693 * fTemp1691 + fRec195[0] * fTemp1697 * fTemp1695 + fRec200[0] * fTemp1705 * fTemp1703 + fRec206[0] * fTemp1708 * fTemp1706 + fRec211[0] * fTemp1682 * fTemp1680 + fRec215[0] * fTemp1711 * fTemp1709 + fRec96[0] * fTemp1619 * fTemp1617 + fRec219[0] * fTemp1616 * fTemp1614 + fRec228[0] * fTemp1613 * fTemp1611 + fRec232[0] * fTemp1610 * fTemp1608 + fRec237[0] * fTemp1714 * fTemp1712 + fRec241[0] * fTemp1717 * fTemp1715 + fRec245[0] * fTemp1720 * fTemp1718 + fRec249[0] * fTemp1723 * fTemp1721 + fRec91[0] * fTemp1607 * fTemp1605 + fRec254[0] * fTemp1726 * fTemp1724 + fRec86[0] * fTemp1729 * fTemp1727 + fRec262[0] * fTemp1732 * fTemp1730 + fRec266[0] * fTemp1735 * fTemp1733 + fRec270[0] * fTemp1604 * fTemp1602 + fRec52[0] * fTemp1738 * fTemp1736 + fRec275[0] * fTemp1741 * fTemp1739 + fRec82[0] * fTemp1744 * fTemp1742 + fRec284[0] * fTemp1747 * fTemp1745 + fRec288[0] * fTemp1750 * fTemp1748 + fRec296[0] * fTemp1753 * fTemp1751 + fRec300[0] * fTemp1601 * fTemp1599 + fRec304[0] * fTemp1598 * fTemp1596 + fRec308[0] * fTemp1595 * fTemp1593 + fRec46[0] * fTemp1592 * fTemp1590 + fRec312[0] * fTemp1589 * fTemp1587 + fRec316[0] * fTemp1586 * fTemp1584 + fRec320[0] * fTemp1583 * fTemp1581 + fRec279[0] * fTemp1756 * fTemp1754 + fRec324[0] * fTemp1580 * fTemp1578 + fRec328[0] * fTemp1577 * fTemp1575 + fRec332[0] * fTemp1574 * fTemp1572 + fRec336[0] * fTemp1571 * fTemp1569 + fRec76[0] * fTemp1567 * fTemp1565 + fRec42[0] * fTemp1564 * fTemp1562 + fRec64[0] * fTemp1561 * fTemp1559 - (fRec58[0] * fTemp1558 * fTemp1556 + fRec223[0] * fTemp1555 * fTemp1553 + fRec258[0] * fTemp1552 * fTemp1550 + fRec292[0] * fTemp1549 * fTemp1547 + fRec70[0] * fTemp1546 * fTemp1544)) + fRec1360[0] * fTemp2129 + fRec1359[0] * fTemp2128 + fRec1358[0] * (fRec139[0] * fTemp1044 * fTemp1042 + fRec134[0] * fTemp1038 * fTemp1036 + fRec146[0] * fTemp1041 * fTemp1039 + fRec159[0] * fTemp1047 * fTemp1045 + fRec152[0] * fTemp1030 * fTemp1028 + fRec127[0] * fTemp1027 * fTemp1025 + fRec121[0] * fTemp1021 * fTemp1019 + fRec114[0] * fTemp1013 * fTemp1011 + fRec166[0] * fTemp1010 * fTemp1008 + fRec108[0] * fTemp1002 * fTemp1000 + fRec176[0] * fTemp998 * fTemp996 + fRec102[0] * fTemp995 * fTemp993 + fRec181[0] * fTemp992 * fTemp990 + fRec186[0] * fTemp989 * fTemp987 + fRec190[0] * fTemp986 * fTemp984 + fRec195[0] * fTemp982 * fTemp980 + fRec200[0] * fTemp1050 * fTemp1048 + fRec206[0] * fTemp1053 * fTemp1051 + fRec211[0] * fTemp1056 * fTemp1054 + fRec215[0] * fTemp978 * fTemp976 + fRec96[0] * fTemp975 * fTemp973 + fRec219[0] * fTemp1059 * fTemp1057 + fRec223[0] * fTemp1062 * fTemp1060 + fRec228[0] * fTemp1065 * fTemp1063 + fRec232[0] * fTemp972 * fTemp970 + fRec237[0] * fTemp1071 * fTemp1069 + fRec241[0] * fTemp1074 * fTemp1072 + fRec245[0] * fTemp1077 * fTemp1075 + fRec249[0] * fTemp1080 * fTemp1078 + fRec91[0] * fTemp1083 * fTemp1081 + fRec254[0] * fTemp1068 * fTemp1066 + fRec86[0] * fTemp1090 * fTemp1088 + fRec258[0] * fTemp1093 * fTemp1091 + fRec262[0] * fTemp1096 * fTemp1094 + fRec266[0] * fTemp1086 * fTemp1084 + fRec270[0] * fTemp1099 * fTemp1097 + fRec52[0] * fTemp1102 * fTemp1100 + fRec275[0] * fTemp1105 * fTemp1103 + fRec82[0] * fTemp1108 * fTemp1106 + fRec284[0] * fTemp1111 * fTemp1109 + fRec288[0] * fTemp1114 * fTemp1112 + fRec296[0] * fTemp1117 * fTemp1115 + fRec300[0] * fTemp1120 * fTemp1118 + fRec304[0] * fTemp969 * fTemp967 + fRec308[0] * fTemp1123 * fTemp1121 + fRec46[0] * fTemp1126 * fTemp1124 + fRec292[0] * fTemp1129 * fTemp1127 + fRec312[0] * fTemp1132 * fTemp1130 + fTemp2131 * fTemp1135 * fTemp1133 + fRec320[0] * fTemp1138 * fTemp1136 + fRec279[0] * fTemp1141 * fTemp1139 + fRec324[0] * fTemp1144 * fTemp1142 + fRec328[0] * fTemp1147 * fTemp1145 + fRec332[0] * fTemp966 * fTemp964 + fRec336[0] * fTemp963 * fTemp961 + fRec76[0] * fTemp960 * fTemp958 + fRec70[0] * fTemp957 * fTemp955 + fRec42[0] * fTemp954 * fTemp952 + fRec64[0] * fTemp951 * fTemp949 - (fRec170[0] * fTemp948 * fTemp946 + fRec58[0] * fTemp945 * fTemp943)) + fRec1357[0] * (fRec139[0] * fTemp837 * fTemp835 + fRec134[0] * fTemp834 * fTemp832 + fRec146[0] * fTemp840 * fTemp838 + fRec159[0] * fTemp827 * fTemp825 + fRec152[0] * fTemp824 * fTemp822 + fRec127[0] * fTemp821 * fTemp819 + fRec114[0] * fTemp818 * fTemp816 + fRec166[0] * fTemp848 * fTemp846 + fRec108[0] * fTemp851 * fTemp849 + fRec170[0] * fTemp815 * fTemp813 + fRec176[0] * fTemp812 * fTemp810 + fRec102[0] * fTemp809 * fTemp807 + fRec181[0] * fTemp806 * fTemp804 + fRec186[0] * fTemp803 * fTemp801 + fRec190[0] * fTemp800 * fTemp798 + fRec195[0] * fTemp797 * fTemp795 + fRec200[0] * fTemp794 * fTemp792 + fRec206[0] * fTemp790 * fTemp788 + fRec211[0] * fTemp787 * fTemp785 + fRec215[0] * fTemp784 * fTemp782 + fRec96[0] * fTemp781 * fTemp779 + fRec58[0] * fTemp773 * fTemp771 + fRec219[0] * fTemp859 * fTemp857 + fRec223[0] * fTemp862 * fTemp860 + fRec228[0] * fTemp866 * fTemp864 + fRec232[0] * fTemp869 * fTemp867 + fRec237[0] * fTemp872 * fTemp870 + fRec241[0] * fTemp875 * fTemp873 + fRec245[0] * fTemp879 * fTemp877 + fRec249[0] * fTemp882 * fTemp880 + fRec91[0] * fTemp885 * fTemp883 + fRec254[0] * fTemp888 * fTemp886 + fRec86[0] * fTemp891 * fTemp889 + fRec258[0] * fTemp770 * fTemp768 + fRec262[0] * fTemp895 * fTemp893 + fRec266[0] * fTemp898 * fTemp896 + fRec270[0] * fTemp902 * fTemp900 + fRec52[0] * fTemp905 * fTemp903 + fRec275[0] * fTemp909 * fTemp907 + fRec82[0] * fTemp912 * fTemp910 + fRec284[0] * fTemp97 * fTemp915 * fTemp913 + fRec288[0] * fTemp918 * fTemp916 + fRec296[0] * fTemp921 * fTemp919 + fRec300[0] * fTemp767 * fTemp765 + fRec304[0] * fTemp924 * fTemp922 + fRec308[0] * fTemp52 * fTemp927 * fTemp925 + fRec46[0] * fTemp930 * fTemp928 + fRec292[0] * fTemp933 * fTemp931 + fRec312[0] * fTemp936 * fTemp934 + fRec316[0] * fTemp764 * fTemp762 + fRec320[0] * fTemp939 * fTemp937 + fRec279[0] * fTemp942 * fTemp940 + fRec324[0] * fTemp761 * fTemp759 + fRec328[0] * fTemp758 * fTemp756 + fRec332[0] * fTemp755 * fTemp753 + fRec336[0] * fTemp752 * fTemp750 + fRec76[0] * fTemp748 * fTemp746 + fRec42[0] * fTemp745 * fTemp743 + fRec64[0] * fTemp742 * fTemp740 - (fRec121[0] * fTemp739 * fTemp737 + fRec70[0] * fTemp736 * fTemp734)) + fRec1356[0] * (fTemp41 * (fRec82[0] * fTemp733 * fTemp731 + fRec279[0] * fTemp730 * fTemp728) + fRec320[0] * fTemp727 * fTemp725 + fRec316[0] * fTemp724 * fTemp722 + fRec312[0] * fTemp721 * fTemp719 + fRec292[0] * fTemp718 * fTemp716 + fRec46[0] * fTemp715 * fTemp713 + fRec308[0] * fTemp460 * fTemp711 * fTemp709 + fRec304[0] * fTemp705 * fTemp703 + fRec300[0] * fTemp702 * fTemp700 + fRec296[0] * fTemp52 * fTemp699 * fTemp697 + fRec288[0] * fTemp696 * fTemp694 + fRec139[0] * fTemp593 * fTemp591 + fRec134[0] * fTemp601 * fTemp599 + fRec146[0] * fTemp590 * fTemp588 + fRec152[0] * fTemp587 * fTemp585 + fRec127[0] * fTemp581 * fTemp579 + fRec121[0] * fTemp577 * fTemp575 + fRec114[0] * fTemp604 * fTemp602 + fRec166[0] * fTemp574 * fTemp572 + fRec108[0] * fTemp571 * fTemp569 + fRec170[0] * fTemp563 * fTemp561 + fRec176[0] * fTemp557 * fTemp555 + fRec102[0] * fTemp607 * fTemp605 + fRec181[0] * fTemp610 * fTemp608 + fRec186[0] * fTemp613 * fTemp611 + fRec190[0] * fTemp619 * fTemp617 + fRec195[0] * fTemp622 * fTemp620 + fRec200[0] * fTemp625 * fTemp623 + fRec206[0] * fTemp628 * fTemp626 + fRec211[0] * fTemp631 * fTemp629 + fRec215[0] * fTemp634 * fTemp632 + fRec96[0] * fTemp637 * fTemp635 + fRec58[0] * fTemp641 * fTemp639 + fRec219[0] * fTemp644 * fTemp642 + fRec223[0] * fTemp647 * fTemp645 + fRec228[0] * fTemp651 * fTemp649 + fRec232[0] * fTemp654 * fTemp652 + fRec237[0] * fTemp657 * fTemp655 + fRec241[0] * fTemp549 * fTemp547 + fRec245[0] * fTemp660 * fTemp658 + fRec249[0] * fTemp664 * fTemp662 + fRec91[0] * fTemp667 * fTemp665 + fRec254[0] * fTemp670 * fTemp668 + fRec86[0] * fTemp546 * fTemp544 + fRec258[0] * fTemp673 * fTemp671 + fRec262[0] * fTemp676 * fTemp674 + fRec266[0] * fTemp680 * fTemp678 + fRec270[0] * fTemp683 * fTemp681 + fRec52[0] * fTemp686 * fTemp684 + fRec275[0] * fTemp689 * fTemp687 + fRec284[0] * fTemp692 * fTemp690 + fRec324[0] * fTemp542 * fTemp540 + fRec328[0] * fTemp385 * fTemp708 * fTemp706 + fRec332[0] * fTemp539 * fTemp537 + fRec336[0] * fTemp535 * fTemp533 + fRec76[0] * fTemp532 * fTemp530 + fRec42[0] * fTemp528 * fTemp526 + fRec64[0] * fTemp525 * fTemp523 - (fRec159[0] * fTemp522 * fTemp520 + fRec70[0] * fTemp519 * fTemp517)) + fRec1355[0] * (1.0 - fRec1354[0]) * (fRec139[0] * fTemp229 * fTemp227 + fRec134[0] * fTemp221 * fTemp219 + fRec146[0] * fTemp245 * fTemp243 + fRec159[0] * fTemp272 * fTemp270 + fRec152[0] * fTemp256 * fTemp254 + fRec127[0] * fTemp207 * fTemp205 + fRec121[0] * fTemp193 * fTemp191 + fRec114[0] * fTemp178 * fTemp176 + fRec166[0] * fTemp288 * fTemp286 + fRec108[0] * fTemp165 * fTemp163 + fRec170[0] * fTemp292 * fTemp290 + fRec176[0] * fTemp304 * fTemp302 + fRec102[0] * fTemp152 * fTemp150 + fRec181[0] * fTemp313 * fTemp311 + fRec186[0] * fTemp322 * fTemp320 + fRec190[0] * fTemp328 * fTemp326 + fRec195[0] * fTemp338 * fTemp336 + fRec200[0] * fTemp346 * fTemp344 + fRec206[0] * fTemp356 * fTemp354 + fRec211[0] * fTemp364 * fTemp362 + fRec215[0] * fTemp370 * fTemp368 + fRec96[0] * fTemp140 * fTemp138 + fRec219[0] * fTemp375 * fTemp373 + fRec223[0] * fTemp381 * fTemp379 + fRec228[0] * fTemp389 * fTemp387 + fRec232[0] * fTemp394 * fTemp392 + fRec237[0] * fTemp403 * fTemp401 + fRec241[0] * fTemp407 * fTemp405 + fRec245[0] * fTemp411 * fTemp409 + fRec249[0] * fTemp416 * fTemp414 + fRec91[0] * fTemp131 * fTemp129 + fRec254[0] * fTemp425 * fTemp423 + fRec86[0] * fTemp121 * fTemp119 + fRec258[0] * fTemp429 * fTemp427 + fRec262[0] * fTemp41 * fTemp433 * fTemp431 + fRec266[0] * fTemp437 * fTemp435 + fRec270[0] * fTemp441 * fTemp439 + fRec275[0] * fTemp449 * fTemp447 + fRec82[0] * fTemp117 * fTemp115 + fRec284[0] * fTemp460 * fTemp457 * fTemp455 + fRec288[0] * fTemp464 * fTemp462 + fRec296[0] * fTemp472 * fTemp470 + fRec300[0] * fTemp476 * fTemp474 + fRec304[0] * fTemp481 * fTemp479 + fRec308[0] * fTemp486 * fTemp484 + fRec292[0] * fTemp468 * fTemp466 + fRec312[0] * fTemp490 * fTemp488 + fTemp2131 * fTemp494 * fTemp492 + fRec320[0] * fTemp499 * fTemp497 + fRec279[0] * fTemp453 * fTemp451 + fRec324[0] * fTemp503 * fTemp501 + fRec328[0] * fTemp507 * fTemp505 + fRec332[0] * fTemp511 * fTemp509 + fRec336[0] * fTemp515 * fTemp513 + fRec76[0] * fTemp105 * fTemp103 + fRec70[0] * fTemp93 * fTemp91 + fRec64[0] * fTemp81 * fTemp79 - (fRec58[0] * fTemp69 * fTemp67 + fRec52[0] * fTemp58 * fTemp56 + fRec46[0] * fTemp48 * fTemp46 + fRec42[0] * fTemp44 * fTemp42)) + fRec1354[0] * fRec1353[0] * (1.0 - 0.5 * fRec1352[0]) * (fTemp2129 * std::cos(fTemp2127) + fTemp2128 * std::sin(fTemp2127)) + fRec1350[0] * fTemp2126;
			fVec557[IOTA0 & 1023] = fTemp2132;
			fRec1364[0] = fSlow799 + fConst7 * fRec1364[1];
			fRec1365[0] = fSlow800 + fConst7 * fRec1365[1];
			double fTemp2133 = ((iTemp14) ? 0.0 : fConst655 + fRec1368[1]);
			fRec1368[0] = fTemp2133 - std::floor(fTemp2133);
			double fTemp2134 = 1.0 - std::fabs(2.0 * fRec1368[0] + -1.0);
			fVec558[0] = fTemp2134;
			fRec1367[0] = -(fConst658 * (fConst657 * fRec1367[1] - (fTemp2134 + fVec558[1])));
			fRec1369[0] = fSlow802 + fConst7 * fRec1369[1];
			double fTemp2135 = fConst0 * (fRec1369[0] * fRec1367[0] + 0.0002);
			double fTemp2136 = fTemp2135 + -0.999995;
			int iTemp2137 = int(fTemp2136);
			double fTemp2138 = std::floor(fTemp2136);
			double fTemp2139 = fTemp2135 + (-2.0 - fTemp2138);
			double fTemp2140 = fTemp2135 + (-1.0 - fTemp2138);
			double fTemp2141 = fTemp2135 - fTemp2138;
			double fTemp2142 = fTemp2141 * fTemp2140;
			double fTemp2143 = (fTemp2135 + (-3.0 - fTemp2138)) * (fTemp2139 * (0.5 * fTemp2141 * fVec557[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp2137 + 1))) & 1023] - 0.16666666666666666 * fVec557[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp2137))) & 1023] * fTemp2140) - 0.5 * fTemp2142 * fVec557[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp2137 + 2))) & 1023]) + 0.16666666666666666 * fTemp2142 * fTemp2139 * fVec557[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp2137 + 3))) & 1023];
			fVec559[0] = fTemp2143;
			fRec1366[0] = -(fConst661 * (fConst660 * fRec1366[1] - (fTemp2143 + fVec559[1])));
			fVec560[0] = fSlow803;
			iRec1370[0] = iSlow804 * (iRec1370[1] + 1);
			fRec1371[0] = fSlow803 + fRec1371[1] * double(fVec560[1] >= fSlow803);
			fVec561[0] = fSlow805;
			iRec1372[0] = iSlow806 * (iRec1372[1] + 1);
			fRec1373[0] = fSlow805 + fRec1373[1] * double(fVec561[1] >= fSlow805);
			fVec562[0] = fSlow807;
			iRec1374[0] = iSlow808 * (iRec1374[1] + 1);
			fRec1375[0] = fSlow807 + fRec1375[1] * double(fVec562[1] >= fSlow807);
			fVec563[0] = fSlow809;
			iRec1376[0] = iSlow810 * (iRec1376[1] + 1);
			fRec1377[0] = fSlow809 + fRec1377[1] * double(fVec563[1] >= fSlow809);
			fVec564[0] = fSlow811;
			iRec1378[0] = iSlow812 * (iRec1378[1] + 1);
			fRec1379[0] = fSlow811 + fRec1379[1] * double(fVec564[1] >= fSlow811);
			fVec565[0] = fSlow813;
			iRec1380[0] = iSlow814 * (iRec1380[1] + 1);
			fRec1381[0] = fSlow813 + fRec1381[1] * double(fVec565[1] >= fSlow813);
			fVec566[0] = fSlow815;
			iRec1382[0] = iSlow816 * (iRec1382[1] + 1);
			fRec1383[0] = fSlow815 + fRec1383[1] * double(fVec566[1] >= fSlow815);
			fVec567[0] = fSlow817;
			iRec1384[0] = iSlow818 * (iRec1384[1] + 1);
			fRec1385[0] = fSlow817 + fRec1385[1] * double(fVec567[1] >= fSlow817);
			fVec568[0] = fSlow819;
			iRec1386[0] = iSlow820 * (iRec1386[1] + 1);
			fRec1387[0] = fSlow819 + fRec1387[1] * double(fVec568[1] >= fSlow819);
			fVec569[0] = fSlow821;
			iRec1388[0] = iSlow822 * (iRec1388[1] + 1);
			fRec1389[0] = fSlow821 + fRec1389[1] * double(fVec569[1] >= fSlow821);
			fVec570[0] = fSlow823;
			iRec1390[0] = iSlow824 * (iRec1390[1] + 1);
			fRec1391[0] = fSlow823 + fRec1391[1] * double(fVec570[1] >= fSlow823);
			fVec571[0] = fSlow825;
			iRec1392[0] = iSlow826 * (iRec1392[1] + 1);
			fRec1393[0] = fSlow825 + fRec1393[1] * double(fVec571[1] >= fSlow825);
			fVec572[0] = fSlow827;
			iRec1394[0] = iSlow828 * (iRec1394[1] + 1);
			fRec1395[0] = fSlow827 + fRec1395[1] * double(fVec572[1] >= fSlow827);
			fVec573[0] = fSlow829;
			iRec1396[0] = iSlow830 * (iRec1396[1] + 1);
			fRec1397[0] = fSlow829 + fRec1397[1] * double(fVec573[1] >= fSlow829);
			fVec574[0] = fSlow831;
			iRec1398[0] = iSlow832 * (iRec1398[1] + 1);
			fRec1399[0] = fSlow831 + fRec1399[1] * double(fVec574[1] >= fSlow831);
			fVec575[0] = fSlow833;
			iRec1400[0] = iSlow834 * (iRec1400[1] + 1);
			fRec1401[0] = fSlow833 + fRec1401[1] * double(fVec575[1] >= fSlow833);
			fVec576[0] = fSlow835;
			iRec1402[0] = iSlow836 * (iRec1402[1] + 1);
			fRec1403[0] = fSlow835 + fRec1403[1] * double(fVec576[1] >= fSlow835);
			fVec577[0] = fSlow837;
			iRec1404[0] = iSlow838 * (iRec1404[1] + 1);
			fRec1405[0] = fSlow837 + fRec1405[1] * double(fVec577[1] >= fSlow837);
			fVec578[0] = fSlow839;
			iRec1406[0] = iSlow840 * (iRec1406[1] + 1);
			fRec1407[0] = fSlow839 + fRec1407[1] * double(fVec578[1] >= fSlow839);
			fVec579[0] = fSlow841;
			iRec1408[0] = iSlow842 * (iRec1408[1] + 1);
			fRec1409[0] = fSlow841 + fRec1409[1] * double(fVec579[1] >= fSlow841);
			fVec580[0] = fSlow843;
			iRec1410[0] = iSlow844 * (iRec1410[1] + 1);
			fRec1411[0] = fSlow843 + fRec1411[1] * double(fVec580[1] >= fSlow843);
			double fTemp2144 = 0.06 * (11.0 * fRec14[0] + 1.0) * (std::max<double>(0.0, std::min<double>(fConst13 * fRec1411[0], 1.0) - fSlow12 * double(iRec1410[0])) * (fRec22[0] * fTemp845 - fRec20[0] * fTemp144) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1409[0], 1.0) - fSlow12 * double(iRec1408[0])) * (fRec20[0] * fTemp584 - fRec22[0] * fTemp23) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1407[0], 1.0) - fSlow12 * double(iRec1406[0])) * (fRec22[0] * fTemp1223 - fRec20[0] * fTemp616) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1405[0], 1.0) - fSlow12 * double(iRec1404[0])) * (fRec22[0] * fTemp1444 + fRec20[0] * fTemp161) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1403[0], 1.0) - fSlow12 * double(iRec1402[0])) * (fRec22[0] * fTemp1007 + fRec20[0] * fTemp598) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1401[0], 1.0) - fSlow12 * double(iRec1400[0])) * (fRec22[0] * fTemp1018 + fRec20[0] * fTemp554) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1399[0], 1.0) - fSlow12 * double(iRec1398[0])) * (fRec22[0] * fTemp1024 + fRec20[0] * fTemp560) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1397[0], 1.0) - fSlow12 * double(iRec1396[0])) * (fRec22[0] * fTemp1694 + fRec20[0] * fTemp568) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1395[0], 1.0) - fSlow12 * double(iRec1394[0])) * (fRec22[0] * fTemp1251 + fRec20[0] * fTemp268) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1393[0], 1.0) - fSlow12 * double(iRec1392[0])) * (fRec22[0] * fTemp1243 + fRec20[0] * fTemp241) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1391[0], 1.0) - fSlow12 * double(iRec1390[0])) * (fRec22[0] * fTemp1035 + fRec20[0] * fTemp214) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1389[0], 1.0) - fSlow12 * double(iRec1388[0])) * (fRec20[0] * fTemp845 - fRec22[0] * fTemp32) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1387[0], 1.0) - fSlow12 * double(iRec1386[0])) * (fRec22[0] * fTemp2008 + fRec20[0] * fTemp1223) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1385[0], 1.0) - fSlow12 * double(iRec1384[0])) * (fRec20[0] * fTemp1444 - fRec22[0] * fTemp1439) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1383[0], 1.0) - fSlow12 * double(iRec1382[0])) * (fRec20[0] * fTemp1007 - fRec22[0] * fTemp1232) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1381[0], 1.0) - fSlow12 * double(iRec1380[0])) * (fRec22[0] * fTemp1633 + fRec20[0] * fTemp1018) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1379[0], 1.0) - fSlow12 * double(iRec1378[0])) * (fRec22[0] * fTemp1702 + fRec20[0] * fTemp1024) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1377[0], 1.0) - fSlow12 * double(iRec1376[0])) * (fRec22[0] * fTemp1647 + fRec20[0] * fTemp1694) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1375[0], 1.0) - fSlow12 * double(iRec1374[0])) * (fRec22[0] * fTemp1690 + fRec20[0] * fTemp1251) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1373[0], 1.0) - fSlow12 * double(iRec1372[0])) * (fRec20[0] * fTemp1243 - fRec22[0] * fTemp1462) + std::max<double>(0.0, std::min<double>(fConst13 * fRec1371[0], 1.0) - fSlow12 * double(iRec1370[0])) * (fRec20[0] * fTemp1035 - fRec22[0] * fTemp1664) + fRec1366[0] * fRec1365[0] + fRec1364[0] * fTemp2132 + (1.0 - fRec1350[0]) * fTemp2126 + std::max<double>(0.0, std::min<double>(fConst13 * fRec35[0], 1.0) - fSlow12 * double(iRec34[0])) * (fRec22[0] * fTemp35 - fRec20[0] * fTemp32) - (std::max<double>(0.0, std::min<double>(fConst13 * fRec31[0], 1.0) - fSlow12 * double(iRec30[0])) * (fRec22[0] * fTemp29 + fRec20[0] * fTemp20) + std::max<double>(0.0, std::min<double>(fConst13 * fRec28[0], 1.0) - fSlow12 * double(iRec27[0])) * (fRec22[0] * fTemp26 + fRec20[0] * fTemp23) + std::max<double>(0.0, std::min<double>(fConst13 * fRec24[0], 1.0) - fSlow12 * double(iRec23[0])) * (fRec22[0] * fTemp20 + fRec20[0] * fTemp17)));
			double fTemp2145 = fTemp12 + fTemp2144;
			fVec581[0] = fTemp2145;
			double fTemp2146 = fTemp2145 - fVec581[1];
			double fTemp2147 = ((std::fabs(fTemp2146) <= fConst3) ? tanh(0.5 * (fTemp2144 + fTemp12 + fVec581[1])) : (std::log(std::min<double>(1.7976931348623157e+308, cosh(fTemp2145))) - std::log(std::min<double>(1.7976931348623157e+308, cosh(fVec581[1])))) / fTemp2146);
			fVec582[0] = fTemp2147 - fTemp13;
			fRec16[0] = 0.995 * fRec16[1] + fTemp2147 - (fTemp13 + fVec582[1]);
			double fTemp2148 = fRec16[0] * fRec15[0];
			double fTemp2149 = 0.35 * (fTemp2148 / fTemp11);
			double fTemp2150 = fRec10[1] + fConst662 * (fTemp2149 - fRec11[1]);
			fRec10[0] = fConst664 * fTemp2150 - fRec10[1];
			double fTemp2151 = fRec11[1] + fConst665 * fTemp2150;
			fRec11[0] = 2.0 * fTemp2151 - fRec11[1];
			double fRec12 = fConst666 * fTemp2150;
			double fRec13 = fTemp2151;
			double fTemp2152 = fRec13 + 1.4142135623730951 * fRec12;
			double fTemp2153 = fRec6[1] + fConst662 * (fTemp2149 - (fTemp2152 + fRec7[1]));
			fRec6[0] = fConst664 * fTemp2153 - fRec6[1];
			double fTemp2154 = fRec7[1] + fConst665 * fTemp2153;
			fRec7[0] = 2.0 * fTemp2154 - fRec7[1];
			double fRec8 = fConst666 * fTemp2153;
			double fRec9 = fTemp2154;
			double fTemp2155 = 1.4142135623730951 * (fRec12 + fRec8) + fRec13 + fRec9;
			double fTemp2156 = fRec1412[1] + fConst667 * (fTemp2149 - (fTemp2155 + fRec1413[1]));
			fRec1412[0] = fConst669 * fTemp2156 - fRec1412[1];
			double fTemp2157 = fRec1413[1] + fConst670 * fTemp2156;
			fRec1413[0] = 2.0 * fTemp2157 - fRec1413[1];
			double fRec1414 = fConst671 * fTemp2156;
			double fTemp2158 = 0.8106253898990492 * fRec1414 + fTemp2149 - fTemp2155;
			fVec583[IOTA0 & 1023] = fTemp2158;
			double fTemp2159 = fConst0 * fTemp8;
			double fTemp2160 = fTemp2159 + -0.999995;
			int iTemp2161 = int(fTemp2160);
			double fTemp2162 = std::floor(fTemp2160);
			double fTemp2163 = fTemp2159 + (-2.0 - fTemp2162);
			double fTemp2164 = fTemp2159 + (-1.0 - fTemp2162);
			double fTemp2165 = fTemp2159 - fTemp2162;
			double fTemp2166 = fTemp2165 * fTemp2164;
			double fTemp2167 = (fTemp2159 + (-3.0 - fTemp2162)) * (fTemp2163 * (0.15 * fTemp2165 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2161 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2161))) & 1023] * fTemp2164) - 0.15 * fTemp2166 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2161 + 2))) & 1023]) + 0.049999999999999996 * fTemp2166 * fTemp2163 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2161 + 3))) & 1023];
			double fTemp2168 = fRec3[1] + fTemp9 * (fTemp2167 - fRec4[1]);
			double fTemp2169 = fTemp2168 / fTemp10;
			fRec3[0] = 2.0 * fTemp2169 - fRec3[1];
			double fTemp2170 = fRec4[1] + fTemp9 * fTemp2168 / fTemp10;
			fRec4[0] = 2.0 * fTemp2170 - fRec4[1];
			double fRec5 = fTemp2170;
			double fTemp2171 = ((fSlow845 > fRec1416[1]) ? fConst673 : fConst672);
			fRec1416[0] = fSlow845 * (1.0 - fTemp2171) + fRec1416[1] * fTemp2171;
			double fTemp2172 = fRec1415[1] + fConst3 * fRec1416[0];
			fRec1415[0] = fTemp2172 - std::floor(fTemp2172);
			double fTemp2173 = 6.283185307179586 * (std::floor(fRec1415[0] + 0.37) + (0.63 - fRec1415[0]));
			double fTemp2174 = fRec1425[1] + fConst662 * (fRec13 - fRec1426[1]);
			fRec1425[0] = fConst664 * fTemp2174 - fRec1425[1];
			double fTemp2175 = fRec1426[1] + fConst665 * fTemp2174;
			fRec1426[0] = 2.0 * fTemp2175 - fRec1426[1];
			double fRec1427 = fTemp2175;
			double fTemp2176 = fRec1421[1] + fConst674 * (fRec1427 - fRec1422[1]);
			fRec1421[0] = fConst676 * fTemp2176 - fRec1421[1];
			double fTemp2177 = fRec1422[1] + fConst677 * fTemp2176;
			fRec1422[0] = 2.0 * fTemp2177 - fRec1422[1];
			double fRec1423 = fConst678 * fTemp2176;
			double fRec1424 = fTemp2177;
			double fTemp2178 = fRec1424 + 1.4142135623730951 * fRec1423;
			double fTemp2179 = fRec1417[1] + fConst674 * (fRec1427 - (fTemp2178 + fRec1418[1]));
			fRec1417[0] = fConst676 * fTemp2179 - fRec1417[1];
			double fTemp2180 = fRec1418[1] + fConst677 * fTemp2179;
			fRec1418[0] = 2.0 * fTemp2180 - fRec1418[1];
			double fRec1419 = fConst678 * fTemp2179;
			double fRec1420 = fTemp2180;
			double fTemp2181 = fRec1427 - (1.4142135623730951 * (fRec1423 + fRec1419) + fRec1424 + fRec1420);
			double fTemp2182 = fRec1428[1] + fConst674 * (fRec1424 - fRec1429[1]);
			fRec1428[0] = fConst676 * fTemp2182 - fRec1428[1];
			double fTemp2183 = fRec1429[1] + fConst677 * fTemp2182;
			fRec1429[0] = 2.0 * fTemp2183 - fRec1429[1];
			double fRec1430 = fTemp2183;
			double fTemp2184 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp6 + -2.2)) + 0.0016);
			double fTemp2185 = 0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fTemp2184) + -2.2)) + 0.0016)) + -2.2)) + 0.0016;
			double fTemp2186 = std::tan(fConst6 * (4.5e+03 * (std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * fTemp2185) + -2.2) + 1.0) + 3e+03));
			double fTemp2187 = fTemp2186 * (fTemp2186 + 1.4144271570014144) + 1.0;
			double fTemp2188 = fConst0 * fTemp2185;
			double fTemp2189 = fTemp2188 + -0.999995;
			int iTemp2190 = int(fTemp2189);
			double fTemp2191 = std::floor(fTemp2189);
			double fTemp2192 = fTemp2188 + (-2.0 - fTemp2191);
			double fTemp2193 = fTemp2188 + (-1.0 - fTemp2191);
			double fTemp2194 = fTemp2188 - fTemp2191;
			double fTemp2195 = fTemp2194 * fTemp2193;
			double fTemp2196 = (fTemp2188 + (-3.0 - fTemp2191)) * (fTemp2192 * (0.15 * fTemp2194 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2190 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2190))) & 1023] * fTemp2193) - 0.15 * fTemp2195 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2190 + 2))) & 1023]) + 0.049999999999999996 * fTemp2195 * fTemp2192 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2190 + 3))) & 1023];
			double fTemp2197 = fRec1431[1] + fTemp2186 * (fTemp2196 - fRec1432[1]);
			double fTemp2198 = fTemp2197 / fTemp2187;
			fRec1431[0] = 2.0 * fTemp2198 - fRec1431[1];
			double fTemp2199 = fRec1432[1] + fTemp2186 * fTemp2197 / fTemp2187;
			fRec1432[0] = 2.0 * fTemp2199 - fRec1432[1];
			double fRec1433 = fTemp2199;
			double fTemp2200 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp6)) + 0.0005);
			double fTemp2201 = 0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fTemp2200))) + 0.0005)))) + 0.0005;
			double fTemp2202 = std::tan(fConst6 * (4.5e+03 * (std::cos(fTemp5 + 6.283185307179586 * (fTemp3 - fRec1[0] * fTemp2201)) + 1.0) + 3e+03));
			double fTemp2203 = fTemp2202 * (fTemp2202 + 1.4144271570014144) + 1.0;
			double fTemp2204 = fConst0 * fTemp2201;
			double fTemp2205 = fTemp2204 + -0.999995;
			int iTemp2206 = int(fTemp2205);
			double fTemp2207 = std::floor(fTemp2205);
			double fTemp2208 = fTemp2204 + (-2.0 - fTemp2207);
			double fTemp2209 = fTemp2204 + (-1.0 - fTemp2207);
			double fTemp2210 = fTemp2204 - fTemp2207;
			double fTemp2211 = fTemp2210 * fTemp2209;
			double fTemp2212 = (fTemp2204 + (-3.0 - fTemp2207)) * (fTemp2208 * (0.15 * fTemp2210 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2206 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2206))) & 1023] * fTemp2209) - 0.15 * fTemp2211 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2206 + 2))) & 1023]) + 0.049999999999999996 * fTemp2211 * fTemp2208 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2206 + 3))) & 1023];
			double fTemp2213 = fRec1434[1] + fTemp2202 * (fTemp2212 - fRec1435[1]);
			double fTemp2214 = fTemp2213 / fTemp2203;
			fRec1434[0] = 2.0 * fTemp2214 - fRec1434[1];
			double fTemp2215 = fRec1435[1] + fTemp2202 * fTemp2213 / fTemp2203;
			fRec1435[0] = 2.0 * fTemp2215 - fRec1435[1];
			double fRec1436 = fTemp2215;
			fRec1437[0] = fSlow846 + fConst10 * fRec1437[1];
			double fTemp2216 = 1.5707963267948966 * fRec1437[0];
			double fTemp2217 = std::sin(fTemp2216);
			double fTemp2218 = 0.35 * (fTemp2148 * std::cos(fTemp2216) / fTemp11);
			output0[i0] = FAUSTFLOAT(fTemp2218 + fTemp2217 * (fRec1436 * (1.0 - 0.225 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp2200)))) + 0.0005))))) + 0.0005)))))) + 0.35 * fRec1433 * (1.0 - 0.225 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp2184)) + -2.2)) + 0.0016))) + -2.2)) + 0.0016))) + -2.2))) + fRec1430 + fTemp2181 * (1.0 - 0.25 * (1.0 - std::cos(fTemp2173 + fTemp5))) + 0.25 * fRec5 * (1.0 - 0.225 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp5 + 6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp7)) + 2.2)) + 0.0028))) + 2.2)) + 0.0028))) + 2.2)))));
			double fTemp2219 = 2.2 - fTemp5;
			double fTemp2220 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp4 + fTemp2219)) + 0.0028);
			double fTemp2221 = 0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fTemp2220) + fTemp2219)) + 0.0028)) + fTemp2219)) + 0.0028;
			double fTemp2222 = std::tan(fConst6 * (4.5e+03 * (std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * fTemp2221) + fTemp2219) + 1.0) + 3e+03));
			double fTemp2223 = fTemp2222 * (fTemp2222 + 1.4144271570014144) + 1.0;
			double fTemp2224 = fConst0 * fTemp2221;
			double fTemp2225 = fTemp2224 + -0.999995;
			int iTemp2226 = int(fTemp2225);
			double fTemp2227 = std::floor(fTemp2225);
			double fTemp2228 = fTemp2224 + (-2.0 - fTemp2227);
			double fTemp2229 = fTemp2224 + (-1.0 - fTemp2227);
			double fTemp2230 = fTemp2224 - fTemp2227;
			double fTemp2231 = fTemp2230 * fTemp2229;
			double fTemp2232 = (fTemp2224 + (-3.0 - fTemp2227)) * (fTemp2228 * (0.15 * fTemp2230 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2226 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2226))) & 1023] * fTemp2229) - 0.15 * fTemp2231 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2226 + 2))) & 1023]) + 0.049999999999999996 * fTemp2231 * fTemp2228 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2226 + 3))) & 1023];
			double fTemp2233 = fRec1438[1] + fTemp2222 * (fTemp2232 - fRec1439[1]);
			double fTemp2234 = fTemp2233 / fTemp2223;
			fRec1438[0] = 2.0 * fTemp2234 - fRec1438[1];
			double fTemp2235 = fRec1439[1] + fTemp2222 * fTemp2233 / fTemp2223;
			fRec1439[0] = 2.0 * fTemp2235 - fRec1439[1];
			double fRec1440 = fTemp2235;
			double fTemp2236 = -2.2 - fTemp5;
			double fTemp2237 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp4 + fTemp2236)) + 0.0016);
			double fTemp2238 = 0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fTemp2237) + fTemp2236)) + 0.0016)) + fTemp2236)) + 0.0016;
			double fTemp2239 = std::tan(fConst6 * (4.5e+03 * (std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * fTemp2238) + fTemp2236) + 1.0) + 3e+03));
			double fTemp2240 = fTemp2239 * (fTemp2239 + 1.4144271570014144) + 1.0;
			double fTemp2241 = fConst0 * fTemp2238;
			double fTemp2242 = fTemp2241 + -0.999995;
			int iTemp2243 = int(fTemp2242);
			double fTemp2244 = std::floor(fTemp2242);
			double fTemp2245 = fTemp2241 + (-2.0 - fTemp2244);
			double fTemp2246 = fTemp2241 + (-1.0 - fTemp2244);
			double fTemp2247 = fTemp2241 - fTemp2244;
			double fTemp2248 = fTemp2247 * fTemp2246;
			double fTemp2249 = (fTemp2241 + (-3.0 - fTemp2244)) * (fTemp2245 * (0.15 * fTemp2247 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2243 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2243))) & 1023] * fTemp2246) - 0.15 * fTemp2248 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2243 + 2))) & 1023]) + 0.049999999999999996 * fTemp2248 * fTemp2245 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2243 + 3))) & 1023];
			double fTemp2250 = fRec1441[1] + fTemp2239 * (fTemp2249 - fRec1442[1]);
			double fTemp2251 = fTemp2250 / fTemp2240;
			fRec1441[0] = 2.0 * fTemp2251 - fRec1441[1];
			double fTemp2252 = fRec1442[1] + fTemp2239 * fTemp2250 / fTemp2240;
			fRec1442[0] = 2.0 * fTemp2252 - fRec1442[1];
			double fRec1443 = fTemp2252;
			double fTemp2253 = fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(fTemp4 - fTemp5)) + 0.0005);
			double fTemp2254 = 0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fTemp3 - fTemp2253) - fTemp5)) + 0.0005)) - fTemp5)) + 0.0005;
			double fTemp2255 = std::tan(fConst6 * (4.5e+03 * (std::cos(6.283185307179586 * (fTemp3 - fRec1[0] * fTemp2254) - fTemp5) + 1.0) + 3e+03));
			double fTemp2256 = fTemp2255 * (fTemp2255 + 1.4144271570014144) + 1.0;
			double fTemp2257 = fConst0 * fTemp2254;
			double fTemp2258 = fTemp2257 + -0.999995;
			int iTemp2259 = int(fTemp2258);
			double fTemp2260 = std::floor(fTemp2258);
			double fTemp2261 = fTemp2257 + (-2.0 - fTemp2260);
			double fTemp2262 = fTemp2257 + (-1.0 - fTemp2260);
			double fTemp2263 = fTemp2257 - fTemp2260;
			double fTemp2264 = fTemp2263 * fTemp2262;
			double fTemp2265 = (fTemp2257 + (-3.0 - fTemp2260)) * (fTemp2261 * (0.15 * fTemp2263 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2259 + 1))) & 1023] - 0.049999999999999996 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2259))) & 1023] * fTemp2262) - 0.15 * fTemp2264 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2259 + 2))) & 1023]) + 0.049999999999999996 * fTemp2264 * fTemp2261 * fVec583[(IOTA0 - std::min<int>(2048, std::max<int>(0, iTemp2259 + 3))) & 1023];
			double fTemp2266 = fRec1444[1] + fTemp2255 * (fTemp2265 - fRec1445[1]);
			double fTemp2267 = fTemp2266 / fTemp2256;
			fRec1444[0] = 2.0 * fTemp2267 - fRec1444[1];
			double fTemp2268 = fRec1445[1] + fTemp2255 * fTemp2266 / fTemp2256;
			fRec1445[0] = 2.0 * fTemp2268 - fRec1445[1];
			double fRec1446 = fTemp2268;
			output1[i0] = FAUSTFLOAT(fTemp2218 + fTemp2217 * (fRec1446 * (1.0 - 0.225 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp2253)) - fTemp5)) + 0.0005))) - fTemp5)) + 0.0005))) - fTemp5))) + 0.35 * fRec1443 * (1.0 - 0.225 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp2237)) + fTemp2236)) + 0.0016))) + fTemp2236)) + 0.0016))) + fTemp2236))) + fRec1430 + fTemp2181 * (1.0 - 0.25 * (1.0 - std::cos(fTemp2173 - fTemp5))) + 0.25 * fRec1440 * (1.0 - 0.225 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fRec1[0] * (0.00043731778425655976 * (1.0 - std::cos(6.283185307179586 * (fRec0[0] - (fTemp2 + fTemp2220)) + fTemp2219)) + 0.0028))) + fTemp2219)) + 0.0028))) + fTemp2219)))));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fVec3[1] = fVec3[0];
			iRec23[1] = iRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fVec4[1] = fVec4[0];
			iRec27[1] = iRec27[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fVec5[1] = fVec5[0];
			iRec30[1] = iRec30[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fVec6[1] = fVec6[0];
			iRec34[1] = iRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			IOTA0 = IOTA0 + 1;
			fVec7[1] = fVec7[0];
			iRec39[1] = iRec39[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fVec8[1] = fVec8[0];
			iRec43[1] = iRec43[0];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
			fVec9[1] = fVec9[0];
			iRec49[1] = iRec49[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec54[1] = fRec54[0];
			fVec10[1] = fVec10[0];
			iRec55[1] = iRec55[0];
			fRec57[1] = fRec57[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec60[1] = fRec60[0];
			fVec11[1] = fVec11[0];
			iRec61[1] = iRec61[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fVec12[1] = fVec12[0];
			iRec67[1] = iRec67[0];
			fRec69[1] = fRec69[0];
			fRec70[1] = fRec70[0];
			fRec71[1] = fRec71[0];
			fRec72[1] = fRec72[0];
			fVec13[1] = fVec13[0];
			iRec73[1] = iRec73[0];
			fRec75[1] = fRec75[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			fRec78[1] = fRec78[0];
			fVec14[1] = fVec14[0];
			iRec79[1] = iRec79[0];
			fRec81[1] = fRec81[0];
			fRec82[1] = fRec82[0];
			fVec15[1] = fVec15[0];
			iRec83[1] = iRec83[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fVec16[1] = fVec16[0];
			iRec88[1] = iRec88[0];
			fRec90[1] = fRec90[0];
			fRec91[1] = fRec91[0];
			fRec92[1] = fRec92[0];
			fVec17[1] = fVec17[0];
			iRec93[1] = iRec93[0];
			fRec95[1] = fRec95[0];
			fRec96[1] = fRec96[0];
			fRec97[1] = fRec97[0];
			fRec98[1] = fRec98[0];
			fVec18[1] = fVec18[0];
			iRec99[1] = iRec99[0];
			fRec101[1] = fRec101[0];
			fRec102[1] = fRec102[0];
			fRec103[1] = fRec103[0];
			fRec104[1] = fRec104[0];
			fVec19[1] = fVec19[0];
			iRec105[1] = iRec105[0];
			fRec107[1] = fRec107[0];
			fRec108[1] = fRec108[0];
			fRec109[1] = fRec109[0];
			fRec110[1] = fRec110[0];
			fVec20[1] = fVec20[0];
			iRec111[1] = iRec111[0];
			fRec113[1] = fRec113[0];
			fRec114[1] = fRec114[0];
			fRec115[1] = fRec115[0];
			fRec116[1] = fRec116[0];
			fRec117[1] = fRec117[0];
			fVec21[1] = fVec21[0];
			iRec118[1] = iRec118[0];
			fRec120[1] = fRec120[0];
			fRec121[1] = fRec121[0];
			fRec122[1] = fRec122[0];
			fRec123[1] = fRec123[0];
			fVec22[1] = fVec22[0];
			iRec124[1] = iRec124[0];
			fRec126[1] = fRec126[0];
			fRec127[1] = fRec127[0];
			fRec128[1] = fRec128[0];
			fRec129[1] = fRec129[0];
			fRec130[1] = fRec130[0];
			fVec23[1] = fVec23[0];
			iRec131[1] = iRec131[0];
			fRec133[1] = fRec133[0];
			fRec134[1] = fRec134[0];
			fRec135[1] = fRec135[0];
			fVec24[1] = fVec24[0];
			iRec136[1] = iRec136[0];
			fRec138[1] = fRec138[0];
			fRec139[1] = fRec139[0];
			fRec140[1] = fRec140[0];
			fRec141[1] = fRec141[0];
			fRec142[1] = fRec142[0];
			fVec25[1] = fVec25[0];
			iRec143[1] = iRec143[0];
			fRec145[1] = fRec145[0];
			fRec146[1] = fRec146[0];
			fRec147[1] = fRec147[0];
			fRec148[1] = fRec148[0];
			fVec26[1] = fVec26[0];
			iRec149[1] = iRec149[0];
			fRec151[1] = fRec151[0];
			fRec152[1] = fRec152[0];
			fRec153[1] = fRec153[0];
			fRec154[1] = fRec154[0];
			fRec155[1] = fRec155[0];
			fVec27[1] = fVec27[0];
			iRec156[1] = iRec156[0];
			fRec158[1] = fRec158[0];
			fRec159[1] = fRec159[0];
			fRec160[1] = fRec160[0];
			fRec161[1] = fRec161[0];
			fRec162[1] = fRec162[0];
			fVec28[1] = fVec28[0];
			iRec163[1] = iRec163[0];
			fRec165[1] = fRec165[0];
			fRec166[1] = fRec166[0];
			fVec29[1] = fVec29[0];
			iRec167[1] = iRec167[0];
			fRec169[1] = fRec169[0];
			fRec170[1] = fRec170[0];
			fRec171[1] = fRec171[0];
			fRec172[1] = fRec172[0];
			fVec30[1] = fVec30[0];
			iRec173[1] = iRec173[0];
			fRec175[1] = fRec175[0];
			fRec176[1] = fRec176[0];
			fRec177[1] = fRec177[0];
			fVec31[1] = fVec31[0];
			iRec178[1] = iRec178[0];
			fRec180[1] = fRec180[0];
			fRec181[1] = fRec181[0];
			fRec182[1] = fRec182[0];
			fVec32[1] = fVec32[0];
			iRec183[1] = iRec183[0];
			fRec185[1] = fRec185[0];
			fRec186[1] = fRec186[0];
			fVec33[1] = fVec33[0];
			iRec187[1] = iRec187[0];
			fRec189[1] = fRec189[0];
			fRec190[1] = fRec190[0];
			fRec191[1] = fRec191[0];
			fVec34[1] = fVec34[0];
			iRec192[1] = iRec192[0];
			fRec194[1] = fRec194[0];
			fRec195[1] = fRec195[0];
			fRec196[1] = fRec196[0];
			fVec35[1] = fVec35[0];
			iRec197[1] = iRec197[0];
			fRec199[1] = fRec199[0];
			fRec200[1] = fRec200[0];
			fRec201[1] = fRec201[0];
			fRec202[1] = fRec202[0];
			fVec36[1] = fVec36[0];
			iRec203[1] = iRec203[0];
			fRec205[1] = fRec205[0];
			fRec206[1] = fRec206[0];
			fRec207[1] = fRec207[0];
			fVec37[1] = fVec37[0];
			iRec208[1] = iRec208[0];
			fRec210[1] = fRec210[0];
			fRec211[1] = fRec211[0];
			fVec38[1] = fVec38[0];
			iRec212[1] = iRec212[0];
			fRec214[1] = fRec214[0];
			fRec215[1] = fRec215[0];
			fVec39[1] = fVec39[0];
			iRec216[1] = iRec216[0];
			fRec218[1] = fRec218[0];
			fRec219[1] = fRec219[0];
			fVec40[1] = fVec40[0];
			iRec220[1] = iRec220[0];
			fRec222[1] = fRec222[0];
			fRec223[1] = fRec223[0];
			fRec224[1] = fRec224[0];
			fVec41[1] = fVec41[0];
			iRec225[1] = iRec225[0];
			fRec227[1] = fRec227[0];
			fRec228[1] = fRec228[0];
			fVec42[1] = fVec42[0];
			iRec229[1] = iRec229[0];
			fRec231[1] = fRec231[0];
			fRec232[1] = fRec232[0];
			fRec233[1] = fRec233[0];
			fVec43[1] = fVec43[0];
			iRec234[1] = iRec234[0];
			fRec236[1] = fRec236[0];
			fRec237[1] = fRec237[0];
			fVec44[1] = fVec44[0];
			iRec238[1] = iRec238[0];
			fRec240[1] = fRec240[0];
			fRec241[1] = fRec241[0];
			fVec45[1] = fVec45[0];
			iRec242[1] = iRec242[0];
			fRec244[1] = fRec244[0];
			fRec245[1] = fRec245[0];
			fVec46[1] = fVec46[0];
			iRec246[1] = iRec246[0];
			fRec248[1] = fRec248[0];
			fRec249[1] = fRec249[0];
			fRec250[1] = fRec250[0];
			fVec47[1] = fVec47[0];
			iRec251[1] = iRec251[0];
			fRec253[1] = fRec253[0];
			fRec254[1] = fRec254[0];
			fVec48[1] = fVec48[0];
			iRec255[1] = iRec255[0];
			fRec257[1] = fRec257[0];
			fRec258[1] = fRec258[0];
			fVec49[1] = fVec49[0];
			iRec259[1] = iRec259[0];
			fRec261[1] = fRec261[0];
			fRec262[1] = fRec262[0];
			fVec50[1] = fVec50[0];
			iRec263[1] = iRec263[0];
			fRec265[1] = fRec265[0];
			fRec266[1] = fRec266[0];
			fVec51[1] = fVec51[0];
			iRec267[1] = iRec267[0];
			fRec269[1] = fRec269[0];
			fRec270[1] = fRec270[0];
			fRec271[1] = fRec271[0];
			fVec52[1] = fVec52[0];
			iRec272[1] = iRec272[0];
			fRec274[1] = fRec274[0];
			fRec275[1] = fRec275[0];
			fVec53[1] = fVec53[0];
			iRec276[1] = iRec276[0];
			fRec278[1] = fRec278[0];
			fRec279[1] = fRec279[0];
			fVec54[1] = fVec54[0];
			iRec280[1] = iRec280[0];
			fRec282[1] = fRec282[0];
			fRec283[1] = fRec283[0];
			fRec284[1] = fRec284[0];
			fVec55[1] = fVec55[0];
			iRec285[1] = iRec285[0];
			fRec287[1] = fRec287[0];
			fRec288[1] = fRec288[0];
			fVec56[1] = fVec56[0];
			iRec289[1] = iRec289[0];
			fRec291[1] = fRec291[0];
			fRec292[1] = fRec292[0];
			fVec57[1] = fVec57[0];
			iRec293[1] = iRec293[0];
			fRec295[1] = fRec295[0];
			fRec296[1] = fRec296[0];
			fVec58[1] = fVec58[0];
			iRec297[1] = iRec297[0];
			fRec299[1] = fRec299[0];
			fRec300[1] = fRec300[0];
			fVec59[1] = fVec59[0];
			iRec301[1] = iRec301[0];
			fRec303[1] = fRec303[0];
			fRec304[1] = fRec304[0];
			fVec60[1] = fVec60[0];
			iRec305[1] = iRec305[0];
			fRec307[1] = fRec307[0];
			fRec308[1] = fRec308[0];
			fVec61[1] = fVec61[0];
			iRec309[1] = iRec309[0];
			fRec311[1] = fRec311[0];
			fRec312[1] = fRec312[0];
			fVec62[1] = fVec62[0];
			iRec313[1] = iRec313[0];
			fRec315[1] = fRec315[0];
			fRec316[1] = fRec316[0];
			fVec63[1] = fVec63[0];
			iRec317[1] = iRec317[0];
			fRec319[1] = fRec319[0];
			fRec320[1] = fRec320[0];
			fVec64[1] = fVec64[0];
			iRec321[1] = iRec321[0];
			fRec323[1] = fRec323[0];
			fRec324[1] = fRec324[0];
			fVec65[1] = fVec65[0];
			iRec325[1] = iRec325[0];
			fRec327[1] = fRec327[0];
			fRec328[1] = fRec328[0];
			fVec66[1] = fVec66[0];
			iRec329[1] = iRec329[0];
			fRec331[1] = fRec331[0];
			fRec332[1] = fRec332[0];
			fVec67[1] = fVec67[0];
			iRec333[1] = iRec333[0];
			fRec335[1] = fRec335[0];
			fRec336[1] = fRec336[0];
			fRec337[1] = fRec337[0];
			fVec68[1] = fVec68[0];
			iRec338[1] = iRec338[0];
			fRec339[1] = fRec339[0];
			fVec69[1] = fVec69[0];
			iRec340[1] = iRec340[0];
			fRec341[1] = fRec341[0];
			fVec70[1] = fVec70[0];
			iRec342[1] = iRec342[0];
			fRec343[1] = fRec343[0];
			fVec71[1] = fVec71[0];
			iRec344[1] = iRec344[0];
			fRec345[1] = fRec345[0];
			fVec72[1] = fVec72[0];
			iRec346[1] = iRec346[0];
			fRec347[1] = fRec347[0];
			fVec73[1] = fVec73[0];
			iRec348[1] = iRec348[0];
			fRec349[1] = fRec349[0];
			fVec74[1] = fVec74[0];
			iRec350[1] = iRec350[0];
			fRec351[1] = fRec351[0];
			fVec75[1] = fVec75[0];
			iRec352[1] = iRec352[0];
			fRec353[1] = fRec353[0];
			fVec76[1] = fVec76[0];
			iRec354[1] = iRec354[0];
			fRec355[1] = fRec355[0];
			fVec77[1] = fVec77[0];
			iRec356[1] = iRec356[0];
			fRec357[1] = fRec357[0];
			fRec358[1] = fRec358[0];
			fVec78[1] = fVec78[0];
			iRec359[1] = iRec359[0];
			fRec360[1] = fRec360[0];
			fRec361[1] = fRec361[0];
			fVec79[1] = fVec79[0];
			iRec362[1] = iRec362[0];
			fRec363[1] = fRec363[0];
			fRec364[1] = fRec364[0];
			fVec80[1] = fVec80[0];
			iRec365[1] = iRec365[0];
			fRec366[1] = fRec366[0];
			fVec81[1] = fVec81[0];
			iRec367[1] = iRec367[0];
			fRec368[1] = fRec368[0];
			fVec82[1] = fVec82[0];
			iRec369[1] = iRec369[0];
			fRec370[1] = fRec370[0];
			fVec83[1] = fVec83[0];
			iRec371[1] = iRec371[0];
			fRec372[1] = fRec372[0];
			fRec373[1] = fRec373[0];
			fVec84[1] = fVec84[0];
			iRec374[1] = iRec374[0];
			fRec375[1] = fRec375[0];
			fVec85[1] = fVec85[0];
			iRec376[1] = iRec376[0];
			fRec377[1] = fRec377[0];
			fVec86[1] = fVec86[0];
			iRec378[1] = iRec378[0];
			fRec379[1] = fRec379[0];
			fRec380[1] = fRec380[0];
			fVec87[1] = fVec87[0];
			iRec381[1] = iRec381[0];
			fRec382[1] = fRec382[0];
			fVec88[1] = fVec88[0];
			iRec383[1] = iRec383[0];
			fRec384[1] = fRec384[0];
			fVec89[1] = fVec89[0];
			iRec385[1] = iRec385[0];
			fRec386[1] = fRec386[0];
			fVec90[1] = fVec90[0];
			iRec387[1] = iRec387[0];
			fRec388[1] = fRec388[0];
			fVec91[1] = fVec91[0];
			iRec389[1] = iRec389[0];
			fRec390[1] = fRec390[0];
			fRec391[1] = fRec391[0];
			fVec92[1] = fVec92[0];
			iRec392[1] = iRec392[0];
			fRec393[1] = fRec393[0];
			fVec93[1] = fVec93[0];
			iRec394[1] = iRec394[0];
			fRec395[1] = fRec395[0];
			fVec94[1] = fVec94[0];
			iRec396[1] = iRec396[0];
			fRec397[1] = fRec397[0];
			fVec95[1] = fVec95[0];
			iRec398[1] = iRec398[0];
			fRec399[1] = fRec399[0];
			fVec96[1] = fVec96[0];
			iRec400[1] = iRec400[0];
			fRec401[1] = fRec401[0];
			fVec97[1] = fVec97[0];
			iRec402[1] = iRec402[0];
			fRec403[1] = fRec403[0];
			fVec98[1] = fVec98[0];
			iRec404[1] = iRec404[0];
			fRec405[1] = fRec405[0];
			fVec99[1] = fVec99[0];
			iRec406[1] = iRec406[0];
			fRec407[1] = fRec407[0];
			fVec100[1] = fVec100[0];
			iRec408[1] = iRec408[0];
			fRec409[1] = fRec409[0];
			fVec101[1] = fVec101[0];
			iRec410[1] = iRec410[0];
			fRec411[1] = fRec411[0];
			fVec102[1] = fVec102[0];
			iRec412[1] = iRec412[0];
			fRec413[1] = fRec413[0];
			fVec103[1] = fVec103[0];
			iRec414[1] = iRec414[0];
			fRec415[1] = fRec415[0];
			fVec104[1] = fVec104[0];
			iRec416[1] = iRec416[0];
			fRec417[1] = fRec417[0];
			fVec105[1] = fVec105[0];
			iRec418[1] = iRec418[0];
			fRec419[1] = fRec419[0];
			fVec106[1] = fVec106[0];
			iRec420[1] = iRec420[0];
			fRec421[1] = fRec421[0];
			fVec107[1] = fVec107[0];
			iRec422[1] = iRec422[0];
			fRec423[1] = fRec423[0];
			fVec108[1] = fVec108[0];
			iRec424[1] = iRec424[0];
			fRec425[1] = fRec425[0];
			fVec109[1] = fVec109[0];
			iRec426[1] = iRec426[0];
			fRec427[1] = fRec427[0];
			fVec110[1] = fVec110[0];
			iRec428[1] = iRec428[0];
			fRec429[1] = fRec429[0];
			fVec111[1] = fVec111[0];
			iRec430[1] = iRec430[0];
			fRec431[1] = fRec431[0];
			fVec112[1] = fVec112[0];
			iRec432[1] = iRec432[0];
			fRec433[1] = fRec433[0];
			fVec113[1] = fVec113[0];
			iRec434[1] = iRec434[0];
			fRec435[1] = fRec435[0];
			fVec114[1] = fVec114[0];
			iRec436[1] = iRec436[0];
			fRec437[1] = fRec437[0];
			fVec115[1] = fVec115[0];
			iRec438[1] = iRec438[0];
			fRec439[1] = fRec439[0];
			fVec116[1] = fVec116[0];
			iRec440[1] = iRec440[0];
			fRec441[1] = fRec441[0];
			fVec117[1] = fVec117[0];
			iRec442[1] = iRec442[0];
			fRec443[1] = fRec443[0];
			fVec118[1] = fVec118[0];
			iRec444[1] = iRec444[0];
			fRec445[1] = fRec445[0];
			fVec119[1] = fVec119[0];
			iRec446[1] = iRec446[0];
			fRec447[1] = fRec447[0];
			fVec120[1] = fVec120[0];
			iRec448[1] = iRec448[0];
			fRec449[1] = fRec449[0];
			fVec121[1] = fVec121[0];
			iRec450[1] = iRec450[0];
			fRec451[1] = fRec451[0];
			fVec122[1] = fVec122[0];
			iRec452[1] = iRec452[0];
			fRec453[1] = fRec453[0];
			fVec123[1] = fVec123[0];
			iRec454[1] = iRec454[0];
			fRec455[1] = fRec455[0];
			fVec124[1] = fVec124[0];
			iRec456[1] = iRec456[0];
			fRec457[1] = fRec457[0];
			fVec125[1] = fVec125[0];
			iRec458[1] = iRec458[0];
			fRec459[1] = fRec459[0];
			fVec126[1] = fVec126[0];
			iRec460[1] = iRec460[0];
			fRec461[1] = fRec461[0];
			fVec127[1] = fVec127[0];
			iRec462[1] = iRec462[0];
			fRec463[1] = fRec463[0];
			fVec128[1] = fVec128[0];
			iRec464[1] = iRec464[0];
			fRec465[1] = fRec465[0];
			fRec466[1] = fRec466[0];
			fVec129[1] = fVec129[0];
			iRec467[1] = iRec467[0];
			fRec468[1] = fRec468[0];
			fVec130[1] = fVec130[0];
			iRec469[1] = iRec469[0];
			fRec470[1] = fRec470[0];
			fVec131[1] = fVec131[0];
			iRec471[1] = iRec471[0];
			fRec472[1] = fRec472[0];
			fVec132[1] = fVec132[0];
			iRec473[1] = iRec473[0];
			fRec474[1] = fRec474[0];
			fVec133[1] = fVec133[0];
			iRec475[1] = iRec475[0];
			fRec476[1] = fRec476[0];
			fVec134[1] = fVec134[0];
			iRec477[1] = iRec477[0];
			fRec478[1] = fRec478[0];
			fVec135[1] = fVec135[0];
			iRec479[1] = iRec479[0];
			fRec480[1] = fRec480[0];
			fVec136[1] = fVec136[0];
			iRec481[1] = iRec481[0];
			fRec482[1] = fRec482[0];
			fVec137[1] = fVec137[0];
			iRec483[1] = iRec483[0];
			fRec484[1] = fRec484[0];
			fVec138[1] = fVec138[0];
			iRec485[1] = iRec485[0];
			fRec486[1] = fRec486[0];
			fVec139[1] = fVec139[0];
			iRec487[1] = iRec487[0];
			fRec488[1] = fRec488[0];
			fVec140[1] = fVec140[0];
			iRec489[1] = iRec489[0];
			fRec490[1] = fRec490[0];
			fVec141[1] = fVec141[0];
			iRec491[1] = iRec491[0];
			fRec492[1] = fRec492[0];
			fRec493[1] = fRec493[0];
			fVec142[1] = fVec142[0];
			iRec494[1] = iRec494[0];
			fRec495[1] = fRec495[0];
			fVec143[1] = fVec143[0];
			iRec496[1] = iRec496[0];
			fRec497[1] = fRec497[0];
			fVec144[1] = fVec144[0];
			iRec498[1] = iRec498[0];
			fRec499[1] = fRec499[0];
			fVec145[1] = fVec145[0];
			iRec500[1] = iRec500[0];
			fRec501[1] = fRec501[0];
			fVec146[1] = fVec146[0];
			iRec502[1] = iRec502[0];
			fRec503[1] = fRec503[0];
			fVec147[1] = fVec147[0];
			iRec504[1] = iRec504[0];
			fRec505[1] = fRec505[0];
			fVec148[1] = fVec148[0];
			iRec506[1] = iRec506[0];
			fRec507[1] = fRec507[0];
			fVec149[1] = fVec149[0];
			iRec508[1] = iRec508[0];
			fRec509[1] = fRec509[0];
			fVec150[1] = fVec150[0];
			iRec510[1] = iRec510[0];
			fRec511[1] = fRec511[0];
			fVec151[1] = fVec151[0];
			iRec512[1] = iRec512[0];
			fRec513[1] = fRec513[0];
			fVec152[1] = fVec152[0];
			iRec514[1] = iRec514[0];
			fRec515[1] = fRec515[0];
			fVec153[1] = fVec153[0];
			iRec516[1] = iRec516[0];
			fRec517[1] = fRec517[0];
			fVec154[1] = fVec154[0];
			iRec518[1] = iRec518[0];
			fRec519[1] = fRec519[0];
			fVec155[1] = fVec155[0];
			iRec520[1] = iRec520[0];
			fRec521[1] = fRec521[0];
			fVec156[1] = fVec156[0];
			iRec522[1] = iRec522[0];
			fRec523[1] = fRec523[0];
			fVec157[1] = fVec157[0];
			iRec524[1] = iRec524[0];
			fRec525[1] = fRec525[0];
			fRec526[1] = fRec526[0];
			fVec158[1] = fVec158[0];
			iRec527[1] = iRec527[0];
			fRec528[1] = fRec528[0];
			fVec159[1] = fVec159[0];
			iRec529[1] = iRec529[0];
			fRec530[1] = fRec530[0];
			fVec160[1] = fVec160[0];
			iRec531[1] = iRec531[0];
			fRec532[1] = fRec532[0];
			fRec533[1] = fRec533[0];
			fVec161[1] = fVec161[0];
			iRec534[1] = iRec534[0];
			fRec535[1] = fRec535[0];
			fVec162[1] = fVec162[0];
			iRec536[1] = iRec536[0];
			fRec537[1] = fRec537[0];
			fRec538[1] = fRec538[0];
			fVec163[1] = fVec163[0];
			iRec539[1] = iRec539[0];
			fRec540[1] = fRec540[0];
			fVec164[1] = fVec164[0];
			iRec541[1] = iRec541[0];
			fRec542[1] = fRec542[0];
			fVec165[1] = fVec165[0];
			iRec543[1] = iRec543[0];
			fRec544[1] = fRec544[0];
			fVec166[1] = fVec166[0];
			iRec545[1] = iRec545[0];
			fRec546[1] = fRec546[0];
			fVec167[1] = fVec167[0];
			iRec547[1] = iRec547[0];
			fRec548[1] = fRec548[0];
			fVec168[1] = fVec168[0];
			iRec549[1] = iRec549[0];
			fRec550[1] = fRec550[0];
			fVec169[1] = fVec169[0];
			iRec551[1] = iRec551[0];
			fRec552[1] = fRec552[0];
			fVec170[1] = fVec170[0];
			iRec553[1] = iRec553[0];
			fRec554[1] = fRec554[0];
			fVec171[1] = fVec171[0];
			iRec555[1] = iRec555[0];
			fRec556[1] = fRec556[0];
			fVec172[1] = fVec172[0];
			iRec557[1] = iRec557[0];
			fRec558[1] = fRec558[0];
			fVec173[1] = fVec173[0];
			iRec559[1] = iRec559[0];
			fRec560[1] = fRec560[0];
			fVec174[1] = fVec174[0];
			iRec561[1] = iRec561[0];
			fRec562[1] = fRec562[0];
			fVec175[1] = fVec175[0];
			iRec563[1] = iRec563[0];
			fRec564[1] = fRec564[0];
			fVec176[1] = fVec176[0];
			iRec565[1] = iRec565[0];
			fRec566[1] = fRec566[0];
			fVec177[1] = fVec177[0];
			iRec567[1] = iRec567[0];
			fRec568[1] = fRec568[0];
			fVec178[1] = fVec178[0];
			iRec569[1] = iRec569[0];
			fRec570[1] = fRec570[0];
			fVec179[1] = fVec179[0];
			iRec571[1] = iRec571[0];
			fRec572[1] = fRec572[0];
			fVec180[1] = fVec180[0];
			iRec573[1] = iRec573[0];
			fRec574[1] = fRec574[0];
			fVec181[1] = fVec181[0];
			iRec575[1] = iRec575[0];
			fRec576[1] = fRec576[0];
			fVec182[1] = fVec182[0];
			iRec577[1] = iRec577[0];
			fRec578[1] = fRec578[0];
			fVec183[1] = fVec183[0];
			iRec579[1] = iRec579[0];
			fRec580[1] = fRec580[0];
			fVec184[1] = fVec184[0];
			iRec581[1] = iRec581[0];
			fRec582[1] = fRec582[0];
			fVec185[1] = fVec185[0];
			iRec583[1] = iRec583[0];
			fRec584[1] = fRec584[0];
			fVec186[1] = fVec186[0];
			iRec585[1] = iRec585[0];
			fRec586[1] = fRec586[0];
			fVec187[1] = fVec187[0];
			iRec587[1] = iRec587[0];
			fRec588[1] = fRec588[0];
			fVec188[1] = fVec188[0];
			iRec589[1] = iRec589[0];
			fRec590[1] = fRec590[0];
			fVec189[1] = fVec189[0];
			iRec591[1] = iRec591[0];
			fRec592[1] = fRec592[0];
			fRec593[1] = fRec593[0];
			fVec190[1] = fVec190[0];
			iRec594[1] = iRec594[0];
			fRec595[1] = fRec595[0];
			fVec191[1] = fVec191[0];
			iRec596[1] = iRec596[0];
			fRec597[1] = fRec597[0];
			fVec192[1] = fVec192[0];
			iRec598[1] = iRec598[0];
			fRec599[1] = fRec599[0];
			fVec193[1] = fVec193[0];
			iRec600[1] = iRec600[0];
			fRec601[1] = fRec601[0];
			fVec194[1] = fVec194[0];
			iRec602[1] = iRec602[0];
			fRec603[1] = fRec603[0];
			fVec195[1] = fVec195[0];
			iRec604[1] = iRec604[0];
			fRec605[1] = fRec605[0];
			fVec196[1] = fVec196[0];
			iRec606[1] = iRec606[0];
			fRec607[1] = fRec607[0];
			fVec197[1] = fVec197[0];
			iRec608[1] = iRec608[0];
			fRec609[1] = fRec609[0];
			fVec198[1] = fVec198[0];
			iRec610[1] = iRec610[0];
			fRec611[1] = fRec611[0];
			fVec199[1] = fVec199[0];
			iRec612[1] = iRec612[0];
			fRec613[1] = fRec613[0];
			fVec200[1] = fVec200[0];
			iRec614[1] = iRec614[0];
			fRec615[1] = fRec615[0];
			fVec201[1] = fVec201[0];
			iRec616[1] = iRec616[0];
			fRec617[1] = fRec617[0];
			fVec202[1] = fVec202[0];
			iRec618[1] = iRec618[0];
			fRec619[1] = fRec619[0];
			fVec203[1] = fVec203[0];
			iRec620[1] = iRec620[0];
			fRec621[1] = fRec621[0];
			fVec204[1] = fVec204[0];
			iRec622[1] = iRec622[0];
			fRec623[1] = fRec623[0];
			fVec205[1] = fVec205[0];
			iRec624[1] = iRec624[0];
			fRec625[1] = fRec625[0];
			fVec206[1] = fVec206[0];
			iRec626[1] = iRec626[0];
			fRec627[1] = fRec627[0];
			fVec207[1] = fVec207[0];
			iRec628[1] = iRec628[0];
			fRec629[1] = fRec629[0];
			fVec208[1] = fVec208[0];
			iRec630[1] = iRec630[0];
			fRec631[1] = fRec631[0];
			fRec632[1] = fRec632[0];
			fVec209[1] = fVec209[0];
			iRec633[1] = iRec633[0];
			fRec634[1] = fRec634[0];
			fVec210[1] = fVec210[0];
			iRec635[1] = iRec635[0];
			fRec636[1] = fRec636[0];
			fRec637[1] = fRec637[0];
			fVec211[1] = fVec211[0];
			iRec638[1] = iRec638[0];
			fRec639[1] = fRec639[0];
			fRec640[1] = fRec640[0];
			fVec212[1] = fVec212[0];
			iRec641[1] = iRec641[0];
			fRec642[1] = fRec642[0];
			fVec213[1] = fVec213[0];
			iRec643[1] = iRec643[0];
			fRec644[1] = fRec644[0];
			fRec645[1] = fRec645[0];
			fVec214[1] = fVec214[0];
			iRec646[1] = iRec646[0];
			fRec647[1] = fRec647[0];
			fVec215[1] = fVec215[0];
			iRec648[1] = iRec648[0];
			fRec649[1] = fRec649[0];
			fVec216[1] = fVec216[0];
			iRec650[1] = iRec650[0];
			fRec651[1] = fRec651[0];
			fVec217[1] = fVec217[0];
			iRec652[1] = iRec652[0];
			fRec653[1] = fRec653[0];
			fVec218[1] = fVec218[0];
			iRec654[1] = iRec654[0];
			fRec655[1] = fRec655[0];
			fVec219[1] = fVec219[0];
			iRec656[1] = iRec656[0];
			fRec657[1] = fRec657[0];
			fVec220[1] = fVec220[0];
			iRec658[1] = iRec658[0];
			fRec659[1] = fRec659[0];
			fVec221[1] = fVec221[0];
			iRec660[1] = iRec660[0];
			fRec661[1] = fRec661[0];
			fVec222[1] = fVec222[0];
			iRec662[1] = iRec662[0];
			fRec663[1] = fRec663[0];
			fVec223[1] = fVec223[0];
			iRec664[1] = iRec664[0];
			fRec665[1] = fRec665[0];
			fVec224[1] = fVec224[0];
			iRec666[1] = iRec666[0];
			fRec667[1] = fRec667[0];
			fVec225[1] = fVec225[0];
			iRec668[1] = iRec668[0];
			fRec669[1] = fRec669[0];
			fVec226[1] = fVec226[0];
			iRec670[1] = iRec670[0];
			fRec671[1] = fRec671[0];
			fVec227[1] = fVec227[0];
			iRec672[1] = iRec672[0];
			fRec673[1] = fRec673[0];
			fVec228[1] = fVec228[0];
			iRec674[1] = iRec674[0];
			fRec675[1] = fRec675[0];
			fVec229[1] = fVec229[0];
			iRec676[1] = iRec676[0];
			fRec677[1] = fRec677[0];
			fVec230[1] = fVec230[0];
			iRec678[1] = iRec678[0];
			fRec679[1] = fRec679[0];
			fVec231[1] = fVec231[0];
			iRec680[1] = iRec680[0];
			fRec681[1] = fRec681[0];
			fVec232[1] = fVec232[0];
			iRec682[1] = iRec682[0];
			fRec683[1] = fRec683[0];
			fVec233[1] = fVec233[0];
			iRec684[1] = iRec684[0];
			fRec685[1] = fRec685[0];
			fVec234[1] = fVec234[0];
			iRec686[1] = iRec686[0];
			fRec687[1] = fRec687[0];
			fVec235[1] = fVec235[0];
			iRec688[1] = iRec688[0];
			fRec689[1] = fRec689[0];
			fVec236[1] = fVec236[0];
			iRec690[1] = iRec690[0];
			fRec691[1] = fRec691[0];
			fVec237[1] = fVec237[0];
			iRec692[1] = iRec692[0];
			fRec693[1] = fRec693[0];
			fVec238[1] = fVec238[0];
			iRec694[1] = iRec694[0];
			fRec695[1] = fRec695[0];
			fVec239[1] = fVec239[0];
			iRec696[1] = iRec696[0];
			fRec697[1] = fRec697[0];
			fVec240[1] = fVec240[0];
			iRec698[1] = iRec698[0];
			fRec699[1] = fRec699[0];
			fVec241[1] = fVec241[0];
			iRec700[1] = iRec700[0];
			fRec701[1] = fRec701[0];
			fVec242[1] = fVec242[0];
			iRec702[1] = iRec702[0];
			fRec703[1] = fRec703[0];
			fVec243[1] = fVec243[0];
			iRec704[1] = iRec704[0];
			fRec705[1] = fRec705[0];
			fVec244[1] = fVec244[0];
			iRec706[1] = iRec706[0];
			fRec707[1] = fRec707[0];
			fVec245[1] = fVec245[0];
			iRec708[1] = iRec708[0];
			fRec709[1] = fRec709[0];
			fVec246[1] = fVec246[0];
			iRec710[1] = iRec710[0];
			fRec711[1] = fRec711[0];
			fVec247[1] = fVec247[0];
			iRec712[1] = iRec712[0];
			fRec713[1] = fRec713[0];
			fVec248[1] = fVec248[0];
			iRec714[1] = iRec714[0];
			fRec715[1] = fRec715[0];
			fVec249[1] = fVec249[0];
			iRec716[1] = iRec716[0];
			fRec717[1] = fRec717[0];
			fVec250[1] = fVec250[0];
			iRec718[1] = iRec718[0];
			fRec719[1] = fRec719[0];
			fRec720[1] = fRec720[0];
			fVec251[1] = fVec251[0];
			iRec721[1] = iRec721[0];
			fRec722[1] = fRec722[0];
			fVec252[1] = fVec252[0];
			iRec723[1] = iRec723[0];
			fRec724[1] = fRec724[0];
			fVec253[1] = fVec253[0];
			iRec725[1] = iRec725[0];
			fRec726[1] = fRec726[0];
			fVec254[1] = fVec254[0];
			iRec727[1] = iRec727[0];
			fRec728[1] = fRec728[0];
			fVec255[1] = fVec255[0];
			iRec729[1] = iRec729[0];
			fRec730[1] = fRec730[0];
			fVec256[1] = fVec256[0];
			iRec731[1] = iRec731[0];
			fRec732[1] = fRec732[0];
			fVec257[1] = fVec257[0];
			iRec733[1] = iRec733[0];
			fRec734[1] = fRec734[0];
			fVec258[1] = fVec258[0];
			iRec735[1] = iRec735[0];
			fRec736[1] = fRec736[0];
			fVec259[1] = fVec259[0];
			iRec737[1] = iRec737[0];
			fRec738[1] = fRec738[0];
			fVec260[1] = fVec260[0];
			iRec739[1] = iRec739[0];
			fRec740[1] = fRec740[0];
			fVec261[1] = fVec261[0];
			iRec741[1] = iRec741[0];
			fRec742[1] = fRec742[0];
			fVec262[1] = fVec262[0];
			iRec743[1] = iRec743[0];
			fRec744[1] = fRec744[0];
			fVec263[1] = fVec263[0];
			iRec745[1] = iRec745[0];
			fRec746[1] = fRec746[0];
			fVec264[1] = fVec264[0];
			iRec747[1] = iRec747[0];
			fRec748[1] = fRec748[0];
			fVec265[1] = fVec265[0];
			iRec749[1] = iRec749[0];
			fRec750[1] = fRec750[0];
			fVec266[1] = fVec266[0];
			iRec751[1] = iRec751[0];
			fRec752[1] = fRec752[0];
			fVec267[1] = fVec267[0];
			iRec753[1] = iRec753[0];
			fRec754[1] = fRec754[0];
			fVec268[1] = fVec268[0];
			iRec755[1] = iRec755[0];
			fRec756[1] = fRec756[0];
			fVec269[1] = fVec269[0];
			iRec757[1] = iRec757[0];
			fRec758[1] = fRec758[0];
			fVec270[1] = fVec270[0];
			iRec759[1] = iRec759[0];
			fRec760[1] = fRec760[0];
			fVec271[1] = fVec271[0];
			iRec761[1] = iRec761[0];
			fRec762[1] = fRec762[0];
			fVec272[1] = fVec272[0];
			iRec763[1] = iRec763[0];
			fRec764[1] = fRec764[0];
			fVec273[1] = fVec273[0];
			iRec765[1] = iRec765[0];
			fRec766[1] = fRec766[0];
			fVec274[1] = fVec274[0];
			iRec767[1] = iRec767[0];
			fRec768[1] = fRec768[0];
			fRec769[1] = fRec769[0];
			fVec275[1] = fVec275[0];
			iRec770[1] = iRec770[0];
			fRec771[1] = fRec771[0];
			fVec276[1] = fVec276[0];
			iRec772[1] = iRec772[0];
			fRec773[1] = fRec773[0];
			fRec774[1] = fRec774[0];
			fVec277[1] = fVec277[0];
			iRec775[1] = iRec775[0];
			fRec776[1] = fRec776[0];
			fVec278[1] = fVec278[0];
			iRec777[1] = iRec777[0];
			fRec778[1] = fRec778[0];
			fRec779[1] = fRec779[0];
			fVec279[1] = fVec279[0];
			iRec780[1] = iRec780[0];
			fRec781[1] = fRec781[0];
			fRec782[1] = fRec782[0];
			fVec280[1] = fVec280[0];
			iRec783[1] = iRec783[0];
			fRec784[1] = fRec784[0];
			fVec281[1] = fVec281[0];
			iRec785[1] = iRec785[0];
			fRec786[1] = fRec786[0];
			fVec282[1] = fVec282[0];
			iRec787[1] = iRec787[0];
			fRec788[1] = fRec788[0];
			fVec283[1] = fVec283[0];
			iRec789[1] = iRec789[0];
			fRec790[1] = fRec790[0];
			fVec284[1] = fVec284[0];
			iRec791[1] = iRec791[0];
			fRec792[1] = fRec792[0];
			fVec285[1] = fVec285[0];
			iRec793[1] = iRec793[0];
			fRec794[1] = fRec794[0];
			fVec286[1] = fVec286[0];
			iRec795[1] = iRec795[0];
			fRec796[1] = fRec796[0];
			fVec287[1] = fVec287[0];
			iRec797[1] = iRec797[0];
			fRec798[1] = fRec798[0];
			fVec288[1] = fVec288[0];
			iRec799[1] = iRec799[0];
			fRec800[1] = fRec800[0];
			fVec289[1] = fVec289[0];
			iRec801[1] = iRec801[0];
			fRec802[1] = fRec802[0];
			fVec290[1] = fVec290[0];
			iRec803[1] = iRec803[0];
			fRec804[1] = fRec804[0];
			fVec291[1] = fVec291[0];
			iRec805[1] = iRec805[0];
			fRec806[1] = fRec806[0];
			fVec292[1] = fVec292[0];
			iRec807[1] = iRec807[0];
			fRec808[1] = fRec808[0];
			fVec293[1] = fVec293[0];
			iRec809[1] = iRec809[0];
			fRec810[1] = fRec810[0];
			fVec294[1] = fVec294[0];
			iRec811[1] = iRec811[0];
			fRec812[1] = fRec812[0];
			fVec295[1] = fVec295[0];
			iRec813[1] = iRec813[0];
			fRec814[1] = fRec814[0];
			fVec296[1] = fVec296[0];
			iRec815[1] = iRec815[0];
			fRec816[1] = fRec816[0];
			fVec297[1] = fVec297[0];
			iRec817[1] = iRec817[0];
			fRec818[1] = fRec818[0];
			fVec298[1] = fVec298[0];
			iRec819[1] = iRec819[0];
			fRec820[1] = fRec820[0];
			fVec299[1] = fVec299[0];
			iRec821[1] = iRec821[0];
			fRec822[1] = fRec822[0];
			fVec300[1] = fVec300[0];
			iRec823[1] = iRec823[0];
			fRec824[1] = fRec824[0];
			fVec301[1] = fVec301[0];
			iRec825[1] = iRec825[0];
			fRec826[1] = fRec826[0];
			fVec302[1] = fVec302[0];
			iRec827[1] = iRec827[0];
			fRec828[1] = fRec828[0];
			fVec303[1] = fVec303[0];
			iRec829[1] = iRec829[0];
			fRec830[1] = fRec830[0];
			fVec304[1] = fVec304[0];
			iRec831[1] = iRec831[0];
			fRec832[1] = fRec832[0];
			fVec305[1] = fVec305[0];
			iRec833[1] = iRec833[0];
			fRec834[1] = fRec834[0];
			fVec306[1] = fVec306[0];
			iRec835[1] = iRec835[0];
			fRec836[1] = fRec836[0];
			fVec307[1] = fVec307[0];
			iRec837[1] = iRec837[0];
			fRec838[1] = fRec838[0];
			fVec308[1] = fVec308[0];
			iRec839[1] = iRec839[0];
			fRec840[1] = fRec840[0];
			fVec309[1] = fVec309[0];
			iRec841[1] = iRec841[0];
			fRec842[1] = fRec842[0];
			fVec310[1] = fVec310[0];
			iRec843[1] = iRec843[0];
			fRec844[1] = fRec844[0];
			fVec311[1] = fVec311[0];
			iRec845[1] = iRec845[0];
			fRec846[1] = fRec846[0];
			fRec847[1] = fRec847[0];
			fVec312[1] = fVec312[0];
			iRec848[1] = iRec848[0];
			fRec849[1] = fRec849[0];
			fVec313[1] = fVec313[0];
			iRec850[1] = iRec850[0];
			fRec851[1] = fRec851[0];
			fVec314[1] = fVec314[0];
			iRec852[1] = iRec852[0];
			fRec853[1] = fRec853[0];
			fVec315[1] = fVec315[0];
			iRec854[1] = iRec854[0];
			fRec855[1] = fRec855[0];
			fVec316[1] = fVec316[0];
			iRec856[1] = iRec856[0];
			fRec857[1] = fRec857[0];
			fVec317[1] = fVec317[0];
			iRec858[1] = iRec858[0];
			fRec859[1] = fRec859[0];
			fVec318[1] = fVec318[0];
			iRec860[1] = iRec860[0];
			fRec861[1] = fRec861[0];
			fVec319[1] = fVec319[0];
			iRec862[1] = iRec862[0];
			fRec863[1] = fRec863[0];
			fVec320[1] = fVec320[0];
			iRec864[1] = iRec864[0];
			fRec865[1] = fRec865[0];
			fVec321[1] = fVec321[0];
			iRec866[1] = iRec866[0];
			fRec867[1] = fRec867[0];
			fVec322[1] = fVec322[0];
			iRec868[1] = iRec868[0];
			fRec869[1] = fRec869[0];
			fVec323[1] = fVec323[0];
			iRec870[1] = iRec870[0];
			fRec871[1] = fRec871[0];
			fVec324[1] = fVec324[0];
			iRec872[1] = iRec872[0];
			fRec873[1] = fRec873[0];
			fVec325[1] = fVec325[0];
			iRec874[1] = iRec874[0];
			fRec875[1] = fRec875[0];
			fVec326[1] = fVec326[0];
			iRec876[1] = iRec876[0];
			fRec877[1] = fRec877[0];
			fVec327[1] = fVec327[0];
			iRec878[1] = iRec878[0];
			fRec879[1] = fRec879[0];
			fVec328[1] = fVec328[0];
			iRec880[1] = iRec880[0];
			fRec881[1] = fRec881[0];
			fVec329[1] = fVec329[0];
			iRec882[1] = iRec882[0];
			fRec883[1] = fRec883[0];
			fVec330[1] = fVec330[0];
			iRec884[1] = iRec884[0];
			fRec885[1] = fRec885[0];
			fVec331[1] = fVec331[0];
			iRec886[1] = iRec886[0];
			fRec887[1] = fRec887[0];
			fVec332[1] = fVec332[0];
			iRec888[1] = iRec888[0];
			fRec889[1] = fRec889[0];
			fVec333[1] = fVec333[0];
			iRec890[1] = iRec890[0];
			fRec891[1] = fRec891[0];
			fVec334[1] = fVec334[0];
			iRec892[1] = iRec892[0];
			fRec893[1] = fRec893[0];
			fVec335[1] = fVec335[0];
			iRec894[1] = iRec894[0];
			fRec895[1] = fRec895[0];
			fVec336[1] = fVec336[0];
			iRec896[1] = iRec896[0];
			fRec897[1] = fRec897[0];
			fVec337[1] = fVec337[0];
			iRec898[1] = iRec898[0];
			fRec899[1] = fRec899[0];
			fVec338[1] = fVec338[0];
			iRec900[1] = iRec900[0];
			fRec901[1] = fRec901[0];
			fVec339[1] = fVec339[0];
			iRec902[1] = iRec902[0];
			fRec903[1] = fRec903[0];
			fVec340[1] = fVec340[0];
			iRec904[1] = iRec904[0];
			fRec905[1] = fRec905[0];
			fRec906[1] = fRec906[0];
			fRec907[1] = fRec907[0];
			fVec341[1] = fVec341[0];
			iRec908[1] = iRec908[0];
			fRec909[1] = fRec909[0];
			fVec342[1] = fVec342[0];
			iRec910[1] = iRec910[0];
			fRec911[1] = fRec911[0];
			fVec343[1] = fVec343[0];
			iRec912[1] = iRec912[0];
			fRec913[1] = fRec913[0];
			fVec344[1] = fVec344[0];
			iRec914[1] = iRec914[0];
			fRec915[1] = fRec915[0];
			fVec345[1] = fVec345[0];
			iRec916[1] = iRec916[0];
			fRec917[1] = fRec917[0];
			fRec918[1] = fRec918[0];
			fVec346[1] = fVec346[0];
			iRec919[1] = iRec919[0];
			fRec920[1] = fRec920[0];
			fVec347[1] = fVec347[0];
			iRec921[1] = iRec921[0];
			fRec922[1] = fRec922[0];
			fVec348[1] = fVec348[0];
			iRec923[1] = iRec923[0];
			fRec924[1] = fRec924[0];
			fVec349[1] = fVec349[0];
			iRec925[1] = iRec925[0];
			fRec926[1] = fRec926[0];
			fVec350[1] = fVec350[0];
			iRec927[1] = iRec927[0];
			fRec928[1] = fRec928[0];
			fVec351[1] = fVec351[0];
			iRec929[1] = iRec929[0];
			fRec930[1] = fRec930[0];
			fVec352[1] = fVec352[0];
			iRec931[1] = iRec931[0];
			fRec932[1] = fRec932[0];
			fVec353[1] = fVec353[0];
			iRec933[1] = iRec933[0];
			fRec934[1] = fRec934[0];
			fVec354[1] = fVec354[0];
			iRec935[1] = iRec935[0];
			fRec936[1] = fRec936[0];
			fVec355[1] = fVec355[0];
			iRec937[1] = iRec937[0];
			fRec938[1] = fRec938[0];
			fVec356[1] = fVec356[0];
			iRec939[1] = iRec939[0];
			fRec940[1] = fRec940[0];
			fVec357[1] = fVec357[0];
			iRec941[1] = iRec941[0];
			fRec942[1] = fRec942[0];
			fVec358[1] = fVec358[0];
			iRec943[1] = iRec943[0];
			fRec944[1] = fRec944[0];
			fVec359[1] = fVec359[0];
			iRec945[1] = iRec945[0];
			fRec946[1] = fRec946[0];
			fVec360[1] = fVec360[0];
			iRec947[1] = iRec947[0];
			fRec948[1] = fRec948[0];
			fVec361[1] = fVec361[0];
			iRec949[1] = iRec949[0];
			fRec950[1] = fRec950[0];
			fVec362[1] = fVec362[0];
			iRec951[1] = iRec951[0];
			fRec952[1] = fRec952[0];
			fVec363[1] = fVec363[0];
			iRec953[1] = iRec953[0];
			fRec954[1] = fRec954[0];
			fVec364[1] = fVec364[0];
			iRec955[1] = iRec955[0];
			fRec956[1] = fRec956[0];
			fVec365[1] = fVec365[0];
			iRec957[1] = iRec957[0];
			fRec958[1] = fRec958[0];
			fVec366[1] = fVec366[0];
			iRec959[1] = iRec959[0];
			fRec960[1] = fRec960[0];
			fVec367[1] = fVec367[0];
			iRec961[1] = iRec961[0];
			fRec962[1] = fRec962[0];
			fVec368[1] = fVec368[0];
			iRec963[1] = iRec963[0];
			fRec964[1] = fRec964[0];
			fVec369[1] = fVec369[0];
			iRec965[1] = iRec965[0];
			fRec966[1] = fRec966[0];
			fVec370[1] = fVec370[0];
			iRec967[1] = iRec967[0];
			fRec968[1] = fRec968[0];
			fVec371[1] = fVec371[0];
			iRec969[1] = iRec969[0];
			fRec970[1] = fRec970[0];
			fVec372[1] = fVec372[0];
			iRec971[1] = iRec971[0];
			fRec972[1] = fRec972[0];
			fRec973[1] = fRec973[0];
			fVec373[1] = fVec373[0];
			iRec974[1] = iRec974[0];
			fRec975[1] = fRec975[0];
			fVec374[1] = fVec374[0];
			iRec976[1] = iRec976[0];
			fRec977[1] = fRec977[0];
			fVec375[1] = fVec375[0];
			iRec978[1] = iRec978[0];
			fRec979[1] = fRec979[0];
			fVec376[1] = fVec376[0];
			iRec980[1] = iRec980[0];
			fRec981[1] = fRec981[0];
			fVec377[1] = fVec377[0];
			iRec982[1] = iRec982[0];
			fRec983[1] = fRec983[0];
			fVec378[1] = fVec378[0];
			iRec984[1] = iRec984[0];
			fRec985[1] = fRec985[0];
			fVec379[1] = fVec379[0];
			iRec986[1] = iRec986[0];
			fRec987[1] = fRec987[0];
			fVec380[1] = fVec380[0];
			iRec988[1] = iRec988[0];
			fRec989[1] = fRec989[0];
			fVec381[1] = fVec381[0];
			iRec990[1] = iRec990[0];
			fRec991[1] = fRec991[0];
			fVec382[1] = fVec382[0];
			iRec992[1] = iRec992[0];
			fRec993[1] = fRec993[0];
			fVec383[1] = fVec383[0];
			iRec994[1] = iRec994[0];
			fRec995[1] = fRec995[0];
			fVec384[1] = fVec384[0];
			iRec996[1] = iRec996[0];
			fRec997[1] = fRec997[0];
			fVec385[1] = fVec385[0];
			iRec998[1] = iRec998[0];
			fRec999[1] = fRec999[0];
			fVec386[1] = fVec386[0];
			iRec1000[1] = iRec1000[0];
			fRec1001[1] = fRec1001[0];
			fVec387[1] = fVec387[0];
			iRec1002[1] = iRec1002[0];
			fRec1003[1] = fRec1003[0];
			fVec388[1] = fVec388[0];
			iRec1004[1] = iRec1004[0];
			fRec1005[1] = fRec1005[0];
			fVec389[1] = fVec389[0];
			iRec1006[1] = iRec1006[0];
			fRec1007[1] = fRec1007[0];
			fVec390[1] = fVec390[0];
			iRec1008[1] = iRec1008[0];
			fRec1009[1] = fRec1009[0];
			fVec391[1] = fVec391[0];
			iRec1010[1] = iRec1010[0];
			fRec1011[1] = fRec1011[0];
			fVec392[1] = fVec392[0];
			iRec1012[1] = iRec1012[0];
			fRec1013[1] = fRec1013[0];
			fVec393[1] = fVec393[0];
			iRec1014[1] = iRec1014[0];
			fRec1015[1] = fRec1015[0];
			fVec394[1] = fVec394[0];
			iRec1016[1] = iRec1016[0];
			fRec1017[1] = fRec1017[0];
			fVec395[1] = fVec395[0];
			iRec1018[1] = iRec1018[0];
			fRec1019[1] = fRec1019[0];
			fVec396[1] = fVec396[0];
			iRec1020[1] = iRec1020[0];
			fRec1021[1] = fRec1021[0];
			fVec397[1] = fVec397[0];
			iRec1022[1] = iRec1022[0];
			fRec1023[1] = fRec1023[0];
			fVec398[1] = fVec398[0];
			iRec1024[1] = iRec1024[0];
			fRec1025[1] = fRec1025[0];
			fVec399[1] = fVec399[0];
			iRec1026[1] = iRec1026[0];
			fRec1027[1] = fRec1027[0];
			fVec400[1] = fVec400[0];
			iRec1028[1] = iRec1028[0];
			fRec1029[1] = fRec1029[0];
			fRec1030[1] = fRec1030[0];
			fVec401[1] = fVec401[0];
			iRec1031[1] = iRec1031[0];
			fRec1032[1] = fRec1032[0];
			fVec402[1] = fVec402[0];
			iRec1033[1] = iRec1033[0];
			fRec1034[1] = fRec1034[0];
			fRec1035[1] = fRec1035[0];
			fRec1036[1] = fRec1036[0];
			fVec403[1] = fVec403[0];
			iRec1037[1] = iRec1037[0];
			fRec1038[1] = fRec1038[0];
			fVec404[1] = fVec404[0];
			iRec1039[1] = iRec1039[0];
			fRec1040[1] = fRec1040[0];
			fVec405[1] = fVec405[0];
			iRec1041[1] = iRec1041[0];
			fRec1042[1] = fRec1042[0];
			fVec406[1] = fVec406[0];
			iRec1043[1] = iRec1043[0];
			fRec1044[1] = fRec1044[0];
			fRec1045[1] = fRec1045[0];
			fVec407[1] = fVec407[0];
			iRec1046[1] = iRec1046[0];
			fRec1047[1] = fRec1047[0];
			fVec408[1] = fVec408[0];
			iRec1048[1] = iRec1048[0];
			fRec1049[1] = fRec1049[0];
			fVec409[1] = fVec409[0];
			iRec1050[1] = iRec1050[0];
			fRec1051[1] = fRec1051[0];
			fVec410[1] = fVec410[0];
			iRec1052[1] = iRec1052[0];
			fRec1053[1] = fRec1053[0];
			fVec411[1] = fVec411[0];
			iRec1054[1] = iRec1054[0];
			fRec1055[1] = fRec1055[0];
			fVec412[1] = fVec412[0];
			iRec1056[1] = iRec1056[0];
			fRec1057[1] = fRec1057[0];
			fVec413[1] = fVec413[0];
			iRec1058[1] = iRec1058[0];
			fRec1059[1] = fRec1059[0];
			fRec1060[1] = fRec1060[0];
			fVec414[1] = fVec414[0];
			iRec1061[1] = iRec1061[0];
			fRec1062[1] = fRec1062[0];
			fVec415[1] = fVec415[0];
			iRec1063[1] = iRec1063[0];
			fRec1064[1] = fRec1064[0];
			fRec1065[1] = fRec1065[0];
			fVec416[1] = fVec416[0];
			iRec1066[1] = iRec1066[0];
			fRec1067[1] = fRec1067[0];
			fVec417[1] = fVec417[0];
			iRec1068[1] = iRec1068[0];
			fRec1069[1] = fRec1069[0];
			fVec418[1] = fVec418[0];
			iRec1070[1] = iRec1070[0];
			fRec1071[1] = fRec1071[0];
			fVec419[1] = fVec419[0];
			iRec1072[1] = iRec1072[0];
			fRec1073[1] = fRec1073[0];
			fVec420[1] = fVec420[0];
			iRec1074[1] = iRec1074[0];
			fRec1075[1] = fRec1075[0];
			fVec421[1] = fVec421[0];
			iRec1076[1] = iRec1076[0];
			fRec1077[1] = fRec1077[0];
			fVec422[1] = fVec422[0];
			iRec1078[1] = iRec1078[0];
			fRec1079[1] = fRec1079[0];
			fVec423[1] = fVec423[0];
			iRec1080[1] = iRec1080[0];
			fRec1081[1] = fRec1081[0];
			fVec424[1] = fVec424[0];
			iRec1082[1] = iRec1082[0];
			fRec1083[1] = fRec1083[0];
			fVec425[1] = fVec425[0];
			iRec1084[1] = iRec1084[0];
			fRec1085[1] = fRec1085[0];
			fVec426[1] = fVec426[0];
			iRec1086[1] = iRec1086[0];
			fRec1087[1] = fRec1087[0];
			fVec427[1] = fVec427[0];
			iRec1088[1] = iRec1088[0];
			fRec1089[1] = fRec1089[0];
			fVec428[1] = fVec428[0];
			iRec1090[1] = iRec1090[0];
			fRec1091[1] = fRec1091[0];
			fVec429[1] = fVec429[0];
			iRec1092[1] = iRec1092[0];
			fRec1093[1] = fRec1093[0];
			fVec430[1] = fVec430[0];
			iRec1094[1] = iRec1094[0];
			fRec1095[1] = fRec1095[0];
			fVec431[1] = fVec431[0];
			iRec1096[1] = iRec1096[0];
			fRec1097[1] = fRec1097[0];
			fVec432[1] = fVec432[0];
			iRec1098[1] = iRec1098[0];
			fRec1099[1] = fRec1099[0];
			fVec433[1] = fVec433[0];
			iRec1100[1] = iRec1100[0];
			fRec1101[1] = fRec1101[0];
			fRec1102[1] = fRec1102[0];
			fVec434[1] = fVec434[0];
			iRec1103[1] = iRec1103[0];
			fRec1104[1] = fRec1104[0];
			fVec435[1] = fVec435[0];
			iRec1105[1] = iRec1105[0];
			fRec1106[1] = fRec1106[0];
			fVec436[1] = fVec436[0];
			iRec1107[1] = iRec1107[0];
			fRec1108[1] = fRec1108[0];
			fVec437[1] = fVec437[0];
			iRec1109[1] = iRec1109[0];
			fRec1110[1] = fRec1110[0];
			fVec438[1] = fVec438[0];
			iRec1111[1] = iRec1111[0];
			fRec1112[1] = fRec1112[0];
			fVec439[1] = fVec439[0];
			iRec1113[1] = iRec1113[0];
			fRec1114[1] = fRec1114[0];
			fVec440[1] = fVec440[0];
			iRec1115[1] = iRec1115[0];
			fRec1116[1] = fRec1116[0];
			fVec441[1] = fVec441[0];
			iRec1117[1] = iRec1117[0];
			fRec1118[1] = fRec1118[0];
			fVec442[1] = fVec442[0];
			iRec1119[1] = iRec1119[0];
			fRec1120[1] = fRec1120[0];
			fVec443[1] = fVec443[0];
			iRec1121[1] = iRec1121[0];
			fRec1122[1] = fRec1122[0];
			fVec444[1] = fVec444[0];
			iRec1123[1] = iRec1123[0];
			fRec1124[1] = fRec1124[0];
			fVec445[1] = fVec445[0];
			iRec1125[1] = iRec1125[0];
			fRec1126[1] = fRec1126[0];
			fVec446[1] = fVec446[0];
			iRec1127[1] = iRec1127[0];
			fRec1128[1] = fRec1128[0];
			fVec447[1] = fVec447[0];
			iRec1129[1] = iRec1129[0];
			fRec1130[1] = fRec1130[0];
			fVec448[1] = fVec448[0];
			iRec1131[1] = iRec1131[0];
			fRec1132[1] = fRec1132[0];
			fVec449[1] = fVec449[0];
			iRec1133[1] = iRec1133[0];
			fRec1134[1] = fRec1134[0];
			fVec450[1] = fVec450[0];
			iRec1135[1] = iRec1135[0];
			fRec1136[1] = fRec1136[0];
			fVec451[1] = fVec451[0];
			iRec1137[1] = iRec1137[0];
			fRec1138[1] = fRec1138[0];
			fVec452[1] = fVec452[0];
			iRec1139[1] = iRec1139[0];
			fRec1140[1] = fRec1140[0];
			fVec453[1] = fVec453[0];
			iRec1141[1] = iRec1141[0];
			fRec1142[1] = fRec1142[0];
			fVec454[1] = fVec454[0];
			iRec1143[1] = iRec1143[0];
			fRec1144[1] = fRec1144[0];
			fVec455[1] = fVec455[0];
			iRec1145[1] = iRec1145[0];
			fRec1146[1] = fRec1146[0];
			fVec456[1] = fVec456[0];
			iRec1147[1] = iRec1147[0];
			fRec1148[1] = fRec1148[0];
			fVec457[1] = fVec457[0];
			iRec1149[1] = iRec1149[0];
			fRec1150[1] = fRec1150[0];
			fVec458[1] = fVec458[0];
			iRec1151[1] = iRec1151[0];
			fRec1152[1] = fRec1152[0];
			fVec459[1] = fVec459[0];
			iRec1153[1] = iRec1153[0];
			fRec1154[1] = fRec1154[0];
			fVec460[1] = fVec460[0];
			iRec1155[1] = iRec1155[0];
			fRec1156[1] = fRec1156[0];
			fVec461[1] = fVec461[0];
			iRec1157[1] = iRec1157[0];
			fRec1158[1] = fRec1158[0];
			fVec462[1] = fVec462[0];
			iRec1159[1] = iRec1159[0];
			fRec1160[1] = fRec1160[0];
			fVec463[1] = fVec463[0];
			iRec1161[1] = iRec1161[0];
			fRec1162[1] = fRec1162[0];
			fVec464[1] = fVec464[0];
			iRec1163[1] = iRec1163[0];
			fRec1164[1] = fRec1164[0];
			fVec465[1] = fVec465[0];
			iRec1165[1] = iRec1165[0];
			fRec1166[1] = fRec1166[0];
			fVec466[1] = fVec466[0];
			iRec1167[1] = iRec1167[0];
			fRec1168[1] = fRec1168[0];
			fVec467[1] = fVec467[0];
			iRec1169[1] = iRec1169[0];
			fRec1170[1] = fRec1170[0];
			fVec468[1] = fVec468[0];
			iRec1171[1] = iRec1171[0];
			fRec1172[1] = fRec1172[0];
			fVec469[1] = fVec469[0];
			iRec1173[1] = iRec1173[0];
			fRec1174[1] = fRec1174[0];
			fVec470[1] = fVec470[0];
			iRec1175[1] = iRec1175[0];
			fRec1176[1] = fRec1176[0];
			fVec471[1] = fVec471[0];
			iRec1177[1] = iRec1177[0];
			fRec1178[1] = fRec1178[0];
			fVec472[1] = fVec472[0];
			iRec1179[1] = iRec1179[0];
			fRec1180[1] = fRec1180[0];
			fVec473[1] = fVec473[0];
			iRec1181[1] = iRec1181[0];
			fRec1182[1] = fRec1182[0];
			fVec474[1] = fVec474[0];
			iRec1183[1] = iRec1183[0];
			fRec1184[1] = fRec1184[0];
			fVec475[1] = fVec475[0];
			iRec1185[1] = iRec1185[0];
			fRec1186[1] = fRec1186[0];
			fVec476[1] = fVec476[0];
			iRec1187[1] = iRec1187[0];
			fRec1188[1] = fRec1188[0];
			fVec477[1] = fVec477[0];
			iRec1189[1] = iRec1189[0];
			fRec1190[1] = fRec1190[0];
			fVec478[1] = fVec478[0];
			iRec1191[1] = iRec1191[0];
			fRec1192[1] = fRec1192[0];
			fVec479[1] = fVec479[0];
			iRec1193[1] = iRec1193[0];
			fRec1194[1] = fRec1194[0];
			fVec480[1] = fVec480[0];
			iRec1195[1] = iRec1195[0];
			fRec1196[1] = fRec1196[0];
			fVec481[1] = fVec481[0];
			iRec1197[1] = iRec1197[0];
			fRec1198[1] = fRec1198[0];
			fVec482[1] = fVec482[0];
			iRec1199[1] = iRec1199[0];
			fRec1200[1] = fRec1200[0];
			fVec483[1] = fVec483[0];
			iRec1201[1] = iRec1201[0];
			fRec1202[1] = fRec1202[0];
			fVec484[1] = fVec484[0];
			iRec1203[1] = iRec1203[0];
			fRec1204[1] = fRec1204[0];
			fVec485[1] = fVec485[0];
			iRec1205[1] = iRec1205[0];
			fRec1206[1] = fRec1206[0];
			fVec486[1] = fVec486[0];
			iRec1207[1] = iRec1207[0];
			fRec1208[1] = fRec1208[0];
			fVec487[1] = fVec487[0];
			iRec1209[1] = iRec1209[0];
			fRec1210[1] = fRec1210[0];
			fVec488[1] = fVec488[0];
			iRec1211[1] = iRec1211[0];
			fRec1212[1] = fRec1212[0];
			fVec489[1] = fVec489[0];
			iRec1213[1] = iRec1213[0];
			fRec1214[1] = fRec1214[0];
			fVec490[1] = fVec490[0];
			iRec1215[1] = iRec1215[0];
			fRec1216[1] = fRec1216[0];
			fVec491[1] = fVec491[0];
			iRec1217[1] = iRec1217[0];
			fRec1218[1] = fRec1218[0];
			fVec492[1] = fVec492[0];
			iRec1219[1] = iRec1219[0];
			fRec1220[1] = fRec1220[0];
			fVec493[1] = fVec493[0];
			iRec1221[1] = iRec1221[0];
			fRec1222[1] = fRec1222[0];
			fVec494[1] = fVec494[0];
			iRec1223[1] = iRec1223[0];
			fRec1224[1] = fRec1224[0];
			fRec1225[1] = fRec1225[0];
			fVec495[1] = fVec495[0];
			iRec1226[1] = iRec1226[0];
			fRec1227[1] = fRec1227[0];
			fVec496[1] = fVec496[0];
			iRec1228[1] = iRec1228[0];
			fRec1229[1] = fRec1229[0];
			fVec497[1] = fVec497[0];
			iRec1230[1] = iRec1230[0];
			fRec1231[1] = fRec1231[0];
			fVec498[1] = fVec498[0];
			iRec1232[1] = iRec1232[0];
			fRec1233[1] = fRec1233[0];
			fVec499[1] = fVec499[0];
			iRec1234[1] = iRec1234[0];
			fRec1235[1] = fRec1235[0];
			fVec500[1] = fVec500[0];
			iRec1236[1] = iRec1236[0];
			fRec1237[1] = fRec1237[0];
			fVec501[1] = fVec501[0];
			iRec1238[1] = iRec1238[0];
			fRec1239[1] = fRec1239[0];
			fVec502[1] = fVec502[0];
			iRec1240[1] = iRec1240[0];
			fRec1241[1] = fRec1241[0];
			fVec503[1] = fVec503[0];
			iRec1242[1] = iRec1242[0];
			fRec1243[1] = fRec1243[0];
			fVec504[1] = fVec504[0];
			iRec1244[1] = iRec1244[0];
			fRec1245[1] = fRec1245[0];
			fVec505[1] = fVec505[0];
			iRec1246[1] = iRec1246[0];
			fRec1247[1] = fRec1247[0];
			fVec506[1] = fVec506[0];
			iRec1248[1] = iRec1248[0];
			fRec1249[1] = fRec1249[0];
			fVec507[1] = fVec507[0];
			iRec1250[1] = iRec1250[0];
			fRec1251[1] = fRec1251[0];
			fVec508[1] = fVec508[0];
			iRec1252[1] = iRec1252[0];
			fRec1253[1] = fRec1253[0];
			fVec509[1] = fVec509[0];
			iRec1254[1] = iRec1254[0];
			fRec1255[1] = fRec1255[0];
			fVec510[1] = fVec510[0];
			iRec1256[1] = iRec1256[0];
			fRec1257[1] = fRec1257[0];
			fVec511[1] = fVec511[0];
			iRec1258[1] = iRec1258[0];
			fRec1259[1] = fRec1259[0];
			fVec512[1] = fVec512[0];
			iRec1260[1] = iRec1260[0];
			fRec1261[1] = fRec1261[0];
			fVec513[1] = fVec513[0];
			iRec1262[1] = iRec1262[0];
			fRec1263[1] = fRec1263[0];
			fVec514[1] = fVec514[0];
			iRec1264[1] = iRec1264[0];
			fRec1265[1] = fRec1265[0];
			fVec515[1] = fVec515[0];
			iRec1266[1] = iRec1266[0];
			fRec1267[1] = fRec1267[0];
			fVec516[1] = fVec516[0];
			iRec1268[1] = iRec1268[0];
			fRec1269[1] = fRec1269[0];
			fRec1270[1] = fRec1270[0];
			fVec517[1] = fVec517[0];
			iRec1271[1] = iRec1271[0];
			fRec1272[1] = fRec1272[0];
			fVec518[1] = fVec518[0];
			iRec1273[1] = iRec1273[0];
			fRec1274[1] = fRec1274[0];
			fVec519[1] = fVec519[0];
			iRec1275[1] = iRec1275[0];
			fRec1276[1] = fRec1276[0];
			fVec520[1] = fVec520[0];
			iRec1277[1] = iRec1277[0];
			fRec1278[1] = fRec1278[0];
			fVec521[1] = fVec521[0];
			iRec1279[1] = iRec1279[0];
			fRec1280[1] = fRec1280[0];
			fVec522[1] = fVec522[0];
			iRec1281[1] = iRec1281[0];
			fRec1282[1] = fRec1282[0];
			fVec523[1] = fVec523[0];
			iRec1283[1] = iRec1283[0];
			fRec1284[1] = fRec1284[0];
			fVec524[1] = fVec524[0];
			iRec1285[1] = iRec1285[0];
			fRec1286[1] = fRec1286[0];
			fVec525[1] = fVec525[0];
			iRec1287[1] = iRec1287[0];
			fRec1288[1] = fRec1288[0];
			fVec526[1] = fVec526[0];
			iRec1289[1] = iRec1289[0];
			fRec1290[1] = fRec1290[0];
			fVec527[1] = fVec527[0];
			iRec1291[1] = iRec1291[0];
			fRec1292[1] = fRec1292[0];
			fVec528[1] = fVec528[0];
			iRec1293[1] = iRec1293[0];
			fRec1294[1] = fRec1294[0];
			fVec529[1] = fVec529[0];
			iRec1295[1] = iRec1295[0];
			fRec1296[1] = fRec1296[0];
			fVec530[1] = fVec530[0];
			iRec1297[1] = iRec1297[0];
			fRec1298[1] = fRec1298[0];
			fVec531[1] = fVec531[0];
			iRec1299[1] = iRec1299[0];
			fRec1300[1] = fRec1300[0];
			fVec532[1] = fVec532[0];
			iRec1301[1] = iRec1301[0];
			fRec1302[1] = fRec1302[0];
			fVec533[1] = fVec533[0];
			iRec1303[1] = iRec1303[0];
			fRec1304[1] = fRec1304[0];
			fVec534[1] = fVec534[0];
			iRec1305[1] = iRec1305[0];
			fRec1306[1] = fRec1306[0];
			fVec535[1] = fVec535[0];
			iRec1307[1] = iRec1307[0];
			fRec1308[1] = fRec1308[0];
			fVec536[1] = fVec536[0];
			iRec1309[1] = iRec1309[0];
			fRec1310[1] = fRec1310[0];
			fVec537[1] = fVec537[0];
			iRec1311[1] = iRec1311[0];
			fRec1312[1] = fRec1312[0];
			fVec538[1] = fVec538[0];
			iRec1313[1] = iRec1313[0];
			fRec1314[1] = fRec1314[0];
			fVec539[1] = fVec539[0];
			iRec1315[1] = iRec1315[0];
			fRec1316[1] = fRec1316[0];
			fVec540[1] = fVec540[0];
			iRec1317[1] = iRec1317[0];
			fRec1318[1] = fRec1318[0];
			fVec541[1] = fVec541[0];
			iRec1319[1] = iRec1319[0];
			fRec1320[1] = fRec1320[0];
			fVec542[1] = fVec542[0];
			iRec1321[1] = iRec1321[0];
			fRec1322[1] = fRec1322[0];
			fVec543[1] = fVec543[0];
			iRec1323[1] = iRec1323[0];
			fRec1324[1] = fRec1324[0];
			fVec544[1] = fVec544[0];
			iRec1325[1] = iRec1325[0];
			fRec1326[1] = fRec1326[0];
			fVec545[1] = fVec545[0];
			iRec1327[1] = iRec1327[0];
			fRec1328[1] = fRec1328[0];
			fVec546[1] = fVec546[0];
			iRec1329[1] = iRec1329[0];
			fRec1330[1] = fRec1330[0];
			fVec547[1] = fVec547[0];
			iRec1331[1] = iRec1331[0];
			fRec1332[1] = fRec1332[0];
			fVec548[1] = fVec548[0];
			iRec1333[1] = iRec1333[0];
			fRec1334[1] = fRec1334[0];
			fVec549[1] = fVec549[0];
			iRec1335[1] = iRec1335[0];
			fRec1336[1] = fRec1336[0];
			fVec550[1] = fVec550[0];
			iRec1337[1] = iRec1337[0];
			fRec1338[1] = fRec1338[0];
			fVec551[1] = fVec551[0];
			iRec1339[1] = iRec1339[0];
			fRec1340[1] = fRec1340[0];
			fVec552[1] = fVec552[0];
			iRec1341[1] = iRec1341[0];
			fRec1342[1] = fRec1342[0];
			fVec553[1] = fVec553[0];
			iRec1343[1] = iRec1343[0];
			fRec1344[1] = fRec1344[0];
			fVec554[1] = fVec554[0];
			iRec1345[1] = iRec1345[0];
			fRec1346[1] = fRec1346[0];
			fVec555[1] = fVec555[0];
			iRec1347[1] = iRec1347[0];
			fRec1348[1] = fRec1348[0];
			fRec1349[1] = fRec1349[0];
			fRec1350[1] = fRec1350[0];
			fRec1351[1] = fRec1351[0];
			fRec1352[1] = fRec1352[0];
			iVec556[1] = iVec556[0];
			fRec1353[1] = fRec1353[0];
			fRec1354[1] = fRec1354[0];
			fRec1355[1] = fRec1355[0];
			fRec1356[1] = fRec1356[0];
			fRec1357[1] = fRec1357[0];
			fRec1358[1] = fRec1358[0];
			fRec1359[1] = fRec1359[0];
			fRec1360[1] = fRec1360[0];
			fRec1361[1] = fRec1361[0];
			fRec1362[1] = fRec1362[0];
			fRec1363[1] = fRec1363[0];
			fRec1364[1] = fRec1364[0];
			fRec1365[1] = fRec1365[0];
			fRec1368[1] = fRec1368[0];
			fVec558[1] = fVec558[0];
			fRec1367[1] = fRec1367[0];
			fRec1369[1] = fRec1369[0];
			fVec559[1] = fVec559[0];
			fRec1366[1] = fRec1366[0];
			fVec560[1] = fVec560[0];
			iRec1370[1] = iRec1370[0];
			fRec1371[1] = fRec1371[0];
			fVec561[1] = fVec561[0];
			iRec1372[1] = iRec1372[0];
			fRec1373[1] = fRec1373[0];
			fVec562[1] = fVec562[0];
			iRec1374[1] = iRec1374[0];
			fRec1375[1] = fRec1375[0];
			fVec563[1] = fVec563[0];
			iRec1376[1] = iRec1376[0];
			fRec1377[1] = fRec1377[0];
			fVec564[1] = fVec564[0];
			iRec1378[1] = iRec1378[0];
			fRec1379[1] = fRec1379[0];
			fVec565[1] = fVec565[0];
			iRec1380[1] = iRec1380[0];
			fRec1381[1] = fRec1381[0];
			fVec566[1] = fVec566[0];
			iRec1382[1] = iRec1382[0];
			fRec1383[1] = fRec1383[0];
			fVec567[1] = fVec567[0];
			iRec1384[1] = iRec1384[0];
			fRec1385[1] = fRec1385[0];
			fVec568[1] = fVec568[0];
			iRec1386[1] = iRec1386[0];
			fRec1387[1] = fRec1387[0];
			fVec569[1] = fVec569[0];
			iRec1388[1] = iRec1388[0];
			fRec1389[1] = fRec1389[0];
			fVec570[1] = fVec570[0];
			iRec1390[1] = iRec1390[0];
			fRec1391[1] = fRec1391[0];
			fVec571[1] = fVec571[0];
			iRec1392[1] = iRec1392[0];
			fRec1393[1] = fRec1393[0];
			fVec572[1] = fVec572[0];
			iRec1394[1] = iRec1394[0];
			fRec1395[1] = fRec1395[0];
			fVec573[1] = fVec573[0];
			iRec1396[1] = iRec1396[0];
			fRec1397[1] = fRec1397[0];
			fVec574[1] = fVec574[0];
			iRec1398[1] = iRec1398[0];
			fRec1399[1] = fRec1399[0];
			fVec575[1] = fVec575[0];
			iRec1400[1] = iRec1400[0];
			fRec1401[1] = fRec1401[0];
			fVec576[1] = fVec576[0];
			iRec1402[1] = iRec1402[0];
			fRec1403[1] = fRec1403[0];
			fVec577[1] = fVec577[0];
			iRec1404[1] = iRec1404[0];
			fRec1405[1] = fRec1405[0];
			fVec578[1] = fVec578[0];
			iRec1406[1] = iRec1406[0];
			fRec1407[1] = fRec1407[0];
			fVec579[1] = fVec579[0];
			iRec1408[1] = iRec1408[0];
			fRec1409[1] = fRec1409[0];
			fVec580[1] = fVec580[0];
			iRec1410[1] = iRec1410[0];
			fRec1411[1] = fRec1411[0];
			fVec581[1] = fVec581[0];
			fVec582[1] = fVec582[0];
			fRec16[1] = fRec16[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec1412[1] = fRec1412[0];
			fRec1413[1] = fRec1413[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec1416[1] = fRec1416[0];
			fRec1415[1] = fRec1415[0];
			fRec1425[1] = fRec1425[0];
			fRec1426[1] = fRec1426[0];
			fRec1421[1] = fRec1421[0];
			fRec1422[1] = fRec1422[0];
			fRec1417[1] = fRec1417[0];
			fRec1418[1] = fRec1418[0];
			fRec1428[1] = fRec1428[0];
			fRec1429[1] = fRec1429[0];
			fRec1431[1] = fRec1431[0];
			fRec1432[1] = fRec1432[0];
			fRec1434[1] = fRec1434[0];
			fRec1435[1] = fRec1435[0];
			fRec1437[1] = fRec1437[0];
			fRec1438[1] = fRec1438[0];
			fRec1439[1] = fRec1439[0];
			fRec1441[1] = fRec1441[0];
			fRec1442[1] = fRec1442[0];
			fRec1444[1] = fRec1444[0];
			fRec1445[1] = fRec1445[0];
		}
	}

};

struct Ev { double t; std::string label; double v; };

static void wavWrite(const char* path, const std::vector<float>& d, int sr) {
    FILE* f = fopen(path, "wb");
    uint32_t dataBytes = d.size() * 4, riff = 36 + dataBytes, fmt = 16, sr32 = sr, br = sr * 8;
    uint16_t fmtTag = 3, ch = 2, ba = 8, bits = 32;
    fwrite("RIFF", 1, 4, f); fwrite(&riff, 4, 1, f); fwrite("WAVEfmt ", 1, 8, f);
    fwrite(&fmt, 4, 1, f); fwrite(&fmtTag, 2, 1, f); fwrite(&ch, 2, 1, f);
    fwrite(&sr32, 4, 1, f); fwrite(&br, 4, 1, f); fwrite(&ba, 2, 1, f); fwrite(&bits, 2, 1, f);
    fwrite("data", 1, 4, f); fwrite(&dataBytes, 4, 1, f); fwrite(d.data(), 4, d.size(), f);
    fclose(f);
}

int main(int argc, char** argv) {
    if (argc < 5) { fprintf(stderr, "usage: render events.txt out.wav seconds sr\n"); return 1; }
    double secs = atof(argv[3]); int sr = atoi(argv[4]);
    std::vector<Ev> ev; std::ifstream in(argv[1]); std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        // format: time|label|value
        std::stringstream ss(line); std::string a, b, c;
        std::getline(ss, a, '|'); std::getline(ss, b, '|'); std::getline(ss, c, '|');
        ev.push_back({atof(a.c_str()), b, atof(c.c_str())});
    }
    std::sort(ev.begin(), ev.end(), [](const Ev& x, const Ev& y){ return x.t < y.t; });
    Tonewheel dsp; MapUI ui; dsp.buildUserInterface(&ui); dsp.init(sr);
    const char* bs = getenv("TW_BLOCK"); const int B = bs ? atoi(bs) : 32;
    const char* tp = getenv("TW_TIMES"); std::vector<double> times; long N = (long)(secs * sr);
    std::vector<double> l(B), r(B); double* outs[2] = { l.data(), r.data() };
    std::vector<float> out; out.reserve(N * 2); size_t ei = 0;
    for (long n = 0; n < N; n += B) {
        while (ei < ev.size() && ev[ei].t * sr <= n) {
            ui.setParamValue(ev[ei].label, ev[ei].v); ei++;
        }
        int b = (int)std::min<long>(B, N - n);
        auto t0 = std::chrono::steady_clock::now();
        dsp.compute(b, nullptr, outs);
        if (tp) times.push_back(std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count());
        for (int i = 0; i < b; i++) { out.push_back((float)l[i]); out.push_back((float)r[i]); }
    }
    wavWrite(argv[2], out, sr);
    if (tp) { FILE* f = fopen(tp, "w"); for (double t : times) fprintf(f, "%.9f\n", t); fclose(f); }
    return 0;
}

#endif
