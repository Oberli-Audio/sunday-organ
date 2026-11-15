#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <array>
#include <vector>

namespace sundayorgan::ui
{
/*  Snow over the panel while a Jingle Jam preset is loaded (Björn, 2026-11-15: "add snow on the gui or
    something other really fancy creative"). A seasonal layer, not the hero: bone flakes in three
    depths (small, faint and fast behind; large six-armed crystals slow in front), drifting on their
    own sway; the Leslie blows them - with the horn at speed the flakes near the rotors whirl around
    them and the rest drift right. Flakes settle: a drift grows along the bottom edge and a thin line
    of snow on the ledge between the two rows. On leaving the section the flakes fade out in 0.6 s and
    the drifts melt in about a second; then idle() is true and the editor hides the layer (F-20: snow
    that kept falling for up to 40 s after the section was left, over an editor too slow to use).

    Never in the way: no mouse clicks (they reach the controls beneath), not accessible, below the
    preset drawer and hidden behind About; it repaints only the flakes' own rectangles and the drifts
    when they change, skips every flake outside the area being painted, and costs nothing once
    everything has melted. What lies beneath it draws from cached images (PluginEditor.cpp), so a
    moving flake is a copy of pixels there, not a redraw. Seeded, so the snapshot tool
    renders the same frame every time. The editor's menu turns it off (a machine-local preference,
    the reduce-motion option of plugin-ui-bob audio-plugins.md 11). */
class Snowfall final : public juce::Component
{
public:
    Snowfall();

    /** One frame of the editor's 30 Hz timer. `falling`: a Jingle Jam preset is loaded and the snow is
        on; `wind` 0-1: the horn's speed against fast; `rotor` the horn's centre, where the snow whirls. */
    void step (bool falling, float wind, juce::Point<float> rotor);

    /** The ledge snow settles on: a hairline at `y` from `x0` to `x1` (editor coordinates). */
    void setLedge (float y, float x0, float x1) { ledgeY = y; ledgeX0 = x0; ledgeX1 = x1; }

    /** How the snow asks to be repainted. JUCE's macOS renderer paints every dirty rectangle in a
        pass of its own over the whole component tree, and keeps the ones it could not present yet
        for the next frame; a rectangle per flake was about a hundred passes a frame, backing up
        (F-21). So each frame's flakes are gathered into at most five horizontal bands. True asks
        per flake again - only the benchmark sets it, to show the difference. */
    static inline bool perFlakeRepaints = false;

    /** The rectangles the last step() asked to repaint (the snapshot tool's benchmark replays them). */
    const std::vector<juce::Rectangle<int>>& lastRepaints() const noexcept { return requested; }

    /** Repaints this layer asked of the editor so far (only while it is visible: the lightweight path). */
    int editorRepaints() const noexcept { return repaintsIssued; }

    /** True when nothing is falling or lying (nothing to draw). */
    bool idle() const noexcept { return flakes.empty() && ! anySnowOnGround; }

    void paint (juce::Graphics&) override;

private:
    friend class SnowOverlay;                        // reads the flakes and drifts to draw them on its own layer

    struct Flake
    {
        float x, y, r, fall, phase, rate, sway, angle, spin, alpha;
        bool crystal, sticks;
        juce::Rectangle<int> bounds() const;
    };

    static constexpr int kMaxFlakes = 80, kBin = 4;
    static constexpr float kDt = 1.0f / 30.0f, kGroundMax = 9.0f, kLedgeMax = 2.5f;
    std::vector<Flake> flakes;
    std::array<float, 1280 / kBin + 1> ground {};   // drift height per 4 px column, along the bottom edge
    std::array<float, 1280 / kBin + 1> ledge {};
    std::array<float, 1280 / kBin + 1> groundCap {};  // uneven, so the drift lies in heaps
    juce::Random random { 0x5101 };
    float spawnDebt = 0.0f, fade = 0.0f, ledgeY = -1.0f, ledgeX0 = 0.0f, ledgeX1 = 0.0f;
    bool anySnowOnGround = false;
    int driftFrames = 0;
    int driftVersion = 0;                            // counts drift changes (the overlay rebuilds its paths)
    int repaintsIssued = 0;                          // repaints that reached the editor (F-21's test)

    static constexpr int kBand = 96;                 // five bands over the 474 px panel
    std::vector<juce::Rectangle<int>> marks, requested;
    void mark (juce::Rectangle<int> r) { marks.push_back (r); }
    void flush();

    Flake spawn (float y);
    void settle (std::array<float, 1280 / kBin + 1>& heights, float x, float amount, const std::array<float, 1280 / kBin + 1>* caps, float cap);
    static juce::Path driftPath (const std::array<float, 1280 / kBin + 1>& heights, float baseline, float x0, float x1);
};
} // namespace sundayorgan::ui
