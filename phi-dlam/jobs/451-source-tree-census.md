<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SOURCE TREE CENSUS 451 - WHERE THE SOURCE FILES STAND, PRINTED WITHOUT SILENT GUARDS (Ground: jobs 447 and 448 both read the game source at the standing address, D VEIL-OMNI Source VEIL, and both came back empty in every source section, while their Content reads in the same runs printed whole, and while jobs 431 through 442 read those same source files successfully at that same address. An empty read guarded by silent Test-Path checks names nothing, so this census prints existence itself. One, it prints EXISTS zero or one for the project root, the Source folder, the VEIL module folder, and the five named files: VEILGameMode cpp, VEILWorldBuilder cpp, VEILCharacter cpp, VEILPauseMenu cpp, VEILMainMenu cpp. Two, it lists the Source tree recursively, folder and file names with sizes, capped at 80 lines, so wherever the source actually stands, it stands printed. Three, it lists the project root top level, capped at 30. The verdict in one line: SOURCE CENSUS with the count of cpp files found anywhere under Source. This job is read only and every variable carries the st451 prefix.) ==='
$st451root = 'D:\VEIL-OMNI'
Write-Output ('EXISTS root=' + (Test-Path $st451root))
Write-Output ('EXISTS Source=' + (Test-Path (Join-Path $st451root 'Source')))
Write-Output ('EXISTS module=' + (Test-Path (Join-Path $st451root 'Source\VEIL')))
foreach ($st451f in @('VEILGameMode.cpp', 'VEILWorldBuilder.cpp', 'VEILCharacter.cpp', 'VEILPauseMenu.cpp', 'VEILMainMenu.cpp')) {
  $st451p = Join-Path $st451root ('Source\VEIL\' + $st451f)
  Write-Output ('EXISTS ' + $st451f + '=' + (Test-Path $st451p))
}
$st451src = Join-Path $st451root 'Source'
$st451cpps = @()
if (Test-Path $st451src) {
  $st451all = @(Get-ChildItem $st451src -Recurse -ErrorAction SilentlyContinue)
  $st451cpps = @($st451all | Where-Object { $_.Extension -eq '.cpp' })
  $st451all | Select-Object -First 80 | ForEach-Object { Write-Output ('TREE ' + $_.FullName.Substring($st451src.Length) + ' bytes=' + $_.Length) }
}
Get-ChildItem $st451root -ErrorAction SilentlyContinue | Select-Object -First 30 | ForEach-Object { Write-Output ('ROOT ' + $_.Name) }
Write-Output ('PHI ST451 VERDICT: SOURCE CENSUS cpp_found=' + $st451cpps.Count)
Write-Output 'JOB 451 DONE'
```
