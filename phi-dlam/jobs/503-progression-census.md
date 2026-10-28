<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PROGRESSION CENSUS 503 - WHAT THE GAME ACTUALLY ADVANCES (Ground: Tyree graded the game at ten percent, not a hundred, and named the missing whole directly - the game has no progression. The systems stand on paper: a quest chain, fragments, a cache, a Warden, health. What a player feels is another matter, and feelings ride on what the code actually awards, tracks, and shows. This job reads the progression ground whole from the source on the PC: the quest system header and source at every quest, stage, fragment, Warden, and reward line, the game mode at its spawn and quest lines, the character at its health and level lines, the world builder function names that mark the regions, and the first objective and HUD text lines anywhere in the source. Read only - the progression seat authors from these prints, against the real code, in the next job. Every variable carries the p503 prefix.) ==='
$p503src = 'D:\VEIL-OMNI\Source\VEIL'
$p503quest = Get-ChildItem $p503src -Recurse -Filter 'OMNIQuest*' -ErrorAction SilentlyContinue
Write-Output ('QUEST FILES=' + @($p503quest).Count)
foreach ($p503f in $p503quest) {
  $p503lines = @(Get-Content $p503f.FullName)
  Write-Output ('QFILE ' + $p503f.Name + ' lines=' + $p503lines.Count)
  for ($p503i = 0; $p503i -lt $p503lines.Count; $p503i++) {
    if ($p503lines[$p503i] -match 'Quest|Stage|Fragment|Warden|Reward|Complete|Advance|XP|Level') { Write-Output ('Q ' + ($p503i + 1) + ': ' + $p503lines[$p503i].Trim()) }
  }
}
$p503gm = Get-ChildItem $p503src -Recurse -Filter 'VEILGameMode*' -ErrorAction SilentlyContinue | Select-Object -First 2
foreach ($p503f in $p503gm) {
  $p503lines = @(Get-Content $p503f.FullName)
  Write-Output ('GMFILE ' + $p503f.Name + ' lines=' + $p503lines.Count)
  for ($p503i = 0; $p503i -lt $p503lines.Count; $p503i++) {
    if ($p503lines[$p503i] -match 'Spawn|Quest|Fragment|Cache|Warden|Give[r]') { Write-Output ('GM ' + ($p503i + 1) + ': ' + $p503lines[$p503i].Trim()) }
  }
}
$p503ch = Get-ChildItem $p503src -Recurse -Filter 'VEILChar*.h' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($p503ch) {
  $p503lines = @(Get-Content $p503ch.FullName)
  for ($p503i = 0; $p503i -lt $p503lines.Count; $p503i++) {
    if ($p503lines[$p503i] -match 'Health|XP|Level|Damage') { Write-Output ('CH ' + ($p503i + 1) + ': ' + $p503lines[$p503i].Trim()) }
  }
}
$p503wb = Get-ChildItem $p503src -Recurse -Filter 'VEILWorldBuild*' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($p503wb) {
  Select-String -Path $p503wb.FullName -Pattern 'void AVEILWorldBuild' | ForEach-Object { Write-Output ('WB ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
}
Get-ChildItem $p503src -Recurse -Include '*.cpp','*.h' -ErrorAction SilentlyContinue | Select-String -Pattern 'Objective|QuestLog|ShowObjective' | Select-Object -First 10 | ForEach-Object { Write-Output ('OBJ ' + $_.Filename + ' ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
Write-Output 'PHI P503 VERDICT: PROGRESSION CENSUS DONE'
Write-Output 'JOB 503 DONE'
```
