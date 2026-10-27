#!/usr/bin/env python3
"""
VEIL: THE LAST SIGNAL - installer for Tyree's PC.
Copies the VEIL Unreal project to the target folder, verifies it landed,
finds the UE 5.8 engine, and prints the exact next step.

Usage:
    python install_veil.py [TARGET]        (default TARGET: D:\\VEIL)

Source resolution (first that exists):
    1. <this repo>/veil/VEIL              (when run inside the phi-vault clone)
    2. ./VEIL next to this script
Stdlib only. Safe to re-run - it refreshes the copy.
"""
import os
import shutil
import sys
from pathlib import Path

ENGINE_CANDIDATES = [
    r"C:\Program Files\Epic Games\UE_5.8",
    r"D:\Epic Games\UE_5.8",
    r"D:\UE_5.8",
    r"C:\UE_5.8",
]


def find_source() -> Path | None:
    here = Path(__file__).resolve()
    candidates = [here.parents[1] / "veil" / "VEIL", here.parent / "VEIL", Path.cwd() / "VEIL"]
    for c in candidates:
        if (c / "VEIL.uproject").exists():
            return c
    return None


def main() -> int:
    target = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(r"D:\VEIL")
    source = find_source()
    if source is None:
        print("VEIL source project not found (looked for veil/VEIL/VEIL.uproject).")
        print("Run this from inside the phi-vault clone, or pass the project path's parent.")
        return 1

    print(f"Source : {source}")
    print(f"Target : {target}")
    shutil.copytree(source, target, dirs_exist_ok=True)

    uproject = target / "VEIL.uproject"
    count = sum(1 for _ in target.rglob("*") if _.is_file())
    print(f"Copied : {count} files")
    print(f"Project: {uproject} -> {'OK' if uproject.exists() else 'MISSING'}")

    engine = next((p for p in ENGINE_CANDIDATES if Path(p).exists()), None)
    if engine:
        print(f"Engine : UE 5.8 found at {engine}")
        print("Next   : right-click VEIL.uproject -> Generate Visual Studio project files,")
        print("         then open VEIL.uproject in UE 5.8 and let it compile.")
    else:
        print("Engine : UE 5.8 folder not found in the usual places - open the project")
        print("         from the Epic Launcher (Library -> UE 5.8 -> your projects).")
    return 0 if uproject.exists() else 2


if __name__ == "__main__":
    raise SystemExit(main())
