<!-- PHI-DIRECT -->
```powershell
Write-Output '=== GATED STEP - KRAKEN ARCHIVE THE PARENTS (Tyrees decision, 2026-10-28, his words: Yeah - KRAKEN archive the parents. LOCKED TERMS: this job runs ONLY after the merged VEIL OMNI build is packaged, launched, and playable in Tyrees hands - and not before. The gate is a proof marker file the playable-proof step writes on Tyrees confirmation; no marker, no archive, this job prints GATE CLOSED and stops. At the gate: both parent projects - D:\OMNI-UE whole, and the VEIL parents pre-merge state as preserved in its backups and parent-era trees - go through the KRAKEN-TON618 pipeline as archive: phi-weighted residuals + zstd, checksums, manifests, round-trip verification printed in-job. The archive stands on D, out of sight (D:\VEIL-OMNI-ARCHIVE). The two parent desktop doors come down in the same motion and the single VEIL OMNI door stands. NO DELETION rides on the archive beyond the standing deletion rule: a parent file retires only where KRAKENs manifest proves every byte preserved and round-trip verified; anything unproven stands live. Until the gate, both parents stand live and untouched - they are the merged games source and fallback. RELEASE PATH: this file sits in jobs-held; at the playable proof, Muse finalizes the pack invocation against the PCs KRAKEN tooling read at that time and moves this job into the drain. Filed 2026-10-28 as the gated final step of the merge execution - triggered by the proof, never by a calendar.) ==='
$gate = 'D:\VEIL\Saved\phi-playable-proof.txt'
if (-not (Test-Path $gate)) { Write-Output 'GATE CLOSED: no playable-proof marker on disk. The parents stand live. Nothing archived, nothing deleted.'; Write-Output 'JOB 346 GATED - STOPPED AT THE GATE'; return }
Write-Output "GATE OPEN: proof marker present - $((Get-Item $gate).LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))"
foreach ($p in @('D:\VEIL','D:\OMNI-UE')) {
  if (Test-Path $p) { $s = (Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; Write-Output ("PHI ARCHIVE CENSUS: $p GB=" + [math]::Round($s / 1GB, 3)) }
}
Write-Output 'ARCHIVE BODY: pack invocation finalized at release against the PCs KRAKEN tooling; this gated copy carries the gate and the census only.'
Write-Output 'JOB 346 GATE READ DONE'
```
