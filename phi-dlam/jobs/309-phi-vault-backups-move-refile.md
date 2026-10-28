<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI-VAULT-BACKUPS MOVE TO D - REFILE of job 294 (294 died on a ParserError before executing; nothing was moved by it. This refile is pure ASCII. Tyree 2026-10-27 22:22 MDT, his tapped decision: move phi-vault-backups to D after the Witcher deletion. What it is: C:\Users\Admin\phi-vault-backups - the lane snapshot folder; the Witcher payload inside it was already deleted by job 293. This job moves the folder to D:\phi-vault-backups with robocopy /MOVE, then verifies with ONE size scan of the D copy and confirms the C folder is gone. If the source is already absent, it reports that and verifies the D copy instead.) ==='
function FolderGB($p) { if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s/1GB,2) } else { return -1 } }
$src = 'C:\Users\Admin\phi-vault-backups'; $dst = 'D:\phi-vault-backups'
if (-not (Test-Path $src)) { Write-Output "SOURCE ABSENT: $src - already moved or gone. D copy: $(FolderGB($dst)) GB" } else {
  $free0 = (Get-PSDrive C).Free
  Write-Output "Moving $src to $dst"
  robocopy $src $dst /E /MOVE /R:1 /W:1 /NFL /NDL /NJH | Out-String | Write-Output
  $after = FolderGB($dst)
  "D copy total: $after GB - C folder still present: $(Test-Path $src) - C free now: $([math]::Round((Get-PSDrive C).Free/1GB,2)) GB (freed $([math]::Round(((Get-PSDrive C).Free-$free0)/1GB,2)) GB)" | Write-Output
}
Write-Output 'BACKUPS MOVE DONE'
```
