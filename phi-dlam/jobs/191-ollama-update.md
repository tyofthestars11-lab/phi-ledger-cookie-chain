<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== Ollama update (Tyree's word, 2026-10-27): version before, winget upgrade, version after, models intact ==="
$before = (& ollama --version 2>&1 | Select-Object -First 1)
Write-Output "before: $before"
winget upgrade --id Ollama.Ollama --silent --accept-source-agreements --accept-package-agreements 2>&1 | Select-Object -Last 6
Start-Sleep -Seconds 5
$after = (& ollama --version 2>&1 | Select-Object -First 1)
Write-Output "after: $after"
Write-Output "--- models on this machine ---"
& ollama list 2>&1 | Select-Object -First 12
Write-Output "=== JOB 191 DONE ==="
```
