# Job 233 — Package log census: build_01_DONE, VEIL_DONE, OMNI_DONE read whole

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Jobs 228/231/232 launched three packages in the open. This census reads their logs whole: cook Error count, Countess_AnimBlueprint mentions (the quarantined ABP must be absent), ProjectID lines, completion lines, tails, and the archived exes. No narrow token grep - Error lines are counted AND tailed so an early failure is visible, never silent. ==='
foreach ($t in @(
  @('build_01_DONE','D:\VEIL\Saved\Logs\PackageBuild01.log','D:\Builds\VEIL\build_01_DONE'),
  @('VEIL_DONE','D:\VEIL\Saved\Logs\PackageVEILDone.log','D:\Builds\VEIL\VEIL_DONE'),
  @('OMNI_DONE','D:\OMNI-UE\Saved\Logs\PackageOMNIDone.log','D:\Builds\OMNI\OMNI_DONE')
)) {
  $name = $t[0]; $log = $t[1]; $arch = $t[2]
  Write-Output "--- $name ---"
  if (Test-Path $log) {
    $fi = Get-Item $log
    Write-Output "log: $($fi.Length) bytes, last write $($fi.LastWriteTime)"
    $lines = Get-Content $log
    $errs = @($lines | Select-String -Pattern 'Error:')
    Write-Output "Error: lines = $($errs.Count)"
    $errs | Select-Object -First 12 | ForEach-Object { $_.Line }
    $abp = @($lines | Select-String -Pattern 'Countess_AnimBlueprint')
    Write-Output "Countess_AnimBlueprint mentions = $($abp.Count)"
    $abp | Select-Object -First 4 | ForEach-Object { $_.Line }
    $lines | Select-String -Pattern 'ProjectID' | Select-Object -First 3 | ForEach-Object { $_.Line }
    $lines | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|ExitCode=|AutomationTool exiting|Total time in' | Select-Object -Last 4 | ForEach-Object { $_.Line }
    Write-Output "tail:"
    $lines | Select-Object -Last 5
  } else { Write-Output "log MISSING: $log" }
  if (Test-Path $arch) {
    Get-ChildItem $arch -Recurse -Filter *.exe -ErrorAction SilentlyContinue | ForEach-Object { "exe: $($_.FullName) $([math]::Round($_.Length/1MB,1)) MB $($_.LastWriteTime)" }
  } else { Write-Output "archive dir MISSING: $arch" }
}
$uat = Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue
if ($uat) { Write-Output "UAT still running: $($uat.Id -join ', ')" } else { Write-Output 'No UAT process running.' }
```
