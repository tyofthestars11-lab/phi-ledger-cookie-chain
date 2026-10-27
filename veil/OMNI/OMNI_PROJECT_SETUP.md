# OMNI RPG: PATH OF LIGHT — Project Setup

Built for **Unreal Engine 5.8** on Tyree's rig: i5-12400F, **RTX 3050 6 GB**, 16 GB RAM.
Design north star: *Cyberpunk × GTA × Crimson Desert × Elder Scrolls* — a living,
seamless sci-fi world, built district by district from this foundation.

---

## 1. What is in this project

```
OMNI/
  OMNI.uproject                  UE 5.8, C++ module "OMNI"
  Config/                        Enhanced Input defaults, renderer tuned for 6 GB VRAM
  Source/OMNI/
    OMNI.Build.cs                Core, Engine, EnhancedInput, AIModule, UMG...
    Public/
      Character/OMNICharacter.h        AOMNICharacter - move/sprint/jump/dodge/aim/fire/health/interact
      AI/OMNIFactionAI.h               AOMNIFactionAgent (6 states) + AOMNIFactionManager (territory, power)
      World/OMNIDistrictStreaming.h    ADistrict + UDistrictChunk + AOMNIStreamingManager (4x4 grid, LOD tiers)
      Systems/OMNIDiscoverySystem.h    clues, artifacts, lore fragments, mysteries, Signal progress
      Game/OMNIGameMode.h              AOMNIGameMode (phases, difficulty, seeding) + AOMNIPlayerController (HUD, pause)
    Private/  (matching .cpp files)
```

Factions: **Void, Scavenger, Guardian, Remnant.** Hostility: everyone fights the
Void; Scavenger ↔ Guardian rivalry; Remnant defends its own ground.

## 2. First compile (UE 5.8)

1. Install **Visual Studio 2022** with the **Game development with C++** workload.
2. Extract this project anywhere (D: drive is fine).
3. Right-click `OMNI.uproject` → **Generate Visual Studio project files**.
4. Open `OMNI.uproject` in UE 5.8 and let it compile, or open the `.sln` and
   build **Development Editor | Win64**.
5. Target: **Win64 Development**.

## 3. Input assets (one-time, in the editor)

Create these in `Content/OMNI/Input/`:

- **IMC_Default** (Input Mapping Context) and Input Actions:
  `IA_Move` (Axis2D), `IA_Look` (Axis2D), `IA_Jump`, `IA_Sprint`, `IA_Dodge`,
  `IA_Aim`, `IA_Fire`, `IA_Interact` (all Boolean except the two axes).
- Suggested keys: WASD → Move (with modifiers for -X/-Y), mouse → Look,
  Space → Jump, Shift → Sprint, Ctrl or Alt → Dodge, Right Mouse → Aim,
  Left Mouse → Fire, **E** → Interact.
- Then open **BP_PlayerCharacter** (see §4) and assign IMC + all actions in
  the **OMNI | Input** section of its defaults.

## 4. Blueprints to create

| Blueprint | Parent class | Purpose |
|---|---|---|
| `BP_PlayerCharacter` | `AOMNICharacter` | Assign a mesh (MetaHuman or Manny), anim BP, and the Input assets |
| `BP_Agent_Void` (+ Scavenger / Guardian / Remnant) | `AOMNIFactionAgent` | Mesh + Faction set per variant; drop into districts, set Patrol Points |
| `BP_District` | `ADistrict` | District root; set DistrictId, Radius, optional Streaming Levels |
| `BP_StreamingManager` (or place the C++ class) | `AOMNIStreamingManager` | One per persistent level |
| `BP_Clue_Terminal` | `AEnvironmentalClue` | Mesh + its Lore Fragment (Id, Title, Body, MysteryId) |
| `BP_Artifact` | `AArtifact` | Mesh + ArtifactId; HealAmount if it's a restorative |
| `WBP_HUD` / `WBP_Pause` | UserWidget | Bind health (OnHealthChanged), objective text, Signal progress |
| `BP_OMNIGameMode` | `AOMNIGameMode` | Fill MysteriesToRegister + TerritoriesToRegister; set as the level's GameMode |

