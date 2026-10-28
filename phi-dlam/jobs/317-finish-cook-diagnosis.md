<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FINISH COOK FAILURE DIAGNOSIS - READ THE COOK LOGS ERROR LINES (Job 315 VEIL finish cook ran for real this time - the Win64 token was accepted - but UAT exited 25 BUILD FAILED before archiving, so the exe on disk is still the old build and its settle proof only re-measured the old package. Exit 25 means the failure is INSIDE the build or cook stage, and the finishcook logs on disk carry the actual error text. This job reads them: for each games finishcook log, print the lines around the first error hits - compiler errors, missing modules, failed DLLs - with context, plus each logs stage markers so the failing stage is named. READ-ONLY: nothing edited, nothing cooked.) ==='
foreach ($g in @(@('VEIL','D:\VEIL\Saved\finishcook315.log'), @('OMNI','D:\OMNI-UE\Saved\finishcook316.log'))) {
  $name = $g[0]; $log = $g[1]
  "##### $name : $log #####" | Write-Output
  if (Test-Path $log) {
    $fi = Get-Item $log; "log size $([math]::Round($fi.Length/1KB,1)) KB, modified $($fi.LastWriteTime.ToString('HH:mm:ss'))" | Write-Output
    '--- stage markers ---' | Write-Output
    Select-String -Path $log -Pattern 'BUILDING:|COOKING:|STAGING:|ARCHIVING:|Building |Cooking |error code|ExitCode' | Select-Object -First 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
    '--- first error contexts ---' | Write-Output
    Select-String -Path $log -Pattern 'error |Error:|ERROR|error:' -Context 1,2 | Select-Object -First 14 | ForEach-Object { $_.Context.PreContext; $_.Line.Trim(); $_.Context.PostContext; '...' } | Write-Output
    '--- err file if present ---' | Write-Output
    if (Test-Path "$log.err") { Get-Content "$log.err" -Tail 15 | Write-Output } else { Write-Output 'no .err file' }
  } else { Write-Output 'LOG NOT FOUND' }
}
Write-Output 'COOK DIAGNOSIS DONE'
```
