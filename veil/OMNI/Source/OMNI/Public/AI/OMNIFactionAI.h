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
