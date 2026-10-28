# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 16:34:20 UTC

## STEP 1
```
=== INPUT CHAIN READ 432 - THE CONTROLS DO NOT ANSWER IN THE MERGED GAME, SO THIS JOB READS THE WHOLE INPUT CHAIN AT ITS OWN LINES (Ground from Tyree own hands, 2026-10-28: she stands, the narrator speaks twice, and no control moves her. The chain that carries a press to the pawn has named links: the input bindings in the character, the possession of the pawn by the controller, the GameMode pawn and controller classes in config, and the action and axis mappings in DefaultInput. One, the job prints every binding line in Source VEIL: SetupPlayerInputComponent, BindAction, BindAxis, BindKey, EnhancedInput, InputComponent, capped at 70 with file and line number. Two, it prints the possession and class lines: Possess, AutoPossessPlayer, DefaultPawnClass, PlayerControllerClass, GameMode, capped at 50. Three, it prints the DefaultEngine lines that name the GameMode, the default pawn, the player controller, and the default maps, capped at 25, and the DefaultInput mapping lines with their count, capped at 40. Four, the verdict in one line: INPUT CHAIN READ with the bind count and the possess count. This job is read only and every variable carries the ic432 prefix.) ===
BIND LINES=28
BIND VEILCharacter.cpp:16 #include "EnhancedInputComponent.h"
BIND VEILCharacter.cpp:17 #include "EnhancedInputSubsystems.h"
BIND VEILCharacter.cpp:171 if (UEnhancedInputLocalPlayerSubsystem* Sub =
BIND VEILCharacter.cpp:172 ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
BIND VEILCharacter.cpp:250 void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
BIND VEILCharacter.cpp:252 Super::SetupPlayerInputComponent(PlayerInputComponent);
BIND VEILCharacter.cpp:255 PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
BIND VEILCharacter.cpp:256 PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
BIND VEILCharacter.cpp:258 if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
BIND VEILCharacter.cpp:260 if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
BIND VEILCharacter.cpp:261 if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
BIND VEILCharacter.cpp:264 EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
BIND VEILCharacter.cpp:265 EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
BIND VEILCharacter.cpp:269 EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
BIND VEILCharacter.cpp:270 EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
BIND VEILCharacter.cpp:272 if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
BIND VEILCharacter.cpp:275 EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
BIND VEILCharacter.cpp:276 EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
BIND VEILCharacter.cpp:278 if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
BIND VEILCharacter.cpp:279 if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
BIND VEILGameMode.cpp:216 void AVEILPlayerController::SetupInputComponent()
BIND VEILGameMode.cpp:218 Super::SetupInputComponent();
BIND VEILGameMode.cpp:219 if (InputComponent)
BIND VEILGameMode.cpp:221 InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILGameMode.cpp:222 InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILGameMode.cpp:223 InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
BIND VEILCharacter.h:41 virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
BIND VEILGameMode.h:106 virtual void SetupInputComponent() override;
POSSESS LINES=26
POSS VEILFactionAI.cpp:24 AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
POSS VEILCharacter.cpp:366 // names the possession state, drives synthetic forward input for
POSS VEILGameMode.cpp:1 #include "Game/VEILGameMode.h"
POSS VEILGameMode.cpp:26 AVEILGameMode::AVEILGameMode()
POSS VEILGameMode.cpp:29 DefaultPawnClass = AVEILCharacter::StaticClass();
POSS VEILGameMode.cpp:30 PlayerControllerClass = AVEILPlayerController::StaticClass();
POSS VEILGameMode.cpp:34 void AVEILGameMode::BeginPlay()
POSS VEILGameMode.cpp:37 UE_LOG(LogTemp, Display, TEXT("PHI GAMEMODE ALIVE: %s paused=%d"), *GetClass()->GetName(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
POSS VEILGameMode.cpp:137 Discovery->OnMysterySolved.AddDynamic(this, &AVEILGameMode::HandleMysterySolved);
POSS VEILGameMode.cpp:157 void AVEILGameMode::SetPhase(EVEILGamePhase NewPhase)
POSS VEILGameMode.cpp:168 void AVEILGameMode::HandleMysterySolved(FName MysteryId)
POSS VEILGameMode.cpp:250 void AVEILGameMode::Tick(float DeltaSeconds)
POSS VEILMainMenu.cpp:12 #include "Game/VEILGameMode.h"
POSS VEILMainMenu.cpp:122 if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
POSS VEILPauseMenu.cpp:11 #include "Game/VEILGameMode.h"
POSS VEILMusicDirector.cpp:40 if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
POSS VEILFactionAI.h:159 /** Agent class used for reinforcements (set by GameMode or in a BP subclass). */
POSS VEILGameMode.h:2 // The GameMode boots the world systems (Faction, Streaming, Discovery are
POSS VEILGameMode.h:3 // WorldSubsystems / level actors that self-register; the GameMode seeds
POSS VEILGameMode.h:10 #include "GameFramework/GameModeBase.h"
POSS VEILGameMode.h:13 #include "VEILGameMode.generated.h"
POSS VEILGameMode.h:33 class VEIL_API AVEILGameMode : public AGameModeBase
POSS VEILGameMode.h:38 AVEILGameMode();
POSS VEILGameMode.h:54 /** Starting world data - fill in the GameMode defaults or a BP subclass. */
POSS VEILMusicDirector.h:9 #include "Game/VEILGameMode.h"
POSS VEILWorldBuilder.h:6 // lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
ENG ; The GameMode stays the global default on EVERY map: on bare maps
ENG GlobalDefaultGameMode=/Script/VEIL.VEILGameMode
ENG GameDefaultMap=/Game/Maps/VEILDistrict
ENG EditorStartupMap=/Game/Maps/VEILDistrict
MAPPINGS=0
PHI IC432 VERDICT: INPUT CHAIN READ bind=28 possess=26
JOB 432 DONE

```
