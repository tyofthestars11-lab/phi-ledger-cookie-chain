<!-- PHI-DIRECT -->
# JOB 072 - OMNI FOG FIX: BUILD 6, COMPILE ONLY (DIRECT)

REVISED per Tyree: no taking over the PC screen. This job never closes
the editor and never launches a game window. Compile + log read only;
the playable check is Tyree's when he opens it.

Build5's killer (job 068, verbatim): error C2039 -
'FogInscatteringColor' is not a member of
UExponentialHeightFogComponent in UE 5.8. Those writes are cut;
density only, same as VEIL. This build also carries the 1st/3rd person
camera toggle (V / R3) and the PHI LICENSE log line.

```powershell
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\OMNI\Source') 'D:\OMNI-UE\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\Config') 'D:\OMNI-UE\Config' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\OMNI.uproject') 'D:\OMNI-UE' /NFL /NDL /NJH | Out-Null
Copy-Item (Join-Path $repo 'veil\OMNI\PHI-LICENSE.md') 'D:\OMNI-UE\PHI-LICENSE.md' -Force
"SYNCED: OMNI Source + Config + uproject + PHI-LICENSE (fog fix, camera toggle)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\OMNI-UE\build6-out.log','D:\OMNI-UE\build6-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build6-out.log' -RedirectStandardError 'D:\OMNI-UE\build6-err.log' -PassThru -WindowStyle Hidden
"BUILD6 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 170
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = (Get-Item 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll' -ErrorAction SilentlyContinue).LastWriteTime
"AFTER 170 s: build processes=$(@($procs).Count) dll=$dll"
Get-Content 'D:\OMNI-UE\build6-out.log' -Tail 3 -ErrorAction SilentlyContinue
$e = Get-Content 'D:\OMNI-UE\build6-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error' | Select-Object -First 15 | ForEach-Object { $_.Line }
if ($e) { "--- BUILD6 ERRORS ---"; $e }
"STATE: code synced, compile read above. NOT launched (screen is Tyree's). Playable = unconfirmed until opened."
"=== JOB 072 DONE ==="
```
