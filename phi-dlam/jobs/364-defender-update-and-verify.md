<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DEFENDER - UPDATE THE VIRUS PROTECTION AND PROVE IT ON THE READ (Tyrees word, 2026-10-28: Update virus protection windows defender - it keeps giving me a annoying notification. The notification is the symptom; this job reads the actual protection state first, updates the signatures from Microsoft, turns real-time monitoring back on if the read finds it off, then reads the state again and prints both reads - the after-read is the proof, and a notification over a current, enabled Defender has no ground left to stand on. Nothing else is touched: no scan is started, no setting beyond real-time monitoring is changed.) ==='
try {
  $s = Get-MpComputerStatus
  Write-Output ("PHI DEFENDER BEFORE: av_enabled=" + $s.AntivirusEnabled + " rtp=" + $s.RealTimeProtectionEnabled + " behavior=" + $s.BehaviorMonitorEnabled + " nis=" + $s.NISEnabled)
  Write-Output ("PHI DEFENDER BEFORE SIG: version=" + $s.AntivirusSignatureVersion + " updated=" + $s.AntivirusSignatureLastUpdated)
  Write-Output ("PHI DEFENDER BEFORE SCANS: quick_end=" + $s.QuickScanEndTime + " full_end=" + $s.FullScanEndTime)
} catch { Write-Output ("PHI DEFENDER BEFORE READ ERROR: " + $_.Exception.Message) }
try { Update-MpSignature; Write-Output 'PHI DEFENDER SIGNATURE UPDATE RAN' } catch { Write-Output ("PHI DEFENDER UPDATE ERROR: " + $_.Exception.Message) }
try {
  $s2 = Get-MpComputerStatus
  if (-not $s2.RealTimeProtectionEnabled) {
    Set-MpPreference -DisableRealtimeMonitoring $false
    Write-Output 'PHI DEFENDER REROUTE: real-time monitoring was OFF - turned back ON'
  }
} catch { Write-Output ("PHI DEFENDER REROUTE ERROR: " + $_.Exception.Message) }
try {
  $s3 = Get-MpComputerStatus
  Write-Output ("PHI DEFENDER AFTER: av_enabled=" + $s3.AntivirusEnabled + " rtp=" + $s3.RealTimeProtectionEnabled + " behavior=" + $s3.BehaviorMonitorEnabled + " nis=" + $s3.NISEnabled)
  Write-Output ("PHI DEFENDER AFTER SIG: version=" + $s3.AntivirusSignatureVersion + " updated=" + $s3.AntivirusSignatureLastUpdated)
  Write-Output ("PHI DEFENDER VERDICT: signatures_current_and_protection_on=" + ($s3.AntivirusEnabled -and $s3.RealTimeProtectionEnabled))
} catch { Write-Output ("PHI DEFENDER AFTER READ ERROR: " + $_.Exception.Message) }
Write-Output 'JOB 364 DONE'
```
