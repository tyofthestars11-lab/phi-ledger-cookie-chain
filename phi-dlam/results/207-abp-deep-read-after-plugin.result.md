# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:06:46 UTC

## STEP 1
```
=== Jobs 198, 200 and 205 are now explained by one cause, proven by job 204: the console file ends at the plugin load error - with no PhiParticleAccelerator DLL, every editor commandlet in both projects aborts during startup (exit 1) and the Python script never executes. Job 206 rebuilds the plugin; if its DLL stands, this rerun of the deep read (job 200s script, unchanged) finally executes: ABP parentage via registry tags, graph inventory, node visibility, Countess pack animation census. If the DLL is still absent this job says so and stops - the read cannot run ahead of the plugin. ===
PLUGIN DLL PRESENT - running the deep read
commandlet exit: 3
[2026.10.27-23.06.52:166][  0]LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-23.06.53:549][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] COMPILER ERROR: failed building connection with 'Object Reference is not compatible with Object Reference.' at  Set Character
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:550][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ResetCombo" in 'Countess_AnimBlueprint'.
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ComboAttackSave" in 'Countess_AnimBlueprint'.
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.06.53:551][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.06.53:553][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] This blueprint (self) is not compatible with ' Target ', therefore that pin must have a connection.
[2026.10.27-23.06.53:553][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  : unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.06.53:553][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Event Dispatcher has no property  Assign <invalid delegate>
[2026.10.27-23.06.53:554][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Failed to create property K2Node_CreateDelegate_OutputDelegate from  <None>  due to a bad or unknown type (Delegate)
[2026.10.27-23.06.53:554][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  Signature Error: Unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.06.54:170][  0]LogPluginManager: Error: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
[2026.10.27-23.06.55:748][  0]LogWindows: Error: === Critical error: ===
[2026.10.27-23.06.55:748][  0]LogWindows: Error: 
[2026.10.27-23.06.55:748][  0]LogWindows: Error: Fatal error!
[2026.10.27-23.06.55:748][  0]LogWindows: Error: 
[2026.10.27-23.06.55:748][  0]LogWindows: Error: Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x000001daf0d51e10
[2026.10.27-23.06.55:748][  0]LogWindows: Error: 
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a3aa8e1 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a2e261d UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a2a0a11 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a2c5ec5 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a3dcc0b UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff97a1095d7 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efd4a71 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efd3c27 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efd93fd UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc557 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc5ba UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70efe1256 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70eff5c74 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ff70eff838a UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: [Callstack] 0x00007ffa4b13dda7 KERNEL32.DLL!UnknownFunction []
[2026.10.27-23.06.55:748][  0]LogWindows: Error: 

```
