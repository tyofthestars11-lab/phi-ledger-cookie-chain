# whole_verify_goal.py
# VEIL OMNI - whole verify + save + Play, inside Unreal Editor 5.8 ONLY.
# DO NOT run this with system Python: `import unreal` exists only inside the editor.
# Run method (see notes at bottom): already-open editor, Output Log in Python mode,
# or Tools > Execute Python Script, or Output Log Cmd: py "D:\VEIL-OMNI\Tools\whole_verify_goal.py"
# DO NOT use -ExecutePythonScript for the Play step: that mode shuts the editor down
# when the script finishes, so a PIE request from that script is not a durable Play session.
#
# Prerequisites, from public 5.8 editor-scripting sources:
# - Python Editor Script Plugin enabled for this project, plus Editor Scripting Utilities, editor restarted.
# - Map already open, or load step below succeeds. No package / cook step is in this script.
#
# Targets - copied verbatim from the parent task, NOT re-derived here:
#   Map:     /Game/Maps/VEILDistrict
#   Vault:   0, 0, -80.9
#   Countess: 809, -309, 64.7, SINGLE - more than 1 Countess match is a FAIL, not a pass
#   RUNNER:  0, 0, 100
#   Floor 1618: no Floor actor name/location was given in this task, so it is NOT checked
#     as an actor here. Do not invent a Floor actor check.
#
# API verdicts (research, not PC proof):
#   CORRECT (supported in 5.8 examples):
#     unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
#     actor_subsystem.get_all_level_actors()  -- instance method, on the subsystem instance
#     actor.get_actor_label()  -- Outliner name, preferred over get_name()
#     actor.get_actor_location()  -- returns a Vector with .x / .y / .z
#   CORRECT CANDIDATE FOR PLAY (not the old, wrong call):
#     unreal.get_editor_subsystem(unreal.LevelEditorSubsystem).editor_request_begin_play()
#     Reported Dec 2024 and used in PIE-capture code with an is_in_play_in_editor() guard.
#   WRONG - DO NOT USE:
#     LevelEditorSubsystem.enter_play_mode()  -- no such method was found; this was invented.
#     EditorLevelLibrary.editor_play_simulate() / editor_play_simulate() as "Play"
#       -- that is Simulate, not Play-in-Editor, and must not be reported as Play.
#     Calling a subsystem method on the class, e.g. unreal.LevelEditorSubsystem().editor_play_simulate()
#       -- forum error: "descriptor needs an argument". Always use get_editor_subsystem().
#   UNCERTAIN - NEEDS PC EDITOR TEST, script tries them in order and logs which worked:
#     [LOAD] LevelEditorSubsystem.load_level(MAP)  -- seen in UE5 MCP/editor scripts.
#     [LOAD fallback] unreal.EditorLoadingAndSavingUtils.load_map(MAP)
#       -- C++ signature is LoadMap(Filename); the Python wrapper's exact return/args
#       were NOT confirmed against the Epic 5.8 reference (that domain was blocked for
#       direct fetch in this research). Treat as fallback only.
#     [SAVE] unreal.EditorLoadingAndSavingUtils.save_map(world, MAP)
#       -- C++ signature is SaveMap(UWorld*, Filename); a third-party Python wrapper
#       calls save_map(world, asset_path) the same way. World is obtained from
#       UnrealEditorSubsystem.get_editor_world(). NOT confirmed in Epic 5.8 reference.
#     [SAVE fallback] LevelEditorSubsystem.save_all_dirty_levels()
#       -- seen in UE5 editor scripts; its exact 5.8 Python name/return were NOT
#       confirmed in the Epic reference. Treat as fallback only.
#     [PLAY guard] LevelEditorSubsystem.is_in_play_in_editor()
#       -- seen in PIE-capture code; NOT confirmed in the Epic 5.8 reference.
#   PLAY TIMING WARNING:
#     A report on EditorRequestBeginPlay says execution after the PIE request may
#     not run until PIE ends. Therefore this script writes the seat log BEFORE Play,
#     and Play is strictly the LAST step. Nothing after Play is relied on.

import time
import unreal

MAP = "/Game/Maps/VEILDistrict"
SEAT = r"D:\VEIL-OMNI\seat719_out.txt"

VAULT_TARGET = (0.0, 0.0, -80.9)
COUNTESS_TARGET = (809.0, -309.0, 64.7)
RUNNER_TARGET = (0.0, 0.0, 100.0)
TOL = 0.1  # Unreal float rounding: 0.1 units, stated explicitly, not exact string equality


def vec_tuple(loc):
    return (float(loc.x), float(loc.y), float(loc.z))


def matches(loc, target):
    v = vec_tuple(loc)
    return all(abs(v[i] - target[i]) <= TOL for i in range(3))


