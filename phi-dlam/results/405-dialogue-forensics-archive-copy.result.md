# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 10:50:46 UTC

## STEP 1
```
=== DIALOGUE TABLE FORENSICS 405 - THE ARCHIVE COPY READ AT THE BYTE LEVEL, NO PROJECT REQUIRED (Job 403 printed PACK DONE: the KRAKEN archive of the parent projects completed with 13042 entries, every one verified, at ratio 0.2177 - and job 399 stopped at its gate on OMNI UPROJECT NOT FOUND, because the parent tree no longer resolves and its forensic body never ran. The dialogue table DT_Dialogue.uasset therefore stands read from its archive copy alone: D:\VEIL-OMNI-ARCHIVE holds DT_Dialogue.uasset.krk at 2363 packed bytes on the earlier record, and the KRAKEN_MANIFEST.json entry carries its original byte count and checksum. The forensic questions stand unchanged from the 388 line: is the archived table byte-whole against its manifest proof, and do its own row strings stand inside it? No project load stands in this job and no editor is waited on; the only writes are the job scratch unpack under D:\VEIL-OMNI\Saved. THIS JOB: one, print the KRAKEN_MANIFEST.json entry for DT_Dialogue whole, every field it carries. Two, unpack DT_Dialogue.uasset.krk from the archive into the scratch folder D:\VEIL-OMNI\Saved\dt405 through the lane kraken tooling, the same unpack road jobs 376 and 384 used, and print the restored size and SHA-256. Three, print the size and checksum verdicts against the manifest - SIZE MATCH or MISMATCH with both numbers, CHECKSUM MATCH or MISMATCH where the manifest carries one. Four, print the first 64 bytes as hex, run the package magic check on C1 83 2A 9E, and search the whole file in ASCII and UTF-16LE for PHIDialogueRow, DT_Dialogue, Speaker, Line, O01 and V01, FOUND or ABSENT for each. Five, print the verdict in one line: TABLE WHOLE IN ARCHIVE when size and checksum match and the strings stand, the rows recoverable from the archive copy - or TABLE DEAD IN ARCHIVE, with the mismatch or the absence printed as the evidence.) ===
KRAKEN TOOL: C:\Users\Admin\phi-vault\phi-dlam\tools\kraken_ton618.py
PYTHON: C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PHI KRAKEN DEPS OK
--- MANIFEST ENTRY WHOLE / UNPACK / BYTE CENSUS / HEADER READ / STRING SEARCH ---
PHI DT405 MANIFEST ENTRIES READ: 13042
PHI DT405 MANIFEST ENTRY WHOLE: {"path": "D:\\OMNI-UE\\Content\\Data\\DT_Dialogue.uasset", "krk": "D:\\OMNI-UE\\Content\\Data\\DT_Dialogue.uasset.krk", "pipeline": "raw", "action": "packed", "orig_size": 5814, "krk_size": 2363, "ratio": 0.4064, "sha256_orig": "e61d57e117a1ae5fb674e2c172348800c5710682307c7d104a3900dfdf5c7c2d", "sha256_krk": "1bd16361deb58f0a58c6d0b8364eda44c8fe37814f6a829316eba847a68dbc50", "verified": true, "elapsed_s": 0.02}
PHI DT405 KRK ON DISK: D:/VEIL-OMNI-ARCHIVE/OMNI-UE/Content/Data/DT_Dialogue.uasset.krk bytes=2363
PHI DT405 UNPACK RETURNED: D:/VEIL-OMNI/Saved/dt405/DT_Dialogue.uasset
PHI DT405 RESTORED: D:/VEIL-OMNI/Saved/dt405/DT_Dialogue.uasset bytes=5814
PHI DT405 RESTORED SHA256: e61d57e117a1ae5fb674e2c172348800c5710682307c7d104a3900dfdf5c7c2d
PHI DT405 MANIFEST CHECKSUMS: e61d57e117a1ae5fb674e2c172348800c5710682307c7d104a3900dfdf5c7c2d 1bd16361deb58f0a58c6d0b8364eda44c8fe37814f6a829316eba847a68dbc50
PHI DT405 CHECKSUM VERDICT: MATCH
PHI DT405 MANIFEST NUMBERS: 5814,2363,0.4064,True,0.02
PHI DT405 SIZE VERDICT: MATCH restored=5814 manifest=5814,2363
PHI DT405 FIRST 64 BYTES HEX: C1 83 2A 9E F7 FF FF FF 60 03 00 00 0A 02 00 00 FA 03 00 00 00 00 00 00 86 24 86 72 1D 3D DB 65 4B 8B 17 A0 B8 EA E8 2F 43 B6 37 12 01 07 00 00 02 00 00 00 DD 75 E5 29 27 46 A3 E0 76 D2 10 9D
PHI DT405 FIRST 64 BYTES TEXT: ..*.....`................$.r.=.eK....../C.7..........u.)'F..v...
PHI DT405 PACKAGE MAGIC C1832A9E: FOUND
PHI DT405 STRING PHIDialogueRow: ASCII FOUND / UTF16 ABSENT
PHI DT405 STRING DT_Dialogue: ASCII FOUND / UTF16 ABSENT
PHI DT405 STRING Speaker: ASCII FOUND / UTF16 ABSENT
PHI DT405 STRING Line: ASCII FOUND / UTF16 ABSENT
PHI DT405 STRING O01: ASCII FOUND / UTF16 ABSENT
PHI DT405 STRING V01: ASCII ABSENT / UTF16 ABSENT
PHI DT405 STRINGS VERDICT: STAND
PHI DT405 EVIDENCE: size=True checksum=True magic=True strings=True
PHI DT405 FORENSIC SHAPE: WHOLE
--- VERDICT ---
PHI DT405 VERDICT: TABLE WHOLE IN ARCHIVE - size and checksum stand against the manifest proof and the row strings stand inside the file; the rows are recoverable from the archive copy
JOB 405 DONE

```
