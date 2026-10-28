<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WORLDBUILDER SOURCE PULL - NAME THE MEGA-VOLUME AT ITS SPAWN SITE (Job 356 stopped clean: its editor commandlet censused the placed VEILDistrict map and NO static-mesh actor there contains the spawn column - the repair was aimed at the wrong venue, and the prints prove it. Job 347s census was a RUNTIME census: the district is built at runtime by AVEILWorldBuilder (job 351s read: the builder actor builds the playable district from engine primitives at runtime - ground, phi-scaled tower grid, plaza, beacon spire - and the GameMode spawns it and calls BuildWorld before anything else). StaticMeshActor_0 of the runtime census - loc (0,0,-50), bounds top=10085.1 base=-138.3, the volume she lands inside and gets ejected through - is a builder-spawned actor, and the repair belongs in the builders spawn math, not in the placed map. THIS JOB pulls the builder source whole from the merged base (now D:\VEIL-OMNI): VEILWorldBuilder.cpp and .h printed entire, plus the GameMode builder-spawn section, so the repair job is authored against the exact spawn code. Read-only; nothing is edited.) ==='
$src = 'D:\VEIL-OMNI\Source\VEIL'
Get-ChildItem $src -Recurse -Filter 'VEILWorldBuilder.*' -File | ForEach-Object { Write-Output ("BUILDER FILE: " + $_.FullName + " bytes=" + $_.Length) }
foreach ($f in @("$src\World\VEILWorldBuilder.h", "$src\World\VEILWorldBuilder.cpp", "$src\VEILWorldBuilder.h", "$src\VEILWorldBuilder.cpp")) {
  if (Test-Path $f) { Write-Output ("===== $f ====="); Get-Content $f | Write-Output }
}
$gm = Get-ChildItem $src -Recurse -Filter 'VEILGameMode.cpp' -File | Select-Object -First 1 -ExpandProperty FullName
if ($gm) { Write-Output "===== $gm (builder spawn section) ====="; Select-String -Path $gm -Pattern 'WorldBuilder|BuildWorld|SpawnActor' -Context 3,3 | ForEach-Object { $_.Context.PreContext + $_.Line + $_.Context.PostContext + '---' } | Write-Output }
Write-Output 'JOB 361 DONE'
```
