# Job 252 — Character source census: both character files whole, for the ABP-reference removal

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 246s standalone log named a defect in the packaged build: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint_C - the character CONSTRUCTOR still hard-references the quarantined ABP class, so the package reads anim=none even though the 220/225 bypass poses Idle_Relaxed elsewhere. The reference comes out, but this lane does not do blind source surgery (job 220s faults are the standing lesson): this census prints both character .cpp and .h files WHOLE, plus every AnimBlueprint mention across both Source trees with file:line, so the removal job is written against the exact lines. Read-only. ==='
foreach ($f in @('D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp','D:\VEIL\Source\VEIL\Public\Character\VEILCharacter.h','D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp','D:\OMNI-UE\Source\OMNI\Public\Character\OMNICharacter.h')) {
  Write-Output "===== $f ====="
  if (Test-Path $f) { Get-Content $f } else { Write-Output 'FILE MISSING' }
}
Write-Output '===== AnimBlueprint mentions, both Source trees ====='
foreach ($root in @('D:\VEIL\Source','D:\OMNI-UE\Source')) {
  Get-ChildItem $root -Recurse -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern 'AnimBlueprint|AnimInstanceClass|SetAnimClass' | ForEach-Object { "$($_.Path):$($_.LineNumber): $($_.Line.Trim())" }
}
```
