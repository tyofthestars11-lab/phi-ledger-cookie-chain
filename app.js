/* PHI LEDGER — Cookie Chain cApp
 * Reads: Cookie Chain RPC (rpc.cookiescan.io), SoloPool BCH API, local ledger snapshot.
 * Writes: one memo transaction on Cookie Chain (user-signed, tiny COOK fee).
 */
const RPC_URL = 'https://rpc.cookiescan.io';
const EXPLORER = 'https://cookiescan.io';
const MEMO_PROGRAM = 'Memo1UhkJRfHyvLMcVucJwxXeuD728EqVDDwQDxFMNo';
const LIGHTHOUSE_PROGRAM = 'L2TExMFKdjpN9kozasaurPirfHy9P8sbXoAN1qA3S95'; // Phantom's protection injector
const SOLOPOOL = 'https://solopool.eu/api/v1/bch/miner/bitcoincash:qp432rtl3cm0se35rdy6ye8ay2tfxas80y24ntf2vm';

const { Connection, PublicKey, Transaction, TransactionInstruction, SystemProgram } = solanaWeb3;
const connection = new Connection(RPC_URL, 'confirmed');

/* Public anchors: anyone anchors their data for a small COOK fee.
 * φ is always φ — the page anchors visitor data too, not just ledger seals. */
const TYREE_WALLET = 'A92L9a5qMwUpp8GRRsvj8n9hF6hx6WBVakQgbSDZzG3q'; // Tyree's Phantom wallet — public-anchor fees land here
const PUBLIC_ANCHOR_FEE_COOK = 1; // small COOK fee per public anchor, paid to Tyree — keep the .pubFee text in index.html in sync

let wallet = null;      // connected public key (base58)
let provider = null;    // injected wallet provider
let snapshot = null;

const $ = id => document.getElementById(id);
const fmtInt = n => Number(n).toLocaleString('en-US');
const short = (s, n=6) => s ? s.slice(0,n) + '…' + s.slice(-4) : '';

