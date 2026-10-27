# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:14:45 UTC

## STEP 1
```
=== The deep read has been gated twice: first by the missing DLL (jobs 198/200/205), then by the modules missing entry point (job 207s CoreUObject crash). Job 209 restores the entry point and proves startup. This job reruns job 200s script unchanged (D:\OMNI-UE\Scripts\abp_deep_read.py): ABP parentage via registry tags, graph inventory incl. the AnimGraph, Python node visibility, Countess pack AnimSequence/AnimMontage/BlendSpace census. Its lines choose the ABP repair route. ===
commandlet exit: 3
[2026.10.27-23.14.51:021][  0]LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-23.14.52:335][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] COMPILER ERROR: failed building connection with 'Object Reference is not compatible with Object Reference.' at  Set Character
[2026.10.27-23.14.52:336][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:336][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:336][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ResetCombo" in 'Countess_AnimBlueprint'.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ComboAttackSave" in 'Countess_AnimBlueprint'.
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:337][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:338][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.14.52:338][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.14.52:339][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] This blueprint (self) is not compatible with ' Target ', therefore that pin must have a connection.
[2026.10.27-23.14.52:340][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  : unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.14.52:340][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Event Dispatcher has no property  Assign <invalid delegate>
[2026.10.27-23.14.52:340][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Failed to create property K2Node_CreateDelegate_OutputDelegate from  <None>  due to a bad or unknown type (Delegate)
[2026.10.27-23.14.52:341][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  Signature Error: Unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.14.52:944][  0]LogPluginManager: Error: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
[2026.10.27-23.14.53:887][  0]LogWindows: Error: === Critical error: ===
[2026.10.27-23.14.53:887][  0]LogWindows: Error: 
[2026.10.27-23.14.53:887][  0]LogWindows: Error: Fatal error!
[2026.10.27-23.14.53:887][  0]LogWindows: Error: 
[2026.10.27-23.14.53:887][  0]LogWindows: Error: Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x00000231057b1e10
[2026.10.27-23.14.53:887][  0]LogWindows: Error: 
[2026.10.27-23.14.53:887][  0]LogWindows: Error: [Callstack] 0x00007ff96448a8e1 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:887][  0]LogWindows: Error: [Callstack] 0x00007ff9643c261d UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:887][  0]LogWindows: Error: [Callstack] 0x00007ff964380a11 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:887][  0]LogWindows: Error: [Callstack] 0x00007ff9643a5ec5 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:887][  0]LogWindows: Error: [Callstack] 0x00007ff9644bcc0b UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff9641e95d7 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efd4a71 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efd3c27 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efd93fd UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc557 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc5ba UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70efe1256 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70eff5c74 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ff70eff838a UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: [Callstack] 0x00007ffa4b13dda7 KERNEL32.DLL!UnknownFunction []
[2026.10.27-23.14.53:888][  0]LogWindows: Error: 

```
