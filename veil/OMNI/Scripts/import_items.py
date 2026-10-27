# PHI items import - run inside UnrealEditor-Cmd with PythonScriptPlugin.
# Creates /Game/Data/DT_Items from Data/items.csv (shipped in the
# project) using the FPHIItemRow struct, fills it from the CSV rows,
# and reports the row count. One source of truth: the CSV.
import unreal, csv, json, os

MODULE = "OMNI"
CSV_PATH = r"D:\OMNI-UE\Data\items.csv"
DEST = "/Game/Data"
NAME = "DT_Items"

rows = []
with open(CSV_PATH, newline="") as f:
    for r in csv.DictReader(f):
        rows.append({
            "Name": r["---"],
            "DisplayName": r["DisplayName"],
            "ItemType": r["ItemType"],
            "Damage": float(r["Damage"]),
            "Rarity": int(r["Rarity"]),
            "Value": int(r["Value"]),
        })
unreal.log("[ITEMS] csv rows read: %d" % len(rows))

if not unreal.EditorAssetLibrary.does_directory_exist(DEST):
    unreal.EditorAssetLibrary.make_directory(DEST)

dt_path = DEST + "/" + NAME
dt = unreal.EditorAssetLibrary.load_asset(dt_path)
if not dt:
    factory = unreal.DataTableFactory()
    struct = unreal.load_object(None, "/Script/%s.PHIItemRow" % MODULE)
    factory.set_editor_property("struct", struct)
    dt = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        NAME, DEST, unreal.DataTable, factory)
    unreal.log("[ITEMS] DT_Items created with row struct PHIItemRow")

ok = unreal.DataTableFunctionLibrary.fill_data_table_from_json_string(
    dt, json.dumps(rows))
names = unreal.DataTableFunctionLibrary.get_data_table_row_names(dt)
unreal.log("[ITEMS] fill ok=%s rows in table=%d" % (ok, len(names)))
unreal.EditorAssetLibrary.save_asset(dt_path)
unreal.log("[ITEMS] IMPORT COMPLETE")
