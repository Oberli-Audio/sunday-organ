#include "Snowfall.h"

#include "OberliLookAndFeel.h"

#include <cmath>

namespace sundayorgan::ui
{
Snowfall::Snowfall()
{
    setInterceptsMouseClicks (false, false);
    setAccessible (false);
    setOpaque (false);
    flakes.reserve (kMaxFlakes);
    marks.reserve (2 * kMaxFlakes + 4);
    requested.reserve (2 * kMaxFlakes + 4);
    // heaps: a few slow waves, 45-100 % of the drift's height
    const float p1 = random.nextFloat() * 6.3f, p2 = random.nextFloat() * 6.3f;
    for (size_t i = 0; i < groundCap.size(); ++i)
    {
        const float x = (float) i / (float) groundCap.size();
        groundCap[i] = kGroundMax * (0.725f + 0.17f * std::sin (11.0f * x + p1) + 0.105f * std::sin (29.0f * x + p2));
    }
}

juce::Rectangle<int> Snowfall::Flake::bounds() const
{
    const float e = r + 2.0f;
    return juce::Rectangle<float> (x - e, y - e, 2.0f * e, 2.0f * e).getSmallestIntegerContainer();
}

Snowfall::Flake Snowfall::spawn (float y)
{
    Flake f {};
    const float depth = random.nextFloat();                      // 0 behind, 1 in front
    f.crystal = depth > 0.88f;
    f.r = f.crystal ? 3.6f + 2.2f * random.nextFloat() : 0.7f + 2.0f * depth;
    f.fall = f.crystal ? 11.0f + 6.0f * random.nextFloat() : 13.0f + 26.0f * depth;   // px/s: the near small flakes fall fastest
    f.alpha = f.crystal ? 0.75f : 0.28f + 0.55f * depth;
    f.x = random.nextFloat() * (float) getWidth();
    f.y = y;
    f.phase = random.nextFloat() * juce::MathConstants<float>::twoPi;
    f.rate = 0.4f + 0.9f * random.nextFloat();                   // sway, rad/s
    f.sway = 4.0f + 10.0f * random.nextFloat();                  // px/s
    f.angle = random.nextFloat() * juce::MathConstants<float>::pi;
    f.spin = (random.nextFloat() - 0.5f) * 0.8f;
    f.sticks = random.nextFloat() < 0.35f;                       // lands on the ledge if it meets it
    return f;
}

void Snowfall::settle (std::array<float, 1280 / kBin + 1>& heights, float x, float amount, const std::array<float, 1280 / kBin + 1>* caps, float cap)
{
    const int c = juce::jlimit (0, (int) heights.size() - 1, (int) (x / (float) kBin));
    for (int d = -4; d <= 4; ++d)                                // a soft heap, not a column
    {
        const int i = c + d;
        if (i < 0 || i >= (int) heights.size()) continue;
        const float w = std::exp (-0.5f * (float) (d * d) / 4.0f);
        heights[(size_t) i] = std::min (caps != nullptr ? (*caps)[(size_t) i] : cap, heights[(size_t) i] + amount * w);
    }
    anySnowOnGround = true;
}

void Snowfall::step (bool falling, float wind, juce::Point<float> rotor)
{
    if (! falling && idle()) return;
    const float w = (float) getWidth(), h = (float) getHeight();
    // in over 0.4 s, out over 0.6 s; gone, the flakes are dropped at once
    fade = falling ? std::min (1.0f, fade + kDt / 0.4f) : fade - kDt / 0.6f;
    if (! falling && fade <= 0.0f && ! flakes.empty())
    {
        for (const auto& f : flakes) mark (f.bounds());
        flakes.clear();
    }
    fade = std::max (0.0f, fade);
    wind = juce::jlimit (0.0f, 1.0f, wind);

    // snow begins with a few flakes, not a curtain
    if (falling && (int) flakes.size() < kMaxFlakes)
    {
        spawnDebt += 2.2f;
        while (spawnDebt >= 1.0f && (int) flakes.size() < kMaxFlakes)
        {
            flakes.push_back (spawn (-8.0f - 30.0f * random.nextFloat()));
            spawnDebt -= 1.0f;
        }
    }

    bool groundChanged = false, ledgeChanged = false;
    for (size_t i = 0; i < flakes.size();)
    {
        auto& f = flakes[i];
        mark (f.bounds());
        f.phase += f.rate * kDt;
        float vx = std::sin (f.phase) * f.sway + 22.0f * wind;   // the Leslie's draught
        float vy = f.fall;
        const auto d = juce::Point<float> (f.x, f.y) - rotor;   // near the horn the snow whirls around it
        const float dist = d.getDistanceFromOrigin();
        if (wind > 0.01f && dist < 190.0f && dist > 1.0f)
        {
            const float s = wind * 120.0f * (1.0f - dist / 190.0f);
            vx += -d.y / dist * s;
            vy += d.x / dist * s * 0.6f;
        }
        f.x += vx * kDt;
        f.y += vy * kDt;
        f.angle += f.spin * kDt * (1.0f + 4.0f * wind);
        if (f.x < -10.0f) f.x += w + 20.0f;
        if (f.x > w + 10.0f) f.x -= w + 20.0f;

        bool gone = false;
        const int bin = juce::jlimit (0, (int) ground.size() - 1, (int) (f.x / (float) kBin));
        if (f.sticks && ledgeY > 0.0f && f.x > ledgeX0 && f.x < ledgeX1 && vy > 0.0f
            && f.y >= ledgeY - ledge[(size_t) bin] - 1.0f && f.y - vy * kDt < ledgeY - ledge[(size_t) bin] - 1.0f)
        {
            settle (ledge, f.x, 0.4f * f.r, nullptr, kLedgeMax);
            ledgeChanged = gone = true;
        }
        else if (f.y >= h - ground[(size_t) bin] - 0.5f * f.r)
        {
            settle (ground, f.x, 0.8f * f.r, &groundCap, kGroundMax);
            groundChanged = gone = true;
        }
        else if (f.y < -60.0f)
            gone = true;

        if (gone) { flakes[i] = flakes.back(); flakes.pop_back(); continue; }
        mark (f.bounds());
        ++i;
    }

    // the drifts melt slowly while it snows (they never fill the edge) and in about 3 s after it stops
    const float melt = (falling ? 0.003f : kGroundMax) * kDt;   // gone in a second once the snow stops
    bool any = false;
    for (auto* heights : { &ground, &ledge })
        for (auto& v : *heights)
            if (v > 0.0f)
            {
                v = std::max (0.0f, v - melt);
                any = any || v > 0.0f;
            }
    if (! falling && anySnowOnGround) groundChanged = ledgeChanged = true;
    anySnowOnGround = any;

    // the drifts repaint every third frame at most: a strip, not the panel
    if (++driftFrames >= 3 && (groundChanged || ledgeChanged))
    {
        driftFrames = 0;
        ++driftVersion;
        if (groundChanged) mark ({ 0, (int) (h - kGroundMax - 3.0f), getWidth(), (int) kGroundMax + 3 });
        if (ledgeChanged && ledgeY > 0.0f) mark ({ (int) ledgeX0 - 8, (int) (ledgeY - kLedgeMax - 3.0f), (int) (ledgeX1 - ledgeX0) + 16, (int) kLedgeMax + 5 });
    }
    flush();
}

void Snowfall::flush()
{
    requested.clear();
    if (perFlakeRepaints)
        requested = marks;
    else
        for (int y0 = 0; y0 < getHeight(); y0 += kBand)             // one rectangle per band: what the flakes in it cover
        {
            const juce::Rectangle<int> band (0, y0, getWidth(), kBand);
            juce::Rectangle<int> covered;
            for (const auto& r : marks)
            {
                const auto part = r.getIntersection (band);
                if (! part.isEmpty()) covered = covered.isEmpty() ? part : covered.getUnion (part);
            }
            if (! covered.isEmpty()) requested.push_back (covered);
        }
    if (isVisible()) repaintsIssued += (int) requested.size();
    for (const auto& r : requested) repaint (r);
    marks.clear();
}

juce::Path Snowfall::driftPath (const std::array<float, 1280 / kBin + 1>& heights, float baseline, float x0, float x1)
{
    juce::Path p;
    p.startNewSubPath (x0, baseline);
    float prevX = x0, prevY = baseline;
    for (size_t i = 0; i < heights.size(); ++i)
    {
        const float x = (float) i * (float) kBin + 0.5f * (float) kBin;
        if (x < x0 || x > x1) continue;
        const float y = baseline - heights[i];
        p.quadraticTo (prevX, prevY, 0.5f * (prevX + x), 0.5f * (prevY + y));   // rounded, like snow lies
        prevX = x; prevY = y;
    }
    p.lineTo (x1, baseline);
    p.closeSubPath();
    return p;
}

void Snowfall::paint (juce::Graphics& g)
{
    if (idle()) return;
    const auto snow = Tokens::ink;
    const auto clip = g.getClipBounds();
    for (const auto& f : flakes)
    {
        if (! clip.intersects (f.bounds())) continue;              // a repaint elsewhere: not this flake
        g.setColour (snow.withAlpha (f.alpha * fade));
        if (! f.crystal)
        {
            g.fillEllipse (f.x - f.r, f.y - f.r, 2.0f * f.r, 2.0f * f.r);
            continue;
        }
        // a six-armed crystal: three strokes through the centre, a small V near each arm's end
        juce::Path p;
        for (int a = 0; a < 6; ++a)
        {
            const float t = f.angle + (float) a * juce::MathConstants<float>::pi / 3.0f;
            const juce::Point<float> c (f.x, f.y), tip = c + juce::Point<float> (std::cos (t), std::sin (t)) * f.r;
            p.startNewSubPath (c);
            p.lineTo (tip);
            const auto mid = c + (tip - c) * 0.6f;
            for (float side : { -0.6f, 0.6f })
            {
                const float u = t + side;
                p.startNewSubPath (mid);
                p.lineTo (mid + juce::Point<float> (std::cos (u), std::sin (u)) * (0.35f * f.r));
            }
        }
        g.strokePath (p, juce::PathStrokeType (1.0f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
    if (! anySnowOnGround) return;
    g.setColour (snow.withAlpha (0.92f));
    if (clip.getBottom() > getHeight() - (int) kGroundMax - 3)
        g.fillPath (driftPath (ground, (float) getHeight(), 0.0f, (float) getWidth()));
    if (ledgeY > 0.0f && clip.getY() < (int) ledgeY + 1 && clip.getBottom() > (int) (ledgeY - kLedgeMax) - 3)
    {
        g.setColour (snow.withAlpha (0.8f));
        g.fillPath (driftPath (ledge, ledgeY, ledgeX0, ledgeX1));
    }
}
} // namespace sundayorgan::ui
