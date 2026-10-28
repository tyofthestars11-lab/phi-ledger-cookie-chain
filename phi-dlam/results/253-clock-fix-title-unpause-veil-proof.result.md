# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:43:27 UTC

## STEP 1
```
=== Job 250 NAMED THE GATE. Engine source (LevelTick.cpp): TimeSeconds advances only inside if ( !bIsPaused ), the TimerManager ticks only under !bIsPaused, and actor ticks ride the same gate. Own-code sweep: the ONLY SetPause(true) in either module is the TITLE - VEILGameMode.cpp:173 / OMNIGameMode.cpp:197, SetPause(true) with the comment "the title is a real title: the world waits behind it". The title pauses the world and the measured runs never lift it: worldTime 0.00 forever, pawnTickEntries 0, timerRemaining frozen at 3.00 - in PIE and in the standalone package alike - while the GAMEMODE ALIVE print read its own view of pause, not the world gate flag. THE FIX, smallest change answering the evidence: the title becomes an overlay on a LIVING world - SetPause(true) at the title line becomes SetPause(false). The pause menu keeps its own pause flow untouched. Backup first, exact-line match required (abort the edit if the count is not exactly 1 per file), then build VEIL and prove the clock in -game: TICKPROOF must show worldTime ADVANCING and pawnTickEntries > 0. A marker file records the verdict for job 254. ===
===== region 150-235: D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp =====
150: 
151: static FTimerHandle GPhiTimerHandle;
152: 
153: void AVEILPlayerController::BeginPlay()
154: {
155: 	Super::BeginPlay();
156: 	// Timer cross-check: a 3-second one-shot on the world's own timer
157: 	// manager. If world time advances, PhiOnTimerCheck fires and logs
158: 	// it; if the clock stands frozen, the TICKPROOF shows it pending.
159: 	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);
160: 
161: 	if (HUDWidgetClass && IsLocalController())
162: 	{
163: 		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
164: 		if (HUDWidget) HUDWidget->AddToViewport(0);
165: 	}
166: 
167: 	if (MainMenuWidgetClass && IsLocalController())
168: 	{
169: 		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
170: 		if (MainMenuWidget)
171: 		{
172: 			MainMenuWidget->AddToViewport(20);
173: 			SetPause(true); // the title is a real title: the world waits behind it
174: 			SetInputMode(FInputModeGameAndUI());
175: 			bShowMouseCursor = true;
176: 			return;
177: 		}
178: 	}
179: 	SetInputMode(FInputModeGameOnly());
180: 	bShowMouseCursor = false;
181: }
182: 
183: void AVEILPlayerController::SetupInputComponent()
184: {
185: 	Super::SetupInputComponent();
186: 	if (InputComponent)
187: 	{
188: 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
189: 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
190: 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
191: 	}
192: }
193: 
194: void AVEILPlayerController::TogglePauseMenu()
195: {
196: 	bPauseOpen = !bPauseOpen;
197: 	SetPause(bPauseOpen);
198: 
199: 	if (bPauseOpen)
200: 	{
201: 		if (PauseWidgetClass && !PauseWidget)
202: 		{
203: 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
204: 		}
205: 		if (PauseWidget) PauseWidget->AddToViewport(10);
206: 		SetInputMode(FInputModeGameAndUI());
207: 		bShowMouseCursor = true;
208: 	}
209: 	else
210: 	{
211: 		if (PauseWidget) PauseWidget->RemoveFromParent();
212: 		SetInputMode(FInputModeGameOnly());
213: 		bShowMouseCursor = false;
214: 	}
215: }
216: 
217: void AVEILGameMode::Tick(float DeltaSeconds)
218: {
219: 	Super::Tick(DeltaSeconds);
220: 	static float GmProofClock = 0.f;
221: 	GmProofClock += DeltaSeconds;
222: 	if (GmProofClock >= 5.f)
223: 	{
224: 		GmProofClock = 0.f;
225: 		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
226: 			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
227: 	}
228: }
229: 
230: void AVEILPlayerController::Tick(float DeltaSeconds)
231: {
232: 	Super::Tick(DeltaSeconds);
233: 	static float PcProofClock = 0.f;
234: 	PcProofClock += DeltaSeconds;
235: 	if (PcProofClock >= 5.f)
===== region 150-235: D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp =====
150: }
151: 
152: void AOMNIGameMode::SetPhase(EOMNIGamePhase NewPhase)
153: {
154: 	if (NewPhase == Phase) return;
155: 	Phase = NewPhase;
156: 	OnPhaseChanged.Broadcast(Phase);
157: }
158: 
159: void AOMNIGameMode::HandleMysterySolved(FName MysteryId)
160: {
161: 	UE_LOG(LogOMNI, Log, TEXT("Mystery solved (%s) - phase: Resolution"), *MysteryId.ToString());
162: 	SetPhase(EOMNIGamePhase::Resolution);
163: }
164: 
165: // ---------------------------------------------------------------------------
166: // Player Controller
167: // ---------------------------------------------------------------------------
168: AOMNIPlayerController::AOMNIPlayerController()
169: {
170: 	// The C++ main menu is the default: a working menu with zero assets.
171: 	MainMenuWidgetClass = UOMNIMainMenu::StaticClass();
172: 	PauseWidgetClass = UOMNIPauseMenu::StaticClass();
173: }
174: 
175: static FTimerHandle GPhiTimerHandle;
176: 
177: void AOMNIPlayerController::BeginPlay()
178: {
179: 	Super::BeginPlay();
180: 	// Timer cross-check: a 3-second one-shot on the world's own timer
181: 	// manager. If world time advances, PhiOnTimerCheck fires and logs
182: 	// it; if the clock stands frozen, the TICKPROOF shows it pending.
183: 	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AOMNIPlayerController::PhiOnTimerCheck, 3.0f, false);
184: 
185: 	if (HUDWidgetClass && IsLocalController())
186: 	{
187: 		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
188: 		if (HUDWidget) HUDWidget->AddToViewport(0);
189: 	}
190: 
191: 	if (MainMenuWidgetClass && IsLocalController())
192: 	{
193: 		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
194: 		if (MainMenuWidget)
195: 		{
196: 			MainMenuWidget->AddToViewport(20);
197: 			SetPause(true); // the title is a real title: the world waits behind it
198: 			SetInputMode(FInputModeGameAndUI());
199: 			bShowMouseCursor = true;
200: 			return;
201: 		}
202: 	}
203: 	SetInputMode(FInputModeGameOnly());
204: 	bShowMouseCursor = false;
205: }
206: 
207: void AOMNIPlayerController::SetupInputComponent()
208: {
209: 	Super::SetupInputComponent();
210: 	if (InputComponent)
211: 	{
212: 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
213: 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
214: 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
215: 	}
216: }
217: 
218: void AOMNIPlayerController::TogglePauseMenu()
219: {
220: 	bPauseOpen = !bPauseOpen;
221: 	SetPause(bPauseOpen);
222: 
223: 	if (bPauseOpen)
224: 	{
225: 		if (PauseWidgetClass && !PauseWidget)
226: 		{
227: 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
228: 		}
229: 		if (PauseWidget) PauseWidget->AddToViewport(10);
230: 		SetInputMode(FInputModeGameAndUI());
231: 		bShowMouseCursor = true;
232: 	}
233: 	else
234: 	{
235: 		if (PauseWidget) PauseWidget->RemoveFromParent();
title-pause matches in D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp : 1
EDITED: D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp
title-pause matches in D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp : 1
EDITED: D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp
===== verify: no title SetPause(true) remains =====
Total time in Unreal Build Accelerator local executor: 23.11 seconds
[2026.10.28-00.44.28:999][490]LogVEIL: PHI TICKPROOF: frames=2490 worldTime=20.0 paused=0
[2026.10.28-00.44.34:001][187]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=25.02 worldDelta=0.0064 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_0 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=3186 timerActive=0 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=-1.00
[2026.10.28-00.44.34:001][187]LogTemp: Display: PHI GM TICKPROOF: worldTime=25.0 paused=0
[2026.10.28-00.44.34:001][187]LogVEIL: PHI TICKPROOF: frames=3187 worldTime=25.0 paused=0
CLOCKFIX VEIL: samplesWithTimeAdvanced=4 samplesWithPawnTicks=1
CLOCK FIX VEIL PROOF DONE

```
