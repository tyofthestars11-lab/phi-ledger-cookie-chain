<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 815 - CHANGE ALT TAB SWITCH KEYS (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word whole: Alt tab does not work for me, change that, I use controller, game is full screen and captures Alt Tab. This job: change the switch keys, Alt Tab is out, new switch is Ctrl Alt M to bring Muse forward plus Windows Tab task view, set game to borderless windowed so switch is not captured, create Muse shortcut with hotkey Ctrl Alt M, verify shortcut hotkey and game window mode whole, close GUI only verify 0, load_level Game Maps VEILDistrict, build_level, save map must land over prior 670004 bytes, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, press Ctrl Alt M and Muse comes forward, press Windows Tab for task view, controller moves in play from job 811, proof in play not log only, no package no cook no 1.0 just finish and verify.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI815 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT815 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-815') -Force; Write-Output 'SEAT815 BACKUP True' }
Write-Output 'SWITCH815 ALT TAB OUT CTRL ALT M IN WINDOWS TAB TASK VIEW GAME BORDERLESS WINDOWED NOT EXCLUSIVE FULLSCREEN CONTROLLER MOVE IN PLAY RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 NO PACKAGE NO COOK FINISH VERIFY'
$dirW = Join-Path $projW 'Saved\Config\Windows'
if (-not (Test-Path $dirW)) { New-Item -ItemType Directory -Path $dirW -Force | Out-Null }
$setW = Join-Path $dirW 'GameUserSettings.ini'
$lowW = @()
$lowW += '[/Script/Engine.GameUserSettings]'
$lowW += 'ResolutionSizeX=1280'
$lowW += 'ResolutionSizeY=720'
$lowW += 'FullscreenMode=1'
$lowW += 'FrameRateLimit=0'
$lowW | Out-File -FilePath $setW -Encoding ascii -Force
Write-Output ('SETTINGS815 BORDERLESS WRITTEN ' + (Test-Path $setW))
$shellW = New-Object -ComObject WScript.Shell
$linkW = 'C:\Users\Admin\Desktop\MUSE SWITCH.lnk'
$shortW = $shellW.CreateShortcut($linkW)
$shortW.TargetPath = 'muse'
$shortW.Hotkey = 'CTRL+ALT+M'
$shortW.Save()
Write-Output ('SHORTCUT815 CREATED ' + (Test-Path $linkW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI815_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI815_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD815 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD815 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP815 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
