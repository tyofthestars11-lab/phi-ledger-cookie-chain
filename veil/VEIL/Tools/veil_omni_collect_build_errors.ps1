# VEIL OMNI: collect ALL build reds in one run, not one-by-one.
# Editor closed first. Writes D:\VEIL-OMNI\build_errors.txt and
# D:\VEIL-OMNI\pc_only_files.txt (PC Source files not in repo).
# No delete of Content, no package, no key, no process kill by default.
$ErrorActionPreference = "Continue"
Set-Location D:\VEIL-OMNI
$buildLog = "D:\VEIL-OMNI\build_log.txt"
$errFile = "D:\VEIL-OMNI\build_errors.txt"
cmd /c "`"C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat`" VEILEditor Win64 Development `"D:\VEIL-OMNI\VEIL.uproject`" -WaitMutex" 2>&1 | Tee-Object -FilePath $buildLog | Out-Null
Select-String -Path $buildLog -Pattern "error [A-Z][0-9]+|Error:" | ForEach-Object { $_.Line } | Sort-Object -Unique | Set-Content $errFile -Encoding utf8
Write-Host "RED LINES SAVED TO $errFile"
Get-Content $errFile
Write-Host "--- PC-ONLY SOURCE FILES (in D:\VEIL-OMNI\Source, not in repo clone) ---"
$repo = "C:\Users\Admin\phi-ledger-cookie-chain\veil\VEIL\Source"
if (Test-Path $repo) {
  Get-ChildItem -Recurse -File D:\VEIL-OMNI\Source | ForEach-Object {
    $rel = $_.FullName.Substring("D:\VEIL-OMNI\Source\".Length)
    if (-not (Test-Path (Join-Path $repo $rel))) { $rel }
  } | Set-Content "D:\VEIL-OMNI\pc_only_files.txt" -Encoding utf8
  Get-Content "D:\VEIL-OMNI\pc_only_files.txt"
}
