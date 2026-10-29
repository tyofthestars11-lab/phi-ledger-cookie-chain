# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 15:18:28 UTC

## STEP 1
```
=== JOB 567 - VEIL TICK 394 REGION READ (Ground: Job 564 named the crash as AVEILCharacter Tick at line 394 with an access violation at address zero, so this job prints the Tick region around line 394 and the guard lines above it, no patch, no build. Every variable carries the p567 prefix.) ===
SOURCE LINES 780
TICK LINE 370 static UAnimationAsset* PhiCur534 = nullptr;
TICK LINE 371 if (!PhiIdle534)
TICK LINE 372 {
TICK LINE 373 PhiIdle534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
TICK LINE 374 PhiJogF534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Fwd.Jog_Fwd"));
TICK LINE 375 PhiJogB534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Bwd.Jog_Bwd"));
TICK LINE 376 PhiJogL534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Left.Jog_Left"));
TICK LINE 377 PhiJogR534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Right.Jog_Right"));
TICK LINE 378 }
TICK LINE 379 const FVector PhiVel534 = GetVelocity();
TICK LINE 380 const float PhiFwd534 = FVector::DotProduct(PhiVel534, GetActorForwardVector());
TICK LINE 381 const float PhiRgt534 = FVector::DotProduct(PhiVel534, GetActorRightVector());
TICK LINE 382 const float PhiSpd534 = FVector(PhiVel534.X, PhiVel534.Y, 0.f).Size();
TICK LINE 383 UAnimSequence* PhiWant534 = PhiIdle534;
TICK LINE 384 if (PhiSpd534 > 30.f)
TICK LINE 385 {
TICK LINE 386 if (FMath::Abs(PhiFwd534) >= FMath::Abs(PhiRgt534)) { PhiWant534 = (PhiFwd534 >= 0.f) ? PhiJogF534 : PhiJogB534; }
TICK LINE 387 else { PhiWant534 = (PhiRgt534 >= 0.f) ? PhiJogR534 : PhiJogL534; }
TICK LINE 388 if (!PhiWant534) { PhiWant534 = PhiJogF534; }
TICK LINE 389 }
TICK LINE 390 if (Cast<UAnimSingleNodeInstance>(GetMesh()->GetAnimInstance()) == nullptr) { GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode); }
TICK LINE 391 if (PhiWant534 && PhiWant534 != PhiCur534 && Cast<UAnimSingleNodeInstance>(GetMesh()->GetAnimInstance()) != nullptr)
TICK LINE 392 {
TICK LINE 393 GetMesh()->SetAnimation(PhiWant534);
TICK LINE 394 GetMesh()->Play(true);
TICK LINE 395 PhiCur534 = PhiWant534;
TICK LINE 396 UE_LOG(LogVEIL, Log, TEXT("PHI LOCOMOTION 534: %s"), *PhiWant534->GetName());
TICK LINE 397 }
TICK LINE 398 if (UAnimSingleNodeInstance* PhiInst534 = Cast<UAnimSingleNodeInstance>(GetMesh()->GetAnimInstance()))
TICK LINE 399 {
TICK LINE 400 PhiInst534->SetPlayRate(FMath::Clamp(PhiSpd534 / 400.f, 0.6f, 1.6f));
TICK LINE 401 }
TICK LINE 402 }
TICK LINE 403 {
TICK LINE 404 static int32 PhiTick365 = 0;
TICK LINE 405 PhiTick365++;
TICK LINE 406 if (PhiTick365 == 5 || PhiTick365 == 30 || PhiTick365 == 60 || PhiTick365 == 120)
TICK LINE 407 {
TICK LINE 408 const FVector CapW365 = GetCapsuleComponent()->GetComponentLocation();
TICK LINE 409 const FVector MeshW365 = GetMesh()->GetComponentLocation();
TICK LINE 410 const FRotator MeshR365 = GetMesh()->GetComponentRotation();
TICK HEAD void AVEILCharacter::Tick(float DeltaSeconds)
PHI P567 VERDICT: VEIL TICK 394 REGION READ ABOVE
JOB 567 DONE

```
