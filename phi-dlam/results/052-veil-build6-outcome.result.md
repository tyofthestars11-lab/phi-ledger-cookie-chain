# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 08:50:07 UTC

## STEP 1
```
DLL EXISTS: False
BUILD PROCESSES RUNNING: 0
== D:\VEIL\build6-out.log (modified 10/27/2026 02:44:40)
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(44,60): error C3878: syntax error: unexpected token '>' following 'simple-type-specifier'
		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		                                                         ^
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(44,60): note: missing one of: '(' '{' ?
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(44,60): error C3878: syntax error: unexpected token '>' following 'simple-declaration'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(51,3): error C2059: syntax error: ';'
	};
	 ^
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(53,2): error C3536: 'AddText': cannot be used before it is initialized
	AddText(TEXT("VEIL"), 64);
	^
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(56,16): error C3536: 'AddButton': cannot be used before it is initialized
	StartButton = AddButton(TEXT("Enter the Signal"));
	              ^
[6/9] Compile [x64] VEILMusicDirector.cpp
Total time in Unreal Build Accelerator local executor: 257.90 seconds

Result: Failed (OtherCompilationError)
Total execution time: 273.71 seconds
Trace written to file C:\Users\Admin\AppData\Local\UnrealBuildTool\Trace.uba with size 36.3kb
== FIRST ERROR LINES in D:\VEIL\build6-out.log :
D:\VEIL\Source\VEIL\Private\AI\VEILFactionAI.cpp(118,52): error C2039: 'Moving': is not a member of 'EPathFollowingStatus'
D:\VEIL\Source\VEIL\Private\AI\VEILFactionAI.cpp(118,52): error C2065: 'Moving': undeclared identifier
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(21,25): error C2027: use of undefined type 'UWidgetTree'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(21,37): error C2039: 'ConstructWidget': is not a member of 'TObjectPtr<UWidgetTree>'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(22,2): error C2027: use of undefined type 'UWidgetTree'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(22,14): error C2039: 'RootWidget': is not a member of 'TObjectPtr<UWidgetTree>'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(24,22): error C2027: use of undefined type 'UWidgetTree'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(24,34): error C2039: 'ConstructWidget': is not a member of 'TObjectPtr<UWidgetTree>'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(32,60): error C3878: syntax error: unexpected token '>' following 'simple-type-specifier'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(32,60): error C3878: syntax error: unexpected token '>' following 'simple-declaration'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(39,3): error C2059: syntax error: ';'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(43,56): error C3878: syntax error: unexpected token '>' following 'simple-type-specifier'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(43,56): error C3878: syntax error: unexpected token '>' following 'simple-declaration'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(44,60): error C3878: syntax error: unexpected token '>' following 'simple-type-specifier'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(44,60): error C3878: syntax error: unexpected token '>' following 'simple-declaration'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(51,3): error C2059: syntax error: ';'
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(53,2): error C3536: 'AddText': cannot be used before it is initialized
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(56,16): error C3536: 'AddButton': cannot be used before it is initialized
Result: Failed (OtherCompilationError)
== D:\VEIL\build6-err.log (modified 10/27/2026 02:40:06)
== FIRST ERROR LINES in D:\VEIL\build6-err.log :

```
