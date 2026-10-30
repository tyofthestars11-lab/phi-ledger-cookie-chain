<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 725 - VEIL OMNI ANIMBLUEPRINT MISSING (Ground: Tyree order dont stop until you finish the game Unreal tells from job 724 tail VEILCharacter CDO Constructor failed to find Countess AnimBlueprint C Paragon Proto Retarget Rig class does not exist map VEILDistrict 626984 in jobs 722 723 724 up from 180952 past 292786 target proof only in play this job reads only starts nothing builds nothing no cook no package no 1.0 real read not print targets. Every variable carries the p725 prefix.) ==='
$p725proj = 'D:\VEIL-OMNI'
$p725map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p725ab = 'D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Animations\Countess_AnimBlueprint.uasset'
$p725rig = 'D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Meshes\Paragon_Proto_Retarget.uasset'
$p725char = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
if (Test-Path $p725map) { Write-Output ('MAP725 SIZE ' + (Get-Item $p725map).Length) } else { Write-Output 'MAP725 MISSING' }
if (Test-Path $p725ab) { Write-Output ('ANIM725 PRESENT SIZE ' + (Get-Item $p725ab).Length) } else { Write-Output 'ANIM725 MISSING Countess_AnimBlueprint' }
if (Test-Path $p725rig) { Write-Output ('RIG725 PRESENT SIZE ' + (Get-Item $p725rig).Length) } else { Write-Output 'RIG725 MISSING Paragon_Proto_Retarget' }
if (Test-Path $p725char) {
  $p725refs = @(Select-String -Path $p725char -Pattern 'AnimBlueprint' -SimpleMatch:$false)
  Write-Output ('CHAR725 ANIMBLUEPRINT LINES ' + $p725refs.Count)
  foreach ($p725r in $p725refs) { Write-Output ('CHAR725 LINE ' + $p725r.LineNumber + ' ' + $p725r.Line) }
} else { Write-Output 'CHAR725 MISSING VEILCharacter.cpp' }
$p725animdir = 'D:\VEIL-OMNI\Content\ParagonCountess\Characters\Heroes\Countess\Animations'
if (Test-Path $p725animdir) {
  $p725anims = @(Get-ChildItem $p725animdir -File -ErrorAction SilentlyContinue)
  Write-Output ('ANIMDIR725 FILES ' + $p725anims.Count)
  foreach ($p725a in $p725anims) { Write-Output ('ANIMDIR725 FILE ' + $p725a.Name) }
} else { Write-Output 'ANIMDIR725 MISSING' }
Write-Output 'UNREAL725 TELLS NOT JOB START LINES'
Write-Output 'PROOF725 ONLY IN PLAY'
Write-Output 'JOB 725 DONE'
```
