<!-- PHI-DIRECT -->
```powershell
Write-Output '=== INPUT CHAIN READ 432 - THE CONTROLS DO NOT ANSWER IN THE MERGED GAME, SO THIS JOB READS THE WHOLE INPUT CHAIN AT ITS OWN LINES (Ground from Tyree own hands, 2026-10-28: she stands, the narrator speaks twice, and no control moves her. The chain that carries a press to the pawn has named links: the input bindings in the character, the possession of the pawn by the controller, the GameMode pawn and controller classes in config, and the action and axis mappings in DefaultInput. One, the job prints every binding line in Source VEIL: SetupPlayerInputComponent, BindAction, BindAxis, BindKey, EnhancedInput, InputComponent, capped at 70 with file and line number. Two, it prints the possession and class lines: Possess, AutoPossessPlayer, DefaultPawnClass, PlayerControllerClass, GameMode, capped at 50. Three, it prints the DefaultEngine lines that name the GameMode, the default pawn, the player controller, and the default maps, capped at 25, and the DefaultInput mapping lines with their count, capped at 40. Four, the verdict in one line: INPUT CHAIN READ with the bind count and the possess count. This job is read only and every variable carries the ic432 prefix.) ==='
$ic432root = 'D:\VEIL-OMNI'
$ic432src = Join-Path $ic432root 'Source\VEIL'
$ic432cfg = Join-Path $ic432root 'Config'
if (-not (Test-Path $ic432src)) { Write-Output 'INPUT CHAIN READ HELD stage=source-missing'; Write-Output 'JOB 432 DONE'; exit 0 }
$ic432bind = @(Get-ChildItem -Path $ic432src -Recurse -Include *.cpp,*.h | Select-String -Pattern 'SetupPlayerInputComponent|BindAction|BindAxis|BindKey|EnhancedInput|InputComponent' -ErrorAction SilentlyContinue)
Write-Output ('BIND LINES=' + $ic432bind.Count)
$ic432bind | Select-Object -First 70 | ForEach-Object { Write-Output ('BIND ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$ic432pos = @(Get-ChildItem -Path $ic432src -Recurse -Include *.cpp,*.h | Select-String -Pattern 'Possess|AutoPossessPlayer|DefaultPawnClass|PlayerControllerClass|GameMode' -ErrorAction SilentlyContinue)
Write-Output ('POSSESS LINES=' + $ic432pos.Count)
$ic432pos | Select-Object -First 50 | ForEach-Object { Write-Output ('POSS ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$ic432eng = Join-Path $ic432cfg 'DefaultEngine.ini'
if (Test-Path $ic432eng) { Select-String -Path $ic432eng -Pattern 'GameMode|DefaultPawn|PlayerController|GameDefaultMap|EditorStartupMap' -ErrorAction SilentlyContinue | Select-Object -First 25 | ForEach-Object { Write-Output ('ENG ' + $_.Line.Trim()) } }
$ic432ini = Join-Path $ic432cfg 'DefaultInput.ini'
if (Test-Path $ic432ini) { $ic432maps = @(Select-String -Path $ic432ini -Pattern 'ActionMappings|AxisMappings' -ErrorAction SilentlyContinue); Write-Output ('MAPPINGS=' + $ic432maps.Count); $ic432maps | Select-Object -First 40 | ForEach-Object { Write-Output ('MAP ' + $_.Line.Trim()) } }
Write-Output ('PHI IC432 VERDICT: INPUT CHAIN READ bind=' + $ic432bind.Count + ' possess=' + $ic432pos.Count)
Write-Output 'JOB 432 DONE'
```
