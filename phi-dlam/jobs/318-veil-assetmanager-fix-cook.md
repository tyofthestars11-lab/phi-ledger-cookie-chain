<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VEIL ASSET MANAGER FIX + FINISH COOK (Job 317 read the finish-cook logs and named the failure exactly: the BUILD stage passed - dotnet exit 0, the MCP plugins do NOT break compilation - and the COOK stage aborted with 2 errors, both one root: LogGameFeatures: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function / LoadErrors: Add entry to PrimaryAssetTypesToScan? Enabling AllToolsets woke the GameFeatures toolset, whose plugin system demands an AssetManager scan rule for GameFeatureData in DefaultGame.ini; neither project has one, so the cook counts it as failure and stops. THE FIX IS THE ONE THE ERROR ITSELF PRESCRIBES: add the PrimaryAssetTypesToScan entry for GameFeatureData to Config/DefaultGame.ini under /Script/Engine.AssetManagerSettings - additive config, backup first, idempotent - then the same Win64 finish cook, archive over the old build, settle proof after. Editor-closed guard on.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - fix+cook deferred, nothing touched.'; Write-Output 'VEIL FIX COOK DEFERRED'; return }
$ini = 'D:\VEIL\Config\DefaultGame.ini'
$scanline = '+PrimaryAssetTypesToScan=(PrimaryAssetType="GameFeatureData",AssetBaseClass="/Script/GameFeatures.GameFeatureData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game")),Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))'
if (Test-Path $ini) {
  Copy-Item $ini "$ini.phi-backup-318" -Force
  $raw = Get-Content $ini -Raw
  if ($raw -match 'GameFeatureData') { Write-Output 'SCAN RULE ALREADY PRESENT - no edit made' } else {
    $lines = [System.Collections.ArrayList]@(Get-Content $ini)
    $sec = -1; for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i] -match '^\[/Script/Engine\.AssetManagerSettings\]') { $sec = $i; break } }
    if ($sec -ge 0) { $ins = $sec + 1; while ($ins -lt $lines.Count -and $lines[$ins] -notmatch '^\[') { $ins++ }; $lines.Insert($ins, $scanline); Write-Output "scan rule inserted into AssetManagerSettings section at line $ins" } else { $lines.Add('[/Script/Engine.AssetManagerSettings]'); $lines.Add($scanline); Write-Output 'AssetManagerSettings section created with the scan rule' }
    Set-Content $ini -Value $lines -Encoding ASCII
  }
  '--- DefaultGame.ini AssetManager readback ---' | Write-Output
  Select-String -Path $ini -Pattern 'AssetManagerSettings|GameFeatureData' | ForEach-Object { $_.Line.Trim() } | Write-Output
} else { Write-Output "DefaultGame.ini NOT FOUND at $ini - fix not applied, cook skipped"; Write-Output 'VEIL FIX COOK DONE'; return }
$uproj = Get-ChildItem 'D:\VEIL' -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
if ($uproj -and (Test-Path $uat)) {
  $cooklog = 'D:\VEIL\Saved\fixcook318.log'
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=D:\Builds\VEIL\VEIL_DONE") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe'
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe: $($fi.FullName) | modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss')) | $([math]::Round($fi.Length/1MB,1)) MB" | Write-Output } else { "exe MISSING: $exe" | Write-Output }
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem 'D:\VEIL\Saved\Logs', 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs' -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "proof log: $($logs.FullName)" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI CENSUS|PHI MOVE TEST|PHI GM TICKPROOF' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process VEIL -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
} else { Write-Output 'TERRAIN MISSING: uproject or RunUAT not found - cook did not run' }
Write-Output 'VEIL FIX COOK DONE'
```
