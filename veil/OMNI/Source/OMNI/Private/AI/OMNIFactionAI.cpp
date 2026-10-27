// OMNI: THE LAST SIGNAL - faction AI implementation.
#include "AI/OMNIFactionAI.h"

#include "AIController.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "OMNI.h"

// ---------------------------------------------------------------------------
// Agent
// ---------------------------------------------------------------------------
AOMNIFactionAgent::AOMNIFactionAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	GetCharacterMovement()->MaxWalkSpeed = 380.f;

	// Visible machine body from engine shapes - same law as the runner:
	// no mesh assets ship, and an invisible agent is not a machine.
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(
			TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
			TEXT("/Engine/BasicShapes/Cube.Cube"));

		UStaticMeshComponent* Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineBody"));
		Body->SetupAttachment(GetCapsuleComponent());
		Body->SetRelativeLocation(FVector(0.f, 0.f, -10.f));
		Body->SetRelativeScale3D(FVector(0.72f, 0.72f, 1.55f));
		Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if (CylinderMesh.Succeeded()) Body->SetStaticMesh(CylinderMesh.Object);
		if (UMaterialInterface* Base = Body->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.14f, 0.10f, 0.20f));
				MID->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor(0.14f, 0.10f, 0.20f));
				Body->SetMaterial(0, MID);
			}
		}

		UStaticMeshComponent* Eye = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineEye"));
		Eye->SetupAttachment(GetCapsuleComponent());
		Eye->SetRelativeLocation(FVector(22.f, 0.f, 60.f));
		Eye->SetRelativeScale3D(FVector(0.10f, 0.30f, 0.10f));
		Eye->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if (CubeMesh.Succeeded()) Eye->SetStaticMesh(CubeMesh.Object);
		if (UMaterialInterface* Base = Eye->GetMaterial(0))
		{
			if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, this))
			{
				MID->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.85f, 0.2f, 1.f));
				MID->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor(0.85f, 0.2f, 1.f) * 3.f);
				Eye->SetMaterial(0, MID);
			}
		}
	}

	Health = MaxHealth;
}

void AOMNIFactionAgent::BeginPlay()
{
	Super::BeginPlay();
	BindStoneBody();
	Health = MaxHealth;
	HomeLocation = GetActorLocation();

	if (UOMNIFactionManager* Manager = GetWorld()->GetSubsystem<UOMNIFactionManager>())
	{
		Manager->RegisterAgent(this);
	}

	// Perception on a light timer keeps 20-40 agents per district cheap.
	GetWorldTimerManager().SetTimer(PerceiveTimer, this, &AOMNIFactionAgent::Perceive, 0.25f, true);
}

void AOMNIFactionAgent::EndPlay(const EEndPlayReason::Type Reason)
{
	if (UOMNIFactionManager* Manager = GetWorld()->GetSubsystem<UOMNIFactionManager>())
	{
		Manager->UnregisterAgent(this);
	}
	Super::EndPlay(Reason);
}

void AOMNIFactionAgent::SetState(EOMNIAgentState NewState)
{
	if (State == NewState || State == EOMNIAgentState::Dead) return;
	State = NewState;
	OnStateChanged.Broadcast(this, NewState);
}

bool AOMNIFactionAgent::CanSeePlayer() const
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return false;
	const FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
	if (ToPlayer.Size() > SightRange) return false;

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(const_cast<AOMNIFactionAgent*>(this));
	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const FVector End = Player->GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const bool bBlocked = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params)
		&& Hit.GetActor() != Player;
	return !bBlocked;
}

void AOMNIFactionAgent::Perceive()
{
	if (!IsAlive()) return;
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;

	if (Health <= MaxHealth * RetreatHealthFraction && Faction != EOMNIFaction::Void)
	{
		SetState(EOMNIAgentState::Retreat);
		return;
	}

	if (CanSeePlayer())
	{
		TargetActor = Player;
		const float Dist = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
		SetState(Dist <= AttackRange ? EOMNIAgentState::Combat : EOMNIAgentState::Hunt);
	}
	else if (State == EOMNIAgentState::Combat || State == EOMNIAgentState::Hunt)
	{
		SetState(EOMNIAgentState::Alert);
		FTimerHandle Timer;
		GetWorldTimerManager().SetTimer(Timer, [this]()
		{
			if (State == EOMNIAgentState::Alert) SetState(EOMNIAgentState::Patrol);
		}, 3.f, false);
	}
}

void AOMNIFactionAgent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!IsAlive()) return;

	switch (State)
	{
	case EOMNIAgentState::Patrol:  ActPatrol(); break;
	case EOMNIAgentState::Hunt:    ActHunt(); break;
	case EOMNIAgentState::Combat:  ActCombat(DeltaSeconds); break;
	case EOMNIAgentState::Defend:  ActDefendOrRetreat(false); break;
	case EOMNIAgentState::Retreat: ActDefendOrRetreat(true); break;
	default: break;
	}
}

