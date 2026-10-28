<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CYBERPUNK FOLDER CENSUS 417 - WHAT ACTUALLY STANDS INSIDE THE TWO CYBERPUNK FOLDERS ON D (Ground from job 415: D XboxGames holds three top folders and two of them carry the Cyberpunk name, Cyberpunk 2077 and Cyberpunk 2077- Phantom Liberty, yet a recursive search inside them found zero Cyberpunk2077.exe and zero standard layout hits, and C XboxGames holds no Cyberpunk folder at all. Vortex answers Game not found because the executable it needs does not stand where it points. The open question is what those two D folders actually hold: a full payload under an unexpected layout, a partial payload, or empty package stubs from a download that never landed its files. This job censuses both folders and changes nothing: one, for each of the two folders print the total file count, the total size in bytes and in GB, and the fifteen largest files with names and sizes. Two, print every exe file anywhere under D XboxGames, all three top folders recursive, with full path and size, any name at all. Three, print the third top folder name and its total size so the whole drive picture stands in print. Four, the verdict in one line: INSTALL STATE with the base folder file count and GB and the exe names found, showing whether the payload ever landed or the folders stand as stubs. Read-only throughout: no writes, no moves, no launches.) ==='
$dRoot = 'D:\XboxGames'
$folders = @('D:\XboxGames\Cyberpunk 2077', 'D:\XboxGames\Cyberpunk 2077- Phantom Liberty')
$baseCount = 0
$baseGB = 0
Write-Output '--- SECTION 1: THE TWO CYBERPUNK FOLDERS ---'
foreach ($folder in $folders) {
  Write-Output ("FOLDER: " + $folder)
  if (-not (Test-Path $folder)) { Write-Output 'FOLDER ABSENT'; continue }
  $files = @(Get-ChildItem $folder -Recurse -File -ErrorAction SilentlyContinue)
  $total = 0
  foreach ($oneFile in $files) { $total += $oneFile.Length }
  $gb = [math]::Round($total / 1073741824, 4)
  Write-Output ("FILE COUNT=" + $files.Count)
  Write-Output ("TOTAL BYTES=" + $total)
  Write-Output ("TOTAL GB=" + $gb)
  if ($folder -eq $folders[0]) { $baseCount = $files.Count; $baseGB = $gb }
  $largest = $files | Sort-Object Length -Descending | Select-Object -First 15
  $rank = 0
  foreach ($big in $largest) { $rank++; Write-Output ("LARGEST " + $rank + ": " + $big.Name + " bytes=" + $big.Length + " path=" + $big.FullName) }
}
Write-Output '--- SECTION 2: EVERY EXE UNDER D XBOXGAMES ---'
$exes = @()
if (Test-Path $dRoot) { $exes = @(Get-ChildItem $dRoot -Recurse -Filter '*.exe' -File -ErrorAction SilentlyContinue) }
Write-Output ("EXE COUNT=" + $exes.Count)
$exeNames = @()
foreach ($exe in $exes) { Write-Output ("EXE: " + $exe.FullName + " bytes=" + $exe.Length); $exeNames += $exe.Name }
Write-Output '--- SECTION 3: THE THIRD TOP FOLDER ---'
if (Test-Path $dRoot) {
  $tops = @(Get-ChildItem $dRoot -Directory -ErrorAction SilentlyContinue)
  Write-Output ("TOP FOLDER COUNT=" + $tops.Count)
  foreach ($top in $tops) {
    if ($top.Name -notlike '*Cyberpunk*') {
      $topFiles = @(Get-ChildItem $top.FullName -Recurse -File -ErrorAction SilentlyContinue)
      $topTotal = 0
      foreach ($topFile in $topFiles) { $topTotal += $topFile.Length }
      Write-Output ("THIRD TOP FOLDER: " + $top.Name + " filecount=" + $topFiles.Count + " bytes=" + $topTotal)
    }
  }
}
Write-Output '--- SECTION 4: VERDICT ---'
if ($exeNames.Count -gt 0) {
  Write-Output ("PHI EXE417 VERDICT: INSTALL STATE base_files=" + $baseCount + " base_gb=" + $baseGB + " exes=" + ($exeNames -join ','))
} else {
  Write-Output ("PHI EXE417 VERDICT: INSTALL STATE base_files=" + $baseCount + " base_gb=" + $baseGB + " exes=NONE FOUND")
}
Write-Output 'JOB 417 DONE'
```
