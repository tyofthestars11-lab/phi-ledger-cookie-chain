<!-- PHI-DIRECT -->
# JOB 078 - VEIL DISTRICT: REAL ACTORS IN A SAVED LEVEL (DIRECT)

The art pass starts here. Scripts/build_district.py places real actors
into a saved level - DistrictGround, Plaza, Tower_00..39 wearing pack
materials, BeaconSpire + BeaconOrb, 12 lamp posts with orbs, the dusk
rig (DuskSun, SkyLight, SkyAtmosphere, DuskFog) and PlazaStart - all
named in the Outliner of /Game/Maps/VEILDistrict, the way a human
builds a level. No more runtime primitives over the debug grid.

This job: sync Source/Scripts/Config from the vault (Content is never
touched - job 075's extracted packs live there), merge the repo plugin
set into both .uproject files on D: (union - nothing removed, so any
plugins Tyree ticked in the editor window survive), inventory the
engine's geometry shelf, then launch the district build detached
through UnrealEditor-Cmd. The verdict rides job 081. Screen-free: if
the GUI editor is open, the launch defers itself and says so.

```powershell
$ErrorActionPreference = 'Continue'
"=== SYNC (Source, Scripts, Config - Content untouched) ==="
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Source D:\VEIL\Source /E /NFL /NDL /NJH | Out-Null
robocopy veil\VEIL\Scripts D:\VEIL\Scripts /E /NFL /NDL /NJH | Out-Null
robocopy veil\VEIL\Config D:\VEIL\Config /E /NFL /NDL /NJH | Out-Null
robocopy veil\OMNI\Source D:\OMNI-UE\Source /E /NFL /NDL /NJH | Out-Null
"SYNCED"
"=== PLUGIN UNION (repo set merged in, nothing removed) ==="
foreach ($pair in @(@{Pc='D:\VEIL\VEIL.uproject'; Repo='veil\VEIL\VEIL.uproject'}, @{Pc='D:\OMNI-UE\OMNI.uproject'; Repo='veil\OMNI\OMNI.uproject'})) {
  if ((Test-Path $pair.Pc) -and (Test-Path $pair.Repo)) {
    $pc = Get-Content $pair.Pc -Raw | ConvertFrom-Json
    $repo = Get-Content $pair.Repo -Raw | ConvertFrom-Json
    $have = @($pc.Plugins | ForEach-Object { $_.Name })
    foreach ($p in $repo.Plugins) { if ($have -notcontains $p.Name) { $pc.Plugins += $p; "ADDED to $($pair.Pc): $($p.Name)" } }
    [IO.File]::WriteAllText($pair.Pc, ($pc | ConvertTo-Json -Depth 10), (New-Object System.Text.UTF8Encoding($false)))
    "PLUGINS in $($pair.Pc): " + (($pc.Plugins | ForEach-Object { $_.Name }) -join ', ')
  } else { "SKIP union (missing): $($pair.Pc)" }
}
"=== ENGINE PLUGIN INVENTORY (geometry / modeling / pcg shelf) ==="
Get-ChildItem 'C:\Program Files\Epic Games\UE_5.8\Engine\Plugins' -Recurse -Filter *.uplugin -ErrorAction SilentlyContinue | Where-Object { $_.BaseName -match 'GeometryScripting|ModelingToolsEditorMode|PCG|PythonScriptPlugin|EditorScriptingUtilities' } | ForEach-Object { "FOUND: $($_.BaseName)" }
"=== DISTRICT BUILD LAUNCH ==="
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { "EDITOR OPEN - district build deferred; rerun this job with the editor closed" }
else {
  $log = 'D:\VEIL\Saved\district-build.log'
  Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList '"D:\VEIL\VEIL.uproject"','-run=PythonScript','-script="D:\VEIL\Scripts\build_district.py"','-unattended','-nop4','-nosplash',"-log=$log" -WindowStyle Hidden
  "DISTRICT BUILD LAUNCHED (detached) - verdict rides job 081"
}
"=== JOB 078 DONE ==="
```
