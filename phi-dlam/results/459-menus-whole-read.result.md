# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 18:37:01 UTC

## STEP 1
```
=== MENUS WHOLE READ 459 - BOTH MENUS AND THE BOOT, READ WHOLE BEFORE THE MENU BUILD (Ground from Tyree hands, 2026-10-28: pressing Start still pauses, like freezes, and his word stands as the order: we need the menus. Job 453 named the pause path: Start binds to TogglePauseMenu on the player controller even while the title menu stands, so at the title a Start press stacks a pause over the menu and stops the world clock, and in the world it pauses with whatever the pause widget truly renders, which no read has yet verified whole. Job 458 seats Resume focus, but focus is not visibility. The menus themselves are small files, VEILPauseMenu cpp at 4891 bytes and VEILMainMenu cpp at 4701, and the rebuild authors from their whole text, not fragments. One, this job prints VEILPauseMenu cpp whole, capped at 220 lines. Two, it prints VEILMainMenu cpp whole, capped at 220 lines. Three, it prints the player controller menu boot region from VEILGameMode cpp: every line naming the main menu widget, the input mode, the pause widget and the phase, capped at 50, so the title and pause stacking stands read. The verdict in one line: MENUS READ with both files line counts and whether a title guard stands anywhere in the boot region. This job is read only and every variable carries the mw459 prefix.) ===
PAUSE 1 // VEIL: THE LAST SIGNAL - pause menu implementation.
PAUSE 2 #include "Game/VEILPauseMenu.h"
PAUSE 3 
PAUSE 4 #include "Blueprint/WidgetTree.h"
PAUSE 5 #include "Components/Button.h"
PAUSE 6 #include "Components/CanvasPanel.h"
PAUSE 7 #include "Components/CanvasPanelSlot.h"
PAUSE 8 #include "Components/TextBlock.h"
PAUSE 9 #include "Components/VerticalBox.h"
PAUSE 10 #include "Components/VerticalBoxSlot.h"
PAUSE 11 #include "Game/VEILGameMode.h"
PAUSE 12 #include "Character/VEILCharacter.h"
PAUSE 13 #include "GameFramework/Pawn.h"
PAUSE 14 #include "GameFramework/GameUserSettings.h"
PAUSE 15 #include "Kismet/GameplayStatics.h"
PAUSE 16 #include "Kismet/KismetSystemLibrary.h"
PAUSE 17 #include "VEIL.h"
PAUSE 18 
PAUSE 19 void UVEILPauseMenu::NativeConstruct()
PAUSE 20 {
PAUSE 21 	Super::NativeConstruct();
PAUSE 22 
PAUSE 23 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
PAUSE 24 	WidgetTree->RootWidget = Canvas;
PAUSE 25 
PAUSE 26 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
PAUSE 27 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
PAUSE 28 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
PAUSE 29 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
PAUSE 30 	BoxSlot->SetAutoSize(true);
PAUSE 31 
PAUSE 32 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
PAUSE 33 	{
PAUSE 34 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
PAUSE 35 		Text->SetText(FText::FromString(Content));
PAUSE 36 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
PAUSE 37 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
PAUSE 38 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
PAUSE 39 		Slot->SetHorizontalAlignment(HAlign_Center);
PAUSE 40 		return Text;
PAUSE 41 	};
PAUSE 42 
PAUSE 43 	auto AddButton = [this, Box](const FString& Label) -> UButton*
PAUSE 44 	{
PAUSE 45 		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
PAUSE 46 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
PAUSE 47 		Text->SetText(FText::FromString(Label));
PAUSE 48 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22));
PAUSE 49 		Button->AddChild(Text);
PAUSE 50 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Button);
PAUSE 51 		Slot->SetPadding(FMargin(0.f, 4.f, 0.f, 4.f));
PAUSE 52 		return Button;
PAUSE 53 	};
PAUSE 54 
PAUSE 55 	AddText(TEXT("PAUSED"), 40);
PAUSE 56 	AddText(TEXT("THE LAST SIGNAL HOLDS"), 16);
PAUSE 57 
PAUSE 58 	GodButton = AddButton(TEXT("GODMODE"));
PAUSE 59 	GodLabel = AddText(TEXT(""), 16);
PAUSE 60 	ResumeButton = AddButton(TEXT("Resume"));
PAUSE 61 	QualityButton = AddButton(TEXT("Graphics"));
PAUSE 62 	QualityLabel = AddText(TEXT(""), 16);
PAUSE 63 	TitleButton = AddButton(TEXT("Quit to Title"));
PAUSE 64 	QuitButton = AddButton(TEXT("Quit Game"));
PAUSE 65 
PAUSE 66 	ResumeButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnResumeClicked);
PAUSE 67 	ResumeButton->SetKeyboardFocus();
PAUSE 68 	GodButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnGodClicked);
PAUSE 69 	QualityButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQualityClicked);
PAUSE 70 	TitleButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnTitleClicked);
PAUSE 71 	QuitButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQuitClicked);
PAUSE 72 
PAUSE 73 	ResumeButton->SetKeyboardFocus();
PAUSE 74 	RefreshQualityLabel();
PAUSE 75 	RefreshGodLabel();
PAUSE 76 }
PAUSE 77 
PAUSE 78 void UVEILPauseMenu::RefreshGodLabel()
PAUSE 79 {
PAUSE 80 	bool bOn = false;
PAUSE 81 	if (APlayerController* PC = GetOwningPlayer())
PAUSE 82 	{
PAUSE 83 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
PAUSE 84 		{
PAUSE 85 			bOn = Runner->IsGodMode();
PAUSE 86 		}
PAUSE 87 	}
PAUSE 88 	if (GodLabel)
PAUSE 89 	{
PAUSE 90 		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
PAUSE 91 	}
PAUSE 92 }
PAUSE 93 
PAUSE 94 void UVEILPauseMenu::OnGodClicked()
PAUSE 95 {
PAUSE 96 	if (APlayerController* PC = GetOwningPlayer())
PAUSE 97 	{
PAUSE 98 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
PAUSE 99 		{
PAUSE 100 			Runner->ToggleGodMode();
PAUSE 101 		}
PAUSE 102 	}
PAUSE 103 	RefreshGodLabel();
PAUSE 104 }
PAUSE 105 
PAUSE 106 void UVEILPauseMenu::RefreshQualityLabel()
PAUSE 107 {
PAUSE 108 	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
PAUSE 109 	if (QualityLabel)
PAUSE 110 	{
PAUSE 111 		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
PAUSE 112 	}
PAUSE 113 }
PAUSE 114 
PAUSE 115 void UVEILPauseMenu::OnResumeClicked()
PAUSE 116 {
PAUSE 117 	if (AVEILPlayerController* PC = Cast<AVEILPlayerController>(GetOwningPlayer()))
PAUSE 118 	{
PAUSE 119 		PC->TogglePauseMenu();
PAUSE 120 	}
PAUSE 121 }
PAUSE 122 
PAUSE 123 void UVEILPauseMenu::OnQualityClicked()
PAUSE 124 {
PAUSE 125 	QualityLevel = (QualityLevel + 1) % 4;
PAUSE 126 	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
PAUSE 127 	{
PAUSE 128 		Settings->SetOverallScalabilityLevel(QualityLevel);
PAUSE 129 		Settings->ApplySettings(false);
PAUSE 130 	}
PAUSE 131 	RefreshQualityLabel();
PAUSE 132 }
PAUSE 133 
PAUSE 134 void UVEILPauseMenu::OnTitleClicked()
PAUSE 135 {
PAUSE 136 	// Back to the title: reload the level; boot state is the main menu
PAUSE 137 	// over a paused world, so the game lands on its title screen.
PAUSE 138 	if (APlayerController* PC = GetOwningPlayer())
PAUSE 139 	{
PAUSE 140 		PC->SetPause(false);
PAUSE 141 	}
PAUSE 142 	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
PAUSE 143 	UE_LOG(LogVEIL, Log, TEXT("Pause menu: Quit to Title."));
PAUSE 144 }
PAUSE 145 
PAUSE 146 void UVEILPauseMenu::OnQuitClicked()
PAUSE 147 {
PAUSE 148 	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
PAUSE 149 }
MAIN 1 // VEIL: THE LAST SIGNAL - main menu implementation.
MAIN 2 #include "Game/VEILMainMenu.h"
MAIN 3 
MAIN 4 #include "Blueprint/WidgetTree.h"
MAIN 5 
MAIN 6 #include "Components/Button.h"
MAIN 7 #include "Components/CanvasPanel.h"
MAIN 8 #include "Components/CanvasPanelSlot.h"
MAIN 9 #include "Components/TextBlock.h"
MAIN 10 #include "Components/VerticalBox.h"
MAIN 11 #include "Components/VerticalBoxSlot.h"
MAIN 12 #include "Game/VEILGameMode.h"
MAIN 13 #include "Character/VEILCharacter.h"
MAIN 14 #include "GameFramework/Pawn.h"
MAIN 15 #include "GameFramework/GameUserSettings.h"
MAIN 16 #include "Kismet/GameplayStatics.h"
MAIN 17 #include "Kismet/KismetSystemLibrary.h"
MAIN 18 #include "VEIL.h"
MAIN 19 
MAIN 20 void UVEILMainMenu::NativeConstruct()
MAIN 21 {
MAIN 22 	Super::NativeConstruct();
MAIN 23 
MAIN 24 	// Build the whole layout in code so the menu exists with zero assets.
MAIN 25 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
MAIN 26 	WidgetTree->RootWidget = Canvas;
MAIN 27 
MAIN 28 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
MAIN 29 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
MAIN 30 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
MAIN 31 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
MAIN 32 	BoxSlot->SetAutoSize(true);
MAIN 33 
MAIN 34 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
MAIN 35 	{
MAIN 36 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MAIN 37 		Text->SetText(FText::FromString(Content));
MAIN 38 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
MAIN 39 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
MAIN 40 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
MAIN 41 		Slot->SetHorizontalAlignment(HAlign_Center);
MAIN 42 		return Text;
MAIN 43 	};
MAIN 44 
MAIN 45 	auto AddButton = [this, Box, &AddText](const FString& Label) -> UButton*
MAIN 46 	{
MAIN 47 		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
MAIN 48 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MAIN 49 		Text->SetText(FText::FromString(Label));
MAIN 50 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22));
MAIN 51 		Button->AddChild(Text);
MAIN 52 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Button);
MAIN 53 		Slot->SetPadding(FMargin(0.f, 4.f, 0.f, 4.f));
MAIN 54 		return Button;
MAIN 55 	};
MAIN 56 
MAIN 57 	AddText(TEXT("VEIL"), 64);
MAIN 58 	AddText(TEXT("THE LAST SIGNAL"), 24);
MAIN 59 
MAIN 60 	GodButton = AddButton(TEXT("GODMODE"));
MAIN 61 	GodLabel = AddText(TEXT(""), 16);
MAIN 62 	StartButton = AddButton(TEXT("Enter the Signal"));
MAIN 63 	QualityButton = AddButton(TEXT("Graphics"));
MAIN 64 	QualityLabel = AddText(TEXT(""), 16);
MAIN 65 	QuitButton = AddButton(TEXT("Quit"));
MAIN 66 
MAIN 67 	StartButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnStartClicked);
MAIN 68 	GodButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnGodClicked);
MAIN 69 	QualityButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQualityClicked);
MAIN 70 	QuitButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQuitClicked);
MAIN 71 
MAIN 72 	StartButton->SetKeyboardFocus();
MAIN 73 	RefreshQualityLabel();
MAIN 74 	RefreshGodLabel();
MAIN 75 }
MAIN 76 
MAIN 77 void UVEILMainMenu::RefreshGodLabel()
MAIN 78 {
MAIN 79 	bool bOn = false;
MAIN 80 	if (APlayerController* PC = GetOwningPlayer())
MAIN 81 	{
MAIN 82 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
MAIN 83 		{
MAIN 84 			bOn = Runner->IsGodMode();
MAIN 85 		}
MAIN 86 	}
MAIN 87 	if (GodLabel)
MAIN 88 	{
MAIN 89 		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
MAIN 90 	}
MAIN 91 }
MAIN 92 
MAIN 93 void UVEILMainMenu::OnGodClicked()
MAIN 94 {
MAIN 95 	if (APlayerController* PC = GetOwningPlayer())
MAIN 96 	{
MAIN 97 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
MAIN 98 		{
MAIN 99 			Runner->ToggleGodMode();
MAIN 100 		}
MAIN 101 	}
MAIN 102 	RefreshGodLabel();
MAIN 103 }
MAIN 104 
MAIN 105 void UVEILMainMenu::RefreshQualityLabel()
MAIN 106 {
MAIN 107 	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
MAIN 108 	if (QualityLabel)
MAIN 109 	{
MAIN 110 		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
MAIN 111 	}
MAIN 112 }
MAIN 113 
MAIN 114 void UVEILMainMenu::OnStartClicked()
MAIN 115 {
MAIN 116 	if (APlayerController* PC = GetOwningPlayer())
MAIN 117 	{
MAIN 118 		PC->SetPause(false);
MAIN 119 		PC->SetInputMode(FInputModeGameOnly());
MAIN 120 		PC->bShowMouseCursor = false;
MAIN 121 	}
MAIN 122 	if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
MAIN 123 	{
MAIN 124 		GM->SetPhase(EVEILGamePhase::Exploration);
MAIN 125 	}
MAIN 126 	RemoveFromParent();
MAIN 127 	UE_LOG(LogVEIL, Log, TEXT("Main menu: Enter the Signal."));
MAIN 128 }
MAIN 129 
MAIN 130 void UVEILMainMenu::OnQualityClicked()
MAIN 131 {
MAIN 132 	QualityLevel = (QualityLevel + 1) % 4;
MAIN 133 	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
MAIN 134 	{
MAIN 135 		Settings->SetOverallScalabilityLevel(QualityLevel);
MAIN 136 		Settings->ApplySettings(false);
MAIN 137 	}
MAIN 138 	RefreshQualityLabel();
MAIN 139 }
MAIN 140 
MAIN 141 void UVEILMainMenu::OnQuitClicked()
MAIN 142 {
MAIN 143 	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
MAIN 144 }
BOOT 14 #include "Game/VEILMainMenu.h"
BOOT 152 SetPhase(EVEILGamePhase::Exploration);
BOOT 157 void AVEILGameMode::SetPhase(EVEILGamePhase NewPhase)
BOOT 171 SetPhase(EVEILGamePhase::Resolution);
BOOT 180 MainMenuWidgetClass = UVEILMainMenu::StaticClass();
BOOT 200 if (MainMenuWidgetClass && IsLocalController())
BOOT 202 MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
BOOT 203 if (MainMenuWidget)
BOOT 205 MainMenuWidget->AddToViewport(20);
BOOT 207 SetInputMode(FInputModeGameAndUI());
BOOT 212 SetInputMode(FInputModeGameOnly());
BOOT 239 SetInputMode(FInputModeGameAndUI());
BOOT 245 SetInputMode(FInputModeGameOnly());
PHI MW459 VERDICT: MENUS READ pause_lines=149 main_lines=144 boot_mainmenu_lines=5
JOB 459 DONE

```
