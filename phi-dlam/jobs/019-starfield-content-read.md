<!-- PHI-DIRECT -->
# JOB 019 - STARFIELD CONTENT REGISTRATION READ (DIRECT)

Authored 2026-10-26 after the D: game's dialog: "This save relies on content
not available on this platform." The save EXISTS (job 017 proved the wgs
folder alive). This read names what the D: install currently sees: the load
order files in AppData\Local\Starfield, and what actually sits in the D:
game's Data folder. REPORT ONLY.

## STEP 1 - LOAD ORDER FILES + D: DATA FOLDER
```powershell
$als = "$env:LOCALAPPDATA\Starfield"
if (Test-Path $als) { Get-ChildItem $als -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object { "ALS: $($_.FullName.Substring($als.Length)) - $([math]::Round($_.Length/1KB,1)) KB - $($_.LastWriteTime.ToString('yyyy-MM-dd HH:mm'))" } } else { "ALS ABSENT: $als" }
$data = 'D:\XboxGames\Starfield\Content\Data'
if (Test-Path $data) {
  $df = Get-ChildItem $data -File -ErrorAction SilentlyContinue
  "DATA FILE COUNT: $($df.Count)"
  "DATA ESM/ESP/ESL: $(($df | Where-Object Extension -in '.esm','.esp','.esl').Count)"
  "DATA BA2: $(($df | Where-Object Extension -eq '.ba2').Count)"
  $df | Sort-Object Length -Descending | Select-Object -First 15 | ForEach-Object { "DATAFILE: $($_.Name) - $([math]::Round($_.Length/1MB,1)) MB" }
} else { "DATA ABSENT: $data" }
$cc = 'D:\XboxGames\Starfield\Content'
if (Test-Path $cc) { Get-ChildItem $cc -Directory -ErrorAction SilentlyContinue | ForEach-Object { "CONTENT-DIR: $($_.Name)" } }
```
