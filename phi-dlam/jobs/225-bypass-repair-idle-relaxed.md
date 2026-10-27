# Job 225 — Bypass repair: the three compile faults corrected, real idle posed, GameMode header-first fixed, build both

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 220s strike hit three faults in this seats code, all named by its build: (1) EAnimationMode::AnimationAsset does not exist in UE 5.8 - the single-node value is AnimationSingleNode; (2) StaticLoadObject returns UObject* - the templated LoadObject<UAnimSequence> is the correct load; (3) its pose pick took Idle_AO_CC, an aim-offset additive - the packs true idle is Idle_Relaxed, named in 220s own census. Plus a fourth the same build exposed: both GameMode.cpp files open with EngineUtils.h - their own header sits at line 4, tripping UBTs first-header rule when the module fully recompiles. This job corrects all four in both games, verifies every anchor before writing, rebuilds both editors, and prints the results. Backups of the current state: D:\_PhiHolding\src-backup-225. Originals from before 220 stand in src-backup-220. ==='
$pose = '/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed'
$enc = New-Object System.Text.UTF8Encoding($false)
New-Item -ItemType Directory -Force -Path 'D:\_PhiHolding\src-backup-225' | Out-Null
$running = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($running) { Write-Output "NOTE: UnrealEditor processes running: $($running.Id -join ', ') - if a link fails on a locked DLL, that is the lock; close the editors and the next drain rebuilds." } else { Write-Output 'No UnrealEditor process running - build lane clear.' }
foreach ($g in @(@('VEIL','D:\VEIL\Source\VEIL'), @('OMNI','D:\OMNI-UE\Source\OMNI'))) {
  $name = $g[0]; $root = $g[1]
  $charFile = "$root\Private\Character\$($name)Character.cpp"
  Copy-Item $charFile "D:\_PhiHolding\src-backup-225\$($name)Character.cpp" -Force
  $src = [IO.File]::ReadAllText($charFile)
  $n1 = ([regex]::Matches($src, 'EAnimationMode::AnimationAsset')).Count
  $src = $src -replace 'EAnimationMode::AnimationAsset', 'EAnimationMode::AnimationSingleNode'
  $n2 = ([regex]::Matches($src, 'StaticLoadObject\(UAnimSequence::StaticClass')).Count
  $src = $src -replace 'UAnimSequence\* PoseSeq = StaticLoadObject\(UAnimSequence::StaticClass\(\), nullptr, TEXT\("[^"]*"\)\)', "UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT(`"$pose`"))"
  $n3 = ([regex]::Matches($src, 'FObjectFinder<UAnimSequence> MannyAnim')).Count
  $src = $src -replace '(FObjectFinder<UAnimSequence> MannyAnim\(\s*TEXT\(")[^"]*("\))', "`$1$pose`$2"
  $good = ($n1 -eq 1) -and ($n2 -eq 1) -and ($n3 -eq 1) -and ($src -match 'AnimationSingleNode') -and ($src -match 'LoadObject<UAnimSequence>') -and (([regex]::Matches($src, 'Idle_Relaxed\.Idle_Relaxed')).Count -eq 2) -and ($src -notmatch 'Idle_AO_CC') -and ($src -notmatch 'StaticLoadObject')
  if ($good) { [IO.File]::WriteAllText($charFile, $src, $enc); Write-Output "$name character repaired: enum fixed ($n1), loader fixed ($n2), finder+pose -> Idle_Relaxed ($n3)." }
  else { Write-Output "$name CHARACTER REPAIR ABORTED - anchors n1=$n1 n2=$n2 n3=$n3; file untouched." }
  $gmFile = "$root\Private\Game\$($name)GameMode.cpp"
  Copy-Item $gmFile "D:\_PhiHolding\src-backup-225\$($name)GameMode.cpp" -Force
  $gm = [IO.File]::ReadAllText($gmFile)
  $inc = "#include `"Game/$($name)GameMode.h`""
  if ($gm -match [regex]::Escape($inc)) {
    $gm = $gm -replace ([regex]::Escape($inc) + '\r?\n'), ''
    $gm = $inc + "`r`n" + $gm.TrimStart([char]0xFEFF, "`r", "`n")
    [IO.File]::WriteAllText($gmFile, $gm, $enc)
    Write-Output "$name GameMode: own header moved to line 1."
  } else { Write-Output "$name GameMode: own-header include not found - untouched." }
}
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  Write-Output "--- BUILD $name ---"
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
}
```
