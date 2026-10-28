# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 14:26:54 UTC

## STEP 1
```
=== VORTEX CYBERPUNK SHIM 421 - MAKE VORTEX ABLE TO SEE THE CYBERPUNK INSTALL (Ground from job 417, read whole: the Microsoft Xbox build of Cyberpunk 2077 stands whole on D, the base folder D:\XboxGames\Cyberpunk 2077 holding 136 files and 61.3176 GB with the Phantom Liberty expansion in its own sibling folder at 54 files and 30.1006 GB, and no Cyberpunk2077.exe stands anywhere under D XboxGames, the only executables being cpLauncher.exe at 84910032 bytes inside the Content folder and gamelaunchhelper.exe twice. Vortex refuses every folder Tyree points it at because its Cyberpunk check demands bin\x64\Cyberpunk2077.exe under the selected folder, the GOG and Steam layout this build never carried. Tyree gave the word on 2026-10-28 at 08:13 MDT: get Vortex to find the files, or allow him, or whatever it takes. This job is the evidence-plus-shim run under that word. One, it locates cpLauncher.exe with a fresh forced search inside the base folder, errors printed and never swallowed, full path and size in print, and prints the top two directory levels of the base folder by name so the Content layout stands in print. Two, the access read prints the ACL owner and access rules for the Content folder and for cpLauncher.exe itself, then runs a write test that creates and immediately removes a zero byte probe file inside Content, printing WRITE OK or the denial verbatim, answering whether the folder allows additions at all. Three, the shim: only when the write test passed and Content\bin\x64\Cyberpunk2077.exe does not already stand, it creates the bin\x64 folders under Content if absent and places a hardlink named Cyberpunk2077.exe there pointing at cpLauncher.exe, then verifies in the same job that the link stands, that its size equals the cpLauncher size, and that the hardlink count for cpLauncher is at least two, printing SHIM PLACED with the full link path; when Content\bin\x64 already stands with files in it, the job censuses and prints those files and writes nothing, printing SHIM HELD LAYOUT ALREADY PRESENT; when the write test failed, it prints SHIM HELD with the denial as the reason; on any failure after a write it removes only what this job created and prints the removal. Four, the verdict in one line: VORTEX FOLDER READY with folder=D:\XboxGames\Cyberpunk 2077\Content, the folder that then contains bin\x64\Cyberpunk2077.exe, or VORTEX STILL BLIND with the named reason. Nothing moves and no game byte changes; the only creation is the hardlink alias, reversible by deleting the alias alone, and every variable carries the vtx421 prefix under the standing ban on automatic variable names.) ===
--- SECTION 1: LOCATE CPLAUNCHER ---
SEARCH ERROR COUNT=0
LAUNCHER HIT COUNT=1
LAUNCHER: D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe bytes=84910032
LAUNCHER PATH: D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe
LAUNCHER SIZE=84910032
--- BASE FOLDER TOP TWO LEVELS, NAMES ONLY ---
LEVEL1: Content
LEVEL2: Content\archive
LEVEL2: Content\engine
LEVEL2: Content\Manifest
LEVEL2: Content\r6
LEVEL1: Shaders
--- SECTION 2: ACCESS READ ---
CONTENT ACL OWNER: BUILTIN\Administrators
CONTENT RULE: NT AUTHORITY\SYSTEM rights=ReadAndExecute, Synchronize type=Allow
CONTENT RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
CONTENT RULE: BUILTIN\Users rights=Read, Synchronize type=Allow
CONTENT RULE: APPLICATION PACKAGE AUTHORITY\ALL APPLICATION PACKAGES rights=ReadAndExecute, Synchronize type=Allow
CONTENT RULE: BUILTIN\Administrators rights=FullControl type=Allow
CONTENT RULE: BUILTIN\Administrators rights=268435456 type=Allow
CONTENT RULE: NT AUTHORITY\SYSTEM rights=FullControl type=Allow
CONTENT RULE: NT AUTHORITY\SYSTEM rights=268435456 type=Allow
CONTENT RULE: NT AUTHORITY\Authenticated Users rights=Modify, Synchronize type=Allow
CONTENT RULE: NT AUTHORITY\Authenticated Users rights=-536805376 type=Allow
CONTENT RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
CONTENT RULE: BUILTIN\Users rights=-1610612736 type=Allow
LAUNCHER ACL OWNER: BUILTIN\Administrators
LAUNCHER RULE: NT AUTHORITY\SYSTEM rights=ReadAndExecute, Synchronize type=Allow
LAUNCHER RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
LAUNCHER RULE: BUILTIN\Users rights=Read, Synchronize type=Allow
LAUNCHER RULE: APPLICATION PACKAGE AUTHORITY\ALL APPLICATION PACKAGES rights=ReadAndExecute, Synchronize type=Allow
LAUNCHER RULE: BUILTIN\Administrators rights=FullControl type=Allow
LAUNCHER RULE: NT AUTHORITY\SYSTEM rights=FullControl type=Allow
LAUNCHER RULE: NT AUTHORITY\Authenticated Users rights=Modify, Synchronize type=Allow
LAUNCHER RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
WRITE TEST: PROBE CREATED AND STANDING
WRITE OK - PROBE CREATED AND REMOVED
--- SECTION 3: THE SHIM ---
CREATED DIR: D:\XboxGames\Cyberpunk 2077\Content\bin
CREATED DIR: D:\XboxGames\Cyberpunk 2077\Content\bin\x64
NEW-ITEM HARDLINK ERROR: Access is denied
FSUTIL: Error 5: Access is denied.
SHIM FAILED: hardlink creation failed on both the New-Item road and the fsutil road
REMOVED AFTER FAILURE: D:\XboxGames\Cyberpunk 2077\Content\bin\x64
REMOVED AFTER FAILURE: D:\XboxGames\Cyberpunk 2077\Content\bin
--- SECTION 4: VERDICT ---
SHIM STATE: FAILED AND CLEANED
PHI VORTEX421 VERDICT: VORTEX STILL BLIND reason=the shim attempt failed and only its own creations were removed: hardlink creation failed on both the New-Item road and the fsutil road shim_state=FAILED AND CLEANED
JOB 421 DONE

```
