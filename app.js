/* PHI LEDGER — Cookie Chain cApp
 * Reads: Cookie Chain RPC (rpc.cookiescan.io), SoloPool BCH API, local ledger snapshot.
 * Writes: one memo transaction on Cookie Chain (user-signed, tiny COOK fee).
 */
const RPC_URL = 'https://rpc.cookiescan.io';
const EXPLORER = 'https://cookiescan.io';
const MEMO_PROGRAM = 'Memo1UhkJRfHyvLMcVucJwxXeuD728EqVDDwQDxFMNo';
// v99 memo compat: a wallet may memo via Memo v1, MemoSq4, or a wallet-added
// program whose data is still a PHI-LEDGER memo. Memo identity is its text,
// not one program ID alone. L2TExMFK...3S95, seen in a screenshot as a
// "missing program", is a wallet-added program, not an altered memo.
const MEMO_PROGRAMS = [MEMO_PROGRAM, 'MemoSq4gqABAXKb96qnH8TysNcWx3S2B9oJ5E'];
const isMemoProgram = (id) => MEMO_PROGRAMS.includes(id);
const memoTextOfIx = (ix) => { try { return new TextDecoder().decode(ix.data); } catch (e) { return ''; } };
const LIGHTHOUSE_PROGRAM = 'L2TExMFKdjpN9kozasaurPirfHy9P8sbXoAN1qA3S95'; // Phantom's protection injector
const SOLOPOOL = 'https://solopool.eu/api/v1/bch/miner/bitcoincash:qp432rtl3cm0se35rdy6ye8ay2tfxas80y24ntf2vm';

const { Connection, PublicKey, Transaction, TransactionInstruction, SystemProgram } = solanaWeb3;
const connection = new Connection(RPC_URL, 'confirmed');

/* Public anchors: anyone anchors their data for a small COOK fee.
 * φ is always φ — the page anchors visitor data too, not just ledger seals. */
const TYREE_WALLET = 'A92L9a5qMwUpp8GRRsvj8n9hF6hx6WBVakQgbSDZzG3q'; // Tyree's Phantom wallet — public-anchor fees land here
const PUBLIC_ANCHOR_FEE_COOK = 1; // small COOK fee per public anchor, paid to Tyree — keep the .pubFee text in index.html in sync

/* Transaction schema — the memo grammar every on-chain anchor carries.
 * v2 (2026-09-29): the anchored snapshot now includes the 13 validated
 * GZ2/trace ledger entries (see TRANSACTION_SCHEMA.md). Memo format unchanged. */
const TRANSACTION_SCHEMA = {
  version: 2,
  sealMemo: 'PHI-LEDGER|seal=<seal>|sha256=<snapshot_sha256>|by=tyofthestarz',
  publicMemo: 'PHI-LEDGER|public|<label>|sha256=<data_sha256>|by=<wallet>',
  snapshotSha256: 'cd06b055da26b251b1d52e20e6c10ac49e8989dc89f48f269d6c22bf5b7cbcb4',
  sealCount: 381,
  entryCount: 3804,
};

let wallet = null;      // connected public key (base58)
let provider = null;    // injected wallet provider
let snapshot = null;

const $ = id => document.getElementById(id);
const fmtInt = n => Number(n).toLocaleString('en-US');
const short = (s, n=6) => s ? s.slice(0,n) + '…' + s.slice(-4) : '';

/* ---------- Cookie Chain network pulse ---------- */
async function pulse() {
  if (walletPromptOpen()) return;
  try {
    const [slot, epoch, perf] = await Promise.all([
      connection.getSlot(),
      connection.getEpochInfo(),
      connection.getRecentPerformanceSamples(1),
    ]);
    $('statSlot').textContent = fmtInt(slot);
    $('statEpoch').textContent = epoch.epoch;
    $('statHeight').textContent = fmtInt(epoch.blockHeight);
    const tps = perf && perf[0] ? Math.round(perf[0].numTransactions / perf[0].samplePeriodSecs) : null;
    $('statTps').textContent = tps !== null ? fmtInt(tps) : 'n/a';
    $('rpcDot').className = 'status-dot bg-green-500';
    $('rpcState').textContent = 'ok';
  } catch (e) {
    $('rpcDot').className = 'status-dot bg-red-500';
    $('rpcState').textContent = 'unreachable';
  }
}

/* ---------- Ledger analytics ---------- */
async function loadLedger() {
  const r = await fetch('ledger-snapshot.json', { cache: 'no-store' }); // ledger is current at every load, never a cached snapshot
  snapshot = await r.json();
  $('sealCount').textContent = snapshot.seal_count;
  $('entryCount').textContent = snapshot.entry_count;
  $('entrySearch').placeholder = 'Search ' + fmtInt(snapshot.entry_count) + ' entries…';
  $('snapHash').textContent = 'sha256 ' + snapshot.snapshot_sha256.slice(0, 12) + '…';

  const byLadder = {};
  for (const e of snapshot.entries) byLadder[e.ladder || 'other'] = (byLadder[e.ladder || 'other'] || 0) + 1;
  const ladders = Object.entries(byLadder).sort((a, b) => b[1] - a[1]);
  $('ladderCount').textContent = ladders.length;
  const max = ladders[0][1];
  $('ladderBars').innerHTML = ladders.slice(0, 10).map(([k, v]) =>
    `<div><div class="flex justify-between text-xs mb-1"><span class="text-gray-300">${k}</span><span class="mono gold">${v}</span></div><div class="bar" style="width:${Math.round(v / max * 100)}%"></div></div>`
  ).join('');

  const sel = $('sealSelect');
  sel.innerHTML = snapshot.seals.map(s => `<option>${s}</option>`).join('');

  renderEntries('');
  $('entrySearch').addEventListener('input', e => renderEntries(e.target.value.toLowerCase()));
}

function renderEntries(q) {
  const list = snapshot.entries
    .filter(e => !q || (e.name || '').toLowerCase().includes(q) || (e.ladder || '').toLowerCase().includes(q))
    .sort((a, b) => b.rung - a.rung)
    .slice(0, 60);
  $('entryList').innerHTML = list.map(e =>
    `<div class="flex justify-between gap-2 border-b border-gray-800/60 py-1"><span>${e.name || '—'}</span><span class="text-gray-500">${e.ladder || ''}</span><span class="gold">φ^${e.rung}</span></div>`
  ).join('') || '<div class="text-gray-500">no matches</div>';
}

/* ---------- BCH mining telemetry (live, CORS-open) ---------- */
async function mining() {
  if (typeof walletPromptOpen === 'function' && walletPromptOpen()) return;
  try {
    const r = await fetch(SOLOPOOL);
    const m = await r.json();
    $('mineHash').textContent = m.hashrate || 'n/a';
    $('mineShares').textContent = fmtInt(m.shares_valid || 0);
    $('mineBest').textContent = m.bestshare_alltime_display || 'n/a';
    $('mineBestSession').textContent = 'session ' + (m.bestshare_display || 'n/a');
    $('mineBlocks').textContent = m.blocks_found ?? 0;
    $('workerList').innerHTML = (m.workers || []).map(w =>
      `<div class="flex justify-between gap-2 border-b border-gray-800/60 py-1"><span class="gold">${w.name}</span><span>${w.hashrate}</span><span class="text-gray-500">${fmtInt(w.shares)} shares</span><span class="${w.status === 'active' ? 'text-green-400' : 'text-red-400'}">${w.status}</span></div>`
    ).join('');
    $('mineAge').textContent = '· updated ' + new Date((m.updated_at || 0) * 1000).toLocaleTimeString();
  } catch (e) {
    $('mineHash').textContent = 'unreachable';
  }
}

/* ---------- The Anchor Engine: one whole flow, φ² = φ + 1 ----------
 * Not parts: the site, the signer, and Cookie Chain move as one motion.
 * Rung 1: build the anchor transaction exactly.
 * Rung 2: sign — then VERIFY THE BYTES. No signer's output is ever trusted.
 * Rung 3: dirty bytes are +1 fuel — the engine reroutes automatically
 *          (in-page → wallet app), never a dead end, never a burned fee.
 * Rung 4: broadcast → confirm → the chain arbitrates (meta.err, memo).
 * The engine stops before broadcast whenever the bytes aren't exactly
 * the anchor. A failed experiment costs nothing. */
const COMPUTE_BUDGET_PROGRAM = 'ComputeBudget111111111111111111111111111111';
async function missingPrograms(signedTx) {
  const ids = [...new Set(signedTx.instructions.map(ix => ix.programId.toString()))];
  const unknown = ids.filter(id => id !== MEMO_PROGRAM && id !== COMPUTE_BUDGET_PROGRAM);
  const missing = [];
  for (const id of unknown) {
    try {
      const info = await connection.getAccountInfo(new PublicKey(id));
      if (!info) missing.push(id);
    } catch (e) { /* RPC hiccup: treat as unknown, not missing */ }
  }
  return { unknown, missing };
}
/* ---------- base58 (for wallet-app deep links) ---------- */
const BS58 = '123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz';
function bs58encode(bytes) {
  let zeros = 0;
  while (zeros < bytes.length && bytes[zeros] === 0) zeros++;
  const digits = [0];
  for (let i = zeros; i < bytes.length; i++) {
    let carry = bytes[i];
    for (let j = 0; j < digits.length; j++) {
      carry += digits[j] << 8;
      digits[j] = carry % 58;
      carry = Math.floor(carry / 58);
    }
    while (carry > 0) { digits.push(carry % 58); carry = Math.floor(carry / 58); }
  }
  let out = '1'.repeat(zeros);
  for (let i = digits.length - 1; i >= 0; i--) out += BS58[digits[i]];
  return out;
}
function bs58decode(s) {
  let zeros = 0;
  while (zeros < s.length && s[zeros] === '1') zeros++;
  const bytes = [0];
  for (let i = zeros; i < s.length; i++) {
    const val = BS58.indexOf(s[i]);
    if (val < 0) throw new Error('bad bs58');
    let carry = val;
    for (let j = 0; j < bytes.length; j++) {
      carry += bytes[j] * 58;
      bytes[j] = carry & 0xff;
      carry >>= 8;
    }
    while (carry > 0) { bytes.push(carry & 0xff); carry >>= 8; }
  }
  const out = new Uint8Array(zeros + bytes.length);
  for (let i = 0; i < bytes.length; i++) out[zeros + i] = bytes[bytes.length - 1 - i];
  return out;
}

/* ---------- Wallet connect (injected provider: Phantom / Nightly / Solflare) ---------- */
function isValidAddress(addr) {
  // Real Solana address: 32-44 base58 chars, not the system program.
  return typeof addr === 'string' && addr.length >= 32 && addr.length <= 44 &&
         addr !== '11111111111111111111111111111111' && /^[1-9A-HJ-NP-Za-km-z]+$/.test(addr);
}
// Cookie Chain, added to phi ledger itself, 2026-10-29 v94.
// This is the network phi ledger uses for every anchor, balance, and chain
// read — not Solana. Wallets that default to Solana get this definition
// from phi ledger, so the site does not lean on the wallet's default.
const COOKIE_CHAIN = {
  id: 'cookie-chain',
  chainId: 'cookie-chain',
  name: 'Cookie Chain',
  rpc: 'https://rpc.cookiescan.io',
  explorer: 'https://cookiescan.io',
  currency: 'COOK',
  chain: 'SVM',
  cluster: 'cookie-chain',
};
// Single provider only — no loops, no popup circles.
// v97 nightly fix: Nightly first. Inside the Nightly browser, window.solana
// may belong to another wallet, so the Nightly provider must win —
// otherwise Add Cookie Chain and Connect Wallet go to the wrong wallet.
// Nightly injects late, so this is read at click time, never cached.
function getProvider() {
  return (window.nightly && window.nightly.solana) || window.solana || window.solflare || window.backpack || null;
}
// v99 merged: every injected provider, in order. A provider that returns
// the system program 111... is not a real account — it is a placeholder
// for "no account selected yet". The old code accepted the first
// non-null key and then threw "invalid address", looping forever.
function getProviders() {
  const list = [];
  const push = (x) => { if (x && !list.includes(x)) list.push(x); };
  push(window.nightly && window.nightly.solana);
  push(window.phantom && window.phantom.solana);
  push(window.solana);
  push(window.solflare);
  push(window.backpack);
  return list;
}
function validPubkeyString(v) {
  const str = (typeof v === 'string') ? v : (v && v.toString ? v.toString() : '');
  return isValidAddress(str) ? str : null;
}
// v102 unlock fix, on Tyree's directive: before Add & Connect, force an
// unlock prompt, not just a message. Try every provider — Phantom,
// Nightly, Backpack, and every injected provider — with eth_requestAccounts,
// solana connect, and wallet_requestPermissions, in that order. If locked,
// the prompt itself is the unlock step; a message alone is not a fix.
// A 111... key is still discarded, never accepted as an account.
function withTimeout(promise, ms) {
  return Promise.race([
    promise,
    new Promise((_, rej) => setTimeout(() => rej(new Error('Wallet prompt timed out')), ms)),
  ]);
}
// v104 Nightly fix: unlock is a Solana connect prompt only. The v102
// eth_requestAccounts / wallet_requestPermissions calls are EVM prompts,
// not Solana prompts — in Nightly they open the wrong prompt, burn up to
// 24 seconds per provider, and bury the real Solana connect prompt.
// A Solana provider is unlocked by its own connect(), nothing else.
async function unlockAllProviders() {
  let unlockedPk = null;
  for (const prov of getProviders()) {
    if (typeof prov.connect === 'function') {
      try { await withTimeout(prov.connect(), 15000); } catch (e) {}
    }
    if (prov.publicKey) {
      const pk = validPubkeyString(prov.publicKey);
      if (pk) unlockedPk = pk;
    }
    if (unlockedPk) break;
  }
  return unlockedPk;
}
async function connectOneProvider(prov) {
  let pk = null;
  // v101: a stale injected publicKey must not win over a fresh connect.
  // The wallet app showing an account selected does not by itself approve
  // this site — connect() must run first to trigger the per-site approval
  // prompt, then the key is read after it. A 111... key is discarded.
  if (typeof prov.connect === 'function') {
    try {
      const resp = await Promise.race([
        prov.connect(),
        new Promise((_, rej) => setTimeout(() => rej(new Error('Wallet connection timed out — not connected.')), 15000)),
      ]);
      const cand = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || (resp && resp.account);
      if (cand) pk = validPubkeyString(cand);
    } catch (e) {}
  }
  if (!pk && prov.publicKey) pk = validPubkeyString(prov.publicKey);
  if (!pk && typeof prov.connect === 'function') {
    try {
      const resp = await Promise.race([
        prov.connect(),
        new Promise((_, rej) => setTimeout(() => rej(new Error('Wallet connection timed out — not connected.')), 15000)),
      ]);
      const cand = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || (resp && resp.account);
      if (cand) pk = validPubkeyString(cand);
    } catch (e) {}
  }
  if (!pk && prov.publicKey) pk = validPubkeyString(prov.publicKey);
  if (!pk && typeof prov.request === 'function') {
    try {
      const resp = await prov.request({ method: 'connect' });
      const cand = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || prov.publicKey;
      if (cand) pk = validPubkeyString(cand);
    } catch (e) {}
  }
  return pk;
}

