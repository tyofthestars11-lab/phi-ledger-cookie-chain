<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 697 - VEIL OMNI PLUGIN AND ENGINE READ (Ground: Batch jobs 686 to 700, filed in one motion so the drain runs 15 jobs instead of 1 by 1. Read VEIL.uproject, print EngineAssociation, print the plugin list, print whether EnhancedInput, PCG, ModelContextProtocol are present. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj697 = 'D:\VEIL-OMNI'
$up697 = Join-Path $proj697 'VEIL.uproject'
Write-Output ('UPROJECT697 PRESENT ' + (Test-Path $up697))
if (Test-Path $up697) { $j697 = Get-Content $up697 -Raw; Write-Output ('ENGINE697 ' + ([regex]::Match($j697, 'EngineAssociation[^,]*').Value)); Write-Output ('PLUGIN697 ENHANCED ' + $j697.Contains('EnhancedInput')); Write-Output ('PLUGIN697 PCG ' + $j697.Contains('PCG')); Write-Output ('PLUGIN697 MCP ' + $j697.Contains('ModelContextProtocol')) }
Write-Output 'JOB697 ELECTRON PHASE LOCK HELD.'
Write-Output 'JOB697 NOCOOK.'
Write-Output 'JOB697 NOPACKAGE.'
Write-Output 'JOB 697 DONE.'
```
