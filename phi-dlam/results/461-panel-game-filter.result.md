# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 18:38:55 UTC

## STEP 1
```
=== PANEL GAME FILTER 461 - THE LIST SHOWS GAMES, NOT THE DESKTOP ITSELF (Ground from Tyree screen, 2026-10-28: the v2 panel stands interactive on his PC, buttons answering, and he attached the only row in view and asked the right question: what game is explorer. Explorer is no game: it is Windows Explorer, the desktop shell itself, 333 MB of windowed process, and the panel game detector, any windowed process over 150 MB, cannot tell the shell from a world. The fix is a system seat filter in ListGames: a named list of Windows shell and host processes, explorer at its head, is skipped before the size test, and a stale row revalidates at click time already by exception; this job adds the filter only. One, it counts the ListGames condition line and the IsOnlineSeat signature in PhiTerminal2 cs and proceeds only when each counts exactly one. Two, it backs the source up, inserts the IsSystemSeat method after IsOnlineSeat, and rewrites the condition line to require not a system seat. Three, it verifies both edits by count. Four, it closes the running panel, recompiles to the same exe, relaunches it standing, and prints the pid and the log tail. The verdict in one line: PANEL FILTER with the edit counts and the state. Every variable carries the pf461 prefix.) ===
COND=1 ANCHOR=1
ISSYSTEMSEAT LINES=2
PANEL CLOSED pid=32072
EXE BYTES=17408
ULOG 2026-10-28 12:36:20 GODMODE ARMED explorer base=0x7FF7EC850000
ULOG 2026-10-28 12:38:57 OUT         .  *  .   PHI TERMINAL v2 - THE PANEL   .  *  .
ULOG 2026-10-28 12:38:57 OUT   click a game, click ATTACH, click GODMODE. typing still works below.
ULOG 2026-10-28 12:38:57 OUT   the universe is alive; so is this terminal.
ULOG 2026-10-28 12:38:57 OUT 0 living worlds in view
ULOG 2026-10-28 12:38:57 HOOK SEATED v2 hook=216203917 handle=8195112
PHI PF461 VERDICT: PANEL FILTER state=STANDS pid=29608 exe_bytes=17408
JOB 461 DONE

```
