# Job 259 — NAVMESH FIX, VEIL (re-queue of 256's VEIL half — 256 never executed: remoting transport break, "(no output)")

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 256 died at the runner transport (PSSessionStateBroken in Tyrees photo; its result is literally "(no output)") - nothing in it ran. This is its VEIL half, re-queued. The proven fix: job 081 set RuntimeGeneration=Dynamic in the ini (nav generates at runtime, build-lock cannot return), job 115 purged the stale RecastNavMesh (banner gone in his 13:52 photo). The art dress then replaced the geometry and the banner returned. Here: verify VEILs ini, census VEILDistrict + VEILWorld (recast, bounds, PlayerStart, ground under spawn with collision - his photo showed the Countess falling through the live world), purge stale recasts, place bounds where missing, BlockAll a no-collision ground carrier under spawn, save. ==='
$ini = 'D:\VEIL\Config\DefaultEngine.ini'
Select-String -Path $ini -Pattern 'RuntimeGeneration' | ForEach-Object { $_.Line.Trim() }
if (-not (Select-String -Path $ini -Pattern 'RuntimeGeneration=Dynamic' -Quiet)) { Add-Content $ini "`r`n[/Script/NavigationSystem.RecastNavMesh]`r`nRuntimeGeneration=Dynamic"; Write-Output 'RuntimeGeneration=Dynamic was MISSING - appended (job 081 re-applied)' } else { Write-Output 'RuntimeGeneration=Dynamic stands' }
$py = @'
import unreal

def fix_map(path):
    unreal.log("NAVFIX load " + path)
    ok = unreal.EditorLoadingAndSavingUtils.load_map(path)
    if not ok:
        unreal.log("NAVFIX LOAD FAILED " + path)
        return
    sub = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    actors = sub.get_all_level_actors()
    starts = [a for a in actors if a.get_class().get_name() == "PlayerStart"]
    recasts = [a for a in actors if a.get_class().get_name() == "RecastNavMesh"]
    bounds = [a for a in actors if a.get_class().get_name() == "NavMeshBoundsVolume"]
    unreal.log("NAVFIX census %s: actors=%d recast=%d bounds=%d playerstarts=%d" % (path, len(actors), len(recasts), len(bounds), len(starts)))
    for r in recasts:
        sub.destroy_actor(r)
        unreal.log("NAVFIX stale RecastNavMesh purged (job 115 pattern) - Dynamic regenerates at runtime")
    if len(bounds) == 0:
        mn = unreal.Vector(1e18, 1e18, 1e18); mx = unreal.Vector(-1e18, -1e18, -1e18)
        for a in actors:
            try:
                o, e = a.get_actor_bounds(False, False)
                mn = unreal.Vector(min(mn.x, o.x - e.x), min(mn.y, o.y - e.y), min(mn.z, o.z - e.z))
                mx = unreal.Vector(max(mx.x, o.x + e.x), max(mx.y, o.y + e.y), max(mx.z, o.z + e.z))
            except Exception:
                pass
        c = unreal.Vector((mn.x + mx.x) / 2.0, (mn.y + mx.y) / 2.0, (mn.z + mx.z) / 2.0)
        ext = unreal.Vector(max(mx.x - mn.x, 1000.0), max(mx.y - mn.y, 1000.0), max(mx.z - mn.z, 1000.0))
        v = sub.spawn_actor_from_class(unreal.NavMeshBoundsVolume, c)
        if v:
            v.set_actor_label("DistrictNavBounds")
            v.set_actor_scale3d(unreal.Vector(ext.x / 200.0, ext.y / 200.0, ext.z / 200.0))
            unreal.log("NAVFIX bounds volume placed (job 081 pattern)")
    for s in starts:
        loc = s.get_actor_location()
        unreal.log("NAVFIX PlayerStart at %s" % str(loc))
        below = []
        for a in actors:
            if a is s:
                continue
            try:
                o, e = a.get_actor_bounds(False, False)
                if abs(o.x - loc.x) <= e.x + 50 and abs(o.y - loc.y) <= e.y + 50 and (o.z + e.z) <= loc.z + 10:
                    below.append((loc.z - (o.z + e.z), a))
            except Exception:
                pass
        below.sort(key=lambda t: t[0])
        for gap, a in below[:3]:
            info = "NAVFIX ground candidate %s gap_below=%.0f class=%s" % (a.get_actor_label(), gap, a.get_class().get_name())
            try:
                comp = a.static_mesh_component
                info += " collision=%s profile=%s" % (str(comp.get_collision_enabled()), str(comp.get_editor_property("collision_profile_name")))
                if "NoCollision" in str(comp.get_collision_enabled()):
                    comp.set_collision_profile_name("BlockAll")
                    info += " -> SET BlockAll (nav and the pawn both stand on this)"
            except Exception as e:
                info += " collision read failed %s" % str(e)
            unreal.log(info)
    saved = unreal.EditorLoadingAndSavingUtils.save_current_level()
    unreal.log("NAVFIX save %s -> %s" % (path, str(saved)))

for m in ['/Game/Maps/VEILDistrict', '/Game/Maps/VEILWorld']:
    fix_map(m)
unreal.log("NAVFIX ALLDONE")
'@
$f = 'D:\_PhiHolding\navfix259.py'; Set-Content $f $py
$log = 'D:\_PhiHolding\navfix259.log'
$p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList @('D:\VEIL\VEIL.uproject', '-run=pythonscript', "-script=$f", '-unattended', '-nop4', '-nosplash', "-abslog=$log") -Wait -PassThru -NoNewWindow
Write-Output "navfix VEIL exit $($p.ExitCode)"
Select-String -Path $log -Pattern 'NAVFIX|Error' | ForEach-Object { $_.Line -replace '^\[[^\]]*\]\[[^\]]*\]', '' } | Select-Object -First 40
Write-Output 'NAVMESH FIX VEIL DONE'
```
