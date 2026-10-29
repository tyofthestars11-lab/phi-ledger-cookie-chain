<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 561 - VEIL CRASH CALLSTACK READ (Ground: Job 558 named the crash as a fatal access violation at address zero in the 08:36 crash folder, so this job reads the full callstack and the log lines before the fatal line and prints the faulting module and function, no patch, no build. Every variable carries the p561 prefix.) ==='
$p561crashRoot = 'D:\VEIL-OMNI\Saved\Crashes'
if (Test-Path $p561crashRoot) {
  $p561latest = Get-ChildItem -Path $p561crashRoot -Directory | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($p561latest) {
    Write-Output ('CRASH FOLDER ' + $p561latest.FullName + ' ' + $p561latest.LastWriteTime)
    $p561all = Get-ChildItem -Path $p561latest.FullName -Recurse -File -ErrorAction SilentlyContinue
    foreach ($p561a in $p561all) { Write-Output ('FOLDER FILE ' + $p561a.FullName) }
    $p561logs = Get-ChildItem -Path $p561latest.FullName -Recurse -Filter '*.log' -ErrorAction SilentlyContinue | Select-Object -First 3
    foreach ($p561lg in $p561logs) {
      Write-Output ('CRASH FILE ' + $p561lg.FullName)
      @(Select-String -Path $p561lg.FullName -Pattern 'Callstack' | Select-Object -First 40) | ForEach-Object { Write-Output ('CALLSTACK LINE ' + $_.Line.Trim()) }
      @(Select-String -Path $p561lg.FullName -Pattern 'Fatal|EXCEPTION' | Select-Object -First 20) | ForEach-Object { Write-Output ('CRASH LINE ' + $_.Line.Trim()) }
    }
  } else { Write-Output 'NO CRASH FOLDER FOUND' }
} else { Write-Output 'NO CRASH FOLDER FOUND' }
$p561velog = 'D:\VEIL-OMNI\Saved\Logs\VEIL.log'
if (Test-Path $p561velog) {
  $p561lines = Get-Content $p561velog
  $p561idx = -1
  for ($p561i = 0; $p561i -lt $p561lines.Count; $p561i++) { if ($p561lines[$p561i] -match 'Fatal') { $p561idx = $p561i } }
  Write-Output ('FATAL INDEX ' + $p561idx)
  if ($p561idx -gt 0) {
    $p561start = [Math]::Max(0, $p561idx - 50)
    for ($p561j = $p561start; $p561j -le $p561idx; $p561j++) { Write-Output ('LOG BEFORE ' + $p561lines[$p561j].Trim()) }
  }
} else { Write-Output 'NO VEIL LOG FOUND' }
Write-Output 'PHI P561 VERDICT: VEIL CRASH CALLSTACK READ ABOVE'
Write-Output 'JOB 561 DONE'
```
