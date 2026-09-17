/* PHI LEDGER — Cookie Chain cApp
 * Reads: Cookie Chain RPC (rpc.cookiescan.io), SoloPool BCH API, local ledger snapshot.
 * Writes: one memo transaction on Cookie Chain (user-signed, tiny COOK fee).
 */
const RPC_URL = 'https://rpc.cookiescan.io';
const EXPLORER = 'https://cookiescan.io';
const MEMO_PROGRAM = 'MemoSq4gqABAXKb96qnH8TysNcWxMyWCqXgDLGmfcHr';
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

/* ---------- base58 (for Phantom mobile deep links) ---------- */
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
function findProvider() {
  const cands = [window.solana, window.nightly && window.nightly.solana, window.backpack].filter(Boolean);
  return cands.find(p => p && p.isPhantom || p && p.connect) || cands[0] || null;
}

$('connectBtn').addEventListener('click', async () => {
  const p = findProvider();
  if (!p) {
    // Mobile Chrome has no injected provider — offer the Phantom app deep-link flow.
    $('mobileAnchor').classList.remove('hidden');
    $('connectBtn').textContent = 'Use Phantom app ↓';
    $('connectBtn').disabled = true;
    $('walletLabel').textContent = 'mobile flow below';
    refreshMobileBalance();
    return;
  }
  try {
    const resp = await p.connect();
    provider = p;
    wallet = resp.publicKey.toString();
    $('walletLabel').textContent = short(wallet, 4);
    $('connectBtn').textContent = 'Connected';
    $('connectBtn').disabled = true;
    $('anchorBtn').disabled = false;
    refreshBalance();
    // Nightly on custom network: remind user
    if (p.isNightly === undefined && window.nightly) {
      console.log('Nightly detected — ensure Cookie Chain network (rpc.cookiescan.io) is added in the wallet.');
    }
  } catch (e) {
    alert('Wallet connection rejected: ' + (e.message || e));
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
    $('mobileAnchorBtn').disabled = cook <= 0;
  } catch (e) {
    $('mobileBal').textContent = 'could not read balance';
  }
}

async function buildAnchorTx(walletAddr, seal) {
  const memoText = `PHI-LEDGER|seal=${seal}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz`;
  const ix = new TransactionInstruction({
    keys: [{ pubkey: new PublicKey(walletAddr), isSigner: true, isWritable: false }],
    programId: new PublicKey(MEMO_PROGRAM),
    data: new TextEncoder().encode(memoText),
  });
  const tx = new Transaction().add(ix);
  tx.feePayer = new PublicKey(walletAddr);
  tx.recentBlockhash = (await connection.getLatestBlockhash('confirmed')).blockhash;
  return tx;
}

$('mobileAddr').addEventListener('change', refreshMobileBalance);

$('mobileAnchorBtn').addEventListener('click', async () => {
  const addr = $('mobileAddr').value.trim();
  const seal = $('sealSelect').value;
  const out = $('mobileOut');
  if (!addr || !seal || !snapshot) { out.textContent = 'Enter your wallet address first.'; return; }
  out.classList.remove('hidden');
  out.innerHTML = '<span class="text-gray-400">Building transaction… opening Phantom.</span>';
  try {
    new PublicKey(addr); // validate
    const tx = await buildAnchorTx(addr, seal);
    const b58 = bs58encode(tx.serialize({ requireAllSignatures: false, verifySignatures: false }));
    const redirect = encodeURIComponent(window.location.origin + window.location.pathname + '?anchored=1');
    window.location.href = `https://phantom.app/ul/v1/signTransaction?transaction=${b58}&redirect_link=${redirect}`;
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${(e.message || e).slice(0, 200)}</span>`;
  }
});

/* Handle return from Phantom app with a signed transaction */
async function handlePhantomReturn() {
  const params = new URLSearchParams(window.location.search);
  if (params.get('errorCode')) {
    const out = $('mobileOut') || $('anchorOut');
    if (out) {
      out.classList.remove('hidden');
      out.innerHTML = `<span class="text-red-400">Phantom declined:</span> <span class="text-gray-400">${(params.get('errorMessage') || 'rejected').slice(0, 160)}</span>`;
    }
    history.replaceState(null, '', window.location.pathname);
    return;
  }
  const signedB58 = params.get('transaction');
  if (!signedB58 || params.get('anchored') !== '1') return;
  history.replaceState(null, '', window.location.pathname);
  const out = $('mobileOut');
  $('mobileAnchor').classList.remove('hidden');
  out.classList.remove('hidden');
  out.innerHTML = '<span class="text-gray-400">Broadcasting to Cookie Chain…</span>';
  try {
    const raw = bs58decode(signedB58);
    const sig = await connection.sendRawTransaction(raw);
    out.innerHTML = '<span class="text-gray-400">Confirming…</span>';
    await connection.confirmTransaction(sig, 'confirmed');
    out.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Broadcast failed:</span> <span class="text-gray-400">${(e.message || e).slice(0, 200)}</span>`;
  }
}

/* ---------- Anchor a seal: memo tx on Cookie Chain ---------- */
$('anchorBtn').addEventListener('click', async () => {
  if (!provider || !wallet) return;
  const seal = $('sealSelect').value;
  const memoText = `PHI-LEDGER|seal=${seal}|sha256=${snapshot.snapshot_sha256}|by=tyofthestarz`;
  const out = $('anchorOut');
  out.classList.remove('hidden');
  out.innerHTML = '<span class="text-gray-400">Building transaction… approve in your wallet.</span>';
  try {
    const ix = new TransactionInstruction({
      keys: [{ pubkey: new PublicKey(wallet), isSigner: true, isWritable: false }],
      programId: new PublicKey(MEMO_PROGRAM),
      data: new TextEncoder().encode(memoText),
    });
    const tx = new Transaction().add(ix);
    tx.feePayer = new PublicKey(wallet);
    const { blockhash, lastValidBlockHeight } = await connection.getLatestBlockhash('confirmed');
    tx.recentBlockhash = blockhash;
    let sig;
    // Always sign locally and broadcast via our Cookie Chain connection.
    // (provider.signAndSendTransaction would broadcast via the wallet's own
    // network — Solana mainnet — where a Cookie Chain blockhash is invalid.)
    const signed = await provider.signTransaction(tx);
    // If the wallet replaced our blockhash, the tx is invalid on Cookie Chain.
    if (signed.recentBlockhash !== blockhash) {
      throw new Error('Wallet changed the transaction network data. Please try Nightly wallet instead — see note below.');
    }
    sig = await connection.sendRawTransaction(signed.serialize(), { skipPreflight: false, maxRetries: 5 });
    out.innerHTML = '<span class="text-gray-400">Confirming…</span>';
    // Retry broadcast: this RPC sometimes drops transactions. Resend the same
    // signed bytes a few times (idempotent) before giving up.
    const rawTx = signed.serialize();
    let confirmed = false;
    let lastErr = null;
    for (let attempt = 0; attempt < 4 && !confirmed; attempt++) {
      if (attempt > 0) {
        out.innerHTML = `<span class="text-gray-400">Retrying broadcast (${attempt + 1}/4)…</span>`;
        try { await connection.sendRawTransaction(rawTx, { skipPreflight: true }); } catch (e) { /* already landed */ }
      }
      try {
        await connection.confirmTransaction({ signature: sig, blockhash, lastValidBlockHeight }, 'confirmed');
        confirmed = true;
      } catch (e) { lastErr = e; await new Promise(r => setTimeout(r, 5000)); }
    }
    if (!confirmed) throw lastErr || new Error('Transaction was not confirmed after 4 broadcast attempts.');
    out.innerHTML = `<span class="text-green-400">Anchored ✓</span><br><span class="text-gray-500">seal:</span> ${seal}<br><a href="${EXPLORER}/tx/${sig}" target="_blank" rel="noopener">${EXPLORER}/tx/${short(sig, 8)}</a>`;
    refreshBalance();
  } catch (e) {
    out.innerHTML = `<span class="text-red-400">Failed:</span> <span class="text-gray-400">${(e.message || e).slice(0, 200)}</span><br><span class="text-gray-500 text-xs">If this is a funds error, bridge a little COOK: <a href="https://bridge.cookiescan.io" target="_blank" rel="noopener">bridge.cookiescan.io</a></span>`;
  }
});

/* ---------- boot ---------- */
pulse(); setInterval(pulse, 15000);
mining(); setInterval(mining, 30000);
loadLedger();
handlePhantomReturn();
