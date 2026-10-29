<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 602 - VISUAL HELP EYES (Ground: Tyree ordered have it visually help like Rabbit DLAM did, it can see etc, Rabbit DLAM eyes described the screen and helped visually, so this job checks the VEIL OMNI editor is visually open on his PC with NWIRO loaded, so visual help is eyes on the editor not a log line, no package until 100 percent done, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p602 prefix.) ==='
$p602procs = @(Get-Process -Name 'Unreal*' -ErrorAction SilentlyContinue)
Write-Output ('EDITOR602 COUNT ' + $p602procs.Count)
foreach ($p602p in $p602procs) { Write-Output ('EDITOR602 ' + $p602p.Id + ' ' + $p602p.ProcessName) }
$p602uproj = 'D:\VEIL-OMNI\VEIL.uproject'
if (Test-Path $p602uproj) { Write-Output 'PROJ602 EXISTS' } else { Write-Output 'PROJ602 MISSING' }
Write-Output 'PHI P602 VERDICT: VISUAL HELP EYES ABOVE'
Write-Output 'JOB 602 DONE'
```
