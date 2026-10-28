# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 16:40:33 UTC

## STEP 1
```
=== INPUT PAUSE GROUND READ 2 435 - THE ENHANCED INPUT ASSETS AND THE PAUSE FUNCTION READ AT THEIR OWN LINES (Ground read whole from job 432: the character binds Enhanced Input actions, Move, Look, Jump, Sprint, Dodge, Aim, Fire, Interact, each guarded by a null check, and adds a mapping context at BeginPlay; the legacy DefaultInput mappings count is zero, which Enhanced Input does not use, so the open question stands at the assets themselves: whether the InputAction and InputMappingContext assets stand in Content and whether the character properties carry them. Ground from job 431: the Start press lands on TogglePauseMenu, bound at VEILGameMode cpp line 223 to Gamepad_Special_Right, and the pause body at lines 228 to 245 creates the widget and flips the input mode; no SetGamePaused line stands anywhere in the pause print. One, the job prints the VEILCharacter header lines that name InputAction or MappingContext properties, capped at 40. Two, it prints VEILCharacter cpp lines 137 to 200 and 355 to 385 whole, the BeginPlay and mapping context ground and the possession ground. Three, it prints VEILGameMode cpp lines 180 to 250 whole: the player controller BeginPlay, its input setup, and the TogglePauseMenu body entire. Four, it prints VEILPauseMenu cpp whole, capped at 140 lines. Five, it censuses the Content tree for input assets: every uasset whose name carries IA or IMC or Input, with name and size, capped at 60. Six, the verdict in one line: INPUT PAUSE GROUND 2 with the property count and the asset count. This job is read only and every variable carries the ip435 prefix.) ===
PROP 13: class UInputMappingContext;
PROP 14: class UInputAction;
PROP 15: struct FInputActionValue;
PROP 115: TObjectPtr<UInputMappingContext> DefaultMappingContext;
PROP 118: TObjectPtr<UInputAction> MoveAction;
PROP 121: TObjectPtr<UInputAction> LookAction;
PROP 124: TObjectPtr<UInputAction> JumpAction;
PROP 127: TObjectPtr<UInputAction> SprintAction;
PROP 130: TObjectPtr<UInputAction> DodgeAction;
PROP 133: TObjectPtr<UInputAction> AimAction;
PROP 136: TObjectPtr<UInputAction> FireAction;
PROP 139: TObjectPtr<UInputAction> InteractAction;
PROP 142: void Move(const FInputActionValue& Value);
PROP 143: void Look(const FInputActionValue& Value);
PROP 159: TObjectPtr<UInputMappingContext> BuiltMappingContext;
PROP 162: TArray<TObjectPtr<UInputAction>> BuiltActions;
PROP LINES=16
--- CHARACTER 137-200 ---
CC 137: void AVEILCharacter::BeginPlay()
CC 138: {
CC 139: 	Super::BeginPlay();
CC 140:     {
CC 141:         UCapsuleComponent* Cap365 = GetCapsuleComponent();
CC 142:         USkeletalMeshComponent* Mesh365 = GetMesh();
CC 143:         UCharacterMovementComponent* Move365 = GetCharacterMovement();
CC 144:     }
CC 145: 	// The anim class is set in the constructor AND here: if the
CC 146: 	// component's initialization overwrote the constructor's
CC 147: 	// assignment, this one - after registration - is the one
CC 148: 	// that lives. The Tick one-shots report which state won.
CC 149: 	{
CC 150: 		if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
CC 151: 		{
CC 152: 			GetMesh()->PlayAnimation(PoseSeq, true);
CC 153: 		}
CC 154: 	}
CC 155: 	UE_LOG(LogVEIL, Log, TEXT("PHI BODY CHECK: mesh=%s anim=%s"),
CC 156: 		GetMesh()->GetSkeletalMeshAsset() ? *GetMesh()->GetSkeletalMeshAsset()->GetName() : TEXT("none"),
CC 157: 		GetMesh()->GetAnimInstance() ? *GetMesh()->GetAnimInstance()->GetClass()->GetName() : TEXT("none"));
CC 158: 	// PHI MOVE TEST v3 lives in Tick (tick-driven state machine -
CC 159: 	// timers never reported in the -game smokes, so the test rides
CC 160: 	// the frame itself).
CC 161: 	Health = MaxHealth;
CC 162: 	OnHealthChanged.Broadcast(Health, MaxHealth);
CC 163: 
CC 164: 	if (!DefaultMappingContext)
CC 165: 	{
CC 166: 		BuildFallbackInput();
CC 167: 	}
CC 168: 
CC 169: 	if (APlayerController* PC = Cast<APlayerController>(Controller))
CC 170: 	{
CC 171: 		if (UEnhancedInputLocalPlayerSubsystem* Sub =
CC 172: 			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
CC 173: 		{
CC 174: 			if (DefaultMappingContext)
CC 175: 			{
CC 176: 				Sub->AddMappingContext(DefaultMappingContext, 0);
CC 177: 			}
CC 178: 		}
CC 179: 	}
CC 180: }
CC 181: 
CC 182: void AVEILCharacter::BuildFallbackInput()
CC 183: {
CC 184: 	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
CC 185: 	// Used only when no editor-made Input assets are assigned.
CC 186: 	auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
CC 187: 	{
CC 188: 		UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
CC 189: 		Action->ValueType = Type;
CC 190: 		BuiltActions.Add(Action);
CC 191: 		return Action;
CC 192: 	};
CC 193: 
CC 194: 	MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
CC 195: 	LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
CC 196: 	JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
CC 197: 	SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
CC 198: 	DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
CC 199: 	AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
CC 200: 	FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
--- CHARACTER 355-385 ---
CC 355: 		else if (PhiC2Stage == 5)
CC 356: 		{
CC 357: 			PhiC2Line(TEXT("DROP2"), DeltaSeconds);
CC 358: 			if (++PhiC2Window >= 45) { PhiC2Stage = 6; }
CC 359: 		}
CC 360: 	}
CC 361: 
CC 362: 
CC 363: 
CC 364: 	++PhiTickEntryCount;
CC 365: 	// PHI MOVE TEST v3 - tick-driven, no timers. At t=5s of tick time it
CC 366: 	// names the possession state, drives synthetic forward input for
CC 367: 	// ~1.2s, then reports the velocity and displacement produced.
CC 368: 	{
CC 369: 		static int32 MovePhase = 0;
CC 370: 		static float MoveClock = 0.f;
CC 371: 		static FVector MoveSpawn = FVector::ZeroVector;
CC 372: 		MoveClock += DeltaSeconds;
CC 373: 		if (MovePhase == 0 && MoveClock >= 5.f)
CC 374: 		{
CC 375: 			MovePhase = 1;
CC 376: 			MoveSpawn = GetActorLocation();
CC 377: 			AController* C = GetController();
CC 378: 			UE_LOG(LogVEIL, Log, TEXT("PHI MOVE TEST BEGIN: controller=%s pawn=%s locallyControlled=%d paused=%d velBefore=%.1f loc=%s"),
CC 379: 				C ? *C->GetClass()->GetName() : TEXT("NONE"), *GetName(),
CC 380: 				IsLocallyControlled() ? 1 : 0, UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0,
CC 381: 				GetVelocity().Size(), *GetActorLocation().ToString());
CC 382: 		}
CC 383: 		else if (MovePhase == 1)
CC 384: 		{
CC 385: 			AddMovementInput(GetActorForwardVector(), 1.0f);
--- GAMEMODE 180-250 ---
GM 180: 	MainMenuWidgetClass = UVEILMainMenu::StaticClass();
GM 181: 	PauseWidgetClass = UVEILPauseMenu::StaticClass();
GM 182: }
GM 183: 
GM 184: static FTimerHandle GPhiTimerHandle;
GM 185: 
GM 186: void AVEILPlayerController::BeginPlay()
GM 187: {
GM 188: 	Super::BeginPlay();
GM 189: 	// Timer cross-check: a 3-second one-shot on the world's own timer
GM 190: 	// manager. If world time advances, PhiOnTimerCheck fires and logs
GM 191: 	// it; if the clock stands frozen, the TICKPROOF shows it pending.
GM 192: 	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);
GM 193: 
GM 194: 	if (HUDWidgetClass && IsLocalController())
GM 195: 	{
GM 196: 		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
GM 197: 		if (HUDWidget) HUDWidget->AddToViewport(0);
GM 198: 	}
GM 199: 
GM 200: 	if (MainMenuWidgetClass && IsLocalController())
GM 201: 	{
GM 202: 		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
GM 203: 		if (MainMenuWidget)
GM 204: 		{
GM 205: 			MainMenuWidget->AddToViewport(20);
GM 206: 			SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
GM 207: 			SetInputMode(FInputModeGameAndUI());
GM 208: 			bShowMouseCursor = true;
GM 209: 			return;
GM 210: 		}
GM 211: 	}
GM 212: 	SetInputMode(FInputModeGameOnly());
GM 213: 	bShowMouseCursor = false;
GM 214: }
GM 215: 
GM 216: void AVEILPlayerController::SetupInputComponent()
GM 217: {
GM 218: 	Super::SetupInputComponent();
GM 219: 	if (InputComponent)
GM 220: 	{
GM 221: 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 222: 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 223: 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 224: 	}
GM 225: }
GM 226: 
GM 227: void AVEILPlayerController::TogglePauseMenu()
GM 228: {
GM 229: 	bPauseOpen = !bPauseOpen;
GM 230: 	SetPause(bPauseOpen);
GM 231: 
GM 232: 	if (bPauseOpen)
GM 233: 	{
GM 234: 		if (PauseWidgetClass && !PauseWidget)
GM 235: 		{
GM 236: 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
GM 237: 		}
GM 238: 		if (PauseWidget) PauseWidget->AddToViewport(10);
GM 239: 		SetInputMode(FInputModeGameAndUI());
GM 240: 		bShowMouseCursor = true;
GM 241: 	}
GM 242: 	else
GM 243: 	{
GM 244: 		if (PauseWidget) PauseWidget->RemoveFromParent();
GM 245: 		SetInputMode(FInputModeGameOnly());
GM 246: 		bShowMouseCursor = false;
GM 247: 	}
GM 248: }
GM 249: 
GM 250: void AVEILGameMode::Tick(float DeltaSeconds)
--- PAUSE MENU CPP lines=148 ---
PM // VEIL: THE LAST SIGNAL - pause menu implementation.
PM #include "Game/VEILPauseMenu.h"
PM 
PM #include "Blueprint/WidgetTree.h"
PM #include "Components/Button.h"
PM #include "Components/CanvasPanel.h"
PM #include "Components/CanvasPanelSlot.h"
PM #include "Components/TextBlock.h"
PM #include "Components/VerticalBox.h"
PM #include "Components/VerticalBoxSlot.h"
PM #include "Game/VEILGameMode.h"
PM #include "Character/VEILCharacter.h"
PM #include "GameFramework/Pawn.h"
PM #include "GameFramework/GameUserSettings.h"
PM #include "Kismet/GameplayStatics.h"
PM #include "Kismet/KismetSystemLibrary.h"
PM #include "VEIL.h"
PM 
PM void UVEILPauseMenu::NativeConstruct()
PM {
PM 	Super::NativeConstruct();
PM 
PM 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
PM 	WidgetTree->RootWidget = Canvas;
PM 
PM 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
PM 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
PM 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
PM 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
PM 	BoxSlot->SetAutoSize(true);
PM 
PM 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
PM 	{
PM 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
PM 		Text->SetText(FText::FromString(Content));
PM 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
PM 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
PM 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
PM 		Slot->SetHorizontalAlignment(HAlign_Center);
PM 		return Text;
PM 	};
PM 
PM 	auto AddButton = [this, Box](const FString& Label) -> UButton*
PM 	{
PM 		UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
PM 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
PM 		Text->SetText(FText::FromString(Label));
PM 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22));
PM 		Button->AddChild(Text);
PM 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Button);
PM 		Slot->SetPadding(FMargin(0.f, 4.f, 0.f, 4.f));
PM 		return Button;
PM 	};
PM 
PM 	AddText(TEXT("PAUSED"), 40);
PM 	AddText(TEXT("THE LAST SIGNAL HOLDS"), 16);
PM 
PM 	GodButton = AddButton(TEXT("GODMODE"));
PM 	GodLabel = AddText(TEXT(""), 16);
PM 	ResumeButton = AddButton(TEXT("Resume"));
PM 	QualityButton = AddButton(TEXT("Graphics"));
PM 	QualityLabel = AddText(TEXT(""), 16);
PM 	TitleButton = AddButton(TEXT("Quit to Title"));
PM 	QuitButton = AddButton(TEXT("Quit Game"));
PM 
PM 	ResumeButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnResumeClicked);
PM 	GodButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnGodClicked);
PM 	QualityButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQualityClicked);
PM 	TitleButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnTitleClicked);
PM 	QuitButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQuitClicked);
PM 
PM 	ResumeButton->SetKeyboardFocus();
PM 	RefreshQualityLabel();
PM 	RefreshGodLabel();
PM }
PM 
PM void UVEILPauseMenu::RefreshGodLabel()
PM {
PM 	bool bOn = false;
PM 	if (APlayerController* PC = GetOwningPlayer())
PM 	{
PM 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
PM 		{
PM 			bOn = Runner->IsGodMode();
PM 		}
PM 	}
PM 	if (GodLabel)
PM 	{
PM 		GodLabel->SetText(FText::FromString(bOn ? TEXT("GODMODE: ON") : TEXT("GODMODE: OFF")));
PM 	}
PM }
PM 
PM void UVEILPauseMenu::OnGodClicked()
PM {
PM 	if (APlayerController* PC = GetOwningPlayer())
PM 	{
PM 		if (AVEILCharacter* Runner = Cast<AVEILCharacter>(PC->GetPawn()))
PM 		{
PM 			Runner->ToggleGodMode();
PM 		}
PM 	}
PM 	RefreshGodLabel();
PM }
PM 
PM void UVEILPauseMenu::RefreshQualityLabel()
PM {
PM 	static const TCHAR* Names[] = { TEXT("Low"), TEXT("Medium"), TEXT("High"), TEXT("Epic") };
PM 	if (QualityLabel)
PM 	{
PM 		QualityLabel->SetText(FText::FromString(FString::Printf(TEXT("Graphics: %s"), Names[QualityLevel])));
PM 	}
PM }
PM 
PM void UVEILPauseMenu::OnResumeClicked()
PM {
PM 	if (AVEILPlayerController* PC = Cast<AVEILPlayerController>(GetOwningPlayer()))
PM 	{
PM 		PC->TogglePauseMenu();
PM 	}
PM }
PM 
PM void UVEILPauseMenu::OnQualityClicked()
PM {
PM 	QualityLevel = (QualityLevel + 1) % 4;
PM 	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
PM 	{
PM 		Settings->SetOverallScalabilityLevel(QualityLevel);
PM 		Settings->ApplySettings(false);
PM 	}
PM 	RefreshQualityLabel();
PM }
PM 
PM void UVEILPauseMenu::OnTitleClicked()
PM {
PM 	// Back to the title: reload the level; boot state is the main menu
PM 	// over a paused world, so the game lands on its title screen.
PM 	if (APlayerController* PC = GetOwningPlayer())
PM 	{
PM 		PC->SetPause(false);
PM 	}
INPUT ASSETS=5
ASSET IA_Jump.uasset bytes=1418 dir=Actions
ASSET IA_Look.uasset bytes=1565 dir=Actions
ASSET IA_Menu.uasset bytes=1418 dir=Actions
ASSET IA_Move.uasset bytes=1565 dir=Actions
ASSET IMC_Default.uasset bytes=14647 dir=Input
PHI IP435 VERDICT: INPUT PAUSE GROUND 2 props=16 assets=5
JOB 435 DONE

```
