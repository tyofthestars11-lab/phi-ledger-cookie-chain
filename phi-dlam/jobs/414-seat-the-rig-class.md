<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RIG CLASS SEAT 414 - THE IKRIG PLUGIN ENTRY THE RETARGET ASSET NEEDS, ENABLED AND VERIFIED, THEN THE LOAD TEST (Job 412 stands as the record: the Countess skeletal mesh at /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess carries sixteen material slots and all sixteen stand with real materials, so the grey render is not a material absence; the named defect left standing is the retarget asset /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget, whose load fails in the editor own words - Unable to load Paragon_Proto_Retarget because its class (Rig) does not exist. The Rig class belongs to the IKRig plugin family, and a class that does not exist in the project means its plugin entry is absent or disabled in the project file. This job reads VEIL.uproject whole and prints its Plugins section verbatim with the IKRig entry named FOUND with its Enabled value or ABSENT; if absent it backs the file up to VEIL.uproject.phi-backup-414 and adds the IKRig entry Enabled true in the same JSON shape the file already uses, then reads the section back in print; the editor target compiles on the proven Build.bat road, and on a compile failure after the write the project file restores from the backup; last, a commandlet loads the retarget asset and the job prints RIG CLASS SEATED with the loaded class named, or RIG STILL MISSING with the load words.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 10) { Start-Sleep -Seconds 10; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI RIG414 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no write and no commandlet launched into the contention'; Write-Output 'JOB 414 STOPPED'; return }
Write-Output 'PHI RIG414 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
function Get-PluginsSection {
  param([string]$Text)
  $pIdx = $Text.IndexOf('"Plugins"')
  if ($pIdx -lt 0) { return $null }
  $aStart = $Text.IndexOf('[', $pIdx)
  if ($aStart -lt 0) { return $null }
  $depth = 0; $inStr = $false; $esc = $false; $aEnd = -1
  for ($i = $aStart; $i -lt $Text.Length; $i++) {
    $c = $Text[$i]
    if ($esc) { $esc = $false; continue }
    if ($inStr -and $c -eq '\') { $esc = $true; continue }
    if ($c -eq '"') { $inStr = -not $inStr; continue }
    if ($inStr) { continue }
    if ($c -eq '[') { $depth++ }
    elseif ($c -eq ']') { $depth--; if ($depth -eq 0) { $aEnd = $i; break } }
  }
  if ($aEnd -lt 0) { return $null }
  return @{ Start = $aStart; End = $aEnd; Text = $Text.Substring($aStart, $aEnd - $aStart + 1) }
}
function Get-ObjectSpans {
  param([string]$Text, [int]$From, [int]$To)
  $spans = @()
  $depth = 0; $inStr = $false; $esc = $false; $oStart = -1
  for ($i = $From; $i -le $To; $i++) {
    $c = $Text[$i]
    if ($esc) { $esc = $false; continue }
    if ($inStr -and $c -eq '\') { $esc = $true; continue }
    if ($c -eq '"') { $inStr = -not $inStr; continue }
    if ($inStr) { continue }
    if ($c -eq '{') { if ($depth -eq 0) { $oStart = $i }; $depth++ }
    elseif ($c -eq '}') { $depth--; if ($depth -eq 0 -and $oStart -ge 0) { $spans += , @($oStart, $i); $oStart = -1 } }
  }
  return $spans
}
Write-Output '--- SECTION 1: PROJECT FILE READ - PLUGINS SECTION AND THE IKRIG ENTRY ---'
$raw = Get-Content $uproj -Raw
Write-Output ('PHI RIG414 UPROJECT CHARS: ' + $raw.Length)
$section = Get-PluginsSection $raw
if ($section) { Write-Output 'PHI RIG414 PLUGINS SECTION VERBATIM:'; Write-Output $section.Text } else { Write-Output 'PHI RIG414 PLUGINS SECTION: NONE FOUND IN THE PROJECT FILE' }
$ikState = 'unknown'
$ikEnabled = ''
try {
  $projObj = $raw | ConvertFrom-Json
  $ikEntry = $null
  if ($projObj.Plugins) { foreach ($pl in $projObj.Plugins) { if ($pl.Name -eq 'IKRig') { $ikEntry = $pl } } }
  if ($ikEntry) { $ikState = 'present'; $ikEnabled = [string]$ikEntry.Enabled }
  elseif ($section) { $ikState = 'absent' }
  else { $ikState = 'no-plugins' }
} catch { $ikState = 'parse-failed'; Write-Output ('PHI RIG414 UPROJECT PARSE ERROR: ' + $_.Exception.Message) }
if ($ikState -eq 'present') { Write-Output ('PHI RIG414 IKRIG ENTRY: FOUND Enabled=' + $ikEnabled) }
elseif ($ikState -eq 'absent') { Write-Output 'PHI RIG414 IKRIG ENTRY: ABSENT FROM THE PLUGINS LIST' }
elseif ($ikState -eq 'no-plugins') { Write-Output 'PHI RIG414 IKRIG ENTRY: ABSENT - THE PROJECT FILE CARRIES NO PLUGINS SECTION' }
else { Write-Output 'PHI RIG414 IKRIG ENTRY: STATE UNRESOLVED - THE PROJECT FILE DID NOT PARSE' }
Write-Output '--- SECTION 2: THE SEATING WRITE ---'
$wrotePlugin = $false
$backupPath = "$uproj.phi-backup-414"
if ($ikState -eq 'present' -and $ikEnabled -eq 'True') {
  Write-Output 'PHI RIG414 PLUGIN ALREADY ENABLED - no write made'
}
elseif ($ikState -eq 'parse-failed') {
  Write-Output 'PHI RIG414 WRITE HELD: THE PROJECT FILE DID NOT PARSE - no hand edit made against an unread file'
}
else {
  Copy-Item $uproj $backupPath -Force
  Write-Output ('PHI RIG414 BACKUP WRITTEN: ' + $backupPath)
  $newRaw = $null
  if ($ikState -eq 'present') {
    $spans = @(Get-ObjectSpans $raw $section.Start $section.End)
    $targetSpan = $null
    foreach ($sp in $spans) { $spanText = $raw.Substring($sp[0], $sp[1] - $sp[0] + 1); if ($spanText -match '"IKRig"') { $targetSpan = $sp; break } }
    if ($targetSpan) {
      $spanText = $raw.Substring($targetSpan[0], $targetSpan[1] - $targetSpan[0] + 1)
      $flipped = [regex]::Replace($spanText, '"Enabled"\s*:\s*false', '"Enabled": true')
      if ($flipped -eq $spanText) { $trimmed = $spanText.TrimEnd(); $flipped = $trimmed.Substring(0, $trimmed.Length - 1) + ', "Enabled": true }' }
      $newRaw = $raw.Substring(0, $targetSpan[0]) + $flipped + $raw.Substring($targetSpan[1] + 1)
      Write-Output 'PHI RIG414 EDIT SHAPE: THE STANDING ENTRY FLIPPED TO ENABLED TRUE'
    } else { Write-Output 'PHI RIG414 EDIT HELD: THE IKRIG OBJECT SPAN WAS NOT FOUND IN THE PLUGINS TEXT' }
  }
  elseif ($ikState -eq 'absent') {
    $spans = @(Get-ObjectSpans $raw $section.Start $section.End)
    if ($spans.Count -gt 0) {
      $fs = $spans[0][0]; $fe = $spans[0][1]
      $template = $raw.Substring($fs, $fe - $fs + 1)
      $entry = [regex]::Replace($template, '"Name"\s*:\s*"[^"]*"', '"Name": "IKRig"')
      if ($entry -match '"Enabled"\s*:') { $entry = [regex]::Replace($entry, '"Enabled"\s*:\s*(true|false)', '"Enabled": true') }
      else { $trimmedE = $entry.TrimEnd(); $entry = $trimmedE.Substring(0, $trimmedE.Length - 1) + ', "Enabled": true }' }
      $sep = $raw.Substring($section.Start + 1, $fs - $section.Start - 1)
      $newRaw = $raw.Substring(0, $section.Start + 1) + $sep + $entry + ',' + $raw.Substring($section.Start + 1)
      Write-Output 'PHI RIG414 EDIT SHAPE: NEW ENTRY INSERTED IN THE SHAPE OF THE FIRST STANDING ENTRY'
    } else {
      $entry = '{ "Name": "IKRig", "Enabled": true }'
      $newRaw = $raw.Substring(0, $section.Start + 1) + $entry + $raw.Substring($section.Start + 1)
      Write-Output 'PHI RIG414 EDIT SHAPE: NEW ENTRY INSERTED INTO THE EMPTY PLUGINS LIST'
    }
  }
  else {
    $nl = [Environment]::NewLine
    $lastBrace = $raw.LastIndexOf('}')
    $pluginsBlock = ',' + $nl + "`t" + '"Plugins": [' + $nl + "`t`t" + '{ "Name": "IKRig", "Enabled": true }' + $nl + "`t" + ']'
    $newRaw = $raw.Substring(0, $lastBrace) + $pluginsBlock + $nl + $raw.Substring($lastBrace)
    Write-Output 'PHI RIG414 EDIT SHAPE: A PLUGINS SECTION ADDED TO THE PROJECT FILE'
  }
  if ($newRaw) {
    $valid = $true
    try { $null = $newRaw | ConvertFrom-Json } catch { $valid = $false; Write-Output ('PHI RIG414 WRITE HELD: THE EDITED TEXT DOES NOT PARSE - ' + $_.Exception.Message) }
    if ($valid) {
      Set-Content $uproj -Value $newRaw -Encoding UTF8 -NoNewline
      $wrotePlugin = $true
      Write-Output 'PHI RIG414 WRITE DONE - READ BACK FOLLOWS'
      $rawBack = Get-Content $uproj -Raw
      $sectionBack = Get-PluginsSection $rawBack
      if ($sectionBack) { Write-Output 'PHI RIG414 PLUGINS SECTION AFTER WRITE:'; Write-Output $sectionBack.Text }
      $projBack = $rawBack | ConvertFrom-Json
      $ikBack = $null
      if ($projBack.Plugins) { foreach ($pl in $projBack.Plugins) { if ($pl.Name -eq 'IKRig') { $ikBack = $pl } } }
      if ($ikBack) { Write-Output ('PHI RIG414 IKRIG ENTRY AFTER WRITE: FOUND Enabled=' + [string]$ikBack.Enabled) } else { Write-Output 'PHI RIG414 IKRIG ENTRY AFTER WRITE: STILL ABSENT - THE WRITE DID NOT LAND' }
    }
  }
}
Write-Output '--- SECTION 3: COMPILE THE EDITOR TARGET ---'
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
& $buildbat VEILEditor Win64 Development -Project="$uproj" -WaitMutex -NoHotReload *> "$base\Saved\build414.log"
$buildCode = $LASTEXITCODE
$buildFailed = $false
if ($buildCode -ne 0) {
  $buildFailed = $true
  Write-Output ('PHI RIG414 BUILD FAILED code=' + $buildCode)
  Select-String -Path "$base\Saved\build414.log" -Pattern 'error|Error|FAILED' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
} else { Write-Output 'PHI RIG414 BUILD SUCCEEDED' }
if ($buildFailed -and $wrotePlugin) {
  Copy-Item $backupPath $uproj -Force
  Write-Output 'PHI RIG414 UPROJECT RESTORED FROM BACKUP AFTER THE COMPILE FAILURE'
  Write-Output 'PHI RIG414 VERDICT: RIG STILL MISSING - the compile failed with the plugin entry written, so the project file stands restored and the seat is unproven'
  Write-Output 'JOB 414 DONE'
  return
}
Write-Output '--- SECTION 4: RETARGET LOAD TEST ---'
$pyP = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpQQVRIID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvUGFyYWdvbl9Qcm90b19SZXRhcmdldCcKb2JqID0gTm9uZQp0cnk6CiAgICBvYmogPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LmxvYWRfYXNzZXQoUEFUSCkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIFJJRzQxNCBMT0FEIEVSUk9SOiAnICsgc3RyKGUpKQppZiBvYmogaXMgTm9uZToKICAgIHRyeToKICAgICAgICBvYmogPSB1bnJlYWwubG9hZF9hc3NldChQQVRIKQogICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgIHcoJ1BISSBSSUc0MTQgTE9BRCBGQUxMQkFDSyBFUlJPUjogJyArIHN0cihlKSkKaWYgb2JqIGlzIE5vbmU6CiAgICB3KCdQSEkgUklHNDE0IFJFVEFSR0VUIExPQUQgTk9ORScpCmVsc2U6CiAgICBjbHMgPSBvYmouZ2V0X2NsYXNzKCkKICAgIHcoJ1BISSBSSUc0MTQgTE9BREVEIENMQVNTOiAnICsgY2xzLmdldF9uYW1lKCkpCiAgICB0cnk6CiAgICAgICAgdygnUEhJIFJJRzQxNCBMT0FERUQgQ0xBU1MgUEFUSDogJyArIGNscy5nZXRfcGF0aF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQxNCBDTEFTUyBQQVRIIEVSUk9SOiAnICsgc3RyKGUpKQogICAgdHJ5OgogICAgICAgIHcoJ1BISSBSSUc0MTQgTE9BREVEIE9CSkVDVDogJyArIG9iai5nZXRfcGF0aF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQxNCBPQkpFQ1QgUEFUSCBFUlJPUjogJyArIHN0cihlKSkKdygnUEhJIFJJRzQxNCBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$outP = "$base\Saved\phi_rig414.txt"
$pyP = $pyP.Replace('OUTFILE', "'$outP'")
Set-Content "$base\Saved\phi_rig414.py" -Value $pyP -Encoding UTF8
Remove-Item $outP -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_rig414.py" -unattended -nopause -nosplash *> "$base\Saved\rig414.log"
if (Test-Path $outP) { Get-Content $outP | Write-Output } else { Write-Output 'NO RIG414 OUTPUT FILE'; Select-String -Path "$base\Saved\rig414.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output }
Write-Output '--- RETARGET LOAD LOG LINES ---'
Select-String -Path "$base\Saved\rig414.log" -Pattern 'Rig|class|Failed|Unable' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output
Write-Output '--- SECTION 5: VERDICT ---'
$loadedClass = ''
if (Test-Path $outP) {
  $lm = [regex]::Match((Get-Content $outP -Raw), 'LOADED CLASS: (.+)')
  if ($lm.Success) { $loadedClass = $lm.Groups[1].Value.Trim() }
}
if ($loadedClass) { Write-Output ('PHI RIG414 VERDICT: RIG CLASS SEATED class=' + $loadedClass) }
else { Write-Output 'PHI RIG414 VERDICT: RIG STILL MISSING - the retarget load words stand in the log lines above' }
Write-Output 'JOB 414 DONE'
```
