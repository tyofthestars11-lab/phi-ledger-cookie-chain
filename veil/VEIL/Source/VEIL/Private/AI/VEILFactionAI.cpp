// VEIL: THE LAST SIGNAL - faction AI implementation.
#include "AI/VEILFactionAI.h"

#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

// ---------------------------------------------------------------------------
// Agent
// ---------------------------------------------------------------------------
AVEILFactionAgent::AVEILFactionAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	GetCharacterMovement()->MaxWalkSpeed = 380.f;
	Health = MaxHealth;
}

void AVEILFactionAgent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	HomeLocation = GetActorLocation();

	if (UVEILFactionManager* Manager = GetWorld()->GetSubsystem<UVEILFactionManager>())
	{
		Manager->RegisterAgent(this);
	}

	// Perception on a light timer keeps 20-40 agents per district cheap.
	GetWorldTimerManager().SetTimer(PerceiveTimer, this, &AVEILFactionAgent::Perceive, 0.25f, true);
}

void AVEILFactionAgent::EndPlay(const EEndPlayReason::Type Reason)
{
	if (UVEILFactionManager* Manager = GetWorld()->GetSubsystem<UVEILFactionManager>())
	{
		Manager->UnregisterAgent(this);
	}
	Super::EndPlay(Reason);
}

void AVEILFactionAgent::SetState(EVEILAgentState NewState)
{
	if (State == NewState || State == EVEILAgentState::Dead) return;
	State = NewState;
	OnStateChanged.Broadcast(this, NewState);
}

bool AVEILFactionAgent::CanSeePlayer() const
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return false;
	const FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
	if (ToPlayer.Size() > SightRange) return false;

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(const_cast<AVEILFactionAgent*>(this));
	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const FVector End = Player->GetActorLocation() + FVector(0.f, 0.f, 60.f);
	const bool bBlocked = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params)
		&& Hit.GetActor() != Player;
	return !bBlocked;
}

void AVEILFactionAgent::Perceive()
{
	if (!IsAlive()) return;
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;

	if (Health <= MaxHealth * RetreatHealthFraction && Faction != EVEILFaction::Void)
	{
		SetState(EVEILAgentState::Retreat);
		return;
	}

	if (CanSeePlayer())
	{
		TargetActor = Player;
		const float Dist = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
		SetState(Dist <= AttackRange ? EVEILAgentState::Combat : EVEILAgentState::Hunt);
	}
	else if (State == EVEILAgentState::Combat || State == EVEILAgentState::Hunt)
	{
		SetState(EVEILAgentState::Alert);
		FTimerHandle Timer;
		GetWorldTimerManager().SetTimer(Timer, [this]()
		{
			if (State == EVEILAgentState::Alert) SetState(EVEILAgentState::Patrol);
		}, 3.f, false);
	}
}

void AVEILFactionAgent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!IsAlive()) return;

	switch (State)
	{
	case EVEILAgentState::Patrol:  ActPatrol(); break;
	case EVEILAgentState::Hunt:    ActHunt(); break;
	case EVEILAgentState::Combat:  ActCombat(DeltaSeconds); break;
	case EVEILAgentState::Defend:  ActDefendOrRetreat(false); break;
	case EVEILAgentState::Retreat: ActDefendOrRetreat(true); break;
	default: break;
	}
}

void AVEILFactionAgent::ActPatrol()
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC || PatrolPoints.Num() == 0) return;
	if (GetVelocity().SizeSquared2D() > 100.f) return; // still travelling to the current point (UE 5.8: EPathFollowingStatus has no 'Moving' member)

	AActor* Point = PatrolPoints[PatrolIndex % PatrolPoints.Num()];
	if (Point)
	{
		AIC->MoveToLocation(Point->GetActorLocation(), 80.f);
		PatrolIndex++;
	}
}

void AVEILFactionAgent::ActHunt()
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC || !TargetActor.IsValid()) return;
	AIC->MoveToLocation(TargetActor->GetActorLocation(), AttackRange * 0.7f);
}

