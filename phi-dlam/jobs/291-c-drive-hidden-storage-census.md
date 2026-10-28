<!-- PHI-DIRECT -->
```powershell
Write-Output '=== C DRIVE HIDDEN STORAGE census (Tyree 2026-10-27 22:07 MDT: Settings shows 354 GB used on C but Installed apps tops out at 3.09 GB - "Microsoft hides it." Read-only: measure the system-level residents Settings does not itemize. Nothing moved, nothing removed, nothing uninstalled.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
Get-PSDrive -PSProvider FileSystem | Where-Object { $_.Name -in @('C','D') } | ForEach-Object { "$($_.Name): free $([math]::Round($_.Free/1GB,2)) GB of $([math]::Round(($_.Used+$_.Free)/1GB,2)) GB" } | Write-Output
Write-Output '--- root system files (pagefile / hiberfil / swapfile) ---'
foreach ($f in @('C:\pagefile.sys','C:\hiberfil.sys','C:\swapfile.sys')) { $i = Get-Item $f -Force -ErrorAction SilentlyContinue; if ($i) { "$f = $([math]::Round($i.Length/1GB,2)) GB" } else { "$f = not readable/absent" } | Write-Output }
Write-Output '--- top-level C folders by size ---'
Get-ChildItem 'C:\' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.FullName; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 10 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- WindowsApps packages on C (Xbox/Store game data hides here) ---'
Get-ChildItem 'C:\Program Files\WindowsApps' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Package = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 10 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- ProgramData top residents ---'
Get-ChildItem 'C:\ProgramData' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 8 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- user profile top residents (Admin) ---'
Get-ChildItem 'C:\Users\Admin' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 10 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- AppData Local top residents (caches, models, app data) ---'
Get-ChildItem 'C:\Users\Admin\AppData\Local' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { [PSCustomObject]@{ Folder = $_.Name; GB = FolderGB($_.FullName) } } | Sort-Object GB -Descending | Select-Object -First 10 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output '--- known model stores ---'
foreach ($p in @('C:\Users\Admin\.ollama','C:\Users\Admin\.lmstudio','C:\Users\Admin\.cache')) { "$p = $(FolderGB($p)) GB" | Write-Output }
Write-Output '--- Windows subtree top residents ---'
foreach ($p in @('C:\Windows\WinSxS','C:\Windows\SoftwareDistribution','C:\Windows\Installer','C:\Windows\Temp','C:\Windows\System32','C:\$Recycle.Bin')) { "$p = $(FolderGB($p)) GB" | Write-Output }
Write-Output '--- shadow copy / restore point storage (vssadmin; may need elevation) ---'
(vssadmin list shadowstorage 2>&1 | Out-String) | Write-Output
Write-Output '--- largest single files on C over 3 GB (top 15) ---'
Get-ChildItem 'C:\' -Recurse -File -Force -ErrorAction SilentlyContinue | Where-Object { $_.Length -gt 3GB } | Sort-Object Length -Descending | Select-Object -First 15 | ForEach-Object { "$([math]::Round($_.Length/1GB,2)) GB  $($_.FullName)" } | Write-Output
Write-Output 'C HIDDEN STORAGE CENSUS DONE'
```
