<!-- PHI-DIRECT -->
```powershell
Write-Output '=== REGION SEATING SOURCE PULL - GOLDEN EYE MISSING PIECES M3 AND M6 (Tyrees assembled order, 2026-10-28: Finish / Golden Eye what you need and add it / All free all phi. The Golden Eye read named the open pairs: OMNIWorld stands in the base as a map file (job 343, verified) but is not yet seated as the Omni District region of the one world, and the five regions of the bible do not yet stand on disk as one world. The base already carries a streaming system - VEILDistrictStreaming - whose real shape decides how the District seats: as a streamed region of the one map, or as a travel-linked region under the one GameMode. THIS JOB prints the full current text of the seating-relevant sources from the PC: VEILDistrictStreaming header and cpp, VEILWorldBuilder header, and the travel and streaming mentions across the VEIL GameMode and Character sources, so the seating job is written from a read. READ-ONLY: nothing on the PC changes.) ==='
$files = @(
  'D:\VEIL\Source\VEIL\Public\World\VEILDistrictStreaming.h',
  'D:\VEIL\Source\VEIL\Private\World\VEILDistrictStreaming.cpp',
  'D:\VEIL\Source\VEIL\Public\World\VEILWorldBuilder.h'
)
foreach ($f in $files) {
  Write-Output "===== FILE $f ====="
  if (Test-Path $f) { Write-Output ([System.IO.File]::ReadAllText($f)) } else { Write-Output "FILE MISSING: $f" }
  Write-Output "===== END $f ====="
}
Write-Output '===== TRAVEL AND STREAMING MENTIONS ====='
Get-ChildItem 'D:\VEIL\Source' -Recurse -Include '*.cpp','*.h' -File -ErrorAction SilentlyContinue | Select-String -Pattern 'ServerTravel|OpenLevel|LoadStreamLevel|Streaming|Teleport' -ErrorAction SilentlyContinue | Select-Object -First 40 | ForEach-Object { Write-Output ("PHI SEAT " + $_.Filename + ":" + $_.LineNumber + " " + $_.Line.Trim()) }
Write-Output 'JOB 351 DONE'
```
