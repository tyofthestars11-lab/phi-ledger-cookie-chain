# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 08:17:21 UTC

## STEP 1
```
=== CCD + ROTATION LOCKS + SUBSTEP 0.01 - JOB 372 (Third study relay, folded whole: the discrete-versus-continuous production fixes, with the mapping onto our pawn made explicit in the relay itself. Our pawn is C++ and a Character WITH a Movement Component - VEILCharacter is an ACharacter C++ class and job 338 prints read the CharacterMovement directly - so she carries both halves at once: the capsule answers to the movement component (discrete floor sweeps; the floor-complexity fix rides job 369, AlwaysCheckFloor rides job 371), while the mesh, IF it is simulating, answers to the physics solver, where CCD, rotation locks and substepping are the governing fixes. For a character pawn the production form is simulate OFF, which job 371 sets; CCD, locks and substepping stand as the settings that protect every simulating body in the game, and this job sets them in their true forms. One, CCD on the mesh body: FBodyInstance bUseCCD = true at class level in the constructor (the flags are read when the physics state is created), with SetCCDEnabled enforced again at BeginPlay. Two, the tumble axes locked: bLockXRotation and bLockYRotation = true on the same BodyInstance - pitch and roll locked, yaw free - so no body wearing this mesh can tumble while it simulates. Three, substepping normalized to the paste own value: job 369 sets MaxSubstepTime=0.016667 only where the section stands absent; the study specifies 0.01 (10 ms micro-steps), and this job normalizes DefaultEngine.ini to bSubstepping=True, MaxSubstepTime=0.01, MaxSubsteps=6 - line-counted edits, backup first (.phi-backup-372), every key verified by read-back, and if the section stands absent here too the whole section is appended with the paste values. Four, the source patch verifies itself by read-back before compile, per the PHI GUARANTEE; anchor misses stop the job before any write. Five, compile the editor target and run VEILDistrict: the PHI CCDLOCK 372 proof line prints ccd, lockX and lockY as read at spawn, beside the 371 and 365 lines where they stand. Merged base at D VEIL-OMNI only; the parents are archive.) ===
--- SECTION 1: SUBSTEPPING NORMALIZE TO 0.01 ---
ENG BEFORE 67: [/Script/Engine.PhysicsSettings]
ENG BEFORE 68: bSubstepping=True
ENG BEFORE 69: MaxSubstepTime=0.016667
ENG BEFORE 70: MaxSubsteps=6
KEY SET: bSubstepping=True (stood x1)
KEY SET: MaxSubstepTime=0.01 (stood x1)
KEY SET: MaxSubsteps=6 (stood x1)
VERIFY bSubstepping=True: True
VERIFY MaxSubstepTime=0.01: True
VERIFY MaxSubsteps=6: True
--- SECTION 2: CCD + LOCKS SOURCE PATCH ---
CPP: D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp
CPP BACKED UP (.phi-backup-372)
PATCHED + VERIFIED in file (ccdlock blocks x2)
--- SECTION 3: COMPILE + RUN ---
BUILD exit: 6
D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp(147,71): error C2039: 'SetCCDEnabled': is not a member of 'FBodyInstance'
D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp(158,9): error C2027: use of undefined type 'UPhysicsAsset'
Total time in Unreal Build Accelerator local executor: 1.96 seconds
Result: Failed (OtherCompilationError)
BUILD FAILED - no game run.
JOB 372 STOPPED AFTER BUILD

```
