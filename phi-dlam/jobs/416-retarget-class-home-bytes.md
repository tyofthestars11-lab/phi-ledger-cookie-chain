<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RETARGET CLASS HOME 416 - THE ASSET BYTES NAME WHERE ITS RIG CLASS LIVES (Ground from job 414: the IKRig plugin stood ABSENT from VEIL.uproject, this lane enabled it with a verified write and a kept backup, the editor target printed BUILD SUCCEEDED, and the retarget asset still refused in the editor own words - Unable to load Paragon_Proto_Retarget because its class (Rig) does not exist. So the Rig class does not live in the IKRig plugin, and the seat built on that ground did not seat it. A uasset carries its own class home in its package header imports: the script package strings inside its name table name the module the class was born in. This job reads the retarget asset at the byte level and no other road: one, resolve the file under the merged base Content tree by its name Paragon_Proto_Retarget.uasset and print the resolved path, its size, and its SHA-256. Two, extract every ASCII string of length five or more that carries a script package path and print each with its byte offset. Three, extract every ASCII string carrying Rig, IKRig, ControlRig, Retarget, or Pose and print each with its byte offset. Four, the verdict in one line: CLASS HOME with the exact script module and class string the asset itself carries for its own class, or CLASS HOME UNREADABLE with what the strings census did find. Read-only throughout: no writes, no moves, no launches, no editor.) ==='
$base = 'D:\VEIL-OMNI'
$name = 'Paragon_Proto_Retarget.uasset'
$target = Join-Path $base 'Content\ParagonCountess\Characters\Heroes\Countess\Meshes\Paragon_Proto_Retarget.uasset'
if (-not (Test-Path $target)) {
  $hit = Get-ChildItem (Join-Path $base 'Content') -Recurse -Filter $name -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($hit) { $target = $hit.FullName } else { $target = $null }
}
Write-Output '--- SECTION 1: RESOLVE, SIZE, SHA-256 ---'
if (-not $target) {
  Write-Output 'RETARGET FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI RIG416 VERDICT: CLASS HOME UNREADABLE - the asset file itself was not found by name under D:\VEIL-OMNI\Content'
  Write-Output 'JOB 416 DONE'
  return
}
Write-Output ("RESOLVED PATH: " + $target)
$fi = Get-Item $target
Write-Output ("SIZE BYTES=" + $fi.Length)
$hash = (Get-FileHash $target -Algorithm SHA256).Hash.ToLower()
Write-Output ("SHA256: " + $hash)
Write-Output '--- SECTION 2: ASCII STRINGS CARRYING SCRIPT PACKAGE PATHS ---'
$bytes = [System.IO.File]::ReadAllBytes($target)
$runs = @()
$start = -1
for ($i = 0; $i -lt $bytes.Length; $i++) {
  $b = $bytes[$i]
  if ($b -ge 32 -and $b -le 126) {
    if ($start -lt 0) { $start = $i }
  } else {
    if ($start -ge 0 -and ($i - $start) -ge 5) {
      $s = [System.Text.Encoding]::ASCII.GetString($bytes, $start, $i - $start)
      $runs += [PSCustomObject]@{ Offset = $start; Text = $s }
    }
    $start = -1
  }
}
if ($start -ge 0 -and ($bytes.Length - $start) -ge 5) {
  $s = [System.Text.Encoding]::ASCII.GetString($bytes, $start, $bytes.Length - $start)
  $runs += [PSCustomObject]@{ Offset = $start; Text = $s }
}
Write-Output ("ASCII RUNS LEN5PLUS COUNT=" + $runs.Count)
$scriptRuns = @($runs | Where-Object { $_.Text.Contains('/Script/') })
Write-Output ("SCRIPT PATH STRINGS COUNT=" + $scriptRuns.Count)
foreach ($run in $scriptRuns) { Write-Output ("SCRIPT STRING offset=" + $run.Offset + " : " + $run.Text) }
Write-Output '--- SECTION 3: ASCII STRINGS CARRYING RIG, CONTROL RIG, RETARGET, POSE ---'
$rigRuns = @($runs | Where-Object { $_.Text.Contains('Rig') -or $_.Text.Contains('Retarget') -or $_.Text.Contains('Pose') })
Write-Output ("RIG FAMILY STRINGS COUNT=" + $rigRuns.Count)
foreach ($run in $rigRuns) { Write-Output ("RIG STRING offset=" + $run.Offset + " : " + $run.Text) }
Write-Output '--- SECTION 4: VERDICT ---'
$home = $null
foreach ($run in $scriptRuns) { if ($run.Text.Contains('Rig')) { $home = $run.Text; break } }
if ($home) {
  Write-Output ("PHI RIG416 VERDICT: CLASS HOME " + $home)
} elseif ($scriptRuns.Count -gt 0) {
  Write-Output ("PHI RIG416 VERDICT: CLASS HOME UNREADABLE - no script string carries Rig; script strings found=" + $scriptRuns.Count + " rig family strings found=" + $rigRuns.Count)
} else {
  Write-Output ("PHI RIG416 VERDICT: CLASS HOME UNREADABLE - no script path strings in the bytes; ascii runs found=" + $runs.Count)
}
Write-Output 'JOB 416 DONE'
```
