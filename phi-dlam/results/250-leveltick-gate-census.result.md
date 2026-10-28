# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:38:35 UTC

## STEP 1
```
=== Job 246 settled the discriminator: the packaged VEIL_DONE, running standalone with no editor, reproduces the frozen signature exactly - worldTime 0.00 in all 7 samples over 30 seconds, pawnTickEntries 0, timerRemaining 3.00 frozen, while worldDelta reads real and the PC ticks. The freeze is in the game data/code, not the editor. Job 244s source census caught the anatomy but at +-1 line of context: RealTimeSeconds += DeltaSeconds runs, then DeltaSeconds = GameDeltaSeconds overwrites the delta, then a braced block holds TimeSeconds += DeltaSeconds - and the condition guarding that block was NOT captured. This job reads LevelTick.cpp with WIDE context around GameDeltaSeconds, the time-advance block, the timer tick, and IsPaused, reads WorldSettings.h for PauseDelay, and sweeps OUR OWN module code (VEIL + OMNI Source trees) for anything that touches pause, dilation, slomo, or delta - our code is a suspect surface too. Read-only. ===
--- GameDeltaSeconds in LevelTick.cpp (context 20,20) ---
			TickNetClient( DeltaSeconds );
		}
	}

	// Update time.
	RealTimeSeconds += DeltaSeconds;

	// Audio always plays at real-time regardless of time dilation, but only when NOT paused
	if( !bIsPaused )
	{
		AudioTimeSeconds += DeltaSeconds;
	}

	// Save off actual delta
	float RealDeltaSeconds = DeltaSeconds;

	// apply time multipliers
	DeltaSeconds *= Info->GetEffectiveTimeDilation();

	// Handle clamping of time to an acceptable value
	const float GameDeltaSeconds = Info->FixupDeltaSeconds(DeltaSeconds, RealDeltaSeconds);
	check(GameDeltaSeconds >= 0.0f);

	DeltaSeconds = GameDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;

	UnpausedTimeSeconds += DeltaSeconds;

	if ( !bIsPaused )
	{
		TimeSeconds += DeltaSeconds;
	}

	if( bPlayersOnly )
	{
		TickType = LEVELTICK_ViewportsOnly;
	}

	// give the async loading code more time if we're performing a high priority load or are in seamless travel
	if (Info->bHighPriorityLoading || Info->bHighPriorityLoadingLocal || IsInSeamlessTravel())
...
		}
	}

	// Update time.
	RealTimeSeconds += DeltaSeconds;

	// Audio always plays at real-time regardless of time dilation, but only when NOT paused
	if( !bIsPaused )
	{
		AudioTimeSeconds += DeltaSeconds;
	}

	// Save off actual delta
	float RealDeltaSeconds = DeltaSeconds;

	// apply time multipliers
	DeltaSeconds *= Info->GetEffectiveTimeDilation();

	// Handle clamping of time to an acceptable value
	const float GameDeltaSeconds = Info->FixupDeltaSeconds(DeltaSeconds, RealDeltaSeconds);
	check(GameDeltaSeconds >= 0.0f);

	DeltaSeconds = GameDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;

	UnpausedTimeSeconds += DeltaSeconds;

	if ( !bIsPaused )
	{
		TimeSeconds += DeltaSeconds;
	}

	if( bPlayersOnly )
	{
		TickType = LEVELTICK_ViewportsOnly;
	}

	// give the async loading code more time if we're performing a high priority load or are in seamless travel
	if (Info->bHighPriorityLoading || Info->bHighPriorityLoadingLocal || IsInSeamlessTravel())
	{
...

	// Update time.
	RealTimeSeconds += DeltaSeconds;

	// Audio always plays at real-time regardless of time dilation, but only when NOT paused
	if( !bIsPaused )
	{
		AudioTimeSeconds += DeltaSeconds;
	}

	// Save off actual delta
	float RealDeltaSeconds = DeltaSeconds;

	// apply time multipliers
	DeltaSeconds *= Info->GetEffectiveTimeDilation();

	// Handle clamping of time to an acceptable value
	const float GameDeltaSeconds = Info->FixupDeltaSeconds(DeltaSeconds, RealDeltaSeconds);
	check(GameDeltaSeconds >= 0.0f);

	DeltaSeconds = GameDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;

	UnpausedTimeSeconds += DeltaSeconds;

	if ( !bIsPaused )
	{
		TimeSeconds += DeltaSeconds;
	}

	if( bPlayersOnly )
	{
		TickType = LEVELTICK_ViewportsOnly;
	}

	// give the async loading code more time if we're performing a high priority load or are in seamless travel
	if (Info->bHighPriorityLoading || Info->bHighPriorityLoadingLocal || IsInSeamlessTravel())
	{
		// GUseUnifiedTimeBudgetForStreaming handles this in HandleUnifiedStreaming
		if (!GUseUnifiedTimeBudgetForStreaming)
...
--- UnpausedTimeSeconds block (context 6,30) ---
	check(GameDeltaSeconds >= 0.0f);

	DeltaSeconds = GameDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;

	UnpausedTimeSeconds += DeltaSeconds;

	if ( !bIsPaused )
	{
		TimeSeconds += DeltaSeconds;
	}

	if( bPlayersOnly )
	{
		TickType = LEVELTICK_ViewportsOnly;
	}

	// give the async loading code more time if we're performing a high priority load or are in seamless travel
	if (Info->bHighPriorityLoading || Info->bHighPriorityLoadingLocal || IsInSeamlessTravel())
	{
		// GUseUnifiedTimeBudgetForStreaming handles this in HandleUnifiedStreaming
		if (!GUseUnifiedTimeBudgetForStreaming)
		{
			CSV_SCOPED_SET_WAIT_STAT(AsyncLoading);
			TRACE_CPUPROFILER_EVENT_SCOPE(HighPriorityAsyncLoading)
			// Force it to use the entire time slice, even if blocked on I/O
			ProcessAsyncLoading(true, true, GPriorityAsyncLoadingExtraTime / 1000.0f);
		}
	}

	// Translate world origin if requested
	if (OriginLocation != RequestedOriginLocation)
	{
		SetNewWorldOrigin(RequestedOriginLocation);
	}
	else
...
--- TimerManager tick in LevelTick.cpp ---
#include "LevelInstance/LevelInstanceSubsystem.h"
#include "ObjectCacheEventSink.h"
#else
#include "TimerManager.h"
#endif

CSV_DECLARE_CATEGORY_MODULE_EXTERN(CORE_API, Basic);
...

				if (TickType != LEVELTICK_TimeOnly && !bIsPaused)
				{
					SCOPE_TIME_GUARD_MS(TEXT("UWorld::Tick - TimerManager"), 5);
					STAT(FScopeCycleCounter Context(GetTimerManager().GetStatId());)
					GetTimerManager().Tick(DeltaSeconds);
				}
...
				if (TickType != LEVELTICK_TimeOnly && !bIsPaused)
				{
					SCOPE_TIME_GUARD_MS(TEXT("UWorld::Tick - TimerManager"), 5);
					STAT(FScopeCycleCounter Context(GetTimerManager().GetStatId());)
					GetTimerManager().Tick(DeltaSeconds);
				}

...
				{
					SCOPE_TIME_GUARD_MS(TEXT("UWorld::Tick - TimerManager"), 5);
					STAT(FScopeCycleCounter Context(GetTimerManager().GetStatId());)
					GetTimerManager().Tick(DeltaSeconds);
				}

				{
...
--- UWorld::IsPaused in World.cpp (context 4,14) ---
--- PauseDelay in WorldSettings.h (context 3,3) ---
--- OWN-CODE SWEEP: pause / dilation / delta writes in both modules ---
>>> D:\VEIL\Source
D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp:173: SetPause(true); // the title is a real title: the world waits behind it
D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp:197: SetPause(bPauseOpen);
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp:118: PC->SetPause(false);
D:\VEIL\Source\VEIL\Private\Game\VEILPauseMenu.cpp:139: PC->SetPause(false);
>>> D:\OMNI-UE\Source
D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp:197: SetPause(true); // the title is a real title: the world waits behind it
D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp:221: SetPause(bPauseOpen);
D:\OMNI-UE\Source\OMNI\Private\Game\OMNIMainMenu.cpp:118: PC->SetPause(false);
D:\OMNI-UE\Source\OMNI\Private\Game\OMNIPauseMenu.cpp:139: PC->SetPause(false);
--- standalone VEIL.log: pause/fixed/demo lines whole ---
LogWindows: Enabling Tpause support
[2026.10.28-00.32.57:246][  0]LogConfig: CVar [[FixedBootOrder:/Script/Engine/Default__SoundBase]] deferred - dummy variable created
[2026.10.28-00.32.57:246][  0]LogConfig: CVar [[FixedBootOrder:/Script/Engine/Default__MaterialInterface]] deferred - dummy variable created
[2026.10.28-00.32.57:246][  0]LogConfig: CVar [[FixedBootOrder:/Script/Engine/Default__DeviceProfileManager]] deferred - dummy variable created
[2026.10.28-00.32.58:095][  0]LogObj: Display: Attempting to load config data for Default__SlateThemeManager before the Class has been constructed/registered/linked (likely during module loading or early startup). This will result in the load silently failing and should be fixed.
[2026.10.28-00.33.01:806][  0]LogTemp: Display: PHI GAMEMODE ALIVE: VEILGameMode paused=0
[2026.10.28-00.33.01:817][  0]LogRHI: Display: ShaderPipelineCache: Paused Batching. 1
[2026.10.28-00.33.09:313][292]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0121 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.14:316][662]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0141 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.19:324][ 33]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0127 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.24:341][403]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0153 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.29:341][777]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0142 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.34:342][145]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0133 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.39:351][514]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0112 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.44:363][880]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0138 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.49:378][250]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0159 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.54:389][622]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0154 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.33.59:394][995]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0133 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.04:398][370]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0144 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.09:403][754]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0130 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.14:415][135]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0149 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.19:419][496]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0123 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.24:427][873]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0123 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.29:431][263]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0120 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.34.34:435][654]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=0.00 worldDelta=0.0131 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_2147482376 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00

```
