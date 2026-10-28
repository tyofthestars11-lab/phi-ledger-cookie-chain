<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP MESH COLLISION 389 - THE TARGETED CALL (Job 385 stands as the record: the bench is full - list_toolsets attempt 1 returned 55 toolsets, including PhysicsToolsets.PhysicsAssetToolset and editor_toolset StaticMeshTools, and 131 tool lines printed before the step timeout closed that job with the mesh collision call unreached; the full descriptions stand saved at Saved phi_mcp_toolsets385.txt on the PC. THIS JOB, merged base at D VEIL-OMNI, same session road as jobs 374, 381 and 385 - endpoint from the project .mcp.json, the editor launched with the documented start server flag only when the server stands silent and no editor stands open, his editor never closed, only a job-launched editor closed - stays narrow and fast, with no full bench scan: one, initialize and send the initialized notification. Two, describe only PhysicsToolsets.PhysicsAssetToolset and editor_toolset StaticMeshTools, with a short retry while the registry warms, and print every callable tool name each one carries together with its full input schema. Three, from those two descriptions find the tool whose name or description carries collision together with mesh or body or trace, and where exactly one stands call it through call_tool with the mesh set to /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01 under the argument key the schema itself names, printing the response whole; where the tool requires other arguments, print its full input schema and call it with the required fields filled from the mesh path wherever a field names the mesh. Four, if no tool in the two toolsets matches, print that verdict and, as the last road, print every line carrying collision from the saved 385 descriptions file so the bench in its own words names where the collision tool lives.) ==='
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
$meshPath = '/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01'
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
$client.Timeout = [TimeSpan]::FromSeconds(45)
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
function Walk-Tools389($node, $bag) {
  if ($null -eq $node) { return }
  if ($node -is [pscustomobject]) {
    foreach ($p in $node.PSObject.Properties) {
      if ($p.Name -eq 'tools' -and $p.Value) {
        foreach ($e in $p.Value) {
          if ($e.name) {
            $d = ''
            if ($e.description) { $d = [string]$e.description }
            $schObj = $null
            $schTxt = ''
            if ($e.inputSchema) { $schObj = $e.inputSchema; $schTxt = ($e.inputSchema | ConvertTo-Json -Compress -Depth 30) }
            [void]$bag.Add(@([string]$e.name, $d, $schTxt, $schObj))
          }
        }
      }
      Walk-Tools389 $p.Value $bag
    }
    return
  }
  if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { Walk-Tools389 $i $bag } }
}
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"phi-dlam","version":"1.0"}},"id":1}'
Write-Output '--- SECTION 2: MCP SESSION ---'
$ep = $null
$resp = Invoke-Mcp $initJson
$alive = $resp -match 'jsonrpc'
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - job deferred, his editor untouched.'; Write-Output 'JOB 389 DEFERRED'; return }
  Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
  $ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
  $tries = 0
  while (-not $alive -and $tries -lt 12) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson; $alive = $resp -match 'jsonrpc'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
  if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; Write-Output '--- LAST PROBE RESPONSE ---'; $resp | Write-Output; if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue }; Write-Output 'JOB 389 STOPPED'; return }
}
Write-Output '--- INITIALIZE RESPONSE (whole) ---'
$resp | Write-Output
if ($script:sid) { Write-Output ("SESSION ID HELD: " + $script:sid) }
$noteResp = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}'
Write-Output ("INITIALIZED NOTIFICATION SENT: " + ($noteResp -split "`n")[0])
Write-Output '--- SECTION 3: DESCRIBE THE TWO TOOLSETS ---'
$targets = @('PhysicsToolsets.PhysicsAssetToolset', 'editor_toolset.toolsets.static_mesh.StaticMeshTools')
$matches = @()
$did = 440
foreach ($ts in $targets) {
  $bag = New-Object System.Collections.ArrayList
  for ($att = 1; $att -le 3; $att++) {
    $did++
    $descCall = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"describe_toolset","arguments":{"toolset_name":"' + $ts + '"}},"id":' + $did + '}'
    $descResp = Invoke-Mcp $descCall
    $bag = New-Object System.Collections.ArrayList
    $dObj = Parse-Mcp $descResp
    if ($dObj) {
      if ($dObj.result) { Walk-Tools389 $dObj.result $bag }
      $dInner = Get-ResultText $dObj
      if ($dInner) { try { $dInnerObj = $dInner | ConvertFrom-Json; Walk-Tools389 $dInnerObj $bag } catch { } }
    }
    Write-Output ("DESCRIBE ATTEMPT " + $att + " TOOLSET " + $ts + " TOOL COUNT: " + $bag.Count)
    if ($bag.Count -gt 0) { break }
    if ($att -lt 3) { Start-Sleep -Seconds 15 }
  }
  $seenT = @()
  foreach ($pair in $bag) {
    $tn = $pair[0]
    $td = $pair[1]
    $tsch = $pair[2]
    $tschObj = $pair[3]
    if ($seenT -contains $tn) { continue }
    $seenT += $tn
    Write-Output ("PHI MCP389 TOOL toolset=" + $ts + " name=" + $tn)
    Write-Output ("PHI MCP389 DESC toolset=" + $ts + " name=" + $tn + " desc=" + $td)
    Write-Output ("PHI MCP389 SCHEMA toolset=" + $ts + " name=" + $tn + " schema=" + $tsch)
    if (($tn -match 'collision' -and $tn -match 'mesh|body|trace') -or ($td -match 'collision' -and $td -match 'mesh|body|trace')) { $matches += ,@($ts, $tn, $tsch, $tschObj) }
  }
}
Write-Output ("MATCH COUNT: " + $matches.Count)
Write-Output '--- SECTION 4: THE MESH COLLISION CALL OR THE SAVED BENCH ROAD ---'
if ($matches.Count -gt 0) {
  if ($matches.Count -gt 1) { Write-Output ("MULTIPLE MATCHES STAND: " + $matches.Count + " - calling the first, named below.") ; foreach ($mm in $matches) { Write-Output ("MATCH: toolset=" + $mm[0] + " name=" + $mm[1]) } }
  $mts = $matches[0][0]
  $mtn = $matches[0][1]
  $msch = $matches[0][2]
  $mschObj = $matches[0][3]
  Write-Output ("MATCHED TOOL: toolset=" + $mts + " name=" + $mtn)
  Write-Output ("MATCHED TOOL FULL INPUT SCHEMA: " + $msch)
  $argsHash = [ordered]@{}
  $propNames = @()
  if ($mschObj -and $mschObj.properties) { $propNames = @($mschObj.properties.PSObject.Properties.Name) }
  if ($propNames -contains 'mesh_path') {
    $argsHash['mesh_path'] = $meshPath
    Write-Output 'ARGUMENT KEY FROM SCHEMA: mesh_path'
  } elseif ($mschObj -and $mschObj.required) {
    foreach ($rq in @($mschObj.required)) {
      $pdef = $null
      if ($mschObj.properties) { $pdef = $mschObj.properties.$rq }
      if ($rq -match 'mesh|asset|path|ref') {
        if ($pdef -and $pdef.type -eq 'object') { $argsHash[$rq] = [ordered]@{ refPath = $meshPath } } else { $argsHash[$rq] = $meshPath }
      } elseif ($pdef -and $pdef.type -eq 'boolean') { $argsHash[$rq] = $true }
      elseif ($pdef -and ($pdef.type.StartsWith('int') -or $pdef.type.StartsWith('num'))) { $argsHash[$rq] = 0 }
      else { $argsHash[$rq] = $meshPath }
    }
    Write-Output 'ARGUMENTS BUILT FROM THE SCHEMA REQUIRED FIELDS, MESH PATH IN EVERY FIELD THAT NAMES THE MESH.'
  } else {
    foreach ($pn in $propNames) { if ($pn -match 'mesh|asset|path|ref') { $argsHash[$pn] = $meshPath } }
    if ($argsHash.Count -eq 0) { $argsHash['mesh_path'] = $meshPath }
    Write-Output 'NO REQUIRED FIELDS IN SCHEMA - MESH PATH SET ON EVERY MESH-NAMING PROPERTY.'
  }
  $argsJson = $argsHash | ConvertTo-Json -Compress -Depth 10
  Write-Output ("CALL ARGUMENTS: " + $argsJson)
  $callJson = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"' + $mts + '","tool_name":"' + $mtn + '","arguments":' + $argsJson + '}},"id":460}'
  $r1 = Invoke-Mcp $callJson
  Write-Output '--- MESH COLLISION RESPONSE (whole, SM_Mountain_01) ---'
  $r1 | Write-Output
} else {
  Write-Output 'PHI MCP389 VERDICT: NO TOOL IN THE TWO TOOLSETS MATCHES COLLISION WITH MESH OR BODY OR TRACE.'
  $saved = "$base\Saved\phi_mcp_toolsets385.txt"
  if (Test-Path $saved) {
    $hits = @(Select-String -Path $saved -Pattern 'collision')
    Write-Output ("COLLISION LINES IN SAVED 385 FILE: " + $hits.Count)
    $shown = 0
    foreach ($h in $hits) { if ($shown -ge 20) { break }; $h.Line | Write-Output; $shown++ }
    Write-Output ("COLLISION LINES SHOWN: " + $shown)
  } else { Write-Output ("SAVED 385 FILE ABSENT: " + $saved) }
}
if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue; Write-Output 'LAUNCHED EDITOR CLOSED BY THIS JOB' }
Write-Output 'JOB 389 DONE'
```
