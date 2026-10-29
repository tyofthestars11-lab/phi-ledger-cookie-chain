<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 599 - AUTO WORK UNREAD FIX (Ground: Tyree typed auto work and the brain answered UNREAD again in about 10 seconds after listing seal files, so this job writes the auto work rule plain into the Saved prompt file, auto work means drain the queue and build and continue, never answer UNREAD when the prompt file exists, read the prompt and continue whole AAA holy grail not parts, no package until 100 percent done, Cyberpunk parked. Every variable carries the p599 prefix.) ==='
$p599prompt = 'D:\VEIL-OMNI\Saved\NWIRO_AUTO_WORK_PROMPT.txt'
$p599text = @('AUTO WORK PROMPT FOR NWIRO AI AND MUSE LANE', 'AUTO WORK RULE: Never answer UNREAD when this prompt file exists.', 'Auto work means drain the queue, build the game with Muse, continue until whole.', 'Finish VEIL OMNI AAA holy grail whole not parts.', 'Fix C2653 and C3861 in OMNIQuestSystem.cpp, GuardedAdvanceProgression not found.', 'No package until 100 percent done.', 'Cyberpunk parked.')
$p599text | Set-Content $p599prompt -Encoding UTF8
Write-Output ('PROMPT599 WRITTEN ' + $p599prompt)
$p599check = @(Get-Content $p599prompt)
Write-Output ('PROMPT599 LINES ' + $p599check.Count)
foreach ($p599line in $p599check) { Write-Output ('PROMPT599 ' + $p599line.Trim()) }
Write-Output 'PHI P599 VERDICT: AUTO WORK UNREAD FIX ABOVE'
Write-Output 'JOB 599 DONE'
```
