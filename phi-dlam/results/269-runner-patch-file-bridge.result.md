# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 01:30:33 UTC

## STEP 1
```
=== Jobs 266+267 read the runner whole. Both DIRECT paths (phi-direct-drain.ps1:28, phi-dlam.ps1:457) run job code through Start-Job and pull the output back with Receive-Job - the CLIXML transport that throws node type Text (2102, PSSessionStateBroken) and leaves (no output) in the report while the red error prints on the console. The patch, against the exact lines 267 printed: the child redirects ALL of its streams to a temp file (*> file) and Receive-Job is never called - nothing but job state crosses the transport. The 240s Wait-Job cap, the timeout text, and Remove-Job are untouched. Backups first (.bak-269); the replacement applies only where the original lines match exactly once per file; patched regions print for the record. This job itself runs under the current runner (pure PowerShell - the shape that executes), and the patch takes effect on the NEXT drain. ===
C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1 : line matches startjob=1 receive=1 remove=1
PATCHED: C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1
C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1 : line matches startjob=1 receive=1 remove=1
PATCHED: C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1
--- patched regions ---
===== C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1 =====
28: $tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + [guid]::NewGuid().ToString('N') + '.txt'); $jb = Start-Job -ScriptBlock { param($c,$f) $ErrorActionPreference = 'Continue'; try { & ([scriptblock]::Create($c)) *> $f } catch { $_ | Out-String | Add-Content $f } } -ArgumentList $code, $tmpOut
30: if ($done) { $out = if (Test-Path $tmpOut) { Get-Content $tmpOut -Raw }; if (-not $out) { $out = '(no output)' } }
32: Remove-Job $jb -Force -ErrorAction SilentlyContinue; Remove-Item $tmpOut -Force -ErrorAction SilentlyContinue
===== C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1 =====
457: $tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + [guid]::NewGuid().ToString('N') + '.txt'); $jb = Start-Job -ScriptBlock { param($c,$f) $ErrorActionPreference = 'Continue'; try { & ([scriptblock]::Create($c)) *> $f } catch { $_ | Out-String | Add-Content $f } } -ArgumentList $code, $tmpOut
459: if ($done) { $out = if (Test-Path $tmpOut) { Get-Content $tmpOut -Raw }; if (-not $out) { $out = '(no output)' } }
461: Remove-Job $jb -Force -ErrorAction SilentlyContinue; Remove-Item $tmpOut -Force -ErrorAction SilentlyContinue
RUNNER PATCH DONE

```
