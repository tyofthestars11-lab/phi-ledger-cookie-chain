# Local result: VEIL OMNI jobs 810-815 + memory fix (local Spark seat 816)

Tyree local on PC. Local Muse Spark did the work, wire via this repo.
No package, no cook. Game left RUNNING through the desktop door.

## Memory fix (the OOM crash)
- Before: VRAM 4957/6144 MiB, 1 UnrealEditor-Cmd squatting, game process 0.
- Dialog dismissed, GUI 0, Cmd 0 verified.
- Real hog: `ollama/llama-server.exe` pinning VRAM. Stopped (restarts on `ollama serve`).
- VRAM after free: 1398/6144 MiB.

## Settings (full, not low-capped)
- `D:\VEIL-OMNI\Saved\Config\Windows\GameUserSettings.ini` created:
  full Epic groups (sg 3, resolution quality 100), 1280x720,
  FullscreenMode=1 borderless, bUseVSync=False, FrameRateLimit=0.
- `D:\VEIL-OMNI\Config\DefaultEngine.ini`: r.Streaming.PoolSize 1400->4000,
  added r.Streaming.Boost=2 (clay-start fix: pool starvation made tan clay).
  t.MaxFPS=0 already unlimited.

## 811 controller, for real
- Root binds already in `VEILCharacter.cpp`: left stick move, right stick look,
  A jump, R3 camera toggle, triggers fire/aim. Verified read, not assumed.
- Missing piece FOUND and FIXED: START (Gamepad_Special_Right) called
  `TogglePauseMenu` which ran `SetPause(true)` - a freeze. Now `SetPause(false)`
  always: pause widget over a LIVING world (job 250/253 clock law).
- Rebuilt `VEILEditor Win64 Development`: Succeeded, 25s.
- Autopilot run (`phi.autopilot 1`): process count 1, worldTime 65->100s,
  paused=0, pawn VEILCharacter_0 ticking, stage-1 waypoint reached on foot,
  combat firing, VRAM 3137, zero OOM/fatal lines.
- Physical-pad movement proof needs Tyree's hands: left stick moves,
  right stick looks, A jumps, R3 toggles camera, START pauses with no freeze.

## 814/815
- `D:\VEIL-OMNI\Saved\no_cartesian_excuse_protocol.txt` installed.
- `MUSE SWITCH.lnk` (Ctrl+Alt+M) created; `VEIL OMNI.lnk` door was missing,
  recreated (UnrealEditor.exe + VEIL.uproject -game).

## Seat/map
- seat719 run: SAVE RESULT True, actors 448, Vault present, Countess placed
  with SM_Countess, golden pitch -17.0324.
- `VEILDistrict.umap` written 2026-10-30 21:30:25, size 670004 = prior byte
  count (compression parity after delete-1/place-1, reported plainly, not
  claimed over).
- Full `Saved\seat719_out.txt` kept whole on the PC seat.

## Clean final state
- Clean relaunch (no autopilot): process count 1, worldTime 80->105s paused=0,
  VRAM 3446/6144, no OOM. Game is UP for Tyree now.
- Note: D:\VEIL-OMNI is not a git repo, so the game-tree diff stays local.
  This file is the pushed result record.