void AOMNIFactionAgent::ActPatrol()
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC || PatrolPoints.Num() == 0) return;
	if (GetVelocity().SizeSquared2D() > 100.f) return; // still travelling to the current point (UE 5.8: EPathFollowingStatus has no 'Moving' member)

	AActor* Point = PatrolPoints[PatrolIndex % PatrolPoints.Num()];
	if (Point)
	{
		MoveToward(Point->GetActorLocation(), 80.f);
		PatrolIndex++;
	}
}

void AOMNIFactionAgent::ActHunt()
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC || !TargetActor.IsValid()) return;
	MoveToward(TargetActor->GetActorLocation(), AttackRange * 0.7f);
}

void AOMNIFactionAgent::ActCombat(float DeltaSeconds)
{
	if (!TargetActor.IsValid()) { SetState(EOMNIAgentState::Patrol); return; }
	AAIController* AIC = Cast<AAIController>(GetController());
	AActor* Target = TargetActor.Get();
	const float Dist = FVector::Dist(GetActorLocation(), Target->GetActorLocation());

	// Face the target; keep at firing distance.
	FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
	ToTarget.Z = 0.f;
	if (!ToTarget.IsNearlyZero())
	{
		SetActorRotation(FRotationMatrix::MakeFromX(ToTarget).Rotator());
	}
	if (AIC && Dist > AttackRange * 0.8f)
	{
		MoveToward(Target->GetActorLocation(), AttackRange * 0.7f);
	}

	const float Now = GetWorld()->TimeSeconds;
	if (Dist <= AttackRange && Now - LastFireTime >= FireInterval)
	{
		LastFireTime = Now;
		if (APawn* TargetPawn = Cast<APawn>(Target))
		{
			UGameplayStatics::ApplyDamage(TargetPawn, WeaponDamage, GetController(), this, UDamageType::StaticClass());
		}
	}
}

void AOMNIFactionAgent::ActDefendOrRetreat(bool bRetreat)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC) return;
	if (FVector::Dist(GetActorLocation(), HomeLocation) > 150.f)
	{
		MoveToward(HomeLocation, 100.f);
	}
	if (!bRetreat && CanSeePlayer())
	{
		SetState(EOMNIAgentState::Combat);
	}
	if (bRetreat && Health > MaxHealth * (RetreatHealthFraction + 0.25f))
	{
		SetState(EOMNIAgentState::Patrol);
	}
}


void AOMNIFactionAgent::BindStoneBody()
{
	// The stone body (job 126's triangle): Greystone is the only hero
	// tree besides the Countess complete in BOTH projects - mesh,
	// Greystone_Skeleton, Greystone_AnimBlueprint, full Jog library.
	// The Warden's own line names the material: nine hundred
	// heartbeats of STONE. If the bind fails, the machine body stands
	// and the log says so - an invisible agent is not an agent.
	USkeletalMesh* Stone = LoadObject<USkeletalMesh>(nullptr,
		TEXT("/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/SM_Greystone.SM_Greystone"));
	if (!Stone)
	{
		Stone = LoadObject<USkeletalMesh>(nullptr,
			TEXT("/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/SK_Greystone.SK_Greystone"));
	}
	UClass* StoneAnim = LoadClass<UAnimInstance>(nullptr,
		TEXT("/Game/ParagonGreystone/Characters/Heroes/Greystone/Greystone_AnimBlueprint.Greystone_AnimBlueprint_C"));
	if (Stone)
	{
		GetMesh()->SetSkeletalMeshAsset(Stone);
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
		GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
		if (StoneAnim) GetMesh()->SetAnimInstanceClass(StoneAnim);
		for (UActorComponent* Comp : GetComponents())
		{
			if (Comp && (Comp->GetName() == TEXT("MachineBody") || Comp->GetName() == TEXT("MachineEye")))
			{
				if (UStaticMeshComponent* SMC = Cast<UStaticMeshComponent>(Comp))
				{
					SMC->SetVisibility(false);
				}
			}
		}
		UE_LOG(LogOMNI, Log, TEXT("PHI FACTION BODY: Greystone stands (mesh %s, anim %s)."),
			*Stone->GetName(), StoneAnim ? *StoneAnim->GetName() : TEXT("unassigned"));
	}
	else
	{
		UE_LOG(LogOMNI, Warning, TEXT("PHI FACTION BODY FALLBACK: no Greystone mesh resolved - machine body stands."));
	}
}

