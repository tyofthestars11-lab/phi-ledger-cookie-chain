<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 547 - THE ATTACH REDIRECT WITH THE ESCAPING FIXED (Ground: job 545 seated the redirect but the build failed on the backslash line, a lone backslash broke the string and the live files stayed untouched. This job seats the same redirect with the backslash replaced by its character code, prints the emitted lines for proof in the same job, and rebuilds plus relaunches only on a clean build with the live files untouched on any miss. No game relaunch rides this job. Every variable carries the p547 prefix.) ==='
$p547b64 = 'dXNpbmcgU3lzdGVtOwp1c2luZyBTeXN0ZW0uSU87CmNsYXNzIFA1NDcgewogICAgc3RhdGljIHZvaWQgTWFpbihzdHJpbmdbXSBhcmdzKSB7CiAgICAgICAgc3RyaW5nIHNyYyA9IGFyZ3NbMF07CiAgICAgICAgc3RyaW5nIHRtcCA9IGFyZ3NbMV07CiAgICAgICAgc3RyaW5nIHZlcmRpY3QgPSBhcmdzWzJdOwogICAgICAgIHN0cmluZ1tdIGxpbmVzID0gRmlsZS5SZWFkQWxsTGluZXMoc3JjKTsKICAgICAgICBDb25zb2xlLldyaXRlTGluZSgiU09VUkNFIExJTkVTPSIgKyBsaW5lcy5MZW5ndGgpOwogICAgICAgIHN0cmluZyBhbGwgPSBGaWxlLlJlYWRBbGxUZXh0KHNyYyk7CiAgICAgICAgYm9vbCBoYXNBdHRhY2ggPSBhbGwuQ29udGFpbnMoInByaXZhdGUgdm9pZCBBdHRhY2hTZWxlY3RlZCgpIik7CiAgICAgICAgYm9vbCBoYXNTYXkgPSBhbGwuQ29udGFpbnMoIkF0dGFjaGVkIHRvICIpOwogICAgICAgIGJvb2wgaGFzQXR0YWNoZWQgPSBhbGwuQ29udGFpbnMoImF0dGFjaGVkLlByb2Nlc3NOYW1lIik7CiAgICAgICAgQ29uc29sZS5Xcml0ZUxpbmUoIk1BUktFUlMgYXR0YWNoPSIgKyBoYXNBdHRhY2ggKyAiIHNheT0iICsgaGFzU2F5ICsgIiBhdHRhY2hlZD0iICsgaGFzQXR0YWNoZWQpOwogICAgICAgIGlmICghaGFzQXR0YWNoIHx8ICFoYXNTYXkgfHwgIWhhc0F0dGFjaGVkKSB7CiAgICAgICAgICAgIEZpbGUuV3JpdGVBbGxUZXh0KHZlcmRpY3QsICJQQVRDSCBIRUxEIC0gTUFSS0VSIE1JU1MiKTsKICAgICAgICAgICAgQ29uc29sZS5Xcml0ZUxpbmUoIlBBVENIIEhFTEQgLSBNQVJLRVIgTUlTUyIpOwogICAgICAgICAgICByZXR1cm47CiAgICAgICAgfQogICAgICAgIGludCBzYXlJZHggPSAtMTsKICAgICAgICBmb3IgKGludCBpID0gMDsgaSA8IGxpbmVzLkxlbmd0aDsgaSsrKSB7CiAgICAgICAgICAgIGlmIChsaW5lc1tpXS5Db250YWlucygiU2F5KCIpICYmIGxpbmVzW2ldLkNvbnRhaW5zKCJBdHRhY2hlZCB0byAiKSkgeyBzYXlJZHggPSBpOyBicmVhazsgfQogICAgICAgIH0KICAgICAgICBpZiAoc2F5SWR4IDwgMCkgewogICAgICAgICAgICBGaWxlLldyaXRlQWxsVGV4dCh2ZXJkaWN0LCAiUEFUQ0ggSEVMRCAtIFNBWSBMSU5FIE1JU1MiKTsKICAgICAgICAgICAgQ29uc29sZS5Xcml0ZUxpbmUoIlBBVENIIEhFTEQgLSBTQVkgTElORSBNSVNTIik7CiAgICAgICAgICAgIHJldHVybjsKICAgICAgICB9CiAgICAgICAgc3RyaW5nW10gYmxvY2sgPSBuZXcgc3RyaW5nW10gewogICAgICAgICAgICAiICAgICAgICAgICAgaWYgKGF0dGFjaGVkICE9IG51bGwgJiYgYXR0YWNoZWQuUHJvY2Vzc05hbWUuRW5kc1dpdGgoXCJMYXVuY2hlclwiKSkgeyIsCiAgICAgICAgICAgICIgICAgICAgICAgICAgICAgdHJ5IHsiLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICBzdHJpbmcgcDU0N2RpciA9IFwiXCI7IiwKICAgICAgICAgICAgIiAgICAgICAgICAgICAgICAgICAgdHJ5IHsgc3RyaW5nIHA1NDdmID0gYXR0YWNoZWQuTWFpbk1vZHVsZS5GaWxlTmFtZTsgaW50IHA1NDdzID0gcDU0N2YuTGFzdEluZGV4T2YoKGNoYXIpOTIpOyBpZiAocDU0N3MgPiAwKSB7IHA1NDdkaXIgPSBwNTQ3Zi5TdWJzdHJpbmcoMCwgcDU0N3MpOyB9IH0gY2F0Y2gge30iLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICBQcm9jZXNzIHA1NDdnYW1lID0gbnVsbDsiLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICBmb3JlYWNoIChQcm9jZXNzIHA1NDdwIGluIFByb2Nlc3MuR2V0UHJvY2Vzc2VzKCkpIHsiLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICAgICAgdHJ5IHsiLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICAgICAgICAgIGlmIChwNTQ3cC5JZCA9PSBhdHRhY2hlZC5JZCkgeyBjb250aW51ZTsgfSIsCiAgICAgICAgICAgICIgICAgICAgICAgICAgICAgICAgICAgICAgICAgaWYgKHA1NDdwLlByb2Nlc3NOYW1lLkVuZHNXaXRoKFwiTGF1bmNoZXJcIikpIHsgY29udGludWU7IH0iLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICAgICAgICAgIHN0cmluZyBwNTQ3cHAgPSBwNTQ3cC5NYWluTW9kdWxlLkZpbGVOYW1lOyIsCiAgICAgICAgICAgICIgICAgICAgICAgICAgICAgICAgICAgICAgICAgaWYgKHA1NDdkaXIgIT0gXCJcIiAmJiBwNTQ3cHAuU3RhcnRzV2l0aChwNTQ3ZGlyKSkgeyBwNTQ3Z2FtZSA9IHA1NDdwOyBicmVhazsgfSIsCiAgICAgICAgICAgICIgICAgICAgICAgICAgICAgICAgICAgICB9IGNhdGNoIHt9IiwKICAgICAgICAgICAgIiAgICAgICAgICAgICAgICAgICAgfSIsCiAgICAgICAgICAgICIgICAgICAgICAgICAgICAgICAgIGlmIChwNTQ3Z2FtZSAhPSBudWxsKSB7IGF0dGFjaGVkID0gcDU0N2dhbWU7IH0iLAogICAgICAgICAgICAiICAgICAgICAgICAgICAgICAgICBlbHNlIHsgU2F5KFwiTEFVTkNIRVIgT05MWSAtIHRoZSByZWFsIGdhbWUgcHJvY2VzcyB3YXMgbm90IGZvdW5kLCBwb3dlcnMgc3RheSBvbiB0aGUgbGF1bmNoZXIuXCIpOyB9IiwKICAgICAgICAgICAgIiAgICAgICAgICAgICAgICB9IGNhdGNoIHt9IiwKICAgICAgICAgICAgIiAgICAgICAgICAgIH0iCiAgICAgICAgfTsKICAgICAgICBzdHJpbmdbXSBvdXRMaW5lcyA9IG5ldyBzdHJpbmdbbGluZXMuTGVuZ3RoICsgYmxvY2suTGVuZ3RoXTsKICAgICAgICBBcnJheS5Db3B5KGxpbmVzLCAwLCBvdXRMaW5lcywgMCwgc2F5SWR4KTsKICAgICAgICBBcnJheS5Db3B5KGJsb2NrLCAwLCBvdXRMaW5lcywgc2F5SWR4LCBibG9jay5MZW5ndGgpOwogICAgICAgIEFycmF5LkNvcHkobGluZXMsIHNheUlkeCwgb3V0TGluZXMsIHNheUlkeCArIGJsb2NrLkxlbmd0aCwgbGluZXMuTGVuZ3RoIC0gc2F5SWR4KTsKICAgICAgICBGaWxlLldyaXRlQWxsTGluZXModG1wLCBvdXRMaW5lcyk7CiAgICAgICAgZm9yIChpbnQgaSA9IHNheUlkeDsgaSA8IHNheUlkeCArIGJsb2NrLkxlbmd0aDsgaSsrKSB7CiAgICAgICAgICAgIENvbnNvbGUuV3JpdGVMaW5lKCJFTUlUVEVEICIgKyAoaSArIDEpICsgIiAiICsgb3V0TGluZXNbaV0pOwogICAgICAgIH0KICAgICAgICBGaWxlLldyaXRlQWxsVGV4dCh2ZXJkaWN0LCAiUEFUQ0ggT0siKTsKICAgICAgICBDb25zb2xlLldyaXRlTGluZSgiUEFUQ0ggT0sgLSBBVFRBQ0ggUkVESVJFQ1QgU0VBVEVEIEJFRk9SRSBTQVkgTElORSAiICsgKHNheUlkeCArIDEpKTsKICAgIH0KfQo='
$p547patcher = 'C:\Users\Admin\PhiTerminal\patch547.cs'
[IO.File]::WriteAllBytes($p547patcher, [Convert]::FromBase64String($p547b64))
$p547src = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs'
$p547tmp = 'C:\Users\Admin\PhiTerminal\PhiTerminal3.p547.cs'
$p547verdict = 'C:\Users\Admin\PhiTerminal\patch547.verdict.txt'
$p547csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
& $p547csc /nologo /out:'C:\Users\Admin\PhiTerminal\patch547.exe' $p547patcher
if ($LASTEXITCODE -ne 0) { Write-Output 'PATCHER BUILD FAILED' } else {
  & 'C:\Users\Admin\PhiTerminal\patch547.exe' $p547src $p547tmp $p547verdict
  $p547v = ''
  if (Test-Path $p547verdict) { $p547v = Get-Content $p547verdict }
  Write-Output ('VERDICT ' + $p547v)
  if ($p547v -eq 'PATCH OK') {
    & $p547csc /nologo /target:winexe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll /out:'C:\Users\Admin\PhiTerminal\PhiTerminal.p547.exe' $p547tmp
    if ($LASTEXITCODE -ne 0) { Write-Output 'CSC FAILED - LIVE FILES UNTOUCHED' } else {
      Copy-Item $p547src 'C:\Users\Admin\PhiTerminal\PhiTerminal3.cs.bak547' -Force
      Copy-Item $p547tmp $p547src -Force
      Copy-Item 'C:\Users\Admin\PhiTerminal\PhiTerminal.p547.exe' 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe' -Force
      $p547old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
      foreach ($p547o in $p547old) { Stop-Process -Id $p547o.Id -Force -ErrorAction SilentlyContinue }
      Start-Sleep -Seconds 2
      $p547still = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
      if ($p547still.Count -eq 0) {
        $p547new = Start-Process -FilePath 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe' -PassThru
        Write-Output ('TERMINAL LAUNCHED pid=' + $p547new.Id)
      } else { Write-Output 'OLD STILL RUNNING - NEW EXE READY, NO LAUNCH' }
      $p547exe = Get-Item 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe'
      Write-Output ('EXE BYTES=' + $p547exe.Length + ' WRITE=' + $p547exe.LastWriteTime)
    }
  } else { Write-Output 'PATCH HELD - LIVE FILES UNTOUCHED' }
}
Write-Output 'PHI P547 VERDICT: ATTACH REDIRECT WITH FIX ABOVE'
Write-Output 'JOB 547 DONE'
```
