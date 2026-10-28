<!-- PHI-DIRECT -->
```powershell
Write-Output '=== OMNI REPACKAGE + STANDALONE PROOF - REFILE (pure ASCII; runs after the OMNI grounding fix refile by job number). Recooks and archives the game with the grounded map, then launches the packaged exe with the standalone proof and reads its log lines. Waits up to 2 minutes for the Unreal Editor to close before cooking, else reports DEFERRED and stops. Verdicts printed from the tools own output - BUILD SUCCESSFUL / ExitCode, then the PHI proof lines verbatim.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - repackage deferred, nothing touched.'; Write-Output 'OMNI REPACKAGE DEFERRED'; return }
$uproj = Get-ChildItem 'D:\OMNI-UE' -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
if (-not (Test-Path $uat)) { $uat = Get-ChildItem 'C:\Program Files\Epic Games' -Recurse -Filter 'RunUAT.bat' -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName }
if ($uproj -and $uat) {
  $cooklog = 'D:\OMNI-UE\Saved\repackage308.log'
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Windows', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=D:\Builds\OMNI\OMNI_DONE") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = 'D:\Builds\OMNI\OMNI_DONE\Windows\OMNI.exe'
  "exe present: $(Test-Path $exe) at $exe" | Write-Output
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 35
    $logs = Get-ChildItem 'D:\OMNI-UE\Saved\Logs', 'D:\Builds\OMNI\OMNI_DONE\Windows\OMNI\Saved\Logs' -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "proof log: $($logs.FullName)" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI.*PROOF|PHI CLOCK|worldTime|paused|Error' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process OMNI -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
} else { Write-Output 'TERRAIN MISSING: uproject or RunUAT not found - nothing ran' }
Write-Output 'OMNI REPACKAGE + PROOF DONE'
```
