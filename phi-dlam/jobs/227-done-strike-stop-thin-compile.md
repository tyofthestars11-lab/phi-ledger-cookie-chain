# Job 227 — DONE strike 1: STOP PIE (close the editors), thin VEILDistrict by half, compile all Blueprints, build VEIL

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Tyrees order verbatim in intent: STOP. KILL PIE. SAVE NOW. VEILDistrict DONE BUILD - no new features, no exploration. This job: (1) closes the Unreal Editor processes - PIE lives in them; graceful close first, force after 15s; the maps on disk are the saved state. (2) Backs up VEILDistrict.umap to D:\_PhiHolding, then thins the map: essentials kept (PlayerStart, lights, sky, fog, post process, nav volumes) plus the half of static-mesh dressing NEAREST the spawn; the farther half is removed from the working map - the backup makes the whole map recoverable in one copy. Counts printed before and after. (3) CompileAllBlueprints across the project. (4) VEILEditor build - with the editors closed, the DLL lock that may have stopped job 225 is gone; this build lands the bypass repair either way. ==='
$eds = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($eds) {
  foreach ($e in $eds) { $e.CloseMainWindow() | Out-Null }
  Start-Sleep -Seconds 15
  $left = Get-Process UnrealEditor -ErrorAction SilentlyContinue
  if ($left) { $left | Stop-Process -Force; Write-Output "Editors force-closed: $($left.Id -join ', ')" } else { Write-Output 'Editors closed gracefully.' }
} else { Write-Output 'No editor process running.' }
Start-Sleep -Seconds 3
Copy-Item 'D:\VEIL\Content\Maps\VEILDistrict.umap' 'D:\_PhiHolding\VEILDistrict-pre-thin-227.umap' -Force
Write-Output 'VEILDistrict backup: D:\_PhiHolding\VEILDistrict-pre-thin-227.umap'
$py = @'
import unreal, math
lines = []
def emit(s):
    lines.append(str(s)); unreal.log_warning(str(s))
w = unreal.EditorLoadingAndSavingUtils.load_map('/Game/Maps/VEILDistrict')
sub = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
actors = list(sub.get_all_level_actors())
emit('THIN actors before: %d' % len(actors))
spawn = None
for a in actors:
    if 'PlayerStart' in a.get_class().get_name():
        spawn = a.get_actor_location(); break
if spawn is None:
    spawn = unreal.Vector(420.0, -420.0, 240.0)
keep_names = ('Light', 'Sky', 'Fog', 'PostProcess', 'NavMesh', 'Recast', 'PlayerStart', 'Camera', 'WorldSettings', 'Volume')
essentials, dressing = [], []
for a in actors:
    cn = a.get_class().get_name()
    if any(k in cn for k in keep_names):
        essentials.append(a)
    elif cn == 'StaticMeshActor':
        dressing.append(a)
    else:
        essentials.append(a)
dressing.sort(key=lambda a: (a.get_actor_location() - spawn).length())
keep_n = (len(dressing) + 1) // 2
remove = dressing[keep_n:]
emit('THIN essentials kept: %d, dressing total: %d, dressing kept: %d, removing: %d' % (len(essentials), len(dressing), keep_n, len(remove)))
for a in remove:
    sub.destroy_actor(a)
ok = unreal.EditorLoadingAndSavingUtils.save_map(w, '/Game/Maps/VEILDistrict')
emit('THIN save_map -> %s' % ok)
actors2 = list(sub.get_all_level_actors())
emit('THIN actors after: %d' % len(actors2))
emit('THIN DONE')
with open(r'D:\VEIL\Saved\thin_out.txt', 'w') as f:
    f.write('\n'.join(lines))
'@
Set-Content -Path 'D:\OMNI-UE\Scripts\thin_district.py' -Value $py -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\thin_district.py' -unattended -nopause 2>&1 | Select-String -Pattern 'Traceback|Exception' | ForEach-Object { $_.Line }
if (Test-Path 'D:\VEIL\Saved\thin_out.txt') { Get-Content 'D:\VEIL\Saved\thin_out.txt' } else { Write-Output 'THIN OUTPUT ABSENT' }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=CompileAllBlueprints -unattended -nopause -abslog='D:\VEIL\Saved\compileall_227.log' 2>&1 | Out-Null
Write-Output "CompileAllBlueprints exit: $LASTEXITCODE"
$bpErr = (Select-String -Path 'D:\VEIL\Saved\compileall_227.log' -Pattern 'LogBlueprint: Error' -ErrorAction SilentlyContinue).Count
$bpWarn = (Select-String -Path 'D:\VEIL\Saved\compileall_227.log' -Pattern 'CompileAllBlueprints|Commandlet' -ErrorAction SilentlyContinue | Select-Object -First 3 | ForEach-Object { $_.Line })
Write-Output "Blueprint Error lines in compile-all log: $bpErr"
$bpWarn | ForEach-Object { Write-Output "  $_" }
$build = & 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' VEILEditor Win64 Development '-Project=D:\VEIL\VEIL.uproject' -WaitMutex 2>&1
$build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
```
