<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 680 - VEIL OMNI BUILD FAIL ROOT CAUSE FIX AND REBUILD (Ground: Job 679 read the build log. Build failed in 4.27 seconds with RulesError, not a code error in the new files. Root cause: Job 677 put the backup at Source VEIL_backup_677, inside Source, so UnrealBuildTool scanned its VEIL.Build.cs and found a duplicate VEIL module, error CS0101 and CS0111. This job moves that backup out of Source to D VEIL_backup_677, verifies no Build.cs remains under Source except the live one, then restarts the build detached with separate logs, under Electron phase lock. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj680 = 'D:\VEIL-OMNI'
$src680 = Join-Path $proj680 'Source'
$bak680 = Join-Path $src680 'VEIL_backup_677'
$out680 = 'D:\VEIL_backup_677'
Write-Output ('FIX680 BACKUP IN SOURCE PRESENT ' + (Test-Path $bak680))
if (Test-Path $bak680) { Move-Item -Force $bak680 $out680 }
Write-Output ('FIX680 BACKUP MOVED OUT PRESENT ' + (Test-Path $out680))
Write-Output ('FIX680 BACKUP IN SOURCE GONE ' + (-not (Test-Path $bak680)))
$buildcs680 = Get-ChildItem -Recurse -File $src680 -Filter *.Build.cs -ErrorAction SilentlyContinue
Write-Output ('FIX680 BUILDCS COUNT ' + $buildcs680.Count)
$buildcs680 | ForEach-Object { Write-Output ('FIX680 BUILDCS FILE ' + $_.FullName) }
$outlog680 = Join-Path $proj680 'Saved\Logs\VEIL_680_build_out.log'
$errlog680 = Join-Path $proj680 'Saved\Logs\VEIL_680_build_err.log'
$build680 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Start-Process -FilePath $build680 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $outlog680 -RedirectStandardError $errlog680 -WindowStyle Hidden
Write-Output 'FIX680 BUILD RESTARTED DETACHED.'
Write-Output 'FIX680 ELECTRON PHASE LOCK HELD.'
Write-Output 'FIX680 NOCOOK.'
Write-Output 'FIX680 NOPACKAGE.'
Write-Output 'JOB 680 DONE.'
```
