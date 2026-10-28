<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MERGE EXECUTION STEP 1 - OMNIWORLD PORTS INTO THE MERGED BASE (Tyrees GO, 2026-10-28: Merge it. The merged base is D:\VEIL; OMNIWorld becomes the Omni District region of the one world. Job 340s manifest names the true map: D:\OMNI-UE\Content\Maps\OMNIWorld.umap at 448005 bytes, while D:\VEIL\Content\Maps already holds a stale OMNIWorld variant at 153774 bytes from the worldgen days. THIS JOB backs the stale variant up (nothing deleted), copies OMNIs true map into the base, and verifies the copy byte-for-byte by length in the same job. OMNI-UE itself is READ-ONLY here - the parent stands untouched. It also copies any OMNI external-actor/object folders for the Maps tree if they exist, and locates DT_Dialogue in both projects (path + bytes printed) so the voice-table port is written from a read, not a guess. NO BUILD in this job: the merged cook rides the systems-port job. Everything stays on D.) ==='
$srcMap = 'D:\OMNI-UE\Content\Maps\OMNIWorld.umap'
$dstMap = 'D:\VEIL\Content\Maps\OMNIWorld.umap'
if (-not (Test-Path $srcMap)) { Write-Output 'SOURCE MAP MISSING - port stops.'; Write-Output 'JOB 343 STOPPED'; return }
$srcLen = (Get-Item $srcMap).Length
"PHI MERGE MAP SOURCE: $srcMap bytes=$srcLen" | Write-Output
if (Test-Path $dstMap) { Copy-Item $dstMap "$dstMap.phi-backup-343" -Force; "PHI MERGE MAP BACKUP: stale variant backed up as OMNIWorld.umap.phi-backup-343 bytes=$((Get-Item $dstMap).Length)" | Write-Output }
Copy-Item $srcMap $dstMap -Force
$dstLen = (Get-Item $dstMap).Length
if ($dstLen -eq $srcLen) { Write-Output "PHI MERGE MAP PORTED + VERIFIED: $dstMap bytes=$dstLen" } else { Write-Output "PHI MERGE MAP COPY MISMATCH: dst=$dstLen src=$srcLen"; Write-Output 'JOB 343 STOPPED'; return }
foreach ($tree in @('__ExternalActors__','__ExternalObjects__')) {
  $s = "D:\OMNI-UE\Content\$tree\Game\Maps"; $d = "D:\VEIL\Content\$tree\Game\Maps"
  if (Test-Path $s) { $n = (Get-ChildItem $s -Recurse -File -ErrorAction SilentlyContinue).Count; New-Item -ItemType Directory -Path $d -Force | Out-Null; Copy-Item "$s\*" $d -Recurse -Force; Write-Output "PHI MERGE EXT $tree : copied $n files from OMNI Maps tree" } else { Write-Output "PHI MERGE EXT $tree : no OMNI Maps tree present" }
}
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  Get-ChildItem $g[1] -Recurse -Filter 'DT_Dialogue*' -File -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ("PHI MERGE DT " + $g[0] + " " + $_.FullName + " bytes=" + $_.Length) }
}
Write-Output 'JOB 343 DONE'
```
