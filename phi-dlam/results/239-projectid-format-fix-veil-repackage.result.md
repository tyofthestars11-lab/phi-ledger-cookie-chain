# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:16:16 UTC

## STEP 1
```
=== Job 233 measured: both VEIL cooks now carry exactly ONE distinct Error - LoadConfig import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3 - and the cook fails ExitCode 25 with the ABP at 0 mentions. Job 201 proved the ini HOLDS that dashed string; 233 proves the engine cannot IMPORT it in that form. Presence is not importability. The form the engine itself exports for an FGuid config value is the struct form (A=,B=,C=,D=) with signed int32 components. This job: (1) dumps the ProjectID lines raw bytes so any stray character stands named in the record; (2) backs up both DefaultGame.ini files; (3) rewrites ONLY the value, components computed here from the existing digits - the GUID identity does not change, nothing is hand-typed; (4) verifies the new line; (5) relaunches the VEIL_DONE package ALONE (231/232 launched together and OMNIs UAT died on the single-instance mutex before its log was set). Job 098 removed the line entirely in the old-guid era and the cook then failed on ABP_Unarmed - that asset is gone and the ABP stands quarantined, so that test does not settle this form. ===
VEIL current line: [ProjectID=451B8EAC-A89D-495A-A347-31670EA913C3]
VEIL line bytes: 50 72 6F 6A 65 63 74 49 44 3D 34 35 31 42 38 45 41 43 2D 41 38 39 44 2D 34 39 35 41 2D 41 33 34 37 2D 33 31 36 37 30 45 41 39 31 33 43 33
VEIL rewritten: [ProjectID=(A=1159433900,B=-1466087078,C=-1555615385,D=245961667)]
OMNI current line: [ProjectID=DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C]
OMNI line bytes: 50 72 6F 6A 65 63 74 49 44 3D 44 43 35 45 34 43 46 31 2D 46 44 34 44 2D 34 38 35 45 2D 39 38 46 31 2D 32 42 39 36 41 46 34 33 44 42 34 43
OMNI rewritten: [ProjectID=(A=-597799695,B=-45266850,C=-1729025130,D=-1354507444)]
PACKAGE VEIL_DONE (attempt 2, ProjectID struct form) LAUNCHED: pid 31012, archive D:\Builds\VEIL\VEIL_DONE, log D:\VEIL\Saved\Logs\PackageVEILDone2.log

```
