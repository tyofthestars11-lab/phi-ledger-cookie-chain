<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 581 - PROGRESSION CALL READ (Ground: Job 578 wired GameState Fixed and build succeeded, job 579 wired Godmode Safe and build succeeded, job 580 read Vault Dress class exists with VEILDistrict map size unchanged, so this job reads where AdvanceProgression is called and where quest rewards and on screen text live, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so progression visibility lands from a read not a guess. Every variable carries the p581 prefix.) ==='
$p581src = 'D:\VEIL-OMNI\Source\VEIL'
$p581hits1 = @(Get-ChildItem -Path $p581src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'AdvanceProgression' | Select-Object -First 40)
foreach ($p581h in $p581hits1) { Write-Output ('PROG581 ' + $p581h.Path + ' ' + $p581h.LineNumber + ' ' + $p581h.Line.Trim()) }
$p581hits2 = @(Get-ChildItem -Path $p581src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'AddOnScreenDebugMessage' | Select-Object -First 40)
foreach ($p581h in $p581hits2) { Write-Output ('SCREEN581 ' + $p581h.Path + ' ' + $p581h.LineNumber + ' ' + $p581h.Line.Trim()) }
$p581hits3 = @(Get-ChildItem -Path $p581src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'ProgressionPercent' | Select-Object -First 40)
foreach ($p581h in $p581hits3) { Write-Output ('PERCENT581 ' + $p581h.Path + ' ' + $p581h.LineNumber + ' ' + $p581h.Line.Trim()) }
Write-Output 'PHI P581 VERDICT: PROGRESSION CALL READ ABOVE'
Write-Output 'JOB 581 DONE'
```
