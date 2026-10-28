<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WORLD BUILDER WHOLE READ 436 - THE HUB BUILD AUTHORED FROM THE BUILDER ENTIRE (Ground read whole from job 430: the world source stands at seven files; VEILWorldBuilder cpp at 8646 bytes builds the standing district at runtime, ground plaza towers beacon and a PlayerStart, through its SpawnBlock instrument; VEILDistrictStreaming carries the district grid with DistrictId on each district; OMNIQuestContent carries the givers, fragments, and cache the GameMode spawns. Region mentions in source stand at Hub 0, and the Hub is the named first campaign tranche, so the Hub build enters through this builder and this GameMode. This job reads the builder whole so the build job is written against the standing code and nothing else. One, it prints VEILWorldBuilder cpp entire with line numbers, capped at 320 lines. Two, it prints VEILWorldBuilder h entire. Three, it prints the VEILGameMode cpp lines that name the builder, BuildWorld, quest content, and spawning, capped at 40. Four, the verdict in one line: BUILDER WHOLE READ with the cpp line count and the header line count. This job is read only and every variable carries the wb436 prefix.) ==='
$wb436root = 'D:\VEIL-OMNI'
$wb436src = Join-Path $wb436root 'Source\VEIL'
if (-not (Test-Path $wb436src)) { Write-Output 'BUILDER WHOLE READ HELD stage=source-missing'; Write-Output 'JOB 436 DONE'; exit 0 }
$wb436cpp = Get-ChildItem -Path $wb436src -Recurse -Filter 'VEILWorldBuilder.cpp' | Select-Object -First 1
$wb436cl = @()
if ($wb436cpp) { $wb436cl = Get-Content $wb436cpp.FullName; Write-Output ('--- BUILDER CPP lines=' + $wb436cl.Count + ' ---'); for ($wb436i = 0; $wb436i -lt $wb436cl.Count -and $wb436i -lt 320; $wb436i++) { Write-Output ('WB ' + ($wb436i + 1) + ': ' + $wb436cl[$wb436i]) } }
$wb436h = Get-ChildItem -Path $wb436src -Recurse -Filter 'VEILWorldBuilder.h' | Select-Object -First 1
$wb436hl = @()
if ($wb436h) { $wb436hl = Get-Content $wb436h.FullName; Write-Output ('--- BUILDER H lines=' + $wb436hl.Count + ' ---'); $wb436hl | ForEach-Object { Write-Output ('WH ' + $_) } }
$wb436gm = Get-ChildItem -Path $wb436src -Recurse -Filter 'VEILGameMode.cpp' | Select-Object -First 1
if ($wb436gm) { $wb436sp = @(Select-String -Path $wb436gm.FullName -Pattern 'SpawnActor|WorldBuilder|BuildWorld|QuestContent' -ErrorAction SilentlyContinue); $wb436sp | Select-Object -First 40 | ForEach-Object { Write-Output ('GM ' + $_.LineNumber + ': ' + $_.Line.Trim()) } }
Write-Output ('PHI WB436 VERDICT: BUILDER WHOLE READ cpp_lines=' + $wb436cl.Count + ' h_lines=' + $wb436hl.Count)
Write-Output 'JOB 436 DONE'
```
