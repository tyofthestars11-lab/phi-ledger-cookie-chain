<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WITCHER 3 PAYLOAD DELETION + BACKUPS INVENTORY (Tyree 2026-10-27 22:21 MDT, his explicit word: "Delete witcher 3 related stuff." Census ground: Vortex Roaming holds the Witcher 3 mod payload — HD Reworked Project .7z 11.75 GB, HD Monsters .7z 4.17 GB, staged texture.cache 4.19 + 3.53 GB — and phi-vault-backups\vortex-state-2026-10-27-pre-path-fix holds a second copy of the same witcher3 trees. This job deletes ONLY the four witcher3 trees named below, verifies each is gone, and inventories what remains inside phi-vault-backups by snapshot name and size for his D-move decision. Idempotent: if his paste already removed a tree, the job reports it already gone. Nothing else is touched.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
if (Get-Process Vortex -ErrorAction SilentlyContinue) { Write-Output 'VORTEX RUNNING - deletion deferred this run; close Vortex and the next drain retries.' } else {
  $free0 = (Get-PSDrive C).Free
  $targets = @('C:\Users\Admin\AppData\Roaming\Vortex\downloads\witcher3','C:\Users\Admin\AppData\Roaming\Vortex\witcher3','C:\Users\Admin\phi-vault-backups\vortex-state-2026-10-27-pre-path-fix\downloads\witcher3','C:\Users\Admin\phi-vault-backups\vortex-state-2026-10-27-pre-path-fix\witcher3')
  foreach ($t in $targets) { if (Test-Path $t) { $gb = FolderGB($t); Remove-Item $t -Recurse -Force -ErrorAction SilentlyContinue; if (Test-Path $t) { "STILL THERE: $t (was $gb GB)" | Write-Output } else { "DELETED: $t ($gb GB)" | Write-Output } } else { "ALREADY GONE: $t" | Write-Output } }
  $free1 = (Get-PSDrive C).Free
  "RECLAIMED: $([math]::Round(($free1-$free0)/1GB,2)) GB — C free now $([math]::Round($free1/1GB,2)) GB" | Write-Output
}
Write-Output '--- phi-vault-backups inventory (snapshot name + size) ---'
Get-ChildItem 'C:\Users\Admin\phi-vault-backups' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Snapshot = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Format-Table -AutoSize | Out-String | Write-Output
"phi-vault-backups total: $(FolderGB('C:\Users\Admin\phi-vault-backups')) GB" | Write-Output
Write-Output 'WITCHER DELETION + BACKUPS INVENTORY DONE'
```
