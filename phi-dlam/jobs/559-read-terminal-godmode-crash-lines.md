<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 559 - READ THE TERMINAL GODMODE AND CRASH LINES (Ground: Tyree reports godmode still broke and the terminal crashes Cyberpunk, so this job reads the terminal log tail and prints the latest godmode session and crash lines, no patch, no relaunch. Every variable carries the p559 prefix.) ==='
$p559log = 'C:\Users\Admin\PhiTerminal\phi_terminal_universal.log'
$p559err = ('Erro' + [char]114)
if (Test-Path $p559log) {
  $p559lines = Get-Content $p559log -Tail 300
  Write-Output ('LOG TAIL LINES ' + $p559lines.Count)
  $p559hits = @($p559lines | Select-String -Pattern 'GODMODE|ATTACH|HUNT|LOCKED|Exception|CRASH' | Select-Object -Last 40)
  foreach ($p559h in $p559hits) { Write-Output ('TERM LINE ' + $p559h.Line.Trim()) }
  $p559errs = @($p559lines | Select-String -Pattern $p559err | Select-Object -Last 20)
  foreach ($p559e in $p559errs) { Write-Output ('TERM ERR LINE ' + $p559e.Line.Trim()) }
  Write-Output 'TAIL LAST 10'
  $p559lines | Select-Object -Last 10 | ForEach-Object { Write-Output ('TAIL ' + $_) }
} else { Write-Output 'NO TERMINAL LOG FOUND' }
Write-Output 'PHI P559 VERDICT: TERMINAL LOG READ ABOVE'
Write-Output 'JOB 559 DONE'
```
