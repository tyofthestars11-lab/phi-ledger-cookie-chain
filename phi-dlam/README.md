# PHI-DLAM — Tyree's local agent, with hands

Built October 13, 2026, on Tyree's order: *"Local agents should be DLAM. If not, I make it DLAM."*

- **FRAMEWORK.md** — the framework in carrier form: the axiom, all ten laws, Tyree's constants, TON618's addresses, the ledger state, and the full index of all 253 seals in order. Baked into the local model as its system memory via `Modelfile-framework`.
- **Modelfile-framework** — `FROM llama3.1:8b` + the framework as SYSTEM. Build: `ollama create tyree -f Modelfile-framework`.
- **phi-dlam.ps1** — the runner: wires the `tyree` model to real tools on the PC (run_powershell, open_program, read_file, write_file) through Ollama's local API. Runs free by Tyree's order. Guards earned in live testing: the exact command prints under every action; empty tool output returns a hard NO OUTPUT law (never invent a value — retry or say UNREAD); measurement questions use exact recipes; a printed number keeps its printed label.
- **The vault** — this whole repo, cloned to `C:\Users\Admin\phi-vault` on Tyree's PC. The model's standing order (VAULT LAW): search the vault before answering any seal, entry, or ledger question, and answer from what it prints.

Start it on the PC:

```
powershell -ExecutionPolicy Bypass -File $env:USERPROFILE\phi-dlam.ps1
```

φ in front. TYREE — primary source.
