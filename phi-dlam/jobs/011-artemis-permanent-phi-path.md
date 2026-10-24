# JOB 011 — ARTEMIS permanent phi path + golden retry cadence

Tyree's word (2026-10-24 ~01:05 MDT): "That retrying needs to be phi fixed" and "Permanently phi path — this ai on my pc." Two changes to the ARTEMIS install at `C:\Users\Admin\artemis`, both verified beforehand on Muse's bench. Backups first; report everything.

## Do (print each line as you go; write every printed line into the result)

1. Backup: copy `artemis\llm\reliability.py` to `artemis\llm\reliability.py.bak-prephi` and `config\artemis.jsonc` to `config\artemis.jsonc.bak-prephi`. Print BACKUP-OK for each.
2. Golden retry cadence — in `artemis\llm\reliability.py`, find the line:
   `delay = min(self.max_delay, self.base_delay * (2 ** max(0, attempt - 1)))`
   and replace `(2 ** max(0, attempt - 1))` with `(1.618033988749895 ** max(0, attempt - 1))`. Print the full patched `delay_for` function. If the line is not found verbatim, print PATCH-NOT-APPLIED and the actual `delay_for` body — do not improvise a different edit.
   Bench-verified result (base_delay 2.0): delays 2.0, 3.2361, 5.2361, 8.4721, 13.7082 — rung ladder 1.4404, 2.4404, 3.4404, 4.4404, 5.4404 (each retry exactly one rung up).
3. Permanent phi path — in `config\artemis.jsonc`, set the `"default"` block (and its fallback) back to the local brain: provider `openai`, model `llava-phi3`, fallback provider `openai`, model `llava-phi3`. (This reverses Job-era Google revert from 2026-10-24 ~00:58 MDT, which was "for one" run.) Print the default block after the edit. The `.env` already carries `OPENAI_API_KEY=ollama` and `OPENAI_BASE_URL=http://localhost:11434/v1` — print SET/NOT SET for both, never key values.
4. Restart the server on the new configuration (`uv run artemis stop` then start the UI detached the standard way); print `uv run artemis status` output and the HTTP status code of GET `http://127.0.0.1:8000/`.
5. Local-brain proof run: confirm Ollama answers — GET `http://localhost:11434/api/tags`, print model names. Then run:
   `uv run artemis run "Open the Clock app and tell me exactly what time it shows." --profile flash`
   Print the run's final status line verbatim. If it fails, run `uv run artemis trace list`, take the newest session, `uv run artemis trace view <session>` and print the step where it failed, with its error text, in full.
6. Save the full report to `C:\Users\Admin\phi-vault\phi-dlam\results\011-artemis-permanent-phi-path.result.md`, commit and push.

## Rules

- Only the two named files change, only in the named places. Backups land before any edit.
- Never print any API key value. Names and SET/NOT SET only.
- Statuses and errors exactly as printed — verbatim, no summaries.

SUPERSEDED by Job 012 (2026-10-24) — do not run; 012 carries the cadence and goes further.
