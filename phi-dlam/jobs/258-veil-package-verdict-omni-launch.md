# Job 258 — VEIL repackage verdict + standalone clock proof + OMNI repackage launch

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 254 launched the VEIL repackage (pid 63448) on the clock-fixed, dressed code; job 255 read it still cooking (UAT running, archive exe was attempt 2s from 16:13) and correctly held OMNI. This job finishes the chain: read VEILs fresh package verdict from its newest UAT log and the archive exe timestamp; if the build succeeded, run the finish-line standalone clock proof on the fresh VEIL_DONE (worldTime advancing + pawnTickEntries > 0 in the package itself); then, with no UAT running, launch the OMNI repackage in the open. If VEIL is still cooking, report terrain and hold everything. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
$exe = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Binaries\Win64\VEIL.exe'
if (Test-Path $exe) { Get-Item $exe | Select-Object FullName, @{n='MB';e={[math]::Round($_.Length/1MB,1)}}, LastWriteTime | Format-List }
$logs = Get-ChildItem 'C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs' -Recurse -Filter '*.txt' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 3
foreach ($l in $logs) { Write-Output "--- UAT log $($l.FullName) ($($l.LastWriteTime)) ---"; Select-String -Path $l.FullName -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=' | Select-Object -Last 3 | ForEach-Object { $_.Line } }
$exeItem = Get-Item $exe -ErrorAction SilentlyContinue
$fresh = $exeItem -and ($exeItem.LastWriteTime -gt (Get-Date '2026-10-27 18:40'))
Write-Output "VEIL archive fresh (post-fix): $fresh"
if ($fresh -and -not $uatRun) {
  Write-Output '--- standalone clock proof on fresh VEIL_DONE ---'
  $p = Start-Process $exe -PassThru
  Start-Sleep -Seconds 45
  Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
  $slog = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs\VEIL.log'
  $proof = Select-String -Path $slog -Pattern 'TICKPROOF' | Select-Object -Last 4 | ForEach-Object { $_.Line }
  $proof | ForEach-Object { Write-Output $_ }
  $adv = ($proof | Where-Object { $_ -match 'worldTime=([0-9.]+)' -and [double]$Matches[1] -gt 0.5 }).Count
  $tick = ($proof | Where-Object { $_ -match 'pawnTickEntries=([0-9]+)' -and [int]$Matches[1] -gt 0 }).Count
  Write-Output "STANDALONE VEIL_DONE CLOCK: samplesWithTimeAdvanced=$adv samplesWithPawnTicks=$tick"
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\OMNI-UE\OMNI.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\OMNI\OMNI_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "OMNI repackage launched pid $($proc.Id) (clock-fixed, dressed OMNIWorld)"
} else { Write-Output 'HELD - VEIL package not fresh or UAT still running; terrain above' }
Write-Output 'PACKAGE CHAIN 258 DONE'
```
