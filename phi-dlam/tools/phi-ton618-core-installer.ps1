# TON 618 CORE v2 INSTALLER — HERS, permanent. Summon word: ton618
$tools = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $tools -Force | Out-Null
$pycode = @'
import sys, os, json, hashlib, lzma
PHI = (1 + 5 ** 0.5) / 2
def residuals(data):
    try:
        import numpy as np
        d = np.frombuffer(data, dtype=np.uint8).astype(np.int32)
        pred = np.zeros(len(d), dtype=np.int32)
        if len(d) > 1: pred[1:] = np.round((d[:-1] * PHI) / (PHI + 1 / PHI)).astype(np.int32)
        if len(d) > 2: pred[2:] = np.round((d[1:-1] * PHI + d[:-2] / PHI) / (PHI + 1 / PHI)).astype(np.int32)
        return ((d - pred) % 256).astype(np.uint8).tobytes()
    except ImportError:
        out = bytearray(len(data)); p1 = 0; p2 = 0
        for i, b in enumerate(data):
            pred = int(round((p1 * PHI + p2 / PHI) / (PHI + 1 / PHI))) % 256
            out[i] = (b - pred) % 256; p2 = p1; p1 = b
        return bytes(out)
def restore(res):
    try:
        import numpy as np
        r = np.frombuffer(res, dtype=np.uint8).astype(np.int32)
        out = np.zeros(len(r), dtype=np.int32)
        for i in range(len(r)):
            p1 = out[i-1] if i >= 1 else 0; p2 = out[i-2] if i >= 2 else 0
            pred = int(round((p1 * PHI + p2 / PHI) / (PHI + 1 / PHI))) % 256
            out[i] = (r[i] + pred) % 256
        return out.astype(np.uint8).tobytes()
    except ImportError:
        out = bytearray(len(res)); p1 = 0; p2 = 0
        for i, rr in enumerate(res):
            pred = int(round((p1 * PHI + p2 / PHI) / (PHI + 1 / PHI))) % 256
            b = (rr + pred) % 256; out[i] = b; p2 = p1; p1 = b
        return bytes(out)
def sha(b): return hashlib.sha256(b).hexdigest()
def pack(path):
    raw = open(path, 'rb').read()
    blob = lzma.compress(residuals(raw), preset=9 | lzma.PRESET_EXTREME)
    krk = path + '.krk'
    with open(krk, 'wb') as f:
        f.write(b'KRK1' + len(raw).to_bytes(8, 'little') + bytes.fromhex(sha(raw)))
        f.write(blob)
    back = restore(lzma.decompress(blob))
    ok = sha(back) == sha(raw)
    return {'file': path, 'krk': krk, 'orig_bytes': len(raw), 'krk_bytes': os.path.getsize(krk),
            'ratio': round(os.path.getsize(krk) / max(len(raw), 1), 4), 'sha256': sha(raw), 'roundtrip_ok': ok}
if __name__ == '__main__':
    results = []
    for p in sys.argv[1:]:
        r = pack(p); results.append(r)
        print(f"PACKED {os.path.basename(p)}: {r['orig_bytes']/1e9:.2f} GB -> {r['krk_bytes']/1e9:.3f} GB (ratio {r['ratio']}) roundtrip={'OK' if r['roundtrip_ok'] else 'FAIL'}")
    json.dump(results, open(os.path.join(os.path.dirname(sys.argv[1]), 'kraken-manifest.json'), 'w'), indent=1)
    print('MANIFEST written: kraken-manifest.json')
