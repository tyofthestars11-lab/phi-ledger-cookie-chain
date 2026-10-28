# Job 255 — OMNI repackage (after VEIL's archive stands) + standalone clock proof on VEIL_DONE

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 254 launched the VEIL repackage in the open after both clock proofs went green. This job keeps the sequence mutex-clean (jobs 233/240: a second UAT into a running one takes ExitCode 1): read VEILs package state; if its archive exe stands AND no UAT/dotnet build is running, launch the OMNI repackage in the open; then run the fresh VEIL_DONE standalone for the finish-line clock proof - TICKPROOF lines with worldTime ADVANCING and pawnTickEntries > 0 in the package itself. If VEIL is still cooking, report terrain and hold OMNI. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
$exe = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Binaries\Win64\VEIL.exe'
if (Test-Path $exe) { Get-Item $exe | Select-Object FullName, @{n='MB';e={[math]::Round($_.Length/1MB,1)}}, LastWriteTime | Format-List }
$vlog = Get-ChildItem 'D:\VEIL\Saved\Logs' -Filter '*.log' | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($vlog) { Write-Output "--- VEIL UAT tail: $($vlog.Name) ---"; Get-Content $vlog.FullName -Tail 60 | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|Error:' | ForEach-Object { $_.Line } }
if ((Test-Path $exe) -and -not $uatRun) {
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\OMNI-UE\OMNI.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\OMNI\OMNI_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "OMNI repackage launched pid $($proc.Id)"
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
} else { Write-Output 'OMNI HELD - VEIL still cooking or archive absent; terrain above' }
Write-Output 'OMNI REPACKAGE + STANDALONE PROOF DONE'
```
