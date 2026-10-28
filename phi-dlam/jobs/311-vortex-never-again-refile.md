<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX NEVER-AGAIN - REFILE of job 297 (297 died on a ParserError before executing; nothing ran under it. Pure ASCII refile. Tyree 2026-10-27 22:30 MDT: make sure Vortex never does that again - the 48 GB Witcher warehouse happened because Vortex downloads defaulted to C:\Users\Admin\AppData\Roaming\Vortex\downloads. This job: (1) creates D:\Vortex Downloads; (2) reports whether Vortex is running; (3) reports Vortex current C footprint as the guard baseline; (4) scans small files in the Vortex roaming folder for download-path setting candidates and prints them. It does NOT edit Vortex settings store blind and does NOT move any game files (Tyree ask-first clause, 2026-10-27 22:31 MDT) - the repoint happens only if a plainly writable setting is found and printed; otherwise the exact setting terrain is reported for the record.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
New-Item -ItemType Directory -Force -Path 'D:\Vortex Downloads' | Out-Null
"Vortex running: $([bool](Get-Process Vortex -ErrorAction SilentlyContinue))" | Write-Output
"Vortex C footprint now: $(FolderGB('C:\Users\Admin\AppData\Roaming\Vortex')) GB (post-Witcher baseline; guard line: report if it ever passes 3 GB again)" | Write-Output
$hits = Get-ChildItem 'C:\Users\Admin\AppData\Roaming\Vortex' -File -Force -ErrorAction SilentlyContinue | Where-Object { $_.Length -lt 50MB }
foreach ($f in $hits) { $m = Select-String -Path $f.FullName -Pattern 'download' -SimpleMatch -ErrorAction SilentlyContinue | Select-Object -First 3; if ($m) { "SETTING CANDIDATE: $($f.FullName)" | Write-Output; $m | ForEach-Object { $_.Line.Substring(0, [math]::Min(300, $_.Line.Length)) } | Write-Output } }
Write-Output 'VORTEX NEVER-AGAIN READ DONE'
```
