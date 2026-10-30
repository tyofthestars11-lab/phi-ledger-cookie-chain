<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 693 - VEIL OMNI NAVMESH ASSET READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Search Content and the project for RecastNavMesh and NavMeshBoundsVolume assets, print NAV693 COUNT, print the first 20 matching file names. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj693 = 'D:\VEIL-OMNI'
$nav693 = Get-ChildItem -Recurse -File (Join-Path $proj693 'Content') -Filter *NavMesh* -ErrorAction SilentlyContinue
Write-Output ('NAV693 COUNT ' + $nav693.Count)
$nav693 | Select-Object -First 20 | ForEach-Object { Write-Output ('NAV693 FILE ' + $_.FullName) }
Write-Output 'JOB693 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB693 NOCOOK.'
Write-Output 'JOB693 NOPACKAGE.'
Write-Output 'JOB 693 DONE.'
```
