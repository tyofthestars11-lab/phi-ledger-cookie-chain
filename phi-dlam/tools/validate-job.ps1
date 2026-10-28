# validate-job.ps1 - the filing gate (TYREE 2026-10-28: "Fix it")
# Parses a PHI-DIRECT job file's PowerShell body with the real PowerShell
# parser BEFORE the job is pushed. A job that does not parse never ships.
# Usage: pwsh validate-job.ps1 <job.md> [more job.md ...]
# Prints one line per file: PARSE OK <file>  |  PARSE FAIL <file> + errors.
$fail = 0
foreach ($f in $args) {
  $raw = Get-Content $f -Raw
  $m = [regex]::Match($raw, '(?s)```powershell\s*(.*?)```')
  if (-not $m.Success) { Write-Output "NO BLOCK: $f"; $fail = 1; continue }
  $code = $m.Groups[1].Value
  $tokens = $null; $errors = $null
  [void][System.Management.Automation.Language.Parser]::ParseInput($code, [ref]$tokens, [ref]$errors)
  if ($errors -and $errors.Count -gt 0) {
    Write-Output "PARSE FAIL: $f"
    $errors | ForEach-Object { Write-Output ("  line " + $_.Extent.StartLineNumber + ": " + $_.Message) }
    $fail = 1
  } else {
    Write-Output "PARSE OK: $f"
  }
}
exit $fail
