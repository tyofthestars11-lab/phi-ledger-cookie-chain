<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FULL RUNTIME TEXT READ - BOTH PROJECTS (Jobs 328+329 closed the floor question by experiment: the PHI_GROUND slabs carry healthy collision - engine Cube, QueryAndPhysics, BlockAll, CTF_USE_DEFAULT, one box shape - and job 329 laid a guaranteed engine-Cube pad exactly under each spawn, top at z=0, saved, recooked BUILD SUCCESSFUL, and the pawns STILL fell through it in both games: VEIL -12341 to -17136, OMNI -12766 to -17597. A stock pawn cannot fall through a stock BlockAll cube. The fault is therefore in runtime code or config this seat has not yet read whole: job 324 printed the Character sources (clean) but only GREP lines of the GameModes, and the PHI instruments - MOVE TEST, CENSUS, TICKPROOF - live in files never printed. This job prints, in one pass: (1) every Source .cpp/.h file whose text contains PHI MOVE TEST, PHI CENSUS, or PHI GM TICKPROOF - full text; (2) both GameMode .cpp files full text; (3) DefaultEngine.ini and DefaultGame.ini full text for both projects. READ-ONLY.) ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  "########## $name ##########" | Write-Output
  $hits = Select-String -Path "$proj\Source\*.cpp","$proj\Source\*.h" -Recurse -Pattern 'PHI MOVE TEST|PHI CENSUS|PHI GM TICKPROOF' -List -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Path -Unique
  if (-not $hits) { $hits = Select-String -Path "$proj\Source" -Recurse -Include '*.cpp','*.h' -Pattern 'PHI MOVE TEST|PHI CENSUS|PHI GM TICKPROOF' -List -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Path -Unique }
  foreach ($f in $hits) { "--- INSTRUMENT FILE: $f ---" | Write-Output; Get-Content $f | Write-Output }
  $gm = Get-ChildItem "$proj\Source" -Recurse -Filter '*GameMode.cpp' -File -ErrorAction SilentlyContinue
  foreach ($f in $gm) { "--- GAMEMODE FILE: $($f.FullName) ---" | Write-Output; Get-Content $f.FullName | Write-Output }
  foreach ($ini in @('DefaultEngine.ini','DefaultGame.ini')) { "--- CONFIG: $ini ---" | Write-Output; Get-Content "$proj\Config\$ini" -ErrorAction SilentlyContinue | Write-Output }
}
Write-Output 'RUNTIME TEXT READ DONE'
```
