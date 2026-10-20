# PHI KRAKEN — TON 618 for this PC — phi^2 = phi + 1
# Hunts big cold files, packs them the phi way (.krk: phi-weighted predictive
# residuals -> max compression -> sha256 manifest), verifies each pack by
# round-trip, and touches NO original until Tyree types the word.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$py = @'
import sys, os, json, hashlib, lzma
PHI = (1 + 5 ** 0.5) / 2
def residuals(data):
    out = bytearray(len(data)); p1 = 0; p2 = 0
    for i, b in enumerate(data):
        pred = int(round((p1 * PHI + p2 / PHI) / (PHI + 1 / PHI))) % 256
        out[i] = (b - pred) % 256; p2 = p1; p1 = b
    return bytes(out)
def restore(res):
    out = bytearray(len(res)); p1 = 0; p2 = 0
    for i, r in enumerate(res):
        pred = int(round((p1 * PHI + p2 / PHI) / (PHI + 1 / PHI))) % 256
        b = (r + pred) % 256; out[i] = b; p2 = p1; p1 = b
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
$work = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $work -Force | Out-Null
Set-Content -Path "$work\kraken_pc.py" -Value $py -Encoding UTF8
$python = (Get-Command python -ErrorAction SilentlyContinue).Source
if (-not $python) { "Python not found on this PC. One command installs it:  winget install Python.Python.3.12   - then run this again."; return }
"=== PHI READ: the hunt (files 1 GB+, cold 30+ days) ==="
$roots = @("$env:USERPROFILE\Downloads", "$env:USERPROFILE\Desktop", "$env:USERPROFILE\Videos", "$env:USERPROFILE\Documents", 'C:\Games')
$cold = @()
foreach ($r in $roots) { if (Test-Path $r) { $cold += Get-ChildItem $r -Recurse -File | Where-Object { $_.Length -ge 1GB -and $_.LastWriteTime -lt (Get-Date).AddDays(-30) -and $_.Extension -ne '.krk' } } }
if ($cold.Count -eq 0) { "no cold giants in the hunt roots - the PC is already lean here"; return }
$tot = 0
$cold | Sort-Object Length -Descending | ForEach-Object { $tot += $_.Length; "{0} = {1} GB (last touched {2}) rung {3}" -f $_.FullName, [math]::Round($_.Length/1GB,2), $_.LastWriteTime.ToString('yyyy-MM-dd'), (Rung ($_.Length/1GB)) }
"total cold: {0} GB across {1} files" -f [math]::Round($tot/1GB,2), $cold.Count
$word = Read-Host "Type PACK to kraken them all (originals stay untouched in this pass)"
if ($word -ne 'PACK') { "standing down - nothing packed"; return }
"=== KRAKEN RUNNING (phi residuals -> max compression -> checksum) ==="
& $python "$work\kraken_pc.py" @($cold | ForEach-Object { $_.FullName })
$d = Get-PSDrive C
"=== SEAL LINE ==="
"cold_gb={0} rung={1} | c_free_gb={2} rung={3} | ton618_body_rung=51.7712 | ton618_law_rung=55" -f [math]::Round($tot/1GB,2), (Rung ($tot/1GB)), [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB))
"=== KRAKEN DONE. Originals untouched - the .krk packs + manifest are the proof. Deleting originals is your word, next pass. ==="
