<!-- PHI-DIRECT -->
```powershell
Write-Output '=== The last ladder stage is now an instrumented measurement (Tyrees word 2026-10-27: "I allow you to climb" - the handshake retires). The standalone proof (278) reads worldTime + pawnTickEntries; the movement proof needs the pawns LOCATION sampled across time under driven input. First step, read-only: census the proof instrument in both games - which source files carry the TICKPROOF census, how -PhiStandaloneProof is detected, where the samples are taken, and whether pawn location is already logged anywhere. The extension is written against this measured shape, never guessed. ==='
foreach ($proj in @('D:\VEIL','D:\OMNI-UE')) {
  Write-Output "--- $proj ---"
  $hits = Get-ChildItem (Join-Path $proj 'Source') -Recurse -Include '*.cpp','*.h' -ErrorAction SilentlyContinue | Select-String -Pattern 'TICKPROOF|PhiStandaloneProof|StandaloneProof' -List | Select-Object -ExpandProperty Path
  Write-Output "files carrying the proof instrument: $($hits.Count)"
  $hits | Write-Output
  foreach ($f in $hits) {
    Write-Output "### $f"
    Select-String -Path $f -Pattern 'TICKPROOF|PhiStandaloneProof|GetActorLocation|pawnTickEntries|worldTime' | ForEach-Object { "L$($_.LineNumber): $($_.Line.Trim())" } | Write-Output
  }
}
Write-Output 'MOVEMENT PROOF INSTRUMENT CENSUS DONE'
```
