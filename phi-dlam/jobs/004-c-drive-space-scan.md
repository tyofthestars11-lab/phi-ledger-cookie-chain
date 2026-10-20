# Job 004 v2 — FAST targeted game-space scan (report only, deletes NOTHING)

v1 (full recursive C: crawl) hangs the local model on "thinking" — DO NOT run a full-drive crawl.
This version checks known game locations directly. Fast, small output.

## Do (in this order, print each line as you go — never sit silent)
1. C: free space: total / used / free in GB.
2. Size of each subfolder (GB, 1 decimal) in these folders IF they exist:
   - C:\Program Files (x86)\Ubisoft\Ubisoft Game Launcher\games
   - C:\Program Files\Ubisoft\Ubisoft Game Launcher\games
   - C:\Program Files\Epic Games
   - C:\XboxGames
   - C:\Games
   - C:\Program Files (x86)\Steam\steamapps\common
   Use ONE PowerShell command per folder:
   Get-ChildItem '<folder>' -Directory | ForEach-Object { $s = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "{0} = {1:N1} GB" -f $_.Name, ($s/1GB) }
3. Write the lines to phi-dlam/results/004-c-drive-space-scan.result.md, commit + push.

## Rules
- REPORT ONLY — delete/move/uninstall nothing.
- Keep output SHORT (folder names + GB lines only). No commentary paragraphs — the long output is what stalls the local seat.
- Missing folder = skip it silently.
