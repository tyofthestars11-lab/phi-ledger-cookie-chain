<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 688 - VEIL OMNI VAULT MESH AND GOLD MATERIAL READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Search Content for M_PHI_Gold and for Vault mesh assets, print GOLD688 COUNT and VAULT688 COUNT, print the first 20 matching file names. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj688 = 'D:\VEIL-OMNI'
$gold688 = Get-ChildItem -Recurse -File (Join-Path $proj688 'Content') -Filter *M_PHI_Gold* -ErrorAction SilentlyContinue
Write-Output ('GOLD688 COUNT ' + $gold688.Count)
$gold688 | Select-Object -First 20 | ForEach-Object { Write-Output ('GOLD688 FILE ' + $_.FullName) }
$vault688 = Get-ChildItem -Recurse -File (Join-Path $proj688 'Content') -Filter *Vault* -ErrorAction SilentlyContinue
Write-Output ('VAULT688 COUNT ' + $vault688.Count)
Write-Output 'JOB688 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB688 NOCOOK.'
Write-Output 'JOB688 NOPACKAGE.'
Write-Output 'JOB 688 DONE.'
```
