<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 562 - TERMINAL GODMODE DIAGNOSIS READ (Ground: Job 559 showed attach still on cpLauncher and the any number hunt stopping at 8621 candidates with a hand refine prompt, so this job reads the terminal source attach and hunt code and the fresh log tail and prints why attach stayed on the launcher and why the hunt stopped, no patch, no relaunch. Every variable carries the p562 prefix.) ==='
$p562src = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs'
if (Test-Path $p562src) {
  $p562lines = Get-Content $p562src
  Write-Output ('SOURCE LINES ' + $p562lines.Count)
  @(Select-String -Path $p562src -Pattern 'AttachForeground' | Select-Object -First 30) | ForEach-Object { Write-Output ('ATTACH LINE ' + $_.Line.Trim()) }
  @(Select-String -Path $p562src -Pattern 'ValueMark|OneValue' | Select-Object -First 30) | ForEach-Object { Write-Output ('HUNT LINE ' + $_.Line.Trim()) }
  @(Select-String -Path $p562src -Pattern 'GODMODE ALL' | Select-Object -First 30) | ForEach-Object { Write-Output ('GODMODE LINE ' + $_.Line.Trim()) }
} else { Write-Output 'NO TERMINAL SOURCE FOUND' }
$p562log = 'C:\Users\Admin\PhiTerminal\phi_terminal_universal.log'
if (Test-Path $p562log) {
  $p562tail = Get-Content $p562log -Tail 300
  Write-Output ('LOG TAIL LINES ' + $p562tail.Count)
  $p562hits = @($p562tail | Select-String -Pattern 'GODMODE|ATTACH|HUNT|LOCKED' | Select-Object -Last 50)
  foreach ($p562h in $p562hits) { Write-Output ('TERM LINE ' + $p562h.Line.Trim()) }
  $p562procs = Get-Process | Where-Object { $_.ProcessName -like '*Launcher*' }
  foreach ($p562pr in $p562procs) { Write-Output ('PROC LINE ' + $p562pr.ProcessName + ' ' + $p562pr.Id) }
} else { Write-Output 'NO TERMINAL LOG FOUND' }
Write-Output 'PHI P562 VERDICT: TERMINAL GODMODE DIAGNOSIS READ ABOVE'
Write-Output 'JOB 562 DONE'
```
