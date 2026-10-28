<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP COLLISION NAMING SWEEP 404 - THE TOOLSET ENTRY AND THE TOOL DESCRIPTION PRINTED WHOLE, THEN THE NAME PAIRINGS SWEPT IN ORDER UNTIL THE BENCH ACCEPTS ONE (Job 400 stands as the measured ground: the MCP session initializes clean - HTTP 200, protocolVersion 2025-11-25, initialized HTTP 202 - and describe_toolset for the StaticMeshTools toolset returns 16 tools, with the registration name field for the collision tools reading editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions and the matching form for generate_convex_collisions. Calling call_tool with toolset_name editor_toolset.toolsets.static_mesh.StaticMeshTools and tool_name set to that full registration name returned Unknown tool for BOTH collision tools, and job 393 stands refused on the same pairing. The short tool name alone has never been sent as tool_name on a working session. THIS JOB, merged base at D VEIL-OMNI, same session road as job 400 - endpoint from the project .mcp.json, the editor launched with the documented start server flag only when the server stands silent and no editor stands open, and the editor this job launches closed at the end on every path: one, initialize and send the initialized notification. Two, call list_toolsets and print the complete list entry for the StaticMeshTools toolset exactly as returned, every field of its registration object, whole. Three, describe_toolset for StaticMeshTools and print the complete described object for remove_collisions exactly as returned, every field. Four, sweep call_tool for remove_collisions on the mesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01 through the name pairings in order - A, toolset_name as in job 400 with tool_name the short remove_collisions - B, toolset_name StaticMeshTools with tool_name remove_collisions - C, toolset_name taken verbatim from the list entry field that names the toolset with tool_name remove_collisions - D, toolset_name as in job 400 with tool_name taken verbatim from the described object name field where it differs from the forms already tried - printing the full request JSON and the full response for each and stopping at the first pairing the bench accepts. Five, the final line prints ACCEPTED PAIRING with the pairing letter and the exact two strings that worked, or ALL PAIRINGS REFUSED with the count.) ==='
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
$meshPath = '/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01'
$script:tsLong404 = 'editor_toolset.toolsets.static_mesh.StaticMeshTools'
$script:callId404 = 481
$script:ep = $null
function Close-Launched404 {
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
function Walk-ToolObjs404($node, $bag) {
  if ($null -eq $node) { return }
  if ($node -is [pscustomobject]) {
    foreach ($p in $node.PSObject.Properties) {
      if ($p.Name -eq 'tools' -and $p.Value) {
        foreach ($e in $p.Value) { if ($e.name) { [void]$bag.Add($e) } }
      }
      Walk-ToolObjs404 $p.Value $bag
    }
    return
  }
  if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { Walk-ToolObjs404 $i $bag } }
}
function Find-ToolsetEntry404($root) {
  $queue = New-Object System.Collections.Queue
  $queue.Enqueue($root)
  $seen = 0
  while ($queue.Count -gt 0 -and $seen -lt 4000) {
    $node = $queue.Dequeue(); $seen++
    if ($null -eq $node) { continue }
    if ($node -is [pscustomobject]) {
      $hit = $false
      foreach ($p in $node.PSObject.Properties) {
        if ($p.Value -is [string] -and $p.Value -match 'StaticMeshTools') { $hit = $true }
      }
      if ($hit) { return $node }
      foreach ($p in $node.PSObject.Properties) { $queue.Enqueue($p.Value) }
      continue
    }
    if ($node -is [System.Collections.IEnumerable] -and $node -isnot [string]) { foreach ($i in $node) { $queue.Enqueue($i) } }
  }
  return $null
}
$script:accLetter404 = ''
$script:accTs404 = ''
$script:accTn404 = ''
$script:sent404 = 0
$script:sentPairs404 = @()
$TryPair404 = {
  param([string]$letter, [string]$ts, [string]$tn)
  $pairKey = $ts + '|' + $tn
  if ($script:sentPairs404 -contains $pairKey) {
    Write-Output ("PHI MCP404 PAIRING " + $letter + " SKIPPED - IDENTICAL PAIRING ALREADY SENT IN THIS SWEEP: toolset_name=" + $ts + " tool_name=" + $tn)
    return
  }
  $script:sentPairs404 += $pairKey
  $script:sent404++
  $argsJson = '{"mesh":{"refPath":"' + $meshPath + '"}}'
  $callJson = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"' + $ts + '","tool_name":"' + $tn + '","arguments":' + $argsJson + '}},"id":' + $script:callId404 + '}'
  $script:callId404++
  Write-Output ("PHI MCP404 PAIRING " + $letter + " toolset_name=" + $ts + " tool_name=" + $tn)
  Write-Output ("PHI MCP404 PAIRING " + $letter + " REQUEST JSON AS SENT:")
  Write-Output $callJson
  $r = Invoke-Mcp $callJson
  Write-Output ("--- PAIRING " + $letter + " RESPONSE (whole) ---")
  $r | Write-Output
  $obj = Parse-Mcp $r
  $rtxt = Get-ResultText $obj
  $refused = $false
  if ($rtxt -match 'Unknown tool') { $refused = $true }
  if ($obj -and $obj.error) { $refused = $true }
  if ($refused) {
    Write-Output ("PHI MCP404 PAIRING " + $letter + " REFUSED")
  } else {
    Write-Output ("PHI MCP404 PAIRING " + $letter + " ACCEPTED")
    $script:accLetter404 = $letter
    $script:accTs404 = $ts
    $script:accTn404 = $tn
  }
}
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"phi-dlam","version":"1.0"}},"id":1}'
Write-Output '--- SECTION 2: MCP SESSION ---'
$resp = Invoke-Mcp $initJson
$alive = $resp -match 'jsonrpc'
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) {
    Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - waiting inside the job up to 60 seconds for the standing state to pass'
    $w404 = 0
    while ($w404 -lt 6) {
      Start-Sleep -Seconds 10; $w404++
      $resp = Invoke-Mcp $initJson; $alive = $resp -match 'jsonrpc'
      if ($alive) { Write-Output 'MCP ANSWERED DURING THE IN-JOB WAIT - proceeding on the standing session'; break }
      if (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue)) { Write-Output 'EDITOR CLOSED DURING THE IN-JOB WAIT - proceeding to the launch path'; break }
    }
    if (-not $alive -and (Get-Process UnrealEditor -ErrorAction SilentlyContinue)) { Write-Output 'NAMED HOLD: EDITOR OPEN AND MCP SILENT AFTER THE 60 SECOND IN-JOB WAIT - no second editor launched, his editor untouched'; Close-Launched404; Write-Output 'JOB 404 STOPPED'; return }
  }
  if (-not $alive) {
    Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
    $script:ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
    $tries = 0
    while (-not $alive -and $tries -lt 10) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson; $alive = $resp -match 'jsonrpc'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
    if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; Write-Output '--- LAST PROBE RESPONSE ---'; $resp | Write-Output; Close-Launched404; Write-Output 'JOB 404 STOPPED'; return }
  }
}
Write-Output '--- INITIALIZE RESPONSE (whole) ---'
$resp | Write-Output
if ($script:sid) { Write-Output ("SESSION ID HELD: " + $script:sid) }
$noteResp = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}'
Write-Output ("INITIALIZED NOTIFICATION SENT: " + ($noteResp -split "`n")[0])
Write-Output '--- SECTION 3: LIST_TOOLSETS - THE STATICMESHTOOLS ENTRY WHOLE ---'
$listJson = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"list_toolsets","arguments":{}},"id":450}'
$listResp = Invoke-Mcp $listJson
$listObj = Parse-Mcp $listResp
$entry404 = $null
if ($listObj) {
  if ($listObj.result) { $entry404 = Find-ToolsetEntry404 $listObj.result }
  $listInner = Get-ResultText $listObj
  if (-not $entry404 -and $listInner) {
    try { $listInnerObj = $listInner | ConvertFrom-Json; $entry404 = Find-ToolsetEntry404 $listInnerObj } catch { }
  }
}
$pairTsC404 = $null
$pairFieldC404 = ''
if ($entry404) {
  Write-Output 'PHI MCP404 LIST ENTRY FOR STATICMESHTOOLS, WHOLE AS RETURNED:'
  Write-Output ($entry404 | ConvertTo-Json -Compress -Depth 30)
  Write-Output ("PHI MCP404 LIST ENTRY FIELD NAMES: " + (@($entry404.PSObject.Properties.Name) -join ', '))
  foreach ($cand in @('name', 'id', 'toolset_name', 'full_name', 'path', 'class')) {
    if (-not $pairTsC404) {
      $pv = $entry404.$cand
      if ($pv -is [string] -and $pv.Length -gt 0) { $pairTsC404 = $pv; $pairFieldC404 = $cand }
    }
  }
  if (-not $pairTsC404) {
    foreach ($p in $entry404.PSObject.Properties) {
      if ($p.Value -is [string] -and $p.Value -match 'StaticMesh') { $pairTsC404 = [string]$p.Value; $pairFieldC404 = $p.Name; break }
    }
  }
  if ($pairTsC404) { Write-Output ("PHI MCP404 PAIRING C TOOLSET NAME TAKEN FROM LIST ENTRY FIELD " + $pairFieldC404 + ": " + $pairTsC404) }
  else { Write-Output 'PHI MCP404 PAIRING C TOOLSET NAME: NO NAME FIELD FOUND IN THE LIST ENTRY' }
} else {
  Write-Output 'PHI MCP404 LIST ENTRY FOR STATICMESHTOOLS NOT FOUND IN THE LIST_TOOLSETS RESPONSE'
  Write-Output '--- LIST_TOOLSETS RESPONSE (whole) ---'
  $listResp | Write-Output
}
Write-Output '--- SECTION 4: DESCRIBE STATICMESHTOOLS - THE REMOVE_COLLISIONS OBJECT WHOLE ---'
$bag = New-Object System.Collections.ArrayList
$did = 460
for ($att = 1; $att -le 3; $att++) {
  $did++
  $descCall = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"describe_toolset","arguments":{"toolset_name":"' + $script:tsLong404 + '"}},"id":' + $did + '}'
  $descResp = Invoke-Mcp $descCall
  $bag = New-Object System.Collections.ArrayList
  $dObj = Parse-Mcp $descResp
  if ($dObj) {
    if ($dObj.result) { Walk-ToolObjs404 $dObj.result $bag }
    $dInner = Get-ResultText $dObj
    if ($dInner) { try { $dInnerObj = $dInner | ConvertFrom-Json; Walk-ToolObjs404 $dInnerObj $bag } catch { } }
  }
  Write-Output ("DESCRIBE ATTEMPT " + $att + " TOOLSET " + $script:tsLong404 + " TOOL COUNT: " + $bag.Count)
  if ($bag.Count -gt 0) { break }
  if ($att -lt 3) { Start-Sleep -Seconds 15 }
}
$toolRC404 = $null
$seenT = @()
foreach ($o in $bag) {
  $tnm = [string]$o.name
  if ($seenT -contains $tnm) { continue }
  $seenT += $tnm
  $sn = ($tnm -split '\.')[-1]
  if ($sn -eq 'remove_collisions') { $toolRC404 = $o }
}
$descName404 = $null
if ($toolRC404) {
  Write-Output 'PHI MCP404 DESCRIBED OBJECT FOR REMOVE_COLLISIONS, WHOLE AS RETURNED:'
  Write-Output ($toolRC404 | ConvertTo-Json -Compress -Depth 30)
  Write-Output ("PHI MCP404 DESCRIBED OBJECT FIELD NAMES: " + (@($toolRC404.PSObject.Properties.Name) -join ', '))
  if ($toolRC404.name) { $descName404 = [string]$toolRC404.name; Write-Output ("PHI MCP404 DESCRIBED OBJECT NAME FIELD: " + $descName404) }
  if ($toolRC404.id) { Write-Output ("PHI MCP404 DESCRIBED OBJECT ID FIELD: " + [string]$toolRC404.id) }
} else {
  Write-Output 'PHI MCP404 DESCRIBED OBJECT FOR REMOVE_COLLISIONS NOT FOUND IN THE DESCRIPTION'
}
Write-Output '--- SECTION 5: THE NAMING SWEEP ---'
if (-not $toolRC404) {
  Write-Output 'PHI MCP404 FINAL: REMOVE_COLLISIONS ABSENT FROM THE DESCRIPTION - NO SWEEP MADE'
} else {
  & $TryPair404 'A' $script:tsLong404 'remove_collisions'
  if (-not $script:accLetter404) { & $TryPair404 'B' 'StaticMeshTools' 'remove_collisions' }
  if (-not $script:accLetter404) {
    if ($pairTsC404) { & $TryPair404 'C' $pairTsC404 'remove_collisions' }
    else { Write-Output 'PHI MCP404 PAIRING C SKIPPED - NO TOOLSET NAME FIELD STOOD IN THE LIST ENTRY' }
  }
  if (-not $script:accLetter404) {
    if ($descName404 -and $descName404 -ne 'remove_collisions') { & $TryPair404 'D' $script:tsLong404 $descName404 }
    elseif ($descName404) { Write-Output 'PHI MCP404 PAIRING D SKIPPED - THE DESCRIBED NAME FIELD MATCHES A FORM ALREADY TRIED' }
    else { Write-Output 'PHI MCP404 PAIRING D SKIPPED - NO NAME FIELD STOOD IN THE DESCRIBED OBJECT' }
  }
  Write-Output '--- SECTION 6: FINAL LINE ---'
  if ($script:accLetter404) {
    Write-Output ("PHI MCP404 FINAL: ACCEPTED PAIRING " + $script:accLetter404 + " toolset_name=" + $script:accTs404 + " tool_name=" + $script:accTn404)
  } else {
    Write-Output ("PHI MCP404 FINAL: ALL PAIRINGS REFUSED count=" + $script:sent404)
  }
}
Close-Launched404
Write-Output 'JOB 404 DONE'
```
