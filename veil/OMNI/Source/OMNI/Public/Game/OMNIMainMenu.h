// OMNI: THE LAST SIGNAL - main menu, built in C++ (no widget assets needed).
// Title, Enter the Signal (start), Graphics (cycles scalability for the
// RTX 3050), Quit. Shown by AOMNIPlayerController at boot; works with
// mouse, keyboard focus, and Xbox controller navigation.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OMNIMainMenu.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class OMNI_API UOMNIMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnStartClicked();

	UFUNCTION()
	void OnGodClicked();

	UFUNCTION()
	void OnQualityClicked();

	UFUNCTION()
	void OnQuitClicked();

	void RefreshQualityLabel();
	void RefreshGodLabel();

	TObjectPtr<UButton> StartButton;
	TObjectPtr<UButton> GodButton;
	TObjectPtr<UButton> QualityButton;
	TObjectPtr<UButton> QuitButton;
	TObjectPtr<UTextBlock> QualityLabel;
	TObjectPtr<UTextBlock> GodLabel;

	/** 0 Low, 1 Medium, 2 High, 3 Epic - prototype default is 1 (Medium). */
	int32 QualityLevel = 1;
};
