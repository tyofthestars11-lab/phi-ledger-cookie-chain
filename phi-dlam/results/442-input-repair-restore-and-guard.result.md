# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 16:59:13 UTC

## STEP 1
```
=== INPUT REPAIR 442 - RESTORE THE CHARACTER, THEN CLOSE THE TRUE LINK (Ground read whole from job 438: both its edits applied and verified by count, loads 1 and built adds 1, but the compile broke at VEILCharacter cpp lines 191 and 194 with brace errors at the edited BeginPlay ground, Result Failed; job 440 compiled the world builder clean and failed only on this same character file, so the Hub stands ready behind this one repair. Ground read whole from jobs 435 and 438: the fallback function, printed entire by 438, builds every action and its full keyboard and Xbox map and ends by assigning DefaultMappingContext from BuiltMappingContext at its line 246, so the context road was whole all along; the dead link stands one step earlier, at SetupPlayerInputComponent, which runs at possession, before BeginPlay builds anything, and reads action pointers that are null at that hour, so its null guards skip every bind and no key ever reaches a function. One, the job prints VEILCharacter cpp lines 150 to 215 as they stand, the damaged ground on the record. Two, it restores the file from its phi-backup-438 copy and verifies the restore: the 438 load count and built add count both read zero again. Three, it applies the repair at the true address: after the Super SetupPlayerInputComponent line, counted exactly once, it inserts a guard that builds the fallback input on the spot when the actions or the context stand unbuilt, so the binds below it read live actions in the same call; the read back counts the BuildFallbackInput call sites, which stand at two, the BeginPlay call and this guard. Four, it compiles VEILEditor Win64 Development, prints the last 15 lines of the log whole, and reads the build state from the Result line itself. Five, the verdict in one line: INPUT REPAIRED with the counts and the build state, or INPUT REPAIR HELD with the stage named. Every variable carries the ir442 prefix.) ===
--- DAMAGED GROUND 150-215 ---
DG 150: 		if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
DG 151: 		{
DG 152: 			GetMesh()->PlayAnimation(PoseSeq, true);
DG 153: 		}
DG 154: 	}
DG 155: 	UE_LOG(LogVEIL, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
DG 156: 		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
DG 157: 		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
DG 158: 	// PHI MOVE TEST v3 lives in Tick (tick-driven state machine -
DG 159: 	// timers never reported in the -game smokes, so the test rides
DG 160: 	// the frame itself).
DG 161: 	Health = MaxHealth;
DG 162: 	OnHealthChanged.Broadcast(Health, MaxHealth);
DG 163: 
DG 164: 	if (!DefaultMappingContext)
DG 165: 	{
DG 166: 		DefaultMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/Polyart/SharedResources/Characters/Blueprints/Input/IMC_Default.IMC_Default"));
DG 167: 		if (DefaultMappingContext)
DG 168: 		{
DG 169: 			MoveAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/Polyart/SharedResources/Characters/Blueprints/Input/Actions/IA_Move.IA_Move"));
DG 170: 			LookAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/Polyart/SharedResources/Characters/Blueprints/Input/Actions/IA_Look.IA_Look"));
DG 171: 			JumpAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/Polyart/SharedResources/Characters/Blueprints/Input/Actions/IA_Jump.IA_Jump"));
DG 172: 		}
DG 173: 	}
DG 174: 	if (!DefaultMappingContext)
DG 175: 	{
DG 176: 		BuildFallbackInput();
DG 177: 	}
DG 178: 
DG 179: 	if (APlayerController* PC = Cast<APlayerController>(Controller))
DG 180: 	{
DG 181: 		if (UEnhancedInputLocalPlayerSubsystem* Sub =
DG 182: 			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
DG 183: 		{
DG 184: 			if (DefaultMappingContext)
DG 185: 			{
DG 186: 				Sub->AddMappingContext(DefaultMappingContext, 0);
DG 187: 	\t\tif (BuiltMappingContext) { Sub->AddMappingContext(BuiltMappingContext, 0); }
DG 188: 			}
DG 189: 		}
DG 190: 	}
DG 191: }
DG 192: 
DG 193: void AVEILCharacter::BuildFallbackInput()
DG 194: {
DG 195: 	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
DG 196: 	// Used only when no editor-made Input assets are assigned.
DG 197: 	auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
DG 198: 	{
DG 199: 		UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
DG 200: 		Action->ValueType = Type;
DG 201: 		BuiltActions.Add(Action);
DG 202: 		return Action;
DG 203: 	};
DG 204: 
DG 205: 	MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
DG 206: 	LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
DG 207: 	JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
DG 208: 	SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
DG 209: 	DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
DG 210: 	AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
DG 211: 	FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
DG 212: 	InteractAction = MakeAction(TEXT("IA_Interact"), EInputActionValueType::Boolean);
DG 213: 
DG 214: 	BuiltMappingContext = NewObject<UInputMappingContext>(this, TEXT("IMC_VEIL_BuiltIn"), RF_Transient);
DG 215: 	UInputMappingContext* IMC = BuiltMappingContext;
RESTORE CHECK loads=0 built_adds=0
GUARD ANCHOR=1
VERIFY fallback call sites=2
--- BUILD LOG TAIL ---
LOG Using Unreal Build Accelerator local executor to run 4 action(s)
LOG   CPU 6 physical cores, 12 logical cores
LOG   Memory 15.84 GB physical, 20.16 GB/41.84 GB committed
LOG   UBA Storage capacity 40 GB
LOG [1/4] Compile [x64] VEILCharacter.cpp
LOG [2/4] Link [x64] UnrealEditor-VEIL.lib
LOG [3/4] Link [x64] UnrealEditor-VEIL.dll
LOG [4/4] WriteMetadata VEILEditor.target [NoUba]
LOG 
LOG Total time in Unreal Build Accelerator local executor: 6.25 seconds
LOG Output binary: C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe
LOG 
LOG Result: Succeeded
LOG Total execution time: 7.39 seconds
LOG Trace written to file C:\Users\Admin\AppData\Local\UnrealBuildTool\Trace.uba with size 5.8kb
PHI IR442 VERDICT: INPUT REPAIRED calls=2 build=OK
JOB 442 DONE

```
