<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 515 - PARTITION AND LIGHT WITNESSES IN THE PLAY LOG (Ground: a compass board from another seat names World Partition streaming and missing lights as the black world fault. His own photo contradicts half of it - a bright sun and a lit sky stand in the frame - and the record seats the district as streaming levels, not a measured partition level. Both claims are checkable in one read of the log the standalone window already wrote: if the level runs under World Partition the log carries its lines, and the lighting actors announce themselves at load. This job greps that log for the partition, light, sky, and fog witnesses and counts them, so the board claims and the record are settled by the instrument instead of by argument. It rides behind the black world read. Every variable carries the p515 prefix.) ==='
$p515logs = 'D:\VEIL-OMNI\Saved\Logs'
$p515new = Get-ChildItem $p515logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if (-not $p515new) {
  Write-Output 'NO LOG FOUND'
  Write-Output 'PHI P515 VERDICT: HELD - NO LOG'
  Write-Output 'JOB 515 DONE'
  return
}
Write-Output ('LOG ' + $p515new.Name + ' at ' + $p515new.LastWriteTime)
$p515pats = @('WorldPartition', 'DirectionalLight', 'SkyLight', 'SkyAtmosphere', 'HeightFog', 'PostProcess', 'LogMaterial')
foreach ($p515pat in $p515pats) {
  $p515hits = Select-String -Path $p515new.FullName -Pattern $p515pat -ErrorAction SilentlyContinue
  Write-Output ('COUNT ' + $p515pat + '=' + ($p515hits | Measure-Object).Count)
  foreach ($p515h in ($p515hits | Select-Object -First 3)) { Write-Output ('WIT ' + $p515pat + ' ' + $p515h.Line) }
}
Write-Output 'PHI P515 VERDICT: WITNESSES PRINTED ABOVE'
Write-Output 'JOB 515 DONE'
```
