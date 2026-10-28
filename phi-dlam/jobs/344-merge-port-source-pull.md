<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MERGE EXECUTION STEP 2 - PORT SOURCE PULL (Tyrees GO, 2026-10-28: Merge it. The systems port - OMNIs quest chain, phi XP ladder and WARDEN PRIME into the VEIL merged base - gets written from the PCs CURRENT sources, not the repos authored copies: job 340 measured the PC files larger than the repo originals (OMNIQuestSystem.cpp 4594 on PC vs 4449 in repo; OMNIGameMode.cpp 12647 vs 9876) because the voice wiring at the quest beats and the nights diagnostic tranches grew them on the PC. Porting from the repo would lose that growth. THIS JOB prints the full current text of every file the port touches: the six OMNI system files (QuestSystem, QuestContent, WardenPrime - header and cpp each), OMNIs current GameMode.cpp (the quest spawning lives there), VEILs current GameMode.cpp (the wiring must land inside it, diagnostics and all), and both FactionAI headers (the Warden derives from the faction agent - the port needs both class declarations named exactly). READ-ONLY: nothing on the PC changes.) ==='
$files = @(
  'D:\OMNI-UE\Source\OMNI\Public\Systems\OMNIQuestSystem.h',
  'D:\OMNI-UE\Source\OMNI\Private\Systems\OMNIQuestSystem.cpp',
  'D:\OMNI-UE\Source\OMNI\Public\World\OMNIQuestContent.h',
  'D:\OMNI-UE\Source\OMNI\Private\World\OMNIQuestContent.cpp',
  'D:\OMNI-UE\Source\OMNI\Public\AI\OMNIWardenPrime.h',
  'D:\OMNI-UE\Source\OMNI\Private\AI\OMNIWardenPrime.cpp',
  'D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp',
  'D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp',
  'D:\OMNI-UE\Source\OMNI\Public\AI\OMNIFactionAI.h',
  'D:\VEIL\Source\VEIL\Public\AI\VEILFactionAI.h'
)
foreach ($f in $files) {
  Write-Output "===== FILE $f ====="
  if (Test-Path $f) { Write-Output ([System.IO.File]::ReadAllText($f)) } else { Write-Output "FILE MISSING: $f" }
  Write-Output "===== END $f ====="
}
Write-Output 'JOB 344 DONE'
```
