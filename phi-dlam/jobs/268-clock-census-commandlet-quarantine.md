# Job 268 — ClockCensusCommandlet quarantine (the VEIL cook's ExitCode 6, named by 265) + game-target builds

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 265 named the cook failure in its own text: D:\VEIL\Source\VEIL\Private\ClockCensusCommandlet.cpp(3,1): fatal error C1083: Cannot open include file: Editor.h. A clock-census instrument from jobs 234-236 sits in the game module: the EDITOR target compiles it (253/254 built fine), the GAME target cannot include an editor-only header, so every package build dies at compilation - that is the ExitCode 6, and OMNI carries the same instrument. The file is an instrument, not game code: it moves to quarantine (a move, never a deletion - its census work is done and the record holds its results), in both projects. Then both GAME targets build: compilation of the game target is the exact gate the package died at. ==='
$q = 'D:\_PhiHolding\clock-census-quarantine'; New-Item -ItemType Directory -Force $q | Out-Null
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $dest = Join-Path $q $g[0]; New-Item -ItemType Directory -Force $dest | Out-Null
  $found = Get-ChildItem $g[1] -Recurse -Filter 'ClockCensusCommandlet.*' -ErrorAction SilentlyContinue
  foreach ($f in $found) { Write-Output "QUARANTINE MOVE: $($f.FullName) -> $dest"; Move-Item $f.FullName $dest -Force }
  if (-not $found) { Write-Output "no ClockCensusCommandlet files under $($g[1])" }
  Write-Output "--- other Editor.h includes in $($g[0]) Source ---"
  Get-ChildItem (Join-Path $g[1] 'Source') -Recurse -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern '#include "Editor\.h"|"Editor/Editor\.h"' | ForEach-Object { "$($_.Path):$($_.LineNumber): $($_.Line.Trim())" }
}
Write-Output '--- game target build: VEIL ---'
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' VEIL Win64 Development -Project='D:\VEIL\VEIL.uproject' -WaitMutex -NoHotReload 2>&1 | Select-String -Pattern 'error|Total time' | Select-Object -First 12 | ForEach-Object { $_.Line }
Write-Output '--- game target build: OMNI ---'
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' OMNI Win64 Development -Project='D:\OMNI-UE\OMNI.uproject' -WaitMutex -NoHotReload 2>&1 | Select-String -Pattern 'error|Total time' | Select-Object -First 12 | ForEach-Object { $_.Line }
Write-Output 'COMMANDLET QUARANTINE + GAME BUILDS DONE'
```
