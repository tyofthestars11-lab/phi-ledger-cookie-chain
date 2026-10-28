# Job 237 — Art-lock state census: what jobs 229/230 actually left on disk (read-only, fast)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 229s result has not surfaced and job 230 TIMED OUT at 240s mid-flight - so the art locks true state is unmeasured, while 231/232 already packaged from these maps. This census is read-only and fast: per project, does the palette exist at /Game/PHI/Palette, and per map, how many actors still carry BasicShapes meshes. Writes results to FILES (the print channel is dead on this lane) and prints the files. ==='
$py = @'
import unreal

def census(project_maps):
    out = []
    pal = ["/Game/PHI/Palette/M_PHI_Gold", "/Game/PHI/Palette/M_PHI_DeepBlue", "/Game/PHI/Palette/M_PHI_WhiteEmissive"]
    for p in pal:
        out.append("PALETTE %s exists=%s" % (p, unreal.EditorAssetLibrary.does_asset_exist(p)))
    for m in project_maps:
        unreal.EditorLevelLibrary.load_level(m)
        actors = unreal.EditorLevelLibrary.get_all_level_actors()
        basic = 0
        total = 0
        for a in actors:
            total += 1
            if isinstance(a, unreal.StaticMeshActor):
                mesh = a.static_mesh_component.static_mesh
                if mesh and "BasicShapes" in mesh.get_path_name():
                    basic += 1
        out.append("MAP %s actors=%d basicshapes=%d" % (m, total, basic))
    return out

import os
proj = unreal.Paths.project_dir()
if "OMNI" in proj:
    lines = census(["/Game/Maps/OMNIWorld"])
    path = os.path.join(proj, "Saved", "Logs", "art_census.txt")
else:
    lines = census(["/Game/Maps/VEILWorld", "/Game/Maps/VEILDistrict"])
    path = os.path.join(proj, "Saved", "Logs", "art_census.txt")
with open(path, "w") as f:
    f.write("\n".join(lines) + "\n")
'@
$enc = New-Object System.Text.UTF8Encoding($false)
$cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
foreach ($g in @(@('VEIL','D:\VEIL\VEIL.uproject','D:\VEIL'), @('OMNI','D:\OMNI-UE\OMNI.uproject','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]; $dir = $g[2]
  [IO.File]::WriteAllText("$dir\Scripts\art_census.py", $py, $enc)
  Write-Output "--- $name ---"
  $run = & $cmd $proj '-run=PythonScript' "-script=$dir\Scripts\art_census.py" "-abslog=$dir\Saved\Logs\art_census_cmd.log" -unattended 2>&1
  $run | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 6 | ForEach-Object { $_.Line }
  Get-Content "$dir\Saved\Logs\art_census.txt" -ErrorAction SilentlyContinue
}
```
