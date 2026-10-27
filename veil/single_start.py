import unreal

# single_start: each world holds TWO PlayerStarts - the world builder's
# WorldStart near the sector-centre statue (256.67,-190,126.67) and the
# designed start at (420,-420,240) placed clear of it (job 124). Two
# starts make the spawn a coin the engine flips. This pass keeps the
# designed start as the ONLY start in both world maps and reports the
# before/after population. The district map is not touched.
MAPS = ["/Game/Maps/OMNIWorld", "/Game/Maps/VEILWorld"]
KEEP_AT = unreal.Vector(420.0, -420.0, 240.0)

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

for map_path in MAPS:
    if not unreal.EditorAssetLibrary.does_asset_exist(map_path):
        unreal.log(f"[START] {map_path}: absent in this project - skipped")
        continue
    les.load_level(map_path)
    starts = [a for a in eas.get_all_level_actors()
              if a.get_class().get_name() == "PlayerStart"]
    unreal.log(f"[START] {map_path}: {len(starts)} PlayerStarts before")
    for a in starts:
        unreal.log(f"[START] {map_path} {a.get_actor_label()} at {a.get_actor_location()}")
    keepers = [a for a in starts
               if a.get_actor_location().equals(KEEP_AT, 1.0)]
    removed = 0
    for a in starts:
        if keepers and a is keepers[0]:
            continue
        eas.destroy_actor(a)
        removed += 1
    left = [a for a in eas.get_all_level_actors()
            if a.get_class().get_name() == "PlayerStart"]
    unreal.log(f"[START] {map_path}: removed={removed} PlayerStarts after={len(left)}")
    les.save_current_level()
    unreal.log(f"[START] {map_path}: saved")
unreal.log("[START] COMPLETE")
