<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MERGED SIZE CENSUS ON D - BOTH PROJECTS EXACT, TONIGHT (Tyree asked the total GB of the merged game and answered the census scope himself: On D. Jobs 080 and 089 hold yesterdays measures - VEIL 5.55 GB at 080 with Content 0.03, Content 10.15 GB after 089; OMNI-UE 2.57 GB at 080, Content 0.12 GB after 089 - but jobs 315 through 338 cooked and built again on both projects since then, so tonights exact total is unread. Tyrees merge word of 2026-10-28 makes the pair one game, VEIL OMNI, so this census reads the pair as one: per-project totals on D, every top-level folder sized separately so Content stands split from Intermediate cache and Binaries, the Builds archives sized, the shared-tree overlap named (Content subtrees present in BOTH projects counted once for the merged-true figure), and D free/total to close. READ-ONLY - nothing moves, nothing is deleted, nothing is packed by this job.) ==='
function SizeGB($p) { if (-not (Test-Path $p)) { return $null }; $s = (Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum).Sum; if ($null -eq $s) { $s = 0 }; return [math]::Round($s / 1GB, 3) }
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  "##### $name $proj #####" | Write-Output
  if (-not (Test-Path $proj)) { Write-Output "$name PROJECT ABSENT"; continue }
  $total = SizeGB $proj
  Write-Output "$name TOTAL GB: $total"
  foreach ($sub in @('Content','Binaries','Intermediate','Saved','Source','Config','Plugins')) {
    $v = SizeGB "$proj\$sub"
    if ($null -ne $v) { Write-Output "$name $sub GB: $v" } else { Write-Output "$name $sub ABSENT" }
  }
}
Write-Output '##### BUILDS #####'
foreach ($b in @('D:\Builds\VEIL','D:\Builds\OMNI')) { $v = SizeGB $b; if ($null -ne $v) { Write-Output "BUILDS $b GB: $v" } else { Write-Output "BUILDS $b ABSENT" } }
Write-Output '##### CONTENT SUBTREES - SHARED OVERLAP (present in both = counted once in the merged game) #####'
$veilSubs = @{}; $omniSubs = @{}
if (Test-Path 'D:\VEIL\Content') { Get-ChildItem 'D:\VEIL\Content' -Directory -ErrorAction SilentlyContinue | ForEach-Object { $veilSubs[$_.Name] = SizeGB $_.FullName } }
if (Test-Path 'D:\OMNI-UE\Content') { Get-ChildItem 'D:\OMNI-UE\Content' -Directory -ErrorAction SilentlyContinue | ForEach-Object { $omniSubs[$_.Name] = SizeGB $_.FullName } }
foreach ($k in ($veilSubs.Keys | Sort-Object)) { Write-Output "VEIL Content\$k GB: $($veilSubs[$k])" }
foreach ($k in ($omniSubs.Keys | Sort-Object)) { $shared = if ($veilSubs.ContainsKey($k)) { ' SHARED-WITH-VEIL' } else { '' }; Write-Output "OMNI Content\$k GB: $($omniSubs[$k])$shared" }
$dv = Get-PSDrive D
Write-Output ("D FREE GB: " + [math]::Round($dv.Free / 1GB, 2) + " / TOTAL GB: " + [math]::Round(($dv.Free + $dv.Used) / 1GB, 2))
Write-Output 'MERGED SIZE CENSUS DONE'
```
