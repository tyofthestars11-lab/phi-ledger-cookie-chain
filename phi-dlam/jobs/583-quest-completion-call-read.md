<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 583 - QUEST COMPLETION CALL READ (Ground: Job 581 read AdvanceProgression at GameState Fixed line 4 via GuardedAdvanceProgression at CrashFix line 45 with on screen percent text, job 582 confirmed NWIRO AI seated yes at 13 plugins, so this job reads where quest completion, fragment gather, Warden defeat, and cache reach call progression, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so progression patch lands from a read not a guess. Every variable carries the p583 prefix.) ==='
$p583src = 'D:\VEIL-OMNI\Source\VEIL'
$p583hits1 = @(Get-ChildItem -Path $p583src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'GatherFragments' | Select-Object -First 40)
foreach ($p583h in $p583hits1) { Write-Output ('FRAG583 ' + $p583h.Path + ' ' + $p583h.LineNumber + ' ' + $p583h.Line.Trim()) }
$p583hits2 = @(Get-ChildItem -Path $p583src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'WardenAwake' | Select-Object -First 40)
foreach ($p583h in $p583hits2) { Write-Output ('WARDEN583 ' + $p583h.Path + ' ' + $p583h.LineNumber + ' ' + $p583h.Line.Trim()) }
$p583hits3 = @(Get-ChildItem -Path $p583src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'GuardedAdvanceProgression' | Select-Object -First 40)
foreach ($p583h in $p583hits3) { Write-Output ('GUARD583 ' + $p583h.Path + ' ' + $p583h.LineNumber + ' ' + $p583h.Line.Trim()) }
Write-Output 'PHI P583 VERDICT: QUEST COMPLETION CALL READ ABOVE'
Write-Output 'JOB 583 DONE'
```
