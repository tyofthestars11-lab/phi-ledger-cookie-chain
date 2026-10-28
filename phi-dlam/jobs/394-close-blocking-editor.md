<!-- PHI-DIRECT -->
```powershell
Write-Output '=== NAME AND CLOSE THE BLOCKING EDITOR 394 - THE FIX WORD FROM TYREE IS THE AUTHORITY FOR THIS JOB: four lane jobs stand consumed as deferred on one state, an Unreal editor process open on this PC, and the commandlet and game jobs defer rather than fight it. THIS JOB: one, census every UnrealEditor and UnrealEditor-Cmd process and print for each its PID, its start time, its full command line and its main window title. Two, classify each from its command line and print the class: JOB LAUNCHED when the line carries the MCP start server flag or a commandlet run token, GAME SESSION when the line carries the game flag (the desktop door opens the project as a game session, no asset editing), EDITING SESSION for anything else. Three, close in order under the Fix word: JOB LAUNCHED instances close outright by Stop-Process; GAME SESSION instances get a graceful CloseMainWindow first, up to 60 seconds, state printed, and if still running they are force closed, a game session holding no unsaved asset edits, the print naming the class it closed; EDITING SESSION instances get the graceful CloseMainWindow only, up to 60 seconds, state printed, and if still open the job prints STILL OPEN - EDITING SESSION HELD and stops, never forcing an editing session. Four, final verification: the process census runs again, the job prints EDITOR COUNT AFTER with the count, and the verdict prints ROAD CLEAR when zero editor processes remain or ROAD HELD with the surviving PID and class.) ==='
function Get-EditorCensus {
  $found = @()
  $cims = @(Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.Name -eq 'UnrealEditor.exe' -or $_.Name -eq 'UnrealEditor-Cmd.exe' })
  foreach ($c in $cims) {
    $cl = $c.CommandLine
    if (-not $cl) { $cl = '' }
    $title = ''
    $started = 'unknown'
    $gp = Get-Process -Id $c.ProcessId -ErrorAction SilentlyContinue
    if ($gp) {
      $title = $gp.MainWindowTitle
      try { $started = $gp.StartTime.ToString('yyyy-MM-dd HH:mm:ss') } catch { $started = 'unknown' }
    }
    $cls = 'EDITING SESSION'
    if ($cl -match 'ModelContextProtocol' -or $cl -match '-run=') { $cls = 'JOB LAUNCHED' }
    elseif ($cl -match '-game') { $cls = 'GAME SESSION' }
    $found += [PSCustomObject]@{ Id = $c.ProcessId; Name = $c.Name; Cmd = $cl; Title = $title; Started = $started; Class = $cls }
  }
  return $found
}
function Show-Census($list, $tag) {
  foreach ($o in $list) {
    Write-Output ("PROC " + $tag + " PID=" + $o.Id)
    Write-Output (" NAME=" + $o.Name)
    Write-Output (" STARTED=" + $o.Started)
    Write-Output (" TITLE=" + $o.Title)
    Write-Output (" CLASS=" + $o.Class)
    Write-Output (" CMD=" + $o.Cmd)
  }
}
function Test-Alive($id) {
  $p = Get-Process -Id $id -ErrorAction SilentlyContinue
  return ($null -ne $p)
}
function Wait-Gone($id, $tries) {
  $w = 0
  while ((Test-Alive $id) -and $w -lt $tries) { Start-Sleep -Seconds 5; $w++ }
  return (Test-Alive $id)
}
Write-Output '--- SECTION 1: EDITOR CENSUS BEFORE ---'
$before = @(Get-EditorCensus)
Write-Output ("EDITOR COUNT BEFORE: " + $before.Count)
Show-Census $before 'BEFORE'
Write-Output '--- SECTION 2: CLOSE JOB LAUNCHED ---'
foreach ($o in $before) {
  if ($o.Class -eq 'JOB LAUNCHED') {
    Stop-Process -Id $o.Id -Force -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 2
    if (Test-Alive $o.Id) { Write-Output (" JOB LAUNCHED PID=" + $o.Id + " STILL RUNNING AFTER STOP-PROCESS") }
    else { Write-Output (" CLOSED JOB LAUNCHED PID=" + $o.Id) }
  }
}
Write-Output '--- SECTION 3: CLOSE GAME SESSIONS ---'
foreach ($o in $before) {
  if ($o.Class -eq 'GAME SESSION') {
    $gp = Get-Process -Id $o.Id -ErrorAction SilentlyContinue
    if ($gp) {
      $null = $gp.CloseMainWindow()
      Write-Output (" GRACEFUL CLOSE SENT TO GAME SESSION PID=" + $o.Id)
      $still = Wait-Gone $o.Id 12
      if ($still) {
        Stop-Process -Id $o.Id -Force -ErrorAction SilentlyContinue
        Start-Sleep -Seconds 2
        Write-Output (" FORCE CLOSED GAME SESSION PID=" + $o.Id + " - a game session holds no unsaved asset edits")
      } else {
        Write-Output (" CLOSED GRACEFULLY GAME SESSION PID=" + $o.Id)
      }
    } else { Write-Output (" GAME SESSION PID=" + $o.Id + " ALREADY GONE") }
  }
}
Write-Output '--- SECTION 4: EDITING SESSIONS - GRACEFUL ONLY ---'
$heldEdit = $false
foreach ($o in $before) {
  if ($o.Class -eq 'EDITING SESSION') {
    if ($heldEdit) { continue }
    $gp = Get-Process -Id $o.Id -ErrorAction SilentlyContinue
    if ($gp) {
      $null = $gp.CloseMainWindow()
      Write-Output (" GRACEFUL CLOSE SENT TO EDITING SESSION PID=" + $o.Id)
      $still = Wait-Gone $o.Id 12
      if ($still) {
        Write-Output ("STILL OPEN - EDITING SESSION HELD PID=" + $o.Id)
        $heldEdit = $true
      } else {
        Write-Output (" CLOSED GRACEFULLY EDITING SESSION PID=" + $o.Id)
      }
    } else { Write-Output (" EDITING SESSION PID=" + $o.Id + " ALREADY GONE") }
  }
}
Write-Output '--- SECTION 5: FINAL CENSUS ---'
$after = @(Get-EditorCensus)
Write-Output ("EDITOR COUNT AFTER: " + $after.Count)
Show-Census $after 'AFTER'
Write-Output '--- VERDICT ---'
if ($after.Count -eq 0) { Write-Output 'PHI 394 VERDICT: ROAD CLEAR' }
else {
  foreach ($o in $after) { Write-Output (" SURVIVOR PID=" + $o.Id + " CLASS=" + $o.Class) }
  Write-Output 'PHI 394 VERDICT: ROAD HELD'
}
Write-Output 'JOB 394 DONE'
```
