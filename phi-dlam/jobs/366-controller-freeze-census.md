<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CONTROLLER FREEZE CENSUS 366 - THE PAD FREEZE RIDES THE SAME REPAIR PASS (Tyree names a new symptom from his own hands on the merged build: using a controller freezes it. Floor first - job 365 carries the fall - and this census rides the same pass, because a build that stands and then freezes on the pad is not playable. The lane already holds one measured freeze shape in this codebase, read on 2026-10-27: the PlayerController lives inside VEILGameMode.cpp, its TogglePauseMenu answers Esc, P and Gamepad_Special_Right, and at that read PauseWidgetClass stood never assigned in either parent - SetPause true plus a mouse cursor with no visible menu is a freeze in every way a player can name, and his words then were that he could not exit that menu either. Whether that mechanism stands armed in the merged base is a source fact, readable in one pass. THIS JOB, merged base at D VEIL-OMNI only, read-only except two short game runs: one, the pause truth - every PauseWidgetClass, HUDWidgetClass, TogglePauseMenu, SetPause and Gamepad line in the GameMode source, plus the TogglePauseMenu and SetupInputComponent bodies printed whole. Two, the character input truth - the SetupPlayerInputComponent and BuildFallbackInput bodies printed whole, and every Gamepad, EnhancedInput and MappingContext line in Source. Three, the config truth - DefaultInput.ini whole where it stands, and the input lines of DefaultEngine.ini. Four, the device truth - Plug and Play status for the pad and Bluetooth devices on the PC, because job 071 proved his third-party Bluetooth Xbox pad paired and ready. Five, log archaeology - the newest three game logs, their pad and pause lines, and the tail of the newest log, where a hard freeze cuts the record mid-motion. Six, two game runs on VEILDistrict, plain and with the NoXInput switch, 40 seconds each, printing the PHI truth line count and the log tail for each - the runs carry no pad press, so they read the launch-side half only, and the job prints that limit in its own voice. No source is edited in this job: the fix for whatever stands armed is written from these prints and rides with the fall fix.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 366 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
function Show-Lines([string]$path, [int]$start, [int]$count) { $lines = Get-Content $path; $end = [Math]::Min($start + $count, $lines.Count); for ($i = $start; $i -lt $end; $i++) { ("{0}: {1}" -f ($i + 1), $lines[$i]) } }
function Show-Function([string]$path, [string]$anchor, [int]$count) { $lines = Get-Content $path; $hit = -1; for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i].Contains($anchor)) { $hit = $i; break } }; if ($hit -lt 0) { Write-Output ("ANCHOR NOT FOUND: " + $anchor); return }; Write-Output ("--- FUNCTION " + $anchor + " at line " + ($hit + 1) + " ---"); Show-Lines $path $hit $count }
Write-Output '--- SECTION 1: PAUSE TRUTH ---'
$gmItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILGameMode.cpp' -File | Select-Object -First 1
if (-not $gmItem) { Write-Output 'GAMEMODE CPP NOT FOUND'; Write-Output 'JOB 366 STOPPED'; return }
Write-Output ("GAMEMODE: " + $gmItem.FullName + " bytes=" + $gmItem.Length)
Select-String -Path $gmItem.FullName -Pattern 'PauseWidgetClass|HUDWidgetClass|TogglePauseMenu|SetPause|PlayerController|Gamepad|MainMenu' | ForEach-Object { ("GM {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output
Show-Function $gmItem.FullName '::TogglePauseMenu' 45
Show-Function $gmItem.FullName '::SetupInputComponent' 45
Write-Output '--- SECTION 2: CHARACTER INPUT TRUTH ---'
$cppItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.cpp' -File | Select-Object -First 1
if ($cppItem) {
  Show-Function $cppItem.FullName '::SetupPlayerInputComponent' 90
  Show-Function $cppItem.FullName '::BuildFallbackInput' 90
}
Get-ChildItem "$base\Source" -Recurse -Include '*.cpp','*.h' -File | ForEach-Object { Select-String -Path $_.FullName -Pattern 'Gamepad|EnhancedInput|MappingContext' -ErrorAction SilentlyContinue } | ForEach-Object { ("IN {0}:{1}: {2}" -f $_.Filename, $_.LineNumber, $_.Line.Trim()) } | Select-Object -First 80 | Write-Output
Write-Output '--- SECTION 3: CONFIG TRUTH ---'
if (Test-Path "$base\Config\DefaultInput.ini") { Write-Output 'DefaultInput.ini:'; Get-Content "$base\Config\DefaultInput.ini" | Write-Output } else { Write-Output 'DefaultInput.ini NOT PRESENT' }
if (Test-Path "$base\Config\DefaultEngine.ini") { Select-String -Path "$base\Config\DefaultEngine.ini" -Pattern 'Gamepad|RawInput|XInput|Input' | ForEach-Object { ("ENG {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output }
Write-Output '--- SECTION 4: DEVICE TRUTH ---'
Get-PnpDevice -ErrorAction SilentlyContinue | Where-Object { $_.FriendlyName -match 'Xbox|Gamepad|Wireless|Bluetooth|Controll' -or $_.Class -eq 'XnaComposite' } | ForEach-Object { ("PNP " + $_.Status + " | " + $_.Class + " | " + $_.FriendlyName) } | Write-Output
Write-Output '--- SECTION 5: LOG ARCHAEOLOGY ---'
$logs = Get-ChildItem "$base\Saved\Logs\*.log" -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 3
foreach ($lf in $logs) {
  Write-Output ("LOGFILE: " + $lf.Name + " bytes=" + $lf.Length + " modified=" + $lf.LastWriteTime)
  Select-String -Path $lf.FullName -Pattern 'Gamepad|SetPause|TogglePause|EnhancedInput|MappingContext' -ErrorAction SilentlyContinue | Select-Object -Last 15 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
if ($logs) { Write-Output '--- NEWEST LOG TAIL ---'; Get-Content $logs[0].FullName -Tail 25 | Write-Output }
Write-Output '--- SECTION 6: A/B GAME RUNS (no pad press in either run - launch-side half only) ---'
foreach ($variant in @('A-plain','B-noxinput')) {
  Write-Output ("--- RUN " + $variant + " ---")
  $args = @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash')
  if ($variant -eq 'B-noxinput') { $args += '-NoXInput' }
  $gp = Start-Process $edexe -ArgumentList $args -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 40
  if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 40s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
  Start-Sleep -Seconds 3
  $logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logf) {
    $hits = Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH' -ErrorAction SilentlyContinue
    $n = 0; if ($hits) { $n = $hits.Count }
    Write-Output ("TRUTH LINES IN RUN LOG: " + $n)
    if ($n -eq 0) { Write-Output 'INSTRUMENT ABSENT OR NO TRUTH LINES - read stands on sections 1 to 5' }
    Write-Output '--- RUN LOG TAIL ---'
    Get-Content $logf.FullName -Tail 8 | Write-Output
  } else { Write-Output 'NO LOG FILE FOUND' }
}
Write-Output 'JOB 366 DONE'
```
