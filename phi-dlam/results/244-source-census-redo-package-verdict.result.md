# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:31:49 UTC

## STEP 1
```
=== Two corrections in one job. (1) Job 238s census printed only its header: its Probe function appended to $script:lines, which bound to a shadow scope - every probe line was written into a variable the final print never read. The redo inlines all five probes in the main body, no functions, no scope tricks. (2) Job 240 raced job 239: it read VEILs attempt-2 log at 2 seconds old (2,692 bytes, cook in flight) and its UAT check looked for process names AutomationTool/RunUAT - the real UAT runs as dotnet, so it launched OMNI while VEIL was still cooking. This job reads both attempt-2 logs whole and delivers the verdict; if OMNIs attempt 2 died on the mutex AND VEILs run is finished, OMNI relaunches alone as attempt 3. ===
=== UE 5.8 SOURCE CENSUS (redo, inline) ===
--- WorldSettings.h exists=True ---
	UPROPERTY(transient, replicated)
	TObjectPtr<class APlayerState> PauserPlayerState;


	inline class APlayerState* GetPauserPlayerState() const { return PauserPlayerState; }
	inline virtual void SetPauserPlayerState(class APlayerState* PlayerState) { PauserPlayerState = PlayerState; }
	inline class APlayerState* GetPauserPlayerState() const { return PauserPlayerState; }
	inline virtual void SetPauserPlayerState(class APlayerState* PlayerState) { PauserPlayerState = PlayerState; }

--- LevelTick.cpp exists=True ---
	const AWorldSettings* Info = GetWorldSettings(/*bCheckStreamingPersistent=*/false, /*bChecked=*/false);
	return ( (Info && Info->GetPauserPlayerState() != nullptr && TimeSeconds >= PauseDelay) ||
				(bRequestedBlockOnAsyncLoading && GetNetMode() == NM_Client) ||
					// Prevent unload request flood.  The additional check ensures that unload requests can still be issued in the first UnloadCooldownTime seconds of play.
					if (TimeSeconds - LevelStreamingObject->LastVolumeUnloadRequestTime > LevelStreamingObject->MinTimeBetweenVolumeUnloadRequests ||  LevelStreamingObject->LastVolumeUnloadRequestTime < 0.1f)
					{
						{
							LevelStreamingObject->LastVolumeUnloadRequestTime = TimeSeconds;
							LevelStreamingObject->SetShouldBeLoaded(false);
	// Update time.
	RealTimeSeconds += DeltaSeconds;

	{
		AudioTimeSeconds += DeltaSeconds;
	}
	DeltaSeconds = GameDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;
	DeltaTimeSeconds = DeltaSeconds;
	DeltaRealTimeSeconds = RealDeltaSeconds;


	UnpausedTimeSeconds += DeltaSeconds;

	{
		TimeSeconds += DeltaSeconds;
	}
		// Update SpeedTree wind objects.
		Scene->UpdateSpeedTreeWind(TimeSeconds);
	}
#if WITH_STATE_STREAM
	StateStreamManager->Game_EndTick(RealTimeSeconds, LaneId);
	StateStreamManager->Game_BeginTick(LaneId);
--- NavigationSystem.cpp exists=True ---
		{
			const bool bIsBuildLocked = IsNavigationBuildingLocked();
			const bool bCanRebuild = !bIsBuildLocked && GetIsAutoUpdateEnabled();
			const bool bIsBuildLocked = IsNavigationBuildingLocked();
			const bool bCanRebuild = !bIsBuildLocked && GetIsAutoUpdateEnabled();

	{
		UE_LOGF(LogNavigation, Warning, "%s Navigation NOT building because navigation build is locked (flags: 0x%x).", __FUNCTION__, NavBuildingLockFlags);
		return;
--- NavigationSystem.h exists=True ---
	/** Cancels all currently running navigation builds */
	NAVIGATIONSYSTEM_API virtual void CancelBuild();

--- NavigationSystemTypes.h exists=True ---
NO MATCHES
=== ATTEMPT-2 PACKAGE VERDICT ===
--- VEIL attempt2 ---
log: 73593 bytes, last write 10/27/2026 18:16:56
Error: lines = 0
BUILD SUCCESSFUL
AutomationTool exiting with ExitCode=0 (Success)
BUILD SUCCESSFUL
AutomationTool executed for 0h 0m 39s
AutomationTool exiting with ExitCode=0 (Success)
exe: D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe 0.2 MB 10/27/2026 18:16:37
exe: D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Binaries\Win64\VEIL.exe 326.3 MB 10/27/2026 16:13:20
--- OMNI attempt2 ---
log: 1291 bytes, last write 10/27/2026 18:16:19
Error: lines = 0
AutomationTool exiting with ExitCode=1 (Error_Unknown)
BUILD FAILED
AutomationTool executed for 0h 0m 0s
AutomationTool exiting with ExitCode=1 (Error_Unknown)
BUILD FAILED
archive MISSING: D:\Builds\OMNI\OMNI_DONE
PACKAGE OMNI_DONE (attempt 3, alone after VEIL finished) LAUNCHED: pid 8692, log D:\OMNI-UE\Saved\Logs\PackageOMNIDone3.log

```
