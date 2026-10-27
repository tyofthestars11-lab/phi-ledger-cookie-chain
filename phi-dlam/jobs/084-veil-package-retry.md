<!-- PHI-DIRECT -->
# JOB 084 - VEIL PACKAGE RETRY, FULLY INSTRUMENTED (DIRECT)

Job 073 named the first package run's only captured error - a
ProjectID config import failure - and restarted the package; job 074
found no exe and no outcome lines. This retry runs BuildCookRun
(Development) detached with its FULL output captured to a log file
job 086 greps for the real verdict: BUILD SUCCESSFUL / FAILED, the
exe, the pak list, the LoadMap line. Development config on purpose:
logs stay on, so the packaged game can speak for itself.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Config D:\VEIL\Config /E /NFL /NDL /NJH | Out-Null
"CONFIG SYNCED"
Select-String -Path 'D:\VEIL\Config\DefaultGame.ini' -Pattern 'ProjectID|ProjectName' | ForEach-Object { "INI: $($_.Line)" }
Select-String -Path 'D:\VEIL\Config\DefaultEngine.ini' -Pattern 'GameDefaultMap|EditorStartupMap' | ForEach-Object { "INI: $($_.Line)" }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { "EDITOR OPEN - package deferred (16 GB rule: never editor + cook together)"; "=== JOB 084 DONE ===" }
else {
  $log = 'D:\VEIL\Saved\uat-package2.log'
  Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat' -ArgumentList 'BuildCookRun','-project="D:\VEIL\VEIL.uproject"','-platform=Win64','-clientconfig=Development','-cook','-build','-stage','-pak','-archive','-archivedirectory="D:\VEIL-Package"','-unattended','-nop4' -RedirectStandardOutput $log -RedirectStandardError "$log.err" -WindowStyle Hidden
  "PACKAGE RETRY LAUNCHED (detached) -> D:\VEIL-Package - verdict rides job 086"
  "=== JOB 084 DONE ==="
}
```
