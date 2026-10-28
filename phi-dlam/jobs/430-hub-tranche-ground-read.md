<!-- PHI-DIRECT -->
```powershell
Write-Output '=== HUB TRANCHE GROUND READ 430 - THE WORLD BUILDER AND QUEST CONTENT SOURCE READ WHOLE IN LINES, SO THE HUB BUILD IS AUTHORED FROM THE STANDING CODE (Ground from job 427, read whole: the merged project at D colon VEIL-OMNI holds 3 maps, OMNIWorld at 448005 bytes, VEILWorld at 442566 bytes, and VEILDistrict at 101328 bytes; the quest system source stands as OMNIQuestSystem and OMNIQuestContent in Source VEIL Private and Public; the Warden stands as OMNIWardenPrime; region mentions in source printed Hub 0, Nest 0, Spire 2, Omni District 0, Megastructure 0, and the stated rule named NEXT TRANCHE Hub. The region names live in the bible and not yet in the code, so the Hub build enters through the standing builder: the class that builds the district at runtime. One, the job lists every file under Source VEIL Private World and Source VEIL Public World with name and size, so the builder ground is measured. Two, the job finds the builder files, any World or District or Builder named source file, and prints the lines in them that carry Spawn, District, Region, Tower, Plaza, or Beacon, with the file and line number on each, capped at 120 printed lines, so the build shape prints in the code own lines. Three, the job reads the quest content ground: the lines of OMNIQuestContent cpp that carry a quoted quest name or a quest call, capped at 60 printed lines, plus the count of those lines, so the Hub quest entries are authored against the standing quest shape. Four, the verdict in one line: HUB GROUND READ with the world file count, the builder line count, and the quest line count. This job is read only: nothing is written, moved, or launched, and every variable carries the hub430 prefix under the standing ban on automatic variable names.) ==='
$hub430Root = 'D:\VEIL-OMNI'
$hub430PrivWorld = Join-Path $hub430Root 'Source\VEIL\Private\World'
$hub430PubWorld = Join-Path $hub430Root 'Source\VEIL\Public\World'
$hub430Source = Join-Path $hub430Root 'Source\VEIL'
Write-Output '--- SECTION 1: WORLD SOURCE FILES ---'
$hub430WorldFiles = @()
foreach ($hub430Dir in @($hub430PrivWorld, $hub430PubWorld)) {
  Write-Output ("DIR CHECK: " + $hub430Dir + " exists=" + (Test-Path $hub430Dir))
  if (Test-Path $hub430Dir) {
    $hub430InDir = @(Get-ChildItem $hub430Dir -File -ErrorAction SilentlyContinue)
    foreach ($hub430F in $hub430InDir) { Write-Output ("WORLD FILE: " + $hub430F.Name + " bytes=" + $hub430F.Length); $hub430WorldFiles += $hub430F }
  }
}
Write-Output ("WORLD FILE COUNT=" + $hub430WorldFiles.Count)
Write-Output '--- SECTION 2: BUILDER LINES ---'
$hub430BuilderFiles = @($hub430WorldFiles | Where-Object { ($_.Name -like '*World*') -or ($_.Name -like '*District*') -or ($_.Name -like '*Builder*') })
Write-Output ("BUILDER FILE COUNT=" + $hub430BuilderFiles.Count)
$hub430BuilderLines = 0
$hub430Printed = 0
foreach ($hub430Bf in $hub430BuilderFiles) {
  if ($hub430Bf.Extension -eq '.cpp' -or $hub430Bf.Extension -eq '.h') {
    $hub430Matches = @(Select-String -Path $hub430Bf.FullName -Pattern 'Spawn|District|Region|Tower|Plaza|Beacon' -ErrorAction SilentlyContinue)
    $hub430BuilderLines += $hub430Matches.Count
    Write-Output ("BUILDER FILE: " + $hub430Bf.Name + " match_lines=" + $hub430Matches.Count)
    foreach ($hub430M in $hub430Matches) {
      if ($hub430Printed -lt 120) { Write-Output ("BL " + $hub430Bf.Name + " " + $hub430M.LineNumber + ": " + $hub430M.Line.Trim()); $hub430Printed += 1 }
    }
  }
}
Write-Output ("BUILDER LINE COUNT=" + $hub430BuilderLines)
Write-Output '--- SECTION 3: QUEST CONTENT LINES ---'
$hub430QuestCpp = Join-Path $hub430PrivWorld 'OMNIQuestContent.cpp'
$hub430QuestLines = 0
if (Test-Path $hub430QuestCpp) {
  $hub430QMatches = @(Select-String -Path $hub430QuestCpp -Pattern 'Quest' -ErrorAction SilentlyContinue)
  $hub430QuestLines = $hub430QMatches.Count
  Write-Output ("QUEST CONTENT FILE: " + $hub430QuestCpp + " quest_lines=" + $hub430QuestLines)
  $hub430QPrinted = 0
  foreach ($hub430Qm in $hub430QMatches) {
    if ($hub430QPrinted -lt 60) { Write-Output ("QL " + $hub430Qm.LineNumber + ": " + $hub430Qm.Line.Trim()); $hub430QPrinted += 1 }
  }
} else {
  Write-Output 'QUEST CONTENT CPP ABSENT AT THE 427 PATH'
}
Write-Output '--- SECTION 4: VERDICT ---'
Write-Output ("PHI HUB430 VERDICT: HUB GROUND READ world_files=" + $hub430WorldFiles.Count + " builder_lines=" + $hub430BuilderLines + " quest_lines=" + $hub430QuestLines)
Write-Output 'JOB 430 DONE'
```
