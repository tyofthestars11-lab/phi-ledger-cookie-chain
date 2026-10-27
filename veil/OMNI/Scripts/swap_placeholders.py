# swap_placeholders.py - mass placeholder swap.
# Source: Google AI's script, carried by Tyree 2026-10-27; kept and
# hardened. Report mode by default: it lists the level's actor label
# families and changes NOTHING. Fill SWAPS with verbatim asset paths
# from DLAM job 082's inventory and set ARMED = True to swap for real.
import unreal

SWAPS = {
    # "Tower": "/Game/Characters/...",  # label substring -> real asset path
}
ARMED = False

def mass_replace_placeholders(placeholder_substring, target_asset_path):
    editor_actor_subs = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    all_actors = editor_actor_subs.get_all_level_actors()
    real_asset = unreal.EditorAssetLibrary.load_asset(target_asset_path)
    if not real_asset:
        unreal.log_error("[SWAP] could not find asset at: " + target_asset_path)
        return
    replaced = 0
    for actor in list(all_actors):
        if placeholder_substring.lower() in actor.get_actor_label().lower():
            loc = actor.get_actor_location()
            rot = actor.get_actor_rotation()
            scale = actor.get_actor_scale_3d()
            new_actor = editor_actor_subs.spawn_actor_from_asset(real_asset, loc, rot)
            new_actor.set_actor_scale_3d(scale)
            editor_actor_subs.destroy_actor(actor)
            replaced += 1
    unreal.log("[SWAP] replaced %d placeholders with %s" % (replaced, target_asset_path))

def main():
    subs = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    families = {}
    for a in subs.get_all_level_actors():
        lab = a.get_actor_label()
        key = lab.rsplit("_", 1)[0] if "_" in lab else lab
        families[key] = families.get(key, 0) + 1
    unreal.log("[SWAP] level actor families: %s" % families)
    if not ARMED or not SWAPS:
        unreal.log("[SWAP] report mode - nothing changed")
        return
    for sub, path in SWAPS.items():
        mass_replace_placeholders(sub, path)

main()
