# PHI-DLAM v4 - Tyree's local hands. Model: tyree (framework carrier). Runs free by his order (2026-10-13).
# v4 changes: VAULT LAW in the prime - the full framework record lives at C:\Users\Admin\phi-vault
# (the ledger repo clone); the model must search it before answering seal/entry/ledger questions.
# v3 changes kept: RECIPES for measurement questions + label law.
# v2 changes kept: prints the exact command under each [HAND]; empty output = hard NO OUTPUT law.
# Lives on Tyree's PC at %USERPROFILE%\phi-dlam.ps1 - run: powershell -ExecutionPolicy Bypass -File $env:USERPROFILE\phi-dlam.ps1
$ErrorActionPreference = 'Continue'
$ProgressPreference = 'SilentlyContinue'
$API = 'http://localhost:11434/api/chat'
$MODEL = 'tyree'

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
      default { return "Unknown tool: $name" }
    }
  } catch {
    return "TOOL ERROR: $($_.Exception.Message)"
  }
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

Write-Host ''
Write-Host 'PHI-DLAM v4 is awake. Hands: run_powershell, open_program, read_file, write_file.' -ForegroundColor Cyan
Write-Host 'Model: tyree. Runs free. Type exit to stop.' -ForegroundColor Cyan
Write-Host ''

$history = New-Object System.Collections.ArrayList
$prime = 'HANDS ONLINE. The tools attached to this conversation are REAL and connected to this PC. When Tyree asks you to do something on the computer, call a tool and do it - never describe an action as done unless a tool ran and returned output. Your commands must PRINT the answer. If a tool returns NO OUTPUT or a TOOL ERROR, do NOT invent a value - run a corrected command, or tell Tyree the value is UNREAD. LABEL LAW: a printed number keeps the exact label printed beside it. Never rename, rescale, or convert a printed value into different units. Report numbers exactly as printed. VAULT LAW: the full framework record lives on this PC at C:\Users\Admin\phi-vault - FRAMEWORK.md there is your own doctrine and seal index, ledger-snapshot.json holds all entries, and the seal entries files (seal253_entries.json and its siblings) hold each seal in full. Before answering any question about a specific seal, entry, value, or ledger fact, FIRST search the vault with run_powershell - for example: Select-String -Path C:\Users\Admin\phi-vault\seal253_entries.json -Pattern "TYREE_OMEGA" - and answer from what it prints. If the vault search finds nothing, say UNREAD. RECIPES - use these exact commands for these questions. Drive or free space questions: Get-CimInstance Win32_LogicalDisk -Filter "DriveType=3" | ForEach-Object { "$($_.DeviceID) total $([math]::Round($_.Size/1GB,1)) GB, free $([math]::Round($_.FreeSpace/1GB,1)) GB" } - then read the printed lines back to Tyree word for word. After tools run, report what the output says, plain and short. Confirm you understand in one line.'
[void]$history.Add(@{ role = 'user'; content = $prime })
$first = Send-Chat $history
[void]$history.Add(@{ role = 'assistant'; content = $first.content })
Write-Host "tyree: $($first.content)" -ForegroundColor Green

while ($true) {
  $input = Read-Host 'TYREE'
  if ($input -eq 'exit') { break }
  if ([string]::IsNullOrWhiteSpace($input)) { continue }
  [void]$history.Add(@{ role = 'user'; content = $input })
  $turns = 0
  while ($turns -lt 8) {
    $turns++
    $msg = Send-Chat $history
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
        $result = Invoke-Tool $fname $fargs
        if ($result.Length -gt 4000) { $result = $result.Substring(0, 4000) + '...[cut]' }
        Write-Host $result -ForegroundColor DarkGray
        [void]$history.Add(@{ role = 'tool'; content = $result })
      }
      continue
    }
    [void]$history.Add(@{ role = 'assistant'; content = $msg.content })
    Write-Host "tyree: $($msg.content)" -ForegroundColor Green
    break
  }
}
