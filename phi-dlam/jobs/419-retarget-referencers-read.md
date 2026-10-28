<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RETARGET REFERENCERS 419 - WHO IN THE GAME ACTUALLY LOADS THE LEGACY RIG ASSET (Ground from job 418, read whole: Paragon_Proto_Retarget.uasset stands byte-identical to the 416 measure at 68570 bytes with SHA-256 d47e86ac806722a6d56eb822db707b2323fcf6220d408e109a8a653ef1bb3a03, its name map carries the constraint family strings RigTransformConstraint, EConstraintTransform, TransformBaseConstraint, and TransformConstraints with its candidate print naming Constraints, its only script package homes are /Script/CoreUObject and /Script/Engine, and the editor refuses to load it because its class (Rig) does not exist in this engine build, which reads as a legacy UE4 4.19 asset whose class was removed from the engine. The decisive open question is whether anything in the merged base actually references this asset at all, because an asset nothing loads only warns and never touches runtime. This job reads the asset registry referencers for Paragon_Proto_Retarget and greps the source and config trees for its name, so the Rig class thread closes on whether anything in the game actually loads it. One, the registry referencer read prints the hard and soft referencers whole or REFERENCERS EMPTY. Two, the source grep prints every line under the Source tree carrying Paragon_Proto_Retarget or Proto_Retarget with file names and line numbers, or SOURCE REFS NONE. Three, the config grep prints the same two tokens under the Config tree the same way, or CONFIG REFS NONE. Four, the census of the Meshes folder the asset sits in prints every sibling asset name with its size, so the whole folder contents stand in print beside it. Five, the verdict in one line: REFERENCED with the combined count and the first referencer named, or UNREFERENCED with all three counts at zero, the load warning then standing as cosmetic on a legacy asset nothing loads at runtime. Read-only throughout: no edits, no moves, and every variable carries the ref419 prefix under the standing ban on automatic variable names.) ==='
$ref419Waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $ref419Waited -lt 10) { Start-Sleep -Seconds 10; $ref419Waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI REF419 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 419 STOPPED'; return }
Write-Output 'PHI REF419 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$ref419Base = 'D:\VEIL-OMNI'
$ref419Uproj = "$ref419Base\VEIL.uproject"
$ref419CmdExe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$ref419MeshFolder = "$ref419Base\Content\ParagonCountess\Characters\Heroes\Countess\Meshes"
$ref419TargetFile = Join-Path $ref419MeshFolder 'Paragon_Proto_Retarget.uasset'
if (-not (Test-Path $ref419TargetFile)) {
  $ref419FoundFile = Get-ChildItem "$ref419Base\Content" -Recurse -Filter 'Paragon_Proto_Retarget.uasset' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($ref419FoundFile) { $ref419TargetFile = $ref419FoundFile.FullName; $ref419MeshFolder = $ref419FoundFile.DirectoryName }
}
Write-Output ("PHI REF419 TARGET FILE: " + $ref419TargetFile)
Write-Output '--- SECTION 1: ASSET REGISTRY REFERENCERS ---'
$ref419Py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IG9zCmltcG9ydCB1bnJlYWwKCm91dCA9IG9wZW4oT1VURklMRSwgJ3cnKQpkZWYgdyhzKToKICAgIG91dC53cml0ZShzdHIocykgKyAnXG4nKQoKUEtHID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvUGFyYWdvbl9Qcm90b19SZXRhcmdldCcKcmVmcyA9IE5vbmUKcmVnX25vdGUgPSAnJwp0cnk6CiAgICByZWdpc3RyeSA9IHVucmVhbC5Bc3NldFJlZ2lzdHJ5SGVscGVycy5nZXRfYXNzZXRfcmVnaXN0cnkoKQogICAgdHJ5OgogICAgICAgIG9wdHMgPSB1bnJlYWwuQXNzZXRSZWdpc3RyeURlcGVuZGVuY3lPcHRpb25zKGluY2x1ZGVfaGFyZF9wYWNrYWdlX3JlZmVyZW5jZXM9VHJ1ZSwgaW5jbHVkZV9zb2Z0X3BhY2thZ2VfcmVmZXJlbmNlcz1UcnVlLCBpbmNsdWRlX3NlYXJjaGFibGVfbmFtZXM9RmFsc2UsIGluY2x1ZGVfaGFyZF9tYW5hZ2VtZW50X3JlZmVyZW5jZXM9RmFsc2UsIGluY2x1ZGVfc29mdF9tYW5hZ2VtZW50X3JlZmVyZW5jZXM9RmFsc2UpCiAgICAgICAgcmVmcyA9IHJlZ2lzdHJ5LmdldF9yZWZlcmVuY2VycyhQS0csIG9wdHMpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGUxOgogICAgICAgIHJlZ19ub3RlID0gJ29wdGlvbnMgZm9ybSByZWZ1c2VkOiAnICsgc3RyKGUxKQogICAgICAgIHJlZnMgPSByZWdpc3RyeS5nZXRfcmVmZXJlbmNlcnMoUEtHKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICByZWdfbm90ZSA9IChyZWdfbm90ZSArICcgfCBwbGFpbiBmb3JtIHJlZnVzZWQ6ICcgKyBzdHIoZSkpIGlmIHJlZ19ub3RlIGVsc2Ugc3RyKGUpCiAgICByZWZzID0gTm9uZQppZiByZWdfbm90ZToKICAgIHcoJ1BISSBSRUY0MTkgUkVHSVNUUlkgTk9URTogJyArIHJlZ19ub3RlKQpyZWZfbmFtZXMgPSBbXQppZiByZWZzIGlzIG5vdCBOb25lOgogICAgZm9yIHJuYW1lIGluIHJlZnM6CiAgICAgICAgdHJ5OgogICAgICAgICAgICByZWZfbmFtZXMuYXBwZW5kKHN0cihybmFtZSkpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbjoKICAgICAgICAgICAgcGFzcwpyZWZfbmFtZXMgPSBzb3J0ZWQoc2V0KHJlZl9uYW1lcykpCncoJ1BISSBSRUY0MTkgUkVGRVJFTkNFUiBDT1VOVD0nICsgc3RyKGxlbihyZWZfbmFtZXMpKSkKaWYgbGVuKHJlZl9uYW1lcykgPT0gMDoKICAgIHcoJ1BISSBSRUY0MTkgUkVGRVJFTkNFUlMgRU1QVFknKQpmb3Igcm4gaW4gcmVmX25hbWVzOgogICAgdygnUEhJIFJFRjQxOSBSRUZFUkVOQ0VSOiAnICsgcm4pCncoJ1BISSBSRUY0MTkgUkVHSVNUUlkgUkVBRCBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$ref419Out = "$ref419Base\Saved\phi_ref419.txt"
$ref419Py = $ref419Py.Replace('OUTFILE', "'$ref419Out'")
Set-Content "$ref419Base\Saved\phi_ref419.py" -Value $ref419Py -Encoding UTF8
Remove-Item $ref419Out -ErrorAction SilentlyContinue
& $ref419CmdExe $ref419Uproj -run=pythonscript -script="$ref419Base\Saved\phi_ref419.py" -unattended -nopause -nosplash *> "$ref419Base\Saved\ref419.log"
$ref419RefCount = -1
$ref419FirstRef = ''
if (Test-Path $ref419Out) {
  $ref419Lines = @(Get-Content $ref419Out)
  $ref419Lines | Write-Output
  $ref419CountLine = $ref419Lines | Where-Object { $_ -like 'PHI REF419 REFERENCER COUNT=*' } | Select-Object -First 1
  if ($ref419CountLine) { $ref419RefCount = [int]($ref419CountLine.Substring($ref419CountLine.IndexOf('=') + 1).Trim()) }
  $ref419FirstLine = $ref419Lines | Where-Object { $_ -like 'PHI REF419 REFERENCER: *' } | Select-Object -First 1
  if ($ref419FirstLine) { $ref419FirstRef = $ref419FirstLine.Substring($ref419FirstLine.IndexOf(':') + 1).Trim() }
} else {
  Write-Output 'NO REF419 OUTPUT FILE'
  Select-String -Path "$ref419Base\Saved\ref419.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
Write-Output '--- SECTION 2: SOURCE GREP ---'
$ref419SrcHits = @(Get-ChildItem "$ref419Base\Source" -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'Paragon_Proto_Retarget|Proto_Retarget' -ErrorAction SilentlyContinue)
Write-Output ("PHI REF419 SOURCE HIT COUNT=" + $ref419SrcHits.Count)
if ($ref419SrcHits.Count -eq 0) { Write-Output 'SOURCE REFS NONE' }
$ref419SrcHits | ForEach-Object { Write-Output ($_.Path + ' ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
Write-Output '--- SECTION 3: CONFIG GREP ---'
$ref419CfgHits = @(Get-ChildItem "$ref419Base\Config" -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'Paragon_Proto_Retarget|Proto_Retarget' -ErrorAction SilentlyContinue)
Write-Output ("PHI REF419 CONFIG HIT COUNT=" + $ref419CfgHits.Count)
if ($ref419CfgHits.Count -eq 0) { Write-Output 'CONFIG REFS NONE' }
$ref419CfgHits | ForEach-Object { Write-Output ($_.Path + ' ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
Write-Output '--- SECTION 4: MESHES FOLDER CENSUS ---'
if (Test-Path $ref419MeshFolder) {
  $ref419Siblings = @(Get-ChildItem $ref419MeshFolder -File -ErrorAction SilentlyContinue | Sort-Object Name)
  Write-Output ("PHI REF419 MESHES FOLDER: " + $ref419MeshFolder)
  Write-Output ("PHI REF419 SIBLING COUNT=" + $ref419Siblings.Count)
  $ref419Siblings | ForEach-Object { Write-Output ("SIBLING: " + $_.Name + " size=" + $_.Length) }
} else {
  Write-Output 'MESHES FOLDER NOT FOUND'
}
Write-Output '--- SECTION 5: VERDICT ---'
$ref419Total = 0
if ($ref419RefCount -gt 0) { $ref419Total += $ref419RefCount }
$ref419Total += $ref419SrcHits.Count + $ref419CfgHits.Count
if ($ref419RefCount -eq 0 -and $ref419SrcHits.Count -eq 0 -and $ref419CfgHits.Count -eq 0) {
  Write-Output 'PHI REF419 VERDICT: UNREFERENCED referencers=0 source=0 config=0 - the load warning stands cosmetic on a legacy asset nothing loads at runtime'
} elseif ($ref419RefCount -lt 0) {
  Write-Output ("PHI REF419 VERDICT: REGISTRY READ UNRESOLVED source=" + $ref419SrcHits.Count + " config=" + $ref419CfgHits.Count + ' - the referencer count never printed and the thread stays open on that count alone')
} else {
  $ref419FirstNamed = $ref419FirstRef
  if ($ref419FirstNamed -eq '' -and $ref419SrcHits.Count -gt 0) { $ref419FirstNamed = $ref419SrcHits[0].Path }
  if ($ref419FirstNamed -eq '' -and $ref419CfgHits.Count -gt 0) { $ref419FirstNamed = $ref419CfgHits[0].Path }
  Write-Output ("PHI REF419 VERDICT: REFERENCED count=" + $ref419Total + " referencers=" + $ref419RefCount + " source=" + $ref419SrcHits.Count + " config=" + $ref419CfgHits.Count + " first=" + $ref419FirstNamed)
}
Write-Output 'JOB 419 DONE'
```
