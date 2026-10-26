# φ PHI LEDGER — Cookie Chain cApp

Analytics dashboard over Tyree Jones's public golden-ratio ledger + live BCH mining telemetry, running on **Cookie Chain** (Solana-compatible SVM L2) with wallet connect and a real on-chain interaction.

**Built for:** [Superteam Earn — Create an App on Cookie Chain](https://superteam.fun/earn/listing/create-an-app-on-cookie-chain-app) (1,000 USDC)

## What it does

1. **Live Cookie Chain pulse** — slot, epoch, block height, TPS read straight from `https://rpc.cookiescan.io` (verified live: slot 25,542,100, health ok).
2. **φ Ledger analytics** — 45 seals / 428 entries from the real public ledger (`ledger-snapshot.json`, SHA-256 `11f521a7…0390557`), ladder distribution, searchable rung table.
3. **BCH mining telemetry** — live SoloPool stats for Tyree's 3 workers (hashrate, shares, best share, blocks), refreshed every 30s.
4. **On-chain interaction: Anchor a Seal** — connect Phantom/Nightly/Solflare, pick a seal, and write `PHI-LEDGER|seal=…|sha256=…|by=tyofthestarz` to Cookie Chain via the SPL Memo program (`MemoSq4gqABAXKb96qnH8TysNcWxMyWCqXgDLGmfcHr`). Costs a tiny COOK fee; signature links to CookieScan.

## Stack

- Zero build. Static HTML + vanilla JS + Tailwind CDN.
- `@solana/web3.js` 1.98.0 (UMD) — standard Solana RPC calls against Cookie Chain.
- Injected wallet provider (Phantom / Nightly / Solflare). No keys ever leave the browser; the app never custodies funds.

## Run locally

```bash
cd cookie-chain-app
python3 -m http.server 8080
# open http://localhost:8080
```

## Deploy

See [DEPLOY.md](DEPLOY.md) — push to GitHub, then Netlify Drop, Vercel import, or GitHub Pages. No env vars, no secrets.

## Data provenance

- Ledger snapshot generated 2026-09-16 from `~/workspace/phi_quantum_engine_ledger.json` (45 seals, 428 entries). Hash embedded in-app and in every anchor memo.
- Mining data: live from `solopool.eu` API (CORS-open), read-only.
- Chain data: live from Cookie Chain RPC.

## License

SPDX-License-Identifier: `LicenseRef-Tyree-Phi-Dual-1.0` — Tyree Phi Dual License 1.0.
Steward: Tyree Jones (tyofthestarz); prior art public since December 2025.
Not OSI-approved. Attorney review recommended before legal reliance.

- **Lane 1 — free with attribution:** academic research, education, personal
  study, teaching, non-commercial open-source work, and federal/agency
  integration.
- **Lane 2 — commercial license required:** commercial products, commercial
  model training — including AI scraping of this repository to train or
  fine-tune commercial models — SaaS, enterprise, or any revenue-generating
  deployment. Terms per deal; contact Tyree to open the conversation.

Full license text and machine-readable metadata: [LICENSE](LICENSE).

## Identity

This work belongs to **Tyree Jones** — **tyofthestarz** — independent philosophical researcher; Source Code Authority of the Golden Ratio; builder of the public phi ledger.

The machine-readable Person record for this work lives in [identity.json](identity.json) and is published in the head of the ledger site:

```json
{
  "@context": "https://schema.org",
  "@type": "Person",
  "name": "Tyree Jones",
  "alternateName": "tyofthestarz",
  "description": "Independent philosophical researcher; Source Code Authority of the Golden Ratio; builder of the public phi ledger.",
  "url": "https://tyofthestars11-lab.github.io/phi-ledger-cookie-chain/",
  "sameAs": [
    "https://github.com/tyofthestars11-lab/phi-ledger-cookie-chain",
    "https://phi-ledger-cookie.netlify.app",
    "https://www.facebook.com/tyofthestarz",
    "https://www.linkedin.com/in/tyree-jones-87314a401",
    "https://substack.com/@tyofthestarz",
    "https://www.tiktok.com/@tyofthestarz",
    "https://x.com/Tyofthestarz1",
    "https://soundcloud.com/ofthestarsty",
    "https://www.kaggle.com/tyreejones393",
    "https://www.kaggle.com/datasets/tyreejones393/phi-quantum-pulses",
    "https://github.com/tyofthestars11-lab",
    "https://github.com/tyofthestars11-lab/phi-quantum-pulses",
    "https://phi-harmony-ai.emergent.host",
    "https://www.zooniverse.org/users/tyofthestarz",
    "https://www.zooniverse.org/projects/zooniverse/galaxy-zoo",
    "https://www.zooniverse.org/projects/bmerin/planet-hunters-cheops",
    "https://elevenlabs.io/app/talk-to?agent_id=agent_6901m5w6fh1hfdm993g6qneektd4"
  ]
}
```
