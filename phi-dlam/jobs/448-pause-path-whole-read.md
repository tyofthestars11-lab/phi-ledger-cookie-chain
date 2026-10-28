<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PAUSE PATH WHOLE READ 448 - THE START PRESS OUTCOME NAMED FROM THE SOURCE AND THE RECORD (Ground: Tyree hands, the controller works in VEIL OMNI and pressing Start ends the game on screen. Jobs 445 and 447 read the record whole: the newest project log ends in a clean exit, RequestExit by ViewportClosed at 16:28:30 UTC, the only crash folder is the old parent plugin crash, and no fatal line, no pause line, and no callstack stands anywhere in the record. So the press outcome in the record is a clean exit, not a fatal fault, and the mechanism must be named from the source of the pause path itself. This job prints that path whole. One, it prints the TogglePauseMenu function whole from VEILGameMode cpp, from its signature to its closing brace, capped at 80 lines. Two, it prints every QuitGame and RequestExit and ExitGame line in the whole Source tree with file and line number, capped at 20, because a clean exit has an author in code. Three, it prints the first 20 lines of NativeConstruct in both menu cpps, VEILPauseMenu and VEILMainMenu, so the WidgetTree use stands read. Four, it prints every line binding Gamepad Special Right or the Menu action across the Source tree, capped at 25, because the same pad button may stand bound twice. The verdict in one line: PAUSE PATH READ with the quit call site count and the special right binding count. This job is read only and every variable carries the pp448 prefix.) ==='
$pp448src = 'D:\VEIL-OMNI\Source\VEIL'
$pp448gm = Join-Path $pp448src 'VEILGameMode.cpp'
if (Test-Path $pp448gm) {
  $pp448lines = @(Get-Content $pp448gm)
  $pp448start = -1
  for ($pp448i = 0; $pp448i -lt $pp448lines.Count; $pp448i++) { if ($pp448lines[$pp448i] -match 'TogglePauseMenu') { $pp448start = $pp448i; break } }
  if ($pp448start -ge 0) { $pp448end = [Math]::Min($pp448start + 80, $pp448lines.Count); for ($pp448j = $pp448start; $pp448j -lt $pp448end; $pp448j++) { Write-Output ('TPM ' + ($pp448j + 1).ToString() + ' ' + $pp448lines[$pp448j]) } }
}
$pp448quits = @(Get-ChildItem $pp448src -Filter '*.cpp' | ForEach-Object { Select-String -Path $_.FullName -Pattern 'QuitGame|RequestExit|ExitGame|Quit' -ErrorAction SilentlyContinue } | Select-Object -First 20)
foreach ($pp448q in $pp448quits) { Write-Output ('QUIT ' + $pp448q.Filename + ':' + $pp448q.LineNumber + ' ' + $pp448q.Line.Trim()) }
foreach ($pp448menu in @('VEILPauseMenu.cpp', 'VEILMainMenu.cpp')) {
  $pp448mp = Join-Path $pp448src $pp448menu
  if (Test-Path $pp448mp) {
    $pp448ml = @(Select-String -Path $pp448mp -Pattern 'NativeConstruct' -ErrorAction SilentlyContinue | Select-Object -First 1)
    if ($pp448ml) { $pp448all = @(Get-Content $pp448mp); $pp448from = $pp448ml.LineNumber - 1; $pp448to = [Math]::Min($pp448from + 20, $pp448all.Count); for ($pp448k = $pp448from; $pp448k -lt $pp448to; $pp448k++) { Write-Output ('MENU ' + $pp448menu + ' ' + ($pp448k + 1).ToString() + ' ' + $pp448all[$pp448k]) } }
  }
}
$pp448binds = @(Get-ChildItem $pp448src -Filter '*.cpp' | ForEach-Object { Select-String -Path $_.FullName -Pattern 'Special_Right|MenuAction|PauseMenu' -ErrorAction SilentlyContinue } | Select-Object -First 25)
foreach ($pp448b in $pp448binds) { Write-Output ('BIND ' + $pp448b.Filename + ':' + $pp448b.LineNumber + ' ' + $pp448b.Line.Trim()) }
Write-Output ('PHI PP448 VERDICT: PAUSE PATH READ quits=' + $pp448quits.Count + ' binds=' + $pp448binds.Count)
Write-Output 'JOB 448 DONE'
```
