<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VEIL REPACKAGE + STANDALONE PROOF (Tyree 2026-10-27 22:49 MDT: "Fix it all" / progression. Runs after the VEIL grounding fix by job number: recooks and archives the game with the grounded map, then launches the packaged exe with the standalone proof and reads its log lines. Waits up to ~3 minutes for the Unreal Editor to close before cooking. Verdicts printed from the tools' own output — BUILD SUCCESSFUL / ExitCode, then the PHI proof lines verbatim.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 13) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after ~3 min - repackage deferred, nothing touched.'; Write-Output 'VEIL REPACKAGE DEFERRED'; return }
$uproj = Get-ChildItem 'D:\VEIL' -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
if (-not (Test-Path $uat)) { $uat = Get-ChildItem 'C:\Program Files\Epic Games' -Recurse -Filter 'RunUAT.bat' -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName }
if ($uproj -and $uat) {
  $cooklog = 'D:\VEIL\Saved\repackage303.log'
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Windows', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=D:\Builds\VEIL\VEIL_DONE") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe'
  "exe present: $(Test-Path $exe) — $exe" | Write-Output
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 50
    $logs = Get-ChildItem 'D:\VEIL\Saved\Logs', 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs' -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "proof log: $($logs.FullName)" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI.*PROOF|PHI CLOCK|worldTime|paused|Error' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process VEIL -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
} else { Write-Output 'TERRAIN MISSING: uproject or RunUAT not found - nothing ran' }
Write-Output 'VEIL REPACKAGE + PROOF DONE'
```
