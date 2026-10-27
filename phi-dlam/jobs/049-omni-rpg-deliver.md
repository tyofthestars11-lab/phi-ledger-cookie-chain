# Job 049 — Deliver OMNI RPG: PATH OF LIGHT to Tyree's PC

<!-- PHI-DIRECT -->

Download the finished Godot game (HUD-fixed build, verified 2026-10-27) and install it on the PC.

```powershell
$ErrorActionPreference = 'Stop'
$url = 'https://muse.ai/files/1007559345773069/1401659371748567/ru2ctmaqha34tsik3ztqx2qb/omni-rpg-path-of-light-windows.zip'
$zip = 'C:\Users\Admin\Downloads\omni-rpg-path-of-light-windows.zip'
$dest = 'D:\OMNI-RPG'
Invoke-WebRequest -Uri $url -OutFile $zip
if (Test-Path $dest) { Remove-Item $dest -Recurse -Force }
Expand-Archive -Path $zip -DestinationPath $dest -Force
$exe = Join-Path $dest 'OmniRPG.exe'
if (Test-Path $exe) {
  $len = (Get-Item $exe).Length
  Write-Output "INSTALLED: $exe size=$len"
} else {
  Write-Output "MISSING: OmniRPG.exe not found after extract"
}
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut('C:\Users\Admin\Desktop\OMNI RPG - Path of Light.lnk')
$lnk.TargetPath = $exe
$lnk.WorkingDirectory = $dest
$lnk.Save()
Write-Output "SHORTCUT: Desktop 'OMNI RPG - Path of Light' created"
```
