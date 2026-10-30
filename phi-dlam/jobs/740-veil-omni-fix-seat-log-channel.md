<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 740 - FIX SEAT LOG CHANNEL THEN SEAT (Ground: Job 739 read seat719 lines 1 to 59 showing log prints SEAT719 plus msg with print, total script lines 304, and the seat736 log searched START lines 25 generic only, WORLD lines 8 generic only, ACTORS lines 4 warning only, FLOOR lines 0, map 626984 unchanged. No SEAT719 prints stood in the seat736 log. The fault is the channel: print does not land in the Cmd out log, unreal log does. This job backs up seat719, replaces the log print with unreal log, prints the edited log function, then starts a fresh detached Cmd run of the fixed script with new log names VEIL_SEAT740. It edits only that one log line, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SCRIPT740 PRESENT ' + (Test-Path $pyW))
if (Test-Path $pyW) {
  $backupW = Join-Path $projW 'Saved\seat719.py.phi-backup-740'
  Copy-Item $pyW $backupW -Force
  Write-Output ('BACKUP740 PRESENT ' + (Test-Path $backupW))
  $contentW = Get-Content $pyW -Raw
  $beforeCount = ([regex]::Matches($contentW, 'print\("SEAT719 "')).Count
  Write-Output ('LOG740 PRINT BEFORE ' + $beforeCount)
  $contentW = $contentW.Replace('print("SEAT719 " + msg)', 'unreal.log("SEAT719 " + msg)')
  Set-Content $pyW $contentW -NoNewline
  $afterContent = Get-Content $pyW -Raw
  $afterPrint = ([regex]::Matches($afterContent, 'print\("SEAT719 "')).Count
  $afterLog = ([regex]::Matches($afterContent, 'unreal\.log\("SEAT719 "')).Count
  Write-Output ('LOG740 PRINT AFTER ' + $afterPrint)
  Write-Output ('LOG740 UNREAL LOG AFTER ' + $afterLog)
  Write-Output 'SCRIPT740 LOG FUNCTION REGION'
  Get-Content $pyW | Select-Object -Skip 39 -First 10
  $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT740_cmd_out.log'
  $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT740_cmd_err.log'
  $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  Write-Output ('SEAT740 CMD PRESENT ' + (Test-Path $cmdW))
  Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
  Write-Output 'SEAT740 CMD STARTED DETACHED NO WAIT'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD740 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP740 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
