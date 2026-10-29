<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 553 - READ THE ATTACK BEFORE THE VISIBLE BOLT PATCH (Ground: job 541 proved the attack fires and hits but nothing visible shows, so the visible bolt fix needs the fire code and the bolt assets read before any patch is written. This job prints the fire body plus the attack lines plus the bolt asset census. No patch rides this job, no build, no launch. No game relaunch rides this job. Every variable carries the p553 prefix.) ==='
$p553cpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
if (-not (Test-Path $p553cpp)) { Write-Output 'FILE MISSING' } else {
  $p553lines = Get-Content $p553cpp
  Write-Output ('SOURCE LINES=' + $p553lines.Count)
  $p553fire = @(Select-String -Path $p553cpp -Pattern '::Fire' | Select-Object -First 20)
  foreach ($p553m in $p553fire) { Write-Output ('FIRE MATCH ' + $p553m.LineNumber + ' ' + $p553m.Line.Trim()) }
  $p553def = @(Select-String -Path $p553cpp -Pattern 'void AVEILCharacter::Fire' | Select-Object -First 1)
  if ($p553def.Count -gt 0) {
    $p553start = $p553def[0].LineNumber - 1
    $p553end = [Math]::Min($p553start + 60, $p553lines.Count - 1)
    for ($p553i = $p553start; $p553i -le $p553end; $p553i++) { Write-Output ('FIRE BODY ' + ($p553i + 1) + ' ' + $p553lines[$p553i]) }
  } else { Write-Output 'FIRE DEF MISSING' }
  $p553atk = @(Select-String -Path $p553cpp -Pattern 'PHI ATTACK' | Select-Object -First 10)
  foreach ($p553m in $p553atk) { Write-Output ('ATTACK LINE ' + $p553m.LineNumber + ' ' + $p553m.Line.Trim()) }
  $p553spawn = @(Select-String -Path $p553cpp -Pattern 'SpawnActor|Projectile|Beam|Particle|Niagara|Lance' | Select-Object -First 30)
  foreach ($p553m in $p553spawn) { Write-Output ('SPAWN MATCH ' + $p553m.LineNumber + ' ' + $p553m.Line.Trim()) }
}
$p553content = 'D:\VEIL-OMNI\Content'
foreach ($p553f in @('Bolt', 'Projectile', 'Beam', 'Lance')) {
  $p553hits = @(Get-ChildItem $p553content -Recurse -Filter ('*' + $p553f + '*') -ErrorAction SilentlyContinue | Select-Object -First 20)
  Write-Output ($p553f.ToUpper() + ' COUNT SHOWN=' + $p553hits.Count)
  foreach ($p553h in $p553hits) { Write-Output ('ASSET ' + $p553h.FullName) }
}
Write-Output 'PHI P553 VERDICT: ATTACK READ ABOVE'
Write-Output 'JOB 553 DONE'
```
