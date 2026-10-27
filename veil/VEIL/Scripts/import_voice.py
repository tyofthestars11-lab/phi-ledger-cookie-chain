# PHI voice import attempt - wav files from Data/Voice into
# /Game/Voice as SoundWaves. The verdict prints either way.
import unreal, os
SRC = r"D:\VEIL\Data\Voice"
DEST = "/Game/Voice"
tasks = []
if os.path.isdir(SRC):
    for fn in sorted(os.listdir(SRC)):
        if fn.lower().endswith(".wav"):
            t = unreal.AssetImportTask()
            t.set_editor_property("filename", os.path.join(SRC, fn))
            t.set_editor_property("destination_path", DEST)
            t.set_editor_property("automated", True)
            t.set_editor_property("save", True)
            tasks.append(t)
unreal.AssetToolsHelpers.get_asset_tools().import_asset_tasks(tasks)
n = 0
for t in tasks:
    for r in t.get_editor_property("imported_object_paths"):
        n += 1
        unreal.log("[VOICE] imported: %s" % r)
unreal.log("[VOICE] total imported: %d of %d" % (n, len(tasks)))
unreal.log("[VOICE] COMPLETE")
