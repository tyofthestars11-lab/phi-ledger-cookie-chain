<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PANEL GAME FILTER 461 - THE LIST SHOWS GAMES, NOT THE DESKTOP ITSELF (Ground from Tyree screen, 2026-10-28: the v2 panel stands interactive on his PC, buttons answering, and he attached the only row in view and asked the right question: what game is explorer. Explorer is no game: it is Windows Explorer, the desktop shell itself, 333 MB of windowed process, and the panel game detector, any windowed process over 150 MB, cannot tell the shell from a world. The fix is a system seat filter in ListGames: a named list of Windows shell and host processes, explorer at its head, is skipped before the size test, and a stale row revalidates at click time already by exception; this job adds the filter only. One, it counts the ListGames condition line and the IsOnlineSeat signature in PhiTerminal2 cs and proceeds only when each counts exactly one. Two, it backs the source up, inserts the IsSystemSeat method after IsOnlineSeat, and rewrites the condition line to require not a system seat. Three, it verifies both edits by count. Four, it closes the running panel, recompiles to the same exe, relaunches it standing, and prints the pid and the log tail. The verdict in one line: PANEL FILTER with the edit counts and the state. Every variable carries the pf461 prefix.) ==='
$pf461dir = 'C:\Users\Admin\PhiTerminal'
$pf461src = Join-Path $pf461dir 'PhiTerminal2.cs'
$pf461text = Get-Content $pf461src -Raw
$pf461cond = 'if (p.MainWindowHandle != IntPtr.Zero && p.WorkingSet64 > 150L * 1024 * 1024)'
$pf461condCount = ([regex]::Matches($pf461text, [regex]::Escape($pf461cond))).Count
$pf461anchor = 'private bool IsOnlineSeat(string name)'
$pf461anchorCount = ([regex]::Matches($pf461text, [regex]::Escape($pf461anchor))).Count
Write-Output ('COND=' + $pf461condCount + ' ANCHOR=' + $pf461anchorCount)
if ($pf461condCount -ne 1 -or $pf461anchorCount -ne 1) { Write-Output 'PHI PF461 VERDICT: PANEL FILTER SKIP gates closed'; Write-Output 'JOB 461 DONE'; return }
Copy-Item $pf461src ($pf461src + '.phi-backup-461') -Force
$pf461method = @('        private static readonly string SystemSeatList = "explorer|sihost|textinputhost|shellexperiencehost|startmenuexperiencehost|searchhost|phiterminal|runtimebroker|applicationframehost|systemsettings";', '        private bool IsSystemSeat(string name)', '        {', '            string n = name.ToLower();', '            foreach (string s in SystemSeatList.Split((char)124)) { if (n == s) return true; }', '            return false;', '        }', '')
$pf461methodText = [string]::Join("`n", $pf461method)
$pf461text = $pf461text.Replace($pf461anchor, $pf461methodText + $pf461anchor)
$pf461newCond = 'if (p.MainWindowHandle != IntPtr.Zero && p.WorkingSet64 > 150L * 1024 * 1024 && !IsSystemSeat(p.ProcessName))'
$pf461text = $pf461text.Replace($pf461cond, $pf461newCond)
Set-Content -Path $pf461src -Value $pf461text -NoNewline
$pf461check = Get-Content $pf461src -Raw
$pf461sysCount = ([regex]::Matches($pf461check, 'IsSystemSeat')).Count
Write-Output ('ISSYSTEMSEAT LINES=' + $pf461sysCount)
$pf461old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($pf461o in $pf461old) { Stop-Process -Id $pf461o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $pf461o.Id) }
Start-Sleep -Seconds 1
$pf461csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$pf461exe = Join-Path $pf461dir 'PhiTerminal.exe'
& $pf461csc /nologo /target:winexe /out:$pf461exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $pf461src | ForEach-Object { Write-Output ('CSC ' + $_) }
$pf461exeBytes = 0; if (Test-Path $pf461exe) { $pf461exeBytes = (Get-Item $pf461exe).Length }
Write-Output ('EXE BYTES=' + $pf461exeBytes)
$pf461pid = 0; $pf461state = 'NOT-LAUNCHED'
if ($pf461exeBytes -gt 0) {
  $pf461proc = Start-Process -FilePath $pf461exe -WorkingDirectory $pf461dir -PassThru
  Start-Sleep -Seconds 3
  $pf461check2 = Get-Process -Id $pf461proc.Id -ErrorAction SilentlyContinue
  if ($pf461check2) { $pf461state = 'STANDS'; $pf461pid = $pf461proc.Id } else { $pf461state = 'EXITED' }
}
$pf461log = Join-Path $pf461dir 'phi_terminal_universal.log'
if (Test-Path $pf461log) { Get-Content $pf461log -Tail 6 | ForEach-Object { Write-Output ('ULOG ' + $_) } }
Write-Output ('PHI PF461 VERDICT: PANEL FILTER state=' + $pf461state + ' pid=' + $pf461pid + ' exe_bytes=' + $pf461exeBytes)
Write-Output 'JOB 461 DONE'
```
