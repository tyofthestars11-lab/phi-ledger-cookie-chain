<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CHARACTER SOURCE WHOLE + MOVEMENT GREP - BOTH PROJECTS, READ-ONLY (Jobs 334+335 printed the identical signature in both packages: capsule capEnabled=3 QueryAndPhysics, capProfile=Pawn, moveMode=3 Falling, onGround=0, floorBlock=0, floorActor=none at every fire; a WorldStatic line trace in the pawn column HITS geometry with top at exactly z=0.0 - VEIL StaticMeshActor_3 hitZ=0.0, OMNI StaticMeshActor_231 hitZ=0.0; and the pawn is already below Z=-50000 at the first diagnostic fire, below -12300 at move-test begin in every proof ever run, at terminal velocity 4000.0. The crossing of z=0 has never been observed by any instrument: from PlayerStart z=120 the arithmetic of an uninterrupted fall reaches -12317 at about 5.15 s, crossing z=0 at about 0.49 s at about 485 u/s, about 4 units per tick at the proofs 120 fps - a swept QueryAndPhysics Pawn capsule registers a BlockAll surface crossed at that speed in every stock project, and every census reads stock shapes with stock settings on both sides. What has never been read whole is the Character source itself: job 324 printed the constructors (clean), job 331 part 1 errored before printing the instrument files, and the MOVE TEST lives in the Character Tick whose full body no result has ever carried. THIS JOB prints, in one pass: (1) every Character .cpp/.h file in both projects, full text; (2) a Source-wide grep of both projects for every movement-affecting call - SetActorLocation, SetActorTransform, Teleport, SetMovementMode, GravityScale, MaxFallSpeed, TerminalVelocity, SetCollisionEnabled, SetCollisionResponse, IgnoreActorWhenMoving, AddActorWorldOffset, SetUpdatedComponent, LaunchCharacter, SetPhysicsLinearVelocity, MOVE_Falling, MOVE_Walking - with file, line number, and line text. READ-ONLY: nothing is written, nothing is cooked.) ==='
foreach ($g in @(@('VEIL','D:\VEIL\Source'), @('OMNI','D:\OMNI-UE\Source'))) {
  $name = $g[0]; $srcdir = $g[1]
  "##### $name CHARACTER FILES #####" | Write-Output
  $charFiles = Get-ChildItem $srcdir -Recurse -File -Include '*Character*.cpp','*Character*.h' | Sort-Object FullName
  if (-not $charFiles) { Write-Output 'NO CHARACTER FILES FOUND' }
  foreach ($f in $charFiles) {
    "----- FILE: $($f.FullName) ($($f.Length) bytes) -----" | Write-Output
    Get-Content $f.FullName | Write-Output
    "----- END FILE: $($f.FullName) -----" | Write-Output
  }
  "##### $name MOVEMENT GREP #####" | Write-Output
  $allSrc = Get-ChildItem $srcdir -Recurse -File -Include '*.cpp','*.h'
  Select-String -Path $allSrc.FullName -Pattern 'SetActorLocation|SetActorTransform|Teleport|SetMovementMode|GravityScale|MaxFallSpeed|TerminalVelocity|SetCollisionEnabled|SetCollisionResponse|IgnoreActorWhenMoving|AddActorWorldOffset|SetUpdatedComponent|LaunchCharacter|SetPhysicsLinearVelocity|MOVE_Falling|MOVE_Walking' | ForEach-Object { "$($_.Filename):$($_.LineNumber): $($_.Line.Trim())" } | Write-Output
  "##### $name DONE #####" | Write-Output
}
Write-Output 'JOB 336 DONE'
```
