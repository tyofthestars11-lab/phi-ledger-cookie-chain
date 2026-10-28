# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 23:27:43 UTC

## STEP 1
```
=== FIX 518 - THE ATTACH TAKES THE TRUE WATCHER LINE (Ground: job 514 gate held again and its prints name the miss precisely: the foreground reads stand at lines 132, 442, and 477, and the pattern reached for the first one outside the attach - line 132, which is the system declaration of the call, not a living call. The living watcher stands at line 442. This job carries the corrected pattern: declaration lines are skipped by name, every remaining foreground read is tried in order, and the first true call seats the memory - the terminal remembers the last non-terminal window its watcher sees, and the attach takes that window when the click lands on the terminal itself. The corrected pattern is dry proven against the exact three line shape before this job ships. On a clean patch the job closes the running terminal, compiles with the standing compiler line, relaunches the fixed build, and prints its log tail. Every variable carries the p518 prefix.) ===
CS LINES=1047
ATTACH DECL=1
ATTACH CALLS=2 at [456, 1032]
GWTPID LINES=[132, 442, 477]
GFW 131: [DllImport("user32.dll")] static extern IntPtr GetForegroundWindow();
GFW 439: IntPtr h = GetForegroundWindow();
GFW 475: IntPtr h = GetForegroundWindow();
TIMER LINES=[53, 222, 406, 633, 708, 792, 988]
ATTACH SPAN=473-486
STATIC FIELD CANDIDATES=3
WATCH LINE=442 var=pid
BRANCH=W
VERIFY lastPidField=1
VERIFY lastPidUse=1
PATCH OK
CSC This compiler is provided as part of the Microsoft (R) .NET Framework, but only supports language versions up to C# 5, which is no longer the latest version. For compilers that support newer versions of the C# programming language, see http://go.microsoft.com/fwlink/?LinkID=533240
CSC 
CSC PhiTerminal\PhiTerminal3.cs(116,24): warning CS0414: The field 'PhiTerminal.TermForm.freezeValue' is assigned but its value is never used
CSC PhiTerminal\PhiTerminal3.cs(117,44): warning CS0169: The field 'PhiTerminal.TermForm.freezeTimer' is never used
CSC PhiTerminal\PhiTerminal3.cs(118,24): warning CS0169: The field 'PhiTerminal.TermForm.freezeBtn' is never used
CSC PhiTerminal\PhiTerminal3.cs(130,20): warning CS0414: The field 'PhiTerminal.TermForm.PhiSelfNoticeTick' is assigned but its value is never used
EXE bytes=45056 written=10/28/2026 17:27:47
NEWTAIL 2026-10-28 17:27:47 OUT   each power toggles alone, and GODMODE ALL holds them all at once.
NEWTAIL 2026-10-28 17:27:47 OUT LIBRARY: 12 games on your shelves, 0 running now
NEWTAIL 2026-10-28 17:27:47 LIBRARY games=12 running=0
NEWTAIL 2026-10-28 17:27:47 HOOK SEATED v53 toggle=TILDE hook=264717
NEWTAIL 2026-10-28 17:27:47 TILDE POLL SEATED v53
NEWTAIL 2026-10-28 17:27:47 FGWATCH pid=27628 name=WindowsTerminal
PHI P518 VERDICT: ATTACH FIXED BUILD STANDING
JOB 518 DONE

```
