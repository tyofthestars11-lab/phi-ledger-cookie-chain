# Job 265 — VEIL cook failure census: ExitCode 6's own error lines

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 258 read the VEIL repackage (launched by 254, pid 63448) as AutomationTool ExitCode=6 after 71.13s of dotnet, archive exe still attempt 2s from 16:13 - the cook FAILED and 258 never printed why. This census reads the newest AutomationTool Log.txt whole-tail plus every Error line in it, so the failure is named by its own text before anything relaunches. Read-only. ==='
$dir = 'C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8'
$log = Join-Path $dir 'Log.txt'
Get-Item $log | Select-Object FullName, Length, LastWriteTime | Format-List
Write-Output '--- every Error line ---'
Select-String -Path $log -Pattern 'Error:|error:|ERROR' | ForEach-Object { $_.Line } | Select-Object -First 40
Write-Output '--- tail 60 ---'
Get-Content $log -Tail 60
Write-Output 'COOK FAILURE CENSUS DONE'
```
