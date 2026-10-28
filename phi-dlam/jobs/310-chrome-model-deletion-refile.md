<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CHROME ON-DEVICE MODEL DELETION - REFILE of job 295 (295 died on a ParserError before executing; nothing was deleted by it. Pure ASCII refile. Tyree 2026-10-27 22:24 MDT, his word: delete the roughly 4 GB item - the 3.98 GB weights.bin inside Chrome OptGuideOnDeviceModel folder, the on-device AI model cache. Scope is ONLY that model folder: C:\Users\Admin\AppData\Local\Google\Chrome\User Data\OptGuideOnDeviceModel. His Chrome profile - history, cookies, logins - is NOT touched. Idempotent. Chrome may re-download the model later while its built-in AI features stay enabled; that is Chrome behavior, noted for the record.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
$t = 'C:\Users\Admin\AppData\Local\Google\Chrome\User Data\OptGuideOnDeviceModel'
if (Get-Process chrome -ErrorAction SilentlyContinue) { Write-Output 'CHROME RUNNING - deletion deferred this run.' } elseif (Test-Path $t) { $gb = FolderGB($t); $free0 = (Get-PSDrive C).Free; Remove-Item $t -Recurse -Force -ErrorAction SilentlyContinue; if (Test-Path $t) { "STILL THERE: $t (was $gb GB)" | Write-Output } else { "DELETED: $t ($gb GB) - C free now $([math]::Round((Get-PSDrive C).Free/1GB,2)) GB (freed $([math]::Round(((Get-PSDrive C).Free-$free0)/1GB,2)) GB)" | Write-Output } } else { Write-Output "ALREADY GONE: $t" }
Write-Output 'CHROME MODEL DELETION DONE'
```
