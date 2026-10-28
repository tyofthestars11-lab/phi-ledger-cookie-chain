<!-- PHI-DIRECT -->
```powershell
Write-Output '=== THE FLOOR, GUARANTEED + RECOOK + PROOF - BOTH GAMES, ONE JOB (Tyree 2026-10-28 00:08 MDT: She keeps falling Muse / Fix that / Render the dang world already. The world IS in the packages - the in-game census counts 15 tall actors in VEIL, 115 in OMNI - but she has never stood in it: every launch drops her through the blue before a single frame on the ground. The pawn is proven healthy (capsule 42/96, job 324) and the repair scripts ran (job 324); the slab mesh geometry question (job 328) stays open - so this job stops depending on it. It lays a GUARANTEED floor: an engine-stock Cube StaticMeshActor (whose BodySetup collision is Epics own, not custom) scaled 4000x4000x100 with its top exactly at z=0 under each spawn - VEIL (0,0), OMNI (420,-420) - collision QueryAndPhysics / BlockAll set explicitly, map saved, both games recooked Win64, settle proofs run. If she stands, the district renders around her because she is finally IN it. Editor-closed guard on; file-write capture per 326/327.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - floor job deferred, nothing touched.'; Write-Output 'FLOOR JOB DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
foreach ($g in @(@('VEIL','D:\VEIL','VEILDistrict',0,0,'D:\Builds\VEIL\VEIL_DONE','VEIL.exe'), @('OMNI','D:\OMNI-UE','OMNIWorld',420,-420,'D:\Builds\OMNI\OMNI_DONE','OMNI.exe'))) {
  $name = $g[0]; $proj = $g[1]; $mapname = $g[2]; $sx = $g[3]; $sy = $g[4]; $arch = $g[5]; $exename = $g[6]
  "##### $name #####" | Write-Output
  $umap = Get-ChildItem "$proj\Content" -Recurse -Filter "$mapname.umap" -File -ErrorAction SilentlyContinue | Select-Object -First 1
  $rel = $umap.FullName.Substring(("$proj\Content").Length).Replace('\','/'); $gpath = '/Game' + $rel.Replace('.umap','')
  Set-Content "$proj\Saved\phi_mappath.txt" -Value $gpath -Encoding ASCII
  $py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHMgKyAnXG4nKQpsZXMgPSB1bnJlYWwuZ2V0X2VkaXRvcl9zdWJzeXN0ZW0odW5yZWFsLkxldmVsRWRpdG9yU3Vic3lzdGVtKQpwYXRoZmlsZSA9IG9wZW4oTUFQUEFUSEZJTEUsICdyJykKbWFwcGF0aCA9IHBhdGhmaWxlLnJlYWQoKS5zdHJpcCgpCnBhdGhmaWxlLmNsb3NlKCkKU1BBV05fWCA9IFNQQVdOWFZBTApTUEFXTl9ZID0gU1BBV05ZVkFMCncoJ1BISSBGTE9PUiBtYXA6ICcgKyBtYXBwYXRoICsgJyBzcGF3biBwYWQgY2VudGVyICUuMGYsICUuMGYnICUgKFNQQVdOX1gsIFNQQVdOX1kpKQp0cnk6CiAgICBsZXMubG9hZF9sZXZlbChtYXBwYXRoKQogICAgdygnUEhJIEZMT09SIGxldmVsIGxvYWRlZCcpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBGTE9PUiBsb2FkIGVycm9yOiAnICsgc3RyKGUpKQphY3RvcnMgPSB1bnJlYWwuRWRpdG9yTGV2ZWxMaWJyYXJ5LmdldF9hbGxfbGV2ZWxfYWN0b3JzKCkKZm9yIGEgaW4gYWN0b3JzOgogICAgaWYgc3RyKGEuZ2V0X2FjdG9yX2xhYmVsKCkpID09ICdQSElfRkxPT1JfUEFEJzoKICAgICAgICB1bnJlYWwuRWRpdG9yTGV2ZWxMaWJyYXJ5LmRlc3Ryb3lfYWN0b3IoYSkKICAgICAgICB3KCdQSEkgRkxPT1Igb2xkIHBhZCByZXBsYWNlZCcpCmN1YmUgPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LmxvYWRfYXNzZXQoJy9FbmdpbmUvQmFzaWNTaGFwZXMvQ3ViZScpCmlmIG5vdCBjdWJlOgogICAgdygnUEhJIEZMT09SIEVSUk9SOiBlbmdpbmUgQ3ViZSBub3QgZm91bmQnKQplbHNlOgogICAgcGFkID0gdW5yZWFsLkVkaXRvckxldmVsTGlicmFyeS5zcGF3bl9hY3Rvcl9mcm9tX2NsYXNzKHVucmVhbC5TdGF0aWNNZXNoQWN0b3IsIHVucmVhbC5WZWN0b3IoU1BBV05fWCwgU1BBV05fWSwgLTUwLjApLCB1bnJlYWwuUm90YXRvcigwLjAsIDAuMCwgMC4wKSkKICAgIHBhZC5zZXRfYWN0b3JfbGFiZWwoJ1BISV9GTE9PUl9QQUQnKQogICAgcGFkLnNldF9hY3Rvcl9zY2FsZTNkKHVucmVhbC5WZWN0b3IoNDAuMCwgNDAuMCwgMS4wKSkKICAgIGNvbXAgPSBwYWQuc3RhdGljX21lc2hfY29tcG9uZW50CiAgICBjb21wLnNldF9zdGF0aWNfbWVzaChjdWJlKQogICAgY29tcC5zZXRfY29sbGlzaW9uX2VuYWJsZWQodW5yZWFsLkNvbGxpc2lvbkVuYWJsZWQuUVVFUllfQU5EX1BIWVNJQ1MpCiAgICBjb21wLnNldF9jb2xsaXNpb25fcHJvZmlsZV9uYW1lKCdCbG9ja0FsbCcpCiAgICBjb21wLnNldF9tb2JpbGl0eSh1bnJlYWwuQ29tcG9uZW50TW9iaWxpdHkuU1RBVElDKQogICAgdygnUEhJIEZMT09SIHBhZCBwbGFjZWQ6IGNlbnRlciAlLjBmLCAlLjBmLCB0b3AgYXQgej0wLCA0MDAweDQwMDAsIGVuZ2luZSBDdWJlIGNvbGxpc2lvbicgJSAoU1BBV05fWCwgU1BBV05fWSkpCiAgICB3KCdQSEkgRkxPT1IgcGFkIGNvbGxpc2lvbl9lbmFibGVkOiAnICsgc3RyKGNvbXAuZ2V0X2NvbGxpc2lvbl9lbmFibGVkKCkpICsgJyBwcm9maWxlOiAnICsgc3RyKGNvbXAuZ2V0X2NvbGxpc2lvbl9wcm9maWxlX25hbWUoKSkpCnRyeToKICAgIGxlcy5zYXZlX2N1cnJlbnRfbGV2ZWwoKQogICAgdygnUEhJIEZMT09SIFNBVkVEJykKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlMjoKICAgIHcoJ1BISSBGTE9PUiBzYXZlIGVycm9yOiAnICsgc3RyKGUyKSkKb3V0LmNsb3NlKCkK'))
  $py = $py.Replace('MAPPATHFILE', "'$proj\Saved\phi_mappath.txt'").Replace('OUTFILE', "'$proj\Saved\phi_floor_out.txt'").Replace('SPAWNXVAL', "$sx.0").Replace('SPAWNYVAL', "$sy.0")
  Set-Content "$proj\Saved\phi_floor.py" -Value $py -Encoding UTF8
  Remove-Item "$proj\Saved\phi_floor_out.txt" -ErrorAction SilentlyContinue
  $uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
  & $cmdexe $uproj -run=pythonscript -script="$proj\Saved\phi_floor.py" -unattended -nopause -nosplash *> "$proj\Saved\floor329.log"
  if (Test-Path "$proj\Saved\phi_floor_out.txt") { Get-Content "$proj\Saved\phi_floor_out.txt" | Write-Output } else { Write-Output 'NO FLOOR OUTPUT FILE' }
  $cooklog = "$proj\Saved\floorcook329.log"
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 5 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = "$arch\Windows\$exename"
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CENSUS|PHI MOVE TEST|PHI GM TICKPROOF' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  } else { Write-Output 'EXE MISSING AFTER FLOOR COOK' }
}
Write-Output 'FLOOR JOB DONE'
```
