<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 748 - RESTORE SEAT SCRIPT AND LOAD MAP PROPER (Ground: Job 747 read seat745 log, SyntaxError expected except or finally block at seat719.py line 71, commandlet return -1, 4 errors, 11 warnings, execution 0.29 seconds, out file present False, VAULT 0, NAVMESH 0, DONE 0, map 626984 unchanged. The 745 one-line try insert broke Python syntax inside the existing world try block. This job restores seat719 from its 745 backup, inserts a proper standalone map load try block before log START, prints the map load region, deletes the old out file, then starts a fresh detached Cmd run with new log names VEIL_SEAT748. It edits only that map load insert, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
$backupW = Join-Path $projW 'Saved\seat719.py.phi-backup-745'
Write-Output ('SCRIPT748 PRESENT ' + (Test-Path $pyW))
Write-Output ('BACKUP748 PRESENT ' + (Test-Path $backupW))
if (Test-Path $backupW) {
  Copy-Item $backupW $pyW -Force
  Write-Output 'RESTORED748 FROM BACKUP 745'
  $contentW = Get-Content $pyW -Raw
  Write-Output ('LOAD748 BEFORE ' + ([regex]::Matches($contentW, 'load_level')).Count)
  $insertW = "    try:`n        unreal.EditorLevelLibrary.load_level(MAP_PATH)`n        log(`"MAP LOADED`")`n    except Exception as exc:`n        log(`"MAP LOAD ERROR: `" + str(exc))`n    log(`"START`")"
  $contentW = $contentW.Replace('    log("START")', $insertW)
  Set-Content $pyW $contentW -NoNewline
  $afterContent = Get-Content $pyW -Raw
  Write-Output ('LOAD748 AFTER ' + ([regex]::Matches($afterContent, 'load_level')).Count)
  Write-Output 'SCRIPT748 MAP LOAD REGION'
  Select-String -Path $pyW -Pattern 'MAP LOAD'
  $outFile = Join-Path $projW 'Saved\seat719_out.txt'
  if (Test-Path $outFile) { Remove-Item $outFile -Force; Write-Output 'OUT748 OLD FILE DELETED' }
  $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT748_cmd_out.log'
  $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT748_cmd_err.log'
  $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  Write-Output ('SEAT748 CMD PRESENT ' + (Test-Path $cmdW))
  Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
  Write-Output 'SEAT748 CMD STARTED DETACHED NO WAIT'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD748 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP748 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
