<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 698 - VEIL OMNI HEALTH HOOK VERIFY (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Select-String TakeDamage in Public Systems and Public Character headers, print HEALTH698 PRESENT if found in the Countess header, print the matching lines. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj698 = 'D:\VEIL-OMNI'
$h698 = Join-Path $proj698 'Source\VEIL\Public\Systems\VEILInteractable.h'
Write-Output ('HEALTH698 FILE PRESENT ' + (Test-Path $h698))
if (Test-Path $h698) { Select-String -Path $h698 -Pattern 'TakeDamage|Health' | ForEach-Object { Write-Output ('HEALTH698 LINE ' + $_.Line.Trim()) } }
$ch698 = Get-ChildItem -Recurse -File (Join-Path $proj698 'Source\VEIL\Public') -Filter VEILCountessCharacter.h -ErrorAction SilentlyContinue
Write-Output ('HEALTH698 COUNTESS HEADER COUNT ' + $ch698.Count)
if ($ch698) { Select-String -Path $ch698[0].FullName -Pattern 'TakeDamage|MaxHealth' | ForEach-Object { Write-Output ('HEALTH698 COUNTESS LINE ' + $_.Line.Trim()) } }
Write-Output 'JOB698 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB698 NOCOOK.'
Write-Output 'JOB698 NOPACKAGE.'
Write-Output 'JOB 698 DONE.'
```
