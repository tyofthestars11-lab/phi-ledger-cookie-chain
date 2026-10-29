# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 01:17:33 UTC

## STEP 1
```
=== JOB 536 - THE PAIR RESTORED FROM THE MERGED SEAT (Ground: job 535 printed the truth and then gated out - the merged line reads btnRow Controls Add MakeBtn ATTACHED FOREGROUND SELECTED wired to AttachSelected, the function Tyree named from the start as the one that never attached, and no ATTACH SELECTED line exists anywhere in the live source: the merge ate the pair and left a button calling the dead function. The current AttachForeground body also carries the watcher layers 495 was supposed to have removed - the remembered pid fallback and the system seat guard. This job restores the original pair in the merged line own seat, ATTACH SELECTED then ATTACH FOREGROUND wired straight to AttachForeground, and reseats the AttachForeground body verbatim to v4 - live foreground window at the click, pid, GetProcessById, SetAttached, nothing else. No watcher layer ships on this button wire. Count gated, backup kept, build and relaunch in the same job. Every variable carries the p536 prefix.) ===
COUNTS merged=1
PATCH OK - PAIR RESTORED=1 FUNCTION=RESEATED V4 VERBATIM
FUNC AFTER 476:         private void AttachForeground()
FUNC AFTER 477:         {
FUNC AFTER 478:             IntPtr h = GetForegroundWindow();
FUNC AFTER 479:             uint pid;
FUNC AFTER 480:             GetWindowThreadProcessId(h, out pid);
FUNC AFTER 481:             try { attached = Process.GetProcessById((int)pid); SetAttached(); }
FUNC AFTER 482:             catch (Exception ex) { Say("attach read an exception: " + ex.Message); }
FUNC AFTER 483:         }

PANEL CLOSED pid=12572
CSC PhiTerminal\PhiTerminal3.cs(116,24): warning CS0414: The field 'PhiTerminal.TermForm.freezeValue' is assigned but its value is never used
CSC PhiTerminal\PhiTerminal3.cs(117,44): warning CS0169: The field 'PhiTerminal.TermForm.freezeTimer' is never used
CSC PhiTerminal\PhiTerminal3.cs(118,24): warning CS0169: The field 'PhiTerminal.TermForm.freezeBtn' is never used
CSC PhiTerminal\PhiTerminal3.cs(130,20): warning CS0414: The field 'PhiTerminal.TermForm.PhiSelfNoticeTick' is assigned but its value is never used
EXE BYTES=44544 WRITE=10/28/2026 19:17:35
TERMINAL V60 STANDS pid=10480
PHI P536 VERDICT: PATCH AND BUILD LINES ABOVE - PROOF IS HIS CLICK PRINTING ATTACHED NAME PID
JOB 536 DONE

```
