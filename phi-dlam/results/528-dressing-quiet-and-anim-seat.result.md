# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 23:54:25 UTC

## STEP 1
```
=== JOB 528 - WHERE THE FIRST DRESSING WENT QUIET, AND HER ANIMATION SEAT (Ground: the first dressing launch exited its editor session without ever writing its page - the script went quiet somewhere inside itself and its prints ride the session logs. The glide question also still stands open: the animation class driving her in the standalone window has not printed yet. This job greps the project logs for the dressing tracebacks and dress lines, and for the body and animation lines that name her mesh and her animation seat. Both answers ride the same read. Every variable carries the p528 prefix.) ===
LOG VEIL.log at 10/28/2026 17:46:49
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:     a = unreal.EditorAssetLibrary.load_asset(p)
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error: RuntimeError: EditorAssetLibrary: /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump : Invalid USkeleton supplied
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:   RuntimeError: EditorAssetLibrary: /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump : Unable to initialize RigHierarchy due to missing USkeleton for (/Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump.MM_WallJump:AnimationSequencerDataModel)
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:     RuntimeError: EditorAssetLibrary: /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump : Unable to retrieve target USkeleton for Animation Asset (/Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump.MM_WallJump)
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:       RuntimeError: EditorAssetLibrary: /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump : Unable to initialize FKControlRig for AnimationSequencerDataModel for /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump.MM_WallJump, provided FKControlRig is invalid
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPython: Error:         RuntimeError: EditorAssetLibrary: /Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump : Unable to retrieve target USkeleton for Animation Asset (/Game/Mannequins/Anims/Unarmed/Jump/MM_WallJump.MM_WallJump)
D528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogPythonScriptCommandlet: Error: Python script executed with errors
D528 [2026.10.28-23.46.49:436][  0]LogPython: Display: Object '/EditorToolset/Python/editor_toolset/toolsets/blueprint_PY.ContainerType' was externally referenced when shutting down Python. Forcibly releasing its Python resources!
D528 [2026.10.28-23.46.49:436][  0]LogPython: Display: Object '/EditorToolset/Python/editor_toolset/toolsets/material_instance_PY.MaterialParameterType' was externally referenced when shutting down Python. Forcibly releasing its Python resources!
D528 [2026.10.28-23.46.49:436][  0]LogPython: Display: Object '/AnimationAssistantToolset/Python/animation_toolset/toolsets/controlrig_PY.EventType' was externally referenced when shutting down Python. Forcibly releasing its Python resources!
D528 [2026.10.28-23.46.49:436][  0]LogPython: Display: Object '/ControlRig/Python/RigHierarchy/add_controls_for_selected_PY.ControlOutputFormat' was externally referenced when shutting down Python. Forcibly releasing its Python resources!
A528 [2026.10.28-23.46.47:117][  0]LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
A528 [2026.10.28-23.46.47:117][  0]LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
A528 [2026.10.28-23.46.47:118][  0]LogUObjectBase: Warning: LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
A528 LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
A528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
A528 [2026.10.28-23.46.49:288][  0]LogInit: Display: LogUObjectBase: Warning: LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
LOG cef3.log at 10/28/2026 17:46:19
LOG VEIL-backup-2026.10.28-23.46.19.log at 10/28/2026 17:46:19
D528 [2026.10.28-23.42.56:448][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
D528 [2026.10.28-23.42.56:522][  0]LogPython: Error: Traceback (most recent call last):
D528 [2026.10.28-23.42.56:522][  0]LogPython: Error:   File "C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py", line 7, in <module>
D528 [2026.10.28-23.42.56:522][  0]LogPython: Error:     tests._toolset_registry_test_runner = unreal.PythonTestRunner.create(
D528 [2026.10.28-23.42.56:522][  0]LogPython: Error:                                           ^^^^^^^^^^^^^^^^^^^^^^^
D528 [2026.10.28-23.42.56:522][  0]LogPython: Error: AttributeError: module 'unreal' has no attribute 'PythonTestRunner'
D528 [2026.10.28-23.42.56:522][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 74.585 ms (total: 108.432 ms)
D528 [2026.10.28-23.42.56:523][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
D528 [2026.10.28-23.42.56:526][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 3.715 ms (total: 112.147 ms)
D528 [2026.10.28-23.42.56:526][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
D528 [2026.10.28-23.42.56:538][  0]LogPython: registering <class 'ControlRigWorkflows.workflow_deformation_rig_preset.provider'>
D528 [2026.10.28-23.42.56:543][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 16.895 ms (total: 129.043 ms)
A528 [2026.10.28-23.42.53:629][  0]LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
A528 [2026.10.28-23.42.53:629][  0]LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
A528 [2026.10.28-23.42.55:708][  0]LogVEIL: PHI BODY CHECK: mesh=SM_Countess anim=AnimSingleNodeInstance
PHI P528 VERDICT: PRINTED ABOVE
JOB 528 DONE

```
