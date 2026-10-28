# Job 277 — VEIL repackage verdict census (pid 64676, launched by 273)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 273 launched the VEIL repackage (pid 64676) under the pre-patch session - the cook runs outside the runner, so its verdict is read from the terrain: UAT processes still alive?, the AutomationTool log tail and its verdict lines, and the archive exe stamp under D:\Builds\VEIL\VEIL_DONE. This package cooks the dressed maps + clock fix + ProjectID form; the nav/ABP deltas (274-276) ride the FINAL repackage after they land. Read-only. ==='
$procs = Get-Process -Name 'dotnet','AutomationTool','UnrealEditor','UnrealEditor-Cmd' -ErrorAction SilentlyContinue
Write-Output "build processes running: $(@($procs).Count)"
$procs | Select-Object ProcessName, Id, CPU | Format-Table -AutoSize | Out-String | Write-Output
$logDir = 'C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8'
$log = Get-ChildItem $logDir -Filter 'Log*.txt' | Sort-Object LastWriteTime -Descending | Select-Object -First 1
$log | Select-Object FullName, Length, LastWriteTime | Format-List | Out-String | Write-Output
if ($log) {
  Select-String -Path $log.FullName -Pattern 'ExitCode=|BUILD SUCCESSFUL|Error:|error ' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() }
  Write-Output '--- log tail 12 ---'
  Get-Content $log.FullName -Tail 12
}
$exe = Get-ChildItem 'D:\Builds\VEIL\VEIL_DONE' -Recurse -Filter 'VEIL.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($exe) { $exe | Select-Object FullName, @{n='MB';e={[math]::Round($_.Length/1MB,1)}}, LastWriteTime | Format-List | Out-String | Write-Output } else { Write-Output 'VEIL.exe not present in the archive yet' }
Write-Output 'COOK VERDICT CENSUS DONE'
```
