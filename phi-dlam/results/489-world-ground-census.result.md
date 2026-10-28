# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 20:55:33 UTC

## STEP 1
```
=== WORLD GROUND 489 - THE BUILDERS READ WHOLE (Ground: the Copilot board folded into the bible as the standing production order, 2026-10-28, and Tyree: do what you need to. Phase 1 rides jobs 487 and 488 already in line. This job gathers the whole ground the next tranches author from, in one read: the world builder source and header whole, so the monument and region seats author against the true SpawnBlock shape; the GameMode spawn region, so the agent and giver seats read as placed; every BindStoneBody caller in the source tree; the Warden files and lines wherever they stand; and the exact on-disk object paths for the Murdock, Revenant and Minion bodies and animation blueprints, built mechanically from the file paths so no path is ever typed from a pattern. Read-only: nothing patches, nothing builds, the prints are the product. Every variable carries the wb489 prefix.) ===
WB LINES=272
WB 1 // VEIL: THE LAST SIGNAL - runtime world builder implementation.
WB 2 #include "World/VEILWorldBuilder.h"
WB 3 
WB 4 #include "Components/SkyAtmosphereComponent.h"
WB 5 #include "Components/DirectionalLightComponent.h"
WB 6 #include "Components/ExponentialHeightFogComponent.h"
WB 7 #include "Components/SkyLightComponent.h"
WB 8 #include "Components/StaticMeshComponent.h"
WB 9 #include "Engine/DirectionalLight.h"
WB 10 #include "Engine/ExponentialHeightFog.h"
WB 11 #include "Engine/PointLight.h"
WB 12 #include "Components/PointLightComponent.h"
WB 13 #include "Engine/SkyLight.h"
WB 14 #include "Engine/StaticMesh.h"
WB 15 #include "Engine/StaticMeshActor.h"
WB 16 #include "GameFramework/PlayerStart.h"
WB 17 #include "Materials/MaterialInstanceDynamic.h"
WB 18 #include "EngineUtils.h"
WB 19 #include "UObject/ConstructorHelpers.h"
WB 20 #include "VEIL.h"
WB 21 
WB 22 AVEILWorldBuilder::AVEILWorldBuilder()
WB 23 {
WB 24 	PrimaryActorTick.bCanEverTick = false;
WB 25 
WB 26 	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(
WB 27 		TEXT("/Engine/BasicShapes/Cube.Cube"));
WB 28 	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cylinder(
WB 29 		TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
WB 30 	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(
WB 31 		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
WB 32 	if (Cube.Succeeded()) CubeMesh = Cube.Object;
WB 33 	if (Cylinder.Succeeded()) CylinderMesh = Cylinder.Object;
WB 34 	if (Sphere.Succeeded()) SphereMesh = Sphere.Object;
WB 35 
WB 36 	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
WB 37 	SetRootComponent(Root);
WB 38 }
WB 39 
WB 40 UStaticMeshComponent* AVEILWorldBuilder::SpawnBlock(const FVector& Location,
WB 41 	const FVector& Scale, UStaticMesh* Mesh, const FLinearColor& Tint,
WB 42 	float EmissiveStrength)
WB 43 {
WB 44 	UWorld* World = GetWorld();
WB 45 	if (!World || !Mesh) return nullptr;
WB 46 
WB 47 	AStaticMeshActor* Block = World->SpawnActor<AStaticMeshActor>(
WB 48 		AStaticMeshActor::StaticClass(), Location, FRotator::ZeroRotator);
WB 49 	if (!Block) return nullptr;
WB 50 
WB 51 	UStaticMeshComponent* Comp = Block->GetStaticMeshComponent();
WB 52 	Comp->SetStaticMesh(Mesh);
WB 53 	Comp->SetMobility(EComponentMobility::Movable);
WB 54 	Block->SetActorScale3D(Scale);
WB 55 
WB 56 	// Tint through a dynamic instance of whatever material the shape ships
WB 57 	// with. The parameter writes are guarded by the material itself: a
WB 58 	// material without the parameter simply keeps its authored look.
WB 59 	if (UMaterialInterface* Base = Comp->GetMaterial(0))
WB 60 	{
WB 61 		UMaterialInstanceDynamic* MID =
WB 62 			UMaterialInstanceDynamic::Create(Base, Block);
WB 63 		if (MID)
WB 64 		{
WB 65 			MID->SetVectorParameterValue(TEXT("Color"), Tint);
WB 66 			MID->SetVectorParameterValue(TEXT("BaseColor"), Tint);
WB 67 			if (EmissiveStrength > 0.f)
WB 68 			{
WB 69 				MID->SetVectorParameterValue(TEXT("EmissiveColor"),
WB 70 					Tint * EmissiveStrength);
WB 71 			}
WB 72 			Comp->SetMaterial(0, MID);
WB 73 		}
WB 74 	}
WB 75 	return Comp;
WB 76 }
WB 77 
WB 78 void AVEILWorldBuilder::BuildLighting()
WB 79 {
WB 80 	UWorld* World = GetWorld();
WB 81 	if (!World) return;
WB 82 
WB 83 	// Low golden sun.
WB 84 	if (ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(
WB 85 		ADirectionalLight::StaticClass(), FVector(0.f, 0.f, 4000.f),
WB 86 		FRotator(-32.f, -38.f, 0.f)))
WB 87 	{
WB 88 		if (UDirectionalLightComponent* Light =
WB 89 			Sun->FindComponentByClass<UDirectionalLightComponent>())
WB 90 		{
WB 91 			Light->SetIntensity(3.2f);
WB 92 			Light->SetLightColor(FLinearColor(1.f, 0.72f, 0.45f));
WB 93 		}
WB 94 	}
WB 95 	// Sky dome: the atmosphere as a component on the builder itself -
WB 96 	// the include surface every engine version carries (the actor
WB 97 	// header path does not exist in 5.8; build10/11/OMNI build3 all
WB 98 	// died on it, forensics job 062).
WB 99 	if (USkyAtmosphereComponent* Atmo =
WB 100 		NewObject<USkyAtmosphereComponent>(this))
WB 101 	{
WB 102 		Atmo->RegisterComponent();
WB 103 	}
WB 104 	if (ASkyLight* Sky = World->SpawnActor<ASkyLight>(
WB 105 		ASkyLight::StaticClass(), FVector(0.f, 0.f, 1000.f),
WB 106 		FRotator::ZeroRotator))
WB 107 	{
WB 108 		if (USkyLightComponent* Comp =
WB 109 			Sky->FindComponentByClass<USkyLightComponent>())
WB 110 		{
WB 111 			Comp->SetIntensity(0.5f);
WB 112 		}
WB 113 	}
WB 114 	// Violet dusk fog for depth.
WB 115 	if (AExponentialHeightFog* Fog = World->SpawnActor<AExponentialHeightFog>(
WB 116 		AExponentialHeightFog::StaticClass(), FVector::ZeroVector,
WB 117 		FRotator::ZeroRotator))
WB 118 	{
WB 119 		if (UExponentialHeightFogComponent* Comp =
WB 120 			Fog->FindComponentByClass<UExponentialHeightFogComponent>())
WB 121 		{
WB 122 			// Density only: the one write every engine version carries.
WB 123 			// The fog's authored color stands - the dusk comes from the
WB 124 			// sun and sky above, not from tinting the fog against spec.
WB 125 			Comp->FogDensity = 0.02f;
WB 126 		}
WB 127 	}
WB 128 	// The beacon's gold heart over the plaza.
WB 129 	if (APointLight* Beacon = World->SpawnActor<APointLight>(
WB 130 		APointLight::StaticClass(), FVector(0.f, -2600.f, 2900.f),
WB 131 		FRotator::ZeroRotator))
WB 132 	{
WB 133 		if (UPointLightComponent* Comp =
WB 134 			Beacon->FindComponentByClass<UPointLightComponent>())
WB 135 		{
WB 136 			Comp->SetIntensity(90000.f);
WB 137 			Comp->SetLightColor(FLinearColor(1.f, 0.78f, 0.3f));
WB 138 			Comp->SetAttenuationRadius(6000.f);
WB 139 		}
WB 140 	}
WB 141 }
WB 142 
WB 143 void AVEILWorldBuilder::BuildDistrict()
WB 144 {
WB 145 	UWorld* World = GetWorld();
WB 146 	if (!World) return;
WB 147 
WB 148 	const FLinearColor GroundTint(0.08f, 0.08f, 0.11f);
WB 149 	const FLinearColor TowerTint(0.23f, 0.25f, 0.38f);
WB 150 	const FLinearColor TowerTintWarm(0.34f, 0.24f, 0.16f);
WB 151 	const FLinearColor PlazaTint(0.30f, 0.23f, 0.10f);
WB 152 	const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
WB 153 
WB 154 	// Ground: one slab, top face exactly at z = 0.
WB 155 	SpawnBlock(FVector(0.f, 0.f, -50.f), FVector(160.f, 160.f, 1.f),
WB 156 		CubeMesh, GroundTint, 0.f);
WB 157 
WB 158 	// Plaza disc the runner lands on.
WB 159 	SpawnBlock(FVector(0.f, 0.f, 4.f), FVector(11.f, 11.f, 0.08f),
WB 160 		CylinderMesh, PlazaTint, 0.f);
WB 161 
WB 162 	// Tower grid, phi-climbing heights, plaza ring kept clear.
WB 163 	const float Phi = 1.61803398875f;
WB 164 	int32 Towers = 0;
WB 165 	for (int32 X = -3; X <= 3; ++X)
WB 166 	{
WB 167 		for (int32 Y = -3; Y <= 3; ++Y)
WB 168 		{
WB 169 			if (FMath::Max(FMath::Abs(X), FMath::Abs(Y)) <= 1) continue;
WB 170 			const float Ring = FMath::Max(FMath::Abs(X), FMath::Abs(Y));
WB 171 			const float Hash = FMath::Frac(FMath::Sin(X * 12.9898f + Y * 78.233f) * 43758.5453f);
WB 172 			const float Height = 520.f * FMath::Pow(Phi, Ring * 0.35f) + Hash * 320.f;
WB 173 			const float Width = 640.f + Hash * 260.f;
WB 174 			const FVector Loc(X * 1450.f, Y * 1450.f, Height * 0.5f);
WB 175 			const FVector Scale(Width / 100.f, Width / 100.f, Height / 100.f);
WB 176 			SpawnBlock(Loc, Scale, CubeMesh,
WB 177 				(Towers % 3 == 0) ? TowerTintWarm : TowerTint, 0.f);
WB 178 			// Lit crown on every third tower.
WB 179 			if (Towers % 3 == 0)
WB 180 			{
WB 181 				SpawnBlock(FVector(Loc.X, Loc.Y, Height + 12.f),
WB 182 					FVector(Width / 130.f, Width / 130.f, 0.24f),
WB 183 					CubeMesh, GoldTint, 2.5f);
WB 184 			}
WB 185 			// Lit floor band on every second tower: at dusk a city
WB 186 			// reads by its light lines, not its silhouettes.
WB 187 			if (Towers % 2 == 0)
WB 188 			{
WB 189 				SpawnBlock(FVector(Loc.X, Loc.Y, Height * 0.55f),
WB 190 					FVector(Width / 98.f, Width / 98.f, 0.16f),
WB 191 					CubeMesh, GoldTint, 1.4f);
WB 192 			}
WB 193 			++Towers;
WB 194 		}
WB 195 	}
WB 196 
WB 197 	// The beacon spire, north of the plaza: the district's landmark.
WB 198 	SpawnBlock(FVector(0.f, -2600.f, 1350.f), FVector(3.2f, 3.2f, 27.f),
WB 199 		CubeMesh, TowerTint, 0.f);
WB 200 	SpawnBlock(FVector(0.f, -2600.f, 2760.f), FVector(1.5f, 1.5f, 1.5f),
WB 201 		SphereMesh, GoldTint, 3.5f);
WB 202 
WB 203 	// Where the runner enters the world.
WB 204 	World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(),
WB 205 		PlazaCenter, FRotator(0.f, 90.f, 0.f));
WB 206 
WB 207 	UE_LOG(LogVEIL, Log,
WB 208 		TEXT("VEIL WORLD BUILT: %d towers, plaza seated, beacon lit."), Towers);
WB 209 }
WB 210 
WB 211 void AVEILWorldBuilder::BuildHub()
WB 212 {
WB 213 	// THE HUB: the first region of the merged world, seated on the standing
WB 214 	// district. Four roads run from the plaza toward the district edge on
WB 215 	// the four axes, and a phi ring of eight lit pylons marks the plaza as
WB 216 	// home ground, the ground the quest givers already stand around.
WB 217 	const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
WB 218 	const FLinearColor RoadTint(0.16f, 0.13f, 0.07f);
WB 219 	int32 Roads = 0;
WB 220 	const FVector RoadDirs[4] = { FVector(1.f, 0.f, 0.f), FVector(-1.f, 0.f, 0.f), FVector(0.f, 1.f, 0.f), FVector(0.f, -1.f, 0.f) };
WB 221 	for (int32 i = 0; i < 4; ++i)
WB 222 	{
WB 223 		const FVector Dir = RoadDirs[i];
WB 224 		const FVector Loc(Dir.X * 4200.f, Dir.Y * 4200.f, 2.f);
WB 225 		const FVector Scale = (Dir.X != 0.f) ? FVector(84.f, 6.f, 0.04f) : FVector(6.f, 84.f, 0.04f);
WB 226 		SpawnBlock(Loc, Scale, CubeMesh, RoadTint, 0.f);
WB 227 		++Roads;
WB 228 	}
WB 229 	int32 Pylons = 0;
WB 230 	const float RingRadius = 1500.f;
WB 231 	for (int32 i = 0; i < 8; ++i)
WB 232 	{
WB 233 		const float A = (float)i * 0.7853981f;
WB 234 		const FVector Loc(FMath::Cos(A) * RingRadius, FMath::Sin(A) * RingRadius, 260.f);
WB 235 		SpawnBlock(Loc, FVector(1.2f, 1.2f, 5.2f), CubeMesh, GoldTint, 2.0f);
WB 236 		++Pylons;
WB 237 	}
WB 238 	UE_LOG(LogVEIL, Log, TEXT("VEIL HUB SEATED: %d roads, %d pylons, the plaza ring stands."), Roads, Pylons);
WB 239 }
WB 240 void AVEILWorldBuilder::BuildWorld()
WB 241 {
WB 242 	if (bBuilt) return;
WB 243 	bBuilt = true;
WB 244 
WB 245 	// ONE RIG, ONE CITY: clear the template map's own stage first.
WB 246 	// Its sun, sky, fog and checker floor are what fought the dusk in
WB 247 	// the first standing photo - two directional lights competing for
WB 248 	// forward shading, a grid floor under the district. A real game
WB 249 	// ships one stage: the builder's. Everything pre-existing in those
WB 250 	// classes dies here, before anything of ours spawns.
WB 251 	UWorld* World = GetWorld();
WB 252 	if (World)
WB 253 	{
WB 254 		for (TActorIterator<ADirectionalLight> It(World); It; ++It) It->Destroy();
WB 255 		for (TActorIterator<ASkyLight> It(World); It; ++It) It->Destroy();
WB 256 		for (TActorIterator<AExponentialHeightFog> It(World); It; ++It) It->Destroy();
WB 257 		for (TActorIterator<AStaticMeshActor> It(World); It; ++It) It->Destroy();
WB 258 		for (TActorIterator<AActor> It(World); It; ++It)
WB 259 		{
WB 260 			const FString Name = It->GetClass()->GetName();
WB 261 			if (Name == TEXT("SkyAtmosphere") || Name == TEXT("VolumetricCloud"))
WB 262 			{
WB 263 				It->Destroy();
WB 264 			}
WB 265 		}
WB 266 	}
WB 267 
WB 268 	BuildLighting();
WB 269 	BuildDistrict();
WB 270 	BuildHub();
WB 271 	UE_LOG(LogVEIL, Log, TEXT("VEIL: free to play under the PHI LICENSE (PHI-LICENSE.md). The phi framework is licensed only through Tyree Shariff Jones, its source - universal, including Earth's."));
WB 272 }
WBH LINES=45
WBH 1 // VEIL: THE LAST SIGNAL - runtime world builder.
WBH 2 //
WBH 3 // The project ships zero level assets by design: this actor builds the
WBH 4 // playable district from engine primitives at runtime - ground, a phi-scaled
WBH 5 // tower grid around a central plaza, a beacon spire, and a golden dusk
WBH 6 // lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
WBH 7 // before anything else, so ANY map - including the editor's empty default -
WBH 8 // becomes VEIL the moment Play is pressed.
WBH 9 #pragma once
WBH 10 
WBH 11 #include "CoreMinimal.h"
WBH 12 #include "GameFramework/Actor.h"
WBH 13 #include "VEILWorldBuilder.generated.h"
WBH 14 
WBH 15 class UStaticMesh;
WBH 16 class UStaticMeshComponent;
WBH 17 
WBH 18 UCLASS()
WBH 19 class VEIL_API AVEILWorldBuilder : public AActor
WBH 20 {
WBH 21 	GENERATED_BODY()
WBH 22 
WBH 23 public:
WBH 24 	AVEILWorldBuilder();
WBH 25 
WBH 26 	/** Build the whole district once. Safe to call again - it builds once. */
WBH 27 	void BuildWorld();
WBH 28 
WBH 29 	/** Plaza center, where the runner and the first machines stand. */
WBH 30 	FVector PlazaCenter = FVector(0.f, 0.f, 220.f);
WBH 31 
WBH 32 private:
WBH 33 	void BuildLighting();
WBH 34 	void BuildDistrict();
WBH 35 	void BuildHub();
WBH 36 
WBH 37 	UStaticMeshComponent* SpawnBlock(const FVector& Location, const FVector& Scale,
WBH 38 		UStaticMesh* Mesh, const FLinearColor& Tint, float EmissiveStrength);
WBH 39 
WBH 40 	TObjectPtr<UStaticMesh> CubeMesh;
WBH 41 	TObjectPtr<UStaticMesh> CylinderMesh;
WBH 42 	TObjectPtr<UStaticMesh> SphereMesh;
WBH 43 
WBH 44 	bool bBuilt = false;
WBH 45 };
GM 85 			Pawn->SetActorLocation(Builder->PlazaCenter);
GM 86 		}
GM 87 		for (int32 i = 0; i < 3; ++i)
GM 88 		{
GM 89 			const float Angle = (2.f * PI / 3.f) * i;
GM 90 			const FVector Loc(FMath::Cos(Angle) * 950.f,
GM 91 				FMath::Sin(Angle) * 950.f, 240.f);
GM 92 			if (AVEILFactionAgent* Agent =
GM 93 				GetWorld()->SpawnActor<AVEILFactionAgent>(
GM 94 					AVEILFactionAgent::StaticClass(), Loc,
GM 95 					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
GM 96 			{
GM 97 				Agent->SpawnDefaultController();
GM 98 			}
GM 99 		}
GM 100 	}
GM 101 
GM 102 	// Seed the world systems with the authored starting data.
GM 103 	// OMNI RPG content: the three statues on the plaza ring, three
GM 104 	// fragments out in the streets, the cache at the south wall. The
GM 105 	// quest system (UOMNIQuestSystem) runs the chain between them.
GM 106 	{
GM 107 		const TCHAR* Names[3] = { TEXT("Keeper"), TEXT("Seer"), TEXT("Cartographer") };
GM 108 		const FVector Spots[3] = {
GM 109 			FVector(900.f, 0.f, 10.f), FVector(-450.f, 780.f, 10.f), FVector(-450.f, -780.f, 10.f) };
GM 110 		const float Yaws[3] = { 180.f, -60.f, 60.f };
GM 111 		for (int32 i = 0; i < 3; ++i)
GM 112 		{
GM 113 			const FTransform T(FRotator(0.f, Yaws[i], 0.f), Spots[i]);
GM 114 			if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
GM 115 				AOMNIQuestGiver::StaticClass(), T))
GM 116 			{
GM 117 				Giver->GiverName = FName(Names[i]);
GM 118 				Giver->FinishSpawning(T);
GM 119 			}
GM 120 		}
GM 121 		const FVector Shards[3] = {
GM 122 			FVector(2000.f, 500.f, 260.f), FVector(-2000.f, -900.f, 260.f), FVector(600.f, -2100.f, 260.f) };
GM 123 		for (int32 i = 0; i < 3; ++i)
GM 124 		{
GM 125 			GetWorld()->SpawnActor<AOMNIFragment>(
GM 126 				AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
GM 127 		}
GM 128 		GetWorld()->SpawnActor<AOMNICache>(
GM 129 			AOMNICache::StaticClass(), FVector(0.f, -6200.f, 10.f), FRotator::ZeroRotator);
GM 130 	}
BIND VEILFactionAI.cpp 74 BindStoneBody();
BIND VEILFactionAI.cpp 235 void AVEILFactionAgent::BindStoneBody()
BIND VEILFactionAI.h 127 void BindStoneBody();
WARFILE D:\VEIL-OMNI\Source\VEIL\Private\AI\OMNIWardenPrime.cpp
WARFILE D:\VEIL-OMNI\Source\VEIL\Public\AI\OMNIWardenPrime.h
WAR OMNIWardenPrime.cpp 1 // OMNI RPG: PATH OF LIGHT - WARDEN PRIME implementation.
WAR OMNIWardenPrime.cpp 2 #include "AI/OMNIWardenPrime.h"
WAR OMNIWardenPrime.cpp 6 AOMNIWardenPrime::AOMNIWardenPrime()
WAR VEILFactionAI.cpp 240 // The Warden's own line names the material: nine hundred
WAR OMNIQuestSystem.cpp 5 #include "AI/OMNIWardenPrime.h"
WAR OMNIQuestSystem.cpp 112 WakeWarden();
WAR OMNIQuestSystem.cpp 115 void UOMNIQuestSystem::WakeWarden()
WAR OMNIQuestSystem.cpp 120 AOMNIWardenPrime* Boss = World->SpawnActor<AOMNIWardenPrime>(
WAR OMNIQuestSystem.cpp 121 AOMNIWardenPrime::StaticClass(), Loc, FRotator(0.f, 90.f, 0.f));
WAR OMNIQuestSystem.cpp 126 Warden = Boss;
WAR OMNIQuestSystem.cpp 127 Stage = EOMNIQuestStage::WardenAwake;
WAR OMNIQuestSystem.cpp 129 TEXT("OMNI QUEST: WARDEN PRIME HAS WOKEN at the plaza's south edge. Stage -> WardenAwake."));
WAR OMNIQuestSystem.cpp 136 if (Stage == EOMNIQuestStage::WardenAwake && Warden && !Warden->IsAlive())
WAR OMNIQuestSystem.cpp 140 AwardXP(100, TEXT("WARDEN PRIME down"));
WAR OMNIQuestSystem.cpp 142 TEXT("OMNI QUEST: WARDEN PRIME DOWN - PATH OF LIGHT CLEAR. +150 gold -> %d. The beacon burns steady."), Gold);
WAR OMNIWardenPrime.h 1 // OMNI RPG: PATH OF LIGHT - WARDEN PRIME, the plaza duel.
WAR OMNIWardenPrime.h 6 #include "OMNIWardenPrime.generated.h"
WAR OMNIWardenPrime.h 9 class VEIL_API AOMNIWardenPrime : public AVEILFactionAgent
WAR OMNIWardenPrime.h 14 AOMNIWardenPrime();
WAR OMNIQuestSystem.h 4 // (Keeper -> fragments -> Seer -> the cache -> WARDEN PRIME -> the clear),
WAR OMNIQuestSystem.h 6 // warden's waking. Everything is proven in the log: every stage turn, XP
WAR OMNIQuestSystem.h 14 class AOMNIWardenPrime;
WAR OMNIQuestSystem.h 23 WardenAwake,
WAR OMNIQuestSystem.h 60 void WakeWarden();
WAR OMNIQuestSystem.h 63 TObjectPtr<AOMNIWardenPrime> Warden;
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Murdock_AnimBlueprint.Murdock_AnimBlueprint bytes=576206
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock.Murdock bytes=10030394
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock_CylShadows.Murdock_CylShadows bytes=115698
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock_Extents.Murdock_Extents bytes=113482
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Murdock_Skeleton.Murdock_Skeleton bytes=47289
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Meshes/Paragon_Proto_Retarget.Paragon_Proto_Retarget bytes=68568
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Skins/Tier2/Corrupt/Meshes/Murdock_Corrupt.Murdock_Corrupt bytes=9817061
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Skins/Tier2/Merc/Meshes/Murdock_Merc.Murdock_Merc bytes=12395670
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Skins/Tier_1_5/Shogun/Meshes/Murdock_Shogun_GDC.Murdock_Shogun_GDC bytes=11850792
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Skins/Tier_1_5/Shogun/Meshes/Murdock_Shogun_PhysMat.Murdock_Shogun_PhysMat bytes=1228
ASSET /Game/ParagonMurdock/Characters/Heroes/Murdock/Skins/Tier_1_5/Shogun/Meshes/Murdock_Shogun_RigidBody.Murdock_Shogun_RigidBody bytes=130431
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_ElevenLaserBeam_Core_100X.SM_ElevenLaserBeam_Core_100X bytes=83129
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_ElevenLaserBeam_Core_Med_100X.SM_ElevenLaserBeam_Core_Med_100X bytes=2195311
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_ElevenLaserBeam_Glows_100X.SM_ElevenLaserBeam_Glows_100X bytes=84549
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_HoloSpline_Targeter.SM_HoloSpline_Targeter bytes=104464
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_MuzzleCore_02.SM_MuzzleCore_02 bytes=107228
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_PriceShield_Hex.SM_PriceShield_Hex bytes=311470
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_PriceShield_HexProject.SM_PriceShield_HexProject bytes=340692
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_PriceShield_MuzzleFX.SM_PriceShield_MuzzleFX bytes=186257
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_PriceShield_ProjectionPlane.SM_PriceShield_ProjectionPlane bytes=94683
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_Shield_ImpactRays.SM_Shield_ImpactRays bytes=194549
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_ShottyMuzzleCone.SM_ShottyMuzzleCone bytes=298262
ASSET /Game/ParagonMurdock/FX/Meshes/Heroes/Murdock/SM_ShottyMuzzleConeHalf.SM_ShottyMuzzleConeHalf bytes=206378
ASSET /Game/ParagonMurdock/FX/Meshes/MuzzleFlashes/SM_Muzzle_Flash.SM_Muzzle_Flash bytes=87697
ASSET /Game/ParagonMurdock/FX/Meshes/Shapes/SM_Camera_Mesh.SM_Camera_Mesh bytes=311547
ASSET /Game/ParagonMurdock/FX/Meshes/Shapes/SM_HalfSphere_100.SM_HalfSphere_100 bytes=144778
ASSET /Game/ParagonMurdock/FX/Meshes/Shapes/SM_Murdock_SlowDome.SM_Murdock_SlowDome bytes=736816
ASSET /Game/ParagonMurdock/FX/Meshes/Shapes/SM_Trap_Radius.SM_Trap_Radius bytes=379275
ASSET /Game/ParagonMurdock/FX/Meshes/Shapes/S_Sphere_FlippedNormals.S_Sphere_FlippedNormals bytes=226653
ASSET /Game/ParagonMurdock/FX/Meshes/Shells/SM_Murdock_SimpleUltBullet.SM_Murdock_SimpleUltBullet bytes=75526
ASSET /Game/ParagonMurdock/FX/Meshes/Shells/SM_PlasmaShot_Shell.SM_PlasmaShot_Shell bytes=124722
ASSET /Game/ParagonMurdock/FX/Meshes/Shells/SM_SpreadShotShell_LOW2.SM_SpreadShotShell_LOW2 bytes=120299
ASSET /Game/ParagonMurdock/FX/Meshes/Smoke/SM_Plasma_Mesh.SM_Plasma_Mesh bytes=142893
ASSET /Game/ParagonMurdock/FX/Meshes/Smoke/SM_Plasma_Mesh_Reduced.SM_Plasma_Mesh_Reduced bytes=143519
ASSET /Game/ParagonMurdock/FX/Meshes/Smoke/SM_SmokeFlat.SM_SmokeFlat bytes=358314
ASSET /Game/ParagonMurdock/FX/Meshes/Splines/M_Spline_Preview.M_Spline_Preview bytes=84994
ASSET /Game/ParagonMurdock/FX/Meshes/Splines/SM_Forward_Burst_Splines.SM_Forward_Burst_Splines bytes=122071
ASSET /Game/ParagonMurdock/FX/Meshes/Splines/SM_Holo_Interface_XAlinged.SM_Holo_Interface_XAlinged bytes=112448
ASSET /Game/ParagonMurdock/FX/Meshes/Splines/SM_Straight_Spline_100.SM_Straight_Spline_100 bytes=99736
ASSET /Game/ParagonMurdock/FX/Meshes/Splines/SM_Tech_Holo_Splines_XAlinged.SM_Tech_Holo_Splines_XAlinged bytes=153430
ASSET /Game/ParagonMurdock/FX/Meshes/Water/SM_WaterFall_RippleMeshes.SM_WaterFall_RippleMeshes bytes=489884
ASSET /Game/ParagonMurdock/FX/Meshes/Water/SM_WaterImpact_ImpactCylinder.SM_WaterImpact_ImpactCylinder bytes=234277
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Revenant_AnimBlueprint.Revenant_AnimBlueprint bytes=605977
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant.Revenant bytes=12493644
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant_Extents.Revenant_Extents bytes=119500
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant_ShadowCyl.Revenant_ShadowCyl bytes=114101
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant_Skeleton.Revenant_Skeleton bytes=43476
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant_SkeletonRig.Revenant_SkeletonRig bytes=81874
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Skins/ChronoBoss/Meshes/Revenant_ChronoBoss.Revenant_ChronoBoss bytes=12369442
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Skins/FrostKing/Meshes/Revenant_FrostKing.Revenant_FrostKing bytes=15120357
ASSET /Game/ParagonRevenant/Characters/Heroes/Revenant/Skins/RavenQuill/Meshes/Revenant_RavenQuill.Revenant_RavenQuill bytes=14047424
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/SM_BigPortal.SM_BigPortal bytes=224249
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/SM_BigPortal_Torus.SM_BigPortal_Torus bytes=300477
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/SM_PlasmaShot_Shell.SM_PlasmaShot_Shell bytes=123363
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/SM_Revenant_SlowDome.SM_Revenant_SlowDome bytes=736956
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_CamFacing_Chunks_01.SM_CamFacing_Chunks_01 bytes=163199
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Recall_Head_01.SM_Recall_Head_01 bytes=177814
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Recall_Lines_4Vari_01.SM_Recall_Lines_4Vari_01 bytes=115715
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revanent_Screen_Border.SM_Revanent_Screen_Border bytes=119504
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revenant_ArmSpiral_01.SM_Revenant_ArmSpiral_01 bytes=184634
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revenant_Projectile_01.SM_Revenant_Projectile_01 bytes=229731
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revenant_Splash_01.SM_Revenant_Splash_01 bytes=357572
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revenant_SplineMesh_01.SM_Revenant_SplineMesh_01 bytes=620638
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Revenant_Ult_CloudSpiral_01.SM_Revenant_Ult_CloudSpiral_01 bytes=259962
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_SpiralSphere_Background_01.SM_SpiralSphere_Background_01 bytes=297390
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_ThinSwirl_XFacing_4Vari_01.SM_ThinSwirl_XFacing_4Vari_01 bytes=132388
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_ThinSwirl_XFacing_Double_01.SM_ThinSwirl_XFacing_Double_01 bytes=170336
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/SM_Ult_Background_Debris_Sphere_01.SM_Ult_Background_Debris_Sphere_01 bytes=355786
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/S_Recall_Head_01.S_Recall_Head_01 bytes=1385
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/S_Recall_Lines_4Vari_01.S_Recall_Lines_4Vari_01 bytes=1441
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/S_ThinSwirl_XFacing_4Vari_01.S_ThinSwirl_XFacing_4Vari_01 bytes=1481
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/S_ThinSwirl_XFacing_Double_01.S_ThinSwirl_XFacing_Double_01 bytes=1489
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/Skins/FrostKing/SM_Revenant_FrostKing_Fire_Head_Trails.SM_Revenant_FrostKing_Fire_Head_Trails bytes=115101
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/Skins/FrostKing/SM_Revenant_FrostKing_Head_Core.SM_Revenant_FrostKing_Head_Core bytes=342716
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/Skins/FrostKing/SM_Revenant_FrostKing_ImpactMesh_CamFacing.SM_Revenant_FrostKing_ImpactMesh_CamFacing bytes=116652
ASSET /Game/ParagonRevenant/FX/Meshes/Heroes/Revenant/Skins/FrostKing/SM_Revenant_FrostKing_Projectile_Crystals.SM_Revenant_FrostKing_Projectile_Crystals bytes=303432
ASSET /Game/ParagonRevenant/FX/Meshes/Misc/SM_Camera_Mesh.SM_Camera_Mesh bytes=320730
ASSET /Game/ParagonRevenant/FX/Meshes/MuzzleFlashes/SM_Muzzle_Flash.SM_Muzzle_Flash bytes=98242
ASSET /Game/ParagonRevenant/FX/Meshes/Shapes/SM_Burden_Projectile.SM_Burden_Projectile bytes=197227
ASSET /Game/ParagonRevenant/FX/Meshes/Shapes/SM_Sphere_FlippedNormals.SM_Sphere_FlippedNormals bytes=244921
ASSET /Game/ParagonRevenant/FX/Meshes/Shapes/S_Sphere_FlippedNormals.S_Sphere_FlippedNormals bytes=1414
ASSET /Game/ParagonRevenant/FX/Meshes/Smoke/SM_Plasma_Mesh_Reduced.SM_Plasma_Mesh_Reduced bytes=152638
ASSET /Game/ParagonRevenant/FX/Meshes/Splines/M_Spline_Preview.M_Spline_Preview bytes=82315
ASSET /Game/ParagonRevenant/FX/Meshes/Splines/SM_Forward_Burst_Splines.SM_Forward_Burst_Splines bytes=129465
ASSET /Game/ParagonRevenant/FX/Meshes/Water/SM_WaterFall_RippleMeshes.SM_WaterFall_RippleMeshes bytes=497216
ASSET /Game/ParagonRevenant/FX/Meshes/Water/SM_WaterImpact_ImpactCylinder.SM_WaterImpact_ImpactCylinder bytes=247121
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Black/Meshes/Buff_Black.Buff_Black bytes=1171341
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Black/Meshes/Buff_Black_CylShadows.Buff_Black_CylShadows bytes=118258
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Black/Meshes/Buff_Black_Skeleton.Buff_Black_Skeleton bytes=14553
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Blue/Meshes/Buff_Blue.Buff_Blue bytes=855448
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Blue/Meshes/Buff_Blue_CylShadows.Buff_Blue_CylShadows bytes=94306
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Blue/Meshes/Buff_Blue_Skeleton.Buff_Blue_Skeleton bytes=6395
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Green/Meshes/Buff_Green.Buff_Green bytes=3006554
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Green/Meshes/Buff_Green_CylShadows.Buff_Green_CylShadows bytes=114116
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Green/Meshes/Buff_Green_Skeleton.Buff_Green_Skeleton bytes=16349
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Red/Meshes/Buff_Red.Buff_Red bytes=3003462
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Red/Meshes/Buff_Red_CylShadows.Buff_Red_CylShadows bytes=114106
ASSET /Game/ParagonMinions/Characters/Buff/Buff_Red/Meshes/Buff_Red_Skeleton.Buff_Red_Skeleton bytes=16377
ASSET /Game/ParagonMinions/Characters/Buff/Buff_White/Meshes/Buff_White.Buff_White bytes=1425764
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Core_Skeleton.Minion_Lane_Core_Skeleton bytes=30389
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Melee_Core_Dawn.Minion_Lane_Melee_Core_Dawn bytes=1284264
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Melee_Dawn.Minion_Lane_Melee_Dawn bytes=1610487
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Melee_Physics.Minion_Lane_Melee_Physics bytes=138256
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Melee_ShadowCyl.Minion_Lane_Melee_ShadowCyl bytes=132960
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Ranged_Core_Dawn.Minion_Lane_Ranged_Core_Dawn bytes=1345394
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Ranged_Dawn.Minion_Lane_Ranged_Dawn bytes=1580377
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Ranged_Physics.Minion_Lane_Ranged_Physics bytes=135848
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Ranged_ShadowCyl.Minion_Lane_Ranged_ShadowCyl bytes=130712
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_Core_Dawn.Minion_Lane_Siege_Core_Dawn bytes=1381139
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_Core_ShadowCyl.Minion_Lane_Siege_Core_ShadowCyl bytes=132945
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_Dawn.Minion_Lane_Siege_Dawn bytes=1669581
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_Physics.Minion_Lane_Siege_Physics bytes=139938
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_ShadowCyl.Minion_Lane_Siege_ShadowCyl bytes=136005
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Siege_Skeleton.Minion_Lane_Siege_Skeleton bytes=21177
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Super_Core_Dawn.Minion_Lane_Super_Core_Dawn bytes=1210930
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Super_Core_Physics.Minion_Lane_Super_Core_Physics bytes=147563
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Super_Dawn.Minion_Lane_Super_Dawn bytes=1324829
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/Minion_Lane_Super_ShadowCyl.Minion_Lane_Super_ShadowCyl bytes=132628
ASSET /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/SK_Minion_Lane_Super.SK_Minion_Lane_Super bytes=15362
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Melee_Core_Dusk.Minion_Lane_Melee_Core_Dusk bytes=1346495
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Melee_Core_ShadowCyl.Minion_Lane_Melee_Core_ShadowCyl bytes=131490
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Melee_Dusk.Minion_Lane_Melee_Dusk bytes=1472014
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Ranged_Core_Dusk.Minion_Lane_Ranged_Core_Dusk bytes=1465382
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Ranged_Core_ShadowCyl.Minion_Lane_Ranged_Core_ShadowCyl bytes=131180
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Ranged_Dusk.Minion_Lane_Ranged_Dusk bytes=1496468
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Siege_Core_ShadowCyl.Minion_Lane_Siege_Core_ShadowCyl bytes=101470
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Siege_Dusk.Minion_Lane_Siege_Dusk bytes=1654019
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Siege_Physics.Minion_Lane_Siege_Physics bytes=101442
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Siege_Skeleton.Minion_Lane_Siege_Skeleton bytes=21177
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Super_Core_Dusk.Minion_Lane_Super_Core_Dusk bytes=1470949
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Minion_Lane_Super_Dusk.Minion_Lane_Super_Dusk bytes=1534503
ASSET /Game/ParagonMinions/Characters/Minions/Dusk_Minions/Meshes/Siege_Core_Dusk.Siege_Core_Dusk bytes=2500012
ASSET /Game/ParagonMinions/Characters/Minions/Prime_Helix/Meshes/Prime_Helix.Prime_Helix bytes=2308202
ASSET /Game/ParagonMinions/Characters/Minions/Prime_Helix/Meshes/Prime_Helix_CylShadows.Prime_Helix_CylShadows bytes=136934
ASSET /Game/ParagonMinions/Characters/Minions/Prime_Helix/Meshes/Prime_Helix_Extents.Prime_Helix_Extents bytes=125910
ASSET /Game/ParagonMinions/Characters/Minions/Prime_Helix/Meshes/Prime_Helix_Skeleton.Prime_Helix_Skeleton bytes=20162
ASSET /Game/ParagonMinions/Characters/Minions/White_Camp_Minion/Meshes/Minion_CylShadows.Minion_CylShadows bytes=104576
ASSET /Game/ParagonMinions/Characters/Minions/White_Camp_Minion/Meshes/Minion_melee.Minion_melee bytes=1570175
ASSET /Game/ParagonMinions/Characters/Minions/White_Camp_Minion/Meshes/Minion_Skeleton.Minion_Skeleton bytes=29748
ASSET /Game/ParagonMinions/Characters/Minions/White_Camp_Minion/Meshes/Orion_Proto_Retarget.Orion_Proto_Retarget bytes=68571
ASSET /Game/ParagonMinions/FX/Meshes/Beams/SM_Aura_v1.SM_Aura_v1 bytes=145106
ASSET /Game/ParagonMinions/FX/Meshes/Beams/SM_Beam_Helix.SM_Beam_Helix bytes=97570
ASSET /Game/ParagonMinions/FX/Meshes/Beams/SM_Prime_Beam_V02.SM_Prime_Beam_V02 bytes=366883
ASSET /Game/ParagonMinions/FX/Meshes/Beams/SM_Recall_PlasmaBeam.SM_Recall_PlasmaBeam bytes=100389
ASSET /Game/ParagonMinions/FX/Meshes/Beams/SM_Shield_Lightbeams.SM_Shield_Lightbeams bytes=236147
ASSET /Game/ParagonMinions/FX/Meshes/Debris/Granite_Large_Grey_Mossy_Rough.Granite_Large_Grey_Mossy_Rough bytes=1501157
PHI WB489 VERDICT: WORLD GROUND wb=1 assets=146
JOB 489 DONE

```
