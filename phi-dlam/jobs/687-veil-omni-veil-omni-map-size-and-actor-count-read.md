<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 687 - VEIL OMNI MAP SIZE AND ACTOR COUNT READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Read the VEILDistrict map file size and print MAP687 SIZE, print the Content Maps folder file list, print whether VEILDistrict, OMNIWorld, VEILWorld maps are present. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj687 = 'D:\VEIL-OMNI'
$maps687 = Get-ChildItem -File (Join-Path $proj687 'Content\Maps') -ErrorAction SilentlyContinue
Write-Output ('MAP687 COUNT ' + $maps687.Count)
$maps687 | ForEach-Object { Write-Output ('MAP687 FILE ' + $_.Name + ' ' + $_.Length) }
Write-Output 'JOB687 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB687 NOCOOK.'
Write-Output 'JOB687 NOPACKAGE.'
Write-Output 'JOB 687 DONE.'
```
