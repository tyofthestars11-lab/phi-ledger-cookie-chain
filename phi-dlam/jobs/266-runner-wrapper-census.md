# Job 266 — Runner wrapper census: how DIRECT jobs are actually invoked (read-only)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The transport break (PSSessionStateBroken 2102, node type Text) sealed jobs 256, 257, 259, 260, 261 at about one second each, while pure-PowerShell jobs in the same drains executed whole. Before anyone patches the runner, this census READS it: list the phi-dlam folder on this machine and grep every script there for the invocation machinery - Invoke-Command, New-PSSession, Start-Job, Invoke-Expression, ScriptBlock - with file and line, so the patch (if one is written) is written against the runners real lines, never against a guess. Read-only: nothing here edits the runner. ==='
$root = 'C:\Users\Admin\phi-vault\phi-dlam'
Get-ChildItem $root -File -ErrorAction SilentlyContinue | Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize
Get-ChildItem 'C:\Users\Admin\phi-vault' -File -ErrorAction SilentlyContinue | Select-Object Name, Length | Format-Table -AutoSize
foreach ($f in (Get-ChildItem $root -Recurse -Include *.ps1,*.psm1,*.bat,*.cmd -ErrorAction SilentlyContinue)) {
  $hits = Select-String -Path $f.FullName -Pattern 'Invoke-Command|New-PSSession|Start-Job|Invoke-Expression|ScriptBlock|ComputerName' -ErrorAction SilentlyContinue
  foreach ($h in $hits) { Write-Output "$($f.FullName):$($h.LineNumber): $($h.Line.Trim())" }
}
Write-Output 'RUNNER WRAPPER CENSUS DONE'
```
