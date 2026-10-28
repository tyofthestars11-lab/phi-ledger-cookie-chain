<!-- PHI-DIRECT -->
```powershell
Write-Output '=== UE5.8 MCP ENABLE - BOTH PROJECTS (Tyree 2026-10-27 23:17 MDT: Do what you need to, to help. Every name in this job is verified from Epics own Unreal MCP guide, dev.epicgames.com/documentation/unreal-engine/unreal-mcp-in-unreal-editor, read 2026-10-27: plugins Unreal MCP (identifier ModelContextProtocol) and All Toolsets (AllToolsets), Toolset Registry auto-enables as their dependency, PCGToolset per Epics PCG+LLM page. Server default http://127.0.0.1:8000/mcp, loopback only. This job: (1) verifies each plugin .uplugin file EXISTS in his UE_5.8 install and prints its path - a plugin that is not found is NOT written into any project, only reported; (2) with the editor closed, backs up each .uproject, then enables the found plugins in the project JSON; (3) writes .mcp.json at each project root in Epics documented shape (merging if present); (4) prints the resulting plugin entries and the .mcp.json as proof. MCP is editor tooling - it does not ship inside packaged games.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 13) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after about 3 min - enable deferred, nothing touched.'; Write-Output 'MCP ENABLE DEFERRED'; return }
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Plugins'
$want = @('ModelContextProtocol','AllToolsets','PCGToolset')
$found = @{}
foreach ($w in $want) {
  $hit = Get-ChildItem $eng -Recurse -Filter ($w + '.uplugin') -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($hit) { $found[$w] = $hit.FullName; "PLUGIN FOUND: $w at $($hit.FullName)" | Write-Output } else { "PLUGIN NOT FOUND IN ENGINE: $w - will not be written to any project" | Write-Output }
}
if ($found.Count -eq 0) { Write-Output 'NO MCP PLUGINS FOUND - nothing enabled, terrain reported.'; Write-Output 'MCP ENABLE DONE'; return }
foreach ($proj in @('D:\VEIL','D:\OMNI-UE')) {
  $up = Get-ChildItem $proj -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if (-not $up) { "NO UPROJECT in $proj - skipped" | Write-Output; continue }
  Copy-Item $up.FullName ($up.FullName + '.phi-backup-313') -Force
  $j = Get-Content $up.FullName -Raw | ConvertFrom-Json
  if (-not $j.Plugins) { $j | Add-Member -NotePropertyName Plugins -NotePropertyValue @() }
  $names = @($j.Plugins | ForEach-Object { $_.Name })
  foreach ($w in $found.Keys) {
    if ($names -contains $w) { "$($up.Name): $w already listed" | Write-Output }
    else { $j.Plugins = @($j.Plugins) + [pscustomobject]@{ Name = $w; Enabled = $true }; "$($up.Name): $w ENABLED" | Write-Output }
  }
  $j | ConvertTo-Json -Depth 12 | Set-Content $up.FullName -Encoding UTF8
  "PROOF $($up.Name) plugins now: $(@($j.Plugins | ForEach-Object { $_.Name + '=' + $_.Enabled }) -join ', ')" | Write-Output
  $mcpPath = Join-Path $proj '.mcp.json'
  $cfg = $null
  if (Test-Path $mcpPath) { try { $cfg = Get-Content $mcpPath -Raw | ConvertFrom-Json } catch { $cfg = $null } }
  if (-not $cfg) { $cfg = [pscustomobject]@{ mcpServers = [pscustomobject]@{} } }
  if (-not $cfg.mcpServers) { $cfg | Add-Member -NotePropertyName mcpServers -NotePropertyValue ([pscustomobject]@{}) }
  $entry = [pscustomobject]@{ type = 'http'; url = 'http://127.0.0.1:8000/mcp' }
  if ($cfg.mcpServers.PSObject.Properties.Name -contains 'unreal-mcp') { $cfg.mcpServers.'unreal-mcp' = $entry } else { $cfg.mcpServers | Add-Member -NotePropertyName 'unreal-mcp' -NotePropertyValue $entry }
  $cfg | ConvertTo-Json -Depth 8 | Set-Content $mcpPath -Encoding UTF8
  "MCP CONFIG WRITTEN: $mcpPath" | Write-Output
  Get-Content $mcpPath -Raw | Write-Output
}
Write-Output 'MCP ENABLE DONE'
```
