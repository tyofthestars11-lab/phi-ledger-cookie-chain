# Job 016 — PC storage TON KRAKEN scan (REPORT ONLY — deletes / moves / compresses NOTHING)

Tyree's law for this machine: Starfield STAYS on C: (install + mods + saves untouchable).
Every other game belongs on D:. C: must come back to 100+ GB free (now 34 GB).
Something unknown is eating C: — this scan NAMES it, by size, so Tyree decides what dies.
NO full-drive recursive crawl (that hung the seat before) — targeted fast scans, print each line as you go.

## Do (in this order, print each line as you go — never sit silent)
1. Physical disks, one line each: name, media type (HDD/SSD), size GB, health.
   Get-PhysicalDisk | ForEach-Object { "{0} | {1} | {2:N0} GB | {3}" -f $_.FriendlyName, $_.MediaType, ($_.Size/1GB), $_.HealthStatus }
   Plus which disk number serves C: and which serves D: (Get-Partition -DriveLetter C / D -> DiskNumber).
2. C:\ top-level folders, size GB (1 decimal), biggest first:
   Get-ChildItem 'C:\' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { $s = (Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "{0} = {1:N1} GB" -f $_.FullName, ($s/1GB) } | Sort-Object { [double]($_ -replace '.*= ','') -replace ' GB','' } -Descending
   Root system files (print each that exists): pagefile.sys, hiberfil.sys, swapfile.sys sizes in GB.
   (Get-Item 'C:\pagefile.sys' -Force -ErrorAction SilentlyContinue etc.)
3. GAMES inventory — every game folder with size, on BOTH drives. For each library folder that exists, one line per game:
   - C:\Program Files (x86)\Steam\steamapps\common and D:\SteamLibrary\steamapps\common (and any other steamapps\common found via libraryfolders.vdf — read it if present)
   - C:\XboxGames, C:\Program Files\Epic Games, C:\Program Files (x86)\Epic Games, Ubisoft games folders (both Program Files roots), C:\Games, D:\Games
   Use the job-009 per-folder command shape (Get-ChildItem -Directory + recursive Measure-Object per game). Line format: "GAME | <full path> = X GB".
   STARFIELD: print its exact install path + total size + size of its Data subfolder. Print the word STARFIELD in the line.
4. Mod + save ground (MEASURE ONLY, never touch): sizes of C:\Users\Admin\Documents\My Games\Starfield (whole + its Data if present), any ModOrganizer2 folder (search C:\ and D:\ roots + AppData\Local\ModOrganizer), Vortex folders (AppData\Roaming\Vortex, C:\Program Files\Black Tree Gaming Ltd) — path = X GB lines, or "absent" if not found.
5. C:\Users\Admin subfolders, size GB, biggest first (Downloads, Documents, Videos, Pictures, Desktop, Music, AppData): same per-folder command shape as step 2 on 'C:\Users\Admin'.
   Then AppData\Local top-level rollup (its subfolders, biggest first, top 20 only).
6. Windows regrowables (measure only): C:\Windows\Temp, C:\Windows\SoftwareDistribution\Download, C:\$Recycle.Bin, C:\Users\Admin\AppData\Local\Temp, NVIDIA DXCache (AppData\Local\NVIDIA\DXCache), D3DSCache — path = X GB lines, skip silently if absent.
7. D:\ top-level folders, size GB, biggest first (same command shape as step 2 on 'D:\').
8. Write ALL printed lines, in order, under the section headers STEP1..STEP7, to phi-dlam/results/016-pc-storage-ton-kraken-scan.result.md, commit + push.

## Rules
- REPORT ONLY. Delete / move / uninstall / compress NOTHING. This job only measures.
- Starfield, its mods, load order, configs, and saves: measure only, forever, in every job.
- Keep lines compact: "path = X GB". No commentary paragraphs — long output stalls the local seat.
- Missing folder = skip silently. A step that errors = print "STEP N ERROR" + the error line and CONTINUE to the next step.
- If one folder's measure runs past ~4 minutes, print "STEP N SLOW: <path>" and move on — never let one folder eat the job.
