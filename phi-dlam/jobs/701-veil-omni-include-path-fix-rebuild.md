<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 701 - VEIL OMNI INCLUDE PATH FIX AND REBUILD (Ground: Job 685 read the 684 build log. Build failed in 35.30 seconds with fatal error C1083 Cannot open include file for every new header, because the Cowork files use flat includes while the headers now sit in Public Character and Public Systems. This job fixes the includes in place, never the pre-existing Discovery class: for every cpp and h file under Source VEIL Private and Public, replace flat include VEILCountessCharacter.h with Character VEILCountessCharacter.h, and replace flat includes PHI_MitochondrialEngine.h, VEILVault.h, VEILInteractable.h, VEILLoopSubsystem.h, VEILLoopActors.h, VEILWaveSpawner.h, VEILEnemy.h, VEILRegionSubsystem.h with Systems versions of the same names, print every file changed, verify no flat include of those names remains, then restart the build detached with separate logs, under Electron phase lock and the Golden Angle Anti-Run-Fail Protocol. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj701 = 'D:\VEIL-OMNI'
$src701 = Join-Path $proj701 'Source\VEIL'
$files701 = Get-ChildItem -Recurse -File $src701 -Include *.cpp,*.h -ErrorAction SilentlyContinue | Where-Object { $_.FullName -match 'VEILCountess|VEILVault|VEILInteractable|VEILLoop|VEILWave|VEILEnemy|VEILRegion|PHI_Mitochondrial' }
Write-Output ('FIX701 FILES FOUND ' + $files701.Count)
foreach ($f701 in $files701) { $t701 = Get-Content $f701.FullName -Raw; $o701 = $t701; $t701 = $t701 -replace '#include "VEILCountessCharacter.h"', '#include "Character/VEILCountessCharacter.h"'; foreach ($h701 in @('PHI_MitochondrialEngine.h','VEILVault.h','VEILInteractable.h','VEILLoopSubsystem.h','VEILLoopActors.h','VEILWaveSpawner.h','VEILEnemy.h','VEILRegionSubsystem.h')) { $t701 = $t701 -replace ('#include "' + $h701 + '"'), ('#include "Systems/' + $h701 + '"') }; if ($t701 -ne $o701) { Set-Content $f701.FullName $t701; Write-Output ('FIX701 UPDATED ' + $f701.FullName) } }
$left701 = Select-String -Path (Get-ChildItem -Recurse -File $src701 -Include *.cpp,*.h | Where-Object { $_.FullName -match 'VEILCountess|VEILVault|VEILInteractable|VEILLoop|VEILWave|VEILEnemy|VEILRegion|PHI_Mitochondrial' }).FullName -Pattern '#include "(VEIL|PHI_)[^"]+\.h"' -ErrorAction SilentlyContinue
Write-Output ('FIX701 FLAT LEFT ' + ($null -ne $left701))
$out701 = Join-Path $proj701 'Saved\Logs\VEIL_701_build_out.log'
$err701 = Join-Path $proj701 'Saved\Logs\VEIL_701_build_err.log'
$build701 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Start-Process -FilePath $build701 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $out701 -RedirectStandardError $err701 -WindowStyle Hidden
Write-Output 'FIX701 BUILD RESTARTED DETACHED.'
Write-Output 'FIX701 ELECTRON PHASE LOCK HELD.'
Write-Output 'FIX701 NOCOOK.'
Write-Output 'FIX701 NOPACKAGE.'
Write-Output 'JOB 701 DONE.'
```