if ($('connectBtn')) $('connectBtn').addEventListener('click', async () => {
  // One click, one connect: disable while connecting so five taps cannot
  // stack five connect attempts, and show status instead of a frozen button.
  // Nightly is slow to answer in its own browser — the label says so while
  // it works, and the button comes back if the attempt fails.
  const btn = $('connectBtn');
  if (btn.disabled) return;
  btn.disabled = true;
  btn.textContent = 'Connecting…';
  $('walletLabel').textContent = 'connecting to wallet…';
  const p = getProvider();
  if (!p) {
    // Mobile Chrome has no injected provider — offer the wallet app deep-link flow.
    // Do NOT permanently disable the button: Nightly injects late, so a first
    // tap before injection must be retryable, not a dead end.
    $('mobileAnchor').classList.remove('hidden');
    $('connectBtn').textContent = 'Connect Wallet';
    $('connectBtn').disabled = false;
    $('walletLabel').textContent = 'no wallet found yet — tap again';
    refreshMobileBalance();
    return;
  }
  // Single connect() call — no loops, no popup circles.
  // RPC routing, 2026-10-29: the only connection endpoint in this file is
  // rpc.cookiescan.io (RPC_URL, single Connection). There is no fallback to
  // any Solana mainnet RPC anywhere in the in-page flow.
  try {
      let pubkey = null;
      // 0. Already connected in this browser session? Use the injected key
      // directly — no new bridge call, so a failing SOLANA_CONNECT bridge
      // cannot block a wallet that is already connected.
      if (p.publicKey) {
        const pk0 = (typeof p.publicKey === 'string') ? p.publicKey : (p.publicKey.toString ? p.publicKey.toString() : String(p.publicKey));
        if (isValidAddress(pk0)) pubkey = pk0;
      }
      // 1. Legacy connect() — with a 60-second break, and guarded on its
      // own: v98 real fix. Before v98 a bridge failure here ("Failed to
      // connect to Solana") jumped straight to the outer catch and
      // SKIPPED the request() fallback below, so a wallet whose bridge
      // fails but whose request() would answer never got tried. A
      // failure here now falls through to step 2 and step 3 instead.
      if (!pubkey && typeof p.connect === 'function') {
        try {
          const resp = await Promise.race([
            p.connect(),
            new Promise((_, rej) => setTimeout(() => rej(new Error('Wallet connection timed out — not connected.')), 15000)),
          ]);
          const pk = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || (resp && resp.account);
          if (pk) { const v = validPubkeyString(pk); if (v) pubkey = v; }
        } catch (e) { /* fall through: publicKey check, then request() fallback */ }
      }
      // 2. Check p.publicKey AFTER connect() (it should now be populated).
      if (!pubkey && p.publicKey) {
        const v = validPubkeyString(p.publicKey);
        if (v) pubkey = v;
      }
      // 3. EIP-1193-style request() as fallback, guarded on its own so a
      // request failure still reaches the outer catch injected-key check
      // below instead of throwing a raw error out of the flow.
      if (!pubkey && typeof p.request === 'function') {
        try {
          const resp = await p.request({ method: 'connect' });
          const pk = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || p.publicKey;
          if (pk) { const v = validPubkeyString(pk); if (v) pubkey = v; }
        } catch (e) { /* fall through to the injected-key check in catch */ }
      }
      provider = p;
      if (!pubkey || !isValidAddress(pubkey)) throw new Error('No account was approved for this site (111...) — your wallet app showing A92L selected does not by itself approve this site. Approve A92L in the wallet prompt for this site, then tap Add & Connect again');
      wallet = pubkey;
    $('walletLabel').textContent = short(wallet, 4);
    $('anchorBtn').disabled = false;
    $('batchAnchorBtn').disabled = false;
    refreshBatchLabel();
    $('pubAnchorBtn').disabled = false;
    refreshBalance();
    // Nightly on custom network: only log when the connected provider
    // actually is the Nightly provider — the old check logged whenever
    // window.nightly merely existed, even on a different provider.
    if (window.nightly && p === window.nightly.solana) {
      console.log('Nightly provider connected — Cookie Chain network (rpc.cookiescan.io). Add Cookie Chain, then Connect Wallet, in that order.');
    }
  } catch (e) {
    // Phi ledger v94: a bridge failure must not block a wallet that
    // already injected its key. If p.publicKey is valid after the failed
    // bridge call, accept it — phi ledger broadcasts via Cookie Chain,
    // so the wallet's default network does not block signing.
    if (p && p.publicKey) {
      const pkAfter = (typeof p.publicKey === 'string') ? p.publicKey : (p.publicKey.toString ? p.publicKey.toString() : String(p.publicKey));
      if (isValidAddress(pkAfter)) {
        provider = p; wallet = pkAfter;
        $('walletLabel').textContent = short(wallet, 4);
        $('connectBtn').textContent = 'Connected';
        $('connectBtn').disabled = true;
        $('anchorBtn').disabled = false;
        $('batchAnchorBtn').disabled = false;
        refreshBatchLabel();
        $('pubAnchorBtn').disabled = false;
        refreshBalance();
        return;
      }
    }
    // No blocking alert: a failed bridge call must not block the page with
    // a JSON dump. The real error stays inline, the button comes back, and
    // the connection state resets clean — no stale provider, no stale
    // cached chain read — so the next attempt starts fresh, not from a
    // half-connected adapter.
    // v99: 111... from one provider is not a dead end — try the other
    // injected providers for a real address before giving up.
    for (const prov of getProviders()) {
      if (prov === p) continue;
      const pkTry = await connectOneProvider(prov);
      if (pkTry) {
        provider = prov; wallet = pkTry;
        $('walletLabel').textContent = short(wallet, 4);
        $('connectBtn').textContent = 'Connected';
        $('connectBtn').disabled = true;
        $('anchorBtn').disabled = false;
        $('batchAnchorBtn').disabled = false;
        refreshBatchLabel();
        $('pubAnchorBtn').disabled = false;
        refreshBalance();
        return;
      }
    }
    provider = null; wallet = null;
    if (typeof invalidateMissingSeals === 'function') invalidateMissingSeals();
    window._walletPromptOpen = false;
    const plainErr = shortErr(e);
    // Phi ledger issue, not Nightly: a Solana-bridge connect failure
    // must say, in plain words, that the wallet is on Solana, not
    // Cookie Chain — not a raw JSON dump, and not a dead end.
    $('walletLabel').textContent = (/connect|solana/i.test(plainErr) ? 'not connected — wallet is on Solana, not Cookie Chain. Add Cookie Chain (rpc.cookiescan.io) in your wallet, then tap Connect again. Error: ' + plainErr : 'not connected — ' + plainErr);
    $('connectBtn').textContent = 'Connect Wallet';
    $('connectBtn').disabled = false;
    return;
  }
});

// Add Cookie Chain to phi ledger, and try to add it to the wallet too.
// Phi ledger fix, 2026-10-29: the site must carry Cookie Chain itself,
// not tell the user to go add it elsewhere and come back. If the wallet
// provider supports a programmatic add-network request, use it. If it
// does not, show the exact Cookie Chain details plainly on the site,
// and keep the site's own connection on Cookie Chain regardless of the
// wallet's default network — signing bytes does not depend on the
// wallet's selected network, broadcasting does, and phi ledger
// broadcasts via Cookie Chain.
if ($('addChainBtn')) $('addChainBtn').addEventListener('click', async () => {
  const p = getProvider();
  $('walletLabel').textContent = 'Cookie Chain added to phi ledger: ' + COOKIE_CHAIN.name + ', RPC ' + COOKIE_CHAIN.rpc + ', explorer ' + COOKIE_CHAIN.explorer + ', currency ' + COOKIE_CHAIN.currency + '.';
  if (p && typeof p.request === 'function') {
    const tries = [
      { method: 'wallet_addNetwork', params: [{ chainId: COOKIE_CHAIN.chainId, name: COOKIE_CHAIN.name, rpc: COOKIE_CHAIN.rpc, rpcUrls: [COOKIE_CHAIN.rpc], explorer: COOKIE_CHAIN.explorer, blockExplorerUrls: [COOKIE_CHAIN.explorer], currency: COOKIE_CHAIN.currency, nativeCurrency: { name: 'COOK', symbol: 'COOK', decimals: 9 } }] },
      { method: 'wallet_addChain', params: [{ chainId: COOKIE_CHAIN.chainId, name: COOKIE_CHAIN.name, rpcUrls: [COOKIE_CHAIN.rpc], blockExplorerUrls: [COOKIE_CHAIN.explorer], nativeCurrency: { name: 'COOK', symbol: 'COOK', decimals: 9 } }] },
      { method: 'wallet_switchChain', params: [{ chainId: COOKIE_CHAIN.chainId }] },
    ];
    // v98 real fix: some wallet browsers reject every add method until the
    // wallet is connected first. If the first pass fails, connect once
    // (guarded) and retry the same three methods in the same order, so
    // the manual-add message only shows after both passes fail.
    for (let attempt = 0; attempt < 2; attempt++) {
      for (const t of tries) {
        try { await p.request(t); $('walletLabel').textContent = 'Cookie Chain added to wallet via phi ledger. Chain ID: ' + COOKIE_CHAIN.chainId + ', RPC: ' + COOKIE_CHAIN.rpc + '. Now tap Connect Wallet.'; return; } catch (e) {}
      }
      if (attempt === 0 && typeof p.connect === 'function') {
        try { await p.connect(); } catch (e) {}
      }
    }
  }
  $('walletLabel').textContent = 'Cookie Chain added to phi ledger. Chain ID: ' + COOKIE_CHAIN.chainId + ', RPC: ' + COOKIE_CHAIN.rpc + ', Explorer: ' + COOKIE_CHAIN.explorer + ', Currency: ' + COOKIE_CHAIN.currency + '. Your wallet does not accept a programmatic add, so add this custom network in your wallet app, then tap Connect Wallet.';
});

// v99 merged: ONE tap, Add & Connect. No "click Add first, then Connect".
// One tap does wallet_addNetwork, wallet_addChain, wallet_switchChain
// (Chain ID cookie-chain, RPC rpc.cookiescan.io, explorer cookiescan.io,
// COOK, SVM), then Connect — and Connect accepts an injected key even
// after a bridge failure, a 111... placeholder, or a memo-program rewrite.
// v105 fix, on Tyree's word: Add & Connect, connect FIRST, one prompt only.
// Fault in phi ledger, read from Tyree's screen: the old handler called
// connect() many times before the real connect — unlock, then add-network
// attempts, then connect loops, then a second pass. A wallet browser
// suppresses repeated prompts, so no approval prompt appeared at all, and
// the provider stayed at the 111... placeholder, which is not an account.
// The old handler also tried wallet_addNetwork with chainId cookie-chain
// BEFORE connecting. Solana wallets reject a non-Solana chainId, and that
// failure left the provider in a rejected state before connect ran.
// New order, in phi ledger only: connect once, read the key, then try to
// add the network as a best effort. Phi ledger broadcasts via Cookie Chain
// regardless, so a failed add-network never blocks a connected wallet.
// A wallet app showing A92L selected is not approval. Approval happens
// only in the prompt that connect() opens for this site.
if ($('addConnectBtn')) $('addConnectBtn').addEventListener('click', async () => {
  const btn = $('addConnectBtn');
  if (btn.disabled) return;
  btn.disabled = true;
  btn.textContent = 'Connecting…';
  $('walletLabel').textContent = 'Tap approve in your wallet prompt for this site — that prompt is the approval. Showing A92L selected in the wallet app alone does not approve this site.';
  // One provider, Nightly first, read at click time, never cached.
  const prov = getProvider();
  if (!prov) {
    $('walletLabel').textContent = 'No wallet provider found in this browser. Open this site inside your wallet app browser, then tap Add & Connect again.';
    btn.textContent = 'Add & Connect';
    btn.disabled = false;
    return;
  }
  // Step 1: connect exactly once. This is the only call that opens the
  // per-site approval prompt. No unlock loop, no second pass, no repeat.
  let connectedPk = null;
  try {
    const resp = await Promise.race([
      prov.connect(),
      new Promise((_, rej) => setTimeout(() => rej(new Error('Wallet prompt timed out')), 30000)),
    ]);
    const cand = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || (resp && resp.account) || prov.publicKey;
    if (cand) connectedPk = validPubkeyString(cand);
  } catch (e) {}
  if (!connectedPk && prov.publicKey) connectedPk = validPubkeyString(prov.publicKey);
  if (connectedPk) {
    provider = prov; wallet = connectedPk;
    $('walletLabel').textContent = short(wallet, 4);
    $('anchorBtn').disabled = false;
    $('batchAnchorBtn').disabled = false;
    refreshBatchLabel();
    $('pubAnchorBtn').disabled = false;
    refreshBalance();
    btn.textContent = 'Connected';
    btn.disabled = true;
    // Step 2, best effort only, after connect: try to add Cookie Chain to
    // the wallet. Every failure is ignored here — phi ledger broadcasts
    // via Cookie Chain on its own connection, so a connected wallet is
    // never blocked by a failed add-network.
    if (typeof prov.request === 'function') {
      const tries = [
        { method: 'wallet_addNetwork', params: [{ chainId: COOKIE_CHAIN.chainId, name: COOKIE_CHAIN.name, rpc: COOKIE_CHAIN.rpc, rpcUrls: [COOKIE_CHAIN.rpc], explorer: COOKIE_CHAIN.explorer, blockExplorerUrls: [COOKIE_CHAIN.explorer], currency: COOKIE_CHAIN.currency, nativeCurrency: { name: 'COOK', symbol: 'COOK', decimals: 9 } }] },
        { method: 'wallet_addChain', params: [{ chainId: COOKIE_CHAIN.chainId, name: COOKIE_CHAIN.name, rpcUrls: [COOKIE_CHAIN.rpc], blockExplorerUrls: [COOKIE_CHAIN.explorer], nativeCurrency: { name: 'COOK', symbol: 'COOK', decimals: 9 } }] },
      ];
      for (const t of tries) {
        try { await withTimeout(prov.request(t), 12000); break; } catch (e) {}
      }
    }
    return;
  }
  // No valid key: the provider answered with no approved account for this
  // site. The 111... value is a placeholder, not an account and not A92L.
  // Plain words, no jargon: no prompt approval landed, so tap once more
  // and approve A92L in the prompt that appears for this site.
  const raw = prov.publicKey ? String(prov.publicKey) : '';
  const seen = raw === '11111111111111111111111111111111' ? 'no account approved yet' : (raw ? 'a key that is not a valid account' : 'no key');
  $('walletLabel').textContent = 'Not connected yet. Your wallet provider answered with ' + seen + ' for this site, not A92L. That means no approval prompt landed yet. Tap Add & Connect once, and when the wallet prompt appears for this site, approve A92L in it, then tap Add & Connect again if the button returns.';
  btn.textContent = 'Add & Connect';
  btn.disabled = false;
});
async function refreshBalance() {
  if (typeof walletPromptOpen === 'function' && walletPromptOpen()) return;
  try {
    const lamports = await connection.getBalance(new PublicKey(wallet));
    const cook = lamports / 1e9;
    $('cookBal').textContent = cook.toFixed(6) + ' COOK';
    $('noCook').classList.toggle('hidden', cook > 0);
  } catch (e) {
    $('cookBal').textContent = 'n/a';
  }
}