void AOMNIFactionAgent::MoveToward(const FVector& Dest, float AcceptRadius)
{
	if (AAIController* AIC = Cast<AAIController>(GetController()))
	{
		if (AIC->MoveToLocation(Dest, AcceptRadius) != EPathFollowingRequestResult::Failed)
		{
			return;
		}
	}
	// Direct steer: no nav path - walk the line, face the line.
	// (The raycast-nav kernel in house clothes; runs per-Tick via
	// the Act functions, so the steering sustains.)
	FVector To = Dest - GetActorLocation();
	To.Z = 0.f;
	if (To.Size() > AcceptRadius)
	{
		To.Normalize();
		AddMovementInput(To, 1.f);
		SetActorRotation(FRotationMatrix::MakeFromX(To).Rotator());
	}
}

float AOMNIFactionAgent::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsAlive()) return 0.f;
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health = FMath::Clamp(Health - Applied, 0.f, MaxHealth);

	if (DamageCauser)
	{
		TargetActor = DamageCauser;
		if (Health > MaxHealth * RetreatHealthFraction || Faction == EOMNIFaction::Void)
		{
			SetState(EOMNIAgentState::Combat);
		}
	}

	if (Health <= 0.f)
	{
		SetState(EOMNIAgentState::Dead);
		DisableInput(nullptr);
		if (AAIController* AIC = Cast<AAIController>(GetController())) AIC->StopMovement();
		GetCharacterMovement()->DisableMovement();
		SetActorEnableCollision(false);
		// Body stays in the world briefly, then cleans up.
		SetLifeSpan(6.f);
	}
	return Applied;
}

// ---------------------------------------------------------------------------
// Faction Manager
// ---------------------------------------------------------------------------
void UOMNIFactionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogOMNI, Log, TEXT("Faction Manager online: Void / Scavenger / Guardian / Remnant."));
}

void UOMNIFactionManager::RegisterAgent(AOMNIFactionAgent* Agent)
{
	if (Agent) Agents.AddUnique(Agent);
}

void UOMNIFactionManager::UnregisterAgent(AOMNIFactionAgent* Agent)
{
	Agents.RemoveAll([Agent](const TWeakObjectPtr<AOMNIFactionAgent>& A) { return A.Get() == Agent || !A.IsValid(); });
}

void UOMNIFactionManager::RegisterTerritory(const FOMNITerritory& Territory)
{
	Territories.Add(Territory);
}

bool UOMNIFactionManager::ClaimTerritory(FName TerritoryName, EOMNIFaction NewOwner)
{
	for (FOMNITerritory& T : Territories)
	{
		if (T.Name == TerritoryName)
		{
			const EOMNIFaction Old = T.Owner;
			T.Owner = NewOwner;
			OnTerritoryChanged.Broadcast(TerritoryName, Old, NewOwner);
			UE_LOG(LogOMNI, Log, TEXT("Territory %s: %d -> %d"), *TerritoryName.ToString(), (int32)Old, (int32)NewOwner);
			return true;
		}
	}
	return false;
}

EOMNIFaction UOMNIFactionManager::GetTerritoryOwner(FName TerritoryName) const
{
	for (const FOMNITerritory& T : Territories)
	{
		if (T.Name == TerritoryName) return T.Owner;
	}
	return EOMNIFaction::None;
}

float UOMNIFactionManager::GetFactionPower(EOMNIFaction Faction) const
{
	float Power = 0.f;
	for (const TWeakObjectPtr<AOMNIFactionAgent>& A : Agents)
	{
		if (A.IsValid() && A->Faction == Faction && A->IsAlive())
		{
			Power += A->Health / A->MaxHealth;
		}
	}
	return Power;
}

int32 UOMNIFactionManager::GetLivingAgentCount(EOMNIFaction Faction) const
{
	int32 Count = 0;
	for (const TWeakObjectPtr<AOMNIFactionAgent>& A : Agents)
	{
		if (A.IsValid() && A->Faction == Faction && A->IsAlive()) Count++;
	}
	return Count;
}

AOMNIFactionAgent* UOMNIFactionManager::SpawnReinforcement(EOMNIFaction Faction, FVector Location)
{
	if (!ReinforcementClass) return nullptr;
	UWorld* World = GetWorld();
	if (!World) return nullptr;
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AOMNIFactionAgent* Agent = World->SpawnActor<AOMNIFactionAgent>(ReinforcementClass, Location, FRotator::ZeroRotator, Params);
	if (Agent) Agent->Faction = Faction;
	return Agent;
}

bool UOMNIFactionManager::IsHostile(EOMNIFaction A, EOMNIFaction B) const
{
	if (A == B || A == EOMNIFaction::None || B == EOMNIFaction::None) return false;
	if (A == EOMNIFaction::Void || B == EOMNIFaction::Void) return true;
	// Scavenger <-> Guardian rivalry.
	if ((A == EOMNIFaction::Scavenger && B == EOMNIFaction::Guardian) ||
		(A == EOMNIFaction::Guardian && B == EOMNIFaction::Scavenger)) return true;
	// Remnant defends itself only - handled in agent territory logic.
	return false;
}
