<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 664 - HUNT VAULT ASSET EVERYWHERE (Ground: Copilot answer pasted whole by Tyree. Lesson taken whole: Muse kept proving Unreal could perform actions while Tyree expected proof the game itself had changed. Those are not the same. Proof from here is visible in play, not load true or save true. Job 663 was the first right question, Countess class SkeletalMesh, mesh assigned, actors 94, save true. Next blocker in Copilot order is Vault. Vault asset search in Content found 0, so placement cannot happen until the asset exists. This job hunts the Vault asset across the project and the PC, it does not claim placement, it does not build a fake Vault, it does not cook, it does not package.) ==='
$p664roots = @('D:\VEIL-OMNI\Content', 'D:\VEIL-OMNI', 'C:\Users\Admin\Downloads', 'D:\')
foreach ($p664root in $p664roots) {
  if (Test-Path $p664root) {
    Write-Output ('HUNT664 ROOT PRESENT ' + $p664root)
    $p664found = @(Get-ChildItem $p664root -Recurse -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*ModularS30*' -or $_.Name -like '*Vault*' } | Select-Object -First 50)
    Write-Output ('HUNT664 FOUND IN ' + $p664root + ' COUNT ' + $p664found.Count)
    foreach ($p664f in $p664found) { Write-Output ('HUNT664 FILE ' + $p664f.FullName) }
  } else { Write-Output ('HUNT664 ROOT MISSING ' + $p664root) }
}
Write-Output 'MAP664 VEILDISTRICT CHECK'
if (Test-Path 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap') { Write-Output 'MAP664 PRESENT' } else { Write-Output 'MAP664 MISSING' }
Write-Output 'ICON664 DESKTOP CHECK'
if (Test-Path 'C:\Users\Admin\Desktop\VEIL OMNI.lnk') { Write-Output 'ICON664 PRESENT' } else { Write-Output 'ICON664 MISSING' }
Write-Output 'NOCOOK664 NO COOK NO PACKAGE'
Write-Output 'JOB 664 DONE'
```
