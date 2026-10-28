# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 19:07:58 UTC

## STEP 1
```
=== TERMINAL V4.1 472 - THE WINDOW BREATHES WHILE IT SCANS (Ground from Tyree hands, 2026-10-28: the mod terminal wont let me click on anything. The v4 powers run their memory scans on the window own thread: FIND reads the whole game process region by region, and FLY MARK reads it again float by float, so the moment a scan starts, the window thread is inside the scan and every click queues behind it, unanswered, until the scan ends, which over a full game can be a long silence. The cure is the classic one, in three count gated source edits with the file backed up first. One, Say learns to marshal: called from a worker it posts itself to the window thread, so scan output still lands in the box safely. Two, a RunBg helper arrives with a SetButtons walk: a scan starts on its own thread, the power buttons rest while it runs, and they wake when it ends. Three, the four scan buttons, FIND and REFINE on both slots and the two FLY marks, capture the typed number on the window thread and then run their scans through RunBg. The FLY mark also narrows to private memory only, where player heights live, which cuts its field enormously. Then the job closes the standing panel even if its thread is busy, recompiles to the same exe, relaunches it standing, and prints the pid and the log tail. The verdict in one line: TERMINAL V41 with the edit counts and the state. Every variable carries the tv472 prefix.) ===
SAY=1 HANDLERS=1,1,1,1,1,1
FLYCOND OCCURRENCES=2
RUNBG LINES=7
PANEL CLOSED pid=44916
CSC PhiTerminal\PhiTerminal3.cs(94,24): warning CS0414: The field 'PhiTerminal.TermForm.freezeValue' is assigned but its value is never used
CSC PhiTerminal\PhiTerminal3.cs(95,44): warning CS0169: The field 'PhiTerminal.TermForm.freezeTimer' is never used
CSC PhiTerminal\PhiTerminal3.cs(96,24): warning CS0169: The field 'PhiTerminal.TermForm.freezeBtn' is never used
EXE BYTES=36352
ULOG 2026-10-28 13:08:00 OUT   it reads what you have: your games, by their names, in sections.
ULOG 2026-10-28 13:08:00 OUT   powers are real now: FIND a number, change it, REFINE, FREEZE it. FLY has its own marks.
ULOG 2026-10-28 13:08:00 OUT   each power toggles alone, and GODMODE ALL holds them all at once.
ULOG 2026-10-28 13:08:00 OUT LIBRARY: 12 games on your shelves, 0 running now
ULOG 2026-10-28 13:08:00 LIBRARY games=12 running=0
ULOG 2026-10-28 13:08:00 HOOK SEATED v3 hook=155978255
PHI TV472 VERDICT: TERMINAL V41 state=STANDS pid=46624 runbg=7
JOB 472 DONE

```
