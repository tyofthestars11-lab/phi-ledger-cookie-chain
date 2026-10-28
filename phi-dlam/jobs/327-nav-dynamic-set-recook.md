<!-- PHI-DIRECT -->
```powershell
Write-Output '=== NAV GENERATION SET DYNAMIC IN-MAP + RECOOK + PROOF - BOTH GAMES, ONE JOB (Job 326 read the maps and found the red texts cause exactly: NavMeshBoundsVolumes exist and cover both districts - VEIL half 6200x6200 at 0,0 / OMNI half 18609x18609 - but the RecastNavMesh ACTOR inside each level carries runtime_generation STATIC (0), and the actors own value governs over the DefaultEngine.ini keys job 320 set. Static nav against maps whose geometry moved in the grounding = NAVMESH NEEDS TO BE REBUILT forever. This job sets the RecastNavMesh actors runtime_generation to DYNAMIC in both maps with the file-write capture that worked in 326, saves both levels, prints job 323s material census log lines from disk, recooks both games Win64, and runs the settle proofs. Editor-closed guard on.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - nav fix deferred, nothing touched.'; Write-Output 'NAV FIX DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
foreach ($g in @(@('VEIL','D:\VEIL','VEILDistrict','D:\Builds\VEIL\VEIL_DONE','VEIL.exe'), @('OMNI','D:\OMNI-UE','OMNIWorld','D:\Builds\OMNI\OMNI_DONE','OMNI.exe'))) {
  $name = $g[0]; $proj = $g[1]; $mapname = $g[2]; $arch = $g[3]; $exename = $g[4]
  "##### $name #####" | Write-Output
  $umap = Get-ChildItem "$proj\Content" -Recurse -Filter "$mapname.umap" -File -ErrorAction SilentlyContinue | Select-Object -First 1
  $rel = $umap.FullName.Substring(("$proj\Content").Length).Replace('\','/'); $gpath = '/Game' + $rel.Replace('.umap','')
  Set-Content "$proj\Saved\phi_mappath.txt" -Value $gpath -Encoding ASCII
  $py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHMgKyAnXG4nKQpsZXMgPSB1bnJlYWwuZ2V0X2VkaXRvcl9zdWJzeXN0ZW0odW5yZWFsLkxldmVsRWRpdG9yU3Vic3lzdGVtKQpwYXRoZmlsZSA9IG9wZW4oTUFQUEFUSEZJTEUsICdyJykKbWFwcGF0aCA9IHBhdGhmaWxlLnJlYWQoKS5zdHJpcCgpCnBhdGhmaWxlLmNsb3NlKCkKdygnUEhJIE5BViBGSVggbWFwOiAnICsgbWFwcGF0aCkKdHJ5OgogICAgbGVzLmxvYWRfbGV2ZWwobWFwcGF0aCkKICAgIHcoJ1BISSBOQVYgRklYIGxldmVsIGxvYWRlZCcpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBOQVYgRklYIGxvYWQgZXJyb3I6ICcgKyBzdHIoZSkpCmZvdW5kID0gMApmb3IgYSBpbiB1bnJlYWwuRWRpdG9yTGV2ZWxMaWJyYXJ5LmdldF9hbGxfbGV2ZWxfYWN0b3JzKCk6CiAgICBpZiAnUmVjYXN0TmF2TWVzaCcgaW4gYS5nZXRfY2xhc3MoKS5nZXRfbmFtZSgpOgogICAgICAgIGZvdW5kICs9IDEKICAgICAgICB0cnk6CiAgICAgICAgICAgIHcoJ1BISSBOQVYgRklYIGJlZm9yZTogJyArIHN0cihhLmdldF9lZGl0b3JfcHJvcGVydHkoJ3J1bnRpbWVfZ2VuZXJhdGlvbicpKSkKICAgICAgICAgICAgYS5zZXRfZWRpdG9yX3Byb3BlcnR5KCdydW50aW1lX2dlbmVyYXRpb24nLCB1bnJlYWwuUnVudGltZUdlbmVyYXRpb25UeXBlLkRZTkFNSUMpCiAgICAgICAgICAgIHcoJ1BISSBOQVYgRklYIGFmdGVyOiAnICsgc3RyKGEuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgncnVudGltZV9nZW5lcmF0aW9uJykpKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZXg6CiAgICAgICAgICAgIHcoJ1BISSBOQVYgRklYIHNldCBlcnJvcjogJyArIHN0cihleCkpCncoJ1BISSBOQVYgRklYIHJlY2FzdCBhY3RvcnMgZm91bmQ6ICcgKyBzdHIoZm91bmQpKQp0cnk6CiAgICBsZXMuc2F2ZV9jdXJyZW50X2xldmVsKCkKICAgIHcoJ1BISSBOQVYgRklYIFNBVkVEJykKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlMjoKICAgIHcoJ1BISSBOQVYgRklYIHNhdmUgZXJyb3I6ICcgKyBzdHIoZTIpKQpvdXQuY2xvc2UoKQo='))
  $py = $py.Replace('MAPPATHFILE', "'$proj\Saved\phi_mappath.txt'").Replace('OUTFILE', "'$proj\Saved\phi_nav_fix_out.txt'")
  Set-Content "$proj\Saved\phi_nav_fix.py" -Value $py -Encoding UTF8
  Remove-Item "$proj\Saved\phi_nav_fix_out.txt" -ErrorAction SilentlyContinue
  $uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
  & $cmdexe $uproj -run=pythonscript -script="$proj\Saved\phi_nav_fix.py" -unattended -nopause -nosplash *> "$proj\Saved\navfix327.log"
  if (Test-Path "$proj\Saved\phi_nav_fix_out.txt") { Get-Content "$proj\Saved\phi_nav_fix_out.txt" | Write-Output } else { Write-Output 'NO NAV FIX OUTPUT FILE' }
  '--- material census 323 log lines ---' | Write-Output
  if (Test-Path "$proj\Saved\materialcensus323.log") { Select-String -Path "$proj\Saved\materialcensus323.log" -Pattern 'PHI MATERIAL|LogPython: Error|Traceback' | Select-Object -First 16 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'material census log not found' }
  $cooklog = "$proj\Saved\navfixcook327.log"
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 5 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = "$arch\Windows\$exename"
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CENSUS|PHI MOVE TEST|PHI GM TICKPROOF|NAVMESH|NavMesh' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  } else { Write-Output 'EXE MISSING AFTER NAV FIX COOK' }
}
Write-Output 'NAV FIX JOB DONE'
```
