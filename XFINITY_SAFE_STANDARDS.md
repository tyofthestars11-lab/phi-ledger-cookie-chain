# Xfinity-Safe Standards — PHI LEDGER — Safety Matching, Not Site Change

φ-AUTHORITY LOCKED ∞ TYREE/φ = DIAMOND LOCK

Tyree's order, 2026-10-31: goal is to make sure safety systems flag the site as safe for anyone. Yes, he allows matching their standards, and Cloudflare etc., and surpassing naturally. That does NOT mean physically changing the site. This file is the standards record only. index.html is untouched by this file.

## Standards to match, and surpass

1. All resources https:// + wss:// only — no http:// fetch.
   - RPC: https://rpc.cookiescan.io
   - Explorer: https://cookiescan.io
   - Exception, not a fetch: XML namespace http://www.w3.org/2000/svg in a data-URI SVG — not a subresource, not fetched.
2. Enforce HTTPS ON in GitHub Pages, certificate Active, TLS 1.2+.
3. Content-Security-Policy: upgrade-insecure-requests; default-src 'self' https: wss: data: blob:; script-src 'self' 'unsafe-inline' https:; style-src 'self' 'unsafe-inline' https:; font-src https: data:; connect-src https: wss:; img-src https: data:; frame-ancestors 'none'; base-uri 'self'; form-action 'self'
4. X-Content-Type-Options: nosniff
5. Referrer-Policy: strict-origin-when-cross-origin
6. Permissions-Policy: camera=(), microphone=(), geolocation=()
7. Memo-only labeling, on the page, in plain text:
   Memo-only, no mining, no payment, SHA-256 hashed in browser never sent anywhere, Read-only telemetry, not banked BCH.
   - BCH Mining Telemetry is proof-of-work telemetry, read-only, not mining, not banked BCH.
   - Anchor flow is memo-only: no token transfer, no approval, no drainer instruction, only tiny COOK fee.
8. Main anchor flow, unchanged: Add & Connect → Anchor a Seal On-Chain → Anchor Yours. No side page. No version number, site is site.
9. φ constants, round-trip verified:
   φ = 1.618033988749895, φ² = 2.618033988749895 = φ+1, θ_φ = 137.5077640500378° = 360/φ², μ = 17.0324°, to_rung(x) = ln(x)/ln(φ), from_rung(r) = φ^r
   If it does not round-trip, it does not ship.

## Verification of the uploaded Xfinity-safe candidate, 2026-10-31, read whole

Candidate file 322, PHI_LEDGER_Xfinity_Safe_index.html, 71 lines, read whole:
- CSP upgrade-insecure-requests: present, line 6, full policy as above.
- X-Content-Type-Options nosniff: present, line 7.
- Referrer-Policy strict-origin-when-cross-origin: present, line 8.
- Memo-only / no mining / no payment / SHA-256 / Read-only: present, line 17 and footer line 68.
- φ constants: present, lines 21 and 68, all values above.
- https RPC: https://rpc.cookiescan.io present, lines 10, 26, 31.
- http:// hits: the string "http://rpc.cookiescan.io" appears once, in the sentence "No http://rpc.cookiescan.io anywhere" (line 26), plus the XML namespace http://www.w3.org/2000/svg noted in the fix card (line 60 in the candidate's Xfinity section, paraphrased here). That is NOT a fetched http:// subresource — it is a sentence about not using http, plus a namespace. A clean push version must still be checked for any actual http:// fetch before it ships; the sentence itself would trip a naive "http://rpc" grep to 1, not 0.
- Stale count inside candidate: Anchor card still says "369 seals, 3680 entries" while the header says "385 seals 3870 entries" — candidate is not a clean drop-in until that count is reconciled to the live ledger at push time. This file does not reconcile it, and does not push it.

Candidate file 321, phi_ledger_xfinity_safe_321, 19K, binary / not readable HTML in this workspace — NOT verified, NOT the 1619-line artifact named in the paste. The 1619-line /mnt/data artifact was not delivered in this chat. Do not claim it was read here.

## Current live site, checked 2026-10-31

- Restored index.html: 17,296 bytes, mtime 2026-10-31 17:52:23 MDT, untouched by this standards file.
- RPC already https, no http://rpc fetch in live index.html.
- Live index.html does NOT yet have CSP upgrade-insecure-requests meta — that is the gap this standard names, not a change made here.

## What this file does NOT do

- Does NOT replace index.html.
- Does NOT push a new site version.
- Does NOT tell Tyree to reset, clear HSTS, or change Xfinity himself.
- Does NOT claim Xfinity, Cloudflare, or any safety system has flagged the site safe — that flag is theirs, on their check, after a future push Tyree explicitly orders with "change it".

Ω SEALED φ-TRUE φ_XFINITY_SAFE_VERIFIED_TYREE_OMEGA — standards only, site untouched, read is anchor.
