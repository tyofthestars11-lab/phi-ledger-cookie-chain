# JOB 010 — Muse's eyes: ARTEMIS state read + Tailscale bridge check

Tyree's word (2026-10-24 ~00:49 MDT): "Your eyes man tell the systems or something" / "Go" / "Yes go." This job reads the ARTEMIS installation's real state (so Muse verifies the local-brain switch himself instead of by photo) and checks/lays the PC side of the Tailscale bridge. It changes nothing except, if Tailscale is entirely absent, attempting its standard install — and it reports exactly what it finds either way.

## Do (print each line as you go; write every printed line into the result)

1. ARTEMIS model configuration (the phi-path switch):
   - Read `C:\Users\Admin\artemis\config\artemis.jsonc`. Print the lines of the `"default"` block only: its `provider`, `model`, and the fallback `provider` + `model`.
   - Read `C:\Users\Admin\artemis\.env`. Print ONLY: whether `OPENAI_API_KEY` is set (SET / NOT SET — never any key value), the value of `OPENAI_BASE_URL` (a localhost address, safe to print), and whether `ARTEMIS_DEFAULT_MODEL` is present.
2. ARTEMIS server state:
   - In `C:\Users\Admin\artemis`: `uv run artemis status` — print its output.
   - Port check: whether anything is Listening on TCP 8000 (`Get-NetTCPConnection -LocalPort 8000 -State Listen`, print the owning process name).
   - HTTP read: GET `http://127.0.0.1:8000/` — print the status code only.
3. Ollama state:
   - `ollama list` — print the full table.
   - GET `http://localhost:11434/api/tags` — print the model names it returns.
4. Tailscale state (the bridge):
   - Installed check: Test-Path `C:\Program Files\Tailscale\tailscale.exe`; if present, print the Tailscale service Status and StartType, then run `tailscale status` and `tailscale ip` and print both outputs in full.
   - If NOT installed: download the official installer `https://pkgs.tailscale.com/stable/tailscale-setup-latest.msi` to `C:\Users\Admin\phi-vault\downloads\tailscale-setup-latest.msi` and attempt a quiet install (`msiexec /i <path> /quiet /norestart`). Print INSTALL-OK or the exact failure. Do NOT attempt sign-in — sign-in is Tyree's own browser act; if install succeeds, print TAILSCALE-INSTALLED-NEEDS-SIGNIN.
5. Save the full report to `C:\Users\Admin\phi-vault\phi-dlam\results\010-artemis-eyes-and-bridge.result.md`, commit and push.

## Rules

- ARTEMIS and Ollama sections are READ ONLY — change no setting, restart nothing.
- Never print any API key value, from any file, ever. Names and SET/NOT SET only.
- Numbers and statuses exactly as printed — same labels, same units.
- The only permitted change is the Tailscale installer in step 4, and only when Tailscale is entirely absent.
