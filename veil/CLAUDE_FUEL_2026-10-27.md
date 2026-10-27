# CLAUDE FUEL — 2026-10-27
Outside seat (Claude, relayed by Tyree). Treatment: the record decides;
payloads fold as TAKEN / ALREADY STANDS / LEFT. Her source was the
complete briefing (your_files/everything-for-claude-finish-the-games).

## Exchange 1 — jobs 182-184 rewritten in full (16:03 MDT)
She held the briefing's law (no guessing, evidence decides) and aimed
at the same three questions the queue already carries.
TAKEN:
- DECISION lines computed inside the smoke job itself, so the result
  file carries the verdict next to the numbers. Adopted into the
  lane's job 182 with the REAL v2 tokens (worldTime, timerActive,
  pawnTickEntries, sameWorld) — hers grepped a field name the code
  never prints ("PhiTickEntryCount="; the log token is
  "pawnTickEntries=%d"), so her decision lines could never fire.
ALREADY STANDS:
- The three jobs themselves: 182 (VEIL header 41-73 + sync + both
  builds + v2 smoke), 183 (A9 error census), 184 (PlayerStart verify)
  were written in-lane and pushed (commit 8c5032f) before her text
  arrived; the queue did not need replacing.
LEFT (would not run / would read nothing on the real machine):
- Format: her jobs are multi-block markdown writing to D:\jobs\*.txt.
  The PHI-DLAM runner executes ONE fenced PowerShell block per job
  under phi-dlam/jobs/ with the PHI-DIRECT marker, syncs via git pull
  at C:\Users\Admin\phi-vault, and returns results to
  phi-dlam/results/. Her outputs land where the lane never looks.
- 182 header path D:\VEIL\Source\VEIL\Public\VEILGameMode.h — the
  real path carries the Game folder: Public\Game\VEILGameMode.h
  (proven by jobs 175/180 printing from it). Her read hits no file.
- 182 builds the "VEIL"/"OMNI" game targets; the lane builds
  VEILEditor/OMNIEditor (the smokes run on the editor binary), and
  she never syncs the repo source, so her build compiles the PC's old
  code and the v2 fields never enter it.
- 182/184 launch UE4Editor.exe — no such binary in UE 5.8
  (UnrealEditor.exe), and her smoke passes no map, so it would not
  open OMNIWorld at all.
- 183 reads A9's errors from D:\OMNI-UE\Saved\Logs — A9 was VEIL's
  cook; its trace lives in the AutomationTool Log.txt under
  AppData\Roaming\Unreal Engine\AutomationTool\Logs\ (where job 178
  read it). Her parse reads the wrong project's editor logs.
- 183's asset classification by name pattern (_BP_/M_) and its
  ">5 assets = version mismatch" verdict are invented instruments;
  the lane's 183 lists the distinct assets the error lines themselves
  name, no threshold verdict attached.
- 184 uses a -run=DumpMap pass and greps a location format nothing
  emits; the lane's 184 loads the level in Python (the census pattern
  proven in jobs 170/171) and prints the PlayerStart transform.
