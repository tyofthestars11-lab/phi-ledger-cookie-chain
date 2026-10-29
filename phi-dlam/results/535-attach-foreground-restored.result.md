# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 01:13:44 UTC

## STEP 1
```
=== JOB 535 - ATTACH FOREGROUND RESTORED AS ITS OWN BUTTON (Ground: Tyree at his screen 2026-10-28 18:31 MDT - the merged button named ATTACHED FOREGROUND SELECTED clicks and does nothing, no acknowledgment, header still NO GAME YET with Cyberpunk 2077 selected. The original pair from v4 sat side by side: ATTACH SELECTED and ATTACH FOREGROUND, and the foreground button worked because it called the v4 body verbatim - live foreground window at the click, pid, GetProcessById, SetAttached speaking ATTACHED name pid. Five versions patched around the button instead of restoring it. This job prints the current merged button handler body and the current AttachForeground body whole into the result first, then retires the merged button from the panel and restores ATTACH FOREGROUND as its own button next to ATTACH SELECTED, wired straight to AttachForeground. The button wire is the reversion; unrelated watcher code stands untouched by this job. Count gated, backup kept, build and relaunch in the same job. Every variable carries the p535 prefix.) ===
MERGED 178: btnRow.Controls.Add(MakeBtn("ATTACHED FOREGROUND SELECTED", (s, e) => AttachSelected()));
FUNC 475:         private void AttachForeground()
FUNC 476:         {
FUNC 477:             IntPtr h = GetForegroundWindow();
FUNC 478:             uint pid;
FUNC 479:             GetWindowThreadProcessId(h, out pid);
FUNC 480:                         if ((int)pid == System.Diagnostics.Process.GetCurrentProcess().Id) { if (PhiLastFgPid > 0) { pid = (uint)PhiLastFgPid; } else { Say("That is the terminal itself - open your game and I attach on my own."); return; } }
FUNC 481:             try
FUNC 482:             {
FUNC 483:                 Process fp = Process.GetProcessById((int)pid);
FUNC 484:                 if (IsSystemSeat(fp.ProcessName)) { Say("That is not a game window - open your game and I attach on my own."); return; }
FUNC 485:                 attached = fp; SetAttached();
FUNC 486:             }
FUNC 487:             catch (Exception ex) { Say("attach read an exception: " + ex.Message); }
FUNC 488:         }
IMPORT FGW=1 GWTPID=1
READ535 DONE
COUNTS merged=1 foreground=0 selected=0
PATCH GATE FAIL - SELECTED COUNT=0

BUILD SKIPPED - PATCH DID NOT PRINT OK
PHI P535 VERDICT: PRINT PATCH AND BUILD LINES ABOVE - PROOF IS HIS CLICK PRINTING ATTACHED NAME PID
JOB 535 DONE

```
