# Job 273 — VEIL repackage launch (game target compiles again per 268; nav + ABP fixes ride ahead in this queue)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 268 quarantined the ClockCensusCommandlet and BOTH game targets built clean - the compilation gate that took ExitCode 6 is open. Jobs 270-272 ahead in this queue land the navmesh fixes and the ABP carrier clear, so this launch cooks the finished state: dressed maps (0 primitives on all three), the title-unpause clock fix, the ProjectID struct form, and the nav/ABP state from this same drain. Launch in the open, one UAT at a time (233/240 mutex law): if any UAT is already running, hold and report. The verdict + standalone clock proof + OMNI launch ride the next job once the archive stands. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
if (-not $uatRun) {
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\VEIL\VEIL.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\VEIL\VEIL_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "VEIL repackage launched pid $($proc.Id)"
} else { Write-Output 'HELD - a UAT is already running; terrain above' }
Write-Output 'VEIL REPACKAGE LAUNCH DONE'
```
