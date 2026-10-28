# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 23:17:57 UTC

## STEP 1
```
=== FIX 514 - THE ATTACH TAKES THE WATCHER ROAD (Ground: job 509 gate held with the census printed whole, and the prints name the miss exactly: a watcher already reads the foreground at line 442 of the terminal source, but it declares its process id inline inside the call, a shape the 509 pattern did not allow, so no branch fired. The two attach call sites at 456 and 1032 closed the other branch as well. This job carries the corrected pattern - the inline declaration allowed - and takes the watcher road: the terminal remembers the last non-terminal window the watcher sees, and when the click lands on the terminal itself the attach takes that remembered window instead of answering itself. On a clean patch the job closes the running terminal, compiles with the standing compiler line, relaunches the fixed build, and prints its log tail. Every variable carries the p514 prefix.) ===
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
PATCH GATE FAIL no branch shape
PHI P514 VERDICT: PATCH HELD - PRINTS ABOVE
JOB 514 DONE

```
