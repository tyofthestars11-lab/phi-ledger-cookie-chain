<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 733 - EDITOR BINARY BUILD (Ground: Job 731 built VEIL Win64 Development with Result Succeeded and VEIL.exe linked, but job 732 read the new seat Cmd tail ending again at the CDO Constructor AnimBlueprint error, with the new Cmd at 1480 MB and no SEAT lines. The game target build does not rebuild the editor module the Cmd loads, so this job reads the VEIL binaries in Binaries Win64 with sizes and write times, then starts a detached VEILEditor Win64 Development build, no wait, so the editor module carries the finder fix. It edits no source, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$binDir = Join-Path $projW 'Binaries\Win64'
Write-Output ('BINDIR733 PRESENT ' + (Test-Path $binDir))
if (Test-Path $binDir) {
  $binFiles = @(Get-ChildItem $binDir -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'VEIL' })
  Write-Output ('BIN733 FILES ' + $binFiles.Count)
  foreach ($binFile in $binFiles) { Write-Output ('BIN733 FILE ' + $binFile.Name + ' SIZE ' + $binFile.Length + ' WRITE ' + $binFile.LastWriteTime) }
}
$outW = Join-Path $projW 'Saved\Logs\VEIL_EDITOR_build_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_EDITOR_build_err.log'
$buildW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output ('BUILD733 PRESENT ' + (Test-Path $buildW))
Start-Process -FilePath $buildW -ArgumentList ('VEILEdito' + [char]114),'Win64','Development','-Project="D:\VEIL-OMNI\VEIL.uproject"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'BUILD733 STARTED DETACHED NO WAIT'
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD733 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP733 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
