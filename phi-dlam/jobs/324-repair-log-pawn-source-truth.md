<!-- PHI-DIRECT -->
```powershell
Write-Output '=== REPAIR LOG TRUTH + PAWN SOURCE TRUTH - READ-ONLY (Jobs 321/322 returned with NO PHI GROUND REPAIR lines in either result - the commandlet output the jobs grepped came back empty, so whether the slab repair ran at all is unread. And VEILs recook in 321 exited 1 Error_Unknown while OMNIs in 322 succeeded and STILL falls at spawn. Meanwhile the other seats capsule theory targets a Blueprint - but job 286 measured the pawns as C++ classes: VEILCharacter.cpp and OMNICharacter.cpp. Her truth is in her source code. This job reads, in one pass: (1) both groundrepair commandlet logs - tails plus any PHI/Error/Exception lines - settling whether the repair executed; (2) VEILs repaircook321.log error context - why that recook exited 1; (3) BOTH character source files, cpp and h, printed whole - capsule setup, movement setup, mesh setup, constructor truth; (4) DefaultPawnClass wiring from the GameMode sources. READ-ONLY: nothing edited.) ==='
'##### groundrepair logs #####' | Write-Output
foreach ($f in @('D:\VEIL\Saved\groundrepair321.log','D:\OMNI-UE\Saved\groundrepair322.log')) {
  "--- $f ---" | Write-Output
  if (Test-Path $f) { $fi = Get-Item $f; "size $([math]::Round($fi.Length/1KB,1)) KB" | Write-Output; Select-String -Path $f -Pattern 'PHI|Error|error|Exception|Traceback|LogPython' | Select-Object -First 30 | ForEach-Object { $_.Line.Trim() } | Write-Output; '...tail...' | Write-Output; Get-Content $f -Tail 6 | Write-Output } else { Write-Output 'LOG NOT FOUND' }
}
'##### repaircook321 error context #####' | Write-Output
if (Test-Path 'D:\VEIL\Saved\repaircook321.log') { Select-String -Path 'D:\VEIL\Saved\repaircook321.log' -Pattern 'error |Error:|ERROR|error:' -Context 1,1 | Select-Object -First 10 | ForEach-Object { $_.Context.PreContext; $_.Line.Trim(); $_.Context.PostContext; '...' } | Write-Output } else { Write-Output 'LOG NOT FOUND' }
'##### character sources #####' | Write-Output
foreach ($f in @('D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp','D:\VEIL\Source\VEIL\Public\Character\VEILCharacter.h','D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp','D:\OMNI-UE\Source\OMNI\Public\Character\OMNICharacter.h')) {
  "--- $f ---" | Write-Output
  if (Test-Path $f) { Get-Content $f -TotalCount 260 | Write-Output } else { Write-Output 'FILE NOT FOUND'; Get-ChildItem (Split-Path $f) -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Name | Write-Output }
}
'##### pawn class wiring #####' | Write-Output
Select-String -Path 'D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp','D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp' -Pattern 'Pawn|Character' -ErrorAction SilentlyContinue | ForEach-Object { "$($_.Filename): $($_.Line.Trim())" } | Write-Output
Write-Output 'PAWN TRUTH READ DONE'
```
