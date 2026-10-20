# STARFIELD STACK — Tyree's build (Game Pass PC, RTX 3050 6GB, i5-12400F, 16GB)

## Applied (phi fixes, in phi-dlam/tools/)
- phi-fix-starfield.ps1 — base game fix (verified run 2026-10-19)
- phi-fix-total.ps1 — micro-to-macro: boost AGGRESSIVE, cores unparked, disk/USB/PCIe sleep OFF,
  pagefile system-managed, Defender exclusions, TON 618 GPU ceiling, governor v2 in STARFIELD PHI launcher
- phi-governor-starfield.ps1 — standalone governor (superseded by launcher v2)
- phi-tracer-lag.ps1 — freeze-window tracer

## STAGED — AISS - AI Settled Systems (Nexus mod 17392, by X-2357, v3.0)
Tyree's word 2026-10-20: "add this to it."
What: AI NPC conversations — typed natural dialogue, per-NPC persistent memory, live quest/
location/ship/gear awareness, group dialogue, optional TTS (ElevenLabs/Fish Audio), 1,350 NPCs.
REQUIRES: SFSE (Starfield Script Extender) + Cassiopeia Papyrus Extender + Longer Names v2
+ one AI provider (OpenRouter key / Player2 / LM Studio local server).
INSTALL ORDER (when unblocked): SFSE -> Cassiopeia -> Longer Names v2 -> AISS via MO2/Vortex ->
enable x2357aiss.esm -> copy a config preset to Data\AISS\config.json -> set provider ->
run Data\AISS\AISS_Backend.exe while playing -> launch through SFSE -> use "AISS Setup" aid item once.
BLOCKER (verified from the mod page + SFSE's known scope): SFSE loads only on Steam/GOG builds.
Tyree's copy is Game Pass (ProjectGold/WindowsApps) — its exe is locked; AISS CANNOT run on it.
UNBLOCK: a Steam copy of Starfield. Then the chain installs in one pass.
PHI NOTE: the provider slot accepts a local server (LM Studio path, OpenAI-compatible endpoint) —
the door for the local `tyree` model to voice the NPCs. Try-first when the day comes.
