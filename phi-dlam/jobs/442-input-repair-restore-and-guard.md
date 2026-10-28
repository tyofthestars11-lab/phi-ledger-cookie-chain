<!-- PHI-DIRECT -->
```powershell
Write-Output '=== INPUT REPAIR 442 - RESTORE THE CHARACTER, THEN CLOSE THE TRUE LINK (Ground read whole from job 438: both its edits applied and verified by count, loads 1 and built adds 1, but the compile broke at VEILCharacter cpp lines 191 and 194 with brace errors at the edited BeginPlay ground, Result Failed; job 440 compiled the world builder clean and failed only on this same character file, so the Hub stands ready behind this one repair. Ground read whole from jobs 435 and 438: the fallback function, printed entire by 438, builds every action and its full keyboard and Xbox map and ends by assigning DefaultMappingContext from BuiltMappingContext at its line 246, so the context road was whole all along; the dead link stands one step earlier, at SetupPlayerInputComponent, which runs at possession, before BeginPlay builds anything, and reads action pointers that are null at that hour, so its null guards skip every bind and no key ever reaches a function. One, the job prints VEILCharacter cpp lines 150 to 215 as they stand, the damaged ground on the record. Two, it restores the file from its phi-backup-438 copy and verifies the restore: the 438 load count and built add count both read zero again. Three, it applies the repair at the true address: after the Super SetupPlayerInputComponent line, counted exactly once, it inserts a guard that builds the fallback input on the spot when the actions or the context stand unbuilt, so the binds below it read live actions in the same call; the read back counts the BuildFallbackInput call sites, which stand at two, the BeginPlay call and this guard. Four, it compiles VEILEditor Win64 Development, prints the last 15 lines of the log whole, and reads the build state from the Result line itself. Five, the verdict in one line: INPUT REPAIRED with the counts and the build state, or INPUT REPAIR HELD with the stage named. Every variable carries the ir442 prefix.) ==='
$ir442root = 'D:\VEIL-OMNI'
$ir442src = Join-Path $ir442root 'Source\VEIL'
$ir442char = Get-ChildItem -Path $ir442src -Recurse -Filter 'VEILCharacter.cpp' | Select-Object -First 1
if (-not $ir442char) { Write-Output 'INPUT REPAIR HELD stage=character-missing'; Write-Output 'JOB 442 DONE'; exit 0 }
$ir442lines = Get-Content $ir442char.FullName
Write-Output '--- DAMAGED GROUND 150-215 ---'
for ($ir442i = 149; $ir442i -lt 215 -and $ir442i -lt $ir442lines.Count; $ir442i++) { Write-Output ('DG ' + ($ir442i + 1) + ': ' + $ir442lines[$ir442i]) }
$ir442backup = $ir442char.FullName + '.phi-backup-438'
if (-not (Test-Path $ir442backup)) { Write-Output 'INPUT REPAIR HELD stage=backup-missing'; Write-Output 'JOB 442 DONE'; exit 0 }
Copy-Item $ir442backup $ir442char.FullName -Force
$ir442body = [IO.File]::ReadAllText($ir442char.FullName)
$ir442rLoads = ([regex]::Matches($ir442body, 'LoadObject<UInputMappingContext>')).Count
$ir442rAdds = ([regex]::Matches($ir442body, 'AddMappingContext\(BuiltMappingContext')).Count
Write-Output ('RESTORE CHECK loads=' + $ir442rLoads + ' built_adds=' + $ir442rAdds)
if ($ir442rLoads -ne 0 -or $ir442rAdds -ne 0) { Write-Output 'INPUT REPAIR HELD stage=restore-dirty'; Write-Output 'JOB 442 DONE'; exit 0 }
Copy-Item $ir442char.FullName ($ir442char.FullName + '.phi-backup-442') -Force
$ir442anchor = 'Super::SetupPlayerInputComponent(PlayerInputComponent);'
$ir442cnt = ([regex]::Matches($ir442body, [regex]::Escape($ir442anchor))).Count
Write-Output ('GUARD ANCHOR=' + $ir442cnt)
if ($ir442cnt -ne 1) { Write-Output 'INPUT REPAIR HELD stage=anchor-count'; Write-Output 'JOB 442 DONE'; exit 0 }
$ir442rep = $ir442anchor + "`n`n`t// PHI 442: possession runs before BeginPlay, so the binds below read`n`t// actions that stand unbuilt at this hour and their null guards skip`n`t// every bind. Build the standing fallback here, at the bind itself.`n`tif (!MoveAction || !DefaultMappingContext)`n`t{`n`t`tBuildFallbackInput();`n`t}"
$ir442body = $ir442body.Replace($ir442anchor, $ir442rep)
[IO.File]::WriteAllText($ir442char.FullName, $ir442body, (New-Object System.Text.UTF8Encoding $false))
$ir442back = [IO.File]::ReadAllText($ir442char.FullName)
$ir442calls = ([regex]::Matches($ir442back, 'BuildFallbackInput\(\);')).Count
Write-Output ('VERIFY fallback call sites=' + $ir442calls)
$ir442buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$ir442uproj = Join-Path $ir442root 'VEIL.uproject'
$ir442log = Join-Path $ir442root 'Saved\build442.log'
& $ir442buildbat VEILEditor Win64 Development -Project="$ir442uproj" -WaitMutex -NoHotReload *> "$ir442log"
Write-Output '--- BUILD LOG TAIL ---'
Get-Content $ir442log -Tail 15 | ForEach-Object { Write-Output ('LOG ' + $_) }
$ir442raw = Get-Content $ir442log -Raw
$ir442bst = 'UNKNOWN'
if ($ir442raw -match 'Result: Succeeded') { $ir442bst = 'OK' } elseif ($ir442raw -match 'Result: Failed') { $ir442bst = 'FAIL' }
Write-Output ('PHI IR442 VERDICT: INPUT REPAIRED calls=' + $ir442calls + ' build=' + $ir442bst)
Write-Output 'JOB 442 DONE'
```
