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
