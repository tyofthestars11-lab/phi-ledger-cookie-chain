<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 723 - READ CMD LOGS THIRD TIME, UNREAL TELLS (Ground: Job 722 read the Cmd logs, editor was loading, shaders compiling, Countess AnimBlueprint error present, no SEAT proof lines yet, Cmd processes were large and alive, so this job reads again, it starts nothing, it builds nothing, no cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$log718 = Join-Path $projW 'Saved\Logs\VEIL_SEAT718_cmd_out.log'
$log719 = Join-Path $projW 'Saved\Logs\VEIL_SEAT719_cmd_out.log'
Write-Output ('SEAT718 LOG PRESENT ' + (Test-Path $log718))
if (Test-Path $log718) { Get-Content $log718 | Select-String 'SEAT718|LogPython|PythonScript' | Select-Object -Last 40 }
Write-Output ('SEAT719 LOG PRESENT ' + (Test-Path $log719))
if (Test-Path $log719) { Get-Content $log719 | Select-String 'SEAT719|LogPython|PythonScript' | Select-Object -Last 40 }
Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
