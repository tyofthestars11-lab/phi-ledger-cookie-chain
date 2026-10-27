<!-- PHI-DIRECT -->
# JOB 086 - WORLDGEN + PACKAGE VERDICTS + GAME DOORS (DIRECT)

Reads both detached runs (083 worldgen, 084 package) and reports
their true states: the [WORLDGEN] lines and the VEILWorld map file;
the package log's outcome lines, the exe, the pak list. Then, for
any packaged exe that now exists, the desktop game door is set -
the icon that opens the game itself, not the editor.

```powershell
$ErrorActionPreference = 'Continue'
"=== WORLDGEN VERDICT ==="
$wl = 'D:\VEIL\Saved\worldgen-build.log'
if (Test-Path $wl) { Select-String -Path $wl -Pattern '\[WORLDGEN\]' | ForEach-Object { $_.Line } } else { "NO WORLDGEN LOG" }
$wm = 'D:\VEIL\Content\Maps\VEILWorld.umap'
if (Test-Path $wm) { "VEILWorld UMAP: {0:N1} KB" -f ((Get-Item $wm).Length/1KB) } else { "VEILWorld UMAP ABSENT" }
"=== PACKAGE VERDICT ==="
$pl = 'D:\VEIL\Saved\uat-package2.log'
if (Test-Path $pl) { Select-String -Path $pl -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=|Error:' | Select-Object -First 12 | ForEach-Object { $_.Line } } else { "NO PACKAGE LOG" }
Get-Process AutomationTool -ErrorAction SilentlyContinue | ForEach-Object { "UAT STILL RUNNING" }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL\Content\Paks') { Get-ChildItem 'D:\VEIL-Package\Windows\VEIL\Content\Paks' | ForEach-Object { "PAK: $($_.Name) {0:N1} MB" -f ($_.Length/1MB) } }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL.exe') { "EXE: D:\VEIL-Package\Windows\VEIL.exe {0:N1} MB" -f ((Get-Item 'D:\VEIL-Package\Windows\VEIL.exe').Length/1MB) } else { "EXE NOT FOUND" }
"=== GAME DOORS ==="
$ws = New-Object -ComObject WScript.Shell
$desk = [Environment]::GetFolderPath('Desktop')
foreach ($c in @(@{Exe='D:\VEIL-Package\Windows\VEIL.exe'; Name='VEIL - The Last Signal'}, @{Exe='D:\OMNI-Package\Windows\OMNI.exe'; Name='OMNI RPG'})) {
  if (Test-Path $c.Exe) {
    $lnk = $ws.CreateShortcut((Join-Path $desk ($c.Name + '.lnk')))
    $lnk.TargetPath = $c.Exe; $lnk.WorkingDirectory = Split-Path $c.Exe; $lnk.Save()
    "SHORTCUT SET: $($c.Name)"
  } else { "NO PACKAGE YET: $($c.Name)" }
}
"=== JOB 086 DONE ==="
```
