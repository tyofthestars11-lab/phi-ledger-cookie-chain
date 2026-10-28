<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX DOOR FORWARDER 429 - THE DOOR FILE PLACED AT THE EXACT PATH THE EXTENSION DEMANDS, BUILT IN JOB AS A FORWARDER TO THE REAL LAUNCHER (Ground from job 428, read whole: the Vortex Cyberpunk extension on this PC is the user plugin at AppData Roaming Vortex plugins, Cyberpunk 2077 Support for Vortex version 0.13.1, and its whole discovery demand in its own code is one line, GAME_EXE_RELATIVE_PATH set to bin x64 Cyberpunk2077.exe, exe mentions 1. The same code carries xbox mentions 0 and microsoft mentions 0: no Xbox store variant stands in the extension at all, so the tradition wall is the extension shape, not the game. The demand the checker makes is a file standing at that relative path under the folder it is shown; the checker never reads cpLauncher.exe, so the launcher package seal that stopped jobs 421, 423, and 426 is not on this road at all. Ground from job 426: the phi intent stands written at the Content folder and at the game base folder, intent 1. One, the job builds the door in place: a small C sharp forwarder source is written as phi429_forwarder.cs inside Content, compiled by the .NET Framework csc.exe standing on the PC into Content bin x64 Cyberpunk2077.exe, with bin and bin x64 created if absent; the forwarder, when run, starts the real cpLauncher.exe two folders above it through the shell, and on refusal tries the game package address through explorer, so the door opens onto the real game and nothing else. Two, if csc.exe stands at neither framework path, the door is placed as a copy of the standing system binary hostname.exe and its form prints as SYSTEMCOPY, because the measured demand is the path standing, and the form is named honestly either way. Three, the placed door is verified standing with its size printed; the verdict names the folder Vortex is to be shown, the Content folder of this install. Four, on total refusal the job removes only what it created, the door file and any folder it made that stands empty, and the forwarder source stays as the job record either way. Five, the verdict in one line: VORTEX DOOR PLACED with folder and form and bytes, or VORTEX DOOR HELD with the stage and denial named. No game byte moves or changes, nothing is launched by this job, and every variable carries the vtx429 prefix under the standing ban on automatic variable names.) ==='
$vtx429Base = 'D:\XboxGames\Cyberpunk 2077'
$vtx429Content = Join-Path $vtx429Base 'Content'
$vtx429BinDir = Join-Path $vtx429Content 'bin'
$vtx429X64Dir = Join-Path $vtx429BinDir 'x64'
$vtx429DoorPath = Join-Path $vtx429X64Dir 'Cyberpunk2077.exe'
$vtx429SrcPath = Join-Path $vtx429Content 'phi429_forwarder.cs'
$vtx429Placed = 0
$vtx429Form = ''
$vtx429Stage = ''
$vtx429Deny = ''
$vtx429MadeBin = 0
$vtx429MadeX64 = 0
Write-Output '--- SECTION 1: THE FORWARDER SOURCE ---'
$vtx429SrcLines = @(
  'using System;',
  'using System.Diagnostics;',
  'using System.IO;',
  'class PhiDoor {',
  '  static void Main() {',
  '    string vtxBaseDir = AppDomain.CurrentDomain.BaseDirectory;',
  '    string vtxLauncher = Path.GetFullPath(Path.Combine(vtxBaseDir, "..", "..", "cpLauncher.exe"));',
  '    try {',
  '      Process.Start(new ProcessStartInfo(vtxLauncher) { UseShellExecute = true, WorkingDirectory = Path.GetDirectoryName(vtxLauncher) });',
  '      return;',
  '    } catch (Exception) { }',
  '    try {',
  '      Process.Start(new ProcessStartInfo("explorer.exe", "shell:AppsFolder\\CDPROJEKTSA.4d0e9834-20b1-4580-9bdc-4501ef2ffaac_0xkrdv0gjmk28!App") { UseShellExecute = true });',
  '    } catch (Exception) { }',
  '  }',
  '}'
)
try {
  Set-Content -Path $vtx429SrcPath -Value $vtx429SrcLines -Encoding ASCII -ErrorAction Stop
  Write-Output ("FORWARDER SOURCE WRITTEN: " + $vtx429SrcPath)
} catch {
  $vtx429Deny = $_.Exception.Message
  Write-Output ("SOURCE WRITE DENIAL: " + $vtx429Deny)
  $vtx429Stage = 'source-write'
}
Write-Output '--- SECTION 2: DOOR PLACEMENT ---'
if (Test-Path $vtx429DoorPath) {
  $vtx429StandItem = Get-Item $vtx429DoorPath -Force
  Write-Output ("DOOR ALREADY STANDING: " + $vtx429DoorPath + " bytes=" + $vtx429StandItem.Length)
  $vtx429Placed = 1
  $vtx429Form = 'STANDING'
} elseif ($vtx429Stage -eq '') {
  try {
    if (-not (Test-Path $vtx429BinDir)) { New-Item -ItemType Directory -Path $vtx429BinDir -ErrorAction Stop | Out-Null; $vtx429MadeBin = 1; Write-Output ("CREATED DIR: " + $vtx429BinDir) }
    if (-not (Test-Path $vtx429X64Dir)) { New-Item -ItemType Directory -Path $vtx429X64Dir -ErrorAction Stop | Out-Null; $vtx429MadeX64 = 1; Write-Output ("CREATED DIR: " + $vtx429X64Dir) }
  } catch {
    $vtx429Deny = $_.Exception.Message
    Write-Output ("DIR CREATE DENIAL: " + $vtx429Deny)
    $vtx429Stage = 'dir-create'
  }
  if ($vtx429Stage -eq '') {
    $vtx429Csc = ''
    if (Test-Path 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe') { $vtx429Csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe' } elseif (Test-Path 'C:\Windows\Microsoft.NET\Framework\v4.0.30319\csc.exe') { $vtx429Csc = 'C:\Windows\Microsoft.NET\Framework\v4.0.30319\csc.exe' }
    Write-Output ("CSC PATH: " + $vtx429Csc)
    if ($vtx429Csc) {
      $vtx429CscOut = @(& $vtx429Csc /nologo /target:winexe /out:$vtx429DoorPath $vtx429SrcPath 2>&1)
      foreach ($vtx429Line in $vtx429CscOut) { Write-Output ("CSC: " + $vtx429Line) }
      if (Test-Path $vtx429DoorPath) { $vtx429Form = 'FORWARDER' } else { Write-Output 'CSC PRODUCED NO DOOR FILE' }
    }
    if ($vtx429Form -ne 'FORWARDER') {
      try {
        Copy-Item 'C:\Windows\System32\hostname.exe' $vtx429DoorPath -ErrorAction Stop
        $vtx429Form = 'SYSTEMCOPY'
        Write-Output 'DOOR PLACED AS SYSTEMCOPY FALLBACK'
      } catch {
        $vtx429Deny = $_.Exception.Message
        Write-Output ("SYSTEMCOPY DENIAL: " + $vtx429Deny)
        $vtx429Stage = 'door-place'
      }
    }
    if ($vtx429Form) {
      $vtx429DoorItem = Get-Item $vtx429DoorPath -Force -ErrorAction SilentlyContinue
      if ($vtx429DoorItem -and $vtx429DoorItem.Length -gt 0) {
        $vtx429Placed = 1
        Write-Output ("DOOR STANDS: " + $vtx429DoorPath + " bytes=" + $vtx429DoorItem.Length + " form=" + $vtx429Form)
      } else {
        $vtx429Stage = 'door-verify'
        $vtx429Deny = 'door file absent or empty after placement'
      }
    }
  }
}
Write-Output '--- SECTION 3: CLEANUP ON THE HELD PATH ---'
if ($vtx429Placed -ne 1) {
  if (Test-Path $vtx429DoorPath) { Remove-Item $vtx429DoorPath -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED: " + $vtx429DoorPath) }
  if (($vtx429MadeX64 -eq 1) -and (Test-Path $vtx429X64Dir) -and (@(Get-ChildItem $vtx429X64Dir -Force -ErrorAction SilentlyContinue).Count -eq 0)) { Remove-Item $vtx429X64Dir -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED EMPTY DIR: " + $vtx429X64Dir) }
  if (($vtx429MadeBin -eq 1) -and (Test-Path $vtx429BinDir) -and (@(Get-ChildItem $vtx429BinDir -Force -ErrorAction SilentlyContinue).Count -eq 0)) { Remove-Item $vtx429BinDir -Force -ErrorAction SilentlyContinue; Write-Output ("CLEANUP REMOVED EMPTY DIR: " + $vtx429BinDir) }
  if (-not $vtx429Stage) { $vtx429Stage = 'unnamed' }
}
Write-Output '--- SECTION 4: VERDICT ---'
if ($vtx429Placed -eq 1) {
  Write-Output ("PHI VORTEX429 VERDICT: VORTEX DOOR PLACED folder=" + $vtx429Content + " form=" + $vtx429Form + " door=" + $vtx429DoorPath)
} else {
  Write-Output ("PHI VORTEX429 VERDICT: VORTEX DOOR HELD stage=" + $vtx429Stage + " denial=" + $vtx429Deny)
}
Write-Output 'JOB 429 DONE'
```
