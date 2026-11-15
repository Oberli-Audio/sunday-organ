#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <memory>

namespace sundayorgan::ui
{
class Snowfall;

/*  The snow on a native layer of its own (F-21). On macOS the editor is one CoreAnimation layer: any
    part of it marked dirty is redrawn, and the layer's backing store is copied and converted on every
    update, so snow drawn into the editor made the whole panel's drawing path run 30 times a second
    (128 % CPU under Rosetta in the Standalone against 47 % without snow). Here the snow is a
    click-through subview above the editor with one CALayer per flake and a shape layer per drift;
    a frame only moves layers, the GPU composites them, and the editor beneath is never redrawn for
    a flake.

    macOS only; elsewhere attach() returns false and the editor draws Snowfall itself (the
    lightweight path, also the snapshot tool's, which has no window). `enabled` false keeps the
    lightweight path on macOS too - only the snapshot tool's --no-overlay sets it, to show the defect. */
class SnowOverlay
{
public:
    static inline bool enabled = true;

    SnowOverlay();
    ~SnowOverlay();

    /** Adds the overlay above `editor` in its native view; false when there is none or no overlay here. */
    bool attach (juce::Component& editor);
    void detach();
    bool attached() const noexcept;

    /** One frame: the snow as `snow` simulates it, in its coordinates times `scale`, placed at
        `frameInPeer` (the editor's bounds in its peer); nothing drawn inside `exclude` (the open
        drawer), in the snow's coordinates. */
    void show (const Snowfall& snow, float scale, juce::Rectangle<int> frameInPeer, juce::Rectangle<float> exclude);
    void hide();

    /** Draws the overlay's layers over `image` (the editor's own snapshot, same size): what the
        player sees, for the snapshot tool's --onscreen render. False when not attached. */
    bool renderOver (juce::Image& image) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
} // namespace sundayorgan::ui
