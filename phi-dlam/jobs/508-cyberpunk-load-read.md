<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 508 - CYBERPUNK LOAD READ (Ground: his photo shows the game on its loading screen behind the terminal, the loading tip up, the world not reached, and his word that it is not loading. This job reads the game side of the machine only: every process in the cyberpunk, gaming services, and xbox family with its responding state, processor seconds, memory, and start time, so a hung load and a slow load read differently at a glance, plus the newest write inside the save containers, which tells whether the game has touched its saves at all in this launch. Nothing is closed, moved, or touched. Every variable carries the p508 prefix.) ==='
$p508procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'cyber|gaming|xbox|game' }
foreach ($p508p in $p508procs) {
  $p508ws = [math]::Round($p508p.WorkingSet64 / 1MB, 1)
  $p508cpu = 0
  try { $p508cpu = [math]::Round($p508p.CPU, 1) } catch {}
  $p508start = 'na'
  try { $p508start = $p508p.StartTime } catch {}
  Write-Output ('PROC ' + $p508p.ProcessName + ' pid=' + $p508p.Id + ' responding=' + $p508p.Responding + ' cpuSec=' + $p508cpu + ' wsMB=' + $p508ws + ' start=' + $p508start)
}
Write-Output ('PROC COUNT=' + ($p508procs | Measure-Object).Count)
$p508pkgs = Get-ChildItem 'C:\Users\Admin\AppData\Local\Packages' -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'CDProjekt|Cyberpunk' }
foreach ($p508pkg in $p508pkgs) {
  $p508wgs = Join-Path $p508pkg.FullName 'SystemAppData\wgs'
  if (Test-Path $p508wgs) {
    $p508new = Get-ChildItem $p508wgs -File -Recurse -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($p508new) { Write-Output ('WGS newest=' + $p508new.LastWriteTime + ' name=' + $p508new.Name) }
  }
  Write-Output ('PKG ' + $p508pkg.Name)
}
Write-Output 'PHI P508 VERDICT: LOAD STATE READ ABOVE'
Write-Output 'JOB 508 DONE'
```
