<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MERGE MANIFEST CENSUS - THE PHYSICAL MERGE, STEP ONE (Tyrees merge word 2026-10-28 01:01 MDT made VEIL and OMNI one game, VEIL OMNI, with the VEIL project on D as the merged base. His question tonight - is it one single game on my PC now - gets answered from the disk, not the bible: the merge is DECIDED and the base is DESIGNATED, and this census is the first physical step. It inventories exactly what the port must carry: every Source file in both projects with sizes (the OMNI quest chain, XP ladder and WARDEN systems live in that tree - UOMNIQuestSystem, AOMNIWardenPrime, OMNIQuestContent, the statues and fragments), every map file in both projects named with sizes (OMNIWorld is the future Omni District region), the GameDefaultMap lines in both DefaultGame.ini files, and the dialogue tables both games carry. From this manifest the port jobs are written file by file - nothing ports on a guess. READ-ONLY: nothing moves, nothing is copied, nothing is deleted.) ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  "##### $name SOURCE #####" | Write-Output
  if (Test-Path "$proj\Source") {
    Get-ChildItem "$proj\Source" -Recurse -File -ErrorAction SilentlyContinue | Sort-Object FullName | ForEach-Object { Write-Output ("PHI MERGE SRC $name " + $_.FullName.Substring($proj.Length + 1) + " bytes=" + $_.Length) }
  } else { Write-Output "PHI MERGE SRC $name SOURCE ABSENT" }
  "##### $name MAPS #####" | Write-Output
  if (Test-Path "$proj\Content") {
    Get-ChildItem "$proj\Content" -Recurse -Filter '*.umap' -File -ErrorAction SilentlyContinue | Sort-Object FullName | ForEach-Object { Write-Output ("PHI MERGE MAP $name " + $_.FullName.Substring($proj.Length + 1) + " bytes=" + $_.Length) }
  }
  "##### $name CONFIG #####" | Write-Output
  $dg = "$proj\Config\DefaultGame.ini"
  if (Test-Path $dg) { Select-String -Path $dg -Pattern 'GameDefaultMap|EditorStartupMap|ProjectName' | ForEach-Object { Write-Output ("PHI MERGE CFG $name " + $_.Line.Trim()) } }
  $de = "$proj\Config\DefaultEngine.ini"
  if (Test-Path $de) { Select-String -Path $de -Pattern 'GameDefaultMap|EditorStartupMap|GlobalDefaultGameMode' | ForEach-Object { Write-Output ("PHI MERGE CFG $name " + $_.Line.Trim()) } }
  "##### $name VOICE #####" | Write-Output
  if (Test-Path "$proj\Content\Voice") { Get-ChildItem "$proj\Content\Voice" -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ("PHI MERGE VOICE $name " + $_.Name + " bytes=" + $_.Length) } } else { Write-Output "PHI MERGE VOICE $name ABSENT" }
}
Write-Output '##### OMNI SYSTEM CLASSES (the port payload, named from its own source) #####'
if (Test-Path 'D:\OMNI-UE\Source') {
  Get-ChildItem 'D:\OMNI-UE\Source' -Recurse -Include '*.h','*.cpp' -File -ErrorAction SilentlyContinue | Select-String -Pattern 'class .*Quest|class .*Warden|XPNeedForLevel|OMNI QUEST|OMNI XP' -ErrorAction SilentlyContinue | Select-Object -First 40 | ForEach-Object { Write-Output ("PHI MERGE SYS " + $_.Filename + ":" + $_.LineNumber + " " + $_.Line.Trim()) }
}
Write-Output 'MERGE MANIFEST DONE'
```
