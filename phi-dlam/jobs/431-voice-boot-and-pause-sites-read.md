<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VOICE BOOT AND PAUSE SITES READ 431 - THE NARRATOR SPEAKS TWICE IN THE MERGED GAME AND THE START PRESS FREEZES IT, SO THIS JOB READS THE STANDING CODE AT ITS OWN LINES (Ground from Tyree own hands at the television, 2026-10-28: the merged game boots, the Countess stands and does not fall, the narrator line plays twice over itself, the controls do not answer, and pressing Start on the controller freezes the game. The record carries two intro voice call sites from the wiring of 2026-10-27: V01 at the VEIL GameMode BeginPlay and O01 at the OMNI quest system world begin, and in the merged project both systems stand in one module, so the double voice has a named pair of candidate addresses. One, the job prints every source line in Source VEIL that calls PHIVoice or PlayVoice, with file and line number, capped at 60. Two, it prints every line that names the V01 or O01 intro rows, capped at 40, and every BeginPlay or OnWorldBeginPlay line in the cpp files, capped at 40. Three, it prints every pause and input mode line: SetGamePaused, PauseWidget, ShowPauseMenu, mouse cursor, SetInputMode, capped at 50, plus the DefaultInput lines that name Pause or the gamepad special buttons, capped at 30. Four, the verdict in one line: VOICE PAUSE READ with the voice call count, the intro row count, and the pause line count. This job is read only and every variable carries the nb431 prefix.) ==='
$nb431root = 'D:\VEIL-OMNI'
$nb431src = Join-Path $nb431root 'Source\VEIL'
$nb431cfg = Join-Path $nb431root 'Config'
if (-not (Test-Path $nb431src)) { Write-Output 'VOICE PAUSE READ HELD stage=source-missing'; Write-Output 'JOB 431 DONE'; exit 0 }
$nb431voice = @(Get-ChildItem -Path $nb431src -Recurse -Include *.cpp,*.h | Select-String -Pattern 'PHIVoice|PlayVoice' -ErrorAction SilentlyContinue)
Write-Output ('VOICE CALL LINES=' + $nb431voice.Count)
$nb431voice | Select-Object -First 60 | ForEach-Object { Write-Output ('VOICE ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$nb431rows = @(Get-ChildItem -Path $nb431src -Recurse -Include *.cpp,*.h | Select-String -Pattern 'V01|O01' -ErrorAction SilentlyContinue)
Write-Output ('INTRO ROW LINES=' + $nb431rows.Count)
$nb431rows | Select-Object -First 40 | ForEach-Object { Write-Output ('ROW ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$nb431boot = @(Get-ChildItem -Path $nb431src -Recurse -Include *.cpp | Select-String -Pattern 'BeginPlay|OnWorldBeginPlay' -ErrorAction SilentlyContinue)
$nb431boot | Select-Object -First 40 | ForEach-Object { Write-Output ('BOOT ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$nb431pause = @(Get-ChildItem -Path $nb431src -Recurse -Include *.cpp,*.h | Select-String -Pattern 'SetGamePaused|PauseWidget|SetShowMouseCursor|ShowPauseMenu|SetInputMode' -ErrorAction SilentlyContinue)
Write-Output ('PAUSE LINES=' + $nb431pause.Count)
$nb431pause | Select-Object -First 50 | ForEach-Object { Write-Output ('PAUSE ' + $_.Filename + ':' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$nb431ini = Join-Path $nb431cfg 'DefaultInput.ini'
if (Test-Path $nb431ini) { $nb431in = @(Select-String -Path $nb431ini -Pattern 'Pause|Gamepad_Special|GlobalPause' -ErrorAction SilentlyContinue); $nb431in | Select-Object -First 30 | ForEach-Object { Write-Output ('INPUT ' + $_.Line.Trim()) } }
Write-Output ('PHI NB431 VERDICT: VOICE PAUSE READ voice=' + $nb431voice.Count + ' intro=' + $nb431rows.Count + ' pause=' + $nb431pause.Count)
Write-Output 'JOB 431 DONE'
```
