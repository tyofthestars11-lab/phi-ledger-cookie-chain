# Job 004 — C: drive space scan (report only, deletes NOTHING)

Tyree's read (2026-10-19): "i have too much space on my local disk its probably a game" — verify at the source, games first.

## Do
1. Report C: total size, used, free (GB, 2 decimals).
2. Top 25 folders on C:\ by total size (recursive), largest first — full path + GB.
3. Game libraries specifically, per game, largest first:
   - Steam: C:\Program Files (x86)\Steam\steamapps\common (and D:\SteamLibrary if present) — each game folder + GB; also read steamapps\appmanifest_*.acf for game names.
   - Epic: C:\Program Files\Epic Games — each folder + GB.
   - Xbox/PC Game Pass: C:\Program Files\WindowsApps may be access-denied; if so, say so plainly and list C:\XboxGames if present.
   - Riot / Battle.net / EA app folders if present under C:\Program Files or C:\Program Files (x86).
4. Largest single files on C:\ over 2 GB (top 20): path + GB. (hiberfil.sys / pagefile.sys noted if present.)
5. Write it all to phi-dlam/results/004-c-drive-space-scan.result.md and commit + push via the normal vault flow.

## Rules
- REPORT ONLY. Delete nothing, move nothing, uninstall nothing. Deletion is Tyree's word on a named basis, never the scan's.
- If a folder is access-denied, name it and move on — no permission surgery.
