# Job 254 — CLOCK FIX: OMNI build + proof, then repackage BOTH (sequentially) + standalone proof

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 253 removed the title pause from both GameModes, built VEIL and proved its clock in -game, leaving the verdict in D:\_PhiHolding\clockfix_veil_proof.txt. This job: build OMNI, prove OMNI the same way, and ONLY IF both proofs show time advancing and pawn ticks flowing, repackage BOTH games SEQUENTIALLY (job 233/240 lesson: never two UATs at once - the mutex takes the second) and run the standalone TICKPROOF on the fresh VEIL_DONE: worldTime advancing in the package is the clock verdict at the finish line. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' OMNIEditor Win64 Development -Project='D:\OMNI-UE\OMNI.uproject' -WaitMutex -NoHotReload 2>&1 | Select-String -Pattern 'error|Total time' | Select-Object -First 12 | ForEach-Object { $_.Line }
$log = 'D:\_PhiHolding\tickproof_omni_clockfix.log'
$p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList @('D:\OMNI-UE\OMNI.uproject','-game','-windowed','-resx=800','-resy=450','-unattended','-nosplash',"-abslog=$log") -PassThru
Start-Sleep -Seconds 40
$proof = Select-String -Path $log -Pattern 'TICKPROOF' -ErrorAction SilentlyContinue | Select-Object -Last 4 | ForEach-Object { $_.Line }
$proof | ForEach-Object { Write-Output $_ }
$adv = ($proof | Where-Object { $_ -match 'worldTime=([0-9.]+)' -and [double]$Matches[1] -gt 0.5 }).Count
$tick = ($proof | Where-Object { $_ -match 'pawnTickEntries=([0-9]+)' -and [int]$Matches[1] -gt 0 }).Count
Write-Output "CLOCKFIX OMNI: samplesWithTimeAdvanced=$adv samplesWithPawnTicks=$tick"
$veilProof = Get-Content 'D:\_PhiHolding\clockfix_veil_proof.txt' -ErrorAction SilentlyContinue
Write-Output "VEIL marker: $veilProof"
if ($adv -gt 0 -and $tick -gt 0 -and "$veilProof" -match 'timeAdvanced=[1-9]' -and "$veilProof" -match 'pawnTicks=[1-9]') {
  Write-Output 'BOTH PROOFS GREEN - VEIL repackage launches in the open (ONE UAT at a time; job 255 fires OMNI only after VEILs archive stands)'
  $uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $proc = Start-Process $uat -ArgumentList @('BuildCookRun','-project=D:\VEIL\VEIL.uproject','-noP4','-platform=Win64','-clientconfig=Development','-build','-cook','-stage','-pak','-archive','-archivedirectory=D:\Builds\VEIL\VEIL_DONE','-unattended','-utf8output') -PassThru -NoNewWindow
  Write-Output "VEIL repackage launched pid $($proc.Id) (dressed maps + clock fix + ProjectID struct form)"
} else { Write-Output 'REPACKAGE HELD - a proof is not green; the census above is the evidence' }
Write-Output 'CLOCK FIX OMNI + REPACKAGE GATE DONE'
```
