<!-- PHI-DIRECT -->
# JOB 079 - DESKTOP GAME DOORS (DIRECT)

Tyree's ask: a VEIL icon that goes directly to the game, not the
.uproject opening the editor. For each packaged build that exists,
put its shortcut on the Desktop. Report states; a missing package is
a state line, never a failure.

```powershell
$ws = New-Object -ComObject WScript.Shell
$desk = [Environment]::GetFolderPath('Desktop')
foreach ($c in @(@{Exe='D:\VEIL-Package\Windows\VEIL.exe'; Name='VEIL - The Last Signal'}, @{Exe='D:\OMNI-Package\Windows\OMNI.exe'; Name='OMNI RPG'})) {
  if (Test-Path $c.Exe) {
    $lnk = $ws.CreateShortcut((Join-Path $desk ($c.Name + '.lnk')))
    $lnk.TargetPath = $c.Exe; $lnk.WorkingDirectory = Split-Path $c.Exe; $lnk.Save()
    "SHORTCUT SET: $($c.Name) -> $($c.Exe) ({0:N1} MB)" -f ((Get-Item $c.Exe).Length/1MB)
  } else { "NO PACKAGE YET: $($c.Exe)" }
}
"=== JOB 079 DONE ==="
```
