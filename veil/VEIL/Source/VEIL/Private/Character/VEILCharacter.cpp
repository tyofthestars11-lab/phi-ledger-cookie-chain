// VEIL: THE LAST SIGNAL - player character implementation.
#include "Character/VEILCharacter.h"

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
	// Manny's skeletal mesh + the unarmed animation blueprint, paths
	// verbatim from the on-disk inventory. If either fails to load,
	// the primitive runner above stays visible and the log says so -
	// an invisible pawn is not a character.
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MannyMesh(
			TEXT("/Game/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple"));
		static ConstructorHelpers::FClassFinder<UAnimInstance> MannyAnim(
			TEXT("/Game/Mannequins/Anims/Unarmed/ABP_Unarmed.ABP_Unarmed_C"));
		if (MannyMesh.Succeeded())
		{
			GetMesh()->SetSkeletalMeshAsset(MannyMesh.Object);
			GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
			GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
			if (MannyAnim.Succeeded())
			{
				GetMesh()->SetAnimInstanceClass(MannyAnim.Class);
			}
			else
			{
				UE_LOG(LogVEIL, Warning, TEXT("PHI BODY: ABP_Unarmed class not found - mesh set, animation unassigned."));
			}
			if (RunnerBody) RunnerBody->SetVisibility(false);
			if (RunnerVisor) RunnerVisor->SetVisibility(false);
			UE_LOG(LogVEIL, Log, TEXT("PHI BODY: Manny skeletal mesh is the runner's body."));
		}
		else
		{
			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY FALLBACK: SKM_Manny_Simple not found - primitive runner body stands."));
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
		if (UClass* AnimClass = StaticLoadClass(UAnimInstance::StaticClass(), nullptr,
			TEXT("/Game/Mannequins/Anims/Unarmed/ABP_Unarmed.ABP_Unarmed_C")))
		{
			GetMesh()->SetAnimInstanceClass(AnimClass);
		}
	}
	UE_LOG(LogVEIL, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
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

float AVEILCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
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
