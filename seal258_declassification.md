---
seal: 258
name: φ_MASSNET_DENOVO_TYREE_OMEGA
title: THE LIBRARY CEILING BREAKS AT SCALE — DE NOVO READING PAST EVERY DATABASE
declassified_by: TYREE — primary source
source: MassNet corpus + XuanjiNovo, Nature Methods (2026), DOI 10.1038/s41592-026-03247-y; PRIDE PXD071590
date: 2026-10-15
status: SEALED
---

# THE LIBRARY CEILING BREAKS AT SCALE

## CLAIM

A corpus of 1.54 billion tandem mass spectra — 648 projects, 35 species, 27,643 runs — re-searched by two engines into 548 million peptide-spectrum matches, and a reader, XuanjiNovo, that takes one spectrum and returns the full amino-acid sequence with no database consulted at inference. On data its training never contained (Orbitrap Astral human), peptide recall 0.45 against rivals at 0.32 and 0.26; on tomato, 0.25 against a rival field spanning 0.01 to 0.06. Trained at 30M, 65M, then 100M spectra, recall rose on every measured axis with no plateau at 100M.

The decoder carries a hard physical constraint: after drafting the whole sequence in parallel and refining it, a knapsack-style optimization selects the highest-scoring residue sequence whose summed mass fits the measured precursor mass. Scale plus a physical law inside the decoding — that is the demonstrated shape of reading past the library ceiling.

## LAW

The library ceiling is not a property of the spectrum. It is a property of the corpus. What cannot be matched can still be read — when the read is trained at scale and the physics is wired into the decoder rather than consulted afterward. This is the CASMI26 front's own wall, answered from the proteomics side: the test molecules in no database are invisible to matching and visible to a reader.

## ECHO — what is missing

1. **The object differs.** A peptide is a linear string over twenty letters with a regular fragment ladder; a small molecule is a branched, ringed graph with rearrangement-heavy fragmentation and true isomer ambiguity. The architecture and its alignment machinery do not transfer directly.
2. **The labels were library-born.** MassNet holds only spectra the search engines confidently identified; unidentified spectra are discarded, and no labeled small-molecule corpus exists at even one percent of this scale. CASMI26's novel molecules sit outside the labeled space by construction.
3. **Bounds stated by the source:** modifications beyond three common ones are unmodeled; performance on older-generation instruments is not competitive without fine-tuning; the widely quoted 38–144% improvement range appears in secondary coverage, not in the paper's text — the recalls beneath it are paper-verified.

## SEAL

Ω SEALED φ-TRUE φ_MASSNET_DENOVO_TYREE_OMEGA 💎

φ in front. TYREE — primary source.
