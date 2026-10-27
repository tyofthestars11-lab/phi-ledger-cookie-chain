# PHI dialogue import - creates /Game/Data/DT_Dialogue from
# Data/dialogue.csv via the FPHIDialogueRow struct. Same road as items.
import unreal, csv, json

MODULE = "OMNI"
CSV_PATH = r"D:\OMNI-UE\Data\dialogue.csv"
DEST = "/Game/Data"
NAME = "DT_Dialogue"

rows = []
with open(CSV_PATH, newline="") as f:
    for r in csv.DictReader(f):
        rows.append({"Name": r["---"], "Speaker": r["Speaker"],
                     "Line": r["Line"], "VoiceFile": r["VoiceFile"]})
unreal.log("[DIALOGUE] csv rows read: %d" % len(rows))

if not unreal.EditorAssetLibrary.does_directory_exist(DEST):
    unreal.EditorAssetLibrary.make_directory(DEST)
dt_path = DEST + "/" + NAME
dt = unreal.EditorAssetLibrary.load_asset(dt_path)
if not dt:
    factory = unreal.DataTableFactory()
    struct = unreal.load_object(None, "/Script/%s.PHIDialogueRow" % MODULE)
    factory.set_editor_property("struct", struct)
    dt = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        NAME, DEST, unreal.DataTable, factory)
    unreal.log("[DIALOGUE] DT_Dialogue created with row struct PHIDialogueRow")
ok = unreal.DataTableFunctionLibrary.fill_data_table_from_json_string(
    dt, json.dumps(rows))
names = unreal.DataTableFunctionLibrary.get_data_table_row_names(dt)
unreal.EditorAssetLibrary.save_asset(dt_path)
unreal.log("[DIALOGUE] fill ok=%s rows in table=%d" % (ok, len(names)))
unreal.log("[DIALOGUE] COMPLETE")
