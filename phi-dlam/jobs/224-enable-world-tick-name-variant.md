# Job 224 — The last unread flag, second spelling: enable_world_tick (Python strips the b prefix)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 219 read the maps and the WorldSettings fine, but b_enable_world_tick and pauser are not Python-visible under those names. Unreal Python strips the b prefix from bool properties: the spelling to try is enable_world_tick. Pauser is runtime-only state (the proof already measured paused=0), so this job is the tick flag alone, all three maps, file output. If it reads False anywhere: set True and save that map in the same motion. If True everywhere, the last flag on the frozen-clock board closes. ==='
$py = @'
import unreal
lines = []
def emit(s):
    lines.append(str(s)); unreal.log_warning(str(s))
for m in ['/Game/Maps/VEILWorld', '/Game/Maps/VEILDistrict', '/Game/Maps/OMNIWorld']:
    try:
        w = unreal.EditorLoadingAndSavingUtils.load_map(m)
        ws = w.get_world_settings()
        v = None
        try:
            v = ws.get_editor_property('enable_world_tick')
            emit('WS2 %s enable_world_tick = %s' % (m, v))
        except Exception as e:
            emit('WS2 %s enable_world_tick ERROR: %s' % (m, e))
        if v is not None and not v:
            ws.set_editor_property('enable_world_tick', True)
            ok = unreal.EditorLoadingAndSavingUtils.save_map(w, m)
            emit('WS2 %s SET True + save_map -> %s' % (m, ok))
    except Exception as e:
        emit('WS2 %s MAP ERROR: %s' % (m, e))
emit('WS2 DONE')
with open(r'D:\VEIL\Saved\ws2_out.txt', 'w') as f:
    f.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\ws_read3.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read3.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Exception' | ForEach-Object { $_.Line }
Write-Output "run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\ws2_out.txt') { Get-Content 'D:\VEIL\Saved\ws2_out.txt' } else { Write-Output 'WS2 OUTPUT ABSENT' }
```
