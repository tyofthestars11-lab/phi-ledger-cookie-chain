# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 06:16:17 UTC

## STEP 1
```
=== FULL RUNTIME TEXT READ - BOTH PROJECTS (Jobs 328+329 closed the floor question by experiment: the PHI_GROUND slabs carry healthy collision - engine Cube, QueryAndPhysics, BlockAll, CTF_USE_DEFAULT, one box shape - and job 329 laid a guaranteed engine-Cube pad exactly under each spawn, top at z=0, saved, recooked BUILD SUCCESSFUL, and the pawns STILL fell through it in both games: VEIL -12341 to -17136, OMNI -12766 to -17597. A stock pawn cannot fall through a stock BlockAll cube. The fault is therefore in runtime code or config this seat has not yet read whole: job 324 printed the Character sources (clean) but only GREP lines of the GameModes, and the PHI instruments - MOVE TEST, CENSUS, TICKPROOF - live in files never printed. This job prints, in one pass: (1) every Source .cpp/.h file whose text contains PHI MOVE TEST, PHI CENSUS, or PHI GM TICKPROOF - full text; (2) both GameMode .cpp files full text; (3) DefaultEngine.ini and DefaultGame.ini full text for both projects. READ-ONLY.) ===
########## VEIL ##########
--- GAMEMODE FILE: D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp ---
#include "Game/VEILGameMode.h"
#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
// VEIL: THE LAST SIGNAL - game mode + player controller implementation.
#include "Systems/PHIVoice.h"
#include "Data/PHIItemRow.h"

#include "Blueprint/UserWidget.h"
#include "Character/VEILCharacter.h"
#include "Game/VEILMainMenu.h"
#include "Game/VEILPauseMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "VEIL.h"
#include "World/VEILWorldBuilder.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AVEILGameMode::AVEILGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AVEILCharacter::StaticClass();
	PlayerControllerClass = AVEILPlayerController::StaticClass();
	ReinforcementAgentClass = AVEILFactionAgent::StaticClass();
}

void AVEILGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("PHI GAMEMODE ALIVE: %s paused=%d"), *GetClass()->GetName(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);

	// PHI CENSUS: 2.5s after boot, read every tall static mesh actor's
	// bounds base in the LIVE world (baked + runtime alike). A floater
	// names itself here - no more arguing with photographs.
	{
		FTimerHandle CensusTimer;
		GetWorldTimerManager().SetTimer(CensusTimer, [this]()
		{
			int32 Total = 0; int32 Floaters = 0;
			for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
			{
				FVector Origin; FVector Extent;
				It->GetActorBounds(false, Origin, Extent);
				if (Extent.Z <= 100.f) continue;
				if (It->GetName().Contains(TEXT("Orb"))) continue;
				++Total;
				const float Base = Origin.Z - Extent.Z;
				if (Base > 5.f)
				{
					++Floaters;
					UE_LOG(LogTemp, Display,
						TEXT("PHI CENSUS FLOAT: %s base=%.1f height=%.1f"),
						*It->GetName(), Base, Extent.Z * 2.f);
				}
			}
			UE_LOG(LogTemp, Display,
				TEXT("PHI CENSUS: tall actors=%d floaters=%d"), Total, Floaters);
		}, 2.5f, false);
	}

	// Build the world FIRST: VEIL ships no level assets, so the district,
	// the light and the plaza are raised here, on whatever map the editor
	// or the game opened with. Then seat the runner on the plaza and wake
	// the first machines around him.
	// Placed worlds (the district / generated-world levels) already hold
	// the city as real actors - the runtime builder stands down there, so
	// one world is never built twice. On bare maps it still raises it.
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AVEILWorldBuilder>(
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->BuildWorld();
		if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
		{
			Pawn->SetActorLocation(Builder->PlazaCenter);
		}
		for (int32 i = 0; i < 3; ++i)
		{
			const float Angle = (2.f * PI / 3.f) * i;
			const FVector Loc(FMath::Cos(Angle) * 950.f,
				FMath::Sin(Angle) * 950.f, 240.f);
			if (AVEILFactionAgent* Agent =
				GetWorld()->SpawnActor<AVEILFactionAgent>(
					AVEILFactionAgent::StaticClass(), Loc,
					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
			{
				Agent->SpawnDefaultController();
			}
		}
	}

	// Seed the world systems with the authored starting data.
	if (UVEILDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UVEILDiscoveryManager>())
	{
		for (const FVEILMystery& Mystery : MysteriesToRegister)
		{
			Discovery->RegisterMystery(Mystery);
		}
		Discovery->OnMysterySolved.AddDynamic(this, &AVEILGameMode::HandleMysterySolved);
	}

	if (UVEILFactionManager* Factions = GetWorld()->GetSubsystem<UVEILFactionManager>())
	{
		for (const FVEILTerritory& Territory : TerritoriesToRegister)
		{
			Factions->RegisterTerritory(Territory);
		}
		if (ReinforcementAgentClass)
		{
			Factions->ReinforcementClass = ReinforcementAgentClass;
		}
	}

	SetPhase(EVEILGamePhase::Exploration);
	UE_LOG(LogVEIL, Log, TEXT("VEIL world booted. Phase: Exploration. Difficulty x%.2f"), DifficultyScale);
	FPHIVoice::Play(GetWorld(), TEXT("V01"));
}

void AVEILGameMode::SetPhase(EVEILGamePhase NewPhase)
{
	if (NewPhase == Phase) return;
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
	if (NewPhase == EVEILGamePhase::Resolution)
	{
		FPHIVoice::Play(GetWorld(), TEXT("V18"));
	}
}

void AVEILGameMode::HandleMysterySolved(FName MysteryId)
{
	UE_LOG(LogVEIL, Log, TEXT("Mystery solved (%s) - phase: Resolution"), *MysteryId.ToString());
	SetPhase(EVEILGamePhase::Resolution);
}

// ---------------------------------------------------------------------------
// Player Controller
// ---------------------------------------------------------------------------
AVEILPlayerController::AVEILPlayerController()
{
	// The C++ main menu is the default: a working menu with zero assets.
	MainMenuWidgetClass = UVEILMainMenu::StaticClass();
	PauseWidgetClass = UVEILPauseMenu::StaticClass();
}

static FTimerHandle GPhiTimerHandle;

void AVEILPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Timer cross-check: a 3-second one-shot on the world's own timer
	// manager. If world time advances, PhiOnTimerCheck fires and logs
	// it; if the clock stands frozen, the TICKPROOF shows it pending.
	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);

	if (HUDWidgetClass && IsLocalController())
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidget) HUDWidget->AddToViewport(0);
	}

	if (MainMenuWidgetClass && IsLocalController())
	{
		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidget)
		{
			MainMenuWidget->AddToViewport(20);
			SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
			SetInputMode(FInputModeGameAndUI());
			bShowMouseCursor = true;
			return;
		}
	}
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AVEILPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
	}
}

void AVEILPlayerController::TogglePauseMenu()
{
	bPauseOpen = !bPauseOpen;
	SetPause(bPauseOpen);

	if (bPauseOpen)
	{
		if (PauseWidgetClass && !PauseWidget)
		{
			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
		}
		if (PauseWidget) PauseWidget->AddToViewport(10);
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
	}
	else
	{
		if (PauseWidget) PauseWidget->RemoveFromParent();
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
}

void AVEILGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float GmProofClock = 0.f;
	GmProofClock += DeltaSeconds;
	if (GmProofClock >= 5.f)
	{
		GmProofClock = 0.f;
		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
	}
}

void AVEILPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float PcProofClock = 0.f;
	PcProofClock += DeltaSeconds;
	if (PcProofClock >= 5.f)
	{
		PcProofClock = 0.f;
		AVEILCharacter* PhiPawn = Cast<AVEILCharacter>(GetPawn());
		UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF: world=%s sameWorld=%d worldTime=%.2f worldDelta=%.4f dilation=%.3f pcTick=%d pcCanTick=%d pawn=%s pawnTick=%d pawnCanTick=%d pawnBegun=%d pawnTickEntries=%d timerActive=%d worldType=%d gameWorld=%d worldBegun=%d timerRemaining=%.2f"),
			GetWorld() ? *GetWorld()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->GetWorld() == GetWorld()) ? 1 : 0,
			GetWorld()->GetTimeSeconds(), GetWorld()->GetDeltaSeconds(),
			UGameplayStatics::GetGlobalTimeDilation(this),
			IsActorTickEnabled() ? 1 : 0, PrimaryActorTick.bCanEverTick ? 1 : 0,
			GetPawn() ? *GetPawn()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->IsActorTickEnabled()) ? 1 : 0,
			(GetPawn() && GetPawn()->PrimaryActorTick.bCanEverTick) ? 1 : 0,
			(GetPawn() && GetPawn()->HasActorBegunPlay()) ? 1 : 0,
			PhiPawn ? PhiPawn->PhiTickEntryCount : -1,
			GetWorldTimerManager().IsTimerActive(GPhiTimerHandle) ? 1 : 0,
			(int32)GetWorld()->WorldType, GetWorld()->IsGameWorld() ? 1 : 0,
			GetWorld()->HasBegunPlay() ? 1 : 0,
			GetWorldTimerManager().GetTimerRemaining(GPhiTimerHandle));
	}
}

void AVEILPlayerController::PhiOnTimerCheck()
{
	UE_LOG(LogTemp, Display, TEXT("PHI TIMER CHECK FIRED: worldTime=%.2f"), GetWorld()->GetTimeSeconds());
}
--- CONFIG: DefaultEngine.ini ---
[/Script/EngineSettings.GameMapsSettings]
; VEIL ships a real level now: /Game/Maps/VEILDistrict (75 placed
; actors, job-verified 2026-10-27) is the default + startup map.
; The GameMode stays the global default on EVERY map: on bare maps
; its runtime builder raises the district; on placed maps it stands
; down and the placed world is the world.
GlobalDefaultGameMode=/Script/VEIL.VEILGameMode
GameInstanceClass=/Script/Engine.GameInstance
GameDefaultMap=/Game/Maps/VEILDistrict
EditorStartupMap=/Game/Maps/VEILDistrict

[/Script/NavigationSystem.NavigationSystemV1]
; Navigation generates itself at runtime - the editor's navigation
; build lock (flags: 0x4) is dead permanently, editor and package.
RuntimeGeneration=Dynamic
bAutoCreateNavigationData=True
bAllowClientSideNavigation=True

[/Script/Engine.RendererSettings]
; Consolidated 2026-10-27 (repo is the single source the lane syncs
; from - PC-side ini surgery alone got clobbered by config syncs).
; RTX 3050 6 GB: Lumen on (software tracing), distance fields on,
; virtual shadows on with capped pages, TSR temporal upscaling at
; 66.6667% history (Google's block, checked against brief section 8).
r.DynamicGlobalIlluminationMethod=1
r.ReflectionMethod=1
r.GenerateMeshDistanceFields=True
r.AllowStaticLighting=True
r.Shadow.Virtual.Enable=1
r.Shadow.Virtual.MaxPhysicalPages=2048
r.DynamicRes.OperationMode=0
r.AntiAliasingMethod=4
r.TSR.History.ScreenPercentage=66.6667
r.TSR.Velocity.Quality=1
r.TSR.Sharpness=1.0
r.Lumen.HardwareRayTracing=0
r.Lumen.TraceDistance=10000.0
r.Lumen.Reflections.Allow=1

[/Script/Engine.Engine]
+ActiveGameNameRedirects=(OldGameName="TP_Blank",NewGameName="/Script/VEIL")

[/Script/NavigationSystem.RecastNavMesh]
bRebuildAtRuntime=True
CellSize=19.0
CellHeight=10.0
AgentMaxSlope=45.0

[/Script/WindowsTargetPlatform.WindowsTargetSettings]
TargetedRHIs=PCD3D_SM6

[/Script/AndroidFileServerEditor.AndroidFileServerRuntimeSettings]
bEnablePlugin=True
bAllowNetworkConnection=True
SecurityToken=9294B1BC45C1648BE5F71F9B793FFCB1
bIncludeInShipping=False
bAllowExternalStartInShipping=False
bCompileAFSProject=False
bUseCompression=False
bLogFiles=False
bReportStats=False
ConnectionType=USBOnly
bUseManualIPAddress=False
ManualIPAddress=

--- CONFIG: DefaultGame.ini ---
[/Script/EngineSettings.GeneralProjectSettings]
ProjectID=(A=1159433900,B=-1466087078,C=-1555615385,D=245961667)
ProjectName=VEIL: THE LAST SIGNAL
Description=Original sci-fi RPG - Prototype 01 foundation.

[StartupActions]
; Keep the first load small: one persistent test level, streamed districts.
[/Script/Engine.AssetManagerSettings]
+PrimaryAssetTypesToScan=(PrimaryAssetType="GameFeatureData",AssetBaseClass="/Script/GameFeatures.GameFeatureData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game")),Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))
########## OMNI ##########
--- GAMEMODE FILE: D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp ---
#include "Game/OMNIGameMode.h"
#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
// OMNI: THE LAST SIGNAL - game mode + player controller implementation.
#include "Data/PHIItemRow.h"

#include "Blueprint/UserWidget.h"
#include "Character/OMNICharacter.h"
#include "Game/OMNIMainMenu.h"
#include "Game/OMNIPauseMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "OMNI.h"
#include "World/OMNIQuestContent.h"
#include "World/OMNIWorldBuilder.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AOMNIGameMode::AOMNIGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AOMNICharacter::StaticClass();
	PlayerControllerClass = AOMNIPlayerController::StaticClass();
	ReinforcementAgentClass = AOMNIFactionAgent::StaticClass();
}

void AOMNIGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("PHI GAMEMODE ALIVE: %s paused=%d"), *GetClass()->GetName(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);

	// PHI CENSUS: 2.5s after boot, read every tall static mesh actor's
	// bounds base in the LIVE world (baked + runtime alike). A floater
	// names itself here - no more arguing with photographs.
	{
		FTimerHandle CensusTimer;
		GetWorldTimerManager().SetTimer(CensusTimer, [this]()
		{
			int32 Total = 0; int32 Floaters = 0;
			for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
			{
				FVector Origin; FVector Extent;
				It->GetActorBounds(false, Origin, Extent);
				if (Extent.Z <= 100.f) continue;
				if (It->GetName().Contains(TEXT("Orb"))) continue;
				++Total;
				const float Base = Origin.Z - Extent.Z;
				if (Base > 5.f)
				{
					++Floaters;
					UE_LOG(LogTemp, Display,
						TEXT("PHI CENSUS FLOAT: %s base=%.1f height=%.1f"),
						*It->GetName(), Base, Extent.Z * 2.f);
				}
			}
			UE_LOG(LogTemp, Display,
				TEXT("PHI CENSUS: tall actors=%d floaters=%d"), Total, Floaters);
		}, 2.5f, false);
	}

	// Build the world FIRST: OMNI ships no level assets, so the district,
	// the light and the plaza are raised here, on whatever map the editor
	// or the game opened with. Then seat the runner on the plaza and wake
	// the first machines around him.
	// Placed worlds (the district / generated-world levels) already hold
	// the city as real actors - the runtime builder stands down there, so
	// one world is never built twice. On bare maps it still raises it.
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AOMNIWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AOMNIWorldBuilder>(
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->BuildWorld();
		if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
		{
			Pawn->SetActorLocation(Builder->PlazaCenter);
		}
		for (int32 i = 0; i < 3; ++i)
		{
			const float Angle = (2.f * PI / 3.f) * i;
			const FVector Loc(FMath::Cos(Angle) * 950.f,
				FMath::Sin(Angle) * 950.f, 240.f);
			if (AOMNIFactionAgent* Agent =
				GetWorld()->SpawnActor<AOMNIFactionAgent>(
					AOMNIFactionAgent::StaticClass(), Loc,
					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
			{
				Agent->SpawnDefaultController();
			}
		}
	}

	// OMNI RPG content: the three statues on the plaza ring, three
	// fragments out in the streets, the cache at the south wall. The
	// quest system (UOMNIQuestSystem) runs the chain between them.
	{
		const TCHAR* Names[3] = { TEXT("Keeper"), TEXT("Seer"), TEXT("Cartographer") };
		const FVector Spots[3] = {
			FVector(900.f, 0.f, 10.f), FVector(-450.f, 780.f, 10.f), FVector(-450.f, -780.f, 10.f) };
		const float Yaws[3] = { 180.f, -60.f, 60.f };
		for (int32 i = 0; i < 3; ++i)
		{
			const FTransform T(FRotator(0.f, Yaws[i], 0.f), Spots[i]);
			if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
				AOMNIQuestGiver::StaticClass(), T))
			{
				Giver->GiverName = FName(Names[i]);
				Giver->FinishSpawning(T);
			}
		}
		const FVector Shards[3] = {
			FVector(2000.f, 500.f, 260.f), FVector(-2000.f, -900.f, 260.f), FVector(600.f, -2100.f, 260.f) };
		for (int32 i = 0; i < 3; ++i)
		{
			GetWorld()->SpawnActor<AOMNIFragment>(
				AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
		}
		GetWorld()->SpawnActor<AOMNICache>(
			AOMNICache::StaticClass(), FVector(0.f, -6200.f, 10.f), FRotator::ZeroRotator);
	}

	// Seed the world systems with the authored starting data.
	if (UOMNIDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UOMNIDiscoveryManager>())
	{
		for (const FOMNIMystery& Mystery : MysteriesToRegister)
		{
			Discovery->RegisterMystery(Mystery);
		}
		Discovery->OnMysterySolved.AddDynamic(this, &AOMNIGameMode::HandleMysterySolved);
	}

	if (UOMNIFactionManager* Factions = GetWorld()->GetSubsystem<UOMNIFactionManager>())
	{
		for (const FOMNITerritory& Territory : TerritoriesToRegister)
		{
			Factions->RegisterTerritory(Territory);
		}
		if (ReinforcementAgentClass)
		{
			Factions->ReinforcementClass = ReinforcementAgentClass;
		}
	}

	SetPhase(EOMNIGamePhase::Exploration);
	UE_LOG(LogOMNI, Log, TEXT("OMNI world booted. Phase: Exploration. Difficulty x%.2f"), DifficultyScale);
}

void AOMNIGameMode::SetPhase(EOMNIGamePhase NewPhase)
{
	if (NewPhase == Phase) return;
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
}

void AOMNIGameMode::HandleMysterySolved(FName MysteryId)
{
	UE_LOG(LogOMNI, Log, TEXT("Mystery solved (%s) - phase: Resolution"), *MysteryId.ToString());
	SetPhase(EOMNIGamePhase::Resolution);
}

// ---------------------------------------------------------------------------
// Player Controller
// ---------------------------------------------------------------------------
AOMNIPlayerController::AOMNIPlayerController()
{
	// The C++ main menu is the default: a working menu with zero assets.
	MainMenuWidgetClass = UOMNIMainMenu::StaticClass();
	PauseWidgetClass = UOMNIPauseMenu::StaticClass();
}

static FTimerHandle GPhiTimerHandle;

void AOMNIPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Timer cross-check: a 3-second one-shot on the world's own timer
	// manager. If world time advances, PhiOnTimerCheck fires and logs
	// it; if the clock stands frozen, the TICKPROOF shows it pending.
	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AOMNIPlayerController::PhiOnTimerCheck, 3.0f, false);

	if (HUDWidgetClass && IsLocalController())
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidget) HUDWidget->AddToViewport(0);
	}

	if (MainMenuWidgetClass && IsLocalController())
	{
		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidget)
		{
			MainMenuWidget->AddToViewport(20);
			SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
			SetInputMode(FInputModeGameAndUI());
			bShowMouseCursor = true;
			return;
		}
	}
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AOMNIPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
	}
}

void AOMNIPlayerController::TogglePauseMenu()
{
	bPauseOpen = !bPauseOpen;
	SetPause(bPauseOpen);

	if (bPauseOpen)
	{
		if (PauseWidgetClass && !PauseWidget)
		{
			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
		}
		if (PauseWidget) PauseWidget->AddToViewport(10);
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
	}
	else
	{
		if (PauseWidget) PauseWidget->RemoveFromParent();
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
}

void AOMNIGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float GmProofClock = 0.f;
	GmProofClock += DeltaSeconds;
	if (GmProofClock >= 5.f)
	{
		GmProofClock = 0.f;
		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
	}
}

void AOMNIPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float PcProofClock = 0.f;
	PcProofClock += DeltaSeconds;
	if (PcProofClock >= 5.f)
	{
		PcProofClock = 0.f;
		AOMNICharacter* PhiPawn = Cast<AOMNICharacter>(GetPawn());
		UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF: world=%s sameWorld=%d worldTime=%.2f worldDelta=%.4f dilation=%.3f pcTick=%d pcCanTick=%d pawn=%s pawnTick=%d pawnCanTick=%d pawnBegun=%d pawnTickEntries=%d timerActive=%d worldType=%d gameWorld=%d worldBegun=%d timerRemaining=%.2f"),
			GetWorld() ? *GetWorld()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->GetWorld() == GetWorld()) ? 1 : 0,
			GetWorld()->GetTimeSeconds(), GetWorld()->GetDeltaSeconds(),
			UGameplayStatics::GetGlobalTimeDilation(this),
			IsActorTickEnabled() ? 1 : 0, PrimaryActorTick.bCanEverTick ? 1 : 0,
			GetPawn() ? *GetPawn()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->IsActorTickEnabled()) ? 1 : 0,
			(GetPawn() && GetPawn()->PrimaryActorTick.bCanEverTick) ? 1 : 0,
			(GetPawn() && GetPawn()->HasActorBegunPlay()) ? 1 : 0,
			PhiPawn ? PhiPawn->PhiTickEntryCount : -1,
			GetWorldTimerManager().IsTimerActive(GPhiTimerHandle) ? 1 : 0,
			(int32)GetWorld()->WorldType, GetWorld()->IsGameWorld() ? 1 : 0,
			GetWorld()->HasBegunPlay() ? 1 : 0,
			GetWorldTimerManager().GetTimerRemaining(GPhiTimerHandle));
	}
}

void AOMNIPlayerController::PhiOnTimerCheck()
{
	UE_LOG(LogTemp, Display, TEXT("PHI TIMER CHECK FIRED: worldTime=%.2f"), GetWorld()->GetTimeSeconds());
}
--- CONFIG: DefaultEngine.ini ---
[/Script/EngineSettings.GameMapsSettings]
; OMNI's placed levels (OMNIDistrict / OMNIWorld, built by its
; editor scripts) become the defaults the day their umaps verify.
; Until then the GameMode is the global default on EVERY map: on
; bare maps its runtime builder raises the district; on placed
; maps it stands down and the placed world is the world.
GlobalDefaultGameMode=/Script/OMNI.OMNIGameMode
GameInstanceClass=/Script/Engine.GameInstance
GameDefaultMap=/Game/Maps/OMNIWorld
EditorStartupMap=/Game/Maps/OMNIWorld

[/Script/NavigationSystem.NavigationSystemV1]
; Navigation generates itself at runtime - the editor's navigation
; build lock (flags: 0x4) is dead permanently, editor and package.
RuntimeGeneration=Dynamic
bAutoCreateNavigationData=True
bAllowClientSideNavigation=True

[/Script/Engine.RendererSettings]
; Consolidated 2026-10-27 (repo is the single source the lane syncs
; from - PC-side ini surgery alone got clobbered by config syncs).
; RTX 3050 6 GB: Lumen on (software tracing), distance fields on,
; virtual shadows on with capped pages, TSR temporal upscaling at
; 66.6667% history (Google's block, checked against brief section 8).
r.DynamicGlobalIlluminationMethod=1
r.ReflectionMethod=1
r.GenerateMeshDistanceFields=True
r.AllowStaticLighting=True
r.Shadow.Virtual.Enable=1
r.Shadow.Virtual.MaxPhysicalPages=2048
r.DynamicRes.OperationMode=0
r.AntiAliasingMethod=4
r.TSR.History.ScreenPercentage=66.6667
r.TSR.Velocity.Quality=1
r.TSR.Sharpness=1.0
r.Lumen.HardwareRayTracing=0
r.Lumen.TraceDistance=10000.0
r.Lumen.Reflections.Allow=1

[/Script/Engine.Engine]
+ActiveGameNameRedirects=(OldGameName="TP_Blank",NewGameName="/Script/OMNI")

[/Script/NavigationSystem.RecastNavMesh]
bRebuildAtRuntime=True
CellSize=19.0
CellHeight=10.0
AgentMaxSlope=45.0

[/Script/WindowsTargetPlatform.WindowsTargetSettings]
TargetedRHIs=PCD3D_SM6

[/Script/AndroidFileServerEditor.AndroidFileServerRuntimeSettings]
bEnablePlugin=True
bAllowNetworkConnection=True
SecurityToken=4238A05F4350D029AAEC28AD96D9604C
bIncludeInShipping=False
bAllowExternalStartInShipping=False
bCompileAFSProject=False
bUseCompression=False
bLogFiles=False
bReportStats=False
ConnectionType=USBOnly
bUseManualIPAddress=False
ManualIPAddress=

--- CONFIG: DefaultGame.ini ---
[/Script/EngineSettings.GeneralProjectSettings]
ProjectID=(A=-597799695,B=-45266850,C=-1729025130,D=-1354507444)
ProjectName=OMNI RPG: PATH OF LIGHT
Description=Original sci-fi RPG - Prototype 01 foundation.

[StartupActions]
; Keep the first load small: one persistent test level, streamed districts.
[/Script/Engine.AssetManagerSettings]
+PrimaryAssetTypesToScan=(PrimaryAssetType="GameFeatureData",AssetBaseClass="/Script/GameFeatures.GameFeatureData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game")),Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))
RUNTIME TEXT READ DONE

Select-String : A parameter cannot be found that matches parameter name 'Recurse'.
At C:\Users\Admin\AppData\Local\Temp\phi-step-59ac75d0c6ab46ed9748082571a8beaa.ps1:5 char:71
+ ... String -Path "$proj\Source\*.cpp","$proj\Source\*.h" -Recurse -Patter ...
+                                                          ~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Select-String], ParameterBindingException
    + FullyQualifiedErrorId : NamedParameterNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 
Select-String : A parameter cannot be found that matches parameter name 'Recurse'.
At C:\Users\Admin\AppData\Local\Temp\phi-step-59ac75d0c6ab46ed9748082571a8beaa.ps1:6 char:64
+ ...  $hits) { $hits = Select-String -Path "$proj\Source" -Recurse -Includ ...
+                                                          ~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Select-String], ParameterBindingException
    + FullyQualifiedErrorId : NamedParameterNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 
Select-String : A parameter cannot be found that matches parameter name 'Recurse'.
At C:\Users\Admin\AppData\Local\Temp\phi-step-59ac75d0c6ab46ed9748082571a8beaa.ps1:5 char:71
+ ... String -Path "$proj\Source\*.cpp","$proj\Source\*.h" -Recurse -Patter ...
+                                                          ~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Select-String], ParameterBindingException
    + FullyQualifiedErrorId : NamedParameterNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 
Select-String : A parameter cannot be found that matches parameter name 'Recurse'.
At C:\Users\Admin\AppData\Local\Temp\phi-step-59ac75d0c6ab46ed9748082571a8beaa.ps1:6 char:64
+ ...  $hits) { $hits = Select-String -Path "$proj\Source" -Recurse -Includ ...
+                                                          ~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Select-String], ParameterBindingException
    + FullyQualifiedErrorId : NamedParameterNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 

```
