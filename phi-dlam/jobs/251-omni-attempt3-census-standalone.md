# Job 251 — OMNI attempt 3: package verdict + standalone clock test in one pass

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 244 launched OMNI_DONE attempt 3 (pid 8692) gated on VEIL finished, after attempt 2 died on the UAT mutex (1,291-byte log, ExitCode 1). This job reads attempt 3s log whole - verdict, Error lines, the archive exe - and if the exe stands, immediately runs job 247s deferred test: launch OMNI standalone 45 seconds and read its own logs telemetry (PHI TICKPROOF / worldTime / GAMEMODE). VEILs standalone verdict is already in (job 246: frozen identically, so the freeze is in the game data/code); OMNI is expected to rhyme, but the record measures, it does not assume. ==='
$log = 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone3.log'
if (Test-Path $log) {
  $fi = Get-Item $log
  Write-Output "attempt3 log: $($fi.Length) bytes, last write $($fi.LastWriteTime)"
  $ll = Get-Content $log
  $errs = @($ll | Select-String -Pattern 'Error:')
  Write-Output "Error: lines = $($errs.Count)"
  $errs | Select-Object -First 10 | ForEach-Object { $_.Line }
  $ll | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting' | Select-Object -Last 3 | ForEach-Object { $_.Line }
} else { Write-Output "attempt3 log MISSING: $log" }
$arch = 'D:\Builds\OMNI\OMNI_DONE'
$exe = $null
if (Test-Path $arch) { $exe = Get-ChildItem $arch -Recurse -Filter 'OMNI.exe' -ErrorAction SilentlyContinue | Sort-Object Length -Descending | Select-Object -First 1 }
if (-not $exe) {
  Write-Output "OMNI_DONE exe NOT FOUND under $arch - standalone test not attempted."
  if (Test-Path $arch) { Get-ChildItem $arch -Recurse -ErrorAction SilentlyContinue | Select-Object -First 15 | ForEach-Object { $_.FullName } }
} else {
  Write-Output "exe: $($exe.FullName) $([math]::Round($exe.Length/1MB,1)) MB"
  $stub = Get-ChildItem $arch -Recurse -Filter 'OMNI.exe' -ErrorAction SilentlyContinue | Sort-Object Length | Select-Object -First 1
  $launch = if ($stub -and $stub.FullName -ne $exe.FullName -and $stub.Length -lt 2MB) { $stub.FullName } else { $exe.FullName }
  Write-Output "launching: $launch"
  $p = Start-Process -FilePath $launch -ArgumentList '-log' -PassThru -WindowStyle Hidden
  Write-Output "launched pid $($p.Id) - running 45s"
  Start-Sleep -Seconds 45
  $alive = Get-Process -Id $p.Id -ErrorAction SilentlyContinue
  if ($alive) { Write-Output 'still running at 45s - closing it'; Stop-Process -Id $p.Id -Force } else { Write-Output "exited on its own, exit code: $($p.ExitCode)" }
  Start-Sleep -Seconds 3
  $logDir = Join-Path $arch 'Windows\OMNI\Saved\Logs'
  $glog = Get-ChildItem $logDir -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($glog) {
    Write-Output "--- game log: $($glog.FullName) $($glog.Length) bytes ---"
    $gl = Get-Content $glog.FullName
    $gl | Select-String -Pattern 'TICKPROOF|worldTime|MOVE TEST|GAMEMODE|PHI BODY|Error' | Select-Object -First 40 | ForEach-Object { $_.Line }
    Write-Output '--- log tail ---'
    $gl | Select-Object -Last 8
  } else { Write-Output "no game log found under $logDir" }
}
```
