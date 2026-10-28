<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RETARGET NAME MAP 418 - THE DECLARED CLASS READ FROM THE NAME MAP WHOLE (The scar this job is authored against, carried in from job 416: its verdict section assigned a value to a variable named HOME, and HOME is a read-only automatic variable in PowerShell, so the assignment refused with VariableNotWritable and the verdict line printed the profile path in place of its measured text. The named failure class is READ-ONLY AUTOMATIC VARIABLE COLLISION, and this job answers it by construction: no variable in this body carries the name of any PowerShell automatic or read-only variable - HOME, matches, error, input, args, profile, host, pid, pwd, shellid, stacktrace, executioncontext, psversiontable, false, true, and null all stand banned as variable names here - every variable carries the rig418 prefix, and every verdict print is built from measured locals only. Ground from job 416, read whole: the retarget asset under the merged base measured 68570 bytes with SHA-256 d47e86ac806722a6d56eb822db707b2323fcf6220d408e109a8a653ef1bb3a03, its only script package strings were /Script/CoreUObject and /Script/Engine with no Rig plugin package string standing in it, five Rig family strings stood in it with RigTransformConstraint among them, and the editor refuses to load it because its class (Rig) does not exist. This job re-reads the retarget asset name map whole and no other road: one, resolve the file under the merged base Content tree by its name Paragon_Proto_Retarget.uasset, print the resolved path, its size, and its SHA-256, and compare the hash against the 416 measure - print HASH MATCHES 416 and continue, or print HASH DRIFT and stop. Two, print the first 120 ASCII strings of length four or more in file order with byte offsets, the package name map standing at the head of the file, so the declared class and its imports read from the list itself. Three, print every ASCII string carrying Rig, Skeletal, Skeleton, Anim, Retarget, Constraint, or Blueprint with its byte offset, uncapped. Four, the verdict in one line: CLASS DECLARED with the candidate string the name map carries for the asset own export and its offset, or CLASS NOT IN THE NAME MAP with the string counts. Read-only throughout: no writes, no moves, no launches, no editor.) ==='
$rig418Base = 'D:\VEIL-OMNI'
$rig418FileName = 'Paragon_Proto_Retarget.uasset'
$rig418ExpectedSize = 68570
$rig418ExpectedHash = 'd47e86ac806722a6d56eb822db707b2323fcf6220d408e109a8a653ef1bb3a03'
$rig418Target = Join-Path $rig418Base 'Content\ParagonCountess\Characters\Heroes\Countess\Meshes\Paragon_Proto_Retarget.uasset'
if (-not (Test-Path $rig418Target)) {
  $rig418Hit = Get-ChildItem (Join-Path $rig418Base 'Content') -Recurse -Filter $rig418FileName -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($rig418Hit) { $rig418Target = $rig418Hit.FullName } else { $rig418Target = '' }
}
Write-Output '--- SECTION 1: RESOLVE, SIZE, SHA-256 AGAINST THE 416 MEASURE ---'
if ($rig418Target -eq '') {
  Write-Output 'RETARGET FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI RIG418 VERDICT: CLASS NOT IN THE NAME MAP - the asset file itself was not found by name under the merged base Content tree'
  Write-Output 'JOB 418 DONE'
  return
}
Write-Output ("RESOLVED PATH: " + $rig418Target)
$rig418Item = Get-Item $rig418Target
Write-Output ("SIZE BYTES=" + $rig418Item.Length + " SIZE 416=" + $rig418ExpectedSize)
$rig418Hash = (Get-FileHash $rig418Target -Algorithm SHA256).Hash.ToLower()
Write-Output ("SHA256: " + $rig418Hash)
Write-Output ("SHA256 416: " + $rig418ExpectedHash)
if ($rig418Hash -ne $rig418ExpectedHash) {
  Write-Output 'HASH DRIFT - the asset bytes differ from the 416 measure and this job stops on the drift'
  Write-Output 'PHI RIG418 VERDICT: HASH DRIFT - no name map read stands on drifted bytes'
  Write-Output 'JOB 418 DONE'
  return
}
Write-Output 'HASH MATCHES 416'
Write-Output '--- SECTION 2: FIRST 120 ASCII STRINGS LENGTH FOUR OR MORE IN FILE ORDER ---'
$rig418Bytes = [System.IO.File]::ReadAllBytes($rig418Target)
$rig418Runs = @()
$rig418Start = -1
for ($rig418Idx = 0; $rig418Idx -lt $rig418Bytes.Length; $rig418Idx++) {
  $rig418Byte = $rig418Bytes[$rig418Idx]
  if ($rig418Byte -ge 32 -and $rig418Byte -le 126) {
    if ($rig418Start -lt 0) { $rig418Start = $rig418Idx }
  } else {
    if ($rig418Start -ge 0 -and ($rig418Idx - $rig418Start) -ge 4) {
      $rig418Text = [System.Text.Encoding]::ASCII.GetString($rig418Bytes, $rig418Start, $rig418Idx - $rig418Start)
      $rig418Runs += [PSCustomObject]@{ Offset = $rig418Start; Text = $rig418Text }
    }
    $rig418Start = -1
  }
}
if ($rig418Start -ge 0 -and ($rig418Bytes.Length - $rig418Start) -ge 4) {
  $rig418Text = [System.Text.Encoding]::ASCII.GetString($rig418Bytes, $rig418Start, $rig418Bytes.Length - $rig418Start)
  $rig418Runs += [PSCustomObject]@{ Offset = $rig418Start; Text = $rig418Text }
}
Write-Output ("ASCII RUNS LEN4PLUS COUNT=" + $rig418Runs.Count)
$rig418First = @($rig418Runs | Select-Object -First 120)
Write-Output ("FIRST STRINGS PRINTED=" + $rig418First.Count)
$rig418Num = 0
foreach ($rig418Run in $rig418First) { $rig418Num++; Write-Output ("NAME STRING " + $rig418Num + " offset=" + $rig418Run.Offset + " : " + $rig418Run.Text) }
Write-Output '--- SECTION 3: RIG AND ANIMATION FAMILY STRINGS WITH OFFSETS UNCAPPED ---'
$rig418Tokens = @('Rig', 'Skeletal', 'Skeleton', 'Anim', 'Retarget', 'Constraint', 'Blueprint')
$rig418Family = @()
foreach ($rig418Run in $rig418Runs) {
  $rig418IsFamily = 0
  foreach ($rig418Token in $rig418Tokens) { if ($rig418Run.Text.Contains($rig418Token)) { $rig418IsFamily = 1; break } }
  if ($rig418IsFamily -eq 1) { $rig418Family += $rig418Run }
}
Write-Output ("FAMILY STRINGS COUNT=" + $rig418Family.Count)
foreach ($rig418Run in $rig418Family) { Write-Output ("FAMILY STRING offset=" + $rig418Run.Offset + " : " + $rig418Run.Text) }
Write-Output '--- SECTION 4: VERDICT ---'
Write-Output 'CANDIDATE RULE: the first family string in file order that carries no path separator and does not carry the asset own name stands as the export class candidate'
$rig418CandText = ''
$rig418CandOffset = -1
foreach ($rig418Run in $rig418Family) {
  if ($rig418Run.Text.Contains('/')) { continue }
  if ($rig418Run.Text.Contains('\')) { continue }
  if ($rig418Run.Text.Contains('Paragon_Proto_Retarget')) { continue }
  $rig418CandText = $rig418Run.Text
  $rig418CandOffset = $rig418Run.Offset
  break
}
if ($rig418CandOffset -ge 0) {
  Write-Output ("PHI RIG418 VERDICT: CLASS DECLARED candidate=" + $rig418CandText + " offset=" + $rig418CandOffset + " family strings=" + $rig418Family.Count + " ascii runs len4plus=" + $rig418Runs.Count)
} else {
  Write-Output ("PHI RIG418 VERDICT: CLASS NOT IN THE NAME MAP family strings=" + $rig418Family.Count + " ascii runs len4plus=" + $rig418Runs.Count + " first strings printed=" + $rig418First.Count)
}
Write-Output 'JOB 418 DONE'
```
