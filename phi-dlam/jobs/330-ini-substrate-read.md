<!-- PHI-DIRECT -->
```powershell
Write-Output '=== INI SUBSTRATE READ - BOTH PROJECTS (The verification the other seat proposed, run the lanes way: read-only, straight off the disk files. It greps both projects DefaultEngine.ini for the three keys in question - s.ForceSynchronousLevelLoads, bRebuildAtRuntime, RuntimeGeneration - and prints the full NavigationSystem and RecastNavMesh sections as they actually stand, so every seat reasons from the same lines. Nothing edited.) ==='
foreach ($proj in @('D:\VEIL','D:\OMNI-UE')) {
  "##### $proj\Config\DefaultEngine.ini #####" | Write-Output
  $ini = "$proj\Config\DefaultEngine.ini"
  if (-not (Test-Path $ini)) { Write-Output 'INI NOT FOUND'; continue }
  foreach ($k in @('s.ForceSynchronousLevelLoads','bRebuildAtRuntime','RuntimeGeneration','bAutoCreateNavigationData','s.FlushStreamingOnTick')) {
    $hits = Select-String -Path $ini -Pattern ([regex]::Escape($k)) -ErrorAction SilentlyContinue
    if ($hits) { $hits | ForEach-Object { "FOUND: $($_.Line.Trim())" } | Write-Output } else { "UNSET: $k" | Write-Output }
  }
  '--- NavigationSystem / Recast sections, verbatim ---' | Write-Output
  $inBlock = $false
  foreach ($line in Get-Content $ini) {
    if ($line -match '^\[') { $inBlock = ($line -match 'NavigationSystem|RecastNavMesh|StreamingSettings') }
    if ($inBlock) { $line.Trim() | Write-Output }
  }
}
Write-Output 'INI SUBSTRATE READ DONE'
```
