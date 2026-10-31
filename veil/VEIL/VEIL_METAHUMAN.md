# VEIL OMNI — MetaHuman, whole, phi free

Project: `D:\VEIL-OMNI`, uproject `VEIL.uproject`, EngineAssociation **5.8**,
Windows **x86** (not 32-bit). No paid pack. No package until 100% done.
MetaHuman itself is free inside Unreal Engine; nothing in this file buys
anything, and no Fab MetaHuman pack is added here.

## 0. The unknown error, stated plainly

No MetaHuman error code, error message, or MetaHuman log line was in the
photos or logs supplied for this task, except the two Manager facts in
photo 210 (see cause 1 below) and the earlier record "MetaHuman Core
Data missing, play stuck, no visual edit yet". This file therefore does
**not** name a specific error code as "the" cause. It lists every cause
that is actually in evidence, and the test that tells them apart. Any
one of them, alone, makes MetaHuman look broken; fixing only one and
claiming "MetaHuman fixed" would be a guess.

## 1. Diagnosis — causes actually in evidence

| # | Cause | Evidence in repo / photos / logs | Test that proves / clears it |
|---|---|---|---|
| 1 | Buff_Black not verified, 0 B, 46 refs | Photo 210, MetaHuman Manager: centre "Buff_Black / Skeletal Clothing / Asset has not been verified / Total Size: 0 B / Number of referenced assets: 46" | Manager > Buff_Black > Verify, photo the result. Until Verify passes, Buff is not usable, whatever its 46 references say. |
| 2 | Buff_* are clothing, not a body | Photo 210, left list heading "Clothing (Skeletal)": Buff_Black/Blue/Green/Red/White, Greystone_*, Murdock_* variants. A clothing item cannot stand alone as a player character. | Try to assign Buff as a body: no body, no play. Assign an assembled body mesh instead (section 3). |
| 3 | MetaHuman plugin was NOT in VEIL.uproject | Repo grep before this commit: VEIL.uproject listed EnhancedInput, PythonScriptPlugin, EditorScriptingUtilities, GeometryScripting, ModelingToolsEditorMode, PCG — no MetaHuman entry. | This commit adds `MetaHuman` + `MetaHumanCharacter` (engine plugin names seen in UE LogPluginManager mounting lists). Editor > Edit > Plugins > MetaHuman must show them enabled after pull + install + restart. If the PC editor reports either name as unknown, remove that one entry and photo the message — do not invent a third name. |
| 4 | MetaHuman Creator Core Data missing | Earlier record: "MetaHuman Core Data missing, play stuck, no visual edit yet". Tyree, 2026-10-31: "Need meta 5gb". Installation Options photo 224: a 5.753 GB item checked. Epic's own warning, via forum: "The MetaHuman Creator plugin requires that the MetaHuman Creator Core Data be installed alongside the Engine. Its functionality will be significantly limited without it." | Epic Launcher > Library > Unreal Engine 5.8 > Options > "MetaHuman Creator Core Data" CHECKED > Apply > restart editor. Photo 224 shows it checked; Apply + restart + Creator opening without that warning is the PC proof. This commit cannot install engine data. |
| 5 | No assembled MetaHuman body in the project | Repo `Content/` is empty (.keep only); `veil_omni_load_and_link.py` already lists `/Game/MetaHumans` as a root to check, FOUND or MISSING. A Manager clothing list is not a body. | Run `veil_omni_metahuman_check.py` in an open editor: `/Game/MetaHumans` FOUND with a body, or MISSING. MISSING = no body to assign yet, even if Buff lists fine. |
| 6 | Fab / My Projects registration blocker | Install map, section 3: Fab Add to Project picker and Epic Launcher My Projects showed empty ("You don't have any projects yet") even after editor Open. MetaHuman Fab items land in Content ONLY via Fab Add to Project -> VEIL OMNI. | After pull + install, Epic Launcher > Unreal Engine > My Projects shows VEIL OMNI. If it still shows empty, that screen photo is the next proof — git does not register a project in the launcher by itself. |

Causes 1–6 are not alternatives to pick from. All of them must clear,
in order: Core Data (4) + plugins (3) first, then Verify (1), then a
real body (5) assigned (section 3), with Fab landing (6) as the route
for Fab items. Clothing (2) is never the body.

## 2. What was added in this commit (repo only, not PC proof)

- `veil/VEIL/VEIL.uproject` — `MetaHuman` and `MetaHumanCharacter`
  enabled, EngineAssociation is now 5.8 (see install map, break-circle section). OMNI.uproject is NOT changed:
  VEIL is the merged main module; OMNI is a mirror, not a second game.
- `veil/VEIL/Source/VEIL/Public/Character/VEILCharacter.h` +
  `Private/Character/VEILCharacter.cpp` — `MetaHumanBodyMesh`
  (USkeletalMesh, EditAnywhere/BlueprintReadWrite) +
  `MetaHumanAnimBlueprintClass` + `AssignMetaHumanBody()`, called in
  `BeginPlay()` AFTER the Countess assignment, so: assigned MetaHuman
  wins, empty assignment changes nothing, Countess mesh / primitive
  runner stays as fallback. Log line: `PHI METAHUMAN BODY: <name>
  assigned as runner body.` / `PHI METAHUMAN: no MetaHumanBodyMesh
  assigned ... Countess/primitive body stands.`
