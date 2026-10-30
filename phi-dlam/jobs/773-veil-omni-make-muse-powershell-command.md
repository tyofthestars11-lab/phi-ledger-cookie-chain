<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 773 - MAKE MUSE POWERSHELL COMMAND (Ground: Tyree whole: So I join powershell and type muse. Tyree is Local, Muse is remote via through his stuff, phone, browser, GitHub, DLAM, Command Prompt, PowerShell. Local brain chat answered REMOTE CONNECT MUSE with generic rephrase, not remote Muse. Job 772 made Saved REMOTE_CONNECT_MUSE.bat, DIAMOND-STABLE, commit ec14897. This job makes a muse PowerShell command file, no brain chat, no map edits, no save. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$batW = Join-Path $projW 'Saved\REMOTE_CONNECT_MUSE.bat'
Write-Output ('BAT773 PRESENT ' + (Test-Path $batW))
$museW = Join-Path $projW 'Saved\muse.ps1'
$museTextW = "Write-Output 'REMOTE CONNECT MUSE'`r`n$bat = Join-Path 'D:\VEIL-OMNI\Saved' 'REMOTE_CONNECT_MUSE.bat'`r`nif (Test-Path $bat) { & $bat } else { Write-Output 'MUSE BAT NOT FOUND' }`r`n"
Set-Content $museW $museTextW -NoNewline
Write-Output ('MUSE773 PRESENT ' + (Test-Path $museW))
if (Test-Path $museW) { Write-Output ('MUSE773 BYTES ' + (Get-Item $museW).Length) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP773 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
