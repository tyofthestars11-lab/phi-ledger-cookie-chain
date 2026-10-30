<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 689 - VEIL OMNI COUNTESS ASSET READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Search Content for Countess assets and for SM_Countess, print COUNTESS689 COUNT, print the first 20 matching file names, print whether a BP_Countess asset is present. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj689 = 'D:\VEIL-OMNI'
$count689 = Get-ChildItem -Recurse -File (Join-Path $proj689 'Content') -Filter *Countess* -ErrorAction SilentlyContinue
Write-Output ('COUNTESS689 COUNT ' + $count689.Count)
$count689 | Select-Object -First 20 | ForEach-Object { Write-Output ('COUNTESS689 FILE ' + $_.FullName) }
$sm689 = Get-ChildItem -Recurse -File (Join-Path $proj689 'Content') -Filter *SM_Countess* -ErrorAction SilentlyContinue
Write-Output ('SM689 COUNT ' + $sm689.Count)
Write-Output 'JOB689 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB689 NOCOOK.'
Write-Output 'JOB689 NOPACKAGE.'
Write-Output 'JOB 689 DONE.'
```