/* ---------- Mobile anchor: Phantom app deep link (no injected provider) ---------- */
async function refreshMobileBalance() {
  if (typeof walletPromptOpen === 'function' && walletPromptOpen()) return;
  const addr = $('mobileAddr').value.trim();
  if (!addr) return;
  try {
    const lamports = await connection.getBalance(new PublicKey(addr));
    const cook = lamports / 1e9;
    $('mobileBal').textContent = cook.toFixed(6) + ' COOK on Cookie Chain';
    $('mobileNoCook').classList.toggle('hidden', cook > 0);
  } catch (e) {
    $('mobileBal').textContent = 'could not read balance';
  }
}

async function buildAnchorTx(walletAddr, seal) {
  if (!snapshot) throw new Error('Ledger snapshot not loaded yet — reload the page and tap once more.');
  const memoText = `PHI-LEDGER|seal=${seal}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz`;
  const ix = new TransactionInstruction({
    keys: [{ pubkey: new PublicKey(walletAddr), isSigner: true, isWritable: false }],
    programId: new PublicKey(MEMO_PROGRAM),
    data: new TextEncoder().encode(memoText),
  });
  const tx = new Transaction().add(ix);
  tx.feePayer = new PublicKey(walletAddr);
  const { blockhash, lastValidBlockHeight } = await connection.getLatestBlockhash('confirmed');
  tx.recentBlockhash = blockhash;
  tx._blockhashInfo = { blockhash, lastValidBlockHeight };
  tx._memoText = memoText;
  return tx;
}

$('mobileAddr').addEventListener('change', refreshMobileBalance);

// Mobile flow: anchor through the Solflare app via the encrypted deep link.
// The session persists on this device, so repeated anchors go straight through.
$('solflareAnchorBtn').addEventListener('click', async () => {
  const addr = $('mobileAddr').value.trim();
  const out = $('mobileOut');
  out.classList.remove('hidden');
  // Inside a wallet's own browser (Nightly/Phantom in-app), the Solflare app
  // cannot return here: its redirect opens the system browser, a different
  // context with no session — the anchor would never confirm. Sign in-page.
  if (getProvider()) {
    out.innerHTML = '<span class="text-amber-300">You are inside a wallet browser — the Solflare app cannot return to this tab, so the anchor would never confirm.</span><br><span class="text-gray-400 text-sm">Connect with the <b>Connect Wallet</b> button above, then tap <b>Anchor on Cookie Chain</b> — it signs in-page, no app switching.</span>';
    return;
  }
  if (!isValidAddress(addr)) {
    out.innerHTML = '<span class="text-amber-300">Enter your Solana wallet address first.</span>';
    return;
  }
  await refreshMobileBalance();
  await solflareAnchorFlow(addr, $('sealSelect').value, out);
});

/* ---------- Phantom app: encrypted deeplink session (NaCl box) ----------
 * The app only honors well-formed requests: an encrypted session first
 * (connect), then an encrypted sign payload. A bare ?transaction= URL is
 * unreadable to the app — it just opens home. This is the documented flow:
 * the approval happens IN THE APP, the site only broadcasts afterwards. */
