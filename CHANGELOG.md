# Changelog

All notable changes to Sunday Organ, newest first (Keep a Changelog). A **Sounds different:**
line marks a release that changes a factory sound; "(reported by X.)" credits a friend's report.

## [Unreleased]
### Added
- Jingle Jam: five Christmas presets for the jam - Snowfall Ballad, Christmas Swing, Hallelujah
  Shout, Silent Night (the carol pad) and Sleigh Bells. While one is loaded it snows on the panel;
  with the Leslie fast the snow whirls around the horn; choose another preset and it is gone within
  a second. The menu turns the snow off.
- Your own presets: **Save current sound** in the preset list, under USER; right-click one of
  yours to rename, share or delete it (deleting moves it to the Trash). They live in
  `~/Library/Audio/Presets/Oberli Audio/Sunday Organ/User` (Windows: `Documents\VST3 Presets\Oberli
  Audio\Sunday Organ\User`).
- Menu: **Load preset from file...** adds a preset someone sent you to your own and loads it;
  **Share preset...** writes the current sound to a file you can send; **Back to ...** returns to
  the sound before the last preset change. A preset file dropped on the plugin is added too.
### Changed
- The first preset, the sound a new instance starts with, is called Clean Slate (it was Init).
- The preset list closes with a click outside it, its close button, Escape or a double-click on a
  preset; it scrolls when your own presets outgrow it.
- A reopened project shows the preset it was saved with.
- The editor's settings moved to `~/Library/Application Support/Oberli Audio/Sunday Organ`: a GUI
  scale chosen before this version is not carried over.
- Drive ends in a speaker roll-off that closes as you turn it up: from about 75 % the top darkens
  like a driven Leslie amplifier, so a hard-driven chord keeps its growl without the fizz.
- The factory presets' Drive voiced again for the new drive stage: Jazz Trio, Smoky Club, Sunday
  Morning and Shout Chorus warmer, Rock Drive and Gospel Full as before.
- The editor wears tangerine, the accent every Oberli Audio instrument shares; the output meter
  shows LIMIT while the safety limiter works.

**Sounds different:** Jazz Trio, Smoky Club, Sunday Morning and Shout Chorus have more drive;
every preset above 75 % Drive (Rock Drive) is darker at the top.

## [0.1.0] - 2026-10-31
### Added
- Started from the Oberli Audio plugin template: instrument, charcoal theme, accent coral.
