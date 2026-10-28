<!-- PHI-DIRECT -->
```powershell
Write-Output '=== GROUNDED PACKAGE SETTLE PROOF + COOK CAUSE READ - BOTH GAMES (ton help execution, Tyree 2026-10-27. State it answers: jobs 305/306 saved grounded maps in both projects; jobs 307/308 repackages printed UAT exit 1 BUILD FAILED yet exes stand present and their proof clocks ticked. Two questions, machine-read only: (1) WHAT did UAT actually fail on - the cook logs on disk carry the real error lines, read them; (2) IS THE GROUND IN THE PACKAGES - launch each packaged exe with the standalone proof and read the pawn instrument lines: a falling pawn shows location z dropping without settling, a grounded pawn settles. Prints exe timestamps and sizes so old-vs-new is read, not guessed.) ==='
foreach ($g in @(@('VEIL','D:\VEIL','D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe','D:\VEIL\Saved\repackage307.log','D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs'), @('OMNI','D:\OMNI-UE','D:\Builds\OMNI\OMNI_DONE\Windows\OMNI.exe','D:\OMNI-UE\Saved\repackage308.log','D:\Builds\OMNI\OMNI_DONE\Windows\OMNI\Saved\Logs'))) {
  $name = $g[0]; $proj = $g[1]; $exe = $g[2]; $cooklog = $g[3]; $buildlogs = $g[4]
  "##### $name #####" | Write-Output
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe: $($fi.FullName) | modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss')) | $([math]::Round($fi.Length/1MB,1)) MB" | Write-Output } else { "exe MISSING: $exe" | Write-Output }
  if (Test-Path $cooklog) { "--- cook log error context ($cooklog) ---" | Write-Output; Select-String -Path $cooklog -Pattern 'Error:|ERROR:|error:' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output; '--- cook log tail ---' | Write-Output; Get-Content $cooklog -Tail 5 | Write-Output } else { "cook log not found: $cooklog" | Write-Output }
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem "$proj\Saved\Logs", $buildlogs -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "--- proof log: $($logs.FullName) ---" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI|pawn|Pawn|Location|Dist2D|Z=|worldTime|paused' | Select-Object -Last 25 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
}
Write-Output 'SETTLE PROOF + COOK CAUSE DONE'
```
