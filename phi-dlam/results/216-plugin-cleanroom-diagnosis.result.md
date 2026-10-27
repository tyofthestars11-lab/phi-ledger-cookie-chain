# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:26:22 UTC

## STEP 1
```
=== The games are unblocked (job 213); the plugin now gets diagnosed in isolation, where it can block nothing. The quarantined VEIL copy (sources + built DLL, exactly as it stood in the project) goes into a blank project with no ABP and no game content, and the startup proof runs. Pre-registered read: crash reproduces here = the plugin build itself carries the defect, and the next step bisects its code; blank project starts = the defect lives in the interaction, and the plugin returns to the games only after that interaction is named. ===
[2026.10.27-23.26.29:113][  0]LogPluginManager: Error: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
[2026.10.27-23.26.29:932][  0]LogWindows: Error: === Critical error: ===
[2026.10.27-23.26.29:932][  0]LogWindows: Error: 
[2026.10.27-23.26.29:932][  0]LogWindows: Error: Fatal error!
[2026.10.27-23.26.29:932][  0]LogWindows: Error: 
[2026.10.27-23.26.29:932][  0]LogWindows: Error: Unhandled Exception: EXCEPTION_ACCESS_VIOLATION reading address 0x00000287e7e61e10
[2026.10.27-23.26.29:932][  0]LogWindows: Error: 
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a3aa8e1 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a2e261d UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a2a0a11 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a2c5ec5 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a3dcc0b UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff97a1095d7 UnrealEditor-CoreUObject.dll!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efd4a71 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efd3c27 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efd93fd UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc557 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efdc5ba UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70efe1256 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70eff5c74 UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ff70eff838a UnrealEditor-Cmd.exe!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: [Callstack] 0x00007ffa4b13dda7 KERNEL32.DLL!UnknownFunction []
[2026.10.27-23.26.29:932][  0]LogWindows: Error: 
CLEAN-ROOM EXIT: 3

```
