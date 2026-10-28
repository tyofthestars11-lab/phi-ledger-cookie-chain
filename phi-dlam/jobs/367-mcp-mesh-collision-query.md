<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP MESH COLLISION QUERY 367 - CANDIDATE A TESTED AT ITS OWN ADDRESS (Tyree hands the lane the discriminating test itself: a tools/call to unreal_editor_query_mesh_collision with mesh_path /Game/Maps/Grounded_Districts/FloorMesh, id 320, posted to the editor MCP on loopback. The address in the paste stands truncated at 127.0.0 and the lane completes it from the PC own config, never from a guess: job 313 wrote .mcp.json at the project roots with the endpoint http://127.0.0.1:8000/mcp, and the merged base stands at D VEIL-OMNI, the renamed home of the VEIL project, so its config is read there first, with the two parent configs as witnesses. Epic guide terrain, verified 2026-10-27: the server starts in the editor, the launch flags -ModelContextProtocolStartServer and -ModelContextProtocolPort stand documented, and the endpoint is loopback only with no auth, so the call must run on the PC itself, which is what this job is. Standing law rides: the tools/list manifest is captured first and its names printed whole, and the named tool is called when the manifest carries it; if the manifest read itself fails, the exact call from the paste is attempted as the fallback and its response printed whole either way; if the manifest answers and the name stands absent, the job prints that verdict and does not invent a call. THIS JOB, merged base only: one, print every .mcp.json found at D VEIL-OMNI, D VEIL and D OMNI-UE, whole. Two, take the endpoint from the merged base config text by pattern, falling back to the documented 8000 endpoint only when no URL line stands in any config, and print which road supplied it. Three, probe the endpoint with an initialize call; if a server already answers, use it and launch nothing. Four, if no server answers and an editor stands open, print that state and defer - his editor is never closed by this job. Five, if no server answers and no editor stands open, launch the editor on the merged base with the documented start-server flag, poll the endpoint until it answers or the poll budget ends, then run the manifest read and the mesh collision call in the same session. Six, close only the editor this job launched. The answer the job hunts, printed whole: collision present or absent on FloorMesh, simple versus complex, and its profile - the value that settles whether the capsule has anything to find under the PlayerStart, riding the same repair pass as the BeginPlay logs of job 365 and the controller census of job 366.) ==='
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
Write-Output '--- SECTION 1: MCP CONFIG ON THIS PC ---'
$url = $null
foreach ($cfg in @("$base\.mcp.json", 'D:\VEIL\.mcp.json', 'D:\OMNI-UE\.mcp.json')) {
  if (Test-Path $cfg) {
    Write-Output ("CONFIG FOUND: " + $cfg)
    $txt = Get-Content $cfg -Raw
    $txt | Write-Output
    if (-not $url) { $m = [regex]::Match($txt, 'https?://[0-9.]+:[0-9]+[A-Za-z0-9/._-]*'); if ($m.Success) { $url = $m.Value; Write-Output ("ENDPOINT FROM CONFIG: " + $url) } }
  } else { Write-Output ("CONFIG ABSENT: " + $cfg) }
}
if (-not $url) { $url = 'http://127.0.0.1:8000/mcp'; Write-Output ("ENDPOINT FROM DOCUMENTED DEFAULT (no URL line in any config): " + $url) }
Write-Output '--- SECTION 2: MCP SESSION ---'
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"phi-lane","version":"1"}},"id":1}'
$listJson = '{"jsonrpc":"2.0","method":"tools/list","params":{},"id":2}'
$callJson = '{"jsonrpc":"2.0","method":"tools/call","params":{"name":"unreal_editor_query_mesh_collision","arguments":{"mesh_path":"/Game/Maps/Grounded_Districts/FloorMesh"}},"id":320}'
function Invoke-Mcp([string]$json, [string]$sid) {
  $hdrs = @('-H', 'Content-Type: application/json', '-H', 'Accept: application/json, text/event-stream')
  if ($sid) { $hdrs += @('-H', ("Mcp-Session-Id: " + $sid)) }
  $out = & curl.exe -s -i -X POST $url @hdrs -d $json --max-time 15 2>&1
  return ($out | Out-String)
}
function Get-SessionId([string]$resp) { $mm = [regex]::Match($resp, 'Mcp-Session-Id:\s*(\S+)'); if ($mm.Success) { return $mm.Groups[1].Value }; return $null }
$resp = Invoke-Mcp $initJson $null
$alive = $resp -match 'jsonrpc|result|protocolVersion'
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - job deferred, his editor untouched.'; Write-Output 'JOB 367 DEFERRED'; return }
  Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
  $ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
  $tries = 0
  while (-not $alive -and $tries -lt 24) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson $null; $alive = $resp -match 'jsonrpc|result|protocolVersion'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
  if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; Write-Output '--- LAST PROBE RESPONSE ---'; $resp | Write-Output; if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue }; Write-Output 'JOB 367 STOPPED'; return }
}
Write-Output '--- INITIALIZE RESPONSE (whole) ---'
$resp | Write-Output
$sid = Get-SessionId $resp
if ($sid) { Write-Output ("SESSION: " + $sid); $note = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}' $sid }
Write-Output '--- SECTION 3: TOOLS LIST MANIFEST ---'
$listResp = Invoke-Mcp $listJson $sid
$listResp | Write-Output
$inManifest = $listResp -match 'unreal_editor_query_mesh_collision'
Write-Output ("NAMED TOOL IN MANIFEST: " + $inManifest)
Write-Output '--- SECTION 4: MESH COLLISION CALL (Tyrees exact arguments, id 320) ---'
if ($inManifest) {
  $callResp = Invoke-Mcp $callJson $sid
  $callResp | Write-Output
} elseif ($listResp -match 'jsonrpc') {
  Write-Output 'MANIFEST ANSWERED AND THE NAMED TOOL STANDS ABSENT - no call invented. The manifest names above are the reroute read.'
} else {
  Write-Output 'MANIFEST READ FAILED - attempting the exact call from the paste as fallback'
  $callResp = Invoke-Mcp $callJson $sid
  $callResp | Write-Output
}
if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue; Write-Output 'LAUNCHED EDITOR CLOSED BY THIS JOB' }
Write-Output 'JOB 367 DONE'
```
