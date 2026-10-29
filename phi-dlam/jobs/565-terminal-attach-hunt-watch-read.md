<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 565 - TERMINAL ATTACH AND HUNT WATCH READ (Ground: Job 562 showed the attach function and hunt functions exist but did not print the launcher redirect body or the hunt watch stop reason, so this job prints the attach function body and the hunt watch body from the terminal source, no patch, no relaunch. Every variable carries the p565 prefix.) ==='
$p565src = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs'
$p565launch = ('Launche' + [char]114)
if (Test-Path $p565src) {
  $p565lines = Get-Content $p565src
  Write-Output ('SOURCE LINES ' + $p565lines.Count)
  @(Select-String -Path $p565src -Pattern $p565launch | Select-Object -First 30) | ForEach-Object { Write-Output ('LAUNCHER LINE ' + $_.Line.Trim()) }
  $p565attachIdx = -1
  for ($p565i = 0; $p565i -lt $p565lines.Count; $p565i++) { if ($p565lines[$p565i] -match 'AttachForeground') { if ($p565lines[$p565i] -match 'private') { $p565attachIdx = $p565i; break } } }
  Write-Output ('ATTACH INDEX ' + $p565attachIdx)
  if ($p565attachIdx -ge 0) {
    $p565end = [Math]::Min($p565lines.Count - 1, $p565attachIdx + 90)
    for ($p565k = $p565attachIdx; $p565k -le $p565end; $p565k++) { Write-Output ('ATTACH BODY ' + $p565k + ' ' + $p565lines[$p565k].Trim()) }
  }
  $p565huntIdx = -1
  for ($p565i = 0; $p565i -lt $p565lines.Count; $p565i++) { if ($p565lines[$p565i] -match 'StartHuntWatch') { $p565huntIdx = $p565i; break } }
  Write-Output ('HUNT INDEX ' + $p565huntIdx)
  if ($p565huntIdx -ge 0) {
    $p565hend = [Math]::Min($p565lines.Count - 1, $p565huntIdx + 70)
    for ($p565k = $p565huntIdx; $p565k -le $p565hend; $p565k++) { Write-Output ('HUNT BODY ' + $p565k + ' ' + $p565lines[$p565k].Trim()) }
  }
  $p565masterIdx = -1
  for ($p565i = 0; $p565i -lt $p565lines.Count; $p565i++) { if ($p565lines[$p565i] -match 'MasterToggle') { $p565masterIdx = $p565i; break } }
  Write-Output ('MASTER INDEX ' + $p565masterIdx)
  if ($p565masterIdx -ge 0) {
    $p565mend = [Math]::Min($p565lines.Count - 1, $p565masterIdx + 40)
    for ($p565k = $p565masterIdx; $p565k -le $p565mend; $p565k++) { Write-Output ('MASTER BODY ' + $p565k + ' ' + $p565lines[$p565k].Trim()) }
  }
} else { Write-Output 'NO TERMINAL SOURCE FOUND' }
Write-Output 'PHI P565 VERDICT: TERMINAL ATTACH AND HUNT WATCH READ ABOVE'
Write-Output 'JOB 565 DONE'
```
