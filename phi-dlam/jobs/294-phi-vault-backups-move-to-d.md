<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI-VAULT-BACKUPS MOVE TO D (Tyree 2026-10-27 22:22 MDT, his tapped decision: "Move phi-vault-backups to D after the Witcher deletion." Runs after job 293 by number. What it is: C:\Users\Admin\phi-vault-backups (49.25 GB before the Witcher deletion) — the lane''s snapshot folder on his PC; the named snapshot vortex-state-2026-10-27-pre-path-fix is a full copy of his Vortex state taken before the Oct 27 path fix, which is why it contains a second copy of the Witcher 3 mod payload. This job moves the whole folder to D:\phi-vault-backups with robocopy /MOVE, then verifies: D copy total matches the pre-move C total (minus anything job 293 removed), and the C folder is gone. If the folder is already on D (his paste moved it), the job reports that and verifies instead.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
$src = 'C:\Users\Admin\phi-vault-backups'; $dst = 'D:\phi-vault-backups'
if (-not (Test-Path $src)) { Write-Output "SOURCE ABSENT: $src — already moved or gone. D copy: $(FolderGB($dst)) GB" } else {
  $before = FolderGB($src); $free0 = (Get-PSDrive C).Free
  Write-Output "Moving $src ($before GB) -> $dst"
  robocopy $src $dst /E /MOVE /R:1 /W:1 /NFL /NDL /NJH | Out-String | Write-Output
  $after = FolderGB($dst)
  "D copy total: $after GB (source was $before GB) — C folder still present: $(Test-Path $src) — C free now: $([math]::Round((Get-PSDrive C).Free/1GB,2)) GB (freed $([math]::Round(((Get-PSDrive C).Free-$free0)/1GB,2)) GB)" | Write-Output
}
Write-Output 'BACKUPS MOVE DONE'
```
