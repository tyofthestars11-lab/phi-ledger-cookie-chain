# Job 221 — Cook A11 (VEIL) launched in the open: the census is the scoreboard (38 -> ?)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== With job 220s bypass built, the ABP should be out of VEILs cook chain. A11 is the first cook on the new chain: BuildCookRun -cook only (no stage/package yet), launched in the open because a full cook outruns the 240s bound. The next job censuses D:\VEIL\Saved\Logs\CookA11.log: Error lines vs A10s 38, whether Countess_AnimBlueprint appears at all, and whether the ProjectID line stands alone. ==='
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$log = 'D:\VEIL\Saved\Logs\CookA11.log'
if (Test-Path $log) { Move-Item $log "$log.prev" -Force }
$p = Start-Process -FilePath $uat -ArgumentList 'BuildCookRun','-Project=D:\VEIL\VEIL.uproject','-Platform=Win64','-Cook','-Unattended','-NoP4' -PassThru -WindowStyle Hidden
Write-Output "COOK A11 LAUNCHED: pid $($p.Id), log $log"
```
