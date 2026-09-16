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

/* ---------- Wallet connect (injected provider: Phantom / Nightly / Solflare) ---------- */
function findProvider() {
  const cands = [window.solana, window.nightly && window.nightly.solana, window.backpack].filter(Boolean);
  return cands.find(p => p && p.isPhantom || p && p.connect) || cands[0] || null;
}

$('connectBtn').addEventListener('click', async () => {
  const p = findProvider();
  if (!p) {
    alert('No Solana wallet found. Install Phantom, Nightly, or Solflare, then reload.');
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
    tx.recentBlockhash = (await connection.getLatestBlockhash('confirmed')).blockhash;
    let sig;
    if (provider.signAndSendTransaction) {
      const res = await provider.signAndSendTransaction(tx);
      sig = res.signature;
    } else {
      const signed = await provider.signTransaction(tx);
      sig = await connection.sendRawTransaction(signed.serialize());
    }
    out.innerHTML = '<span class="text-gray-400">Confirming…</span>';
    await connection.confirmTransaction(sig, 'confirmed');
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
