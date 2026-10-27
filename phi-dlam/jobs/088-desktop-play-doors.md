<!-- PHI-DIRECT -->
# JOB 088 - DESKTOP PLAY DOORS FOR BOTH GAMES (DIRECT)

Tyree's ask (2026-10-27): "I need a veil and omni rpg location for
the desktop too please." Two desktop icons that open the GAMES
themselves - standalone game mode (-game), full screen, no editor
UI - pointing at the live projects. When the packaged exes land,
job 086's doors take the same names and upgrade the target to the
package. Double-click -> title menu -> controller in hand.

```powershell
$ErrorActionPreference = 'Continue'
$ws = New-Object -ComObject WScript.Shell
$desk = [Environment]::GetFolderPath('Desktop')
$ue = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
foreach ($c in @(@{Proj='D:\VEIL\VEIL.uproject'; Name='VEIL - The Last Signal'}, @{Proj='D:\OMNI-UE\OMNI.uproject'; Name='OMNI RPG'})) {
  $lnk = $ws.CreateShortcut((Join-Path $desk ($c.Name + '.lnk')))
  $lnk.TargetPath = $ue
  $lnk.Arguments = '"' + $c.Proj + '" -game -ResX=1920 -ResY=1080 -Fullscreen'
  $lnk.WorkingDirectory = Split-Path $c.Proj
  $lnk.Description = 'Play ' + $c.Name
  $lnk.Save()
  "DOOR SET: $($c.Name) -> $($c.Proj) -game fullscreen"
}
"=== JOB 088 DONE ==="
```