World Settings → GameMode Override = `BP_OMNIGameMode`; Default Pawn is wired
to `AOMNICharacter` in C++ — set the GameMode's pawn to `BP_PlayerCharacter`
in the BP defaults for the meshed version.

## 5. First playable level — L_MegaStructure_Persistent

Layout (the megastructure core, one district of the future 4×4):

- Big floor plate + modular ruins (Fab free sci-fi packs, Megascans).
- `BP_StreamingManager` at origin. 2–3 `BP_District` actors: **Central Hub**
  (radius 4000), **Ruins East**, **Machine Nest West**.
- Player Start in Central Hub.
- 3 clues forming one mystery (`SIGNAL_ORIGIN`: clue ids `clue_terminal_01`,
  `clue_recording_01`, `clue_ruin_mark_01`) + 1 artifact.
- 6–10 agents: Void pack at the Machine Nest, Guardians holding the Hub,
  2 Scavengers patrolling the ruins. Nav Mesh Bounds Volume over the play area
  (**Build → Build Paths** after placing).

Play: explore → examine clues (E) → mystery solves → Guardians claim the
territory, Void reinforces. That loop *is* Prototype 01.

## 6. Performance targets — RTX 3050 6 GB

- **1080p, Dynamic Resolution 59–100%** (already in `DefaultEngine.ini`).
- Scalability baseline **Medium**; shadows Medium; no Virtual Shadow Maps
  in the prototype (disabled in config).
- Budgets: ≤ 4 districts Near at once (grid + distances are set for this),
  20–40 agents per district, agent perception on a 0.25 s timer (coded).
- Watch it: `stat fps`, `stat unit`, `stat GPU` in the console (~ key).

## 7. Debugging

- Log category **LogOMNI** (Window → Output Log, filter `LogOMNI`):
  faction boots, territory claims, mystery solves print there.
- Console: `ShowDebug AI` on a selected agent; `OMNI` actors all expose
  their state as Blueprint-readable properties for on-screen debug widgets.

## 8. Free asset sources (no paid assets, ever)

- **Fab** (fab.com) — free monthly drops + Epic free content, Megascans library.
- **MetaHuman** — free, for the player + faction leaders.
- **Quixel Megascans** via Fab — ruins, rock, megastructure surfaces.
- **Mixamo** — free character animations to bootstrap movement/combat.
- Epic's **Lyra / City Sample** pieces can be mined for systems reference —
  do not ship their assets in an original title; learn, don't lift.

## 9. Honest state of this code

The C++ is written complete against UE 5.8 APIs but has **not been compiled
on this machine** (no Unreal install here). Expect the editor's first compile
to be the real test — any red squiggles land in the Output Log with file and
line, and we fix forward from there. Meshes, animations, and UI art are the
asset-creation list in the design doc; the systems underneath them are done.

## 10. Addendum — controls, menu, music, install script

- **Controls work with zero editor setup.** If no Input assets are assigned,
  `AOMNICharacter` builds its own map in code: **WASD + mouse** and a full
  **Xbox controller** map (left stick move, right stick look, A jump, B dodge,
  X interact, LT aim, RT fire, L3 sprint). Pause/menu: **P**, **Esc**, or the
  pad's **Menu** button. Assigning editor-made assets overrides the built-in map.
- **Main menu included (C++).** `UOMNIMainMenu` — title, *Enter the Signal*,
  *Graphics* (cycles Low/Medium/High/Epic scalability), *Quit* — shows at boot
  with no widget assets. The PlayerController defaults to it; replace with a
  styled `WBP_MainMenu` later by setting MainMenu Widget Class.
- **Music system included.** Place one `AOMNIMusicDirector` in the persistent
  level and assign any free tracks: Exploration Music, Combat Music (crossfades
  in when the phase turns to Confrontation), Discovery Stinger (plays when a
  mystery solves). Empty slots stay silent.
- **Install script.** `tools/install_veil.py` (kept with the project copies)
  installs the project to `D:\OMNI`, verifies it, and finds the UE 5.8 engine.
  On Tyree's PC this runs through PHI-DLAM (job 031) — no manual steps.
