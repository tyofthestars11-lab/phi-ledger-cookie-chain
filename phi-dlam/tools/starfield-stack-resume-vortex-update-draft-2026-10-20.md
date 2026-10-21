# STARFIELD STACK — RESUME UPDATE DRAFT (2026-10-20 evening, Vortex session)
Status: DRAFT prepared 2026-10-20 ~20:35 MDT. Not committed, not pushed. Awaits TYREE's word to replace starfield-stack-resume.md.

## What changed tonight (supersedes the 18:35 MDT resume sheet where they conflict)
- VORTEX IS IN THE CIRCUIT: launch bridge v2 order is now Xbox systems → Vortex → the braid → Starfield → NVIDIA. Mods ride Nexus → Vortex, deployed in the Game Pass pattern.
- ASI LOADER: Game Pass ASI Loader selected in Vortex's Install Injector/Loader dialog (the generic "A Code Injector" bucket is the Steam/GOG-pattern class — not his build).
- SFCP ROUTE CHANGED: Starfield Community Patch now comes from its Nexus page, v1.0.0, via the Vortex button. This SUPERSEDES the staged GitHub 0.1.7 copy.
  - ACTION ON HIS WORD: retire phi-add-community-patch.ps1 (bundled-zip-first) from the run order. Do NOT run it after the Vortex install — both routes place StarfieldCommunityPatch.esm in the same Data seat and register it in plugins.txt; running both risks a version collision / double registration, with the older 0.1.7 able to overwrite the newer 1.0.0.
  - The staged 0.1.7 payload (sha256 91ec1ce33a001144) stays in the vault as the archive copy, untouched — route retired, file kept.
- ENABLED VIA VORTEX (his installs, 2026-10-20 evening): Starfield Optimizations – Ultra Optimized (the in-play stutter treatment) + EXE – Effect Textures Enhanced.
  - A/B note carried from chat: if a session feels worse, EXE textures is the first suspect — one-click toggle off in Vortex, ten-second read.
- DLSS-G MOD RULED OUT: LukeFZ frame-gen mod v1.3.0 (Sep 2023) — Frame Generation is RTX 40-series only; his RTX 3050 cannot switch it on, and Bethesda ships native DLSS now. His door: in-game Settings → Display → Upscaling → DLSS (Quality or Balanced) + render-resolution slider.
- AMAZON COMPANION: loop closed, his word "Let it go" — no reorder. (Separate lane; recorded here so the resume sheet carries the closed state.)

## Unchanged from the 18:35 sheet
- NAMED: lag fires ON SAVE; 8s lag = Creations reconciliation cost; Creations stay (TYREE law); binary never leads the stack (TYREE law).
- STAGED (vault, awaiting PC pull): phi-ton618-core v2 installer, phi-fix-8second.ps1, phi-fix-save-lag.ps1, phi-anyons-keeper.ps1, companion v3.6 installer (29 seats), phi-xbox-systems.ps1.
- OPEN READ (one): phi-ton618-core.ps1 on PC = 77 lines + v2 header = hers; anything else = stub, re-deliver.
- AISS stays staged behind the Steam fork — declined; Game Pass copy stands.
