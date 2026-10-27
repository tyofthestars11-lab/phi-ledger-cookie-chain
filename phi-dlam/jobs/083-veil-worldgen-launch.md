<!-- PHI-DIRECT -->
# JOB 083 - WORLD GENERATOR LAUNCH (VEIL) + TSR UPSCALING (DIRECT)

Tyree's order (2026-10-27): "Create a world generator." Scripts/
build_world.py generates a CONNECTED world - three sectors on the
golden spiral joined by lamp-lit roads, statue + fragment field per
sector, beacon at the golden centroid, nav over all of it - as real
actors in /Game/Maps/VEILWorld. This job syncs the scripts, turns on
TSR (Unreal's temporal upscaler, the DLSS-class path built into the
engine) in DefaultEngine.ini, and launches the generator detached
through UnrealEditor-Cmd. Verdict rides job 086. Screen-free: if the
GUI editor is open, everything defers and says so.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\VEIL\Scripts D:\VEIL\Scripts /E /NFL /NDL /NJH | Out-Null
robocopy veil\VEIL\Source D:\VEIL\Source /E /NFL /NDL /NJH | Out-Null
robocopy veil\OMNI\Source D:\OMNI-UE\Source /E /NFL /NDL /NJH | Out-Null
"SYNCED (scripts + sources, incl. GameMode placed-world guard)"
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { "EDITOR OPEN - worldgen deferred; rerun with the editor closed"; "=== JOB 083 DONE ===" }
else {
  $ini = 'D:\VEIL\Config\DefaultEngine.ini'
  Copy-Item $ini "$ini.bak-083" -Force
  $t = Get-Content $ini -Raw
  if ($t -notmatch 'r\.AntiAliasingMethod') { $t = $t -replace '(\[/Script/Engine\.RendererSettings\])', "`$1`r`nr.AntiAliasingMethod=4" }
  Set-Content $ini $t -Encoding ASCII
  "TSR SET: r.AntiAliasingMethod=4 (temporal upscaling, DLSS-class)"
  $log = 'D:\VEIL\Saved\worldgen-build.log'
  Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList '"D:\VEIL\VEIL.uproject"','-run=PythonScript','-script="D:\VEIL\Scripts\build_world.py"','-unattended','-nop4','-nosplash',"-log=$log" -WindowStyle Hidden
  "WORLDGEN LAUNCHED (detached) - verdict rides job 086"
  "=== JOB 083 DONE ==="
}
```
