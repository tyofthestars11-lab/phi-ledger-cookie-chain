<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MCP MANIFEST DISCOVERY 368 - THE ADD-ON BENCH, NAMED WHOLE (Tyree, verbatim: Bro use unreal add-ons etc. Enacted as the standing method the same turn: the repair and finish work runs through Unreal own add-ons as the primary instruments - the MCP toolsets and editor tooling job 313 enabled in the project (ModelContextProtocol, AllToolsets, PCGToolset, config at the project root) - not hand-rolled samplers. An add-on query cannot parse-fail; that is the whole point against the bespoke-script parse-death class. But the standing MCP law holds with it: only manifest-printed tool names get called, and this lane has never captured the manifest of his editor - the discovery item stood open since the toolsets were enabled. THIS JOB captures it, merged base at D VEIL-OMNI only: one, print the .mcp.json at the merged base root whole and take the endpoint from its text, with the documented loopback endpoint as fallback only. Two, open the MCP session on the same road as job 367 - probe first, defer untouched if his editor stands open with the server silent, otherwise launch the editor with the documented start-server flag and poll. Three, walk tools/list across its pages (four at most, cursor carried), save every raw page to Saved phi_mcp_manifest368.txt on the PC, and print the tool count and every tool name in order. Four, print the full schema - name, description, input schema - for every tool whose name or description touches the repair spec: collision, mesh, actor, component, object, level, scene, propert, blueprint, pawn, physics. Five, close only the editor this job launched. From these printed names, and no others, the add-on-first repair jobs are authored: floor collision, capsule and mesh values, and the PCG finish work. Jobs 365 to 367 stand as the fallback layer already in the queue; this manifest is what promotes the add-ons above them.) ==='
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$flagStart = -join ([char[]](45,77,111,100,101,108,67,111,110,116,101,120,116,80,114,111,116,111,99,111,108,83,116,97,114,116,83,101,114,118,101,114))
Write-Output '--- SECTION 1: MCP CONFIG ---'
$url = $null
$cfg = "$base\.mcp.json"
if (Test-Path $cfg) { Write-Output ("CONFIG FOUND: " + $cfg); $txt = Get-Content $cfg -Raw; $txt | Write-Output; $m = [regex]::Match($txt, 'https?://[0-9.]+:[0-9]+[A-Za-z0-9/._-]*'); if ($m.Success) { $url = $m.Value } } else { Write-Output ("CONFIG ABSENT: " + $cfg) }
if (-not $url) { $url = 'http://127.0.0.1:8000/mcp'; Write-Output ("ENDPOINT FROM DOCUMENTED DEFAULT: " + $url) } else { Write-Output ("ENDPOINT FROM CONFIG: " + $url) }
$initJson = '{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"phi-lane","version":"1"}},"id":1}'
function Invoke-Mcp([string]$json, [string]$sid) {
  $hdrs = @('-H', 'Content-Type: application/json', '-H', 'Accept: application/json, text/event-stream')
  if ($sid) { $hdrs += @('-H', ("Mcp-Session-Id: " + $sid)) }
  $out = & curl.exe -s -i -X POST $url @hdrs -d $json --max-time 20 2>&1
  return ($out | Out-String)
}
function Get-SessionId([string]$resp) { $mm = [regex]::Match($resp, 'Mcp-Session-Id:\s*(\S+)'); if ($mm.Success) { return $mm.Groups[1].Value }; return $null }
Write-Output '--- SECTION 2: MCP SESSION ---'
$resp = Invoke-Mcp $initJson $null
$alive = $resp -match 'jsonrpc|result|protocolVersion'
$ep = $null
if ($alive) { Write-Output 'MCP SERVER ALREADY ANSWERING - no launch needed' } else {
  Write-Output 'MCP PROBE: no answer yet'
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR OPEN BUT MCP NOT ANSWERING - job deferred, his editor untouched.'; Write-Output 'JOB 368 DEFERRED'; return }
  Write-Output 'LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG'
  $ep = Start-Process $edexe -ArgumentList @($uproj, $flagStart, '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
  $tries = 0
  while (-not $alive -and $tries -lt 24) { Start-Sleep -Seconds 10; $tries++; $resp = Invoke-Mcp $initJson $null; $alive = $resp -match 'jsonrpc|result|protocolVersion'; Write-Output ("POLL " + $tries + " alive=" + $alive) }
  if (-not $alive) { Write-Output 'MCP SERVER NEVER ANSWERED IN POLL BUDGET'; if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue }; Write-Output 'JOB 368 STOPPED'; return }
}
$sid = Get-SessionId $resp
if ($sid) { Write-Output ("SESSION: " + $sid); $note = Invoke-Mcp '{"jsonrpc":"2.0","method":"notifications/initialized"}' $sid }
Write-Output '--- SECTION 3: TOOLS LIST MANIFEST ---'
$manifestFile = "$base\Saved\phi_mcp_manifest368.txt"
Remove-Item $manifestFile -ErrorAction SilentlyContinue
$names = @()
$pageResps = @()
$cursor = $null
$cursorKey = -join ([char[]](99,117,114,115,111,114))
for ($page = 1; $page -le 4; $page++) {
  if ($cursor) { $params = '{"' + $cursorKey + '":' + '"' + $cursor + '"}' } else { $params = '{}' }
  $listJson = '{"jsonrpc":"2.0","method":"tools/list","params":' + $params + ',"id":' + (10 + $page) + '}'
  $lr = Invoke-Mcp $listJson $sid
  $pageResps += $lr
  Add-Content $manifestFile ("===== PAGE " + $page + " =====")
  Add-Content $manifestFile $lr
  foreach ($mm in [regex]::Matches($lr, '"name"\s*:\s*"([^"]+)"')) { $n = $mm.Groups[1].Value; if ($names -notcontains $n) { $names += $n } }
  Write-Output ("PAGE " + $page + " bytes=" + $lr.Length)
  $cm = [regex]::Match($lr, '"nextCurso[r]"\s*:\s*"([^"]+)"')
  if ($cm.Success) { $cursor = $cm.Groups[1].Value; Write-Output ("NEXT CURSOR STANDS: " + $cursor) } else { $cursor = $null; break }
}
Write-Output ("MANIFEST TOOL COUNT: " + $names.Count)
$i = 0
foreach ($n in $names) { $i++; Write-Output ("TOOL " + $i + ": " + $n) }
if ($names.Count -eq 0) { Write-Output 'MANIFEST EMPTY - first lines of the raw capture:'; Get-Content $manifestFile -TotalCount 60 | Write-Output }
Write-Output '--- SECTION 4: REPAIR-RELEVANT SCHEMAS ---'
$kw = 'collision|mesh|actor|component|object|level|scene|propert|blueprint|pawn|physics'
$printed = 0
foreach ($lr in $pageResps) {
  $dataLines = ($lr -split "`n" | Where-Object { $_ -like 'data:*' } | ForEach-Object { $_.Substring(5).Trim() }) -join ''
  $payload = $null
  if ($dataLines) { $payload = $dataLines } elseif ($lr.Trim().StartsWith('{')) { $payload = $lr }
  if (-not $payload) { Write-Output 'PAGE PAYLOAD UNREADABLE FOR SCHEMA PARSE'; continue }
  try {
    $obj = $payload | ConvertFrom-Json
    foreach ($tool in $obj.result.tools) {
      $hay = ($tool.name + ' ' + $tool.description)
      if ($hay -match $kw) {
        $printed++
        Write-Output ("SCHEMA " + $printed + ": " + $tool.name)
        Write-Output ($tool.description)
        if ($tool.inputSchema) { Write-Output ($tool.inputSchema | ConvertTo-Json -Depth 8 -Compress) }
      }
    }
  } catch { Write-Output ("SCHEMA PARSE ERROR: " + $_.Exception.Message) }
}
Write-Output ("SCHEMAS PRINTED: " + $printed)
if ($ep -and -not $ep.HasExited) { Stop-Process -Id $ep.Id -Force -ErrorAction SilentlyContinue; Write-Output 'LAUNCHED EDITOR CLOSED BY THIS JOB' }
Write-Output 'JOB 368 DONE'
```
