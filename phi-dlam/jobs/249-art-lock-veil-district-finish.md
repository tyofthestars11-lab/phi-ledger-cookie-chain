# Job 249 — ART LOCK FINISH, VEIL District: swap pass only, candidates from job 242's measured census

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 241 timed out on the District carrying palette creation + census + swaps in one run. Both slow phases are now already done and measured: the palette EXISTS in VEIL (job 242 verified all three) and 242s census named the candidate meshes with extents. This job is the swap pass alone: load District, swap every BasicShapes carrier onto the record-named candidates at the same bounds, palette by 229s shape rule, recount, save. If 248 shows the District already dressed (241 finished before its output died), the recount reads 0 swaps needed and the map stands untouched. ==='
$py = @'
import unreal
OUT = r'D:\VEIL\Saved\artlock_district_finish_out.txt'
lines = []
def emit(s):
    lines.append(str(s)); unreal.log_warning(str(s))
    try:
        with open(OUT, 'w') as fh: fh.write('\n'.join(lines))
    except Exception: pass
CANDS = [
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01', (51057, 51057, 20076)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02', (51200, 51200, 18841)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain.SM_Iceland_Eroded_Mountain', (51200, 51200, 17643)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Plateus_01.SM_Iceland_Plateus_01', (51200, 51200, 5629)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Crest.SM_Iceland_Crest', (51200, 51200, 3810)),
  ('/Game/ParagonGreystone/FX/Meshes/Heroes/SM_Greystone_SlowDome.SM_Greystone_SlowDome', (596, 596, 599)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_02.SM_Mountain_02', (512, 512, 238)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_05.SM_Mountain_05', (512, 512, 207)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_07.SM_Mountain_07', (512, 512, 191)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_Plateu_01.SM_Mountain_Plateu_01', (512, 512, 176)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_09.SM_Mountain_09', (512, 512, 145)),
  ('/Game/Iceland_Environment/Static_Meshes/SM_Mountain_06.SM_Mountain_06', (512, 512, 116)),
]
pals = {}
for name in ['M_PHI_Gold', 'M_PHI_DeepBlue', 'M_PHI_WhiteEmissive']:
    m = unreal.EditorAssetLibrary.load_asset('/Game/PHI/Palette/' + name)
    emit('PALETTE %s loaded=%s' % (name, m is not None))
    if m: pals[name] = m
def is_prim(comp):
    try:
        m = comp.get_editor_property('static_mesh')
        return m is not None and 'BasicShapes' in m.get_path_name()
    except Exception:
        return False
w = unreal.EditorLoadingAndSavingUtils.load_map('/Game/Maps/VEILDistrict')
sub = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
actors = list(sub.get_all_level_actors())
prims = []
for a in actors:
    if a.get_class().get_name() != 'StaticMeshActor': continue
    comp = a.get_component_by_class(unreal.StaticMeshComponent)
    if comp and is_prim(comp): prims.append((a, comp))
emit('DISTRICT primitives before: %d' % len(prims))
cache = {}
swaps = 0
for i, (a, comp) in enumerate(prims):
    origin, ext = a.get_actor_bounds(False)
    S = (ext.x * 2, ext.y * 2, ext.z * 2)
    cp, ce = CANDS[i % len(CANDS)]
    M = (ce[0] * 2, ce[1] * 2, ce[2] * 2)
    f = max(S) / max(M)
    try:
        if cp not in cache: cache[cp] = unreal.EditorAssetLibrary.load_asset(cp)
        comp.set_static_mesh(cache[cp])
        a.set_actor_scale3d(unreal.Vector(f, f, f))
        if S[2] > 1200 and 'M_PHI_Gold' in pals: comp.set_material(0, pals['M_PHI_Gold'])
        elif min(S[0], S[1]) < 130 and S[2] > 250 and 'M_PHI_WhiteEmissive' in pals: comp.set_material(0, pals['M_PHI_WhiteEmissive'])
        elif 'M_PHI_DeepBlue' in pals: comp.set_material(0, pals['M_PHI_DeepBlue'])
        swaps += 1
    except Exception as ex:
        emit('swap ERROR on %s: %s' % (a.get_actor_label(), ex))
left = 0
for a in actors:
    if a.get_class().get_name() != 'StaticMeshActor': continue
    comp = a.get_component_by_class(unreal.StaticMeshComponent)
    if comp and is_prim(comp): left += 1
emit('DISTRICT swaps: %d, primitives after: %d' % (swaps, left))
if swaps > 0:
    ok = unreal.EditorLoadingAndSavingUtils.save_map(w, '/Game/Maps/VEILDistrict')
    emit('DISTRICT save_map -> %s' % ok)
emit('ARTLOCK DISTRICT FINISH DONE')
'@
$enc = New-Object System.Text.UTF8Encoding($false)
[IO.File]::WriteAllText('D:\VEIL\Scripts\art_lock_district_finish.py', $py, $enc)
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\VEIL\Scripts\art_lock_district_finish.py' -abslog='D:\VEIL\Saved\Logs\artlock_district_finish.log' -unattended -nopause 2>&1 | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\artlock_district_finish_out.txt') { Get-Content 'D:\VEIL\Saved\artlock_district_finish_out.txt' } else { Write-Output 'FINISH OUTPUT ABSENT' }
```
