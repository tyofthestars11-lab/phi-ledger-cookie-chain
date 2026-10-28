<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 528 - WHERE THE FIRST DRESSING WENT QUIET, AND HER ANIMATION SEAT (Ground: the first dressing launch exited its editor session without ever writing its page - the script went quiet somewhere inside itself and its prints ride the session logs. The glide question also still stands open: the animation class driving her in the standalone window has not printed yet. This job greps the project logs for the dressing tracebacks and dress lines, and for the body and animation lines that name her mesh and her animation seat. Both answers ride the same read. Every variable carries the p528 prefix.) ==='
$p528logs = Get-ChildItem 'D:\VEIL-OMNI\Saved\Logs' -Filter '*.log' | Sort-Object LastWriteTime -Descending | Select-Object -First 3
foreach ($p528l in $p528logs) {
  Write-Output ('LOG ' + $p528l.Name + ' at ' + $p528l.LastWriteTime)
  $p528d = Select-String -Path $p528l.FullName -Pattern 'Traceback|DRESS|LogPython' -ErrorAction SilentlyContinue | Select-Object -Last 12
  foreach ($p528x in $p528d) { Write-Output ('D528 ' + $p528x.Line) }
  $p528a = Select-String -Path $p528l.FullName -Pattern 'BODY CHECK|AnimInstance|AnimBlueprint|AnimationSingleNode|SetAnim' -ErrorAction SilentlyContinue | Select-Object -Last 8
  foreach ($p528y in $p528a) { Write-Output ('A528 ' + $p528y.Line) }
}
Write-Output 'PHI P528 VERDICT: PRINTED ABOVE'
Write-Output 'JOB 528 DONE'
```
