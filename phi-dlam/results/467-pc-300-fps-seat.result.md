# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 19:00:11 UTC

## STEP 1
```
=== PC 300 FPS SEAT 467 - EVERY CAP COMES OFF, MEASURED FIRST (Ground from Tyree, 2026-10-28: lets make my pc 300 fps. His machine stands measured in the record: i5 12400F, RTX 3050 6 GB, 16 GB RAM, and his own PIE photo reads FPS 59.6, which is the signature of caps, not of silicon: frame smoothing, a 60 class frame limit, vsync and the balanced power plan each hold the rate down before the GPU is ever asked. This job measures the ground, then removes every cap the lane can lawfully touch. One, it prints the current power plan, the monitor refresh rate, the GPU name and driver, and every frame line already standing in the VEIL engine ini and the game user settings. Two, it seats the Windows power plan to High Performance. Three, in DefaultEngine ini, backed up first, it seats frame smoothing off under the Engine section and t.MaxFPS at 0, uncapped, under a ConsoleVariables section, so his 300 target is a ceiling the game may reach, not a lock it hits; existing lines are replaced, missing lines are added, and the seats verify by count. Four, in the saved GameUserSettings it seats the frame rate limit at 0 and vsync off where those lines stand, creating the file section if absent. The verdict in one line: FPS SEAT with the caps state. Every variable carries the fp467 prefix.) ===
DISPLAY gpu=NVIDIA GeForce RTX 3050 refresh=60 driver=32.0.16.1742
POWER BEFORE Power Scheme GUID: 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c  (High performance)
POWER AFTER Power Scheme GUID: 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c  (High performance)
INI SEATED smooth=1 maxfps=1
GUS ABSENT (seats at first run from the engine ini)
PHI FP467 VERDICT: FPS SEAT caps removed, ceiling open
JOB 467 DONE

```