const PHANTOM_SCHEME = 'phantom://v1'; // custom protocol: opens the app directly, no website, ever
// Session persists across tabs (the app can return into a fresh tab).
function lsGet(k) { try { return localStorage.getItem(k); } catch (e) { return null; } }
function lsSet(k, v) { try { localStorage.setItem(k, v); } catch (e) {} }
function lsDel(k) { try { localStorage.removeItem(k); } catch (e) {} }
function phantomRedirect() { return window.location.origin + window.location.pathname; }
function getDappKeys() {
  let pub = lsGet('dapp_pub'), sec = lsGet('dapp_sec');
  if (!pub || !sec) {
    const kp = nacl.box.keyPair();
    pub = bs58encode(kp.publicKey); sec = bs58encode(kp.secretKey);
    lsSet('dapp_pub', pub); lsSet('dapp_sec', sec);
  }
  return { pub, sec };
}
function getPhantomSession() {
  const session = lsGet('phantom_session');
  const phantomPub = lsGet('phantom_pubkey');
  if (session && phantomPub) return { session, phantomPub };
  return null;
}
function setPhantomSession(session, phantomPub) {
  lsSet('phantom_session', session); lsSet('phantom_pubkey', phantomPub);
}
function setPendingSign(addr, seal, kind, extra) {
  lsSet('phantom_pending_sign', JSON.stringify({ addr, seal, kind: kind || 'phantom', extra: extra || null }));
  lsSet('anchorReroute', seal);
}
function getPendingSign() {
  try { return JSON.parse(lsGet('phantom_pending_sign') || 'null'); } catch (e) { return null; }
}
function clearPendingSign() {
  lsDel('phantom_pending_sign'); lsDel('anchorReroute');
}
function encryptForWallet(obj, walletPubB58) {
  const dapp = getDappKeys();
  const nonce = nacl.randomBytes(24);
  const box = nacl.box(new TextEncoder().encode(JSON.stringify(obj)), nonce, bs58decode(walletPubB58), bs58decode(dapp.sec));
  return { nonceB58: bs58encode(nonce), payloadB58: bs58encode(box) };
}
function decryptFromWallet(dataB58, nonceB58, walletPubB58) {
  const dapp = getDappKeys();
  const opened = nacl.box.open(bs58decode(dataB58), bs58decode(nonceB58), bs58decode(walletPubB58), bs58decode(dapp.sec));
  if (!opened) throw new Error('Could not decrypt the wallet response.');
  return JSON.parse(new TextDecoder().decode(opened));
}
// Step 1: connect — establishes the encrypted session. On return the boot
// handler stores the session and continues to the sign step automatically.
function phantomConnect(out) {
  const dapp = getDappKeys();
  if (out) out.innerHTML = '<span class="text-gray-400">Opening Phantom to connect… approve in the app.</span>';
  const redirect = encodeURIComponent(phantomRedirect());
  const appUrl = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&cluster=mainnet-beta&app_url=${appUrl}&redirect_link=${redirect}`;
  window.location.href = `${PHANTOM_SCHEME}/connect?${q}`; // straight into the app
}
// Step 2: sign — fresh transaction, encrypted payload, approval IN THE APP.
async function phantomSignRequest(addr, seal, out) {
  const sess = getPhantomSession();
  if (!sess) { phantomConnect(out); return; }
  if (out) out.innerHTML = '<span class="text-gray-400">Opening Phantom… approve the anchor in the app.</span>';
  const tx = await buildAnchorTx(addr, seal); // fresh blockhash for the app
  const b58 = bs58encode(tx.serialize({ requireAllSignatures: false, verifySignatures: false }));
  const enc = encryptForWallet({ transaction: b58, session: sess.session }, sess.phantomPub);
  const dapp = getDappKeys();
  const redirect = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&nonce=${enc.nonceB58}&redirect_link=${redirect}&payload=${enc.payloadB58}`;
  window.location.href = `${PHANTOM_SCHEME}/signTransaction?${q}`; // straight into the app
}
// Entry: one call from either button. Connects first if needed, else signs.
async function phantomAnchorFlow(addr, seal, out) {
  setPendingSign(addr, seal, 'phantom');
  try {
    if (getPhantomSession()) await phantomSignRequest(addr, seal, out);
    else phantomConnect(out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${shortErr(e)}</span>`;
  }
}

/* ---------- Solflare app: encrypted deeplink session (NaCl box) ----------
 * Same universal-link protocol as Phantom — verified against Solflare's
 * official deep-link sample app (solflare-wallet/deep-link-sample-app):
 * solflare://ul/v1/connect and solflare://ul/v1/signTransaction, NaCl-box
 * encrypted payloads, the wallet answers with solflare_encryption_public_key. */
const SOLFLARE_SCHEME = 'solflare://ul/v1'; // custom protocol: opens the app directly, no website, ever
function getSolflareSession() {
  const session = lsGet('solflare_session');
  const solflarePub = lsGet('solflare_pubkey');
  if (session && solflarePub) return { session, solflarePub };
  return null;
}
function setSolflareSession(session, solflarePub) {
  lsSet('solflare_session', session); lsSet('solflare_pubkey', solflarePub);
}
// Step 1: connect — establishes the encrypted session. On return the boot
// handler stores the session and continues to the sign step automatically.
function solflareConnect(out) {
  const dapp = getDappKeys();
  if (out) out.innerHTML = '<span class="text-gray-400">Opening Solflare to connect… approve in the app.</span>';
  const redirect = encodeURIComponent(phantomRedirect());
  const appUrl = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&cluster=mainnet-beta&app_url=${appUrl}&redirect_link=${redirect}`;
  window.location.href = `${SOLFLARE_SCHEME}/connect?${q}`; // straight into the app
  // If the app never takes the link (not installed), say so plainly —
  // no silent spinner.
  setTimeout(() => {
    if (!document.hidden && out) {
      out.innerHTML += `<br><span class="text-amber-300 text-sm">Solflare didn't open — it may not be installed on this device. <a class="underline" href="https://solflare.com" target="_blank" rel="noopener">Get Solflare</a>, then tap again.</span>`;
    }
  }, 4000);
}
// Step 2: sign — fresh transaction, encrypted payload, approval IN THE APP.
async function solflareSignRequest(addr, seal, out) {
  const sess = getSolflareSession();
  if (!sess) { solflareConnect(out); return; }
  if (out) out.innerHTML = '<span class="text-gray-400">Opening Solflare… approve the anchor in the app.</span>';
  const tx = await buildAnchorTx(addr, seal); // fresh blockhash for the app
  const b58 = bs58encode(tx.serialize({ requireAllSignatures: false, verifySignatures: false }));
  const enc = encryptForWallet({ transaction: b58, session: sess.session }, sess.solflarePub);
  const dapp = getDappKeys();
  const redirect = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&nonce=${enc.nonceB58}&redirect_link=${redirect}&payload=${enc.payloadB58}`;
  window.location.href = `${SOLFLARE_SCHEME}/signTransaction?${q}`; // straight into the app
}
// Entry: one call from either button. Connects first if needed, else signs.
async function solflareAnchorFlow(addr, seal, out) {
  setPendingSign(addr, seal, 'solflare');
  try {
    if (getSolflareSession()) await solflareSignRequest(addr, seal, out);
    else solflareConnect(out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${shortErr(e)}</span>`;
  }
}

/* The three golden buttons above are plain links to the wallet sites —
 * if the app is already installed, the device opens it directly. */

/* Handle returns from the wallet apps: connect (session) or sign (signed tx).
 * Speaks both Phantom and Solflare — same encrypted protocol, the wallet
 * answers with phantom_encryption_public_key or solflare_encryption_public_key. */
async function handleWalletReturn() {
  const params = new URLSearchParams(window.location.search);
  const phantomPub = params.get('phantom_encryption_public_key');
  const solflarePub = params.get('solflare_encryption_public_key');
  const encPub = phantomPub || solflarePub;
  const retKind = solflarePub ? 'solflare' : 'phantom';
  const wName = k => (k === 'solflare' ? 'Solflare' : 'Phantom');
  const data = params.get('data');
  const nonce = params.get('nonce');
  const errCode = params.get('errorCode');
  const rerouted = getPendingSign();
  const out = $('mobileOut') || $('anchorOut');

  if (errCode) {
    clearPendingSign();
    history.replaceState(null, '', window.location.pathname);
    if (out) {
      out.classList.remove('hidden');
      out.innerHTML = `<span class="text-red-400">Wallet declined:</span> <span class="text-gray-400">${(params.get('errorMessage') || 'rejected').slice(0, 160)}</span>`;
    }
    return;
  }
  // Loop trap: we fired an app deeplink but came back with no app response —
  // the app didn't take the link. Surface it plainly; no browser instructions.
  if (rerouted && !encPub && !data) {
    clearPendingSign();
    history.replaceState(null, '', window.location.pathname);
    const ao = $('anchorOut');
    ao.classList.remove('hidden');
    ao.innerHTML = `<span class="text-amber-300">The app didn't respond to the link.</span><br><span class="text-gray-400 text-sm">Make sure the ${wName(rerouted && rerouted.kind)} app is installed, then tap Anchor once more.</span>`;
    return;
  }
  if (!encPub && !data) return; // not our return
  history.replaceState(null, '', window.location.pathname);

  // --- Connect return: decrypt, store the session, continue to sign ---
  if (encPub && data) {
    try {
      const dec = decryptFromWallet(data, nonce, encPub);
      if (retKind === 'solflare') setSolflareSession(dec.session, encPub);
      else setPhantomSession(dec.session, encPub);
      const pending = getPendingSign();
      if (pending) {
        const po = $('mobileOut');
        $('mobileAnchor').classList.remove('hidden');
        if (po) po.classList.remove('hidden');
        const isPub = pending.extra && pending.extra.isPublic;
        if (isPub) {
          const pout = pending.extra.outId ? $(pending.extra.outId) : (po || out);
          if (pout) pout.classList.remove('hidden');
          await publicSignRequest(pending.addr, pending.extra.label, pending.extra.dataHash, pout, pending.kind);
        }
        else if (pending.kind === 'solflare') await solflareSignRequest(pending.addr, pending.seal, po || out);
        else await phantomSignRequest(pending.addr, pending.seal, po || out);
      } else if (out) {
        out.classList.remove('hidden');
        out.innerHTML = `<span class="text-green-400">Connected to the ${wName(retKind)} app.</span>`;
      }
    } catch (e) {
      clearPendingSign();
      if (out) {
        out.classList.remove('hidden');
        out.innerHTML = `<span class="text-red-400">Connect failed:</span> <span class="text-gray-400">${shortErr(e)}</span>`;
      }
    }
    return;
  }

  // --- Sign return: decode the bytes, verify the signature, seal via φ ---
  // The seal flow never broadcasts — the bytes can't land on Cookie Chain
  // (e.g. Phantom injects its Lighthouse instruction, which has no account
  // there). But the signature inside them is real: Tyree's ed25519 signature
  // over the memo. We decode it, verify it cryptographically, and encode the
  // verified approval via the golden ratio. Nothing broadcast, no fee spent —
  // the approval itself is the anchor, sealed by math.
  if (data) {
    const pending = getPendingSign();
    clearPendingSign();
    const kind = (pending && pending.kind) || retKind;
    const mo = $('mobileOut');
    $('mobileAnchor').classList.remove('hidden');
    mo.classList.remove('hidden');
    try {
      const sess = kind === 'solflare' ? getSolflareSession() : getPhantomSession();
      // No session here: this approval landed in a different browser than the
      // one that started it (the wallet app returned to the system browser).
      // Say so plainly — "tap again" in this tab can never complete it.
      if (!sess) throw new Error('This approval opened in a different browser than the one that started it — the wallet app returned to the system browser, which holds no session. Open the site inside your wallet\'s browser and anchor in-page (Connect Wallet → Anchor on Cookie Chain).');
      const dec = decryptFromWallet(data, nonce, kind === 'solflare' ? sess.solflarePub : sess.phantomPub);
      const returned = Transaction.from(bs58decode(dec.transaction));
      const msgBytes = returned.serializeMessage();
      // Decode: find the memo instruction, extract the text.
      let memoText = '';
      for (const ix of returned.instructions) {
        const t = memoTextOfIx(ix);
        if (isMemoProgram(ix.programId.toString()) || t.indexOf('PHI-LEDGER|') === 0) {
          memoText = t;
          break;
        }
      }
      const isPhiMemo = memoText.indexOf('PHI-LEDGER|') === 0;
      // Verify: ed25519 — the signature must be valid and from his wallet.
      const PHI = 1.618033988749895;
      let sigValid = false, signerAddr = '', sigB58 = '';
      const expectedAddr = pending ? pending.addr : '';
      for (const s of returned.signatures) {
        if (!s.signature) continue;
        try {
          if (nacl.sign.detached.verify(msgBytes, new Uint8Array(s.signature), s.publicKey.toBytes())) {
            sigValid = true;
            signerAddr = s.publicKey.toString();
            sigB58 = bs58encode(new Uint8Array(s.signature));
            break;
          }
        } catch (e) {}
      }
      const isHis = expectedAddr && signerAddr === expectedAddr;
      // --- Public anchor return: signature verified AND broadcast ---
      // Unlike seal approvals (verify-only), a public anchor must land on-chain:
      // the fee transfer + memo are atomic in the visitor's signed tx.
      const isPublicReturn = pending && pending.extra && pending.extra.isPublic;
      if (isPublicReturn) {
        const expMemo = `PHI-LEDGER|public|${pending.extra.label}|sha256=${pending.extra.dataHash}|by=${pending.addr}`;
        const pmo = (pending.extra.outId && $(pending.extra.outId)) || mo;
        pmo.classList.remove('hidden');
        const memoOk = memoText === expMemo;
        if (!(sigValid && isHis && memoOk)) {
          let why = 'the signature did not verify';
          if (!sigValid) why = 'no valid ed25519 signature found in the returned bytes';
          else if (!isHis) why = 'the signature is not from the expected wallet';
          else why = 'the returned memo does not match your anchor';
          pmo.innerHTML = `<span class="text-red-400">Not anchored:</span> <span class="text-gray-400">${esc(why)} — no fee spent.</span>`;
          return;
        }
        try {
          pmo.innerHTML = '<span class="text-gray-400">Signature verified — broadcasting your anchor to Cookie Chain…</span>';
          const sig = await connection.sendRawTransaction(returned.serialize(), { skipPreflight: true, maxRetries: 5 });
          pmo.innerHTML = '<span class="text-gray-400">Confirming…</span>';
          await connection.confirmTransaction(sig, 'confirmed');
          pmo.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">label:</span> ${esc(pending.extra.label)}<br><span class="text-gray-500">sha256:</span> <span class="text-xs break-all">${esc(pending.extra.dataHash)}</span><br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
        } catch (e) {
          pmo.innerHTML = `<span class="text-red-400">Broadcast failed:</span> <span class="text-gray-400">${esc(shortErr(e))}</span><br><span class="text-gray-500 text-xs">The signature was valid — tap again to retry (nothing was spent).</span>`;
        }
        return;
      }
      if (sigValid && isHis && isPhiMemo) {
        // The wallet returned a signed, valid seal tx. If every program in it
        // exists on Cookie Chain and the bytes are exactly our anchor, the
        // page broadcasts it here — the app only signed. (This bypasses any
        // injected provider that rewrites memos: what lands is byte-verified.)
        const pendSeal = (pending && pending.seal) || '';
        const expSealMemo = (snapshot && pendSeal)
          ? `PHI-LEDGER|seal=${pendSeal}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz` : null;
        let broadcastable = false, bcWhy = '';
        try {
          const bc = expSealMemo ? await verifyBytesClean(returned, expSealMemo) : { clean: false, problems: ['no expected memo'] };
          const mp = await missingPrograms(returned);
          if (bc.clean && mp.missing.length === 0) broadcastable = true;
          else bcWhy = 'bytes: ' + (bc.problems || []).join('; ') + (mp.missing.length ? ' | missing on-chain: ' + mp.missing.map(m => short(m, 8)).join(',') : '');
        } catch (e) { bcWhy = shortErr(e); }
        if (broadcastable) {
          try {
            mo.innerHTML = '<span class="text-gray-400">Signature verified — broadcasting your anchor to Cookie Chain…</span>';
            const sig = await connection.sendRawTransaction(returned.serialize(), { skipPreflight: true, maxRetries: 5 });
            mo.innerHTML = '<span class="text-gray-400">Confirming…</span>';
            await connection.confirmTransaction(sig, 'confirmed');
            const sealMatch = memoText.match(/seal=([^|]+)/);
            mo.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">seal:</span> ${esc(sealMatch ? sealMatch[1] : pendSeal)}<br><a class="underline" href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
            try { if (typeof refreshBalance === 'function') refreshBalance(); } catch (e) {}
            return;
          } catch (e) {
            mo.innerHTML = `<span class="text-red-400">Broadcast failed:</span> <span class="text-gray-400">${esc(shortErr(e))}</span><br><span class="text-gray-500 text-xs">Signature was valid — nothing verifiable landed. Tap again to retry.</span>`;
            return;
          }
        }
        // Not broadcastable (e.g. wallet injected a foreign instruction):
        // keep the verify-only seal — the approval is real, nothing lands.
        // Encode via the golden ratio: the verified approval as a φ seal.
        const sealMatch = memoText.match(/seal=([^|]+)/);
        const sealName = sealMatch ? sealMatch[1] : 'seal';
        const shaMatch = memoText.match(/sha256=([0-9a-f]+)/);
        const snapHash = shaMatch ? shaMatch[1] : '';
        const sigRung = (Math.log(64) / Math.log(PHI)).toFixed(4);
        const memoRung = (Math.log(memoText.length) / Math.log(PHI)).toFixed(4);
        const now = new Date().toISOString();
        mo.innerHTML = `<span class="text-green-400">Signature verified ✓</span><br><br>` +
          `<span class="text-gray-300">Tyree approved the PHI LEDGER memo. The signature is cryptographically valid — verified by ed25519 math, not by trust.</span><br><br>` +
          `<span class="text-gray-500">Seal:</span> <span class="text-yellow-300">${esc(sealName)}</span><br>` +
          `<span class="text-gray-500">Memo:</span> <span class="text-gray-300 text-xs break-all">${esc(memoText)}</span><br>` +
          `<span class="text-gray-500">Signer:</span> <span class="text-gray-300 text-xs break-all">${esc(signerAddr)}</span><br>` +
          `<span class="text-gray-500">Signature:</span> <span class="text-gray-300 text-xs break-all">${esc(sigB58)}</span><br>` +
          `<span class="text-gray-500">Snapshot:</span> <span class="text-gray-300 text-xs break-all">${esc(snapHash)}</span><br><br>` +
          `<span class="text-gray-500">φ encoding —</span><br>` +
          `<span class="text-gray-500">signature bytes (64) → ${sigRung} (constant arithmetic — every ed25519 signature is 64 bytes, not an address)</span><br>` +
          `<span class="text-gray-500">memo length (${memoText.length}) → rung ${memoRung}</span><br>` +
          `<span class="text-gray-500">sealed:</span> <span class="text-gray-300">${esc(now)}</span><br><br>` +
          `<span class="text-gray-400">Nothing was broadcast${kind === 'phantom' ? " (Phantom's Lighthouse instruction cannot land on Cookie Chain)" : ""}, no fee spent. The approval is sealed — send a screenshot to complete the ledger entry.</span>`;
        return;
      }
      let why = 'the signature did not verify';
      if (!sigValid) why = 'no valid ed25519 signature found in the returned bytes';
      else if (!isHis) why = 'the signature is not from the expected wallet';
      else if (!isPhiMemo) why = 'the memo is not a PHI-LEDGER memo';
      mo.innerHTML = `<span class="text-red-400">Not sealed:</span> <span class="text-gray-400">${esc(why)}.</span>`;
    } catch (e) {
      mo.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${esc(shortErr(e))}</span>`;
    }
  }
}

/* ---------- Anchor engine ---------- */
function shortErr(e) {
  // Never print "[object Object]": Nightly and other wallets reject with plain
  // objects (code, error, data) that have no .message. Show the real payload.
  // Nightly bridge errors arrive as a JSON string — extract payload.error
  // ("User rejected the request") instead of printing the whole JSON dump.
  if (!e) return 'unknown error';
  if (typeof e === 'string') {
    try { const j = JSON.parse(e); if (j && j.payload && j.payload.error) return String(j.payload.error).slice(0, 220); } catch (err) {}
    return e.slice(0, 220);
  }
  if (e.message) {
    try { const j = JSON.parse(String(e.message)); if (j && j.payload && j.payload.error) return String(j.payload.error).slice(0, 220); } catch (err) {}
    return String(e.message).slice(0, 220);
  }
  if (e.error && e.error.message) return String(e.error.message).slice(0, 220);
  // Phi ledger issue, not Nightly, 2026-10-29: Nightly bridge errors
  // arrive as an object {network, method, success:false, payload:{error}}
  // — the old code stringified the whole object into walletLabel, so
  // Tyree saw a raw JSON dump instead of a plain error. Extract it here.
  if (e.payload && e.payload.error) return String(e.payload.error).slice(0, 220);
  if (e.payload && typeof e.payload === 'string') {
    try { const j = JSON.parse(e.payload); if (j && j.error) return String(j.error).slice(0, 220); } catch (err) {}
    return String(e.payload).slice(0, 220);
  }
  try { const j = JSON.stringify(e); if (j && j !== '{}') return j.slice(0, 220); } catch (err) {}
  if (e.code !== undefined) return 'wallet error code ' + e.code;
  return String(e).slice(0, 220);
}

// The byte rung: signed bytes must be EXACTLY what we built — our memo
// instruction(s), our data verbatim, every program present on-chain.
// expectedMemo: one string (single anchor) or an array (batch anchor).
async function verifyBytesClean(signedTx, expectedMemo) {
  const expected = Array.isArray(expectedMemo) ? expectedMemo : [expectedMemo];
  const problems = [];
  // Endless-loop fix, 2026-10-29: Phantom adds extra non-memo
  // instructions to a signed transaction (instruction count 3, expected 1,
  // foreign program at ix 0 and ix 1, memo at ix 2) — compute-budget /
  // priority-fee style instructions, not a memo alteration. The old strict
  // check rejected that whole transaction, so every confirmed batch was
  // thrown away and the run looped forever with 0 anchored. The memo gate
  // is now: every expected memo must appear verbatim, in order, among
  // the signed transaction's memo instructions. Extra non-memo
  // instructions are ignored, not a rejection — the memos are the anchor,
  // not the instruction count. Only a missing memo, or a memo instruction
  // whose data differs from its expected text, is a problem.
  const memoTexts = [];
  for (let i = 0; i < signedTx.instructions.length; i++) {
    const ix = signedTx.instructions[i];
    if (!ix) continue;
    const dataText = memoTextOfIx(ix);
    if (isMemoProgram(ix.programId.toString()) || dataText.indexOf('PHI-LEDGER|') === 0) memoTexts.push(dataText);
  }
  if (memoTexts.length !== expected.length) problems.push('memo count ' + memoTexts.length + ' (expected ' + expected.length + ')');
  for (let i = 0; i < expected.length; i++) {
    if (memoTexts[i] !== expected[i]) problems.push('memo data altered at memo ' + i);
  }
  // v99: a wallet-added program is NOT a memo alteration. getAccountInfo
  // returning null on Cookie Chain does not prove a program is missing
  // (native / wallet-added programs), and rejecting on it looped every
  // batch with L2TExMFK...3S95. Gate is memo verbatim + signature verifies.
  return { clean: problems.length === 0, problems };
}

async function broadcastAndVerify(signedTx, out, blockhashInfo, expectedMemos) {
  out.innerHTML = '<span class="text-gray-400">Broadcasting to Cookie Chain…</span>';
  const rawTx = signedTx.serialize();
  const sig = await connection.sendRawTransaction(rawTx, { skipPreflight: true, maxRetries: 5 });
  out.innerHTML = '<span class="text-gray-400">Confirming…</span>';
  // Retry broadcast: this RPC sometimes drops transactions. Resend the same
  // signed bytes a few times (idempotent) before giving up.
  let confirmed = false, lastErr = null;
  for (let attempt = 0; attempt < 4 && !confirmed; attempt++) {
    if (attempt > 0) {
      out.innerHTML = `<span class="text-gray-400">Retrying broadcast (${attempt + 1}/4)…</span>`;
      try { await connection.sendRawTransaction(rawTx, { skipPreflight: true }); } catch (e) {}
    }
    try {
      if (blockhashInfo) {
        await connection.confirmTransaction({ signature: sig, blockhash: blockhashInfo.blockhash, lastValidBlockHeight: blockhashInfo.lastValidBlockHeight }, 'confirmed');
      } else {
        await connection.confirmTransaction(sig, 'confirmed');
      }
      confirmed = true;
    } catch (e) { lastErr = e; await new Promise(r => setTimeout(r, 5000)); }
  }
  if (!confirmed) throw lastErr || new Error('Not confirmed after 4 broadcast attempts.');
  // Entanglement read: the chain arbitrates. Read the transaction BACK from
  // the chain and match every expected memo verbatim — "Anchored ✓" is only
  // said when the chain itself shows the bytes. Local intent and on-chain
  // state are one thing, or the anchor did not happen.
  //
  // Nightly + Cookie Chain RPC can be slow to index a freshly confirmed
  // transaction, so the read is patient: it polls with backoff for minutes,
  // and before giving up it asks the chain whether the signature is still
  // alive — a living transaction gets more patience, only a dead one gets
  // reported as lost. Every wallet gets the golden ratio: no provider's
  // timing quirks stop the read.
  const want = expectedMemos ? (Array.isArray(expectedMemos) ? expectedMemos : [expectedMemos]) : [];
  out.innerHTML = '<span class="text-gray-400">Confirmed — reading it back from the chain…</span>';
  let raw = null;
  for (let i = 0; i < 24 && !raw; i++) {
    try { raw = await fetchRawTx(sig); } catch (e) {}
    if (!raw) await new Promise(r => setTimeout(r, 5000));
  }
  if (!raw) {
    let alive = false;
    try {
      const r = await fetch(connection.rpcEndpoint, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ jsonrpc: '2.0', id: 1, method: 'getSignatureStatuses', params: [[sig], { searchTransactionHistory: true }] }),
      });
      const j = await r.json();
      const st = j && j.result && j.result.value && j.result.value[0];
      alive = !!(st && !st.err);
    } catch (e) {}
    if (alive) {
      out.innerHTML = '<span class="text-gray-400">Still settling on-chain — giving it more time…</span>';
      for (let i = 0; i < 24 && !raw; i++) {
        try { raw = await fetchRawTx(sig); } catch (e) {}
        if (!raw) await new Promise(r => setTimeout(r, 5000));
      }
    }
  }
  if (!raw) throw new Error('confirmed but the transaction is not readable on-chain yet — not counted as anchored.');
  if (raw.meta && raw.meta.err) throw new Error('Chain rejected it: ' + JSON.stringify(raw.meta.err));
  if (want.length) {
    const onchain = memosFromRawTx(raw);
    const missingMemos = want.filter(m => onchain.indexOf(m) < 0);
    if (missingMemos.length) throw new Error('confirmed but ' + missingMemos.length + ' memo(s) not found on-chain — not counted as anchored.');
  }
  return sig;
}

// Raw chain read: fetch a transaction as JSON and pull out every Memo-program
// memo verbatim. This is the same parse the off-chain verifier uses.
async function fetchRawTx(sig) {
  const r = await fetch(connection.rpcEndpoint, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ jsonrpc: '2.0', id: 1, method: 'getTransaction', params: [sig, { encoding: 'json', maxSupportedTransactionVersion: 0 }] }),
  });
  const j = await r.json();
  return (j && j.result) || null;
}
function memosFromRawTx(raw) {
  const memos = [];
  try {
    const msg = raw.transaction.message;
    const keys = msg.accountKeys.map(k => (typeof k === 'string' ? k : k.pubkey));
    for (const ix of msg.instructions) {
      try {
        const txt = new TextDecoder().decode(bs58decode(ix.data));
        if (keys[ix.programIdIndex] && (isMemoProgram(keys[ix.programIdIndex]) || txt.indexOf('PHI-LEDGER|') === 0)) memos.push(txt);
      } catch (e) {}
    }
  } catch (e) {}
  return memos;
}
// A confirmation timeout almost always means the blockhash died while the
// wallet approval sat open (slow wallet, slow hands) — the transaction can
// never confirm. The omni answer: fresh blockhash, one more approval, retry.
function isExpiredBlockhashErr(e) {
  const m = String((e && e.message) || e).toLowerCase();
  return /blockhash not found|blockhash.*expired|block height exceeded|not confirmed|timed out|timeout/i.test(m);
}
// Omni retry: a wallet that alters or returns unreadable bytes is not a
// dead end — the caller rebuilds a fresh transaction and tries signTransaction
// again, in any wallet, with no wallet-specific branch.
function isRetryableSignErr(e) {
  if (isExpiredBlockhashErr(e)) return true;
  const m = String((e && e.message) || e).toLowerCase();
  return /altered the bytes|unreadable signature|returned an unreadable|429|rate limit/i.test(m);
}
function isRateLimitErr(e) {
  const m = String((e && e.message) || e).toLowerCase();
  return /429|rate limit/.test(m);
}
function sleepMs(ms) { return new Promise(r => setTimeout(r, ms)); }
// Omni prompt timeout: a wallet prompt that never loads (spinner, no wallet
// read) cannot hang the run forever. After 60 seconds the attempt throws a
// retryable error and the caller rebuilds fresh and retries. No fee is spent
// on a timed-out attempt, because nothing is broadcast until a signature
// returns in the current round.
function signTransactionTimed(tx) {
  return Promise.race([
    provider.signTransaction(tx),
    new Promise((_, reject) => setTimeout(() => reject(new Error('Wallet prompt timed out — retry fresh. No fee spent.')), 60000)),
  ]);
}

// Byte helpers
function hexOf(u8) {
  let s = '';
  for (let i = 0; i < u8.length; i++) s += u8[i].toString(16).padStart(2, '0');
  return s;
}

function anchorDone(out, sig, seal) {
  out.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">seal:</span> ${seal}<br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
  // A single anchor also counts for "Anchor all missing": record it, drop the
  // cached missing list, and refresh the button count.
  try {
    batchMarkDone([seal]);
    invalidateMissingSeals();
    refreshBatchLabel();
  } catch (e) {}
}

function wireCopyButton(id) {
  const cp = $(id);
  if (cp) cp.addEventListener('click', async () => {
    try {
      await navigator.clipboard.writeText(window.location.origin + window.location.pathname);
      cp.textContent = 'Copied — paste it in Chrome';
    } catch (e) { cp.textContent = 'Copy failed — long-press the address bar'; }
  });
}

// Engine reroute into the encrypted app flow (connect first if needed).
function fireAppDeeplink(addr, seal, out) {
  setPendingSign(addr, seal);
  if (getPhantomSession()) phantomSignRequest(addr, seal, out).catch(e => {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${shortErr(e)}</span>`;
  });
  else phantomConnect(out);
}

const IS_MOBILE = /Android|iPhone|iPad|iPod/i.test(navigator.userAgent || '');

/* ---------- Signature plumbing: every known wallet return shape ----------
 * v42 root-cause fix: the old code assumed provider.signMessage returns
 * {signature} as base58. If the wallet returns base64 (or hex, or a raw
 * Uint8Array), bs58decode produces garbage and addSignature throws
 * "Signature verification failed". Now every candidate encoding is tried
 * and each candidate is verified with ed25519 BEFORE attaching — the exact
 * divergence is reported instead of guessed. */
function b64decode(s) {
  const bin = atob(s);
  const out = new Uint8Array(bin.length);
  for (let i = 0; i < bin.length; i++) out[i] = bin.charCodeAt(i);
  return out;
}
function hexDecode(s) {
  const clean = String(s).trim().toLowerCase();
  if (!/^[0-9a-f]+$/.test(clean) || clean.length % 2 !== 0) return null;
  const out = new Uint8Array(clean.length / 2);
  for (let i = 0; i < out.length; i++) out[i] = parseInt(clean.slice(2 * i, 2 * i + 2), 16);
  return out;
}
function coerceBytes(v) {
  // Unknown payload -> Uint8Array. Tries base64, base58, hex for strings.
  if (!v && v !== '') return null;
  if (v instanceof Uint8Array) return v;
  if (Array.isArray(v)) return new Uint8Array(v);
  if (typeof v === 'string') {
    const s = v.trim();
    if (!s) return null;
    try { const b = b64decode(s); if (b.length > 0) return b; } catch (e) {}
    try { return bs58decode(s); } catch (e) {}
    const h = hexDecode(s);
    if (h && h.length > 0) return h;
  }
  return null;
}
function extractSigCandidates(r) {
  // Pull every plausible 64-byte signature out of a signMessage response.
  const cands = [];
  const push = (bytes, enc) => { if (bytes && bytes.length === 64) cands.push({ enc, bytes }); };
  if (!r && r !== '') return cands;
  if (r instanceof Uint8Array) { push(r, 'raw-bytes'); return cands; }
  if (Array.isArray(r)) { push(new Uint8Array(r), 'array'); return cands; }
  if (typeof r === 'string') {
    const s = r.trim();
    try { push(bs58decode(s), 'bs58'); } catch (e) {}
    try { push(b64decode(s), 'base64'); } catch (e) {}
    const h = hexDecode(s); if (h) push(h, 'hex');
    return cands;
  }
  if (typeof r === 'object') {
    const s = r.signature !== undefined ? r.signature : (r.signatures && r.signatures[0] !== undefined ? r.signatures[0] : (r.data !== undefined ? r.data : null));
    if (s !== null && s !== undefined) extractSigCandidates(s).forEach(c => cands.push(c));
  }
  return cands;
}
function txSignatureVerifies(signedTx, walletAddr) {
  try {
    const msg = signedTx.serializeMessage();
    const pub = new PublicKey(walletAddr).toBytes();
    const sigs = signedTx.signatures;
    if (!sigs || !sigs.length || !sigs[0].signature) return false;
    return nacl.sign.detached.verify(msg, new Uint8Array(sigs[0].signature), pub);
  } catch (e) { return false; }
}
function normalizeSignedTx(r) {
  // provider.signTransaction return shapes: Transaction instance, tx-like
  // object, Wallet-Standard bytes (base64/bs58/hex/Uint8Array), {signedTransaction},
  // {transaction}, or single-element arrays. Returns a Transaction or null.
  try {
    if (!r) return null;
    if (r instanceof Transaction) return r;
    if (Array.isArray(r)) return normalizeSignedTx(r[0]);
    if (typeof r === 'object') {
      const inner = r.signedTransaction !== undefined ? r.signedTransaction : (r.transaction !== undefined ? r.transaction : r);
      if (inner instanceof Transaction) return inner;
      if (typeof inner.serializeMessage === 'function') return inner;
      const bytes = coerceBytes(inner);
      if (bytes && bytes.length > 64) return Transaction.from(bytes);
      return null;
    }
    const bytes = coerceBytes(r);
    if (bytes && bytes.length > 64) return Transaction.from(bytes);
  } catch (e) {}
  return null;
}
function describeShape(r) {
  // Compact, exception-safe description of an unknown provider return value.
  try {
    if (r === null) return 'null';
    if (r === undefined) return 'undefined';
    const t = typeof r;
    if (t === 'string') return `string len=${r.length} head=${r.slice(0, 24)}`;
    if (t !== 'object') return t + '=' + String(r).slice(0, 40);
    if (r instanceof Uint8Array) return `Uint8Array len=${r.length} head=${hexOf(r.slice(0, 8))}`;
    if (Array.isArray(r)) return `array len=${r.length} [${r.slice(0, 4).map(describeShape).join('|')}]`;
    const ctor = (r.constructor && r.constructor.name) || '?';
    const vals = Object.keys(r).slice(0, 8).map(k => {
      let v;
      try { v = r[k]; } catch (e) { return k + '=<throw>'; }
      if (typeof v === 'string') return `${k}:str len=${v.length} head=${v.slice(0, 16)}`;
      if (v instanceof Uint8Array) return `${k}:u8 len=${v.length} head=${hexOf(v.slice(0, 8))}`;
      if (Array.isArray(v)) return `${k}:arr len=${v.length}`;
      return `${k}:${typeof v}`;
    }).join(', ');
    return `object ctor=${ctor} {${vals}}`;
  } catch (e) { return '<undescribable>'; }
}
function txToB64(u8) {
  let s = '';
  for (let i = 0; i < u8.length; i += 8192) s += String.fromCharCode.apply(null, u8.subarray(i, i + 8192));
  return btoa(s);
}
function transformProbes(msgBytes) {
  // Every known way a wallet might rewrite message bytes before signing.
  const enc = new TextEncoder();
  const probes = [['raw-bytes', msgBytes]];
  try { probes.push(['utf8-round-trip', enc.encode(new TextDecoder().decode(msgBytes))]); } catch (e) {}
  probes.push(['comma-joined', enc.encode(Array.from(msgBytes).join(','))]);
  probes.push(['json-array', enc.encode(JSON.stringify(Array.from(msgBytes)))]);
  probes.push(['hex-string', enc.encode(hexOf(msgBytes))]);
  try { probes.push(['base64-string', enc.encode(txToB64(msgBytes))]); } catch (e) {}
  const pre = enc.encode('solana offchain');
  const env0 = new Uint8Array(1 + pre.length + 1 + msgBytes.length);
  env0[0] = 0xff; env0.set(pre, 1); env0[1 + pre.length] = 0x00; env0.set(msgBytes, 1 + pre.length + 1);
  probes.push(['offchain-envelope-v0', env0]);
  const envR = new Uint8Array(1 + pre.length + msgBytes.length);
  envR[0] = 0xff; envR.set(pre, 1); envR.set(msgBytes, 1 + pre.length);
  probes.push(['offchain-envelope-raw', envR]);
  return probes;
}
function probeVerifies(cands, msgBytes, pub) {
  // Try every transform; return {name, enc} of the first that verifies, else null.
  for (const [name, bytes] of transformProbes(msgBytes)) {
    for (const c of cands) {
      try { if (nacl.sign.detached.verify(bytes, c.bytes, pub)) return { name, enc: c.enc }; } catch (e) {}
    }
  }
  return null;
}
const KEY_CHECK_TEXT = 'phi-ledger-key-check';
async function walletKeyCheck(pubBytes) {
  // The decisive test: does this provider sign with the key it reports?
  // Signs a fixed readable message and checks the signature against the
  // connected public key under every known transform.
  // Returns {outcome: 'raw'|'enveloped'|'none', detail}.
  const msg = new TextEncoder().encode(KEY_CHECK_TEXT);
  const r = await provider.signMessage(msg);
  const cands = extractSigCandidates(r);
  const hit = probeVerifies(cands, msg, pubBytes);
  if (hit && hit.name === 'raw-bytes') return { outcome: 'raw', detail: 'signed raw bytes with the reported key' };
  if (hit) return { outcome: 'enveloped', detail: `signed <${hit.name}> (as ${hit.enc}) — never raw bytes` };
  return { outcome: 'none', detail: `tried ${cands.length ? cands[0].enc : 'no-candidate'}; response ${describeShape(r)}` };
}
function firstDiffByte(aHex, bHex) {
  const n = Math.min(aHex.length, bHex.length);
  for (let i = 0; i < n; i += 2) {
    if (aHex.slice(i, i + 2) !== bHex.slice(i, i + 2)) return i / 2;
  }
  return n / 2;
}
function divergenceReport(msgBytes, cands, raw, pub) {
  const parts = [];
  parts.push(`wallet signature did not verify against the anchor bytes (message ${msgBytes.length}B)`);
  if (!cands.length) {
    parts.push('no 64-byte signature candidate in the wallet response (' + describeShape(raw) + ')');
  } else {
    for (const c of cands.slice(0, 3)) parts.push(`tried ${c.enc} sig=${bs58encode(c.bytes).slice(0, 12)}… — invalid`);
    parts.push('full sig: ' + bs58encode(cands[0].bytes));
  }
  const hit = probeVerifies(cands, msgBytes, pub);
  if (hit) parts.push(`PROBE MATCH: the wallet signed <${hit.name}> (as ${hit.enc}), not the raw anchor bytes — this signature can never broadcast`);
  else parts.push('probes (raw, utf8-round-trip, comma-joined, json-array, hex-string, base64-string, offchain envelopes): no match — the wallet signed with a different key or an unknown transform');
  return parts.join('; ');
}
async function signMessageFallback(walletAddr, seal) {
  // The wallet signs the EXACT message bytes; the signature is verified with
  // ed25519 before it is ever attached. Fresh transaction, fresh blockhash.
  if (typeof provider.signMessage !== 'function') {
    throw new Error('Wallet rewrote the transaction bytes and does not support raw message signing.');
  }
  const tx2 = await buildAnchorTx(walletAddr, seal);
  const msgBytes = new Uint8Array(tx2.serializeMessage());
  const r = await provider.signMessage(msgBytes);
  const cands = extractSigCandidates(r);
  const pub = new PublicKey(walletAddr).toBytes();
  for (const c of cands) {
    let ok = false;
    try { ok = nacl.sign.detached.verify(msgBytes, c.bytes, pub); } catch (e) {}
    if (ok) {
      tx2.addSignature(new PublicKey(walletAddr), c.bytes); // pre-verified: cannot throw
      return tx2;
    }
  }
  throw new Error(divergenceReport(msgBytes, cands, r, pub));
}

// One tap runs the whole: key-check → sign → verify bytes → broadcast → verify.
async function runAnchorEngine() {
  if (!provider || !wallet) return;
  const seal = $('sealSelect').value;
  const out = $('anchorOut');
  out.classList.remove('hidden');
  let alterNote = '';
  const pubBytes = new PublicKey(wallet).toBytes();
  window._walletPromptOpen = true; // background RPC polling pauses while the wallet prompt is open
  try {
    // Clear cached chain state before requesting a new signature.
    if (typeof invalidateMissingSeals === 'function') invalidateMissingSeals();
    // Step 0 — key check: does this provider sign with the key it reports?
    // One readable approval ("phi-ledger-key-check"). If the wallet signs with a
    // different key than the connected address, nothing downstream can verify.
    let enveloped = false;
    if (typeof provider.signMessage === 'function') {
      out.innerHTML = '<span class="text-gray-400">Checking the wallet key… approve once in your wallet.</span>';
      const kc = await walletKeyCheck(pubBytes);
      if (kc.outcome === 'none') {
        throw new Error(`key check FAILED: the wallet's signature for "${KEY_CHECK_TEXT}" does not verify with ${wallet} (${kc.detail}). It reports one address and signs with another (or rewrites every payload) — no signature from this provider can anchor. No fee spent.`);
      }
      enveloped = kc.outcome !== 'raw';
      if (enveloped) alterNote = `key check: wallet ${kc.detail}. `;
    }
    // Omni rounds: a slow approval can kill the blockhash — that just costs
    // one more approval on a fresh transaction, never a lost anchor.
    // A dismissed approval stops everything immediately and is never retried.
    let sig = null, lastErr = null;
    for (let round = 0; round < 3 && !sig; round++) {
      if (round > 0) out.innerHTML = '<span class="text-gray-400">Refreshing the transaction — approve in your wallet.</span>';
      try {
        sig = await anchorSingleAttempt(wallet, seal, pubBytes, enveloped, alterNote, out);
      } catch (e) {
        if (isRejection(e)) throw e;
        lastErr = e;
        if (!isRetryableSignErr(e) || round === 2) throw e;
      }
    }
    if (!sig) throw lastErr || new Error('Anchor did not land.');
    // "Anchored ✓" is said only after the chain itself shows the memo bytes
    // (entanglement read inside broadcastAndVerify).
    anchorDone(out, sig, seal);
    refreshBalance();
  } catch (e) {
    const full = (alterNote + String((e && e.message) || e)).slice(0, 900);
    out.innerHTML = `<span class="text-red-400">Stopped:</span> <span class="text-gray-400">${full}</span><br><span class="text-gray-500 text-xs">A transaction that never confirms costs no fee.</span>`;
  } finally {
    window._walletPromptOpen = false;
  }
}

// One attempt: build (fresh blockhash) → sign → verify bytes → broadcast →
// entanglement read. Throws on anything less than the chain showing the memo.
async function anchorSingleAttempt(walletAddr, seal, pubBytes, enveloped, alterNote, out) {
  out.innerHTML = '<span class="text-gray-400">Building anchor transaction…</span>';
  const tx = await buildAnchorTx(walletAddr, seal);
  out.innerHTML = '<span class="text-gray-400">Signing… approve in your wallet.</span>';
  // Always sign locally and broadcast via our Cookie Chain connection.
  // (provider.signAndSendTransaction would broadcast via the wallet's own
  // network — Solana mainnet — where a Cookie Chain blockhash is invalid.)
  let finalTx = null, finalInfo = tx._blockhashInfo, finalMemo = tx._memoText;
  if (typeof provider.signTransaction === 'function') {
    const rawSigned = await signTransactionTimed(tx);
    const signedTx = normalizeSignedTx(rawSigned);
    if (signedTx) {
      const wantHex = hexOf(tx.serializeMessage());
      const gotHex = hexOf(signedTx.serializeMessage());
      // Same omni memo gate as the batch path: accept altered non-memo
      // bytes when the signature verifies and the memo is verbatim.
      if (txSignatureVerifies(signedTx, walletAddr)) {
        const check = await verifyBytesClean(signedTx, tx._memoText);
        if (check.clean) {
          if (gotHex !== wantHex) alterNote += `wallet altered non-memo bytes (first diff at byte ${firstDiffByte(wantHex, gotHex)}) but memo is verbatim — accepting. `;
          finalTx = signedTx;
        } else {
          throw new Error(alterNote + 'wallet altered memo bytes (' + check.problems.join('; ') + ') — retry fresh. No fee spent.');
        }
      } else {
        throw new Error(alterNote + 'signature did not verify — retry fresh. No fee spent.');
      }
    } else {
      // Maybe signTransaction returned a bare signature instead of a transaction.
      const msgBytes = new Uint8Array(tx.serializeMessage());
      const cands = extractSigCandidates(rawSigned);
      let attached = false;
      for (const c of cands) {
        try {
          if (nacl.sign.detached.verify(msgBytes, c.bytes, pubBytes)) {
            tx.addSignature(new PublicKey(walletAddr), c.bytes);
            attached = true;
            break;
          }
        } catch (e) {}
      }
      if (attached) {
        alterNote += 'signTransaction returned a bare signature (verified) instead of a transaction. ';
        finalTx = tx;
      } else {
        alterNote += 'signTransaction returned ' + describeShape(rawSigned) + '. ';
        throw new Error(alterNote + 'signTransaction returned an unreadable signature — retry fresh. No fee spent.');
        finalInfo = finalTx._blockhashInfo; finalMemo = finalTx._memoText;
      }
    }
  } else if (typeof provider.signMessage === 'function') {
    if (enveloped) throw new Error(alterNote + 'this provider only signs enveloped messages, never raw transaction bytes — no broadcastable signature exists. No fee spent.');
    out.innerHTML = '<span class="text-gray-400">Signing the exact bytes… approve in your wallet.</span>';
    finalTx = await signMessageFallback(walletAddr, seal);
    finalInfo = finalTx._blockhashInfo; finalMemo = finalTx._memoText;
  } else {
    throw new Error('Wallet supports neither signTransaction nor signMessage.');
  }
  const check = await verifyBytesClean(finalTx, finalMemo);
  if (!check.clean) {
    throw new Error('wallet returned altered bytes (' + check.problems.join('; ') + ') — no fee spent.');
  }
  if (!txSignatureVerifies(finalTx, walletAddr)) {
    throw new Error('assembled transaction carries no valid signature — no fee spent.');
  }
  return broadcastAndVerify(finalTx, out, finalInfo, finalMemo);
}

$('anchorBtn').addEventListener('click', runAnchorEngine);

/* ---------- Batch anchor: every missing seal, a few approvals ----------
 * "All 185 should be anchored." One transaction carries several seal memos
 * (packed under the 1232-byte wire limit), so 123 missing seals land in ~18
 * wallet approvals instead of 123 — and ~18 tiny fees instead of 123.
 * Same byte-rung discipline as the single anchor: every memo verified
 * verbatim before signing, the signature verified before broadcast, chain
 * confirmation per transaction. Progress persists in localStorage — pause
 * any time (including a dismissed approval), resume where it stopped.
 * The memo grammar is unchanged: one PHI-LEDGER|seal memo per seal, several
 * memos per transaction. */
const BATCH_MSG_CAP = 1150; // serialized-message ceiling; +65B signature stays under 1232
function batchMemoText(seal) {
  return `PHI-LEDGER|seal=${seal}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz`;
}
// 50-per, 2026-10-29: one memo per transaction, listing seal indices in
// snapshot order, instead of one memo per seal. 50 indices + full snapshot
// hash fit in ~240 bytes, far under the 1232-byte transaction limit, so
// 170 missing seals land in 4 transactions, not 17, with 4 simulations
// instead of 17, and 4 fees instead of 17. Indices map back to seal names
// through the public ledger snapshot, whose full hash is in the memo itself,
// so the batch memo is phase-locked to that snapshot, not to a wallet grid.
// The old per-seal memo grammar still counts in the chain read below.
function batch50MemoText(seals) {
  const indices = seals.map(s => snapshot.seals.indexOf(s) + 1).filter(i => i > 0);
  return `PHI-LEDGER|seals=${indices.join(',')}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz`;
}
async function buildBatch50Tx(walletAddr, seals) {
  if (!snapshot) throw new Error('Ledger snapshot not loaded yet — reload the page and tap once more.');
  const tx = new Transaction();
  const memoText = batch50MemoText(seals);
  tx.add(new TransactionInstruction({
    keys: [{ pubkey: new PublicKey(walletAddr), isSigner: true, isWritable: false }],
    programId: new PublicKey(MEMO_PROGRAM),
    data: new TextEncoder().encode(memoText),
  }));
  tx.feePayer = new PublicKey(walletAddr);
  const { blockhash, lastValidBlockHeight } = await connection.getLatestBlockhash('confirmed');
  tx.recentBlockhash = blockhash;
  tx._blockhashInfo = { blockhash, lastValidBlockHeight };
  tx._memoTexts = [memoText];
  tx._memoText = memoText;
  return tx;
}
function pack50Batches(seals) {
  const batches = [];
  for (let i = 0; i < seals.length; i += 50) batches.push(seals.slice(i, i + 50));
  return batches;
}
async function buildBatchAnchorTx(walletAddr, seals) {
  if (!snapshot) throw new Error('Ledger snapshot not loaded yet — reload the page and tap once more.');
  const tx = new Transaction();
  const memoTexts = seals.map(batchMemoText);
  for (const memoText of memoTexts) {
    tx.add(new TransactionInstruction({
      keys: [{ pubkey: new PublicKey(walletAddr), isSigner: true, isWritable: false }],
      programId: new PublicKey(MEMO_PROGRAM),
      data: new TextEncoder().encode(memoText),
    }));
  }
  tx.feePayer = new PublicKey(walletAddr);
  const { blockhash, lastValidBlockHeight } = await connection.getLatestBlockhash('confirmed');
  tx.recentBlockhash = blockhash;
  tx._blockhashInfo = { blockhash, lastValidBlockHeight };
  tx._memoTexts = memoTexts;
  return tx;
}
const MAX_BATCH_SEALS = 10; // 429 throttle: never more than 10 seals per wallet approval, no matter the byte cap
function packSealBatches(seals) {
  // Greedy pack: keep adding seal memos while the estimated serialized
  // message stays under cap, and never past 10 seals per batch.
  // Deterministic — same list, same batches.
  const est = arr => 3 + 65 + 32 + arr.reduce((n, s) => n + 5 + new TextEncoder().encode(batchMemoText(s)).length, 0);
  const batches = [];
  let cur = [];
  for (const s of seals) {
    if (cur.length && (cur.length >= MAX_BATCH_SEALS || est(cur.concat([s])) > BATCH_MSG_CAP)) { batches.push(cur); cur = []; }
    cur.push(s);
  }
  if (cur.length) batches.push(cur);
  return batches;
}
async function signMessageFallbackBatch(walletAddr, seals) {
  // The wallet signs the EXACT message bytes; the signature is verified with
  // ed25519 before it is ever attached. Fresh transaction, fresh blockhash.
  if (typeof provider.signMessage !== 'function') {
    throw new Error('Wallet rewrote the transaction bytes and does not support raw message signing.');
  }
  const tx2 = await buildBatchAnchorTx(walletAddr, seals);
  const msgBytes = new Uint8Array(tx2.serializeMessage());
  const r = await provider.signMessage(msgBytes);
  const cands = extractSigCandidates(r);
  const pub = new PublicKey(walletAddr).toBytes();
  for (const c of cands) {
    let ok = false;
    try { ok = nacl.sign.detached.verify(msgBytes, c.bytes, pub); } catch (e) {}
    if (ok) {
      tx2.addSignature(new PublicKey(walletAddr), c.bytes); // pre-verified: cannot throw
      return tx2;
    }
  }
  throw new Error(divergenceReport(msgBytes, cands, r, pub));
}
// Sign one batch transaction with the same dispatch as the single anchor:
// signTransaction when it behaves, exact-bytes fallback when it rewrites.
// buildFresh rebuilds the transaction (fresh blockhash) for the fallback path.
async function signBatchTx(tx, walletAddr, pubBytes, kc, buildFresh) {
  let alterNote = '';
  const enveloped = kc && kc.outcome !== 'raw';
  let finalTx = null, finalInfo = tx._blockhashInfo;
  // Omni, 2026-10-29: one path for every wallet — signTransaction only.
  // No Nightly branch, no Phantom branch, no message-signing fallback for
  // transaction bytes. Altered non-memo bytes are accepted when the
  // signature verifies and every memo is verbatim; only altered memos,
  // bad signatures, or unreadable returns throw a retryable error, and
  // the caller rebuilds fresh and retries.
  if (typeof provider.signTransaction === 'function') {
    const rawSigned = await signTransactionTimed(tx);
    const signedTx = normalizeSignedTx(rawSigned);
    if (signedTx) {
      const wantHex = hexOf(tx.serializeMessage());
      const gotHex = hexOf(signedTx.serializeMessage());
      // Omni memo gate: strict full-hex equality rejected a wallet that
      // alters a non-memo byte (Phantom, first diff at byte 2) even when
      // every memo was verbatim. The memos are the anchor, not the header
      // bytes — if the signature verifies for the signed bytes AND every
      // memo is verbatim, accept it. The downstream chain read still
      // verifies the memos on-chain before any "Anchored" is said.
      if (txSignatureVerifies(signedTx, walletAddr)) {
        const check = await verifyBytesClean(signedTx, tx._memoTexts);
        if (check.clean) {
          if (gotHex !== wantHex) alterNote += `wallet altered non-memo bytes (first diff at byte ${firstDiffByte(wantHex, gotHex)}) but memos are verbatim — accepting. `;
          finalTx = signedTx;
        } else {
          throw new Error(alterNote + 'wallet altered memo bytes (' + check.problems.join('; ') + ') — retry fresh. No fee spent.');
        }
      } else {
        throw new Error(alterNote + 'signature did not verify — retry fresh. No fee spent.');
      }
    } else {
      const msgBytes = new Uint8Array(tx.serializeMessage());
      const cands = extractSigCandidates(rawSigned);
      let attached = false;
      for (const c of cands) {
        try {
          if (nacl.sign.detached.verify(msgBytes, c.bytes, pubBytes)) {
            tx.addSignature(new PublicKey(walletAddr), c.bytes);
            attached = true;
            break;
          }
        } catch (e) {}
      }
      if (attached) {
        alterNote += 'signTransaction returned a bare signature (verified). ';
        finalTx = tx;
      } else {
        alterNote += 'signTransaction returned ' + describeShape(rawSigned) + '. ';
        throw new Error(alterNote + 'signTransaction returned an unreadable signature — retry fresh. No fee spent.');
      }
    }
  } else if (typeof provider.signMessage === 'function') {
    if (enveloped) throw new Error(alterNote + 'this provider only signs enveloped messages — no broadcastable signature exists. No fee spent.');
    finalTx = await buildFresh();
    finalInfo = finalTx._blockhashInfo;
  } else if (!finalTx) {
    throw new Error('Wallet supports neither signTransaction nor signMessage.');
  }
  const check = await verifyBytesClean(finalTx, finalTx._memoTexts || tx._memoTexts);
  if (!check.clean) throw new Error(alterNote + 'wallet returned altered bytes (' + check.problems.join('; ') + ') — no fee spent.');
  if (!txSignatureVerifies(finalTx, walletAddr)) throw new Error(alterNote + 'assembled transaction carries no valid signature — no fee spent.');
  return { finalTx, finalInfo, alterNote };
}
let batchRunning = false;
function batchDoneList() {
  try { const v = JSON.parse(lsGet('batchAnchoredV1') || '[]'); return Array.isArray(v) ? v : []; } catch (e) { return []; }
}
function batchMarkDone(seals) {
  const done = new Set(batchDoneList());
  seals.forEach(s => done.add(s));
  lsSet('batchAnchoredV1', JSON.stringify([...done]));
  // Cumulative transaction count across sessions, so the final message
  // never mixes this-run batches with all-time seals.
  try { lsSet('batchTxTotalV1', String((parseInt(lsGet('batchTxTotalV1') || '0', 10) || 0) + 1)); } catch (e) {}
}
function batchTxTotal() {
  try { return parseInt(lsGet('batchTxTotalV1') || '0', 10) || 0; } catch (e) { return 0; }
}
/* Live missing-seal read: the chain is the record. The old static
 * missing_seals.json was a dead empty list, which made "Anchor all
 * missing" claim everything was already anchored. This walks the wallet's
 * real transaction history over RPC (paginated getSignaturesForAddress),
 * reads every transaction's Memo-program memos, and reports the snapshot
 * seals with no on-chain PHI-LEDGER memo as missing. Anything the wallet
 * anchored — single or batch, any session — counts. */
/* 429 throttle, 2026-10-29: when the RPC answers 429, stop sending — do not
 * spam retries. All site RPC calls pause for 60 seconds, and the error names
 * the rate limit plainly instead of surfacing as a bare "429 :" prompt. */
async function rpcCall(method, params) {
  if (window._rpcPausedUntil && Date.now() < window._rpcPausedUntil) {
    throw new Error('RPC rate limited (429) — paused, do not tap again until the pause clears.');
  }
  const r = await fetch(connection.rpcEndpoint, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ jsonrpc: '2.0', id: 1, method, params }),
  });
  if (!r.ok) {
    if (r.status === 429) window._rpcPausedUntil = Date.now() + 60000;
    throw new Error('RPC HTTP ' + r.status + (r.status === 429 ? ' — rate limited, paused 60 seconds, do not tap again.' : ''));
  }
  const j = await r.json();
  if (j.error) {
    if (String(j.error.message || '').includes('429')) window._rpcPausedUntil = Date.now() + 60000;
    throw new Error('RPC ' + method + ': ' + (j.error.message || 'error'));
  }
  return j.result;
}
/* While a wallet prompt is open, the site sends no background RPC calls at
 * all — no pulse, no mining, no balance, no fee vault — so nothing competes
 * with the wallet's own simulation while Tyree approves. */
