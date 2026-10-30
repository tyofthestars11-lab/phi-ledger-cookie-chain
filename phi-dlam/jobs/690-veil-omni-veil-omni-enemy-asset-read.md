<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 690 - VEIL OMNI ENEMY ASSET READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Search Content for enemy mesh assets and for BP_VEILEnemy, print ENEMY690 COUNT, print the first 20 matching file names. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj690 = 'D:\VEIL-OMNI'
$en690 = Get-ChildItem -Recurse -File (Join-Path $proj690 'Content') -Filter *Enemy* -ErrorAction SilentlyContinue
Write-Output ('ENEMY690 COUNT ' + $en690.Count)
$en690 | Select-Object -First 20 | ForEach-Object { Write-Output ('ENEMY690 FILE ' + $_.FullName) }
Write-Output 'JOB690 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB690 NOCOOK.'
Write-Output 'JOB690 NOPACKAGE.'
Write-Output 'JOB 690 DONE.'
```
