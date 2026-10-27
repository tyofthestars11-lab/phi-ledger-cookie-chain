<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
Write-Output "=== kill the vim merge, permanently ==="
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "standing merge sealed" } else { Write-Output "no merge standing" }
git config core.editor "true"
Write-Output "core.editor now: $(git config core.editor)  (merges auto-seal with the default message; no editor can ever park a pull again)"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
if (Test-Path ".git\MERGE_HEAD") { Write-Output "WARNING: merge still standing" } else { Write-Output "clone clean - no MERGE_HEAD" }
Write-Output "=== JOB 135 DONE ==="
```
