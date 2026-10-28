<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX SHIM ROAD B 423 - THE FILESYSTEM TYPE READ, THE HARDLINK CAPABILITY PROBED WITH TEMP FILES, AND THE CYBERPUNK2077.EXE ALIAS PLACED AS HARDLINK OR COPY BY WHAT THE PROBE PROVES (Ground from job 421, read whole: inside the Content folder of the Microsoft Xbox Cyberpunk 2077 install on D a zero byte write probe passed so additions are allowed, but creating a hardlink to cpLauncher.exe at 84910032 bytes was refused with Access denied on both the New-Item road and the fsutil road, and the bin and bin x64 folders the job created were removed after the failure. Two candidate causes stand open: the D volume filesystem may not support hardlinks at all, the drive showing as a Lexar volume where exFAT carries no hardlink form, or the cpLauncher file itself is protected against linking. One, the job prints the D volume filesystem type on its own FILESYSTEM line from Get-Volume with a CIM fallback. Two, the capability probe creates a small temp file inside Content, attempts a hardlink to it under a second temp name by the New-Item road and then the fsutil road, prints PROBE HARDLINK OK or the denial verbatim, removes both temp files, and prints the cleanup, so capability is measured on a file the job itself owns before the game file is touched again. Three, the placement follows the probe: if Content bin x64 Cyberpunk2077.exe already stands it is verified and printed and the job stops; otherwise the bin and bin x64 folders are created if absent, and when the probe hardlink worked the alias is placed as a hardlink to cpLauncher.exe, with a launcher denial at that point printed beside the probe result as the pairing that names the file itself as the protected party; when the probe hardlink failed or the launcher hardlink is denied, the alias is placed as a full copy of cpLauncher.exe instead. Whatever is placed is verified standing with its size equal to 84910032 and printed as PLACED AS HARDLINK or PLACED AS COPY with the full path. Four, on total refusal both denials print verbatim and the cleanup removes only what this job created, the alias file if it made one and any folder it created that stands empty. Five, the verdict in one line: VORTEX FOLDER READY with folder=D XboxGames Cyberpunk 2077 Content and the form named, or VORTEX STILL BLIND with the filesystem type and the denials named. Nothing moves, no game byte changes, the alias is the only addition and stands reversible by its own deletion, and every variable carries the vtx423 prefix under the standing ban on automatic variable names.) ==='
$vtx423Base = 'D:\XboxGames\Cyberpunk 2077'
$vtx423Content = Join-Path $vtx423Base 'Content'
$vtx423Launcher = Join-Path $vtx423Content 'cpLauncher.exe'
$vtx423ExpectedSize = 84910032
$vtx423BinDir = Join-Path $vtx423Content 'bin'
$vtx423X64Dir = Join-Path $vtx423BinDir 'x64'
$vtx423LinkPath = Join-Path $vtx423X64Dir 'Cyberpunk2077.exe'
$vtx423FsType = ''
$vtx423ProbeOk = 0
$vtx423ProbeDeny = ''
$vtx423Placed = 0
$vtx423Form = ''
$vtx423LaunchDeny = ''
$vtx423CopyDeny = ''
$vtx423MadeBin = 0
$vtx423MadeX64 = 0
$vtx423MadeAlias = 0
Write-Output '--- SECTION 1: D VOLUME FILESYSTEM TYPE ---'
try {
  $vtx423Vol = Get-Volume -DriveLetter D -ErrorAction Stop
  $vtx423FsType = $vtx423Vol.FileSystem
} catch {
  Write-Output ("GET-VOLUME DENIAL: " + $_.Exception.Message)
}
if (-not $vtx423FsType) {
  $vtx423Disk = Get-CimInstance Win32_LogicalDisk | Where-Object { $_.DeviceID -eq 'D:' } | Select-Object -First 1
  if ($vtx423Disk) { $vtx423FsType = $vtx423Disk.FileSystem }
}
if (-not $vtx423FsType) { $vtx423FsType = 'UNREAD' }
Write-Output ("FILESYSTEM=" + $vtx423FsType)
Write-Output '--- SECTION 2: HARDLINK CAPABILITY PROBE INSIDE CONTENT ---'
if (-not (Test-Path $vtx423Content)) {
  Write-Output 'CONTENT FOLDER ABSENT - PROBE CANNOT RUN'
  $vtx423ProbeDeny = 'Content folder absent'
} else {
  $vtx423ProbeSrc = Join-Path $vtx423Content 'phi423_probe_src.tmp'
  $vtx423ProbeLink = Join-Path $vtx423Content 'phi423_probe_link.tmp'
  if (Test-Path $vtx423ProbeSrc) { Remove-Item $vtx423ProbeSrc -Force -ErrorAction SilentlyContinue; Write-Output 'STALE PROBE SOURCE REMOVED' }
  if (Test-Path $vtx423ProbeLink) { Remove-Item $vtx423ProbeLink -Force -ErrorAction SilentlyContinue; Write-Output 'STALE PROBE LINK REMOVED' }
  try {
    Set-Content -Path $vtx423ProbeSrc -Value 'phi423 capability probe' -Encoding ASCII -ErrorAction Stop
    Write-Output ("PROBE SOURCE CREATED: " + $vtx423ProbeSrc)
    try {
      New-Item -ItemType HardLink -Path $vtx423ProbeLink -Target $vtx423ProbeSrc -ErrorAction Stop | Out-Null
      $vtx423ProbeOk = 1
    } catch {
      $vtx423ProbeDeny = $_.Exception.Message
      Write-Output ("PROBE NEW-ITEM HARDLINK DENIAL: " + $vtx423ProbeDeny)
      $vtx423FsOut = @(fsutil hardlink create $vtx423ProbeLink $vtx423ProbeSrc 2>&1)
      foreach ($vtx423FsLine in $vtx423FsOut) { Write-Output ("FSUTIL: " + $vtx423FsLine) }
      if (Test-Path $vtx423ProbeLink) { $vtx423ProbeOk = 1 }
    }
  } catch {
    $vtx423ProbeDeny = $_.Exception.Message
    Write-Output ("PROBE SOURCE DENIAL: " + $vtx423ProbeDeny)
  }
  if ($vtx423ProbeOk -eq 1) { Write-Output 'PROBE HARDLINK OK' } else { Write-Output ("PROBE HARDLINK FAILED: " + $vtx423ProbeDeny) }
  if (Test-Path $vtx423ProbeLink) { Remove-Item $vtx423ProbeLink -Force -ErrorAction SilentlyContinue; Write-Output ("PROBE CLEANUP REMOVED: " + $vtx423ProbeLink) }
  if (Test-Path $vtx423ProbeSrc) { Remove-Item $vtx423ProbeSrc -Force -ErrorAction SilentlyContinue; Write-Output ("PROBE CLEANUP REMOVED: " + $vtx423ProbeSrc) }
  Write-Output ("PROBE FILES GONE CHECK: link=" + (Test-Path $vtx423ProbeLink) + " source=" + (Test-Path $vtx423ProbeSrc))
}
Write-Output '--- SECTION 3: THE PLACEMENT ---'
if (-not (Test-Path $vtx423Launcher)) {
  Write-Output 'CPLAUNCHER ABSENT AT THE 421 PATH - NOTHING TO ALIAS'
} elseif (Test-Path $vtx423LinkPath) {
  $vtx423StandItem = Get-Item $vtx423LinkPath -Force
  Write-Output ("ALIAS ALREADY STANDING: " + $vtx423LinkPath + " bytes=" + $vtx423StandItem.Length)
  $vtx423ListLines = @(fsutil hardlink list $vtx423Launcher 2>&1)
  $vtx423StandForm = 'COPY'
  foreach ($vtx423ListLine in $vtx423ListLines) { if ($vtx423ListLine -like '*bin\x64\Cyberpunk2077.exe') { $vtx423StandForm = 'HARDLINK' } }
  Write-Output ("ALIAS STANDING FORM=" + $vtx423StandForm)
  if ($vtx423StandItem.Length -eq $vtx423ExpectedSize) { $vtx423Placed = 1; $vtx423Form = $vtx423StandForm }
} else {
  try {
    if (-not (Test-Path $vtx423BinDir)) { New-Item -ItemType Directory -Path $vtx423BinDir -ErrorAction Stop | Out-Null; $vtx423MadeBin = 1; Write-Output ("CREATED DIR: " + $vtx423BinDir) }
    if (-not (Test-Path $vtx423X64Dir)) { New-Item -ItemType Directory -Path $vtx423X64Dir -ErrorAction Stop | Out-Null; $vtx423MadeX64 = 1; Write-Output ("CREATED DIR: " + $vtx423X64Dir) }
  } catch {
    Write-Output ("DIR CREATE DENIAL: " + $_.Exception.Message)
    $vtx423CopyDeny = $_.Exception.Message
  }
  if ($vtx423ProbeOk -eq 1) {
    try {
      New-Item -ItemType HardLink -Path $vtx423LinkPath -Target $vtx423Launcher -ErrorAction Stop | Out-Null
      $vtx423MadeAlias = 1; $vtx423Form = 'HARDLINK'
    } catch {
      $vtx423LaunchDeny = $_.Exception.Message
      Write-Output ("LAUNCHER NEW-ITEM HARDLINK DENIAL: " + $vtx423LaunchDeny)
      $vtx423FsOut2 = @(fsutil hardlink create $vtx423LinkPath $vtx423Launcher 2>&1)
      foreach ($vtx423FsLine2 in $vtx423FsOut2) { Write-Output ("FSUTIL: " + $vtx423FsLine2) }
      if (Test-Path $vtx423LinkPath) { $vtx423MadeAlias = 1; $vtx423Form = 'HARDLINK' }
    }
    if ($vtx423Form -eq 'HARDLINK') {
      Write-Output 'PAIRING: PROBE HARDLINK OK AND LAUNCHER HARDLINK PLACED'
    } else {
      Write-Output 'PAIRING: PROBE HARDLINK OK BUT THE LAUNCHER HARDLINK WAS DENIED - THE DENIAL BELONGS TO THE CPLAUNCHER FILE ITSELF, SO THE COPY ROAD RUNS'
    }
  } else {
    Write-Output 'PROBE HARDLINK FAILED SO THE COPY ROAD RUNS WITHOUT A LAUNCHER HARDLINK ATTEMPT'
  }
  if ($vtx423Form -ne 'HARDLINK') {
    try {
      Copy-Item $vtx423Launcher $vtx423LinkPath -ErrorAction Stop
      $vtx423MadeAlias = 1; $vtx423Form = 'COPY'
    } catch {
      $vtx423CopyDeny = $_.Exception.Message
      Write-Output ("COPY DENIAL: " + $vtx423CopyDeny)
    }
  }
  if ($vtx423MadeAlias -eq 1) {
    $vtx423AliasItem = Get-Item $vtx423LinkPath -Force -ErrorAction SilentlyContinue
    if ($vtx423AliasItem -and $vtx423AliasItem.Length -eq $vtx423ExpectedSize) {
      $vtx423Placed = 1
      Write-Output ("PLACED AS " + $vtx423Form + ": " + $vtx423LinkPath + " bytes=" + $vtx423AliasItem.Length)
    } else {
      Write-Output 'PLACED FILE SIZE DID NOT VERIFY AGAINST 84910032 - REMOVING THE JOB CREATION'
      Remove-Item $vtx423LinkPath -Force -ErrorAction SilentlyContinue
      $vtx423MadeAlias = 0
      $vtx423CopyDeny = 'placed file size mismatch'
    }
  }
  if ($vtx423Placed -ne 1) {
    if (Test-Path $vtx423LinkPath) { Remove-Item $vtx423LinkPath -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED: " + $vtx423LinkPath) }
    if (($vtx423MadeX64 -eq 1) -and (Test-Path $vtx423X64Dir) -and (@(Get-ChildItem $vtx423X64Dir -Force -ErrorAction SilentlyContinue).Count -eq 0)) { Remove-Item $vtx423X64Dir -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED EMPTY DIR: " + $vtx423X64Dir) }
    if (($vtx423MadeBin -eq 1) -and (Test-Path $vtx423BinDir) -and (@(Get-ChildItem $vtx423BinDir -Force -ErrorAction SilentlyContinue).Count -eq 0)) { Remove-Item $vtx423BinDir -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED EMPTY DIR: " + $vtx423BinDir) }
  }
}
Write-Output '--- SECTION 4: VERDICT ---'
if ($vtx423Placed -eq 1) {
  Write-Output ("PHI VORTEX423 VERDICT: VORTEX FOLDER READY folder=" + $vtx423Content + " form=" + $vtx423Form)
} else {
  Write-Output ("PHI VORTEX423 VERDICT: VORTEX STILL BLIND filesystem=" + $vtx423FsType + " probe_denial=" + $vtx423ProbeDeny + " launcher_hardlink_denial=" + $vtx423LaunchDeny + " copy_denial=" + $vtx423CopyDeny)
}
Write-Output 'JOB 423 DONE'
```
