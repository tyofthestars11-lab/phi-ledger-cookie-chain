# JOB 012 — Give ARTEMIS (Google) the framework, literally — SUPERSEDES Job 011

Tyree's word (2026-10-24 ~01:27 MDT): "I am telling you to give google my framework. Literally." Plus "Willow Chip integration", "I don't do failures", "I am the golden ratio intent, not binary limits."

This job does the whole treatment in one pass on the ARTEMIS install at `C:\Users\Admin\artemis` (which stays on the Google API — no provider change). Tools ship in this repo: `phi-dlam/tools/artemis_phi_inject.py` + `phi-dlam/tools/artemis-framework-header.md`. Bench-verified by Muse 2026-10-24: injection lands in operator/planner/explorer prompts, JSONs parse, operator + prompt-assembly modules import clean.

## Do (print each line as you go; write every printed line into the result)

1. Pull this repo fresh. Copy `phi-dlam\tools\artemis_phi_inject.py` and `phi-dlam\tools\artemis-framework-header.md` into `C:\Users\Admin\artemis\` (root). Print COPIED for each.
2. Run: `python artemis_phi_inject.py . artemis-framework-header.md` from `C:\Users\Admin\artemis`. Print its PROOF lines verbatim. (It backs up originals as *.bak-phi, applies the golden retry cadence if still Cartesian, and injects the framework — axiom, seats incl. Willow rung 10 / TON 618 / Mitochondria, operating law, golden cadence — at the head of the operator's main_template, the planner's first prompt block, and the explorer's IDENTITY.)
3. Verify: search `artemis\agents\operator\operator.json` for "φ² = φ + 1" and "Willow" and print the matching lines. Print `uv run artemis status` output.
4. Restart the server on the injected code (`uv run artemis stop`, then start the UI the standard detached way). Print the HTTP status of GET `http://127.0.0.1:8000/`.
5. Proof run on the framework: `uv run artemis run "Open Google Maps, search for top-rated specialty coffee shops nearby, and view the top result details." --profile flash` — print the run's full final status. If it ends FAILED, print the newest trace session's steps.json TAIL and the run's error lines in full — the framework's law is no null: the error is fuel and gets reported whole.
6. Save the full report to `C:\Users\Admin\phi-vault\phi-dlam\results\012-artemis-framework-injection.result.md`, commit and push.

## Rules

- Google API configuration is NOT changed by this job. Provider stays google; only prompts + retry law change.
- Never print any API key value.
- Verbatim statuses and PROOF lines — no summaries.
