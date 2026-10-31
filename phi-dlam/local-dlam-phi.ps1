$PHI = 1.618033988749895
$ErrorActionPreference = "SilentlyContinue"
Stop-Process -Name UnrealEditor -Force
Stop-Process -Name ollama -Force
Remove-Item "D:\VEIL-OMNI\Saved\Logs\seat719_out.txt" -Force
Remove-Item "D:\VEIL-OMNI\Saved\survey_out.txt" -Force
Write-Host "LOCAL DLAM - phi authority lock - seat first - NV_ONLY"
$seat = @"
import unreal
PHI = 1.618033988749895
try:
    unreal.EditorLoadingAndSavingUtils.load_map("/Game/Maps/VEILDistrict")
except:
    pass
for a in unreal.EditorLevelLibrary.get_all_level_actors():
    try:
        if "countess" in a.get_actor_label().lower():
            unreal.EditorLevelLibrary.destroy_actor(a)
    except:
        pass
loc_v = unreal.Vector(0,0,-50*PHI)
loc_c = unreal.Vector(500*PHI,-500/PHI,40*PHI)
rot = unreal.Rotator(0,0,0)
actor_v = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, loc_v, rot)
actor_v.set_actor_label("VAULT_PHI")
actor_c = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkeletalMeshActor, loc_c, rot)
actor_c.set_actor_label("SM_Countess_SINGLE_PHI")
loc_f = unreal.Vector(0,0,-50*PHI)
actor_f = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, loc_f, rot)
actor_f.set_actor_label("PHI_FLOOR_PAD_1618")
loc_n = unreal.Vector(0,0,0)
actor_n = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.NavMeshBoundsVolume, loc_n, rot)
actor_n.set_actor_label("NavMesh_PHI_1618")
unreal.EditorLevelLibrary.build_level()
unreal.EditorLoadingAndSavingUtils.save_map("/Game/Maps/VEILDistrict","/Game/Maps/VEILDistrict")
"@
$seat | Out-File -FilePath "D:\VEIL-OMNI\Saved\seat719_temp.py" -Encoding utf8
$ue = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $ue "D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719_temp.py" -log -stdout
Get-Item "D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap" | Select-Object Length, LastWriteTime
Get-Content "D:\VEIL-OMNI\Saved\Logs\seat719_out.txt" -ErrorAction SilentlyContinue | Select-Object -Last 30
