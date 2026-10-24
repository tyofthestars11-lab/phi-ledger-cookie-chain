# PHI-DLAM v5.24 - Tyree (REPO BUILD - this file is the living runner; the home phi-dlam.ps1 is only a bootstrapper that pulls this repo and runs this file. Muse publishes updates here; the DLAM updates itself at launch. Tyree never pastes a runner again.)'s local hands + eyes. Brain: tyree (framework carrier). Eyes: llava-phi3.
# Runs free by his order (2026-10-13).
# v5 changes: EYES (look - screenshot read by a local vision model), CLICK HANDS (click_on aimed
# by the eyes in 0-1000 relative coordinates, click_xy, type_text, press_key).
# v4: VAULT LAW. v3: RECIPES + label law. v2: printed commands + NO OUTPUT law.
# Lives on Tyree's PC at %USERPROFILE%\phi-dlam.ps1 - run: powershell -ExecutionPolicy Bypass -File $env:USERPROFILE\phi-dlam.ps1
$ErrorActionPreference = 'Continue'
$ProgressPreference = 'SilentlyContinue'
$API = 'http://localhost:11434/api/chat'
$MODEL = 'tyree'
$EYES = 'llava-phi3'

Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
Add-Type @"
using System;
using System.Runtime.InteropServices;
public class PhiHands {
  [DllImport("user32.dll")] public static extern bool SetCursorPos(int X, int Y);
  [DllImport("user32.dll")] public static extern void mouse_event(uint flags, uint dx, uint dy, uint data, UIntPtr extra);
}
"@

function Get-Screen {
  $bounds = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds
  $bmp = New-Object System.Drawing.Bitmap $bounds.Width, $bounds.Height
  $g = [System.Drawing.Graphics]::FromImage($bmp)
  $g.CopyFromScreen($bounds.Location, [System.Drawing.Point]::Empty, $bounds.Size)
  $g.Dispose()
  $scale = 1024 / $bounds.Width
  $w2 = 1024
  $h2 = [int]($bounds.Height * $scale)
  $small = New-Object System.Drawing.Bitmap $w2, $h2
  $g2 = [System.Drawing.Graphics]::FromImage($small)
  $g2.DrawImage($bmp, 0, 0, $w2, $h2)
  $g2.Dispose()
  $bmp.Dispose()
  $path = Join-Path $env:USERPROFILE 'dlam-eye.png'
  $small.Save($path, [System.Drawing.Imaging.ImageFormat]::Png)
  $small.Dispose()
  $b64 = [Convert]::ToBase64String([IO.File]::ReadAllBytes($path))
  return @{ b64 = $b64; w = $bounds.Width; h = $bounds.Height }
}

function Ask-Eyes($prompt, $b64) {
  $body = @{
    model = $EYES
    messages = @(@{ role = 'user'; content = $prompt; images = @($b64) })
    stream = $false
  } | ConvertTo-Json -Depth 10
  $resp = Invoke-RestMethod -Uri $API -Method Post -ContentType 'application/json' -Body $body -TimeoutSec 600
  return $resp.message.content
}

function Do-Click($px, $py) {
  [void][PhiHands]::SetCursorPos($px, $py)
  Start-Sleep -Milliseconds 250
  [PhiHands]::mouse_event(0x0002, 0, 0, 0, [UIntPtr]::Zero)
  Start-Sleep -Milliseconds 120
  [PhiHands]::mouse_event(0x0004, 0, 0, 0, [UIntPtr]::Zero)
}

