# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:16:18 UTC

## STEP 1
```
=== Job 239 relaunched VEIL_DONE with the ProjectID struct form. This census reads attempt 2 whole - Error lines, completion lines, the archive exe - AND the full AutomationTool exception trace the UAT tail points at (the 233 census read only UAT stdout; an UnknownCookFailure hides its cause in that trace). Then, with the UAT lane free, OMNI_DONE launches ALONE: job 232s OMNI UAT died before its log was set (ExitCode 1, 1291-byte log) because 231 and 232 launched together into the single-instance mutex. Sequential from here. ===
VEIL attempt2 log: 2692 bytes, last write 10/27/2026 18:16:18
Error: lines = 0
LogCsvProfiler: Display: Metadata set : compacttset="0"
LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL\VEIL.uproject -run=Cook -TargetPlatform=Windows -unversioned -fileopenlog -abslog="C:\Program Files\Epic Games\UE_5.8\Engine\Programs\AutomationTool\Saved\Cook-2026.10.27-18.16.18.txt" -stdout -CrashForUAT -unattended -NoLogTimes""
LogCsvProfiler: Display: Metadata set : loginid="00359c3cc1654340888e9704ab14b49f"
LogCsvProfiler: Display: Metadata set : llm="0"
LogCsvProfiler: Display: Metadata set : zenstreaming="0"
VEIL_DONE archive still MISSING.
--- AutomationTool Log.txt (exception trace, last 40 lines) ---
TraceHost=(null)
TraceFile=(null)
Project Params **************
********** COOK COMMAND STARTED **********
Looking for targets for project D:\VEIL\VEIL.uproject
Searching for target rule files in D:/VEIL
Found 2 target rule files:
  D:\VEIL\Source\VEIL.Target.cs
  D:\VEIL\Source\VEILEditor.Target.cs
Targets DLL C:\Users\Admin\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_5.8\Rules\UATRules-c8453fb96c65dc5ec68a30cffd349628.dll is up to date.
Compiling targets DLL: C:\Users\Admin\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_5.8\Rules\UATRules-c8453fb96c65dc5ec68a30cffd349628.dll
Creating target rules object: VEILTarget
Adding target: VEILTarget (Game)
Creating target rules object: VEILEditorTarget
Adding target: VEILEditorTarget (Editor)
Loading ini files for D:\VEIL\VEIL.uproject
Running UnrealEditor Cook for project D:\VEIL\VEIL.uproject
Commandlet log file is C:\Program Files\Epic Games\UE_5.8\Engine\Programs\AutomationTool\Saved\Cook-2026.10.27-18.16.18.txt
SafeFileExists C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe=True
Running: C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe "D:\VEIL\VEIL.uproject" -run=Cook  -TargetPlatform=Windows  -unversioned -fileopenlog -abslog="C:\Program Files\Epic Games\UE_5.8\Engine\Programs\AutomationTool\Saved\Cook-2026.10.27-18.16.18.txt" -stdout -CrashForUAT -unattended -NoLogTimes
LogInit: Display: Running engine for game: VEIL
LogCore: Display: Requested channels: 'cpu,gpu,frame,log,bookmark,screenshot,region'
LogTrace: Display: Control listening on port 1985
LogCsvProfiler: Display: Metadata set : platform="Windows"
LogCsvProfiler: Display: Metadata set : config="Development"
LogCsvProfiler: Display: Metadata set : buildversion="++UE5+Release-5.8-CL-55116800"
LogCsvProfiler: Display: Metadata set : engineversion="5.8.0-55116800+++UE5+Release-5.8"
LogCsvProfiler: Display: Metadata set : enginereleaseversion="5.8.0"
LogCsvProfiler: Display: Metadata set : os="Windows 11 (26H2) [10.0.26300.9711] "
LogCsvProfiler: Display: Metadata set : cpu="GenuineIntel|12th Gen Intel(R) Core(TM) i5-12400F"
LogCsvProfiler: Display: Metadata set : pgoenabled="0"
LogCsvProfiler: Display: Metadata set : pgoprofilingenabled="0"
LogCsvProfiler: Display: Metadata set : ltoenabled="0"
LogCsvProfiler: Display: Metadata set : asan="0"
LogCsvProfiler: Display: Metadata set : mergedmodules="0"
LogCsvProfiler: Display: Metadata set : compacttset="0"
LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL\VEIL.uproject -run=Cook -TargetPlatform=Windows -unversioned -fileopenlog -abslog="C:\Program Files\Epic Games\UE_5.8\Engine\Programs\AutomationTool\Saved\Cook-2026.10.27-18.16.18.txt" -stdout -CrashForUAT -unattended -NoLogTimes""
LogCsvProfiler: Display: Metadata set : loginid="00359c3cc1654340888e9704ab14b49f"
LogCsvProfiler: Display: Metadata set : llm="0"
LogCsvProfiler: Display: Metadata set : zenstreaming="0"
PACKAGE OMNI_DONE (attempt 2, alone, ProjectID struct form) LAUNCHED: pid 52988, archive D:\Builds\OMNI\OMNI_DONE, log D:\OMNI-UE\Saved\Logs\PackageOMNIDone2.log

```
