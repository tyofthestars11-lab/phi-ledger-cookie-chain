# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 14:08:35 UTC

## STEP 1
```
=== RETARGET REFERENCERS 419 - WHO IN THE GAME ACTUALLY LOADS THE LEGACY RIG ASSET (Ground from job 418, read whole: Paragon_Proto_Retarget.uasset stands byte-identical to the 416 measure at 68570 bytes with SHA-256 d47e86ac806722a6d56eb822db707b2323fcf6220d408e109a8a653ef1bb3a03, its name map carries the constraint family strings RigTransformConstraint, EConstraintTransform, TransformBaseConstraint, and TransformConstraints with its candidate print naming Constraints, its only script package homes are /Script/CoreUObject and /Script/Engine, and the editor refuses to load it because its class (Rig) does not exist in this engine build, which reads as a legacy UE4 4.19 asset whose class was removed from the engine. The decisive open question is whether anything in the merged base actually references this asset at all, because an asset nothing loads only warns and never touches runtime. This job reads the asset registry referencers for Paragon_Proto_Retarget and greps the source and config trees for its name, so the Rig class thread closes on whether anything in the game actually loads it. One, the registry referencer read prints the hard and soft referencers whole or REFERENCERS EMPTY. Two, the source grep prints every line under the Source tree carrying Paragon_Proto_Retarget or Proto_Retarget with file names and line numbers, or SOURCE REFS NONE. Three, the config grep prints the same two tokens under the Config tree the same way, or CONFIG REFS NONE. Four, the census of the Meshes folder the asset sits in prints every sibling asset name with its size, so the whole folder contents stand in print beside it. Five, the verdict in one line: REFERENCED with the combined count and the first referencer named, or UNREFERENCED with all three counts at zero, the load warning then standing as cosmetic on a legacy asset nothing loads at runtime. Read-only throughout: no edits, no moves, and every variable carries the ref419 prefix under the standing ban on automatic variable names.) ===
PHI REF419 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
PHI REF419 TARGET FILE: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\Paragon_Proto_Retarget.uasset
--- SECTION 1: ASSET REGISTRY REFERENCERS ---
PHI REF419 REFERENCER COUNT=1
PHI REF419 REFERENCER: /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/S_Countess_Skeleton
PHI REF419 REGISTRY READ COMPLETE
--- SECTION 2: SOURCE GREP ---
PHI REF419 SOURCE HIT COUNT=0
SOURCE REFS NONE
--- SECTION 3: CONFIG GREP ---
PHI REF419 CONFIG HIT COUNT=0
CONFIG REFS NONE
--- SECTION 4: MESHES FOLDER CENSUS ---
PHI REF419 MESHES FOLDER: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes
PHI REF419 SIBLING COUNT=5
SIBLING: PA_Countess_Phat_CylShadows.uasset size=114266
SIBLING: PA_Countess_Phat_Extents.uasset size=111515
SIBLING: Paragon_Proto_Retarget.uasset size=68570
SIBLING: S_Countess_Skeleton.uasset size=44707
SIBLING: SM_Countess.uasset size=12684538
--- SECTION 5: VERDICT ---
PHI REF419 VERDICT: REFERENCED count=1 referencers=1 source=0 config=0 first=/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/S_Countess_Skeleton
JOB 419 DONE

```
