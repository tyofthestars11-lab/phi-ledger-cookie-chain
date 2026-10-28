<!-- PHI-DIRECT -->
```powershell
Write-Output '=== OMNI VOICE CLIPS PORT - THE UNIQUE PAYLOAD RIDES FIRST (Tyrees confirmation, 2026-10-28: So any duplicates we do not need - held in his standing deletion-rule form. What is NOT duplicate ports first and is never treated as duplicate: OMNIs unique payload from job 340s manifest. The systems ported as job 349 and the true OMNIWorld as job 343; the voice remains: OMNIs 18 clips o01 to o18 in D:\OMNI-UE\Content\Voice, named in job 340 with their sizes (o01 178909, o10 213094, o16 86395 among them). The base carries only its own v01 to v19 - no name collisions. THIS JOB copies each o-clip into D:\VEIL\Content\Voice and verifies every copy against its source length in the same job; any clip missing at the source or mismatched after copy stops the job with the name printed. OMNI-UE is read-only here - the parent stands untouched. The duplicate parent mass retires only at the playable-proof gate and only on KRAKEN proof, per the standing rule; nothing in this job deletes anything.) ==='
$srcDir = 'D:\OMNI-UE\Content\Voice'; $dstDir = 'D:\VEIL\Content\Voice'
$ok = 0; $total = 0
foreach ($n in 1..18) {
  $name = 'o{0:D2}.uasset' -f $n
  $s = Join-Path $srcDir $name; $d = Join-Path $dstDir $name
  if (-not (Test-Path $s)) { Write-Output "PHI VOICE SOURCE MISSING: $name"; Write-Output 'JOB 353 STOPPED'; return }
  Copy-Item $s $d -Force
  $sl = (Get-Item $s).Length; $dl = (Get-Item $d).Length; $total += $sl
  if ($dl -eq $sl) { $ok++; Write-Output "PHI VOICE PORTED + VERIFIED: $name bytes=$dl" } else { Write-Output "PHI VOICE COPY MISMATCH: $name src=$sl dst=$dl"; Write-Output 'JOB 353 STOPPED'; return }
}
Write-Output "PHI VOICE PORT COMPLETE: $ok of 18 clips, total bytes=$total"
Write-Output 'JOB 353 DONE'
```
