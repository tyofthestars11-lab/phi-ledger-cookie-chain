<!-- PHI-DIRECT -->
# JOB 093 - VEIL: MANNY BUILD + STANDALONE SMOKE (DIRECT)

The runner's body is wired (SKM_Manny_Simple + ABP_Unarmed, paths
verbatim from job 089; primitive body remains the logged fallback).
This job syncs Source, compiles the editor target, then launches
the game itself standalone (-game) with an auto-quit, and reads
the PHI BODY proof lines from the game's own log.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Source D:\VEIL\Source /E /NFL /NDL /NJH | Out-Null
robocopy veil\OMNI\Source D:\OMNI-UE\Source /E /NFL /NDL /NJH | Out-Null
"SYNCED sources (both games carry the Manny wiring)"
$out = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' VEILEditor Win64 Development '-project=D:\VEIL\VEIL.uproject' -waitmutex -NoHotReload 2>&1
$out | Select-Object -Last 6 | ForEach-Object { "$_" }
if ("$out" -match 'Result: Succeeded') {
  $smoke = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList '"D:\VEIL\VEIL.uproject"','-game','-unattended','-nosplash','-windowed','-ResX=1280','-ResY=720','-abslog=D:\VEIL\Saved\smoke-game.log','-ExecCmds=QUIT' -PassThru -WindowStyle Hidden
  if (-not $smoke.WaitForExit(90000)) { Stop-Process -Id $smoke.Id -Force; "SMOKE: still running at 90 s - stopped (log below carries the state)" } else { "SMOKE EXITED code $($smoke.ExitCode)" }
  Select-String -Path 'D:\VEIL\Saved\smoke-game.log' -Pattern 'PHI BODY|VEIL WORLD BUILT|VEIL: free to play|LoadMap' | Select-Object -First 10 | ForEach-Object { $_.Line }
} else { "BUILD DID NOT SUCCEED - smoke skipped" }
"=== JOB 093 DONE ==="
```
