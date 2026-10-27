// OMNI RPG: PATH OF LIGHT - pause menu implementation.
#include "Game/OMNIPauseMenu.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Game/OMNIGameMode.h"
#include "Character/OMNICharacter.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "OMNI.h"

void UOMNIPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();

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

	auto AddButton = [this, Box](const FString& Label) -> UButton*
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

	AddText(TEXT("PAUSED"), 40);
	AddText(TEXT("THE LAST SIGNAL HOLDS"), 16);

	GodButton = AddButton(TEXT("GODMODE"));
	GodLabel = AddText(TEXT(""), 16);
	ResumeButton = AddButton(TEXT("Resume"));
	QualityButton = AddButton(TEXT("Graphics"));
	QualityLabel = AddText(TEXT(""), 16);
	TitleButton = AddButton(TEXT("Quit to Title"));
	QuitButton = AddButton(TEXT("Quit Game"));

	ResumeButton->OnClicked.AddDynamic(this, &UOMNIPauseMenu::OnResumeClicked);
	GodButton->OnClicked.AddDynamic(this, &UOMNIPauseMenu::OnGodClicked);
	QualityButton->OnClicked.AddDynamic(this, &UOMNIPauseMenu::OnQualityClicked);
	TitleButton->OnClicked.AddDynamic(this, &UOMNIPauseMenu::OnTitleClicked);
	QuitButton->OnClicked.AddDynamic(this, &UOMNIPauseMenu::OnQuitClicked);

	ResumeButton->SetKeyboardFocus();
	RefreshQualityLabel();
	RefreshGodLabel();
}

void UOMNIPauseMenu::RefreshGodLabel()
{
	bool bOn = false;
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (AOMNICharacter* Runner = Cast<AOMNICharacter>(PC->GetPawn()))
		{
			bOn = Runner->IsGodMode();
		}
	}
	if (GodLabel)
	{
		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
	}
}

void UOMNIPauseMenu::OnGodClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (AOMNICharacter* Runner = Cast<AOMNICharacter>(PC->GetPawn()))
		{
			Runner->ToggleGodMode();
		}
	}
	RefreshGodLabel();
}

void UOMNIPauseMenu::RefreshQualityLabel()
{
	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
	if (QualityLabel)
	{
		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
	}
}

void UOMNIPauseMenu::OnResumeClicked()
{
	if (AOMNIPlayerController* PC = Cast<AOMNIPlayerController>(GetOwningPlayer()))
	{
		PC->TogglePauseMenu();
	}
}

void UOMNIPauseMenu::OnQualityClicked()
{
	QualityLevel = (QualityLevel + 1) % 4;
	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
	{
		Settings->SetOverallScalabilityLevel(QualityLevel);
		Settings->ApplySettings(false);
	}
	RefreshQualityLabel();
}

void UOMNIPauseMenu::OnTitleClicked()
{
	// Back to the title: reload the level; boot state is the main menu
	// over a paused world, so the game lands on its title screen.
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->SetPause(false);
	}
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
	UE_LOG(LogOMNI, Log, TEXT("Pause menu: Quit to Title."));
}

void UOMNIPauseMenu::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
