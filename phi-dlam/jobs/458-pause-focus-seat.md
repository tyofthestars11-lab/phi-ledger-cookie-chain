<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PAUSE FOCUS SEAT 458 - THE PAUSE MENU OPENS ON RESUME, NEVER ON QUIT (Ground read whole from job 453 at the true source address: TogglePauseMenu stands on the player controller, bound to P, Escape and Gamepad Special Right, and its body is clean, pause, create widget, add to viewport, game and UI input. The record holds no fatal line anywhere, only clean exits, and QuitGame stands at exactly two sites in the whole tree, behind the QUIT buttons of the main menu and the pause menu. The main menu seats keyboard focus on its Start button at construct, job 439 read it whole, but the pause menu seats focus on nothing: its five buttons bind at lines 66 to 70 and no focus line follows, so when the menu opens over a paused world, the pad confirm press can land on QUIT, and the game exits clean, which is the exact shape Tyree reported: Start froze the world, then the game was gone. This job seats the focus where it belongs. One, it counts the ResumeButton click binding line in VEILPauseMenu cpp and proceeds only when the count is exactly one. Two, it backs the file up, inserts ResumeButton SetKeyboardFocus on the line after that binding, and prints the region back. Three, it counts the inserted focus lines, exactly one expected. Four, the build runs the standing way and its Result line rides the verdict. If the gate misses, the job prints SKIP and builds nothing. Every variable carries the pf458 prefix.) ==='
$pf458file = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILPauseMenu.cpp'
$pf458lines = @(Get-Content $pf458file)
$pf458idx = @()
for ($pf458i = 0; $pf458i -lt $pf458lines.Count; $pf458i++) { if ($pf458lines[$pf458i] -match 'ResumeButton->OnClicked') { $pf458idx += $pf458i } }
Write-Output ('RESUME BIND LINES=' + $pf458idx.Count)
if ($pf458idx.Count -ne 1) { Write-Output 'PHI PF458 VERDICT: PAUSE FOCUS SKIP gate closed'; Write-Output 'JOB 458 DONE'; return }
Copy-Item $pf458file ($pf458file + '.phi-backup-458') -Force
$pf458new = @()
for ($pf458j = 0; $pf458j -lt $pf458lines.Count; $pf458j++) { $pf458new += $pf458lines[$pf458j]; if ($pf458j -eq $pf458idx[0]) { $pf458new += "`tResumeButton->SetKeyboardFocus();" } }
Set-Content -Path $pf458file -Value $pf458new
$pf458verify = @(Select-String -Path $pf458file -Pattern 'SetKeyboardFocus' -ErrorAction SilentlyContinue)
Write-Output ('FOCUS LINES=' + $pf458verify.Count)
$pf458from = [Math]::Max(0, $pf458idx[0] - 2); $pf458to = [Math]::Min($pf458idx[0] + 6, $pf458new.Count)
for ($pf458k = $pf458from; $pf458k -lt $pf458to; $pf458k++) { Write-Output ('REGION ' + ($pf458k + 1).ToString() + ' ' + $pf458new[$pf458k]) }
$pf458buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$pf458uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$pf458log = 'D:\VEIL-OMNI\Saved\build458.log'
& $pf458buildbat VEILEditor Win64 Development -Project="$pf458uproj" -WaitMutex -NoHotReload *> "$pf458log"
$pf458result = @(Select-String -Path $pf458log -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
foreach ($pf458r in $pf458result) { Write-Output ('BUILD ' + $pf458r.Line.Trim()) }
Write-Output ('PHI PF458 VERDICT: PAUSE FOCUS SEATED focus_lines=' + $pf458verify.Count)
Write-Output 'JOB 458 DONE'
```
