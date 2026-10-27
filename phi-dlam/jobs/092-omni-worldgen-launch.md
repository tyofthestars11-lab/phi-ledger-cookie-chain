<!-- PHI-DIRECT -->
# JOB 092 - OMNI WORLD GENERATOR LAUNCH (DIRECT)

VEILWorld proved (349.7 KB umap, job 086). OMNI's generator is the
same script mirrored - it builds OMNI's connected world (3 sectors,
roads, beacon, nav) into /Game/Maps/OMNIWorld. Launched on the
connected lane through UnrealEditor-Cmd with -abslog (the correct
absolute-log flag - the -log form silently wrote elsewhere).
Verdict reads OMNI's Saved\Logs in a later drain.

```powershell
$ErrorActionPreference = 'Continue'
cd C:\Users\Admin\phi-vault; git pull --no-rebase
robocopy veil\OMNI\Scripts D:\OMNI-UE\Scripts /E /NFL /NDL /NJH | Out-Null
"SYNCED OMNI scripts"
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { "EDITOR OPEN - OMNI worldgen deferred; rerun with the editor closed" }
else {
  Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList '"D:\OMNI-UE\OMNI.uproject"','-run=PythonScript','-script="D:\OMNI-UE\Scripts\build_world.py"','-unattended','-nop4','-nosplash','-abslog="D:\OMNI-UE\Saved\worldgen-build.log"' -WindowStyle Hidden
  "OMNI WORLDGEN LAUNCHED on the connected lane"
}
"=== JOB 092 DONE ==="
```
