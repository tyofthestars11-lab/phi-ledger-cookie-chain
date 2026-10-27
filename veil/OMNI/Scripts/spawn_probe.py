# PHI spawn probe (OMNI): where the player start stands vs the ground.
import unreal
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
les.load_level("/Game/Maps/OMNIWorld")
world = unreal.EditorLevelLibrary.get_editor_world()
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
for a in eas.get_all_level_actors():
    lbl = a.get_actor_label()
    if isinstance(a, unreal.PlayerStart):
        unreal.log("[SPAWN] PlayerStart at %s" % a.get_actor_location())
    low = lbl.lower()
    if any(k in low for k in ("slab", "foundation", "island", "ground")):
        o, e = a.get_actor_bounds(False)
        unreal.log("[GROUND] %s loc=%s bounds origin=%s extent=%s" % (lbl, a.get_actor_location(), o, e))
unreal.log("[SPAWN] COMPLETE")
