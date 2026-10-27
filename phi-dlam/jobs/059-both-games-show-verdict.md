<!-- PHI-DIRECT -->
# JOB 059 - BOTH GAMES: SHOW VERDICT (DIRECT)

Reads the builds from jobs 057 (VEIL world tranche) and 058 (OMNI first
build). When a build is done, launches that game with -game so the
GameMode runs and the world builds, then reads the game's own log for the
world-built line. VEIL's game window is LEFT OPEN for Tyree; OMNI's is
closed after its verdict (one game window at a time on the 3050).

```powershell
$waited = 0
while ($waited -lt 200) {
  $procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
  if (@($procs).Count -eq 0) { break }
  Start-Sleep -Seconds 25; $waited += 25
}
"BUILD DRAIN WAITED: $waited s"
"--- VEIL build10 tail ---"
Get-Content 'D:\VEIL\build10-out.log' -Tail 3 -ErrorAction SilentlyContinue
Get-Content 'D:\VEIL\build10-err.log' -Tail 3 -ErrorAction SilentlyContinue
"--- OMNI build1 tail ---"
Get-Content 'D:\OMNI-UE\build1-out.log' -Tail 3 -ErrorAction SilentlyContinue
Get-Content 'D:\OMNI-UE\build1-err.log' -Tail 3 -ErrorAction SilentlyContinue
$editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
"=== VEIL -game ==="
$veilDll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
if (Test-Path $veilDll) {
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g.Refresh()
  "VEIL GAME: running=$(-not $g.HasExited) pid=$($g.Id) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\VEIL\Saved\Logs\VEIL.log' -Tail 300 -ErrorAction SilentlyContinue | Select-String -Pattern 'VEIL WORLD BUILT|VEIL world booted|Error|Fatal' | Select-Object -Last 8 | ForEach-Object { $_.Line }
} else { "VEIL GAME: DLL MISSING - build10 failed, see tail above" }
"=== OMNI -game ==="
$omniDll = 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll'
if (Test-Path $omniDll) {
  $g2 = Start-Process -FilePath $editor -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g2.Refresh()
  "OMNI GAME: running=$(-not $g2.HasExited) pid=$($g2.Id) window='$($g2.MainWindowTitle)'"
  Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 300 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI world booted|Error|Fatal' | Select-Object -Last 8 | ForEach-Object { $_.Line }
  if (-not $g2.HasExited) { $null = $g2.CloseMainWindow(); Start-Sleep -Seconds 3; if (-not $g2.HasExited) { Stop-Process -Id $g2.Id -Force -ErrorAction SilentlyContinue } }
  "OMNI game closed after verdict (VEIL stays open)."
} else { "OMNI GAME: DLL MISSING - build1 failed or still running, see tail above" }
"=== JOB 059 DONE ==="
```
