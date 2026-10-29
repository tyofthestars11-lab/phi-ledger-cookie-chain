<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 580 - VAULT DRESS PLACEMENT READ (Ground: Job 579 wired ToggleGodMode to Godmode Safe and build succeeded, job 574 staged Vault Dress not placed, so this job reads whether the Vault Dress actor is placed in VEILDistrict and where its class path lives, no patch, no build, no package, no map placement yet, no terminal work, Cyberpunk parked, so placement lands from a read not a guess. Every variable carries the p580 prefix.) ==='
$p580map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p580vaulth = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_WorldDress_Vault.h'
if (Test-Path $p580map) { Write-Output ('MAP580 EXISTS ' + $p580map) } else { Write-Output ('MAP580 MISSING ' + $p580map) }
if (Test-Path $p580vaulth) { Write-Output ('VAULT580 EXISTS ' + $p580vaulth) } else { Write-Output ('VAULT580 MISSING ' + $p580vaulth) }
$p580hits = @(Select-String -Path $p580vaulth -Pattern 'WorldDress' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p580h in $p580hits) { Write-Output ('VAULT580 ' + $p580h.LineNumber + ' ' + $p580h.Line.Trim()) }
$p580size = 0
if (Test-Path $p580map) { $p580size = (Get-Item $p580map).Length; Write-Output ('MAP580 SIZE ' + $p580size) }
Write-Output 'PHI P580 VERDICT: VAULT DRESS PLACEMENT READ ABOVE'
Write-Output 'JOB 580 DONE'
```
