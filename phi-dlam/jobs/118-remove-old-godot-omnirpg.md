<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Config\*" "D:\VEIL\Config" -Force
Copy-Item "veil\OMNI\Config\*" "D:\OMNI-UE\Config" -Force
Write-Output "SYNCED config (SM6 declared for Virtual Shadow Maps)"

Write-Output "=== ProjectID lines on disk ==="
Select-String -Path "D:\VEIL\Config\DefaultGame.ini" -Pattern "ProjectID|ProjectName" | ForEach-Object { "VEIL " + $_.Line }
Select-String -Path "D:\OMNI-UE\Config\DefaultGame.ini" -Pattern "ProjectID|ProjectName" | ForEach-Object { "OMNI " + $_.Line }

# Remove the OLD Godot OmniRPG export (D:\OMNI-RPG) - Tyree's word.
# Guard: it must look like the Godot export (OmniRPG + .pck, NO
# .uproject) or nothing is deleted and the contents are reported.
$old = "D:\OMNI-RPG"
if (Test-Path $old) {
    Write-Output "=== D:\OMNI-RPG contents before removal ==="
    Get-ChildItem $old | ForEach-Object { $_.Name }
    $hasPck = Test-Path "$old\OmniRPG.pck"
    $hasExe = Test-Path "$old\OmniRPG.exe"
    $hasUproject = (Get-ChildItem $old -Filter "*.uproject" -ErrorAction SilentlyContinue).Count -gt 0
    if (($hasPck -or $hasExe) -and -not $hasUproject) {
        Remove-Item $old -Recurse -Force
        Write-Output "REMOVED D:\OMNI-RPG (old Godot export). Gone: $(-not (Test-Path $old))"
    } else {
        Write-Output "GUARD HELD: folder does not match the Godot export signature - NOT deleted"
    }
} else { Write-Output "D:\OMNI-RPG already absent" }
Write-Output "OMNI-UE intact: $(Test-Path 'D:\OMNI-UE\OMNI.uproject')"
Write-Output "=== JOB 118 DONE ==="
```
