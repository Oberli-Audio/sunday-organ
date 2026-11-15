#include "SnowOverlay.h"

#include "OberliLookAndFeel.h"
#include "Snowfall.h"

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#include <objc/runtime.h>

#include <cmath>
#include <vector>

namespace sundayorgan::ui
{
namespace
{
/** The overlay's NSView class: registered at run time under a unique name (two plugins built from
    this code in one host must not share a class), click-through (hitTest: answers nil, so every
    click reaches the editor beneath) and top-left origin like JUCE's views. */
struct SnowViewClass
{
    Class cls = nil;

    SnowViewClass()
    {
        const auto name = "SundayOrganSnowView_" + juce::String::toHexString (juce::Random::getSystemRandom().nextInt64());
        cls = objc_allocateClassPair ([NSView class], name.toRawUTF8(), 0);
        auto hit = +[] (id, SEL, NSPoint) -> NSView* { return nil; };
        auto flipped = +[] (id, SEL) -> BOOL { return YES; };
        class_addMethod (cls, @selector (hitTest:), (IMP) hit, (juce::String ("@@:") + @encode (NSPoint)).toRawUTF8());
        class_addMethod (cls, @selector (isFlipped), (IMP) flipped, (juce::String (@encode (BOOL)) + "@:").toRawUTF8());
        objc_registerClassPair (cls);
    }

    ~SnowViewClass() { if (cls != nil) objc_disposeClassPair (cls); }   // the plugin unloads: no class may point into it
};

Class snowViewClass()
{
    static SnowViewClass holder;
    return holder.cls;
}

CGColorRef bone (CGFloat alpha)
{
    const auto c = Tokens::ink;
    const CGFloat components[] = { c.getFloatRed(), c.getFloatGreen(), c.getFloatBlue(), alpha };
    auto space = CGColorSpaceCreateWithName (kCGColorSpaceSRGB);
    auto colour = CGColorCreate (space, components);
    CGColorSpaceRelease (space);
    return colour;
}

/** A flake drawn once, at 4x its largest size: a disc, or the six-armed crystal of Snowfall::paint. */
CGImageRef flakeImage (bool crystal)
{
    const int px = 64;
    auto space = CGColorSpaceCreateWithName (kCGColorSpaceSRGB);
    auto ctx = CGBitmapContextCreate (nullptr, px, px, 8, 0, space, (CGBitmapInfo) kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease (space);
    const CGFloat c = px / 2.0, r = px / 2.0 - 1.0;
    auto colour = bone (1.0);
    if (! crystal)
    {
        CGContextSetFillColorWithColor (ctx, colour);
        CGContextFillEllipseInRect (ctx, CGRectMake (c - r, c - r, 2 * r, 2 * r));
    }
    else
    {
        CGContextSetStrokeColorWithColor (ctx, colour);
        CGContextSetLineWidth (ctx, px / 11.0);                     // 1 px at a 5.5 px crystal, as Snowfall draws it
        CGContextSetLineCap (ctx, kCGLineCapRound);
        for (int a = 0; a < 6; ++a)
        {
            const CGFloat t = (CGFloat) a * M_PI / 3.0;
            const CGFloat tx = c + std::cos (t) * r, ty = c + std::sin (t) * r;
            CGContextMoveToPoint (ctx, c, c);
            CGContextAddLineToPoint (ctx, tx, ty);
            const CGFloat mx = c + (tx - c) * 0.6, my = c + (ty - c) * 0.6;
            for (CGFloat side : { -0.6, 0.6 })
            {
                CGContextMoveToPoint (ctx, mx, my);
                CGContextAddLineToPoint (ctx, mx + std::cos (t + side) * 0.35 * r, my + std::sin (t + side) * 0.35 * r);
            }
        }
        CGContextStrokePath (ctx);
    }
    CGColorRelease (colour);
    auto image = CGBitmapContextCreateImage (ctx);
    CGContextRelease (ctx);
    return image;
}
} // namespace

struct SnowOverlay::Impl
{
    NSView* view = nil;
    CALayer* root = nil;
    std::vector<CALayer*> flakes;
    CAShapeLayer* ground = nil;
    CAShapeLayer* ledge = nil;
    CGImageRef dot = nullptr, crystal = nullptr;
    int driftVersion = -1;
    juce::Rectangle<float> lastExclude;
    juce::Rectangle<int> lastFrame;

