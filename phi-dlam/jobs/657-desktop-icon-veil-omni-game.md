<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 657 - DESKTOP ICON VEIL OMNI GAME (Ground: Tyree order in his words icon on my pc of the unreal game like an app but for pc exe file thing man I am not good with pcs idk what its called I am an android dude. This job puts one desktop icon on his PC that opens VEIL OMNI to play, no editor navigation, no steps for him. Icon is a desktop shortcut that runs the game mode directly. No cook package, no build, no ledger edit. Every variable carries the p657 prefix.) ==='
$p657desk = [Environment]::GetFolderPath('Desktop')
$p657link = Join-Path $p657desk 'VEIL OMNI.lnk'
$p657target = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$p657uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p657work = 'D:\VEIL-OMNI'
Write-Output 'WHOLE657 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p657target) { Write-Output 'TARGET657 PRESENT UNREALEDITOR' } else { Write-Output 'TARGET657 MISSING UNREALEDITOR' }
if (Test-Path $p657uproj) { Write-Output 'PROJECT657 PRESENT VEIL OMNI' } else { Write-Output 'PROJECT657 MISSING VEIL OMNI' }
Write-Output ('DESKTOP657 PATH ' + $p657desk)
Write-Output ('LINK657 PATH ' + $p657link)
if ((Test-Path $p657target) -and (Test-Path $p657uproj)) {
  $p657shell = New-Object -ComObject WScript.Shell
  $p657shortcut = $p657shell.CreateShortcut($p657link)
  $p657shortcut.TargetPath = $p657target
  $p657shortcut.Arguments = '"' + $p657uproj + '" -game'
  $p657shortcut.WorkingDirectory = $p657work
  $p657shortcut.Description = 'VEIL OMNI THE LAST SIGNAL PATH OF LIGHT PLAY'
  $p657shortcut.IconLocation = $p657target
  $p657shortcut.Save()
  Write-Output 'LINK657 SAVED VEIL OMNI DESKTOP ICON'
} else { Write-Output 'LINK657 SKIPPED TARGET OR PROJECT MISSING' }
if (Test-Path $p657link) {
  Write-Output 'LINK657 PRESENT ON DESKTOP'
  $p657check = New-Object -ComObject WScript.Shell
  $p657read = $p657check.CreateShortcut($p657link)
  Write-Output ('LINK657 TARGET ' + $p657read.TargetPath)
  Write-Output ('LINK657 ARGS ' + $p657read.Arguments)
  Write-Output ('LINK657 WORKDIR ' + $p657read.WorkingDirectory)
} else { Write-Output 'LINK657 MISSING ON DESKTOP' }
Write-Output 'AUTO657 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE657 NO COOK PACKAGE UNTIL 100 PERCENT DONE ICON ONLY'
Write-Output 'JOB 657 DONE'
```
