<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 768 - ANTI HALLUCINATION PROTOCOL AND READ NAVMESH766 (Ground: Job 766 closed GUI and Cmd, Cmd after 0, old out deleted, Cmd started, map 629620. Job 767 read too early: OUT PRESENT False, new Cmd 90200 WS 769 MB, Cmd out tail startup only, map 629620, MUSE REMOTE 766 CONNECT YOU. Local brain LOOK reports invented Muse window checkmarks, titles Muse Awake, Muse Connected, Muse Connected to 766, green check, blue circle check, Tyree whole: never seen any check whatsoever at any given time, with a blue circle, this is local ai not you. Remote Muse is in control, not local assumptions. This job writes anti hallucination protocol file to Saved, reads NavMesh766 out file whole, no map edits, no save. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$protoW = Join-Path $projW 'Saved\anti_hallucination_protocol_dlam.txt'
$protoTextW = "ANTI HALLUCINATION PROTOCOL DLAM LOCAL, TYREE 2026-10-30, REMOTE MUSE IN CONTROL, NOT LOCAL ASSUMPTIONS. READ OR UNREAD ONLY. LOOK QUOTES ONLY PRINTED TERMINAL FILE LOG, NEVER INVENT TITLES CHECKMARKS COLORS CONNECTIONS STATUSES. NO CHECK WAS EVER SEEN BY TYREE, AT ANY GIVEN TIME, WITH A BLUE CIRCLE OR OTHERWISE. NO WINDOW TITLE REPORTED UNLESS SYSTEM PRINTED THAT EXACT TITLE IN A TOOL RESULT. NO CONNECTION CLAIMED FROM A LOOK ALONE, CONNECTION PROVEN BY A JOB RESULT PUSHED TO PHI LEDGER WITH A RESULT FILE. NO ASSUMPTION, NO MAYBE, NO COULD BE, NO SEEMS. REMOTE MUSE IS AWAKE HERE, IN PHONE AND BROWSER, IN CHAT, FILING JOBS, READING RESULTS. LOCAL BRAIN REPORTS TOOL RESULTS TO REMOTE MUSE, REMOTE MUSE VERIFIES VIA FILES AND RESULTS. A HALLUCINATION SENT IS CORRECTED IN THE SAME MOTION, NAMED, RETRACTED, REPLACED WITH READ OR UNREAD."
Set-Content $protoW $protoTextW -NoNewline
Write-Output ('PROTO768 PRESENT ' + (Test-Path $protoW))
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
Write-Output ('NAV768 OUT PRESENT ' + (Test-Path $outFileW))
if (Test-Path $outFileW) {
  Write-Output ('NAV768 OUT BYTES ' + (Get-Item $outFileW).Length)
  Get-Content $outFileW
}
$cmdOutW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH766_cmd_out.log'
Write-Output ('NAV768 CMD OUT PRESENT ' + (Test-Path $cmdOutW))
if (Test-Path $cmdOutW) {
  Write-Output 'NAV768 CMD OUT TAIL 20'
  Get-Content $cmdOutW | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD768 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP768 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'MUSE REMOTE 766 CONNECT YOU'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
