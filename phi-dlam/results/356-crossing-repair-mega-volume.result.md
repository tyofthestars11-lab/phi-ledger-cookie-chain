# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 07:38:32 UTC

## STEP 1
```
=== CROSSING REPAIR - THE MEGA-VOLUME COMES OFF THE SPAWN COLUMN - MERGED BASE ONLY (Authored from job 347s per-tick prints, read whole. The shape, exact: at both redrop columns she first stands at floor contact - z=97.5, capsule bottom on the z=0 surface - with FindFloor naming StaticMeshActor_0 at floorDist=-42.0, embedded, refusing blocking and walkable; ONE tick later she is displaced downward in a single jump with no velocity behind it - 97.5 to -220.2 in VEIL DROP1, 97.5 to -220.3 in VEIL DROP2 - then falls clean under gravity. That is penetration ejection: the pawn lands INSIDE a volume and the movement solver pushes her out through its bottom. Job 347s column census names the volume: StaticMeshActor_0, bounds top=10085.1 base=-138.3, the one actor whose bounds contain BOTH test columns - a mega-volume standing over the spawn plaza and the slab column alike. The true ground (top exactly 0) stands underneath it. THIS JOB, merged base only: an editor commandlet censuses every static-mesh actor whose bounds contain the spawn column, prints mesh and collision for each, and sets collision to NO_COLLISION on exactly those matching the mega-volume criteria (bounds contain the column, top above 1000, base below 0), then saves the level. The map is backed up first. Then a full recook and the standalone proof: the v2 sampler still stands in the Character source, so the DROP prints themselves verify the repair - she holds at floor contact or walks, no one-tick jump. If no actor matches the criteria, the job stops before the cook with the census printed. OMNI-UE is not touched: the repair lands once, on the merged base.) ===
VEILDISTRICT BACKED UP (.phi-backup-356)
PHI CROSSFIX level loaded: /Game/Maps/VEILDistrict
NO MEGA-VOLUME MATCHED - no cook runs.
JOB 356 STOPPED BEFORE COOK

```
