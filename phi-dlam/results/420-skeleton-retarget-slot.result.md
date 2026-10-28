# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 14:15:17 UTC

## STEP 1
```
=== SKELETON RETARGET SLOT 420 - THE SKELETON SIDE OF THE REFERENCE TO THE LEGACY RIG ASSET (Ground from job 419, read whole: Paragon_Proto_Retarget.uasset, a UE 4.19 era asset whose class Rig does not exist in this engine build, stands REFERENCED with exactly one referencer, /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/S_Countess_Skeleton, the Countess own skeleton asset at 44707 bytes in the same Meshes folder, with source refs zero and config refs zero, so the skeleton itself carries the reference to the unloadable legacy rig. This job reads the skeleton side of that reference and no other road, so the fix for the missing Rig class is authored against the exact slot that carries it. One, print the skeleton file size and SHA-256. Two, the byte census prints every ASCII string of length four or more carrying Rig, Retarget, Proto, or /Script/ with its byte offset, uncapped, and the slot name the skeleton uses for this reference stands among them. Three, the registry dependency read prints the dependency type the registry records between S_Countess_Skeleton and Paragon_Proto_Retarget, probed with hard-only and soft-only option sets beside the full set, because a hard reference loads with the skeleton while a soft one loads on demand. Four, load S_Countess_Skeleton in a pythonscript commandlet, print the loaded class name, and print every line of the load log carrying Retarget, Rig, Failed, Unable, or Missing, the skeleton load being where the warning fires. Five, the verdict in one line: SKELETON REFERENCE with the slot string named and the dependency type stated, or REFERENCE FORM UNREADABLE with the counts. Read-only throughout: no edits, no moves, and every variable carries the skl420 prefix under the standing ban on automatic variable names.) ===
PHI SKL420 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: RESOLVE, SIZE, SHA-256 ---
PHI SKL420 TARGET FILE: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\S_Countess_Skeleton.uasset
PHI SKL420 SIZE BYTES=44707
PHI SKL420 SHA256: 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941
--- SECTION 2: BYTE CENSUS - RIG RETARGET PROTO AND SCRIPT STRINGS WITH OFFSETS UNCAPPED ---
PHI SKL420 ASCII RUNS LEN4PLUS COUNT=515
PHI SKL420 FAMILY STRINGS COUNT=10
PHI SKL420 SCRIPT STRINGS COUNT=2
FAMILY STRING offset=332 : /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget
FAMILY STRING offset=667 : /Script/CoreUObject
FAMILY STRING offset=695 : /Script/Engine
FAMILY STRING offset=1690 : EBoneTranslationRetargetingMode
FAMILY STRING offset=1730 : EBoneTranslationRetargetingMode::Animation
FAMILY STRING offset=4392 : Paragon_Proto_Retarget
FAMILY STRING offset=4884 : RigConfig
FAMILY STRING offset=4902 : RigConfiguration
FAMILY STRING offset=6783 : TranslationRetargetingMode
FAMILY STRING offset=11462 : Rig /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget.Paragon_Proto_Retarget
SLOT RULE: the slot candidate is the first family string in file order that carries Rig with no path separator and no Paragon text; if none stands, the first family string carrying the full Paragon_Proto_Retarget name stands as the slot text
PHI SKL420 SLOT CANDIDATE: RigConfig offset=4884
--- SECTION 3: REGISTRY DEPENDENCY FORM ---
PHI SKL420 DEP ALL COUNT=2
PHI SKL420 DEP: /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget
PHI SKL420 DEP: /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess
PHI SKL420 DEP IN ALL=1
PHI SKL420 DEP HARD HIT=1
PHI SKL420 DEP SOFT HIT=0
PHI SKL420 REGISTRY READ COMPLETE
PHI SKL420 DEP TYPE=HARD
--- SECTION 4: SKELETON LOAD AND ITS LOG ---
PHI SKL420 LOADED CLASS=Skeleton
PHI SKL420 LOADED CLASS PATH=/Script/Engine.Skeleton
PHI SKL420 LOAD READ COMPLETE
PHI SKL420 LOAD LOG HIT COUNT=9
LOAD LOG: Unable to find required SDK version 'MainVersion' for platform LinuxArm64. Check your SDK.json files
LOAD LOG: Unable to find required SDK version 'MainVersion' for platform VisionOS. Check your SDK.json files
LOAD LOG: [2026.10.28-14.15.29:987][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Android'
LOAD LOG: [2026.10.28-14.15.30:008][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'IOS'
LOAD LOG: [2026.10.28-14.15.30:029][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Linux'
LOAD LOG: [2026.10.28-14.15.30:053][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Mac'
LOAD LOG: [2026.10.28-14.15.30:054][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'TVOS'
LOAD LOG: [2026.10.28-14.15.34:883][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
LOAD LOG: [2026.10.28-14.15.37:030][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
--- SECTION 5: VERDICT ---
PHI SKL420 VERDICT: SKELETON REFERENCE slot=RigConfig dep=HARD
JOB 420 DONE

```
