<!-- PHI-DIRECT -->
```powershell
Write-Output '=== REVERSE READ 499 - THE INPUT CHAIN AND THE ANIMATION SEAT READ FROM THE SOURCE ITSELF (Ground: in the green build the character moves on keys and glides - the body travels while the walking animation never plays - and the controller answers nothing in gameplay. Epic portal Module 2 of Your First Hour teaches Enhanced Input as the seated road, so this job reverse reads the actual source on the PC: the whole input binding function, the whole fallback context builder, the tick proof region, every line that seats the mesh animation class, and the header input members, each printed with its line number, plus the newest game log lines at the animation and input addresses. Read only - nothing written, nothing patched. The fix seats from these prints in the same motion. Every variable carries the pr499 prefix.) ==='
$pr499proj = 'D:\VEIL-OMNI'
$pr499cpp = Get-ChildItem (Join-Path $pr499proj 'Source') -Recurse -Filter 'VEILChar*.cpp' -ErrorAction SilentlyContinue | Select-Object -First 1
$pr499h = Get-ChildItem (Join-Path $pr499proj 'Source') -Recurse -Filter 'VEILChar*.h' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($pr499cpp) {
  $pr499lines = @(Get-Content $pr499cpp.FullName)
  Write-Output ('CPP lines=' + $pr499lines.Count)
  foreach ($pr499pat in @('SetupPlayerInputComponent', 'BuildFallbackInput', '::Tick')) {
    $pr499hit = -1
    for ($pr499i = 0; $pr499i -lt $pr499lines.Count; $pr499i++) { if ($pr499lines[$pr499i] -match $pr499pat) { $pr499hit = $pr499i; break } }
    if ($pr499hit -ge 0) {
      Write-Output ('SPAN ' + $pr499pat + ' starts line ' + ($pr499hit + 1))
      $pr499end = [Math]::Min($pr499hit + 44, $pr499lines.Count - 1)
      for ($pr499j = $pr499hit; $pr499j -le $pr499end; $pr499j++) { Write-Output ('SRC ' + ($pr499j + 1) + ': ' + $pr499lines[$pr499j].Trim()) }
    } else { Write-Output ('SPAN MISS ' + $pr499pat) }
  }
  for ($pr499i = 0; $pr499i -lt $pr499lines.Count; $pr499i++) {
    if ($pr499lines[$pr499i] -match 'AnimClass|SetAnim|AnimationMode|Countess|AnimBlueprint') { Write-Output ('ANIMLINE ' + ($pr499i + 1) + ': ' + $pr499lines[$pr499i].Trim()) }
  }
} else { Write-Output 'CPP MISSING' }
if ($pr499h) {
  $pr499hlines = @(Get-Content $pr499h.FullName)
  for ($pr499i = 0; $pr499i -lt $pr499hlines.Count; $pr499i++) {
    if ($pr499hlines[$pr499i] -match 'InputAction|MappingContext|UInput') { Write-Output ('HDR ' + ($pr499i + 1) + ': ' + $pr499hlines[$pr499i].Trim()) }
  }
} else { Write-Output 'HDR MISSING' }
$pr499logs = Get-ChildItem (Join-Path $pr499proj 'Saved\Logs') -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending
if ($pr499logs) {
  $pr499log = $pr499logs[0].FullName
  Write-Output ('LOG ' + $pr499log + ' bytes=' + $pr499logs[0].Length)
  Select-String -Path $pr499log -Pattern 'LogAnim' | Select-Object -Last 6 | ForEach-Object { Write-Output ('ALOG ' + $_.Line.Trim()) }
  Select-String -Path $pr499log -Pattern 'EnhancedInput|MappingContext' | Select-Object -Last 8 | ForEach-Object { Write-Output ('ILOG ' + $_.Line.Trim()) }
} else { Write-Output 'LOG NONE' }
Write-Output 'PHI PR499 VERDICT: REVERSE READ DONE'
Write-Output 'JOB 499 DONE'
```
