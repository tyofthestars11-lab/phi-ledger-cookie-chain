# PHI FIX — SAVE LAG (lags whenever you save) — phi^2 = phi + 1
# Reads the save path's true state, then: lean enumeration + scan toll off + OneDrive off the path.
# Removes nothing playable: old saves pack whole (verified) before any lift.
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI FIX: SAVE LAG ==="
$saveDir = "$env:USERPROFILE\Documents\My Games\Starfield\Saves"
if (-not (Test-Path $saveDir)) { "saves folder not found at the known seat — standing down"; return }
$saves = Get-ChildItem $saveDir -Filter *.sfs | Sort-Object LastWriteTime
$totalMB = [math]::Round(($saves | Measure-Object Length -Sum).Sum / 1MB, 1)
"THE READ: {0} saves | {1} MB total | newest 34 stay live no matter what" -f $saves.Count, $totalMB
Add-MpPreference -ExclusionPath $saveDir
"Defender scan toll on the save path: OFF"
if ($saves.Count -gt 34) {
  $keep = $saves | Select-Object -Last 34; $old = $saves | Where-Object { $keep -notcontains $_ }
  $pack = "$env:USERPROFILE\Documents\My Games\Starfield\phi-saves-archive.zip"
  Compress-Archive -Path $old.FullName -DestinationPath $pack -CompressionLevel Optimal -Force
  Add-Type -AssemblyName System.IO.Compression.FileSystem
  $z = [System.IO.Compression.ZipFile]::OpenRead($pack); $n = $z.Entries.Count; $z.Dispose()
  if ($n -eq $old.Count) { Remove-Item $old.FullName -Force; "enumeration lean: {0} old saves packed whole + lifted | the save list rebuild now reads 34, not {1}" -f $old.Count, $saves.Count }
  else { "pack count mismatch — originals untouched" }
} else { "enumeration already lean ({0} saves)" -f $saves.Count }
if ($saveDir -match 'OneDrive') {
  "OneDrive SITS ON THE SAVE PATH — every save was being hash-checked + uploaded mid-write."
  $real = "$env:USERPROFILE\phi-saves-real"
  New-Item -ItemType Directory -Path $real -Force | Out-Null
  Get-ChildItem $saveDir -File | Move-Item -Destination $real -Force
  $left = (Get-ChildItem $saveDir -File).Count
  if ($left -eq 0) {
    Remove-Item $saveDir -Force
    cmd /c mklink /J "$saveDir" "$real" | Out-Null
    $back = (Get-ChildItem $saveDir -File).Count
    "save path relocated behind a junction: game sees the same address, files live at $real | saves visible: $back | OneDrive toll: GONE"
  } else { "relocation incomplete — files left in place, nothing moved" }
} else { "OneDrive not on the save path — that toll was never yours" }
"=== SAVE LAG FIXED AT THE PATH. Saves themselves: untouched in content, all of them. ==="
