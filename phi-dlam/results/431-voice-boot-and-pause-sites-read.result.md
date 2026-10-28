# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 16:34:17 UTC

## STEP 1
```
=== VOICE BOOT AND PAUSE SITES READ 431 - THE NARRATOR SPEAKS TWICE IN THE MERGED GAME AND THE START PRESS FREEZES IT, SO THIS JOB READS THE STANDING CODE AT ITS OWN LINES (Ground from Tyree own hands at the television, 2026-10-28: the merged game boots, the Countess stands and does not fall, the narrator line plays twice over itself, the controls do not answer, and pressing Start on the controller freezes the game. The record carries two intro voice call sites from the wiring of 2026-10-27: V01 at the VEIL GameMode BeginPlay and O01 at the OMNI quest system world begin, and in the merged project both systems stand in one module, so the double voice has a named pair of candidate addresses. One, the job prints every source line in Source VEIL that calls PHIVoice or PlayVoice, with file and line number, capped at 60. Two, it prints every line that names the V01 or O01 intro rows, capped at 40, and every BeginPlay or OnWorldBeginPlay line in the cpp files, capped at 40. Three, it prints every pause and input mode line: SetGamePaused, PauseWidget, ShowPauseMenu, mouse cursor, SetInputMode, capped at 50, plus the DefaultInput lines that name Pause or the gamepad special buttons, capped at 30. Four, the verdict in one line: VOICE PAUSE READ with the voice call count, the intro row count, and the pause line count. This job is read only and every variable carries the nb431 prefix.) ===
VOICE CALL LINES=14
VOICE VEILGameMode.cpp:9 #include "Systems/PHIVoice.h"
VOICE VEILGameMode.cpp:154 FPHIVoice::Play(GetWorld(), TEXT("V01"));
VOICE VEILGameMode.cpp:164 FPHIVoice::Play(GetWorld(), TEXT("V18"));
VOICE OMNIQuestSystem.cpp:3 #include "Systems/PHIVoice.h"
VOICE OMNIQuestSystem.cpp:24 FPHIVoice::Play(&InWorld, TEXT("O01"));
VOICE OMNIQuestSystem.cpp:50 FPHIVoice::Play(GetWorld(), TEXT("O03"));
VOICE OMNIQuestSystem.cpp:65 FPHIVoice::Play(GetWorld(), TEXT("O08"));
VOICE OMNIQuestSystem.cpp:101 FPHIVoice::Play(GetWorld(), TEXT("O06"));
VOICE OMNIQuestSystem.cpp:130 FPHIVoice::Play(GetWorld(), TEXT("O13"));
VOICE OMNIQuestSystem.cpp:143 FPHIVoice::Play(GetWorld(), TEXT("O16"));
VOICE PHIVoice.cpp:2 #include "Systems/PHIVoice.h"
VOICE PHIVoice.cpp:10 void FPHIVoice::Play(UWorld* World, const TCHAR* RowId)
VOICE PHIVoice.cpp:21 if (const FPHIDialogueRow* Row = DT->FindRow<FPHIDialogueRow>(FName(*Id), TEXT("PHIVoice")))
VOICE PHIVoice.h:10 struct VEIL_API FPHIVoice
INTRO ROW LINES=2
ROW VEILGameMode.cpp:154 FPHIVoice::Play(GetWorld(), TEXT("V01"));
ROW OMNIQuestSystem.cpp:24 FPHIVoice::Play(&InWorld, TEXT("O01"));
BOOT VEILFactionAI.cpp:71 void AVEILFactionAgent::BeginPlay()
BOOT VEILFactionAI.cpp:73 Super::BeginPlay();
BOOT VEILCharacter.cpp:137 void AVEILCharacter::BeginPlay()
BOOT VEILCharacter.cpp:139 Super::BeginPlay();
BOOT VEILCharacter.cpp:406 // BeginPlay, so the first tick that sees it logs the live class.
BOOT VEILGameMode.cpp:34 void AVEILGameMode::BeginPlay()
BOOT VEILGameMode.cpp:36 Super::BeginPlay();
BOOT VEILGameMode.cpp:186 void AVEILPlayerController::BeginPlay()
BOOT VEILGameMode.cpp:188 Super::BeginPlay();
BOOT OMNIQuestSystem.cpp:16 void UOMNIQuestSystem::OnWorldBeginPlay(UWorld& InWorld)
BOOT OMNIQuestSystem.cpp:18 Super::OnWorldBeginPlay(InWorld);
BOOT VEILMusicDirector.cpp:23 void AVEILMusicDirector::BeginPlay()
BOOT VEILMusicDirector.cpp:25 Super::BeginPlay();
BOOT OMNIQuestContent.cpp:87 void AOMNIQuestGiver::BeginPlay()
BOOT OMNIQuestContent.cpp:89 Super::BeginPlay();
BOOT OMNIQuestContent.cpp:126 void AOMNIFragment::BeginPlay()
BOOT OMNIQuestContent.cpp:128 Super::BeginPlay();
BOOT OMNIQuestContent.cpp:175 void AOMNICache::BeginPlay()
BOOT OMNIQuestContent.cpp:177 Super::BeginPlay();
BOOT VEILDistrictStreaming.cpp:60 void ADistrict::BeginPlay()
BOOT VEILDistrictStreaming.cpp:62 Super::BeginPlay();
BOOT VEILDistrictStreaming.cpp:118 void AVEILStreamingManager::BeginPlay()
BOOT VEILDistrictStreaming.cpp:120 Super::BeginPlay();
PAUSE LINES=13
PAUSE VEILGameMode.cpp:181 PauseWidgetClass = UVEILPauseMenu::StaticClass();
PAUSE VEILGameMode.cpp:207 SetInputMode(FInputModeGameAndUI());
PAUSE VEILGameMode.cpp:212 SetInputMode(FInputModeGameOnly());
PAUSE VEILGameMode.cpp:234 if (PauseWidgetClass && !PauseWidget)
PAUSE VEILGameMode.cpp:236 PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
PAUSE VEILGameMode.cpp:238 if (PauseWidget) PauseWidget->AddToViewport(10);
PAUSE VEILGameMode.cpp:239 SetInputMode(FInputModeGameAndUI());
PAUSE VEILGameMode.cpp:244 if (PauseWidget) PauseWidget->RemoveFromParent();
PAUSE VEILGameMode.cpp:245 SetInputMode(FInputModeGameOnly());
PAUSE VEILMainMenu.cpp:119 PC->SetInputMode(FInputModeGameOnly());
PAUSE VEILGameMode.h:91 TSubclassOf<UUserWidget> PauseWidgetClass;
PAUSE VEILGameMode.h:110 TObjectPtr<UUserWidget> PauseWidget;
PAUSE VEILPauseMenu.h:3 // PauseWidgetClass points here - before this class existed the pause
PHI NB431 VERDICT: VOICE PAUSE READ voice=14 intro=2 pause=13
JOB 431 DONE

```
