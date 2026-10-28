# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 14:39:24 UTC

## STEP 1
```
=== SKELETON RIG PROPERTY NAME 424 - THE TRUE NAME OF THE RIG SLOT READ FROM THE SKELETON BYTES AROUND THE RIGCONFIG STRINGS AND FROM THE LOADED OBJECT ITSELF (Ground from job 422, read whole: clearing the Countess skeleton RigConfig slot held because the editor Python property read could not find the property under the names probed, rig_config and RigConfig, the read answering Failed to find property for attribute on Skeleton, and the skeleton was restored from its backup byte-identical at SHA-256 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941. Ground from job 420 stands beside it: the skeleton bytes carry the string RigConfig at offset 4884 and a RigConfiguration string at offset 4902, so a rig slot exists in the package even where the Python names missed it. One, the byte context prints every ASCII string standing within offsets 4600 to 5300 of the skeleton file, in file order with offsets, so the names neighbouring the two rig strings stand in print whole. Two, a pythonscript commandlet loads the skeleton and prints every attribute name the loaded object exposes through Python introspection carrying rig, config, skeleton, or retarget, uncapped and with the match count, then attempts get_editor_property on each candidate name in turn, RigConfig, rig_config, RigConfiguration, rig_configuration, Rig, and rig, printing HIT with the value rendered or MISS with the denial. Three, the loaded class property names carrying rig or config print the same way where the API offers that list, with the refusal printed where it does not. Four, the verdict in one line: PROPERTY FOUND with the exact name and its rendered value, or PROPERTY NOT EXPOSED with the introspection counts, so the clearing job that follows uses the name the engine itself answers to. Read-only throughout, the editor guard waits inside the job on the standing 100 second bound with a named hold, and every variable carries the rig424 prefix under the standing ban on automatic variable names.) ===
PHI RIG424 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: BYTE CONTEXT OFFSETS 4600 TO 5300 ---
PHI RIG424 TARGET FILE: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\S_Countess_Skeleton.uasset
PHI RIG424 SIZE BYTES=44707
STRING @4617: R_brow_outer
STRING @4638: R_cheek_inner
STRING @4660: R_eye
STRING @4674: R_eye_lid_lower_mid
STRING @4702: R_eye_lid_upper_mid
STRING @4730: R_lip_corner
STRING @4751: R_lip_lower_outer
STRING @4777: R_lip_upper_outer
STRING @4803: RelativeLocation
STRING @4828: RelativeRotation
STRING @4853: ResetCombo
STRING @4884: RigConfig
STRING @4902: RigConfiguration
STRING @4927: ring_01_l
STRING @4945: ring_01_r
STRING @4963: ring_02_l
STRING @4981: ring_02_r
STRING @4999: ring_03_l
STRING @5017: ring_03_r
STRING @5035: root
STRING @5048: Root
STRING @5061: Rotator
STRING @5077: S_Countess_Skeleton
STRING @5105: SaveAttack
STRING @5124: sheath_l
STRING @5141: sheath_r
STRING @5158: shoulderpad_01_SHOGUN_l
STRING @5190: shoulderpad_01_SHOGUN_r
STRING @5222: shoulderpad_02_SHOGUN_l
STRING @5254: shoulderpad_02_SHOGUN_r
STRING @5286: shoulderpad_03_SHOGUN_l
RANGE STRING COUNT=31
--- SECTION 2: PROPERTY ENUMERATION IN THE COMMANDLET ---
PHI RIG424 LOAD OK=1
PHI RIG424 LOADED CLASS=Skeleton
PHI RIG424 LOADED CLASS PATH=/Script/Engine.Skeleton
PHI RIG424 INTROSPECTION MATCH COUNT=8
PHI RIG424 ATTR: add_compatible_skeleton
PHI RIG424 ATTR: add_compatible_skeleton_soft
PHI RIG424 ATTR: compatible_skeletons
PHI RIG424 ATTR: copy_bones_from_skeleton
PHI RIG424 ATTR: get_skeleton_additional_preview_meshes
PHI RIG424 ATTR: get_skeleton_preview_mesh
PHI RIG424 ATTR: set_skeleton_additional_preview_meshes
PHI RIG424 ATTR: set_skeleton_preview_mesh
PHI RIG424 MISS RigConfig denial=Skeleton: Failed to find property 'RigConfig' for attribute 'RigConfig' on 'Skeleton'
PHI RIG424 MISS rig_config denial=Skeleton: Failed to find property 'rig_config' for attribute 'rig_config' on 'Skeleton'
PHI RIG424 MISS RigConfiguration denial=Skeleton: Failed to find property 'RigConfiguration' for attribute 'RigConfiguration' on 'Skeleton'
PHI RIG424 MISS rig_configuration denial=Skeleton: Failed to find property 'rig_configuration' for attribute 'rig_configuration' on 'Skeleton'
PHI RIG424 MISS Rig denial=Skeleton: Failed to find property 'Rig' for attribute 'Rig' on 'Skeleton'
PHI RIG424 MISS rig denial=Skeleton: Failed to find property 'rig' for attribute 'rig' on 'Skeleton'
PHI RIG424 CLASS ATTR MATCH COUNT=0
PHI RIG424 READ COMPLETE
--- SECTION 3: VERDICT ---
PHI RIG424 VERDICT: PROPERTY NOT EXPOSED introspection_matches=8 candidate_misses=6
JOB 424 DONE

```
