# Job 219 — WorldSettings tick flags v2: file output (job 215s script spoke through the dead print() channel)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 215 executed with the editors unblocked - and produced zero WSREAD lines: its script (written for job 205) reports through Python print(), which this lanes console capture never carries, the same dead channel job 214 exposed. The flags are still unread, not unmeasurable. This v2 writes every finding to D:\VEIL\Saved\ws_out.txt and the job prints that file: WorldSettings bEnableWorldTick and Pauser as persisted in VEILWorld, VEILDistrict and OMNIWorld. If bEnableWorldTick sits at False in the maps, the frozen clocks root is in the data. ==='
$py = @'
import unreal
lines = []
def emit(s):
    lines.append(str(s))
    unreal.log_warning(str(s))
for label, maps in (('VEIL', ['/Game/Maps/VEILWorld', '/Game/Maps/VEILDistrict']), ('OMNI', ['/Game/Maps/OMNIWorld'])):
    for m in maps:
        try:
            w = unreal.EditorLoadingAndSavingUtils.load_map(m)
            ws = w.get_world_settings()
            emit('WSREAD %s worldsettings class: %s' % (m, ws.get_class().get_name()))
            for prop in ('b_enable_world_tick', 'pauser'):
                try:
                    emit('WSREAD %s %s = %s' % (m, prop, ws.get_editor_property(prop)))
                except Exception as e:
                    emit('WSREAD %s %s ERROR: %s' % (m, prop, e))
        except Exception as e:
            emit('WSREAD %s MAP ERROR: %s' % (m, e))
emit('WSREAD DONE')
with open(r'D:\VEIL\Saved\ws_out.txt', 'w') as f:
    f.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\ws_read2.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read2.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Exception' | ForEach-Object { $_.Line }
Write-Output "VEIL run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\ws_out.txt') { Get-Content 'D:\VEIL\Saved\ws_out.txt' } else { Write-Output 'WS OUTPUT ABSENT after VEIL run' }
Remove-Item 'D:\VEIL\Saved\ws_out.txt' -ErrorAction SilentlyContinue
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\OMNI-UE\OMNI.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read2.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Exception' | ForEach-Object { $_.Line }
Write-Output "OMNI run exit: $LASTEXITCODE"
if (Test-Path 'D:\VEIL\Saved\ws_out.txt') { Get-Content 'D:\VEIL\Saved\ws_out.txt' } else { Write-Output 'WS OUTPUT ABSENT after OMNI run' }
```
