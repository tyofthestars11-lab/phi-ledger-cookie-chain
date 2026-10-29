<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 558 - NAME THE VEIL CRASH (Ground: Tyree reports VEIL crashes for whatever reason, so this job reads the latest crash folder and log tail and prints the named reason, no guessing, no patch, no build. Every variable carries the p558 prefix.) ==='
$p558crashRoot = 'D:\VEIL-OMNI\Saved\Crashes'
if (Test-Path $p558crashRoot) {
  $p558latest = Get-ChildItem -Path $p558crashRoot -Directory | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($p558latest) {
    Write-Output ('CRASH FOLDER ' + $p558latest.FullName + ' ' + $p558latest.LastWriteTime)
    $p558logs = Get-ChildItem -Path $p558latest.FullName -Recurse -Filter '*.log' -ErrorAction SilentlyContinue | Select-Object -First 2
    foreach ($p558lg in $p558logs) {
      Write-Output ('CRASH LOG ' + $p558lg.FullName)
      @(Select-String -Path $p558lg.FullName -Pattern 'Fatal|EXCEPTION|Callstack' | Select-Object -First 20) | ForEach-Object { Write-Output ('CRASH LINE ' + $_.Line.Trim()) }
    }
  } else { Write-Output 'NO CRASH FOLDER FOUND' }
} else { Write-Output 'NO CRASH FOLDER FOUND' }
$p558velog = 'D:\VEIL-OMNI\Saved\Logs\VEIL.log'
if (Test-Path $p558velog) {
  @(Select-String -Path $p558velog -Pattern 'Fatal|EXCEPTION' | Select-Object -Last 20) | ForEach-Object { Write-Output ('VEIL LOG LINE ' + $_.Line.Trim()) }
} else { Write-Output 'NO VEIL LOG FOUND' }
Write-Output 'PHI P558 VERDICT: VEIL CRASH READ ABOVE'
Write-Output 'JOB 558 DONE'
```
