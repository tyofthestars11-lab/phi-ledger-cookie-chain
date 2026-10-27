# Job 218 — ABP deep read v2: findings written to a file (print() is a dead channel on this lane; UE 5.8 AssetData fix)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 214 finally executed the deep read - and named two instrument faults, both now corrected. (1) Python print() never reaches this lanes console capture (the scripts earlier lines ran and vanished; only UE_LOG lines and tracebacks surface) - this script writes every finding to D:\VEIL\Saved\abp_deep_out.txt and the job prints that file. (2) The census crashed at AssetData.object_path, which UE 5.8 does not expose; paths are built from package_name + asset_name instead. Same questions as always: ABP parentage via registry tags, graph inventory incl. the AnimGraph, node visibility, Countess pack animation census. ==='
$py = @'
import unreal
lines = []
def emit(s):
    lines.append(str(s))
    unreal.log_warning(str(s))
abp_path = '/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint'
reg = unreal.AssetRegistryHelpers.get_asset_registry()
data = reg.get_asset_by_object_path(abp_path)
emit('ABPDEEP asset found: %s' % (data is not None))
if data:
    for tag in ('ParentClass', 'NativeParentClass', 'GeneratedClass', 'Skeleton', 'TargetSkeleton'):
        try:
            emit('ABPDEEP tag %s = %s' % (tag, data.get_tag_value(tag)))
        except Exception as e:
            emit('ABPDEEP tag %s ERROR: %s' % (tag, e))
abp = unreal.load_asset(abp_path)
emit('ABPDEEP loaded: %s' % (abp is not None))
if abp:
    emit('ABPDEEP class: %s' % abp.get_class().get_name())
    for prop in ('function_graphs', 'macro_graphs', 'delegate_signature_graphs', 'ubergraph_pages', 'animation_graphs'):
        try:
            v = abp.get_editor_property(prop)
            emit('ABPDEEP %s: count=%s' % (prop, len(v) if v is not None else None))
            if v:
                for g in v:
                    try:
                        nodes = g.get_editor_property('nodes')
                        emit('ABPDEEP   graph %s nodes=%s' % (g.get_name(), len(nodes) if nodes is not None else None))
                    except Exception as e:
                        emit('ABPDEEP   graph %s nodes ERROR: %s' % (g.get_name(), e))
        except Exception as e:
            emit('ABPDEEP %s ERROR: %s' % (prop, e))
filt = unreal.ARFilter(package_paths=['/Game/ParagonCountess'], recursive_paths=True)
assets = reg.get_assets(filt)
from collections import Counter
names = {}
for d in assets:
    try:
        cn = str(d.asset_class_path.asset_name)
    except Exception:
        cn = '?'
    names.setdefault(cn, []).append('%s.%s' % (d.package_name, d.asset_name))
emit('ABPDEEP CENSUS total assets under /Game/ParagonCountess: %d' % len(assets))
for cn in sorted(names):
    emit('ABPDEEP CENSUS %s: %d' % (cn, len(names[cn])))
    if cn in ('AnimSequence', 'AnimMontage', 'BlendSpace', 'BlendSpace1D', 'AimOffsetBlendSpace'):
        for p in sorted(names[cn])[:40]:
            emit('ABPDEEP   %s' % p)
emit('ABPDEEP DONE')
with open(r'D:\VEIL\Saved\abp_deep_out.txt', 'w') as f:
    f.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\abp_deep_read2.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read2.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Error|Exception' | ForEach-Object { $_.Line }
Write-Output "commandlet exit: $LASTEXITCODE"
Write-Output '--- abp_deep_out.txt ---'
if (Test-Path 'D:\VEIL\Saved\abp_deep_out.txt') { Get-Content 'D:\VEIL\Saved\abp_deep_out.txt' } else { Write-Output 'OUTPUT FILE ABSENT - script died before writing' }
```
