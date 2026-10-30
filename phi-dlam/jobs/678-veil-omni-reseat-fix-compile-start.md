<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 678 - VEIL OMNI RESEAT FIX AND COMPILE START (Ground: Job 677 copied Public into Public and Private into Private, so files landed at Public Public and Private Private, health hook check failed, and the build Start-Process failed because stdout and stderr used the same log file. This job moves the nested files up one level to the correct Public and Private paths, verifies the health hook at the correct path, then starts the build detached with separate stdout and stderr logs. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj678 = 'D:\VEIL-OMNI'
$src678 = Join-Path $proj678 'Source\VEIL'
Write-Output ('FIX678 PROJECT PRESENT ' + (Test-Path $proj678))
$pubNest678 = Join-Path $src678 'Public\Public'
$priNest678 = Join-Path $src678 'Private\Private'
if (Test-Path $pubNest678) { Get-ChildItem -Recurse -File $pubNest678 | ForEach-Object { $rel678 = $_.FullName.Substring($pubNest678.Length + 1); $dst678 = Join-Path (Join-Path $src678 'Public') $rel678; if (-not (Test-Path (Split-Path $dst678))) { New-Item -ItemType Directory -Force (Split-Path $dst678) | Out-Null }; Copy-Item -Force $_.FullName $dst678; Write-Output ('FIX678 PUBLIC MOVED ' + $dst678) } }
if (Test-Path $priNest678) { Get-ChildItem -Recurse -File $priNest678 | ForEach-Object { $rel678 = $_.FullName.Substring($priNest678.Length + 1); $dst678 = Join-Path (Join-Path $src678 'Private') $rel678; if (-not (Test-Path (Split-Path $dst678))) { New-Item -ItemType Directory -Force (Split-Path $dst678) | Out-Null }; Copy-Item -Force $_.FullName $dst678; Write-Output ('FIX678 PRIVATE MOVED ' + $dst678) } }
Write-Output ('FIX678 COUNTESS HEADER PRESENT ' + (Test-Path (Join-Path $src678 'Public\Character\VEILCountessCharacter.h')))
Write-Output ('FIX678 COUNTESS SOURCE PRESENT ' + (Test-Path (Join-Path $src678 'Private\Character\VEILCountessCharacter.cpp')))
Write-Output ('FIX678 VAULT HEADER PRESENT ' + (Test-Path (Join-Path $src678 'Public\Systems\VEILVault.h')))
Write-Output ('FIX678 WAVE HEADER PRESENT ' + (Test-Path (Join-Path $src678 'Public\Systems\VEILWaveSpawner.h')))
$health678 = Select-String -Path (Join-Path $src678 'Public\Character\VEILCountessCharacter.h') -Pattern 'TakeDamage' -SimpleMatch
Write-Output ('FIX678 HEALTH HOOK PRESENT ' + ($null -ne $health678))
$out678 = Join-Path $proj678 'Saved\Logs\VEIL_678_build_out.log'
$err678 = Join-Path $proj678 'Saved\Logs\VEIL_678_build_err.log'
if (-not (Test-Path (Split-Path $out678))) { New-Item -ItemType Directory -Force (Split-Path $out678) | Out-Null }
$build678 = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output ('FIX678 BUILD BAT PRESENT ' + (Test-Path $build678))
Start-Process -FilePath $build678 -ArgumentList 'VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload' -RedirectStandardOutput $out678 -RedirectStandardError $err678 -WindowStyle Hidden
Write-Output 'FIX678 BUILD STARTED DETACHED.'
Write-Output 'FIX678 NOCOOK.'
Write-Output 'FIX678 NOPACKAGE.'
Write-Output 'JOB 678 DONE.'
```
