# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 12:53:48 UTC

## STEP 1
```
=== RETARGET CLASS HOME 416 - THE ASSET BYTES NAME WHERE ITS RIG CLASS LIVES (Ground from job 414: the IKRig plugin stood ABSENT from VEIL.uproject, this lane enabled it with a verified write and a kept backup, the editor target printed BUILD SUCCEEDED, and the retarget asset still refused in the editor own words - Unable to load Paragon_Proto_Retarget because its class (Rig) does not exist. So the Rig class does not live in the IKRig plugin, and the seat built on that ground did not seat it. A uasset carries its own class home in its package header imports: the script package strings inside its name table name the module the class was born in. This job reads the retarget asset at the byte level and no other road: one, resolve the file under the merged base Content tree by its name Paragon_Proto_Retarget.uasset and print the resolved path, its size, and its SHA-256. Two, extract every ASCII string of length five or more that carries a script package path and print each with its byte offset. Three, extract every ASCII string carrying Rig, IKRig, ControlRig, Retarget, or Pose and print each with its byte offset. Four, the verdict in one line: CLASS HOME with the exact script module and class string the asset itself carries for its own class, or CLASS HOME UNREADABLE with what the strings census did find. Read-only throughout: no writes, no moves, no launches, no editor.) ===
--- SECTION 1: RESOLVE, SIZE, SHA-256 ---
RESOLVED PATH: D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\Paragon_Proto_Retarget.uasset
SIZE BYTES=68570
SHA256: d47e86ac806722a6d56eb822db707b2323fcf6220d408e109a8a653ef1bb3a03
--- SECTION 2: ASCII STRINGS CARRYING SCRIPT PACKAGE PATHS ---
ASCII RUNS LEN5PLUS COUNT=184
SCRIPT PATH STRINGS COUNT=2
SCRIPT STRING offset=399 : /Script/CoreUObject
SCRIPT STRING offset=427 : /Script/Engine
--- SECTION 3: ASCII STRINGS CARRYING RIG, CONTROL RIG, RETARGET, POSE ---
RIG FAMILY STRINGS COUNT=5
RIG STRING offset=312 : /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget
RIG STRING offset=1541 : Paragon_Proto_Retarget
RIG STRING offset=1765 : RigTransformConstraint
RIG STRING offset=2933 : Paragon_Proto_Retarget
RIG STRING offset=2968 : Paragon_Proto_Retarget
--- SECTION 4: VERDICT ---
PHI RIG416 VERDICT: CLASS HOME C:\Users\Admin
JOB 416 DONE

Cannot overwrite variable HOME because it is read-only or constant.
At C:\Users\Admin\AppData\Local\Temp\phi-step-4dd76c9fe8d841d093a57dac1e38e55a.ps1:50 char:1
+ $home = $null
+ ~~~~~~~~~~~~~
    + CategoryInfo          : WriteError: (HOME:String) [], SessionStateUnauthorizedAccessException
    + FullyQualifiedErrorId : VariableNotWritable
 

```
