"""Screenshot frame.html at 1x and 2x (Playwright, the pre-installed Chromium)."""
import pathlib
from playwright.sync_api import sync_playwright
here = pathlib.Path(__file__).parent.resolve()
with sync_playwright() as p:
    b = p.chromium.launch()
    for scale in (1, 2):
        pg = b.new_page(viewport={"width": 1280, "height": 600}, device_scale_factor=scale)
        pg.goto((here / "frame.html").as_uri()); pg.wait_for_timeout(400)
        el = pg.query_selector(".oa-plugin"); el.screenshot(path=str(here / f"sunday-organ@{scale}x.png"))
        print(scale, el.bounding_box())
    b.close()
