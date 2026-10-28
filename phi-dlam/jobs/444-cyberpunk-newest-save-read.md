<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CYBERPUNK NEWEST SAVE READ 444 - THE NEWEST WRITES AT THE PACKAGE ADDRESS, NAMED WITH THEIR TIMES (Ground read whole from job 441: his Cyberpunk saves stand at the Xbox package address, LocalAppData Packages CDPROJEKTSA SystemAppData wgs containers, 128 files and 320518567 bytes in all, and the newest write in that census stood at 06:23:41 on 2026-10-28. Tyree word now: I do not see a save file, just my old ones. So this job reads the same ground by time, newest first, so the record names whether any save has written since that census and exactly when. One, it walks both CDPROJEKTSA package folders, SystemAppData, LocalState, and LocalCache, collecting every file with its write time. Two, it prints the 15 newest files whole: tree, name, bytes, and the write time to the second. Three, it prints the containers index head lines if the index stands, capped at 12, because the index names the containers in the package own bookkeeping. Four, the verdict in one line: NEWEST SAVE READ with the single newest write time and its file name. This job is read only, nothing is written or moved, and every variable carries the ns444 prefix.) ==='
$ns444pkgs = Join-Path $env:LOCALAPPDATA 'Packages'
$ns444dirs = @(Get-ChildItem $ns444pkgs -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*CDPROJEKTSA*' })
$ns444all = @()
foreach ($ns444d in $ns444dirs) {
  foreach ($ns444sub in @('SystemAppData', 'LocalState', 'LocalCache')) {
    $ns444path = Join-Path $ns444d.FullName $ns444sub
    if (Test-Path $ns444path) {
      foreach ($ns444f in @(Get-ChildItem $ns444path -Recurse -File -ErrorAction SilentlyContinue)) {
        $ns444all += [PSCustomObject]@{ Tree = $ns444sub; Name = $ns444f.Name; Bytes = $ns444f.Length; When = $ns444f.LastWriteTime; Full = $ns444f.FullName }
      }
    }
  }
}
Write-Output ('TOTAL FILES=' + $ns444all.Count)
$ns444sorted = @($ns444all | Sort-Object When -Descending)
$ns444sorted | Select-Object -First 15 | ForEach-Object { Write-Output ('NEW ' + $_.Tree + ' ' + $_.Name + ' bytes=' + $_.Bytes + ' at=' + $_.When.ToString('yyyy-MM-dd HH:mm:ss')) }
$ns444idx = $ns444all | Where-Object { $_.Name -eq 'containers.index' } | Select-Object -First 1
if ($ns444idx) { Write-Output '--- CONTAINERS INDEX HEAD ---'; Get-Content $ns444idx.Full -TotalCount 12 -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('IDX ' + $_) } }
$ns444top = $ns444sorted | Select-Object -First 1
if ($ns444top) { Write-Output ('PHI NS444 VERDICT: NEWEST SAVE READ newest=' + $ns444top.When.ToString('yyyy-MM-dd HH:mm:ss') + ' file=' + $ns444top.Name) } else { Write-Output 'PHI NS444 VERDICT: NEWEST SAVE READ newest=NONE' }
Write-Output 'JOB 444 DONE'
```
