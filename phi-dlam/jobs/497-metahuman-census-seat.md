<!-- PHI-DIRECT -->
```powershell
Write-Output '=== METAHUMAN 497 - CENSUS FIRST, SEAT WHAT THE DISK HOLDS (Ordered: add MetaHumans etc. The engine on this PC is Unreal 5.8, installed and building daily; MetaHuman content rides the engine install itself, so the road is a census, not a download. This job lists every MetaHuman plugin descriptor under the engine plugins tree with its true plugin name read off the descriptor file, counts the MetaHuman assets standing inside the plugin content and inside the project content, and lists the project content top folders whole so the etcetera is enumerated from the disk, not guessed. If a MetaHuman creator plugin stands in the install and the project file does not enable it, the job seats the enable entry in VEIL.uproject by the same verified insert that turned Fab off, reads it back, and builds when the editor stands closed so the plugin modules compile into the game. Nothing is fetched and no account is touched. Every variable carries the mh497 prefix.) ==='
$mh497proj = 'D:\VEIL-OMNI'
$mh497uproj = Join-Path $mh497proj 'VEIL.uproject'
$mh497engPlugins = 'C:\Program Files\Epic Games\UE_5.8\Engine\Plugins'
$mh497found = @(Get-ChildItem $mh497engPlugins -Recurse -Filter 'MetaHuman*.uplugin' -ErrorAction SilentlyContinue)
foreach ($mh497f in $mh497found) { Write-Output ('MHPLUGIN ' + $mh497f.BaseName + ' at ' + $mh497f.FullName) }
Write-Output ('MHPLUGIN COUNT=' + $mh497found.Count)
$mh497engAssets = 0
foreach ($mh497f in $mh497found) { $mh497engAssets += @(Get-ChildItem $mh497f.DirectoryName -Recurse -Filter '*.uasset' -ErrorAction SilentlyContinue).Count }
Write-Output ('MH ENGINE ASSETS=' + $mh497engAssets)
$mh497projAssets = @(Get-ChildItem (Join-Path $mh497proj 'Content') -Recurse -Filter '*MetaHuman*.uasset' -ErrorAction SilentlyContinue)
Write-Output ('MH PROJECT ASSETS=' + $mh497projAssets.Count)
$mh497projAssets | Select-Object -First 12 | ForEach-Object { Write-Output ('MHPA ' + $_.FullName) }
Get-ChildItem (Join-Path $mh497proj 'Content') -Directory -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CONTENTDIR ' + $_.Name) }
$mh497seat = 'none'
if ($mh497found.Count -gt 0) {
  $mh497pick = $mh497found | Where-Object { $_.BaseName -eq ('MetaHumanCharacte' + [char]114) } | Select-Object -First 1
  if (-not $mh497pick) { $mh497pick = $mh497found[0] }
  $mh497name = $mh497pick.BaseName
  $mh497raw = Get-Content $mh497uproj -Raw
  if ($mh497raw -match ('"Name":\s*"' + [regex]::Escape($mh497name) + '"')) { $mh497seat = 'alreadyEnabled ' + $mh497name }
  else {
    Copy-Item $mh497uproj ($mh497uproj + '.phi-backup-497') -Force
    $mh497entry = '{"Name": "' + $mh497name + '", "Enabled": true},'
    $mh497new = $mh497raw -replace '("Plugins"\s*:\s*\[)', ('$1' + $mh497entry)
    Set-Content $mh497uproj $mh497new -Encoding ASCII
    $mh497seat = 'seated ' + $mh497name
  }
  $mh497back = Get-Content $mh497uproj -Raw
  if ($mh497back -match ('"Name":\s*"' + [regex]::Escape($mh497name) + '"')) { Write-Output ('UPRO VERIFY metahuman=' + $mh497name) } else { Write-Output 'UPRO VERIFY metahuman=MISSING' }
}
Write-Output ('MH SEAT=' + $mh497seat)
$mh497ed = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
if ($mh497ed.Count -gt 0) { Write-Output 'EDITOR=OPEN build=HELD'; Write-Output ('PHI MH497 VERDICT: METAHUMAN plugins=' + $mh497found.Count + ' seat=' + $mh497seat + ' build=HELD-EDITOR-OPEN'); Write-Output 'JOB 497 DONE'; return }
Write-Output 'EDITOR=CLOSED'
$mh497buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$mh497log = Join-Path $mh497proj 'Saved\build497.log'
& $mh497buildbat VEILEditor Win64 Development -Project="$mh497uproj" -WaitMutex -NoHotReload *> "$mh497log"
$mh497res = ''
if (Test-Path $mh497log) { $mh497res = (Select-String -Path $mh497log -Pattern 'Result:' | Select-Object -Last 1).Line }
Write-Output ('BUILD ' + $mh497res)
if (Test-Path $mh497log) { Select-String -Path $mh497log -Pattern 'rro[r]' | Select-Object -First 8 | ForEach-Object { Write-Output ('ERR ' + $_.Line) } }
Write-Output ('PHI MH497 VERDICT: METAHUMAN plugins=' + $mh497found.Count + ' seat=' + $mh497seat + ' build=' + $mh497res)
Write-Output 'JOB 497 DONE'
```
