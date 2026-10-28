# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 15:58:55 UTC

## STEP 1
```
=== SKELETON RIG MATCHED CLEAR 425 - THE COUNTESS SKELETON RIG REFERENCE CLEARED THROUGH THE ATTRIBUTE THAT CARRIES IT, READ FROM THE JOB 424 MATCHED LIST AND VERIFIED FROM A FRESH LOAD (Ground from job 420: S_Countess_Skeleton.uasset carries a HARD reference to the unloadable UE 4.19 era asset Paragon_Proto_Retarget from a slot whose bytes carry RigConfig at offset 4884 and RigConfiguration at offset 4902, and every skeleton load prints the warning that its class Rig does not exist. Ground from job 422: clearing through the editor property names rig_config and RigConfig held with property not found, and the skeleton was restored byte-identical. Ground from job 424, read whole: the loaded skeleton exposed 8 attribute names through Python introspection in the rig and config and skeleton and retarget family - add_compatible_skeleton, add_compatible_skeleton_soft, compatible_skeletons, copy_bones_from_skeleton, get_skeleton_additional_preview_meshes, get_skeleton_preview_mesh, set_skeleton_additional_preview_meshes, set_skeleton_preview_mesh - while all 6 direct property candidates missed, so the reference, if the editor Python surface reaches it at all, stands inside one of those 8 matched attributes as a sub-object or a differently shaped container. One, the skeleton is backed up to the Saved folder as S_Countess_Skeleton.phi-backup-425 with the backup path and size printed, and the live file SHA-256 is verified against the standing measure 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941 before any write; a moved hash prints HASH MOVED and closes HELD untouched. Two, a pythonscript commandlet loads the skeleton and reads every one of the 8 matched attributes whole, values rendered in print, method attributes named as methods with the two getter methods called and their returned values printed, and the attribute whose value references Paragon_Proto_Retarget or holds the rig is named as the carrier. Three, where a carrier stands, the reference is cleared through that carrier by its own shape, the after-read prints empty, and the asset is saved through the editor API with the save result printed; where no carrier stands among the matched attributes, the job prints NO CARRIER FOUND and closes without writing, adding the closing line that the thread closes cosmetic because the reference is not reachable through the editor Python surface and the skeleton loads and animates with the warning as log noise only. Four, only where a clear was saved, a second fresh commandlet verifies the whole fix: the skeleton loaded again with its matched attributes read fresh and the carrier expected empty, the registry referencers of Paragon_Proto_Retarget re-read with zero expected and the count printed, and the fresh load log lines carrying Paragon_Proto_Retarget counted with zero expected. Five, any failure after a write, or a fresh read still showing the reference standing, restores the skeleton from the backup and prints SKELETON RESTORED with the stage named before closing HELD. The verdict in one line: RIG SLOT CLEARED with the carrier name and the referencer and warning counts, or RIG SLOT HELD with the stage named. Every variable carries the rig425 prefix under the standing ban on automatic variable names.) ===
PHI RIG425 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: TARGET, HASH GATE, AND BACKUP BEFORE ANY WRITE ---
PHI RIG425 TARGET FILE: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\S_Countess_Skeleton.uasset
PHI RIG425 SIZE BYTES=44707
PHI RIG425 SHA256: 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941
PHI RIG425 BACKUP WRITTEN: D:\VEIL-OMNI\Saved\S_Countess_Skeleton.phi-backup-425
PHI RIG425 BACKUP SIZE BYTES=44707
PHI RIG425 HASH GATE PASSED: the live skeleton matches the standing measure
--- SECTION 2: READ THE MATCHED ATTRIBUTES AND CLEAR THROUGH THE CARRIER (PART A) ---
PHI RIG425 LOAD OK=1
PHI RIG425 LOADED CLASS=Skeleton
PHI RIG425 ATTR add_compatible_skeleton KIND=METHOD
PHI RIG425 ATTR add_compatible_skeleton_soft KIND=METHOD
PHI RIG425 ATTR compatible_skeletons KIND=VALUE TYPE=Array
PHI RIG425 ATTR compatible_skeletons VALUE: []
PHI RIG425 ATTR compatible_skeletons EDITOR VALUE: []
PHI RIG425 ATTR copy_bones_from_skeleton KIND=METHOD
PHI RIG425 ATTR get_skeleton_additional_preview_meshes KIND=METHOD
PHI RIG425 ATTR get_skeleton_additional_preview_meshes CALL VALUE: NONE
PHI RIG425 ATTR get_skeleton_preview_mesh KIND=METHOD
PHI RIG425 ATTR get_skeleton_preview_mesh CALL VALUE: /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess
PHI RIG425 ATTR set_skeleton_additional_preview_meshes KIND=METHOD
PHI RIG425 ATTR set_skeleton_preview_mesh KIND=METHOD
PHI RIG425 CARRIER FOUND=0
PHI RIG425 PART A COMPLETE
PHI RIG425 NO CARRIER FOUND: none of the 8 matched attributes carries the retarget reference on the editor Python surface
PHI RIG425 THREAD CLOSES COSMETIC - the reference is not reachable through the editor Python surface, the skeleton loads and animates with the warning as log noise only
PHI RIG425 VERDICT: RIG SLOT HELD - stage=no carrier; no attribute among the job 424 matched list holds the reference, so nothing was written
JOB 425 DONE

```
