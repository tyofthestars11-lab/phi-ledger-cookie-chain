# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 21:00:03 UTC

## STEP 1
```
Current branch main is up to date.
=== OMNI deep pass: spawn census + material census + nav rebuild, then materials re-pass ===
[2026.10.27-21.00.04:989][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\OMNI-UE\OMNI.uproject -run=pythonscript -script=D:\OMNI-UE\Scripts\omni_deep_pass.py -unattended -nosplash""
[2026.10.27-21.00.12:397][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\OMNI-UE\Scripts\omni_deep_pass.py
[2026.10.27-21.00.12:505][  0]LogPython: Warning: D:/OMNI-UE/Scripts/omni_deep_pass.py:20: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
[2026.10.27-21.00.12:627][  0]LogInit: Display: LogPython: Warning: D:/OMNI-UE/Scripts/omni_deep_pass.py:20: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
--- materials re-pass (stocked pools, post job-111 copies) ---
[2026.10.27-21.00.15:344][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\OMNI-UE\OMNI.uproject -run=pythonscript -script=D:\OMNI-UE\Scripts\apply_materials.py -unattended -nosplash""
[2026.10.27-21.00.15:811][  0]LogTextureFormatASTC: Display: ASTCEnc version 5.0.1 library loaded
[2026.10.27-21.00.15:811][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatASTC
[2026.10.27-21.00.15:811][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatDXT
[2026.10.27-21.00.15:811][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatETC2
[2026.10.27-21.00.15:811][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatIntelISPCTexComp
[2026.10.27-21.00.15:811][  0]LogTextureFormatOodle: Display: Oodle Texture TFO init; latest sdk version = 2.9.16
[2026.10.27-21.00.15:811][  0]LogTextureFormatOodle: Display: Oodle Texture loading DLL: oo2tex_win64_2.9.16.dll
[2026.10.27-21.00.15:812][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatOodle
[2026.10.27-21.00.15:812][  0]LogTextureFormatManager: Display: Loaded Base TextureFormat: TextureFormatUncompressed
[2026.10.27-21.00.19:791][  0]LogMeshReduction: Display: Using QuadricMeshReduction for automatic static mesh reduction
[2026.10.27-21.00.19:791][  0]LogMeshReduction: Display: Using SkeletalMeshReduction for automatic skeletal mesh reduction
[2026.10.27-21.00.19:791][  0]LogMeshReduction: Display: Using ProxyLODMeshReduction for automatic mesh merging
[2026.10.27-21.00.19:791][  0]LogMeshReduction: Display: No distributed automatic mesh merging module available
[2026.10.27-21.00.22:519][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.00.22:523][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 3.921 ms (total: 67.189 ms)
[2026.10.27-21.00.22:523][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.00.22:576][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 52.964 ms (total: 120.153 ms)
[2026.10.27-21.00.22:576][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\OMNI-UE\Scripts\apply_materials.py
=== JOB 140 DONE ===

```
