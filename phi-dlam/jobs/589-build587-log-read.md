<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 589 - BUILD LOG READ (Ground: Job 587 patched Clear progression OK with brace 23/23 paren 127/127 but BUILD587 EXIT 6, so this job reads the build log error lines for the exact failure, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the repair lands from the error not a guess. Every variable carries the p589 prefix.) ==='
$p589logs = @('D:\VEIL-OMNI\Saved\build587.log', 'D:\VEIL-OMNI\Saved\build588.log')
foreach ($p589log in $p589logs) {
  if (Test-Path $p589log) { Write-Output ('LOG589 EXISTS ' + $p589log) } else { Write-Output ('LOG589 MISSING ' + $p589log) }
  $p589hits = @(Select-String -Path $p589log -Pattern 'error' -ErrorAction SilentlyContinue | Select-Object -First 40)
  foreach ($p589h in $p589hits) { Write-Output ('ERR589 ' + $p589log + ' ' + $p589h.LineNumber + ' ' + $p589h.Line.Trim()) }
  $p589hits2 = @(Select-String -Path $p589log -Pattern 'GuardedAdvanceProgression' -ErrorAction SilentlyContinue | Select-Object -First 40)
  foreach ($p589h in $p589hits2) { Write-Output ('GUARD589 ' + $p589log + ' ' + $p589h.LineNumber + ' ' + $p589h.Line.Trim()) }
}
Write-Output 'PHI P589 VERDICT: BUILD LOG READ ABOVE'
Write-Output 'JOB 589 DONE'
```
