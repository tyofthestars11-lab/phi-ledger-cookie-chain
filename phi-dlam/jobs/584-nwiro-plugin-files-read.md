<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 584 - NWIRO PLUGIN FILES READ (Ground: Job 582 confirmed NWIRO AI seated yes at 13 plugins with plugin line 63, Tyree asked is the AI helping, so this job reads the NWIRO plugin files and manifest names on this PC, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so AI help proof lands from a read not a guess. Every variable carries the p584 prefix.) ==='
$p584plugins = 'D:\VEIL-OMNI\Plugins'
if (Test-Path $p584plugins) { Write-Output ('PLUGINS584 EXISTS ' + $p584plugins) } else { Write-Output ('PLUGINS584 MISSING ' + $p584plugins) }
$p584files = @(Get-ChildItem -Path $p584plugins -Recurse -File -ErrorAction SilentlyContinue | Select-Object -First 100)
foreach ($p584f in $p584files) { Write-Output ('FILE584 ' + $p584f.FullName) }
$p584hits = @(Get-ChildItem -Path $p584plugins -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'NWIRO' | Select-Object -First 40)
foreach ($p584h in $p584hits) { Write-Output ('NWIRO584 ' + $p584h.Path + ' ' + $p584h.LineNumber + ' ' + $p584h.Line.Trim()) }
Write-Output 'PHI P584 VERDICT: NWIRO PLUGIN FILES READ ABOVE'
Write-Output 'JOB 584 DONE'
```
