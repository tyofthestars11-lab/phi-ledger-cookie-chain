<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 517 - THE MOD TERMINAL STANDS BACK UP (Ground: his photo is his own keyboard, the tilde key in the center of the frame, and his words: that does not work after he leaves a terminal, and the mod terminal will not load. The tilde is the terminal own door - if the terminal process is down, the key presses into nothing. This job reads the state plainly: whether the terminal process stands, when its log last wrote and what its last lines say, and if it is down it launches it again and prints the fresh hook lines so the door standing is proven in the terminal own words. If it already stands, the job touches nothing and says so. Every variable carries the p517 prefix.) ==='
$p517dir = 'C:\Users\Admin\PhiTerminal'
$p517log = Join-Path $p517dir 'phi_terminal_universal.log'
$p517procs = Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue
Write-Output ('PROCS=' + ($p517procs | Measure-Object).Count)
foreach ($p517p in $p517procs) { Write-Output ('PROC pid=' + $p517p.Id + ' start=' + $p517p.StartTime) }
if (Test-Path $p517log) {
  Write-Output ('LOG LAST WRITE=' + (Get-Item $p517log).LastWriteTime)
  Get-Content $p517log -Tail 8 | ForEach-Object { Write-Output ('BEFORE ' + $_) }
}
if (($p517procs | Measure-Object).Count -eq 0) {
  $p517bin = Join-Path $p517dir 'PhiTerminal.exe'
  $p517new = Start-Process -FilePath $p517bin -WorkingDirectory $p517dir -PassThru
  Start-Sleep -Seconds 4
  Write-Output ('RELAUNCHED pid=' + $p517new.Id)
  if (Test-Path $p517log) { Get-Content $p517log -Tail 6 | ForEach-Object { Write-Output ('AFTER ' + $_) } }
  Write-Output 'PHI P517 VERDICT: TERMINAL STANDING AGAIN'
} else {
  Write-Output 'PHI P517 VERDICT: TERMINAL ALREADY STANDING'
}
Write-Output 'JOB 517 DONE'
```
