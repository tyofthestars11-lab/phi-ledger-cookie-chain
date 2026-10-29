<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 541 - READ THE ATTACK EVIDENCE BEFORE TOUCHING CODE (Ground: Tyree at his screen 2026-10-28 19:59 MDT, the game up on the guarded build with no crash in the frame, and his standing report from 19:31 MDT that attack still does not land under his hands. The 527 binds seat Fire on the right trigger and the Tick carries a pad proof block that prints whether the built and default mapping contexts are present in the standalone window, plus the Fire code prints its own visible line when it runs. Guessing another bind without that evidence is the dead code class. This job reads only: it finds the newest standalone log, prints the pad proof values, the locomotion lines, every attack line, and any error lines near the end, plus whether the game process stands and when the log last wrote. No source is changed, no build runs, no relaunch rides this job. Every variable carries the p541 prefix.) ==='
$p541logs = 'D:\VEIL-OMNI\Saved\Logs'
if (Test-Path $p541logs) {
  $p541files = @(Get-ChildItem $p541logs -Filter '*.log' | Sort-Object LastWriteTime -Descending)
  foreach ($p541f in $p541files) { Write-Output ('LOGFILE ' + $p541f.Name + ' WRITE=' + $p541f.LastWriteTime) }
  if ($p541files.Count -gt 0) {
    $p541log = $p541files[0].FullName
    $p541pad = @(Select-String -Path $p541log -Pattern 'PHI PAD PROOF' | Select-Object -Last 5)
    foreach ($p541m in $p541pad) { Write-Output ('PAD ' + $p541m.Line) }
    if ($p541pad.Count -eq 0) { Write-Output 'PAD NONE FOUND' }
    $p541loc = @(Select-String -Path $p541log -Pattern 'PHI LOCOMOTION' | Select-Object -Last 5)
    foreach ($p541m in $p541loc) { Write-Output ('LOCO ' + $p541m.Line) }
    if ($p541loc.Count -eq 0) { Write-Output 'LOCO NONE FOUND' }
    $p541atk = @(Select-String -Path $p541log -Pattern 'PHI ATTACK' | Select-Object -Last 10)
    foreach ($p541m in $p541atk) { Write-Output ('ATTACK ' + $p541m.Line) }
    if ($p541atk.Count -eq 0) { Write-Output 'ATTACK NONE FOUND' }
    $p541err = @(Select-String -Path $p541log -Pattern 'Error|Exception' | Select-Object -Last 10)
    foreach ($p541m in $p541err) { Write-Output ('LOGERR ' + $p541m.Line) }
    if ($p541err.Count -eq 0) { Write-Output 'LOGERR NONE FOUND' }
  } else { Write-Output 'LOG NONE FOUND' }
} else { Write-Output 'LOGDIR MISSING' }
$p541proc = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
foreach ($p541p in $p541proc) { Write-Output ('GAMEPROC pid=' + $p541p.Id) }
if ($p541proc.Count -eq 0) { Write-Output 'GAMEPROC NONE RUNNING' }
Write-Output 'PHI P541 VERDICT: PAD LOCO ATTACK AND ERROR LINES ABOVE - THE NEXT FIX READS THEM'
Write-Output 'JOB 541 DONE'
```
