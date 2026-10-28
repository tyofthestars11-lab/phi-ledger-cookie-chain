<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PAUSE PATH TRUE ADDRESS READ 453 - THE START PRESS NAMED AT THE REAL SOURCE ADDRESS (Ground: job 451 censused the source tree whole and the mystery of the empty reads closed: the game source lives in the Unreal module layout, Private and Public category folders under Source VEIL, and jobs 447 and 448 probed the flat module folder where no cpp stands. The true addresses: Private Game VEILGameMode cpp at 12791 bytes, Private Game VEILPauseMenu cpp, Private Game VEILMainMenu cpp, Private World VEILWorldBuilder cpp. The question stands from Tyree hands: the controller works and pressing Start ends the game on screen, while the record holds only a clean exit and no fatal line. This job re-runs the pause read at the true address. One, it prints TogglePauseMenu whole from VEILGameMode cpp, signature to closing brace, capped at 80 lines. Two, it prints every QuitGame, RequestExit and ExitGame line across the Private tree with file and line, capped at 20. Three, it prints the first 22 lines of NativeConstruct in both menu cpps. Four, it prints every Special Right, MenuAction and PauseMenu binding line across the Private tree, capped at 25. The verdict in one line: PAUSE PATH READ with the quit count and the binding count. This job is read only and every variable carries the pp453 prefix.) ==='
$pp453priv = 'D:\VEIL-OMNI\Source\VEIL\Private'
$pp453gm = Join-Path $pp453priv 'Game\VEILGameMode.cpp'
Write-Output ('GM EXISTS=' + (Test-Path $pp453gm))
if (Test-Path $pp453gm) {
  $pp453lines = @(Get-Content $pp453gm)
  $pp453start = -1
  for ($pp453i = 0; $pp453i -lt $pp453lines.Count; $pp453i++) { if ($pp453lines[$pp453i] -match 'TogglePauseMenu') { $pp453start = $pp453i; break } }
  if ($pp453start -ge 0) { $pp453end = [Math]::Min($pp453start + 80, $pp453lines.Count); for ($pp453j = $pp453start; $pp453j -lt $pp453end; $pp453j++) { Write-Output ('TPM ' + ($pp453j + 1).ToString() + ' ' + $pp453lines[$pp453j]) } }
}
$pp453quits = @(Get-ChildItem $pp453priv -Recurse -Filter '*.cpp' | ForEach-Object { Select-String -Path $_.FullName -Pattern 'QuitGame|RequestExit|ExitGame' -ErrorAction SilentlyContinue } | Select-Object -First 20)
foreach ($pp453q in $pp453quits) { Write-Output ('QUIT ' + $pp453q.Filename + ':' + $pp453q.LineNumber + ' ' + $pp453q.Line.Trim()) }
foreach ($pp453menu in @('VEILPauseMenu.cpp', 'VEILMainMenu.cpp')) {
  $pp453mp = Join-Path $pp453priv ('Game\' + $pp453menu)
  if (Test-Path $pp453mp) {
    $pp453all = @(Get-Content $pp453mp)
    $pp453hit = -1
    for ($pp453k = 0; $pp453k -lt $pp453all.Count; $pp453k++) { if ($pp453all[$pp453k] -match 'NativeConstruct') { $pp453hit = $pp453k; break } }
    if ($pp453hit -ge 0) { $pp453to = [Math]::Min($pp453hit + 22, $pp453all.Count); for ($pp453m = $pp453hit; $pp453m -lt $pp453to; $pp453m++) { Write-Output ('MENU ' + $pp453menu + ' ' + ($pp453m + 1).ToString() + ' ' + $pp453all[$pp453m]) } }
  }
}
$pp453binds = @(Get-ChildItem $pp453priv -Recurse -Filter '*.cpp' | ForEach-Object { Select-String -Path $_.FullName -Pattern 'Special_Right|MenuAction|PauseMenu|Gamepad_Menu' -ErrorAction SilentlyContinue } | Select-Object -First 25)
foreach ($pp453b in $pp453binds) { Write-Output ('BIND ' + $pp453b.Filename + ':' + $pp453b.LineNumber + ' ' + $pp453b.Line.Trim()) }
Write-Output ('PHI PP453 VERDICT: PAUSE PATH READ quits=' + $pp453quits.Count + ' binds=' + $pp453binds.Count)
Write-Output 'JOB 453 DONE'
```
