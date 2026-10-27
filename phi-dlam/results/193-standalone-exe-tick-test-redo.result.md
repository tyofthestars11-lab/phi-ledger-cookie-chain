# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 22:20:18 UTC

## STEP 1
```
Already up to date.
=== job 189's harness flaw: the exe existed but no proof lines were captured and the log was never checked. This redo instruments the harness itself. ===
exe written: 10/27/2026 16:16:11, size 326.3 MB
exe EXITED within 10s, exit code: 0
log exists: 66657 bytes
LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
[2026.10.27-22.20.19:951][  0]LogShaderLibrary: Error: Failed to initialize ShaderCodeLibrary required by the project because part of the Global shader library is missing from ../../Content/.
[2026.10.27-22.20.19:952][  0]LogWindows: Error: Failed to create dialog. The specified resource type cannot be found in the image file. Error: 0x715 (1813)
no TICKPROOF in the standalone log - the tail decides:
[2026.10.27-22.20.19:904][  0]LogCsvProfiler: Display: Metadata set : shaderplatform="PCD3D_SM6"
[2026.10.27-22.20.19:904][  0]LogCsvProfiler: Display: Metadata set : gpu="NVIDIA GeForce RTX 3050"
[2026.10.27-22.20.19:904][  0]LogCsvProfiler: Display: Metadata set : gpudriver="617.42"
[2026.10.27-22.20.19:904][  0]LogInit: Initializing FReadOnlyCVARCache
[2026.10.27-22.20.19:909][  0]LogRendererCore: Ray tracing is disabled. Reason: disabled through project setting (r.RayTracing=0).
[2026.10.27-22.20.19:909][  0]LogShaderLibrary: Display: Running without a pakfile/IoStore and did not find a monolithic library 'Global' - attempting disk search for its chunks
[2026.10.27-22.20.19:909][  0]LogShaderLibrary: Display:    ....  not found
[2026.10.27-22.20.19:951][  0]LogShaderLibrary: Error: Failed to initialize ShaderCodeLibrary required by the project because part of the Global shader library is missing from ../../Content/.
[2026.10.27-22.20.19:952][  0]LogWindows: Error: Failed to create dialog. The specified resource type cannot be found in the image file. Error: 0x715 (1813)
[2026.10.27-22.20.19:952][  0]LogWindows: FPlatformMisc::RequestExit(1, FShaderCodeLibrary::InitForRuntime)
[2026.10.27-22.20.19:952][  0]LogWindows: FPlatformMisc::RequestExitWithStatus(1, 0, FShaderCodeLibrary::InitForRuntime)
[2026.10.27-22.20.19:952][  0]LogCore: Engine exit requested (reason: Win RequestExit)
=== JOB 193 DONE ===

```
