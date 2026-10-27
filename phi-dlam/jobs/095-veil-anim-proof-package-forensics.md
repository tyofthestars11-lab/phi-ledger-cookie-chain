<!-- PHI-DIRECT -->
# JOB 095 - VEIL: ANIM PROOF + PACKAGE FORENSICS (DIRECT)

Two reads. (1) Job 093 proved the Manny mesh is on the runner but
its BeginPlay check read anim=none - the anim instance is created
after BeginPlay, so a one-shot Tick log now proves it live: sync,
build, launch -game for a 25-second dwell (no auto-quit), read the
log, stop only the smoke process this job started.
(2) Package3 failed with the consolidated config in place - the
config causes are cleared, so read the cook's OWN error lines from
uat-package3.log and report them verbatim. No relaunch: the fix
follows the evidence.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Source D:\VEIL\Source /E /NFL /NDL /NJH | Out-Null
robocopy veil\OMNI\Source D:\OMNI-UE\Source /E /NFL /NDL /NJH | Out-Null
"SYNCED sources"
$out = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' VEILEditor Win64 Development '-project=D:\VEIL\VEIL.uproject' -waitmutex -NoHotReload 2>&1
$out | Select-Object -Last 4 | ForEach-Object { "$_" }
if ("$out" -match 'Result: Succeeded') {
  $smoke = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList '"D:\VEIL\VEIL.uproject"','-game','-unattended','-nosplash','-windowed','-ResX=1280','-ResY=720','-abslog=D:\VEIL\Saved\smoke-game2.log' -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 25
  if (-not $smoke.HasExited) { Stop-Process -Id $smoke.Id -Force; "SMOKE: 25 s dwell complete, stopped" } else { "SMOKE EXITED code $($smoke.ExitCode)" }
  Select-String -Path 'D:\VEIL\Saved\smoke-game2.log' -Pattern 'PHI BODY|LoadMap' | Select-Object -First 8 | ForEach-Object { $_.Line }
} else { "BUILD DID NOT SUCCEED - anim proof skipped" }
"=== PACKAGE FORENSICS (uat-package3.log) ==="
$pl = 'D:\VEIL\Saved\uat-package3.log'
if (Test-Path $pl) {
  Select-String -Path $pl -Pattern 'LogCook: Error|Error: |ERROR:|Failed to|Assertion|Missing' | Select-Object -First 16 | ForEach-Object { $_.Line }
  "--- LOG TAIL ---"
  Get-Content $pl -Tail 12
} else { "NO PACKAGE3 LOG" }
"=== JOB 095 DONE ==="
```