- `veil/VEIL/Tools/veil_omni_metahuman_check.py` — guarded editor
  script: lists `/Game/MetaHumans`, `/Game/EditableCharacters`,
  `/Game/MetaHuman`, plus Buff/Greystone/Murdock needles, FOUND or
  MISSING, and prints the checklist in section 4. It does NOT verify,
  package, download, assemble, or delete anything. There is NO
  confirmed UE 5.8 Python API for MetaHuman Manager Verify/Package,
  so no script here claims to do it.
- `veil/VEIL/Tools/veil_omni_install_to_pc.ps1` — now also copies
  this file (`VEIL_METAHUMAN.md`) to `D:\VEIL-OMNI\`, alongside the
  install map. It still never touches `D:\VEIL-OMNI\Content`.
- `veil/VEIL/VEIL_OMNI_INSTALL_MAP.md` — section 6 added below
  (destinations + checklist + not-claimed).

## 3. Assignment path — BP_PlayerCharacter / AVEILCharacter

In the open editor, with a VEILDistrict map open:

1. Open `BP_PlayerCharacter` (class `AVEILCharacter`).
2. Details > VEIL > MetaHuman:
   - `MetaHumanBodyMesh` = an **assembled body mesh** under
     `/Game/MetaHumans/<Name>/Body/` — NOT Buff_Black, NOT a
     clothing item, NOT a Paragon mesh.
   - `MetaHumanAnimBlueprintClass` = that MetaHuman's AnimBlueprint,
     if one is assigned in its assembly; leave empty to keep the
     previous anim class.
3. Buff outfit: apply Buff_Black (or another Buff_*) as clothing on
   that MetaHuman body in Creator / Manager, AFTER the body is
   verified (section 4). Do not put Buff in `MetaHumanBodyMesh`.
4. Compile the Blueprint, save, Play. Output Log must show
   `PHI METAHUMAN BODY:` with the body name, and the viewport must
   show the MetaHuman body in-play. That photo + log line is proof;
   a Blueprint assignment alone is not.

If no assembled body exists yet: create / assemble one in
MetaHuman Creator in-engine (Content Browser > MetaHuman >
MetaHuman Character, then Create Full Rig + Assemble, UE Optimized),
or Add to Project a free MetaHuman from Fab Library -> VEIL OMNI.
Do not hand-assign a Paragon mesh and call it a MetaHuman.

## 4. Editor-only Verify / Package checklist — Buff_Black

Do these in the MetaHuman Manager window (photo 210), in order.
Stop at the first failure and photo it. Do not delete anything.

1. Open the editor on VEILDistrict. Open MetaHuman Manager.
   Left list: Clothing (Skeletal). Select **Buff_Black**.
   Centre must show its details (46 references, materials listed).
2. Click **Verify** (bottom of the Manager window, photo 210).
   Wait for the result. Photo the Verify result line.
   - Pass: continue to step 3.
   - Fail / error text: STOP. Photo the exact error text. Do NOT
     Package, do NOT delete Buff_Black, do NOT reassign its
     references by hand. That error text is the next diagnosis.
3. Only after Verify passes: click **Package**.
   Photo the Package result.
   - Package here is the Manager's Fab-package step (.mhpkg);
     using Buff in VEIL OMNI itself does not wait on a Fab listing,
     but the Manager Verify gate in step 2 is the gate for use.
4. Run `veil_omni_metahuman_check.py` in Output Log Cmd
   (`py "D:\VEIL-OMNI\Tools\veil_omni_metahuman_check.py"`,
   never PowerShell, never `-ExecutePythonScript` for Play).
   Expect Buff needles FOUND, `/Game/MetaHumans` FOUND or MISSING
   with the section 1 meaning, and the checklist printed.
5. Assign a body per section 3, save map, Play, photo in-play.

## 5. Destinations — Fab / Creator -> Tyree's stuff

| Source | Lands in D:\VEIL-OMNI as |
|---|---|
| Fab MetaHuman (free / already-owned), Add to Project -> VEIL OMNI | `Content\MetaHumans\...` (assembly default: `/Game/MetaHumans/`) |
| Assembled MetaHuman Common assets | `Content\MetaHumans\Common\...` (`/Game/MetaHumans/Common`) |
| Pre-assembly MetaHuman Character asset (MHC) | `Content\EditableCharacters\...` (`/Game/EditableCharacters/`) |
| Buff_* clothing | MetaHuman Manager > Clothing (Skeletal) list only — do NOT move Buff files by hand into Content root; Manager folder structure is what Verify checks |
| This file + install map + Tools scripts (git) | `D:\VEIL-OMNI\VEIL_METAHUMAN.md`, `VEIL_OMNI_INSTALL_MAP.md`, `Tools\...` via `veil_omni_install_to_pc.ps1` |
| Maps, Paragon trees, SICKA, Lava (already on PC) | `D:\VEIL-OMNI\Content\...` — install script NEVER touches Content |

## 6. What is NOT claimed by this commit

- MetaHuman is NOT verified, NOT packaged, NOT in-play, and Core
  Data is NOT installed, from a commit alone. Each needs a PC
  editor photo or Output Log line at its own address (section 4).
- No specific "unknown error" code is claimed fixed. The unknown
  error, as supplied, had no code or log line; section 1 is the
  diagnosis, section 4 is the test.
- No MetaHuman body was created or assembled here — the repo has
  no Content, and no MetaHuman DNA / rig data ships in git.
- No package, no cook, no Fab purchase. Packaging gate stands:
  no cook/package/packaged exe until 100% done in project.
