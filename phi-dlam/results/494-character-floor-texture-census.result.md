# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 21:09:25 UTC

## STEP 1
```
=== SOURCE CENSUS 494 - THE CHARACTER, THE FLOOR, THE TEXTURE READ (Ordered read: the truth lives in the source, not in theory. This job prints the actual VEILCharacter constructor with its capsule size, collision profile and mesh physics flags, the movement settings in source and header, the floor truth from the game own newest log - the floor diag lines the running game already prints - and the texture pool state from the settings file beside a count of the mesh files standing in Content. Nothing is invented and nothing is fixed in this job: it reads and prints, and the fix seats from these prints. It rides behind job 493, which turns the broken Fab plugin off so the builds compile again. Every variable carries the cc494 prefix.) ===
CTOR at=29
CC 30: AVEILCharacter::AVEILCharacter()
CC 31: {
CC 32: 	PrimaryActorTick.bCanEverTick = true;
CC 33: 
CC 34: 	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
CC 35: 
CC 36: 	bUseControllerRotationPitch = false;
CC 37: 	bUseControllerRotationYaw = false;
CC 38: 	bUseControllerRotationRoll = false;
CC 39: 
CC 40: 	UCharacterMovementComponent* Move = GetCharacterMovement();
CC 41: 	Move->bOrientRotationToMovement = true;
CC 42: 	Move->RotationRate = FRotator(0.f, 540.f, 0.f);
CC 43: 	Move->JumpZVelocity = 620.f;
CC 44: 	Move->AirControl = 0.35f;
CC 45: 	Move->MaxWalkSpeed = WalkSpeed;
CC 46: 	Move->SetWalkableFloorAngle(60.f);
CC 47: 	Move->MaxStepHeight = 90.f;
CC 48: 
CC 49: 	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
CC 50: 	CameraBoom->SetupAttachment(RootComponent);
CC 51: 	CameraBoom->TargetArmLength = 420.f;
CC 52: 	CameraBoom->bUsePawnControlRotation = true;
CC 53: 
CC 54: 	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
CC 55: 	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
CC 56: 	FollowCamera->bUsePawnControlRotation = false;
CC 57: 
CC 58: 	// The runner's visible body, built from engine shapes - no mesh assets
CC 59: 	// ship with the project, and an invisible pawn is not a character.
CC 60: 	{
CC 61: 		static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(
CC 62: 			TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
CC 63: 		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
CC 64: 			TEXT("/Engine/BasicShapes/Cube.Cube"));
CC 65: 
CC 66: 		UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerBody"));
CC 67: 		Body->SetupAttachment(GetCapsuleComponent());
CC 68: 		Body->SetRelativeLocation(FVector(0.f, 0.f, -15.f));
CC 69: 		Body->SetRelativeScale3D(FVector(0.62f, 0.62f, 1.5f));
CC 70: 		Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
CC 71: 		RunnerBody = Body;
CC 72: 		if (CylinderMesh.Succeeded()) Body->SetStaticMesh(CylinderMesh.Object);
CC 73: 		if (UMaterialInterface* Base = Body->GetMaterial(0))
CC 74: 		{
CC 75: 			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
CC 76: 			{
CC 77: 				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.08f, 0.08f, 0.12f));
CC 78: 				MID->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(0.08f, 0.08f, 0.12f));
CC 79: 				Body->SetMaterial(0, MID);
CC 80: 			}
CC 81: 		}
CC 82: 
CC 83: 		UStaticMeshComponent* Visor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunnerVisor"));
CC 84: 		Visor->SetupAttachment(GetCapsuleComponent());
CC 85: 		Visor->SetRelativeLocation(FVector(20.f, 0.f, 58.f));
CC 86: 		Visor->SetRelativeScale3D(FVector(0.10f, 0.46f, 0.12f));
CC 87: 		Visor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
CC 88: 		RunnerVisor = Visor;
CC 89: 		if (CubeMesh.Succeeded()) Visor->SetStaticMesh(CubeMesh.Object);
CC 90: 		if (UMaterialInterface* Base = Visor->GetMaterial(0))
CC 91: 		{
CC 92: 			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
CC 93: 			{
CC 94: 				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.78f, 0.30f));
CC 95: 				MID->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor(1.f, 0.78f, 0.30f) * 3.f);
CC 96: 				Visor->SetMaterial(0, MID);
CC 97: 			}
CC 98: 		}
CC 99: 	}
CC 100: 
CC 101: 	// The real body (job 089 landed the Mannequins tree in Content):
CC 102: 	// The Countess: mesh, skeleton and AnimBlueprint all resolve in
CC 103: 	// the ParagonCountess tree (job 116's triangle). Manny's mesh never
CC 104: 	// carried a skeleton in this seat; the Countess closes the triangle.
CC 105: 	// verbatim from the on-disk inventory. If either fails to load,
CC 106: 	// the primitive runner above stays visible and the log says so -
CC 107: 	// an invisible pawn is not a character.
CC 108: 	{
CC 109: 		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MannyMesh(
CC 110: 			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
CC 111: 		static ConstructorHelpers::FObjectFinder<UAnimSequence> MannyAnim(
CC 112: 			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
CC 113: 		if (MannyMesh.Succeeded())
CC 114: 		{
CC 115: 			GetMesh()->SetSkeletalMeshAsset(MannyMesh.Object);
CC 116: 			GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
CC 117: 			GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
CC 118: 			if (MannyAnim.Succeeded())
CC 119: 			{
CC 120: 				GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
CC 121: 			}
CC 122: 			else
CC 123: 			{
CC 124: 				UE_LOG(LogVEIL, Warning, TEXT("PHI BODY: Countess pose sequence not found - mesh set, animation unassigned."));
CC 125: 			}
CC 126: 			if (RunnerBody) RunnerBody->SetVisibility(false);
CC 127: 			if (RunnerVisor) RunnerVisor->SetVisibility(false);
CC 128: 			UE_LOG(LogVEIL, Log, TEXT("PHI BODY: Countess skeletal mesh is the runner's body."));
CC 129: 		}
CC 130: 		else
CC 131: 		{
CC 132: 			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY FALLBACK: SM_Countess not found - primitive runner body stands."));
CC 133: 		}
CC 134: 	}
CC 135: 
CC 136: 	Health = MaxHealth;
CC 137: }
MOVE 364: UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 %s: tick=%d dt=%.4f z=%.1f velZ=%.1f mode=%d findBlock=%d findWalk=%d floorDist=%.1f floorActor=%s curBlock=%d"), Tag, PhiC2Tick, Dt, GetActorLocation().Z, GetVelocity().Z, (int32)GetCharacterMovement()->MovementMode, PhiF.bBlockingHit ? 1 : 0, PhiF.bWalkableFloor ? 1 : 0, PhiF.FloorDist, PhiF.HitResult.GetActor() ? *PhiF.HitResult.GetActor()->GetName() : TEXT("none"), GetCharacterMovement()->CurrentFloor.bBlockingHit ? 1 : 0);
MOVE 45: Move->MaxWalkSpeed = WalkSpeed;
MOVE 504: if (bAiming)        Move->MaxWalkSpeed = AimWalkSpeed;
MOVE 505: else if (bSprinting) Move->MaxWalkSpeed = SprintSpeed;
MOVE 506: else                 Move->MaxWalkSpeed = WalkSpeed;
MOVE 37: bUseControllerRotationYaw = false;
MOVE 510: bUseControllerRotationYaw = bAiming;
MOVE 41: Move->bOrientRotationToMovement = true;
MOVE 509: Move->bOrientRotationToMovement = !bAiming;
LOG D:\VEIL-OMNI\Saved\Logs\VEIL.log
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_0 top=10085.1 base=-138.3 loc=X=0 Y=-0 Z=4973 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_1 top=1075.5 base=-28.4 loc=X=0 Y=0 Z=524 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_42 top=1008.0 base=0.0 loc=X=0 Y=-2600 Z=504 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_43 top=2961.6 base=2858.6 loc=X=0 Y=-2600 Z=2910 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_44 top=169.9 base=0.0 loc=X=2100 Y=0 Z=85 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_45 top=660.3 base=642.2 loc=X=2100 Y=0 Z=651 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_46 top=235.9 base=0.0 loc=X=184 Y=-2092 Z=118 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_47 top=668.4 base=639.0 loc=X=184 Y=-2092 Z=654 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_48 top=206.8 base=0.0 loc=X=-2068 Y=-366 Z=103 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_49 top=659.2 base=650.4 loc=X=-2068 Y=-366 Z=655 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_50 top=344.7 base=300.0 loc=X=-545 Y=2028 Z=322 collEnabled=3
LOGF [2026.10.28-21.08.37:289][965]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_51 top=680.0 base=600.0 loc=X=-545 Y=2028 Z=640 collEnabled=3
LOGM [2026.10.28-21.04.05:438][  0]LogConfig: Set CVar [[r.Streaming.LimitPoolSizeToVRAM:0]]
LOGM [2026.10.28-21.04.05:438][  0]LogConfig: Set CVar [[r.Streaming.PoolSize:1000]]
LOGM [2026.10.28-21.04.05:447][  0]LogConfig: Set CVar [[r.Streaming.PoolSize:2500]]
LOGM [2026.10.28-21.04.36:269][  0]LogInit: Texture streaming: Enabled
LOGM [2026.10.28-21.04.44:691][  0]LogCsvProfiler: Display: Metadata set : streamingpoolsizemb="2500"
INI 73: [ConsoleVariables]
INI 74: r.Streaming.PoolSize=2500
CONTENT uasset=11971
PACK ParagonCountess=2725
PACK ParagonMurdock=1896
PACK ParagonRevenant=1621
PACK ParagonGreystone=1733
PACK ParagonMinions=2105
PHI CC494 VERDICT: CENSUS READ ABOVE
JOB 494 DONE

```
