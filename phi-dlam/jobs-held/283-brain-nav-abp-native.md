---
id: 283
title: BRAIN - nav + ABP payloads run natively in the seat session, then the VEIL standalone proof
---

CONTEXT (measured, from this seat's record): the git layer is healed — your operator ran the fix block at 20:27 MDT: commit 5c120c1 filed the runner patch, git pull --rebase succeeded, the tree is clean, push is up-to-date. Jobs 274/275/276 then ran under the patched DIRECT drain, but their reports END right before their editor-launch section (274 stops after its ini lines, 276 after its ini sweep): a DIRECT block that Start-Process-launches UnrealEditor-Cmd from inside a Start-Job child loses everything after the launch point. The payloads themselves never executed. Job 277 LANDED whole: job 273's VEIL cook = **BUILD SUCCESSFUL, AutomationTool ExitCode=0, D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe stamped 10/27/2026 7:31:50 PM**.

YOUR TASK — run the payloads through YOUR OWN shell (run_powershell, in this session — the native channel, no Start-Job child):

1. The payload scripts are embedded as base64 inside the job files already on your disk:
   - C:\Users\Admin\phi-vault\phi-dlam\jobs\274-navmesh-veil-fresh.md (payload: D:\_PhiHolding\navfix274.py, map /Game/Maps/VEILDistrict, VEIL project)
   - ...\275-navmesh-omni-fresh.md (payload: D:\_PhiHolding\navfix275.py, map /Game/Maps/OMNIWorld, OMNI-UE project)
   - ...\276-abp-carrier-fresh.md (payload: D:\_PhiHolding\abp276.py, both projects)
   For each: read the job file, extract the base64 string from its $b64 assignment, [IO.File]::WriteAllBytes the target .py. If D:\_PhiHolding\navfix274.py etc. already exist from the drain's partial run, overwrite them the same way.
2. Run each commandlet DIRECTLY in your shell, exactly as the job files specify (UnrealEditor-Cmd.exe -run=pythonscript -script=<py> -abslog=<project>\Saved\<name>.log, waiting for completion), then Select-String the abslog for the census tokens the job files name (NAVFIX274 / NAVFIX275 / ABPFIX output lines, Error|Traceback|Exception) and report what the logs actually carry: recast counts, bounds placed or already present, PlayerStart ground verdicts, the Countess post-process slot read (and cleared, if it named the quarantined blueprint).
3. Then the standalone proof (job 278's substance): launch D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe with -PhiStandaloneProof, wait for its log at D:\VEIL\Saved\Logs\VEIL.log, and report the PHI STANDALONE PROOF / PHI CLOCK PROOF lines verbatim.
4. Report everything through your normal result channel. If a commandlet errors, report the log's own lines — never a summary of what should have happened.
