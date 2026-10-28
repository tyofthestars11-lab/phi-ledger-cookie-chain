# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 08:13:44 UTC

## STEP 1
```
=== CONTROLLER FREEZE CENSUS 366 - THE PAD FREEZE RIDES THE SAME REPAIR PASS (Tyree names a new symptom from his own hands on the merged build: using a controller freezes it. Floor first - job 365 carries the fall - and this census rides the same pass, because a build that stands and then freezes on the pad is not playable. The lane already holds one measured freeze shape in this codebase, read on 2026-10-27: the PlayerController lives inside VEILGameMode.cpp, its TogglePauseMenu answers Esc, P and Gamepad_Special_Right, and at that read PauseWidgetClass stood never assigned in either parent - SetPause true plus a mouse cursor with no visible menu is a freeze in every way a player can name, and his words then were that he could not exit that menu either. Whether that mechanism stands armed in the merged base is a source fact, readable in one pass. THIS JOB, merged base at D VEIL-OMNI only, read-only except two short game runs: one, the pause truth - every PauseWidgetClass, HUDWidgetClass, TogglePauseMenu, SetPause and Gamepad line in the GameMode source, plus the TogglePauseMenu and SetupInputComponent bodies printed whole. Two, the character input truth - the SetupPlayerInputComponent and BuildFallbackInput bodies printed whole, and every Gamepad, EnhancedInput and MappingContext line in Source. Three, the config truth - DefaultInput.ini whole where it stands, and the input lines of DefaultEngine.ini. Four, the device truth - Plug and Play status for the pad and Bluetooth devices on the PC, because job 071 proved his third-party Bluetooth Xbox pad paired and ready. Five, log archaeology - the newest three game logs, their pad and pause lines, and the tail of the newest log, where a hard freeze cuts the record mid-motion. Six, two game runs on VEILDistrict, plain and with the NoXInput switch, 40 seconds each, printing the PHI truth line count and the log tail for each - the runs carry no pad press, so they read the launch-side half only, and the job prints that limit in its own voice. No source is edited in this job: the fix for whatever stands armed is written from these prints and rides with the fall fix.) ===
--- SECTION 1: PAUSE TRUTH ---
GAMEMODE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp bytes=12791
GM 14: #include "Game/VEILMainMenu.h"
GM 30: PlayerControllerClass = AVEILPlayerController::StaticClass();
GM 177: AVEILPlayerController::AVEILPlayerController()
GM 180: MainMenuWidgetClass = UVEILMainMenu::StaticClass();
GM 181: PauseWidgetClass = UVEILPauseMenu::StaticClass();
GM 186: void AVEILPlayerController::BeginPlay()
GM 192: GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);
GM 194: if (HUDWidgetClass && IsLocalController())
GM 196: HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
GM 200: if (MainMenuWidgetClass && IsLocalController())
GM 202: MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
GM 203: if (MainMenuWidget)
GM 205: MainMenuWidget->AddToViewport(20);
GM 206: SetPause(false); // PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike
GM 216: void AVEILPlayerController::SetupInputComponent()
GM 221: InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 222: InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 223: InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
GM 227: void AVEILPlayerController::TogglePauseMenu()
GM 230: SetPause(bPauseOpen);
GM 234: if (PauseWidgetClass && !PauseWidget)
GM 236: PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
GM 263: void AVEILPlayerController::Tick(float DeltaSeconds)
GM 329: void AVEILPlayerController::PhiOnTimerCheck()
--- FUNCTION ::TogglePauseMenu at line 221 ---
221: 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
222: 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
223: 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
224: 	}
225: }
226: 
227: void AVEILPlayerController::TogglePauseMenu()
228: {
229: 	bPauseOpen = !bPauseOpen;
230: 	SetPause(bPauseOpen);
231: 
232: 	if (bPauseOpen)
233: 	{
234: 		if (PauseWidgetClass && !PauseWidget)
235: 		{
236: 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
237: 		}
238: 		if (PauseWidget) PauseWidget->AddToViewport(10);
239: 		SetInputMode(FInputModeGameAndUI());
240: 		bShowMouseCursor = true;
241: 	}
242: 	else
243: 	{
244: 		if (PauseWidget) PauseWidget->RemoveFromParent();
245: 		SetInputMode(FInputModeGameOnly());
246: 		bShowMouseCursor = false;
247: 	}
248: }
249: 
250: void AVEILGameMode::Tick(float DeltaSeconds)
251: {
252: 	Super::Tick(DeltaSeconds);
253: 	static float GmProofClock = 0.f;
254: 	GmProofClock += DeltaSeconds;
255: 	if (GmProofClock >= 5.f)
256: 	{
257: 		GmProofClock = 0.f;
258: 		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
259: 			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
260: 	}
261: }
262: 
263: void AVEILPlayerController::Tick(float DeltaSeconds)
264: {
265: 	Super::Tick(DeltaSeconds);
--- FUNCTION ::SetupInputComponent at line 216 ---
216: void AVEILPlayerController::SetupInputComponent()
217: {
218: 	Super::SetupInputComponent();
219: 	if (InputComponent)
220: 	{
221: 		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
222: 		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
223: 		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
224: 	}
225: }
226: 
227: void AVEILPlayerController::TogglePauseMenu()
228: {
229: 	bPauseOpen = !bPauseOpen;
230: 	SetPause(bPauseOpen);
231: 
232: 	if (bPauseOpen)
233: 	{
234: 		if (PauseWidgetClass && !PauseWidget)
235: 		{
236: 			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
237: 		}
238: 		if (PauseWidget) PauseWidget->AddToViewport(10);
239: 		SetInputMode(FInputModeGameAndUI());
240: 		bShowMouseCursor = true;
241: 	}
242: 	else
243: 	{
244: 		if (PauseWidget) PauseWidget->RemoveFromParent();
245: 		SetInputMode(FInputModeGameOnly());
246: 		bShowMouseCursor = false;
247: 	}
248: }
249: 
250: void AVEILGameMode::Tick(float DeltaSeconds)
251: {
252: 	Super::Tick(DeltaSeconds);
253: 	static float GmProofClock = 0.f;
254: 	GmProofClock += DeltaSeconds;
255: 	if (GmProofClock >= 5.f)
256: 	{
257: 		GmProofClock = 0.f;
258: 		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
259: 			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
260: 	}
--- SECTION 2: CHARACTER INPUT TRUTH ---
--- FUNCTION ::SetupPlayerInputComponent at line 251 ---
251: void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
252: {
253: 	Super::SetupPlayerInputComponent(PlayerInputComponent);
254: 
255: 	// 1st/3rd person toggle: V on keyboard, right-stick click (R3) on the pad.
256: 	PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
257: 	PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
258: 
259: 	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
260: 	{
261: 		if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
262: 		if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
263: 		if (JumpAction)
264: 		{
265: 			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
266: 			EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
267: 		}
268: 		if (SprintAction)
269: 		{
270: 			EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
271: 			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
272: 		}
273: 		if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
274: 		if (AimAction)
275: 		{
276: 			EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
277: 			EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
278: 		}
279: 		if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
280: 		if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
281: 	}
282: }
283: 
284: void AVEILCharacter::Tick(float DeltaSeconds)
285: {
286: 	Super::Tick(DeltaSeconds);
287:     // PHI TICK TRUTH 365 - mesh versus capsule divergence read
288:     {
289:         static int32 PhiTick365 = 0;
290:         PhiTick365++;
291:         if (PhiTick365 == 5 || PhiTick365 == 30 || PhiTick365 == 60 || PhiTick365 == 120)
292:         {
293:             const FVector CapW365 = GetCapsuleComponent()->GetComponentLocation();
294:             const FVector MeshW365 = GetMesh()->GetComponentLocation();
295:             const FRotator MeshR365 = GetMesh()->GetComponentRotation();
296:             const FFindFloorResult& Fl365 = GetCharacterMovement()->CurrentFloor;
297:             UE_LOG(LogTemp, Warning, TEXT("PHI TICK TRUTH name=%s tick=%d capZ=%.1f meshZ=%.1f delta=%.1f meshPitch=%.1f meshRoll=%.1f meshSim=%d moveMode=%d floorBlock=%d floorActor=%s"), *GetName(), PhiTick365, CapW365.Z, MeshW365.Z, (MeshW365 - CapW365).Size(), MeshR365.Pitch, MeshR365.Roll, GetMesh()->IsSimulatingPhysics() ? 1 : 0, (int32)GetCharacterMovement()->MovementMode, Fl365.bBlockingHit ? 1 : 0, Fl365.HitResult.GetActor() ? *Fl365.HitResult.GetActor()->GetName() : TEXT("none"));
298:         }
299:     }
300: 	// PHI CROSSING SAMPLER V2 (jobs 341/342): per-tick shape of the displacement from spawn, a column census at both redrop points, and a redrop onto the PHI_GROUND slab column whose top is z=0.
301: 	{
302: 		static float PhiC2Clock = 0.f;
303: 		static int32 PhiC2Tick = 0;
304: 		static int32 PhiC2Stage = 0;
305: 		static int32 PhiC2Window = 0;
306: 		static FVector PhiC2Spawn = FVector::ZeroVector;
307: 		PhiC2Clock += DeltaSeconds;
308: 		++PhiC2Tick;
309: 		auto PhiC2Line = [this](const TCHAR* Tag, float Dt) {
310: 			FFindFloorResult PhiF;
311: 			GetCharacterMovement()->FindFloor(GetActorLocation(), PhiF, false);
312: 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 %s: tick=%d dt=%.4f z=%.1f velZ=%.1f mode=%d findBlock=%d findWalk=%d floorDist=%.1f floorActor=%s curBlock=%d"), Tag, PhiC2Tick, Dt, GetActorLocation().Z, GetVelocity().Z, (int32)GetCharacterMovement()->MovementMode, PhiF.bBlockingHit ? 1 : 0, PhiF.bWalkableFloor ? 1 : 0, PhiF.FloorDist, PhiF.HitResult.GetActor() ? *PhiF.HitResult.GetActor()->GetName() : TEXT("none"), GetCharacterMovement()->CurrentFloor.bBlockingHit ? 1 : 0);
313: 		};
314: 		auto PhiC2Column = [this](float X, float Y) {
315: 			for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
316: 			{
317: 				FBox PhiB = It->GetComponentsBoundingBox(true);
318: 				if (X >= PhiB.Min.X && X <= PhiB.Max.X && Y >= PhiB.Min.Y && Y <= PhiB.Max.Y)
319: 				{
320: 					UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 COLUMN: x=%.0f y=%.0f actor=%s top=%.1f base=%.1f loc=%s"), X, Y, *It->GetName(), PhiB.Max.Z, PhiB.Min.Z, *It->GetActorLocation().ToString());
321: 				}
322: 			}
323: 		};
324: 		if (PhiC2Stage == 0)
325: 		{
326: 			PhiC2Spawn = GetActorLocation();
327: 			PhiC2Stage = 1;
328: 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 SPAWN: loc=%s"), *PhiC2Spawn.ToString());
329: 		}
330: 		if (PhiC2Stage == 1)
331: 		{
332: 			PhiC2Line(TEXT("TICK"), DeltaSeconds);
333: 			if (PhiC2Tick >= 90) { PhiC2Stage = 2; }
334: 		}
335: 		else if (PhiC2Stage == 2 && PhiC2Clock >= 8.f)
336: 		{
337: 			PhiC2Column(PhiC2Spawn.X, PhiC2Spawn.Y);
338: 			SetActorLocation(FVector(PhiC2Spawn.X, PhiC2Spawn.Y, 300.f));
339: 			GetCharacterMovement()->Velocity = FVector::ZeroVector;
340: 			UE_LOG(LogTemp, Display, TEXT("PHI CROSS2 REDROP1: loc=%s"), *GetActorLocation().ToString());
--- FUNCTION ::BuildFallbackInput at line 183 ---
183: void AVEILCharacter::BuildFallbackInput()
184: {
185: 	// Build the full control scheme in code - keyboard/mouse AND Xbox pad.
186: 	// Used only when no editor-made Input assets are assigned.
187: 	auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
188: 	{
189: 		UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
190: 		Action->ValueType = Type;
191: 		BuiltActions.Add(Action);
192: 		return Action;
193: 	};
194: 
195: 	MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
196: 	LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
197: 	JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
198: 	SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
199: 	DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
200: 	AimAction = MakeAction(TEXT("IA_Aim"), EInputActionValueType::Boolean);
201: 	FireAction = MakeAction(TEXT("IA_Fire"), EInputActionValueType::Boolean);
202: 	InteractAction = MakeAction(TEXT("IA_Interact"), EInputActionValueType::Boolean);
203: 
204: 	BuiltMappingContext = NewObject<UInputMappingContext>(this, TEXT("IMC_VEIL_BuiltIn"), RF_Transient);
205: 	UInputMappingContext* IMC = BuiltMappingContext;
206: 
207: 	auto Map = [IMC, this](UInputAction* Action, const FKey Key,
208: 		bool bNegate = false, bool bSwizzle = false)
209: 	{
210: 		FEnhancedActionKeyMapping& Mapping = IMC->MapKey(Action, Key);
211: 		if (bSwizzle)
212: 		{
213: 			UInputModifierSwizzleAxis* Swizzle = NewObject<UInputModifierSwizzleAxis>(this);
214: 			Swizzle->Order = EInputAxisSwizzle::YXZ;
215: 			Mapping.Modifiers.Add(Swizzle);
216: 		}
217: 		if (bNegate)
218: 		{
219: 			Mapping.Modifiers.Add(NewObject<UInputModifierNegate>(this));
220: 		}
221: 	};
222: 
223: 	// ---- Keyboard + mouse ----
224: 	Map(MoveAction, EKeys::W, false, true);
225: 	Map(MoveAction, EKeys::S, true, true);
226: 	Map(MoveAction, EKeys::A, true, false);
227: 	Map(MoveAction, EKeys::D, false, false);
228: 	Map(LookAction, EKeys::Mouse2D);
229: 	Map(JumpAction, EKeys::SpaceBar);
230: 	Map(SprintAction, EKeys::LeftShift);
231: 	Map(DodgeAction, EKeys::LeftAlt);
232: 	Map(AimAction, EKeys::RightMouseButton);
233: 	Map(FireAction, EKeys::LeftMouseButton);
234: 	Map(InteractAction, EKeys::E);
235: 
236: 	// ---- Xbox controller ----
237: 	Map(MoveAction, EKeys::Gamepad_Left2D);
238: 	Map(LookAction, EKeys::Gamepad_Right2D);
239: 	Map(JumpAction, EKeys::Gamepad_FaceButton_Bottom);  // A
240: 	Map(DodgeAction, EKeys::Gamepad_FaceButton_Right);  // B
241: 	Map(InteractAction, EKeys::Gamepad_FaceButton_Left);// X
242: 	Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
243: 	Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
244: 	Map(SprintAction, EKeys::Gamepad_LeftThumbstick);   // L3
245: 	// Pause/menu lives on the PlayerController: P, Esc, and pad Menu button.
246: 
247: 	DefaultMappingContext = BuiltMappingContext;
248: 	UE_LOG(LogVEIL, Log, TEXT("VEIL input: built-in map active (keyboard/mouse + Xbox controller)."));
249: }
250: 
251: void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
252: {
253: 	Super::SetupPlayerInputComponent(PlayerInputComponent);
254: 
255: 	// 1st/3rd person toggle: V on keyboard, right-stick click (R3) on the pad.
256: 	PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
257: 	PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
258: 
259: 	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
260: 	{
261: 		if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
262: 		if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
263: 		if (JumpAction)
264: 		{
265: 			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
266: 			EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
267: 		}
268: 		if (SprintAction)
269: 		{
270: 			EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
271: 			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
272: 		}
IN VEILCharacter.cpp:15: #include "EnhancedInputComponent.h"
IN VEILCharacter.cpp:16: #include "EnhancedInputSubsystems.h"
IN VEILCharacter.cpp:23: #include "InputMappingContext.h"
IN VEILCharacter.cpp:165: if (!DefaultMappingContext)
IN VEILCharacter.cpp:172: if (UEnhancedInputLocalPlayerSubsystem* Sub =
IN VEILCharacter.cpp:173: ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
IN VEILCharacter.cpp:175: if (DefaultMappingContext)
IN VEILCharacter.cpp:177: Sub->AddMappingContext(DefaultMappingContext, 0);
IN VEILCharacter.cpp:204: BuiltMappingContext = NewObject<UInputMappingContext>(this, TEXT("IMC_VEIL_BuiltIn"), RF_Transient);
IN VEILCharacter.cpp:205: UInputMappingContext* IMC = BuiltMappingContext;
IN VEILCharacter.cpp:237: Map(MoveAction, EKeys::Gamepad_Left2D);
IN VEILCharacter.cpp:238: Map(LookAction, EKeys::Gamepad_Right2D);
IN VEILCharacter.cpp:239: Map(JumpAction, EKeys::Gamepad_FaceButton_Bottom);  // A
IN VEILCharacter.cpp:240: Map(DodgeAction, EKeys::Gamepad_FaceButton_Right);  // B
IN VEILCharacter.cpp:241: Map(InteractAction, EKeys::Gamepad_FaceButton_Left);// X
IN VEILCharacter.cpp:242: Map(FireAction, EKeys::Gamepad_RightTrigger);       // RT
IN VEILCharacter.cpp:243: Map(AimAction, EKeys::Gamepad_LeftTrigger);         // LT
IN VEILCharacter.cpp:244: Map(SprintAction, EKeys::Gamepad_LeftThumbstick);   // L3
IN VEILCharacter.cpp:247: DefaultMappingContext = BuiltMappingContext;
IN VEILCharacter.cpp:257: PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
IN VEILCharacter.cpp:259: if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
IN VEILGameMode.cpp:223: InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
IN VEILCharacter.h:13: class UInputMappingContext;
IN VEILCharacter.h:115: TObjectPtr<UInputMappingContext> DefaultMappingContext;
IN VEILCharacter.h:159: TObjectPtr<UInputMappingContext> BuiltMappingContext;
--- SECTION 3: CONFIG TRUTH ---
DefaultInput.ini:
[/Script/Engine.InputSettings]
; VEIL uses the Enhanced Input system everywhere (UE 5.8).
-DefaultPlayerInputClass=/Script/Engine.PlayerInput
+DefaultPlayerInputClass=/Script/EnhancedInput.EnhancedPlayerInput
-DefaultInputComponentClass=/Script/Engine.InputComponent
+DefaultInputComponentClass=/Script/EnhancedInput.EnhancedInputComponent
bAltEnterTogglesFullscreen=True
bF11TogglesFullscreen=True
--- SECTION 4: DEVICE TRUTH ---
PNP OK | System | High Definition Audio Controller
PNP Unknown | System | High Definition Audio Controller
PNP OK | Net | Bluetooth Device (Personal Area Network) #2
PNP OK | HIDClass | HID-compliant system controller
PNP Unknown | SoftwareDevice | Bluetooth
PNP Unknown | HIDClass | HID-compliant game controller
PNP OK | System | Intel(R) Serial IO SPI Host Controller - 7AAB
PNP OK | Bluetooth | Realtek Bluetooth Adapter
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | System | PCI standard RAM Controller
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7ACD
PNP OK | HIDClass | Bluetooth LE XINPUT compatible input device
PNP OK | System | High Definition Audio Controller
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | System | Programmable interrupt controller
PNP OK | SCSIAdapter | Microsoft Storage Spaces Controller
PNP OK | System | Intel(R) SPI (flash) Controller - 7AA4
PNP OK | Bluetooth | Microsoft Bluetooth Enumerator
PNP OK | HIDClass | XBOX Synthetic Gamepad Bus
PNP OK | HIDClass | HID-compliant system controller
PNP OK | Bluetooth | Microsoft Bluetooth LE Enumerator
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | Bluetooth | Xbox Wireless Controller
PNP OK | USB | Intel(R) USB 3.20 eXtensible Host Controller - 1.20 (Microsoft)
PNP OK | HIDClass | Bluetooth XINPUT compatible input device
PNP Unknown | System | High Definition Audio Controller
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7AFD
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7ACF
PNP OK | SoftwareDevice | Bluetooth
PNP OK | Net | Realtek 8852BE Wireless LAN WiFi 6 PCI-E NIC
PNP OK | HIDClass | Bluetooth Low Energy GATT compliant HID device
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7ACC
PNP OK | MEDIA | Wireless Microphone
PNP OK | AudioEndpoint | Microphone (Wireless Microphone)
PNP OK | Bluetooth | Xbox Wireless Controller
PNP OK | Bluetooth | Bluetooth Device (RFCOMM Protocol TDI)
PNP OK | HDC | Standard SATA AHCI Controller
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7AFC
PNP OK | System | Intel(R) Serial IO UART Host Controller - 7AA8
PNP OK | System | Intel(R) Serial IO I2C Host Controller - 7ACE
PNP OK | SCSIAdapter | Standard NVM Express Controller
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | System | Intel(R) Serial IO GPIO Host Controller - INTC1056
PNP OK | Bluetooth | Bluetooth LE Generic Attribute Service
PNP OK | System | Nefarius Virtual Gamepad Emulation Bus
PNP OK | Net | Realtek PCIe GbE Family Controller
PNP Unknown | System | High Definition Audio Controller
--- SECTION 5: LOG ARCHAEOLOGY ---
LOGFILE: VEIL.log bytes=323785 modified=10/28/2026 02:12:22
LogPluginManager: Mounting Engine plugin EnhancedInput
[2026.10.28-08.11.26:908][  0]LogModuleManager: InternalLoadLibrary: 'EnhancedInput' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-EnhancedInput.dll')
[2026.10.28-08.11.26:916][  0]LogModuleManager: InternalLoadLibrary: 'InputBlueprintNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputBlueprintNodes.dll')
[2026.10.28-08.11.28:176][  0]LogModuleManager: InternalLoadLibrary: 'InputEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputEditor.dll')
[2026.10.28-08.11.29:054][  0]LogGameFeatures: Loading 278 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsights, AudioInsightsRuntime, AudioModulationInsights, BaseMaterial, Bridge, ChaosCloth, ChaosInsights, ChaosVD, CmdLinkServer, Dataflow, DerivedDataBuildController, EnhancedInput, Fab, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, RenderTraceInsights, TraceUtilities, UbaController, WorldMetrics, XGEController, CompositeCore, CLionSourceCodeAccess, AnimationSharing, CodeLiteSourceCodeAccess, DumpGPUServices, GitSourceControl, GPUReshape, NamingTokens, NullSourceCodeAccess, KDevelopSourceCodeAccess, N10XSourceCodeAccess, PixWinPlugin, PlasticSourceControl, PerforceSourceControl, ProjectLauncher, PluginUtils, PropertyAccessNode, RenderDocPlugin, RiderSourceCodeAccess, SubversionSourceControl, UObjectPlugin, VisualStudioCodeSourceCodeAccess, VisualStudioSourceCodeAccess, XCodeSourceCodeAccess, Cascade, Niagara, NiagaraInsights, NiagaraSimCaching, InterchangeAssets, NiagaraPreviewContent, Interchange, InterchangeEditor, TcpMessaging, UdpMessaging, DatasmithContent, GLTFExporter, VariantManager, AlembicImporter, VariantManagerContent, ActorSequence, LevelSequenceEditor, SequenceValidator, SequencerScripting, TemplateSequence, AutomatedPerfTestTools, AndroidMedia, AvfMedia, ImgMedia, MediaCompositing, MediaPlayerEditor, MediaPlate, MP4Utilities, TmvMedia, WebMMedia, LauncherChunkInstaller, WmfMedia, ActorLayerUtilities, AndroidFileServer, AndroidDeviceProfileSelector, AndroidMoviePlayer, AndroidPermission, AppleImageUtils, AppleMoviePlayer, AssetTags, ArchVisCharacter, AudioCapture, AudioSynesthesia, CableComponent, ChunkDownloader, CustomMeshComponent, AudioWidgets, ComputeFramework, DataRegistry, ExampleDeviceProfileSelector, GameFeatures, GameplayAbilities, GeometryCache, GeometryScripting, GeometryProcessing, GooglePAD, GoogleCloudMessaging, HairStrands, InputDebugging, IOSDeviceProfileSelector, LinuxDeviceProfileSelector, LocationServicesBPLibrary, Metasound, MeshModelingToolset, MobilePatchingUtils, ModelViewViewModel, ModularGameplay, MsQuic, ProceduralMeshComponent, PropertyAccessEditor, PropertyBindingUtils, ResonanceAudio, RigVM, SignificanceManager, SkeletalMerging, SoundFields, StateTree, Synthesis, WebMMoviePlayer, WaveTable, WindowsDeviceProfileSelector, WorldConditions, WindowsMoviePlayer, NNEDenoiser, Paper2D, NNERuntimeORT, AISupport, EnvironmentQueryEditor, ACLPlugin, AnimationModifierLibrary, AnimationData, AnimatorKit, BlendSpaceMotionAnalysis, ControlRig, DeformerGraph, ControlRigSpline, ControlRigModules, GameplayInsights, EaseCurveTool, IKRig, PhysicsControl, SkeletalMeshModelingTools, RigLogic, EngineCameras, CameraShakePreviewer, TweeningUtils, GameplayCameras, OodleNetwork, AssetManagerEditor, AssetReferenceRestrictions, BlueprintMaterialTextureNodes, BlueprintHeaderView, ChangelistReview, ColorGrading, ConsoleVariables, CryptoKeys, DataValidation, EditorDebugTools, CurveEditorTools, EditorScriptingUtilities, GameplayTagsEditor, FacialAnimation, EngineAssetDefinitions, GeometryMode, MacGraphicsSwitching, MeshLODToolset, MaterialAssetWizard, MobileLauncherProfileWizard, MaterialAnalyzer, ModelingToolsEditorMode, PluginBrowser, ProxyLODPlugin, SequencerAnimTools, SpeedTreeImporter, UVEditor, UMGWidgetPreview, StylusInput, WorldPartitionHLODUtilities, AdvancedRenamer, AutomationUtils, BackChannel, Buoyancy, ChaosCaching, ChaosEditor, ChaosNiagara, ChaosSolverPlugin, ChaosUserDataPT, CharacterAI, CommonConversation, EditorDataStorage, EditorPerformance, EditorTelemetry, EditorDataStorageFeatures, EditorTRSGizmo, Fracture, FullBodyIK, GeometryCollectionPlugin, GizmoFramework, GeometryFlow, GlobalConfigurationData, GeometryDataflow, ControlRigPhysics, HttpInsights, Landmass, LevelSequenceNavigatorBridge, LowLevelNetTrace, LocalizableMessage, MeshModelingToolsetExp, ModelContextProtocol, MutableAssetUserData, NFORDenoise, PlanarCut, PlatformCrypto, PythonScriptPlugin, RuntimeTelemetry, SequenceNavigator, SemanticSearch, SkeletalReduction, ToolPresets, ToolsetRegistry, Water, MetaHumanSDK, EOSShared, OnlineBase, OnlineServices, OnlineSubsystem, OnlineSubsystemUtils, OnlineSubsystemNull, InterchangeTests, Takes, ConcertMain, FileSandbox, BaseCharacterFXEditor, AIModuleToolset, AllToolsets, ConfigSettingsToolset, AutomationTestToolset, AnimationAssistantToolset, ConversationToolset, DataRegistryToolset, DataflowAgent, GameFeaturesToolset, EditorToolset, GASToolsets, PCGToolset, NiagaraToolsets, MCPClientToolset, GameplayTagsToolset, PluginToolset, SemanticSearchToolset, PhysicsToolsets, SlateInspectorToolset, StateTreeToolset, UMGToolSet, InterchangeAxfAssets, WorldConditionsToolset, OnlineSubsystemGooglePlay, ContentBrowserClassDataSource, ContentBrowserAssetDataSource, ContentBrowserFileDataSource, XInputDevice, SQLiteCore, LightMixer, ObjectMixer, Scribble, OnlineSubsystemIOS, PortableObjectFileDataSource, ConcertSyncCore, ConcertSyncClient, ConcertSharedSlate].
[2026.10.28-08.11.29:072][  0]LogContentValidation: Adding native validator /Script/InputBlueprintNodes.EnhancedInputUserWidgetValidator
LOGFILE: VEIL-backup-2026.10.28-08.11.19.log bytes=267290 modified=10/28/2026 02:11:19
LogPluginManager: Mounting Engine plugin EnhancedInput
[2026.10.28-08.11.16:074][  0]LogModuleManager: InternalLoadLibrary: 'EnhancedInput' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-EnhancedInput.dll')
[2026.10.28-08.11.16:082][  0]LogModuleManager: InternalLoadLibrary: 'InputBlueprintNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputBlueprintNodes.dll')
[2026.10.28-08.11.17:305][  0]LogModuleManager: InternalLoadLibrary: 'InputEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputEditor.dll')
[2026.10.28-08.11.18:193][  0]LogGameFeatures: Loading 278 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsightsRuntime, AudioModulationInsights, AudioInsights, BaseMaterial, Bridge, ChaosCloth, ChaosInsights, ChaosVD, CmdLinkServer, Dataflow, DerivedDataBuildController, EnhancedInput, Fab, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, RenderTraceInsights, TraceUtilities, UbaController, WorldMetrics, XGEController, ACLPlugin, AnimationData, AnimatorKit, AnimationModifierLibrary, BlendSpaceMotionAnalysis, ControlRigModules, ControlRigSpline, DeformerGraph, ControlRig, GameplayInsights, EaseCurveTool, IKRig, PhysicsControl, RigLogic, SkeletalMeshModelingTools, TweeningUtils, CodeLiteSourceCodeAccess, AnimationSharing, CLionSourceCodeAccess, DumpGPUServices, GitSourceControl, GPUReshape, KDevelopSourceCodeAccess, NullSourceCodeAccess, NamingTokens, PixWinPlugin, PerforceSourceControl, N10XSourceCodeAccess, ProjectLauncher, PluginUtils, PlasticSourceControl, RenderDocPlugin, PropertyAccessNode, RiderSourceCodeAccess, SubversionSourceControl, VisualStudioSourceCodeAccess, VisualStudioCodeSourceCodeAccess, UObjectPlugin, XCodeSourceCodeAccess, AdvancedRenamer, AutomationUtils, BackChannel, Buoyancy, ChaosEditor, ChaosCaching, ChaosNiagara, ChaosSolverPlugin, CharacterAI, ChaosUserDataPT, CommonConversation, ControlRigPhysics, EditorDataStorage, EditorDataStorageFeatures, EditorTelemetry, EditorTRSGizmo, EditorPerformance, Fracture, FullBodyIK, GeometryDataflow, GeometryFlow, GeometryCollectionPlugin, GizmoFramework, GlobalConfigurationData, HttpInsights, Landmass, LevelSequenceNavigatorBridge, LocalizableMessage, LowLevelNetTrace, MeshModelingToolsetExp, ModelContextProtocol, MutableAssetUserData, NFORDenoise, PlatformCrypto, PlanarCut, PythonScriptPlugin, RuntimeTelemetry, SequenceNavigator, SemanticSearch, SkeletalReduction, ToolPresets, ToolsetRegistry, Water, MetaHumanSDK, EOSShared, OnlineBase, OnlineServices, OnlineSubsystem, OnlineSubsystemNull, OnlineSubsystemUtils, CameraShakePreviewer, GameplayCameras, EngineCameras, CompositeCore, AssetManagerEditor, AssetReferenceRestrictions, BlueprintHeaderView, BlueprintMaterialTextureNodes, ColorGrading, ChangelistReview, ConsoleVariables, CryptoKeys, CurveEditorTools, DataValidation, EditorScriptingUtilities, EditorDebugTools, EngineAssetDefinitions, FacialAnimation, GeometryMode, GameplayTagsEditor, MacGraphicsSwitching, MaterialAnalyzer, MaterialAssetWizard, MobileLauncherProfileWizard, MeshLODToolset, ModelingToolsEditorMode, PluginBrowser, ProxyLODPlugin, SequencerAnimTools, SpeedTreeImporter, UMGWidgetPreview, StylusInput, UVEditor, WorldPartitionHLODUtilities, AlembicImporter, TcpMessaging, UdpMessaging, NNEDenoiser, NNERuntimeORT, AutomatedPerfTestTools, InterchangeTests, Takes, AISupport, EnvironmentQueryEditor, Paper2D, OodleNetwork, DatasmithContent, GLTFExporter, VariantManagerContent, VariantManager, Cascade, Niagara, NiagaraInsights, NiagaraPreviewContent, NiagaraSimCaching, InterchangeAssets, InterchangeEditor, Interchange, AndroidMedia, AvfMedia, ImgMedia, MediaCompositing, MediaPlate, MediaPlayerEditor, MP4Utilities, TmvMedia, WebMMedia, WmfMedia, ActorSequence, LevelSequenceEditor, SequencerScripting, TemplateSequence, LauncherChunkInstaller, SequenceValidator, ActorLayerUtilities, AndroidDeviceProfileSelector, AndroidFileServer, AndroidMoviePlayer, AndroidPermission, AppleImageUtils, AppleMoviePlayer, AudioCapture, AssetTags, ArchVisCharacter, AudioSynesthesia, CableComponent, ChunkDownloader, AudioWidgets, ComputeFramework, CustomMeshComponent, DataRegistry, ExampleDeviceProfileSelector, GameFeatures, GameplayAbilities, GeometryProcessing, GeometryCache, GeometryScripting, GoogleCloudMessaging, HairStrands, GooglePAD, IOSDeviceProfileSelector, InputDebugging, LinuxDeviceProfileSelector, LocationServicesBPLibrary, MeshModelingToolset, Metasound, MobilePatchingUtils, ModelViewViewModel, ModularGameplay, MsQuic, ProceduralMeshComponent, PropertyAccessEditor, PropertyBindingUtils, ResonanceAudio, RigVM, SkeletalMerging, SignificanceManager, SoundFields, StateTree, Synthesis, WaveTable, WebMMoviePlayer, WindowsDeviceProfileSelector, WorldConditions, WindowsMoviePlayer, BaseCharacterFXEditor, ConcertMain, LightMixer, ObjectMixer, FileSandbox, AllToolsets, AnimationAssistantToolset, AIModuleToolset, AutomationTestToolset, ConfigSettingsToolset, ConversationToolset, DataflowAgent, DataRegistryToolset, EditorToolset, GameFeaturesToolset, GameplayTagsToolset, GASToolsets, MCPClientToolset, NiagaraToolsets, PhysicsToolsets, PCGToolset, PluginToolset, SemanticSearchToolset, StateTreeToolset, SlateInspectorToolset, UMGToolSet, OnlineSubsystemIOS, WorldConditionsToolset, OnlineSubsystemGooglePlay, InterchangeAxfAssets, XInputDevice, SQLiteCore, ContentBrowserAssetDataSource, ContentBrowserFileDataSource, ContentBrowserClassDataSource, Scribble, PortableObjectFileDataSource, ConcertSyncClient, ConcertSyncCore, ConcertSharedSlate].
[2026.10.28-08.11.18:210][  0]LogContentValidation: Adding native validator /Script/InputBlueprintNodes.EnhancedInputUserWidgetValidator
LOGFILE: VEIL-backup-2026.10.28-08.11.08.log bytes=267408 modified=10/28/2026 02:11:08
LogPluginManager: Mounting Engine plugin EnhancedInput
[2026.10.28-08.11.04:846][  0]LogModuleManager: InternalLoadLibrary: 'EnhancedInput' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-EnhancedInput.dll')
[2026.10.28-08.11.04:854][  0]LogModuleManager: InternalLoadLibrary: 'InputBlueprintNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputBlueprintNodes.dll')
[2026.10.28-08.11.06:213][  0]LogModuleManager: InternalLoadLibrary: 'InputEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputEditor.dll')
[2026.10.28-08.11.07:184][  0]LogGameFeatures: Loading 278 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsightsRuntime, AudioInsights, AudioModulationInsights, BaseMaterial, Bridge, ChaosCloth, ChaosInsights, ChaosVD, CmdLinkServer, Dataflow, DerivedDataBuildController, EnhancedInput, Fab, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, RenderTraceInsights, UbaController, TraceUtilities, WorldMetrics, XGEController, AISupport, EnvironmentQueryEditor, CameraShakePreviewer, GameplayCameras, EngineCameras, CompositeCore, AnimationSharing, CodeLiteSourceCodeAccess, CLionSourceCodeAccess, DumpGPUServices, GitSourceControl, KDevelopSourceCodeAccess, N10XSourceCodeAccess, NullSourceCodeAccess, NamingTokens, GPUReshape, PlasticSourceControl, PluginUtils, PixWinPlugin, ProjectLauncher, PerforceSourceControl, RenderDocPlugin, PropertyAccessNode, RiderSourceCodeAccess, SubversionSourceControl, VisualStudioCodeSourceCodeAccess, VisualStudioSourceCodeAccess, UObjectPlugin, XCodeSourceCodeAccess, AdvancedRenamer, AutomationUtils, BackChannel, Buoyancy, ChaosCaching, ChaosEditor, ChaosNiagara, ChaosUserDataPT, CharacterAI, ChaosSolverPlugin, CommonConversation, ControlRigPhysics, EditorDataStorage, EditorTelemetry, EditorTRSGizmo, EditorPerformance, EditorDataStorageFeatures, Fracture, FullBodyIK, GeometryCollectionPlugin, GizmoFramework, GeometryFlow, GlobalConfigurationData, GeometryDataflow, HttpInsights, Landmass, LevelSequenceNavigatorBridge, LowLevelNetTrace, MeshModelingToolsetExp, LocalizableMessage, ModelContextProtocol, MutableAssetUserData, NFORDenoise, PlanarCut, PlatformCrypto, PythonScriptPlugin, RuntimeTelemetry, SemanticSearch, SequenceNavigator, SkeletalReduction, ToolPresets, ToolsetRegistry, Water, NNEDenoiser, NNERuntimeORT, AnimationData, ACLPlugin, AnimationModifierLibrary, AnimatorKit, BlendSpaceMotionAnalysis, ControlRig, ControlRigSpline, DeformerGraph, ControlRigModules, GameplayInsights, EaseCurveTool, IKRig, PhysicsControl, SkeletalMeshModelingTools, RigLogic, TweeningUtils, AssetManagerEditor, AssetReferenceRestrictions, BlueprintHeaderView, ChangelistReview, ColorGrading, BlueprintMaterialTextureNodes, ConsoleVariables, CurveEditorTools, CryptoKeys, DataValidation, EditorScriptingUtilities, EngineAssetDefinitions, EditorDebugTools, FacialAnimation, GeometryMode, GameplayTagsEditor, MacGraphicsSwitching, MaterialAnalyzer, MaterialAssetWizard, MeshLODToolset, MobileLauncherProfileWizard, ModelingToolsEditorMode, SequencerAnimTools, PluginBrowser, ProxyLODPlugin, StylusInput, SpeedTreeImporter, UMGWidgetPreview, UVEditor, WorldPartitionHLODUtilities, Cascade, NiagaraInsights, Niagara, NiagaraPreviewContent, NiagaraSimCaching, InterchangeAssets, InterchangeEditor, Interchange, AndroidMedia, AvfMedia, ImgMedia, MediaPlate, MediaPlayerEditor, MediaCompositing, MP4Utilities, TmvMedia, WebMMedia, WmfMedia, ActorSequence, LevelSequenceEditor, SequenceValidator, SequencerScripting, TemplateSequence, AutomatedPerfTestTools, DatasmithContent, GLTFExporter, VariantManager, VariantManagerContent, TcpMessaging, UdpMessaging, InterchangeTests, LauncherChunkInstaller, Takes, Paper2D, OodleNetwork, AlembicImporter, MetaHumanSDK, OnlineBase, EOSShared, OnlineServices, OnlineSubsystem, OnlineSubsystemNull, OnlineSubsystemUtils, ActorLayerUtilities, AndroidDeviceProfileSelector, AndroidFileServer, AndroidMoviePlayer, AndroidPermission, AppleMoviePlayer, AppleImageUtils, ArchVisCharacter, AssetTags, AudioCapture, AudioSynesthesia, CableComponent, ChunkDownloader, AudioWidgets, CustomMeshComponent, ComputeFramework, ExampleDeviceProfileSelector, DataRegistry, GameFeatures, GameplayAbilities, GeometryCache, GeometryProcessing, GoogleCloudMessaging, GeometryScripting, HairStrands, GooglePAD, InputDebugging, IOSDeviceProfileSelector, LinuxDeviceProfileSelector, LocationServicesBPLibrary, MeshModelingToolset, Metasound, ModularGameplay, MobilePatchingUtils, ModelViewViewModel, MsQuic, PropertyBindingUtils, PropertyAccessEditor, ProceduralMeshComponent, ResonanceAudio, SkeletalMerging, SoundFields, RigVM, SignificanceManager, StateTree, Synthesis, WebMMoviePlayer, WaveTable, WindowsDeviceProfileSelector, WindowsMoviePlayer, WorldConditions, InterchangeAxfAssets, ConcertMain, FileSandbox, ContentBrowserAssetDataSource, ContentBrowserClassDataSource, ContentBrowserFileDataSource, OnlineSubsystemIOS, PortableObjectFileDataSource, SQLiteCore, Scribble, XInputDevice, BaseCharacterFXEditor, AIModuleToolset, AllToolsets, AnimationAssistantToolset, AutomationTestToolset, ConfigSettingsToolset, DataflowAgent, ConversationToolset, EditorToolset, GameFeaturesToolset, DataRegistryToolset, GASToolsets, GameplayTagsToolset, MCPClientToolset, NiagaraToolsets, PhysicsToolsets, PluginToolset, PCGToolset, SemanticSearchToolset, SlateInspectorToolset, StateTreeToolset, WorldConditionsToolset, UMGToolSet, ObjectMixer, LightMixer, OnlineSubsystemGooglePlay, ConcertSyncClient, ConcertSyncCore, ConcertSharedSlate].
[2026.10.28-08.11.07:203][  0]LogContentValidation: Adding native validator /Script/InputBlueprintNodes.EnhancedInputUserWidgetValidator
--- NEWEST LOG TAIL ---
[2026.10.28-08.12.20:487][  0]LogExit: Editor shut down
[2026.10.28-08.12.21:228][  0]LogEditorDataStorage: Destroyed TEDS Core.
[2026.10.28-08.12.21:228][  0]LogEditorDataStorage: Destroyed TEDS Compatibility.
[2026.10.28-08.12.21:675][  0]LogExit: Object subsystem successfully closed.
[2026.10.28-08.12.21:726][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
[2026.10.28-08.12.21:978][  0]LogSemanticSearch: Cancelled pending HTTP requests (InFlight: 0)
[2026.10.28-08.12.21:978][  0]LogSemanticSearch: Cancelled pending HTTP requests (InFlight: 0)
[2026.10.28-08.12.21:978][  0]LogSemanticSearch: CancelIndexing: Canceled all tasks (IndexId=60197705)
[2026.10.28-08.12.22:055][  0]LogObjectProfiler: Shutdown
[2026.10.28-08.12.22:055][  0]LogMemoryProfiler: Shutdown
[2026.10.28-08.12.22:056][  0]LogNetworkingProfiler: Shutdown
[2026.10.28-08.12.22:056][  0]LogLoadingProfiler: Shutdown
[2026.10.28-08.12.22:056][  0]LogTimingProfiler: Shutdown
[2026.10.28-08.12.22:065][  0]LogChaosVDEditor: [FChaosVDExtensionsManager::UnRegisterExtension] UnRegistering CVD Extension [FChaosVDGenericDebugDrawExtension] ...
[2026.10.28-08.12.22:066][  0]LogChaosVDEditor: [FChaosVDExtensionsManager::UnRegisterExtension] UnRegistering CVD Extension [FChaosVDAccelerationStructuresExtension] ...
[2026.10.28-08.12.22:066][  0]LogChaosVDEditor: [FChaosVDExtensionsManager::UnRegisterExtension] UnRegistering CVD Extension [FChaosVDCameraTracesExtension] ...
[2026.10.28-08.12.22:066][  0]LogChaosVDEditor: [FChaosVDExtensionsManager::UnRegisterExtension] UnRegistering CVD Extension [FChaosVDParticleExtraDataExtension] ...
[2026.10.28-08.12.22:066][  0]LogChaosVDEditor: [FChaosVDExtensionsManager::UnRegisterExtension] UnRegistering CVD Extension [FPerformanceMetricsExtension] ...
[2026.10.28-08.12.22:346][  0]LogChaosDD: Chaos Debug Draw Shutdown
[2026.10.28-08.12.22:419][  0]LogEOSShared: FEOSSDKManager::Shutdown EOS_Shutdown Result=[EOS_Success]
[2026.10.28-08.12.22:420][  0]LogNFORDenoise: NFORDenoise function shutting down
[2026.10.28-08.12.22:512][  0]LogXGEController: Cleaning working directory: C:/Users/Admin/AppData/Local/Temp/UnrealXGEWorkingDir/
[2026.10.28-08.12.22:531][  0]LogPakFile: Destroying PakPlatformFile
[2026.10.28-08.12.22:562][  0]LogExit: Exiting.
[2026.10.28-08.12.22:589][  0]Log file closed, 10/28/26 02:12:22
--- SECTION 6: A/B GAME RUNS (no pad press in either run - launch-side half only) ---
--- RUN A-plain ---
RUN STOPPED AFTER 40s CAPTURE
TRUTH LINES IN RUN LOG: 0
INSTRUMENT ABSENT OR NO TRUTH LINES - read stands on sections 1 to 5
--- RUN LOG TAIL ---
[2026.10.28-08.14.24:491][ 15]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_47 top=668.4 base=639.0 loc=X=184 Y=-2092 Z=654 collEnabled=3
[2026.10.28-08.14.24:491][ 15]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_48 top=206.8 base=0.0 loc=X=-2068 Y=-366 Z=103 collEnabled=3
[2026.10.28-08.14.24:491][ 15]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_49 top=659.2 base=650.4 loc=X=-2068 Y=-366 Z=655 collEnabled=3
[2026.10.28-08.14.24:491][ 15]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_50 top=344.7 base=300.0 loc=X=-545 Y=2028 Z=322 collEnabled=3
[2026.10.28-08.14.24:491][ 16]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_51 top=680.0 base=600.0 loc=X=-545 Y=2028 Z=640 collEnabled=3
[2026.10.28-08.14.24:491][ 16]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=25.00 worldDelta=0.0005 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_0 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=48013 timerActive=0 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=-1.00
[2026.10.28-08.14.24:491][ 16]LogTemp: Display: PHI GM TICKPROOF: worldTime=25.0 paused=0
[2026.10.28-08.14.24:491][ 16]LogVEIL: PHI TICKPROOF: frames=48014 worldTime=25.0 paused=0
--- RUN B-noxinput ---
RUN STOPPED AFTER 40s CAPTURE
TRUTH LINES IN RUN LOG: 0
INSTRUMENT ABSENT OR NO TRUTH LINES - read stands on sections 1 to 5
--- RUN LOG TAIL ---
[2026.10.28-08.15.06:343][896]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_47 top=668.4 base=639.0 loc=X=184 Y=-2092 Z=654 collEnabled=3
[2026.10.28-08.15.06:343][896]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_48 top=206.8 base=0.0 loc=X=-2068 Y=-366 Z=103 collEnabled=3
[2026.10.28-08.15.06:343][896]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_49 top=659.2 base=650.4 loc=X=-2068 Y=-366 Z=655 collEnabled=3
[2026.10.28-08.15.06:344][896]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_50 top=344.7 base=300.0 loc=X=-545 Y=2028 Z=322 collEnabled=3
[2026.10.28-08.15.06:344][897]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_51 top=680.0 base=600.0 loc=X=-545 Y=2028 Z=640 collEnabled=3
[2026.10.28-08.15.06:344][897]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=30.00 worldDelta=0.0005 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_0 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=57894 timerActive=0 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=-1.00
[2026.10.28-08.15.06:344][897]LogTemp: Display: PHI GM TICKPROOF: worldTime=30.0 paused=0
[2026.10.28-08.15.06:344][897]LogVEIL: PHI TICKPROOF: frames=57895 worldTime=30.0 paused=0
JOB 366 DONE

```
