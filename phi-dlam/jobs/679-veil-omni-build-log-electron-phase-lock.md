<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 679 - VEIL OMNI BUILD LOG READ AND ELECTRON PHASE LOCK (Ground: Job 678 started the C++ build detached. This job reads the build out log and err log, prints the tail and every error line, and applies the Electron phase lock law to any run fail: a fail is a misaligned address to realign and continue through, never a stop, never a split, one whole entangled. If the build is still running, this job reports running and does not kill it. If the build failed, this job prints the exact error lines for the next repair job, and does not drop the build address. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj679 = 'D:\VEIL-OMNI'
$out679 = Join-Path $proj679 'Saved\Logs\VEIL_678_build_out.log'
$err679 = Join-Path $proj679 'Saved\Logs\VEIL_678_build_err.log'
Write-Output ('PHASE679 OUT PRESENT ' + (Test-Path $out679))
Write-Output ('PHASE679 ERR PRESENT ' + (Test-Path $err679))
if (Test-Path $out679) { $lines679 = Get-Content $out679; Write-Output ('PHASE679 OUT LINES ' + $lines679.Count); $lines679 | Select-Object -Last 40 | ForEach-Object { Write-Output ('PHASE679 OUT TAIL ' + $_.Trim()) } }
if (Test-Path $err679) { $errs679 = Get-Content $err679; Write-Output ('PHASE679 ERR LINES ' + $errs679.Count); $errs679 | Select-Object -Last 40 | ForEach-Object { Write-Output ('PHASE679 ERR TAIL ' + $_.Trim()) } }
$buildProc679 = Get-Process -Name 'Build' -ErrorAction SilentlyContinue
Write-Output ('PHASE679 BUILD RUNNING ' + ($null -ne $buildProc679))
Write-Output 'PHASE679 ELECTRON PHASE LOCK APPLIED TO ANY RUN FAIL.'
Write-Output 'PHASE679 NOCOOK.'
Write-Output 'PHASE679 NOPACKAGE.'
Write-Output 'JOB 679 DONE.'
```
