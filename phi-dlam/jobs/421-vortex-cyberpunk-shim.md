<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX CYBERPUNK SHIM 421 - MAKE VORTEX ABLE TO SEE THE CYBERPUNK INSTALL (Ground from job 417, read whole: the Microsoft Xbox build of Cyberpunk 2077 stands whole on D, the base folder D:\XboxGames\Cyberpunk 2077 holding 136 files and 61.3176 GB with the Phantom Liberty expansion in its own sibling folder at 54 files and 30.1006 GB, and no Cyberpunk2077.exe stands anywhere under D XboxGames, the only executables being cpLauncher.exe at 84910032 bytes inside the Content folder and gamelaunchhelper.exe twice. Vortex refuses every folder Tyree points it at because its Cyberpunk check demands bin\x64\Cyberpunk2077.exe under the selected folder, the GOG and Steam layout this build never carried. Tyree gave the word on 2026-10-28 at 08:13 MDT: get Vortex to find the files, or allow him, or whatever it takes. This job is the evidence-plus-shim run under that word. One, it locates cpLauncher.exe with a fresh forced search inside the base folder, errors printed and never swallowed, full path and size in print, and prints the top two directory levels of the base folder by name so the Content layout stands in print. Two, the access read prints the ACL owner and access rules for the Content folder and for cpLauncher.exe itself, then runs a write test that creates and immediately removes a zero byte probe file inside Content, printing WRITE OK or the denial verbatim, answering whether the folder allows additions at all. Three, the shim: only when the write test passed and Content\bin\x64\Cyberpunk2077.exe does not already stand, it creates the bin\x64 folders under Content if absent and places a hardlink named Cyberpunk2077.exe there pointing at cpLauncher.exe, then verifies in the same job that the link stands, that its size equals the cpLauncher size, and that the hardlink count for cpLauncher is at least two, printing SHIM PLACED with the full link path; when Content\bin\x64 already stands with files in it, the job censuses and prints those files and writes nothing, printing SHIM HELD LAYOUT ALREADY PRESENT; when the write test failed, it prints SHIM HELD with the denial as the reason; on any failure after a write it removes only what this job created and prints the removal. Four, the verdict in one line: VORTEX FOLDER READY with folder=D:\XboxGames\Cyberpunk 2077\Content, the folder that then contains bin\x64\Cyberpunk2077.exe, or VORTEX STILL BLIND with the named reason. Nothing moves and no game byte changes; the only creation is the hardlink alias, reversible by deleting the alias alone, and every variable carries the vtx421 prefix under the standing ban on automatic variable names.) ==='
$vtx421Base = 'D:\XboxGames\Cyberpunk 2077'
$vtx421Content = Join-Path $vtx421Base 'Content'
$vtx421LauncherName = 'cpLauncher.exe'
$vtx421LinkName = 'Cyberpunk2077.exe'
$vtx421LauncherPath = ''
$vtx421LauncherSize = 0
$vtx421WriteOk = 0
$vtx421WriteDeny = ''
$vtx421ShimState = 'NOT PLACED'
$vtx421BlindReason = ''
Write-Output '--- SECTION 1: LOCATE CPLAUNCHER ---'
if (-not (Test-Path $vtx421Base)) {
  Write-Output 'BASE FOLDER ABSENT'
  $vtx421BlindReason = 'base folder absent on D'
} else {
  $vtx421SearchErrs = @()
  $vtx421Hits = @(Get-ChildItem $vtx421Base -Recurse -Force -Filter $vtx421LauncherName -File -ErrorAction Continue -ErrorVariable vtx421SearchErrs)
  Write-Output ("SEARCH ERROR COUNT=" + $vtx421SearchErrs.Count)
  foreach ($vtx421OneErr in $vtx421SearchErrs) { Write-Output ("SEARCH ERROR: " + $vtx421OneErr.Exception.Message) }
  Write-Output ("LAUNCHER HIT COUNT=" + $vtx421Hits.Count)
  foreach ($vtx421Hit in $vtx421Hits) { Write-Output ("LAUNCHER: " + $vtx421Hit.FullName + " bytes=" + $vtx421Hit.Length) }
  if ($vtx421Hits.Count -gt 0) { $vtx421LauncherPath = $vtx421Hits[0].FullName; $vtx421LauncherSize = $vtx421Hits[0].Length }
  Write-Output ("LAUNCHER PATH: " + $vtx421LauncherPath)
  Write-Output ("LAUNCHER SIZE=" + $vtx421LauncherSize)
  Write-Output '--- BASE FOLDER TOP TWO LEVELS, NAMES ONLY ---'
  $vtx421Level1 = @(Get-ChildItem $vtx421Base -Directory -Force -ErrorAction Continue)
  foreach ($vtx421L1 in $vtx421Level1) {
    Write-Output ("LEVEL1: " + $vtx421L1.Name)
    $vtx421Level2 = @(Get-ChildItem $vtx421L1.FullName -Directory -Force -ErrorAction Continue)
    foreach ($vtx421L2 in $vtx421Level2) { Write-Output ("LEVEL2: " + $vtx421L1.Name + '\' + $vtx421L2.Name) }
  }
}
Write-Output '--- SECTION 2: ACCESS READ ---'
if (-not (Test-Path $vtx421Content)) {
  Write-Output 'CONTENT FOLDER ABSENT'
  if (-not $vtx421BlindReason) { $vtx421BlindReason = 'Content folder absent in the base tree' }
} else {
  $vtx421AclFolder = Get-Acl $vtx421Content
  Write-Output ("CONTENT ACL OWNER: " + $vtx421AclFolder.Owner)
  foreach ($vtx421RuleA in $vtx421AclFolder.Access) { Write-Output ("CONTENT RULE: " + $vtx421RuleA.IdentityReference + " rights=" + $vtx421RuleA.FileSystemRights + " type=" + $vtx421RuleA.AccessControlType) }
  if ($vtx421LauncherPath) {
    $vtx421AclExe = Get-Acl $vtx421LauncherPath
    Write-Output ("LAUNCHER ACL OWNER: " + $vtx421AclExe.Owner)
    foreach ($vtx421RuleB in $vtx421AclExe.Access) { Write-Output ("LAUNCHER RULE: " + $vtx421RuleB.IdentityReference + " rights=" + $vtx421RuleB.FileSystemRights + " type=" + $vtx421RuleB.AccessControlType) }
  }
  $vtx421Probe = Join-Path $vtx421Content 'phi421_probe.tmp'
  if (Test-Path $vtx421Probe) { Remove-Item $vtx421Probe -Force -ErrorAction Continue; Write-Output 'STALE PROBE REMOVED BEFORE TEST' }
  try {
    New-Item -ItemType File -Path $vtx421Probe -ErrorAction Stop | Out-Null
    if (Test-Path $vtx421Probe) {
      $vtx421WriteOk = 1
      Write-Output 'WRITE TEST: PROBE CREATED AND STANDING'
    } else {
      $vtx421WriteDeny = 'probe create returned with no file standing'
      Write-Output ("WRITE TEST FAILED: " + $vtx421WriteDeny)
    }
  } catch {
    $vtx421WriteDeny = $_.Exception.Message
    Write-Output ("WRITE DENIED: " + $vtx421WriteDeny)
  }
  if ($vtx421WriteOk -eq 1) {
    try {
      Remove-Item $vtx421Probe -Force -ErrorAction Stop
      Write-Output 'WRITE OK - PROBE CREATED AND REMOVED'
    } catch {
      Write-Output ("PROBE REMOVAL FAILED: " + $_.Exception.Message)
      Write-Output 'WRITE OK - PROBE CREATED, REMOVAL ANSWER STANDS ABOVE'
    }
  }
}
Write-Output '--- SECTION 3: THE SHIM ---'
$vtx421BinDir = Join-Path $vtx421Content 'bin'
$vtx421X64Dir = Join-Path $vtx421BinDir 'x64'
$vtx421LinkPath = Join-Path $vtx421X64Dir $vtx421LinkName
if (-not $vtx421LauncherPath) {
  Write-Output 'SHIM HELD - CPLAUNCHER NOT FOUND'
  $vtx421ShimState = 'HELD NO LAUNCHER'
  if (-not $vtx421BlindReason) { $vtx421BlindReason = 'cpLauncher.exe not found in the base folder census' }
} elseif (Test-Path $vtx421LinkPath) {
  $vtx421StandItem = Get-Item $vtx421LinkPath -Force
  Write-Output ("LINK ALREADY STANDING: " + $vtx421LinkPath + " bytes=" + $vtx421StandItem.Length)
  $vtx421StandList = @(fsutil hardlink list $vtx421LauncherPath)
  $vtx421StandCount = 0
  foreach ($vtx421StandLine in $vtx421StandList) { if ($vtx421StandLine -ne '') { $vtx421StandCount++; Write-Output ("HARDLINK LISTED: " + $vtx421StandLine) } }
  Write-Output ("HARDLINK COUNT FOR CPLAUNCHER=" + $vtx421StandCount)
  if (($vtx421StandItem.Length -eq $vtx421LauncherSize) -and ($vtx421StandCount -ge 2)) {
    $vtx421ShimState = 'STANDING VERIFIED'
  } else {
    $vtx421ShimState = 'STANDING UNVERIFIED'
    $vtx421BlindReason = 'an alias already stands at the bin x64 path but its size or hardlink count did not verify'
  }
} elseif ($vtx421WriteOk -ne 1) {
  Write-Output ("SHIM HELD - WRITE TEST FAILED: " + $vtx421WriteDeny)
  $vtx421ShimState = 'HELD WRITE DENIED'
  $vtx421BlindReason = 'the Content folder refused the write test: ' + $vtx421WriteDeny
} elseif ((Test-Path $vtx421X64Dir) -and (@(Get-ChildItem $vtx421X64Dir -Recurse -Force -ErrorAction Continue).Count -gt 0)) {
  $vtx421Present = @(Get-ChildItem $vtx421X64Dir -Recurse -Force -ErrorAction Continue)
  Write-Output ("BIN X64 ALREADY HOLDS ITEMS=" + $vtx421Present.Count)
  foreach ($vtx421Item in $vtx421Present) { Write-Output ("PRESENT: " + $vtx421Item.FullName + " bytes=" + $vtx421Item.Length) }
  Write-Output 'SHIM HELD LAYOUT ALREADY PRESENT'
  $vtx421ShimState = 'HELD LAYOUT PRESENT'
  $vtx421BlindReason = 'Content bin x64 already stands with files in it and the job wrote nothing into a standing layout'
} else {
  $vtx421MadeBin = 0
  $vtx421MadeX64 = 0
  $vtx421MadeLink = 0
  try {
    if (-not (Test-Path $vtx421BinDir)) { New-Item -ItemType Directory -Path $vtx421BinDir -ErrorAction Stop | Out-Null; $vtx421MadeBin = 1; Write-Output ("CREATED DIR: " + $vtx421BinDir) }
    if (-not (Test-Path $vtx421X64Dir)) { New-Item -ItemType Directory -Path $vtx421X64Dir -ErrorAction Stop | Out-Null; $vtx421MadeX64 = 1; Write-Output ("CREATED DIR: " + $vtx421X64Dir) }
    try {
      New-Item -ItemType HardLink -Path $vtx421LinkPath -Target $vtx421LauncherPath -ErrorAction Stop | Out-Null
      $vtx421MadeLink = 1
    } catch {
      Write-Output ("NEW-ITEM HARDLINK ERROR: " + $_.Exception.Message)
      $vtx421FsutilOut = @(fsutil hardlink create $vtx421LinkPath $vtx421LauncherPath 2>&1)
      foreach ($vtx421FsLine in $vtx421FsutilOut) { Write-Output ("FSUTIL: " + $vtx421FsLine) }
      if (Test-Path $vtx421LinkPath) { $vtx421MadeLink = 1 }
    }
    if ($vtx421MadeLink -ne 1) { throw 'hardlink creation failed on both the New-Item road and the fsutil road' }
    $vtx421LinkItem = Get-Item $vtx421LinkPath -Force -ErrorAction Stop
    $vtx421NewList = @(fsutil hardlink list $vtx421LauncherPath)
    $vtx421NewCount = 0
    foreach ($vtx421NewLine in $vtx421NewList) { if ($vtx421NewLine -ne '') { $vtx421NewCount++; Write-Output ("HARDLINK LISTED: " + $vtx421NewLine) } }
    Write-Output ("LINK SIZE=" + $vtx421LinkItem.Length + " LAUNCHER SIZE=" + $vtx421LauncherSize)
    Write-Output ("HARDLINK COUNT FOR CPLAUNCHER=" + $vtx421NewCount)
    if (($vtx421LinkItem.Length -eq $vtx421LauncherSize) -and ($vtx421NewCount -ge 2)) {
      $vtx421ShimState = 'PLACED VERIFIED'
      Write-Output ("SHIM PLACED: " + $vtx421LinkPath)
    } else {
      throw 'verification counts did not match after link creation'
    }
  } catch {
    $vtx421FailText = $_.Exception.Message
    Write-Output ("SHIM FAILED: " + $vtx421FailText)
    if (Test-Path $vtx421LinkPath) { Remove-Item $vtx421LinkPath -Force -ErrorAction Continue; Write-Output ("REMOVED AFTER FAILURE: " + $vtx421LinkPath) }
    if ($vtx421MadeX64 -eq 1) { Remove-Item $vtx421X64Dir -Force -ErrorAction Continue; Write-Output ("REMOVED AFTER FAILURE: " + $vtx421X64Dir) }
    if ($vtx421MadeBin -eq 1) { Remove-Item $vtx421BinDir -Force -ErrorAction Continue; Write-Output ("REMOVED AFTER FAILURE: " + $vtx421BinDir) }
    $vtx421ShimState = 'FAILED AND CLEANED'
    $vtx421BlindReason = 'the shim attempt failed and only its own creations were removed: ' + $vtx421FailText
  }
}
Write-Output '--- SECTION 4: VERDICT ---'
Write-Output ("SHIM STATE: " + $vtx421ShimState)
if (($vtx421ShimState -eq 'PLACED VERIFIED') -or ($vtx421ShimState -eq 'STANDING VERIFIED')) {
  Write-Output ("PHI VORTEX421 VERDICT: VORTEX FOLDER READY folder=" + $vtx421Content)
} else {
  Write-Output ("PHI VORTEX421 VERDICT: VORTEX STILL BLIND reason=" + $vtx421BlindReason + " shim_state=" + $vtx421ShimState)
}
Write-Output 'JOB 421 DONE'
```
