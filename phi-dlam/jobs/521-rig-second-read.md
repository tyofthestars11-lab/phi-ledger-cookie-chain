<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 521 - THE RIG SECOND READ (Ground: job 519 launched the light rig detached and job 520 read too early or after a silent end: the rig page was not present and the district save time had not moved. Two states are possible and they read differently: the editor command process still runs and simply had not reached the script, or it ended and the project log carries the reason. This job reads both witnesses in one pass: the command process count, the rig page if it stands now, the district save time, and the newest project log lines that name the script, the Python hand, or an error. Every variable carries the p521 prefix.) ==='
$p521cmd = Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue
Write-Output ('CMD PROCS=' + ($p521cmd | Measure-Object).Count)
foreach ($p521p in $p521cmd) { Write-Output ('CMD pid=' + $p521p.Id + ' start=' + $p521p.StartTime) }
$p521page = 'D:\VEIL-OMNI\worldfix519.txt'
if (Test-Path $p521page) {
  Write-Output ('RIG PAGE at ' + (Get-Item $p521page).LastWriteTime)
  Get-Content $p521page | ForEach-Object { Write-Output ('RIG ' + $_) }
} else {
  Write-Output 'RIG PAGE NOT PRESENT'
}
$p521map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p521map) { Write-Output ('DISTRICT SAVED AT ' + (Get-Item $p521map).LastWriteTime + ' bytes=' + (Get-Item $p521map).Length) }
$p521logs = 'D:\VEIL-OMNI\Saved\Logs'
$p521new = Get-ChildItem $p521logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($p521new) {
  Write-Output ('LOG ' + $p521new.Name + ' at ' + $p521new.LastWriteTime)
  $p521hits = Select-String -Path $p521new.FullName -Pattern 'worldfix|pythonscript|Python|LogPython' -ErrorAction SilentlyContinue | Select-Object -Last 15
  foreach ($p521h in $p521hits) { Write-Output ('PYLOG ' + $p521h.Line) }
}
Write-Output 'PHI P521 VERDICT: RIG STATE READ FROM BOTH WITNESSES'
Write-Output 'JOB 521 DONE'
```
