<!-- PHI-DIRECT -->
```powershell
Write-Output '=== COMBAT AND STUCK READ 457 - THE VERB TABLE AND THE FLOOR, READ AT THE TRUE ADDRESS BEFORE THE FIX (Ground from Tyree hands in PIE, 2026-10-28: she renders in color, armor and blades, and his verdicts stand whole: she gets stuck in the terrain whenever he loads, he cannot attack, all he can do is move and jump, and sprint on L3 works and is good. So the verb table is partly alive: Move, Look, Jump, Sprint answer; Fire and the rest do not. Job 454 read the builder whole at the true address, Private Character VEILCharacter cpp is 22036 bytes at the same layout, and every fix in this lane authors from printed ground. This job prints five sections. One, every input bind line in the character cpp, capped at 40, so which actions bind where stands named. Two, every handler function signature in the character cpp, capped at 40, the whole verb table at a glance. Three, the Fire and Attack handler bodies whole, capped at 60 lines, plus the lines where the fallback builder maps the Fire and Aim keys, capped at 30. Four, the movement ground: every line naming MaxWalkSpeed, slope, WalkableFloor, CapsuleRadius, CapsuleHalfHeight and StepHeight across the character and the GameMode, capped at 30, because a runner who sticks in terrain is a slope, step or capsule address until the print says otherwise. Five, the spawn ground: the PlayerStart and spawn lines in the GameMode, capped at 20, because stuck whenever I load begins at the spawn. The verdict in one line: COMBAT STUCK READ with the bind count and the fire handler found state. This job is read only and every variable carries the cs457 prefix.) ==='
$cs457char = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$cs457gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$cs457binds = 0; $cs457fire = 0
if (Test-Path $cs457char) {
  $cs457all = @(Get-Content $cs457char)
  $cs457bl = @(Select-String -Path $cs457char -Pattern 'BindAction|BindAxis|BindKey' -ErrorAction SilentlyContinue | Select-Object -First 40)
  foreach ($cs457b in $cs457bl) { Write-Output ('BIND ' + $cs457b.LineNumber + ' ' + $cs457b.Line.Trim()); $cs457binds += 1 }
  $cs457sig = @(Select-String -Path $cs457char -Pattern '::(Start|Stop|On|Do)[A-Z]\w*\(' -ErrorAction SilentlyContinue | Select-Object -First 40)
  foreach ($cs457s in $cs457sig) { Write-Output ('FUNC ' + $cs457s.LineNumber + ' ' + $cs457s.Line.Trim()) }
  $cs457hit = -1
  for ($cs457i = 0; $cs457i -lt $cs457all.Count; $cs457i++) { if ($cs457all[$cs457i] -match '::(StartFire|OnFire|Attack|StartAttack|Fire)\(') { $cs457hit = $cs457i; break } }
  if ($cs457hit -ge 0) { $cs457fire = 1; $cs457to = [Math]::Min($cs457hit + 60, $cs457all.Count); for ($cs457j = $cs457hit; $cs457j -lt $cs457to; $cs457j++) { Write-Output ('FIRE ' + ($cs457j + 1).ToString() + ' ' + $cs457all[$cs457j]) } }
  $cs457fb = @(Select-String -Path $cs457char -Pattern 'Fire|Aim' -ErrorAction SilentlyContinue | Select-Object -First 30)
  foreach ($cs457f in $cs457fb) { Write-Output ('FA ' + $cs457f.LineNumber + ' ' + $cs457f.Line.Trim()) }
  $cs457mv = @(Select-String -Path $cs457char -Pattern 'MaxWalkSpeed|Slope|WalkableFloor|CapsuleRadius|CapsuleHalfHeight|StepHeight|MaxStepHeight' -ErrorAction SilentlyContinue | Select-Object -First 30)
  foreach ($cs457m in $cs457mv) { Write-Output ('MOVE ' + $cs457m.LineNumber + ' ' + $cs457m.Line.Trim()) }
}
if (Test-Path $cs457gm) {
  $cs457sp = @(Select-String -Path $cs457gm -Pattern 'PlayerStart|SpawnActor<AVEILCharacter|RestartPlayer|SpawnLocation' -ErrorAction SilentlyContinue | Select-Object -First 20)
  foreach ($cs457p in $cs457sp) { Write-Output ('SPAWN ' + $cs457p.LineNumber + ' ' + $cs457p.Line.Trim()) }
}
Write-Output ('PHI CS457 VERDICT: COMBAT STUCK READ binds=' + $cs457binds + ' fire_found=' + $cs457fire)
Write-Output 'JOB 457 DONE'
```
