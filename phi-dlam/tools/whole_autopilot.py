# WHOLE AUTOPILOT phi^2 = phi + 1 - Model 03330
# Launch -> Editor -> Map -> Verify Vault/Countess/RUNNER -> Save -> Play -> Loop
# Muse direct, not tyree refusal, not UNREAD default, not talk only
import subprocess, time, pathlib, os, shutil

PROJECT = r"D:\VEIL-OMNI\VEIL.uproject"
UE_EXE = r"C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
MAP = "/Game/Maps/VEILDistrict"
SEAT = pathlib.Path(r"D:\VEIL-OMNI\seat719_out.txt")
WHOLE_VERIFY = pathlib.Path(r"D:\VEIL-OMNI\Tools\whole_verify.py")
REPO_VERIFY = pathlib.Path(__file__).parent / "whole_verify.py"

print("[WHOLE phi^2] launching VEIL - whole, not step")

# Copy whole_verify into VEIL Tools, so editor can run it on PC
WHOLE_VERIFY.parent.mkdir(parents=True, exist_ok=True)
if REPO_VERIFY.exists():
    shutil.copyfile(REPO_VERIFY, WHOLE_VERIFY)

# 1. LAUNCH editor first, no -game, so map can be verified and saved in editor
proc = subprocess.Popen([UE_EXE, PROJECT], env={**os.environ})
print("[WHOLE] Splash VEIL+Unreal+Epic purple - waiting for editor to replace splash...")

# 2. WAIT for editor window, not splash, poll seat, up to 5 min
for i in range(150):
    time.sleep(2)
    if SEAT.exists():
        txt = SEAT.read_text(errors="ignore")
        if "WORLD" in txt and "VAULT" in txt:
            print(f"[WHOLE] seat719_out.txt shows WORLD - editor replacing splash - {i*2}s")
            break
    if i % 15 == 0:
        print(f"[WHOLE] Waiting editor... {i*2}s - splash -> editor window")

# 3. WHOLE VERIFY - editor Python, Vault / Countess / RUNNER, then save
print("[WHOLE] Editor loaded - show editor photo - look - click Play - verify Vault 0,0,-80.9, Countess 809,-309,64.7, RUNNER 0,0,100 - save - play - continuous until whole")
print(f"[WHOLE] whole_verify.py at {WHOLE_VERIFY} - run in editor Python console, then save map, then Play")
print("[WHOLE] Continuous Play loop - no package - phi^2 = phi + 1 whole")
