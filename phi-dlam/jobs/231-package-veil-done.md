# Job 231 — Package VEIL_DONE: the art-locked VEIL, archived (waits out build_01_DONE's UAT)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== After job 229s art lock, VEIL packages again as VEIL_DONE - the DONE form with real meshes and the unified palette. Full BuildCookRun (-Cook -Stage -Pak -Package -Archive), archive D:\Builds\VEIL\VEIL_DONE, Development config. build_01_DONE (job 228) may still hold the UAT mutex: wait up to ~200s, then launch in the open. Census reads D:\VEIL\Saved\Logs\PackageVEILDone.log next drain. ==='
$waited = 0
while ($waited -lt 200) {
  if (-not (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue)) { break }
  Start-Sleep -Seconds 10; $waited += 10
}
if (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue) { Write-Output "UAT STILL BUSY after ${waited}s - VEIL_DONE not launched; it launches on the next drain."; return }
Write-Output "UAT free after ${waited}s wait."
$uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$log = 'D:\VEIL\Saved\Logs\PackageVEILDone.log'
if (Test-Path $log) { Move-Item $log "$log.prev" -Force }
$p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\VEIL\VEIL.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\VEIL\VEIL_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $log -RedirectStandardError 'D:\VEIL\Saved\Logs\PackageVEILDone.err.log'
Write-Output "PACKAGE VEIL_DONE LAUNCHED: pid $($p.Id), archive D:\Builds\VEIL\VEIL_DONE, log $log"
```
