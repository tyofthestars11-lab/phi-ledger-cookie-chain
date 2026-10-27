// VEIL: THE LAST SIGNAL - pause menu, built in C++ (no widget assets).
// Resume, Graphics, Quit to Title, Quit Game. The PlayerController's
// PauseWidgetClass points here - before this class existed the pause
// toggle paused the game behind NO visible menu at all, which is the
// trap Tyree hit: frozen game, nothing on screen to exit through.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VEILPauseMenu.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class VEIL_API UVEILPauseMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnResumeClicked();

	UFUNCTION()
	void OnQualityClicked();

	UFUNCTION()
	void OnTitleClicked();

	UFUNCTION()
	void OnQuitClicked();

	void RefreshQualityLabel();

	TObjectPtr<UButton> ResumeButton;
	TObjectPtr<UButton> QualityButton;
	TObjectPtr<UButton> TitleButton;
	TObjectPtr<UButton> QuitButton;
	TObjectPtr<UTextBlock> QualityLabel;

	int32 QualityLevel = 1;
};
