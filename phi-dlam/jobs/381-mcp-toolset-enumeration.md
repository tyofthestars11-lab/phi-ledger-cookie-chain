<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP TOOLSET ENUMERATION 381 - THE ADD-ON BENCH, NAMED TOOLSET BY TOOLSET (Job 374 stands as the record: the handshake now works - initialize answered HTTP 200, the session initialized, and the manifest carries exactly three tools: list_toolsets, describe_toolset and call_tool, with the raw manifest saved at Saved phi_mcp_manifest374.txt on the PC. The named mesh collision tool from Tyrees original curl does not stand as a top level tool, and job 374 invented no call - but the three manifest tools are themselves the discovery road: toolsets are listed, each toolset describes its own callable tools, and call_tool runs a toolset tool by name. THIS JOB, merged base at D VEIL-OMNI, same session road as 374 - endpoint from the project .mcp.json, the editor launched with the documented start server flag only when the server stands silent and no editor stands open, his editor never closed, only a job-launched editor closed: one, initialize and send the initialized notification. Two, call list_toolsets and print the full result. Three, for every toolset name returned, call describe_toolset, print every callable tool name it carries, and save the full descriptions to Saved phi_mcp_toolsets381.txt with the names printed in this result. Four, if any described tool matches mesh collision - its name or its description carrying collision and mesh together - call it through call_tool with mesh_path /Game/Maps/Grounded_Districts/FloorMesh, and if that asset path draws an error, call it again with /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01, both responses printed whole; if no described tool matches, print that verdict plainly and make no call. From these printed names, and no others, the add-on-first repair work gets authored.) ==='
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
Write-Output '--- SECTION 1: MCP CONFIG ---'
$url = $null
$cfg = "$base\.mcp.json"
if (Test-Path $cfg) {
  $txt = Get-Content $cfg -Raw
  Write-Output ("CONFIG FOUND: " + $cfg)
  $txt | Write-Output
  $m = [regex]::Match($txt, 'https?://[0-9.]+:[0-9]+[A-Za-z0-9/._-]*')
  if ($m.Success) { $url = $m.Value; Write-Output ("ENDPOINT FROM CONFIG: " + $url) }
} else { Write-Output ("CONFIG ABSENT: " + $cfg) }
if (-not $url) { $url = 'http://127.0.0.1:8000/mcp'; Write-Output ("ENDPOINT FROM DOCUMENTED DEFAULT: " + $url) }
Add-Type -AssemblyName System.Net.Http
$client = New-Object System.Net.Http.HttpClient
$client.Timeout = [TimeSpan]::FromSeconds(60)
$script:sid = $null
function Invoke-Mcp([string]$json) {
  $req = New-Object System.Net.Http.HttpRequestMessage([System.Net.Http.HttpMethod]::Post, $url)
  $req.Content = New-Object System.Net.Http.StringContent($json, [System.Text.Encoding]::UTF8, 'application/json')
  [void]$req.Headers.TryAddWithoutValidation('Accept', 'application/json, text/event-stream')
  if ($script:sid) { [void]$req.Headers.TryAddWithoutValidation('Mcp-Session-Id', $script:sid) }
  try {
    $resp = $client.SendAsync($req).Result
    $body = $resp.Content.ReadAsStringAsync().Result
    $vals = $null
    if ($resp.Headers.TryGetValues('Mcp-Session-Id', [ref]$vals)) { $script:sid = ($vals | Select-Object -First 1) }
    return ("HTTP " + [int]$resp.StatusCode + "`n" + $body)
  } catch { return ("MCP HTTP ERROR: " + $_.Exception.Message) }
}
function Read-McpJson([string]$raw) {
  $data = @()
  foreach ($ln in ($raw -split "`n")) { $t = $ln.Trim(); if ($t.StartsWith('data:')) { $data += $t.Substring(5).Trim() } }
  if ($data.Count -gt 0) { return ($data -join "`n") }
  $i = $raw.IndexOf('{')
  if ($i -ge 0) { return $raw.Substring($i) }
  return $raw
}
function Parse-Mcp([string]$raw) {
  $jt = Read-McpJson $raw
  try { return ($jt | ConvertFrom-Json) } catch { return $null }
}
function Get-ResultText($obj) {
  $texts = @()
  if ($obj -and $obj.result -and $obj.result.content) {
    foreach ($c in $obj.result.content) { if ($c.text) { $texts += [string]$c.text } }
  }
  return ($texts -join "`n")
}
function Walk-Toolsets($node, $bag) {
  if ($null -eq $node) { return }
  if ($node -is [pscustomobject]) {
    foreach ($p in $node.PSObject.Properties) {
      if ($p.Name -eq 'toolsets' -and $p.Value) { foreach ($e in $p.Value) { if ($e.name) { [void]$bag.Add([string]$e.name) } } }
      Walk-Toolsets $p.Value $bag
    }
    return
  }
  if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { Walk-Toolsets $i $bag } }
}
function Walk-Tools($node, $bag) {
  if ($null -eq $node) { return }
  if ($node -is [pscustomobject]) {
    foreach ($p in $node.PSObject.Properties) {
      if ($p.Name -eq 'tools' -and $p.Value) {
        foreach ($e in $p.Value) {
          if ($e.name) {
            $d = ''
            if ($e.description) { $d = [string]$e.description }
            [void]$bag.Add(@([string]$e.name, $d))
          }
        }
      }
      Walk-Tools $p.Value $bag
    }
    return
  }
  if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { Walk-Tools $i $bag } }
}
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"phi-dlam","version":"1.0"}},"id":1}'
Write-Output '--- SECTION 2: MCP SESSION ---'
$ep = $null
$resp = Invoke-Mcp $initJson
$alive = $resp -match 'jsonrpc'
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - job deferred, his editor untouched.'; Write-Output 'JOB 381 DEFERRED'; return }
  Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
  $ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
  $tries = 0
  while (-not $alive -and $tries -lt 24) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson; $alive = $resp -match 'jsonrpc'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
  if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; Write-Output '--- LAST PROBE RESPONSE ---'; $resp | Write-Output; if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue }; Write-Output 'JOB 381 STOPPED'; return }
}
Write-Output '--- INITIALIZE RESPONSE (whole) ---'
$resp | Write-Output
if ($script:sid) { Write-Output ("SESSION ID HELD: " + $script:sid) }
$noteResp = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}'
Write-Output ("INITIALIZED NOTIFICATION SENT: " + ($noteResp -split "`n")[0])
$tsPath = "$base\Saved\phi_mcp_toolsets381.txt"
Set-Content $tsPath -Value 'PHI MCP TOOLSETS 381 FULL DESCRIPTIONS' -Encoding UTF8
Write-Output '--- SECTION 3: LIST TOOLSETS ---'
$listCall = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"list_toolsets","arguments":{}},"id":410}'
$listResp = Invoke-Mcp $listCall
Write-Output '--- LIST_TOOLSETS RESPONSE (whole) ---'
$listResp | Write-Output
Add-Content $tsPath '===== LIST_TOOLSETS ====='
Add-Content $tsPath $listResp
$tsBag = New-Object System.Collections.ArrayList
$listObj = Parse-Mcp $listResp
if ($listObj) {
  if ($listObj.result) { Walk-Toolsets $listObj.result $tsBag }
  $inner = Get-ResultText $listObj
  if ($inner) { try { $innerObj = $inner | ConvertFrom-Json; Walk-Toolsets $innerObj $tsBag } catch { } }
}
$toolsets = @()
foreach ($t in $tsBag) { if ($toolsets -notcontains $t) { $toolsets += $t } }
Write-Output ("TOOLSET COUNT: " + $toolsets.Count)
foreach ($t in $toolsets) { Write-Output ("TOOLSET: " + $t) }
Write-Output '--- SECTION 4: DESCRIBE EACH TOOLSET ---'
$matchList = @()
$did = 420
foreach ($ts in $toolsets) {
  $did++
  $descCall = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"describe_toolset","arguments":{"toolset_name":"' + $ts + '"}},"id":' + $did + '}'
  $descResp = Invoke-Mcp $descCall
  Write-Output ("--- DESCRIBE_TOOLSET " + $ts + " (whole) ---")
  $descResp | Write-Output
  Add-Content $tsPath ("===== DESCRIBE " + $ts + " =====")
  Add-Content $tsPath $descResp
  $toolBag = New-Object System.Collections.ArrayList
  $dObj = Parse-Mcp $descResp
  if ($dObj) {
    if ($dObj.result) { Walk-Tools $dObj.result $toolBag }
    $dInner = Get-ResultText $dObj
    if ($dInner) { try { $dInnerObj = $dInner | ConvertFrom-Json; Walk-Tools $dInnerObj $toolBag } catch { } }
  }
  $seenT = @()
  foreach ($pair in $toolBag) {
    $tn = $pair[0]
    $td = $pair[1]
    if ($seenT -contains $tn) { continue }
    $seenT += $tn
    $dshort = $td
    if ($dshort.Length -gt 200) { $dshort = $dshort.Substring(0, 200) }
    Write-Output ("PHI MCP381 TOOL toolset=" + $ts + " name=" + $tn + " desc=" + $dshort)
    if (($tn -match 'collision' -and $tn -match 'mesh') -or ($td -match 'collision' -and $td -match 'mesh')) { $matchList += @(@($ts, $tn)) }
  }
}
Write-Output ("TOOLSET DESCRIPTIONS SAVED: " + $tsPath)
Write-Output '--- SECTION 5: MESH COLLISION CALL THROUGH call_tool ---'
if ($matchList.Count -gt 0) {
  $mts = $matchList[0][0]
  $mtn = $matchList[0][1]
  Write-Output ("MATCHED TOOL: toolset=" + $mts + " name=" + $mtn)
  $call1 = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"' + $mts + '","tool_name":"' + $mtn + '","arguments":{"mesh_path":"/Game/Maps/Grounded_Districts/FloorMesh"}}},"id":430}'
  $r1 = Invoke-Mcp $call1
  Write-Output '--- MESH COLLISION RESPONSE 1 (whole, FloorMesh path) ---'
  $r1 | Write-Output
  $errPat = -join ([char[]](34,101,114,114,111,114,34,124,105,115,69,114,114,111,114))
  if ($r1 -match $errPat) {
    $call2 = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"' + $mts + '","tool_name":"' + $mtn + '","arguments":{"mesh_path":"/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01"}}},"id":431}'
    $r2 = Invoke-Mcp $call2
    Write-Output '--- MESH COLLISION RESPONSE 2 (whole, SM_Mountain_01 path) ---'
    $r2 | Write-Output
  }
} else {
  Write-Output 'NO DESCRIBED TOOL MATCHES MESH COLLISION - no call made. The tool names above are the reroute read.'
}
if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue; Write-Output 'LAUNCHED EDITOR CLOSED BY THIS JOB' }
Write-Output 'JOB 381 DONE'
```
