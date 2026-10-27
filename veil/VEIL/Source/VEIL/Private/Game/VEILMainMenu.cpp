// VEIL: THE LAST SIGNAL - main menu implementation.
#include "Game/VEILMainMenu.h"

#include "Blueprint/WidgetTree.h"

#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Game/VEILGameMode.h"
#include "Character/VEILCharacter.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "VEIL.h"

void UVEILMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	// Build the whole layout in code so the menu exists with zero assets.
	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
	WidgetTree->RootWidget = Canvas;

	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
	BoxSlot->SetAutoSize(true);

	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
	{
		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		Text->SetText(FText::FromString(Content));
		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
		Slot->SetHorizontalAlignment(HAlign_Center);
		return Text;
	};

	auto AddButton = [this, Box, &AddText](const FString& Label) -> UButton*
	{
		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		Text->SetText(FText::FromString(Label));
		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22));
		Button->AddChild(Text);
		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Button);
		Slot->SetPadding(FMargin(0.f, 4.f, 0.f, 4.f));
		return Button;
	};

	AddText(TEXT("VEIL"), 64);
	AddText(TEXT("THE LAST SIGNAL"), 24);

	GodButton = AddButton(TEXT("GODMODE"));
	GodLabel = AddText(TEXT(""), 16);
	StartButton = AddButton(TEXT("Enter the Signal"));
	QualityButton = AddButton(TEXT("Graphics"));
	QualityLabel = AddText(TEXT(""), 16);
	QuitButton = AddButton(TEXT("Quit"));

	StartButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnStartClicked);
	GodButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnGodClicked);
	QualityButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQualityClicked);
	QuitButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQuitClicked);

	StartButton->SetKeyboardFocus();
	RefreshQualityLabel();
	RefreshGodLabel();
}

void UVEILMainMenu::RefreshGodLabel()
{
	bool bOn = false;
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
		{
			bOn = Runner->IsGodMode();
		}
	}
	if (GodLabel)
	{
		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
	}
}

void UVEILMainMenu::OnGodClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
		{
			Runner->ToggleGodMode();
		}
	}
	RefreshGodLabel();
}

void UVEILMainMenu::RefreshQualityLabel()
{
	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
	if (QualityLabel)
	{
		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
	}
}

void UVEILMainMenu::OnStartClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->SetPause(false);
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;
	}
	if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->SetPhase(EVEILGamePhase::Exploration);
	}
	RemoveFromParent();
	UE_LOG(LogVEIL, Log, TEXT("Main menu: Enter the Signal."));
}

void UVEILMainMenu::OnQualityClicked()
{
	QualityLevel = (QualityLevel + 1) % 4;
	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
	{
		Settings->SetOverallScalabilityLevel(QualityLevel);
		Settings->ApplySettings(false);
	}
	RefreshQualityLabel();
}

void UVEILMainMenu::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
