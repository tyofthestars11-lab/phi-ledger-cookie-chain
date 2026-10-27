<!-- PHI-DIRECT -->
# JOB 091 - PACKAGE FINAL VERDICT + WORLDGEN LOG PROOF + DOORS (DIRECT)

Reads the package state honestly: exe + paks + the cook log's own
outcome lines, or STILL COOKING if the processes are alive (a
verdict read 8 seconds into a cook is not a verdict). Also pulls
the [WORLDGEN] lines from the editor's real log (Saved\Logs) as
retro-proof of the generator's counts. Sets the packaged game
doors when the exe exists.

```powershell
$ErrorActionPreference = 'Continue'
"=== WORLDGEN LOG PROOF ==="
$el = 'D:\VEIL\Saved\Logs\VEIL.log'
if (Test-Path $el) { Select-String -Path $el -Pattern '\[WORLDGEN\]|\[DISTRICT\]' | ForEach-Object { $_.Line } } else { "NO EDITOR LOG" }
"=== PACKAGE FINAL VERDICT ==="
foreach ($pl in 'D:\VEIL\Saved\uat-package3.log','D:\VEIL\Saved\uat-package2.log') {
  if (Test-Path $pl) { "LOG: $pl"; Select-String -Path $pl -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=' | Select-Object -Last 4 | ForEach-Object { $_.Line }; break }
}
$cooking = Get-Process UnrealEditor-Cmd,dotnet -ErrorAction SilentlyContinue
if ($cooking) { "PACKAGE STILL COOKING - verdict next drain" }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL\Content\Paks') { Get-ChildItem 'D:\VEIL-Package\Windows\VEIL\Content\Paks' | ForEach-Object { "PAK: $($_.Name) {0:N1} MB" -f ($_.Length/1MB) } }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL.exe') { "EXE: D:\VEIL-Package\Windows\VEIL.exe {0:N1} MB" -f ((Get-Item 'D:\VEIL-Package\Windows\VEIL.exe').Length/1MB) } else { "EXE NOT FOUND" }
"=== GAME DOORS ==="
$ws = New-Object -ComObject WScript.Shell
$desk = [Environment]::GetFolderPath('Desktop')
foreach ($c in @(@{Exe='D:\VEIL-Package\Windows\VEIL.exe'; Name='VEIL - The Last Signal'}, @{Exe='D:\OMNI-Package\Windows\OMNI.exe'; Name='OMNI RPG'})) {
  if (Test-Path $c.Exe) {
    $lnk = $ws.CreateShortcut((Join-Path $desk ($c.Name + '.lnk')))
    $lnk.TargetPath = $c.Exe; $lnk.WorkingDirectory = Split-Path $c.Exe; $lnk.Save()
    "DOOR UPGRADED TO PACKAGE: $($c.Name)"
  } else { "DOOR STAYS -game MODE: $($c.Name)" }
}
"=== JOB 091 DONE ==="
```
