<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 722 - UNREAL TELLS, READ CMD AND AI LOGS AGAIN (Ground: Job 721 read the logs, build succeeded, NPC files present, map size grew, but no SEAT proof lines were in the Cmd logs yet, so this job reads again, Unreal tells, not the job start lines, it starts nothing, it builds nothing, no cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$log718 = Join-Path $projW 'Saved\Logs\VEIL_SEAT718_cmd_out.log'
$log719 = Join-Path $projW 'Saved\Logs\VEIL_SEAT719_cmd_out.log'
Write-Output ('SEAT718 LOG PRESENT ' + (Test-Path $log718))
if (Test-Path $log718) { Get-Content $log718 | Select-Object -Last 40 }
Write-Output ('SEAT719 LOG PRESENT ' + (Test-Path $log719))
if (Test-Path $log719) { Get-Content $log719 | Select-Object -Last 40 }
Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$logsW = Join-Path $projW 'Saved\Logs'
Get-ChildItem $logsW -Filter 'VEIL_*.log' | Sort-Object LastWriteTime -Descending | Select-Object -First 3 | ForEach-Object { Write-Output ('UNREAL LOG ' + $_.Name + ' BYTES ' + $_.Length + ' WRITE ' + $_.LastWriteTime) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP SIZE ' + (Get-Item $mapW).Length) }
$aiPriv = Join-Path $projW 'Source\VEIL\Private\AI'
$aiPub = Join-Path $projW 'Source\VEIL\Public\AI'
if (Test-Path $aiPriv) { Get-ChildItem $aiPriv -File | ForEach-Object { Write-Output ('AI PRIVATE ' + $_.Name) } }
if (Test-Path $aiPub) { Get-ChildItem $aiPub -File | ForEach-Object { Write-Output ('AI PUBLIC ' + $_.Name) } }
$seat718 = Join-Path $projW 'Saved\seat718.py'
$seat719 = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SEAT718 SCRIPT PRESENT ' + (Test-Path $seat718))
Write-Output ('SEAT719 SCRIPT PRESENT ' + (Test-Path $seat719))
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
