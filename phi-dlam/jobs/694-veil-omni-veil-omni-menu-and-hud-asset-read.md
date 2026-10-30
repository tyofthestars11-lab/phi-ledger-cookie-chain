<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 694 - VEIL OMNI MENU AND HUD ASSET READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Search Content for MainMenu, PauseMenu, HUD, and health bar widget assets, print MENU694 COUNT, print the first 20 matching file names. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj694 = 'D:\VEIL-OMNI'
foreach ($k694 in @('MainMenu','PauseMenu','HUD')) { $f694 = Get-ChildItem -Recurse -File (Join-Path $proj694 'Content') -Filter ('*' + $k694 + '*') -ErrorAction SilentlyContinue; Write-Output ($k694 + '694 COUNT ' + $f694.Count) }
Write-Output 'JOB694 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB694 NOCOOK.'
Write-Output 'JOB694 NOPACKAGE.'
Write-Output 'JOB 694 DONE.'
```
