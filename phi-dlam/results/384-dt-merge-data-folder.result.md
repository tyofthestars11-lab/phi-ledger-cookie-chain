# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 09:30:30 UTC

## STEP 1
```
=== DT MERGE 384 - THE WHOLE DATA FOLDER ROAD (Job 380 stands as the record: the archive manifest carries the table itself at D:\OMNI-UE\Content\Data\DT_Dialogue.uasset, no PHIDialogue-named struct asset surfaced anywhere, and the OMNI table load returned None inside both projects - a table whose supporting files stand packed in the same folder cannot load alone. THIS JOB: one, print every archive manifest entry whose original path sits under D:\OMNI-UE\Content\Data\, with its path, its packed form and its bytes. Two, restore all of them into D:\OMNI-UE at their original paths through the kraken tooling, copied never moved, any standing target backed up as .phi-backup-384, restored bytes printed per file, so the table and everything the Data folder holds stand together in their own project. Three, in the OMNI-UE project, load DT_Dialogue, print its row struct name, export through export_to_json_string and print the row census; if the load still returns None, print that verdict and stop. Four, in the merged base at D VEIL-OMNI, back the base table file up as .phi-backup-384 first, load and export the base table, merge with base rows kept and OMNI rows appended only where absent, skips printed, fill through fill_from_json_string, save, re-export and print the full merged census with the total - 37 rows is the shape of done.) ===
MERGED BASE PROJECT: D:\VEIL-OMNI\VEIL.uproject
OMNI PROJECT: 
--- SECTION 1: KRAKEN TOOLING ---
KRAKEN TOOL: C:\Users\Admin\phi-vault\phi-dlam\tools\kraken_ton618.py
PYTHON: C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PHI KRAKEN DEPS OK
--- SECTION 2: MANIFEST DATA ENTRIES + RESTORE INTO OMNI-UE ---
PHI DT384 MANIFEST ENTRIES READ: 12708
PHI DT384 MANIFEST DATA ENTRY: D:\OMNI-UE\Content\Data\DT_Dialogue.uasset | D:\OMNI-UE\Content\Data\DT_Dialogue.uasset.krk | raw | packed | e61d57e117a1ae5fb674e2c172348800c5710682307c7d104a3900dfdf5c7c2d | 1bd16361deb58f0a58c6d0b8364eda44c8fe37814f6a829316eba847a68dbc50 | numbers=5814,2363,0.4064,True,0.02
PHI DT384 MANIFEST DATA ENTRY: D:\OMNI-UE\Content\Data\DT_Items.uasset | D:\OMNI-UE\Content\Data\DT_Items.uasset.krk | raw | packed | c2f25b03d8c4b129de6f139dc72bcea51e834d212e83ac7a935fe4d8bba0a5fb | 03e66642cf57a239a8a1954a8d084deff6a1f366c626574fc2f1f30011c12532 | numbers=6777,1871,0.2761,True,0.02
PHI DT384 DATA TARGETS: 2
PHI DT384 TARGET BACKED UP (.phi-backup-384): D:/OMNI-UE/Content/Data/DT_Dialogue.uasset
PHI DT384 RESTORED: D:/OMNI-UE/Content/Data/DT_Dialogue.uasset bytes=5814
PHI DT384 RESTORED: D:/OMNI-UE/Content/Data/DT_Items.uasset bytes=6777
PHI DT384 RESTORED COUNT: 2
PHI DT384 RESTORE COMPLETE
--- SECTION 3: OMNI TABLE EXPORT IN THE OMNI-UE PROJECT ---
PHI DT384 OMNI LOAD NONE
PHI DT384 VERDICT: OMNI TABLE STILL UNREADABLE IN ITS OWN PROJECT AFTER THE WHOLE DATA FOLDER RESTORE
JOB 384 STOPPED

```
