# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:22:38 UTC

## STEP 1
```
=== Job 209 rebuilt Succeeded x2 yet the startup proof died identically (plugin init error, CoreUObject AV, exit 3), and the DLL size did not move: 146432 bytes before and after. Three questions, one job. (1) Did the module file ever land on this disk, and when was the DLL actually written? (2) What does Epics own crash record (newest Saved/Crashes folder, OMNI) name as the faulting module? (3) Clean-room test: the identical plugin folder, copied whole from D:\VEIL, inside a blank project with no ABP, no game content - does the editor start? Pre-registered read: crash reproduces in the clean room = the plugin build itself is the seat. Clean room starts = VEIL/OMNI project state is the seat (the ABP compiler errors print before every crash, and its malformed delegate property is created inside CoreUObject). ===
MODULE FILE ON DISK: yes, written 10/27/2026 17:14:28
VEIL DLL: 146432 bytes, written 10/27/2026 17:06:32
--- newest crash folder: UECC-Windows-35F086EC4C5F4F79352C7191A69A9F61_0000 ---
<ErrorMessage>Unhandled Exception: EXCEPTION_ACCESS_VIOLATION 0x0000000000000000</ErrorMessage>
<CallStack>UnrealEditor_CoreUObject
ntdll</CallStack>
<PCallStack>
</PCallStack>
<PCallStackHash>843A1C9AEC104F2544A3BCB7FAC6ECE503A38CB2</PCallStackHash>
<CallStack>Unknown 0x0000000000000000 + 0
</CallStack>
<CallStack>ntdll 0x00007ffa4c640000 + 165a24
</CallStack>
<CallStack>ntdll 0x00007ffa4c640000 + 165a24
</CallStack>
--- crash log tail ---
Scanning file cache for directory 'D:/OMNI-UE/Content/Collections/' took 0.00s
InternalLoadLibrary: 'ContentBrowserFileDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ContentBrowser/ContentBrowserFileDataSource/Binaries/Win64/UnrealEditor-ContentBrowserFileDataSource.dll')
InternalLoadLibrary: 'ContentBrowserClassDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ContentBrowser/ContentBrowserClassDataSource/Binaries/Win64/UnrealEditor-ContentBrowserClassDataSource.dll')
InternalLoadLibrary: 'LightMixer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ObjectMixer/LightMixer/Binaries/Win64/UnrealEditor-LightMixer.dll')
InternalLoadLibrary: 'ObjectMixerEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ObjectMixer/ObjectMixer/Binaries/Win64/UnrealEditor-ObjectMixerEditor.dll')
InternalLoadLibrary: 'BaseCharacterFXEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/CharacterFXEditor/BaseCharacterFXEditor/Binaries/Win64/UnrealEditor-BaseCharacterFXEditor.dll')
InternalLoadLibrary: 'XInputDevice' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/Windows/XInputDevice/Binaries/Win64/UnrealEditor-XInputDevice.dll')
InternalLoadLibrary: 'FileSandboxCore' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Sandbox/FileSandbox/Binaries/Win64/UnrealEditor-FileSandboxCore.dll')
InternalLoadLibrary: 'FileSandboxUI' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Sandbox/FileSandbox/Binaries/Win64/UnrealEditor-FileSandboxUI.dll')
InternalLoadLibrary: 'PortableObjectFileDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/Localization/PortableObjectFileDataSource/Binaries/Win64/UnrealEditor-PortableObjectFileDataSource.dll')
InternalLoadLibrary: 'ConcertSyncClient' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertSync/ConcertSyncClient/Binaries/Win64/UnrealEditor-ConcertSyncClient.dll')
InternalLoadLibrary: 'ConcertSharedSlate' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertUI/ConcertSharedSlate/Binaries/Win64/UnrealEditor-ConcertSharedSlate.dll')
InternalLoadLibrary: 'PhiParticleAccelerator' ('D:/OMNI-UE/Plugins/PhiParticleAccelerator/Binaries/Win64/UnrealEditor-PhiParticleAccelerator.dll')
Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
Message dialog closed, result: Ok, title: Message, text: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
Engine exit requested (reason: EngineExit() was called)
Abandoning remaining async distance field tasks for shutdown
Abandoning remaining async card representation tasks for shutdown
Beginning Audio Device Manager Shutdown (Module: )...
Audio Device Manager Shutdown
Slate User Destroyed.  User Index 0, Is Virtual User: 0
Preparing to exit.
CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
CloseDisregardForGC: 0/0 objects in disregard for GC pool
[2026.10.27-23.22.46:536][  0]LogPluginManager: Error: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
[2026.10.27-23.22.47:381][  0]LogWindows: Error: === Critical error: ===
[2026.10.27-23.22.47:381][  0]LogWindows: Error: 
[2026.10.27-23.22.47:381][  0]LogWindows: Error: Fatal error!
[2026.10.27-23.22.47:381][  0]LogWindows: Error: 
[2026.10.27-23.22.47:381][  0]LogWindows: Error: Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x000001fa5c401e10
[2026.10.27-23.22.47:381][  0]LogWindows: Error: 
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a3aa8e1 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a2e261d UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a2a0a11 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a2c5ec5 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a3dcc0b UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff97a1095d7 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efd4a71 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efd3c27 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efd93fd UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc557 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc5ba UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70efe1256 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70eff5c74 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ff70eff838a UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: [Callstack] 0x00007ffa4b13dda7 KERNEL32.DLL!UnknownFunction []
[2026.10.27-23.22.47:381][  0]LogWindows: Error: 
CLEAN-ROOM EXIT: 3

```
