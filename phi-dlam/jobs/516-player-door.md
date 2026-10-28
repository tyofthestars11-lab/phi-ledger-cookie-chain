<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 516 - A PLAYER DOOR FOR THE GAME (Ground: his words - he does not know how to start the game, he has no file, all he has is the Unreal version, as if he is editing and not playing. He is right: the project opens in the editor, and a player gets a door, not an editor. This job builds that door on his desktop: a shortcut named VEIL OMNI PLAY that opens the game itself in its own window, the same game mode window where his controller already works, with no editor surface anywhere in it. This is not a package and not a cook - the packaging gate stands untouched; it is the project standing in game mode behind one double click. The job creates the shortcut, then reads it back and prints its target and arguments as the proof. Every variable carries the p516 prefix.) ==='
$p516target = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$p516desk = [Environment]::GetFolderPath('Desktop')
$p516lnk = Join-Path $p516desk 'VEIL OMNI - PLAY.lnk'
$p516shell = New-Object -ComObject WScript.Shell
$p516sc = $p516shell.CreateShortcut($p516lnk)
$p516sc.TargetPath = $p516target
$p516sc.Arguments = '"D:\VEIL-OMNI\VEIL.uproject" -game -windowed'
$p516sc.WorkingDirectory = 'D:\VEIL-OMNI'
$p516sc.Save()
Write-Output ('DOOR EXISTS=' + (Test-Path $p516lnk) + ' path=' + $p516lnk)
$p516back = $p516shell.CreateShortcut($p516lnk)
Write-Output ('DOOR TARGET=' + $p516back.TargetPath)
Write-Output ('DOOR ARGS=' + $p516back.Arguments)
Write-Output 'PHI P516 VERDICT: PLAYER DOOR STANDING'
Write-Output 'JOB 516 DONE'
```
