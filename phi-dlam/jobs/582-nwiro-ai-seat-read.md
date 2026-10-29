<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 582 - NWIRO AI SEAT READ (Ground: Tyree confirmed have Unreal AI help make the game, NWIRO AI Pro 1.1.7 is seated in VEIL OMNI at 13 plugins, so this job reads the seated AI plugin state and its enabled list, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so AI help lands from a read not a guess. Every variable carries the p582 prefix.) ==='
$p582proj = 'D:\VEIL-OMNI\VEIL.uproject'
if (Test-Path $p582proj) { Write-Output ('PROJ582 EXISTS ' + $p582proj) } else { Write-Output ('PROJ582 MISSING ' + $p582proj) }
$p582hits = @(Select-String -Path $p582proj -Pattern 'NWIRO' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p582h in $p582hits) { Write-Output ('NWIRO582 ' + $p582h.LineNumber + ' ' + $p582h.Line.Trim()) }
$p582hits2 = @(Select-String -Path $p582proj -Pattern 'Plugins' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p582h in $p582hits2) { Write-Output ('PLUGIN582 ' + $p582h.LineNumber + ' ' + $p582h.Line.Trim()) }
$p582text = Get-Content $p582proj -Raw -ErrorAction SilentlyContinue
if ($p582text -match 'Nwiro') { Write-Output 'NWIRO582 SEATED YES' } else { Write-Output 'NWIRO582 SEATED NO' }
Write-Output 'PHI P582 VERDICT: NWIRO AI SEAT READ ABOVE'
Write-Output 'JOB 582 DONE'
```
