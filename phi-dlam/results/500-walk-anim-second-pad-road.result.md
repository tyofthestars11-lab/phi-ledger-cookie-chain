# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 22:10:30 UTC

## STEP 1
```
=== SEAT 500 - THE WALK ANIMATION AND THE SECOND PAD ROAD (Ground: job 499 read the glide at its exact address - the runner mesh stands in single node mode playing one idle pose, line 121 of the character source, so the body travels while the pose never walks. This job seats the Countess animation blueprint as the mesh animation class with the single node kept only as fallback, and it seats a second controller road that bypasses the mapping layer entirely: direct axis and key binds in the binding function itself, the same shape as the working thumbstick bind that already stands there, with four small handlers declared in the header and defined in the source. The patcher prints the constructor span first, gates on its anchors, holds the whole patch if any line replays the idle pose, verifies by read back, and the build runs in this same job when the editor stands closed. Every variable carries the p500 prefix.) ===
CPP LINES=692
SPAN 95: 				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.78f, 0.30f));
SPAN 96: 				MID->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor(1.f, 0.78f, 0.30f) * 3.f);
SPAN 97: 				Visor->SetMaterial(0, MID);
SPAN 98: 			}
SPAN 99: 		}
SPAN 100: 	}
SPAN 101: 
SPAN 102: 	// The real body (job 089 landed the Mannequins tree in Content):
SPAN 103: 	// The Countess: mesh, skeleton and AnimBlueprint all resolve in
SPAN 104: 	// the ParagonCountess tree (job 116's triangle). Manny's mesh never
SPAN 105: 	// carried a skeleton in this seat; the Countess closes the triangle.
SPAN 106: 	// verbatim from the on-disk inventory. If either fails to load,
SPAN 107: 	// the primitive runner above stays visible and the log says so -
SPAN 108: 	// an invisible pawn is not a character.
SPAN 109: 	{
SPAN 110: 		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MannyMesh(
SPAN 111: 			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
SPAN 112: 		static ConstructorHelpers::FObjectFinder<UAnimSequence> MannyAnim(
SPAN 113: 			TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
SPAN 114: 		if (MannyMesh.Succeeded())
SPAN 115: 		{
SPAN 116: 			GetMesh()->SetSkeletalMeshAsset(MannyMesh.Object);
SPAN 117: 			GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
SPAN 118: 			GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
SPAN 119: 			if (MannyAnim.Succeeded())
SPAN 120: 			{
SPAN 121: 				GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
SPAN 122: 			}
SPAN 123: 			else
SPAN 124: 			{
SPAN 125: 				UE_LOG(LogVEIL, Warning, TEXT("PHI BODY: Countess pose sequence not found - mesh set, animation unassigned."));
SPAN 126: 			}
SPAN 127: 			if (RunnerBody) RunnerBody->SetVisibility(false);
SPAN 128: 			if (RunnerVisor) RunnerVisor->SetVisibility(false);
SPAN 129: 			UE_LOG(LogVEIL, Log, TEXT("PHI BODY: Countess skeletal mesh is the runner's body."));
SPAN 130: 		}
SPAN 131: 		else
SPAN 132: 		{
SPAN 133: 			UE_LOG(LogVEIL, Warning, TEXT("PHI BODY FALLBACK: SM_Countess not found - primitive runner body stands."));
SPAN 134: 		}
SPAN 135: 	}
SPAN 136: 
SPAN 137: 	Health = MaxHealth;
SPAN 138: }
SPAN 139: 
SPAN 140: void AVEILCharacter::BeginPlay()
SPAN 141: {
SPAN 142: 	Super::BeginPlay();
SPAN 143:     {
SPAN 144:         UCapsuleComponent* Cap365 = GetCapsuleComponent();
SPAN 145:         USkeletalMeshComponent* Mesh365 = GetMesh();
SPAN 146:         UCharacterMovementComponent* Move365 = GetCharacterMovement();
SPAN 147:     }
SPAN 148: 	// The anim class is set in the constructor AND here: if the
SPAN 149: 	// component's initialization overwrote the constructor's
SPAN 150: 	// assignment, this one - after registration - is the one
SPAN 151: 	// that lives. The Tick one-shots report which state won.
SPAN 152: 	{
SPAN 153: 		if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
SPAN 154: 		{
SPAN 155: 			GetMesh()->PlayAnimation(PoseSeq, true);
SPAN 156: 		}
SPAN 157: 	}
SPAN 158: 	UE_LOG(LogVEIL, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
SPAN 159: 		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
SPAN 160: 		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
SPAN 161: 	// PHI MOVE TEST v3 lives in Tick (tick-driven state machine -
SPAN 162: 	// timers never reported in the -game smokes, so the test rides
SPAN 163: 	// the frame itself).
SPAN 164: 	Health = MaxHealth;
SPAN 165: 	OnHealthChanged.Broadcast(Health, MaxHealth);
SPAN 166: 
SPAN 167: 	if (!DefaultMappingContext)
SPAN 168: 	{
SPAN 169: 		BuildFallbackInput();
SPAN 170: 	}
SPAN 171: 
SPAN 172: 	if (APlayerController* PC = Cast<APlayerController>(Controller))
SPAN 173: 	{
SPAN 174: 		if (UEnhancedInputLocalPlayerSubsystem* Sub =
SPAN 175: 			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
SPAN 176: 		{
SPAN 177: 			if (DefaultMappingContext)
SPAN 178: 			{
SPAN 179: 				Sub->AddMappingContext(DefaultMappingContext, 0);
SPAN 180: 			}
SPAN 181: 		}
SPAN 182: 	}
SPAN 183:     // PHI 480: the built context is seated at BeginPlay as the second road.
SPAN 184:     if (APlayerController* Phi480PC = Cast<APlayerController>(GetController()))
SPAN 185:     {
SPAN 186:         if (ULocalPlayer* Phi480LP = Phi480PC->GetLocalPlayer())
SPAN 187:         {
SPAN 188:             if (UEnhancedInputLocalPlayerSubsystem* Phi480Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Phi480LP))
SPAN 189:             {
SPAN 190:                 if (BuiltMappingContext && !Phi480Sub->HasMappingContext(BuiltMappingContext)) { Phi480Sub->AddMappingContext(BuiltMappingContext, 0); }
SPAN 191:                 UE_LOG(LogTemp, Display, TEXT("PHI INPUT SEAT: beginplay"));
SPAN 192:             }
SPAN 193:         }
SPAN 194:     }
SPAN 195: }
SPAN 196: 
SPAN 197: void AVEILCharacter::BuildFallbackInput()
SPAN 198: {
SPAN 199: 	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
SPAN 200: 	// Used only when no editor-made Input assets are assigned.
ANCHOR A COUNT=1
PLAYANIM 155: GetMesh()->PlayAnimation(PoseSeq, true);
CTOR START=31 ANCHOR LINE=121
PATCH GATE FAIL reflip PlayAnimation present - patch held
BLD Total time in Unreal Build Accelerator local executor: 61.97 seconds
BLD Result: Succeeded
PHI P500 VERDICT: BUILD READ DONE
JOB 500 DONE

```
