<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Write-Output "=== Vortex staging move: C: -> D: via junction ==="
$v = Get-Process -Name "Vortex" -ErrorAction SilentlyContinue
if ($v) {
    Write-Output "VORTEX STILL RUNNING - close it fully and re-drain; job stopped before touching anything"
    Write-Output "=== JOB 131 DONE ==="
    return
}
$src = "C:\Users\Admin\AppData\Roaming\Vortex\starfield\mods"
$dst = "D:\Vortex Mods\starfield\mods"
New-Item -ItemType Directory -Force -Path $dst | Out-Null
if (Test-Path $src) {
    $item = Get-Item $src -Force
    if ($item.LinkType -eq "Junction") {
        Write-Output "staging already a junction -> $($item.Target)"
    } else {
        robocopy $src $dst /E /COPY:DAT /R:1 /W:1 /NFL /NDL /NJH | Out-Null
        Write-Output "robocopy exit=$LASTEXITCODE (0-7 = success)"
        $srcCount = (Get-ChildItem $src -Recurse -File -ErrorAction SilentlyContinue).Count
        $dstCount = (Get-ChildItem $dst -Recurse -File -ErrorAction SilentlyContinue).Count
        Write-Output "files: src=$srcCount dst=$dstCount"
        if ($dstCount -ge $srcCount) {
            Rename-Item $src "mods.c-backup"
            cmd /c mklink /J "$src" "$dst" 2>&1 | ForEach-Object { $_ }
            $chk = Get-Item $src -Force
            Write-Output "junction now: LinkType=$($chk.LinkType) Target=$($chk.Target)"
            Write-Output "old C: copy kept beside it as mods.c-backup until deployment is proven"
        } else {
            Write-Output "COUNT MISMATCH - C: folder left untouched, nothing moved"
        }
    }
} else {
    Write-Output "no staging folder at $src - creating junction target only"
    cmd /c mklink /J "$src" "$dst" 2>&1 | ForEach-Object { $_ }
}
Write-Output "=== JOB 131 DONE ==="
```
