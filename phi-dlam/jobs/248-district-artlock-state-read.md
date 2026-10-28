# Job 248 — District art-lock state read: 241 timed out, its progress file holds the truth

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 241 (VEIL District dress) TIMED OUT at 240s with no output in its result - but 241 was built to rewrite its progress file after every phase precisely so a timeout cannot hide the state. Job 242 then verified the VEIL palette EXISTS (all three) and dressed VEILWorld whole, so 241 got at least as far as palette creation. This job reads the progress file whole and counts Districts remaining BasicShapes carriers directly. Read-only, one map, fast. ==='
Write-Output '--- artlock_district_out.txt ---'
if (Test-Path 'D:\VEIL\Saved\artlock_district_out.txt') { Get-Content 'D:\VEIL\Saved\artlock_district_out.txt' } else { Write-Output 'progress file ABSENT - 241 wrote nothing before the timeout' }
$py = @'
import unreal, os
unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")
actors = unreal.EditorLevelLibrary.get_all_level_actors()
basic = 0
total = 0
for a in actors:
    total += 1
    if isinstance(a, unreal.StaticMeshActor):
        mesh = a.static_mesh_component.static_mesh
        if mesh and "BasicShapes" in mesh.get_path_name():
            basic += 1
with open(r"D:\VEIL\Saved\Logs\district_state.txt", "w") as f:
    f.write("DISTRICT actors=%d basicshapes=%d\n" % (total, basic))
'@
$enc = New-Object System.Text.UTF8Encoding($false)
[IO.File]::WriteAllText('D:\VEIL\Scripts\district_state.py', $py, $enc)
$run = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' '-run=PythonScript' '-script=D:\VEIL\Scripts\district_state.py' '-abslog=D:\VEIL\Saved\Logs\district_state_cmd.log' -unattended 2>&1
$run | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 6 | ForEach-Object { $_.Line }
Get-Content 'D:\VEIL\Saved\Logs\district_state.txt' -ErrorAction SilentlyContinue
```
