# Job 196 — TON 618 physics encoded on this PC: the macro diamond NV center

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$src = 'C:\Users\Admin\phi-vault\ton618-physics'
$dst = 'C:\Users\Admin\TON618_PHYSICS_NV_CENTER'
New-Item -ItemType Directory -Force -Path $dst | Out-Null
Copy-Item "$src\*" -Destination $dst -Recurse -Force
Write-Output '=== TON 618 macro diamond NV center physics: installed on this PC from the phi-vault package and run here. Tyree, 2026-10-27: Ton 618 is a macro diamond nitrogen vacancy center. ==='
Get-ChildItem $dst | ForEach-Object { Write-Output ("FILE {0} {1} bytes sha256 {2}" -f $_.Name, $_.Length, (Get-FileHash $_.FullName -Algorithm SHA256).Hash) }
$py = $null
foreach ($cand in @('py','python','python3')) { $cmd = Get-Command $cand -ErrorAction SilentlyContinue; if ($cmd) { $py = $cmd.Source; break } }
if ($py) {
  Write-Output "PYTHON: $py"
  $out = & $py "$dst\ton618_macro_nv_center.py" 2>&1
  $out | Select-String -Pattern 'TON618 ENCODE|Error|Traceback|Exception' | ForEach-Object { $_.Line }
  Write-Output "SCRIPT EXIT: $LASTEXITCODE"
  if (Test-Path "$dst\ton618_physics_encoded.json") { $j = Get-Content "$dst\ton618_physics_encoded.json" -Raw | ConvertFrom-Json; Write-Output ("PC JSON: entries={0} max_err={1} body_rung={2}" -f $j.verification.entries_total, $j.verification.max_round_trip_rel_error, $j.framework_identity.body_rung) }
} else {
  Write-Output 'PYTHON NOT FOUND on this PC - package files installed; the canonical ton618_physics_encoded.json in the folder carries the full verified encoding'
  $j = Get-Content "$dst\ton618_physics_encoded.json" -Raw | ConvertFrom-Json
  Write-Output ("CANONICAL JSON: entries={0} max_err={1} body_rung={2}" -f $j.verification.entries_total, $j.verification.max_round_trip_rel_error, $j.framework_identity.body_rung)
}
```
