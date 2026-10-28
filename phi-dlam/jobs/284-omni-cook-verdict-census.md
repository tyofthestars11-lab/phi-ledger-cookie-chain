<!-- PHI-DIRECT -->
```powershell
Write-Output '=== Job 279 launched the OMNI repackage (pid 11600) at 20:32 MDT under the pre-v5.34 runner. Its verdict is read from the terrain: UAT processes still alive?, the AutomationTool log tail and verdict lines, the archive exe under D:\Builds\OMNI. Also census: does job 283s result exist yet (the brain nav+ABP run). Read-only. ==='
$uat = @(Get-Process | Where-Object { $_.ProcessName -match 'AutomationTool|UnrealEditor' } | Select-Object ProcessName, Id, CPU)
Write-Output "build processes running: $($uat.Count)"
$uat | Format-Table -AutoSize | Out-String | Write-Output
$log = 'C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt'
if (Test-Path $log) {
  Get-Item $log | Select-Object FullName, Length, LastWriteTime | Format-List | Out-String | Write-Output
  Select-String -Path $log -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|ExitCode=|Error:|Total time' | Select-Object -Last 10 | ForEach-Object { $_.Line } | Write-Output
  Write-Output '--- log tail 8 ---'
  Get-Content $log -Tail 8 | Write-Output
}
if (Test-Path 'D:\Builds\OMNI') {
  Get-ChildItem 'D:\Builds\OMNI' -Recurse -Filter '*.exe' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 3 | ForEach-Object { "exe: $($_.FullName) MB $([math]::Round($_.Length/1MB,1)) stamp $($_.LastWriteTime)" } | Write-Output
} else { Write-Output 'D:\Builds\OMNI does not exist yet' }
Write-Output "job 283 result exists: $(Test-Path 'C:\Users\Admin\phi-vault\phi-dlam\results\283-brain-nav-abp-native.result.md')"
Write-Output 'OMNI COOK VERDICT CENSUS DONE'
```
