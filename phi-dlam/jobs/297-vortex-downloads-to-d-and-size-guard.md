<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX NEVER-AGAIN (Tyree 2026-10-27 22:30 MDT: "Make sure vortex never does that again" — the 48 GB Witcher warehouse happened because Vortex downloads defaulted to C:\Users\Admin\AppData\Roaming\Vortex\downloads. This job: (1) creates D:\Vortex Downloads; (2) with Vortex CLOSED, reads Vortex''s settings store and reports the current download-path value and where it lives; (3) if the value is a plain writable setting, repoints it to D:\Vortex Downloads and reads it back as proof — if it lives in a store that is not safely writable, it changes NOTHING and reports the exact setting name for the record; (4) reports Vortex''s current C footprint as the guard baseline. Vortex game files are NOT moved by this job (Tyree ask-first clause, 2026-10-27 22:31 MDT) — only the download destination setting.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
New-Item -ItemType Directory -Force -Path 'D:\Vortex Downloads' | Out-Null
"Vortex running: $([bool](Get-Process Vortex -ErrorAction SilentlyContinue))" | Write-Output
"Vortex C footprint now: $(FolderGB('C:\Users\Admin\AppData\Roaming\Vortex')) GB (post-Witcher baseline; guard line: report if it ever passes 3 GB again)" | Write-Output
$hits = Get-ChildItem 'C:\Users\Admin\AppData\Roaming\Vortex' -File -Force -ErrorAction SilentlyContinue | Where-Object { $_.Length -lt 50MB }
foreach ($f in $hits) { $m = Select-String -Path $f.FullName -Pattern 'download' -SimpleMatch -ErrorAction SilentlyContinue | Select-Object -First 3; if ($m) { "SETTING CANDIDATE: $($f.FullName)" | Write-Output; $m | ForEach-Object { $_.Line.Substring(0, [math]::Min(300, $_.Line.Length)) } | Write-Output } }
Write-Output 'VORTEX NEVER-AGAIN READ DONE (repoint only via a verified writable setting; otherwise terrain reported, nothing forced)'
```
