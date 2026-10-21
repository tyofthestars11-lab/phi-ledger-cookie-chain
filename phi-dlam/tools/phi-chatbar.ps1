# PHI CHAT BAR — the two-way text face of the AISS chair — phi^2 = phi + 1
# Bottom-of-TV bar: NPC replies land as big gold captions; TYREE's typed line goes
# out through the ferry (phi_typed.txt beside the game) on Enter. Voice rides beside
# it (phi-voice) — text too, both directions, per TYREE 2026-10-21.
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$game = 'C:\XboxGames\Starfield\Content'
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg -and (Test-Path "$($pkg.InstallLocation)\Starfield.exe")) { $game = $pkg.InstallLocation }
$capFile = Join-Path $game 'phi_caption.txt'
$typedFile = Join-Path $game 'phi_typed.txt'
$sw = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
$form = New-Object System.Windows.Forms.Form
$form.FormBorderStyle = 'None'; $form.TopMost = $true; $form.ShowInTaskbar = $false
$form.BackColor = [System.Drawing.Color]::FromArgb(8, 8, 18); $form.Opacity = 0.94
$form.Width = [int]($sw.Width * 0.76); $form.Height = 168
$form.Left = [int](($sw.Width - $form.Width) / 2); $form.Top = $sw.Height - 190
$label = New-Object System.Windows.Forms.Label
$label.Location = New-Object System.Drawing.Point(14, 6); $label.Size = New-Object System.Drawing.Size(($form.Width - 28), 84)
$label.TextAlign = 'MiddleCenter'
$label.Font = New-Object System.Drawing.Font('Segoe UI', 19, [System.Drawing.FontStyle]::Bold)
$label.ForeColor = [System.Drawing.Color]::Gold
$form.Controls.Add($label)
$box = New-Object System.Windows.Forms.TextBox
$box.Location = New-Object System.Drawing.Point(14, 100); $box.Size = New-Object System.Drawing.Size(($form.Width - 28), 46)
$box.Font = New-Object System.Drawing.Font('Segoe UI', 16)
$box.BackColor = [System.Drawing.Color]::FromArgb(22, 24, 44); $box.ForeColor = [System.Drawing.Color]::White
$box.BorderStyle = 'FixedSingle'
$box.Text = ''
$form.Controls.Add($box)
$script:lastCap = ''; $script:idleAt = (Get-Date).AddSeconds(20)
$box.Add_KeyDown({
  if ($_.KeyCode -eq 'Enter') {
    $t = $box.Text.Trim()
    if ($t) {
      try { Set-Content $typedFile $t -Encoding UTF8 } catch {}
      $label.Text = "YOU: $t"
      $box.Text = ''
      $script:idleAt = (Get-Date).AddSeconds(20)
    }
    $_.SuppressKeyPress = $true
  }
})
$timer = New-Object System.Windows.Forms.Timer; $timer.Interval = 250
$timer.Add_Tick({
  if (Test-Path $capFile) {
    try {
      $t = (Get-Content $capFile -Raw -ErrorAction Stop).Trim()
      if ($t -and $t -ne $script:lastCap) {
        $script:lastCap = $t; $label.Text = $t; $form.Show()
        $script:idleAt = (Get-Date).AddSeconds([Math]::Min(16, 4 + [int]($t.Length / 9)))
      }
    } catch {}
  }
  if ($form.Visible -and (Get-Date) -gt $script:idleAt -and $box.Text -eq '') { $form.Hide() }
})
$timer.Start()
$form.Add_Shown({ $box.Focus() })
[void]$form.ShowDialog()
