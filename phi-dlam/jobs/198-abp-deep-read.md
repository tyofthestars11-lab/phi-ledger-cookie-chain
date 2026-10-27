# Job 198 — ABP deep read: parent class by the registry route, graph inventory, rebuild material census

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$py = @'
import unreal
from collections import Counter
P = '/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint'
def show(label, fn):
    try:
        print('ABPDEEP', label, '=', fn())
    except Exception as e:
        print('ABPDEEP', label, 'ERROR:', e)
abp = unreal.EditorAssetLibrary.load_asset(P)
show('asset class', lambda: abp.get_class().get_name())
reg = unreal.AssetRegistryHelpers.get_asset_registry()
data = reg.get_asset_by_object_path(P + '.' + P.split('/')[-1])
show('ParentClass tag', lambda: data.get_tag_value('ParentClass'))
show('NativeParentClass tag', lambda: data.get_tag_value('NativeParentClass'))
show('GeneratedClass tag', lambda: data.get_tag_value('GeneratedClass'))
for prop in ('function_graphs', 'macro_graphs', 'delegate_signature_graphs', 'ubergraph_pages', 'animation_graphs'):
    show(prop, lambda p=prop: [g.get_name() for g in abp.get_editor_property(p)])
def nodes_probe():
    gs = abp.get_editor_property('function_graphs')
    if not gs:
        return 'no function graphs'
    g = gs[0]
    try:
        return 'graph %s nodes prop count %d' % (g.get_name(), len(g.get_editor_property('nodes')))
    except Exception as e:
        return 'nodes prop ERROR: %s' % e
show('graph nodes probe', nodes_probe)
all_data = reg.get_assets_by_path('/Game/ParagonCountess', recursive=True)
c = Counter()
names = {}
for d in all_data:
    cn = str(d.asset_class_path.asset_name)
    c[cn] += 1
    if cn in ('AnimSequence', 'AnimMontage', 'BlendSpace'):
        names.setdefault(cn, []).append(str(d.object_path))
print('ABPDEEP pack class census:', dict(c))
for cn in ('AnimSequence', 'AnimMontage', 'BlendSpace'):
    print('ABPDEEP', cn, 'count', len(names.get(cn, [])))
    for p in names.get(cn, [])[:60]:
        print('ABPDEEP', cn, p)
print('ABPDEEP DONE')
'@
New-Item -ItemType Directory -Force -Path 'D:\OMNI-UE\Scripts' | Out-Null
Set-Content -Path 'D:\OMNI-UE\Scripts\abp_deep_read.py' -Value $py -Encoding UTF8
$log = 'D:\OMNI-UE\Saved\abp-deep.log'
Write-Output '=== ABP deep read (job 194 follow-up, shaped by the Gemini fold): parent class via the asset-registry tags (the direct API call errored in 194), the full graph inventory incl. the AnimGraph, whether Python can see graph nodes at all, and the Countess pack census of AnimSequences / Montages / BlendSpaces - the material any rebuild route has to work with. One question: what exactly can be repaired or rebuilt by script? ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read.py' -abslog=$log -unattended -nopause | Out-Null
Select-String -Path $log -Pattern 'ABPDEEP|Error|Traceback|Exception' | ForEach-Object { $_.Line }
```
