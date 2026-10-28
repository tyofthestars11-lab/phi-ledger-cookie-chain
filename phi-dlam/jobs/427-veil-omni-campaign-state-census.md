<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VEIL OMNI CAMPAIGN STATE CENSUS 427 - WHAT CAMPAIGN CONTENT ACTUALLY STANDS IN THE MERGED PROJECT, READ BY FILESYSTEM AND SOURCE SO THE NEXT BUILD TRANCHE IS AUTHORED FROM MEASURED STATE (Ground: the merge execution order named campaign Acts one to five content built region by region as the remaining motion after the crossing repair. Ground from job 349: the OMNI quest and Warden systems port compiled into the merged base at D colon VEIL-OMNI. Ground from job 402: no map holds a placed District actor; the district builds at runtime through the WorldBuilder. Ground from job 409: the merged dialogue table DT_Dialogue stands at 37 rows, V01 to V19 plus O01 to O18, fresh load verified. Ground from job 413: StreamingLevelNames stands written in source at COUNT 2, the OMNIWorld and VEILWorld maps. Ground from job 425: the Countess grey thread closed cosmetic and the skeleton stands untouched. One, the census lists every umap under Content Maps with name and size, so the map ground of each region is measured, not assumed. Two, the census counts and names the campaign system files: every file under Source and Content whose name carries Quest, Warden, Dialogue, Faction, or Statue, printed as counts per family with the file names following. Three, the census counts source mentions of each region name, Hub, Nest, Spire, Omni District, and Megastructure, across the cpp and h files under Source, one count per region, so region presence in the standing code is measured per region. Four, the next tranche is named by a fixed rule stated here before the read: the region with the lowest mention count is the next build tranche target, and ties break in bible order Hub then Nest then Spire then Omni District then Megastructure. Five, the verdict in one line: CAMPAIGN STATE READ with the map count, the quest family count, and the region counts, plus NEXT TRANCHE with the region the rule names. This job is read only: nothing is written, moved, or launched, and every variable carries the cen427 prefix under the standing ban on automatic variable names.) ==='
$cen427Root = 'D:\VEIL-OMNI'
$cen427MapsDir = Join-Path $cen427Root 'Content\Maps'
$cen427SourceDir = Join-Path $cen427Root 'Source'
$cen427ContentDir = Join-Path $cen427Root 'Content'
Write-Output '--- SECTION 1: MAPS ON DISK ---'
$cen427MapCount = 0
if (Test-Path $cen427MapsDir) {
  $cen427Maps = @(Get-ChildItem $cen427MapsDir -Filter *.umap -File -ErrorAction SilentlyContinue)
  $cen427MapCount = $cen427Maps.Count
  foreach ($cen427Map in $cen427Maps) { Write-Output ("MAP: " + $cen427Map.Name + " bytes=" + $cen427Map.Length) }
} else {
  Write-Output 'MAPS DIR ABSENT'
}
Write-Output ("MAP COUNT=" + $cen427MapCount)
Write-Output '--- SECTION 2: CAMPAIGN SYSTEM FILES BY FAMILY ---'
$cen427Families = @('Quest', 'Warden', 'Dialogue', 'Faction', 'Statue')
$cen427QuestCount = 0
foreach ($cen427Family in $cen427Families) {
  $cen427Found = @()
  if (Test-Path $cen427SourceDir) { $cen427Found += @(Get-ChildItem $cen427SourceDir -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -like ('*' + $cen427Family + '*') }) }
  if (Test-Path $cen427ContentDir) { $cen427Found += @(Get-ChildItem $cen427ContentDir -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -like ('*' + $cen427Family + '*') }) }
  Write-Output ("FAMILY " + $cen427Family + " COUNT=" + $cen427Found.Count)
  foreach ($cen427File in $cen427Found) { Write-Output ("FILE " + $cen427Family + ": " + $cen427File.FullName) }
  if ($cen427Family -eq 'Quest') { $cen427QuestCount = $cen427Found.Count }
}
Write-Output '--- SECTION 3: REGION MENTIONS IN SOURCE ---'
$cen427Regions = @('Hub', 'Nest', 'Spire', 'Omni District', 'Megastructure')
$cen427SourceFiles = @()
if (Test-Path $cen427SourceDir) { $cen427SourceFiles = @(Get-ChildItem $cen427SourceDir -Recurse -File -Include *.cpp, *.h -ErrorAction SilentlyContinue) }
Write-Output ("SOURCE FILE COUNT=" + $cen427SourceFiles.Count)
$cen427Counts = @{}
foreach ($cen427Region in $cen427Regions) {
  $cen427Hits = 0
  foreach ($cen427Sf in $cen427SourceFiles) {
    $cen427FoundLines = @(Select-String -Path $cen427Sf.FullName -Pattern $cen427Region -SimpleMatch -ErrorAction SilentlyContinue)
    $cen427Hits += $cen427FoundLines.Count
  }
  $cen427Counts[$cen427Region] = $cen427Hits
  Write-Output ("REGION " + $cen427Region + " MENTIONS=" + $cen427Hits)
}
Write-Output '--- SECTION 4: NEXT TRANCHE BY THE STATED RULE ---'
$cen427Next = $cen427Regions[0]
foreach ($cen427Region in $cen427Regions) {
  if ($cen427Counts[$cen427Region] -lt $cen427Counts[$cen427Next]) { $cen427Next = $cen427Region }
}
Write-Output ("NEXT TRANCHE REGION: " + $cen427Next)
Write-Output '--- SECTION 5: VERDICT ---'
Write-Output ("PHI CEN427 VERDICT: CAMPAIGN STATE READ maps=" + $cen427MapCount + " quest_family=" + $cen427QuestCount + " hub=" + $cen427Counts['Hub'] + " nest=" + $cen427Counts['Nest'] + " spire=" + $cen427Counts['Spire'] + " omni=" + $cen427Counts['Omni District'] + " mega=" + $cen427Counts['Megastructure'] + " NEXT TRANCHE=" + $cen427Next)
Write-Output 'JOB 427 DONE'
```
