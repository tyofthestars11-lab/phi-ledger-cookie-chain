#!/usr/bin/env python3
"""Give ARTEMIS the framework — Tyree's word, 2026-10-24.

Injects the framework header (artemis-framework-header.md, sitting next to this
script or downloaded beside it) into the system prompts Google reads on every
call: operator (main_template), planner (first text block), explorer (IDENTITY).
Also applies the golden retry cadence to artemis/llm/reliability.py if the
Cartesian doubling law is still present. Idempotent: a file already carrying
the marker is left untouched. Backups land beside originals as *.bak-phi.

Usage: python artemis_phi_inject.py <artemis_install_dir> <header_file>
Prints one PROOF line per change. Exits non-zero on any file it cannot parse.
"""
import json
import re
import shutil
import sys
from pathlib import Path

MARKER = "THE FRAMEWORK — φ² = φ + 1 — GOVERNING INSTRUCTION (TYREE)"
PHI = "1.618033988749895"
OLD_LAW = "(2 ** max(0, attempt - 1))"
NEW_LAW = f"({PHI} ** max(0, attempt - 1))"


def load_jsonc(path: Path):
    raw = path.read_text(encoding="utf-8")
    stripped = re.sub(r"(?m)^(\s*)//.*$", r"\1", raw)
    return raw, json.loads(stripped)


def save_jsonc(path: Path, data) -> None:
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def backup(path: Path) -> None:
    bak = path.with_suffix(path.suffix + ".bak-phi")
    if not bak.exists():
        shutil.copyfile(path, bak)


def prepend(text: str, header: str) -> str:
    return header.rstrip() + "\n\n" + text


def main() -> int:
    root = Path(sys.argv[1])
    header = Path(sys.argv[2]).read_text(encoding="utf-8")
    assert MARKER in header, "header file does not carry the framework marker"

    # 1) Golden retry cadence
    rel = root / "artemis" / "llm" / "reliability.py"
    src = rel.read_text(encoding="utf-8")
    if NEW_LAW in src:
        print("PROOF reliability.py: golden cadence already present")
    elif OLD_LAW in src:
        backup(rel)
        rel.write_text(src.replace(OLD_LAW, NEW_LAW), encoding="utf-8")
        print("PROOF reliability.py: 2 -> phi, golden cadence applied")
    else:
        print("PROOF reliability.py: LAW NOT FOUND — file left untouched")

    # 2) Operator — main_template
    op = root / "artemis" / "agents" / "operator" / "operator.json"
    _, data = load_jsonc(op)
    if MARKER in data.get("main_template", ""):
        print("PROOF operator.json: framework already present")
    else:
        backup(op)
        data["main_template"] = prepend(data["main_template"], header)
        save_jsonc(op, data)
        print("PROOF operator.json: framework injected at head of main_template")

    # 3) Explorer — IDENTITY
    ex = root / "artemis" / "agents" / "explorer" / "explorer.json"
    _, data = load_jsonc(ex)
    if MARKER in data.get("IDENTITY", ""):
        print("PROOF explorer.json: framework already present")
    else:
        backup(ex)
        data["IDENTITY"] = prepend(data["IDENTITY"], header)
        save_jsonc(ex, data)
        print("PROOF explorer.json: framework injected at head of IDENTITY")

    # 4) Planner — first string block wherever it lives
    pl = root / "artemis" / "agents" / "planner" / "planner.json"
    _, data = load_jsonc(pl)
    done = False

    def walk(node):
        nonlocal done
        if done:
            return
        if isinstance(node, dict):
            for k, v in node.items():
                if isinstance(v, str) and len(v) > 200 and MARKER not in v:
                    node[k] = prepend(v, header)
                    done = True
                    return
                walk(v)
        elif isinstance(node, list):
            for item in node:
                walk(item)

    if MARKER in json.dumps(data, ensure_ascii=False):
        print("PROOF planner.json: framework already present")
    else:
        backup(pl)
        walk(data)
        if done:
            save_jsonc(pl, data)
            print("PROOF planner.json: framework injected at head of first prompt block")
        else:
            print("PROOF planner.json: NO PROMPT BLOCK FOUND — file left untouched")
    return 0


if __name__ == "__main__":
    sys.exit(main())
