# dlam_rabbit_r1.py - Brain tyree Eyes llava-phi3 - rabbit r1 loop
# Open browser + wait for next prompt, not just look
# Muse direct, not tyree refusal, not UNREAD default, not 402
import webbrowser, os, time
from pathlib import Path

REAL_KEY = os.getenv("REAL_API_KEY", "")
UNIVERSAL = f"03330-{REAL_KEY}" if REAL_KEY else "03330"
MODEL_BRAIN = "tyree:latest"
MODEL_EYES = "llava-phi3:latest"
OLLAMA = "http://localhost:11434/api/generate"
SEAT_FILE = Path("D:/VEIL-OMNI/seat719_out.txt")

print(f"[DLAM R1] Model {UNIVERSAL} - Brain {MODEL_BRAIN} Eyes {MODEL_EYES}")
print("[DLAM R1] Browser opened - waiting for next prompt from user input...")
try:
    webbrowser.open("http://localhost:11434")
except Exception as e:
    print(f"[DLAM R1] browser open note: {e}")

if SEAT_FILE.exists():
    print(SEAT_FILE.read_text(encoding="utf-8", errors="ignore")[:500])

print("[DLAM R1] WORLD /Game/Maps/VEILDistrict.VEILDistrict VAULT 0,0,-80.9 COUNTESS 809,-309,64.7")
print("[DLAM R1] Waiting for next prompt - type exit to stop")
while True:
    try:
        user_prompt = input("\n[USER PROMPT] > ").strip()
        if not user_prompt:
            continue
        if user_prompt.lower() in ("exit", "quit", "q"):
            break
        print(f"\n[DLAM R1] Received prompt, whole via phi: {user_prompt}\n")
        print("[DLAM R1] Ollama call goes here via localhost:11434 - Brain tyree, Eyes llava-phi3")
        if "VAULT" in user_prompt or "COUNTESS" in user_prompt:
            with open(SEAT_FILE, "a", encoding="utf-8") as f:
                f.write(f"\n{time.time()} {user_prompt[:200]}")
    except KeyboardInterrupt:
        break
    except Exception as e:
        print(f"[DLAM ERROR] {e} - Ollama running? ollama serve")
        time.sleep(2)
