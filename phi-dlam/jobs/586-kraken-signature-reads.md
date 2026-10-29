<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 586 - KRAKEN SIGNATURE READS (Ground: Job 583 read GuardedAdvanceProgression at CrashFix line 33 and header 16, job 585 read quest screen lines and Warden lines, so this one job kraken packs the exact signatures needed for the next patch, CrashFix header, GameState Fixed header, QuestSystem header, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the patch lands from signatures not a guess. Every variable carries the p586 prefix.) ==='
$p586files = @('D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_CrashFix_AddressZero.h', 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_GameState_Fixed.h', 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\OMNIQuestSystem.h')
foreach ($p586f in $p586files) {
  if (Test-Path $p586f) { Write-Output ('FILE586 EXISTS ' + $p586f) } else { Write-Output ('FILE586 MISSING ' + $p586f) }
  $p586lines = @(Get-Content $p586f -ErrorAction SilentlyContinue | Select-Object -First 100)
  foreach ($p586l in $p586lines) { Write-Output ('LINE586 ' + $p586f + ' ' + $p586l.Trim()) }
}
Write-Output 'PHI P586 VERDICT: KRAKEN SIGNATURE READS ABOVE'
Write-Output 'JOB 586 DONE'
```
