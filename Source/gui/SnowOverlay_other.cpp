#include "SnowOverlay.h"

// Outside macOS there is no overlay (yet): the editor draws Snowfall itself. Windows' renderer has
// no CoreAnimation backing store to copy; whether the lightweight path is fast enough there is for
// the Windows test (docs/status.md, F-21).
namespace sundayorgan::ui
{
struct SnowOverlay::Impl {};
SnowOverlay::SnowOverlay() = default;
SnowOverlay::~SnowOverlay() = default;
bool SnowOverlay::attach (juce::Component&) { return false; }
void SnowOverlay::detach() {}
bool SnowOverlay::attached() const noexcept { return false; }
void SnowOverlay::show (const Snowfall&, float, juce::Rectangle<int>, juce::Rectangle<float>) {}
void SnowOverlay::hide() {}
bool SnowOverlay::renderOver (juce::Image&) const { return false; }
} // namespace sundayorgan::ui
