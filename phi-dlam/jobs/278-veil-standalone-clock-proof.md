# Job 278 — VEIL standalone clock proof (the archive 273 cooked: dressed maps + title-unpause fix)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The archive under D:\Builds\VEIL\VEIL_DONE was cooked from the dressed maps with the title SetPause fix compiled in (253 proved the same code in the editor: worldTime 25.02, pawnTickEntries 3186). This is the standalone proof of that archive: launch the packaged exe, let it run, read the census lines from its own log, close it. If the 273 cook is still running (UAT alive), hold and report instead - the proof rides the next drain rather than fight a cook for RAM on a 16GB machine. ==='
$uatRun = Get-Process -Name 'dotnet','AutomationTool' -ErrorAction SilentlyContinue
Write-Output "UAT processes running: $(@($uatRun).Count)"
$exe = Get-ChildItem 'D:\Builds\VEIL\VEIL_DONE' -Recurse -Filter 'VEIL.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($uatRun) { Write-Output 'HELD - the 273 cook is still running; proof deferred to the next drain' }
elseif (-not $exe) { Write-Output 'HELD - VEIL.exe not present in the archive yet; the cook has not landed' }
else {
  Write-Output "archive exe: $($exe.FullName) stamp $($exe.LastWriteTime)"
  $p = Start-Process $exe.FullName -ArgumentList @('-windowed','-ResX=960','-ResY=540') -PassThru
  Write-Output "standalone launched pid $($p.Id); sampling window 40s"
  Start-Sleep -Seconds 40
  $logDirs = @('D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs', "$env:LOCALAPPDATA\VEIL\Saved\Logs")
  $log = $null
  foreach ($d in $logDirs) { $cand = Get-ChildItem $d -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1; if ($cand) { $log = $cand; break } }
  if ($log) {
    Write-Output "log: $($log.FullName)"
    $hits = Select-String -Path $log.FullName -Pattern 'worldTime|pawnTick|BODY CHECK|samplesWith' -ErrorAction SilentlyContinue
    Write-Output "census lines: $(@($hits).Count)"
    $hits | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() }
  } else { Write-Output 'no game log found in either Saved\Logs location' }
  Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
  Write-Output 'standalone closed'
}
Write-Output 'VEIL STANDALONE CLOCK PROOF DONE'
```
