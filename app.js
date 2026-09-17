/* PHI LEDGER — Cookie Chain cApp
 * Reads: Cookie Chain RPC (rpc.cookiescan.io), SoloPool BCH API, local ledger snapshot.
 * Writes: one memo transaction on Cookie Chain (user-signed, tiny COOK fee).
 */
const RPC_URL = 'https://rpc.cookiescan.io';
const EXPLORER = 'https://cookiescan.io';
const MEMO_PROGRAM = 'Memo1UhkJRfHyvLMcVucJwxXeuD728EqVDDwQDxFMNo';
const LIGHTHOUSE_PROGRAM = 'L2TExMFKdjpN9kozasaurPirfHy9P8sbXoAN1qA3S95'; // Phantom's protection injector
const SOLOPOOL = 'https://solopool.eu/api/v1/bch/miner/bitcoincash:qp432rtl3cm0se35rdy6ye8ay2tfxas80y24ntf2vm';

const { Connection, PublicKey, Transaction, TransactionInstruction } = solanaWeb3;
const connection = new Connection(RPC_URL, 'confirmed');

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
  const r = await fetch('ledger-snapshot.json');
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
function findProviders() {
  const cands = [window.nightly && window.nightly.solana, window.solana, window.backpack].filter(Boolean);
  // Prefer Nightly when present. The engine verifies every signer's bytes
  // anyway; preference just skips the known-dirty path first.
  const nightly = cands.filter(p => p && p.isNightly);
  const rest = cands.filter(p => p && !p.isNightly && p.connect);
  return [...nightly, ...rest];
}

