# JOB 014 — Return ARTEMIS to Google, cut the stuck local-phone session, repair the summon

Tyree's word (2026-10-24 ~02:13-02:15 MDT): typing `artemis` in PowerShell "goes to the local phone and not the local ai artemis thing and wont respond at all — fix that." Then: "go back to google." The S26+ session is stuck ("like it's bricked"); the phone is a hand, not the brain. Google is the through-channel for this pass. This job supersedes the summon half of Job 013 (verify-only if 013 already landed).

## Do (print each line as you go; write every printed line into the result)

1. From `C:\Users\Admin\artemis`: `uv run artemis stop`. Then print any process still listening on port 8000 (Get-NetTCPConnection -LocalPort 8000) and stop it. Print PORT8000 CLEAR.
2. Cut the stuck phone session: with the SDK adb (`C:\Users\Admin\AppData\Local\Android\Sdk\platform-tools\adb.exe`) run `disconnect 10.0.0.118:46103` and `disconnect 10.0.0.118:41429` (either may already be gone — print output verbatim). Then print `adb devices`. Do NOT reconnect or drive the S26+ this pass.
3. Google channel check: print the `default` block of `config\artemis.jsonc`. It must read provider google, model gemini-3.8-flash, fallback google / gemini-3.7-flash. If it reads anything else (openai, llava-phi3), restore exactly that Google default + fallback, keeping the rest of the file intact. Print the block after.
4. `.env`: ensure a line `ARTEMIS_DEFAULT_MODEL=gemini-3.8-flash` exists. If a line pins `gemini-2.5-flash`, replace it — Google retired the 2.x models for new keys (404 "no longer available to new users"), so that pin is a dead road. Confirm GEMINI_API_KEY is present WITHOUT printing its value (print only `GEMINI_API_KEY: present`).
5. Summon repair: read the PowerShell `$PROFILE`. Ensure exactly ONE function named `artemis` exists, defined as: Set-Location "$env:USERPROFILE\artemis" then `uv run artemis ui`. Remove duplicate `artemis` function definitions if more than one exists. Print the function body found after repair.
6. Fresh-shell proof: open a new PowerShell, run `Get-Command artemis` (must show Function), then run `artemis`; if the port menu appears choose Restart server. Print the HTTP status of GET `http://127.0.0.1:8000/`. THE PORT LAW (Tyree, 2026-10-24 ~02:16 MDT): port 8000 belongs to the AI console on THIS PC — never the phone. After the restart, print the console's selected device: it must NOT be either S26+ endpoint (10.0.0.118:46103 / :41429). The phone blanking the console instead is the exact failure this job kills.
7. Run `uv run artemis doctor` and print it verbatim.
8. Save the full report to `C:\Users\Admin\phi-vault\phi-dlam\results\014-artemis-google-return.result.md`, commit and push.

## Rules

- Provider stays GOOGLE this pass. No provider change, no local-model switch.
- Never print any API key value.
- The S26+ stays disconnected this pass — Tyree's word controls when it returns.
- Verbatim statuses and outputs — no summaries.
