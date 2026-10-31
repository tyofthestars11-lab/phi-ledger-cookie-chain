# dlam_autopilot_r1.py - TRUE AUTOPILOT, not manual input()
# Opens browser, watches for next prompt, drains queue like work / workloop, no user typing
# Muse direct, not tyree refusal, not UNREAD default, not 402
import webbrowser, os, requests, time, pathlib

REAL_KEY = os.getenv("REAL_API_KEY", "")
UNIVERSAL = f"03330-{REAL_KEY}" if REAL_KEY else "03330"
BRAIN = "tyree:latest"
EYES = "llava-phi3:latest"
OLLAMA = "http://localhost:11434/api/generate"

QUEUE_DIR = pathlib.Path("D:/VEIL-OMNI/queue")
NEXT_PROMPT = pathlib.Path("D:/VEIL-OMNI/next_prompt.txt")
SEAT = pathlib.Path("D:/VEIL-OMNI/seat719_out.txt")
QUEUE_DIR.mkdir(exist_ok=True)

def call_tyree(prompt, model=BRAIN):
    r = requests.post(OLLAMA, json={
        "model": model,
        "prompt": f"TYREE BRIEF phi law UNREAD rule - AUTOPILOT - {prompt} - {UNIVERSAL} tetra-bonds golden-ratio-intent - verify first action only study 875 - MODEL 03330",
        "stream": False,
        "options": {"num_ctx": 8192}
    }, timeout=120)
    return r.json()["response"]

webbrowser.open("http://localhost:11434")
print(f"[AUTOPILOT R1] {UNIVERSAL} - Brain {BRAIN} - open browser, waiting for next prompt...")

while True:
    prompt = None
    if NEXT_PROMPT.exists() and NEXT_PROMPT.stat().st_size > 0:
        prompt = NEXT_PROMPT.read_text(encoding="utf-8").strip()
        NEXT_PROMPT.write_text("", encoding="utf-8")
    else:
        jobs = sorted(QUEUE_DIR.glob("*.txt"))
        if jobs:
            prompt = jobs[0].read_text(encoding="utf-8").strip()
            jobs[0].unlink()
    if prompt:
        print(f"\n[AUTOPILOT PROMPT] {prompt[:200]}")
        model = EYES if any(k in prompt.lower() for k in ["white", "image", "look", "see", ".jpg"]) else BRAIN
        resp = call_tyree(prompt, model)
        print(f"[TYREE AUTOPILOT] {resp[:1000]}")
        if "white" in prompt.lower() or "VAULT_PHI" in prompt:
            SEAT.write_text(f"WORLD /Game/Maps/VEILDistrict.VEILDistrict VAULT 0,0,-80.9 COUNTESS 809,-309,64.7 MODEL 03330 FLOOR 1618 AUTOPILOT {time.time()} SAVE RESULT True\n", encoding="utf-8")
    else:
        time.sleep(1.5)
