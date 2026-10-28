<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CYBERPUNK EXE CENSUS 415 - FIND THE EXECUTABLE, NAME THE FOLDER VORTEX NEEDS, AND CENSUS THE C SIDE FOR A GHOST, CHANGING NOTHING (Ground: Tyree installed Cyberpunk 2077 with the Phantom Liberty expansion to the D XboxGames folder on 2026-10-27, his standing layout with all games on D, and Vortex now answers the Cyberpunk entry with a Game not found dialog whose words say the directory it was pointed at does not contain bin x64 Cyberpunk2077.exe. The Starfield precedent on this same PC stands in the record: Vortex held a C ghost path while the real install lived on D. This job enumerates the Cyberpunk-named top-level folders under D XboxGames and searches inside each one recursively for Cyberpunk2077.exe, adds direct checks of the standard layout paths across every top-level folder, and prints every executable path found with its file size. For the first executable found it prints the parent chain up four levels and the ancestor folder that contains bin x64 Cyberpunk2077.exe in that layout on its own VORTEX FOLDER line, so the Content folder layout stands in print beside the plain layout. It then censuses C XboxGames for any Cyberpunk-named folder, printing EXISTS for each one found with whether a bin x64 Cyberpunk2077.exe stands inside it or the folder stands as an empty ghost with its file count, or the standing line that C XboxGames has no Cyberpunk folder. The verdict closes it: EXE ON D with the VORTEX FOLDER path, or EXE NOT FOUND ON D with what the census did find. Read-only throughout: no writes, no moves, no launches, no editor.) ==='
$dRoot = 'D:\XboxGames'
$cRoot = 'C:\XboxGames'
$exeName = 'Cyberpunk2077.exe'
$foundMap = @{}
$cyFolders = @()
$stdHits = 0
$foundList = @()
$vortexFolder = ''
Write-Output '--- SECTION 1: SEARCH D XBOXGAMES ---'
if (-not (Test-Path $dRoot)) {
  Write-Output 'D XBOXGAMES FOLDER ABSENT'
} else {
  $topFolders = @(Get-ChildItem $dRoot -Directory -ErrorAction SilentlyContinue)
  Write-Output ("D XBOXGAMES TOP FOLDER COUNT=" + $topFolders.Count)
  $cyFolders = @($topFolders | Where-Object { $_.Name -like '*Cyberpunk*' })
  Write-Output ("CYBERPUNK NAMED TOP FOLDER COUNT=" + $cyFolders.Count)
  foreach ($f in $cyFolders) { Write-Output ("CYBERPUNK TOP FOLDER: " + $f.FullName) }
  foreach ($f in $cyFolders) {
    $hits = @(Get-ChildItem $f.FullName -Recurse -Filter $exeName -File -ErrorAction SilentlyContinue)
    foreach ($h in $hits) { $foundMap[$h.FullName] = $h.Length }
  }
  foreach ($f in $topFolders) {
    foreach ($sub in @('bin\x64', 'Content\bin\x64')) {
      $cand = Join-Path (Join-Path $f.FullName $sub) $exeName
      if (Test-Path $cand) { $stdHits++; $fi = Get-Item $cand; $foundMap[$fi.FullName] = $fi.Length }
    }
  }
  $candRoot = Join-Path (Join-Path $dRoot 'bin\x64') $exeName
  if (Test-Path $candRoot) { $stdHits++; $fi = Get-Item $candRoot; $foundMap[$fi.FullName] = $fi.Length }
  Write-Output ("STANDARD LAYOUT DIRECT HITS=" + $stdHits)
}
$foundList = @($foundMap.Keys | Sort-Object)
Write-Output ("EXE FOUND COUNT=" + $foundList.Count)
foreach ($p in $foundList) { Write-Output ("EXE FOUND: " + $p + " size=" + $foundMap[$p]) }
Write-Output '--- SECTION 2: THE FOLDER VORTEX NEEDS ---'
if ($foundList.Count -gt 0) {
  $exePath = $foundList[0]
  $chain = @()
  $cur = Split-Path $exePath -Parent
  for ($i = 0; $i -lt 5; $i++) { if ($cur) { $chain += $cur; $cur = Split-Path $cur -Parent } }
  for ($i = 0; $i -lt $chain.Count; $i++) { Write-Output ("CHAIN LEVEL " + $i + ": " + $chain[$i]) }
  foreach ($a in $chain) {
    $cand = Join-Path (Join-Path $a 'bin\x64') $exeName
    if ($cand -eq $exePath) { $vortexFolder = $a; break }
  }
  if ($vortexFolder) { Write-Output ("VORTEX FOLDER: " + $vortexFolder) } else { Write-Output 'VORTEX FOLDER: NO STANDARD ANCESTOR - THE CHAIN ABOVE IS THE LAYOUT' }
} else {
  Write-Output 'NO EXE FOUND - NO FOLDER TO NAME'
}
Write-Output '--- SECTION 3: C XBOXGAMES CENSUS ---'
if (-not (Test-Path $cRoot)) {
  Write-Output 'C XBOXGAMES FOLDER ABSENT'
  Write-Output 'C XBOXGAMES HAS NO CYBERPUNK FOLDER'
} else {
  $cTop = @(Get-ChildItem $cRoot -Directory -ErrorAction SilentlyContinue)
  $cCy = @($cTop | Where-Object { $_.Name -like '*Cyberpunk*' })
  if ($cCy.Count -eq 0) {
    Write-Output 'C XBOXGAMES HAS NO CYBERPUNK FOLDER'
  } else {
    foreach ($f in $cCy) {
      Write-Output ("C CYBERPUNK FOLDER EXISTS: " + $f.FullName)
      $cExe = Join-Path (Join-Path $f.FullName 'bin\x64') $exeName
      $cExe2 = Join-Path (Join-Path $f.FullName 'Content\bin\x64') $exeName
      $fc = @(Get-ChildItem $f.FullName -Recurse -File -ErrorAction SilentlyContinue).Count
      Write-Output ("C CYBERPUNK FOLDER FILE COUNT=" + $fc)
      if ((Test-Path $cExe) -or (Test-Path $cExe2)) {
        Write-Output ("C CYBERPUNK EXE PRESENT under: " + $f.FullName)
      } elseif ($fc -eq 0) {
        Write-Output ("C CYBERPUNK FOLDER IS AN EMPTY GHOST: " + $f.FullName)
      } else {
        Write-Output ("C CYBERPUNK EXE ABSENT - FOLDER HOLDS FILES BUT NO EXE: " + $f.FullName)
      }
    }
  }
}
Write-Output '--- SECTION 4: VERDICT ---'
if ($foundList.Count -gt 0) {
  if ($vortexFolder) {
    Write-Output ("PHI EXE415 VERDICT EXE ON D VORTEX FOLDER: " + $vortexFolder)
  } else {
    Write-Output ("PHI EXE415 VERDICT EXE ON D NO STANDARD ANCESTOR exe=" + $foundList[0])
  }
} else {
  Write-Output ("PHI EXE415 VERDICT EXE NOT FOUND ON D cyberpunk_top_folders=" + $cyFolders.Count + " standard_hits=" + $stdHits)
}
Write-Output 'JOB 415 DONE'
```
