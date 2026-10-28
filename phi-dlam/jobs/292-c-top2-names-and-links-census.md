<!-- PHI-DIRECT -->
```powershell
Write-Output '=== C TOP-2 NAMES + LINKS census (Tyree 2026-10-27 22:15 MDT: "I need names" — drill into C:\Users 173.39 GB and C:\Program Files 52.98 GB, and list every junction/symlink in the Xbox and Unreal trees — "Are they linked? Unlink if so" is answered from this read first. Windows + ProgramData + x86 stack is hands-off by his word. Read-only: nothing moved, nothing unlinked, nothing removed.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
Write-Output '--- C:\Users\Admin subfolders by size (top 15) ---'
Get-ChildItem 'C:\Users\Admin' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 15 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- AppData split: Local / Roaming / LocalLow totals ---'
foreach ($p in @('C:\Users\Admin\AppData\Local','C:\Users\Admin\AppData\Roaming','C:\Users\Admin\AppData\LocalLow')) { "$p = $(FolderGB($p)) GB" | Write-Output }
Write-Output '--- AppData Roaming top residents ---'
Get-ChildItem 'C:\Users\Admin\AppData\Roaming' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 8 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- C:\Program Files subfolders by size (top 15) ---'
Get-ChildItem 'C:\Program Files' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 15 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- largest single files inside C:\Users over 2 GB (top 15) ---'
Get-ChildItem 'C:\Users' -Recurse -File -Force -ErrorAction SilentlyContinue | Where-Object { $_.Length -gt 2GB } | Sort-Object Length -Descending | Select-Object -First 15 | ForEach-Object { "$([math]::Round($_.Length/1GB,2)) GB  $($_.FullName)" } | Write-Output
Write-Output '--- reparse points (junctions/symlinks): C root, profile, AppData Local, XboxGames C and D ---'
foreach ($root in @('C:\','C:\Users\Admin','C:\Users\Admin\AppData\Local','C:\XboxGames','D:\XboxGames')) { if (Test-Path $root) { Get-ChildItem $root -Directory -Force -ErrorAction SilentlyContinue | Where-Object { $_.Attributes -match 'ReparsePoint' } | ForEach-Object { "LINK: $($_.FullName) -> $($_.Target)" } | Write-Output } }
Write-Output '--- UnrealEngine local tree: subfolders + any reparse points inside ---'
Get-ChildItem 'C:\Users\Admin\AppData\Local\UnrealEngine' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName); Link = ($_.Attributes -match 'ReparsePoint') } } | Sort-Object GB -Descending | Format-Table -AutoSize | Out-String | Write-Output
Write-Output 'TOP2 NAMES AND LINKS CENSUS DONE'
```