def main():
    lines = []
    lines.append("WHOLE_VERIFY_GOAL start map=%s" % MAP)

    # ---- 1. Load map (try documented UE5 subsystem first, then the older util) ----
    load_ok = False
    load_used = "none"
    try:
        level_sub = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
        level_sub.load_level(MAP)
        load_ok, load_used = True, "LevelEditorSubsystem.load_level"
    except Exception as e:
        lines.append("LOAD load_level failed: %r" % (e,))
        try:
            unreal.EditorLoadingAndSavingUtils.load_map(MAP)
            load_ok, load_used = True, "EditorLoadingAndSavingUtils.load_map [UNCERTAIN - PC test]"
        except Exception as e2:
            lines.append("LOAD load_map failed: %r" % (e2,))
    lines.append("LOAD ok=%s used=%s" % (load_ok, load_used))

    # ---- 2. Collect actors ----
    actor_sub = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    actors = actor_sub.get_all_level_actors()
    vaults = []
    countesses = []
    runners = []
    for a in actors:
        try:
            label = a.get_actor_label()
            loc = a.get_actor_location()
        except Exception:
            continue
        upper = label.upper()
        if "VAULT" in upper:
            vaults.append((label, vec_tuple(loc), matches(loc, VAULT_TARGET)))
        if "COUNTESS" in upper:
            countesses.append((label, vec_tuple(loc), matches(loc, COUNTESS_TARGET)))
        if "RUNNER" in upper:
            runners.append((label, vec_tuple(loc), matches(loc, RUNNER_TARGET)))

    for label, loc, ok in vaults:
        lines.append("VAULT %s %s target=%s match=%s" % (label, loc, VAULT_TARGET, ok))
    for label, loc, ok in countesses:
        lines.append("COUNTESS %s %s target=%s match=%s" % (label, loc, COUNTESS_TARGET, ok))
    for label, loc, ok in runners:
        lines.append("RUNNER %s %s target=%s match=%s" % (label, loc, RUNNER_TARGET, ok))

    vault_pass = len(vaults) >= 1 and all(ok for _, _, ok in vaults)
    # Countess: exactly one, and it must match. Double Countess = FAIL, even if one matches.
    countess_pass = len(countesses) == 1 and countesses[0][2]
    runner_pass = len(runners) >= 1 and all(ok for _, _, ok in runners)
    verify_pass = bool(load_ok and vault_pass and countess_pass and runner_pass)
    lines.append("VERIFY vault=%s count=%d countess=%s count=%d runner=%s count=%d PASS=%s" % (
        vault_pass, len(vaults), countess_pass, len(countesses), runner_pass, len(runners), verify_pass))

    # ---- 3. Save map (verify-only for locations: this script does NOT move actors) ----
    save_ok = False
    save_used = "none"
    try:
        editor_sub = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem)
        world = editor_sub.get_editor_world()
        result = unreal.EditorLoadingAndSavingUtils.save_map(world, MAP)
        save_ok, save_used = bool(result), "EditorLoadingAndSavingUtils.save_map(world, MAP) [UNCERTAIN - PC test]"
    except Exception as e:
        lines.append("SAVE save_map failed: %r" % (e,))
        try:
            level_sub2 = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
            level_sub2.save_all_dirty_levels()
            save_ok, save_used = True, "LevelEditorSubsystem.save_all_dirty_levels() [UNCERTAIN - PC test, return not confirmed]"
        except Exception as e2:
            lines.append("SAVE save_all_dirty_levels failed: %r" % (e2,))
    lines.append("SAVE ok=%s used=%s" % (save_ok, save_used))
    # Do NOT write "SAVE RESULT True" unless save_ok is True from a call above.
    lines.append("SAVE RESULT %s" % ("True" if save_ok else "False"))

    # ---- 4. Seat log BEFORE Play (Play may suspend further script execution) ----
    seat_text = "\n".join(lines) + "\nWHOLE %s VAULT 0,0,-80.9 COUNTESS 809,-309,64.7 RUNNER 0,0,100 VERIFY_PASS=%s SAVE=%s PLAY_REQUESTED_NEXT\n" % (
        time.time(), verify_pass, save_ok)
    try:
        with open(SEAT, "a", encoding="utf-8") as f:
            f.write(seat_text)
        lines.append("SEAT written %s" % SEAT)
    except Exception as e:
        lines.append("SEAT write failed: %r" % (e,))
    for line in lines:
        unreal.log(line)

    # ---- 5. Play - LAST step only ----
    try:
        les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
        already = None
        try:
            already = les.is_in_play_in_editor()
        except Exception:
            already = None  # guard name unconfirmed in 5.8 reference; do not fail Play on it
        if already:
            unreal.log("PLAY already in PIE, not requesting again")
        else:
            les.editor_request_begin_play()
            unreal.log("PLAY requested via LevelEditorSubsystem.editor_request_begin_play()")
    except Exception as e:
        unreal.log_error("PLAY editor_request_begin_play failed: %r" % (e,))
        # Do NOT claim Play succeeded. The editor photo / PIE state on the PC is the proof,
        # and it has NOT been verified in this research.


main()
