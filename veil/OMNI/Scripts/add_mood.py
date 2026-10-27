# PHI mood pass - run inside UnrealEditor-Cmd with PythonScriptPlugin.
# Adds one UNBOUND Post Process Volume per map: bloom, exposure, and a
# color grade per game. VEIL reads dusk (warm, deeper contrast); OMNI
# reads bright signal-day (cooler, lifted). Runs after the art pass.
import unreal

MAPS = ["/Game/Maps/OMNIWorld"]
GRADE = {'bloom': 0.45, 'exposure': 0.15, 'sat': 1.0, 'gain': (0.95, 1.0, 1.08)}

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
ews = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
for m in MAPS:
    if not les.load_level(m):
        unreal.log("[MOOD] LOAD FAILED: %s" % m)
        continue
    for actor in ews.get_all_level_actors():
        if actor.get_actor_label() == "PHIPostProcess":
            ews.destroy_actor(actor)
    ppv = ews.spawn_actor_from_class(unreal.PostProcessVolume, unreal.Vector(0, 0, 0))
    ppv.set_actor_label("PHIPostProcess")
    ppv.set_editor_property("unbound", True)
    s = ppv.get_editor_property("settings")
    s.set_editor_property("override_bloom_intensity", True)
    s.set_editor_property("bloom_intensity", GRADE["bloom"])
    s.set_editor_property("override_auto_exposure_bias", True)
    s.set_editor_property("auto_exposure_bias", GRADE["exposure"])
    s.set_editor_property("override_color_saturation", True)
    s.set_editor_property("color_saturation", unreal.Vector4(
        GRADE["sat"], GRADE["sat"], GRADE["sat"], 1.0))
    s.set_editor_property("override_color_gain", True)
    s.set_editor_property("color_gain", unreal.Vector4(
        GRADE["gain"][0], GRADE["gain"][1], GRADE["gain"][2], 1.0))
    ppv.set_editor_property("settings", s)
    les.save_current_level()
    unreal.log("[MOOD] %s: PHIPostProcess placed (bloom %.2f, exposure %.2f)" % (
        m, GRADE["bloom"], GRADE["exposure"]))
unreal.log("[MOOD] PASS COMPLETE")
