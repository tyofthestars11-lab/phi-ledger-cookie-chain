# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 10:43:20 UTC

## STEP 1
```
=== KRAKEN ARCHIVE COMPLETION READ 403 - THE PACK, THREE HOURS ON (Job 358 launched the parent archive pack detached on this PC - driver pid 5684, script kraken_archive_driver.py, log at D:\VEIL-OMNI-ARCHIVE\pack358.log and manifest at D:\VEIL-OMNI-ARCHIVE\KRAKEN_MANIFEST.json - and job 378 read it still running: 12087 entries, all verified, bytes in 24226504444, bytes krk 3261478835, ratio 0.1346, with D:\OMNI-UE and both Builds trees still standing. THIS JOB IS READ-ONLY and changes nothing: one, print whether the pack driver still stands, with pid and start time. Two, print the last 25 lines of the pack log. Three, print the manifest summary - entries, packed, kept raw, verified, bytes in, bytes krk, and the ratio computed from those two byte counts to four decimals. Four, census the parent trees - D:\OMNI-UE, D:\VEIL if it stands, and the Builds trees job 378 named - each STANDING with its file count and byte total, or ABSENT. Five, print the verdict in one line: PACK DONE when the log carries its completion print and the driver no longer stands, or PACK STILL RUNNING with the last log line as the evidence.) ===
--- SECTION 1: DRIVER PROCESS ---
PHI PACK403 DRIVER PID5684 NOT STANDING
PHI PACK403 NO PROCESS CARRIES THE PACK SCRIPT NAME
--- SECTION 2: PACK LOG TAIL ---
PHI PACK403 LOG STANDS: D:\VEIL-OMNI-ARCHIVE\pack358.log bytes=8310 lastwrite=2026-10-28 04:14:44
02:23:38 PHI KRAKEN PROGRESS OMNI-UE: files=10900 packed=9317
02:28:15 PHI KRAKEN PROGRESS OMNI-UE: files=11000 packed=9414
02:28:48 PHI KRAKEN PROGRESS OMNI-UE: files=11100 packed=9449
02:29:20 PHI KRAKEN PROGRESS OMNI-UE: files=11200 packed=9549
02:31:02 PHI KRAKEN PROGRESS OMNI-UE: files=11300 packed=9628
02:32:18 PHI KRAKEN PROGRESS OMNI-UE: files=11400 packed=9703
02:32:44 PHI KRAKEN PROGRESS OMNI-UE: files=11500 packed=9769
02:33:12 PHI KRAKEN PROGRESS OMNI-UE: files=11600 packed=9864
02:33:45 PHI KRAKEN PROGRESS OMNI-UE: files=11700 packed=9963
02:34:13 PHI KRAKEN PROGRESS OMNI-UE: files=11800 packed=10006
02:34:41 PHI KRAKEN PROGRESS OMNI-UE: files=11900 packed=10072
02:35:11 PHI KRAKEN PROGRESS OMNI-UE: files=12000 packed=10161
03:21:38 PHI KRAKEN PROGRESS OMNI-UE: files=12100 packed=10227
03:22:14 PHI KRAKEN PROGRESS OMNI-UE: files=12200 packed=10326
03:24:10 PHI KRAKEN PROGRESS OMNI-UE: files=12300 packed=10411
03:24:39 PHI KRAKEN PROGRESS OMNI-UE: files=12400 packed=10461
03:25:04 PHI KRAKEN PROGRESS OMNI-UE: files=12500 packed=10461
03:27:41 PHI KRAKEN PROGRESS OMNI-UE: files=12600 packed=10537
03:29:44 PHI KRAKEN PROGRESS OMNI-UE: files=12700 packed=10632
03:45:14 PHI KRAKEN PROGRESS OMNI-UE: files=12800 packed=10701
03:45:41 PHI KRAKEN ROOT DONE: OMNI-UE
04:00:30 PHI KRAKEN ROOT DONE: BUILDS-VEIL
04:14:44 PHI KRAKEN ROOT DONE: BUILDS-OMNI
04:14:44 PHI KRAKEN BACKUPS DONE: files=0
04:14:44 PHI KRAKEN ARCHIVE DRIVER DONE: {"packed": 10891, "kept_raw": 2151, "errors": 0, "bytes_in": 32961638595, "bytes_krk": 24037024796}
--- SECTION 3: MANIFEST SUMMARY ---
PHI PACK403 MANIFEST entries=13042 packed=10891 kept_raw=2151 verified=13042
PHI PACK403 MANIFEST BYTES in=32961638595 krk=7174965001
PHI PACK403 MANIFEST RATIO krk_over_in=0.2177
--- SECTION 4: PARENT TREE CENSUS ---
PHI PACK403 TREE D:\OMNI-UE state=STANDING files=6 bytes=55624
PHI PACK403 TREE D:\VEIL state=ABSENT
PHI PACK403 TREE D:\Builds\VEIL state=STANDING files=0 bytes=
PHI PACK403 TREE D:\Builds\OMNI state=STANDING files=0 bytes=
--- SECTION 5: VERDICT ---
PHI PACK403 VERDICT: PACK DONE
JOB 403 DONE

```
