<!-- PHI-DIRECT -->
# JOB 090 - CONFIG CONSOLIDATION + PACKAGE STATE CHECK (DIRECT)

Root cause found 2026-10-27: every ini fix (nav, maps, Lumen,
optimization) lived only in the PC copies, and job 084's config
sync overwrote them from the repo - whose DefaultEngine.ini still
carried the prototype-era file. The repo inis are now consolidated
(map defaults, Dynamic navigation, Lumen, TSR, Google's block).
This job syncs Config to both projects, PROVES the lines are on
disk, then reads the package retry's true state. If no exe exists
and no cook is running, it relaunches BuildCookRun once with the
consolidated config.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Config D:\VEIL\Config /E /NFL /NDL /NJH | Out-Null
robocopy veil\OMNI\Config D:\OMNI-UE\Config /E /NFL /NDL /NJH | Out-Null
"CONFIG SYNCED (consolidated repo inis)"
"=== PROOF ON DISK ==="
Select-String -Path 'D:\VEIL\Config\DefaultEngine.ini' -Pattern 'GameDefaultMap|RuntimeGeneration|DynamicGlobalIllumination|AntiAliasingMethod' | ForEach-Object { "VEIL INI: $($_.Line)" }
Select-String -Path 'D:\OMNI-UE\Config\DefaultEngine.ini' -Pattern 'RuntimeGeneration|DynamicGlobalIllumination|AntiAliasingMethod' | ForEach-Object { "OMNI INI: $($_.Line)" }
"=== PACKAGE STATE ==="
$pl = 'D:\VEIL\Saved\uat-package2.log'
if (Test-Path $pl) { Select-String -Path $pl -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=' | Select-Object -Last 4 | ForEach-Object { $_.Line } }
$cooking = Get-Process UnrealEditor-Cmd,dotnet -ErrorAction SilentlyContinue
if (Test-Path 'D:\VEIL-Package\Windows\VEIL.exe') { "EXE EXISTS: D:\VEIL-Package\Windows\VEIL.exe" }
elseif ($cooking) { "PACKAGE STILL COOKING - verdict next drain" }
else {
  $log = 'D:\VEIL\Saved\uat-package3.log'
  Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat' -ArgumentList 'BuildCookRun','-project="D:\VEIL\VEIL.uproject"','-platform=Win64','-clientconfig=Development','-cook','-build','-stage','-pak','-archive','-archivedirectory="D:\VEIL-Package"','-unattended','-nop4' -RedirectStandardOutput $log -RedirectStandardError "$log.err" -WindowStyle Hidden
  "PACKAGE RELAUNCHED with consolidated config -> D:\VEIL-Package (log: uat-package3.log)"
}
"=== JOB 090 DONE ==="
```
