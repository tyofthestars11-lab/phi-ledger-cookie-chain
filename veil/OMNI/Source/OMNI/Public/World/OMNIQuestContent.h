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
