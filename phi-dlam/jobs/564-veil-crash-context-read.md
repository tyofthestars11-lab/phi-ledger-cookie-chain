<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 564 - VEIL CRASH CONTEXT READ (Ground: Job 561 found no callstack lines in the crash log and no fatal line in the current log, so this job reads the crash context file in the same crash folder and prints the error message and callstack and module lines from it, no patch, no build. Every variable carries the p564 prefix.) ==='
$p564crashRoot = 'D:\VEIL-OMNI\Saved\Crashes'
if (Test-Path $p564crashRoot) {
  $p564latest = Get-ChildItem -Path $p564crashRoot -Directory | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($p564latest) {
    Write-Output ('CRASH FOLDER ' + $p564latest.FullName + ' ' + $p564latest.LastWriteTime)
    $p564all = Get-ChildItem -Path $p564latest.FullName -Recurse -File -ErrorAction SilentlyContinue
    foreach ($p564a in $p564all) { Write-Output ('FOLDER FILE ' + $p564a.FullName + ' BYTES ' + $p564a.Length) }
    $p564ctx = Join-Path $p564latest.FullName 'CrashContext.runtime-xml'
    if (Test-Path $p564ctx) {
      Write-Output ('CONTEXT FILE ' + $p564ctx)
      @(Select-String -Path $p564ctx -Pattern 'CallStack|ErrorMessage|Module|VEIL' | Select-Object -First 60) | ForEach-Object { Write-Output ('CONTEXT LINE ' + $_.Line.Trim()) }
      $p564first = Get-Content $p564ctx -TotalCount 80
      foreach ($p564l in $p564first) { Write-Output ('CONTEXT HEAD ' + $p564l.Trim()) }
    } else { Write-Output 'NO CONTEXT FILE FOUND' }
  } else { Write-Output 'NO CRASH FOLDER FOUND' }
} else { Write-Output 'NO CRASH FOLDER FOUND' }
Write-Output 'PHI P564 VERDICT: VEIL CRASH CONTEXT READ ABOVE'
Write-Output 'JOB 564 DONE'
```
