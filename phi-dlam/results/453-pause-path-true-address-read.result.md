# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 18:27:56 UTC

## STEP 1
```
=== PAUSE PATH TRUE ADDRESS READ 453 - THE START PRESS NAMED AT THE REAL SOURCE ADDRESS (Ground: job 451 censused the source tree whole and the mystery of the empty reads closed: the game source lives in the Unreal module layout, Private and Public category folders under Source VEIL, and jobs 447 and 448 probed the flat module folder where no cpp stands. The true addresses: Private Game VEILGameMode cpp at 12791 bytes, Private Game VEILPauseMenu cpp, Private Game VEILMainMenu cpp, Private World VEILWorldBuilder cpp. The question stands from Tyree hands: the controller works and pressing Start ends the game on screen, while the record holds only a clean exit and no fatal line. This job re-runs the pause read at the true address. One, it prints TogglePauseMenu whole from VEILGameMode cpp, signature to closing brace, capped at 80 lines. Two, it prints every QuitGame, RequestExit and ExitGame line across the Private tree with file and line, capped at 20. Three, it prints the first 22 lines of NativeConstruct in both menu cpps. Four, it prints every Special Right, MenuAction and PauseMenu binding line across the Private tree, capped at 25. The verdict in one line: PAUSE PATH READ with the quit count and the binding count. This job is read only and every variable carries the pp453 prefix.) ===
GM EXISTS=True
TPM 221 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
TPM 222 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
TPM 223 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
TPM 224 	}
TPM 225 }
TPM 226 
TPM 227 void AVEILPlayerController::TogglePauseMenu()
TPM 228 {
TPM 229 	bPauseOpen = !bPauseOpen;
TPM 230 	SetPause(bPauseOpen);
TPM 231 
TPM 232 	if (bPauseOpen)
TPM 233 	{
TPM 234 		if (PauseWidgetClass && !PauseWidget)
TPM 235 		{
TPM 236 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
TPM 237 		}
TPM 238 		if (PauseWidget) PauseWidget->AddToViewport(10);
TPM 239 		SetInputMode(FInputModeGameAndUI());
TPM 240 		bShowMouseCursor = true;
TPM 241 	}
TPM 242 	else
TPM 243 	{
TPM 244 		if (PauseWidget) PauseWidget->RemoveFromParent();
TPM 245 		SetInputMode(FInputModeGameOnly());
TPM 246 		bShowMouseCursor = false;
TPM 247 	}
TPM 248 }
TPM 249 
TPM 250 void AVEILGameMode::Tick(float DeltaSeconds)
TPM 251 {
TPM 252 	Super::Tick(DeltaSeconds);
TPM 253 	static float GmProofClock = 0.f;
TPM 254 	GmProofClock += DeltaSeconds;
TPM 255 	if (GmProofClock >= 5.f)
TPM 256 	{
TPM 257 		GmProofClock = 0.f;
TPM 258 		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
TPM 259 			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
TPM 260 	}
TPM 261 }
TPM 262 
TPM 263 void AVEILPlayerController::Tick(float DeltaSeconds)
TPM 264 {
TPM 265 	Super::Tick(DeltaSeconds);
TPM 266 	static float PcProofClock = 0.f;
TPM 267 	PcProofClock += DeltaSeconds;
TPM 268 	if (PcProofClock >= 5.f)
TPM 269 	{
TPM 270 		PcProofClock = 0.f;
TPM 271 		AVEILCharacter* PhiPawn = Cast<AVEILCharacter>(GetPawn());
TPM 272 		static float PhiDiagClock = 0.f;
TPM 273 		PhiDiagClock += DeltaSeconds;
TPM 274 		if (PhiDiagClock >= 0.f && PhiDiagClock < 1000.f)
TPM 275 		{
TPM 276 			PhiDiagClock = 500.f;
TPM 277 			if (ACharacter* DiagPawn = Cast<ACharacter>(GetPawn()))
TPM 278 			{
TPM 279 				UCapsuleComponent* Cap = DiagPawn->GetCapsuleComponent();
TPM 280 				UCharacterMovementComponent* CMove = DiagPawn->GetCharacterMovement();
TPM 281 				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR DIAG: world=%s capEnabled=%d capProfile=%s moveMode=%d onGround=%d floorBlock=%d floorActor=%s"),
TPM 282 					*GetWorld()->GetName(),
TPM 283 					Cap ? (int32)Cap->GetCollisionEnabled() : -1,
TPM 284 					Cap ? *Cap->GetCollisionProfileName().ToString() : TEXT("none"),
TPM 285 					CMove ? (int32)CMove->MovementMode : -1, (CMove && CMove->IsMovingOnGround()) ? 1 : 0,
TPM 286 					(CMove && CMove->CurrentFloor.bBlockingHit) ? 1 : 0,
TPM 287 					(CMove && CMove->CurrentFloor.HitResult.GetActor()) ? *CMove->CurrentFloor.HitResult.GetActor()->GetName() : TEXT("none"));
TPM 288 				const FVector PawnLoc = DiagPawn->GetActorLocation();
TPM 289 				FHitResult TraceHit;
TPM 290 				const FVector TraceStart(PawnLoc.X, PawnLoc.Y, 500.f);
TPM 291 				const FVector TraceEnd(PawnLoc.X, PawnLoc.Y, -500.f);
TPM 292 				const bool bTrace = GetWorld()->LineTraceSingleByChannel(TraceHit, TraceStart, TraceEnd, ECC_WorldStatic);
TPM 293 				UE_LOG(LogTemp, Display, TEXT("PHI FLOOR TRACE: hit=%d actor=%s hitZ=%.1f pawnZ=%.1f"),
TPM 294 					bTrace ? 1 : 0, TraceHit.GetActor() ? *TraceHit.GetActor()->GetName() : TEXT("none"),
TPM 295 					TraceHit.Location.Z, PawnLoc.Z);
TPM 296 				int32 Printed = 0;
TPM 297 				for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
TPM 298 				{
TPM 299 					FVector Origin; FVector Extent;
TPM 300 					It->GetActorBounds(false, Origin, Extent);
QUIT VEILMainMenu.cpp:143 UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
QUIT VEILPauseMenu.cpp:147 UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
MENU VEILPauseMenu.cpp 19 void UVEILPauseMenu::NativeConstruct()
MENU VEILPauseMenu.cpp 20 {
MENU VEILPauseMenu.cpp 21 	Super::NativeConstruct();
MENU VEILPauseMenu.cpp 22 
MENU VEILPauseMenu.cpp 23 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
MENU VEILPauseMenu.cpp 24 	WidgetTree->RootWidget = Canvas;
MENU VEILPauseMenu.cpp 25 
MENU VEILPauseMenu.cpp 26 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
MENU VEILPauseMenu.cpp 27 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
MENU VEILPauseMenu.cpp 28 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
MENU VEILPauseMenu.cpp 29 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
MENU VEILPauseMenu.cpp 30 	BoxSlot->SetAutoSize(true);
MENU VEILPauseMenu.cpp 31 
MENU VEILPauseMenu.cpp 32 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
MENU VEILPauseMenu.cpp 33 	{
MENU VEILPauseMenu.cpp 34 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MENU VEILPauseMenu.cpp 35 		Text->SetText(FText::FromString(Content));
MENU VEILPauseMenu.cpp 36 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
MENU VEILPauseMenu.cpp 37 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
MENU VEILPauseMenu.cpp 38 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
MENU VEILPauseMenu.cpp 39 		Slot->SetHorizontalAlignment(HAlign_Center);
MENU VEILPauseMenu.cpp 40 		return Text;
MENU VEILMainMenu.cpp 20 void UVEILMainMenu::NativeConstruct()
MENU VEILMainMenu.cpp 21 {
MENU VEILMainMenu.cpp 22 	Super::NativeConstruct();
MENU VEILMainMenu.cpp 23 
MENU VEILMainMenu.cpp 24 	// Build the whole layout in code so the menu exists with zero assets.
MENU VEILMainMenu.cpp 25 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
MENU VEILMainMenu.cpp 26 	WidgetTree->RootWidget = Canvas;
MENU VEILMainMenu.cpp 27 
MENU VEILMainMenu.cpp 28 	UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("MenuBox"));
MENU VEILMainMenu.cpp 29 	UCanvasPanelSlot* BoxSlot = Canvas->AddChildToCanvas(Box);
MENU VEILMainMenu.cpp 30 	BoxSlot->SetAnchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f));
MENU VEILMainMenu.cpp 31 	BoxSlot->SetAlignment(FVector2D(0.5f, 0.5f));
MENU VEILMainMenu.cpp 32 	BoxSlot->SetAutoSize(true);
MENU VEILMainMenu.cpp 33 
MENU VEILMainMenu.cpp 34 	auto AddText = [this, Box](const FString& Content, int32 Size) -> UTextBlock*
MENU VEILMainMenu.cpp 35 	{
MENU VEILMainMenu.cpp 36 		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
MENU VEILMainMenu.cpp 37 		Text->SetText(FText::FromString(Content));
MENU VEILMainMenu.cpp 38 		Text->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), Size));
MENU VEILMainMenu.cpp 39 		UVerticalBoxSlot* Slot = Box->AddChildToVerticalBox(Text);
MENU VEILMainMenu.cpp 40 		Slot->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
MENU VEILMainMenu.cpp 41 		Slot->SetHorizontalAlignment(HAlign_Center);
BIND VEILGameMode.cpp:15 #include "Game/VEILPauseMenu.h"
BIND VEILGameMode.cpp:181 PauseWidgetClass = UVEILPauseMenu::StaticClass();
BIND VEILGameMode.cpp:221 InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILGameMode.cpp:222 InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILGameMode.cpp:223 InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILGameMode.cpp:227 void AVEILPlayerController::TogglePauseMenu()
BIND VEILPauseMenu.cpp:2 #include "Game/VEILPauseMenu.h"
BIND VEILPauseMenu.cpp:19 void UVEILPauseMenu::NativeConstruct()
BIND VEILPauseMenu.cpp:66 ResumeButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnResumeClicked);
BIND VEILPauseMenu.cpp:67 GodButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnGodClicked);
BIND VEILPauseMenu.cpp:68 QualityButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQualityClicked);
BIND VEILPauseMenu.cpp:69 TitleButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnTitleClicked);
BIND VEILPauseMenu.cpp:70 QuitButton->OnClicked.AddDynamic(this, &UVEILPauseMenu::OnQuitClicked);
BIND VEILPauseMenu.cpp:77 void UVEILPauseMenu::RefreshGodLabel()
BIND VEILPauseMenu.cpp:93 void UVEILPauseMenu::OnGodClicked()
BIND VEILPauseMenu.cpp:105 void UVEILPauseMenu::RefreshQualityLabel()
BIND VEILPauseMenu.cpp:114 void UVEILPauseMenu::OnResumeClicked()
BIND VEILPauseMenu.cpp:118 PC->TogglePauseMenu();
BIND VEILPauseMenu.cpp:122 void UVEILPauseMenu::OnQualityClicked()
BIND VEILPauseMenu.cpp:133 void UVEILPauseMenu::OnTitleClicked()
BIND VEILPauseMenu.cpp:145 void UVEILPauseMenu::OnQuitClicked()
PHI PP453 VERDICT: PAUSE PATH READ quits=2 binds=21
JOB 453 DONE

```
