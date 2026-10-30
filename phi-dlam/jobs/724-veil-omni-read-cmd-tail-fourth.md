<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 724 - READ CMD TAIL FOURTH TIME, UNREAL TELLS (Ground: Job 723 searched the Cmd logs, no SEAT lines yet, Cmd processes large and alive, map unchanged, so this job reads the full tail, not just a search, to see where the editor stands now, it starts nothing, it builds nothing, no cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$log718 = Join-Path $projW 'Saved\Logs\VEIL_SEAT718_cmd_out.log'
$log719 = Join-Path $projW 'Saved\Logs\VEIL_SEAT719_cmd_out.log'
Write-Output ('SEAT718 LOG PRESENT ' + (Test-Path $log718))
if (Test-Path $log718) { Get-Content $log718 | Select-Object -Last 60 }
Write-Output ('SEAT719 LOG PRESENT ' + (Test-Path $log719))
if (Test-Path $log719) { Get-Content $log719 | Select-Object -Last 60 }
Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
