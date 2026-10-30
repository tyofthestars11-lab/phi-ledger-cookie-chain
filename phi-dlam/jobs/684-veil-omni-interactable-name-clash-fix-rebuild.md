<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 684 - VEIL OMNI INTERACTABLE NAME CLASH FIX AND REBUILD (Ground: Job 683 read the 682 build log. Build failed in 10.34 seconds with OtherCompilationError. Root cause, exact line: Public Systems VEILInteractable.h line 7, interface UVEILInteractable shares engine name VEILInteractable with class AVEILInteractable in Public Systems VEILDiscoverySystem.h line 64, a pre-existing project class. This job renames the Cowork interface only, never the pre-existing Discovery class: in VEILInteractable.h rename UVEILInteractable to UVEILVaultInteractable and IVEILInteractable to IVEILVaultInteractable, in VEILVault.h and VEILVault.cpp update the interface reference to the new name, in VEILCountessCharacter.cpp update the Execute Interact call to the new name, print every changed file, then verify no UVEILInteractable string remains in the new files, then restart the build detached with separate logs, under Electron phase lock. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj684 = 'D:\VEIL-OMNI'
$sys684 = Join-Path $proj684 'Source\VEIL\Public\Systems'
Write-Output ('FIX684 INTERACTABLE PRESENT ' + (Test-Path (Join-Path $sys684 'VEILInteractable.h')))
$files684 = @((Join-Path $sys684 'VEILInteractable.h'), (Join-Path $sys684 'VEILVault.h'), (Join-Path $proj684 'Source\VEIL\Private\Systems\VEILVault.cpp'), (Join-Path $proj684 'Source\VEIL\Private\Character\VEILCountessCharacter.cpp'))
foreach ($f684 in $files684) { if (Test-Path $f684) { (Get-Content $f684 -Raw) -replace 'UVEILInteractable', 'UVEILVaultInteractable' -replace 'IVEILInteractable', 'IVEILVaultInteractable' -replace 'UVeilInteractable', 'UVEILVaultInteractable' | Set-Content $f684; Write-Output ('FIX684 UPDATED ' + $f684) } else { Write-Output ('FIX684 MISSING ' + $f684) } }
$left684 = Select-String -Path (Join-Path $sys684 'VEILInteractable.h'), (Join-Path $sys684 'VEILVault.h') -Pattern 'UVEILInteractable' -ErrorAction SilentlyContinue
Write-Output ('FIX684 OLD NAME LEFT ' + ($null -ne $left684))
$out684 = Join-Path $proj684 'Saved\Logs\VEIL_684_build_out.log'
$err684 = Join-Path $proj684 'Saved\Logs\VEIL_684_build_err.log'
$build684 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Start-Process -FilePath $build684 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $out684 -RedirectStandardError $err684 -WindowStyle Hidden
Write-Output 'FIX684 BUILD RESTARTED DETACHED.'
Write-Output 'FIX684 ELECTRON PHASE LOCK HELD.'
Write-Output 'FIX684 NOCOOK.'
Write-Output 'FIX684 NOPACKAGE.'
Write-Output 'JOB 684 DONE.'
```
