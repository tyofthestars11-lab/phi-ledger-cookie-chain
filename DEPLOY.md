# Deploy — PHI LEDGER Cookie Chain cApp

No build step, no env vars, no secrets. Pick ONE path.

## Path A — Netlify Drop (fastest, ~2 min)

1. Zip the `cookie-chain-app` folder (or just drag the folder).
2. Go to https://app.netlify.com/drop and drag it in.
3. You get a live URL like `https://phi-ledger-cookie.netlify.app`. Done.
4. (Optional) Rename the site under Site settings → Change site name.

## Path B — Vercel (~3 min)

1. Push this folder to a GitHub repo (e.g. `tyofthestarz11-lab/phi-ledger-cookie`).
2. Go to https://vercel.com/new → Import the repo.
3. Framework preset: **Other**. Build command: empty. Output directory: `.` (or leave default). `vercel.json` in the folder handles it.
4. Deploy → live URL.

## Path C — GitHub Pages (free, ~3 min)

1. Push this folder to a GitHub repo.
2. Repo Settings → Pages → Source: Deploy from branch → `main` → folder `/` (if the repo root IS this folder) or `/docs`.
3. Live at `https://<you>.github.io/<repo>/`.

## After deploy — verify (2 min)

1. Open the live URL. Chain strip should show slot/epoch/TPS (live from Cookie Chain RPC).
2. Ledger panel: 45 seals / 428 entries, snapshot hash `11f521a7…`.
3. Mining panel: live hashrate from SoloPool.
4. Install Phantom or Nightly → add Cookie Chain network (`https://rpc.cookiescan.io`, symbol COOK) → connect → your COOK balance shows.
5. Bridge a tiny amount of COOK from Solana (https://bridge.cookiescan.io) for fees.
6. Pick a seal → **Anchor on Cookie Chain** → approve in wallet → signature links to CookieScan. This is the on-chain interaction the bounty asks for.

## Troubleshooting

- **"No Solana wallet found"** — install Phantom/Nightly/Solflare extension and reload.
- **Anchor fails / funds error** — you need a little COOK on Cookie Chain for the fee. Bridge: https://bridge.cookiescan.io.
- **Wallet shows wrong network** — in Nightly, add custom SVM network: RPC `https://rpc.cookiescan.io`, symbol `COOK`.
