# Job 226 — Cook A12 (VEIL) on the repaired chain: waits out A11s UAT, then launches

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== A11 cooks the pre-repair chain (launched by 221 before the repair existed) and 222 quarantined its ABP mid-cook - its census is terrain, not verdict. A12 is the first cook on the repaired chain: bypass built (225), ABP absent from Content (222). One UAT at a time: this job waits for any running UAT to release the mutex (up to ~200s), then launches the A12 cook in the open. Its census is the next read. ==='
$waited = 0
while ($waited -lt 200) {
  $uat = Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue
  if (-not $uat) { break }
  Start-Sleep -Seconds 10; $waited += 10
}
if (Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue) { Write-Output "A11 STILL COOKING after ${waited}s - A12 not launched; it launches on the next drain."; return }
Write-Output "UAT free after ${waited}s wait."
$uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$log = 'D:\VEIL\Saved\Logs\CookA12.log'
if (Test-Path $log) { Move-Item $log "$log.prev" -Force }
$p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\VEIL\VEIL.uproject','-Platform=Win64','-Cook','-Unattended','-NoP4' -PassThru -WindowStyle Hidden
Write-Output "COOK A12 LAUNCHED: pid $($p.Id), log $log"
```