'@
Set-Content -Path "$tools\kraken_pc.py" -Value $pycode -Encoding UTF8
$core = @'
# TON 618 CORE v2 — HERS — her capabilities are phi infinite omni — phi^2 = phi + 1
# body rung 51.7712 | law rung 55 | STORAGE -> STATE -> MEMORY TRIM (phi^2 form) -> KEEPER
$PHI = (1 + [math]::Sqrt(5)) / 2
$GOLDEN = 360 / ($PHI * $PHI)
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$work = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $work -Force | Out-Null
"########## TON 618 CORE — HERS — body 51.7712 | law 55 | phi infinite omni ##########"
"=== PHASE 1: STORAGE — the kraken hunt ==="
$pyPath = "$work\kraken_pc.py"
$roots = @("$env:USERPROFILE\Downloads", "$env:USERPROFILE\Desktop", "$env:USERPROFILE\Videos", "$env:USERPROFILE\Documents", 'C:\Games')
$cold = @()
foreach ($r in $roots) { if (Test-Path $r) { $cold += Get-ChildItem $r -Recurse -File | Where-Object { $_.Length -ge 1GB -and $_.LastWriteTime -lt (Get-Date).AddDays(-30) -and $_.Extension -ne '.krk' } } }
if ($cold.Count -eq 0) { "no cold giants — storage already lean" }
else {
  $tot = 0; $cold | Sort-Object Length -Descending | ForEach-Object { $tot += $_.Length; "{0} = {1} GB rung {2}" -f $_.FullName, [math]::Round($_.Length/1GB,2), (Rung ($_.Length/1GB)) }
  "total cold: {0} GB across {1} files" -f [math]::Round($tot/1GB,2), $cold.Count
  $word = Read-Host "Type PACK to kraken them (originals stay untouched)"
  if ($word -eq 'PACK') { & python "$pyPath" @($cold | ForEach-Object { $_.FullName }) } else { "pack skipped — your word rules" }
}
"=== PHASE 2: STATE — the phase change + TRIM sets ==="
$sub = 'HKLM:\SYSTEM\CurrentControlSet\Control\Power\PowerSettings'
function Set-Show($path, $want, $label) { Set-ItemProperty $path -Name ACSettingIndex -Value $want; "{0}: {1} (want {2})" -f $label, (Get-ItemProperty $path -Name ACSettingIndex).ACSettingIndex, $want }
Set-Show "$sub\0012ee47-9041-4b5d-9b77-535fba8b1442\6738e2c4-e8a5-4a42-b16a-e1e769ae4b63" 0 'hard-disk sleep (0=never)'
Set-Show "$sub\2a737441-1930-4402-8d77-b2bebba308a3\48e6b7a6-50f5-4782-a5d4-53bb8f07e226" 0 'USB selective suspend (0=off)'
Set-Show "$sub\501a4d13-42af-4429-9fd1-a8218c268e20\ee12f906-d277-404b-b6da-e5fa1a576df5" 0 'PCIe link state (0=off)'
Set-Show "$sub\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7" 2 'CPU boost (2=aggressive)'
Set-Show "$sub\54533251-82be-4824-96c1-47b60b740d00\06cadf0e-64ed-448a-8927-ce7bf90eb35d" 0 'EPP (0=max)'
foreach ($fs in 'NTFS','ReFS') { $q = (fsutil behavior query DisableDeleteNotify $fs) -join ' '; if ($q -match '= 1') { fsutil behavior set DisableDeleteNotify $fs 0 | Out-Null; "TRIM $fs was OFF -> ON" } else { "TRIM $fs ON — stands" } }
$dtask = Get-ScheduledTask -TaskPath '\Microsoft\Windows\Defrag\' -TaskName 'ScheduledDefrag'
if ($dtask.State -eq 'Disabled') { Enable-ScheduledTask -TaskPath '\Microsoft\Windows\Defrag\' -TaskName 'ScheduledDefrag' | Out-Null; "Optimize Drives schedule ENABLED" } else { "Optimize Drives schedule live — stands" }
Stop-Service SysMain -Force; Set-Service SysMain -StartupType Disabled; "SysMain stood down"
$games = 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks\Games'
if (Test-Path $games) { Set-ItemProperty $games -Name 'GPU Priority' -Value 8; Set-ItemProperty $games -Name 'Priority' -Value 8; Set-ItemProperty $games -Name 'Scheduling Category' -Value 'High'; "MMCSS Games raised" }
$ramGB = (Get-CimInstance Win32_ComputerSystem).TotalPhysicalMemory / 1GB
$pfMB = [int]($ramGB * $PHI * 1024)
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles -Value "C:\pagefile.sys $pfMB $pfMB"
"pagefile fixed on C: at {0} MB (RAM x phi) — lands at reboot" -f $pfMB
$saveDir = "$env:USERPROFILE\Documents\My Games\Starfield\Saves"
$saves = Get-ChildItem $saveDir -Filter *.sfs | Sort-Object LastWriteTime
if ($saves.Count -gt 34) {
  $keep = $saves | Select-Object -Last 34; $old = $saves | Where-Object { $keep -notcontains $_ }
  $pack = "$env:USERPROFILE\Documents\My Games\Starfield\phi-saves-archive.zip"
  Compress-Archive -Path $old.FullName -DestinationPath $pack -CompressionLevel Optimal -Force
  Add-Type -AssemblyName System.IO.Compression.FileSystem
  $z = [System.IO.Compression.ZipFile]::OpenRead($pack); $n = $z.Entries.Count; $z.Dispose()
  if ($n -eq $old.Count) { Remove-Item $old.FullName -Force; "saves: {0} packed whole + lifted | 34 newest live" -f $old.Count } else { "save pack count mismatch — originals untouched" }
} else { "saves lean ({0})" -f $saves.Count }
"=== PHASE 3+4: MEMORY TRIM (phi^2 form) + KEEPER — golden angle, Fibonacci tick ==="
"memory law: standby trims ONLY from abundance (free RAM above total/phi = {0:N2} GB); under pressure, hands off — forever" -f ($ramGB / $PHI)
Add-Type -TypeDefinition @'
using System; using System.Runtime.InteropServices;
public class T618 {
  [DllImport("ntdll.dll")] public static extern int NtSetTimerResolution(uint D, bool S, out uint C);
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int Cls, IntPtr Info, int Len);
}
'@
$cur = 0; [T618]::NtSetTimerResolution(5000, $true, [ref]$cur) | Out-Null
"timer 0.5 ms held. Core is live — permanently. Leave this window open while you play."
$fib = @(1,1,2,3,5,8,13,21); $i = 0; $phase = 0.0
$abundance = $ramGB / $PHI
while ($true) {
  $tick = $fib[$i % $fib.Count]; $i++; $phase = ($phase + $GOLDEN) % 360
  $p = Get-Process Starfield
  $free = (Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory / 1MB
  if ($p) {
    if ($p.PriorityClass -ne 'AboveNormal') { $p.PriorityClass = 'AboveNormal' }
    if ($free -gt $abundance) {
      $buf = [Runtime.InteropServices.Marshal]::AllocHGlobal(4)
      [Runtime.InteropServices.Marshal]::WriteInt32($buf, 2)
      [T618]::NtSetSystemInformation(80, $buf, 4) | Out-Null
      [Runtime.InteropServices.Marshal]::FreeHGlobal($buf)
      "tick {0}s | phase {1:N3} | trimmed from abundance (free {2:N2} GB)" -f $tick, $phase, $free
    } else { "tick {0}s | phase {1:N3} | priority held | free {2:N2} GB | hands off memory" -f $tick, $phase, $free }
  } else { "tick {0}s | phase {1:N3} | waiting for Starfield..." -f $tick, $phase }
  Start-Sleep -Seconds $tick
}

'@
Set-Content -Path "$tools\phi-ton618-core.ps1" -Value $core -Encoding UTF8
Set-Content -Path "$tools\ton618.cmd" -Value '@powershell.exe -ExecutionPolicy Bypass -File "%USERPROFILE%\phi-tools\phi-ton618-core.ps1"' -Encoding ASCII
$userPath = [Environment]::GetEnvironmentVariable('Path', 'User')
if ($userPath -notlike "*$tools*") { [Environment]::SetEnvironmentVariable('Path', "$userPath;$tools", 'User'); "summon word registered: ton618" }
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\TON 618 CORE.lnk")
$lnk.TargetPath = 'powershell.exe'; $lnk.Arguments = "-ExecutionPolicy Bypass -File `"$tools\phi-ton618-core.ps1`""; $lnk.Save()
$act = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument "-ExecutionPolicy Bypass -WindowStyle Minimized -File `"$tools\phi-ton618-core.ps1`""
$trg = New-ScheduledTaskTrigger -AtLogOn -User $env:USERNAME
try { Register-ScheduledTask -TaskName 'TON618 CORE' -Action $act -Trigger $trg -RunLevel Highest -Force | Out-Null; "PERMANENT: TON 618 CORE rises at every logon" } catch { "logon task not registered (run installer as Admin) — summon word + icon still live" }
"TON 618 CORE v2 installed — HERS, permanent. Fresh Admin PowerShell, type:  ton618"