    Impl() : dot (flakeImage (false)), crystal (flakeImage (true)) {}

    ~Impl()
    {
        remove();
        CGImageRelease (dot);
        CGImageRelease (crystal);
    }

    void remove()
    {
        for (auto* l : flakes) [l release];
        flakes.clear();
        [ground release]; ground = nil;
        [ledge release]; ledge = nil;
        if (view != nil) { [view removeFromSuperview]; [view release]; view = nil; }
        root = nil;
        driftVersion = -1;
    }

    CAShapeLayer* shape (CGFloat alpha)
    {
        auto* s = [[CAShapeLayer alloc] init];
        auto colour = bone (alpha);
        s.fillColor = colour;
        CGColorRelease (colour);
        s.strokeColor = nil;
        [root addSublayer: s];
        return s;
    }

    /** The drift as Snowfall::driftPath draws it: rounded heaps over `heights`, from x0 to x1. */
    template <typename Heights>
    static CGPathRef driftPath (const Heights& heights, float bin, float baseline, float x0, float x1)
    {
        auto p = CGPathCreateMutable();
        CGPathMoveToPoint (p, nullptr, x0, baseline);
        float prevX = x0, prevY = baseline;
        for (size_t i = 0; i < heights.size(); ++i)
        {
            const float x = (float) i * bin + 0.5f * bin;
            if (x < x0 || x > x1) continue;
            const float y = baseline - heights[i];
            CGPathAddQuadCurveToPoint (p, nullptr, prevX, prevY, 0.5f * (prevX + x), 0.5f * (prevY + y));
            prevX = x; prevY = y;
        }
        CGPathAddLineToPoint (p, nullptr, x1, baseline);
        CGPathCloseSubpath (p);
        return p;
    }
};

SnowOverlay::SnowOverlay() = default;
SnowOverlay::~SnowOverlay() = default;

bool SnowOverlay::attached() const noexcept { return impl != nullptr && impl->view != nil; }

bool SnowOverlay::attach (juce::Component& editor)
{
    if (! enabled || attached()) return attached();
    auto* parent = (NSView*) editor.getWindowHandle();
    if (parent == nil) return false;
    if (impl == nullptr) impl = std::make_unique<Impl>();
    auto& i = *impl;
    i.view = [[snowViewClass() alloc] initWithFrame: NSZeroRect];
    i.root = [CALayer layer];                                       // a layer-hosting view: no drawRect, only layers
    // y runs down, as the snow counts: the view is flipped (isFlipped) and AppKit sets the layer's
    // geometry to match the view's, so no geometryFlipped of our own (AppKit resets it anyway)
    i.root.masksToBounds = YES;
    [i.view setLayer: i.root];
    [i.view setWantsLayer: YES];
    [parent addSubview: i.view positioned: NSWindowAbove relativeTo: nil];
    i.ground = i.shape (0.92);                                      // the view keeps the root layer; these two are ours
    i.ledge = i.shape (0.8);
    return true;
}

void SnowOverlay::detach()
{
    if (impl != nullptr) impl->remove();
}

void SnowOverlay::hide()
{
    if (attached()) impl->view.hidden = YES;
}

void SnowOverlay::show (const Snowfall& snow, float scale, juce::Rectangle<int> frameInPeer, juce::Rectangle<float> exclude)
{
    if (! attached()) return;
    auto& i = *impl;

    [CATransaction begin];
    [CATransaction setDisableActions: YES];                        // positions jump, they do not animate
    i.view.hidden = NO;
    if (frameInPeer != i.lastFrame)
    {
        i.lastFrame = frameInPeer;
        [i.view setFrame: NSMakeRect (frameInPeer.getX(), frameInPeer.getY(), frameInPeer.getWidth(), frameInPeer.getHeight())];
    }
    i.root.sublayerTransform = CATransform3DMakeScale (scale, scale, 1.0);
    const CGFloat backing = i.view.window != nil ? i.view.window.backingScaleFactor : 2.0;

    // one layer per flake, made once and reused
    const auto& flakes = snow.flakes;
    while (i.flakes.size() < flakes.size())
    {
        auto* l = [[CALayer alloc] init];
        l.contentsGravity = kCAGravityResize;
        [i.root insertSublayer: l below: i.ground];
        i.flakes.push_back (l);
    }
    for (size_t k = 0; k < i.flakes.size(); ++k)
    {
        auto* l = i.flakes[k];
        if (k >= flakes.size()) { l.hidden = YES; continue; }
        const auto& f = flakes[k];
        const bool inside = exclude.contains (f.x, f.y);
        l.hidden = inside;
        if (inside) continue;
        l.contents = (id) (f.crystal ? i.crystal : i.dot);
        l.bounds = CGRectMake (0, 0, 2.0 * f.r, 2.0 * f.r);
        l.position = CGPointMake (f.x, f.y);
        l.opacity = f.alpha * snow.fade;
        l.affineTransform = f.crystal ? CGAffineTransformMakeRotation (f.angle) : CGAffineTransformIdentity;
        l.rasterizationScale = backing * scale;
    }

    // the drifts: rebuilt only when they changed, or the drawer opened or closed over them
    if (snow.driftVersion != i.driftVersion || exclude != i.lastExclude)
    {
        i.driftVersion = snow.driftVersion;
        i.lastExclude = exclude;
        const float bin = (float) Snowfall::kBin, w = (float) snow.getWidth(), h = (float) snow.getHeight();
        const float x0 = exclude.isEmpty() ? 0.0f : exclude.getRight();
        auto g = Impl::driftPath (snow.ground, bin, h, x0, w);
        i.ground.path = g;
        CGPathRelease (g);
        i.ground.contentsScale = backing * scale;
        if (snow.ledgeY > 0.0f)
        {
            auto l = Impl::driftPath (snow.ledge, bin, snow.ledgeY, std::max (snow.ledgeX0, x0), snow.ledgeX1);
            i.ledge.path = l;
            CGPathRelease (l);
        }
        i.ledge.contentsScale = backing * scale;
    }
    i.ground.hidden = i.ledge.hidden = ! snow.anySnowOnGround;
    [CATransaction commit];
}
bool SnowOverlay::renderOver (juce::Image& image) const
{
    if (! attached() || impl->view.hidden) return false;
    juce::Image::BitmapData px (image, juce::Image::BitmapData::readWrite);
    auto space = CGColorSpaceCreateWithName (kCGColorSpaceSRGB);
    auto ctx = CGBitmapContextCreate (px.data, (size_t) image.getWidth(), (size_t) image.getHeight(), 8, (size_t) px.lineStride, space,
                                      (CGBitmapInfo) kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Little);   // JUCE's ARGB in memory
    CGColorSpaceRelease (space);
    if (ctx == nullptr) return false;
    const auto frame = [impl->view frame];
    // on screen the flipped view above turns this layer top-down; rendered alone it needs that flip here
    CGContextTranslateCTM (ctx, 0, (CGFloat) image.getHeight());
    CGContextScaleCTM (ctx, (CGFloat) image.getWidth() / frame.size.width, -(CGFloat) image.getHeight() / frame.size.height);
    [impl->root renderInContext: (CGContextRef _Nonnull) ctx];   // not null: checked above
    CGContextRelease (ctx);
    return true;
}
} // namespace sundayorgan::ui
