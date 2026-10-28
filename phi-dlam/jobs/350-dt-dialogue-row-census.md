<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DT DIALOGUE ROW CENSUS - GOLDEN EYE MISSING PIECE M5 (Tyrees assembled order, 2026-10-28: Finish / Golden Eye what you need and add it / All free all phi. The Golden Eye reversal read over the merged game named the open pair: the ported quest beats call FPHIVoice rows O01 to O18, and the base dialogue table does not carry the O rows yet - job 349 rides with PHI VOICE MISS until they stand in the table. Job 343 located both tables: VEIL D:\VEIL\Content\Data\DT_Dialogue.uasset at 5908 bytes, OMNI D:\OMNI-UE\Content\Data\DT_Dialogue.uasset at 5814 bytes. THIS JOB reads the row names straight out of both packages - data table row names stand as plain strings in the asset - and prints exactly which rows each table carries, so the table merge job is written from a read, not a guess. READ-ONLY: no editor, no writes, nothing moves.) ==='
foreach ($g in @(@('VEIL','D:\VEIL\Content\Data\DT_Dialogue.uasset'), @('OMNI','D:\OMNI-UE\Content\Data\DT_Dialogue.uasset'))) {
  $path = $g[1]
  if (-not (Test-Path $path)) { Write-Output ("PHI DT " + $g[0] + " TABLE MISSING"); continue }
  $bytes = [System.IO.File]::ReadAllBytes($path)
  $text = [System.Text.Encoding]::ASCII.GetString($bytes)
  $ids = [regex]::Matches($text, '[VO][0-9][0-9]') | ForEach-Object { $_.Value } | Sort-Object -Unique
  Write-Output ("PHI DT " + $g[0] + " rows=" + $ids.Count + " : " + ($ids -join ' '))
  $fields = [regex]::Matches($text, '[A-Za-z_][A-Za-z0-9_ ]{2,40}') | ForEach-Object { $_.Value.Trim() } | Where-Object { $_ -match 'Speaker|Line|Text|Wave|Sound|Row' } | Sort-Object -Unique | Select-Object -First 20
  Write-Output ("PHI DT " + $g[0] + " fields: " + ($fields -join ' | '))
}
Write-Output 'JOB 350 DONE'
```
