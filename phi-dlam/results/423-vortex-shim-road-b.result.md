# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 14:39:21 UTC

## STEP 1
```
=== VORTEX SHIM ROAD B 423 - THE FILESYSTEM TYPE READ, THE HARDLINK CAPABILITY PROBED WITH TEMP FILES, AND THE CYBERPUNK2077.EXE ALIAS PLACED AS HARDLINK OR COPY BY WHAT THE PROBE PROVES (Ground from job 421, read whole: inside the Content folder of the Microsoft Xbox Cyberpunk 2077 install on D a zero byte write probe passed so additions are allowed, but creating a hardlink to cpLauncher.exe at 84910032 bytes was refused with Access denied on both the New-Item road and the fsutil road, and the bin and bin x64 folders the job created were removed after the failure. Two candidate causes stand open: the D volume filesystem may not support hardlinks at all, the drive showing as a Lexar volume where exFAT carries no hardlink form, or the cpLauncher file itself is protected against linking. One, the job prints the D volume filesystem type on its own FILESYSTEM line from Get-Volume with a CIM fallback. Two, the capability probe creates a small temp file inside Content, attempts a hardlink to it under a second temp name by the New-Item road and then the fsutil road, prints PROBE HARDLINK OK or the denial verbatim, removes both temp files, and prints the cleanup, so capability is measured on a file the job itself owns before the game file is touched again. Three, the placement follows the probe: if Content bin x64 Cyberpunk2077.exe already stands it is verified and printed and the job stops; otherwise the bin and bin x64 folders are created if absent, and when the probe hardlink worked the alias is placed as a hardlink to cpLauncher.exe, with a launcher denial at that point printed beside the probe result as the pairing that names the file itself as the protected party; when the probe hardlink failed or the launcher hardlink is denied, the alias is placed as a full copy of cpLauncher.exe instead. Whatever is placed is verified standing with its size equal to 84910032 and printed as PLACED AS HARDLINK or PLACED AS COPY with the full path. Four, on total refusal both denials print verbatim and the cleanup removes only what this job created, the alias file if it made one and any folder it created that stands empty. Five, the verdict in one line: VORTEX FOLDER READY with folder=D XboxGames Cyberpunk 2077 Content and the form named, or VORTEX STILL BLIND with the filesystem type and the denials named. Nothing moves, no game byte changes, the alias is the only addition and stands reversible by its own deletion, and every variable carries the vtx423 prefix under the standing ban on automatic variable names.) ===
--- SECTION 1: D VOLUME FILESYSTEM TYPE ---
FILESYSTEM=NTFS
--- SECTION 2: HARDLINK CAPABILITY PROBE INSIDE CONTENT ---
PROBE SOURCE CREATED: D:\XboxGames\Cyberpunk 2077\Content\phi423_probe_src.tmp
PROBE HARDLINK OK
PROBE CLEANUP REMOVED: D:\XboxGames\Cyberpunk 2077\Content\phi423_probe_link.tmp
PROBE CLEANUP REMOVED: D:\XboxGames\Cyberpunk 2077\Content\phi423_probe_src.tmp
PROBE FILES GONE CHECK: link=False source=False
--- SECTION 3: THE PLACEMENT ---
CREATED DIR: D:\XboxGames\Cyberpunk 2077\Content\bin
CREATED DIR: D:\XboxGames\Cyberpunk 2077\Content\bin\x64
LAUNCHER NEW-ITEM HARDLINK DENIAL: Access is denied
FSUTIL: Error 5: Access is denied.
PAIRING: PROBE HARDLINK OK BUT THE LAUNCHER HARDLINK WAS DENIED - THE DENIAL BELONGS TO THE CPLAUNCHER FILE ITSELF, SO THE COPY ROAD RUNS
COPY DENIAL: Access to the path 'D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe' is denied.
CLEANUP REMOVED EMPTY DIR: D:\XboxGames\Cyberpunk 2077\Content\bin\x64
CLEANUP REMOVED EMPTY DIR: D:\XboxGames\Cyberpunk 2077\Content\bin
--- SECTION 4: VERDICT ---
PHI VORTEX423 VERDICT: VORTEX STILL BLIND filesystem=NTFS probe_denial= launcher_hardlink_denial=Access is denied copy_denial=Access to the path 'D:\XboxGames\Cyberpunk 2077\Content\cpLauncher.exe' is denied.
JOB 423 DONE

```