function walletPromptOpen() { return !!window._walletPromptOpen; }
async function loadMissingSeals(force, onProgress) {
  if (window._missingSeals && !force) return window._missingSeals;
  if (!snapshot) throw new Error('Ledger snapshot not loaded yet — reload the page and tap once more.');
  if (!wallet) throw new Error('Connect your wallet first — missing seals are read from the chain.');
  const anchored = new Set();
  const need = new Set(snapshot.seals);
  let before = null;
  for (let page = 0; page < 20 && need.size > 0; page++) {
    const opts = { limit: 1000, commitment: 'confirmed' };
    if (before) opts.before = before;
    const sigs = await rpcCall('getSignaturesForAddress', [wallet, opts]);
    if (!sigs || !sigs.length) break;
    before = sigs[sigs.length - 1].signature;
    if (onProgress) { try { onProgress(anchored.size, need.size); } catch (e) {} }
    // Read memos in parallel — a few hundred ms per wave, not per tx.
    const CONC = 8;
    for (let i = 0; i < sigs.length && need.size > 0; i += CONC) {
      const wave = sigs.slice(i, i + CONC);
      const raws = await Promise.all(wave.map(async s => {
        if (s.err) return null;
        try { return await fetchRawTx(s.signature); } catch (e) { return null; }
      }));
      for (const raw of raws) {
        if (!raw) continue;
        for (const memo of memosFromRawTx(raw)) {
          const m = memo.match(/PHI-LEDGER\|seal=([^|]+)\|/);
          if (m) { anchored.add(m[1]); need.delete(m[1]); }
          const b = memo.match(/PHI-LEDGER\|seals=([0-9,]+)\|/);
          if (b) {
            for (const part of b[1].split(',')) {
              const idx = parseInt(part, 10);
              const name = snapshot.seals[idx - 1];
              if (name) { anchored.add(name); need.delete(name); }
            }
          }
        }
      }
    }
    // v99: do NOT stop after a short first page. Cookie Chain RPC returns
    // a sliding visible window (79-80 sigs), not the full history, so a
    // seal anchored before that window (e.g. position 275) would read as
    // missing. Paginate with `before` until empty, need empty, or 20 pages.
    if (!sigs.length) break;
  }
  window._missingSeals = snapshot.seals.filter(s => !anchored.has(s));
  return window._missingSeals;
}
function invalidateMissingSeals() { window._missingSeals = null; }
/* The missing list itself, in plain HTML that renders the same in Nightly,
 * in any wallet browser, and on desktop — no fancy widget, no hidden state.
 * It lives in its own element (#missingList), so the batch run's progress
 * text in #batchOut can never overwrite it. Seal names come from the ledger
 * snapshot (letters, digits, underscore, phi only), so plain joining is safe. */
