// OMNI: THE LAST SIGNAL - runtime world builder implementation.
#include "World/OMNIWorldBuilder.h"

#include "Components/SkyAtmosphereComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PointLight.h"
#include "Components/PointLightComponent.h"
#include "Engine/SkyLight.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/PlayerStart.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "EngineUtils.h"
#include "UObject/ConstructorHelpers.h"
#include "OMNI.h"

AOMNIWorldBuilder::AOMNIWorldBuilder()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(
		TEXT("/Engine/BasicShapes/Cube.Cube"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cylinder(
		TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (Cube.Succeeded()) CubeMesh = Cube.Object;
	if (Cylinder.Succeeded()) CylinderMesh = Cylinder.Object;
	if (Sphere.Succeeded()) SphereMesh = Sphere.Object;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

UStaticMeshComponent* AOMNIWorldBuilder::SpawnBlock(const FVector& Location,
	const FVector& Scale, UStaticMesh* Mesh, const FLinearColor& Tint,
	float EmissiveStrength)
{
	UWorld* World = GetWorld();
	if (!World || !Mesh) return nullptr;

	AStaticMeshActor* Block = World->SpawnActor<AStaticMeshActor>(
		AStaticMeshActor::StaticClass(), Location, FRotator::ZeroRotator);
	if (!Block) return nullptr;

	UStaticMeshComponent* Comp = Block->GetStaticMeshComponent();
	Comp->SetStaticMesh(Mesh);
	Comp->SetMobility(EComponentMobility::Movable);
	Block->SetActorScale3D(Scale);

	// Tint through a dynamic instance of whatever material the shape ships
	// with. The parameter writes are guarded by the material itself: a
	// material without the parameter simply keeps its authored look.
	if (UMaterialInterface* Base = Comp->GetMaterial(0))
	{
		UMaterialInstanceDynamic* MID =
			UMaterialInstanceDynamic::Create(Base, Block);
		if (MID)
		{
			MID->SetVectorParameterValue(TEXT("Color"), Tint);
			MID->SetVectorParameterValue(TEXT("BaseColor"), Tint);
			if (EmissiveStrength > 0.f)
			{
				MID->SetVectorParameterValue(TEXT("EmissiveColor"),
					Tint * EmissiveStrength);
			}
			Comp->SetMaterial(0, MID);
		}
	}
	return Comp;
}

void AOMNIWorldBuilder::BuildLighting()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Low golden sun.
	if (ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(
		ADirectionalLight::StaticClass(), FVector(0.f, 0.f, 4000.f),
		FRotator(-32.f, -38.f, 0.f)))
	{
		if (UDirectionalLightComponent* Light =
			Sun->FindComponentByClass<UDirectionalLightComponent>())
		{
			Light->SetIntensity(3.2f);
			Light->SetLightColor(FLinearColor(1.f, 0.72f, 0.45f));
		}
	}
	// Sky dome: the atmosphere as a component on the builder itself -
	// the include surface every engine version carries (the actor
	// header path does not exist in 5.8; build10/11/OMNI build3 all
	// died on it, forensics job 062).
	if (USkyAtmosphereComponent* Atmo =
		NewObject<USkyAtmosphereComponent>(this))
	{
		Atmo->RegisterComponent();
	}
	if (ASkyLight* Sky = World->SpawnActor<ASkyLight>(
		ASkyLight::StaticClass(), FVector(0.f, 0.f, 1000.f),
		FRotator::ZeroRotator))
	{
		if (USkyLightComponent* Comp =
			Sky->FindComponentByClass<USkyLightComponent>())
		{
			Comp->SetIntensity(0.5f);
		}
	}
	// Violet dusk fog for depth.
	if (AExponentialHeightFog* Fog = World->SpawnActor<AExponentialHeightFog>(
		AExponentialHeightFog::StaticClass(), FVector::ZeroVector,
		FRotator::ZeroRotator))
	{
		if (UExponentialHeightFogComponent* Comp =
			Fog->FindComponentByClass<UExponentialHeightFogComponent>())
		{
			// Density only: FogInscatteringColor is NOT a member of
			// UExponentialHeightFogComponent in UE 5.8 - build5 died on
			// exactly that line (error C2039, job 068). The dusk comes
			// from the sun and sky rig, not from tinting the fog.
			Comp->FogDensity = 0.02f;
		}
	}
	// The beacon's gold heart over the plaza.
	if (APointLight* Beacon = World->SpawnActor<APointLight>(
		APointLight::StaticClass(), FVector(0.f, -2600.f, 2900.f),
		FRotator::ZeroRotator))
	{
		if (UPointLightComponent* Comp =
			Beacon->FindComponentByClass<UPointLightComponent>())
		{
			Comp->SetIntensity(90000.f);
			Comp->SetLightColor(FLinearColor(1.f, 0.78f, 0.3f));
			Comp->SetAttenuationRadius(6000.f);
		}
	}
}

void AOMNIWorldBuilder::BuildDistrict()
{
	UWorld* World = GetWorld();
	if (!World) return;

	const FLinearColor GroundTint(0.08f, 0.08f, 0.11f);
	const FLinearColor TowerTint(0.23f, 0.25f, 0.38f);
	const FLinearColor TowerTintWarm(0.34f, 0.24f, 0.16f);
	const FLinearColor PlazaTint(0.30f, 0.23f, 0.10f);
	const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);

	// Ground: one slab, top face exactly at z = 0.
	SpawnBlock(FVector(0.f, 0.f, -50.f), FVector(160.f, 160.f, 1.f),
		CubeMesh, GroundTint, 0.f);

	// Plaza disc the runner lands on.
	SpawnBlock(FVector(0.f, 0.f, 4.f), FVector(11.f, 11.f, 0.08f),
		CylinderMesh, PlazaTint, 0.f);

	// Tower grid, phi-climbing heights, plaza ring kept clear.
	const float Phi = 1.61803398875f;
	int32 Towers = 0;
	for (int32 X = -3; X <= 3; ++X)
	{
		for (int32 Y = -3; Y <= 3; ++Y)
		{
			if (FMath::Max(FMath::Abs(X), FMath::Abs(Y)) <= 1) continue;
			const float Ring = FMath::Max(FMath::Abs(X), FMath::Abs(Y));
			const float Hash = FMath::Frac(FMath::Sin(X * 12.9898f + Y * 78.233f) * 43758.5453f);
			const float Height = 520.f * FMath::Pow(Phi, Ring * 0.35f) + Hash * 320.f;
			const float Width = 640.f + Hash * 260.f;
			const FVector Loc(X * 1450.f, Y * 1450.f, Height * 0.5f);
			const FVector Scale(Width / 100.f, Width / 100.f, Height / 100.f);
			SpawnBlock(Loc, Scale, CubeMesh,
				(Towers % 3 == 0) ? TowerTintWarm : TowerTint, 0.f);
			// Lit crown on every third tower.
			if (Towers % 3 == 0)
			{
				SpawnBlock(FVector(Loc.X, Loc.Y, Height + 12.f),
					FVector(Width / 130.f, Width / 130.f, 0.24f),
					CubeMesh, GoldTint, 2.5f);
			}
			// Lit floor band on every second tower: at dusk a city
			// reads by its light lines, not its silhouettes.
			if (Towers % 2 == 0)
			{
				SpawnBlock(FVector(Loc.X, Loc.Y, Height * 0.55f),
					FVector(Width / 98.f, Width / 98.f, 0.16f),
					CubeMesh, GoldTint, 1.4f);
			}
			++Towers;
		}
	}

	// The beacon spire, north of the plaza: the district's landmark.
	SpawnBlock(FVector(0.f, -2600.f, 1350.f), FVector(3.2f, 3.2f, 27.f),
		CubeMesh, TowerTint, 0.f);
	SpawnBlock(FVector(0.f, -2600.f, 2760.f), FVector(1.5f, 1.5f, 1.5f),
		SphereMesh, GoldTint, 3.5f);

	// Where the runner enters the world.
	World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(),
		PlazaCenter, FRotator(0.f, 90.f, 0.f));

	UE_LOG(LogOMNI, Log,
		TEXT("OMNI WORLD BUILT: %d towers, plaza seated, beacon lit."), Towers);
}

void AOMNIWorldBuilder::BuildWorld()
{
	if (bBuilt) return;
	bBuilt = true;

	// ONE RIG, ONE CITY: clear the template map's own stage first.
	// Its sun, sky, fog and checker floor are what fought the dusk in
	// the first standing photo - two directional lights competing for
	// forward shading, a grid floor under the district. A real game
	// ships one stage: the builder's. Everything pre-existing in those
	// classes dies here, before anything of ours spawns.
	UWorld* World = GetWorld();
	if (World)
	{
		for (TActorIterator<ADirectionalLight> It(World); It; ++It) It->Destroy();
		for (TActorIterator<ASkyLight> It(World); It; ++It) It->Destroy();
		for (TActorIterator<AExponentialHeightFog> It(World); It; ++It) It->Destroy();
		for (TActorIterator<AStaticMeshActor> It(World); It; ++It) It->Destroy();
		for (TActorIterator<AActor> It(World); It; ++It)
		{
			const FString Name = It->GetClass()->GetName();
			if (Name == TEXT("SkyAtmosphere") || Name == TEXT("VolumetricCloud"))
			{
				It->Destroy();
			}
		}
	}

	BuildLighting();
	BuildDistrict();
}
