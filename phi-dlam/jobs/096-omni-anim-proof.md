<!-- PHI-DIRECT -->
# JOB 096 - OMNI: ANIM PROOF SMOKE (DIRECT)

OMNI's character carries the same Manny wiring and the same
one-shot Tick proof. Build, launch -game for a 25-second dwell,
read the PHI BODY lines from OMNI's own log, stop only the smoke
process this job started. OMNI boots its runtime district on the
bare map until OMNIWorld is seated as its default.

```powershell
$ErrorActionPreference = 'Continue'
$out = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' OMNIEditor Win64 Development '-project=D:\OMNI-UE\OMNI.uproject' -waitmutex -NoHotReload 2>&1
$out | Select-Object -Last 4 | ForEach-Object { "$_" }
if ("$out" -match 'Result: Succeeded') {
  $smoke = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList '"D:\OMNI-UE\OMNI.uproject"','-game','-unattended','-nosplash','-windowed','-ResX=1280','-ResY=720','-abslog=D:\OMNI-UE\Saved\smoke-game2.log' -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 25
  if (-not $smoke.HasExited) { Stop-Process -Id $smoke.Id -Force; "SMOKE: 25 s dwell complete, stopped" } else { "SMOKE EXITED code $($smoke.ExitCode)" }
  Select-String -Path 'D:\OMNI-UE\Saved\smoke-game2.log' -Pattern 'PHI BODY|LoadMap' | Select-Object -First 8 | ForEach-Object { $_.Line }
} else { "BUILD DID NOT SUCCEED - anim proof skipped" }
"=== JOB 096 DONE ==="
```