/* ---------- Cookie Chain network pulse ---------- */
async function pulse() {
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
  const r = await fetch('ledger-snapshot.json?v=125');
  snapshot = await r.json();
  $('sealCount').textContent = snapshot.seal_count;
  $('entryCount').textContent = snapshot.entry_count;
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
  try {
    const r = await fetch(SOLOPOOL);
    const m = await r.json();
    $('mineHash').textContent = m.hashrate || 'n/a';
    $('mineShares').textContent = fmtInt(m.shares_valid || 0);
    $('mineBest').textContent = m.bestshare_display || 'n/a';
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
// Single provider only — no loops, no popup circles. window.solana is the standard.
function getProvider() {
  return window.solana || (window.nightly && window.nightly.solana) || window.solflare || window.backpack || null;
}

$('connectBtn').addEventListener('click', async () => {
  const p = getProvider();
  if (!p) {
    // Mobile Chrome has no injected provider — offer the wallet app deep-link flow.
    $('mobileAnchor').classList.remove('hidden');
    $('connectBtn').textContent = 'Use Phantom app ↓';
    $('connectBtn').disabled = true;
    $('walletLabel').textContent = 'mobile flow below';
    refreshMobileBalance();
    return;
  }
  // Single connect() call — no loops, no popup circles.
  try {
      let pubkey = null;
      // 1. Legacy connect() — the authoritative source.
      if (typeof p.connect === 'function') {
        const resp = await p.connect();
        const pk = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || (resp && resp.account);
        if (pk) pubkey = (typeof pk === 'string') ? pk : (pk.toString ? pk.toString() : String(pk));
      }
      // 2. Check p.publicKey AFTER connect() (it should now be populated).
      if (!pubkey && p.publicKey) {
        const pk = p.publicKey;
        pubkey = (typeof pk === 'string') ? pk : (pk.toString ? pk.toString() : String(pk));
      }
      // 3. EIP-1193-style request() as fallback.
      if (!pubkey && typeof p.request === 'function') {
        const resp = await p.request({ method: 'connect' });
        const pk = (resp && resp.publicKey) || (resp && resp.address) || (typeof resp === 'string' ? resp : null) || p.publicKey;
        if (pk) pubkey = (typeof pk === 'string') ? pk : (pk.toString ? pk.toString() : String(pk));
      }
      provider = p;
      if (!pubkey || !isValidAddress(pubkey)) throw new Error('wallet returned invalid address: ' + pubkey);
      wallet = pubkey;
    $('walletLabel').textContent = short(wallet, 4);
    $('connectBtn').textContent = 'Connected';
    $('connectBtn').disabled = true;
    $('anchorBtn').disabled = false;
    $('pubAnchorBtn').disabled = false;
    refreshBalance();
    // Nightly on custom network: remind user
    if (p.isNightly === undefined && window.nightly) {
      console.log('Nightly detected — ensure Cookie Chain network (rpc.cookiescan.io) is added in the wallet.');
    }
  } catch (e) {
    alert('Wallet connection rejected: ' + (e.message || e));
    return;
  }
});

async function refreshBalance() {
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
        if (ix.programId.toString() === MEMO_PROGRAM) {
          try { memoText = new TextDecoder().decode(ix.data); } catch (e) {}
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
function shortErr(e) { return String((e && e.message) || e).slice(0, 220); }

// The byte rung: signed bytes must be EXACTLY what we built — one memo
// instruction, our data verbatim, every program present on-chain.
async function verifyBytesClean(signedTx, expectedMemoText) {
  const problems = [];
  if (signedTx.instructions.length !== 1) problems.push('instruction count ' + signedTx.instructions.length + ' (expected 1)');
  const ix = signedTx.instructions[0];
  if (!ix || ix.programId.toString() !== MEMO_PROGRAM) problems.push('foreign program ' + short(ix ? ix.programId.toString() : '?', 8));
  let dataText = '';
  try { dataText = new TextDecoder().decode(ix.data); } catch (e) {}
  if (dataText !== expectedMemoText) problems.push('memo data altered');
  const { missing } = await missingPrograms(signedTx);
  if (missing.length > 0) problems.push('missing program ' + missing.map(m => short(m, 8)).join(','));
  return { clean: problems.length === 0, problems };
}

async function broadcastAndVerify(signedTx, out, blockhashInfo) {
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
  // The chain arbitrates: success means meta.err is null.
  const txInfo = await connection.getTransaction(sig, { commitment: 'confirmed' });
  if (txInfo?.meta?.err) throw new Error('Chain rejected it: ' + JSON.stringify(txInfo.meta.err));
  return sig;
}

// Byte helpers
function hexOf(u8) {
  let s = '';
  for (let i = 0; i < u8.length; i++) s += u8[i].toString(16).padStart(2, '0');
  return s;
}

function anchorDone(out, sig, seal) {
  out.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">seal:</span> ${seal}<br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
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
  try {
    out.innerHTML = '<span class="text-gray-400">Building anchor transaction…</span>';
    const tx = await buildAnchorTx(wallet, seal);
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
    out.innerHTML = '<span class="text-gray-400">Signing… approve in your wallet.</span>';
    // Always sign locally and broadcast via our Cookie Chain connection.
    // (provider.signAndSendTransaction would broadcast via the wallet's own
    // network — Solana mainnet — where a Cookie Chain blockhash is invalid.)
    let finalTx = null, finalInfo = tx._blockhashInfo, finalMemo = tx._memoText;
    if (typeof provider.signTransaction === 'function') {
      const rawSigned = await provider.signTransaction(tx);
      const signedTx = normalizeSignedTx(rawSigned);
      if (signedTx) {
        const wantHex = hexOf(tx.serializeMessage());
        const gotHex = hexOf(signedTx.serializeMessage());
        if (gotHex === wantHex && txSignatureVerifies(signedTx, wallet)) {
          finalTx = signedTx;
        } else {
          const off = firstDiffByte(wantHex, gotHex);
          alterNote += `signTransaction altered the bytes (first diff at byte ${off}; want ${wantHex.slice(off * 2, off * 2 + 16)}…, got ${gotHex.slice(off * 2, off * 2 + 16)}…). `;
          if (enveloped) throw new Error(alterNote + 'signMessage is enveloped too, so this provider never signs raw transaction bytes — no broadcastable signature exists. No fee spent.');
          out.innerHTML = '<span class="text-gray-400">Wallet rewrote the transaction — signing the exact bytes instead… approve in your wallet.</span>';
          finalTx = await signMessageFallback(wallet, seal);
          finalInfo = finalTx._blockhashInfo; finalMemo = finalTx._memoText;
        }
      } else {
        // Maybe signTransaction returned a bare signature instead of a transaction.
        const msgBytes = new Uint8Array(tx.serializeMessage());
        const cands = extractSigCandidates(rawSigned);
        let attached = false;
        for (const c of cands) {
          try {
            if (nacl.sign.detached.verify(msgBytes, c.bytes, pubBytes)) {
              tx.addSignature(new PublicKey(wallet), c.bytes);
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
          if (enveloped) throw new Error(alterNote + 'signMessage is enveloped too, so this provider never signs raw transaction bytes — no broadcastable signature exists. No fee spent.');
          out.innerHTML = '<span class="text-gray-400">Wallet returned an unreadable signature — signing the exact bytes instead… approve in your wallet.</span>';
          finalTx = await signMessageFallback(wallet, seal);
          finalInfo = finalTx._blockhashInfo; finalMemo = finalTx._memoText;
        }
      }
    } else if (typeof provider.signMessage === 'function') {
      if (enveloped) throw new Error(alterNote + 'this provider only signs enveloped messages, never raw transaction bytes — no broadcastable signature exists. No fee spent.');
      out.innerHTML = '<span class="text-gray-400">Signing the exact bytes… approve in your wallet.</span>';
      finalTx = await signMessageFallback(wallet, seal);
      finalInfo = finalTx._blockhashInfo; finalMemo = finalTx._memoText;
    } else {
      throw new Error('Wallet supports neither signTransaction nor signMessage.');
    }
    const check = await verifyBytesClean(finalTx, finalMemo);
    if (!check.clean) {
      throw new Error('wallet returned altered bytes (' + check.problems.join('; ') + ') — no fee spent.');
    }
    if (!txSignatureVerifies(finalTx, wallet)) {
      throw new Error('assembled transaction carries no valid signature — no fee spent.');
    }
    const sig = await broadcastAndVerify(finalTx, out, finalInfo);
    // Broadcast confirmed by the RPC — the chain holds the transaction.
    // "Anchored" means the network confirmed it; the memo text was verified
    // byte-identical before signing (verifyBytesClean above).
    anchorDone(out, sig, seal);
    refreshBalance();
  } catch (e) {
    const full = (alterNote + String((e && e.message) || e)).slice(0, 900);
    out.innerHTML = `<span class="text-red-400">Stopped:</span> <span class="text-gray-400">${full}</span><br><span class="text-gray-500 text-xs">Stopped before broadcast — no fee was spent.</span>`;
  }
}

$('anchorBtn').addEventListener('click', runAnchorEngine);

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
  const tx = new Transaction().add(
    SystemProgram.transfer({
      fromPubkey: from,
      toPubkey: new PublicKey(TYREE_WALLET),
      lamports: Math.round(PUBLIC_ANCHOR_FEE_COOK * 1e9),
    }),
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
    const sig = await broadcastAndVerify(signed, out, tx._blockhashInfo);
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
pulse(); setInterval(pulse, 15000);
mining(); setInterval(mining, 30000);
/* Fee vault: Tyree's Nano balance on Cookie Chain, shown on the page. */
async function refreshFeeVault() {
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
  refreshFeeVault(); setInterval(refreshFeeVault, 30000);
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
