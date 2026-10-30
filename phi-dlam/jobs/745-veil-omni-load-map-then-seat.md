<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 745 - LOAD MAP THEN SEAT (Ground: Job 744 read seat719_out.txt whole, 4 lines, 113 bytes: SEAT719 START, SEAT719 WORLD /Temp/Untitled_0.Untitled, SEAT719 ACTORS BEFORE 0, SEAT719 MAP NOT LOADED STOP. The seat Cmd never loaded VEILDistrict, it ran in an untitled temp world with 0 actors, so the script stopped at once. The log channel now works, the map load is the fault. This job backs up seat719, inserts a map load call at the head of main before the world read, prints the edited head region, deletes the old out file, then starts a fresh detached Cmd run with new log names VEIL_SEAT745. It edits only that map load insert, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SCRIPT745 PRESENT ' + (Test-Path $pyW))
if (Test-Path $pyW) {
  $backupW = Join-Path $projW 'Saved\seat719.py.phi-backup-745'
  Copy-Item $pyW $backupW -Force
  Write-Output ('BACKUP745 PRESENT ' + (Test-Path $backupW))
  $contentW = Get-Content $pyW -Raw
  $beforeLoad = ([regex]::Matches($contentW, 'load_level')).Count
  Write-Output ('LOAD745 BEFORE ' + $beforeLoad)
  $insertW = "    try: unreal.EditorLevelLibrary.load_level(MAP_PATH)`n    except Exception as exc: log(`"MAP LOAD ERROR: `" + str(exc))`n    log(`"MAP LOAD ATTEMPTED`")`n    world = unreal.EditorLevelLibrary.get_editor_world()"
  $contentW = $contentW.Replace('    world = unreal.EditorLevelLibrary.get_editor_world()', $insertW)
  Set-Content $pyW $contentW -NoNewline
  $afterContent = Get-Content $pyW -Raw
  Write-Output ('LOAD745 AFTER ' + ([regex]::Matches($afterContent, 'load_level')).Count)
  Write-Output 'SCRIPT745 MAP LOAD REGION'
  Select-String -Path $pyW -Pattern 'MAP LOAD'
  $outFile = Join-Path $projW 'Saved\seat719_out.txt'
  if (Test-Path $outFile) { Remove-Item $outFile -Force; Write-Output 'OUT745 OLD FILE DELETED' }
  $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT745_cmd_out.log'
  $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT745_cmd_err.log'
  $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  Write-Output ('SEAT745 CMD PRESENT ' + (Test-Path $cmdW))
  Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
  Write-Output 'SEAT745 CMD STARTED DETACHED NO WAIT'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD745 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP745 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
