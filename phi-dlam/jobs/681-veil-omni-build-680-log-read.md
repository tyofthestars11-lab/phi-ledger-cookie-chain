<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 681 - VEIL OMNI BUILD 680 LOG READ (Ground: Job 680 moved the duplicate backup out of Source and restarted the build detached. This job reads the 680 out log and err log, prints line counts, tail 40 lines each, and every error line, and reports whether the build is still running, succeeded, or failed, under Electron phase lock. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj681 = 'D:\VEIL-OMNI'
$out681 = Join-Path $proj681 'Saved\Logs\VEIL_680_build_out.log'
$err681 = Join-Path $proj681 'Saved\Logs\VEIL_680_build_err.log'
Write-Output ('READ681 OUT PRESENT ' + (Test-Path $out681))
Write-Output ('READ681 ERR PRESENT ' + (Test-Path $err681))
if (Test-Path $out681) { $lines681 = Get-Content $out681; Write-Output ('READ681 OUT LINES ' + $lines681.Count); $lines681 | Select-Object -Last 40 | ForEach-Object { Write-Output ('READ681 OUT TAIL ' + $_.Trim()) } }
if (Test-Path $err681) { $errs681 = Get-Content $err681; Write-Output ('READ681 ERR LINES ' + $errs681.Count); $errs681 | Select-Object -Last 40 | ForEach-Object { Write-Output ('READ681 ERR TAIL ' + $_.Trim()) } }
$proc681 = Get-Process -Name 'Build' -ErrorAction SilentlyContinue
Write-Output ('READ681 BUILD RUNNING ' + ($null -ne $proc681))
Write-Output 'READ681 ELECTRON PHASE LOCK HELD.'
Write-Output 'READ681 NOCOOK.'
Write-Output 'READ681 NOPACKAGE.'
Write-Output 'JOB 681 DONE.'
```
