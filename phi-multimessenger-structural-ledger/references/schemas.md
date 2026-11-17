# Input schemas and conventions

## Corpus JSON

Use either a list or an object with an `inscriptions` list:

```json
[{"id":"P1-A","tokens":["sign01","sign12","sign07"]}]
```

A variant map is a JSON object from observed token to canonical token:

```json
{"sign01.variantA":"sign01"}
```

## Neutrino residual JSONL

The real-time adapter emits one object per line. The corpus ledger consumes the `residual` fields:

```json
{"event_name":"IceCube-YYMMDDA","residual":{"continuous_residual_fuel":0.42,"phase_rad":1.2}}
```

Only ingest records with documented provenance. An empty stream is represented by omitting `--neutrino-jsonl`; do not synthesize a zero-event claim as an observation.

## Fibonacci modular convention

Use

`phi = (1 + sqrt(5))/2`, `D = sqrt(1 + phi**2)`.

In the `(1, tau)` basis:

`S = [[1, phi], [phi, -1]] / D`

`T = diag(1, exp(4*pi*i/5))`

For the braid representation use `R = diag(exp(-4*pi*i/5), exp(3*pi*i/5))`, `B1 = R`, and `B2 = F @ R @ F`, where

`F = [[1/phi, 1/sqrt(phi)], [1/sqrt(phi), -1/phi]]`.

These are convention-dependent mathematical matrices. Preserve the convention in every output and do not interpret them as direct measurements of physical anyons in radio or inscription data.
