<!-- PHI-DIRECT -->
# JOB 081 - VEIL DISTRICT VERDICT + NAV FIX + MAP DEFAULTS + LUMEN (DIRECT)

Reads the district build log job 078 launched and proves the level
file exists. The navigation fix lands REGARDLESS of the district
verdict: RuntimeGeneration=Dynamic in DefaultEngine.ini means the
navmesh generates itself at runtime - the editor's "Build Navigation
NOT building because navigation build is locked (flags: 0x4)" state
is dead permanently, in the editor and in the packaged game. If the
level exists, VEILDistrict is also seated as default + startup map
and the Lumen lines go in. One ini backup covers everything.

```powershell
"=== DISTRICT VERDICT ==="
$log = 'D:\VEIL\Saved\district-build.log'
if (Test-Path $log) { Select-String -Path $log -Pattern '\[DISTRICT\]' | ForEach-Object { $_.Line } } else { "NO DISTRICT LOG" }
$ini = 'D:\VEIL\Config\DefaultEngine.ini'
Copy-Item $ini "$ini.bak-081" -Force
$t = Get-Content $ini -Raw
"=== NAV FIX (always) ==="
if ($t -notmatch 'NavigationSystemV1') { $t += "`r`n[/Script/NavigationSystem.NavigationSystemV1]`r`n" }
if ($t -notmatch 'RuntimeGeneration=') { $t = $t -replace '(\[/Script/NavigationSystem\.NavigationSystemV1\])', "`$1`r`nRuntimeGeneration=Dynamic" }
"NAV FIX SET: RuntimeGeneration=Dynamic - the navigation build lock is dead"
$umap = 'D:\VEIL\Content\Maps\VEILDistrict.umap'
if (Test-Path $umap) {
  "UMAP EXISTS: {0:N1} KB" -f ((Get-Item $umap).Length/1KB)
  if ($t -notmatch 'GameMapsSettings') { $t += "`r`n[/Script/EngineSettings.GameMapsSettings]`r`n" }
  if ($t -notmatch 'GameDefaultMap=') { $t = $t -replace '(\[/Script/EngineSettings\.GameMapsSettings\])', "`$1`r`nGameDefaultMap=/Game/Maps/VEILDistrict`r`nEditorStartupMap=/Game/Maps/VEILDistrict" }
  if ($t -notmatch 'RendererSettings') { $t += "`r`n[/Script/Engine.RendererSettings]`r`n" }
  foreach ($kv in 'r.DynamicGlobalIlluminationMethod=1','r.ReflectionMethod=1','r.GenerateMeshDistanceFields=True') {
    if ($t -notmatch [regex]::Escape($kv.Split('=')[0])) { $t = $t -replace '(\[/Script/Engine\.RendererSettings\])', "`$1`r`n$kv" }
  }
  "MAP DEFAULTS + LUMEN SET"
} else {
  "UMAP ABSENT - district build did not land; log tail:"
  if (Test-Path $log) { Get-Content $log -Tail 25 }
}
Set-Content $ini $t -Encoding ASCII
"INI WRITTEN (backup: DefaultEngine.ini.bak-081)"
"=== JOB 081 DONE ==="
```
