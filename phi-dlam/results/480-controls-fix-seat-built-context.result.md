# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 19:54:22 UTC

## STEP 1
```
=== CONTROLS FIX 480 - THE BUILT MAP GETS ITS SEAT (Ground assembled whole: Tyree at the 473 build, mouse and key does, not xbox controller, stop regression, the Golden Ratio progresses only. Job 477 read the run whole: the pawn stands on the floor, the world clock runs, nothing is paused, and every bind stands in the source. The ancestor of this character stands in the repo under veil and reads plain: its code-built fallback holds the full pad map, left stick move, right stick look, A jump, B dodge, X interact, RT fire, LT aim, L3 sprint, and at its tail it hands the built context to DefaultMappingContext, and BeginPlay seats that context on the subsystem. In the merged file one link of that chain stands broken, and no read has yet printed the merged BeginPlay or the merged fallback tail, so this job prints both whole first, plus every AddMappingContext line and every DefaultMappingContext assignment in the file, the header context members, and the GameMode menu region lines 195 to 215. Then the repair, carried as a count gated base64 patcher: the built context is seated directly, by its own name BuiltMappingContext, at two points that cover both call orders, the tail of BuildFallbackInput itself and the tail of BeginPlay, each guarded so a context already seated is never doubled, each printing a PHI INPUT SEAT line into the game log when it fires. The patcher gates on the context member standing in the header and the cpp; if the seat already stands it writes nothing and the prints carry the ground for the next pass. On a clean patch one build runs the standing way and its Result line rides the verdict. Backups first, every variable carries the cf480 prefix.) ===
MAPCTX 178 Sub->AddMappingContext(DefaultMappingContext, 0);
MAPCTX COUNT=1
DMCASSIGN 249 DefaultMappingContext = BuiltMappingContext;
HD 13 class UInputMappingContext;
HD 115 TObjectPtr<UInputMappingContext> DefaultMappingContext;
HD 159 TObjectPtr<UInputMappingContext> BuiltMappingContext;
FB PADKEYS=18
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
PYTHON=C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PATCHER GATES headerBuilt=1 cppBuilt=3 alreadySeated=0
PATCHER SPANS fallback=183..250 beginplay=138..181
PATCHER BRACE DELTA open=8 close=8 include=0
PATCHER PATCH OK seat=2
BUILD none
PHI CF480 VERDICT: CONTROLS FIX patch=OK padkeys=18 build=none
JOB 480 DONE

out-file : Cannot find drive. A drive with the name '\D' does not exist.
At C:\Users\Admin\AppData\Local\Temp\phi-step-0aa0922d8dc94adb974f73edf310311b.ps1:109 char:1
+ & $cf480buildbat VEILEditor Win64 Development -Project=\"$cf480uproj\ ...
+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (\D:String) [Out-File], DriveNotFoundException
    + FullyQualifiedErrorId : DriveNotFound,Microsoft.PowerShell.Commands.OutFileCommand
 
Select-String : Cannot find path 'D:\VEIL-OMNI\Saved\build480.log' because it does not exist.
At C:\Users\Admin\AppData\Local\Temp\phi-step-0aa0922d8dc94adb974f73edf310311b.ps1:110 char:18
+ ... 0result = @(Select-String -Path $cf480logf -Pattern 'Result:' -ErrorA ...
+                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (D:\VEIL-OMNI\Saved\build480.log:String) [Select-String], ItemNotFoundEx 
   ception
    + FullyQualifiedErrorId : PathNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 
Select-String : Cannot find path 'D:\VEIL-OMNI\Saved\build480.log' because it does not exist.
At C:\Users\Admin\AppData\Local\Temp\phi-step-0aa0922d8dc94adb974f73edf310311b.ps1:113 char:16
+ ... 480errs = @(Select-String -Path $cf480logf -Pattern 'erro[r] C' -Erro ...
+                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (D:\VEIL-OMNI\Saved\build480.log:String) [Select-String], ItemNotFoundEx 
   ception
    + FullyQualifiedErrorId : PathNotFound,Microsoft.PowerShell.Commands.SelectStringCommand
 

```
