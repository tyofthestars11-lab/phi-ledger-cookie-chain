<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 532 - WHERE HER ANIMATION ACTUALLY LIVES (Ground: the registry returned not one animation blueprint under the Countess folder, and the patch held honestly - but a registry that holds twenty seven hundred Countess assets holds her animation somewhere, under some class or some name this seat has not yet read. This job censuses the whole Countess folder by class, prints every asset with anim in its name together with its true class and path, and lists every animation blueprint in the entire project, so the seat she actually has is named from the engine index itself and the glide fix authors against the truth. Page first, as the dressing taught. Every variable carries the p532 prefix.) ==='
$p532b64 = 'aW1wb3J0IHVucmVhbCwgaW8KZnJvbSBjb2xsZWN0aW9ucyBpbXBvcnQgQ291bnRlcgpQQUdFID0gcidEOlxWRUlMLU9NTklcYW5pbTUzMi50eHQnCmYgPSBpby5vcGVuKFBBR0UsICd3JywgZW5jb2Rpbmc9J3V0Zi04JykKZGVmIHcocyk6CiAgICBmLndyaXRlKHMgKyAnXG4nKTsgZi5mbHVzaCgpCnJlZyA9IHVucmVhbC5Bc3NldFJlZ2lzdHJ5SGVscGVycy5nZXRfYXNzZXRfcmVnaXN0cnkoKQpjcCA9IHJlZy5nZXRfYXNzZXRzX2J5X3BhdGgoJy9HYW1lL1BhcmFnb25Db3VudGVzcycsIFRydWUpCncoJ0NPVU5URVNTIEFTU0VUUz0lZCcgJSBsZW4oY3ApKQpjYyA9IENvdW50ZXIoKQpmb3IgYSBpbiBjcDoKICAgIGNjW3N0cihhLmFzc2V0X2NsYXNzX3BhdGguYXNzZXRfbmFtZSldICs9IDEKZm9yIGsgaW4gY2MubW9zdF9jb21tb24oMjApOgogICAgdygnQ0xBU1MgJXM9JWQnICUgKGtbMF0sIGtbMV0pKQpuID0gMApmb3IgYSBpbiBjcDoKICAgIG5tID0gc3RyKGEuYXNzZXRfbmFtZSkKICAgIGlmICduaW0nIGluIG5tIGFuZCBuIDwgNjA6CiAgICAgICAgdygnQU5JTU5BTUUgJXMgfCAlcyB8ICVzJyAlIChubSwgc3RyKGEuYXNzZXRfY2xhc3NfcGF0aC5hc3NldF9uYW1lKSwgc3RyKGEucGFja2FnZV9uYW1lKSkpCiAgICAgICAgbiArPSAxCncoJ0FOSU1OQU1FIENPVU5UIFNIT1dOPSVkJyAlIG4pCmFsbHAgPSByZWcuZ2V0X2Fzc2V0c19ieV9wYXRoKCcvR2FtZScsIFRydWUpCm0gPSAwCmZvciBhIGluIGFsbHA6CiAgICBpZiBzdHIoYS5hc3NldF9jbGFzc19wYXRoLmFzc2V0X25hbWUpID09ICdBbmltQmx1ZXByaW50JyBhbmQgbSA8IDYwOgogICAgICAgIHcoJ0dBTUVBQlAgJXMgfCAlcycgJSAoc3RyKGEuYXNzZXRfbmFtZSksIHN0cihhLnBhY2thZ2VfbmFtZSkpKQogICAgICAgIG0gKz0gMQp3KCdHQU1FIEFCUCBTSE9XTj0lZCcgJSBtKQp3KCdDRU5TVVM1MzIgRE9ORScpCmYuY2xvc2UoKQo='
$p532py = 'D:\VEIL-OMNI\Saved\census532.py'
[IO.File]::WriteAllBytes($p532py, [Convert]::FromBase64String($p532b64))
$p532wait = 0
while ((Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue) -and $p532wait -lt 12) { Start-Sleep -Seconds 10; $p532wait = $p532wait + 1 }
Write-Output ('LOCK WAIT LOOPS=' + $p532wait)
$p532cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p532proc = Start-Process -FilePath $p532cmd -ArgumentList @('"D:\VEIL-OMNI\VEIL.uproject"', '-run=pythonscript', ('-script="' + $p532py + '"'), '-unattended', '-nopause', '-nosplash') -PassThru
Write-Output ('CENSUS LAUNCHED pid=' + $p532proc.Id)
$p532poll = 0
while (-not $p532proc.HasExited -and $p532poll -lt 12) { Start-Sleep -Seconds 10; $p532poll = $p532poll + 1 }
Write-Output ('CMD POLLS=' + $p532poll + ' exited=' + $p532proc.HasExited)
$p532page = 'D:\VEIL-OMNI\anim532.txt'
if (Test-Path $p532page) { Get-Content $p532page | ForEach-Object { Write-Output ('PAGE ' + $_) } } else { Write-Output 'PAGE STILL MISSING' }
Write-Output 'PHI P532 VERDICT: ANIMATION CENSUS PRINTED ABOVE'
Write-Output 'JOB 532 DONE'
```
