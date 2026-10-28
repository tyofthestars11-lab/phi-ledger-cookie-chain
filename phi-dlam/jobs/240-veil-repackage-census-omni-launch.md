# Job 240 — VEIL repackage census (incl. the full exception trace) + OMNI_DONE launch alone

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 239 relaunched VEIL_DONE with the ProjectID struct form. This census reads attempt 2 whole - Error lines, completion lines, the archive exe - AND the full AutomationTool exception trace the UAT tail points at (the 233 census read only UAT stdout; an UnknownCookFailure hides its cause in that trace). Then, with the UAT lane free, OMNI_DONE launches ALONE: job 232s OMNI UAT died before its log was set (ExitCode 1, 1291-byte log) because 231 and 232 launched together into the single-instance mutex. Sequential from here. ==='
$log = 'D:\VEIL\Saved\Logs\PackageVEILDone2.log'
if (Test-Path $log) {
  $fi = Get-Item $log
  Write-Output "VEIL attempt2 log: $($fi.Length) bytes, last write $($fi.LastWriteTime)"
  $lines = Get-Content $log
  $errs = @($lines | Select-String -Pattern 'Error:')
  Write-Output "Error: lines = $($errs.Count)"
  $errs | Select-Object -First 12 | ForEach-Object { $_.Line }
  $lines | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=|AutomationTool exiting' | Select-Object -Last 4 | ForEach-Object { $_.Line }
  $lines | Select-Object -Last 5
} else { Write-Output "attempt2 log MISSING: $log - 239 may not have launched it (UAT busy then); the launch below covers OMNI only after a VEIL relaunch note." }
if (Test-Path 'D:\Builds\VEIL\VEIL_DONE') {
  Get-ChildItem 'D:\Builds\VEIL\VEIL_DONE' -Recurse -Filter *.exe -ErrorAction SilentlyContinue | ForEach-Object { "exe: $($_.FullName) $([math]::Round($_.Length/1MB,1)) MB $($_.LastWriteTime)" }
} else { Write-Output 'VEIL_DONE archive still MISSING.' }
$trace = 'C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt'
if (Test-Path $trace) {
  Write-Output '--- AutomationTool Log.txt (exception trace, last 40 lines) ---'
  Get-Content $trace | Select-Object -Last 40
} else { Write-Output "trace MISSING: $trace" }
$uat = Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue
if ($uat) { Write-Output "UAT still running ($($uat.Id -join ', ')) - OMNI package NOT launched this drain." }
else {
  $uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $olog = 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone2.log'
  $p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\OMNI-UE\OMNI.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\OMNI\OMNI_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $olog -RedirectStandardError 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone2.err.log'
  Write-Output "PACKAGE OMNI_DONE (attempt 2, alone, ProjectID struct form) LAUNCHED: pid $($p.Id), archive D:\Builds\OMNI\OMNI_DONE, log $olog"
}
```
