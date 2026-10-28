<!-- PHI-DIRECT -->
```powershell
Write-Output '=== UE5.8 MCP TERRAIN CENSUS (Tyree 2026-10-27 23:15 MDT handed this seat a full decode of Unreal Engine 5.8 Model Context Protocol support - the official bridge that lets an AI agent drive the editor live - and ordered: reverse engineer this, to help you. Reverse engineering starts at the source, not at a paste: this job censuses HIS engine install for the MCP plugin terrain and reads both projects plugin lists, so the enable step that follows uses machine-carried names only. READ-ONLY: nothing enabled, nothing edited.) ==='
$eng = 'C:\Program Files\Epic Games\UE_5.8'
"engine present: $(Test-Path $eng) at $eng" | Write-Output
if (Test-Path "$eng\Engine\Plugins") {
  Get-ChildItem "$eng\Engine\Plugins" -Recurse -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'ModelContextProtocol|MCP|Toolset' } | ForEach-Object { "PLUGIN DIR: $($_.FullName)" } | Write-Output
  Get-ChildItem "$eng\Engine\Plugins" -Recurse -Filter '*.uplugin' -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'ModelContextProtocol|MCP|Toolset' } | ForEach-Object { "UPLUGIN FILE: $($_.FullName)" } | Write-Output
} else { Write-Output 'ENGINE PLUGINS TREE NOT FOUND at the expected path - terrain differs, report only' }
foreach ($proj in @('D:\VEIL','D:\OMNI-UE')) {
  $up = Get-ChildItem $proj -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($up) { "=== $($up.FullName) ===" | Write-Output; (Get-Content $up.FullName -Raw) | Write-Output } else { "NO UPROJECT FOUND in $proj" | Write-Output }
}
Write-Output 'MCP TERRAIN CENSUS DONE'
```
