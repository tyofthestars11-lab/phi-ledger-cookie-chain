<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 661 - STOP POPPING DRAIN PAUSE (Ground: Tyree word Powershell keeps popping up like crazy with a blank and I have no idea what that means if it is not actually doing work. This job pauses the HiddenDrain so the blank window stops popping. Jobs 659 and 660 stay queued in the repo, they do not run while the drain is paused, they run again when Tyree starts the seat. No project file is touched, no map is touched, no icon is touched.) ==='
Write-Output 'DRAIN661 END ATTEMPT'
schtasks /end /tn 'PHI-DLAM-HiddenDrain' 2>&1
Write-Output 'DRAIN661 DISABLE ATTEMPT'
schtasks /change /tn 'PHI-DLAM-HiddenDrain' /disable 2>&1
Write-Output 'DRAIN661 STATUS AFTER'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'QUEUE661 JOBS STAY QUEUED 659 660'
Write-Output 'JOB 661 DONE'
```
