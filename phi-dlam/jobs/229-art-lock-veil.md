# Job 229 — ART LOCK, VEIL: no primitives standing, real meshes in, unified palette (Meta direction, record-corrected targets)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The replace rule lands with record-true targets. Meta AI named the rule - find placeholders, swap final meshes at the same transform, one unified palette, primitives to zero - and named assets that DO NOT EXIST (SM_PhiSpiral_Tower, SM_VEL_Curve, M_Gold_Navy, an ACubePlaceholder class, BLOCK tags). None of those run. The measured form: targets are StaticMeshActors carrying engine BasicShapes (Cube/Cylinder/Sphere); replacements are the largest real architectural meshes the registry actually holds (census first, names machine-read); the palette is created fresh at /Game/PHI/Palette - gold, deep blue, white emissive - because M_Gold_Navy does not exist. Maps: VEILWorld, VEILDistrict. If the census finds no candidates, the maps stay untouched and the job says so. ==='
$py = @'
import unreal
lines = []
def emit(s):
    lines.append(str(s)); unreal.log_warning(str(s))
MEL = unreal.MaterialEditingLibrary
def ensure_palette():
    pals = {}
    specs = {
      'M_PHI_Gold':        ((1.0, 0.72, 0.28), 1.0, 0.32, None),
      'M_PHI_DeepBlue':    ((0.015, 0.06, 0.30), 0.6, 0.40, None),
      'M_PHI_WhiteEmissive':((0.90, 0.92, 1.0), 0.0, 0.50, (1.6, 1.7, 2.0)),
    }
    unreal.EditorAssetLibrary.make_directory('/Game/PHI/Palette')
    for name, (rgb, metal, rough, emis) in specs.items():
        path = '/Game/PHI/Palette/' + name
        m = unreal.EditorAssetLibrary.load_asset(path)
        if m:
            pals[name] = m; emit('PALETTE %s exists' % name); continue
        try:
            m = unreal.AssetToolsHelpers.get_asset_tools().create_asset(name, '/Game/PHI/Palette', unreal.Material, unreal.MaterialFactoryNew())
            c = MEL.create_material_expression(m, unreal.MaterialExpressionConstant3Vector, -400, 0)
            c.set_editor_property('constant', unreal.LinearColor(rgb[0], rgb[1], rgb[2], 1.0))
            MEL.connect_material_property(c, '', unreal.MaterialProperty.MP_BASE_COLOR)
            cm = MEL.create_material_expression(m, unreal.MaterialExpressionConstant, -400, 200)
            cm.set_editor_property('r', metal)
            MEL.connect_material_property(cm, '', unreal.MaterialProperty.MP_METALLIC)
            cr = MEL.create_material_expression(m, unreal.MaterialExpressionConstant, -400, 300)
            cr.set_editor_property('r', rough)
            MEL.connect_material_property(cr, '', unreal.MaterialProperty.MP_ROUGHNESS)
            if emis:
                e = MEL.create_material_expression(m, unreal.MaterialExpressionConstant3Vector, -400, -200)
                e.set_editor_property('constant', unreal.LinearColor(emis[0], emis[1], emis[2], 1.0))
                MEL.connect_material_property(e, '', unreal.MaterialProperty.MP_EMISSIVE_COLOR)
            MEL.layout_material_expressions(m)
            MEL.recompile_material(m)
            unreal.EditorAssetLibrary.save_asset(path)
            pals[name] = m; emit('PALETTE %s created' % name)
        except Exception as ex:
            emit('PALETTE %s FAILED: %s' % (name, ex))
    return pals
