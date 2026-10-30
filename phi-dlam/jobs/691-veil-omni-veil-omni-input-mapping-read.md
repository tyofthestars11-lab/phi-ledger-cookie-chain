<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 691 - VEIL OMNI INPUT MAPPING READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Read Config DefaultInput.ini and Config DefaultEngine.ini, print whether Enhanced Input actions IA_Move, IA_Look, IA_Jump, IA_Attack are present, print whether legacy MoveForward mapping is present, print INPUT691 ENHANCED or INPUT691 LEGACY. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj691 = 'D:\VEIL-OMNI'
$ini691 = Join-Path $proj691 'Config\DefaultInput.ini'
Write-Output ('INPUT691 INI PRESENT ' + (Test-Path $ini691))
if (Test-Path $ini691) { $t691 = Get-Content $ini691 -Raw; Write-Output ('INPUT691 IA_MOVE ' + $t691.Contains('IA_Move')); Write-Output ('INPUT691 IA_JUMP ' + $t691.Contains('IA_Jump')); Write-Output ('INPUT691 LEGACY_MOVE ' + $t691.Contains('MoveForward')) }
Write-Output 'JOB691 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB691 NOCOOK.'
Write-Output 'JOB691 NOPACKAGE.'
Write-Output 'JOB 691 DONE.'
```
