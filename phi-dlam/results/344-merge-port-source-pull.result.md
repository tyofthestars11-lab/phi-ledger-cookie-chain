# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 07:14:07 UTC

## STEP 1
```
=== MERGE EXECUTION STEP 2 - PORT SOURCE PULL (Tyrees GO, 2026-10-28: Merge it. The systems port - OMNIs quest chain, phi XP ladder and WARDEN PRIME into the VEIL merged base - gets written from the PCs CURRENT sources, not the repos authored copies: job 340 measured the PC files larger than the repo originals (OMNIQuestSystem.cpp 4594 on PC vs 4449 in repo; OMNIGameMode.cpp 12647 vs 9876) because the voice wiring at the quest beats and the nights diagnostic tranches grew them on the PC. Porting from the repo would lose that growth. THIS JOB prints the full current text of every file the port touches: the six OMNI system files (QuestSystem, QuestContent, WardenPrime - header and cpp each), OMNIs current GameMode.cpp (the quest spawning lives there), VEILs current GameMode.cpp (the wiring must land inside it, diagnostics and all), and both FactionAI headers (the Warden derives from the faction agent - the port needs both class declarations named exactly). READ-ONLY: nothing on the PC changes.) ===
===== FILE D:\OMNI-UE\Source\OMNI\Public\Systems\OMNIQuestSystem.h =====
// OMNI RPG: PATH OF LIGHT - quest + progression system (Unreal port).
//
// The whole Godot game's spine as one WorldSubsystem: the six-stage chain
// (Keeper -> fragments -> Seer -> the cache -> WARDEN PRIME -> the clear),
// XP by the phi ladder (need = round(20 * phi^(level-1))), gold, and the
// warden's waking. Everything is proven in the log: every stage turn, XP
// gain and level prints an OMNI QUEST line the build jobs can read back.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OMNIQuestSystem.generated.h"

class AOMNIWardenPrime;

UENUM(BlueprintType)
enum class EOMNIQuestStage : uint8
{
	MeetKeeper,
	GatherFragments,
	MeetSeer,
	ReachCache,
	WardenAwake,
	Clear
};

UCLASS()
class OMNI_API UOMNIQuestSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	EOMNIQuestStage Stage = EOMNIQuestStage::MeetKeeper;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Gold = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Fragments = 0;

	/** XP needed to leave the given level: round(20 * phi^(level-1)). */
	static int32 XPNeedForLevel(int32 InLevel);

	void AwardXP(int32 Amount, const TCHAR* Reason);
	void TalkTo(FName Giver);
	void CollectFragment();
	void ReachCache();

private:
	void Poll();
	void WakeWarden();

	FTimerHandle PollHandle;
	TObjectPtr<AOMNIWardenPrime> Warden;
	bool bCartographerTipped = false;
};

===== END D:\OMNI-UE\Source\OMNI\Public\Systems\OMNIQuestSystem.h =====
===== FILE D:\OMNI-UE\Source\OMNI\Private\Systems\OMNIQuestSystem.cpp =====
// OMNI RPG: PATH OF LIGHT - quest + progression implementation.
#include "Systems/OMNIQuestSystem.h"
#include "Systems/PHIVoice.h"

#include "AI/OMNIWardenPrime.h"
#include "Engine/World.h"
#include "OMNI.h"
#include "TimerManager.h"

int32 UOMNIQuestSystem::XPNeedForLevel(int32 InLevel)
{
	const double Phi = 1.618033988749895;
	return FMath::RoundToInt(20.0 * FMath::Pow(Phi, (double)FMath::Max(0, InLevel - 1)));
}

void UOMNIQuestSystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	InWorld.GetTimerManager().SetTimer(PollHandle, this,
		&UOMNIQuestSystem::Poll, 0.5f, true);
	UE_LOG(LogOMNI, Log,
		TEXT("OMNI QUEST SYSTEM ONLINE: stage=MeetKeeper, level 1, first rung needs %d XP."),
		XPNeedForLevel(1));
	FPHIVoice::Play(&InWorld, TEXT("O01"));
}

void UOMNIQuestSystem::AwardXP(int32 Amount, const TCHAR* Reason)
{
	XP += Amount;
	UE_LOG(LogOMNI, Log, TEXT("OMNI XP +%d (%s) -> %d XP at level %d (rung needs %d)."),
		Amount, Reason, XP, Level, XPNeedForLevel(Level));
	while (XP >= XPNeedForLevel(Level))
	{
		XP -= XPNeedForLevel(Level);
		++Level;
		UE_LOG(LogOMNI, Log, TEXT("OMNI LEVEL UP: the Runner reaches level %d. Next rung needs %d XP."),
			Level, XPNeedForLevel(Level));
	}
}

void UOMNIQuestSystem::TalkTo(FName Giver)
{
	if (Giver == FName(TEXT("Keeper")))
	{
		if (Stage == EOMNIQuestStage::MeetKeeper)
		{
			Stage = EOMNIQuestStage::GatherFragments;
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Keeper]: \"The signal broke into three, Runner. Gather the fragments where the streets remember them.\" Stage -> GatherFragments."));
			FPHIVoice::Play(GetWorld(), TEXT("O03"));
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Keeper]: \"The plaza keeps what the towers cannot. Walk on.\""));
		}
	}
	else if (Giver == FName(TEXT("Seer")))
	{
		if (Stage == EOMNIQuestStage::MeetSeer)
		{
			Stage = EOMNIQuestStage::ReachCache;
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Seer]: \"Starlit, Runner. My cache sleeps by the south wall, green and glowing. Bring word of it - and wake what guards the beacon.\" Stage -> ReachCache."));
			FPHIVoice::Play(GetWorld(), TEXT("O08"));
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Seer]: \"I see the rungs you climb. They hold.\""));
		}
	}
	else if (Giver == FName(TEXT("Cartographer")))
	{
		if (!bCartographerTipped)
		{
			bCartographerTipped = true;
			Gold += 10;
			AwardXP(5, TEXT("the Cartographer's word"));
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Cartographer]: \"Every street in this district is a ratio, Runner. Take 10 gold for hearing it.\" Gold -> %d."), Gold);
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Cartographer]: \"The wall remembers what I cannot.\""));
		}
	}
}

void UOMNIQuestSystem::CollectFragment()
{
	++Fragments;
	AwardXP(15, TEXT("a fragment of the signal"));
	UE_LOG(LogOMNI, Log, TEXT("OMNI FRAGMENT %d/3 gathered."), Fragments);
	if (Stage == EOMNIQuestStage::GatherFragments && Fragments >= 3)
	{
		Stage = EOMNIQuestStage::MeetSeer;
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: the signal is whole in your hands. The Seer waits. Stage -> MeetSeer."));
		FPHIVoice::Play(GetWorld(), TEXT("O06"));
	}
}

void UOMNIQuestSystem::ReachCache()
{
	if (Stage != EOMNIQuestStage::ReachCache) return;
	Gold += 80;
	AwardXP(25, TEXT("the survey cache"));
	UE_LOG(LogOMNI, Log,
		TEXT("OMNI QUEST: cache claimed (+80 gold -> %d). The beacon answers - something stands up in the plaza."), Gold);
	WakeWarden();
}

void UOMNIQuestSystem::WakeWarden()
{
	UWorld* World = GetWorld();
	if (!World) return;
	const FVector Loc(0.f, -1200.f, 260.f);
	AOMNIWardenPrime* Boss = World->SpawnActor<AOMNIWardenPrime>(
		AOMNIWardenPrime::StaticClass(), Loc, FRotator(0.f, 90.f, 0.f));
	if (Boss)
	{
		Boss->SetActorScale3D(FVector(1.7f));
		Boss->SpawnDefaultController();
		Warden = Boss;
		Stage = EOMNIQuestStage::WardenAwake;
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: WARDEN PRIME HAS WOKEN at the plaza's south edge. Stage -> WardenAwake."));
		FPHIVoice::Play(GetWorld(), TEXT("O13"));
	}
}

void UOMNIQuestSystem::Poll()
{
	if (Stage == EOMNIQuestStage::WardenAwake && Warden && !Warden->IsAlive())
	{
		Stage = EOMNIQuestStage::Clear;
		Gold += 150;
		AwardXP(100, TEXT("WARDEN PRIME down"));
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: WARDEN PRIME DOWN - PATH OF LIGHT CLEAR. +150 gold -> %d. The beacon burns steady."), Gold);
		FPHIVoice::Play(GetWorld(), TEXT("O16"));
	}
}

===== END D:\OMNI-UE\Source\OMNI\Private\Systems\OMNIQuestSystem.cpp =====
===== FILE D:\OMNI-UE\Source\OMNI\Public\World\OMNIQuestContent.h =====
// OMNI RPG: PATH OF LIGHT - the quest's physical content.
//
// Statues that talk by standing close, fragments that gather by touch,
// the Seer's cache by the south wall. All overlap-driven: no input assets
// needed, the Runner's presence is the interaction.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OMNIQuestContent.generated.h"

class USphereComponent;
class UStaticMeshComponent;

// ---------------------------------------------------------------------------
// A talking statue: Keeper, Seer, Cartographer.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AOMNIQuestGiver : public AActor
{
	GENERATED_BODY()

public:
	AOMNIQuestGiver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Quest")
	FName GiverName = FName(TEXT("Keeper"));

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnTalkRadius(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	TObjectPtr<USphereComponent> TalkRadius;
	bool bSpokenThisVisit = false;
};

// ---------------------------------------------------------------------------
// A fragment of the broken signal: gold, turning, gathered by touch.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AOMNIFragment : public AActor
{
	GENERATED_BODY()

public:
	AOMNIFragment();
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	TObjectPtr<UStaticMeshComponent> Body;
	TObjectPtr<USphereComponent> TouchRadius;
	float BaseZ = 0.f;
};

// ---------------------------------------------------------------------------
// The Seer's survey cache: green, glowing, at the district's south wall.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AOMNICache : public AActor
{
	GENERATED_BODY()

public:
	AOMNICache();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOpened(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	TObjectPtr<USphereComponent> OpenRadius;
};

===== END D:\OMNI-UE\Source\OMNI\Public\World\OMNIQuestContent.h =====
===== FILE D:\OMNI-UE\Source\OMNI\Private\World\OMNIQuestContent.cpp =====
// OMNI RPG: PATH OF LIGHT - quest content implementation.
#include "World/OMNIQuestContent.h"

#include "Character/OMNICharacter.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "OMNI.h"
#include "Systems/OMNIQuestSystem.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
	void Tint(UStaticMeshComponent* Comp, const FLinearColor& Color, float Emissive)
	{
		if (!Comp) return;
		if (UMaterialInterface* Base = Comp->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, Comp))
			{
				MID->SetVectorParameterValue(TEXT("Color"), Color);
				MID->SetVectorParameterValue(TEXT("BaseColor"), Color);
				if (Emissive > 0.f)
				{
					MID->SetVectorParameterValue(TEXT("EmissiveColor"), Color * Emissive);
				}
				Comp->SetMaterial(0, MID);
			}
		}
	}

	USphereComponent* MakeRadius(AActor* Owner, USceneComponent* Root, float Radius)
	{
		USphereComponent* Sphere = NewObject<USphereComponent>(Owner);
		Sphere->SetupAttachment(Root);
		Sphere->InitSphereRadius(Radius);
		Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		Sphere->SetCollisionObjectType(ECC_WorldDynamic);
		Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
		Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
		Sphere->SetGenerateOverlapEvents(true);
		Sphere->RegisterComponent();
		return Sphere;
	}
}

// ---------------------------------------------------------------------------
// Giver
// ---------------------------------------------------------------------------
AOMNIQuestGiver::AOMNIQuestGiver()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(
		TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
		TEXT("/Engine/BasicShapes/Cube.Cube"));

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueBody"));
	Body->SetupAttachment(Root);
	Body->SetRelativeLocation(FVector(0.f, 0.f, 150.f));
	Body->SetRelativeScale3D(FVector(0.9f, 0.9f, 3.f));
	if (CylinderMesh.Succeeded()) Body->SetStaticMesh(CylinderMesh.Object);
	Tint(Body, FLinearColor(0.35f, 0.33f, 0.38f), 0.f);

	UStaticMeshComponent* Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueHead"));
	Head->SetupAttachment(Root);
	Head->SetRelativeLocation(FVector(0.f, 0.f, 345.f));
	Head->SetRelativeScale3D(FVector(0.55f, 0.55f, 0.55f));
	if (SphereMesh.Succeeded()) Head->SetStaticMesh(SphereMesh.Object);
	Tint(Head, FLinearColor(0.35f, 0.33f, 0.38f), 0.f);

	UStaticMeshComponent* Visor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueVisor"));
	Visor->SetupAttachment(Root);
	Visor->SetRelativeLocation(FVector(26.f, 0.f, 350.f));
	Visor->SetRelativeScale3D(FVector(0.10f, 0.5f, 0.10f));
	if (CubeMesh.Succeeded()) Visor->SetStaticMesh(CubeMesh.Object);
	Tint(Visor, FLinearColor(1.f, 0.78f, 0.30f), 3.f);
}

void AOMNIQuestGiver::BeginPlay()
{
	Super::BeginPlay();
	TalkRadius = MakeRadius(this, RootComponent, 340.f);
	TalkRadius->OnComponentBeginOverlap.AddDynamic(this, &AOMNIQuestGiver::OnTalkRadius);
	UE_LOG(LogOMNI, Log, TEXT("OMNI QUEST CONTENT: the %s stands ready."), *GiverName.ToString());
}

void AOMNIQuestGiver::OnTalkRadius(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (!Cast<AOMNICharacter>(OtherActor)) return;
	if (UOMNIQuestSystem* Quests = GetWorld()->GetSubsystem<UOMNIQuestSystem>())
	{
		Quests->TalkTo(GiverName);
	}
}

// ---------------------------------------------------------------------------
// Fragment
// ---------------------------------------------------------------------------
AOMNIFragment::AOMNIFragment()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FragmentBody"));
	Body->SetupAttachment(Root);
	Body->SetRelativeScale3D(FVector(0.45f, 0.45f, 0.45f));
	Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if (SphereMesh.Succeeded()) Body->SetStaticMesh(SphereMesh.Object);
	Tint(Body, FLinearColor(1.f, 0.78f, 0.30f), 3.5f);
}

void AOMNIFragment::BeginPlay()
{
	Super::BeginPlay();
	BaseZ = GetActorLocation().Z;
	TouchRadius = MakeRadius(this, RootComponent, 260.f);
	TouchRadius->OnComponentBeginOverlap.AddDynamic(this, &AOMNIFragment::OnTouched);
}

void AOMNIFragment::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AddActorLocalRotation(FRotator(0.f, 60.f * DeltaSeconds, 0.f));
	FVector Loc = GetActorLocation();
	Loc.Z = BaseZ + FMath::Sin(GetWorld()->GetTimeSeconds() * 1.7f) * 18.f;
	SetActorLocation(Loc);
}

void AOMNIFragment::OnTouched(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (!Cast<AOMNICharacter>(OtherActor)) return;
	if (UOMNIQuestSystem* Quests = GetWorld()->GetSubsystem<UOMNIQuestSystem>())
	{
		Quests->CollectFragment();
	}
	Destroy();
}

// ---------------------------------------------------------------------------
// Cache
// ---------------------------------------------------------------------------
AOMNICache::AOMNICache()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
		TEXT("/Engine/BasicShapes/Cube.Cube"));

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CacheBody"));
	Body->SetupAttachment(Root);
	Body->SetRelativeLocation(FVector(0.f, 0.f, 40.f));
	Body->SetRelativeScale3D(FVector(0.8f, 0.8f, 0.8f));
	if (CubeMesh.Succeeded()) Body->SetStaticMesh(CubeMesh.Object);
	Tint(Body, FLinearColor(0.15f, 0.9f, 0.35f), 2.5f);
}

void AOMNICache::BeginPlay()
{
	Super::BeginPlay();
	OpenRadius = MakeRadius(this, RootComponent, 300.f);
	OpenRadius->OnComponentBeginOverlap.AddDynamic(this, &AOMNICache::OnOpened);
	UE_LOG(LogOMNI, Log, TEXT("OMNI QUEST CONTENT: the survey cache sleeps by the south wall."));
}

void AOMNICache::OnOpened(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (!Cast<AOMNICharacter>(OtherActor)) return;
	if (UOMNIQuestSystem* Quests = GetWorld()->GetSubsystem<UOMNIQuestSystem>())
	{
		Quests->ReachCache();
	}
}

===== END D:\OMNI-UE\Source\OMNI\Private\World\OMNIQuestContent.cpp =====
===== FILE D:\OMNI-UE\Source\OMNI\Public\AI\OMNIWardenPrime.h =====
// OMNI RPG: PATH OF LIGHT - WARDEN PRIME, the plaza duel.
#pragma once

#include "CoreMinimal.h"
#include "AI/OMNIFactionAI.h"
#include "OMNIWardenPrime.generated.h"

UCLASS()
class OMNI_API AOMNIWardenPrime : public AOMNIFactionAgent
{
	GENERATED_BODY()

public:
	AOMNIWardenPrime();
};

===== END D:\OMNI-UE\Source\OMNI\Public\AI\OMNIWardenPrime.h =====
===== FILE D:\OMNI-UE\Source\OMNI\Private\AI\OMNIWardenPrime.cpp =====
// OMNI RPG: PATH OF LIGHT - WARDEN PRIME implementation.
#include "AI/OMNIWardenPrime.h"

#include "GameFramework/CharacterMovementComponent.h"

AOMNIWardenPrime::AOMNIWardenPrime()
{
	// The duel: twelve times a street machine's frame, a heavier hand,
	// a longer eye. Spawned at 1.7 scale by the quest system.
	MaxHealth = 900.f;
	Health = MaxHealth;
	WeaponDamage = 18.f;
	SightRange = 3200.f;
	AttackRange = 1600.f;
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}

===== END D:\OMNI-UE\Source\OMNI\Private\AI\OMNIWardenPrime.cpp =====
===== FILE D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp =====
#include "Game/OMNIGameMode.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/StaticMeshActor.h"
#include "EngineUtils.h"
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
		static float PhiDiagClock = 0.f;
		PhiDiagClock += DeltaSeconds;
		if (PhiDiagClock >= 0.f && PhiDiagClock < 1000.f)
		{
			PhiDiagClock = 500.f;
			if (ACharacter* DiagPawn = Cast<ACharacter>(GetPawn()))
			{
				UCapsuleComponent* Cap = DiagPawn->GetCapsuleComponent();
				UCharacterMovementComponent* CMove = DiagPawn->GetCharacterMovement();
				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR DIAG: world=%s capEnabled=%d capProfile=%s moveMode=%d onGround=%d floorBlock=%d floorActor=%s"),
					*GetWorld()->GetName(),
					Cap ? (int32)Cap->GetCollisionEnabled() : -1,
					Cap ? *Cap->GetCollisionProfileName().ToString() : TEXT("none"),
					CMove ? (int32)CMove->MovementMode : -1, (CMove && CMove->IsMovingOnGround()) ? 1 : 0,
					(CMove && CMove->CurrentFloor.bBlockingHit) ? 1 : 0,
					(CMove && CMove->CurrentFloor.HitResult.GetActor()) ? *CMove->CurrentFloor.HitResult.GetActor()->GetName() : TEXT("none"));
				const FVector PawnLoc = DiagPawn->GetActorLocation();
				FHitResult TraceHit;
				const FVector TraceStart(PawnLoc.X, PawnLoc.Y, 500.f);
				const FVector TraceEnd(PawnLoc.X, PawnLoc.Y, -500.f);
				const bool bTrace = GetWorld()->LineTraceSingleByChannel(TraceHit, TraceStart, TraceEnd, ECC_WorldStatic);
				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR TRACE: hit=%d actor=%s hitZ=%.1f pawnZ=%.1f"),
					bTrace ? 1 : 0, TraceHit.GetActor() ? *TraceHit.GetActor()->GetName() : TEXT("none"),
					TraceHit.Location.Z, PawnLoc.Z);
				int32 Printed = 0;
				for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
				{
					FVector Origin; FVector Extent;
					It->GetActorBounds(false, Origin, Extent);
					if (FMath::Abs(Origin.X - PawnLoc.X) < 2500.f && FMath::Abs(Origin.Y - PawnLoc.Y) < 2500.f && Printed < 12)
					{
						++Printed;
						UE_LOG(LogTemp, Display, TEXT("PHI FLOOR ACTOR: name=%s top=%.1f base=%.1f loc=X=%.0f Y=%.0f Z=%.0f collEnabled=%d"),
							*It->GetName(), Origin.Z + Extent.Z, Origin.Z - Extent.Z, Origin.X, Origin.Y, Origin.Z,
							It->GetStaticMeshComponent() ? (int32)It->GetStaticMeshComponent()->GetCollisionEnabled() : -1);
					}
				}
			}
		}
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

===== END D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp =====
===== FILE D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp =====
#include "Game/VEILGameMode.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/StaticMeshActor.h"
#include "EngineUtils.h"
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
		static float PhiDiagClock = 0.f;
		PhiDiagClock += DeltaSeconds;
		if (PhiDiagClock >= 0.f && PhiDiagClock < 1000.f)
		{
			PhiDiagClock = 500.f;
			if (ACharacter* DiagPawn = Cast<ACharacter>(GetPawn()))
			{
				UCapsuleComponent* Cap = DiagPawn->GetCapsuleComponent();
				UCharacterMovementComponent* CMove = DiagPawn->GetCharacterMovement();
				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR DIAG: world=%s capEnabled=%d capProfile=%s moveMode=%d onGround=%d floorBlock=%d floorActor=%s"),
					*GetWorld()->GetName(),
					Cap ? (int32)Cap->GetCollisionEnabled() : -1,
					Cap ? *Cap->GetCollisionProfileName().ToString() : TEXT("none"),
					CMove ? (int32)CMove->MovementMode : -1, (CMove && CMove->IsMovingOnGround()) ? 1 : 0,
					(CMove && CMove->CurrentFloor.bBlockingHit) ? 1 : 0,
					(CMove && CMove->CurrentFloor.HitResult.GetActor()) ? *CMove->CurrentFloor.HitResult.GetActor()->GetName() : TEXT("none"));
				const FVector PawnLoc = DiagPawn->GetActorLocation();
				FHitResult TraceHit;
				const FVector TraceStart(PawnLoc.X, PawnLoc.Y, 500.f);
				const FVector TraceEnd(PawnLoc.X, PawnLoc.Y, -500.f);
				const bool bTrace = GetWorld()->LineTraceSingleByChannel(TraceHit, TraceStart, TraceEnd, ECC_WorldStatic);
				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR TRACE: hit=%d actor=%s hitZ=%.1f pawnZ=%.1f"),
					bTrace ? 1 : 0, TraceHit.GetActor() ? *TraceHit.GetActor()->GetName() : TEXT("none"),
					TraceHit.Location.Z, PawnLoc.Z);
				int32 Printed = 0;
				for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
				{
					FVector Origin; FVector Extent;
					It->GetActorBounds(false, Origin, Extent);
					if (FMath::Abs(Origin.X - PawnLoc.X) < 2500.f && FMath::Abs(Origin.Y - PawnLoc.Y) < 2500.f && Printed < 12)
					{
						++Printed;
						UE_LOG(LogTemp, Display, TEXT("PHI FLOOR ACTOR: name=%s top=%.1f base=%.1f loc=X=%.0f Y=%.0f Z=%.0f collEnabled=%d"),
							*It->GetName(), Origin.Z + Extent.Z, Origin.Z - Extent.Z, Origin.X, Origin.Y, Origin.Z,
							It->GetStaticMeshComponent() ? (int32)It->GetStaticMeshComponent()->GetCollisionEnabled() : -1);
					}
				}
			}
		}
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

===== END D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp =====
===== FILE D:\OMNI-UE\Source\OMNI\Public\AI\OMNIFactionAI.h =====
// OMNI: THE LAST SIGNAL - faction AI.
// Four factions (Void, Scavenger, Guardian, Remnant), six-state agents,
// territory control, and a world-level Faction Manager (a WorldSubsystem).
// Self-contained: perception runs on a light timer, no Behavior Tree assets
// required to get the prototype moving.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Subsystems/WorldSubsystem.h"
#include "OMNIFactionAI.generated.h"

class AOMNIFactionAgent;

UENUM(BlueprintType)
enum class EOMNIFaction : uint8
{
	Void,
	Scavenger,
	Guardian,
	Remnant,
	None
};

UENUM(BlueprintType)
enum class EOMNIAgentState : uint8
{
	Patrol,
	Alert,
	Hunt,
	Combat,
	Defend,
	Retreat,
	Dead
};

USTRUCT(BlueprintType)
struct FOMNITerritory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOMNIFaction Owner = EOMNIFaction::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Center = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 2000.f;

	/** Higher = factions fight harder to hold / take it. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StrategicValue = 1.f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOMNITerritoryChanged, FName, TerritoryName, EOMNIFaction, OldOwner, EOMNIFaction, NewOwner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOMNIAgentStateChanged, AOMNIFactionAgent*, Agent, EOMNIAgentState, NewState);

// ---------------------------------------------------------------------------
// Agent
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AOMNIFactionAgent : public ACharacter
{
	GENERATED_BODY()

public:
	AOMNIFactionAgent();

	virtual void Tick(float DeltaSeconds) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Faction")
	EOMNIFaction Faction = EOMNIFaction::Void;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Faction")
	EOMNIAgentState State = EOMNIAgentState::Patrol;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Faction")
	FOMNIAgentStateChanged OnStateChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Health")
	float MaxHealth = 75.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Health")
	float Health = 75.f;

	/** Retreat below this fraction of MaxHealth. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	float RetreatHealthFraction = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	float SightRange = 2200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	float AttackRange = 1400.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	float WeaponDamage = 8.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	float FireInterval = 1.1f;

	/** Actors to walk between while patrolling (place Target Points). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	TArray<TObjectPtr<AActor>> PatrolPoints;

	/** Home ground this agent falls back to when defending / retreating. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|AI")
	FName HomeTerritory = NAME_None;

	UFUNCTION(BlueprintCallable, Category = "OMNI|Faction")
	void SetState(EOMNIAgentState NewState);

	UFUNCTION(BlueprintPure, Category = "OMNI|Faction")
	bool IsAlive() const { return State != EOMNIAgentState::Dead; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

private:
	void BindStoneBody();
	void MoveToward(const FVector& Dest, float AcceptRadius);
	void Perceive();
	void ActPatrol();
	void ActHunt();
	void ActCombat(float DeltaSeconds);
	void ActDefendOrRetreat(bool bRetreat);
	bool CanSeePlayer() const;

	TWeakObjectPtr<AActor> TargetActor;
	int32 PatrolIndex = 0;
	float LastFireTime = -100.f;
	FVector HomeLocation = FVector::ZeroVector;

	FTimerHandle PerceiveTimer;
};

// ---------------------------------------------------------------------------
// Faction Manager - one per world. Tracks every agent, faction power,
// territory ownership, and reinforcement spawns.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API UOMNIFactionManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Faction")
	FOMNITerritoryChanged OnTerritoryChanged;

	/** Agent class used for reinforcements (set by GameMode or in a BP subclass). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Faction")
	TSubclassOf<AOMNIFactionAgent> ReinforcementClass;

	void RegisterAgent(AOMNIFactionAgent* Agent);
	void UnregisterAgent(AOMNIFactionAgent* Agent);

	UFUNCTION(BlueprintCallable, Category = "OMNI|Faction")
	void RegisterTerritory(const FOMNITerritory& Territory);

	UFUNCTION(BlueprintCallable, Category = "OMNI|Faction")
	bool ClaimTerritory(FName TerritoryName, EOMNIFaction NewOwner);

	UFUNCTION(BlueprintPure, Category = "OMNI|Faction")
	EOMNIFaction GetTerritoryOwner(FName TerritoryName) const;

	/** Living agent count x average health: the faction's weight in the world. */
	UFUNCTION(BlueprintPure, Category = "OMNI|Faction")
	float GetFactionPower(EOMNIFaction Faction) const;

	UFUNCTION(BlueprintPure, Category = "OMNI|Faction")
	int32 GetLivingAgentCount(EOMNIFaction Faction) const;

	/** Spawn a fresh agent for a faction near a location (reinforcement wave). */
	UFUNCTION(BlueprintCallable, Category = "OMNI|Faction")
	AOMNIFactionAgent* SpawnReinforcement(EOMNIFaction Faction, FVector Location);

	/** Hostility matrix: who fights whom. Default: everyone fights Void;
	 *  Scavenger and Guardian are rivals; Remnant is defensive-neutral
	 *  (fights only when its territory is entered - handled in agent logic). */
	UFUNCTION(BlueprintPure, Category = "OMNI|Faction")
	bool IsHostile(EOMNIFaction A, EOMNIFaction B) const;

private:
	TArray<TWeakObjectPtr<AOMNIFactionAgent>> Agents;
	TArray<FOMNITerritory> Territories;
};

===== END D:\OMNI-UE\Source\OMNI\Public\AI\OMNIFactionAI.h =====
===== FILE D:\VEIL\Source\VEIL\Public\AI\VEILFactionAI.h =====
// VEIL: THE LAST SIGNAL - faction AI.
// Four factions (Void, Scavenger, Guardian, Remnant), six-state agents,
// territory control, and a world-level Faction Manager (a WorldSubsystem).
// Self-contained: perception runs on a light timer, no Behavior Tree assets
// required to get the prototype moving.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Subsystems/WorldSubsystem.h"
#include "VEILFactionAI.generated.h"

class AVEILFactionAgent;

UENUM(BlueprintType)
enum class EVEILFaction : uint8
{
	Void,
	Scavenger,
	Guardian,
	Remnant,
	None
};

UENUM(BlueprintType)
enum class EVEILAgentState : uint8
{
	Patrol,
	Alert,
	Hunt,
	Combat,
	Defend,
	Retreat,
	Dead
};

USTRUCT(BlueprintType)
struct FVEILTerritory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EVEILFaction Owner = EVEILFaction::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Center = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 2000.f;

	/** Higher = factions fight harder to hold / take it. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StrategicValue = 1.f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FVEILTerritoryChanged, FName, TerritoryName, EVEILFaction, OldOwner, EVEILFaction, NewOwner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVEILAgentStateChanged, AVEILFactionAgent*, Agent, EVEILAgentState, NewState);

// ---------------------------------------------------------------------------
// Agent
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AVEILFactionAgent : public ACharacter
{
	GENERATED_BODY()

public:
	AVEILFactionAgent();

	virtual void Tick(float DeltaSeconds) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Faction")
	EVEILFaction Faction = EVEILFaction::Void;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Faction")
	EVEILAgentState State = EVEILAgentState::Patrol;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Faction")
	FVEILAgentStateChanged OnStateChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Health")
	float MaxHealth = 75.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Health")
	float Health = 75.f;

	/** Retreat below this fraction of MaxHealth. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	float RetreatHealthFraction = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	float SightRange = 2200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	float AttackRange = 1400.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	float WeaponDamage = 8.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	float FireInterval = 1.1f;

	/** Actors to walk between while patrolling (place Target Points). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	TArray<TObjectPtr<AActor>> PatrolPoints;

	/** Home ground this agent falls back to when defending / retreating. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|AI")
	FName HomeTerritory = NAME_None;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Faction")
	void SetState(EVEILAgentState NewState);

	UFUNCTION(BlueprintPure, Category = "VEIL|Faction")
	bool IsAlive() const { return State != EVEILAgentState::Dead; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

private:
	void BindStoneBody();
	void MoveToward(const FVector& Dest, float AcceptRadius);
	void Perceive();
	void ActPatrol();
	void ActHunt();
	void ActCombat(float DeltaSeconds);
	void ActDefendOrRetreat(bool bRetreat);
	bool CanSeePlayer() const;

	TWeakObjectPtr<AActor> TargetActor;
	int32 PatrolIndex = 0;
	float LastFireTime = -100.f;
	FVector HomeLocation = FVector::ZeroVector;

	FTimerHandle PerceiveTimer;
};

// ---------------------------------------------------------------------------
// Faction Manager - one per world. Tracks every agent, faction power,
// territory ownership, and reinforcement spawns.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API UVEILFactionManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Faction")
	FVEILTerritoryChanged OnTerritoryChanged;

	/** Agent class used for reinforcements (set by GameMode or in a BP subclass). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Faction")
	TSubclassOf<AVEILFactionAgent> ReinforcementClass;

	void RegisterAgent(AVEILFactionAgent* Agent);
	void UnregisterAgent(AVEILFactionAgent* Agent);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Faction")
	void RegisterTerritory(const FVEILTerritory& Territory);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Faction")
	bool ClaimTerritory(FName TerritoryName, EVEILFaction NewOwner);

	UFUNCTION(BlueprintPure, Category = "VEIL|Faction")
	EVEILFaction GetTerritoryOwner(FName TerritoryName) const;

	/** Living agent count x average health: the faction's weight in the world. */
	UFUNCTION(BlueprintPure, Category = "VEIL|Faction")
	float GetFactionPower(EVEILFaction Faction) const;

	UFUNCTION(BlueprintPure, Category = "VEIL|Faction")
	int32 GetLivingAgentCount(EVEILFaction Faction) const;

	/** Spawn a fresh agent for a faction near a location (reinforcement wave). */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Faction")
	AVEILFactionAgent* SpawnReinforcement(EVEILFaction Faction, FVector Location);

	/** Hostility matrix: who fights whom. Default: everyone fights Void;
	 *  Scavenger and Guardian are rivals; Remnant is defensive-neutral
	 *  (fights only when its territory is entered - handled in agent logic). */
	UFUNCTION(BlueprintPure, Category = "VEIL|Faction")
	bool IsHostile(EVEILFaction A, EVEILFaction B) const;

private:
	TArray<TWeakObjectPtr<AVEILFactionAgent>> Agents;
	TArray<FVEILTerritory> Territories;
};

===== END D:\VEIL\Source\VEIL\Public\AI\VEILFactionAI.h =====
JOB 344 DONE

```
