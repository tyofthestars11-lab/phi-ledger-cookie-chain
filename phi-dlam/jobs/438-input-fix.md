<!-- PHI-DIRECT -->
```powershell
Write-Output '=== INPUT FIX 438 - THE CONTROLS ANSWER AT THEIR OWN ADDRESS (Ground read whole from jobs 432 and 435: the character binds eight Enhanced Input actions, each behind a null guard; five input assets stand in Content, IA Move, IA Look, IA Jump, IA Menu, and IMC Default at 14647 bytes; the character holds a DefaultMappingContext property and a code fallback, BuildFallbackInput, which builds actions when the default context is null; and BeginPlay adds a mapping context to the subsystem only through the DefaultMappingContext branch, so if that property stands unassigned on the C plus plus pawn class the GameMode spawns, no mapping context ever goes active and no key or stick ever becomes an action value, which is the dead controls Tyree reports from his chair. This job repairs both roads in one pass, each edit counted and verified. One, it prints VEILCharacter cpp lines 182 to 252, the fallback function entire, and counts the BuiltMappingContext assignments and adds. Two, it derives the true asset paths from the files standing in Content, splitting each full name at the Content folder, so the paths are measured, never typed from memory. Three, Edit B: the BeginPlay fallback block is replaced by a block that first loads IMC Default and the Move, Look, and Jump actions from their measured paths, the same LoadObject shape this very function already uses for its animation at line 150, and only falls back to the code build if the load leaves the context null. Four, Edit A: if the fallback builds a BuiltMappingContext that nothing adds, the subsystem add for the default context gains a sibling line that adds the built context when it stands. Five, every edit is backup first, counted before, and read back after; then the job compiles VEILEditor Win64 Development and prints the last 15 lines of the build log whole. Six, the verdict in one line: INPUT FIX with the edit states and the asset load count. Every variable carries the if438 prefix.) ==='
$if438root = 'D:\VEIL-OMNI'
$if438src = Join-Path $if438root 'Source\VEIL'
$if438char = Get-ChildItem -Path $if438src -Recurse -Filter 'VEILCharacter.cpp' | Select-Object -First 1
if (-not $if438char) { Write-Output 'INPUT FIX HELD stage=character-missing'; Write-Output 'JOB 438 DONE'; exit 0 }
$if438lines = Get-Content $if438char.FullName
Write-Output '--- FALLBACK 182-252 ---'
for ($if438i = 181; $if438i -lt 252 -and $if438i -lt $if438lines.Count; $if438i++) { Write-Output ('FB ' + ($if438i + 1) + ': ' + $if438lines[$if438i]) }
$if438body = [IO.File]::ReadAllText($if438char.FullName)
$if438bmAssign = ([regex]::Matches($if438body, 'BuiltMappingContext\s*=')).Count
$if438bmAdd = ([regex]::Matches($if438body, 'AddMappingContext\(BuiltMappingContext')).Count
Write-Output ('BUILT CONTEXT assign=' + $if438bmAssign + ' add=' + $if438bmAdd)
function Get-GamePath438($if438file) { $if438parts = $if438file.FullName -split '\\Content\\'; if ($if438parts.Count -lt 2) { return '' }; $if438rel = $if438parts[1] -replace '\\', '/'; $if438rel = $if438rel -replace '\.uasset$', ''; return '/Game/' + $if438rel + '.' + $if438file.BaseName }
$if438content = Join-Path $if438root 'Content'
$if438imc = Get-ChildItem -Path $if438content -Recurse -Filter 'IMC_Default.uasset' | Select-Object -First 1
$if438move = Get-ChildItem -Path $if438content -Recurse -Filter 'IA_Move.uasset' | Select-Object -First 1
$if438look = Get-ChildItem -Path $if438content -Recurse -Filter 'IA_Look.uasset' | Select-Object -First 1
$if438jump = Get-ChildItem -Path $if438content -Recurse -Filter 'IA_Jump.uasset' | Select-Object -First 1
$if438pIMC = ''; $if438pMove = ''; $if438pLook = ''; $if438pJump = ''
if ($if438imc) { $if438pIMC = Get-GamePath438 $if438imc }
if ($if438move) { $if438pMove = Get-GamePath438 $if438move }
if ($if438look) { $if438pLook = Get-GamePath438 $if438look }
if ($if438jump) { $if438pJump = Get-GamePath438 $if438jump }
Write-Output ('PATHS imc=' + $if438pIMC + ' move=' + $if438pMove + ' look=' + $if438pLook + ' jump=' + $if438pJump)
Copy-Item $if438char.FullName ($if438char.FullName + '.phi-backup-438') -Force
$if438editB = 'SKIPPED'
if ($if438pIMC -ne '' -and $if438pMove -ne '') {
  $if438patB = 'if \(!DefaultMappingContext\)\s*\{\s*BuildFallbackInput\(\);\s*\}'
  $if438cntB = ([regex]::Matches($if438body, $if438patB)).Count
  Write-Output ('EDIT B anchor count=' + $if438cntB)
  if ($if438cntB -eq 1) {
    $if438repB = "if (!DefaultMappingContext)`n`t{`n`t`tDefaultMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT(`"$if438pIMC`"));`n`t`tif (DefaultMappingContext)`n`t`t{`n`t`t`tMoveAction = LoadObject<UInputAction>(nullptr, TEXT(`"$if438pMove`"));`n`t`t`tLookAction = LoadObject<UInputAction>(nullptr, TEXT(`"$if438pLook`"));`n`t`t`tJumpAction = LoadObject<UInputAction>(nullptr, TEXT(`"$if438pJump`"));`n`t`t}`n`t}`n`tif (!DefaultMappingContext)`n`t{`n`t`tBuildFallbackInput();`n`t}"
    $if438body = [regex]::Replace($if438body, $if438patB, $if438repB)
    $if438editB = 'APPLIED'
  } else { $if438editB = 'HELD-COUNT' }
}
$if438editA = 'SKIPPED'
if ($if438bmAssign -ge 1 -and $if438bmAdd -eq 0) {
  $if438patA = 'Sub->AddMappingContext\(DefaultMappingContext, 0\);'
  $if438cntA = ([regex]::Matches($if438body, $if438patA)).Count
  Write-Output ('EDIT A anchor count=' + $if438cntA)
  if ($if438cntA -eq 1) {
    $if438repA = "Sub->AddMappingContext(DefaultMappingContext, 0);`n`t\t\tif (BuiltMappingContext) { Sub->AddMappingContext(BuiltMappingContext, 0); }"
    $if438body = [regex]::Replace($if438body, $if438patA, $if438repA)
    $if438editA = 'APPLIED'
  } else { $if438editA = 'HELD-COUNT' }
}
if ($if438editA -ne 'SKIPPED' -or $if438editB -ne 'SKIPPED') { [IO.File]::WriteAllText($if438char.FullName, $if438body, (New-Object System.Text.UTF8Encoding $false)) }
$if438back = [IO.File]::ReadAllText($if438char.FullName)
$if438vLoads = ([regex]::Matches($if438back, 'LoadObject<UInputMappingContext>')).Count
$if438vAdds = ([regex]::Matches($if438back, 'AddMappingContext\(BuiltMappingContext')).Count
Write-Output ('VERIFY loads=' + $if438vLoads + ' built_adds=' + $if438vAdds + ' editA=' + $if438editA + ' editB=' + $if438editB)
$if438buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$if438uproj = Join-Path $if438root 'VEIL.uproject'
$if438log = Join-Path $if438root 'Saved\build438.log'
& $if438buildbat VEILEditor Win64 Development -Project="$if438uproj" -WaitMutex -NoHotReload *> "$if438log"
Write-Output '--- BUILD LOG TAIL ---'
Get-Content $if438log -Tail 15 | ForEach-Object { Write-Output ('LOG ' + $_) }
$if438raw = Get-Content $if438log -Raw
$if438bst = 'UNKNOWN'
if ($if438raw.Contains('BUILD SUCCESS')) { $if438bst = 'OK' } elseif ($if438raw -match 'BUILD FAILED|Build failed') { $if438bst = 'FAIL' }
Write-Output ('PHI IF438 VERDICT: INPUT FIX editA=' + $if438editA + ' editB=' + $if438editB + ' loads=' + $if438vLoads + ' build=' + $if438bst)
Write-Output 'JOB 438 DONE'
```
