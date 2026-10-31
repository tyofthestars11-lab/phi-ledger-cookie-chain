// VEIL OMNI real minimap: render-target + UMG, NOT a bland placeholder.
// How it works, whole:
//  1. AVEILMinimapCapture (place ONE in VEILDistrict, high above the
//     district) looks straight down with a SceneCaptureComponent2D in
//     orthographic mode and writes to a UTextureRenderTarget2D.
//     That render target IS the minimap image: it shows the real
//     district as built, with real Paragon/SICKA/MetaHuman assets in
//     place, not a painted fake.
//  2. UVEILMinimapWidget (UMG, put in the HUD) shows that render
//     target in an Image named MinimapImage, and moves a player
//     marker by converting the player pawn's world XY into minimap UV.
//  3. If no render target is assigned, the capture creates a transient
//     512x512 render target in BeginPlay and logs it - the widget
//     still shows a live (empty) target instead of a static picture.
// Bounds: WorldMin/WorldMax are EDITOR-TUNED in the capture actor
// (default +-8000 covers the VEILDistrict tower grid at 1450 spacing
// x7 plus plaza; tune to the placed map in editor, do not claim these
// numbers are a measured map census).
// UNCONFIRMED / EDITOR-ONLY: the widget Blueprint must contain an
// Image named MinimapImage, and the capture actor must be placed in
// the map. Code alone does not create a .umap, a .uasset render
// target, or a widget Blueprint - those are editor steps, listed in
// VEIL_OMNI_INSTALL_MAP.md, and a PC editor photo is the proof.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Actor.h"
#include "VEILMinimap.generated.h"

class USceneCaptureComponent2D;
class UTextureRenderTarget2D;
class UImage;

UCLASS()
class VEIL_API AVEILMinimapCapture : public AActor
{
	GENERATED_BODY()

public:
	AVEILMinimapCapture();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Minimap")
	TObjectPtr<USceneCaptureComponent2D> Capture;

	/** Assign a real render-target asset in editor for a saved target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Minimap")
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Minimap")
	FVector2D WorldMin = FVector2D(-8000.f, -8000.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Minimap")
	FVector2D WorldMax = FVector2D(8000.f, 8000.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Minimap")
	float CaptureHeight = 6000.f;

	UFUNCTION(BlueprintPure, Category = "VEIL|Minimap")
	FVector2D WorldToMinimapUV(const FVector& WorldLocation) const;
};

UCLASS()
class VEIL_API UVEILMinimapWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/** The render target the capture writes. Set from HUD / GameMode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Minimap")
	TObjectPtr<UTextureRenderTarget2D> MinimapRenderTarget;

protected:
	// BindWidgetOptional: a widget Blueprint without this Image still
	// constructs; NativeTick logs the miss instead of crashing.
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UImage> MinimapImage;
};
