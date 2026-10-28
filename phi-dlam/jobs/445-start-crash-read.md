<!-- PHI-DIRECT -->
```powershell
Write-Output '=== START CRASH READ 445 - THE CRASH NAMES ITS OWN ADDRESS IN THE LOG (Ground from Tyree hands, 2026-10-28 11:15 MDT: the controller WORKS in VEIL OMNI, the input repair of job 442 proven in live play, and pressing Start now crashes the game outright, where before the repair it froze. The press reaches TogglePauseMenu in VEILGameMode cpp: SetPause, then CreateWidget on the pause class and AddToViewport, and UVEILPauseMenu NativeConstruct builds its whole tree through WidgetTree at its first lines. A crash writes its own record: the project log tail under Saved Logs and the crash context under Saved Crashes carry the fatal line and the callstack in the engine own words. One, the job finds the newest log in Saved Logs and prints its last 70 lines whole. Two, it finds the newest crash folder under Saved Crashes and prints the crash context lines that carry the error message and the callstack, capped at 60. Three, it prints any minidump or diagnostics names with sizes. Four, the verdict in one line: CRASH READ with the log name and whether a crash folder stands. This job is read only, launches nothing, and every variable carries the sc445 prefix.) ==='
$sc445root = 'D:\VEIL-OMNI'
$sc445logs = Join-Path $sc445root 'Saved\Logs'
$sc445newlog = $null
if (Test-Path $sc445logs) { $sc445newlog = Get-ChildItem $sc445logs -Filter '*.log' | Sort-Object LastWriteTime -Descending | Select-Object -First 1 }
if ($sc445newlog) { Write-Output ('LOG: ' + $sc445newlog.Name + ' bytes=' + $sc445newlog.Length + ' at=' + $sc445newlog.LastWriteTime); Write-Output '--- LOG TAIL ---'; Get-Content $sc445newlog.FullName -Tail 70 | ForEach-Object { Write-Output ('LT ' + $_) } } else { Write-Output 'LOG: none found' }
$sc445crashes = Join-Path $sc445root 'Saved\Crashes'
$sc445folder = $null
if (Test-Path $sc445crashes) { $sc445folder = Get-ChildItem $sc445crashes -Directory | Sort-Object LastWriteTime -Descending | Select-Object -First 1 }
if ($sc445folder) {
  Write-Output ('CRASH FOLDER: ' + $sc445folder.Name)
  Get-ChildItem $sc445folder.FullName -File | ForEach-Object { Write-Output ('CFILE ' + $_.Name + ' bytes=' + $_.Length) }
  $sc445ctx = Get-ChildItem $sc445folder.FullName -Filter '*.xml' | Select-Object -First 1
  if ($sc445ctx) { $sc445lines = @(Select-String -Path $sc445ctx.FullName -Pattern 'ErrorMessage|CallStack|PCallStack|Fatal' -ErrorAction SilentlyContinue); $sc445lines | Select-Object -First 60 | ForEach-Object { Write-Output ('CTX ' + $_.Line.Trim()) } }
  $sc445clog = Get-ChildItem $sc445folder.FullName -Filter '*.log' | Select-Object -First 1
  if ($sc445clog) { Write-Output '--- CRASH LOG TAIL ---'; Get-Content $sc445clog.FullName -Tail 40 | ForEach-Object { Write-Output ('CL ' + $_) } }
} else { Write-Output 'CRASH FOLDER: none found' }
$sc445has = 0; if ($sc445folder) { $sc445has = 1 }
Write-Output ('PHI SC445 VERDICT: CRASH READ crash_folder=' + $sc445has)
Write-Output 'JOB 445 DONE'
```
