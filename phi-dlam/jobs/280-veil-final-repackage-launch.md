# Job 280 — VEIL FINAL repackage launch (the nav fix 274 + ABP carrier 276 land ahead of this job in the same drain)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The 273 archive proved the package chain but predates the navmesh fix (274) and the ABP carrier clear (276), which land earlier in this same drain. This launch cooks VEILs DONE state whole: dressed maps (0 primitives on all three), title-unpause clock fix, navmesh regenerated with ground holding the spawn, the ABP post-process slot cleared at its carrier. One UAT at a time: if the OMNI cook (279) or any UAT is still running, hold and report - the launch re-queues next drain rather than collide. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
if (-not $uatRun) {
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\VEIL\VEIL.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\VEIL\VEIL_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "VEIL FINAL repackage launched pid $($proc.Id)"
} else { Write-Output 'HELD - a UAT is already running; terrain above' }
Write-Output 'VEIL FINAL REPACKAGE LAUNCH DONE'
```
