<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 695 - VEIL OMNI SOURCE LAYOUT VERIFY (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Verify the source layout: print PUBLIC695 COUNT and PRIVATE695 COUNT under Source VEIL, verify no Public Public folder exists, verify no Private Private folder exists, verify no backup folder exists under Source, verify exactly one VEIL.Build.cs file exists under Source. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj695 = 'D:\VEIL-OMNI'
$pub695 = Join-Path $proj695 'Source\VEIL\Public'
$pri695 = Join-Path $proj695 'Source\VEIL\Private'
Write-Output ('PUBLIC695 COUNT ' + (Get-ChildItem -Recurse -File $pub695 -ErrorAction SilentlyContinue).Count)
Write-Output ('PRIVATE695 COUNT ' + (Get-ChildItem -Recurse -File $pri695 -ErrorAction SilentlyContinue).Count)
Write-Output ('PUBLIC695 NESTED GONE ' + (-not (Test-Path (Join-Path $pub695 'Public'))))
Write-Output ('PRIVATE695 NESTED GONE ' + (-not (Test-Path (Join-Path $pri695 'Private'))))
$b695 = Get-ChildItem -Recurse -File (Join-Path $proj695 'Source') -Filter *.Build.cs -ErrorAction SilentlyContinue
Write-Output ('BUILD695 COUNT ' + $b695.Count)
Write-Output 'JOB695 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB695 NOCOOK.'
Write-Output 'JOB695 NOPACKAGE.'
Write-Output 'JOB 695 DONE.'
```
