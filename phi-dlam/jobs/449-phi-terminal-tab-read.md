<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI TERMINAL TAB READ 449 - WHY THE TAB TOGGLE DID NOT ANSWER IN HIS NEW GAME (Ground: job 437 placed the Phi Terminal at C Users Admin PhiTerminal2077, an 8192 byte exe with a low level keyboard hook, Tab toggles its window, and every event logs to phi_terminal log in its folder. Tyree word now: he started a new Cyberpunk game and Tab does not work. The terminal only lives while its exe runs, and its log is the discriminating record: if the log shows the hook seated and Tab presses arriving, the fault is in the toggle; if the log is absent or stale, the exe never ran beside this session; if the process stands absent entirely, the hook was never seated. One, the job lists the live processes matching the terminal and the game, with pids. Two, it lists the terminal folder whole with sizes and times. Three, it prints the phi terminal log whole, capped at 60 lines. Four, the verdict in one line: TAB READ with whether the terminal process stands, whether the game process stands, and the log line count. This job is read only and every variable carries the pt449 prefix.) ==='
$pt449folder = 'C:\Users\Admin\PhiTerminal2077'
$pt449procs = @(Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'PhiTerminal|Cyberpunk' })
$pt449term = 0; $pt449game = 0
foreach ($pt449p in $pt449procs) { Write-Output ('PROC ' + $pt449p.ProcessName + ' pid=' + $pt449p.Id); if ($pt449p.ProcessName -match 'PhiTerminal') { $pt449term = 1 }; if ($pt449p.ProcessName -match 'Cyberpunk') { $pt449game = 1 } }
if (Test-Path $pt449folder) { Get-ChildItem $pt449folder -File | ForEach-Object { Write-Output ('TFILE ' + $_.Name + ' bytes=' + $_.Length + ' at=' + $_.LastWriteTime) } }
$pt449log = Join-Path $pt449folder 'phi_terminal.log'
$pt449lines = 0
if (Test-Path $pt449log) { $pt449all = @(Get-Content $pt449log); $pt449lines = $pt449all.Count; $pt449all | Select-Object -Last 60 | ForEach-Object { Write-Output ('TLOG ' + $_) } } else { Write-Output 'TLOG: log absent' }
Write-Output ('PHI PT449 VERDICT: TAB READ terminal_proc=' + $pt449term + ' game_proc=' + $pt449game + ' log_lines=' + $pt449lines)
Write-Output 'JOB 449 DONE'
```
