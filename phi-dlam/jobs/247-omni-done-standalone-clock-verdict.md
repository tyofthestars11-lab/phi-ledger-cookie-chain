# Job 247 — OMNI_DONE standalone launch: same clock verdict on OMNI's rails

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 246s twin for OMNI. OMNIs packaging path was the rough one: attempt 1 died on the UAT mutex before its log was set (231/232 launched together), attempt 2 was launched by 240 while VEIL was still cooking, and 244 may have launched attempt 3 gated on VEIL finishing. Whichever attempt produced the archive, this job launches the OMNI_DONE exe standalone for 45 seconds and reads its log for the same telemetry: PHI TICKPROOF / worldTime / MOVE / GAMEMODE. If no exe stands yet, it reports the archive state - the OMNI verdict then rides the next drain after the package lands. ==='
$arch = 'D:\Builds\OMNI\OMNI_DONE'
$exe = $null
if (Test-Path $arch) { $exe = Get-ChildItem $arch -Recurse -Filter 'OMNI.exe' -ErrorAction SilentlyContinue | Select-Object -First 1 }
if (-not $exe) {
  Write-Output "OMNI_DONE exe NOT FOUND under $arch - package still in flight or failed; standalone test not attempted."
  if (Test-Path $arch) { Get-ChildItem $arch -Recurse -ErrorAction SilentlyContinue | Select-Object -First 20 | ForEach-Object { $_.FullName } }
} else {
  Write-Output "exe: $($exe.FullName) $([math]::Round($exe.Length/1MB,1)) MB"
  $p = Start-Process -FilePath $exe.FullName -ArgumentList '-log' -PassThru -WindowStyle Hidden
  Write-Output "launched pid $($p.Id) - running 45s"
  Start-Sleep -Seconds 45
  $alive = Get-Process -Id $p.Id -ErrorAction SilentlyContinue
  if ($alive) { Write-Output 'still running at 45s - closing it'; Stop-Process -Id $p.Id -Force } else { Write-Output "exited on its own, exit code: $($p.ExitCode)" }
  Start-Sleep -Seconds 3
  $logDir = Join-Path $arch 'Windows\OMNI\Saved\Logs'
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
