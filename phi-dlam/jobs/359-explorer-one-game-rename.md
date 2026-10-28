<!-- PHI-DIRECT -->
```powershell
Write-Output '=== EXPLORER READS ONE GAME - THE MERGED BASE STANDS UNDER THE VEIL OMNI NAME (From Tyrees photo after his restart, 2026-10-28 01:37 MDT: Where is the game.? I still see 2. The photo is File Explorer: folders VEIL and OMNI-UE both standing on D, and the Recent list carrying two Unreal projects. The door swap fixes his desktop; this job fixes Explorer itself. The safe form, assessed here and verified in-job per the phi guarantee: the merged base FOLDER renames from D:\VEIL to D:\VEIL-OMNI - same drive, a rename, nothing moves between drives - while the .uproject file and the module keep their names inside, because the module identity (the VEIL_API macros, LogVEIL, the code the whole port line compiled against) is not presentation and renaming it is a refactor, not a rename. Before any rename, the job censuses every hardcoded D:\VEIL path reference in the project configs and prints them, so the blast radius is read, not guessed. Sequencing: this job runs LAST in the restart drain, after 355, 356, 357 and 358, because those jobs address the base at its current path; it first prints the prerequisite states (355 import print, 356 crossfix print, the door from 357, the 358 pack log) and stops clean if the base is not where the drain left it. After the rename: the desktop door is repointed to the new path and verified by read-back, the renamed project is opened once through the editor binary so it tops his Recent list by use, and the job closes with the one-game census print - D root game folders, the archive beside them, the door - against the photos two.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 359 DEFERRED'; return }
$old = 'D:\VEIL'; $new = 'D:\VEIL-OMNI'
Write-Output ("PHI ONE GAME PREREQ dt-import: " + (Test-Path "$old\Saved\phi_dt_import_out.txt"))
Write-Output ("PHI ONE GAME PREREQ crossfix: " + (Test-Path "$old\Saved\phi_crossfix_out.txt"))
Write-Output ("PHI ONE GAME PREREQ door: " + (Test-Path "$env:USERPROFILE\Desktop\VEIL OMNI - The Last Signal - Path of Light.lnk"))
Write-Output ("PHI ONE GAME PREREQ pack-log: " + (Test-Path 'D:\VEIL-OMNI-ARCHIVE\pack358.log'))
if (-not (Test-Path $old)) { Write-Output 'BASE FOLDER D:\VEIL NOT FOUND - nothing renamed.'; Write-Output 'JOB 359 STOPPED'; return }
if (Test-Path $new) { Write-Output 'D:\VEIL-OMNI ALREADY EXISTS - nothing renamed.'; Write-Output 'JOB 359 STOPPED'; return }
Write-Output '--- hardcoded path census (pre-rename read) ---'
Get-ChildItem "$old\Config", "$old\Source" -Recurse -File -Include '*.ini','*.cs','*.cpp','*.h' -ErrorAction SilentlyContinue | Select-String -SimpleMatch 'D:\VEIL' -List | ForEach-Object { Write-Output ("PHI PATHREF: " + $_.Path) }
Rename-Item $old $new
if (-not (Test-Path $new)) { Write-Output 'RENAME FAILED'; Write-Output 'JOB 359 STOPPED'; return }
Write-Output 'PHI ONE GAME RENAMED: D:\VEIL -> D:\VEIL-OMNI (folder only; uproject and module names unchanged inside)'
$uproj = Get-ChildItem $new -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
Write-Output "PHI ONE GAME UPROJECT: $uproj"
$ws = New-Object -ComObject WScript.Shell
$lnkPath = "$env:USERPROFILE\Desktop\VEIL OMNI - The Last Signal - Path of Light.lnk"
$editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$lnk = $ws.CreateShortcut($lnkPath)
$lnk.TargetPath = $editor
$lnk.Arguments = '"' + $uproj + '" -game'
$lnk.WorkingDirectory = $new
$lnk.Description = 'VEIL OMNI - the one game (project, in -game mode; repoints to the package at the 100 percent gate)'
$lnk.Save()
$chk = $ws.CreateShortcut($lnkPath)
Write-Output ("PHI DOOR REPOINTED: " + $chk.TargetPath + ' ' + $chk.Arguments)
$py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCm91dC53cml0ZSgnUEhJIE9ORSBHQU1FIE9QRU46IHByb2plY3QgcmVnaXN0ZXJlZCB1bmRlciBpdHMgVkVJTCBPTU5JIGZvbGRlclxuJykKb3V0LndyaXRlKCdQSEkgT05FIEdBTUUgUFJPSkVDVDogJyArIHVucmVhbC5QYXRocy5nZXRfcHJvamVjdF9maWxlX3BhdGgoKSArICdcbicpCm91dC5jbG9zZSgpCg=='))
$py = $py.Replace('OUTFILE', "'D:\VEIL-OMNI\Saved\phi_onegame_open_out.txt'")
Set-Content "$new\Saved\phi_onegame_open.py" -Value $py -Encoding UTF8
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
& $cmdexe $uproj -run=pythonscript -script="$new\Saved\phi_onegame_open.py" -unattended -nopause -nosplash *> "$new\Saved\onegame359.log"
if (Test-Path "$new\Saved\phi_onegame_open_out.txt") { Get-Content "$new\Saved\phi_onegame_open_out.txt" | Write-Output } else { Write-Output 'NO OPEN OUTPUT FILE (Recent tops on his first door launch regardless)' }
Write-Output '--- ONE GAME CENSUS ---'
Get-ChildItem 'D:\' -Directory | Where-Object { $_.Name -match 'VEIL|OMNI' } | ForEach-Object { Write-Output ("PHI D ROOT: " + $_.Name) }
Write-Output ("PHI DOOR COUNT CHECK: door=" + (Test-Path $lnkPath) + " archive=" + (Test-Path 'D:\VEIL-OMNI-ARCHIVE'))
Write-Output 'JOB 359 DONE'
```
