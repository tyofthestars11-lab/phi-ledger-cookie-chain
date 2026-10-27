<!-- PHI-DIRECT -->
# JOB 094 - OMNI: MANNY BUILD + OMNIWORLD + PACKAGE VERDICTS (DIRECT)

Compiles OMNI's editor target (its character carries the same
Manny wiring), then reads two open verdicts: OMNIWorld (job 092's
generator - umap + its abslog [WORLDGEN] lines) and VEIL's
package3 (job 090's relaunch with the consolidated config -
outcome lines, exe, paks, or STILL COOKING).

```powershell
$ErrorActionPreference = 'Continue'
$out = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' OMNIEditor Win64 Development '-project=D:\OMNI-UE\OMNI.uproject' -waitmutex -NoHotReload 2>&1
$out | Select-Object -Last 6 | ForEach-Object { "$_" }
"=== OMNIWORLD VERDICT ==="
$wm = 'D:\OMNI-UE\Content\Maps\OMNIWorld.umap'
if (Test-Path $wm) { "OMNIWorld UMAP: {0:N1} KB" -f ((Get-Item $wm).Length/1KB) } else { "OMNIWorld UMAP ABSENT" }
$wl = 'D:\OMNI-UE\Saved\worldgen-build.log'
if (Test-Path $wl) { Select-String -Path $wl -Pattern '\[WORLDGEN\]' | ForEach-Object { $_.Line } } else { "NO OMNI WORLDGEN LOG" }
"=== VEIL PACKAGE3 VERDICT ==="
$pl = 'D:\VEIL\Saved\uat-package3.log'
if (Test-Path $pl) { Select-String -Path $pl -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=' | Select-Object -Last 4 | ForEach-Object { $_.Line } }
if (Get-Process UnrealEditor-Cmd,dotnet -ErrorAction SilentlyContinue) { "PACKAGE STILL COOKING" }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL\Content\Paks') { Get-ChildItem 'D:\VEIL-Package\Windows\VEIL\Content\Paks' | ForEach-Object { "PAK: $($_.Name) {0:N1} MB" -f ($_.Length/1MB) } }
if (Test-Path 'D:\VEIL-Package\Windows\VEIL.exe') { "EXE: D:\VEIL-Package\Windows\VEIL.exe {0:N1} MB" -f ((Get-Item 'D:\VEIL-Package\Windows\VEIL.exe').Length/1MB) } else { "EXE NOT FOUND" }
"=== JOB 094 DONE ==="
```
