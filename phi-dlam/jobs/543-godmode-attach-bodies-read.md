<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 543 - READ THE LIVE GODMODE AND ATTACH BODIES BEFORE THE ALL ON PATCH (Ground: Tyree pressed GODMODE ALL and the terminal printed 1 powers hold at once while health and ammo stayed off, then the game crashed after the terminal attached to the launcher. The all on patch must be written against the live source, not a remembered body, and the real game process name must be read from the live census, so this job reads only: it prints the live MasterToggle and AttachSelected regions from the terminal source, the terminal log tail from his session, and the live process census naming the launcher and any real game process. No source is changed, no build runs, no relaunch rides this job. Every variable carries the p543 prefix.) ==='
$p543src = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs'
if (Test-Path $p543src) {
  $p543lines = @(Get-Content $p543src)
  Write-Output ('SOURCE LINES=' + $p543lines.Count)
  $p543hits = @(Select-String -Path $p543src -Pattern 'MasterToggle|GODMODE ALL|find a number|AttachSelected|Attached to')
  foreach ($p543m in $p543hits) { Write-Output ('SRC ' + $p543m.LineNumber + ' ' + $p543m.Line) }
  if ($p543hits.Count -eq 0) { Write-Output 'SRC NONE FOUND' }
} else { Write-Output 'SOURCE MISSING' }
$p543log = 'C:\Users\Admin\PhiTerminal\phi_terminal_universal.log'
if (Test-Path $p543log) {
  $p543tail = @(Get-Content $p543log -Tail 200 | Select-String -Pattern 'GODMODE|FLY|Type your number|Attached to' | Select-Object -Last 30)
  foreach ($p543m in $p543tail) { Write-Output ('LOG ' + $p543m.Line) }
  if ($p543tail.Count -eq 0) { Write-Output 'LOG NONE FOUND' }
} else { Write-Output 'LOG MISSING' }
$p543procs = @(Get-Process | Where-Object { $_.ProcessName -match 'PhiTerminal|cpLauncher|Cyberpunk|gamingservices' })
foreach ($p543p in $p543procs) {
  $p543path = ''
  try { $p543path = $p543p.MainModule.FileName } catch { $p543path = 'PATH DENIED' }
  Write-Output ('PROC ' + $p543p.ProcessName + ' pid=' + $p543p.Id + ' path=' + $p543path)
}
if ($p543procs.Count -eq 0) { Write-Output 'PROC NONE FOUND' }
Write-Output 'PHI P543 VERDICT: SOURCE LOG AND PROCESS LINES ABOVE - THE ALL ON PATCH READS THEM'
Write-Output 'JOB 543 DONE'
```
