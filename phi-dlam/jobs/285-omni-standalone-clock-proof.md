<!-- PHI-DIRECT -->
```powershell
Write-Output '=== The OMNI archive (job 279s cook, verdict read by 284) gets the same standalone proof VEIL passed in job 278: launch the packaged exe, let it run, read the PHI TICKPROOF census lines from its own log, close it. Guards: if a UAT is alive or the archive exe is missing, report the terrain and end - the proof re-queues rather than fight a cook for RAM on a 16GB machine. ==='
$uat = @(Get-Process -Name 'AutomationTool' -ErrorAction SilentlyContinue)
Write-Output "UAT processes running: $($uat.Count)"
if ($uat.Count -gt 0) { Write-Output 'HELD - a cook is running'; Write-Output 'OMNI STANDALONE PROOF DONE'; return }
$exe = Get-ChildItem 'D:\Builds\OMNI' -Recurse -Filter 'OMNI.exe' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if (-not $exe) { Write-Output 'archive exe not found under D:\Builds\OMNI'; Write-Output 'OMNI STANDALONE PROOF DONE'; return }
Write-Output "archive exe: $($exe.FullName) stamp $($exe.LastWriteTime)"
$p = Start-Process -FilePath $exe.FullName -ArgumentList '-PhiStandaloneProof' -PassThru
Write-Output "standalone launched pid $($p.Id); sampling window 40s"
Start-Sleep -Seconds 40
$logDir = Join-Path $exe.DirectoryName 'OMNI\Saved\Logs'
$log = Get-ChildItem $logDir -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($log) {
  Write-Output "log: $($log.FullName)"
  $lines = Select-String -Path $log.FullName -Pattern 'PHI TICKPROOF|PHI PC TICKPROOF|PHI CLOCK PROOF|PHI STANDALONE PROOF|Error|Traceback|Exception' | ForEach-Object { $_.Line }
  Write-Output "census lines: $($lines.Count)"
  $lines | Select-Object -Last 14 | Write-Output
} else { Write-Output "no log found under $logDir" }
try { $p | Stop-Process -Force -ErrorAction SilentlyContinue } catch {}
if (-not $p.HasExited) { try { $p.Kill() } catch {} }
Write-Output 'standalone closed'
Write-Output 'OMNI STANDALONE CLOCK PROOF DONE'
```
