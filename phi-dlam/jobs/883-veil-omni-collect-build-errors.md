<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 883 - VEIL OMNI COLLECT BUILD ERRORS EDITOR CLOSED FIRST TYREE TYPES NOTHING ==='
Set-Location "C:\Users\Admin\phi-ledger-cookie-chain"
git pull origin main
git log --oneline -1
powershell -File .\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
powershell -File D:\VEIL-OMNI\Tools\veil_omni_collect_build_errors.ps1
Write-Output "=== JOB883 BUILD ERRORS FILE WHOLE ==="
if (Test-Path "D:\VEIL-OMNI\build_errors.txt") { Get-Content "D:\VEIL-OMNI\build_errors.txt" } else { Write-Output "JOB883 BUILD ERRORS FILE MISSING" }
Write-Output "=== JOB883 PC ONLY FILES WHOLE ==="
if (Test-Path "D:\VEIL-OMNI\pc_only_files.txt") { Get-Content "D:\VEIL-OMNI\pc_only_files.txt" } else { Write-Output "JOB883 PC ONLY FILES MISSING" }
Write-Output "=== JOB883 NO DELETE SAVED NO DELETE CONTENT NO PACKAGE NO LAUNCHER OPEN NO PROCESS KILL ==="
Write-Output "WHOLE JOB DONE."
```
