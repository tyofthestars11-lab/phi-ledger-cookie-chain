# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 18:34:53 UTC

## STEP 1
```
=== COMBAT AND STUCK READ 457 - THE VERB TABLE AND THE FLOOR, READ AT THE TRUE ADDRESS BEFORE THE FIX (Ground from Tyree hands in PIE, 2026-10-28: she renders in color, armor and blades, and his verdicts stand whole: she gets stuck in the terrain whenever he loads, he cannot attack, all he can do is move and jump, and sprint on L3 works and is good. So the verb table is partly alive: Move, Look, Jump, Sprint answer; Fire and the rest do not. Job 454 read the builder whole at the true address, Private Character VEILCharacter cpp is 22036 bytes at the same layout, and every fix in this lane authors from printed ground. This job prints five sections. One, every input bind line in the character cpp, capped at 40, so which actions bind where stands named. Two, every handler function signature in the character cpp, capped at 40, the whole verb table at a glance. Three, the Fire and Attack handler bodies whole, capped at 60 lines, plus the lines where the fallback builder maps the Fire and Aim keys, capped at 30. Four, the movement ground: every line naming MaxWalkSpeed, slope, WalkableFloor, CapsuleRadius, CapsuleHalfHeight and StepHeight across the character and the GameMode, capped at 30, because a runner who sticks in terrain is a slope, step or capsule address until the print says otherwise. Five, the spawn ground: the PlayerStart and spawn lines in the GameMode, capped at 20, because stuck whenever I load begins at the spawn. The verdict in one line: COMBAT STUCK READ with the bind count and the fire handler found state. This job is read only and every variable carries the cs457 prefix.) ===
BIND 263 PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
BIND 264 PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
BIND 268 if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
BIND 269 if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
BIND 272 EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
BIND 273 EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
BIND 277 EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
BIND 278 EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
BIND 280 if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
BIND 283 EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
BIND 284 EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
BIND 286 if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
BIND 287 if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
FUNC 466 void AVEILCharacter::StartSprint() { bSprinting = true; ApplySpeed(); }
FUNC 467 void AVEILCharacter::StopSprint()  { bSprinting = false; ApplySpeed(); }
FUNC 469 void AVEILCharacter::StartAim()
FUNC 476 void AVEILCharacter::StopAim()
FUNC 483 void AVEILCharacter::DoDodge()
FIRE 505 void AVEILCharacter::Fire()
FIRE 506 {
FIRE 507 	const float Now = GetWorld()->TimeSeconds;
FIRE 508 	if (!IsAlive() || Now - LastFireTime < FireCooldown) return;
FIRE 509 	LastFireTime = Now;
FIRE 510 
FIRE 511 	FVector Start;
FIRE 512 	FRotator ViewRot;
FIRE 513 	if (Controller) Controller->GetPlayerViewPoint(Start, ViewRot);
FIRE 514 	else { Start = GetActorLocation(); ViewRot = GetActorRotation(); }
FIRE 515 
FIRE 516 	const FVector End = Start + ViewRot.Vector() * WeaponRange;
FIRE 517 	FHitResult Hit;
FIRE 518 	FCollisionQueryParams Params;
FIRE 519 	Params.AddIgnoredActor(this);
FIRE 520 
FIRE 521 	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
FIRE 522 	{
FIRE 523 		if (AActor* Victim = Hit.GetActor())
FIRE 524 		{
FIRE 525 			UGameplayStatics::ApplyDamage(Victim, WeaponDamage, Controller, this, UDamageType::StaticClass());
FIRE 526 		}
FIRE 527 	}
FIRE 528 }
FIRE 529 
FIRE 530 void AVEILCharacter::Interact()
FIRE 531 {
FIRE 532 	if (!IsAlive()) return;
FIRE 533 	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 60.f);
FIRE 534 	const FVector End = Start + GetActorForwardVector() * 320.f;
FIRE 535 	FHitResult Hit;
FIRE 536 	FCollisionQueryParams Params;
FIRE 537 	Params.AddIgnoredActor(this);
FIRE 538 
FIRE 539 	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
FIRE 540 	{
FIRE 541 		if (AVEILInteractable* Target = Cast<AVEILInteractable>(Hit.GetActor()))
FIRE 542 		{
FIRE 543 			Target->Interact(this);
FIRE 544 		}
FIRE 545 	}
FIRE 546 }
FIRE 547 
FIRE 548 void AVEILCharacter::ToggleGodMode()
FIRE 549 {
FIRE 550 	bGodMode = !bGodMode;
FIRE 551 	UE_LOG(LogVEIL, Warning, TEXT("PHI GODMODE: %s"), bGodMode ? TEXT("ON") : TEXT("OFF"));
FIRE 552 }
FIRE 553 
FIRE 554 float AVEILCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
FIRE 555 	AController* EventInstigator, AActor* DamageCauser)
FIRE 556 {
FIRE 557 	if (bGodMode) return 0.f;
FIRE 558 	if (!IsAlive()) return 0.f;
FIRE 559 	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
FIRE 560 	Health = FMath::Clamp(Health - Applied, 0.f, MaxHealth);
FIRE 561 	OnHealthChanged.Broadcast(Health, MaxHealth);
FIRE 562 	if (Health <= 0.f)
FIRE 563 	{
FIRE 564 		CombatState = EVEILCombatState::Dead;
FA 199 AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
FA 200 FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
FA 231 Map(AimAction, EKeys::RightMouseButton);
FA 232 Map(FireAction, EKeys::LeftMouseButton);
FA 241 Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
FA 242 Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
FA 281 if (AimAction)
FA 283 EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
FA 284 EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
FA 286 if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
FA 457 if (bAiming)        Move->MaxWalkSpeed = AimWalkSpeed;
FA 461 // Aiming locks facing to the camera; exploring lets movement orient the body.
FA 462 Move->bOrientRotationToMovement = !bAiming;
FA 463 bUseControllerRotationYaw = bAiming;
FA 469 void AVEILCharacter::StartAim()
FA 471 bAiming = true;
FA 472 CombatState = EVEILCombatState::Aiming;
FA 476 void AVEILCharacter::StopAim()
FA 478 bAiming = false;
FA 479 if (CombatState == EVEILCombatState::Aiming) CombatState = EVEILCombatState::Exploring;
FA 500 CombatState = bAiming ? EVEILCombatState::Aiming : EVEILCombatState::Exploring;
FA 505 void AVEILCharacter::Fire()
FA 508 if (!IsAlive() || Now - LastFireTime < FireCooldown) return;
FA 509 LastFireTime = Now;
MOVE 45 Move->MaxWalkSpeed = WalkSpeed;
MOVE 317 UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 %s: tick=%d dt=%.4f z=%.1f velZ=%.1f mode=%d findBlock=%d findWalk=%d floorDist=%.1f floorActor=%s curBlock=%d"), Tag, PhiC2Tick, Dt, GetActorLocation().Z, GetVelocity().Z, (int32)GetCharacterMovement()->MovementMode, PhiF.bBlockingHit ? 1 : 0, PhiF.bWalkableFloor ? 1 : 0, PhiF.FloorDist, PhiF.HitResult.GetActor() ? *PhiF.HitResult.GetActor()->GetName() : TEXT("none"), GetCharacterMovement()->CurrentFloor.bBlockingHit ? 1 : 0);
MOVE 457 if (bAiming)        Move->MaxWalkSpeed = AimWalkSpeed;
MOVE 458 else if (bSprinting) Move->MaxWalkSpeed = SprintSpeed;
MOVE 459 else                 Move->MaxWalkSpeed = WalkSpeed;
PHI CS457 VERDICT: COMBAT STUCK READ binds=13 fire_found=1
JOB 457 DONE

```
