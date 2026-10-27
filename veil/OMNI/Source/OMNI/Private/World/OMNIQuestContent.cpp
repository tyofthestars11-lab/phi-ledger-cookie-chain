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
