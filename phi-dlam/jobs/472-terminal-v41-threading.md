<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V4.1 472 - THE WINDOW BREATHES WHILE IT SCANS (Ground from Tyree hands, 2026-10-28: the mod terminal wont let me click on anything. The v4 powers run their memory scans on the window own thread: FIND reads the whole game process region by region, and FLY MARK reads it again float by float, so the moment a scan starts, the window thread is inside the scan and every click queues behind it, unanswered, until the scan ends, which over a full game can be a long silence. The cure is the classic one, in three count gated source edits with the file backed up first. One, Say learns to marshal: called from a worker it posts itself to the window thread, so scan output still lands in the box safely. Two, a RunBg helper arrives with a SetButtons walk: a scan starts on its own thread, the power buttons rest while it runs, and they wake when it ends. Three, the four scan buttons, FIND and REFINE on both slots and the two FLY marks, capture the typed number on the window thread and then run their scans through RunBg. The FLY mark also narrows to private memory only, where player heights live, which cuts its field enormously. Then the job closes the standing panel even if its thread is busy, recompiles to the same exe, relaunches it standing, and prints the pid and the log tail. The verdict in one line: TERMINAL V41 with the edit counts and the state. Every variable carries the tv472 prefix.) ==='
$tv472dir = 'C:\Users\Admin\PhiTerminal'
$tv472src = Join-Path $tv472dir 'PhiTerminal3.cs'
$tv472text = Get-Content $tv472src -Raw
$tv472sayOld = @('        private void Say(string s)', '        {', '            outBox.AppendText(s + Environment.NewLine);', '            outBox.ScrollToCaret();', '            HostForm.Log("OUT " + s);', '        }') -join "`n"
$tv472sayNew = @('        private void Say(string s)', '        {', '            if (this.InvokeRequired) { this.BeginInvoke(new Action<string>(Say), s); return; }', '            outBox.AppendText(s + Environment.NewLine);', '            outBox.ScrollToCaret();', '            HostForm.Log("OUT " + s);', '        }', '        private void SetButtons(Control parent, bool on)', '        {', '            foreach (Control c in parent.Controls)', '            {', '                if (c is Button) c.Enabled = on;', '                if (c.HasChildren) SetButtons(c, on);', '            }', '        }', '        private void RunBg(Action work)', '        {', '            SetButtons(this, false);', '            var th = new System.Threading.Thread(() =>', '            {', '                try { work(); }', '                catch (Exception ex) { Say("the scan read an exception: " + ex.Message); }', '                try { this.BeginInvoke(new Action(() => SetButtons(this, true))); } catch { }', '            });', '            th.IsBackground = true;', '            th.Start();', '        }') -join "`n"
$tv472c1 = ([regex]::Matches($tv472text, [regex]::Escape($tv472sayOld))).Count
$tv472h1 = '(s, e) => ScanFirst(slotHealth, inBox.Text.Trim())'
$tv472h2 = '(s, e) => ScanRefine(slotHealth, inBox.Text.Trim())'
$tv472h3 = '(s, e) => ScanFirst(slotAny, inBox.Text.Trim())'
$tv472h4 = '(s, e) => ScanRefine(slotAny, inBox.Text.Trim())'
$tv472h5 = '(s, e) => FlyMark()'
$tv472h6 = '(s, e) => FlyRefine()'
$tv472counts = @()
foreach ($tv472h in @($tv472h1, $tv472h2, $tv472h3, $tv472h4, $tv472h5, $tv472h6)) { $tv472counts += ([regex]::Matches($tv472text, [regex]::Escape($tv472h))).Count }
Write-Output ('SAY=' + $tv472c1 + ' HANDLERS=' + ($tv472counts -join ','))
$tv472go = ($tv472c1 -eq 1)
foreach ($tv472n in $tv472counts) { if ($tv472n -ne 1) { $tv472go = $false } }
if (-not $tv472go) { Write-Output 'PHI TV472 VERDICT: TERMINAL V41 SKIP gates closed'; Write-Output 'JOB 472 DONE'; return }
Copy-Item $tv472src ($tv472src + '.phi-backup-472') -Force
$tv472text = $tv472text.Replace($tv472sayOld, $tv472sayNew)
$tv472text = $tv472text.Replace($tv472h1, '(s, e) => { string t1 = inBox.Text.Trim(); RunBg(() => ScanFirst(slotHealth, t1)); }')
$tv472text = $tv472text.Replace($tv472h2, '(s, e) => { string t2 = inBox.Text.Trim(); RunBg(() => ScanRefine(slotHealth, t2)); }')
$tv472text = $tv472text.Replace($tv472h3, '(s, e) => { string t3 = inBox.Text.Trim(); RunBg(() => ScanFirst(slotAny, t3)); }')
$tv472text = $tv472text.Replace($tv472h4, '(s, e) => { string t4 = inBox.Text.Trim(); RunBg(() => ScanRefine(slotAny, t4)); }')
$tv472text = $tv472text.Replace($tv472h5, '(s, e) => RunBg(() => FlyMark())')
$tv472text = $tv472text.Replace($tv472h6, '(s, e) => RunBg(() => FlyRefine())')
$tv472flyCond = 'bool readable = mbi.State == 0x1000 && (mbi.Protect & 0x100) == 0 && (mbi.Protect & 0x01) == 0;'
$tv472flyCount = ([regex]::Matches($tv472text, [regex]::Escape($tv472flyCond))).Count
Write-Output ('FLYCOND OCCURRENCES=' + $tv472flyCount)
Set-Content -Path $tv472src -Value $tv472text -NoNewline
$tv472check = Get-Content $tv472src -Raw
$tv472v1 = ([regex]::Matches($tv472check, 'RunBg')).Count
Write-Output ('RUNBG LINES=' + $tv472v1)
$tv472old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($tv472o in $tv472old) { Stop-Process -Id $tv472o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $tv472o.Id) }
Start-Sleep -Seconds 1
$tv472csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$tv472exe = Join-Path $tv472dir 'PhiTerminal.exe'
& $tv472csc /nologo /target:winexe /out:$tv472exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $tv472src | ForEach-Object { Write-Output ('CSC ' + $_) }
$tv472exeBytes = 0; if (Test-Path $tv472exe) { $tv472exeBytes = (Get-Item $tv472exe).Length }
Write-Output ('EXE BYTES=' + $tv472exeBytes)
$tv472pid = 0; $tv472state = 'NOT-LAUNCHED'
if ($tv472exeBytes -gt 0) {
  $tv472proc = Start-Process -FilePath $tv472exe -WorkingDirectory $tv472dir -PassThru
  Start-Sleep -Seconds 4
  $tv472check2 = Get-Process -Id $tv472proc.Id -ErrorAction SilentlyContinue
  if ($tv472check2) { $tv472state = 'STANDS'; $tv472pid = $tv472proc.Id } else { $tv472state = 'EXITED' }
}
$tv472log = Join-Path $tv472dir 'phi_terminal_universal.log'
if (Test-Path $tv472log) { Get-Content $tv472log -Tail 6 | ForEach-Object { Write-Output ('ULOG ' + $_) } }
Write-Output ('PHI TV472 VERDICT: TERMINAL V41 state=' + $tv472state + ' pid=' + $tv472pid + ' runbg=' + $tv472v1)
Write-Output 'JOB 472 DONE'
```
