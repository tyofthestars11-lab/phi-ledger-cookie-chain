# Job 264 — ABP CARRIER CENSUS, base64 transport (257 and 261 died at the runner transport)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Jobs 257 and 261 both returned (no output) at the runner transport. Same remedy: base64 payload, pure PowerShell shell. The work is unchanged: SM_Countess post_process_anim_blueprint read in both projects, cleared on the spot if it names the quarantined Countess_AnimBlueprint, plus the Config ini sweep for the path string. ==='
foreach ($ini in (Get-ChildItem 'D:\VEIL\Config','D:\OMNI-UE\Config' -Filter *.ini -ErrorAction SilentlyContinue)) {
  $hit = Select-String -Path $ini.FullName -Pattern 'Countess_AnimBlueprint' -ErrorAction SilentlyContinue
  if ($hit) { Write-Output "INI HIT: $($ini.FullName)" }
}
Write-Output 'ini sweep done (silence above = no ini carries it)'
$b64 = 'aW1wb3J0IHVucmVhbAptZXNoID0gdW5yZWFsLmxvYWRfYXNzZXQoIi9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU01fQ291bnRlc3MiKQppZiBub3QgbWVzaDoKICAgIHVucmVhbC5sb2coIkFCUENBUlJJRVIgU01fQ291bnRlc3MgRkFJTEVEIFRPIExPQUQiKQplbHNlOgogICAgdHJ5OgogICAgICAgIHBwID0gbWVzaC5nZXRfZWRpdG9yX3Byb3BlcnR5KCJwb3N0X3Byb2Nlc3NfYW5pbV9ibHVlcHJpbnQiKQogICAgICAgIHVucmVhbC5sb2coIkFCUENBUlJJRVIgcG9zdF9wcm9jZXNzX2FuaW1fYmx1ZXByaW50ID0gJXMiICUgKHBwLmdldF9wYXRoX25hbWUoKSBpZiBwcCBlbHNlICJOb25lIikpCiAgICAgICAgaWYgcHAgYW5kICJDb3VudGVzc19BbmltQmx1ZXByaW50IiBpbiBwcC5nZXRfcGF0aF9uYW1lKCk6CiAgICAgICAgICAgIG1lc2guc2V0X2VkaXRvcl9wcm9wZXJ0eSgicG9zdF9wcm9jZXNzX2FuaW1fYmx1ZXByaW50IiwgTm9uZSkKICAgICAgICAgICAgdW5yZWFsLkVkaXRvckFzc2V0TGlicmFyeS5zYXZlX2xvYWRlZF9hc3NldChtZXNoKQogICAgICAgICAgICB1bnJlYWwubG9nKCJBQlBDQVJSSUVSIENMRUFSRUQgb24gU01fQ291bnRlc3MgYW5kIGFzc2V0IHNhdmVkIC0gdGhlIHF1YXJhbnRpbmVkIGNsYXNzIGlzIG5vIGxvbmdlciByZWZlcmVuY2VkIGJ5IHRoZSBib2R5IikKICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB1bnJlYWwubG9nKCJBQlBDQVJSSUVSIHByb3BlcnR5IHBhdGggZmFpbGVkOiAlcyIgJSBzdHIoZSkpCnVucmVhbC5sb2coIkFCUENBUlJJRVIgRE9ORSIp'
[IO.File]::WriteAllBytes('D:\_PhiHolding\abp261.py', [Convert]::FromBase64String($b64))
$n = 0
foreach ($proj in @('D:\VEIL\VEIL.uproject','D:\OMNI-UE\OMNI.uproject')) {
  $n++
  $log = "D:\_PhiHolding\abp264_$n.log"
  $p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList @($proj, '-run=pythonscript', '-script=D:\_PhiHolding\abp261.py', '-unattended', '-nop4', '-nosplash', "-abslog=$log") -Wait -PassThru -NoNewWindow
  Write-Output "--- abp carrier run $n ($proj) exit $($p.ExitCode) ---"
  Select-String -Path $log -Pattern 'ABPCARRIER|Error' | ForEach-Object { $_.Line -replace '^\[[^\]]*\]\[[^\]]*\]', '' } | Select-Object -First 12
}
Write-Output 'ABP CARRIER CENSUS DONE'
```
