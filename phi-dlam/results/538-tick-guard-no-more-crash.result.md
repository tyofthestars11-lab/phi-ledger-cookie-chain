# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 01:36:32 UTC

## STEP 1
```
=== JOB 538 - THE CRASH STEP GETS A GUARD (Ground: Tyree at his screen 2026-10-28 19:31 to 19:34 MDT, the crash reporter twice names the same place, AVEILCharacter Tick line 386 then line 388, access violation reading a null address, right after she runs. The movement step drives an animation seat, and when that seat is missing the step reads nothing and takes the game down. This job prints the Tick region whole, seats a guard in front of the drive so a missing mesh, a missing animation instance, or a missing single node seat stops that tick instead of crashing, skips any missing sequence on the SetAnimation call, keeps a backup, and rebuilds in the same job with its verdict read from the build log. Every variable carries the p538 prefix.) ===
TICK SPAN lines=203 first=335
TICKLINE 335 void AVEILCharacter::Tick(float DeltaSeconds)
TICKLINE 336 {
TICKLINE 337 	{
TICKLINE 338 		static float PadProofAcc = 0.f;
TICKLINE 339 		static int PadProofCount = 0;
TICKLINE 340 		PadProofAcc += DeltaSeconds;
TICKLINE 341 		if (PadProofAcc > 2.f && PadProofCount < 60)
TICKLINE 342 		{
TICKLINE 343 			PadProofAcc = 0.f; PadProofCount++;
TICKLINE 344 			if (APlayerController* PPC = Cast<APlayerController>(GetController()))
TICKLINE 345 			{
TICKLINE 346 				float LX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftX);
TICKLINE 347 				float LY = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftY);
TICKLINE 348 				float RX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_RightX);
TICKLINE 349 				int FA = PPC->IsInputKeyDown(EKeys::Gamepad_FaceButton_Bottom) ? 1 : 0;
TICKLINE 350 				int HasBuilt = -1; int HasDef = -1;
TICKLINE 351 				if (ULocalPlayer* LP = PPC->GetLocalPlayer()) { if (UEnhancedInputLocalPlayerSubsystem* ES = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) { HasBuilt = (BuiltMappingContext && ES->HasMappingContext(BuiltMappingContext)) ? 1 : 0; HasDef = (DefaultMappingContext && ES->HasMappingContext(DefaultMappingContext)) ? 1 : 0; } }
TICKLINE 352 				UE_LOG(LogTemp, Display, TEXT("PHI PAD PROOF: n=%d lx=%.2f ly=%.2f rx=%.2f faceA=%d hasBuilt=%d hasDef=%d"), PadProofCount, LX, LY, RX, FA, HasBuilt, HasDef);
TICKLINE 353 			}
TICKLINE 354 		}
TICKLINE 355 	}
TICKLINE 356 	Super::Tick(DeltaSeconds);
TICKLINE 357 
TICKLINE 358     // PHI LOCOMOTION 534: her own sequences, driven by her velocity - the glide ends here.
TICKLINE 359     {
TICKLINE 360         static UAnimSequence* PhiIdle534 = nullptr;
TICKLINE 361         static UAnimSequence* PhiJogF534 = nullptr;
TICKLINE 362         static UAnimSequence* PhiJogB534 = nullptr;
TICKLINE 363         static UAnimSequence* PhiJogL534 = nullptr;
TICKLINE 364         static UAnimSequence* PhiJogR534 = nullptr;
TICKLINE 365         static UAnimationAsset* PhiCur534 = nullptr;
TICKLINE 366         if (!PhiIdle534)
TICKLINE 367         {
TICKLINE 368             PhiIdle534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
TICKLINE 369             PhiJogF534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Fwd.Jog_Fwd"));
TICKLINE 370             PhiJogB534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Bwd.Jog_Bwd"));
TICKLINE 371             PhiJogL534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Left.Jog_Left"));
TICKLINE 372             PhiJogR534 = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Jog_Right.Jog_Right"));
TICKLINE 373         }
TICKLINE 374         const FVector PhiVel534 = GetVelocity();
TICKLINE 375         const float PhiFwd534 = FVector::DotProduct(PhiVel534, GetActorForwardVector());
TICKLINE 376         const float PhiRgt534 = FVector::DotProduct(PhiVel534, GetActorRightVector());
TICKLINE 377         const float PhiSpd534 = FVector(PhiVel534.X, PhiVel534.Y, 0.f).Size();
TICKLINE 378         UAnimSequence* PhiWant534 = PhiIdle534;
TICKLINE 379         if (PhiSpd534 > 30.f)
TICKLINE 380         {
TICKLINE 381             if (FMath::Abs(PhiFwd534) >= FMath::Abs(PhiRgt534)) { PhiWant534 = (PhiFwd534 >= 0.f) ? PhiJogF534 : PhiJogB534; }
TICKLINE 382             else { PhiWant534 = (PhiRgt534 >= 0.f) ? PhiJogR534 : PhiJogL534; }
TICKLINE 383             if (!PhiWant534) { PhiWant534 = PhiJogF534; }
TICKLINE 384         }
TICKLINE 385         if (PhiWant534 && PhiWant534 != PhiCur534)
TICKLINE 386         {
TICKLINE 387             GetMesh()->SetAnimation(PhiWant534);
TICKLINE 388             GetMesh()->Play(true);
TICKLINE 389             PhiCur534 = PhiWant534;
TICKLINE 390             UE_LOG(LogVEIL, Log, TEXT("PHI LOCOMOTION 534: %s"), *PhiWant534->GetName());
TICKLINE 391         }
TICKLINE 392         if (UAnimSingleNodeInstance* PhiInst534 = Cast<UAnimSingleNodeInstance>(GetMesh()->GetAnimInstance()))
TICKLINE 393         {
TICKLINE 394             PhiInst534->SetPlayRate(FMath::Clamp(PhiSpd534 / 400.f, 0.6f, 1.6f));
TICKLINE 395         }
TICKLINE 396     }
TICKLINE 397     {
TICKLINE 398         static int32 PhiTick365 = 0;
TICKLINE 399         PhiTick365++;
TICKLINE 400         if (PhiTick365 == 5 || PhiTick365 == 30 || PhiTick365 == 60 || PhiTick365 == 120)
TICKLINE 401         {
TICKLINE 402             const FVector CapW365 = GetCapsuleComponent()->GetComponentLocation();
TICKLINE 403             const FVector MeshW365 = GetMesh()->GetComponentLocation();
TICKLINE 404             const FRotator MeshR365 = GetMesh()->GetComponentRotation();
TICKLINE 405             const FFindFloorResult& Fl365 = GetCharacterMovement()->CurrentFloor;
TICKLINE 406         }
TICKLINE 407     }
TICKLINE 408 	// PHI CROSSING SAMPLER V2 (jobs 341/342): per-tick shape of the displacement from spawn, a column census at both redrop points, and a redrop onto the PHI_GROUND slab column whose top is z=0.
TICKLINE 409 	{
TICKLINE 410 		static float PhiC2Clock = 0.f;
TICKLINE 411 		static int32 PhiC2Tick = 0;
TICKLINE 412 		static int32 PhiC2Stage = 0;
TICKLINE 413 		static int32 PhiC2Window = 0;
TICKLINE 414 		static FVector PhiC2Spawn = FVector::ZeroVector;
TICKLINE 415 		PhiC2Clock += DeltaSeconds;
TICKLINE 416 		++PhiC2Tick;
TICKLINE 417 		auto PhiC2Line = [this](const TCHAR* Tag, float Dt) {
TICKLINE 418 			FFindFloorResult PhiF;
TICKLINE 419 			GetCharacterMovement()->FindFloor(GetActorLocation(), PhiF, false);
TICKLINE 420 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 %s: tick=%d dt=%.4f z=%.1f velZ=%.1f mode=%d findBlock=%d findWalk=%d floorDist=%.1f floorActor=%s curBlock=%d"), Tag, PhiC2Tick, Dt, GetActorLocation().Z, GetVelocity().Z, (int32)GetCharacterMovement()->MovementMode, PhiF.bBlockingHit ? 1 : 0, PhiF.bWalkableFloor ? 1 : 0, PhiF.FloorDist, PhiF.HitResult.GetActor() ? *PhiF.HitResult.GetActor()->GetName() : TEXT("none"), GetCharacterMovement()->CurrentFloor.bBlockingHit ? 1 : 0);
TICKLINE 421 		};
TICKLINE 422 		auto PhiC2Column = [this](float X, float Y) {
TICKLINE 423 			for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
TICKLINE 424 			{
TICKLINE 425 				FBox PhiB = It->GetComponentsBoundingBox(true);
TICKLINE 426 				if (X >= PhiB.Min.X && X <= PhiB.Max.X && Y >= PhiB.Min.Y && Y <= PhiB.Max.Y)
TICKLINE 427 				{
TICKLINE 428 					UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 COLUMN: x=%.0f y=%.0f actor=%s top=%.1f base=%.1f loc=%s"), X, Y, *It->GetName(), PhiB.Max.Z, PhiB.Min.Z, *It->GetActorLocation().ToString());
TICKLINE 429 				}
TICKLINE 430 			}
TICKLINE 431 		};
TICKLINE 432 		if (PhiC2Stage == 0)
TICKLINE 433 		{
TICKLINE 434 			PhiC2Spawn = GetActorLocation();
TICKLINE 435 			PhiC2Stage = 1;
TICKLINE 436 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 SPAWN: loc=%s"), *PhiC2Spawn.ToString());
TICKLINE 437 		}
TICKLINE 438 		if (PhiC2Stage == 1)
TICKLINE 439 		{
TICKLINE 440 			PhiC2Line(TEXT("TICK"), DeltaSeconds);
TICKLINE 441 			if (PhiC2Tick >= 90) { PhiC2Stage = 2; }
TICKLINE 442 		}
TICKLINE 443 		else if (PhiC2Stage == 2 && PhiC2Clock >= 8.f)
TICKLINE 444 		{
TICKLINE 445 			PhiC2Column(PhiC2Spawn.X, PhiC2Spawn.Y);
TICKLINE 446 			SetActorLocation(FVector(PhiC2Spawn.X, PhiC2Spawn.Y, 300.f));
TICKLINE 447 			GetCharacterMovement()->Velocity = FVector::ZeroVector;
TICKLINE 448 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 REDROP1: loc=%s"), *GetActorLocation().ToString());
TICKLINE 449 			PhiC2Window = 0;
TICKLINE 450 			PhiC2Stage = 3;
TICKLINE 451 		}
TICKLINE 452 		else if (PhiC2Stage == 3)
TICKLINE 453 		{
TICKLINE 454 			PhiC2Line(TEXT("DROP1"), DeltaSeconds);
TICKLINE 455 			if (++PhiC2Window >= 45) { PhiC2Stage = 4; }
TICKLINE 456 		}
TICKLINE 457 		else if (PhiC2Stage == 4 && PhiC2Clock >= 12.f)
TICKLINE 458 		{
TICKLINE 459 			PhiC2Column(128.f, -416.f);
TICKLINE 460 			SetActorLocation(FVector(128.f, -416.f, 300.f));
TICKLINE 461 			GetCharacterMovement()->Velocity = FVector::ZeroVector;
TICKLINE 462 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 REDROP2: loc=%s"), *GetActorLocation().ToString());
TICKLINE 463 			PhiC2Window = 0;
TICKLINE 464 			PhiC2Stage = 5;
TICKLINE 465 		}
TICKLINE 466 		else if (PhiC2Stage == 5)
TICKLINE 467 		{
TICKLINE 468 			PhiC2Line(TEXT("DROP2"), DeltaSeconds);
TICKLINE 469 			if (++PhiC2Window >= 45) { PhiC2Stage = 6; }
TICKLINE 470 		}
TICKLINE 471 	}
TICKLINE 472 
TICKLINE 473 
TICKLINE 474 
TICKLINE 475 	++PhiTickEntryCount;
TICKLINE 476 	// PHI MOVE TEST v3 - tick-driven, no timers. At t=5s of tick time it
TICKLINE 477 	// names the possession state, drives synthetic forward input for
TICKLINE 478 	// ~1.2s, then reports the velocity and displacement produced.
TICKLINE 479 	{
TICKLINE 480 		static int32 MovePhase = 0;
TICKLINE 481 		static float MoveClock = 0.f;
TICKLINE 482 		static FVector MoveSpawn = FVector::ZeroVector;
TICKLINE 483 		MoveClock += DeltaSeconds;
TICKLINE 484 		if (MovePhase == 0 && MoveClock >= 5.f)
TICKLINE 485 		{
TICKLINE 486 			MovePhase = 1;
TICKLINE 487 			MoveSpawn = GetActorLocation();
TICKLINE 488 			AController* C = GetController();
TICKLINE 489 			UE_LOG(LogVEIL, Log, TEXT("PHI MOVE TEST BEGIN: controller=%s pawn=%s locallyControlled=%d paused=%d velBefore=%.1f loc=%s"),
TICKLINE 490 				C ? *C->GetClass()->GetName() : TEXT("NONE"), *GetName(),
TICKLINE 491 				IsLocallyControlled() ? 1 : 0, UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0,
TICKLINE 492 				GetVelocity().Size(), *GetActorLocation().ToString());
TICKLINE 493 		}
TICKLINE 494 		else if (MovePhase == 1)
TICKLINE 495 		{
TICKLINE 496 			AddMovementInput(GetActorForwardVector(), 1.0f);
TICKLINE 497 			if (MoveClock >= 6.2f)
TICKLINE 498 			{
TICKLINE 499 				MovePhase = 2;
TICKLINE 500 				UE_LOG(LogVEIL, Log, TEXT("PHI MOVE TEST: velAfter=%.1f locAfter=%s moved=%.1f"),
TICKLINE 501 					GetVelocity().Size(), *GetActorLocation().ToString(),
TICKLINE 502 					FVector::Dist2D(GetActorLocation(), MoveSpawn));
TICKLINE 503 			}
TICKLINE 504 		}
TICKLINE 505 	}
TICKLINE 506 	{
TICKLINE 507 		static float ProofClock = 0.f;
TICKLINE 508 		static int64 ProofFrames = 0;
TICKLINE 509 		ProofClock += DeltaSeconds;
TICKLINE 510 		++ProofFrames;
TICKLINE 511 		if (ProofClock >= 5.f)
TICKLINE 512 		{
TICKLINE 513 			ProofClock = 0.f;
TICKLINE 514 		}
TICKLINE 515 	}
TICKLINE 516 	// One-shot animation proof: the anim instance is created after
TICKLINE 517 	// BeginPlay, so the first tick that sees it logs the live class.
TICKLINE 518 	static bool bAnimProofLogged = false;
TICKLINE 519 	if (!bAnimProofLogged && GetMesh()->GetAnimInstance())
TICKLINE 520 	{
TICKLINE 521 		bAnimProofLogged = true;
TICKLINE 522 		UE_LOG(LogVEIL, Log, TEXT("PHI BODY ANIM LIVE: %s"), *GetMesh()->GetAnimInstance()->GetClass()->GetName());
TICKLINE 523 	static float AnimDiagTimer = 0.f;
TICKLINE 524 	if (!bAnimProofLogged)
TICKLINE 525 	{
TICKLINE 526 		AnimDiagTimer += DeltaSeconds;
TICKLINE 527 		if (AnimDiagTimer > 5.f)
TICKLINE 528 		{
TICKLINE 529 			bAnimProofLogged = true;
TICKLINE 530 			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY ANIM DIAG: instance=none class=%s skeleton=%s"),
TICKLINE 531 				GetMesh()->GetAnimClass() ? *GetMesh()->GetAnimClass()->GetName() : TEXT("none"),
TICKLINE 532 				(GetMesh()->GetSkeletalMeshAsset() && GetMesh()->GetSkeletalMeshAsset()->GetSkeleton())
TICKLINE 533 					? *GetMesh()->GetSkeletalMeshAsset()->GetSkeleton()->GetName() : TEXT("none"));
TICKLINE 534 		}
TICKLINE 535 	}
TICKLINE 536 	}
TICKLINE 537 }
CAST GUARD SEATED var=PhiInst534
SETANIM GUARDS=0
PATCH OK - TICK GUARD 538 SEATED

BUILD Result: Failed (OtherCompilationError)
PHI P538 VERDICT: PATCH AND BUILD LINES ABOVE - THE NEXT LAUNCH READS THE GUARD
JOB 538 DONE

```
