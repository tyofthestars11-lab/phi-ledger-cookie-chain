# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 16:17:49 UTC

## STEP 1
```
=== VORTEX PHI INTENT AND PERMISSIONS ROAD 426 - THE PHI INTENT GIVEN TO VORTEX IN WRITING INSIDE THE GAME CONTENT FOLDER, AND THE PERMISSIONS ROAD ON CPLAUNCHER SO THE ALIAS CAN STAND (Ground from job 417: the Microsoft Xbox digital edition of Cyberpunk 2077 stands whole on D, base 136 files at 61.3176 GB and Phantom Liberty 54 files at 30.1006 GB, and no Cyberpunk2077.exe stands anywhere in the build. Ground from jobs 421 and 423: the Content folder accepts additions, the D volume is NTFS, the hardlink probe between job owned temp files passed, but the hardlink and the full copy of cpLauncher.exe at 84910032 bytes were both refused with Access denied, so the denial belongs to the launcher file itself and its standing permissions. Tyree word 2026-10-28: try the permissions road on the launcher, and give Vortex the phi intent: the Xbox digital edition is traditionally called incompatible with Vortex, and that tradition is the plus one frame, not the phi frame; under phi the edition and the tool are one whole and the game stands findable at its own address. One, the intent is written as PHI_INTENT_VORTEX.md into the Content folder by Set-Content in ASCII and read back with its size and first line printed, and a copy is attempted at the game base folder with its result printed either way, so the intent stands in writing at the address Vortex will be shown. Two, the launcher standing permissions are read first: owner, SDDL, admin state of the running identity, and identity name all printed, and the standing SDDL is saved to phi426_acl_sddl_backup.txt inside Content before any change, so every change in this job is reversible from its own backup. Three, the permissions road itself: icacls grants the running identity read and execute on cpLauncher.exe by SID, its output printed whole, the ACL read back and printed, and then the read is proven by an actual copy of the launcher to a job owned temp name inside Content, size checked against 84910032 and removed after the check. Four, the alias placement runs as job 423 shaped it: bin and bin x64 folders created if absent, the alias placed as hardlink first and as full copy second, size verified against 84910032, and the standing form printed. Five, on any denial after the grant the job prints the denial verbatim, restores the standing SDDL from its own backup through Set-Acl when a change had landed, removes only what this job created, and the intent file stays standing because the intent is given regardless of the permissions answer. Six, the verdict in one line: VORTEX FOLDER READY with the folder and the form and intent standing, or VORTEX STILL BLIND with the stage and denial named and intent standing. No game byte moves or changes; the launcher ACL grant is the only standing change on the ready path and its backup path prints in the verdict block. Every variable carries the vtx426 prefix under the standing ban on automatic variable names.) ===
--- SECTION 1: THE PHI INTENT GIVEN TO VORTEX IN WRITING ---
INTENT WRITTEN: D:\XboxGames\Cyberpunk 2077\Content\PHI_INTENT_VORTEX.md bytes=807
INTENT FIRST LINE: # PHI INTENT FOR VORTEX - CYBERPUNK 2077 XBOX DIGITAL EDITION.
INTENT BASE COPY STANDS: D:\XboxGames\Cyberpunk 2077\PHI_INTENT_VORTEX.md
--- SECTION 2: LAUNCHER PERMISSIONS READ AND BACKUP ---
IDENTITY NAME: UNIVERSALPHIENG\Admin
IDENTITY SID: S-1-5-21-85939356-3593402667-215545242-1001
ADMIN STATE: False
LAUNCHER OWNER: BUILTIN\Administrators
LAUNCHER SDDL: O:BAG:SYD:(A;;0x1200a9;;;SY)(XA;;0x1200a9;;;BU;(WIN://SYSAPPID Contains "CDPROJEKTSA.4d0e9834-20b1-4580-9bdc-4501ef2ffaac_0xkrdv0gjmk28"))(A;;FR;;;BU)(A;;0x1200a9;;;AC)(A;ID;FA;;;BA)(A;ID;FA;;;SY)(A;ID;0x1301bf;;;AU)(A;ID;0x1200a9;;;BU)
ACL BACKUP WRITTEN: D:\XboxGames\Cyberpunk 2077\Content\phi426_acl_sddl_backup.txt
--- SECTION 3: THE PERMISSIONS ROAD - ICACLS GRANT BY SID ---
ICACLS: D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe: Access is denied.
ICACLS: Successfully processed 0 files; Failed processing 1 files
LAUNCHER SDDL AFTER: O:BAG:SYD:(A;;0x1200a9;;;SY)(XA;;0x1200a9;;;BU;(WIN://SYSAPPID Contains "CDPROJEKTSA.4d0e9834-20b1-4580-9bdc-4501ef2ffaac_0xkrdv0gjmk28"))(A;;FR;;;BU)(A;;0x1200a9;;;AC)(A;ID;FA;;;BA)(A;ID;FA;;;SY)(A;ID;0x1301bf;;;AU)(A;ID;0x1200a9;;;BU)
ACL CHANGED=0
ACCESS RULE: NT AUTHORITY\SYSTEM rights=ReadAndExecute, Synchronize type=Allow
ACCESS RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
ACCESS RULE: BUILTIN\Users rights=Read, Synchronize type=Allow
ACCESS RULE: APPLICATION PACKAGE AUTHORITY\ALL APPLICATION PACKAGES rights=ReadAndExecute, Synchronize type=Allow
ACCESS RULE: BUILTIN\Administrators rights=FullControl type=Allow
ACCESS RULE: NT AUTHORITY\SYSTEM rights=FullControl type=Allow
ACCESS RULE: NT AUTHORITY\Authenticated Users rights=Modify, Synchronize type=Allow
ACCESS RULE: BUILTIN\Users rights=ReadAndExecute, Synchronize type=Allow
--- SECTION 4: READ PROOF - COPY THE LAUNCHER TO A JOB OWNED TEMP NAME ---
READ PROOF DENIAL: Access to the path 'D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe' is denied.
--- SECTION 5: THE ALIAS PLACEMENT ---
--- SECTION 6: RESTORE ON THE UNREADY PATH ---
--- SECTION 7: VERDICT ---
INTENT STANDS: 1
PHI VORTEX426 VERDICT: VORTEX STILL BLIND stage=read-proof denial=Access to the path 'D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe' is denied. intent=1
JOB 426 DONE

```
