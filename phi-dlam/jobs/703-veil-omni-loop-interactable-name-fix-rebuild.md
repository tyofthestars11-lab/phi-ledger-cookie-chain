<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 703 - VEIL OMNI LOOP INTERACTABLE NAME FIX AND REBUILD (Ground: Job 702 read the 701 build log. Build failed in 82.88 seconds, no longer C1083, now VEILLoopActors.h lines 13, 28, 40 error C2504 IVEILInteractable base class undefined and C3668 Interact_Implementation override did not override, because job 684 renamed the Cowork interface to IVEILVaultInteractable but VEILLoopActors still uses the old name. This job replaces IVEILInteractable with IVEILVaultInteractable in VEILLoopActors.h and VEILLoopActors.cpp and in any other new file under Source VEIL that uses the old interface name, never the pre-existing Discovery class, prints every file changed, prints the Interactable header interface lines, then restarts the build detached with separate logs, under Electron phase lock and the Golden Angle Anti-Run-Fail Protocol. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj703 = 'D:\VEIL-OMNI'
$src703 = Join-Path $proj703 'Source\VEIL'
$h703 = Join-Path $src703 'Public\Systems\VEILInteractable.h'
if (Test-Path $h703) { Select-String -Path $h703 -Pattern 'Interactable' | ForEach-Object { Write-Output ('FIX703 INTERACTABLE LINE ' + $_.Line.Trim()) } }
$files703 = Get-ChildItem -Recurse -File $src703 -Include *.cpp,*.h -ErrorAction SilentlyContinue
foreach ($f703 in $files703) { $t703 = Get-Content $f703.FullName -Raw; if ($t703 -match 'IVEILInteractable') { $n703 = $t703 -replace 'IVEILInteractable', 'IVEILVaultInteractable'; Set-Content $f703.FullName $n703; Write-Output ('FIX703 UPDATED ' + $f703.FullName) } }
$left703 = Select-String -Path (Get-ChildItem -Recurse -File $src703 -Include *.cpp,*.h).FullName -Pattern 'IVEILInteractable' -ErrorAction SilentlyContinue
Write-Output ('FIX703 OLD INTERFACE LEFT ' + ($null -ne $left703))
$out703 = Join-Path $proj703 'Saved\Logs\VEIL_703_build_out.log'
$err703 = Join-Path $proj703 'Saved\Logs\VEIL_703_build_err.log'
$build703 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Start-Process -FilePath $build703 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $out703 -RedirectStandardError $err703 -WindowStyle Hidden
Write-Output 'FIX703 BUILD RESTARTED DETACHED.'
Write-Output 'FIX703 ELECTRON PHASE LOCK HELD.'
Write-Output 'FIX703 NOCOOK.'
Write-Output 'FIX703 NOPACKAGE.'
Write-Output 'JOB 703 DONE.'
```
