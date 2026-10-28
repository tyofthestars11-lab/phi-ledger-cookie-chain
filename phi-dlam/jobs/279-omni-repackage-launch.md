# Job 279 — OMNI repackage launch (nav fix 275 lands ahead of this job in the same drain)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== OMNI packages from its finished state: dressed OMNIWorld (0 primitives), the title SetPause fix (254 proved it in the editor: worldTime 25.02, pawnTickEntries 3210), the ProjectID struct form, the ClockCensusCommandlet quarantined (268 - game target built 22.85s), and the navmesh fix from job 275 earlier in this same drain. Launch in the open, one UAT at a time: if any UAT is already running, hold and report. The verdict + standalone proof ride the next jobs once the archive stands. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
if (-not $uatRun) {
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\OMNI-UE\OMNI.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\OMNI\OMNI_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "OMNI repackage launched pid $($proc.Id)"
} else { Write-Output 'HELD - a UAT is already running; terrain above' }
Write-Output 'OMNI REPACKAGE LAUNCH DONE'
```
