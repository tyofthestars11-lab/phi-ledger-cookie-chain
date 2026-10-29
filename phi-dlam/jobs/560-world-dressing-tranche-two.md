<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 560 - WORLD DRESSING TRANCHE TWO (Ground: Tyree reports no progress on the world, so this job copies the missing vault packs into the project and dresses the district from the new pack, same spawn road as the proven dressing, bounded to one pack and twenty four placements, then saves and prints the counts. No config overwrite rides this job. Every variable carries the p560 prefix.) ==='
$p560vault = 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache'
$p560content = 'D:\VEIL-OMNI\Content'
$p560packs = @(Get-ChildItem -Path $p560vault -Directory -ErrorAction SilentlyContinue)
$p560have = @(Get-ChildItem -Path $p560content -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.Name.ToLower() })
$p560missing = @()
foreach ($p560pk in $p560packs) { if ($p560have -notcontains $p560pk.Name.ToLower()) { $p560missing += $p560pk } }
Write-Output ('VAULT PACKS ' + $p560packs.Count + ' MISSING ' + $p560missing.Count)
foreach ($p560m in $p560missing) { Write-Output ('MISSING PACK ' + $p560m.Name) }
$p560pick = $null
foreach ($p560m in $p560missing) { if ($p560m.Name -like '*Modular*') { $p560pick = $p560m; break } }
if (-not $p560pick -and $p560missing.Count -gt 0) { $p560pick = $p560missing[0] }
if ($p560pick) {
  Write-Output ('COPY PACK ' + $p560pick.Name)
  Copy-Item -Path $p560pick.FullName -Destination (Join-Path $p560content $p560pick.Name) -Recurse -Force
  $p560bytes = (Get-ChildItem -Path (Join-Path $p560content $p560pick.Name) -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum).Sum
  Write-Output ('PACK COPIED ' + $p560pick.Name + ' MB ' + [math]::Round($p560bytes / 1MB, 1))
  [IO.File]::WriteAllText('D:\VEIL-OMNI\Saved\dress560_pack.txt', $p560pick.Name)
  $p560b64 = 'aW1wb3J0IHVucmVhbCwgbWF0aCwgaW8KUEFDS0YgPSByJ0Q6XFZFSUwtT01OSVxTYXZlZFxkcmVzczU2MF9wYWNrLnR4dCcKUEFHRSA9IHInRDpcVkVJTC1PTU5JXGRyZXNzNTYwLnR4dCcKR0EgPSAxMzcuNTA3NzY0CmYgPSBpby5vcGVuKFBBR0UsICd3JywgZW5jb2Rpbmc9J3V0Zi04JykKZGVmIHcocyk6CiAgICBmLndyaXRlKHMgKyAnXG4nKTsgZi5mbHVzaCgpCnRyeToKICAgIHBhY2sgPSBvcGVuKFBBQ0tGLCAncicsIGVuY29kaW5nPSd1dGYtOCcpLnJlYWQoKS5zdHJpcCgpCiAgICB3KCdQQUNLICcgKyBwYWNrKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQQUNLIFJFQUQgVEhST1c6ICcgKyBzdHIoZSkpOyBwYWNrID0gJycKdygnRFJFU1M1NjAgUEFHRSBPUEVOJykKdHJ5OgogICAgbGVzID0gdW5yZWFsLmdldF9lZGl0b3Jfc3Vic3lzdGVtKHVucmVhbC5MZXZlbEVkaXRvclN1YnN5c3RlbSkKICAgIGxlcy5sb2FkX2xldmVsKCcvR2FtZS9NYXBzL1ZFSUxEaXN0cmljdCcpCiAgICB3KCdMRVZFTCBMT0FERUQnKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdMRVZFTCBMT0FEIFRIUk9XOiAnICsgc3RyKGUpKQpyZWcgPSB1bnJlYWwuQXNzZXRSZWdpc3RyeUhlbHBlcnMuZ2V0X2Fzc2V0X3JlZ2lzdHJ5KCkKcGF0aHMgPSByZWcuZ2V0X2Fzc2V0c19ieV9wYXRoKCcvR2FtZScsIFRydWUpCnBvb2wgPSBbXQpmb3IgYSBpbiBwYXRoczoKICAgIGlmIHN0cihhLmFzc2V0X2NsYXNzX3BhdGguYXNzZXRfbmFtZSkgIT0gJ1N0YXRpY01lc2gnOgogICAgICAgIGNvbnRpbnVlCiAgICBwa2cgPSBzdHIoYS5wYWNrYWdlX25hbWUpCiAgICBpZiBwYWNrIGFuZCAoJy8nICsgcGFjayArICcvJykgbm90IGluIHBrZzoKICAgICAgICBjb250aW51ZQogICAgcG9vbC5hcHBlbmQoYSkKdygnUE9PTD0lZCcgJSBsZW4ocG9vbCkpCmVhcyA9IHVucmVhbC5nZXRfZWRpdG9yX3N1YnN5c3RlbSh1bnJlYWwuRWRpdG9yQWN0b3JTdWJzeXN0ZW0pCnBsYWNlZCA9IDAKZm9yIGksIGEgaW4gZW51bWVyYXRlKHBvb2xbOjI0XSk6CiAgICB0cnk6CiAgICAgICAgbWVzaCA9IGEuZ2V0X2Fzc2V0KCkKICAgICAgICBpZiBpIDwgNToKICAgICAgICAgICAgdygnRElBRyAlZCBuYW1lPSVzIG1lc2g9JXMnICUgKGksIHN0cihhLmFzc2V0X25hbWUpLCB0eXBlKG1lc2gpLl9fbmFtZV9fIGlmIG1lc2ggZWxzZSAnTm9uZScpKQogICAgICAgIGlmIG5vdCBtZXNoOgogICAgICAgICAgICBjb250aW51ZQogICAgICAgIGFuZyA9IG1hdGgucmFkaWFucyhpICogR0EpCiAgICAgICAgciA9IDIwMDAuMCArIChpICUgNikgKiAxMjUwLjAKICAgICAgICB4ID0gciAqIG1hdGguY29zKGFuZyk7IHkgPSByICogbWF0aC5zaW4oYW5nKQogICAgICAgIHNjYWxlID0gMS4yICsgKGkgJSA0KSAqIDAuNTUKICAgICAgICBiID0gbWVzaC5nZXRfYm91bmRzKCkKICAgICAgICB6ID0gLWIub3JpZ2luLnogKiBzY2FsZQogICAgICAgIGxvYyA9IHVucmVhbC5WZWN0b3IoeCwgeSwgeikKICAgICAgICByb3QgPSB1bnJlYWwuUm90YXRvcigwLjAsIChpICogR0EpICUgMzYwLjAsIDAuMCkKICAgICAgICBhY3QgPSBlYXMuc3Bhd25fYWN0b3JfZnJvbV9jbGFzcyh1bnJlYWwuU3RhdGljTWVzaEFjdG9yLCBsb2MsIHJvdCkKICAgICAgICBpZiBhY3Q6CiAgICAgICAgICAgIGFjdC5zdGF0aWNfbWVzaF9jb21wb25lbnQuc2V0X3N0YXRpY19tZXNoKG1lc2gpCiAgICAgICAgICAgIGFjdC5zZXRfYWN0b3Jfc2NhbGUzZCh1bnJlYWwuVmVjdG9yKHNjYWxlLCBzY2FsZSwgc2NhbGUpKQogICAgICAgICAgICBhY3Quc2V0X2FjdG9yX2xhYmVsKCdQSElfRFJFU1MyXyUwMmQnICUgaSkKICAgICAgICAgICAgcGxhY2VkICs9IDEKICAgICAgICBlbGlmIGkgPCA1OgogICAgICAgICAgICB3KCdESUFHICVkIHNwYXduIHJldHVybmVkIE5vbmUnICUgaSkKICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQTEFDRSAlZCBUSFJPVzogJXMnICUgKGksIHN0cihlKSkpCncoJ1BMQUNFRD0lZCcgJSBwbGFjZWQpCnRyeToKICAgIG9rID0gbGVzLnNhdmVfY3VycmVudF9sZXZlbCgpCiAgICB3KCdTQVZFPSVzJyAlIG9rKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdTQVZFIFRIUk9XOiAnICsgc3RyKGUpKQp3KCdEUkVTUzU2MCBET05FJykKZi5jbG9zZSgpCg=='
  $p560py = 'D:\VEIL-OMNI\Saved\dress560.py'
  [IO.File]::WriteAllBytes($p560py, [Convert]::FromBase64String($p560b64))
  $p560wait = 0
  while ((Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue) -and $p560wait -lt 12) { Start-Sleep -Seconds 10; $p560wait = $p560wait + 1 }
  Write-Output ('LOCK WAIT LOOPS=' + $p560wait)
  $p560cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  $p560proc = Start-Process -FilePath $p560cmd -ArgumentList @('"D:\VEIL-OMNI\VEIL.uproject"', '-run=pythonscript', ('-script="' + $p560py + '"'), '-unattended', '-nopause', '-nosplash') -PassThru
  Write-Output ('DRESS LAUNCHED pid=' + $p560proc.Id)
  $p560poll = 0
  while (-not $p560proc.HasExited -and $p560poll -lt 12) { Start-Sleep -Seconds 10; $p560poll = $p560poll + 1 }
  Write-Output ('CMD POLLS=' + $p560poll + ' exited=' + $p560proc.HasExited)
  $p560page = 'D:\VEIL-OMNI\dress560.txt'
  if (Test-Path $p560page) { Get-Content $p560page | ForEach-Object { Write-Output ('PAGE ' + $_) } } else { Write-Output 'PAGE STILL MISSING' }
} else { Write-Output 'NO NEW PACKS - NO DRESS' }
Write-Output 'PHI P560 VERDICT: WORLD DRESSING TRANCHE TWO ABOVE'
Write-Output 'JOB 560 DONE'
```
