# GOOGLE FUEL — carried by Tyree, 2026-10-27

Google AI's answer to the two-games brief. Fuel, kept whole. What was
taken from it, and what was left, is recorded at the bottom.

## 1. Manny wiring template (ConstructorHelpers)
- Mesh finder path (Google's form): `/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'`
- Anim finder path (Google's form): `/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny_C`
- Mesh offset in their template: location (0,0,-90), rotation yaw -90.
- NOTE from the study brief (section 3): capsule 34/88, mesh offset
  z -88; and the pack's real folder names come from job 082's
  verbatim inventory — never from this page. The template's SHAPE
  (static finders, Succeeded() checks, loud UE_LOG on failure) is
  the adopted pattern.

## 2. Material mapping (Python)
Same shape as the kept `swap_placeholders.py` family: find actors by
label substring, walk StaticMeshComponents, set every material slot.
Runs when 082's verbatim material paths exist.

## 3. Geometry Scripting golden district (C++)
`UDistrictGeneratorComponent::GenerateGoldenDistrict` — Vogel's
model: radius 300*sqrt(i), theta = i * golden angle, heights
500 * phi^min(i*0.1, 3), boxes appended into one UDynamicMesh via
UMeshBasicShapeFunctions::AppendBox. The world generator's next
form (one mesh, one actor) after VEILWorld proves in placed actors.

## 4. TSR / Lumen scaler block
Folded into DLAM job 087 verbatim (both games, DefaultEngine.ini):
r.DynamicRes.OperationMode=0, r.AntiAliasingMethod=4,
r.TSR.History.ScreenPercentage=66.6667, r.TSR.Velocity.Quality=1,
r.TSR.Sharpness=1.0, r.Lumen.HardwareRayTracing=0,
r.Lumen.TraceDistance=10000.0, r.Lumen.Reflections.Allow=1,
r.Shadow.Virtual.MaxPhysicalPages=2048.

## 5. Their package command (NOT adopted as-is)
Shipping + -allmaps + D:\VEIL\Build_Output. Ours stays Development
until playable is proven (logs on, per brief sections 7/9);
Shipping is the hand-off form for later.

## Verdict (Muse, 2026-10-27)
TAKEN: the Manny template shape (code lands against 082's real
paths), the material-mapping shape, the scaler block (job 087),
the Geometry Scripting generator (next form, queued behind proof).
LEFT: invented asset paths, the Shipping-first package command,
and its closing offer — OMNI's phi XP curve already exists in
UOMNIQuestSystem, and the 3-sector world generator is already
built (build_world.py, both games).

---

## Second carry - the greybox-to-game roadmap (2026-10-27 ~12:19 MDT)

Google's six-step roadmap (loop/controls, RPG logic, art swap, lighting, gameplay/UI/audio, package), read whole against the live state. Google itself names the first move: "Complete the task your agent is working on (Checking anim load)" - the lane's jobs 097-099, already queued.

TAKEN:
- Item DataTable via agent-written CSV (20-30 items, Name/Damage/Rarity/Value), imported by editor script. Queued as the tranche after the 097-099 verdicts; stats on the phi curve (damage by phi growth, rarity as rungs).
- Post Process Volumes for per-game mood (VEIL dusk grade). Rides the next art tranche with the mesh swaps.
- Sculpted landscape under OMNI's sectors. Later tranche, after the city proves; VEIL's district stays flat by design (it is a city).

ALREADY STANDS (the roadmap does not know the shelf):
- Perspective: both, toggle V / R3, boom 420 <-> 0. Enhanced Input gamepad map live: move, look, jump, dodge, interact, fire, aim, sprint, camera, pause.
- RPG logic: OMNI 6-stage quest system, XP = round(20 * phi^(level-1)), Warden Prime 900 HP, health/damage, HUD quest tracker, pause/title shell in both games.
- Lighting: Lumen GI + reflections, virtual shadow maps, SkyAtmosphere + fog + sun placed by the builders, TSR tuned in both inis.
- Enemies: faction agents in C++ with per-faction attack patterns (not Behavior Trees).
- Animation Blueprint: ABP_Unarmed already exists in the Mannequins tree with its blend spaces; the work is wiring it live (097/099), not authoring from zero.

LEFT:
- Behavior Trees as the enemy route - a rewrite for ceremony; the C++ agents already perceive, move, and attack.
- Fab downloads through the Launcher as the art source - the shelf on disk feeds first (19.5 GB VaultCache + TemplateResources already copied in, job 089); Launcher downloads are also his-account clicks, not lane work.
- "Use default template characters to start" - Manny is already the body in both games.
- Deleting the flat blocks to sculpt - the blocks receive real meshes and materials (swap tranche); the layout Google says to keep is the layout we keep.
- Audio remains a real gap (the Unreal builds are silent; the web fleet carries THE SCORE) - named, parked behind anim/art/package.

---

## Third + fourth carries - the AAA blueprint and the phi-Cartesian map (2026-10-27 ~12:27 MDT)

Read against the live state and the 097-100 verdicts (below). Google's AAA list mostly names roads already closed or roads closed by the machine (RTX 3050 6GB):

- Nanite: TAKEN for static environment meshes where it fits the 3050 budget (rides the mesh-swap tranche).
- Lumen hardware ray tracing: LEFT - off by design; Lumen software RT is the standing rig.
- Substrate materials: LEFT - experimental cost on a 6GB card; the art problem is family-correct assignment, not material model.
- GAS: LEFT - health/quest/XP/abilities already run as custom C++ systems; a GAS migration replaces working systems for ceremony.
- Motion Warping / Control Rig IK: LATER - real, but behind the skeleton (nothing animates until SKM_Manny_Simple has one).
- World Partition / Data Layers: LEFT - maps are standard levels by design.
- MetaHumans / Fab packs: LEFT - Launcher-account downloads and size; the VaultCache shelf feeds first.
- "100-weapon JSON for GAS tags": the items table already stands at 24 phi-curve rows (job 100; fill shape fixed, reimport queued) - scaling the CSV is an edit, not a pipeline.
- The phi-Cartesian matrix snippet: NAMES WHAT THE WORLDGEN ALREADY RUNS - build_world.py places sectors on the golden spiral (golden angle, phi growth) over the Cartesian grid; the 1 -> phi -> phi^2 scale ladder is its tower math. Taken from it: the camera composition note (player resting at the phi intersection of the viewport) for the cinematic pass.

## The 097-100 verdicts (2026-10-27 ~12:21-12:25 MDT) - one root, three symptoms

- 097: LogAnimation names it: "SKM_Manny_Simple has no skeleton." The TemplateResources Mannequins copy carried no Skeletons folder. Anim instance can never be created - T-pose explained at the root. VEIL art pass v1 exited 1 after inventorying 824 materials; it still dressed the district (Tyree's photo: towers wearing a character-suit material - the keyword race went to the character kits).
- 098: ProjectID removed, cook advanced 85 s and failed on the REAL error: "ABP_Unarmed - The skeleton asset for this animation Blueprint is missing, so it cannot be compiled!" ProjectID was a passenger, never the cause - the removal test is what exposed the true one. One root (missing skeleton) drives anim, T-pose, and every failed cook.
- 099: OMNIWorld now loads as OMNI's default map (seat confirmed). OMNI art: only 5 materials exist in OMNI's /Game (Mannequins only) - every actor NO MATERIAL, matching Tyree's blue-void photo. OMNI needs its content drop (SickaEnv + ParagonMinions, job 102).
- 100: DT_Items created with FPHIItemRow in both games; fill returned ok=True with 0 rows - the JSON shape was keyed-object; the fill wants an array of row objects with a Name field. Script fixed; reimport rides job 103.
- Queued: 101 skeleton probe + install-wide hunt (the copy/fix job follows the named home), 102 OMNI content + VEIL art v2 (environment pools, character kits blacklisted, chosen material per family logged), 103 OMNI art v2 + mood pass both + items reimport, 104 package attempt 5 + door upgrade if the exe lands.

---

## Fifth carry - the three blockers answered (2026-10-27 ~12:32 MDT)

- Blocker 1(a) skeleton home: Google names Engine TemplateResources ...\Mannequins\Meshes\SK_Mannequin_Skeleton.uasset, in-project /Game/Mannequins/Meshes/SK_Mannequin_Skeleton. Checkable, not assumed - job 101 hunts it; job 105 mirror-copies whatever the hunt finds (Content-relative) into both projects and re-probes every mannequin mesh.
- Blocker 1(b) fix_skeleton.py: LEFT as written. It creates an EMPTY skeleton (no bones) and binds it - that silences the warning while breaking the body, and its ABP path omits the Unarmed folder. The lane copies the real skeleton or none.
- Blocker 1(c): the quoted cook errors are invented text; our measured error stands in the 098 log.
- Blocker 2 scripts: material paths invented (no such assets verified) - LEFT; art v2's registry discovery is the honest form. TAKEN: the OMNI identity allocation - LavaMate (volcanic) for OMNI instead of sharing VEIL's SickaEnv; Revenant for Warden Prime and Countess + ModularStylizedChars for OMNI variety ride the agents'-bodies tranche. Job 102 amended (LavaMate -> OMNI; OMNI art hints += lava).
- Blocker 3: CONFIRMS the lane's fix - array of row objects with a Name field (job 103 reimport). Google's example uses enum-typed fields; our struct is FString/int32, so plain values are correct here.
- Config block: already standing in our consolidated inis (Lumen SWRT, TSR, VSM). Its ScreenPercentage=100 and DynamicRes lines contradict the 3050 tuning - LEFT; nothing applied.
- Its closing either/or (Minion bindings vs OMNI landscape): neither re-sequences the lane - agents' bodies already sit in the queue behind the body/art proof.

---

## Sixth carry - "both still stuck" + the bulletproof fixes (2026-10-27 ~12:39 MDT)

Google's diagnosis (a cooking checkpoint rejecting the scripts before they parse) is invented - the logs show the scripts ran (824 materials inventoried, DT_Items created) and the cook dies on the ABP's missing skeleton, measured in 098. Its scripts, weighed one by one:

- fix_skeleton_core.py: the CORE MOVE IS REAL - SkeletonFactoryNew with the factory's skeletal_mesh property set builds the skeleton FROM the mesh's bone tree (its earlier version omitted this and would have made an empty skeleton). TAKEN as the guarded FALLBACK (job 106): corrected ABP path (/Anims/Unarmed/ABP_Unarmed), a guard that skips when job 105's disk copy already resolved the mesh, probe/build/smoke verdict attached. The hunt+copy (105) still outranks it - a copied template skeleton carries the true retarget data.
- load_items_datatable.py: LEFT - points at a nonexistent /Game/Core/DT_ItemDatabase and fills 3 invented enum rows; ours is /Game/Data/DT_Items, 24 phi-curve rows from the CSV, fill shape already fixed (job 103).
- AssignFactionMesh.py: LEFT - invented mesh path (Minion_Lane_Super_Dawn vs measured SK_Minion_Lane_Super) and invented class name; faction agents are runtime-spawned C++ actors - their bodies are wired in C++ in the agents' tranche.
- The bash manifest: LEFT - wrong project names throughout (VeilGame.uproject); the lane's own sequence stands.

His photos this round: VEIL's plaza wears a SickaEnv floor texture stretched across the whole cube face (giant yellow bands - cube UVs make any photographic texture read at building scale; the mesh-swap tranche is the true cure, material-on-cube is a stopgap), towers in the suit material, T-pose shadow still - all consistent with v1 art + the missing skeleton. OMNI still the blue void until 102/103 land.

---

## Seventh carry - phi reverse-engineering of UE5 (2026-10-27 ~12:39 MDT)

- PhiCameraModifier: LEFT. Its own math cancels (phi^2/(phi+1) = 1.0 by its comment) and then multiplies FOV by 1.37508/aspect - a permanent frustum distortion dressed as framing. The off-center projection note was already taken for the cinematic pass; a modifier class is not the vehicle.
- TSR phi tiers: LEFT - DynamicRes is OFF by standing tune (OperationMode=0, history SP 66.6667); the 61.8033 tier fights the 3050 budget math already sealed in the ini.
- PhiSpiralSpawner: LEFT - duplicates build_world.py's law as a runtime spawner; our sectors are placed and saved, a runtime spawner double-builds the world.
- Nothing in the carry touches a live blocker. The blockers fell to the probe instead (101): the skeleton was in-project all along.

## The 101-105 verdicts (2026-10-27 ~12:33-12:37 MDT)

- THE SKELETON WAS HOME ALL ALONG: /Game/Mannequins/Meshes/SK_Mannequin is a Skeleton asset sitting in the project; both Simple meshes carry an EMPTY skeleton reference (probe: NONE), and the ABP's skeleton reference is broken with it. Job 105 copied the UE4-era SK_Mannequin_Skeleton from Standard\Mannequin into /Game/Character/Mesh/ - present, unreferenced, harmless. The fix is a BIND, not a hunt: bind_skeleton.py sets the real SK_Mannequin onto both meshes + the ABP, compiles, verifies by reload (job 107, with VEIL build + smoke + package attempt 6).
- ITEMS: DONE - fill ok=True, rows in table=24, both games (103).
- MOOD: DONE - PHIPostProcess placed in OMNIWorld + VEILDistrict + VEILWorld (103).
- VEIL ART V2: env pool = 153 (Sicka_EnvPack2: Ancient_Kit + Scifi_Interior); exited 1 again - application lines + cause ride job 107's forensics grep.
- OMNI ART: zero - job 102 searched the WRONG VaultCache root (UnrealEngineLauncher); the true root is C:\ProgramData\Epic\EpicGamesLauncher\VaultCache (job 089's file). Job 108 re-copies LavaMate by the 089 pattern + inventories every pack folder + reruns OMNI art + smoke.
- PACKAGE attempt 5 (104): same ABP error - it ran ahead of any bind; attempt 6 rides the bind in 107.
