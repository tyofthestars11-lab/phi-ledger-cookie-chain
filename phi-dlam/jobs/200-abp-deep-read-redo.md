# Job 200 — ABP deep read, redo (job 198's harness produced no log; abslog now sits under the project being run, console captured as second channel)

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
$log = 'D:\VEIL\Saved\abp-deep.log'
$console = 'D:\VEIL\Saved\abp-deep-console.txt'
Write-Output '=== ABP deep read REDO: job 198 produced no log at all (its abslog sat under the other project). This run seats the abslog under D:\VEIL\Saved (the project being run) and captures the console as a second channel. Same one question: parent class, graph inventory incl. the AnimGraph, node visibility, Countess pack animation census. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read.py' -abslog=$log -unattended -nopause 2>&1 | Set-Content $console
Write-Output "commandlet exit: $LASTEXITCODE"
if (Test-Path $log) {
  Write-Output "abslog exists: $((Get-Item $log).Length) bytes"
  Select-String -Path $log -Pattern 'ABPDEEP|Error|Traceback|Exception' | ForEach-Object { $_.Line }
} else {
  Write-Output 'abslog ABSENT again - console tail decides:'
  Get-Content $console -Tail 40
}
```
