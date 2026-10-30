<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 743 - SEAT LOG TO FILE THEN SEAT (Ground: Job 742 read seat719 head showing main calls log START, WORLD, ACTORS BEFORE, and stops if actors 0, seat740 out log 288 lines, LogPython Display 19 all startup scripts, Error 3 summary and LiveCoding pipe only, Exception 0, Traceback 0, SEAT719 6 metadata only, err log size 0, map 626984 unchanged. The log calls run but never reach the Cmd out log, so the log channel itself is the fault. This job backs up seat719, changes its log line to also append every SEAT719 line to a file on disk, deletes any old out file first, prints the edited log line, then starts a fresh detached Cmd run with new log names VEIL_SEAT743. It edits only that one log line, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SCRIPT743 PRESENT ' + (Test-Path $pyW))
if (Test-Path $pyW) {
  $backupW = Join-Path $projW 'Saved\seat719.py.phi-backup-743'
  Copy-Item $pyW $backupW -Force
  Write-Output ('BACKUP743 PRESENT ' + (Test-Path $backupW))
  $contentW = Get-Content $pyW -Raw
  $beforeLog = ([regex]::Matches($contentW, 'unreal\.log\("SEAT719 "')).Count
  Write-Output ('LOG743 UNREAL LOG BEFORE ' + $beforeLog)
  $contentW = $contentW.Replace('unreal.log("SEAT719 " + msg)', 'unreal.log("SEAT719 " + msg); open("D:\\VEIL-OMNI\\Saved\\seat719_out.txt", "a", encoding="utf-8").write("SEAT719 " + msg + "\n")')
  Set-Content $pyW $contentW -NoNewline
  $afterContent = Get-Content $pyW -Raw
  Write-Output ('LOG743 UNREAL LOG AFTER ' + ([regex]::Matches($afterContent, 'unreal\.log\("SEAT719 "')).Count)
  Write-Output ('LOG743 FILE WRITE AFTER ' + ([regex]::Matches($afterContent, 'seat719_out\.txt')).Count)
  Write-Output 'SCRIPT743 LOG LINE REGION'
  Select-String -Path $pyW -Pattern 'seat719_out'
  $outFile = Join-Path $projW 'Saved\seat719_out.txt'
  if (Test-Path $outFile) { Remove-Item $outFile -Force; Write-Output 'OUT743 OLD FILE DELETED' }
  $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT743_cmd_out.log'
  $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT743_cmd_err.log'
  $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  Write-Output ('SEAT743 CMD PRESENT ' + (Test-Path $cmdW))
  Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
  Write-Output 'SEAT743 CMD STARTED DETACHED NO WAIT'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD743 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP743 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
