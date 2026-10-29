<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 577 - GODMODE VAULT WIRING READ (Ground: Job 574 staged Godmode Safe and Vault Dress not wired, job 576 wires GameState Fixed, so this job reads where the GODMODE button path lives and where Godmode Safe and Vault Dress live, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the wiring patch lands from a read not a guess. Every variable carries the p577 prefix.) ==='
$p577godh = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_GodmodeSafe.h'
$p577godcpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_GodmodeSafe.cpp'
$p577vaulth = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_WorldDress_Vault.h'
$p577vaultcpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_WorldDress_Vault.cpp'
$p577src = 'D:\VEIL-OMNI\Source\VEIL'
foreach ($p577f in @($p577godh, $p577godcpp, $p577vaulth, $p577vaultcpp)) { if (Test-Path $p577f) { Write-Output ('EXISTS577 ' + $p577f) } else { Write-Output ('MISSING577 ' + $p577f) } }
$p577hits1 = @(Select-String -Path $p577godh, $p577godcpp -Pattern 'SetGodmode' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p577h in $p577hits1) { Write-Output ('GODMODE577 ' + $p577h.Path + ' ' + $p577h.LineNumber + ' ' + $p577h.Line.Trim()) }
$p577hits2 = @(Select-String -Path $p577vaulth, $p577vaultcpp -Pattern 'Vault' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p577h in $p577hits2) { Write-Output ('VAULT577 ' + $p577h.Path + ' ' + $p577h.LineNumber + ' ' + $p577h.Line.Trim()) }
$p577hits3 = @(Get-ChildItem -Path $p577src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'GODMODE' | Select-Object -First 40)
foreach ($p577h in $p577hits3) { Write-Output ('BUTTON577 ' + $p577h.Path + ' ' + $p577h.LineNumber + ' ' + $p577h.Line.Trim()) }
$p577hits4 = @(Get-ChildItem -Path $p577src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'GodmodeSafe' | Select-Object -First 40)
foreach ($p577h in $p577hits4) { Write-Output ('CALLER577 ' + $p577h.Path + ' ' + $p577h.LineNumber + ' ' + $p577h.Line.Trim()) }
Write-Output 'PHI P577 VERDICT: GODMODE VAULT WIRING READ ABOVE'
Write-Output 'JOB 577 DONE'
```
