# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 04:03:39 UTC

## STEP 1
```
DLL EXISTS: False
BUILD PROCESSES RUNNING: 0
== D:\VEIL\build3-out.log (tail 40)
  Memory 15.84 GB physical, 17.57 GB/40.84 GB committed
  UBA Storage capacity 40 GB
[1/15] Compile Resource [x64] Default.rc2
[2/15] Compile [x64] SharedPCH.UnrealEd.Project.ValApi.ValExpApi.Cpp20.cpp
[3/15] Compile [x64] PerModuleInline.gen.cpp
[4/15] Compile [x64] VEIL.cpp
[5/15] Compile [x64] VEILCharacter.cpp
D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp(18,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[6/15] Compile [x64] VEILDistrictStreaming.cpp
D:\VEIL\Source\VEIL\Private\World\VEILDistrictStreaming.cpp(5,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[7/15] Compile [x64] VEILDiscoverySystem.cpp
D:\VEIL\Source\VEIL\Private\Systems\VEILDiscoverySystem.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[8/15] Compile [x64] VEILFactionAI.cpp
D:\VEIL\Source\VEIL\Private\AI\VEILFactionAI.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[9/15] Compile [x64] VEILGameMode.cpp
D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp(9,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[10/15] Compile [x64] VEILMusicDirector.cpp
D:\VEIL\Source\VEIL\Private\Systems\VEILMusicDirector.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[11/15] Compile [x64] VEILMainMenu.cpp
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(14,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
#include "VEIL.h"
^
[12/15] Compile [x64] Module.VEIL.gen.cpp
Total time in Unreal Build Accelerator local executor: 43.52 seconds

Result: Failed (OtherCompilationError)
Total execution time: 74.46 seconds
Trace written to file C:\Users\Admin\AppData\Local\UnrealBuildTool\Trace.uba with size 14.4kb
== error/result lines:
D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp(18,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\World\VEILDistrictStreaming.cpp(5,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\Systems\VEILDiscoverySystem.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\AI\VEILFactionAI.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp(9,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\Systems\VEILMusicDirector.cpp(7,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
D:\VEIL\Source\VEIL\Private\Game\VEILMainMenu.cpp(14,1): fatal error C1083: Cannot open include file: 'VEIL.h': No such file or directory
Total time in Unreal Build Accelerator local executor: 43.52 seconds
Result: Failed (OtherCompilationError)
Total execution time: 74.46 seconds
== D:\VEIL\build3-err.log (tail 40)
== error/result lines:

```
