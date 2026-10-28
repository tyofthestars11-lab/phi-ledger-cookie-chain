# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 07:14:03 UTC

## STEP 1
```
=== MERGE EXECUTION STEP 1 - OMNIWORLD PORTS INTO THE MERGED BASE (Tyrees GO, 2026-10-28: Merge it. The merged base is D:\VEIL; OMNIWorld becomes the Omni District region of the one world. Job 340s manifest names the true map: D:\OMNI-UE\Content\Maps\OMNIWorld.umap at 448005 bytes, while D:\VEIL\Content\Maps already holds a stale OMNIWorld variant at 153774 bytes from the worldgen days. THIS JOB backs the stale variant up (nothing deleted), copies OMNIs true map into the base, and verifies the copy byte-for-byte by length in the same job. OMNI-UE itself is READ-ONLY here - the parent stands untouched. It also copies any OMNI external-actor/object folders for the Maps tree if they exist, and locates DT_Dialogue in both projects (path + bytes printed) so the voice-table port is written from a read, not a guess. NO BUILD in this job: the merged cook rides the systems-port job. Everything stays on D.) ===
PHI MERGE MAP SOURCE: D:\OMNI-UE\Content\Maps\OMNIWorld.umap bytes=448005
PHI MERGE MAP BACKUP: stale variant backed up as OMNIWorld.umap.phi-backup-343 bytes=153774
PHI MERGE MAP PORTED + VERIFIED: D:\VEIL\Content\Maps\OMNIWorld.umap bytes=448005
PHI MERGE EXT __ExternalActors__ : no OMNI Maps tree present
PHI MERGE EXT __ExternalObjects__ : no OMNI Maps tree present
PHI MERGE DT VEIL D:\VEIL\Content\Data\DT_Dialogue.uasset bytes=5908
PHI MERGE DT OMNI D:\OMNI-UE\Content\Data\DT_Dialogue.uasset bytes=5814
JOB 343 DONE

```
