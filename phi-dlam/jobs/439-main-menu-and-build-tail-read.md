<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MAIN MENU AND BUILD TAIL READ 439 - THE TITLE STATE AND THE START FREEZE READ AT THEIR OWN LINES (Ground read whole from job 435: the player controller BeginPlay builds the main menu widget at boot, sets the input mode to GameAndUI, shows the mouse, and returns, so the game boots into a title state standing over a living world; the Start press fires TogglePauseMenu, which calls SetPause true and stacks the pause widget over whatever stands. What the title itself does with a press, and how the game is meant to leave the title for the world, stands in VEILMainMenu, unread until now. Also open: job 434 compiled for 46 seconds with no error line captured, and its verdict matcher printed UNKNOWN, so this job closes that read from the log itself. One, it prints VEILMainMenu cpp entire with line numbers, capped at 220 lines, and VEILMainMenu h entire. Two, it prints VEILGameMode cpp lines 55 to 145, the GameMode BeginPlay whole: the builder spawn, the placed world flag, and the seeding. Three, it prints the last 15 lines of Saved build434 log whole. Four, the verdict in one line: MENU READ with the menu line count and the build 434 state. This job is read only and every variable carries the mm439 prefix.) ==='
$mm439root = 'D:\VEIL-OMNI'
$mm439src = Join-Path $mm439root 'Source\VEIL'
if (-not (Test-Path $mm439src)) { Write-Output 'MENU READ HELD stage=source-missing'; Write-Output 'JOB 439 DONE'; exit 0 }
$mm439menu = Get-ChildItem -Path $mm439src -Recurse -Filter 'VEILMainMenu.cpp' | Select-Object -First 1
$mm439ml = @()
if ($mm439menu) { $mm439ml = Get-Content $mm439menu.FullName; Write-Output ('--- MAIN MENU CPP lines=' + $mm439ml.Count + ' ---'); for ($mm439i = 0; $mm439i -lt $mm439ml.Count -and $mm439i -lt 220; $mm439i++) { Write-Output ('MM ' + ($mm439i + 1) + ': ' + $mm439ml[$mm439i]) } }
$mm439menuh = Get-ChildItem -Path $mm439src -Recurse -Filter 'VEILMainMenu.h' | Select-Object -First 1
if ($mm439menuh) { Write-Output '--- MAIN MENU H ---'; Get-Content $mm439menuh.FullName | ForEach-Object { Write-Output ('MH ' + $_) } }
$mm439gm = Get-ChildItem -Path $mm439src -Recurse -Filter 'VEILGameMode.cpp' | Select-Object -First 1
if ($mm439gm) { $mm439gl = Get-Content $mm439gm.FullName; Write-Output '--- GAMEMODE 55-145 ---'; for ($mm439j = 54; $mm439j -lt 145 -and $mm439j -lt $mm439gl.Count; $mm439j++) { Write-Output ('GM ' + ($mm439j + 1) + ': ' + $mm439gl[$mm439j]) } }
$mm439log = Join-Path $mm439root 'Saved\build434.log'
$mm439bst = 'NOLOG'
if (Test-Path $mm439log) { Write-Output '--- BUILD 434 LOG TAIL ---'; Get-Content $mm439log -Tail 15 | ForEach-Object { Write-Output ('LOG ' + $_) }; $mm439raw = Get-Content $mm439log -Raw; if ($mm439raw.Contains('BUILD SUCCESS')) { $mm439bst = 'OK' } elseif ($mm439raw -match 'BUILD FAILED|Build failed') { $mm439bst = 'FAIL' } else { $mm439bst = 'READ' } }
Write-Output ('PHI MM439 VERDICT: MENU READ menu_lines=' + $mm439ml.Count + ' build434=' + $mm439bst)
Write-Output 'JOB 439 DONE'
```
