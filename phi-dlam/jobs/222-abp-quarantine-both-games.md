# Job 222 — ABP quarantine, both games: the compile-error banner addressed at the asset

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Tyrees word: ADDRESS THIS FOR BOTH GAMES - the BLUEPRINT COMPILE ERROR banner is Countess_AnimBlueprint failing compilation on load. Job 220 takes it out of the cook chain in code; this job takes the asset itself out of Content (a move to D:\_PhiHolding\ABP-quarantine, never a deletion - fully reversible), so no editor session can load or compile it again and the banner has nothing left to stand on. Referencers are read first for the record. Verification: a commandlet load of each project afterward must show ZERO Countess_AnimBlueprint compiler-error lines. ==='
$py = @'
import unreal
reg = unreal.AssetRegistryHelpers.get_asset_registry()
pkg = unreal.Name('/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint')
refs = []
try:
    for r in reg.get_referencers(pkg, unreal.AssetRegistryDependencyOptions(include_soft_package_references=True, include_hard_package_references=True, include_searchable_names=False, include_soft_management_references=False, include_hard_management_references=False)):
        refs.append(str(r))
except Exception as e:
    refs.append('REFERENCER READ ERROR: %s' % e)
with open(r'D:\VEIL\Saved\abp_refs.txt', 'w') as f:
    f.write('\n'.join(refs) if refs else 'NO REFERENCERS')
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\abp_refs.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_refs.py' -unattended -nopause 2>&1 | Out-Null
Write-Output '--- ABP referencers (registry) ---'
if (Test-Path 'D:\VEIL\Saved\abp_refs.txt') { Get-Content 'D:\VEIL\Saved\abp_refs.txt' } else { Write-Output 'refs file absent' }
foreach ($g in @(@('VEIL','D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset'), @('OMNI','D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset'))) {
  $name = $g[0]; $file = $g[1]
  $destDir = "D:\_PhiHolding\ABP-quarantine\$name"
  New-Item -ItemType Directory -Force -Path $destDir | Out-Null
  if (Test-Path $file) { Move-Item $file "$destDir\Countess_AnimBlueprint.uasset" -Force; Write-Output "$name ABP moved to quarantine." } else { Write-Output "$name ABP not at expected path (already moved?): $file" }
  Write-Output "$name ABP still in Content: $(Test-Path $file)"
}
foreach ($g in @(@('VEIL','D:\VEIL\VEIL.uproject'), @('OMNI','D:\OMNI-UE\OMNI.uproject'))) {
  $name = $g[0]; $proj = $g[1]
  $out = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' $proj -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_refs.py' -unattended -nopause -abslog="D:\VEIL\Saved\abp_verify_$name.log" 2>&1
  $hits = (Select-String -Path "D:\VEIL\Saved\abp_verify_$name.log" -Pattern 'Countess_AnimBlueprint.*COMPILER ERROR|Could not find a function named' -ErrorAction SilentlyContinue).Count
  Write-Output "$name post-quarantine ABP compiler-error lines: $hits (startup exit $LASTEXITCODE)"
}
```
