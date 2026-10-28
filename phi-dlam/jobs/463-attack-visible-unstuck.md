<!-- PHI-DIRECT -->
```powershell
Write-Output '=== ATTACK VISIBLE AND UNSTUCK 463 - THE SHOT ANSWERS, THE GROUND LETS GO (Ground read whole from job 457: the verb table stands complete in VEILCharacter cpp, Fire binds at line 286 to a real handler that traces and applies damage, mapped to left mouse and the right trigger, and the movement sections print no slope, step or capsule settings at all, so the movement component runs on engine defaults, a walkable angle near 45 degrees and a step height of 45, while the district is built of steep Iceland stone and phi towers: that is the stuck, she wedges against faces the defaults refuse. And the attack reads dead in the hand for a plainer reason: Fire does its work invisibly, a trace and a damage call, no bolt, no flash, no answer in the world. This job seats both. One, it finds the Fire signature and inserts a lance bolt before the closing brace of the handler: a gold emissive bolt stretched from the view point to the hit point or the full range, plus an impact flash where it lands, both on a short lifespan, authored in the builder own MID pattern. Two, it maps Fire also to the pad X face button after the right trigger map line, because a runner attacks with the thumb that is already there. Three, after the constructor speed line it seats a walkable floor angle of 60 degrees and a step height of 90, so slopes and ledges stop holding her while flat ground proofs stand untouched. All three edits are count gated with the file backed up first; the regions verify by count; the build runs the standing way and its Result line rides the verdict. If a gate misses, SKIP prints and nothing builds. Every variable carries the av463 prefix.) ==='
$av463file = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$av463lines = @(Get-Content $av463file)
$av463fireIdx = @(); $av463mapIdx = @(); $av463speedIdx = @()
for ($av463i = 0; $av463i -lt $av463lines.Count; $av463i++) {
  if ($av463lines[$av463i] -match 'void AVEILCharacter::Fire\(\)') { $av463fireIdx += $av463i }
  if ($av463lines[$av463i] -match 'Map\(FireAction, EKeys::Gamepad_RightTrigger\)') { $av463mapIdx += $av463i }
  if ($av463lines[$av463i].Trim() -eq 'Move->MaxWalkSpeed = WalkSpeed;') { $av463speedIdx += $av463i }
}
Write-Output ('GATES fire=' + $av463fireIdx.Count + ' map=' + $av463mapIdx.Count + ' speed=' + $av463speedIdx.Count)
$av463go = ($av463fireIdx.Count -eq 1) -and ($av463mapIdx.Count -eq 1) -and ($av463speedIdx.Count -eq 1)
if (-not $av463go) { Write-Output 'PHI AV463 VERDICT: ATTACK SKIP gates closed'; Write-Output 'JOB 463 DONE'; return }
$av463close = -1
for ($av463c = $av463fireIdx[0] + 1; $av463c -lt $av463lines.Count; $av463c++) { if ($av463lines[$av463c] -eq '}') { $av463close = $av463c; break } }
if ($av463close -lt 0) { Write-Output 'PHI AV463 VERDICT: ATTACK SKIP no closing brace'; Write-Output 'JOB 463 DONE'; return }
Copy-Item $av463file ($av463file + '.phi-backup-463') -Force
$av463bolt = @(
"`t// PHI ATTACK VISIBLE: the shot answers in the world - a gold lance bolt",
"`t// from the view point to the hit point, and a flash where it lands.",
"`t{",
"`t`tconst FVector BoltEnd = Hit.bBlockingHit ? Hit.Location : End;",
"`t`tconst FVector BoltMid = (Start + BoltEnd) * 0.5f;",
"`t`tconst float BoltLen = (BoltEnd - Start).Size();",
"`t`tif (UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT(""/Engine/BasicShapes/Cube.Cube"")))",
"`t`t{",
"`t`t`tif (AStaticMeshActor* Bolt = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltMid, (BoltEnd - Start).Rotation()))",
"`t`t`t{",
"`t`t`t`tBolt->SetActorScale3D(FVector(BoltLen / 100.f, 0.06f, 0.06f));",
"`t`t`t`tBolt->SetLifeSpan(0.15f);",
"`t`t`t`tif (UStaticMeshComponent* BC = Bolt->GetStaticMeshComponent())",
"`t`t`t`t{",
"`t`t`t`t`tBC->SetStaticMesh(CubeMesh);",
"`t`t`t`t`tBC->SetCollisionEnabled(ECollisionEnabled::NoCollision);",
"`t`t`t`t`tif (UMaterialInterface* Base = BC->GetMaterial(0))",
"`t`t`t`t`t{",
"`t`t`t`t`t`tif (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, Bolt))",
"`t`t`t`t`t`t{",
"`t`t`t`t`t`t`tMID->SetVectorParameterValue(TEXT(""Colo\x72""), FLinearColor(1.f, 0.78f, 0.25f));",
"`t`t`t`t`t`t`tMID->SetVectorParameterValue(TEXT(""EmissiveColo\x72""), FLinearColor(1.f, 0.78f, 0.25f) * 3.f);",
"`t`t`t`t`t`t`tBC->SetMaterial(0, MID);",
"`t`t`t`t`t`t}",
"`t`t`t`t`t}",
"`t`t`t`t}",
"`t`t`t}",
"`t`t}",
"`t`tif (UStaticMesh* SphereMesh = LoadObject<UStaticMesh>(nullptr, TEXT(""/Engine/BasicShapes/Sphere.Sphere"")))",
"`t`t{",
"`t`t`tif (AStaticMeshActor* Flash = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltEnd, FRotator::ZeroRotator))",
"`t`t`t{",
"`t`t`t`tFlash->SetActorScale3D(FVector(0.3f, 0.3f, 0.3f));",
"`t`t`t`tFlash->SetLifeSpan(0.2f);",
"`t`t`t`tif (UStaticMeshComponent* FC = Flash->GetStaticMeshComponent())",
"`t`t`t`t{",
"`t`t`t`t`tFC->SetStaticMesh(SphereMesh);",
"`t`t`t`t`tFC->SetCollisionEnabled(ECollisionEnabled::NoCollision);",
"`t`t`t`t`tif (UMaterialInterface* Base2 = FC->GetMaterial(0))",
"`t`t`t`t`t{",
"`t`t`t`t`t`tif (UMaterialInstanceDynamic* MID2 = UMaterialInstanceDynamic::Create(Base2, Flash))",
"`t`t`t`t`t`t{",
"`t`t`t`t`t`t`tMID2->SetVectorParameterValue(TEXT(""Colo\x72""), FLinearColor(1.f, 0.85f, 0.4f));",
"`t`t`t`t`t`t`tMID2->SetVectorParameterValue(TEXT(""EmissiveColo\x72""), FLinearColor(1.f, 0.85f, 0.4f) * 4.f);",
"`t`t`t`t`t`t`tFC->SetMaterial(0, MID2);",
"`t`t`t`t`t`t}",
"`t`t`t`t`t}",
"`t`t`t`t}",
"`t`t`t}",
"`t`t}",
"`t}",
"`tUE_LOG(LogTemp, Display, TEXT(""PHI ATTACK FIRED len=%.0f hit=%d""), BoltLen, Hit.bBlockingHit ? 1 : 0);"
)
$av463new = @()
for ($av463j = 0; $av463j -lt $av463lines.Count; $av463j++) {
  if ($av463j -eq $av463close) { foreach ($av463b in $av463bolt) { $av463new += $av463b } }
  $av463new += $av463lines[$av463j]
  if ($av463j -eq $av463mapIdx[0]) { $av463new += "`t`tMap(FireAction, EKeys::Gamepad_FaceButton_Left);   // X" }
  if ($av463j -eq $av463speedIdx[0]) { $av463new += "`tMove->SetWalkableFloorAngle(60.f);"; $av463new += "`tMove->MaxStepHeight = 90.f;" }
}
Set-Content -Path $av463file -Value $av463new
$av463check = Get-Content $av463file -Raw
$av463c1 = ([regex]::Matches($av463check, 'PHI ATTACK FIRED')).Count
$av463c2 = ([regex]::Matches($av463check, 'Gamepad_FaceButton_Left')).Count
$av463c3 = ([regex]::Matches($av463check, 'SetWalkableFloorAngle')).Count
Write-Output ('VERIFY bolt=' + $av463c1 + ' xmap=' + $av463c2 + ' floor=' + $av463c3)
$av463buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$av463uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$av463log = 'D:\VEIL-OMNI\Saved\build463.log'
& $av463buildbat VEILEditor Win64 Development -Project="$av463uproj" -WaitMutex -NoHotReload *> "$av463log"
$av463result = @(Select-String -Path $av463log -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
foreach ($av463r in $av463result) { Write-Output ('BUILD ' + $av463r.Line.Trim()) }
Write-Output ('PHI AV463 VERDICT: ATTACK VISIBLE bolt=' + $av463c1 + ' xmap=' + $av463c2 + ' floor=' + $av463c3)
Write-Output 'JOB 463 DONE'
```
