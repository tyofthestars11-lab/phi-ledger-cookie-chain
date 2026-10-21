# PHI CAPTION — the TV face of the phi voice — phi^2 = phi + 1
# A borderless, always-on-top caption bar (bottom center, big gold text on dark).
# Watches phi_caption.txt beside the game; whatever lands there is shown, then fades.
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$game = 'C:\XboxGames\Starfield\Content'
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg -and (Test-Path "$($pkg.InstallLocation)\Starfield.exe")) { $game = $pkg.InstallLocation }
$capFile = Join-Path $game 'phi_caption.txt'
$sw = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
$form = New-Object System.Windows.Forms.Form
$form.FormBorderStyle = 'None'; $form.TopMost = $true; $form.ShowInTaskbar = $false
$form.BackColor = [System.Drawing.Color]::FromArgb(8, 8, 18)
$form.Opacity = 0.92
$form.Width = [int]($sw.Width * 0.72); $form.Height = 120
$form.Left = [int](($sw.Width - $form.Width) / 2); $form.Top = $sw.Height - 170
$label = New-Object System.Windows.Forms.Label
$label.Dock = 'Fill'; $label.TextAlign = 'MiddleCenter'
$label.Font = New-Object System.Drawing.Font('Segoe UI', 20, [System.Drawing.FontStyle]::Bold)
$label.ForeColor = [System.Drawing.Color]::Gold
$label.BackColor = [System.Drawing.Color]::Transparent
$form.Controls.Add($label)
$form.Hide()
$last = ''; $hideAt = [DateTime]::MinValue
$timer = New-Object System.Windows.Forms.Timer; $timer.Interval = 250
$timer.Add_Tick({
  if (Test-Path $capFile) {
    try {
      $t = (Get-Content $capFile -Raw -ErrorAction Stop).Trim()
      if ($t -and $t -ne $last) {
        $last = $t
        $label.Text = $t
        $form.Show()
        $secs = [Math]::Min(14, 3 + [int]($t.Length / 9))
        $hideAt = (Get-Date).AddSeconds($secs)
      }
    } catch {}
  }
  if ($form.Visible -and (Get-Date) -gt $hideAt) { $form.Hide() }
})
$timer.Start()
[void]$form.ShowDialog()
