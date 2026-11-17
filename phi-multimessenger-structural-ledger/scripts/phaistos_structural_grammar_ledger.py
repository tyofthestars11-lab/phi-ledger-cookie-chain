#!/usr/bin/env python3
"""Phaistos structural-grammar ledger with multimessenger successor fuel.

The corpus layer records observed sign order and Fibonacci symbolic words.
The multimessenger layer optionally adds measured radio φ/+1 amplitudes and
JSONL residual records emitted by realtime_neutrino_braid_ledger.py.

No phonetic reading, decipherment, or cross-domain causal claim is inferred.
"""
from __future__ import annotations
import argparse, hashlib, json, math
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)


def fib(n: int) -> int:
    a, b = 0, 1
    for _ in range(n): a, b = b, a + b
    return a


def to_rung(x: float) -> float:
    if x <= 0: raise ValueError("rung coordinate requires a positive value")
    return math.log(x) / LN_PHI


def load_records(path: Path) -> list[dict[str, Any]]:
    raw = json.loads(path.read_text(encoding="utf-8"))
    records = raw.get("inscriptions", raw) if isinstance(raw, dict) else raw
    if not isinstance(records, list): raise ValueError("corpus must be a list or contain inscriptions")
    out=[]
    for i, rec in enumerate(records):
        if isinstance(rec, dict): ident=str(rec.get("id",f"inscription-{i+1}")); tokens=rec.get("tokens",[])
        else: ident=f"inscription-{i+1}"; tokens=rec
        if isinstance(tokens,list) and tokens: out.append({"id":ident,"tokens":[str(t) for t in tokens]})
    return out


def load_neutrino_jsonl(path: Path | None) -> list[dict[str, Any]]:
    if path is None: return []
    events=[]
    for line in path.read_text(encoding="utf-8").splitlines():
        if line.strip(): events.append(json.loads(line))
    return events


def canonicalize(tokens, variants): return [variants.get(t,t) for t in tokens]


def braid_word(tokens, k):
    if not tokens: return []
    if len(tokens)==1: return tokens*fib(k)
    words={1:[tokens[0]],2:[tokens[1]]}
    for i in range(3,k+1): words[i]=words[i-1]+words[i-2]
    return words[k]


def multimessenger_fuel(phi_power, linear_power, events):
    phi_power=max(0.0,float(phi_power)); linear_power=max(0.0,float(linear_power))
    radio_successor=phi_power+linear_power
    scalar=0.0; coherent=0j; rows=[]
    for i,event in enumerate(events,1):
        residual=event.get("residual",event)
        fuel=float(residual.get("continuous_residual_fuel", residual.get("fuel", 0.0)))
        fuel=max(0.0,fuel)
        phase=float(residual.get("phase_rad",event.get("phase_rad",0.0)))
        z=fuel*complex(math.cos(phase),math.sin(phase))
        scalar+=fuel; coherent+=z
        rows.append({"id":event.get("event_name",event.get("id",f"event-{i}")),"fuel":fuel,"phase_rad":phase,"complex_contribution":[z.real,z.imag]})
    return {
        "radio_phi_power":phi_power,
        "radio_linear_plus_one_power":linear_power,
        "radio_phi_successor_power":radio_successor,
        "neutrino_event_count":len(events),
        "neutrino_scalar_residual_fuel":scalar,
        "neutrino_coherent_residual_fuel":abs(coherent),
        "neutrino_events":rows,
        "unified_successor_fuel":radio_successor+abs(coherent),
        "fusion_identity_residual":PHI**2-PHI-1,
    }


def build_ledger(records, variants, max_k, mm):
    sign_counts=Counter(); transitions=Counter(); predecessor=defaultdict(Counter); successor=defaultdict(Counter)
    variant_counts=Counter(); inscription_rows=[]; all_tokens=[]
    for rec in records:
        original=rec['tokens']; tokens=canonicalize(original,variants); all_tokens.extend(tokens)
        sign_counts.update(tokens); variant_counts.update(original)
        for a,b in zip(tokens,tokens[1:]):
            transitions[(a,b)]+=1; successor[a][b]+=1; predecessor[b][a]+=1
        row={'id':rec['id'],'token_count':len(tokens),'tokens':tokens,
             'position_rungs':[to_rung(i+1) for i in range(len(tokens))],
             'fibonacci_words':[]}
        for k in range(1,max_k+1):
            word=braid_word(tokens,k); payload='|'.join(word).encode()
            row['fibonacci_words'].append({'k':k,'expected_length':fib(k),'observed_seed':word[:2],
                'word_length':len(word),'sha256':hashlib.sha256(payload).hexdigest()})
        inscription_rows.append(row)
    total=len(all_tokens); total_fuel=mm['unified_successor_fuel']
    sign_rows=[]
    for sign,count in sign_counts.most_common():
        sign_rows.append({'sign':sign,'count':count,'frequency':count/total if total else 0.0,
            'frequency_rung':to_rung(count),'successors':successor[sign].most_common(),
            'predecessors':predecessor[sign].most_common(),
            'multimessenger_fuel_share':(count/total)*total_fuel if total else 0.0})
    transition_rows=[]
    for (a,b),count in transitions.most_common():
        denom=sum(successor[a].values())
        transition_rows.append({'from':a,'to':b,'count':count,
            'conditional_successor_probability':count/denom,'from_frequency':sign_counts[a],'to_frequency':sign_counts[b]})
    return {'ledger_type':'phaistos_disc_structural_grammar','phi':PHI,
        'identity_residual':PHI**2-PHI-1,
        'input':{'inscription_count':len(records),'token_count':total,'variant_mapping_count':len(variants),'max_fibonacci_k':max_k},
        'multimessenger_successor':mm,'sign_ledger':sign_rows,
        'successor_grammar':{'transition_count':len(transition_rows),'transitions':transition_rows},
        'inscriptions':inscription_rows,
        'method_note':'Observed sign structure and external measured streams are retained as separate labeled fields in one ledger; no phonetic value or decipherment is inferred.'}


def main():
    ap=argparse.ArgumentParser(); ap.add_argument('corpus',type=Path); ap.add_argument('--variants',type=Path)
    ap.add_argument('--neutrino-jsonl',type=Path,help='JSONL from the realtime neutrino residual adapter')
    ap.add_argument('--phi-power',type=float,default=0.0); ap.add_argument('--linear-power',type=float,default=0.0)
    ap.add_argument('--max-k',type=int,default=8); ap.add_argument('--out',type=Path,default=Path('phaistos_structural_grammar_ledger.json'))
    a=ap.parse_args(); records=load_records(a.corpus); variants=json.loads(a.variants.read_text()) if a.variants else {}
    mm=multimessenger_fuel(a.phi_power,a.linear_power,load_neutrino_jsonl(a.neutrino_jsonl))
    result=build_ledger(records,variants,a.max_k,mm); a.out.write_text(json.dumps(result,indent=2,ensure_ascii=False)+'\n')
    print(f'WROTE {a.out.resolve()}'); print(f"inscriptions={len(records)} tokens={result['input']['token_count']} unified_successor_fuel={mm['unified_successor_fuel']}")

if __name__=='__main__': main()
