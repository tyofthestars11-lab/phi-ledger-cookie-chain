<!-- PHI-DIRECT -->
```powershell
Write-Output '=== BUILD FIX PASS 473 - THE COMPILER NAMED THREE ADDRESSES, ALL ANSWERED (Ground read whole from jobs 466 and 468: the builds never touched a DLL lock; the compiler named source faults in the code this lane seated, and they stand in three places. First, flight: the pause binds at lines 221 to 223 of VEILGameMode cpp belong to the player controller, not the game mode, so the F bind calling a game mode ToggleFlight and the game mode qualified definition both miss the class that actually owns the input component, errors C2039 C2276 C2672, and the GetWorld call at the file end lands outside any class, C3861. Flight is a controller power and this pass moves it there whole: the bind retargets to the player controller, the appended function is rewritten under the controller qualifier fetching its own pawn, and the header declaration is verified inside the controller class region, moved there if it sits elsewhere. Second, the attack log line at VEILCharacter cpp 582 reads BoltLen outside the bolt block braces that declared it, C2065; the log line drops the length and keeps the hit flag, one line, zero scope risk. Third, the face button read: X already carries Interact at line 242, so the Fire seat added at 244 moves to Y, the free face button, leaving X to Interact alone. Every edit is count gated with backups, the regions print, and one build runs the standing way carrying flight, attack, floor and the 464 menu bodies together, its Result line riding the verdict. Every variable carries the bf473 prefix.) ==='
$bf473gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$bf473gh = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\VEILGameMode.h'
$bf473ch = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$bf473gl = @(Get-Content $bf473gm)
$bf473bind = @(); $bf473func = @()
for ($bf473i = 0; $bf473i -lt $bf473gl.Count; $bf473i++) {
  if ($bf473gl[$bf473i] -match 'BindKey\(EKeys::F') { $bf473bind += $bf473i }
  if ($bf473gl[$bf473i] -match 'void AVEILGameMode::ToggleFlight\(\)') { $bf473func += $bf473i }
}
$bf473hl = @(Get-Content $bf473gh)
$bf473decl = @(); for ($bf473k = 0; $bf473k -lt $bf473hl.Count; $bf473k++) { if ($bf473hl[$bf473k] -match 'void ToggleFlight\(\);') { $bf473decl += $bf473k } }
$bf473cl = @(Get-Content $bf473ch)
$bf473log = @(); $bf473xmap = @()
for ($bf473m = 0; $bf473m -lt $bf473cl.Count; $bf473m++) {
  if ($bf473cl[$bf473m] -match 'PHI ATTACK FIRED') { $bf473log += $bf473m }
  if ($bf473cl[$bf473m] -match 'Map\(FireAction, EKeys::Gamepad_FaceButton_Left\)') { $bf473xmap += $bf473m }
}
Write-Output ('GATES bind=' + $bf473bind.Count + ' func=' + $bf473func.Count + ' decl=' + $bf473decl.Count + ' log=' + $bf473log.Count + ' xmap=' + $bf473xmap.Count)
$bf473go = ($bf473bind.Count -eq 1) -and ($bf473func.Count -eq 1) -and ($bf473decl.Count -eq 1) -and ($bf473log.Count -eq 1) -and ($bf473xmap.Count -eq 1)
if (-not $bf473go) { Write-Output 'PHI BF473 VERDICT: BUILD FIX SKIP gates closed'; Write-Output 'JOB 473 DONE'; return }
Copy-Item $bf473gm ($bf473gm + '.phi-backup-473') -Force
Copy-Item $bf473gh ($bf473gh + '.phi-backup-473') -Force
Copy-Item $bf473ch ($bf473ch + '.phi-backup-473') -Force
$bf473gl[$bf473bind[0]] = $bf473gl[$bf473bind[0]].Replace('AVEILGameMode::ToggleFlight', 'AVEILPlayerController::ToggleFlight')
$bf473fend = -1
for ($bf473e = $bf473func[0] + 1; $bf473e -lt $bf473gl.Count; $bf473e++) { if ($bf473gl[$bf473e] -eq '}') { $bf473fend = $bf473e; break } }
Write-Output ('FUNC END=' + $bf473fend)
$bf473newFunc = @(
'void AVEILPlayerController::ToggleFlight()',
'{',
"`tACharacter* Runner = Cast<ACharacter>(GetPawn());",
"`tif (!Runner) { return; }",
"`tUCharacterMovementComponent* Move = Runner->GetCharacterMovement();",
"`tif (!Move) { return; }",
"`tif (Move->MovementMode == MOVE_Flying)",
"`t{",
"`t`tMove->SetMovementMode(MOVE_Walking);",
"`t`tUE_LOG(LogTemp, Display, TEXT(""PHI FLIGHT OFF""));",
"`t}",
"`telse",
"`t{",
"`t`tMove->SetMovementMode(MOVE_Flying);",
"`t`tMove->bCheatFlying = true;",
"`t`tUE_LOG(LogTemp, Display, TEXT(""PHI FLIGHT ON""));",
"`t}",
'}'
)
$bf473out = @()
for ($bf473j = 0; $bf473j -lt $bf473gl.Count; $bf473j++) {
  if ($bf473j -eq $bf473func[0]) { foreach ($bf473n in $bf473newFunc) { $bf473out += $bf473n }; $bf473j = $bf473fend; continue }
  $bf473out += $bf473gl[$bf473j]
}
Set-Content -Path $bf473gm -Value $bf473out
$bf473pcClass = -1; $bf473gmClass = -1
for ($bf473q = 0; $bf473q -lt $bf473hl.Count; $bf473q++) {
  if ($bf473hl[$bf473q] -match 'class.*AVEILPlayerControlle[r]') { $bf473pcClass = $bf473q }
  if ($bf473hl[$bf473q] -match 'class.*AVEILGameMode') { if ($bf473gmClass -lt 0) { $bf473gmClass = $bf473q } }
}
Write-Output ('HEADER CLASSES pc=' + $bf473pcClass + ' gm=' + $bf473gmClass + ' declAt=' + $bf473decl[0])
$bf473declInPc = ($bf473pcClass -ge 0) -and ($bf473decl[0] -gt $bf473pcClass)
if (-not $bf473declInPc) {
  $bf473hl2 = @()
  for ($bf473r = 0; $bf473r -lt $bf473hl.Count; $bf473r++) { if ($bf473r -ne $bf473decl[0]) { $bf473hl2 += $bf473hl[$bf473r] } }
  $bf473tpm = -1
  for ($bf473s = 0; $bf473s -lt $bf473hl2.Count; $bf473s++) { if ($bf473hl2[$bf473s] -match 'TogglePauseMenu' -and $bf473s -gt $bf473pcClass) { $bf473tpm = $bf473s; break } }
  Write-Output ('PC TPM DECL=' + $bf473tpm)
  if ($bf473tpm -ge 0) {
    $bf473hl3 = @()
    for ($bf473t = 0; $bf473t -lt $bf473hl2.Count; $bf473t++) { $bf473hl3 += $bf473hl2[$bf473t]; if ($bf473t -eq $bf473tpm) { $bf473hl3 += "`tvoid ToggleFlight();" } }
    Set-Content -Path $bf473gh -Value $bf473hl3
    Write-Output 'DECL MOVED INTO CONTROLLER'
  }
}
$bf473cl[$bf473log[0]] = "`tUE_LOG(LogTemp, Display, TEXT(""PHI ATTACK FIRED hit=%d""), Hit.bBlockingHit ? 1 : 0);"
$bf473cl[$bf473xmap[0]] = $bf473cl[$bf473xmap[0]].Replace('Gamepad_FaceButton_Left', 'Gamepad_FaceButton_Top').Replace('// X', '// Y')
Set-Content -Path $bf473ch -Value $bf473cl
$bf473v1 = ([regex]::Matches((Get-Content $bf473gm -Raw), 'AVEILPlayerController::ToggleFlight')).Count
$bf473v2 = ([regex]::Matches((Get-Content $bf473ch -Raw), 'Gamepad_FaceButton_Top')).Count
Write-Output ('VERIFY pcflight=' + $bf473v1 + ' ymap=' + $bf473v2)
$bf473buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$bf473uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$bf473logf = 'D:\VEIL-OMNI\Saved\build473.log'
& $bf473buildbat VEILEditor Win64 Development -Project="$bf473uproj" -WaitMutex -NoHotReload *> "$bf473logf"
$bf473result = @(Select-String -Path $bf473logf -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
foreach ($bf473rr in $bf473result) { Write-Output ('BUILD ' + $bf473rr.Line.Trim()) }
$bf473errs = @(Select-String -Path $bf473logf -Pattern 'erro[r] C' -ErrorAction SilentlyContinue | Select-Object -First 10)
foreach ($bf473ee in $bf473errs) { Write-Output ('ERR ' + $bf473ee.Line.Trim()) }
Write-Output ('PHI BF473 VERDICT: BUILD FIX pcflight=' + $bf473v1 + ' ymap=' + $bf473v2)
Write-Output 'JOB 473 DONE'
```
