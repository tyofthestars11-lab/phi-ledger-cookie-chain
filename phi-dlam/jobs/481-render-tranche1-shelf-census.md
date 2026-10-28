<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RENDER TRANCHE ONE 481 - THE SHELF READ (Ground: Tyree, 2026-10-28, still no new rendering. The entered world stands in template shapes because no real mesh or surface from his own shelves has been seated in it yet, and the seating job authors only from printed paths, never from shelf names remembered or guessed. Job 474 already proved the hero meshes do not stand under SK names, so this census reads the Paragon shelves exactly as they lie: every file under any Mesh folder, every file whose name carries SK or SM, and every animation blueprint, for Greystone, Murdock, Revenant, Countess and the Minions, printed with its full path and size. It also prints every line in the game source where a mesh is assigned today and every SpawnActor line, so the seating pass sees both the shelves and the seats in one read. Read only, nothing written, nothing moved. Every variable carries the rc481 prefix.) ==='
$rc481content = 'D:\VEIL-OMNI\Content'
$rc481heroes = @('ParagonGreystone', 'ParagonMurdock', 'ParagonRevenant', 'ParagonCountess', 'ParagonMinions')
$rc481counts = @()
foreach ($rc481hero in $rc481heroes) {
  $rc481root = Join-Path $rc481content $rc481hero
  if (-not (Test-Path $rc481root)) { Write-Output ('SHELF ' + $rc481hero + ' MISSING'); $rc481counts += ($rc481hero + '=0'); continue }
  $rc481files = @(Get-ChildItem -Path $rc481root -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.FullName -match 'Mesh' -or $_.Name -match '^(SK_|SM_)' -or $_.Name -match 'AnimBlueprint|_ABP' })
  $rc481counts += ($rc481hero + '=' + $rc481files.Count)
  $rc481shown = 0
  foreach ($rc481f in $rc481files) {
    if ($rc481shown -ge 120) { Write-Output ('MESH ' + $rc481hero + ' TRUNCATED'); break }
    Write-Output ('MESH ' + $rc481hero + ' ' + $rc481f.FullName.Substring($rc481content.Length) + ' ' + $rc481f.Length)
    $rc481shown++
  }
}
$rc481src = 'D:\VEIL-OMNI\Source\VEIL\Private'
$rc481cpps = @(Get-ChildItem -Path $rc481src -Recurse -Filter *.cpp -File -ErrorAction SilentlyContinue)
$rc481meshSet = @($rc481cpps | Select-String -SimpleMatch 'SkeletalMesh' -ErrorAction SilentlyContinue | Select-Object -First 60)
foreach ($rc481ms in $rc481meshSet) { Write-Output ('MESHSET ' + $rc481ms.Filename + ' ' + $rc481ms.LineNumber + ' ' + $rc481ms.Line.Trim()) }
$rc481spawns = @($rc481cpps | Select-String -Pattern 'SpawnActo[r]' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($rc481sp in $rc481spawns) { Write-Output ('SPAWN ' + $rc481sp.Filename + ' ' + $rc481sp.LineNumber + ' ' + $rc481sp.Line.Trim()) }
Write-Output ('PHI RC481 VERDICT: RENDER CENSUS ' + ($rc481counts -join ' ') + ' meshset=' + $rc481meshSet.Count + ' spawns=' + $rc481spawns.Count)
Write-Output 'JOB 481 DONE'
```
