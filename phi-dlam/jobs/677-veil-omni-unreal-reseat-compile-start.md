<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 677 - VEIL OMNI UNREAL RESEAT AND COMPILE START (Ground: Cowork Unreal files are downloaded on the Muse VM, re-seated to Public Private layout, with Countess health added, and pushed to github veil-omni-unreal. This job pulls that repo on the PC, backs up Source VEIL, copies the re-seated files in, prints counts, then starts the C++ build detached to a log, so the 240 second step limit cannot kill the build. No cook, no package, no 1.0, no editor GUI launch.) ==='
$repo677 = 'C:\Users\Admin\veil-omni-unreal'
$proj677 = 'D:\VEIL-OMNI'
Write-Output ('RESEAT677 PROJECT PRESENT ' + (Test-Path $proj677))
if (Test-Path $repo677) { Set-Location $repo677; git pull --ff-only } else { git clone https://github.com/tyofthestars11-lab/veil-omni-unreal.git $repo677 }
Write-Output ('RESEAT677 REPO PRESENT ' + (Test-Path $repo677))
$src677 = Join-Path $proj677 'Source\VEIL'
$bak677 = Join-Path $proj677 'Source\VEIL_backup_677'
if (-not (Test-Path $bak677)) { Copy-Item -Recurse $src677 $bak677 }
Write-Output ('RESEAT677 BACKUP PRESENT ' + (Test-Path $bak677))
Copy-Item -Recurse -Force (Join-Path $repo677 'Public') (Join-Path $src677 'Public')
Copy-Item -Recurse -Force (Join-Path $repo677 'Private') (Join-Path $src677 'Private')
$pub677 = Get-ChildItem -Recurse -File (Join-Path $src677 'Public') | Where-Object { $_.Name -like 'VEIL*' -or $_.Name -like 'PHI*' }
$pri677 = Get-ChildItem -Recurse -File (Join-Path $src677 'Private') | Where-Object { $_.Name -like 'VEIL*' -or $_.Name -like 'PHI*' }
Write-Output ('RESEAT677 PUBLIC COUNT ' + $pub677.Count)
Write-Output ('RESEAT677 PRIVATE COUNT ' + $pri677.Count)
$pub677 | ForEach-Object { Write-Output ('RESEAT677 PUBLIC FILE ' + $_.FullName + ' BYTES ' + $_.Length) }
$pri677 | ForEach-Object { Write-Output ('RESEAT677 PRIVATE FILE ' + $_.FullName + ' BYTES ' + $_.Length) }
$health677 = Select-String -Path (Join-Path $src677 'Public\Character\VEILCountessCharacter.h') -Pattern 'TakeDamage' -SimpleMatch
Write-Output ('RESEAT677 HEALTH HOOK PRESENT ' + ($null -ne $health677))
$log677 = Join-Path $proj677 'Saved\Logs\VEIL_677_build.log'
if (-not (Test-Path (Split-Path $log677))) { New-Item -ItemType Directory -Force (Split-Path $log677) | Out-Null }
$build677 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output ('RESEAT677 BUILD BAT PRESENT ' + (Test-Path $build677))
Start-Process -FilePath $build677 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $log677 -RedirectStandardError $log677 -WindowStyle Hidden
Write-Output 'RESEAT677 BUILD STARTED DETACHED.'
Write-Output 'RESEAT677 NOCOOK.'
Write-Output 'RESEAT677 NOPACKAGE.'
Write-Output 'JOB 677 DONE.'
```
