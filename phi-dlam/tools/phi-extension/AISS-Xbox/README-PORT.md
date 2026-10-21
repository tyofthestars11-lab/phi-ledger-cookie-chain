# AISS-Xbox-GamePass — port runbook (blueprint: Manus, 2026-10-20, two passes; build: Golden Ratio Muse)
ROUTE: Starfield.exe -> Ultimate ASI Loader -> PHI AISS BRIDGE -> AISS_Backend.exe (unchanged)
       -> provider (LM Studio local 127.0.0.1:1234 is TYREE's seat).

PACKAGE SHAPE (Manus §4):
  AISS-Xbox-GamePass-<ver>.zip
  ├── Data/AISS/            (shared: config.json, presets, profiles, addons — from TYREE's own AISS install)
  ├── Data/Scripts/User/    (shared: AISS Papyrus scripts, common APIs)
  ├── Data/x2357aiss.esm    (shared — from TYREE's own AISS install; NOT redistributed here)
  ├── AISS_Backend.exe      (shared, unchanged — from TYREE's own AISS install; not redistributed here)
  └── phi_aiss_bridge.asi   (THE PORT — loader-required location: game root, beside Starfield.exe)
EXCLUDED by rule: sfse_loader.exe (Steam's — the phi loader wearing that seat is a SEPARATE artifact),
sfse_*.dll, SFSE plugin folders, Steam launch scripts. Do NOT rename an SFSE DLL into this package.

MACHINE CROSS-CHECKS (verified against TYREE's setup, 2026-10-20):
  §6 game location C:\XboxGames\Starfield\Content — MATCHES his install.
  §7 data-folder junction (Content\Data <-> Documents\My Games\Starfield\Data) — Vortex-side option;
     cloud-sync off for those folders first (his save-lag fix already handles the OneDrive toll).
  §9 StarfieldCustom.ini [Archive] bInvalidateOlderFiles=1 + sResourceDataDirsFinal= — already written
     by phi-add-mods.ps1 in this stack.
  §5 Vortex: his build shows v2.9.0 (above the extension's 1.12 LOOT floor).

BRIDGE STATUS: v0.1 transport + contract LIVE (blackboard, event log, outbox loop). PROJECT STATE: ACTIVE — TYREE, 2026-10-20: "I am not giving up on the ai thing." Shelved in Vortex != abandoned; the port continues until AISS wakes on the Game Pass build.
REMAINDERS (the engineering core, Manus §3): Papyrus-side binding for Cassiopeia calls +
Store-exe context addresses (NPC/quest/location). Until those land, this package deploys as a
DATA + TRANSPORT test build: installs clean, dialogue back-end integration completes when the
bridge's deep half lands.

TEST LADDER (Manus §11 — the acceptance order, run in sequence):
 1 Vortex detects the Game Pass install   2 archive deploys, no conflicts
 3 x2357aiss.esm in plugin list           4 game launches, no crash (PROVEN gate after 2026-10-20 repair)
 5 AISS Setup item in Aid inventory       6 AISS dialogue option on a supported NPC
 7 typed text reaches backend             8 backend responds
 9 response appears in-game               10 TTS separately
 Steps 1–5 green + 6 dark = bridge deep half. 6 green + 7/8 dark = backend/config/provider.
