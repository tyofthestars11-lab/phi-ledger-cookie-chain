# Job 220 — ABP bypass: the runner poses from a pack AnimSequence (single-node), ABP leaves the cook chain, build both

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The cook has one blocker: Countess_AnimBlueprint, 38 errors, all in its EVENT graph (casts and calls to the quarantined character BP). Its AnimGraph poses the runner in every PIE session - Tyrees own screens today show the body check green and the Countess standing posed. The repair surgery waits on graph reads; the PACKAGE does not have to. This job takes the ABP out of the reference chain without touching the asset: a census names the Countess packs own AnimSequences, the first Idle (else Run, else Walk, else first) becomes the runners pose in single-node AnimationAsset mode - a real pose from the packs own data, played by the mesh component, no AnimBlueprint in the chain. Originals are backed up to D:\_PhiHolding\src-backup-220 first; the ABP asset itself is untouched; reverting is restoring two files. If the anchors do not match exactly, the edit aborts untouched. ==='
$py = @'
import unreal
reg = unreal.AssetRegistryHelpers.get_asset_registry()
filt = unreal.ARFilter(package_paths=['/Game/ParagonCountess'], recursive_paths=True)
seqs = []
for d in reg.get_assets(filt):
    try:
        cn = str(d.asset_class_path.asset_name)
    except Exception:
        cn = '?'
    if cn == 'AnimSequence':
        seqs.append('%s.%s' % (d.package_name, d.asset_name))
with open(r'D:\VEIL\Saved\seq_out.txt', 'w') as f:
    f.write('\n'.join(sorted(seqs)))
print('SEQCOUNT', len(seqs))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\seq_census.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\seq_census.py' -unattended -nopause 2>&1 | Out-Null
if (-not (Test-Path 'D:\VEIL\Saved\seq_out.txt')) { Write-Output 'CENSUS FAILED - no sequence file; job stops, sources untouched.'; return }
$seqs = Get-Content 'D:\VEIL\Saved\seq_out.txt' | Where-Object { $_ }
Write-Output "AnimSequences under /Game/ParagonCountess: $($seqs.Count)"
$seqs | ForEach-Object { Write-Output "  SEQ $_" }
$pick = $seqs | Where-Object { $_ -match 'Idle' } | Select-Object -First 1
if (-not $pick) { $pick = $seqs | Where-Object { $_ -match 'Run' } | Select-Object -First 1 }
if (-not $pick) { $pick = $seqs | Where-Object { $_ -match 'Walk' } | Select-Object -First 1 }
if (-not $pick) { $pick = $seqs | Select-Object -First 1 }
if (-not $pick) { Write-Output 'NO ANIMSEQUENCE IN THE PACK - bypass impossible; job stops, sources untouched.'; return }
Write-Output "POSE SEQUENCE PICK: $pick"
New-Item -ItemType Directory -Force -Path 'D:\_PhiHolding\src-backup-220' | Out-Null
foreach ($g in @(@('VEIL','D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp'), @('OMNI','D:\OMNI-UE\Source\OMNI\Private\Character\OMNICharacter.cpp'))) {
  $name = $g[0]; $file = $g[1]
  Copy-Item $file "D:\_PhiHolding\src-backup-220\$name`Character.cpp" -Force
  $src = Get-Content $file -Raw
  $ok = $true
  if ($src -notmatch 'FClassFinder<UAnimInstance> MannyAnim\(') { $ok = $false }
  if ($src -notmatch 'SetAnimInstanceClass\(MannyAnim\.Class\)') { $ok = $false }
  if ($src -notmatch 'StaticLoadClass\(UAnimInstance::StaticClass\(\)') { $ok = $false }
  if (-not $ok) { Write-Output "$name EDIT ABORTED - anchors do not match; source untouched."; continue }
  $src = $src -replace 'FClassFinder<UAnimInstance> MannyAnim\(', 'FObjectFinder<UAnimSequence> MannyAnim('
  $src = $src -replace [regex]::Escape('/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint_C"));' + "`r`n`t\tif (MannyMesh.Succeeded())"), ($pick + '"));' + "`r`n`t\tif (MannyMesh.Succeeded())")
  $src = $src -replace 'GetMesh\(\)->SetAnimInstanceClass\(MannyAnim\.Class\);', 'GetMesh()->SetAnimationMode(EAnimationMode::AnimationAsset);'
  $src = $src -replace 'Countess_AnimBlueprint class not found - mesh set, animation unassigned\.', 'Countess pose sequence not found - mesh set, animation unassigned.'
  $beginBlock = '(?s)if \(UClass\* AnimClass = StaticLoadClass\(UAnimInstance::StaticClass\(\), nullptr,\s*TEXT\("/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint\.Countess_AnimBlueprint_C"\)\)\)\s*\{\s*GetMesh\(\)->SetAnimInstanceClass\(AnimClass\);\s*\}'
  $replacement = "if (UAnimSequence* PoseSeq = StaticLoadObject(UAnimSequence::StaticClass(), nullptr, TEXT(`"$pick`")))`r`n`t`t{`r`n`t`t`tGetMesh()->PlayAnimation(PoseSeq, true);`r`n`t`t}"
  $src = $src -replace $beginBlock, $replacement
  if ($src -match 'SetAnimInstanceClass') { Write-Output "$name EDIT INCOMPLETE - SetAnimInstanceClass remains; restoring backup."; Copy-Item "D:\_PhiHolding\src-backup-220\$name`Character.cpp" $file -Force; continue }
  if ($src -notmatch 'PlayAnimation\(PoseSeq, true\)') { Write-Output "$name EDIT INCOMPLETE - PlayAnimation missing; restoring backup."; Copy-Item "D:\_PhiHolding\src-backup-220\$name`Character.cpp" $file -Force; continue }
  $lines = $src -split "`r`n"
  $idx = -1
  for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i] -match '^#include ') { $idx = $i; break } }
  if ($idx -ge 0 -and $src -notmatch 'Animation/AnimSequence\.h') { $lines = $lines[0..$idx] + '#include "Animation/AnimSequence.h"' + $lines[($idx+1)..($lines.Count-1)]; $src = $lines -join "`r`n" }
  Set-Content -Path $file -Value $src -Encoding UTF8
  Write-Output "$name character edited: single-node pose from $pick"
}
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
}
```
