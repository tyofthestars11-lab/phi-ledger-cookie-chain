# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 21:42:53 UTC

## STEP 1
```
=== WHOLE JOB 742 - READ SEAT740 FULL AND SCRIPT HEAD (Ground: Job 741 read seat740 log, SEAT719 lines 6 metadata only, VAULT lines 0, COUNTESS lines 2 Rig warnings only, NAVMESH lines 0, SAVE lines 10 path matches only, DONE lines 0, GOLDEN PITCH lines 0, tail ends 21.11.50 with commandlet execution 0.23 seconds Success 0 errors 13 warnings, map 626984 unchanged. Even with unreal log, no SEAT719 prints stood. This job reads only: seat719 lines 40 to 80, the full seat740 out log line count and size, searches for LogPython Display, Error, Exception, Traceback, SEAT, the seat740 err log, and lists log files under Saved Logs written after 21.11.50. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
SCRIPT742 LOG AND MAIN HEAD
    try:
        return str(actor.get_class().get_path_name())
    except Exception:
        return ""


def find_actors(substring):
    found = []
    try:
        for actor in unreal.EditorLevelLibrary.get_all_level_actors():
            if substring in class_path_of(actor):
                found.append(actor)
    except Exception as exc:
        log("ACTOR LIST ERROR: " + str(exc))
    return found


def first_component(actor, comp_class):
    try:
        comps = actor.get_components_by_class(comp_class)
        if comps:
            return comps[0]
    except Exception:
        pass
    return None


def main():
    log("START")
    try:
        world = unreal.EditorLevelLibrary.get_editor_world()
        log("WORLD: " + str(world.get_path_name()))
    except Exception:
        log("WORLD UNREAD")
    before = unreal.EditorLevelLibrary.get_all_level_actors()
    log("ACTORS BEFORE: " + str(len(before)))
    if len(before) == 0:
        log("MAP NOT LOADED, STOP")
        return

    # Floor height: a Floor actor in the level, else 0, printed plainly.
    floor_z = 0.0
    floor_source = "UNREAD, USED 0"
    for actor in before:
        try:
SEAT742 OUT PRESENT True
SEAT742 OUT LINES 288 SIZE 39712
SEAT742 TERM LogPython: Display LINES 19
SEAT742 LINE [2026.10.30-21.11.49:605][  0]LogPython: Display: No pip-enabled plugins with python dependencies found, skipping
SEAT742 LINE [2026.10.30-21.11.50:235][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:300][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... took 64.221 ms
SEAT742 LINE [2026.10.30-21.11.50:300][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:305][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... took 4.905 ms (total: 69.126 ms)
SEAT742 LINE [2026.10.30-21.11.50:305][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:365][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... took 59.533 ms (total: 128.660 ms)
SEAT742 LINE [2026.10.30-21.11.50:365][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:370][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... took 5.711 ms (total: 134.372 ms)
SEAT742 LINE [2026.10.30-21.11.50:370][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:436][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... took 65.707 ms (total: 200.079 ms)
SEAT742 LINE [2026.10.30-21.11.50:436][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:440][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... took 3.920 ms (total: 204.000 ms)
SEAT742 LINE [2026.10.30-21.11.50:440][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:441][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 734 us (total: 204.734 ms)
SEAT742 LINE [2026.10.30-21.11.50:441][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:444][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 3.194 ms (total: 207.929 ms)
SEAT742 LINE [2026.10.30-21.11.50:444][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
SEAT742 LINE [2026.10.30-21.11.50:467][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 22.431 ms (total: 230.361 ms)
SEAT742 TERM Error LINES 3
SEAT742 LINE [2026.10.30-21.11.50:470][  0]LogInit: Display: Warning/Error Summary (Unique only)
SEAT742 LINE [2026.10.30-21.11.50:477][  0]LogInit: Display: Success - 0 error(s), 13 warning(s)
SEAT742 LINE LogLiveCodingServer: Error: Error 0xEA while reading from pipe. Size: 1, read: 1
SEAT742 TERM Exception LINES 0
SEAT742 TERM Traceback LINES 0
SEAT742 TERM SEAT719 LINES 6
SEAT742 LINE [2026.10.30-21.11.41:186][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL-OMNI\VEIL.uproject /Game/Maps/VEILDistrict -run=PythonScript -script=D:\VEIL-OMNI\Saved\seat719.py""
SEAT742 LINE [2026.10.30-21.11.50:467][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL-OMNI\Saved\seat719.py
SEAT742 LINE [2026.10.30-21.11.50:469][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT742 LINE [2026.10.30-21.11.50:469][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT742 LINE [2026.10.30-21.11.50:475][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT742 LINE [2026.10.30-21.11.50:476][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT742 ERR PRESENT True
SEAT742 ERR SIZE 0
CMD742 ID 76260 WS MB -1995
MAP742 SIZE 626984
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
