// OMNI: THE LAST SIGNAL - runtime world builder.
//
// The project ships zero level assets by design: this actor builds the
// playable district from engine primitives at runtime - ground, a phi-scaled
// tower grid around a central plaza, a beacon spire, and a golden dusk
// lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
// before anything else, so ANY map - including the editor's empty default -
// becomes OMNI the moment Play is pressed.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OMNIWorldBuilder.generated.h"

class UStaticMesh;
class UStaticMeshComponent;

UCLASS()
class OMNI_API AOMNIWorldBuilder : public AActor
{
	GENERATED_BODY()

public:
	AOMNIWorldBuilder();

	/** Build the whole district once. Safe to call again - it builds once. */
	void BuildWorld();

	/** Plaza center, where the runner and the first machines stand. */
	FVector PlazaCenter = FVector(0.f, 0.f, 220.f);

private:
	void BuildLighting();
	void BuildDistrict();

	UStaticMeshComponent* SpawnBlock(const FVector& Location, const FVector& Scale,
		UStaticMesh* Mesh, const FLinearColor& Tint, float EmissiveStrength);

	TObjectPtr<UStaticMesh> CubeMesh;
	TObjectPtr<UStaticMesh> CylinderMesh;
	TObjectPtr<UStaticMesh> SphereMesh;

	bool bBuilt = false;
};
