<!-- PHI-DIRECT -->
```powershell
Write-Output '=== REGION SEATING 377 - OMNIWORLD TAKES ITS SEAT IN THE ONE WORLD, OR THE READ SAYS WHY NOT (Job 351 pulled the seating sources whole and its read stands: ADistrict carries StreamingLevelNames, the level names loaded while a district stands Near or Mid, and the district registers itself with the one Streaming Manager at BeginPlay - no travel code stands anywhere in the base, and job 343 verified OMNIWorld stands in the merged base as a map file, unseated as a region. THIS JOB, merged base at D:\VEIL-OMNI: one, print the source sections that carry StreamingLevelNames and every district and region configuration line across the Source tree. Two, print every ini line and every data asset name that names streaming levels or regions, and run a strings census over the map files for OMNIWorld. Three, print the verdict: OMNIWorld seated or OMNIWorld absent. Four, if it stands absent and the registration mechanism is unambiguous from the printed record - a source list, an ini list, or a data asset in list form - seat OMNIWorld in that same form with a backup first as .phi-backup-377, a counted edit, and read-back verification printed; if the mechanism cannot be determined from the printed source, print the streaming source whole as the reroute read and change nothing.) ==='
$base = 'D:\VEIL-OMNI'
$src = "$base\Source"
$omniSeen = $false
Write-Output '--- SECTION 1: SOURCE SECTIONS CARRYING StreamingLevelNames ---'
$streamMatches = Get-ChildItem $src -Recurse -Include '*.h','*.cpp' -File -ErrorAction SilentlyContinue | Select-String -Pattern 'StreamingLevelNames'
if (-not $streamMatches) { Write-Output 'PHI SEAT377 NO StreamingLevelNames LINE STANDS IN SOURCE' }
foreach ($f in ($streamMatches | Select-Object -ExpandProperty Path -Unique)) {
  Write-Output "FILE: $f"
  $flines = Get-Content $f
  foreach ($m in ($streamMatches | Where-Object { $_.Path -eq $f })) {
    $start = [Math]::Max(0, $m.LineNumber - 7)
    $end = [Math]::Min($flines.Count - 1, $m.LineNumber + 5)
    Write-Output ("... context for line " + $m.LineNumber + " ...")
    for ($i = $start; $i -le $end; $i++) { Write-Output $flines[$i] }
  }
}
Write-Output '--- SECTION 2: DISTRICT AND REGION CONFIGURATION LINES IN SOURCE ---'
$cfgLines = Get-ChildItem $src -Recurse -Include '*.h','*.cpp' -File -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNIWorld|RegisterDistrict|DistrictId|LoadStreamLevel|UnloadStreamLevel|StreamingManager|WorldBuilder|SpawnActor<'
foreach ($m in $cfgLines) { Write-Output ("{0}:{1}: {2}" -f $m.Path, $m.LineNumber, $m.Line.Trim()) }
if (($cfgLines | ForEach-Object { $_.Line }) -match 'OMNIWorld') { $omniSeen = $true; Write-Output 'PHI SEAT377 OMNIWorld NAMED IN SOURCE' }
Write-Output '--- SECTION 3: INI LINES NAMING STREAMING LEVELS OR REGIONS ---'
$iniHits = @()
Get-ChildItem "$base\Config" -Filter '*.ini' -File -ErrorAction SilentlyContinue | ForEach-Object {
  $iniFile = $_.FullName
  Select-String -Path $iniFile -Pattern 'OMNIWorld|StreamingLevel|District|Region' | ForEach-Object {
    Write-Output ("{0}:{1}: {2}" -f $iniFile, $_.LineNumber, $_.Line.Trim())
    $iniHits += [PSCustomObject]@{ File = $iniFile; LineNumber = $_.LineNumber; Text = $_.Line }
  }
}
if (($iniHits | ForEach-Object { $_.Text }) -match 'OMNIWorld') { $omniSeen = $true; Write-Output 'PHI SEAT377 OMNIWorld NAMED IN INI' }
Write-Output '--- SECTION 4: MAP FILES AND DISTRICT OR REGION DATA ASSETS ---'
$omniMaps = Get-ChildItem "$base\Content" -Recurse -Filter 'OMNIWorld.umap' -File -ErrorAction SilentlyContinue
foreach ($om in $omniMaps) { Write-Output ("PHI SEAT377 OMNIWorld MAP STANDS: " + $om.FullName + ' bytes=' + $om.Length) }
if (-not $omniMaps) { Write-Output 'PHI SEAT377 NO OMNIWorld.umap UNDER CONTENT' }
Get-ChildItem "$base\Content\Maps" -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ("MAP: " + $_.FullName) }
Get-ChildItem "$base\Content" -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'District|Region|Streaming' } | ForEach-Object { Write-Output ("ASSET NAME: " + $_.FullName) }
Write-Output '--- SECTION 5: MAP STRINGS CENSUS FOR OMNIWorld ---'
$mapOmni = $false
Get-ChildItem "$base\Content" -Recurse -Filter '*.umap' -File -ErrorAction SilentlyContinue | ForEach-Object {
  $txt = [System.Text.Encoding]::ASCII.GetString([System.IO.File]::ReadAllBytes($_.FullName))
  $hasOmni = $txt.Contains('OMNIWorld')
  $hasStream = $txt.Contains('StreamingLevelNames')
  Write-Output ("PHI SEAT377 MAPCENSUS " + $_.Name + " omniworld=" + $hasOmni + " streaminglevelnames=" + $hasStream)
  if ($hasOmni) { $mapOmni = $true }
}
if ($mapOmni) { $omniSeen = $true; Write-Output 'PHI SEAT377 OMNIWorld NAMED INSIDE A MAP FILE' }
Write-Output '--- SECTION 6: VERDICT AND SEAT ---'
if ($omniSeen) {
  Write-Output 'PHI SEAT377 VERDICT: OMNIWorld SEATED - named in the registration record printed above; no edit made.'
  Write-Output 'JOB 377 DONE'; return
}
Write-Output 'PHI SEAT377 VERDICT: OMNIWorld ABSENT from source lists, ini lines, data asset names and map strings.'
$streamIni = $iniHits | Where-Object { $_.Text -match 'StreamingLevel' }
$seatDone = $false
if ($streamIni) {
  $files = $streamIni | Select-Object -ExpandProperty File -Unique
  $keys = $streamIni | ForEach-Object { ($_.Text -split '=')[0].Trim() } | Sort-Object -Unique
  if ($files.Count -eq 1 -and $keys.Count -eq 1) {
    $target = $files[0]
    $keyText = $keys[0]
    $commaForm = $streamIni | Where-Object { $_.Text -match ',' }
    Copy-Item $target "$target.phi-backup-377" -Force
    Write-Output "INI BACKED UP (.phi-backup-377): $target"
    $before = Get-Content $target
    $countBefore = $before.Count
    if ($commaForm) {
      $ln = ($commaForm | Select-Object -First 1).LineNumber
      $before[$ln - 1] = $before[$ln - 1].TrimEnd() + ',OMNIWorld'
      Write-Output 'PHI SEAT377 SEAT FORM: comma list extended in place'
    } else {
      $insertAt = ($streamIni | Select-Object -Last 1).LineNumber
      $newLine = $keyText + '=OMNIWorld'
      $before = @($before[0..($insertAt - 1)]) + @($newLine) + @($before[$insertAt..($before.Count - 1)])
      Write-Output 'PHI SEAT377 SEAT FORM: sibling line added under the same key'
    }
    Set-Content $target -Value $before -Encoding UTF8
    $after = Get-Content $target
    Write-Output ("PHI SEAT377 LINE COUNT before=" + $countBefore + " after=" + $after.Count)
    $rb = Select-String -Path $target -Pattern 'OMNIWorld'
    foreach ($m in $rb) { Write-Output ("PHI SEAT377 READBACK {0}:{1}: {2}" -f $target, $m.LineNumber, $m.Line.Trim()) }
    if ($rb) { $seatDone = $true; Write-Output 'PHI SEAT377 OMNIWorld SEATED IN INI LIST FORM - VERIFIED BY READBACK' }
  } else {
    Write-Output 'PHI SEAT377 INI STREAMING LINES STAND IN MORE THAN ONE FILE OR KEY FORM - mechanism not unambiguous, no edit.'
  }
}
if (-not $seatDone) {
  Write-Output '--- REROUTE READ: THE STREAMING SOURCE WHOLE ---'
  foreach ($name in @('VEILDistrictStreaming.h', 'VEILDistrictStreaming.cpp')) {
    $sf = Get-ChildItem $src -Recurse -Filter $name -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
    if ($sf) { Write-Output "===== FILE $sf ====="; Get-Content $sf | Write-Output; Write-Output "===== END $sf =====" }
  }
  Write-Output 'PHI SEAT377 NO CHANGE - the registration mechanism does not stand in an unambiguous list form in the printed record.'
}
Write-Output 'PHI SEAT377 COMPILE: not required - no source file edited by this job.'
Write-Output 'JOB 377 DONE'
```
