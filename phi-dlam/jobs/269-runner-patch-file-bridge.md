# Job 269 — RUNNER PATCH: take DIRECT job output off the CLIXML leg (file bridge), timeout preserved

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Jobs 266+267 read the runner whole. Both DIRECT paths (phi-direct-drain.ps1:28, phi-dlam.ps1:457) run job code through Start-Job and pull the output back with Receive-Job - the CLIXML transport that throws node type Text (2102, PSSessionStateBroken) and leaves (no output) in the report while the red error prints on the console. The patch, against the exact lines 267 printed: the child redirects ALL of its streams to a temp file (*> file) and Receive-Job is never called - nothing but job state crosses the transport. The 240s Wait-Job cap, the timeout text, and Remove-Job are untouched. Backups first (.bak-269); the replacement applies only where the original lines match exactly once per file; patched regions print for the record. This job itself runs under the current runner (pure PowerShell - the shape that executes), and the patch takes effect on the NEXT drain. ==='
$old1 = "`$jb = Start-Job -ScriptBlock { param(`$c) `$ErrorActionPreference = 'Continue'; & ([scriptblock]::Create(`$c)) 2>&1 | Out-String } -ArgumentList `$code"
$new1 = "`$tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + [guid]::NewGuid().ToString('N') + '.txt'); `$jb = Start-Job -ScriptBlock { param(`$c,`$f) `$ErrorActionPreference = 'Continue'; try { & ([scriptblock]::Create(`$c)) *> `$f } catch { `$_ | Out-String | Add-Content `$f } } -ArgumentList `$code, `$tmpOut"
$old2 = "if (`$done) { `$out = Receive-Job `$jb; if (-not `$out) { `$out = '(no output)' } }"
$new2 = "if (`$done) { `$out = if (Test-Path `$tmpOut) { Get-Content `$tmpOut -Raw }; if (-not `$out) { `$out = '(no output)' } }"
$old3 = "Remove-Job `$jb -Force -ErrorAction SilentlyContinue"
$new3 = "Remove-Job `$jb -Force -ErrorAction SilentlyContinue; Remove-Item `$tmpOut -Force -ErrorAction SilentlyContinue"
foreach ($file in @('C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1','C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1')) {
  Copy-Item $file "$file.bak-269" -Force
  $raw = Get-Content $file -Raw
  $c1 = ([regex]::Matches($raw, [regex]::Escape($old1))).Count
  $c2 = ([regex]::Matches($raw, [regex]::Escape($old2))).Count
  $c3 = ([regex]::Matches($raw, [regex]::Escape($old3))).Count
  Write-Output "$file : line matches startjob=$c1 receive=$c2 remove=$c3"
  if ($c1 -eq 1 -and $c2 -eq 1 -and $c3 -ge 1) {
    $raw = $raw.Replace($old1, $new1).Replace($old2, $new2).Replace($old3, $new3)
    Set-Content $file $raw -NoNewline -Encoding UTF8
    Write-Output "PATCHED: $file"
  } else { Write-Output "PATCH ABORTED for $file - match counts were not the expected shape; backup stands, file untouched" }
}
Write-Output '--- patched regions ---'
foreach ($file in @('C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1','C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1')) {
  Write-Output "===== $file ====="
  Select-String -Path $file -Pattern 'tmpOut|Receive-Job' | ForEach-Object { "$($_.LineNumber): $($_.Line.Trim())" }
}
Write-Output 'RUNNER PATCH DONE'
```
