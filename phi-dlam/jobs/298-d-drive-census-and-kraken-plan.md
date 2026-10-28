<!-- PHI-DIRECT -->
```powershell
Write-Output '=== D DRIVE CENSUS + KRAKEN PLAN (Tyree 2026-10-27 22:31 MDT: "Give my hard drives ton 618 kraken" — KRAKEN-TON618 treatment for his PC drives starts with the measured census: D total/free, D top-level folders by size, and the cold-data candidates named for packing. Read-only: nothing packed, moved, or deleted by this job. Also verifies the Cyberpunk landing zone: ~100 GB estimated for base + Phantom Liberty + mods on D per the all-games-on-D law.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
$d = Get-PSDrive D; "D: total $([math]::Round(($d.Used+$d.Free)/1GB,2)) GB — used $([math]::Round($d.Used/1GB,2)) — FREE $([math]::Round($d.Free/1GB,2)) GB" | Write-Output
$c = Get-PSDrive C; "C: FREE $([math]::Round($c.Free/1GB,2)) GB" | Write-Output
Write-Output '--- D top-level folders by size ---'
Get-ChildItem 'D:\' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ GB = FolderGB($_.FullName); Folder = $_.FullName } } | Sort-Object GB -Descending | Select-Object -First 15 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- cold-data pack candidates (backups + archives over 1 GB on D) ---'
"phi-vault-backups on D: $(FolderGB('D:\phi-vault-backups')) GB" | Write-Output
Get-ChildItem 'D:\' -Recurse -File -Force -ErrorAction SilentlyContinue | Where-Object { $_.Length -gt 1GB -and $_.Extension -in '.7z','.zip','.tar','.gz','.bak' } | Sort-Object Length -Descending | Select-Object -First 10 | ForEach-Object { "$([math]::Round($_.Length/1GB,2)) GB — $($_.FullName)" } | Write-Output
Write-Output 'D CENSUS + KRAKEN PLAN DONE'
```
