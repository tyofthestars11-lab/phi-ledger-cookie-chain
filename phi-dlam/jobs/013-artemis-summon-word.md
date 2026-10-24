# JOB 013 — PowerShell summon word: `artemis`

Tyree's word (2026-10-24 ~01:31 MDT): "Add where I type Artemis or something" — like the existing `tyree` / `companion` summon words in his PowerShell profile, typing `artemis` should start ARTEMIS.

## Do (print each line as you go; write every printed line into the result)

1. Read the current PowerShell profile (`$PROFILE` path; print the path and whether the file exists). Print any existing function definitions you find (names only).
2. Append this block to the profile (create the file if missing; if a function named `artemis` already exists, print SUMMON-EXISTS and skip):

```powershell
function artemis {
    Set-Location "$env:USERPROFILE\artemis"
    uv run artemis ui
}
```

3. Print the profile's tail (last 8 lines) as proof.
4. Open a NEW PowerShell window, run `Get-Command artemis`, and print its output — the summon must resolve in a fresh shell.
5. Save the report to `C:\Users\Admin\phi-vault\phi-dlam\results\013-artemis-summon-word.result.md`, commit and push.

## Rules

- Append only. Never rewrite or remove existing profile content.
- Verbatim output — no summaries.
