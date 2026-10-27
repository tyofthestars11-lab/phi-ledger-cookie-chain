# Job 223 — Navmesh rebuild, all three maps: the second banner addressed at the data

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Tyrees word: ADDRESS THIS FOR BOTH GAMES - the NAVMESH NEEDS TO BE REBUILT banner is stale navigation data: the worlds geometry moved after the last nav build. This job rebuilds navigation in VEILWorld, VEILDistrict and OMNIWorld and saves each map with its fresh Recast data. Route: Python first (NavigationSystemV1 build on the loaded editor world), console command as the second route (RebuildNavigation); every step writes markers to a file, and the saved maps timestamp is the receipt. ==='
$py = @'
import unreal, os
lines = []
def emit(s):
    lines.append(str(s)); unreal.log_warning(str(s))
maps = ['/Game/Maps/VEILWorld', '/Game/Maps/VEILDistrict', '/Game/Maps/OMNIWorld']
for m in maps:
    try:
        w = unreal.EditorLoadingAndSavingUtils.load_map(m)
        emit('NAV %s loaded' % m)
        built = False
        try:
            nav = unreal.NavigationSystemV1.get_navigation_system(w)
            emit('NAV %s nav system: %s' % (m, nav))
            if nav:
                nav.build()
                emit('NAV %s python build() called' % m)
                built = True
        except Exception as e:
            emit('NAV %s python build ERROR: %s' % (m, e))
        if not built:
            try:
                unreal.SystemLibrary.execute_console_command(w, 'RebuildNavigation')
                emit('NAV %s console RebuildNavigation issued' % m)
                built = True
            except Exception as e:
                emit('NAV %s console ERROR: %s' % (m, e))
        try:
            ok = unreal.EditorLoadingAndSavingUtils.save_map(w, m)
            emit('NAV %s save_map -> %s' % (m, ok))
        except Exception as e:
            emit('NAV %s save ERROR: %s' % (m, e))
    except Exception as e:
        emit('NAV %s MAP ERROR: %s' % (m, e))
emit('NAV DONE')
with open(r'D:\VEIL\Saved\nav_out.txt', 'w') as f:
    f.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\nav_build.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\nav_build.py' -unattended -nopause 2>&1 | Select-String -Pattern 'LogNavigation|RebuildNavigation|Traceback' | ForEach-Object { $_.Line }
Write-Output "VEIL maps run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\nav_out.txt') { Get-Content 'D:\VEIL\Saved\nav_out.txt' } else { Write-Output 'NAV OUTPUT ABSENT after VEIL run' }
Remove-Item 'D:\VEIL\Saved\nav_out.txt' -ErrorAction SilentlyContinue
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\OMNI-UE\OMNI.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\nav_build.py' -unattended -nopause 2>&1 | Select-String -Pattern 'LogNavigation|RebuildNavigation|Traceback' | ForEach-Object { $_.Line }
Write-Output "OMNI maps run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\nav_out.txt') { Get-Content 'D:\VEIL\Saved\nav_out.txt' } else { Write-Output 'NAV OUTPUT ABSENT after OMNI run' }
foreach ($m in @('D:\VEIL\Content\Maps\VEILWorld.umap','D:\VEIL\Content\Maps\VEILDistrict.umap','D:\OMNI-UE\Content\Maps\OMNIWorld.umap')) {
  if (Test-Path $m) { $i = Get-Item $m; Write-Output ("MAP {0} last-write {1}" -f $m, $i.LastWriteTime) }
}
```
