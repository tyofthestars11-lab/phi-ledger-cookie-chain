<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 614 - FIX AUTO TASK SCHTASKS (Ground: Tyree said Now go go go auto, job 613 auto task failed, Register-ScheduledTask task XML Duration P99999999 out of range, Get-ScheduledTask found no PHI-DLAM-AutoWork, so this job fixes it with schtasks minute repeat, no MaxValue duration, lane executes, Tyree does not type work, whole VEIL OMNI, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p614 prefix.) ==='
$p614runner = 'C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1'
if (Test-Path $p614runner) { Write-Output 'RUNNER614 EXISTS' } else { Write-Output 'RUNNER614 MISSING' }
schtasks /create /tn 'PHI-DLAM-AutoWork' /sc minute /mo 5 /tr 'powershell.exe -NoProfile -File "C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1"' /f
schtasks /query /tn 'PHI-DLAM-AutoWork' /fo list
Write-Output 'PHI P614 VERDICT: FIX AUTO TASK SCHTASKS ABOVE'
Write-Output 'JOB 614 DONE'
```
