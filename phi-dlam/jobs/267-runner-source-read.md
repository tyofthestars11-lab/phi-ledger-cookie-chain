# Job 267 — Runner source read: the DIRECT execution region, whole (read-only, before any patch)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 266 named the wrapper: phi-direct-drain.ps1:28 and phi-dlam.ps1:457 both run DIRECT job code through Start-Job with the output piped to Out-String inside the child - the CLIXML transport that throws node type Text. A patch written against one line, blind to the timeout and result machinery around it, could break the drain itself. This job prints the terrain whole: phi-direct-drain.ps1 entire (2,394 bytes) and phi-dlam.ps1 lines 200-230 (the Invoke-Expression path), 320-350 (the cap region), 440-500 (the DIRECT Start-Job region). Read-only. ==='
Write-Output '===== phi-direct-drain.ps1 WHOLE ====='
Get-Content 'C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1'
Write-Output '===== phi-dlam.ps1 lines 200-230 ====='
$c = Get-Content 'C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1'
for ($i=199; $i -lt [Math]::Min(230,$c.Count); $i++) { '{0}: {1}' -f ($i+1), $c[$i] }
Write-Output '===== phi-dlam.ps1 lines 320-350 ====='
for ($i=319; $i -lt [Math]::Min(350,$c.Count); $i++) { '{0}: {1}' -f ($i+1), $c[$i] }
Write-Output '===== phi-dlam.ps1 lines 440-500 ====='
for ($i=439; $i -lt [Math]::Min(500,$c.Count); $i++) { '{0}: {1}' -f ($i+1), $c[$i] }
Write-Output 'RUNNER SOURCE READ DONE'
```
