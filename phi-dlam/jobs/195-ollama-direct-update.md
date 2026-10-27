<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== Ollama update, direct route (Tyree's word; job 191 proved winget carries nothing newer than 0.40.11) ==="
$before = (& ollama --version 2>&1 | Select-Object -First 1)
Write-Output "before: $before"
$installer = "D:\_PhiHolding\OllamaSetup.exe"
Invoke-WebRequest -Uri "https://ollama.com/download/OllamaSetup.exe" -OutFile $installer -UseBasicParsing
Write-Output "installer downloaded: $([math]::Round((Get-Item $installer).Length/1MB,1)) MB"
$p = Start-Process $installer -ArgumentList "/VERYSILENT","/SUPPRESSMSGBOXES","/NORESTART" -PassThru -Wait
Write-Output "installer exit code: $($p.ExitCode)"
Start-Sleep -Seconds 5
$after = (& ollama --version 2>&1 | Select-Object -First 1)
Write-Output "after: $after"
& ollama list 2>&1 | Select-Object -First 6
Write-Output "=== JOB 195 DONE ==="
```