void AVEILFactionAgent::ActCombat(float DeltaSeconds)
{
	if (!TargetActor.IsValid()) { SetState(EVEILAgentState::Patrol); return; }
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
		AIC->MoveToLocation(Target->GetActorLocation(), AttackRange * 0.7f);
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

void AVEILFactionAgent::ActDefendOrRetreat(bool bRetreat)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	if (!AIC) return;
	if (FVector::Dist(GetActorLocation(), HomeLocation) > 150.f)
	{
		AIC->MoveToLocation(HomeLocation, 100.f);
	}
	if (!bRetreat && CanSeePlayer())
	{
		SetState(EVEILAgentState::Combat);
	}
	if (bRetreat && Health > MaxHealth * (RetreatHealthFraction + 0.25f))
	{
		SetState(EVEILAgentState::Patrol);
	}
}

float AVEILFactionAgent::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsAlive()) return 0.f;
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health = FMath::Clamp(Health - Applied, 0.f, MaxHealth);

	if (DamageCauser)
	{
		TargetActor = DamageCauser;
		if (Health > MaxHealth * RetreatHealthFraction || Faction == EVEILFaction::Void)
		{
			SetState(EVEILAgentState::Combat);
		}
	}

	if (Health <= 0.f)
	{
		SetState(EVEILAgentState::Dead);
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
void UVEILFactionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogVEIL, Log, TEXT("Faction Manager online: Void / Scavenger / Guardian / Remnant."));
}

void UVEILFactionManager::RegisterAgent(AVEILFactionAgent* Agent)
{
	if (Agent) Agents.AddUnique(Agent);
}

void UVEILFactionManager::UnregisterAgent(AVEILFactionAgent* Agent)
{
	Agents.RemoveAll([Agent](const TWeakObjectPtr<AVEILFactionAgent>& A) { return A.Get() == Agent || !A.IsValid(); });
}

void UVEILFactionManager::RegisterTerritory(const FVEILTerritory& Territory)
{
	Territories.Add(Territory);
}

bool UVEILFactionManager::ClaimTerritory(FName TerritoryName, EVEILFaction NewOwner)
{
	for (FVEILTerritory& T : Territories)
	{
		if (T.Name == TerritoryName)
		{
			const EVEILFaction Old = T.Owner;
			T.Owner = NewOwner;
			OnTerritoryChanged.Broadcast(TerritoryName, Old, NewOwner);
			UE_LOG(LogVEIL, Log, TEXT("Territory %s: %d -> %d"), *TerritoryName.ToString(), (int32)Old, (int32)NewOwner);
			return true;
		}
	}
	return false;
}

EVEILFaction UVEILFactionManager::GetTerritoryOwner(FName TerritoryName) const
{
	for (const FVEILTerritory& T : Territories)
	{
		if (T.Name == TerritoryName) return T.Owner;
	}
	return EVEILFaction::None;
}

float UVEILFactionManager::GetFactionPower(EVEILFaction Faction) const
{
	float Power = 0.f;
	for (const TWeakObjectPtr<AVEILFactionAgent>& A : Agents)
	{
		if (A.IsValid() && A->Faction == Faction && A->IsAlive())
		{
			Power += A->Health / A->MaxHealth;
		}
	}
	return Power;
}

int32 UVEILFactionManager::GetLivingAgentCount(EVEILFaction Faction) const
{
	int32 Count = 0;
	for (const TWeakObjectPtr<AVEILFactionAgent>& A : Agents)
	{
		if (A.IsValid() && A->Faction == Faction && A->IsAlive()) Count++;
	}
	return Count;
}

AVEILFactionAgent* UVEILFactionManager::SpawnReinforcement(EVEILFaction Faction, FVector Location)
{
	if (!ReinforcementClass) return nullptr;
	UWorld* World = GetWorld();
	if (!World) return nullptr;
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AVEILFactionAgent* Agent = World->SpawnActor<AVEILFactionAgent>(ReinforcementClass, Location, FRotator::ZeroRotator, Params);
	if (Agent) Agent->Faction = Faction;
	return Agent;
}

bool UVEILFactionManager::IsHostile(EVEILFaction A, EVEILFaction B) const
{
	if (A == B || A == EVEILFaction::None || B == EVEILFaction::None) return false;
	if (A == EVEILFaction::Void || B == EVEILFaction::Void) return true;
	// Scavenger <-> Guardian rivalry.
	if ((A == EVEILFaction::Scavenger && B == EVEILFaction::Guardian) ||
		(A == EVEILFaction::Guardian && B == EVEILFaction::Scavenger)) return true;
	// Remnant defends itself only - handled in agent territory logic.
	return false;
}
