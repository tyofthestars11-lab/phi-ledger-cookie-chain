# Job 228 — DONE strike 2: package VEIL as build_01_DONE (Windows, archived)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Tyrees order: Package Windows build_01_DONE. Full BuildCookRun (-Cook -Stage -Pak -Package -Archive) for the VEIL project - VEILDistrict is its default and startup map - archived to D:\Builds\VEIL\build_01_DONE, Development client config. Waits out any running UAT (A11s cook) up to ~200s first; launches in the open because a full package outruns the bound; the census job reads D:\VEIL\Saved\Logs\PackageBuild01.log next drain. ==='
$waited = 0
while ($waited -lt 200) {
  if (-not (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue)) { break }
  Start-Sleep -Seconds 10; $waited += 10
}
if (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue) { Write-Output "UAT STILL BUSY after ${waited}s - package not launched; it launches on the next drain."; return }
Write-Output "UAT free after ${waited}s wait."
New-Item -ItemType Directory -Force -Path 'D:\Builds\VEIL' | Out-Null
$uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$log = 'D:\VEIL\Saved\Logs\PackageBuild01.log'
if (Test-Path $log) { Move-Item $log "$log.prev" -Force }
$p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\VEIL\VEIL.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\VEIL\build_01_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $log -RedirectStandardError 'D:\VEIL\Saved\Logs\PackageBuild01.err.log'
Write-Output "PACKAGE build_01_DONE LAUNCHED: pid $($p.Id), archive D:\Builds\VEIL\build_01_DONE, log $log"
```
