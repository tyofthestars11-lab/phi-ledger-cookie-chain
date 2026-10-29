<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 567 - VEIL TICK 394 REGION READ (Ground: Job 564 named the crash as AVEILCharacter Tick at line 394 with an access violation at address zero, so this job prints the Tick region around line 394 and the guard lines above it, no patch, no build. Every variable carries the p567 prefix.) ==='
$p567src = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
if (Test-Path $p567src) {
  $p567lines = Get-Content $p567src
  Write-Output ('SOURCE LINES ' + $p567lines.Count)
  $p567start = 369
  $p567end = 409
  if ($p567end -ge $p567lines.Count) { $p567end = $p567lines.Count - 1 }
  for ($p567k = $p567start; $p567k -le $p567end; $p567k++) { Write-Output ('TICK LINE ' + ($p567k + 1) + ' ' + $p567lines[$p567k].Trim()) }
  @(Select-String -Path $p567src -Pattern 'AVEILCharacter::Tick' | Select-Object -First 5) | ForEach-Object { Write-Output ('TICK HEAD ' + $_.Line.Trim()) }
} else { Write-Output 'NO CHARACTER SOURCE FOUND' }
Write-Output 'PHI P567 VERDICT: VEIL TICK 394 REGION READ ABOVE'
Write-Output 'JOB 567 DONE'
```
