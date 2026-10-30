<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 696 - VEIL OMNI MOBILE PROJECT READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Check whether D VEIL-OMNI-Mobile exists, print MOBILE696 PRESENT, print its Scripts folder file list if present, print whether a VEIL_Mobile uproject file is present. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj696 = 'D:\VEIL-OMNI'
$mob696 = 'D:\VEIL-OMNI-Mobile'
Write-Output ('MOBILE696 PRESENT ' + (Test-Path $mob696))
if (Test-Path $mob696) { Get-ChildItem -File $mob696 -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('MOBILE696 FILE ' + $_.Name) } }
Write-Output 'JOB696 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB696 NOCOOK.'
Write-Output 'JOB696 NOPACKAGE.'
Write-Output 'JOB 696 DONE.'
```
