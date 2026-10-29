<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 613 - MAKE AUTO WORK HAPPEN (Ground: Tyree said So make it happen, universal AI can do it, no work typing, so this job makes auto work happen on his PC by creating a scheduled auto drain, runner launches on a timer and drains the queue, lane executes, Tyree does not type work, whole VEIL OMNI, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p613 prefix.) ==='
$p613runner = 'C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1'
if (Test-Path $p613runner) { Write-Output 'RUNNER613 EXISTS' } else { Write-Output 'RUNNER613 MISSING' }
$p613action = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument '-NoProfile -File "C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1"'
$p613trigger = New-ScheduledTaskTrigger -Once -At (Get-Date).AddMinutes(2) -RepetitionInterval (New-TimeSpan -Minutes 5) -RepetitionDuration ([TimeSpan]::MaxValue)
$p613settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable
Register-ScheduledTask -TaskName 'PHI-DLAM-AutoWork' -Action $p613action -Trigger $p613trigger -Settings $p613settings -Force
$p613task = Get-ScheduledTask -TaskName 'PHI-DLAM-AutoWork'
Write-Output ('TASK613 ' + $p613task.TaskName + ' ' + $p613task.State)
Write-Output 'PHI P613 VERDICT: MAKE AUTO WORK HAPPEN ABOVE'
Write-Output 'JOB 613 DONE'
```