def census():
    reg = unreal.AssetRegistryHelpers.get_asset_registry()
    filt = unreal.ARFilter(package_paths=['/Game'], recursive_paths=True)
    skip = ('BasicShapes', '/ParagonCountess/', '/Mannequins/', '/ParagonMinions/', 'Characters')
    paths = []
    for d in reg.get_assets(filt):
        try: cn = str(d.asset_class_path.asset_name)
        except Exception: cn = '?'
        if cn != 'StaticMesh': continue
        p = '%s.%s' % (d.package_name, d.asset_name)
        if any(s in p for s in skip): continue
        paths.append(p)
    cands = []
    for p in sorted(paths)[:90]:
        try:
            mesh = unreal.EditorAssetLibrary.load_asset(p)
            ext = mesh.get_bounds().box_extent
            mx = max(ext.x, ext.y, ext.z)
            if mx >= 150.0:
                cands.append((ext.x * ext.y * ext.z, p, (ext.x, ext.y, ext.z)))
        except Exception:
            pass
    cands.sort(reverse=True)
    emit('CENSUS candidates >=150cm: %d (of %d static meshes scanned)' % (len(cands), len(paths)))
    for v, p, e in cands[:12]:
        emit('CAND %s extent=(%.0f, %.0f, %.0f)' % (p, e[0], e[1], e[2]))
    return [p for v, p, e in cands], dict((p, e) for v, p, e in cands)
def is_prim(comp):
    try:
        m = comp.get_editor_property('static_mesh')
        return m is not None and 'BasicShapes' in m.get_path_name()
    except Exception:
        return False
def dress(map_path, pals, cand_paths, cand_ext):
    w = unreal.EditorLoadingAndSavingUtils.load_map(map_path)
    sub = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    actors = list(sub.get_all_level_actors())
    prims = []
    for a in actors:
        if a.get_class().get_name() != 'StaticMeshActor': continue
        comp = a.get_component_by_class(unreal.StaticMeshComponent)
        if comp and is_prim(comp): prims.append((a, comp))
    emit('DRESS %s primitives before: %d' % (map_path, len(prims)))
    if not cand_paths:
        emit('DRESS %s NO CANDIDATES - map untouched' % map_path); return
    swaps = 0
    for i, (a, comp) in enumerate(prims):
        origin, ext = a.get_actor_bounds(False)
        S = (ext.x * 2, ext.y * 2, ext.z * 2)
        cp = cand_paths[i % len(cand_paths)]
        ce = cand_ext[cp]
        M = (ce[0] * 2, ce[1] * 2, ce[2] * 2)
        f = max(S) / max(M)
        try:
            mesh = unreal.EditorAssetLibrary.load_asset(cp)
            comp.set_static_mesh(mesh)
            a.set_actor_scale3d(unreal.Vector(f, f, f))
            if S[2] > 1200 and 'M_PHI_Gold' in pals: comp.set_material(0, pals['M_PHI_Gold'])
            elif min(S[0], S[1]) < 130 and S[2] > 250 and 'M_PHI_WhiteEmissive' in pals: comp.set_material(0, pals['M_PHI_WhiteEmissive'])
            elif 'M_PHI_DeepBlue' in pals: comp.set_material(0, pals['M_PHI_DeepBlue'])
            swaps += 1
        except Exception as ex:
            emit('DRESS swap ERROR on %s: %s' % (a.get_actor_label(), ex))
    left = 0
    for a in actors:
        if a.get_class().get_name() != 'StaticMeshActor': continue
        comp = a.get_component_by_class(unreal.StaticMeshComponent)
        if comp and is_prim(comp): left += 1
    emit('DRESS %s swaps: %d, primitives after: %d' % (map_path, swaps, left))
    if swaps > 0:
        ok = unreal.EditorLoadingAndSavingUtils.save_map(w, map_path)
        emit('DRESS %s save_map -> %s' % (map_path, ok))
pals = ensure_palette()
cand_paths, cand_ext = census()
for mp in ['/Game/Maps/VEILWorld', '/Game/Maps/VEILDistrict']:
    dress(mp, pals, cand_paths, cand_ext)
emit('ARTLOCK DONE')
with open(r'D:\VEIL\Saved\artlock_out.txt', 'w') as fh:
    fh.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\art_lock.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\art_lock.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Exception' | ForEach-Object { $_.Line }
Write-Output "run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\artlock_out.txt') { Get-Content 'D:\VEIL\Saved\artlock_out.txt' } else { Write-Output 'ARTLOCK OUTPUT ABSENT' }
```