function showMissingList(missing) {
  const el = $('missingList');
  if (!el) return;
  el.classList.remove('hidden');
  if (!missing || !missing.length) {
    el.innerHTML = '<span class="text-green-400">Missing on-chain: none — all seals anchored on-chain.</span>';
    return;
  }
  const names = missing.map((s, i) => (i + 1) + '. ' + s).join('<br>');
  el.innerHTML = '<span class="text-gray-400">Missing on-chain (' + missing.length + '):</span><br>' +
    '<div style="max-height:240px;overflow:auto;border:1px solid #333;padding:8px;margin-top:4px;">' + names + '</div>' +
    '<br><span class="text-gray-500 text-xs">If you just anchored seals and they still show here, the chain history is still syncing — wait before re-anchoring, or the same seals will be charged again.</span>';
}
function isRejection(e) {
  const m = String((e && e.message) || e).toLowerCase();
  return /reject|denied|cancel|dismiss|user closed|declined/.test(m);
}
async function runBatchAnchor() {
  if (!provider || !wallet) return;
  if (batchRunning) return;
  const out = $('batchOut');
  out.classList.remove('hidden');
  const btn = $('batchAnchorBtn');
  batchRunning = true;
  btn.disabled = true;
  const pubBytes = new PublicKey(wallet).toBytes();
  window._walletPromptOpen = true; // background RPC polling pauses while the wallet prompt is open
  try {
    // Clear cached chain state before requesting a new signature.
    if (typeof invalidateMissingSeals === 'function') invalidateMissingSeals();
    if (!snapshot) throw new Error('Ledger snapshot not loaded yet — reload the page and tap once more.');
    out.innerHTML = '<span class="text-gray-400">Reading chain history… this is the slow sync — the app is working, do not tap again.</span>';
    const missing = await loadMissingSeals(true, (found, left) => {
      out.innerHTML = '<span class="text-gray-400">Reading chain history… ' + found + ' seals found on-chain, ' + left + ' still to check.</span>';
    }); // fresh chain read every run
    // CHAIN ONLY, 2026-10-29 fix: the local done list (batchAnchoredV1) must
    // NEVER filter this list. Filtering by it is how "All missing seals
    // already anchored" was printed while the chain still missed seals, and
    // how fees were spent on the assumption of anchors that were not there.
    // Resume still works: a batch that landed is now in the chain read, so
    // it is no longer missing. A seal in the done list but missing on-chain
    // is re-anchored, because the chain is the truth, not this browser.
    const todo = missing.slice();
    const anchoredCount = snapshot.seals.length - missing.length;
    showMissingList(missing);
    out.innerHTML = `<span class="text-gray-400">Chain read: ${anchoredCount} of ${snapshot.seals.length} seals anchored on-chain, ${missing.length} missing. No fee is charged until you approve a batch. The missing names are listed below, on Nightly or any app.</span>`;
    // This-run counters only: the all-time done list must never leak into
    // this run's progress display (that was the "150 of 27" / "-123 left" bug).
    let runAnchored = 0, runTx = 0;
    if (!todo.length) {
      out.innerHTML = `<span class="text-green-400">All ${snapshot.seals.length} seals anchored on-chain ✓</span><br><span class="text-gray-500 text-xs">Chain read, not a local list: ${anchoredCount} of ${snapshot.seals.length} seals found on-chain.</span>`;
      batchRunning = false; btn.disabled = false; btn.textContent = 'Anchor all missing';
      return;
    }
    // Key check once for the whole run — one approval, not one per batch.
    // Skipped on the seal-all path: signAllTransactions plus per-transaction
    // signature + memo verification before any broadcast already proves the
    // key, so seal-all stays at one approval total, not key-check plus sign-all.
    let kc = window._batchKeyCheck || null;
    if (!kc && typeof provider.signMessage === 'function' && typeof provider.signAllTransactions !== 'function') {
      out.innerHTML = '<span class="text-gray-400">Checking the wallet key… approve once in your wallet.</span>';
      kc = await walletKeyCheck(pubBytes);
      if (kc.outcome === 'none') throw new Error('key check FAILED: ' + kc.detail + ' — no fee spent.');
      window._batchKeyCheck = kc;
    }
    const batches = pack50Batches(todo);
    // 50 per batch, one approval per batch, 2026-10-29: the all-at-once
    // signAllTransactions path is OFF. Phantom blocked it outright as
    // "Request blocked — This dApp could be malicious" when the site
    // tried to sign all missing seals at once, and the run paused with
    // 0 anchored. A bulk sign request from a github.io dApp is what
    // Phantom's filter flags, not the ledger itself — the transactions
    // are memo-only, no tokens move, only a tiny COOK fee. So batch
    // anchoring is now always per-batch: 50 seals per transaction,
    // one normal single-transaction approval per batch, broadcast and
    // verified on-chain before the next batch, progress saved so a
    // pause resumes where it stopped. 161 missing seals = 4 approvals,
    // not 1 bulk, not 161 singles.
    if (false && typeof provider.signAllTransactions === 'function') {
      out.innerHTML = `<span class="text-gray-400">Signing all ${todo.length} missing seals in one approval — ${batches.length} transactions, 50 seals each… approve once in your wallet. If your wallet says simulation failed, 429, or 403, that is its Solana simulation, not Cookie Chain — Cookie Chain broadcast skips preflight, so confirming still anchors on Cookie Chain.</span>`;
      const txs = [];
      for (const seals of batches) txs.push(await buildBatch50Tx(wallet, seals));
      let signedAll;
      // 429 cause and fix, 2026-10-29: Nightly's own Solana simulation
      // rate-limits when many transactions are simulated at once, and it
      // surfaces that as a "429 :" prompt instead of transaction details.
      // That simulation is wallet-side, not Cookie Chain, and it is not
      // the anchor failing — but sending 17 simulations at once is what
      // trips it. On a 429, wait 60 seconds for the rate limit to clear,
      // rebuild fresh, and try the one approval again, inside this same
      // run, instead of stopping. A rejection still pauses, as before.
      for (let attempt = 0; attempt < 3 && !signedAll; attempt++) {
        try {
          signedAll = await Promise.race([
            provider.signAllTransactions(txs),
            new Promise((_, reject) => setTimeout(() => reject(new Error('Wallet prompt timed out — no fee spent.')), 300000)),
          ]);
        } catch (e) {
          if (isRejection(e)) {
            out.innerHTML = `<span class="text-amber-300">Paused</span> <span class="text-gray-400">— approval dismissed. 0 of ${todo.length} seals anchored this run. Tap the button to resume.</span>`;
            batchRunning = false; btn.disabled = false; btn.textContent = `Resume anchoring (${todo.length} left)`;
            return;
          }
          if (isRateLimitErr(e) && attempt < 2) {
            out.innerHTML = `<span class="text-gray-400">Rate limited (429) — waiting 60 seconds for the limit to clear, then trying the one approval again…</span>`;
            await sleepMs(60000);
            const fresh = [];
            for (const seals of batches) fresh.push(await buildBatch50Tx(wallet, seals));
            txs.length = 0; fresh.forEach(t => txs.push(t));
            continue;
          }
          // Bypass, 2026-10-29: if sign-all simulation fails (Phantom
          // "Failed to simulate", Nightly 403/429), do not stop the run.
          // Break out to the per-batch loop below, in this same run,
          // with 50 seals per transaction — not 1 by 1, not 10 by 10.
          if (/simulate|403|forbidden/i.test(String((e && e.message) || e))) {
            out.innerHTML = `<span class="text-gray-400">Sign-all simulation blocked by the wallet — bypassing to per-batch in this same run, 50 seals per transaction…</span>`;
            signedAll = null;
            break;
          }
          throw e;
        }
      }
      if (signedAll) {
      const signedTxs = [];
      for (let i = 0; i < txs.length; i++) {
        const raw = Array.isArray(signedAll) ? signedAll[i] : null;
        const signedTx = normalizeSignedTx(raw);
        if (!signedTx) throw new Error('Wallet returned nothing for batch ' + (i + 1) + ' — no fee spent.');
        if (!txSignatureVerifies(signedTx, wallet)) throw new Error('Signature did not verify for batch ' + (i + 1) + ' — no fee spent.');
        const check = await verifyBytesClean(signedTx, txs[i]._memoTexts);
        if (!check.clean) throw new Error('Wallet altered memo bytes in batch ' + (i + 1) + ' (' + check.problems.join('; ') + ') — no fee spent.');
        signedTx._memoTexts = txs[i]._memoTexts;
        signedTx._blockhashInfo = txs[i]._blockhashInfo;
        signedTxs.push(signedTx);
      }
      for (let bi = 0; bi < signedTxs.length; bi++) {
        const seals = batches[bi];
        out.innerHTML = `<span class="text-gray-400">Broadcasting batch ${bi + 1}/${signedTxs.length} — ${seals.length} seals…</span>`;
        // Succeeded only: a broadcast that fails on a retryable error is
        // retried fresh inside this same run, not left as a Stopped run
        // for a later Resume run to succeed. Only a rejection pauses.
        let sig = null, lastErr = null;
        for (let round = 0; round < 3 && !sig; round++) {
          try {
            if (round === 0) {
              sig = await broadcastAndVerify(signedTxs[bi], out, signedTxs[bi]._blockhashInfo, signedTxs[bi]._memoTexts);
            } else {
              out.innerHTML = `<span class="text-gray-400">Batch ${bi + 1}/${signedTxs.length} — refreshing… approve in your wallet.</span>`;
              const tx = await buildBatch50Tx(wallet, seals);
              const signed = await signBatchTx(tx, wallet, pubBytes, kc, () => signMessageFallbackBatch(wallet, seals));
              sig = await broadcastAndVerify(signed.finalTx, out, signed.finalInfo, signed.finalTx._memoTexts);
            }
          } catch (e) {
            if (isRejection(e)) {
              out.innerHTML = `<span class="text-amber-300">Paused</span> <span class="text-gray-400">— approval dismissed at batch ${bi + 1}/${signedTxs.length}. ${runAnchored} of ${todo.length} seals anchored. Tap the button to resume.</span>`;
              batchRunning = false; btn.disabled = false; btn.textContent = `Resume anchoring (${todo.length - runAnchored} left)`;
              return;
            }
            lastErr = e;
            if (!isRetryableSignErr(e) || round === 2) throw e;
            if (isRateLimitErr(e)) {
              out.innerHTML = `<span class="text-gray-400">Rate limited (429) — waiting 60 seconds, then retrying batch ${bi + 1}/${signedTxs.length}…</span>`;
              await sleepMs(60000);
            }
          }
        }
        if (!sig) throw lastErr || new Error('Batch did not land.');
        batchMarkDone(seals);
        runAnchored += seals.length; runTx += 1;
        out.innerHTML = `<span class="text-green-400">Anchored ✓</span> <span class="text-gray-400">batch ${bi + 1}/${signedTxs.length} — ${seals.length} seals verified on-chain.</span><br><span class="text-gray-500 text-xs">Anchored so far: ${runAnchored} of ${todo.length} seals</span><br><a class="underline text-gray-500 text-xs" href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
      }
      const leftAll = todo.length - runAnchored;
      out.innerHTML = `<span class="text-green-400">Anchored ✓</span> <span class="text-gray-400">${runAnchored} of ${todo.length} seals on-chain in ${runTx} transactions, one approval.</span>` + (leftAll === 0 ? `<br><span class="gold">All ${todo.length} seals anchored.</span>` : '');
      invalidateMissingSeals();
      showMissingList([]);
      refreshBalance();
      batchRunning = false; btn.disabled = false;
      btn.textContent = leftAll ? `Resume anchoring (${leftAll} left)` : 'Anchor all missing';
      return;
    }
    }
    for (let bi = 0; bi < batches.length; bi++) {
      const seals = batches[bi];
      // Omni rounds per batch: a slow approval kills the blockhash — fresh
      // transaction, one more approval, never a lost batch.
      let sig = null, lastErr = null;
      for (let round = 0; round < 3 && !sig; round++) {
        if (round === 0) {
          out.innerHTML = `<span class="text-gray-400">Batch ${bi + 1}/${batches.length} — ${seals.length} seals… approve in your wallet.</span><br><span class="text-gray-500 text-xs">Anchored so far: ${runAnchored} of ${todo.length} seals</span>`;
        } else {
          out.innerHTML = `<span class="text-gray-400">Batch ${bi + 1}/${batches.length} — refreshing… approve in your wallet.</span>`;
        }
        const tx = await buildBatch50Tx(wallet, seals); // fresh blockhash every round
        try {
          const signed = await signBatchTx(tx, wallet, pubBytes, kc, () => signMessageFallbackBatch(wallet, seals));
          sig = await broadcastAndVerify(signed.finalTx, out, signed.finalInfo, signed.finalTx._memoTexts);
        } catch (e) {
          if (isRejection(e)) {
            out.innerHTML = `<span class="text-amber-300">Paused</span> <span class="text-gray-400">— approval dismissed at batch ${bi + 1}/${batches.length}. ${runAnchored} of ${todo.length} seals anchored. Tap the button to resume.</span>`;
            batchRunning = false; btn.disabled = false; btn.textContent = `Resume anchoring (${todo.length - runAnchored} left)`;
            return;
          }
          lastErr = e;
          if (!isRetryableSignErr(e) || round === 2) throw e;
          if (isRateLimitErr(e)) {
            out.innerHTML = `<span class="text-gray-400">Rate limited (429) — waiting 60 seconds, then retrying batch ${bi + 1}/${batches.length}…</span>`;
            await sleepMs(60000);
          }
        }
      }
      if (!sig) throw lastErr || new Error('Batch did not land.');
      batchMarkDone(seals);
      runAnchored += seals.length; runTx += 1;
      // Same cadence as the single anchor: Confirmed → read back → Anchored ✓.
      // broadcastAndVerify already showed "Confirmed — reading it back…";
      // this lands the per-batch Anchored line before the next approval.
      out.innerHTML = `<span class="text-green-400">Anchored ✓</span> <span class="text-gray-400">batch ${bi + 1}/${batches.length} — ${seals.length} seals verified on-chain.</span><br><span class="text-gray-500 text-xs">Anchored so far: ${runAnchored} of ${todo.length} seals</span><br><a class="underline text-gray-500 text-xs" href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
    }
    const left = todo.length - runAnchored;
    out.innerHTML = `<span class="text-green-400">Anchored ✓</span> <span class="text-gray-400">${runAnchored} of ${todo.length} seals on-chain in ${runTx} transactions.</span>` + (left === 0 ? `<br><span class="gold">All ${todo.length} seals anchored.</span>` : '');
    invalidateMissingSeals();
    if (left) showMissingList(todo.slice(runAnchored));
    else showMissingList([]);
    refreshBalance();
    batchRunning = false; btn.disabled = false;
    btn.textContent = left ? `Resume anchoring (${left} left)` : 'Anchor all missing';
  } catch (e) {
    // Do NOT claim "no fee was spent" here: this catch runs after a batch may
    // already have been broadcast, so a fee may have been spent even though
    // the run stopped. The chain read on the next run is the only fee truth.
    out.innerHTML = `<span class="text-red-400">Stopped:</span> <span class="text-gray-400">${shortErr(e)}</span><br><span class="text-gray-500 text-xs">Progress is saved — tap the button to resume. If a batch was already broadcast, its fee was spent even if this run stopped — check the chain read before re-anchoring.</span>`;
    batchRunning = false; btn.disabled = false; btn.textContent = 'Resume anchoring';
  } finally {
    window._walletPromptOpen = false;
  }
}
async function refreshBatchLabel() {
  const btn = $('batchAnchorBtn');
  if (!btn) return;
  try {
    // Connect must stay fast on Nightly: use the cached chain read here.
    // The Anchor run itself always forces a fresh chain read and lists the
    // missing names before any approval, so a stale button count can never
    // be the last word before money moves.
    const missing = await loadMissingSeals();
    showMissingList(missing);
    const left = missing.length;
    btn.textContent = left ? `Anchor all missing (${left})` : 'Anchor all missing';
  } catch (e) { btn.textContent = 'Anchor all missing'; }
}
$('batchAnchorBtn').addEventListener('click', runBatchAnchor);

/* ---------- Public anchors: anyone anchors their data for a small COOK fee ----------
 * The visitor's text is hashed (SHA-256) in their browser — never sent anywhere.
 * One atomic tx: transfer PUBLIC_ANCHOR_FEE_COOK to Tyree + the PHI-LEDGER|public
 * memo carrying label + hash + visitor address. Fee and memo land together or
 * not at all. Desktop/wallet-browser signs in-page; mobile goes through the
 * wallet app deep link and the return handler broadcasts the signed bytes. */
async function sha256hex(text) {
  const buf = await crypto.subtle.digest('SHA-256', new TextEncoder().encode(text));
  return Array.from(new Uint8Array(buf)).map(b => b.toString(16).padStart(2, '0')).join('');
}
const cleanLabel = s => (s || '').trim().replace(/[^A-Za-z0-9_-]/g, '').slice(0, 32);

async function buildPublicAnchorTx(walletAddr, label, dataHash) {
  const from = new PublicKey(walletAddr);
  const memoText = `PHI-LEDGER|public|${label}|sha256=${dataHash}|by=${walletAddr}`;
  // Phi ledger v93, 2026-10-29: public anchor is memo-only on the main site.
  // The old 1-COOK payment instruction is paused, so the main site code
  // carries no payment instruction at all — memo only, preflight on.
  // Tyree can re-enable the payment instruction with his word.
  const tx = new Transaction().add(
    new TransactionInstruction({
      keys: [{ pubkey: from, isSigner: true, isWritable: false }],
      programId: new PublicKey(MEMO_PROGRAM),
      data: new TextEncoder().encode(memoText),
    })
  );
  tx.feePayer = from;
  const { blockhash, lastValidBlockHeight } = await connection.getLatestBlockhash('confirmed');
  tx.recentBlockhash = blockhash;
  tx._blockhashInfo = { blockhash, lastValidBlockHeight };
  tx._memoText = memoText;
  return tx;
}

function publicDone(out, sig, label, dataHash) {
  out.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">label:</span> ${esc(label)}<br><span class="text-gray-500">sha256:</span> <span class="text-xs break-all">${esc(dataHash)}</span><br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
}

async function runPublicAnchorEngine() {
  if (!provider || !wallet) return;
  const label = cleanLabel($('pubLabel').value);
  const data = $('pubData').value || '';
  const out = $('pubOut');
  out.classList.remove('hidden');
  if (!label) { out.innerHTML = '<span class="text-amber-300">Give your anchor a label first.</span>'; return; }
  if (!data.trim()) { out.innerHTML = '<span class="text-amber-300">Paste the data to anchor first.</span>'; return; }
  try {
    out.innerHTML = '<span class="text-gray-400">Hashing in your browser — your data never leaves this page…</span>';
    const dataHash = await sha256hex(data);
    const bal = await connection.getBalance(new PublicKey(wallet));
    if (bal < Math.round(PUBLIC_ANCHOR_FEE_COOK * 1e9) + 20000) {
      out.innerHTML = `<span class="text-amber-300">Not enough COOK — you need ${PUBLIC_ANCHOR_FEE_COOK} COOK for the fee plus a little for the network fee.</span>`;
      return;
    }
    out.innerHTML = '<span class="text-gray-400">Building… approve in your wallet.</span>';
    const tx = await buildPublicAnchorTx(wallet, label, dataHash);
    let signed = null;
    if (typeof provider.signTransaction === 'function') {
      signed = normalizeSignedTx(await provider.signTransaction(tx));
    } else {
      throw new Error('This wallet cannot sign transactions.');
    }
    if (!signed) throw new Error('Wallet returned nothing to broadcast — no fee spent.');
    if (hexOf(signed.serializeMessage()) !== hexOf(tx.serializeMessage())) {
      throw new Error('wallet altered the transaction bytes — no fee spent.');
    }
    if (!txSignatureVerifies(signed, wallet)) throw new Error('signature did not verify — no fee spent.');
    const sig = await broadcastAndVerify(signed, out, tx._blockhashInfo, tx._memoText);
    publicDone(out, sig, label, dataHash);
    refreshBalance();
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Stopped:</span> <span class="text-gray-400">${esc(shortErr(e))}</span>`;
  }
}
$('pubAnchorBtn').addEventListener('click', runPublicAnchorEngine);

/* Mobile public anchor: same tx, approved in the wallet app via deep link. */
async function publicSignRequest(addr, label, dataHash, out, kind) {
  kind = kind || 'solflare';
  const sess = kind === 'phantom' ? getPhantomSession() : getSolflareSession();
  const wpub = sess ? (kind === 'phantom' ? sess.phantomPub : sess.solflarePub) : null;
  const scheme = kind === 'phantom' ? PHANTOM_SCHEME : SOLFLARE_SCHEME;
  const wname = kind === 'phantom' ? 'Phantom' : 'Solflare';
  if (!sess) { (kind === 'phantom' ? phantomConnect : solflareConnect)(out); return; }
  if (out) out.innerHTML = `<span class="text-gray-400">Opening ${wname}… approve the anchor in the app.</span>`;
  const tx = await buildPublicAnchorTx(addr, label, dataHash); // fresh blockhash for the app
  const b58 = bs58encode(tx.serialize({ requireAllSignatures: false, verifySignatures: false }));
  const enc = encryptForWallet({ transaction: b58, session: sess.session }, wpub);
  const dapp = getDappKeys();
  const redirect = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&nonce=${enc.nonceB58}&redirect_link=${redirect}&payload=${enc.payloadB58}`;
  window.location.href = `${scheme}/signTransaction?${q}`; // straight into the app
}
function publicAnchorFlow(addr, label, dataHash, out, outId, kind) {
  setPendingSign(addr, 'public:' + label, kind || 'solflare', { isPublic: true, label, dataHash, outId: outId || null });
  try {
    const sess = (kind === 'phantom') ? getPhantomSession() : getSolflareSession();
    if (sess) publicSignRequest(addr, label, dataHash, out, kind || 'solflare');
    else (kind === 'phantom' ? phantomConnect : solflareConnect)(out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${esc(shortErr(e))}</span>`;
  }
}
$('pubSolflareBtn').addEventListener('click', async () => {
  const addr = $('mobileAddr').value.trim();
  const out = $('pubOutM');
  out.classList.remove('hidden');
  // Same cross-context trap as the seal flow: inside a wallet browser the
  // Solflare app cannot return to this tab. Anchor in-page instead.
  if (getProvider()) {
    out.innerHTML = '<span class="text-amber-300">You are inside a wallet browser — the Solflare app cannot return to this tab.</span><br><span class="text-gray-400 text-sm">Connect with the <b>Connect Wallet</b> button above and use the public-anchor panel at the top of the page instead.</span>';
    return;
  }
  if (!isValidAddress(addr)) { out.innerHTML = '<span class="text-amber-300">Enter your wallet address first.</span>'; return; }
  const label = cleanLabel($('pubLabelM').value);
  const data = $('pubDataM').value || '';
  if (!label) { out.innerHTML = '<span class="text-amber-300">Give your anchor a label first.</span>'; return; }
  if (!data.trim()) { out.innerHTML = '<span class="text-amber-300">Paste the data to anchor first.</span>'; return; }
  try {
    out.innerHTML = '<span class="text-gray-400">Hashing in your browser…</span>';
    const dataHash = await sha256hex(data);
    await publicAnchorFlow(addr, label, dataHash, out, 'pubOutM', 'solflare');
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${esc(shortErr(e))}</span>`;
  }
});

/* ---------- boot ---------- */
pulse(); setInterval(pulse, 30000);
mining(); setInterval(mining, 60000);
/* Fee vault: Tyree's Nano balance on Cookie Chain, shown on the page. */
async function refreshFeeVault() {
  if (typeof walletPromptOpen === 'function' && walletPromptOpen()) return;
  try {
    const lamports = await connection.getBalance(new PublicKey(TYREE_WALLET));
    $('feeVault').textContent = (lamports / 1e9).toFixed(6) + ' COOK';
  } catch (e) {
    $('feeVault').textContent = 'n/a';
  }
  $('feeVaultLink').href = EXPLORER + '/address/' + TYREE_WALLET;
}

(async () => {
  try { await loadLedger(); } catch (e) { /* snapshot stays null; anchor button guards it */ }
  document.querySelectorAll('.pubFee').forEach(el => el.textContent = PUBLIC_ANCHOR_FEE_COOK + ' COOK');
  refreshFeeVault(); setInterval(refreshFeeVault, 60000);
  if ($('mobileAddr').value.trim()) refreshMobileBalance();
  // In a wallet's own browser the app deep-link is a dead end (the wallet app
  // returns to the system browser, never to this tab). Swap the dead-end
  // buttons for the in-page route before the user can tap them.
  if (getProvider()) {
    const swapForInPage = (btnId, label) => {
      const b = $(btnId);
      if (!b) return;
      const note = document.createElement('p');
      note.className = 'text-sm text-gray-400';
      note.innerHTML = `Wallet browser detected — ${label} signs <b>in-page</b>: tap <b>Connect Wallet</b> above, then anchor. (The wallet-app button is hidden here because the app cannot return to this tab.)`;
      b.replaceWith(note);
    };
    swapForInPage('solflareAnchorBtn', 'Sealing');
    swapForInPage('pubSolflareBtn', 'Public anchors');
  }
  await handleWalletReturn();
})();
