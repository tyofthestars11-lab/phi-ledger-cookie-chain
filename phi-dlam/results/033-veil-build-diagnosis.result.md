# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 03:12:59 UTC

## STEP 1
```
VS2022 DIRS:
FOUND: C:\Program Files\Microsoft Visual Studio\2022\BuildTools
VSWHERE: Visual Studio Build Tools 2022
VC TOOLS: Visual Studio Build Tools 2022
UBT LOG ERRORS:
Running Internal UnrealHeaderTool D:\VEIL\VEIL.uproject D:\VEIL\Intermediate\Build\Win64\UnrealEditor\UnrealEditor.uhtmanifest -WarningsAsErrors -installed
D:\VEIL\Source\VEIL\Public\Systems\VEILDiscoverySystem.h(131): Error: Class 'AVEILDiscoveryManager' has an invalid Unreal prefix, expecting 'UVEILDiscoveryManager'
D:\VEIL\Source\VEIL\Public\AI\VEILFactionAI.h(146): Error: Class 'AVEILFactionManager' has an invalid Unreal prefix, expecting 'UVEILFactionManager'
CompilationResultException: OtherCompilationError
Result: Failed (OtherCompilationError)
EDITOR LOG: VEIL.log
LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
PixWinPlugin: PIX capture plugin failed to initialize! Check that the process is launched from PIX.
[2026.10.27-03.06.06:608][  0]LogDirectoryWatcher: Display: CreateFile failed for 'D:/VEIL/Content/'. GetLastError code [2]
[2026.10.27-03.06.06:609][  0]LogDirectoryWatcher: Warning: Failed to begin reading directory changes for D:/VEIL/Content/. Error: The system cannot find the file specified. (0x00000002)
[2026.10.27-03.06.11:698][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Android'
[2026.10.27-03.06.11:724][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'IOS'
[2026.10.27-03.06.11:754][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Linux'
[2026.10.27-03.06.11:782][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Mac'
[2026.10.27-03.06.11:785][  0]LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'TVOS'
[2026.10.27-03.06.14:610][  0]LogShaderCompilers: Display: Failed to delete old shader autogen file: D:/VEIL/Intermediate/ShaderAutogen/PCD3D_SM5/AutogenShaderHeaders.ush
[2026.10.27-03.06.28:262][  0]LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: VEIL0001THELASTSIGNAL000000001

```

## STEP 2
```
BUILD STARTED detached, PID 20632 - outcome lands in D:\VEIL\build-out.log

```