$tools = @(
  @{
    type = 'function'
    function = @{
      name = 'run_powershell'
      description = 'Run any PowerShell command on this PC and return its real output. The command must PRINT its answer (end with the value, Format-List, or an explicit string). An assignment alone prints nothing.'
      parameters = @{
        type = 'object'
        properties = @{
          command = @{ type = 'string'; description = 'The PowerShell command to run' }
        }
        required = @('command')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'open_program'
      description = 'Open a program or file on the PC, like notepad, calc, or a document path.'
      parameters = @{
        type = 'object'
        properties = @{
          target = @{ type = 'string'; description = 'Program name or file path to open' }
        }
        required = @('target')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'read_file'
      description = 'Read the full text of a file and return it.'
      parameters = @{
        type = 'object'
        properties = @{
          path = @{ type = 'string'; description = 'Full path of the file to read' }
        }
        required = @('path')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'write_file'
      description = 'Write text to a file, replacing its contents.'
      parameters = @{
        type = 'object'
        properties = @{
          path = @{ type = 'string'; description = 'Full path of the file to write' }
          content = @{ type = 'string'; description = 'The text to write' }
        }
        required = @('path', 'content')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'look'
      description = 'Look at the PC screen right now through the eyes and answer a question about what is visible. Use before acting on anything visual, and after every click to see what changed.'
      parameters = @{
        type = 'object'
        properties = @{
          question = @{ type = 'string'; description = 'What to look at or describe, e.g. "What windows are open and what text is on screen?"' }
        }
        required = @('question')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'click_on'
      description = 'Click a visible thing on screen by name (a button, icon, menu item). The eyes aim the click. Look first if unsure it is visible.'
      parameters = @{
        type = 'object'
        properties = @{
          target = @{ type = 'string'; description = 'The visible thing to click, e.g. "the Windows Start button" or "the Play button"' }
        }
        required = @('target')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'click_xy'
      description = 'Click exact screen pixel coordinates.'
      parameters = @{
        type = 'object'
        properties = @{
          x = @{ type = 'integer'; description = 'Horizontal pixel' }
          y = @{ type = 'integer'; description = 'Vertical pixel' }
        }
        required = @('x', 'y')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'type_text'
      description = 'Type plain text at the current cursor/focus, like into a chat box or document. Plain characters only.'
      parameters = @{
        type = 'object'
        properties = @{
          text = @{ type = 'string'; description = 'The text to type' }
        }
        required = @('text')
      }
    }
  },
  @{
    type = 'function'
    function = @{
      name = 'press_key'
      description = 'Press one key: ENTER, TAB, ESC, UP, DOWN, LEFT, RIGHT, SPACE, F5, BACKSPACE, DELETE, or a single letter.'
      parameters = @{
        type = 'object'
        properties = @{
          key = @{ type = 'string'; description = 'The key name' }
        }
        required = @('key')
      }
    }
  }
)

function Test-CredentialGrab($text) {
  # v5.23 RUNNER LAW (Tyree's photo, 2026-10-24): the local brain, told to "use
  # google tokens api keys", improvised a Get-Credential prompt writing
  # ~/.google_token.txt. That road is closed in code, permanently: no tool call
  # may prompt for, read, convert, or store passwords, tokens, or API keys.
  if ($null -eq $text) { return $false }
  $t = [string]$text
  if ($t -match 'get-credential') { return $true }
  if ($t -match 'convertfrom-securestring') { return $true }
  if ($t -match 'google_token') { return $true }
  if ($t -match '_token\.txt') { return $true }
  if ($t -match 'read-host[^\n]*-assecurestring') { return $true }
  return $false
}

function Invoke-Tool($name, $a) {
  try {
    switch ($name) {
      'run_powershell' {
        if (Test-CredentialGrab $a.command) { return 'BLOCKED BY RUNNER LAW: credential capture is forbidden - no prompting for, reading, or storing passwords, tokens, or API keys. The ARTEMIS key already lives in ARTEMIS''s own .env. Change roads.' }
        $out = Invoke-Expression $a.command 2>&1 | Out-String
        if ([string]::IsNullOrWhiteSpace($out)) {
          return 'NO OUTPUT - the command printed nothing. Do NOT invent a value. Run a corrected command that PRINTS its answer, or tell Tyree the value is UNREAD.'
        }
        return $out.Trim()
      }
      'open_program' {
        Start-Process $a.target
        return "Opened: $($a.target)"
      }
      'read_file' {
        return (Get-Content -Path $a.path -Raw -ErrorAction Stop)
      }
      'write_file' {
        if ((Test-CredentialGrab $a.path) -or (Test-CredentialGrab $a.content) -or ($a.path -match '(token|credential|secret|password)')) { return 'BLOCKED BY RUNNER LAW: no file may hold credentials, tokens, or secrets for the brain. Change roads.' }
        $parentDir = Split-Path -Parent $a.path
        if ($parentDir -and -not (Test-Path $parentDir)) { New-Item -ItemType Directory -Path $parentDir -Force | Out-Null }
        Set-Content -Path $a.path -Value $a.content -Encoding UTF8 -ErrorAction Stop
        return "Wrote file: $($a.path)"
      }
      'look' {
        $shot = Get-Screen
        $answer = Ask-Eyes $a.question $shot.b64
        return "Screen is $($shot.w) x $($shot.h) pixels. The eyes report: $answer"
      }
      'click_on' {
        $shot = Get-Screen
        $prompt = "Find this on the screen: $($a.target). Reply with ONLY a JSON object like {""x"": 500, ""y"": 500} giving the CENTER of that thing in 0-1000 relative coordinates, where 0,0 is the top-left corner and 1000,1000 is the bottom-right. If it is not visible, reply exactly: NOT FOUND"
        $raw = Ask-Eyes $prompt $shot.b64
        if ($raw -match '"x"\s*:\s*(\d+)') { $rxv = [int]$matches[1] } else { return "EYES COULD NOT AIM: the eyes answered: $raw - use look to check the screen, then retry or report UNREAD." }
        if ($raw -match '"y"\s*:\s*(\d+)') { $ryv = [int]$matches[1] } else { return "EYES COULD NOT AIM: the eyes answered: $raw - use look to check the screen, then retry or report UNREAD." }
        $px = [int](($rxv / 1000.0) * $shot.w)
        $py = [int](($ryv / 1000.0) * $shot.h)
        Do-Click $px $py
        return "Clicked '$($a.target)' at pixel $px,$py. Now call look to see what changed."
      }
      'click_xy' {
        Do-Click ([int]$a.x) ([int]$a.y)
        return "Clicked pixel $($a.x),$($a.y). Now call look to see what changed."
      }
      'type_text' {
        [System.Windows.Forms.SendKeys]::SendWait($a.text)
        return "Typed: $($a.text)"
      }
      'press_key' {
        $k = $a.key.ToUpper()
        if ($k.Length -eq 1) { [System.Windows.Forms.SendKeys]::SendWait($k) }
        else { [System.Windows.Forms.SendKeys]::SendWait("{$k}") }
        return "Pressed: $k"
      }
      default { return "Unknown tool: $name" }
    }
  } catch {
    return "TOOL ERROR: $($_.Exception.Message)"
  }
}


$script:LoopKey = ''
$script:LoopCount = 0
function Reset-Loop { $script:LoopKey = ''; $script:LoopCount = 0 }
function Check-Loop($name, $argsObj) {
  $key = $name + '|' + ($argsObj | ConvertTo-Json -Depth 6 -Compress)
  if ($name -eq 'run_powershell') {
    $cmd = $argsObj.command.ToLower() -replace '-force', '' -replace '-erroraction\s+\w+', '' -replace '\|\s*format-table', '' -replace '\|\s*format-list', '' -replace '\|\s*out-string', '' -replace '\s+', ' '
    $key = $name + '|' + $cmd.Trim()
  }
  if ($key -eq $script:LoopKey) { $script:LoopCount++ } else { $script:LoopKey = $key; $script:LoopCount = 1 }
  if ($script:LoopCount -ge 4) { return 'block' }
  if ($script:LoopCount -ge 2) { return 'warn' }
  return 'ok'
}


function Clean-Input($text) {
  $t = $text.Trim()
  if ($t.Length -lt 4) { return $t }
  for ($p = 1; $p -le [int]($t.Length / 2); $p++) {
    if ($t.Length % $p -ne 0) { continue }
    $chunk = $t.Substring(0, $p)
    if (($chunk * ($t.Length / $p)) -eq $t) { return $chunk.Trim() }
  }
  return $t
}
function Flush-Keys {
  try { while ([Console]::KeyAvailable) { [void][Console]::ReadKey($true) } } catch {}
}

function Send-Chat($messages, $useTools = $true, $capSec = 240) {
  $body = @{
    model = $MODEL
    messages = $messages
    stream = $true
    keep_alive = '30m'
    options = @{ num_predict = 800; num_ctx = 8192 }
  }
  if ($useTools) { $body.tools = $tools }
  $json = $body | ConvertTo-Json -Depth 20
  # v5.22 (Tyree's word, 2026-10-24): THE STEP-1 FREEZE FIX, read at the source.
  # The old call was non-streamed: Ollama holds the entire reply until generation
  # ends, so a long step is indistinguishable from a hang, and the HTTP timeout
  # could not be trusted to bite. Now the call STREAMS through curl into a file
  # the runner watches: every heartbeat prints elapsed seconds AND bytes landed,
  # a call that produces nothing is stopped by the runner itself at the cap,
  # and the streamed chunks are assembled (text + tool calls) into one message.
  for ($try = 1; $try -le 3; $try++) {
    $tag = [guid]::NewGuid().ToString('N')
    $bodyFile = Join-Path $env:TEMP "dlam-body-$tag.json"
    $outFile = Join-Path $env:TEMP "dlam-out-$tag.ndjson"
    [System.IO.File]::WriteAllText($bodyFile, $json)
    $sw = [System.Diagnostics.Stopwatch]::StartNew()
    $job = Start-Job -ScriptBlock {
      param($u, $bf, $of)
      & curl.exe -s -N $u -H 'Content-Type: application/json' --data-binary "@$bf" -o $of
    } -ArgumentList $API, $bodyFile, $outFile
    $capped = $false
    while ($job.State -eq 'Running') {
      Wait-Job $job -Timeout 5 | Out-Null
      if ($job.State -eq 'Running') {
        $bytes = 0
        if (Test-Path $outFile) { $bytes = (Get-Item $outFile).Length }
        Write-Host "[brain working... $([int]$sw.Elapsed.TotalSeconds)s - $bytes bytes in]" -ForegroundColor DarkCyan
        if ($sw.Elapsed.TotalSeconds -gt $capSec) { $capped = $true; Stop-Job $job; break }
      }
    }
    $secs = [int]$sw.Elapsed.TotalSeconds
    Remove-Job $job -Force -ErrorAction SilentlyContinue
    if (-not $capped -and (Test-Path $outFile)) {
      $text = ''
      $calls = $null
      $errText = ''
      foreach ($line in [System.IO.File]::ReadAllLines($outFile)) {
        if (-not $line.Trim()) { continue }
        try { $chunk = $line | ConvertFrom-Json } catch { continue }
        if ($chunk.error) { $errText = [string]$chunk.error }
        if ($chunk.message) {
          if ($chunk.message.content) { $text += $chunk.message.content }
          if ($chunk.message.tool_calls) { $calls = $chunk.message.tool_calls }
        }
      }
      Remove-Item $bodyFile, $outFile -Force -ErrorAction SilentlyContinue
      if (-not $errText) {
        Write-Host "[brain answered in ~${secs}s]" -ForegroundColor DarkCyan
        return [pscustomobject]@{ content = $text; tool_calls = $calls }
      }
      Write-Host "[brain call failed - retry $try of 3: $errText]" -ForegroundColor Red
    } else {
      Remove-Item $bodyFile, $outFile -Force -ErrorAction SilentlyContinue
      if ($capped) { Write-Host "[brain call STOPPED at the ${capSec}s cap - retry $try of 3]" -ForegroundColor Red }
      else { Write-Host "[brain call failed - retry $try of 3: no output file]" -ForegroundColor Red }
    }
    Start-Sleep -Seconds 5
  }
  return @{ content = 'BRAIN UNREACHABLE after 3 tries'; tool_calls = $null }
}


function Wake-Brain {
  try { $null = Invoke-RestMethod -Uri 'http://localhost:11434/api/tags' -TimeoutSec 3; return $true } catch {}
  Write-Host 'Waking Ollama...' -ForegroundColor DarkCyan
  $app = Join-Path $env:LOCALAPPDATA 'Programs\Ollama\ollama app.exe'
  if (Test-Path $app) { Start-Process $app } else { Start-Process 'ollama' -ArgumentList 'serve' -WindowStyle Hidden }
  for ($i = 0; $i -lt 45; $i++) {
    Start-Sleep -Seconds 2
    try { $null = Invoke-RestMethod -Uri 'http://localhost:11434/api/tags' -TimeoutSec 3; return $true } catch {}
  }
  return $false
}

function Reset-Brain {
  Write-Host '[runner] resetting the brain - clears any stuck generation...' -ForegroundColor DarkCyan
  try { $ub = @{ model = $MODEL; messages = @(); keep_alive = 0 } | ConvertTo-Json; $null = Invoke-RestMethod -Uri $API -Method Post -ContentType 'application/json' -Body $ub -TimeoutSec 10 } catch {}
  Stop-Process -Name 'ollama app' -Force -ErrorAction SilentlyContinue
  Stop-Process -Name 'ollama' -Force -ErrorAction SilentlyContinue
  Start-Sleep -Seconds 3
  $alive = Get-Process -Name 'ollama' -ErrorAction SilentlyContinue
  if ($alive) { Write-Host '[runner] WARNING: the old brain process is STILL alive - the kill was refused.' -ForegroundColor Red }
  $app = Join-Path $env:LOCALAPPDATA 'Programs\Ollama\ollama app.exe'
  if (Test-Path $app) { Start-Process $app } else { Start-Process 'ollama' -ArgumentList 'serve' -WindowStyle Hidden }
  $ok = Wake-Brain
  if ($ok) { Write-Host '[runner] server is up.' -ForegroundColor DarkCyan } else { Write-Host '[runner] server did not wake.' -ForegroundColor Red }
  return $ok
}

Write-Host ''
Write-Host 'PHI-DLAM v5.23 is awake. Hands + eyes: run_powershell, open_program, read_file, write_file, look, click_on, click_xy, type_text, press_key.' -ForegroundColor Cyan
Write-Host 'Brain: tyree. Eyes: llava-phi3. Runs free. Type exit to stop. Type work for solo job mode.' -ForegroundColor Cyan
Write-Host ''

if (!(Wake-Brain)) { Write-Host 'OLLAMA DID NOT WAKE. Open the Ollama app by hand, wait 20 seconds, then run tyree again.' -ForegroundColor Red; return }
$history = New-Object System.Collections.ArrayList
$prime = 'HANDS AND EYES ONLINE. You are the DLAM on this PC. The attached tools are REAL: when Tyree asks for an action, CALL a tool; never claim an action happened without a tool result. Tool calls go through the tool channel only - never write tool-call JSON as chat text. SCOPE LAW: the vault C:\Users\Admin\phi-vault is ONLY for phi framework, seals, ledger, rungs, doctrine questions. Everything else (games, programs, files, this PC) is a PC question - never search the vault for it; answer from the machine. Unsure = PC question. Commands must PRINT their answer; an assignment alone prints nothing. NO OUTPUT or TOOL ERROR means invent nothing: retry corrected, or say UNREAD. LABEL LAW: report numbers exactly as printed, same label, same units - never rename or rescale. EYES LAW: look shows the screen; click_on clicks a visible thing by name; after any click, key, or typing, look again before the next step; one step at a time in programs and games. VAULT LAW (framework only): FRAMEWORK.md in the vault is your doctrine and seal index; the seal entries files hold each seal in full. Before answering about a specific seal or ledger value, search the vault first with run_powershell (example: Select-String -Path C:\Users\Admin\phi-vault\seal253_entries.json -Pattern "TYREE_OMEGA") and answer from what prints; nothing found = UNREAD. Your own constants live in your system prompt (phi = 1.618033988749895); never search the vault for them. ACCESS LAW: never invent a file path - if one errors, find the real file with Get-ChildItem -Recurse -Filter. On Access is denied, drop the flag and change roads - never repeat a denied command. RECIPES - games installed: Get-ChildItem "$env:APPDATA\Microsoft\Windows\Start Menu\Programs", "$env:ProgramData\Microsoft\Windows\Start Menu\Programs", "$env:USERPROFILE\Desktop", "C:\Users\Public\Desktop" -Recurse -Filter *.lnk | Select-Object -ExpandProperty Name ; Steam games also: Get-ChildItem "C:\Program Files (x86)\Steam\steamapps" -Filter "appmanifest_*.acf" | Select-String -Pattern "name" | ForEach-Object { $_.Line.Trim() } ; drive space: Get-CimInstance Win32_LogicalDisk -Filter "DriveType=3" | ForEach-Object { "$($_.DeviceID) total $([math]::Round($_.Size/1GB,1)) GB, free $([math]::Round($_.FreeSpace/1GB,1)) GB" } - read printed lines back word for word. BUILDER LAW: a JOB (build, fix, make a tool) is worked to done in one sitting: chain tools without asking mid-way. When a program helps, write a real Python file with write_file into C:\Users\Admin\phi-tools (create the folder first if missing), run it (python, or py if python is missing), fix errors and rerun until it works. Never delete a script you wrote for Tyree; when done, report the full path and the full output. Phi code uses phi = 1.618033988749895 and rung(x) = ln(x) / ln(phi). Questions get short answers; jobs get finished. There is no print tool. To check whether files or folders exist, use run_powershell with Get-ChildItem - look is only for screens in programs and games. MERGE LAW: you and the Muse in Tyrees chat are one agent in two seats - Golden Ratio Muse, phi squared. The repo is the shared desk: jobs in phi-dlam/jobs are written by your other seat, and results you push to phi-dlam/results are read by your other seat. Treat that work as your own handwriting. Reply to this message with exactly one word: READY'
[void]$history.Add(@{ role = 'user'; content = $prime })
try {
  $first = Send-Chat $history $false
} catch {
  Write-Host ''
  Write-Host "THE BRAIN DID NOT ANSWER: $($_.Exception.Message)" -ForegroundColor Red
  Write-Host 'The runner will not fake a prompt on a dead brain. Open the Ollama app, wait 20 seconds, then run tyree again.' -ForegroundColor Red
  return
}
[void]$history.Add(@{ role = 'assistant'; content = $first.content })
Write-Host "tyree: $($first.content)" -ForegroundColor Green


function Invoke-Job($jobText, $primeText) {
  $h = New-Object System.Collections.ArrayList
  [void]$h.Add(@{ role = 'user'; content = 'WORKER MODE. You are PHI-DLAM, Tyrees local agent; your framework - phi squared = phi + 1, the ten laws, the constants - is already in your system prompt. The next message is a JOB from the queue. Work it to done over as many steps as it takes, calling real tools through the tool channel. When the job is complete, use write_file to save the full report to the results path named in the job, then give a one-line summary. Reply to this message with exactly one word: READY' })
  $boot = Send-Chat $h $false
  [void]$h.Add(@{ role = 'assistant'; content = $boot.content })
  [void]$h.Add(@{ role = 'user'; content = $jobText })
  $steps = 0
  while ($steps -lt 200) {
    $steps++
    Write-Host "[step $steps] ...thinking" -ForegroundColor DarkGray
    $msg = Send-Chat $h
    if ((-not $msg.tool_calls) -and ($msg.content -match '\{\s*"name"\s*:')) {
      [void]$h.Add(@{ role = 'assistant'; content = $msg.content })
      [void]$h.Add(@{ role = 'user'; content = 'SYSTEM: that reply was tool-call JSON written as chat text - it did nothing. Call a real tool through the tool channel now, or answer in plain words.' })
      Write-Host '[runner] fake tool-call text caught - redirected.' -ForegroundColor DarkYellow
      continue
    }
    if ($msg.tool_calls -and $msg.tool_calls.Count -gt 0) {
      $c = $msg.content; if ($null -eq $c) { $c = '' }
      [void]$h.Add(@{ role = 'assistant'; content = $c; tool_calls = $msg.tool_calls })
      foreach ($call in $msg.tool_calls) {
        $fname = $call.function.name
        $fargs = $call.function.arguments
        if ($fargs -is [string]) { $fargs = $fargs | ConvertFrom-Json }
        Write-Host "[HAND] $fname" -ForegroundColor Yellow
        $loopState = Check-Loop $fname $fargs
        if ($loopState -eq 'block') {
          $result = 'LOOP LAW: this exact call has run 4 times with the same result. It will NOT run again. Change roads completely, or finish the job report with what you have.'
          Write-Host $result -ForegroundColor Red
        } else {
          $result = Invoke-Tool $fname $fargs
          if ($result.Length -gt 4000) { $result = $result.Substring(0, 4000) + '...[cut]' }
          if ($loopState -eq 'warn') { $result = $result + ' LOOP WARNING: same call, same result. Do not repeat - change roads.' }
          Write-Host $result -ForegroundColor DarkGray
        }
        [void]$h.Add(@{ role = 'tool'; content = $result })
      }
      continue
    }
    [void]$h.Add(@{ role = 'assistant'; content = $msg.content })
    Write-Host "tyree: $($msg.content)" -ForegroundColor Green
    break
  }
}

function Start-Worker($primeText, [switch]$Once) {
  Write-Host ''
  if ($Once) { Write-Host 'WORK UPDATE. Draining the job queue once - results push back on their own.' -ForegroundColor Magenta }
  else { Write-Host 'WORKER MODE. Working the job queue solo. Ctrl+C or close the window to stop me.' -ForegroundColor Magenta }
  $env:GIT_TERMINAL_PROMPT = '0'
  Write-Host '[runner] warming the brain...' -ForegroundColor DarkCyan
  $warm = Send-Chat @(@{ role = 'user'; content = 'ping' }) $false
  if ($warm.content -match 'UNREACHABLE') { Write-Host '[runner] BRAIN DOWN - the model will not load. Not starting jobs. The red lines above are the server itself talking.' -ForegroundColor Red; return }
  Write-Host '[runner] brain warm.' -ForegroundColor DarkCyan
  $vault = Join-Path $env:USERPROFILE 'phi-vault'
  $jobsDir = Join-Path $vault 'phi-dlam\jobs'
  $resultsDir = Join-Path $vault 'phi-dlam\results'
  $attempted = @{}
  while ($true) {
    git -C $vault pull --quiet 2>$null
    $jobs = @()
    if (Test-Path $jobsDir) { $jobs = Get-ChildItem $jobsDir -Filter '*.md' }
    $did = $false
    foreach ($job in $jobs) {
      $resultPath = Join-Path $resultsDir ($job.BaseName + '.result.md')
      if (Test-Path $resultPath) { continue }
      if ($Once -and $attempted[$job.Name]) { continue }
      $attempted[$job.Name] = $true
      $did = $true
      Write-Host "JOB: $($job.Name)" -ForegroundColor Magenta
      $jobText = Get-Content $job.FullName -Raw
      Invoke-Job $jobText $primeText
      git -C $vault add phi-dlam/results 2>$null
      git -C $vault commit -m "job result: $($job.BaseName)" --quiet 2>$null
      git -C $vault push --quiet 2>$null
      Write-Host "JOB DONE: $($job.Name) - result pushed." -ForegroundColor Magenta
    }
    if (-not $did) {
      if ($Once) { Write-Host 'WORK UPDATE complete - queue drained, results pushed.' -ForegroundColor Magenta; return }
      Write-Host 'Queue empty. Sleeping 60 seconds...' -ForegroundColor DarkGray
    }
    if (-not $Once) { Start-Sleep -Seconds 60 }
  }
}

# v5.24 WORK UPDATE (Tyree's word, 2026-10-24): the queue drains itself at launch.
# By the time he could type 'work', the work update is already done - results pushed,
# and this seat's watcher carries them to his chat. He never has to ask the queue twice.
Write-Host '[runner] WORK UPDATE at launch - draining the job queue before the seat opens...' -ForegroundColor DarkCyan
try { Start-Worker $prime -Once } catch { Write-Host "[runner] work update skipped: $($_.Exception.Message)" -ForegroundColor DarkYellow }

while ($true) {
  Flush-Keys
  $rawInput = Read-Host 'TYREE'
  $input = Clean-Input $rawInput
  if ($input -ne $rawInput.Trim()) { Write-Host '[runner] repeated paste collapsed to one.' -ForegroundColor DarkYellow }
  if ($input -eq 'exit') { break }
  if ($input -eq 'work') { Start-Worker $prime -Once; continue }
  if ($input -eq 'workloop') { Start-Worker $prime; continue }
  if ([string]::IsNullOrWhiteSpace($input)) { continue }
  Reset-Loop
  [void]$history.Add(@{ role = 'user'; content = $input })
  $turns = 0
  while ($turns -lt 40) {
    $turns++
    Write-Host '...thinking' -ForegroundColor DarkGray
    try {
      $msg = Send-Chat $history
    } catch {
      if ($_.Exception.Message -match 'repeat') {
        Write-Host 'The brain looped and Ollama cut it off. Resetting this session clean...' -ForegroundColor Red
        $history.Clear()
        [void]$history.Add(@{ role = 'user'; content = $prime })
        $msg = Send-Chat $history
        [void]$history.Add(@{ role = 'assistant'; content = $msg.content })
        Write-Host "tyree: $($msg.content)" -ForegroundColor Green
        Write-Host 'Session reset. Ask again, fresh.' -ForegroundColor Red
        break
      }
      throw
    }
    if ((-not $msg.tool_calls) -and ($msg.content -match '\{\s*"name"\s*:')) {
      [void]$history.Add(@{ role = 'assistant'; content = $msg.content })
      [void]$history.Add(@{ role = 'user'; content = 'SYSTEM: that reply was tool-call JSON written as chat text - it did nothing. There is no print tool. Call a real tool through the tool channel now, or answer in plain words.' })
      Write-Host '[runner] fake tool-call text caught - redirected.' -ForegroundColor DarkYellow
      continue
    }
    if ($msg.tool_calls -and $msg.tool_calls.Count -gt 0) {
      $c = $msg.content
      if ($null -eq $c) { $c = '' }
      [void]$history.Add(@{ role = 'assistant'; content = $c; tool_calls = $msg.tool_calls })
      foreach ($call in $msg.tool_calls) {
        $fname = $call.function.name
        $fargs = $call.function.arguments
        if ($fargs -is [string]) { $fargs = $fargs | ConvertFrom-Json }
        if ($fname -eq 'run_powershell') {
          Write-Host "[HAND] $fname : $($fargs.command)" -ForegroundColor Yellow
        } else {
          Write-Host "[HAND] $fname" -ForegroundColor Yellow
        }
        $loopState = Check-Loop $fname $fargs
        if ($loopState -eq 'block') {
          $result = 'LOOP LAW: this exact call has run 4 times with the same result. It will NOT run again. Change roads completely, or answer Tyree now with what you have (UNREAD if you have nothing).'
          Write-Host $result -ForegroundColor Red
        } else {
          $result = Invoke-Tool $fname $fargs
          if ($result.Length -gt 4000) { $result = $result.Substring(0, 4000) + '...[cut]' }
          if ($loopState -eq 'warn') { $result = $result + ' LOOP WARNING: you already ran this exact call and got this result. Do not run it a third time - change roads or answer.' }
          Write-Host $result -ForegroundColor DarkGray
        }
        [void]$history.Add(@{ role = 'tool'; content = $result })
      }
      continue
    }
    [void]$history.Add(@{ role = 'assistant'; content = $msg.content })
    Write-Host "tyree: $($msg.content)" -ForegroundColor Green
    break
  }
}
