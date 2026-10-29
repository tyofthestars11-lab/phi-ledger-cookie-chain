<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 592 - BUILD590 ERROR READ (Ground: Job 590 patched Fibonacci percents with count 2 and brace 23/23 paren 131/131 but BUILD590 EXIT 6, job 591 braided build590 log line 58 Result Failed, so this job reads the exact error lines in build590 log, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the next repair lands from the exact error not a guess. Every variable carries the p592 prefix.) ==='
$p592log = 'D:\VEIL-OMNI\Saved\build590.log'
if (Test-Path $p592log) { Write-Output ('LOG592 EXISTS ' + $p592log) } else { Write-Output ('LOG592 MISSING ' + $p592log) }
$p592hits = @(Select-String -Path $p592log -Pattern 'GuardedAdvanceProgression' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p592h in $p592hits) { Write-Output ('GUARD592 ' + $p592h.LineNumber + ' ' + $p592h.Line.Trim()) }
$p592hits2 = @(Select-String -Path $p592log -Pattern 'CrashFix' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p592h in $p592hits2) { Write-Output ('CRASH592 ' + $p592h.LineNumber + ' ' + $p592h.Line.Trim()) }
Write-Output 'PHI P592 VERDICT: BUILD590 ERROR READ ABOVE'
Write-Output 'JOB 592 DONE'
```
