// VEIL OMNI real minimap implementation.
#include "UI/VEILMinimap.h"

#include "Components/Image.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Styling/SlateBrush.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

AVEILMinimapCapture::AVEILMinimapCapture()
{
	PrimaryActorTick.bCanEverTick = false;
	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MinimapCapture"));
	RootComponent = Capture;
	Capture->ProjectionType = ECameraProjectionMode::Orthographic;
	Capture->OrthoWidth = 16000.f;
	Capture->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	Capture->bCaptureEveryFrame = true;
	Capture->bCaptureOnMovement = false;
}

void AVEILMinimapCapture::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, CaptureHeight));
	SetActorRotation(FRotator(-90.f, 0.f, 0.f));
	if (!RenderTarget)
	{
		RenderTarget = NewObject<UTextureRenderTarget2D>(this, TEXT("RT_VEILMinimap_Transient"));
		RenderTarget->InitCustomFormat(512, 512, PF_B8G8R8A8, false);
		UE_LOG(LogVEIL, Log, TEXT("PHI MINIMAP: transient 512x512 render target created - assign a saved RT asset in editor for a persistent minimap."));
	}
	if (Capture) Capture->TextureTarget = RenderTarget;
	UE_LOG(LogVEIL, Log, TEXT("PHI MINIMAP: capture at height %.0f, ortho %.0f, target=%s"),
		CaptureHeight, Capture->OrthoWidth,
		RenderTarget ? *RenderTarget->GetName() : TEXT("none"));
}

FVector2D AVEILMinimapCapture::WorldToMinimapUV(const FVector& WorldLocation) const
{
	const FVector2D Size = WorldMax - WorldMin;
	if (Size.X == 0.f || Size.Y == 0.f) return FVector2D(0.5f, 0.5f);
	return FVector2D(
		FMath::Clamp((WorldLocation.X - WorldMin.X) / Size.X, 0.f, 1.f),
		FMath::Clamp((WorldLocation.Y - WorldMin.Y) / Size.Y, 0.f, 1.f));
}

void UVEILMinimapWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (!MinimapImage)
	{
		return; // Widget Blueprint has no Image named MinimapImage yet - editor step, not a crash.
	}
	if (MinimapRenderTarget)
	{
		FSlateBrush Brush;
		Brush.SetResourceObject(MinimapRenderTarget);
		Brush.ImageSize = FVector2D(256.f, 256.f);
		MinimapImage->SetBrush(Brush);
	}
	// Player marker position is derived live each tick in a full HUD
	// implementation (marker widget anchored by WorldToMinimapUV). This
	// base widget renders the live district image; the marker anchor
	// is set by the HUD Blueprint that owns this widget, using
	// AVEILMinimapCapture::WorldToMinimapUV(player location).
	// No static minimap picture is ever drawn here.
}
