# Job 246 — VEIL_DONE standalone launch: the frozen clock's verdict (editor context vs cooked data)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The decisive rung of the finish-the-games ladder. Every frozen-clock measurement so far was taken inside the editor or PIE: PC ticks with real DeltaSeconds, TimeSeconds 0.00 forever, timers frozen, pawn Tick 0 - and the reflection census (234-236) cleared the maps WorldSettings of every flag Meta named. If the packaged game, running on its own with no editor anywhere, advances its clock and moves its pawn, the freeze is an editor-context phenomenon of these maps. If it freezes identically, the freeze is in the cooked data itself. This job launches the VEIL_DONE archive exe (job 239s attempt 2, ProjectID struct form), lets it run 45 seconds, closes it, and reads its own log for the telemetry lines the module carries: PHI TICKPROOF / worldTime / MOVE / GAMEMODE. If the exe is not there, the job reports the archive state and the verdict stays with 244s census - it does not guess. ==='
$arch = 'D:\Builds\VEIL\VEIL_DONE'
$exe = $null
if (Test-Path $arch) { $exe = Get-ChildItem $arch -Recurse -Filter 'VEIL.exe' -ErrorAction SilentlyContinue | Select-Object -First 1 }
if (-not $exe) {
  Write-Output "VEIL_DONE exe NOT FOUND under $arch - package verdict belongs to job 244s census; standalone test not attempted."
  if (Test-Path $arch) { Get-ChildItem $arch -Recurse -ErrorAction SilentlyContinue | Select-Object -First 20 | ForEach-Object { $_.FullName } }
} else {
  Write-Output "exe: $($exe.FullName) $([math]::Round($exe.Length/1MB,1)) MB"
  $p = Start-Process -FilePath $exe.FullName -ArgumentList '-log' -PassThru -WindowStyle Hidden
  Write-Output "launched pid $($p.Id) - running 45s"
  Start-Sleep -Seconds 45
  $alive = Get-Process -Id $p.Id -ErrorAction SilentlyContinue
  if ($alive) { Write-Output 'still running at 45s - closing it'; Stop-Process -Id $p.Id -Force } else { Write-Output "exited on its own, exit code: $($p.ExitCode)" }
  Start-Sleep -Seconds 3
  $logDir = Join-Path $arch 'Windows\VEIL\Saved\Logs'
  $log = Get-ChildItem $logDir -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($log) {
    Write-Output "--- game log: $($log.FullName) $($log.Length) bytes ---"
    $ll = Get-Content $log.FullName
    $ll | Select-String -Pattern 'TICKPROOF|worldTime|TimeSeconds|MOVE TEST|GAMEMODE|PHI BODY|Error' | Select-Object -First 40 | ForEach-Object { $_.Line }
    Write-Output '--- log tail ---'
    $ll | Select-Object -Last 10
  } else { Write-Output "no game log found under $logDir" }
}
```
