<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX PER-GAME INVENTORY (Tyree 2026-10-27 22:26 MDT: "What all mod files for vortex what games???" — the census named only witcher3 in the biggest-files list; this read names EVERY game Vortex holds downloads or staged mods for, with sizes. Read-only: nothing deleted, nothing moved. Runs after job 293: if the witcher3 trees are already gone, they report 0/absent and the inventory reflects the post-deletion state.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
$V = 'C:\Users\Admin\AppData\Roaming\Vortex'
"Vortex total: $(FolderGB($V)) GB" | Write-Output
Write-Output '--- downloads, per game ---'
Get-ChildItem "$V\downloads" -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Game = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- staged mods, per game ---'
Get-ChildItem $V -Directory -Force -ErrorAction SilentlyContinue | Where-Object { Test-Path (Join-Path $_.FullName 'mods') } | ForEach-Object { [PSCustomObject]@{ Game = $_.Name; ModsGB = FolderGB((Join-Path $_.FullName 'mods')) } } | Sort-Object ModsGB -Descending | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- Vortex top-level folders ---'
Get-ChildItem $V -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 12 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output 'VORTEX PER-GAME INVENTORY DONE'
```
