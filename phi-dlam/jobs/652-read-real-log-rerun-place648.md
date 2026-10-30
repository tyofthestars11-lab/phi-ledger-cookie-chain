<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 652 - READ REAL LOG RERUN PLACE648 (Ground: Tyree order file 652 read real Cmd log and rerun place648 with stdout captured plus 651 result GUI closed Cmd started PID 60436 exit 1 log missing map after 180952 no change not progress build exit 0. This job reads the real Unreal log in Saved Logs, reruns Cmd with stdout and stderr captured to files, prints the captured lines, then map before and after. No split phi squared equals phi plus 1 does not split one whole everywhere all at once. No package until 100 percent done. No ledger edit. Every variable carries the p652 prefix.) ==='
$p652uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p652map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p652script = 'D:\VEIL-OMNI\Saved\place648.py'
$p652out = 'D:\VEIL-OMNI\Saved\place652.out'
$p652errout = 'D:\VEIL-OMNI\Saved\place652.err.txt'
$p652logs = 'D:\VEIL-OMNI\Saved\Logs'
$p652backup = 'D:\VEIL-OMNI\Saved\backup652'
$p652cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p652batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
New-Item -ItemType Directory -Path $p652backup -Force | Out-Null
foreach ($p652f in @($p652map, $p652uproj)) { if (Test-Path $p652f) { Copy-Item $p652f $p652backup -Force; Write-Output ('BACKUP652 DONE ' + $p652f) } else { Write-Output ('BACKUP652 MISSING ' + $p652f) } }
Write-Output 'WHOLE652 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p652map) { Write-Output ('MAP652 BEFORE SIZE ' + (Get-Item $p652map).Length) } else { Write-Output 'MAP652 BEFORE MISSING' }
if (Test-Path $p652script) { Write-Output ('SCRIPT652 FOUND SIZE ' + (Get-Item $p652script).Length) } else { Write-Output 'SCRIPT652 MISSING EDITOR RUN STOPPED' }
Write-Output 'LOG652 REAL UNREAL LOGS LIST NEWEST FIRST'
if (Test-Path $p652logs) {
  $p652logFiles = @(Get-ChildItem $p652logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 3)
  foreach ($p652lf in $p652logFiles) { Write-Output ('LOG652 FILE ' + $p652lf.Name + ' SIZE ' + $p652lf.Length + ' WRITTEN ' + $p652lf.LastWriteTime) }
  if ($p652logFiles.Count -gt 0) {
    $p652tail = @(Get-Content $p652logFiles[0].FullName -Tail 200 -ErrorAction SilentlyContinue | Select-String -Pattern 'Error|Python|ACTORS648|ACTOR648|VAULT648|SAVE648|Fatal|Failed' -ErrorAction SilentlyContinue)
    Write-Output ('LOG652 NEWEST MATCH LINES ' + $p652tail.Count)
    foreach ($p652t in $p652tail) { Write-Output ('LOG652 ' + $p652t.Line) }
  }
} else { Write-Output 'LOG652 LOGS FOLDER MISSING' }
$p652gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p652gui) { Write-Output 'EDITOR652 GUI OPEN CMD RUN SKIPPED GUI BLOCKS CMD RUN' } else { Write-Output 'EDITOR652 GUI CLOSED CMD RUN STARTS WITH CAPTURE' }
if ((-not $p652gui) -and (Test-Path $p652script) -and (Test-Path $p652cmd) -and (Test-Path $p652uproj)) {
  $p652proc = Start-Process $p652cmd -ArgumentList "`"$p652uproj`"", '-run=PythonScript', "-script=`"$p652script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p652out -RedirectStandardError $p652errout -PassThru
  Write-Output ('EDITOR652 STARTED PID ' + $p652proc.Id)
  $p652wait = 0
  while ((-not $p652proc.HasExited) -and ($p652wait -lt 180)) { Start-Sleep -Seconds 10; $p652wait += 10 }
  if ($p652proc.HasExited) { Write-Output ('EDITOR652 EXIT ' + $p652proc.ExitCode) } else { Write-Output 'EDITOR652 STILL RUNNING AFTER 180 SECONDS BUILD SKIPPED WHILE EDITOR RUNS' }
} else { Write-Output 'EDITOR652 CMD RUN SKIPPED GUI OPEN OR PREREQUISITE MISSING' }
if (Test-Path $p652out) {
  $p652outLines = @(Get-Content $p652out -ErrorAction SilentlyContinue | Select-String -Pattern 'ACTORS648|ACTOR648|VAULT648|COUNTESS648|SAVE648|Error|Python|Traceback' -ErrorAction SilentlyContinue)
  Write-Output ('OUT652 MATCH LINES ' + $p652outLines.Count)
  foreach ($p652o in $p652outLines) { Write-Output ('OUT652 ' + $p652o.Line) }
  Write-Output ('OUT652 TOTAL BYTES ' + (Get-Item $p652out).Length)
} else { Write-Output 'OUT652 MISSING CAPTURE FAILED' }
if (Test-Path $p652errout) {
  $p652erroutLines = @(Get-Content $p652errout -ErrorAction SilentlyContinue)
  Write-Output ('ERROUT652 LINES ' + $p652erroutLines.Count)
  foreach ($p652e in $p652erroutLines) { Write-Output ('ERROUT652 ' + $p652e) }
} else { Write-Output 'ERROUT652 MISSING' }
if ((-not (Get-Process UnrealEditor-Cmd -ErrorAction SilentlyContinue)) -and (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue))) {
  Set-Location $p652batdir
  .\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build652.log'
  Write-Output ('BUILD652 EXIT ' + $LASTEXITCODE)
} else { Write-Output 'BUILD652 SKIPPED EDITOR PROCESS STILL RUNNING' }
if (Test-Path $p652map) {
  $p652afterSize = (Get-Item $p652map).Length
  Write-Output ('MAP652 AFTER SIZE ' + $p652afterSize)
  if ($p652afterSize -eq 180952) { Write-Output 'PROGRESS652 NO CHANGE NOT PROGRESS BUILD EXIT 0 ALONE IS NOT PROGRESS' } else { Write-Output 'PROGRESS652 CHANGED MAP SIZE MOVED' }
} else { Write-Output 'MAP652 AFTER MISSING' }
Write-Output 'AUTO652 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE652 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 652 DONE'
```