$('connectBtn').addEventListener('click', async () => {
  const providers = findProviders();
  if (!providers.length) {
    // Mobile Chrome has no injected provider — offer the Phantom app deep-link flow.
    $('mobileAnchor').classList.remove('hidden');
    $('connectBtn').textContent = 'Use Phantom app ↓';
    $('connectBtn').disabled = true;
    $('walletLabel').textContent = 'mobile flow below';
    refreshMobileBalance();
    return;
  }
  // Try each provider in order; if one's connect() throws, try the next.
  let lastErr = null;
  // Universal: try every provider, and for each try publicKey, connect(), and request().
  for (const p of providers) {
    const methods = [];
    // 1. Already-available publicKey (dApp browser).
    // 2. Legacy connect().
    // 3. EIP-1193-style request().
    try {
      let pubkey = p.publicKey;
      if (pubkey && typeof pubkey !== 'string') pubkey = pubkey.toString ? pubkey.toString() : String(pubkey);
      if (!pubkey && typeof p.connect === 'function') {
        const resp = await p.connect().catch(e => { throw e; });
        pubkey = (resp && resp.publicKey) || (resp && resp.address) || p.publicKey || (resp && resp.account);
        if (pubkey && typeof pubkey !== 'string') pubkey = pubkey.toString ? pubkey.toString() : String(pubkey);
      }
      if (!pubkey && typeof p.request === 'function') {
        const resp = await p.request({ method: 'connect' });
        pubkey = (resp && resp.publicKey) || (resp && resp.address) || p.publicKey || (typeof resp === 'string' ? resp : null);
        if (pubkey && typeof pubkey !== 'string') pubkey = pubkey.toString ? pubkey.toString() : String(pubkey);
      }
      provider = p;
      if (!pubkey || !isValidAddress(pubkey)) throw new Error('wallet returned invalid address: ' + pubkey);
      wallet = pubkey;
    $('walletLabel').textContent = short(wallet, 4);
    $('connectBtn').textContent = 'Connected';
    $('connectBtn').disabled = true;
    $('anchorBtn').disabled = false;
    refreshBalance();
    // Nightly on custom network: remind user
    if (p.isNightly === undefined && window.nightly) {
      console.log('Nightly detected — ensure Cookie Chain network (rpc.cookiescan.io) is added in the wallet.');
    }
    lastErr = null;
    break; // connected — stop trying providers
  } catch (e) {
    lastErr = e;
    continue; // try next provider
  }
  }
  if (lastErr) {
    alert('Wallet connection rejected: ' + (lastErr.message || lastErr));
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
    // The seal flow only captures and verifies the signature — no broadcast,
    // no fee. Button stays enabled whenever an address is set.
    $('mobileAnchorBtn').disabled = false;
  } catch (e) {
    $('mobileBal').textContent = 'could not read balance';
    $('mobileAnchorBtn').disabled = false;
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
$('mobileAddr').addEventListener('input', () => { if ($('mobileAddr').value.trim()) $('mobileAnchorBtn').disabled = false; });

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
function setPendingSign(addr, seal) {
  lsSet('phantom_pending_sign', JSON.stringify({ addr, seal }));
  lsSet('anchorReroute', seal);
}
function getPendingSign() {
  try { return JSON.parse(lsGet('phantom_pending_sign') || 'null'); } catch (e) { return null; }
}
function clearPendingSign() {
  lsDel('phantom_pending_sign'); lsDel('anchorReroute');
}
function encryptForPhantom(obj, phantomPubB58) {
  const dapp = getDappKeys();
  const nonce = nacl.randomBytes(24);
  const box = nacl.box(new TextEncoder().encode(JSON.stringify(obj)), nonce, bs58decode(phantomPubB58), bs58decode(dapp.sec));
  return { nonceB58: bs58encode(nonce), payloadB58: bs58encode(box) };
}
function decryptFromPhantom(dataB58, nonceB58, phantomPubB58) {
  const dapp = getDappKeys();
  const opened = nacl.box.open(bs58decode(dataB58), bs58decode(nonceB58), bs58decode(phantomPubB58), bs58decode(dapp.sec));
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
  const enc = encryptForPhantom({ transaction: b58, session: sess.session }, sess.phantomPub);
  const dapp = getDappKeys();
  const redirect = encodeURIComponent(phantomRedirect());
  const q = `dapp_encryption_public_key=${dapp.pub}&nonce=${enc.nonceB58}&redirect_link=${redirect}&payload=${enc.payloadB58}`;
  window.location.href = `${PHANTOM_SCHEME}/signTransaction?${q}`; // straight into the app
}
// Entry: one call from either button. Connects first if needed, else signs.
async function phantomAnchorFlow(addr, seal, out) {
  setPendingSign(addr, seal);
  try {
    if (getPhantomSession()) await phantomSignRequest(addr, seal, out);
    else phantomConnect(out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${shortErr(e)}</span>`;
  }
}

$('mobileAnchorBtn').addEventListener('click', async () => {
  const addr = $('mobileAddr').value.trim();
  const seal = $('sealSelect').value;
  const out = $('mobileOut');
  if (!addr || !seal || !snapshot) { out.textContent = 'Enter your wallet address first.'; return; }
  out.classList.remove('hidden');
  try {
    new PublicKey(addr); // validate
    await phantomAnchorFlow(addr, seal, out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${(e.message || e).slice(0, 200)}</span>`;
  }
});

/* Handle returns from the Phantom app: connect (session) or sign (signed tx) */
async function handlePhantomReturn() {
  const params = new URLSearchParams(window.location.search);
  const encPub = params.get('phantom_encryption_public_key');
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
    ao.innerHTML = `<span class="text-amber-300">The app didn't respond to the link.</span><br><span class="text-gray-400 text-sm">Make sure the Phantom app is installed, then tap Anchor once more.</span>`;
    return;
  }
  if (!encPub && !data) return; // not our return
  history.replaceState(null, '', window.location.pathname);

  // --- Connect return: decrypt, store the session, continue to sign ---
  if (encPub && data) {
    try {
      const dec = decryptFromPhantom(data, nonce, encPub);
      setPhantomSession(dec.session, encPub);
      const pending = getPendingSign();
      if (pending) {
        const po = $('mobileOut');
        $('mobileAnchor').classList.remove('hidden');
        if (po) po.classList.remove('hidden');
        await phantomSignRequest(pending.addr, pending.seal, po || out);
      } else if (out) {
        out.classList.remove('hidden');
        out.innerHTML = '<span class="text-green-400">Connected to the Phantom app.</span>';
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
  // Phantom injects its Lighthouse instruction into every transaction, and
  // that program has no account on Cookie Chain — so the bytes can never be
  // broadcast there. But the signature inside them is real: Tyree's ed25519
  // signature over the memo. We decode it, verify it cryptographically, and
  // encode the verified approval via the golden ratio. Nothing broadcast,
  // no fee spent — the approval itself is the anchor, sealed by math.
  if (data) {
    const pending = getPendingSign();
    clearPendingSign();
    const mo = $('mobileOut');
    $('mobileAnchor').classList.remove('hidden');
    mo.classList.remove('hidden');
    try {
      const sess = getPhantomSession();
      if (!sess) throw new Error('Session expired — tap again to reconnect.');
      const dec = decryptFromPhantom(data, nonce, sess.phantomPub);
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
      if (sigValid && isHis && isPhiMemo) {
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
          `<span class="text-gray-500">signature bytes (64) → rung ${sigRung}</span><br>` +
          `<span class="text-gray-500">memo length (${memoText.length}) → rung ${memoRung}</span><br>` +
          `<span class="text-gray-500">sealed:</span> <span class="text-gray-300">${esc(now)}</span><br><br>` +
          `<span class="text-gray-400">Nothing was broadcast (Phantom's Lighthouse instruction cannot land on Cookie Chain), no fee spent. The approval is sealed — send a screenshot to complete the ledger entry.</span>`;
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

// One tap runs the whole: build → sign → verify bytes → reroute-or-broadcast → verify.
async function runAnchorEngine() {
  if (!provider || !wallet) return;
  const seal = $('sealSelect').value;
  const out = $('anchorOut');
  out.classList.remove('hidden');
  try {
    out.innerHTML = '<span class="text-gray-400">Building anchor transaction…</span>';
    const tx = await buildAnchorTx(wallet, seal);
    out.innerHTML = '<span class="text-gray-400">Signing… approve in your wallet.</span>';
    // Always sign locally and broadcast via our Cookie Chain connection.
    // (provider.signAndSendTransaction would broadcast via the wallet's own
    // network — Solana mainnet — where a Cookie Chain blockhash is invalid.)
    const signed = await provider.signTransaction(tx);
    if (signed.recentBlockhash !== tx._blockhashInfo.blockhash) {
      throw new Error('Wallet changed the transaction network data.');
    }
    const check = await verifyBytesClean(signed, tx._memoText);
    if (check.clean) {
      const sig = await broadcastAndVerify(signed, out, tx._blockhashInfo);
      anchorDone(out, sig, seal);
      refreshBalance();
      return;
    }
    // Fuel: dirty bytes reroute automatically — no second tap, no fee spent.
    out.innerHTML = `<span class="text-gray-400">In-page signing returned foreign bytes (${check.problems.join('; ')}) — rerouting through the wallet app…</span>`;
    if (!IS_MOBILE) {
      throw new Error('In-page signing returned foreign bytes (' + check.problems.join('; ') + '). On desktop the remaining route is Nightly with the Cookie Chain network (rpc.cookiescan.io) added.');
    }
    fireAppDeeplink(wallet, seal, out);
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Stopped:</span> <span class="text-gray-400">${shortErr(e)}</span><br><span class="text-gray-500 text-xs">No fee was spent — the engine stops before broadcast whenever the bytes aren't exactly the anchor.</span>`;
  }
}
$('anchorBtn').addEventListener('click', runAnchorEngine);

/* ---------- boot ---------- */
pulse(); setInterval(pulse, 15000);
mining(); setInterval(mining, 30000);
(async () => {
  try { await loadLedger(); } catch (e) { /* snapshot stays null; anchor button guards it */ }
  if ($('mobileAddr').value.trim()) refreshMobileBalance();
  await handlePhantomReturn();
})();
