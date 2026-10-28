# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 05:57:53 UTC

## STEP 1
```
=== REPAIR LOG TRUTH + PAWN SOURCE TRUTH - READ-ONLY (Jobs 321/322 returned with NO PHI GROUND REPAIR lines in either result - the commandlet output the jobs grepped came back empty, so whether the slab repair ran at all is unread. And VEILs recook in 321 exited 1 Error_Unknown while OMNIs in 322 succeeded and STILL falls at spawn. Meanwhile the other seats capsule theory targets a Blueprint - but job 286 measured the pawns as C++ classes: VEILCharacter.cpp and OMNICharacter.cpp. Her truth is in her source code. This job reads, in one pass: (1) both groundrepair commandlet logs - tails plus any PHI/Error/Exception lines - settling whether the repair executed; (2) VEILs repaircook321.log error context - why that recook exited 1; (3) BOTH character source files, cpp and h, printed whole - capsule setup, movement setup, mesh setup, constructor truth; (4) DefaultPawnClass wiring from the GameMode sources. READ-ONLY: nothing edited.) ===
##### groundrepair logs #####
--- D:\VEIL\Saved\groundrepair321.log ---
size 64.3 KB
[2026.10.28-05.49.26:430][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL\VEIL.uproject -run=pythonscript -script=D:\VEIL\Saved\phi_ground_repair.py -unattended -nopause -nosplash""
[2026.10.28-05.49.34:386][  0]LogPython: Display: No pip-enabled plugins with python dependencies found, skipping
[2026.10.28-05.49.34:916][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.35:614][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... took 698.219 ms
[2026.10.28-05.49.35:615][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.35:676][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... took 61.415 ms (total: 759.634 ms)
[2026.10.28-05.49.35:676][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.35:996][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... took 319.378 ms (total: 1.07 sec)
[2026.10.28-05.49.35:996][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:033][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... took 37.054 ms (total: 1.11 sec)
[2026.10.28-05.49.36:033][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:328][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... took 294.795 ms (total: 1.41 sec)
[2026.10.28-05.49.36:328][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:359][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... took 30.824 ms (total: 1.44 sec)
[2026.10.28-05.49.36:359][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:382][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 22.704 ms (total: 1.46 sec)
[2026.10.28-05.49.36:383][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:499][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 116.895 ms (total: 1.58 sec)
[2026.10.28-05.49.36:500][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.28-05.49.36:507][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 7.036 ms (total: 1.58 sec)
[2026.10.28-05.49.36:507][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL\Saved\phi_ground_repair.py
[2026.10.28-05.49.36:700][  0]LogPython: Warning: D:/VEIL/Saved/phi_ground_repair.py:13: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
[2026.10.28-05.49.36:819][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.28-05.49.36:819][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.28-05.49.36:820][  0]LogInit: Display: LogPython: Warning: D:/VEIL/Saved/phi_ground_repair.py:13: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
[2026.10.28-05.49.36:820][  0]LogInit: Display: Success - 0 error(s), 5 warning(s)
...tail...
[2026.10.28-05.49.36:833][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.28-05.49.36:833][  0]LogToolsetRegistry: Display: Unregistering Toolset AutomationTestToolset.AutomationTestToolset
[2026.10.28-05.49.36:833][  0]LogToolsetRegistry: Display: Unregistering Toolset SlateInspectorToolset.SlateInspectorToolset
[2026.10.28-05.49.36:950][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.28-05.49.36:950][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.28-05.49.37:174][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
--- D:\OMNI-UE\Saved\groundrepair322.log ---
size 64.4 KB
[2026.10.28-05.50.52:495][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\OMNI-UE\OMNI.uproject -run=pythonscript -script=D:\OMNI-UE\Saved\phi_ground_repair.py -unattended -nopause -nosplash""
[2026.10.28-05.50.59:882][  0]LogPython: Display: No pip-enabled plugins with python dependencies found, skipping
[2026.10.28-05.51.00:387][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:448][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... took 61.491 ms
[2026.10.28-05.51.00:448][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:453][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... took 4.884 ms (total: 66.375 ms)
[2026.10.28-05.51.00:453][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:513][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... took 59.857 ms (total: 126.232 ms)
[2026.10.28-05.51.00:513][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:517][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... took 3.742 ms (total: 129.975 ms)
[2026.10.28-05.51.00:517][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:579][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... took 61.689 ms (total: 191.665 ms)
[2026.10.28-05.51.00:579][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:582][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... took 3.438 ms (total: 195.104 ms)
[2026.10.28-05.51.00:582][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:583][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 226 us (total: 195.330 ms)
[2026.10.28-05.51.00:583][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:586][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 2.897 ms (total: 198.227 ms)
[2026.10.28-05.51.00:586][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.28-05.51.00:606][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 20.522 ms (total: 218.750 ms)
[2026.10.28-05.51.00:607][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\OMNI-UE\Saved\phi_ground_repair.py
[2026.10.28-05.51.00:844][  0]LogPython: Warning: D:/OMNI-UE/Saved/phi_ground_repair.py:13: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
[2026.10.28-05.51.00:989][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.28-05.51.00:989][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.28-05.51.00:989][  0]LogInit: Display: LogPython: Warning: D:/OMNI-UE/Saved/phi_ground_repair.py:13: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
[2026.10.28-05.51.00:989][  0]LogInit: Display: Success - 0 error(s), 5 warning(s)
...tail...
[2026.10.28-05.51.01:001][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.28-05.51.01:001][  0]LogToolsetRegistry: Display: Unregistering Toolset AutomationTestToolset.AutomationTestToolset
[2026.10.28-05.51.01:001][  0]LogToolsetRegistry: Display: Unregistering Toolset SlateInspectorToolset.SlateInspectorToolset
[2026.10.28-05.51.01:108][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.28-05.51.01:108][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.28-05.51.01:246][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
##### repaircook321 error context #####
LogInit: Display:
LogInit: Display: Warning/Error Summary (Unique only)
LogInit: Display: -----------------------------------
...
LogInit: Display:
LogInit: Display: Success - 0 error(s), 4 warning(s)
LogInit: Display:
...
Reading oplog from http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows/entries?trim_by_referencedset=true
Failed reading oplog from Zen at [::1]:8558 for oplog VEIL.209c94b5.Windows: One or more errors occurred. (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: An error occurred while sending the request.) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)) (Failed to send op attachment request to Zen at http://[::1]:8558/prj/VEIL.209c94b5/oplog/Windows: No connection could be made because the target machine actively refused it. ([::1]:8558)).
(see C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt for full exception trace)
...
AutomationTool executed for 0h 0m 30s
AutomationTool exiting with ExitCode=1 (Error_Unknown)
BUILD FAILED
...
##### character sources #####
--- D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp ---
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
--- D:\VEIL\Source\VEIL\Public\Character\VEILCharacter.h ---
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
--- D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp ---
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
--- D:\OMNI-UE\Source\OMNI\Public\Character\OMNICharacter.h ---
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
##### pawn class wiring #####
VEILGameMode.cpp: #include "Character/VEILCharacter.h"
VEILGameMode.cpp: DefaultPawnClass = AVEILCharacter::StaticClass();
VEILGameMode.cpp: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp: if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
VEILGameMode.cpp: Pawn->SetActorLocation(Builder->PlazaCenter);
VEILGameMode.cpp: GetWorld()->SpawnActor<AVEILFactionAgent>(
VEILGameMode.cpp: Agent->SpawnDefaultController();
VEILGameMode.cpp: SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
VEILGameMode.cpp: AVEILCharacter* PhiPawn = Cast<AVEILCharacter>(GetPawn());
VEILGameMode.cpp: UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF: world=%s sameWorld=%d worldTime=%.2f worldDelta=%.4f dilation=%.3f pcTick=%d pcCanTick=%d pawn=%s pawnTick=%d pawnCanTick=%d pawnBegun=%d pawnTickEntries=%d timerActive=%d worldType=%d gameWorld=%d worldBegun=%d timerRemaining=%.2f"),
VEILGameMode.cpp: (GetPawn() && GetPawn()->GetWorld() == GetWorld()) ? 1 : 0,
VEILGameMode.cpp: GetPawn() ? *GetPawn()->GetName() : TEXT("none"),
VEILGameMode.cpp: (GetPawn() && GetPawn()->IsActorTickEnabled()) ? 1 : 0,
VEILGameMode.cpp: (GetPawn() && GetPawn()->PrimaryActorTick.bCanEverTick) ? 1 : 0,
VEILGameMode.cpp: (GetPawn() && GetPawn()->HasActorBegunPlay()) ? 1 : 0,
VEILGameMode.cpp: PhiPawn ? PhiPawn->PhiTickEntryCount : -1,
OMNIGameMode.cpp: #include "Character/OMNICharacter.h"
OMNIGameMode.cpp: DefaultPawnClass = AOMNICharacter::StaticClass();
OMNIGameMode.cpp: : GetWorld()->SpawnActor<AOMNIWorldBuilder>(
OMNIGameMode.cpp: if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
OMNIGameMode.cpp: Pawn->SetActorLocation(Builder->PlazaCenter);
OMNIGameMode.cpp: GetWorld()->SpawnActor<AOMNIFactionAgent>(
OMNIGameMode.cpp: Agent->SpawnDefaultController();
OMNIGameMode.cpp: if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
OMNIGameMode.cpp: Giver->FinishSpawning(T);
OMNIGameMode.cpp: GetWorld()->SpawnActor<AOMNIFragment>(
OMNIGameMode.cpp: GetWorld()->SpawnActor<AOMNICache>(
OMNIGameMode.cpp: SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
OMNIGameMode.cpp: AOMNICharacter* PhiPawn = Cast<AOMNICharacter>(GetPawn());
OMNIGameMode.cpp: UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF: world=%s sameWorld=%d worldTime=%.2f worldDelta=%.4f dilation=%.3f pcTick=%d pcCanTick=%d pawn=%s pawnTick=%d pawnCanTick=%d pawnBegun=%d pawnTickEntries=%d timerActive=%d worldType=%d gameWorld=%d worldBegun=%d timerRemaining=%.2f"),
OMNIGameMode.cpp: (GetPawn() && GetPawn()->GetWorld() == GetWorld()) ? 1 : 0,
OMNIGameMode.cpp: GetPawn() ? *GetPawn()->GetName() : TEXT("none"),
OMNIGameMode.cpp: (GetPawn() && GetPawn()->IsActorTickEnabled()) ? 1 : 0,
OMNIGameMode.cpp: (GetPawn() && GetPawn()->PrimaryActorTick.bCanEverTick) ? 1 : 0,
OMNIGameMode.cpp: (GetPawn() && GetPawn()->HasActorBegunPlay()) ? 1 : 0,
OMNIGameMode.cpp: PhiPawn ? PhiPawn->PhiTickEntryCount : -1,
PAWN TRUTH READ DONE

```
