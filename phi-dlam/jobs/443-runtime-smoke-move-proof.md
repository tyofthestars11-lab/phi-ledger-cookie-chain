<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RUNTIME SMOKE 443 - THE REPAIRED GAME PROVES ITSELF IN ITS OWN LOG (Ground: job 434 seated the single voice, o01 zero and v01 one, Result Succeeded; job 442 repaired the input at the bind, fallback call sites two, Result Succeeded, and job 440 Hub section compiled into the same green build. The character carries its own instrument for exactly this hour, PHI MOVE TEST v3, tick driven: at five seconds of tick time it names the possession state, drives synthetic forward input for about a second, and reports the velocity and displacement produced. This job runs the game the standing smoke way, the editor exe with the project in game mode, windowed, log to Saved smoke443 log, waits one hundred seconds inside the step bound, reads the proof lines, and closes the process it launched on every path. The lines that carry the verdict: PHI VOICE lines with their count, so the narrator reads once; the built-in map active line from the input fallback; PHI BODY CHECK; PHI MOVE TEST BEGIN and its result line, with the displacement number whole. One, it launches and prints the pid. Two, it waits, then greps the log for the proof patterns, capped at 40 lines. Three, it counts the V01 voice lines. Four, it closes the process and prints the close. Five, the verdict in one line: SMOKE with the v01 count, the move displacement as printed, and the close state. Every variable carries the sm443 prefix.) ==='
$sm443root = 'D:\VEIL-OMNI'
$sm443editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$sm443uproj = Join-Path $sm443root 'VEIL.uproject'
$sm443log = Join-Path $sm443root 'Saved\smoke443.log'
if (Test-Path $sm443log) { Remove-Item $sm443log -Force }
$sm443proc = $null
try {
  $sm443proc = Start-Process $sm443editor -ArgumentList ('"' + $sm443uproj + '" -game -windowed -ResX=1280 -ResY=720 -abslog=' + $sm443log) -PassThru
  Write-Output ('LAUNCHED pid=' + $sm443proc.Id)
  Start-Sleep -Seconds 100
  if (Test-Path $sm443log) {
    $sm443hits = @(Select-String -Path $sm443log -Pattern 'PHI VOICE|MOVE TEST|built-in map|PHI BODY CHECK|VEIL WORLD BUILT|Error|HUB SEATED|LogTemp' -ErrorAction SilentlyContinue)
    $sm443hits | Select-Object -First 40 | ForEach-Object { Write-Output ('HIT ' + $_.Line.Trim()) }
    $sm443voice = @(Select-String -Path $sm443log -Pattern 'PHI VOICE' -ErrorAction SilentlyContinue)
    $sm443v01 = @($sm443voice | Where-Object { $_.Line -match 'V01' }).Count
    Write-Output ('VOICE LINES=' + $sm443voice.Count + ' V01=' + $sm443v01)
  } else { Write-Output 'SMOKE LOG ABSENT'; $sm443v01 = -1 }
} finally {
  if ($sm443proc -and -not $sm443proc.HasExited) { Stop-Process -Id $sm443proc.Id -Force -ErrorAction SilentlyContinue; Write-Output ('CLOSED pid=' + $sm443proc.Id) } else { Write-Output 'CLOSE: process already out' }
}
Write-Output ('PHI SM443 VERDICT: SMOKE v01=' + $sm443v01)
Write-Output 'JOB 443 DONE'
```
