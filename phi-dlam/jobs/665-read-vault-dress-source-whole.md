<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 665 - READ VAULT DRESS SOURCE WHOLE (Ground: job 664 hunted the Vault asset everywhere. Content search found 1 file, ModularS30eeb54ea3e4V1, plus Vault dress code PHI_WorldDress_Vault.cpp and PHI_WorldDress_Vault.h plus build artifacts, but no Vault mesh asset named in Content. Job 663 proved the Countess question by printing class first, SkeletalMesh, then setting the right component and saving. This job reads the Vault dress source whole and prints exactly what Vault asset it references, so the next placement job names a real asset, not a guess. Read only, no edit, no build, no cook, no package.) ==='
$cpp665 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_WorldDress_Vault.cpp'
$h665 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_WorldDress_Vault.h'
foreach ($f665 in @($cpp665, $h665)) {
  if (Test-Path $f665) {
    $lines665 = @(Get-Content $f665)
    Write-Output ('VAULT665 SOURCE PRESENT ' + $f665 + ' LINES ' + $lines665.Count)
    $hits665 = @(Select-String -Path $f665 -Pattern 'Mesh|Asset|/Game/|Content|StaticMesh|SkeletalMesh' | Select-Object -First 40)
    Write-Output ('VAULT665 REF LINES ' + $hits665.Count)
    foreach ($hit665 in $hits665) { Write-Output ('VAULT665 REF ' + $hit665.Line.Trim()) }
  } else {
    Write-Output ('VAULT665 SOURCE MISSING ' + $f665)
  }
}
$mod665 = 'D:\VEIL-OMNI\Content\ModularS30eeb54ea3e4V1'
if (Test-Path $mod665) {
  $item665 = Get-Item $mod665
  Write-Output ('VAULT665 MODULAR PRESENT LENGTH ' + $item665.Length + ' EXTENSION ' + $item665.Extension)
} else {
  Write-Output 'VAULT665 MODULAR MISSING'
}
$v665 = @(Get-ChildItem 'D:\VEIL-OMNI\Content' -Recurse -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*Vault*' })
Write-Output ('VAULT665 CONTENT VAULT COUNT ' + $v665.Count)
foreach ($x665 in $v665) { Write-Output ('VAULT665 CONTENT FILE ' + $x665.FullName) }
Write-Output 'NOCOOK665 NO COOK NO PACKAGE'
Write-Output 'JOB 665 DONE'
```
