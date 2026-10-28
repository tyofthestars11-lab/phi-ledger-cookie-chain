# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 09:04:35 UTC

## STEP 1
```
=== DT DIALOGUE MERGE REROUTE 376 - THE TABLE COMES OUT OF THE ARCHIVE AND THE 37 ROWS STAND (Job 362 stopped at its export half: loading the OMNI-UE DT_Dialogue returned None, because job 358 and its KRAKEN pack had already packed that asset into D:\VEIL-OMNI-ARCHIVE - the table was never lost, it stands packed with its manifest proof. Job 355 printed the API census this merge rides: the DataTable carries export_to_json_string and fill_from_json_string natively, and both tables share the one struct PHIDialogueRow with fields Speaker and Line - VEIL rows V01 to V19 in the base, OMNI rows O01 to O18 in the parent. THIS JOB, one motion: one, find the packed DT_Dialogue inside the archive by filename search and by the KRAKEN manifest, and print what stands. Two, restore it to its original path under D:\OMNI-UE Content with the kraken tooling the lane shipped for job 358, copied never moved out of the archive, and print the restored byte count. Three, export the OMNI table in its own project and the base table in the merged base at D:\VEIL-OMNI through export_to_json_string, print both struct names and both row censuses, and stop before any write if either load fails or a struct name differs from PHIDialogueRow. Four, merge with VEIL rows kept and OMNI rows appended only where the row name stands absent, print any skip, fill the base table from the merged JSON, save the base asset, and print the full merged census with the total count - 37 rows is the shape of done.) ===
--- SECTION 1: LOCATE THE PACKED TABLE IN THE ARCHIVE ---
PHI DT376 ARCHIVE HIT: D:\VEIL-OMNI-ARCHIVE\OMNI-UE\Content\Data\DT_Dialogue.uasset.krk bytes=2363
PHI DT376 MANIFEST STANDS: D:\VEIL-OMNI-ARCHIVE\KRAKEN_MANIFEST.json
"path": "D:\\OMNI-UE\\Content\\Data\\DT_Dialogue.uasset",
"krk": "D:\\OMNI-UE\\Content\\Data\\DT_Dialogue.uasset.krk",
--- SECTION 2: RESTORE TO THE ORIGINAL PATH ---
KRAKEN TOOL: C:\Users\Admin\phi-vault\phi-dlam\tools\kraken_ton618.py
PYTHON: C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PHI KRAKEN DEPS OK
PHI DT376 RESTORED: D:/OMNI-UE/Content/Data/DT_Dialogue.uasset bytes=5814
PHI DT376 RESTORED BYTE COUNT: 5814
--- SECTION 3: EXPORT THE OMNI TABLE IN ITS OWN PROJECT ---
BASE DT BACKED UP (.phi-backup-376)
PHI DT376 OMNI LOAD NONE
PHI DT376 OMNI TABLE STILL UNREADABLE AFTER RESTORE
JOB 376 STOPPED

```
