<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 568 - TERMINAL MASTERTOGGLE AND HUNTCAP READ (Ground: Job 565 printed the hunt watch stop at stage over 3 and the attach redirect body but not the MasterToggle function body, so this job prints the MasterToggle function definition and the hunt cap lines, no patch, no relaunch. Every variable carries the p568 prefix.) ==='
$p568src = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs'
if (Test-Path $p568src) {
  $p568lines = Get-Content $p568src
  Write-Output ('SOURCE LINES ' + $p568lines.Count)
  $p568masterIdx = -1
  for ($p568i = 0; $p568i -lt $p568lines.Count; $p568i++) { if ($p568lines[$p568i] -match 'void MasterToggle') { $p568masterIdx = $p568i; break } }
  Write-Output ('MASTER INDEX ' + $p568masterIdx)
  if ($p568masterIdx -ge 0) {
    $p568mend = [Math]::Min($p568lines.Count - 1, $p568masterIdx + 80)
    for ($p568k = $p568masterIdx; $p568k -le $p568mend; $p568k++) { Write-Output ('MASTER BODY ' + $p568k + ' ' + $p568lines[$p568k].Trim()) }
  }
  @(Select-String -Path $p568src -Pattern 'huntStage' | Select-Object -First 30) | ForEach-Object { Write-Output ('HUNT LINE ' + $_.Line.Trim()) }
} else { Write-Output 'NO TERMINAL SOURCE FOUND' }
Write-Output 'PHI P568 VERDICT: TERMINAL MASTERTOGGLE AND HUNTCAP READ ABOVE'
Write-Output 'JOB 568 DONE'
```
