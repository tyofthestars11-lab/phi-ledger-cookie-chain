<!-- PHI-DIRECT -->
# JOB 035 - VORTEX STAGING ADDRESS, WHOLE-TREE HUNT (DIRECT, read only)

Job 032's scoped search found "installPath" only inside vortex.log (a
log line about Fallout NV) - the real staging address for Starfield is
NOT in the state JSONs it searched. Vortex 2.9 may keep it in its
database stores (Local Storage leveldb, metadb). This job sweeps the
whole Roaming\Vortex tree - excluding downloads, game staging folders
and caches - for the staging strings in every file type, binaries
included, and prints file + window for each hit. Read only.

## STEP 1 - SWEEP FOR THE ADDRESS
```powershell
$root = "$env:APPDATA\Vortex"
$skip = '\\downloads\\|\\Cache\\|\\GPUCache\\|\\Code Cache\\|\\starfield\\mods\\|\\witcher3\\|\\falloutnv\\'
$hits = New-Object System.Collections.ArrayList
Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Length -lt 60MB -and $_.FullName -notmatch $skip } | ForEach-Object {
  $m = Select-String -Path $_.FullName -Pattern 'installPath|starfield\\mods|starfield/mods' -ErrorAction SilentlyContinue | Select-Object -First 2
  if ($m) { foreach ($x in $m) { [void]$hits.Add("$($_.FullName) :: $($x.Line.Trim().Substring(0, [Math]::Min(220, $x.Line.Trim().Length)))") } }
}
"WHOLE-TREE HITS: $($hits.Count)"
$hits | Select-Object -First 20 | ForEach-Object { $_ }
```
