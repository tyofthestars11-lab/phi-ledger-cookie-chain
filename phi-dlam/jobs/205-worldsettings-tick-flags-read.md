# Job 205 — WorldSettings tick flags read, both maps, both games (Meta AI ex.3's surviving measurement)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$py = @'
import unreal
MAPS = [
    '/Game/Maps/VEILWorld', '/Game/Maps/VEILDistrict',
    '/Game/Maps/OMNIWorld',
]
for m in MAPS:
    try:
        w = unreal.EditorLoadingAndSavingUtils.load_map(m)
        ws = w.get_world_settings()
        print('WSREAD', m, 'worldsettings class:', ws.get_class().get_name())
        for prop in ('b_enable_world_tick', 'pauser', 'time_dilation', 'min_global_time_dilation', 'max_global_time_dilation'):
            try:
                print('WSREAD', m, prop, '=', ws.get_editor_property(prop))
            except Exception as e:
                print('WSREAD', m, prop, 'ERROR:', e)
        lv = w.get_editor_property('persistent_level')
        print('WSREAD', m, 'persistent level actors:', len(lv.get_editor_property('actors')) if lv else None)
    except Exception as e:
        print('WSREAD', m, 'MAP ERROR:', e)
print('WSREAD DONE')
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\ws_read.py' -Value $py -Encoding UTF8
$console = 'D:\VEIL\Saved\ws-read-console.txt'
Write-Output '=== WorldSettings tick-flag read (Meta AI ex.3 fallback measurement, kept): the frozen-clock record already falsified pause (0) and dilation (1.000); the two flags never yet read are the WorldSettings own bEnableWorldTick and Pauser as persisted in the maps. VEIL maps read under VEIL, OMNIWorld under OMNI - the script runs twice, once per project. bAreActorsInitialized is runtime state and is not readable from a commandlet; this read takes what is readable. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "VEIL run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\OMNI-UE\OMNI.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "OMNI run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
```
