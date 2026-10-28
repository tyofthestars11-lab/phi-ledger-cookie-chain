<!-- PHI-DIRECT -->
```powershell
Write-Output '=== READ THE REMAINS OF THE 395 RUN 398 - NO LONG SLEEPS, EVERYTHING INSIDE THE STEP WINDOW: job 395 section 1 verified the complex-as-simple set standing on both mountain meshes, CTF_USE_COMPLEX_AS_SIMPLE on SM_Mountain_01 and on SM_Iceland_Mountain_02, and its section 2 launched VEILDistrict in game mode with a 300 second capture, but the runner 240 second step timeout killed that job before its log read ran, so no proof lines were captured in its result. The game process was started detached by that job, so it may still stand on this PC as an orphan, and the log it writes, the newest file under the merged base Saved Logs, may already carry the proof lines from the minutes it has lived. THIS JOB, merged base at D VEIL-OMNI: one, census every UnrealEditor process with PID, start time and full command line printed, and name any whose command line carries the game flag and the VEIL project path as the 395 run. Two, read the newest log whole in its parts: its file name and last write time, the count of static mesh and async compilation build lines with the first and the last printed, every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line, and the last 15 lines of the log. Three, if the 395 run process still stands, stop it by its PID after the log read and print RUN PROCESS STOPPED with the PID, or print NO RUN PROCESS STANDING. Four, the verdict in its true shape: PROOF LINES LANDED with the tick series, floorBlock and capZ across the ticks - or NO PROOF LINES IN THE RUN LOG, with the last build line printed as the evidence of how far the world build got.) ==='
$base = 'D:\VEIL-OMNI'
Write-Output '--- SECTION 1: PROCESS CENSUS ---'
$runPids = @()
$cims = @(Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.Name -eq 'UnrealEditor.exe' -or $_.Name -eq 'UnrealEditor-Cmd.exe' })
Write-Output ("EDITOR PROCESS COUNT: " + $cims.Count)
foreach ($c in $cims) {
  $cl = $c.CommandLine
  if (-not $cl) { $cl = '' }
  $started = 'unknown'
  $gp = Get-Process -Id $c.ProcessId -ErrorAction SilentlyContinue
  if ($gp) { try { $started = $gp.StartTime.ToString('yyyy-MM-dd HH:mm:ss') } catch { $started = 'unknown' } }
  Write-Output ("PROC PID=" + $c.ProcessId + " NAME=" + $c.Name + " STARTED=" + $started)
  Write-Output (" CMD=" + $cl)
  if (($cl -match '-game') -and ($cl -match 'VEIL\.uproject')) {
    Write-Output (" GAME RUN FOUND PID=" + $c.ProcessId + " - the 395 run shape")
    $runPids += $c.ProcessId
  }
}
if ($runPids.Count -eq 0) { Write-Output 'NO GAME RUN PROCESS IN CENSUS' }
Write-Output '--- SECTION 2: NEWEST RUN LOG READ ---'
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
$hits = @()
$build = @()
if ($logf) {
  Write-Output ("RUN LOG: " + $logf.FullName)
  Write-Output ("RUN LOG LAST WRITE: " + $logf.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))
  $build = @(Select-String -Path $logf.FullName -Pattern 'LogStaticMesh|LogAsyncCompilation' -ErrorAction SilentlyContinue)
  Write-Output ("PHI PROOF398 BUILD LINES count=" + $build.Count)
  if ($build.Count -gt 0) {
    Write-Output '--- FIRST BUILD LINE ---'
    $build[0].Line | Write-Output
    Write-Output '--- LAST BUILD LINE ---'
    $build[$build.Count - 1].Line | Write-Output
  } else { Write-Output 'NO BUILD LINES IN LOG' }
  $hits = @(Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH|PHI TUMBLEKILL 371|PHI CCDLOCK 372' -ErrorAction SilentlyContinue)
  if ($hits.Count -gt 0) { Write-Output '--- PROOF LINES ---'; $hits | ForEach-Object { $_.Line } | Write-Output } else { Write-Output 'NO PROOF LINES IN LOG for this run' }
  Write-Output '--- RUN LOG LAST 15 LINES ---'
  Get-Content $logf.FullName -Tail 15 | Write-Output
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output '--- SECTION 3: CLOSE THE RUN ---'
$stopped = 0
foreach ($pidRun in $runPids) {
  $p = Get-Process -Id $pidRun -ErrorAction SilentlyContinue
  if ($p) {
    Stop-Process -Id $pidRun -Force -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 2
    Write-Output ("RUN PROCESS STOPPED PID=" + $pidRun)
    $stopped++
  } else { Write-Output ("RUN PROCESS ALREADY GONE PID=" + $pidRun) }
}
if ($stopped -eq 0) { Write-Output 'NO RUN PROCESS STANDING' }
Write-Output '--- VERDICT ---'
if ($hits.Count -gt 0) {
  Write-Output 'PHI PROOF398 VERDICT: PROOF LINES LANDED'
  Write-Output '--- TICK SERIES ---'
  $hits | Where-Object { $_.Line -match 'PHI TICK TRUTH' } | ForEach-Object { $_.Line } | Write-Output
} else {
  Write-Output 'PHI PROOF398 VERDICT: NO PROOF LINES IN THE RUN LOG'
  if ($build.Count -gt 0) { Write-Output 'LAST BUILD LINE AS EVIDENCE:'; $build[$build.Count - 1].Line | Write-Output } else { Write-Output 'NO BUILD LINE STANDS AS EVIDENCE' }
}
Write-Output 'JOB 398 DONE'
```
