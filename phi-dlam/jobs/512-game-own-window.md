<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 512 - THE GAME IN ITS OWN WINDOW (Ground: his photos from his own play - the pad proof in the editor log reads n=2 with every value at zero again, on top of the sixty flat samples from the earlier census. Inside the editor process the pad has never once arrived, across every road built into the game. The one road never tried is the game standing in its own window, outside the editor, where the system hands the window its own controller directly. This job launches exactly that: the project in game mode, windowed, detached, printing the process it woke and the newest log name before and after, so the play that follows writes a fresh log the lane can read for the pad proof and the body check. The job ends in seconds; the window stands on its own. Every variable carries the p512 prefix.) ==='
$p512uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p512logs = 'D:\VEIL-OMNI\Saved\Logs'
$p512before = Get-ChildItem $p512logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($p512before) { Write-Output ('LOG BEFORE: ' + $p512before.Name + ' at ' + $p512before.LastWriteTime) }
$p512exe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$p512proc = Start-Process -FilePath $p512exe -ArgumentList ('"' + $p512uproj + '" -game -windowed') -PassThru
Write-Output ('GAME WINDOW LAUNCHED pid=' + $p512proc.Id)
Write-Output 'PHI P512 VERDICT: STANDALONE GAME WINDOW ISSUED'
Write-Output 'JOB 512 DONE'
```
