<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP COLLISION CALL 397 - THE TOOL NAME READ FROM ITS REGISTRATION FIELD AND THE LAUNCHED EDITOR CLOSED ON EVERY PATH (Job 393 stands as the record: it described the bench clean, printed its request whole, called remove_collisions on SM_Mountain_01 under the qualified name the description printed, and the bench answered Unknown tool for that very name. THIS JOB, merged base at D VEIL-OMNI, same session road as job 393 - endpoint from the project .mcp.json, the editor launched with the documented start server flag only when the server stands silent and no editor stands open, and the editor this job launches closed at the end on every path so the lane leaves no editor behind: one, initialize and send the initialized notification. Two, print the lesson of job 393 as two standing lines - the request it sent and the refusal it got. Three, describe only the StaticMeshTools toolset and print the registration fields of remove_collisions and generate_convex_collisions exactly as the description carries them, every name field and id field in print. Four, call remove_collisions through call_tool under the name exactly as its registration field gives it, the request JSON printed whole before sending, the response printed whole. Five, where that name stands refused, call generate_convex_collisions the same way. Six, the final line names the call the bench accepted, or prints BOTH NAMES REFUSED with both refusals standing beneath it.) ==='
Write-Output '--- THE LESSON OF JOB 393, TWO STANDING LINES ---'
Write-Output 'PHI MCP397 LESSON393 THE REQUEST IT SENT:'
Write-Output '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"editor_toolset.toolsets.static_mesh.StaticMeshTools","tool_name":"editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions","arguments":{"mesh":{"refPath":"/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01"}}}},"id":470}'
Write-Output 'PHI MCP397 LESSON393 THE REFUSAL IT GOT:'
Write-Output 'Unknown tool editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions'
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
$meshPath = '/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01'
$script:tsName397 = 'editor_toolset.toolsets.static_mesh.StaticMeshTools'
$script:callId397 = 471
$script:ep = $null
function Close-Launched397 {
  if ($script:ep) {
    if (-not $script:ep.HasExited) {
      try { Stop-Process -Id $script:ep.Id -Force -ErrorAction Stop; Write-Output 'EDITOR CLOSED BY JOB' }
      catch { Write-Output ('EDITOR CLOSE FAILED FOR PID ' + $script:ep.Id + ': ' + $_.Exception.Message) }
    } else { Write-Output 'EDITOR CLOSED BY JOB - THE LAUNCHED PROCESS HAD ALREADY EXITED' }
  } else { Write-Output 'NO EDITOR LAUNCHED BY THIS JOB - NOTHING TO CLOSE' }
}
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
function Walk-ToolObjs397($node, $bag) {
  if ($null -eq $node) { return }
  if ($node -is [pscustomobject]) {
    foreach ($p in $node.PSObject.Properties) {
      if ($p.Name -eq 'tools' -and $p.Value) {
        foreach ($e in $p.Value) { if ($e.name) { [void]$bag.Add($e) } }
      }
      Walk-ToolObjs397 $p.Value $bag
    }
    return
  }
  if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { Walk-ToolObjs397 $i $bag } }
}
$RegRead397 = {
  param($toolObj, [string]$short)
  Write-Output ("PHI MCP397 REGISTRATION " + $short + " FULL OBJECT AS DESCRIBED:")
  Write-Output ($toolObj | ConvertTo-Json -Compress -Depth 30)
  $fnames = @($toolObj.PSObject.Properties.Name)
  Write-Output ("PHI MCP397 REGISTRATION " + $short + " FIELD NAMES: " + ($fnames -join ', '))
  foreach ($p in $toolObj.PSObject.Properties) {
    if ($p.Name -eq 'id' -or $p.Name -eq 'name') { Write-Output ("PHI MCP397 REGISTRATION " + $short + " FIELD " + $p.Name + " = " + [string]$p.Value) }
  }
  $script:regName397 = $null
  $script:regFrom397 = ''
  if ($toolObj.id) { $script:regName397 = [string]$toolObj.id; $script:regFrom397 = 'id' }
  elseif ($toolObj.name) { $script:regName397 = [string]$toolObj.name; $script:regFrom397 = 'name' }
  Write-Output ("PHI MCP397 REGISTRATION " + $short + " CALL NAME TAKEN FROM FIELD " + $script:regFrom397 + ": " + $script:regName397)
  $script:regSchObj397 = $toolObj.inputSchema
  $script:regSchTxt397 = ''
  if ($toolObj.inputSchema) { $script:regSchTxt397 = ($toolObj.inputSchema | ConvertTo-Json -Compress -Depth 30) }
}
$InvokeCol397 = {
  param([string]$short, [string]$regName, $schObj, [string]$schTxt)
  $script:colRefused = $true
  $script:colRefTxt = ''
  Write-Output ("PHI MCP397 CALLING " + $short + " UNDER REGISTRATION NAME: " + $regName)
  Write-Output ("PHI MCP397 " + $short + " INPUT SCHEMA: " + $schTxt)
  $argsHash = [ordered]@{}
  $reqFields = @()
  if ($schObj -and $schObj.required) { $reqFields = @($schObj.required) }
  if ($reqFields.Count -eq 0 -and $schObj -and $schObj.properties) { $reqFields = @($schObj.properties.PSObject.Properties.Name) }
  foreach ($rq in $reqFields) {
    $pdef = $null
    if ($schObj -and $schObj.properties) { $pdef = $schObj.properties.$rq }
    if ($rq -eq 'mesh') { $argsHash[$rq] = [ordered]@{ refPath = $meshPath } }
    elseif ($pdef -and $pdef.type -eq 'object') { $argsHash[$rq] = [ordered]@{ refPath = $meshPath } }
    elseif ($pdef -and $pdef.type -eq 'boolean') { $argsHash[$rq] = $true }
    elseif ($pdef -and $pdef.type -and $pdef.type.StartsWith('int')) { if ($null -ne $pdef.default) { $argsHash[$rq] = $pdef.default } else { $argsHash[$rq] = 0 } }
    elseif ($pdef -and $pdef.type -and $pdef.type.StartsWith('num')) { if ($null -ne $pdef.default) { $argsHash[$rq] = $pdef.default } else { $argsHash[$rq] = 0 } }
    else { $argsHash[$rq] = $meshPath }
  }
  $argsJson = $argsHash | ConvertTo-Json -Compress -Depth 10
  $callJson = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"' + $script:tsName397 + '","tool_name":"' + $regName + '","arguments":' + $argsJson + '}},"id":' + $script:callId397 + '}'
  $script:callId397++
  Write-Output ("PHI MCP397 REQUEST JSON AS SENT (" + $short + "):")
  Write-Output $callJson
  $r = Invoke-Mcp $callJson
  Write-Output ("--- RESPONSE (" + $short + ", whole) ---")
  $r | Write-Output
  $obj = Parse-Mcp $r
  $txt = Get-ResultText $obj
  $refused = $false
  if ($obj -and $obj.error) { $refused = $true }
  if ($obj -and $obj.result -and $obj.result.isError) { $refused = $true }
  if ($txt -match 'Unknown tool') { $refused = $true }
  $script:colRefused = $refused
  $script:colRefTxt = $txt
  if ($refused) { Write-Output ("PHI MCP397 CALL " + $short + " REFUSED") } else { Write-Output ("PHI MCP397 CALL " + $short + " ACCEPTED") }
}
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"phi-dlam","version":"1.0"}},"id":1}'
Write-Output '--- SECTION 2: MCP SESSION ---'
$resp = Invoke-Mcp $initJson
$alive = $resp -match 'jsonrpc'
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - job deferred, his editor untouched.'; Close-Launched397; Write-Output 'JOB 397 DEFERRED'; return }
  Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
  $script:ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
  $tries = 0
  while (-not $alive -and $tries -lt 12) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson; $alive = $resp -match 'jsonrpc'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
  if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; Write-Output '--- LAST PROBE RESPONSE ---'; $resp | Write-Output; Close-Launched397; Write-Output 'JOB 397 STOPPED'; return }
}
Write-Output '--- INITIALIZE RESPONSE (whole) ---'
$resp | Write-Output
if ($script:sid) { Write-Output ("SESSION ID HELD: " + $script:sid) }
$noteResp = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}'
Write-Output ("INITIALIZED NOTIFICATION SENT: " + ($noteResp -split "`n")[0])
Write-Output '--- SECTION 3: DESCRIBE STATICMESHTOOLS, READ THE REGISTRATION FIELDS ---'
$bag = New-Object System.Collections.ArrayList
$did = 440
for ($att = 1; $att -le 3; $att++) {
  $did++
  $descCall = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"describe_toolset","arguments":{"toolset_name":"' + $script:tsName397 + '"}},"id":' + $did + '}'
  $descResp = Invoke-Mcp $descCall
  $bag = New-Object System.Collections.ArrayList
  $dObj = Parse-Mcp $descResp
  if ($dObj) {
    if ($dObj.result) { Walk-ToolObjs397 $dObj.result $bag }
    $dInner = Get-ResultText $dObj
    if ($dInner) { try { $dInnerObj = $dInner | ConvertFrom-Json; Walk-ToolObjs397 $dInnerObj $bag } catch { } }
  }
  Write-Output ("DESCRIBE ATTEMPT " + $att + " TOOLSET " + $script:tsName397 + " TOOL COUNT: " + $bag.Count)
  if ($bag.Count -gt 0) { break }
  if ($att -lt 3) { Start-Sleep -Seconds 15 }
}
$seenT = @()
$toolRC = $null
$toolGC = $null
foreach ($o in $bag) {
  $tn = [string]$o.name
  if ($seenT -contains $tn) { continue }
  $seenT += $tn
  Write-Output ("PHI MCP397 TOOL name=" + $tn)
  $sn = ($tn -split '\.')[-1]
  if ($sn -eq 'remove_collisions') { $toolRC = $o }
  if ($sn -eq 'generate_convex_collisions') { $toolGC = $o }
}
Write-Output '--- SECTION 4: THE CALLS, REQUESTS PRINTED WHOLE ---'
$accepted = ''
$regRC = ''
$regGC = ''
$refRC = $null
$refGC = $null
if (-not $toolRC -and -not $toolGC) {
  Write-Output 'PHI MCP397 FINAL: COLLISION TOOLS ABSENT FROM THE DESCRIPTION - NO CALL MADE'
} else {
  if ($toolRC) {
    & $RegRead397 $toolRC 'remove_collisions'
    $regRC = $script:regName397
    & $InvokeCol397 'remove_collisions' $regRC $script:regSchObj397 $script:regSchTxt397
    if (-not $script:colRefused) { $accepted = 'remove_collisions' } else { $refRC = $script:colRefTxt }
  }
  if (-not $accepted -and $toolGC) {
    & $RegRead397 $toolGC 'generate_convex_collisions'
    $regGC = $script:regName397
    & $InvokeCol397 'generate_convex_collisions' $regGC $script:regSchObj397 $script:regSchTxt397
    if (-not $script:colRefused) { $accepted = 'generate_convex_collisions' } else { $refGC = $script:colRefTxt }
  }
  Write-Output '--- SECTION 5: FINAL LINE ---'
  if ($accepted -eq 'remove_collisions') {
    Write-Output ("PHI MCP397 FINAL: BENCH ACCEPTED remove_collisions UNDER THE NAME " + $regRC)
  } elseif ($accepted -eq 'generate_convex_collisions') {
    Write-Output ("PHI MCP397 FINAL: BENCH ACCEPTED generate_convex_collisions UNDER THE NAME " + $regGC)
  } elseif ($null -ne $refRC -and $null -ne $refGC) {
    Write-Output 'PHI MCP397 FINAL: BOTH NAMES REFUSED'
    Write-Output ("PHI MCP397 REFUSAL remove_collisions: " + $refRC)
    Write-Output ("PHI MCP397 REFUSAL generate_convex_collisions: " + $refGC)
  } elseif ($null -ne $refRC) {
    Write-Output 'PHI MCP397 FINAL: remove_collisions REFUSED AND generate_convex_collisions ABSENT FROM THE DESCRIPTION'
    Write-Output ("PHI MCP397 REFUSAL remove_collisions: " + $refRC)
  } else {
    Write-Output 'PHI MCP397 FINAL: generate_convex_collisions REFUSED AND remove_collisions ABSENT FROM THE DESCRIPTION'
    Write-Output ("PHI MCP397 REFUSAL generate_convex_collisions: " + $refGC)
  }
}
Close-Launched397
Write-Output 'JOB 397 DONE'
```
