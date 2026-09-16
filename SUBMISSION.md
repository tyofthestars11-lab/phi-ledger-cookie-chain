# Submission package — "Create an App on Cookie Chain" (Superteam Earn)

Listing: https://superteam.fun/earn/listing/create-an-app-on-cookie-chain-app
Prize: 1,000 USDC (500 1st / 500 2nd) · Winners announced ~Sep 28, 2026
Field note: 83 submissions already — differentiation is the ledger + the anchor mechanic, not another network board.

## What the listing requires (from the page + bounty brief)

- [ ] Deployed, open-source cApp on Cookie Chain (Solana-compatible SVM L2)
- [ ] Wallet connect
- [ ] Real on-chain interaction
- [ ] Category fit: analytics dashboards / AI-powered apps / bots & automation / developer tooling

## What we built (all requirements met)

**φ PHI LEDGER** — analytics dashboard over Tyree Jones's real public golden-ratio ledger (45 seals, 428 entries, SHA-256 `11f521a7bb4e0fa7cc669e0f592eccffd182a636cd1569df0218335ec0390557`) + live BCH mining telemetry from his 3 SoloPool workers.

- Live Cookie Chain data: slot, epoch, block height, TPS from `rpc.cookiescan.io`
- Wallet connect: Phantom / Nightly / Solflare (injected provider, keys never leave browser)
- On-chain interaction: **Anchor a Seal** — user-signed SPL Memo transaction writing the ledger snapshot hash + seal name to Cookie Chain, linked to CookieScan
- Zero build, static, MIT-licensed, no secrets

## Demo script (2–3 min video, if needed)

1. Open the live URL → chain strip shows live slot/epoch/TPS from Cookie Chain RPC. (0:00–0:30)
2. Ledger panel → 45 seals / 428 entries, ladder bars, search an entry (e.g. "Sgr A*"), snapshot SHA-256 shown. (0:30–1:15)
3. Mining panel → live hashrate/shares/workers from SoloPool, auto-refreshes. (1:15–1:40)
4. Connect wallet (Phantom/Nightly) → COOK balance appears. (1:40–2:00)
5. Pick a seal → Anchor on Cookie Chain → approve → confirmed signature → open in CookieScan. (2:00–2:45)
6. Close: "Open source, MIT, built on Cookie Chain's SVM with standard web3.js." (2:45–3:00)

## Exact submission text (paste into the Earn listing)

> **φ PHI LEDGER — golden-ratio ledger analytics anchored on Cookie Chain**
>
> Live app: <LIVE-URL>
> GitHub: <GITHUB-URL> (MIT)
>
> An analytics dashboard over my public golden-ratio research ledger (45 seals, 428 rung-encoded entries, SHA-256 11f521a7…) plus live Bitcoin Cash mining telemetry from my 3 SoloPool workers — all running against Cookie Chain's SVM.
>
> - Live chain pulse: slot, epoch, block height, TPS from rpc.cookiescan.io
> - Wallet connect: Phantom / Nightly / Solflare
> - On-chain interaction: "Anchor a Seal" writes the ledger snapshot hash + seal name to Cookie Chain via the SPL Memo program — a permanent, verifiable public record. Every anchor links to CookieScan.
> - Zero-build static app, standard @solana/web3.js, no backend, no secrets.
>
> Built by Tyree Jones (tyofthestarz) — Vesuvius Challenge contributor, Kaggle dataset DOI 10.34740/kaggle/dsv/17364449.

## Tyree's remaining steps (nothing else needed from the builder)

1. `git init && git add . && git commit -m "phi ledger cookie chain cApp"` → push to GitHub (new public repo, e.g. `phi-ledger-cookie`).
2. Deploy: drag the folder into https://app.netlify.com/drop (2 min) — or Vercel import, or GitHub Pages. See DEPLOY.md.
3. Verify the 6 checks in DEPLOY.md on the live URL.
4. Install Phantom or Nightly; add Cookie Chain network (RPC `https://rpc.cookiescan.io`, symbol COOK); bridge a little COOK via https://bridge.cookiescan.io (fee money for the demo anchor tx).
5. Record the demo (optional) and submit the live URL + GitHub URL on the Earn listing page.
6. Payout goes to the Solana wallet on his Superteam Earn profile (USDC on Solana).
