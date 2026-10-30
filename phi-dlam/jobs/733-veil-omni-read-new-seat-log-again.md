<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 733 - READ NEW SEAT LOG AGAIN (Ground: Tyree order do not stop until done job 731 read the 728 build as Result Succeeded and started a fresh detached seat run on the new binary job 732 read the seat731 log early with SEAT719 lines 1 only the metadata line no seat proof yet and the tail still showing the old CDO AnimBlueprint error at 20:29:38 UTC while the editor was still loading. This job reads the same seat731 log again to see whether seat proof prints and whether the CDO error clears on the new binary. It starts nothing edits nothing builds nothing cooks nothing packages nothing no 1.0 proof only in play. Every variable carries the p733 prefix.) ==='
$p733proj = 'D:\VEIL-OMNI'
$p733out = 'D:\VEIL-OMNI\Saved\Logs\VEIL_SEAT731_cmd_out.log'
$p733err = 'D:\VEIL-OMNI\Saved\Logs\VEIL_SEAT731_cmd_err.log'
$p733map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
Write-Output ('SEAT733 OUT PRESENT ' + (Test-Path $p733out))
if (Test-Path $p733out) {
  $p733seat = @(Select-String -Path $p733out -Pattern 'SEAT719')
  Write-Output ('SEAT733 LINES ' + $p733seat.Count)
  foreach ($p733s in $p733seat) { Write-Output ('SEAT733 LINE ' + $p733s.Line) }
  $p733pitch = @(Select-String -Path $p733out -Pattern 'GOLDEN PITCH')
  Write-Output ('PITCH733 LINES ' + $p733pitch.Count)
  foreach ($p733p in $p733pitch) { Write-Output ('PITCH733 LINE ' + $p733p.Line) }
  $p733cdo = @(Select-String -Path $p733out -Pattern 'CDO')
  Write-Output ('CDO733 LINES ' + $p733cdo.Count)
  foreach ($p733c in $p733cdo) { Write-Output ('CDO733 LINE ' + $p733c.Line) }
  Write-Output 'SEAT733 OUT TAIL 40'
  Get-Content $p733out | Select-Object -Last 40
}
Write-Output ('SEAT733 ERR PRESENT ' + (Test-Path $p733err))
if (Test-Path $p733err) { Get-Content $p733err | Select-Object -Last 20 }
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD733 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
if (Test-Path $p733map) { Write-Output ('MAP733 SIZE ' + (Get-Item $p733map).Length) } else { Write-Output 'MAP733 MISSING' }
Write-Output 'UNREAL733 TELLS NOT JOB START LINES'
Write-Output 'PROOF733 ONLY IN PLAY'
Write-Output 'JOB 733 DONE'
```
