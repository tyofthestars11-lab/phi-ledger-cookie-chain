# Job 232 — Package OMNI_DONE: OMNI on the same rails (editor build verified first)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== OMNI gets its DONE package: job 225 already rebuilt OMNIEditor with the bypass repair (Result: Succeeded) and job 230 dresses OMNIWorld. This job re-verifies the OMNIEditor build (incremental), waits out any running UAT up to ~200s, then launches the full BuildCookRun package archived to D:\Builds\OMNI\OMNI_DONE, Development config, in the open. Census reads D:\OMNI-UE\Saved\Logs\PackageOMNIDone.log next drain. ==='
$build = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' OMNIEditor Win64 Development '-Project=D:\OMNI-UE\OMNI.uproject' -WaitMutex 2>&1
$build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
$waited = 0
while ($waited -lt 200) {
  if (-not (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue)) { break }
  Start-Sleep -Seconds 10; $waited += 10
}
if (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue) { Write-Output "UAT STILL BUSY after ${waited}s - OMNI_DONE not launched; it launches on the next drain."; return }
Write-Output "UAT free after ${waited}s wait."
New-Item -ItemType Directory -Force -Path 'D:\Builds\OMNI' | Out-Null
$uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$log = 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone.log'
if (Test-Path $log) { Move-Item $log "$log.prev" -Force }
$p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\OMNI-UE\OMNI.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\OMNI\OMNI_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $log -RedirectStandardError 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone.err.log'
Write-Output "PACKAGE OMNI_DONE LAUNCHED: pid $($p.Id), archive D:\Builds\OMNI\OMNI_DONE, log $log"
```
