# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 06:50:20 UTC

## STEP 1
```
=== CHARACTER SOURCE WHOLE + MOVEMENT GREP - BOTH PROJECTS, READ-ONLY (Jobs 334+335 printed the identical signature in both packages: capsule capEnabled=3 QueryAndPhysics, capProfile=Pawn, moveMode=3 Falling, onGround=0, floorBlock=0, floorActor=none at every fire; a WorldStatic line trace in the pawn column HITS geometry with top at exactly z=0.0 - VEIL StaticMeshActor_3 hitZ=0.0, OMNI StaticMeshActor_231 hitZ=0.0; and the pawn is already below Z=-50000 at the first diagnostic fire, below -12300 at move-test begin in every proof ever run, at terminal velocity 4000.0. The crossing of z=0 has never been observed by any instrument: from PlayerStart z=120 the arithmetic of an uninterrupted fall reaches -12317 at about 5.15 s, crossing z=0 at about 0.49 s at about 485 u/s, about 4 units per tick at the proofs 120 fps - a swept QueryAndPhysics Pawn capsule registers a BlockAll surface crossed at that speed in every stock project, and every census reads stock shapes with stock settings on both sides. What has never been read whole is the Character source itself: job 324 printed the constructors (clean), job 331 part 1 errored before printing the instrument files, and the MOVE TEST lives in the Character Tick whose full body no result has ever carried. THIS JOB prints, in one pass: (1) every Character .cpp/.h file in both projects, full text; (2) a Source-wide grep of both projects for every movement-affecting call - SetActorLocation, SetActorTransform, Teleport, SetMovementMode, GravityScale, MaxFallSpeed, TerminalVelocity, SetCollisionEnabled, SetCollisionResponse, IgnoreActorWhenMoving, AddActorWorldOffset, SetUpdatedComponent, LaunchCharacter, SetPhysicsLinearVelocity, MOVE_Falling, MOVE_Walking - with file, line number, and line text. READ-ONLY: nothing is written, nothing is cooked.) ===
##### VEIL CHARACTER FILES #####
----- FILE: D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp (18954 bytes) -----
// VEIL: THE LAST SIGNAL - player character implementation.
#include "Character/VEILCharacter.h"
#include "Animation/AnimSequence.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputCoreTypes.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "Kismet/GameplayStatics.h"
#include "Systems/VEILDiscoverySystem.h"
#include "VEIL.h"

AVEILCharacter::AVEILCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* Move = GetCharacterMovement();
	Move->bOrientRotationToMovement = true;
	Move->RotationRate = FRotator(0.f, 540.f, 0.f);
	Move->JumpZVelocity = 620.f;
	Move->AirControl = 0.35f;
	Move->MaxWalkSpeed = WalkSpeed;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 420.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// The runner's visible body, built from engine shapes - no mesh assets
	// ship with the project, and an invisible pawn is not a character.
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(
			TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
			TEXT("/Engine/BasicShapes/Cube.Cube"));

		UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerBody"));
		Body->SetupAttachment(GetCapsuleComponent());
		Body->SetRelativeLocation(FVector(0.f, 0.f, -15.f));
		Body->SetRelativeScale3D(FVector(0.62f, 0.62f, 1.5f));
		Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		RunnerBody = Body;
		if (CylinderMesh.Succeeded()) Body->SetStaticMesh(CylinderMesh.Object);
		if (UMaterialInterface* Base = Body->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.08f, 0.08f, 0.12f));
				MID->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(0.08f, 0.08f, 0.12f));
				Body->SetMaterial(0, MID);
			}
		}

		UStaticMeshComponent* Visor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerVisor"));
		Visor->SetupAttachment(GetCapsuleComponent());
		Visor->SetRelativeLocation(FVector(20.f, 0.f, 58.f));
		Visor->SetRelativeScale3D(FVector(0.10f, 0.46f, 0.12f));
		Visor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		RunnerVisor = Visor;
		if (CubeMesh.Succeeded()) Visor->SetStaticMesh(CubeMesh.Object);
		if (UMaterialInterface* Base = Visor->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.78f, 0.30f));
				MID->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor(1.f, 0.78f, 0.30f) * 3.f);
				Visor->SetMaterial(0, MID);
			}
		}
	}

	// The real body (job 089 landed the Mannequins tree in Content):
	// The Countess: mesh, skeleton and AnimBlueprint all resolve in
	// the ParagonCountess tree (job 116's triangle). Manny's mesh never
	// carried a skeleton in this seat; the Countess closes the triangle.
	// verbatim from the on-disk inventory. If either fails to load,
	// the primitive runner above stays visible and the log says so -
	// an invisible pawn is not a character.
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MannyMesh(
			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
		static ConstructorHelpers::FObjectFinder<UAnimSequence> MannyAnim(
			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
		if (MannyMesh.Succeeded())
		{
			GetMesh()->SetSkeletalMeshAsset(MannyMesh.Object);
			GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
			GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
			if (MannyAnim.Succeeded())
			{
				GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			}
			else
			{
				UE_LOG(LogVEIL, Warning, TEXT("PHI BODY: Countess pose sequence not found - mesh set, animation unassigned."));
			}
			if (RunnerBody) RunnerBody->SetVisibility(false);
			if (RunnerVisor) RunnerVisor->SetVisibility(false);
			UE_LOG(LogVEIL, Log, TEXT("PHI BODY: Countess skeletal mesh is the runner's body."));
		}
		else
		{
			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY FALLBACK: SM_Countess not found - primitive runner body stands."));
		}
	}

	Health = MaxHealth;
}

void AVEILCharacter::BeginPlay()
{
	Super::BeginPlay();
	// The anim class is set in the constructor AND here: if the
	// component's initialization overwrote the constructor's
	// assignment, this one - after registration - is the one
	// that lives. The Tick one-shots report which state won.
	{
		if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
		{
			GetMesh()->PlayAnimation(PoseSeq, true);
		}
	}
	UE_LOG(LogVEIL, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
	// PHI MOVE TEST v3 lives in Tick (tick-driven state machine -
	// timers never reported in the -game smokes, so the test rides
	// the frame itself).
	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health, MaxHealth);

	if (!DefaultMappingContext)
	{
		BuildFallbackInput();
	}

	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Sub =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Sub->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AVEILCharacter::BuildFallbackInput()
{
	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
	// Used only when no editor-made Input assets are assigned.
	auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
	{
		UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
		Action->ValueType = Type;
		BuiltActions.Add(Action);
		return Action;
	};

	MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
	LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
	JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
	SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
	DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
	AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
	FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
	InteractAction = MakeAction(TEXT("IA_Interact"), EInputActionValueType::Boolean);

	BuiltMappingContext = NewObject<UInputMappingContext>(this, TEXT("IMC_VEIL_BuiltIn"), RF_Transient);
	UInputMappingContext* IMC = BuiltMappingContext;

	auto Map = [IMC, this](UInputAction* Action, const FKey Key,
		bool bNegate = false, bool bSwizzle = false)
	{
		FEnhancedActionKeyMapping& Mapping = IMC->MapKey(Action, Key);
		if (bSwizzle)
		{
			UInputModifierSwizzleAxis* Swizzle = NewObject<UInputModifierSwizzleAxis>(this);
			Swizzle->Order = EInputAxisSwizzle::YXZ;
			Mapping.Modifiers.Add(Swizzle);
		}
		if (bNegate)
		{
			Mapping.Modifiers.Add(NewObject<UInputModifierNegate>(this));
		}
	};

	// ---- Keyboard + mouse ----
	Map(MoveAction, EKeys::W, false, true);
	Map(MoveAction, EKeys::S, true, true);
	Map(MoveAction, EKeys::A, true, false);
	Map(MoveAction, EKeys::D, false, false);
	Map(LookAction, EKeys::Mouse2D);
	Map(JumpAction, EKeys::SpaceBar);
	Map(SprintAction, EKeys::LeftShift);
	Map(DodgeAction, EKeys::LeftAlt);
	Map(AimAction, EKeys::RightMouseButton);
	Map(FireAction, EKeys::LeftMouseButton);
	Map(InteractAction, EKeys::E);

	// ---- Xbox controller ----
	Map(MoveAction, EKeys::Gamepad_Left2D);
	Map(LookAction, EKeys::Gamepad_Right2D);
	Map(JumpAction, EKeys::Gamepad_FaceButton_Bottom);  // A
	Map(DodgeAction, EKeys::Gamepad_FaceButton_Right);  // B
	Map(InteractAction, EKeys::Gamepad_FaceButton_Left);// X
	Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
	Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
	Map(SprintAction, EKeys::Gamepad_LeftThumbstick);   // L3
	// Pause/menu lives on the PlayerController: P, Esc, and pad Menu button.

	DefaultMappingContext = BuiltMappingContext;
	UE_LOG(LogVEIL, Log, TEXT("VEIL input: built-in map active (keyboard/mouse + Xbox controller)."));
}

void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 1st/3rd person toggle: V on keyboard, right-stick click (R3) on the pad.
	PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
	PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
		if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
		if (JumpAction)
		{
			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		}
		if (SprintAction)
		{
			EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
		}
		if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
		if (AimAction)
		{
			EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
			EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
		}
		if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
		if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
	}
}

void AVEILCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	++PhiTickEntryCount;
	// PHI MOVE TEST v3 - tick-driven, no timers. At t=5s of tick time it
	// names the possession state, drives synthetic forward input for
	// ~1.2s, then reports the velocity and displacement produced.
	{
		static int32 MovePhase = 0;
		static float MoveClock = 0.f;
		static FVector MoveSpawn = FVector::ZeroVector;
		MoveClock += DeltaSeconds;
		if (MovePhase == 0 && MoveClock >= 5.f)
		{
			MovePhase = 1;
			MoveSpawn = GetActorLocation();
			AController* C = GetController();
			UE_LOG(LogVEIL, Log, TEXT("PHI MOVE TEST BEGIN: controller=%s pawn=%s locallyControlled=%d paused=%d velBefore=%.1f loc=%s"),
				C ? *C->GetClass()->GetName() : TEXT("NONE"), *GetName(),
				IsLocallyControlled() ? 1 : 0, UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0,
				GetVelocity().Size(), *GetActorLocation().ToString());
		}
		else if (MovePhase == 1)
		{
			AddMovementInput(GetActorForwardVector(), 1.0f);
			if (MoveClock >= 6.2f)
			{
				MovePhase = 2;
				UE_LOG(LogVEIL, Log, TEXT("PHI MOVE TEST: velAfter=%.1f locAfter=%s moved=%.1f"),
					GetVelocity().Size(), *GetActorLocation().ToString(),
					FVector::Dist2D(GetActorLocation(), MoveSpawn));
			}
		}
	}
	// PHI TICKPROOF: every ~5s of tick time the game states it is turning.
	{
		static float ProofClock = 0.f;
		static int64 ProofFrames = 0;
		ProofClock += DeltaSeconds;
		++ProofFrames;
		if (ProofClock >= 5.f)
		{
			ProofClock = 0.f;
			UE_LOG(LogVEIL, Log, TEXT("PHI TICKPROOF: frames=%lld worldTime=%.1f paused=%d"),
				ProofFrames, GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
		}
	}
	// One-shot animation proof: the anim instance is created after
	// BeginPlay, so the first tick that sees it logs the live class.
	static bool bAnimProofLogged = false;
	if (!bAnimProofLogged && GetMesh()->GetAnimInstance())
	{
		bAnimProofLogged = true;
		UE_LOG(LogVEIL, Log, TEXT("PHI BODY ANIM LIVE: %s"), *GetMesh()->GetAnimInstance()->GetClass()->GetName());
	static float AnimDiagTimer = 0.f;
	if (!bAnimProofLogged)
	{
		AnimDiagTimer += DeltaSeconds;
		if (AnimDiagTimer > 5.f)
		{
			bAnimProofLogged = true;
			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY ANIM DIAG: instance=none class=%s skeleton=%s"),
				GetMesh()->GetAnimClass() ? *GetMesh()->GetAnimClass()->GetName() : TEXT("none"),
				(GetMesh()->GetSkeletalMeshAsset() && GetMesh()->GetSkeletalMeshAsset()->GetSkeleton())
					? *GetMesh()->GetSkeletalMeshAsset()->GetSkeleton()->GetName() : TEXT("none"));
		}
	}
	}
}

void AVEILCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller || !IsAlive()) return;
	const FVector2D Axis = Value.Get<FVector2D>();
	const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
	AddMovementInput(Forward, Axis.Y);
	AddMovementInput(Right, Axis.X);
}

void AVEILCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(Axis.Y);
}

void AVEILCharacter::ApplySpeed()
{
	UCharacterMovementComponent* Move = GetCharacterMovement();
	if (bAiming)        Move->MaxWalkSpeed = AimWalkSpeed;
	else if (bSprinting) Move->MaxWalkSpeed = SprintSpeed;
	else                 Move->MaxWalkSpeed = WalkSpeed;

	// Aiming locks facing to the camera; exploring lets movement orient the body.
	Move->bOrientRotationToMovement = !bAiming;
	bUseControllerRotationYaw = bAiming;
}

void AVEILCharacter::StartSprint() { bSprinting = true; ApplySpeed(); }
void AVEILCharacter::StopSprint()  { bSprinting = false; ApplySpeed(); }

void AVEILCharacter::StartAim()
{
	bAiming = true;
	CombatState = EVEILCombatState::Aiming;
	ApplySpeed();
}

void AVEILCharacter::StopAim()
{
	bAiming = false;
	if (CombatState == EVEILCombatState::Aiming) CombatState = EVEILCombatState::Exploring;
	ApplySpeed();
}

void AVEILCharacter::DoDodge()
{
	const float Now = GetWorld()->TimeSeconds;
	if (!IsAlive() || Now - LastDodgeTime < DodgeCooldown) return;
	LastDodgeTime = Now;
	CombatState = EVEILCombatState::Dodging;

	FVector Dir = GetLastMovementInputVector();
	if (Dir.IsNearlyZero()) Dir = -GetActorForwardVector();
	Dir.Z = 0.f; Dir.Normalize();
	LaunchCharacter(Dir * DodgeDistance + FVector(0.f, 0.f, 120.f), true, false);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, [this]()
	{
		if (CombatState == EVEILCombatState::Dodging)
		{
			CombatState = bAiming ? EVEILCombatState::Aiming : EVEILCombatState::Exploring;
		}
	}, 0.35f, false);
}

void AVEILCharacter::Fire()
{
	const float Now = GetWorld()->TimeSeconds;
	if (!IsAlive() || Now - LastFireTime < FireCooldown) return;
	LastFireTime = Now;

	FVector Start;
	FRotator ViewRot;
	if (Controller) Controller->GetPlayerViewPoint(Start, ViewRot);
	else { Start = GetActorLocation(); ViewRot = GetActorRotation(); }

	const FVector End = Start + ViewRot.Vector() * WeaponRange;
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AActor* Victim = Hit.GetActor())
		{
			UGameplayStatics::ApplyDamage(Victim, WeaponDamage, Controller, this, UDamageType::StaticClass());
		}
	}
}

void AVEILCharacter::Interact()
{
	if (!IsAlive()) return;
	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const FVector End = Start + GetActorForwardVector() * 320.f;
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AVEILInteractable* Target = Cast<AVEILInteractable>(Hit.GetActor()))
		{
			Target->Interact(this);
		}
	}
}

void AVEILCharacter::ToggleGodMode()
{
	bGodMode = !bGodMode;
	UE_LOG(LogVEIL, Warning, TEXT("PHI GODMODE: %s"), bGodMode ? TEXT("ON") : TEXT("OFF"));
}

float AVEILCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (bGodMode) return 0.f;
	if (!IsAlive()) return 0.f;
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health = FMath::Clamp(Health - Applied, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(Health, MaxHealth);
	if (Health <= 0.f)
	{
		CombatState = EVEILCombatState::Dead;
		OnDied.Broadcast();
		DisableInput(Cast<APlayerController>(Controller));
	}
	return Applied;
}

void AVEILCharacter::Heal(float Amount)
{
	if (!IsAlive()) return;
	Health = FMath::Clamp(Health + Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(Health, MaxHealth);
}

void AVEILCharacter::ToggleCameraMode()
{
	bFirstPerson = !bFirstPerson;
	if (CameraBoom)
	{
		CameraBoom->TargetArmLength = bFirstPerson ? 0.f : 420.f;
		CameraBoom->SetRelativeLocation(bFirstPerson ? FVector(30.f, 0.f, 64.f) : FVector::ZeroVector);
	}
	if (RunnerBody) RunnerBody->SetOwnerNoSee(bFirstPerson);
	if (RunnerVisor) RunnerVisor->SetOwnerNoSee(bFirstPerson);
	GetMesh()->SetOwnerNoSee(bFirstPerson);
	UE_LOG(LogVEIL, Log, TEXT("VEIL camera: %s person."), bFirstPerson ? TEXT("first") : TEXT("third"));
}

----- END FILE: D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp -----
----- FILE: D:\VEIL\Source\VEIL\Public\Character\VEILCharacter.h (5651 bytes) -----
// VEIL: THE LAST SIGNAL - player character.
// Third-person movement, sprint, jump, dodge, aim + hitscan fire, health,
// interact trace. Enhanced Input throughout (UE 5.8).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VEILCharacter.generated.h"

class UCameraComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVEILHealthChanged, float, NewHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVEILCharacterDied);

UENUM(BlueprintType)
enum class EVEILCombatState : uint8
{
	Exploring,
	Aiming,
	Dodging,
	Dead
};

UCLASS()
class VEIL_API AVEILCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AVEILCharacter();
	/** Incremented as the first act of Tick - the controller reads it
	 *  to prove whether Tick is ever entered. */
	int32 PhiTickEntryCount = 0;

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	// ---- Health ----
	UPROPERTY(BlueprintAssignable, Category = "VEIL|Health")
	FVEILHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Health")
	FVEILCharacterDied OnDied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Health")
	float Health = 100.f;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Health")
	void Heal(float Amount);

	UFUNCTION(BlueprintPure, Category = "VEIL|Health")
	bool IsAlive() const { return Health > 0.f; }

	// ---- God Mode: on the menus, on the console, in the damage gate ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|GodMode")
	bool bGodMode = false;

	UFUNCTION(Exec, BlueprintCallable, Category = "VEIL|GodMode")
	void ToggleGodMode();

	UFUNCTION(BlueprintPure, Category = "VEIL|GodMode")
	bool IsGodMode() const { return bGodMode; }

	// ---- Combat ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Combat")
	EVEILCombatState CombatState = EVEILCombatState::Exploring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float WeaponDamage = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float WeaponRange = 6000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float FireCooldown = 0.22f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float DodgeDistance = 550.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float DodgeCooldown = 0.9f;

	// ---- Movement tuning ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float WalkSpeed = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float SprintSpeed = 750.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float AimWalkSpeed = 220.f;

protected:
	virtual void BeginPlay() override;

	// ---- Components ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	// ---- Enhanced Input assets (assign in BP_PlayerCharacter) ----
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> InteractAction;

	// ---- Input handlers ----
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
	void DoDodge();
	void StartAim();
	void StopAim();
	void Fire();
	void Interact();

private:
	/** If no Input assets are assigned in the Blueprint, the game builds its
	 *  own mapping in code: WASD + mouse AND a full Xbox controller map.
	 *  Either way, both control schemes are live from the first frame. */
	void BuildFallbackInput();

	UPROPERTY()
	TObjectPtr<UInputMappingContext> BuiltMappingContext;

	UPROPERTY()
	TArray<TObjectPtr<UInputAction>> BuiltActions;

	bool bSprinting = false;
	bool bAiming = false;
	float LastFireTime = -100.f;
	float LastDodgeTime = -100.f;

	bool bFirstPerson = false;
	void ToggleCameraMode();
	TObjectPtr<UStaticMeshComponent> RunnerBody;
	TObjectPtr<UStaticMeshComponent> RunnerVisor;

	void ApplySpeed();
};
----- END FILE: D:\VEIL\Source\VEIL\Public\Character\VEILCharacter.h -----
##### VEIL MOVEMENT GREP #####
VEILFactionAI.cpp:39: Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
VEILFactionAI.cpp:55: Eye->SetCollisionEnabled(ECollisionEnabled::NoCollision);
VEILCharacter.cpp:65: Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
VEILCharacter.cpp:82: Visor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
VEILCharacter.cpp:402: LaunchCharacter(Dir * DodgeDistance + FVector(0.f, 0.f, 120.f), true, false);
VEILGameMode.cpp:84: Pawn->SetActorLocation(Builder->PlazaCenter);
VEILDiscoverySystem.cpp:17: Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
VEILDiscoverySystem.cpp:44: Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
##### VEIL DONE #####
##### OMNI CHARACTER FILES #####
----- FILE: D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp (18954 bytes) -----
// OMNI: THE LAST SIGNAL - player character implementation.
#include "Character/OMNICharacter.h"
#include "Animation/AnimSequence.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputCoreTypes.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "Kismet/GameplayStatics.h"
#include "Systems/OMNIDiscoverySystem.h"
#include "OMNI.h"

AOMNICharacter::AOMNICharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* Move = GetCharacterMovement();
	Move->bOrientRotationToMovement = true;
	Move->RotationRate = FRotator(0.f, 540.f, 0.f);
	Move->JumpZVelocity = 620.f;
	Move->AirControl = 0.35f;
	Move->MaxWalkSpeed = WalkSpeed;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 420.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// The runner's visible body, built from engine shapes - no mesh assets
	// ship with the project, and an invisible pawn is not a character.
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(
			TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
			TEXT("/Engine/BasicShapes/Cube.Cube"));

		UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerBody"));
		Body->SetupAttachment(GetCapsuleComponent());
		Body->SetRelativeLocation(FVector(0.f, 0.f, -15.f));
		Body->SetRelativeScale3D(FVector(0.62f, 0.62f, 1.5f));
		Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		RunnerBody = Body;
		if (CylinderMesh.Succeeded()) Body->SetStaticMesh(CylinderMesh.Object);
		if (UMaterialInterface* Base = Body->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.08f, 0.08f, 0.12f));
				MID->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(0.08f, 0.08f, 0.12f));
				Body->SetMaterial(0, MID);
			}
		}

		UStaticMeshComponent* Visor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerVisor"));
		Visor->SetupAttachment(GetCapsuleComponent());
		Visor->SetRelativeLocation(FVector(20.f, 0.f, 58.f));
		Visor->SetRelativeScale3D(FVector(0.10f, 0.46f, 0.12f));
		Visor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		RunnerVisor = Visor;
		if (CubeMesh.Succeeded()) Visor->SetStaticMesh(CubeMesh.Object);
		if (UMaterialInterface* Base = Visor->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.78f, 0.30f));
				MID->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor(1.f, 0.78f, 0.30f) * 3.f);
				Visor->SetMaterial(0, MID);
			}
		}
	}

	// The real body (job 089 landed the Mannequins tree in Content):
	// The Countess: mesh, skeleton and AnimBlueprint all resolve in
	// the ParagonCountess tree (job 116's triangle). Manny's mesh never
	// carried a skeleton in this seat; the Countess closes the triangle.
	// verbatim from the on-disk inventory. If either fails to load,
	// the primitive runner above stays visible and the log says so -
	// an invisible pawn is not a character.
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MannyMesh(
			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
		static ConstructorHelpers::FObjectFinder<UAnimSequence> MannyAnim(
			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
		if (MannyMesh.Succeeded())
		{
			GetMesh()->SetSkeletalMeshAsset(MannyMesh.Object);
			GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
			GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
			if (MannyAnim.Succeeded())
			{
				GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			}
			else
			{
				UE_LOG(LogOMNI, Warning, TEXT("PHI BODY: Countess pose sequence not found - mesh set, animation unassigned."));
			}
			if (RunnerBody) RunnerBody->SetVisibility(false);
			if (RunnerVisor) RunnerVisor->SetVisibility(false);
			UE_LOG(LogOMNI, Log, TEXT("PHI BODY: Countess skeletal mesh is the runner's body."));
		}
		else
		{
			UE_LOG(LogOMNI, Warning, TEXT("PHI BODY FALLBACK: SM_Countess not found - primitive runner body stands."));
		}
	}

	Health = MaxHealth;
}

void AOMNICharacter::BeginPlay()
{
	Super::BeginPlay();
	// The anim class is set in the constructor AND here: if the
	// component's initialization overwrote the constructor's
	// assignment, this one - after registration - is the one
	// that lives. The Tick one-shots report which state won.
	{
		if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
		{
			GetMesh()->PlayAnimation(PoseSeq, true);
		}
	}
	UE_LOG(LogOMNI, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
	// PHI MOVE TEST v3 lives in Tick (tick-driven state machine -
	// timers never reported in the -game smokes, so the test rides
	// the frame itself).
	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health, MaxHealth);

	if (!DefaultMappingContext)
	{
		BuildFallbackInput();
	}

	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Sub =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Sub->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AOMNICharacter::BuildFallbackInput()
{
	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
	// Used only when no editor-made Input assets are assigned.
	auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
	{
		UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
		Action->ValueType = Type;
		BuiltActions.Add(Action);
		return Action;
	};

	MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
	LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
	JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
	SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
	DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
	AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
	FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
	InteractAction = MakeAction(TEXT("IA_Interact"), EInputActionValueType::Boolean);

	BuiltMappingContext = NewObject<UInputMappingContext>(this, TEXT("IMC_OMNI_BuiltIn"), RF_Transient);
	UInputMappingContext* IMC = BuiltMappingContext;

	auto Map = [IMC, this](UInputAction* Action, const FKey Key,
		bool bNegate = false, bool bSwizzle = false)
	{
		FEnhancedActionKeyMapping& Mapping = IMC->MapKey(Action, Key);
		if (bSwizzle)
		{
			UInputModifierSwizzleAxis* Swizzle = NewObject<UInputModifierSwizzleAxis>(this);
			Swizzle->Order = EInputAxisSwizzle::YXZ;
			Mapping.Modifiers.Add(Swizzle);
		}
		if (bNegate)
		{
			Mapping.Modifiers.Add(NewObject<UInputModifierNegate>(this));
		}
	};

	// ---- Keyboard + mouse ----
	Map(MoveAction, EKeys::W, false, true);
	Map(MoveAction, EKeys::S, true, true);
	Map(MoveAction, EKeys::A, true, false);
	Map(MoveAction, EKeys::D, false, false);
	Map(LookAction, EKeys::Mouse2D);
	Map(JumpAction, EKeys::SpaceBar);
	Map(SprintAction, EKeys::LeftShift);
	Map(DodgeAction, EKeys::LeftAlt);
	Map(AimAction, EKeys::RightMouseButton);
	Map(FireAction, EKeys::LeftMouseButton);
	Map(InteractAction, EKeys::E);

	// ---- Xbox controller ----
	Map(MoveAction, EKeys::Gamepad_Left2D);
	Map(LookAction, EKeys::Gamepad_Right2D);
	Map(JumpAction, EKeys::Gamepad_FaceButton_Bottom);  // A
	Map(DodgeAction, EKeys::Gamepad_FaceButton_Right);  // B
	Map(InteractAction, EKeys::Gamepad_FaceButton_Left);// X
	Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
	Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
	Map(SprintAction, EKeys::Gamepad_LeftThumbstick);   // L3
	// Pause/menu lives on the PlayerController: P, Esc, and pad Menu button.

	DefaultMappingContext = BuiltMappingContext;
	UE_LOG(LogOMNI, Log, TEXT("OMNI input: built-in map active (keyboard/mouse + Xbox controller)."));
}

void AOMNICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 1st/3rd person toggle: V on keyboard, right-stick click (R3) on the pad.
	PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AOMNICharacter::ToggleCameraMode);
	PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AOMNICharacter::ToggleCameraMode);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AOMNICharacter::Move);
		if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AOMNICharacter::Look);
		if (JumpAction)
		{
			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		}
		if (SprintAction)
		{
			EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AOMNICharacter::StartSprint);
			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AOMNICharacter::StopSprint);
		}
		if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AOMNICharacter::DoDodge);
		if (AimAction)
		{
			EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AOMNICharacter::StartAim);
			EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AOMNICharacter::StopAim);
		}
		if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AOMNICharacter::Fire);
		if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AOMNICharacter::Interact);
	}
}

void AOMNICharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	++PhiTickEntryCount;
	// PHI MOVE TEST v3 - tick-driven, no timers. At t=5s of tick time it
	// names the possession state, drives synthetic forward input for
	// ~1.2s, then reports the velocity and displacement produced.
	{
		static int32 MovePhase = 0;
		static float MoveClock = 0.f;
		static FVector MoveSpawn = FVector::ZeroVector;
		MoveClock += DeltaSeconds;
		if (MovePhase == 0 && MoveClock >= 5.f)
		{
			MovePhase = 1;
			MoveSpawn = GetActorLocation();
			AController* C = GetController();
			UE_LOG(LogOMNI, Log, TEXT("PHI MOVE TEST BEGIN: controller=%s pawn=%s locallyControlled=%d paused=%d velBefore=%.1f loc=%s"),
				C ? *C->GetClass()->GetName() : TEXT("NONE"), *GetName(),
				IsLocallyControlled() ? 1 : 0, UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0,
				GetVelocity().Size(), *GetActorLocation().ToString());
		}
		else if (MovePhase == 1)
		{
			AddMovementInput(GetActorForwardVector(), 1.0f);
			if (MoveClock >= 6.2f)
			{
				MovePhase = 2;
				UE_LOG(LogOMNI, Log, TEXT("PHI MOVE TEST: velAfter=%.1f locAfter=%s moved=%.1f"),
					GetVelocity().Size(), *GetActorLocation().ToString(),
					FVector::Dist2D(GetActorLocation(), MoveSpawn));
			}
		}
	}
	// PHI TICKPROOF: every ~5s of tick time the game states it is turning.
	{
		static float ProofClock = 0.f;
		static int64 ProofFrames = 0;
		ProofClock += DeltaSeconds;
		++ProofFrames;
		if (ProofClock >= 5.f)
		{
			ProofClock = 0.f;
			UE_LOG(LogOMNI, Log, TEXT("PHI TICKPROOF: frames=%lld worldTime=%.1f paused=%d"),
				ProofFrames, GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
		}
	}
	// One-shot animation proof: the anim instance is created after
	// BeginPlay, so the first tick that sees it logs the live class.
	static bool bAnimProofLogged = false;
	if (!bAnimProofLogged && GetMesh()->GetAnimInstance())
	{
		bAnimProofLogged = true;
		UE_LOG(LogOMNI, Log, TEXT("PHI BODY ANIM LIVE: %s"), *GetMesh()->GetAnimInstance()->GetClass()->GetName());
	static float AnimDiagTimer = 0.f;
	if (!bAnimProofLogged)
	{
		AnimDiagTimer += DeltaSeconds;
		if (AnimDiagTimer > 5.f)
		{
			bAnimProofLogged = true;
			UE_LOG(LogOMNI, Warning, TEXT("PHI BODY ANIM DIAG: instance=none class=%s skeleton=%s"),
				GetMesh()->GetAnimClass() ? *GetMesh()->GetAnimClass()->GetName() : TEXT("none"),
				(GetMesh()->GetSkeletalMeshAsset() && GetMesh()->GetSkeletalMeshAsset()->GetSkeleton())
					? *GetMesh()->GetSkeletalMeshAsset()->GetSkeleton()->GetName() : TEXT("none"));
		}
	}
	}
}

void AOMNICharacter::Move(const FInputActionValue& Value)
{
	if (!Controller || !IsAlive()) return;
	const FVector2D Axis = Value.Get<FVector2D>();
	const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
	AddMovementInput(Forward, Axis.Y);
	AddMovementInput(Right, Axis.X);
}

void AOMNICharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(Axis.Y);
}

void AOMNICharacter::ApplySpeed()
{
	UCharacterMovementComponent* Move = GetCharacterMovement();
	if (bAiming)        Move->MaxWalkSpeed = AimWalkSpeed;
	else if (bSprinting) Move->MaxWalkSpeed = SprintSpeed;
	else                 Move->MaxWalkSpeed = WalkSpeed;

	// Aiming locks facing to the camera; exploring lets movement orient the body.
	Move->bOrientRotationToMovement = !bAiming;
	bUseControllerRotationYaw = bAiming;
}

void AOMNICharacter::StartSprint() { bSprinting = true; ApplySpeed(); }
void AOMNICharacter::StopSprint()  { bSprinting = false; ApplySpeed(); }

void AOMNICharacter::StartAim()
{
	bAiming = true;
	CombatState = EOMNICombatState::Aiming;
	ApplySpeed();
}

void AOMNICharacter::StopAim()
{
	bAiming = false;
	if (CombatState == EOMNICombatState::Aiming) CombatState = EOMNICombatState::Exploring;
	ApplySpeed();
}

void AOMNICharacter::DoDodge()
{
	const float Now = GetWorld()->TimeSeconds;
	if (!IsAlive() || Now - LastDodgeTime < DodgeCooldown) return;
	LastDodgeTime = Now;
	CombatState = EOMNICombatState::Dodging;

	FVector Dir = GetLastMovementInputVector();
	if (Dir.IsNearlyZero()) Dir = -GetActorForwardVector();
	Dir.Z = 0.f; Dir.Normalize();
	LaunchCharacter(Dir * DodgeDistance + FVector(0.f, 0.f, 120.f), true, false);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, [this]()
	{
		if (CombatState == EOMNICombatState::Dodging)
		{
			CombatState = bAiming ? EOMNICombatState::Aiming : EOMNICombatState::Exploring;
		}
	}, 0.35f, false);
}

void AOMNICharacter::Fire()
{
	const float Now = GetWorld()->TimeSeconds;
	if (!IsAlive() || Now - LastFireTime < FireCooldown) return;
	LastFireTime = Now;

	FVector Start;
	FRotator ViewRot;
	if (Controller) Controller->GetPlayerViewPoint(Start, ViewRot);
	else { Start = GetActorLocation(); ViewRot = GetActorRotation(); }

	const FVector End = Start + ViewRot.Vector() * WeaponRange;
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AActor* Victim = Hit.GetActor())
		{
			UGameplayStatics::ApplyDamage(Victim, WeaponDamage, Controller, this, UDamageType::StaticClass());
		}
	}
}

void AOMNICharacter::Interact()
{
	if (!IsAlive()) return;
	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const FVector End = Start + GetActorForwardVector() * 320.f;
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AOMNIInteractable* Target = Cast<AOMNIInteractable>(Hit.GetActor()))
		{
			Target->Interact(this);
		}
	}
}

void AOMNICharacter::ToggleGodMode()
{
	bGodMode = !bGodMode;
	UE_LOG(LogOMNI, Warning, TEXT("PHI GODMODE: %s"), bGodMode ? TEXT("ON") : TEXT("OFF"));
}

float AOMNICharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (bGodMode) return 0.f;
	if (!IsAlive()) return 0.f;
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health = FMath::Clamp(Health - Applied, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(Health, MaxHealth);
	if (Health <= 0.f)
	{
		CombatState = EOMNICombatState::Dead;
		OnDied.Broadcast();
		DisableInput(Cast<APlayerController>(Controller));
	}
	return Applied;
}

void AOMNICharacter::Heal(float Amount)
{
	if (!IsAlive()) return;
	Health = FMath::Clamp(Health + Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(Health, MaxHealth);
}

void AOMNICharacter::ToggleCameraMode()
{
	bFirstPerson = !bFirstPerson;
	if (CameraBoom)
	{
		CameraBoom->TargetArmLength = bFirstPerson ? 0.f : 420.f;
		CameraBoom->SetRelativeLocation(bFirstPerson ? FVector(30.f, 0.f, 64.f) : FVector::ZeroVector);
	}
	if (RunnerBody) RunnerBody->SetOwnerNoSee(bFirstPerson);
	if (RunnerVisor) RunnerVisor->SetOwnerNoSee(bFirstPerson);
	GetMesh()->SetOwnerNoSee(bFirstPerson);
	UE_LOG(LogOMNI, Log, TEXT("OMNI camera: %s person."), bFirstPerson ? TEXT("first") : TEXT("third"));
}

----- END FILE: D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp -----
----- FILE: D:\OMNI-UE\Source\OMNI\Public\Character\OMNICharacter.h (5651 bytes) -----
// OMNI: THE LAST SIGNAL - player character.
// Third-person movement, sprint, jump, dodge, aim + hitscan fire, health,
// interact trace. Enhanced Input throughout (UE 5.8).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OMNICharacter.generated.h"

class UCameraComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOMNIHealthChanged, float, NewHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOMNICharacterDied);

UENUM(BlueprintType)
enum class EOMNICombatState : uint8
{
	Exploring,
	Aiming,
	Dodging,
	Dead
};

UCLASS()
class OMNI_API AOMNICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOMNICharacter();
	/** Incremented as the first act of Tick - the controller reads it
	 *  to prove whether Tick is ever entered. */
	int32 PhiTickEntryCount = 0;

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	// ---- Health ----
	UPROPERTY(BlueprintAssignable, Category = "OMNI|Health")
	FOMNIHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Health")
	FOMNICharacterDied OnDied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Health")
	float Health = 100.f;

	UFUNCTION(BlueprintCallable, Category = "OMNI|Health")
	void Heal(float Amount);

	UFUNCTION(BlueprintPure, Category = "OMNI|Health")
	bool IsAlive() const { return Health > 0.f; }

	// ---- God Mode: on the menus, on the console, in the damage gate ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|GodMode")
	bool bGodMode = false;

	UFUNCTION(Exec, BlueprintCallable, Category = "OMNI|GodMode")
	void ToggleGodMode();

	UFUNCTION(BlueprintPure, Category = "OMNI|GodMode")
	bool IsGodMode() const { return bGodMode; }

	// ---- Combat ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Combat")
	EOMNICombatState CombatState = EOMNICombatState::Exploring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float WeaponDamage = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float WeaponRange = 6000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float FireCooldown = 0.22f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float DodgeDistance = 550.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float DodgeCooldown = 0.9f;

	// ---- Movement tuning ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float WalkSpeed = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float SprintSpeed = 750.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float AimWalkSpeed = 220.f;

protected:
	virtual void BeginPlay() override;

	// ---- Components ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	// ---- Enhanced Input assets (assign in BP_PlayerCharacter) ----
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> InteractAction;

	// ---- Input handlers ----
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
	void DoDodge();
	void StartAim();
	void StopAim();
	void Fire();
	void Interact();

private:
	/** If no Input assets are assigned in the Blueprint, the game builds its
	 *  own mapping in code: WASD + mouse AND a full Xbox controller map.
	 *  Either way, both control schemes are live from the first frame. */
	void BuildFallbackInput();

	UPROPERTY()
	TObjectPtr<UInputMappingContext> BuiltMappingContext;

	UPROPERTY()
	TArray<TObjectPtr<UInputAction>> BuiltActions;

	bool bSprinting = false;
	bool bAiming = false;
	float LastFireTime = -100.f;
	float LastDodgeTime = -100.f;

	bool bFirstPerson = false;
	void ToggleCameraMode();
	TObjectPtr<UStaticMeshComponent> RunnerBody;
	TObjectPtr<UStaticMeshComponent> RunnerVisor;

	void ApplySpeed();
};
----- END FILE: D:\OMNI-UE\Source\OMNI\Public\Character\OMNICharacter.h -----
##### OMNI MOVEMENT GREP #####
OMNIFactionAI.cpp:39: Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
OMNIFactionAI.cpp:55: Eye->SetCollisionEnabled(ECollisionEnabled::NoCollision);
OMNICharacter.cpp:65: Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
OMNICharacter.cpp:82: Visor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
OMNICharacter.cpp:402: LaunchCharacter(Dir * DodgeDistance + FVector(0.f, 0.f, 120.f), true, false);
OMNIGameMode.cpp:84: Pawn->SetActorLocation(Builder->PlazaCenter);
OMNIDiscoverySystem.cpp:17: Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
OMNIDiscoverySystem.cpp:44: Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
OMNIQuestContent.cpp:38: Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
OMNIQuestContent.cpp:40: Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
OMNIQuestContent.cpp:41: Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
OMNIQuestContent.cpp:121: Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
OMNIQuestContent.cpp:140: SetActorLocation(Loc);
##### OMNI DONE #####
JOB 336 DONE

```
