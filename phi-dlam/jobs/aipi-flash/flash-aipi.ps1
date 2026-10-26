# flash-aipi.ps1 - AiPi Lite (XORIGIN AI PI-Lite, model XY006PL01, ESP32-S3) -> Muse Gadgets firmware.
# STEP A (FIRST, MANDATORY): full 16 MB stock backup to aipi-lite-stock-backup.bin beside this script.
# STEP B: write the Muse firmware using this folder's flash_args file VERBATIM (its own tokens are
#         passed straight to esptool - offsets, flash mode/freq/size all come from that file).
# Everything is written to flash-aipi-result.log beside this script.
# Exit code 0 = flash complete. Exit code 1 = aborted/failed BEFORE or DURING the job; read the log.
$ErrorActionPreference = 'Continue'
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $here
$logPath = Join-Path $here 'flash-aipi-result.log'

function Say($m) {
  $line = "[{0}] {1}" -f (Get-Date -Format 'yyyy-MM-dd HH:mm:ss'), $m
  Write-Host $line
  Add-Content -Path $logPath -Value $line -Encoding UTF8
}
function Fail($m) {
  Say "ABORT: $m"
  Say 'AIPI FLASH NOT COMPLETED - see the lines above. Nothing was improvised; report this log as-is.'
  exit 1
}

Say '=== AIPI LITE -> MUSE GADGETS FLASH ==='
Say "Package folder: $here"

# --- Expected payload (byte sizes from the verified build) ---
$expect = @{
  'muse-gadget.bin'                      = 2166784
  'ota_data_initial.bin'                 = 8192
  'bootloader\bootloader.bin'            = 22608
  'partition_table\partition-table.bin'  = 3072
  'flash_args'                           = 179
}
foreach ($rel in $expect.Keys) {
  $p = Join-Path $here $rel
  if (-not (Test-Path $p)) { Fail "payload file missing: $rel" }
  $sz = (Get-Item $p).Length
  if ($sz -ne $expect[$rel]) { Fail "payload size mismatch: $rel is $sz bytes, expected $($expect[$rel])" }
  Say "payload OK: $rel ($sz bytes)"
}

# --- Python + esptool (local venv beside this script) ---
$pyBase = $null; $pyBaseArgs = @()
foreach ($cand in @('python', 'py', 'python3')) {
  if (Get-Command $cand -ErrorAction SilentlyContinue) {
    $pyBase = $cand
    if ($cand -eq 'py') { $pyBaseArgs = @('-3') }
    break
  }
}
if (-not $pyBase) { Fail 'no Python found on PATH (tried python, py, python3)' }
Say "python launcher: $pyBase $($pyBaseArgs -join ' ')"

$venv = Join-Path $here '.venv-esptool'
$venvPy = Join-Path $venv 'Scripts\python.exe'
if (-not (Test-Path $venvPy)) {
  Say 'creating esptool venv (one time)...'
  & $pyBase @pyBaseArgs -m venv $venv 2>&1 | ForEach-Object { Say "$_" }
  if (-not (Test-Path $venvPy)) { Fail 'venv creation failed' }
}
Say 'installing/upgrading esptool into the venv...'
& $venvPy -m pip install --upgrade esptool 2>&1 | ForEach-Object { Say "$_" }
if ($LASTEXITCODE -ne 0) { Fail 'pip install esptool failed (no internet? read the pip lines above)' }
& $venvPy -m esptool version 2>&1 | ForEach-Object { Say "$_" }

# --- Find her COM port: Espressif native USB (VID_303A PID_1001) first, then any serial port.
#     Probe each candidate with chip-id; the one that answers ESP32-S3 is hers. ---
$candidates = @()
$pnp = Get-CimInstance Win32_PnPEntity -ErrorAction SilentlyContinue |
  Where-Object { $_.DeviceID -match 'VID_303A&PID_1001' }
foreach ($d in $pnp) { if ($d.Name -match '\((COM\d+)\)') { $candidates += $matches[1] } }
foreach ($p in [System.IO.Ports.SerialPort]::GetPortNames()) {
  if ($candidates -notcontains $p) { $candidates += $p }
}
$candidates = @($candidates | Select-Object -Unique)
if ($candidates.Count -eq 0) { Fail 'no COM ports found at all - is the board plugged in by USB-C?' }
Say "candidate ports: $($candidates -join ', ')"

$port = $null
foreach ($p in $candidates) {
  Say "probing $p ..."
  $out = & $venvPy -m esptool -p $p chip_id 2>&1 | Out-String
  $out -split "`r?`n" | Where-Object { $_ -ne '' } | ForEach-Object { Say "${p}: $_" }
  if ($out -match 'ESP32-S3') { $port = $p; break }
}
if (-not $port) { Fail 'no ESP32-S3 answered on any candidate port' }
Say "PORT: $port"
$macOut = & $venvPy -m esptool -p $port read_mac 2>&1 | Out-String
$macOut -split "`r?`n" | Where-Object { $_ -ne '' } | ForEach-Object { Say "read_mac: $_" }

# --- STEP A: stock backup FIRST. Never overwrite an existing full-size backup: it is the
#     original stock image and her only restore point. ---
$backup = Join-Path $here 'aipi-lite-stock-backup.bin'
if ((Test-Path $backup) -and ((Get-Item $backup).Length -eq 16777216)) {
  Say "BACKUP ALREADY EXISTS - KEEPING ORIGINAL: $backup (16777216 bytes)"
} else {
  Say 'STEP A: reading full stock flash (0x0, 16 MB) - this takes a few minutes...'
  & $venvPy -m esptool -p $port -b 921600 read_flash 0x0 0x1000000 $backup 2>&1 |
    ForEach-Object { Say "$_" }
  if ($LASTEXITCODE -ne 0) { Fail "stock backup read failed (esptool exit $LASTEXITCODE)" }
  if (-not (Test-Path $backup)) { Fail 'stock backup file was not created' }
  $bsz = (Get-Item $backup).Length
  if ($bsz -ne 16777216) { Fail "stock backup has wrong size: $bsz bytes (expected 16777216)" }
  Say "BACKUP OK: $backup (16777216 bytes)"
}

# --- STEP B: write the Muse firmware. Every token comes from flash_args verbatim. ---
Say 'STEP B: writing Muse firmware with flash_args verbatim...'
$faTokens = (Get-Content (Join-Path $here 'flash_args') -Raw) -split '\s+' |
  Where-Object { $_ -ne '' }
Say "flash_args tokens: $($faTokens -join ' ')"
& $venvPy -m esptool --chip esp32s3 -p $port -b 921600 write_flash @faTokens 2>&1 |
  ForEach-Object { Say "$_" }
if ($LASTEXITCODE -ne 0) {
  Say "FLASH WRITE FAILED (esptool exit $LASTEXITCODE) - the stock backup beside this script is the restore point."
  Fail 'write_flash did not complete'
}
Say 'FLASH WRITE OK (esptool verified the write)'

# Post-flash liveness probe (informational only; the write exit code above is the verdict).
$probe = & $venvPy -m esptool -p $port chip_id 2>&1 | Out-String
$probe -split "`r?`n" | Where-Object { $_ -ne '' } | ForEach-Object { Say "post-flash probe: $_" }

Say 'AIPI FLASH COMPLETE'
Say 'Next (Tyree, phone): Muse app > Settings > Devices > Developer mode ON > Add Device > MuseGadget-XXXXXX, then press her bottom-right talk button when the light breathes blue. Green = connected.'
exit 0
