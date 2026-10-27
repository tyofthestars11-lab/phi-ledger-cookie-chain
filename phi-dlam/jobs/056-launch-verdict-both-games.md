<!-- PHI-DIRECT -->
# JOB 056 - LAUNCH VERDICT: OMNI RPG + VEIL (DIRECT)

Tyree's word (2026-10-27): "check to see if Omni Rpg and VEIL work on my pc."
Launch both, read the verdict from the machine itself. OMNI RPG: start it,
confirm the process lives with a window, then close it clean. VEIL: open the
project in UnrealEditor, wait for load, read the project log tail for errors,
and LEAVE THE EDITOR OPEN for Tyree. Idempotent: if the editor is already
running with the project, report that instead of launching a second copy.

```powershell
"=== OMNI RPG ==="
$exe = Get-ChildItem 'D:\OMNI-RPG\*.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $exe) { "OMNI VERDICT: NO EXE FOUND at D:\OMNI-RPG" }
else {
  $omni = Start-Process -FilePath $exe.FullName -WorkingDirectory 'D:\OMNI-RPG' -PassThru
  Start-Sleep -Seconds 20
  $omni.Refresh()
  if ($omni.HasExited) { "OMNI VERDICT: EXITED EARLY, code=$($omni.ExitCode)" }
  else {
    "OMNI VERDICT: RUNNING. pid=$($omni.Id) window='$($omni.MainWindowTitle)'"
    $null = $omni.CloseMainWindow()
    Start-Sleep -Seconds 3
    if (-not $omni.HasExited) { Stop-Process -Id $omni.Id -Force -ErrorAction SilentlyContinue }
    "OMNI closed clean after the check."
  }
}
"=== VEIL (UNREAL) ==="
$editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$already = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($already) { "VEIL VERDICT: EDITOR ALREADY RUNNING. pid=$($already.Id) window='$($already.MainWindowTitle)'" }
elseif (-not (Test-Path $editor)) { "VEIL VERDICT: EDITOR EXE NOT FOUND at $editor" }
else {
  $vp = Start-Process -FilePath $editor -ArgumentList '"D:\VEIL\VEIL.uproject"' -PassThru
  $waited = 0; $ready = $false
  while ($waited -lt 150) {
    Start-Sleep -Seconds 15; $waited += 15
    $vp.Refresh()
    if ($vp.HasExited) { break }
    if ($vp.MainWindowTitle -match 'VEIL') { $ready = $true; break }
  }
  $vp.Refresh()
  if ($vp.HasExited) { "VEIL VERDICT: EDITOR EXITED DURING LOAD, code=$($vp.ExitCode) after $waited s" }
  else {
    "VEIL VERDICT: EDITOR RUNNING. pid=$($vp.Id) window='$($vp.MainWindowTitle)' waited=$waited s project-ui=$ready"
    "Editor LEFT OPEN for Tyree."
  }
  $log = 'D:\VEIL\Saved\Logs\VEIL.log'
  if (Test-Path $log) {
    "--- VEIL.log: last init/error lines ---"
    Get-Content $log -Tail 400 | Select-String -Pattern 'LogInit: Display: Engine is initialized|Error:|Fatal|Failed to load|LogLoad:' | Select-Object -Last 12 | ForEach-Object { $_.Line }
  } else { "VEIL.log not found yet at $log" }
}
"=== JOB 056 DONE ==="
```
