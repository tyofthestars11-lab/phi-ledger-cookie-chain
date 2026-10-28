<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SINGLE VOICE FIX 434 - THE NARRATOR SPEAKS ONCE IN THE MERGED GAME (Ground read whole from job 431: exactly two intro voice call sites stand in the merged module, VEILGameMode cpp line 154 plays V01 at GameMode BeginPlay, and OMNIQuestSystem cpp line 24 plays O01 inside OnWorldBeginPlay; both fire at boot, and Tyree heard the narrator twice over itself at his television. The merged game base is VEIL, its intro stands at V01, and the OMNI quest beats O03, O06, O08, O13, and O16 keep their voices at their stages; the one line that doubles the intro is the quest boot call. One, the job finds OMNIQuestSystem cpp under Source VEIL by name, backs it up to a phi-backup-434 copy, and counts the exact boot call string; unless the count is exactly one the job holds and prints why. Two, the job replaces that one call with a comment line that records the merge: the intro voice stands at V01 in the GameMode, one narrator at one address. Three, the job reads the file back and verifies: the O01 play count in the quest system is zero, and the V01 play count in VEILGameMode cpp still stands at one. Four, the job compiles with Build dot bat, VEILEditor Win64 Development against the VEIL-OMNI project, and prints the build log lines that carry error or success. Five, the verdict in one line: SINGLE VOICE FIXED with the verify counts and the build state, or SINGLE VOICE HELD with the stage named. Every variable carries the sv434 prefix.) ==='
$sv434root = 'D:\VEIL-OMNI'
$sv434src = Join-Path $sv434root 'Source\VEIL'
$sv434file = Get-ChildItem -Path $sv434src -Recurse -Filter 'OMNIQuestSystem.cpp' | Select-Object -First 1
if (-not $sv434file) { Write-Output 'SINGLE VOICE HELD stage=quest-system-missing'; Write-Output 'JOB 434 DONE'; exit 0 }
Write-Output ('QUEST SYSTEM: ' + $sv434file.FullName)
Copy-Item $sv434file.FullName ($sv434file.FullName + '.phi-backup-434') -Force
$sv434body = [IO.File]::ReadAllText($sv434file.FullName)
$sv434needle = 'FPHIVoice::Play(&InWorld, TEXT("O01"));'
$sv434count = ([regex]::Matches($sv434body, [regex]::Escape($sv434needle))).Count
Write-Output ('BOOT CALL COUNT=' + $sv434count)
if ($sv434count -ne 1) { Write-Output 'SINGLE VOICE HELD stage=count-not-one'; Write-Output 'JOB 434 DONE'; exit 0 }
$sv434new = $sv434body.Replace($sv434needle, '/* PHI 434: the merged intro stands at V01 in the GameMode; this quest boot beat stays silent so the narrator speaks once. */')
[IO.File]::WriteAllText($sv434file.FullName, $sv434new, (New-Object System.Text.UTF8Encoding $false))
$sv434back = [IO.File]::ReadAllText($sv434file.FullName)
$sv434o01 = ([regex]::Matches($sv434back, [regex]::Escape($sv434needle))).Count
$sv434gm = Get-ChildItem -Path $sv434src -Recurse -Filter 'VEILGameMode.cpp' | Select-Object -First 1
$sv434v01 = 0
if ($sv434gm) { $sv434v01 = ([regex]::Matches([IO.File]::ReadAllText($sv434gm.FullName), [regex]::Escape('FPHIVoice::Play(GetWorld(), TEXT("V01"));'))).Count }
Write-Output ('VERIFY o01_plays=' + $sv434o01 + ' v01_plays=' + $sv434v01)
$sv434buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$sv434uproj = Join-Path $sv434root 'VEIL.uproject'
$sv434log = Join-Path $sv434root 'Saved\build434.log'
& $sv434buildbat VEILEditor Win64 Development -Project="$sv434uproj" -WaitMutex -NoHotReload *> "$sv434log"
$sv434tail = @(Select-String -Path $sv434log -Pattern 'error|BUILD SUCCESS|Build succeeded|Total time' -ErrorAction SilentlyContinue)
$sv434tail | Select-Object -Last 12 | ForEach-Object { Write-Output ('BUILD ' + $_.Line.Trim()) }
$sv434ok = 'UNKNOWN'
if (Test-Path $sv434log) { $sv434raw = Get-Content $sv434log -Raw; if ($sv434raw -match 'BUILD SUCCESS') { $sv434ok = 'OK' } elseif ($sv434raw -match 'erro[r]') { $sv434ok = 'FAIL' } }
Write-Output ('PHI SV434 VERDICT: SINGLE VOICE FIXED o01=' + $sv434o01 + ' v01=' + $sv434v01 + ' build=' + $sv434ok)
Write-Output 'JOB 434 DONE'
```
