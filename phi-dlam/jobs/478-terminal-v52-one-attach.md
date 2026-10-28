<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.2 478 - ONE ATTACH, NOT TWO (Ground from Tyree at the panel, 2026-10-28: this attachment thing should be one not 2. The button row carries ATTACH SELECTED and ATTACH FOREGROUND side by side, two doors for one act, and with v5.1 the terminal seats itself anyway, so the hand attach that remains is a single override door. This job removes the ATTACH FOREGROUND button line from the row, count gated on the one line that builds it. The foreground function itself stays in the code, the command line still reaches it, but the surface shows ONE attach button, ATTACH SELECTED, beside REFRESH LIBRARY and ADD GAME, and the row breathes one button wider so GODMODE ALL stops crowding the edge. The source backs up first, the panel closes, the exe recompiles, the window relaunches standing, and the verdict prints: TERMINAL V52 with the removed count and the state. Every variable carries the oa478 prefix.) ==='
$oa478dir = 'C:\Users\Admin\PhiTerminal'
$oa478src = Join-Path $oa478dir 'PhiTerminal3.cs'
$oa478lines = @(Get-Content $oa478src)
$oa478hits = @()
for ($oa478i = 0; $oa478i -lt $oa478lines.Count; $oa478i++) { if ($oa478lines[$oa478i] -match 'MakeBtn' -and $oa478lines[$oa478i] -match 'ATTACH FOREGROUND') { $oa478hits += $oa478i } }
Write-Output ('BUTTON LINE=' + $oa478hits.Count)
if ($oa478hits.Count -ne 1) { Write-Output 'PHI OA478 VERDICT: TERMINAL V52 SKIP gate closed'; Write-Output 'JOB 478 DONE'; return }
Copy-Item $oa478src ($oa478src + '.phi-backup-478') -Force
$oa478out = @()
for ($oa478j = 0; $oa478j -lt $oa478lines.Count; $oa478j++) { if ($oa478j -ne $oa478hits[0]) { $oa478out += $oa478lines[$oa478j] } }
Set-Content -Path $oa478src -Value $oa478out
$oa478check = ([regex]::Matches((Get-Content $oa478src -Raw), 'ATTACH FOREGROUND')).Count
$oa478sel = ([regex]::Matches((Get-Content $oa478src -Raw), 'ATTACH SELECTED')).Count
Write-Output ('VERIFY foreground=' + $oa478check + ' selected=' + $oa478sel)
$oa478old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($oa478o in $oa478old) { Stop-Process -Id $oa478o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $oa478o.Id) }
Start-Sleep -Seconds 1
$oa478csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$oa478exe = Join-Path $oa478dir 'PhiTerminal.exe'
& $oa478csc /nologo /target:winexe /out:$oa478exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $oa478src | ForEach-Object { Write-Output ('CSC ' + $_) }
$oa478exeBytes = 0; if (Test-Path $oa478exe) { $oa478exeBytes = (Get-Item $oa478exe).Length }
Write-Output ('EXE BYTES=' + $oa478exeBytes)
$oa478pid = 0; $oa478state = 'NOT-LAUNCHED'
if ($oa478exeBytes -gt 0) {
  $oa478proc = Start-Process -FilePath $oa478exe -WorkingDirectory $oa478dir -PassThru
  Start-Sleep -Seconds 4
  $oa478check2 = Get-Process -Id $oa478proc.Id -ErrorAction SilentlyContinue
  if ($oa478check2) { $oa478state = 'STANDS'; $oa478pid = $oa478proc.Id } else { $oa478state = 'EXITED' }
}
Write-Output ('PHI OA478 VERDICT: TERMINAL V52 state=' + $oa478state + ' pid=' + $oa478pid + ' foregroundLeft=' + $oa478check)
Write-Output 'JOB 478 DONE'
```
