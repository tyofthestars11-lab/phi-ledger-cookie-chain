<!-- PHI-DIRECT -->
# JOB 063 - OMNI REBUILD AFTER UPROJECT FIX (DIRECT)

Root cause found at the source (2026-10-27): OMNI.uproject was mangled to
a truncated, invalid JSON during the clone - that is why build1/build2 died
in under a second. The repo now carries a clean, validated uproject. This
job syncs it, rebuilds OMNI, and shows the game.

```powershell
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\OMNI') 'D:\OMNI-UE' /MIR /NFL /NDL /NJH /XD Binaries Intermediate Saved DerivedDataCache | Out-Null
"SYNCED: OMNI project (fixed uproject)"
try { Get-Content 'D:\OMNI-UE\OMNI.uproject' -Raw | ConvertFrom-Json | Out-Null; "UPROJECT JSON: VALID" } catch { "UPROJECT JSON: INVALID - $($_.Exception.Message)" }
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$p = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build3-out.log' -RedirectStandardError 'D:\OMNI-UE\build3-err.log' -PassThru -WindowStyle Hidden
"BUILD3 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 200
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll'
"AFTER 200 s: build processes=$(@($procs).Count) dll=$((Get-Item $dll -ErrorAction SilentlyContinue).LastWriteTime)"
Get-Content 'D:\OMNI-UE\build3-out.log' -Tail 4 -ErrorAction SilentlyContinue
Get-Content 'D:\OMNI-UE\build3-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error' | Select-Object -First 10 | ForEach-Object { $_.Line }
if (Test-Path $dll) {
  $editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g.Refresh()
  "OMNI GAME: running=$(-not $g.HasExited) window='$($g.MainWindowTitle)'"
  Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI QUEST|OMNI world booted|Error|Fatal' | Select-Object -Last 12 | ForEach-Object { $_.Line }
  if (-not $g.HasExited) { $null = $g.CloseMainWindow(); Start-Sleep -Seconds 3; if (-not $g.HasExited) { Stop-Process -Id $g.Id -Force -ErrorAction SilentlyContinue } }
  "OMNI game closed after verdict."
} else { "OMNI GAME: DLL MISSING - build3 still running or failed, error lines above carry the cause." }
"=== JOB 063 DONE ==="
```
