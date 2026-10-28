# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 12:41:43 UTC

## STEP 1
```
=== RIG CLASS SEAT 414 - THE IKRIG PLUGIN ENTRY THE RETARGET ASSET NEEDS, ENABLED AND VERIFIED, THEN THE LOAD TEST (Job 412 stands as the record: the Countess skeletal mesh at /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess carries sixteen material slots and all sixteen stand with real materials, so the grey render is not a material absence; the named defect left standing is the retarget asset /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget, whose load fails in the editor own words - Unable to load Paragon_Proto_Retarget because its class (Rig) does not exist. The Rig class belongs to the IKRig plugin family, and a class that does not exist in the project means its plugin entry is absent or disabled in the project file. This job reads VEIL.uproject whole and prints its Plugins section verbatim with the IKRig entry named FOUND with its Enabled value or ABSENT; if absent it backs the file up to VEIL.uproject.phi-backup-414 and adds the IKRig entry Enabled true in the same JSON shape the file already uses, then reads the section back in print; the editor target compiles on the proven Build.bat road, and on a compile failure after the write the project file restores from the backup; last, a commandlet loads the retarget asset and the job prints RIG CLASS SEATED with the loaded class named, or RIG STILL MISSING with the load words.) ===
PHI RIG414 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: PROJECT FILE READ - PLUGINS SECTION AND THE IKRIG ENTRY ---
PHI RIG414 UPROJECT CHARS: 1780
PHI RIG414 PLUGINS SECTION VERBATIM:
[
                    {
                        "Enabled":  true,
                        "Name":  "EnhancedInput"
                    },
                    {
                        "Name":  "PythonScriptPlugin",
                        "Enabled":  true
                    },
                    {
                        "Name":  "EditorScriptingUtilities",
                        "Enabled":  true
                    },
                    {
                        "Name":  "GeometryScripting",
                        "Enabled":  true
                    },
                    {
                        "Name":  "ModelingToolsEditorMode",
                        "Enabled":  true
                    },
                    {
                        "Name":  "PCG",
                        "Enabled":  true
                    },
                    {
                        "Name":  "AllToolsets",
                        "Enabled":  true
                    },
                    {
                        "Name":  "PCGToolset",
                        "Enabled":  true
                    },
                    {
                        "Name":  "ModelContextProtocol",
                        "Enabled":  true
                    }
                ]
PHI RIG414 IKRIG ENTRY: ABSENT FROM THE PLUGINS LIST
--- SECTION 2: THE SEATING WRITE ---
PHI RIG414 BACKUP WRITTEN: D:\VEIL-OMNI\VEIL.uproject.phi-backup-414
PHI RIG414 EDIT SHAPE: NEW ENTRY INSERTED IN THE SHAPE OF THE FIRST STANDING ENTRY
PHI RIG414 WRITE DONE - READ BACK FOLLOWS
PHI RIG414 PLUGINS SECTION AFTER WRITE:
[
                    {
                        "Enabled": true,
                        "Name": "IKRig"
                    },
                    {
                        "Enabled":  true,
                        "Name":  "EnhancedInput"
                    },
                    {
                        "Name":  "PythonScriptPlugin",
                        "Enabled":  true
                    },
                    {
                        "Name":  "EditorScriptingUtilities",
                        "Enabled":  true
                    },
                    {
                        "Name":  "GeometryScripting",
                        "Enabled":  true
                    },
                    {
                        "Name":  "ModelingToolsEditorMode",
                        "Enabled":  true
                    },
                    {
                        "Name":  "PCG",
                        "Enabled":  true
                    },
                    {
                        "Name":  "AllToolsets",
                        "Enabled":  true
                    },
                    {
                        "Name":  "PCGToolset",
                        "Enabled":  true
                    },
                    {
                        "Name":  "ModelContextProtocol",
                        "Enabled":  true
                    }
                ]
PHI RIG414 IKRIG ENTRY AFTER WRITE: FOUND Enabled=True
--- SECTION 3: COMPILE THE EDITOR TARGET ---
PHI RIG414 BUILD SUCCEEDED
--- SECTION 4: RETARGET LOAD TEST ---
PHI RIG414 RETARGET LOAD NONE
PHI RIG414 COMPLETE
--- RETARGET LOAD LOG LINES ---
[2026.10.28-12.41.56:030][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.28-12.41.56:033][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 2.846 ms (total: 194.720 ms)
[2026.10.28-12.41.56:033][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.28-12.41.56:050][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 17.143 ms (total: 211.863 ms)
[2026.10.28-12.41.56:050][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL-OMNI\Saved\phi_rig414.py
[2026.10.28-12.41.56:051][  0]LogEditorAssetSubsystem: Error: LoadAsset failed: The asset '/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget.Paragon_Proto_Retarget' exists but was not able to be loaded.
[2026.10.28-12.41.56:051][  0]LogUObjectGlobals: Warning: Failed to find object 'Object /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget'
[2026.10.28-12.41.56:051][  0]LogInit: Display: LogEditorAssetSubsystem: Error: LoadAsset failed: The asset '/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget.Paragon_Proto_Retarget' exists but was not able to be loaded.
[2026.10.28-12.41.56:051][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.28-12.41.56:051][  0]LogInit: Display: LogUObjectGlobals: Warning: Failed to find object 'Object /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget'
--- SECTION 5: VERDICT ---
PHI RIG414 VERDICT: RIG STILL MISSING - the retarget load words stand in the log lines above
JOB 414 DONE

```
