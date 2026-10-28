# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 23:48:51 UTC

## STEP 1
```
=== JOB 526 - THE INPUT SEAT READ WHOLE (Ground: his hands report the game as it plays now: the sticks move her, A jumps, L2 pushes her forward which is a binding standing in the wrong place, and attack does not exist under his hands at all - no swing, no lance. The character source holds every binding as it stands after the legacy road was seated beside the enhanced one. This job prints the binding lines and the attack lines from the character source and header, numbered, so the fix authors against the true map: what L2 is actually bound to, whether the attack handlers exist, and which road they hang from. Every variable carries the p526 prefix.) ===
FILE D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp
LINES=726
B526 17: #include "EnhancedInputComponent.h"
B526 22: #include "InputAction.h"
B526 23: #include "InputActionValue.h"
B526 44: Move->JumpZVelocity = 620.f;
B526 203: auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
B526 205: UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
B526 211: MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
B526 212: LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
B526 213: JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
B526 214: SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
B526 215: DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
B526 216: AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
B526 217: FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
B526 218: InteractAction = MakeAction(TEXT("IA_Interact"), EInputActionValueType::Boolean);
B526 223: auto Map = [IMC, this](UInputAction* Action, const FKey Key,
B526 245: Map(JumpAction, EKeys::SpaceBar);
B526 253: Map(MoveAction, EKeys::Gamepad_Left2D);
B526 254: Map(LookAction, EKeys::Gamepad_Right2D);
B526 255: Map(JumpAction, EKeys::Gamepad_FaceButton_Bottom);  // A
B526 256: Map(DodgeAction, EKeys::Gamepad_FaceButton_Right);  // B
B526 257: Map(InteractAction, EKeys::Gamepad_FaceButton_Left);// X
B526 258: Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
B526 259: Map(FireAction, EKeys::Gamepad_FaceButton_Top);   // Y
B526 260: Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
B526 261: Map(SprintAction, EKeys::Gamepad_LeftThumbstick);   // L3
B526 281: void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
B526 283: Super::SetupPlayerInputComponent(PlayerInputComponent);
B526 285: // PHI 442: possession runs before BeginPlay, so the binds below read
B526 287: // every bind. Build the standing fallback here, at the bind itself.
B526 294: PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
B526 295: PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
B526 296: PlayerInputComponent->BindAxisKey(EKeys::Gamepad_LeftY, this, &AVEILCharacter::PhiPadMoveFwd);
B526 297: PlayerInputComponent->BindAxisKey(EKeys::Gamepad_LeftX, this, &AVEILCharacter::PhiPadMoveRight);
B526 298: PlayerInputComponent->BindAxisKey(EKeys::Gamepad_RightX, this, &AVEILCharacter::PhiPadLookYaw);
B526 299: PlayerInputComponent->BindAxisKey(EKeys::Gamepad_RightY, this, &AVEILCharacter::PhiPadLookPitch);
B526 300: PlayerInputComponent->BindKey(EKeys::Gamepad_FaceButton_Bottom, IE_Pressed, this, &ACharacter::Jump);
B526 301: PlayerInputComponent->BindKey(EKeys::Gamepad_FaceButton_Bottom, IE_Released, this, &ACharacter::StopJumping);
B526 303: if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
B526 305: if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
B526 306: if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
B526 307: if (JumpAction)
B526 309: EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
B526 310: EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
B526 314: EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
B526 315: EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
B526 317: if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
B526 320: EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
B526 321: EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
B526 323: if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
B526 324: if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
B526 339: float LX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftX);
B526 340: float LY = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftY);
B526 341: float RX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_RightX);
B526 342: int FA = PPC->IsInputKeyDown(EKeys::Gamepad_FaceButton_Bottom) ? 1 : 0;
B526 492: void AVEILCharacter::Move(const FInputActionValue& Value)
B526 503: void AVEILCharacter::Look(const FInputActionValue& Value)
B526 584: // PHI ATTACK VISIBLE: the shot answers in the world - a gold lance bolt
B526 635: UE_LOG(LogTemp, Display, TEXT("PHI ATTACK FIRED hit=%d"), Hit.bBlockingHit ? 1 : 0);
B526 709: void AVEILCharacter::PhiPadMoveRight(float Value)
FILE D:\VEIL-OMNI\Source\VEIL\Public\Character\VEILCharacter.h
LINES=179
B526 2: // Third-person movement, sprint, jump, dodge, aim + hitscan fire, health,
B526 14: class UInputAction;
B526 15: struct FInputActionValue;
B526 41: virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
B526 118: TObjectPtr<UInputAction> MoveAction;
B526 121: TObjectPtr<UInputAction> LookAction;
B526 124: TObjectPtr<UInputAction> JumpAction;
B526 127: TObjectPtr<UInputAction> SprintAction;
B526 130: TObjectPtr<UInputAction> DodgeAction;
B526 133: TObjectPtr<UInputAction> AimAction;
B526 136: TObjectPtr<UInputAction> FireAction;
B526 139: TObjectPtr<UInputAction> InteractAction;
B526 142: void Move(const FInputActionValue& Value);
B526 143: void Look(const FInputActionValue& Value);
B526 145: void PhiPadMoveRight(float Value);
B526 166: TArray<TObjectPtr<UInputAction>> BuiltActions;
PHI P526 VERDICT: INPUT SEAT PRINTED ABOVE
JOB 526 DONE

```
