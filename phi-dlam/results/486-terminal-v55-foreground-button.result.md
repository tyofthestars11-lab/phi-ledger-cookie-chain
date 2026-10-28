# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 20:18:36 UTC

## STEP 1
```
=== TERMINAL V5.5 486 - THE ATTACH BUTTON RUNS THE FOREGROUND CODE (Ground from Tyree at the panel, 2026-10-28, assembled whole: attach foreground worked and loaded the game, attach selected does not work, use that code for attached, the button is attach foreground slash selected with foreground code, and it does not hold the attached when clicked, just hovers blue over the game words. His photo of the merged button clicks reads the fault plain: the picked game was not running, the library scan found nothing running, and the foreground road seated last only ever saw the terminal itself, because a button click makes the terminal the front window. This job seats the foreground code as the button engine itself. The panel now watches the front window four times a second with the foreground code own eyes and remembers the last real game window standing in front, skipping system seats and the terminal itself. The ATTACH button runs that remembered foreground seat FIRST, then the picked game, then the library scan. The game pick now holds its blue when clicked, and the attached game is held in the panel title where it cannot be missed. The foreground function itself is not touched. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V55 with fgFirst. Every variable carries the fg486 prefix.) ===
SEL 426         private void AttachSelected()
SEL 427         {
SEL 428             // PHI v5.4: one attach door - the picked game first, then any running game in the library,
SEL 429             // then the foreground road merged in as the last road. The button never sits silent.
SEL 430             if (lib.SelectedItems.Count > 0)
SEL 431             {
SEL 432                 GameRow picked = (GameRow)lib.SelectedItems[0].Tag;
SEL 433                 if (TryAttachRow(picked)) { return; }
SEL 434                 Say(picked.Name + " is not running - looking for the game that is");
SEL 435             }
SEL 436             foreach (GameRow row in catalog)
SEL 437             {
SEL 438                 if (TryAttachRow(row)) { return; }
SEL 439             }
SEL 440             AttachForeground();
SEL 441         }
SA 470         private void SetAttached()
SA 471         {
SA 472             statusLine.Text = "ATTACHED: " + attached.ProcessName + " pid=" + attached.Id + (IsOnlineSeat(attached.ProcessName) ? "  (online game - powers rest here)" : "  (your powers work here)");
SA 473             Say("Attached to " + attached.ProcessName + ".");
SA 474             HostForm.Log("ATTACH " + attached.ProcessName + " pid=" + attached.Id);
SA 475         }
PYTHON=C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe
PATCHER GATE attachSelected=1
PATCHER GATE tryAttachRow=1
PATCHER GATE scanSay=1
PATCHER GATE attachedField=1
PATCHER GATE ctor=1
PATCHER GATE setAttached=1
PATCHER GATE listView=1
PATCHER GATE fgDecl=1
PATCHER GATE systemSeat=1
PATCHER GATE notYet=1
PATCHER SPAN sel=425..440 setAttached=469..474 ctor=129..216 field=108 lib=152
PATCHER BRACE DELTA open=7 close=7
PATCHER PATCH OK fgFirst=1
PANEL CLOSED pid=43184
CSC PhiTerminal\PhiTerminal3.cs(116,24): warning CS0414: The field 'PhiTerminal.TermForm.freezeValue' is assigned but its value is never used
CSC PhiTerminal\PhiTerminal3.cs(117,44): warning CS0169: The field 'PhiTerminal.TermForm.freezeTimer' is never used
CSC PhiTerminal\PhiTerminal3.cs(118,24): warning CS0169: The field 'PhiTerminal.TermForm.freezeBtn' is never used
EXE BYTES=45568
PHI FG486 VERDICT: TERMINAL V55 state=STANDS pid=42720 fgFirst=1
JOB 486 DONE

```
