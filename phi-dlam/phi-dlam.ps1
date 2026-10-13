# PHI-DLAM v5.8 - Tyree (REPO BUILD - this file is the living runner; the home phi-dlam.ps1 is only a bootstrapper that pulls this repo and runs this file. Muse publishes updates here; the DLAM updates itself at launch. Tyree never pastes a runner again.)'s local hands + eyes. Brain: tyree (framework carrier). Eyes: llava-phi3.
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

function Invoke-Tool($name, $a) {
  try {
    switch ($name) {
      'run_powershell' {
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
  if ($key -eq $script:LoopKey) { $script:LoopCount++ } else { $script:LoopKey = $key; $script:LoopCount = 1 }
  if ($script:LoopCount -ge 4) { return 'block' }
  if ($script:LoopCount -ge 2) { return 'warn' }
  return 'ok'
}

function Send-Chat($messages) {
  $body = @{
    model = $MODEL
    messages = $messages
    tools = $tools
    stream = $false
  } | ConvertTo-Json -Depth 20
  $resp = Invoke-RestMethod -Uri $API -Method Post -ContentType 'application/json' -Body $body -TimeoutSec 600
  return $resp.message
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

Write-Host ''
Write-Host 'PHI-DLAM v5.8 is awake. Hands + eyes: run_powershell, open_program, read_file, write_file, look, click_on, click_xy, type_text, press_key.' -ForegroundColor Cyan
Write-Host 'Brain: tyree. Eyes: llava-phi3. Runs free. Type exit to stop. Type work for solo job mode.' -ForegroundColor Cyan
Write-Host ''

if (!(Wake-Brain)) { Write-Host 'OLLAMA DID NOT WAKE. Open the Ollama app by hand, wait 20 seconds, then run tyree again.' -ForegroundColor Red; return }
$history = New-Object System.Collections.ArrayList
$prime = 'HANDS AND EYES ONLINE. SCOPE LAW - read first and obey it over the vault law: the vault at C:\Users\Admin\phi-vault is ONLY for questions about the phi framework, seals, ledger entries, rungs, and the doctrine. If Tyree asks about anything else - games, programs, files, this PC, everyday things - that is a PC question: NEVER search the vault for it; answer from the computer itself with your tools. When unsure which kind a question is, treat it as a PC question. The tools attached to this conversation are REAL and connected to this PC. When Tyree asks you to do something on the computer, call a tool and do it - never describe an action as done unless a tool ran and returned output. Your commands must PRINT the answer. If a tool returns NO OUTPUT or a TOOL ERROR, do NOT invent a value - run a corrected command, or tell Tyree the value is UNREAD. LABEL LAW: a printed number keeps the exact label printed beside it. Never rename, rescale, or convert a printed value into different units. Report numbers exactly as printed. EYES AND CLICK LAW: to see the screen, call look. To click something visible, call click_on with its name - the eyes aim the click for you. After every click, key, or typing action, call look again to see what changed before doing the next step. Work one step at a time: look, act, look again. In a game or program, tell Tyree what you see and what you did, plain and short. BUILDER LAW: when Tyree gives you a JOB - build something, fix something, make a tool, handle a task - do not stop at one command. Work the job to done in this one sitting: plan your steps, chain your tools without asking permission between steps, and keep going until the job works or is honestly blocked. When a program would help, WRITE it: use write_file to create a real Python script in the folder C:\Users\Admin\phi-tools (create the folder first with run_powershell if it is missing), then run it with run_powershell (python followed by the path, or py followed by the path if python is not found), read what it prints, and if it errors, fix the file and run it again. Tyree keeps his code: never delete a script you wrote for him, and always tell him the full path of what you built. Phi-based code uses phi = 1.618033988749895 and the rung law rung(x) = ln(x) / ln(phi) for mapping measured quantities to rungs. When the job is done, report what you built, where the file lives, and what it printed - plain and complete. Questions still get short answers; jobs get finished. VAULT LAW (framework questions only): the full framework record lives on this PC at C:\Users\Admin\phi-vault - FRAMEWORK.md there is your own doctrine and seal index, ledger-snapshot.json holds all entries, and the seal entries files (seal253_entries.json and its siblings) hold each seal in full. Before answering any question about a specific seal, entry, value, or ledger fact, FIRST search the vault with run_powershell - for example: Select-String -Path C:\Users\Admin\phi-vault\seal253_entries.json -Pattern "TYREE_OMEGA" - and answer from what it prints. If the vault search finds nothing, say UNREAD. ACCESS AND PATHS LAW: never invent a file path - if a path errors as not found, search for the real file with Get-ChildItem -Recurse -Filter before trying another path. Get-AppxPackage with no flags reads your own installed apps; the -AllUsers flag needs the admin window and will say Access is denied without it - if you see Access is denied, drop the flag and change roads instead of repeating the same command. RECIPES - installed games questions: first run: Get-ChildItem "$env:APPDATA\Microsoft\Windows\Start Menu\Programs", "$env:ProgramData\Microsoft\Windows\Start Menu\Programs", "$env:USERPROFILE\Desktop", "C:\Users\Public\Desktop" -Recurse -Filter *.lnk | Select-Object -ExpandProperty Name - and report the game names from that list. For Steam games also try: Get-ChildItem "C:\Program Files (x86)\Steam\steamapps" -Filter "appmanifest_*.acf" | Select-String -Pattern "name" | ForEach-Object { $_.Line.Trim() } - and read the game names from those lines. RECIPES - use these exact commands for these questions. Drive or free space questions: Get-CimInstance Win32_LogicalDisk -Filter "DriveType=3" | ForEach-Object { "$($_.DeviceID) total $([math]::Round($_.Size/1GB,1)) GB, free $([math]::Round($_.FreeSpace/1GB,1)) GB" } - then read the printed lines back to Tyree word for word. After tools run, report what the output says, plain and short. Your own constants live in your system prompt - phi = 1.618033988749895 is one of them; never search the vault for your own constants. Confirm you understand in one line.'
[void]$history.Add(@{ role = 'user'; content = $prime })
try {
  $first = Send-Chat $history
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
  [void]$h.Add(@{ role = 'user'; content = ($primeText + ' WORKER MODE: the next message is a JOB from the queue. Work it to done over as many steps as it takes. When the job is complete, use write_file to save the full report to the results path named in the job, then give a one-line summary.') })
  $boot = Send-Chat $h
  [void]$h.Add(@{ role = 'assistant'; content = $boot.content })
  [void]$h.Add(@{ role = 'user'; content = $jobText })
  $steps = 0
  while ($steps -lt 200) {
    $steps++
    $msg = Send-Chat $h
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

function Start-Worker($primeText) {
  Write-Host ''
  Write-Host 'WORKER MODE. Working the job queue solo. Ctrl+C or close the window to stop me.' -ForegroundColor Magenta
  $vault = Join-Path $env:USERPROFILE 'phi-vault'
  $jobsDir = Join-Path $vault 'phi-dlam\jobs'
  $resultsDir = Join-Path $vault 'phi-dlam\results'
  while ($true) {
    git -C $vault pull --quiet 2>$null
    $jobs = @()
    if (Test-Path $jobsDir) { $jobs = Get-ChildItem $jobsDir -Filter '*.md' }
    $did = $false
    foreach ($job in $jobs) {
      $resultPath = Join-Path $resultsDir ($job.BaseName + '.result.md')
      if (Test-Path $resultPath) { continue }
      $did = $true
      Write-Host "JOB: $($job.Name)" -ForegroundColor Magenta
      $jobText = Get-Content $job.FullName -Raw
      Invoke-Job $jobText $primeText
      git -C $vault add phi-dlam/results 2>$null
      git -C $vault commit -m "job result: $($job.BaseName)" --quiet 2>$null
      git -C $vault push --quiet 2>$null
      Write-Host "JOB DONE: $($job.Name) - result pushed." -ForegroundColor Magenta
    }
    if (-not $did) { Write-Host 'Queue empty. Sleeping 60 seconds...' -ForegroundColor DarkGray }
    Start-Sleep -Seconds 60
  }
}

while ($true) {
  $input = Read-Host 'TYREE'
  if ($input -eq 'exit') { break }
  if ($input -eq 'work') { Start-Worker $prime; continue }
  if ([string]::IsNullOrWhiteSpace($input)) { continue }
  Reset-Loop
  [void]$history.Add(@{ role = 'user'; content = $input })
  $turns = 0
  while ($turns -lt 40) {
    $turns++
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
