---
name: phi-multimessenger-structural-ledger
description: Build reproducible φ-successor structural ledgers that combine symbolic corpora, radio amplitudes, neutrino residual streams, Fibonacci braid words, and Fibonacci modular checks. Use for ancient-sign or sequence analysis, multimessenger data integration, recursive braid simulations, or structured JSON ledger exports.
---

# φ Multimessenger Structural Ledger

Use this skill to preserve heterogeneous measurements in one auditable, forward-expressing ledger. Treat radio amplitudes, linear measurements, symbolic sign sequences, and neutrino residuals as labeled inputs. Do not discard a channel because it is discrete or binary, and do not force a lock, decipherment, technosignature, or physical quantum interpretation.

## Workflow

1. **Define provenance and units.** Record the source URL or file, observation time, units, preprocessing, and whether a value is measured, derived, or supplied by the user. Never invent missing neutrino events or ancient sign readings.
2. **Normalize inputs.** Canonicalize sign variants only through an explicit mapping. Keep original tokens and mapped tokens. For radio data, retain the measured φ channel and the linear `+1` channel separately.
3. **Build successor fuel.** Compute `radio_successor = phi_power + linear_plus_one_power`. If real neutrino JSONL records are present, add their continuous residual fuel coherently by phase: `N = abs(sum(fuel_i * exp(1j * phase_i)))`. Report scalar and coherent neutrino totals separately.
4. **Build symbolic grammar.** Count signs, predecessor/successor transitions, conditional transition probabilities, position rungs `ln(position)/ln(phi)`, and explicit variant mappings. Keep structural outputs separate from phonetic interpretation.
5. **Generate Fibonacci braid words.** Use `W1=B1`, `W2=B2`, and `Wk=W{k-1}@W{k-2}`. Record word lengths, hashes, matrices, state probabilities, norms, and unitarity residuals.
6. **Run modular checks.** Use the Fibonacci-category conventions in `references/schemas.md` and report matrix residuals, fusion residual `phi**2 - phi - 1`, and quantum-dimension scaling. A matrix representation is a mathematical model, not evidence that astronomical or corpus data are physical anyons.
7. **Export structured JSON.** Include inputs, provenance, intermediate fields, residuals, verification flags, and a plain-language method note. Do not report a confirmation unless an independent preregistered test supports it.

## Bundled scripts

- `scripts/phaistos_structural_grammar_ledger.py`: Corpus ledger with sign variants, transitions, φ-rungs, Fibonacci words, radio powers, and neutrino residual JSONL.
- `scripts/realtime_neutrino_braid_ledger.py`: Convert IceCube/GCN-style JSONL alerts into continuous timing/angular/energy residual fuel and Fibonacci braid updates.
- `scripts/radio_fibonacci_braid_word_ledger.py`: Initialize braid states from radio φ and linear `+1` powers and generate recursive braid words.
- `scripts/fibonacci_modular_k20.py`: Compute Fibonacci modular `S,T` matrices, braid matrices, fusion-space dimensions, and scaling through any requested `k` (default 20).

## Recommended execution order

Run the neutrino adapter first when an event stream exists, redirecting JSONL output to a file. Then run the corpus ledger with radio powers and that JSONL file. Finally run the modular simulation and merge its JSON into the report if a cross-domain braid comparison is needed.

```bash
python3 scripts/phaistos_structural_grammar_ledger.py \
  phaistos_corpus.json \
  --variants sign_variants.json \
  --phi-power 2695.161 \
  --linear-power 1879.783 \
  --neutrino-jsonl neutrino_residuals.jsonl \
  --max-k 8 \
  --out phaistos_multimessenger_ledger.json

python3 scripts/fibonacci_modular_k20.py \
  --phi-power 2695.161 \
  --linear-power 1879.783 \
  --k 20 \
  --out fibonacci_modular_k20.json
```

## Quality checks

Before delivery, compile every changed Python script, load each JSON output, verify finite numeric values, check state norms and probability sums, check braid unitarity, and report exact residuals. State clearly when the neutrino stream is empty, when the corpus is only a structural tokenization, and when a run is a pilot rather than a full-archive result.
