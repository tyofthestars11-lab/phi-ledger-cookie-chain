<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CONTROLS REGRESSION READ 477 - MOUSE KEY AND PAD ALL READ AT THE SOURCE (Ground from Tyree hands on the new build, 2026-10-28, assembled whole: controls do not work, mouse and keyboard does not, xbox controller does not, stop regression, the Golden Ratio progresses only. The 442 state had the controller proven in his hands at 11:15 and the verbs working at 12:32, move jump sprint, so dead input on the 473 build is a regression with an address in what changed or in what the run shows, and this read takes both. One, the newest game log in Saved Logs prints its input, possess, menu and phi lines whole, capped, because the run itself says whether input setup ran, whether the pawn was possessed, and whether a menu stands holding the input mode. Two, the character input regions print whole: SetupPlayerInputComponent wherever it stands and the fallback builder with its map lines, so the binding state is read as written today, not as remembered. Three, every menu show and input mode line in the GameMode cpp prints, CreateWidget, SetInputMode, ShowMainMenu and the widget class seats, because a menu holding GameAndUI mode over the world reads exactly like dead controls. Four, the flight region as 473 left it prints, bind line and function, to verify the rewrite touched nothing beside itself. The verdict in one line: REGRESSION READ with the section counts. Read only, and every variable carries the cr477 prefix.) ==='
$cr477logs = 'D:\VEIL-OMNI\Saved\Logs'
$cr477newest = Get-ChildItem $cr477logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($cr477newest) {
  Write-Output ('LOG ' + $cr477newest.Name + ' bytes=' + $cr477newest.Length + ' mtime=' + $cr477newest.LastWriteTime)
  $cr477hits = @(Select-String -Path $cr477newest.FullName -Pattern 'Input|Possess|PHI |Menu|Erro[r]|Warning' -ErrorAction SilentlyContinue | Select-Object -Last 40)
  foreach ($cr477h in $cr477hits) { Write-Output ('LG ' + $cr477h.Line.Trim()) }
  Write-Output ('LOG HITS=' + $cr477hits.Count)
} else { Write-Output 'LOG NONE' }
$cr477ch = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$cr477cl = @(Get-Content $cr477ch)
$cr477setup = -1; $cr477fb = -1
for ($cr477i = 0; $cr477i -lt $cr477cl.Count; $cr477i++) {
  if ($cr477cl[$cr477i] -match '::SetupPlayerInputComponent') { $cr477setup = $cr477i }
  if ($cr477cl[$cr477i] -match 'BuildFallbackInput') { if ($cr477fb -lt 0) { $cr477fb = $cr477i } }
}
Write-Output ('SETUP AT=' + $cr477setup + ' FALLBACK FIRST AT=' + $cr477fb)
if ($cr477setup -ge 0) { for ($cr477a = $cr477setup; $cr477a -lt [Math]::Min($cr477setup + 45, $cr477cl.Count); $cr477a++) { Write-Output ('IN ' + ($cr477a + 1) + ' ' + $cr477cl[$cr477a].Trim()) } }
$cr477gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$cr477gl = @(Get-Content $cr477gm)
$cr477menu = @(Select-String -Path $cr477gm -Pattern 'CreateWidget|SetInputMode|MainMenuWidget|ShowMain|InputMode' -ErrorAction SilentlyContinue)
foreach ($cr477mm in $cr477menu) { Write-Output ('MENU ' + $cr477mm.LineNumber + ' ' + $cr477mm.Line.Trim()) }
$cr477fl = @(Select-String -Path $cr477gm -Pattern 'ToggleFlight|BindKey\(EKeys::F' -ErrorAction SilentlyContinue)
foreach ($cr477ff in $cr477fl) { Write-Output ('FLY ' + $cr477ff.LineNumber + ' ' + $cr477ff.Line.Trim()) }
Write-Output ('PHI CR477 VERDICT: REGRESSION READ loghits=' + $cr477hits.Count + ' menulines=' + $cr477menu.Count)
Write-Output 'JOB 477 DONE'
```
