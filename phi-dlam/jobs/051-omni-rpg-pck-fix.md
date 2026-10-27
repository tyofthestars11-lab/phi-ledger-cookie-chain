# Job 051 — OMNI RPG phi fix: deliver the missing .pck

<!-- PHI-DIRECT -->

Job 049 installed OmniRPG.exe without its data file OmniRPG.pck — the game
alerted "Couldn't load project data... Is the .pck file missing?" This job
re-delivers the complete pair and verifies BOTH files by size.

```powershell
$ErrorActionPreference = 'Stop'
$url = 'https://muse.ai/files/1007559345773069/2550008745426814/mghekkku0x40y0g0525p1teh/omni-rpg-path-of-light-windows.zip'
$zip = 'C:\Users\Admin\Downloads\omni-rpg-path-of-light-windows.zip'
$dest = 'D:\OMNI-RPG'
Invoke-WebRequest -Uri $url -OutFile $zip
Expand-Archive -Path $zip -DestinationPath $dest -Force
$exe = Join-Path $dest 'OmniRPG.exe'
$pck = Join-Path $dest 'OmniRPG.pck'
Write-Output "EXE: exists=$(Test-Path $exe) size=$((Get-Item $exe).Length)"
Write-Output "PCK: exists=$(Test-Path $pck) size=$((Get-Item $pck).Length)"
```
