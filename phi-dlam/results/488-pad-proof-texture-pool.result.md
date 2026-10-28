# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 20:55:28 UTC

## STEP 1
```
=== PAD PROOF 488 - THE PAD SPEAKS IN THE LOG (Ground: Tyree, 2026-10-28: fix the game pad for VEIL, it worked fine before just jumping and running, and his editor photo the same minutes: she stands, the world clock runs, paused equals 0, and the red line reads video memory exhausted 18.258 MB over budget while the bodies stand black against the sky. The pad worked in his hands in the 442 era, keyboard and mouse work now, the source pad map stands whole at 18 keys, both input seats stand written, and the 482 build is green, so the fault lives at runtime where no source read can see it. This job prints the GameMode input region and the main menu file whole, raises the texture streaming pool to 2500 in DefaultEngine.ini so the bodies can take their real materials, seats PHI PAD PROOF in the character Tick: every two seconds the log reads the raw stick and button state straight from the controller and which mapping contexts stand seated, a read that names its own fault line next play. The build runs when the editor stands closed; when the editor stands open the patch stands written and the build rides the next drain. Every variable carries the gp488 prefix.) ===
GM 180 	MainMenuWidgetClass = UVEILMainMenu::StaticClass();
GM 181 	PauseWidgetClass = UVEILPauseMenu::StaticClass();
GM 182 }
GM 183 
GM 184 static FTimerHandle GPhiTimerHandle;
GM 185 
GM 186 void AVEILPlayerController::BeginPlay()
GM 187 {
GM 188 	Super::BeginPlay();
GM 189 	// Timer cross-check: a 3-second one-shot on the world's own timer
GM 190 	// manager. If world time advances, PhiOnTimerCheck fires and logs
GM 191 	// it; if the clock stands frozen, the TICKPROOF shows it pending.
GM 192 	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);
GM 193 
GM 194 	if (HUDWidgetClass && IsLocalController())
GM 195 	{
GM 196 		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
GM 197 		if (HUDWidget) HUDWidget->AddToViewport(0);
GM 198 	}
GM 199 
GM 200 	if (MainMenuWidgetClass && IsLocalController())
GM 201 	{
GM 202 		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
GM 203 		if (MainMenuWidget)
GM 204 		{
GM 205 			MainMenuWidget->AddToViewport(20);
GM 206 			SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
GM 207 			SetInputMode(FInputModeGameAndUI());
GM 208 			bShowMouseCursor = true;
GM 209 			return;
GM 210 		}
GM 211 	}
GM 212 	SetInputMode(FInputModeGameOnly());
GM 213 	bShowMouseCursor = false;
GM 214 }
GM 215 
GM 216 void AVEILPlayerController::SetupInputComponent()
GM 217 {
GM 218 	Super::SetupInputComponent();
GM 219 	if (InputComponent)
GM 220 	{
GM 221 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 222 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 223 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 224 		InputComponent->BindKey(EKeys::F, IE_Pressed, this, &AVEILPlayerController::ToggleFlight);
GM 225 	}
GM 226 }
GM 227 
GM 228 void AVEILPlayerController::TogglePauseMenu()
GM 229 {
GM 230 	// Title stands: while the main menu is up, Start summons nothing.
MENU LINES=151
MENU 1 // VEIL: THE LAST SIGNAL - main menu implementation.
MENU 2 #include "Game/VEILMainMenu.h"
MENU 3 
MENU 4 #include "Blueprint/WidgetTree.h"
MENU 5 
MENU 6 #include "Components/Button.h"
MENU 7 #include "Components/Border.h"
MENU 8 #include "Components/CanvasPanel.h"
MENU 9 #include "Components/CanvasPanelSlot.h"
MENU 10 #include "Components/TextBlock.h"
MENU 11 #include "Components/VerticalBox.h"
MENU 12 #include "Components/VerticalBoxSlot.h"
MENU 13 #include "Game/VEILGameMode.h"
MENU 14 #include "Character/VEILCharacter.h"
MENU 15 #include "GameFramework/Pawn.h"
MENU 16 #include "GameFramework/GameUserSettings.h"
MENU 17 #include "Kismet/GameplayStatics.h"
MENU 18 #include "Kismet/KismetSystemLibrary.h"
MENU 19 #include "VEIL.h"
MENU 20 
MENU 21 void UVEILMainMenu::NativeConstruct()
MENU 22 {
MENU 23 	Super::NativeConstruct();
MENU 24 
MENU 25 	// Build the whole layout in code so the menu exists with zero assets.
MENU 26 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
MENU 27 	WidgetTree->RootWidget = Canvas;
MENU 28 	UBorder* Dim = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Dim"));
MENU 29 	Dim->SetBrushColor(FLinearColor(0.f, 0.f, 0.f, 0.72f));
MENU 30 	UCanvasPanelSlot* DimSlot = Canvas->AddChildToCanvas(Dim);
MENU 31 	DimSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
MENU 32 	DimSlot->SetOffsets(FMargin(0.f));
MENU 33 
MENU 34 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
MENU 35 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
MENU 36 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
MENU 37 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
MENU 38 	BoxSlot->SetAutoSize(true);
MENU 39 
MENU 40 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
MENU 41 	{
MENU 42 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MENU 43 		Text->SetText(FText::FromString(Content));
MENU 44 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
MENU 45 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
MENU 46 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
MENU 47 		Slot->SetHorizontalAlignment(HAlign_Center);
MENU 48 		return Text;
MENU 49 	};
MENU 50 
MENU 51 	auto AddButton = [this, Box, &AddText](const FString& Label) -> UButton*
MENU 52 	{
MENU 53 		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
MENU 54 		Button->SetBackgroundColor(FLinearColor(0.13f, 0.10f, 0.02f, 0.95f));
MENU 55 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MENU 56 		Text->SetText(FText::FromString(Label));
MENU 57 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22));
MENU 58 		Button->AddChild(Text);
MENU 59 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Button);
MENU 60 		Slot->SetPadding(FMargin(0.f, 4.f, 0.f, 4.f));
MENU 61 		return Button;
MENU 62 	};
MENU 63 
MENU 64 	AddText(TEXT("VEIL"), 64);
MENU 65 	AddText(TEXT("THE LAST SIGNAL"), 24);
MENU 66 
MENU 67 	GodButton = AddButton(TEXT("GODMODE"));
MENU 68 	GodLabel = AddText(TEXT(""), 16);
MENU 69 	StartButton = AddButton(TEXT("Enter the Signal"));
MENU 70 	QualityButton = AddButton(TEXT("Graphics"));
MENU 71 	QualityLabel = AddText(TEXT(""), 16);
MENU 72 	QuitButton = AddButton(TEXT("Quit"));
MENU 73 
MENU 74 	StartButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnStartClicked);
MENU 75 	GodButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnGodClicked);
MENU 76 	QualityButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQualityClicked);
MENU 77 	QuitButton->OnClicked.AddDynamic(this, &UVEILMainMenu::OnQuitClicked);
MENU 78 
MENU 79 	StartButton->SetKeyboardFocus();
MENU 80 	RefreshQualityLabel();
MENU 81 	RefreshGodLabel();
MENU 82 }
MENU 83 
MENU 84 void UVEILMainMenu::RefreshGodLabel()
MENU 85 {
MENU 86 	bool bOn = false;
MENU 87 	if (APlayerController* PC = GetOwningPlayer())
MENU 88 	{
MENU 89 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
MENU 90 		{
MENU 91 			bOn = Runner->IsGodMode();
MENU 92 		}
MENU 93 	}
MENU 94 	if (GodLabel)
MENU 95 	{
MENU 96 		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
MENU 97 	}
MENU 98 }
MENU 99 
MENU 100 void UVEILMainMenu::OnGodClicked()
MENU 101 {
MENU 102 	if (APlayerController* PC = GetOwningPlayer())
MENU 103 	{
MENU 104 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
MENU 105 		{
MENU 106 			Runner->ToggleGodMode();
MENU 107 		}
MENU 108 	}
MENU 109 	RefreshGodLabel();
MENU 110 }
MENU 111 
MENU 112 void UVEILMainMenu::RefreshQualityLabel()
MENU 113 {
MENU 114 	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
MENU 115 	if (QualityLabel)
MENU 116 	{
MENU 117 		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
MENU 118 	}
MENU 119 }
MENU 120 
MENU 121 void UVEILMainMenu::OnStartClicked()
MENU 122 {
MENU 123 	if (APlayerController* PC = GetOwningPlayer())
MENU 124 	{
MENU 125 		PC->SetPause(false);
MENU 126 		PC->SetInputMode(FInputModeGameOnly());
MENU 127 		PC->bShowMouseCursor = false;
MENU 128 	}
MENU 129 	if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
MENU 130 	{
MENU 131 		GM->SetPhase(EVEILGamePhase::Exploration);
MENU 132 	}
MENU 133 	RemoveFromParent();
MENU 134 	UE_LOG(LogVEIL, Log, TEXT("Main menu: Enter the Signal."));
MENU 135 }
MENU 136 
MENU 137 void UVEILMainMenu::OnQualityClicked()
MENU 138 {
MENU 139 	QualityLevel = (QualityLevel + 1) % 4;
MENU 140 	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
MENU 141 	{
MENU 142 		Settings->SetOverallScalabilityLevel(QualityLevel);
MENU 143 		Settings->ApplySettings(false);
MENU 144 	}
MENU 145 	RefreshQualityLabel();
MENU 146 }
MENU 147 
MENU 148 void UVEILMainMenu::OnQuitClicked()
MENU 149 {
MENU 150 	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
MENU 151 }
INI BEFORE [ConsoleVariables]
INI VERIFY r.Streaming.PoolSize=2500
PYTHON=C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PATCHER GATE tickSig=1
PATCHER GATE notYet=1
PATCHER GATE ctxMembers=1
PATCHER TICK param=DeltaSeconds
PATCHER SPAN tick=318..461 open=319
PATCHER BRACE DELTA open=5 close=5
PATCHER PATCH OK padproof=1
EDITOR=CLOSED
BUILD Result: Failed (RulesError)
ERR Result: Failed (RulesError)
PHI GP488 VERDICT: PADPROOF patch=OK ini=2500 build=Result: Failed (RulesError)
JOB 488 DONE

```
