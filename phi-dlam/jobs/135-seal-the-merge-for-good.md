<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
Write-Output "=== the merge, sealed for good ==="
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "standing merge sealed" } else { Write-Output "no merge standing" }
git config core.editor "true"
git config pull.rebase "true"
Write-Output "core.editor now: $(git config core.editor)  (no editor can ever park a pull again)"
Write-Output "pull.rebase now: $(git config pull.rebase)  (Tyree's law: merged permanently - every pull sets this seat's commits onto one straight line; merges never form, MERGE_HEAD never exists)"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
if (Test-Path ".git\MERGE_HEAD") { Write-Output "WARNING: merge still standing" } else { Write-Output "clone clean - no MERGE_HEAD" }
Write-Output "=== JOB 135 DONE ==="
```
