<!-- PHI-DIRECT -->
```powershell
Write-Output '=== NAV GENERATION + GROUND: BOTH GAMES, ONE JOB (Tyree 2026-10-27 23:37 MDT photographed his screen: NAVMESH NEEDS TO BE REBUILT over the blue - and his word stands: fix the ground so it stops free falling, never ignore what he puts in front of this seat. The grounding fixes 305/306 placed NavMeshBoundsVolumes but never baked navigation - bake was explicitly not claimed - so the falling packages carry no nav data at all. This job closes ground and navmesh as ONE motion in both projects: (1) DefaultEngine.ini gets the navigation system set to BUILD ITS DATA AT RUNTIME in the packaged game - /Script/NavigationSystem.NavigationSystemV1 RuntimeGeneration=Dynamic and bAutoCreateNavigationData=True - backup first, section-aware, idempotent, readback printed; (2) the full Win64 finish cook for both games with everything now in place - grounded maps saved, AssetManager scan rule from 318/319, nav generation set - archive over the old builds; (3) the settle proof on each new package: census must show the grounded counts and the MOVE TEST must begin at ground height and hold, not at negative thousands. Editor-closed guard on.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred, nothing touched.'; Write-Output 'NAV GROUND JOB DEFERRED'; return }
function Set-NavConfig($proj) {
  $ini = "$proj\Config\DefaultEngine.ini"
  if (-not (Test-Path $ini)) { Write-Output "DefaultEngine.ini NOT FOUND at $ini"; return $false }
  Copy-Item $ini "$ini.phi-backup-320" -Force
  $lines = [System.Collections.ArrayList]@(Get-Content $ini)
  $sec = -1; for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i] -match '^\[/Script/NavigationSystem\.NavigationSystemV1\]') { $sec = $i; break } }
  if ($sec -lt 0) { $lines.Add('[/Script/NavigationSystem.NavigationSystemV1]'); $sec = $lines.Count - 1; Write-Output "nav section created in $ini" }
  $end = $sec + 1; while ($end -lt $lines.Count -and $lines[$end] -notmatch '^\[') { $end++ }
  $seg = ''
  for ($j = $sec; $j -lt $end; $j++) { $seg += $lines[$j] + "`n" }
  $insAt = $end
  if ($seg -notmatch 'RuntimeGeneration=') { $lines.Insert($insAt, 'RuntimeGeneration=Dynamic'); $insAt++; Write-Output "RuntimeGeneration=Dynamic set in $ini" } else { Write-Output "RuntimeGeneration already set in $ini" }
  if ($seg -notmatch 'bAutoCreateNavigationData=') { $lines.Insert($insAt, 'bAutoCreateNavigationData=True'); Write-Output "bAutoCreateNavigationData=True set in $ini" } else { Write-Output "bAutoCreateNavigationData already set in $ini" }
  Set-Content $ini -Value $lines -Encoding ASCII
  Select-String -Path $ini -Pattern 'NavigationSystemV1|RuntimeGeneration|bAutoCreateNavigationData' | ForEach-Object { $_.Line.Trim() } | Write-Output
  return $true
}
$okV = Set-NavConfig 'D:\VEIL'
$okO = Set-NavConfig 'D:\OMNI-UE'
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
foreach ($g in @(@('VEIL','D:\VEIL','D:\Builds\VEIL\VEIL_DONE','VEIL.exe', $okV), @('OMNI','D:\OMNI-UE','D:\Builds\OMNI\OMNI_DONE','OMNI.exe', $okO))) {
  $name = $g[0]; $proj = $g[1]; $arch = $g[2]; $exename = $g[3]; $navok = $g[4]
  "##### $name #####" | Write-Output
  if (-not $navok) { Write-Output 'nav config failed for this project - cook skipped'; continue }
  $uproj = Get-ChildItem $proj -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
  if (-not ($uproj -and (Test-Path $uat))) { Write-Output 'TERRAIN MISSING: uproject or RunUAT not found'; continue }
  $cooklog = "$proj\Saved\navcook320.log"
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = "$arch\Windows\$exename"
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe: $($fi.FullName) | modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss')) | $([math]::Round($fi.Length/1MB,1)) MB" | Write-Output } else { "exe MISSING: $exe" | Write-Output }
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "proof log: $($logs.FullName)" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI CENSUS|PHI MOVE TEST|PHI GM TICKPROOF|NAVMESH|NavMesh' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
}
Write-Output 'NAV GROUND JOB DONE'
```
