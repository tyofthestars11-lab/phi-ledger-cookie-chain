<!-- PHI-DIRECT -->
# JOB 021 - MAKE THE SAVE ROOM ON D: AND MOVE THE SAVES IN (DIRECT)

Job 020 found the D: package home but no SystemAppData\wgs folder inside it
yet - the game has not built its save room on D:. This job builds that room
(New-Item -Force) inside the D: package home found by 020, then copies the
C: save set (31 files, 150.3 MB) in whole, and verifies source vs target.
Nothing is deleted anywhere; the C: set stays as the backup. Any error is
printed verbatim into the report.

## STEP 1 - BUILD THE ROOM
```powershell
$pkg = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($pkg) {
  $tw = Join-Path $pkg.FullName 'SystemAppData\wgs'
  try { New-Item -ItemType Directory -Force -Path $tw -ErrorAction Stop | Out-Null; "ROOM READY: $tw" } catch { "ROOM CREATE FAILED: $($_.Exception.Message)" }
} else { "D PACKAGE NOT FOUND" }
```

## STEP 2 - MOVE THE SET IN + VERIFY
```powershell
$src = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
$sw = if ($src) { Join-Path $src.FullName 'SystemAppData\wgs' } else { $null }
$pkg = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
$tw = if ($pkg) { Join-Path $pkg.FullName 'SystemAppData\wgs' } else { $null }
if ($sw -and (Test-Path $sw) -and $tw -and (Test-Path $tw)) {
  Copy-Item "$sw\*" -Destination $tw -Recurse -Force -ErrorAction Continue
  $sf = Get-ChildItem $sw -Recurse -File -Force -ErrorAction SilentlyContinue
  $tf = Get-ChildItem $tw -Recurse -File -Force -ErrorAction SilentlyContinue
  "SOURCE: $($sf.Count) files, $([math]::Round(($sf | Measure-Object Length -Sum).Sum/1MB,1)) MB"
  "TARGET: $($tf.Count) files, $([math]::Round(($tf | Measure-Object Length -Sum).Sum/1MB,1)) MB at $tw"
} else { "COPY NOT RUN: source ok = $([bool]($sw -and (Test-Path $sw))); target = $tw exists = $([bool]($tw -and (Test-Path $tw)))" }
```
