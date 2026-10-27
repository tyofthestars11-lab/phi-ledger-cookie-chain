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
