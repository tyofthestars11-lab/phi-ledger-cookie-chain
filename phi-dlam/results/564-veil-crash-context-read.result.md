# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 15:06:25 UTC

## STEP 1
```
=== JOB 564 - VEIL CRASH CONTEXT READ (Ground: Job 561 found no callstack lines in the crash log and no fatal line in the current log, so this job reads the crash context file in the same crash folder and prints the error message and callstack and module lines from it, no patch, no build. Every variable carries the p564 prefix.) ===
CRASH FOLDER D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000 10/29/2026 08:36:10
FOLDER FILE D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000\CrashContext.runtime-xml BYTES 201107
FOLDER FILE D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000\CrashReportClient.ini BYTES 239
FOLDER FILE D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000\UEMinidump.dmp BYTES 1564112
FOLDER FILE D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000\VEIL.log BYTES 344279
CONTEXT FILE D:\VEIL-OMNI\Saved\Crashes\UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000\CrashContext.runtime-xml
CONTEXT LINE <ErrorMessage>Unhandled Exception: EXCEPTION_ACCESS_VIOLATION 0x0000000000000000</ErrorMessage>
CONTEXT LINE <GameName>UE-VEIL</GameName>
CONTEXT LINE <CallStack>UnrealEditor_Engine
CONTEXT LINE UnrealEditor_VEIL!AVEILCharacter::Tick() [D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp:394]
CONTEXT LINE ntdll</CallStack>
CONTEXT LINE <PCallStack>
CONTEXT LINE UnrealEditor-VEIL 0x00007ff9882a0000 + 24952
CONTEXT LINE </PCallStack>
CONTEXT LINE <PCallStackHash>ABA0C3DA770F4ED282C48AEFCDDD6164EF91EAEE</PCallStackHash>
CONTEXT LINE <CallStack>Unknown 0x0000000000000000 + 0
CONTEXT LINE UnrealEditor-VEIL 0x00007ff9882a0000 + 24952
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166b04
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166a64
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166a64
CONTEXT LINE </CallStack>
CONTEXT LINE <ThreadName>FAsyncWriter_VEIL</ThreadName>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 16a0b4
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166a64
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166f34
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166f34
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 16a054
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT LINE </CallStack>
CONTEXT LINE <CallStack>ntdll 0x00007ffb131f0000 + 166464
CONTEXT HEAD <?xml version="1.0" encoding="UTF-8"?>
CONTEXT HEAD <FGenericCrashContext>
CONTEXT HEAD <RuntimeProperties>
CONTEXT HEAD <CrashVersion>3</CrashVersion>
CONTEXT HEAD <ExecutionGuid>E2D5012C43E8744D4CB20AA76B853A37</ExecutionGuid>
CONTEXT HEAD <CrashGUID>UECC-Windows-A7603F614E081855FE57FDBE100E5EED_0000</CrashGUID>
CONTEXT HEAD <IsEnsure>false</IsEnsure>
CONTEXT HEAD <IsStall>false</IsStall>
CONTEXT HEAD <IsAssert>false</IsAssert>
CONTEXT HEAD <CrashType>Crash</CrashType>
CONTEXT HEAD <ErrorMessage>Unhandled Exception: EXCEPTION_ACCESS_VIOLATION 0x0000000000000000</ErrorMessage>
CONTEXT HEAD <CrashReporterMessage />
CONTEXT HEAD <CrashReporterMessage>Attended</CrashReporterMessage>
CONTEXT HEAD <ProcessId>36004</ProcessId>
CONTEXT HEAD <SecondsSinceStart>131</SecondsSinceStart>
CONTEXT HEAD <IsInternalBuild>false</IsInternalBuild>
CONTEXT HEAD <IsPerforceBuild>false</IsPerforceBuild>
CONTEXT HEAD <IsWithDebugInfo>true</IsWithDebugInfo>
CONTEXT HEAD <IsSourceDistribution>false</IsSourceDistribution>
CONTEXT HEAD <GameName>UE-VEIL</GameName>
CONTEXT HEAD <ExecutableName>UnrealEditor</ExecutableName>
CONTEXT HEAD <BuildConfiguration>Development</BuildConfiguration>
CONTEXT HEAD <GameSessionID />
CONTEXT HEAD <PlatformName>WindowsEditor</PlatformName>
CONTEXT HEAD <PlatformFullName>Win64 [Windows 11 (26H2) [10.0.26300.9818]  64b]</PlatformFullName>
CONTEXT HEAD <PlatformNameIni>Windows</PlatformNameIni>
CONTEXT HEAD <EngineMode>Game</EngineMode>
CONTEXT HEAD <EngineModeEx>Unset</EngineModeEx>
CONTEXT HEAD <DeploymentName />
CONTEXT HEAD <EngineVersion>5.8.4-58902052+++UE5+Release-5.8</EngineVersion>
CONTEXT HEAD <EngineCompatibleVersion>5.8.4-58902052+++UE5+Release-5.8</EngineCompatibleVersion>
CONTEXT HEAD <CommandLine>CommandLineRemoved</CommandLine>
CONTEXT HEAD <LanguageLCID>9</LanguageLCID>
CONTEXT HEAD <AppDefaultLocale>en-US</AppDefaultLocale>
CONTEXT HEAD <BuildVersion>++UE5+Release-5.8-CL-58902052</BuildVersion>
CONTEXT HEAD <Symbols>**UE5*Release-5.8-CL-58902052-Win64-Development</Symbols>
CONTEXT HEAD <IsUERelease>true</IsUERelease>
CONTEXT HEAD <IsRequestingExit>false</IsRequestingExit>
CONTEXT HEAD <UserName />
CONTEXT HEAD <BaseDir>C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/</BaseDir>
CONTEXT HEAD <RootDir>C:/Program Files/Epic Games/UE_5.8/</RootDir>
CONTEXT HEAD <MachineId>00359C3CC1654340888E9704AB14B49F</MachineId>
CONTEXT HEAD <LoginId>00359c3cc1654340888e9704ab14b49f</LoginId>
CONTEXT HEAD <EpicAccountId>ce1557c9b4394f10933e9506099f2c16</EpicAccountId>
CONTEXT HEAD <SourceContext />
CONTEXT HEAD <UserDescription />
CONTEXT HEAD <UserActivityHint />
CONTEXT HEAD <CrashDumpMode>0</CrashDumpMode>
CONTEXT HEAD <GameStateName />
CONTEXT HEAD <Misc.NumberOfCores>6</Misc.NumberOfCores>
CONTEXT HEAD <Misc.NumberOfCoresIncludingHyperthreads>12</Misc.NumberOfCoresIncludingHyperthreads>
CONTEXT HEAD <Misc.Is64bitOperatingSystem>1</Misc.Is64bitOperatingSystem>
CONTEXT HEAD <Misc.CPUVendor>GenuineIntel</Misc.CPUVendor>
CONTEXT HEAD <Misc.CPUBrand>12th Gen Intel(R) Core(TM) i5-12400F</Misc.CPUBrand>
CONTEXT HEAD <Misc.CPUModelID>26994</Misc.CPUModelID>
CONTEXT HEAD <Misc.CPUMicrocodeRevision>35</Misc.CPUMicrocodeRevision>
CONTEXT HEAD <Misc.PrimaryGPUBrand>NVIDIA GeForce RTX 3050</Misc.PrimaryGPUBrand>
CONTEXT HEAD <Misc.OSVersionMajor>Windows 11 (26H2) [10.0.26300.9818]</Misc.OSVersionMajor>
CONTEXT HEAD <Misc.OSVersionMinor />
CONTEXT HEAD <Misc.AnticheatProvider />
CONTEXT HEAD <MemoryStats.TotalPhysical>17012555776</MemoryStats.TotalPhysical>
CONTEXT HEAD <MemoryStats.TotalVirtual>44929843200</MemoryStats.TotalVirtual>
CONTEXT HEAD <MemoryStats.PageSize>4096</MemoryStats.PageSize>
CONTEXT HEAD <MemoryStats.TotalPhysicalGB>16</MemoryStats.TotalPhysicalGB>
CONTEXT HEAD <MemoryStats.AvailablePhysical>0</MemoryStats.AvailablePhysical>
CONTEXT HEAD <MemoryStats.AvailableVirtual>0</MemoryStats.AvailableVirtual>
CONTEXT HEAD <MemoryStats.UsedPhysical>0</MemoryStats.UsedPhysical>
CONTEXT HEAD <MemoryStats.PeakUsedPhysical>0</MemoryStats.PeakUsedPhysical>
CONTEXT HEAD <MemoryStats.UsedVirtual>0</MemoryStats.UsedVirtual>
CONTEXT HEAD <MemoryStats.PeakUsedVirtual>0</MemoryStats.PeakUsedVirtual>
CONTEXT HEAD <MemoryStats.bIsOOM>0</MemoryStats.bIsOOM>
CONTEXT HEAD <MemoryStats.OOMAllocationSize>0</MemoryStats.OOMAllocationSize>
CONTEXT HEAD <MemoryStats.OOMAllocationAlignment>0</MemoryStats.OOMAllocationAlignment>
CONTEXT HEAD <NumMinidumpFramesToIgnore>0</NumMinidumpFramesToIgnore>
CONTEXT HEAD <CallStack>UnrealEditor_Engine
CONTEXT HEAD UnrealEditor_Engine
CONTEXT HEAD UnrealEditor_VEIL!AVEILCharacter::Tick() [D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp:394]
CONTEXT HEAD UnrealEditor_Engine
CONTEXT HEAD UnrealEditor_Engine
CONTEXT HEAD UnrealEditor_Engine
PHI P564 VERDICT: VEIL CRASH CONTEXT READ ABOVE
JOB 564 DONE

```
