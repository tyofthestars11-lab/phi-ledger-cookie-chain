# Job 245 — NOT-BLOCKS PROOF: the after-audit for jobs 241-243, measured on the mesh each actor carries

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The proof audit for the art-lock redo, built on the measurement that actually separates blocks from dressed actors: the MESH PATH an actor carries, not its label. Job 237s census is the instrument - an actor is a block iff its StaticMesh path contains BasicShapes. Metas pasted audit read actor labels and unit scale instead: our blockout actors carry generated labels, and the towers are primitives scaled LARGE, so that audit would print block_actors=0 over worlds where 231 primitives stand - a false clean. Its destroy-by-label job also never saved the map, so even its removals would not persist; and removal is not the fix on this record - 241-243 SWAP the carriers to real registry meshes at the same transform and save, keeping the districts layout. This census runs after them: per map, BasicShapes count (the verdict line), plus Metas one sound check kept as a secondary read - any actor LABEL containing cube/block/box gets named - plus palette existence per project. Read-only. ==='
$py = @'
import unreal, os

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
        labelled = []
        for a in actors:
            total += 1
            try:
                lab = a.get_actor_label().lower()
                if ("cube" in lab or "block" in lab or "box" in lab) and "countess" not in lab:
                    labelled.append(a.get_actor_label())
            except Exception:
                pass
            if isinstance(a, unreal.StaticMeshActor):
                mesh = a.static_mesh_component.static_mesh
                if mesh and "BasicShapes" in mesh.get_path_name():
                    basic += 1
        out.append("MAP %s actors=%d basicshapes=%d" % (m, total, basic))
        out.append("MAP %s label_hits=%d %s" % (m, len(labelled), labelled[:12]))
    return out

proj = unreal.Paths.project_dir()
if "OMNI" in proj:
    lines = census(["/Game/Maps/OMNIWorld"])
else:
    lines = census(["/Game/Maps/VEILWorld", "/Game/Maps/VEILDistrict"])
path = os.path.join(proj, "Saved", "Logs", "not_blocks_proof.txt")
with open(path, "w") as f:
    f.write("\n".join(lines) + "\n")
'@
$enc = New-Object System.Text.UTF8Encoding($false)
$cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
foreach ($g in @(@('VEIL','D:\VEIL\VEIL.uproject','D:\VEIL'), @('OMNI','D:\OMNI-UE\OMNI.uproject','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]; $dir = $g[2]
  New-Item -ItemType Directory -Force -Path "$dir\Scripts" | Out-Null
  [IO.File]::WriteAllText("$dir\Scripts\not_blocks_proof.py", $py, $enc)
  Write-Output "--- $name ---"
  $run = & $cmd $proj '-run=PythonScript' "-script=$dir\Scripts\not_blocks_proof.py" "-abslog=$dir\Saved\Logs\not_blocks_proof_cmd.log" -unattended 2>&1
  $run | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 6 | ForEach-Object { $_.Line }
  Get-Content "$dir\Saved\Logs\not_blocks_proof.txt" -ErrorAction SilentlyContinue
}
```
