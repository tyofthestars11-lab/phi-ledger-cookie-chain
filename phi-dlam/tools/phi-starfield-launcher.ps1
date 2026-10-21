# STARFIELD PHI LAUNCHER — talk-and-click front door — phi^2 = phi + 1
# One window. Big buttons. No typing. G-Assist opens it by its name: STARFIELD PHI.
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$work = "$env:USERPROFILE\phi-tools"
$form = New-Object System.Windows.Forms.Form
$form.Text = 'STARFIELD PHI'
$form.Size = New-Object System.Drawing.Size(560, 640)
$form.StartPosition = 'CenterScreen'
$form.BackColor = [System.Drawing.Color]::FromArgb(10, 12, 26)
$form.ForeColor = [System.Drawing.Color]::Gold
$title = New-Object System.Windows.Forms.Label
$title.Text = 'STARFIELD PHI'
$title.Font = New-Object System.Drawing.Font('Segoe UI', 26, [System.Drawing.FontStyle]::Bold)
$title.ForeColor = [System.Drawing.Color]::Gold
$title.AutoSize = $true; $title.Location = New-Object System.Drawing.Point(24, 16)
$form.Controls.Add($title)
$status = New-Object System.Windows.Forms.Label
$status.Text = 'Ready when you are, Captain.'
$status.Font = New-Object System.Drawing.Font('Segoe UI', 12)
$status.ForeColor = [System.Drawing.Color]::White
$status.AutoSize = $true; $status.Location = New-Object System.Drawing.Point(26, 66)
$form.Controls.Add($status)
function New-PhiButton($text, $y, $action) {
  $b = New-Object System.Windows.Forms.Button
  $b.Text = $text
  $b.Font = New-Object System.Drawing.Font('Segoe UI', 15, [System.Drawing.FontStyle]::Bold)
  $b.Size = New-Object System.Drawing.Size(500, 58)
  $b.Location = New-Object System.Drawing.Point(26, $y)
  $b.BackColor = [System.Drawing.Color]::FromArgb(30, 34, 64)
  $b.ForeColor = [System.Drawing.Color]::Gold
  $b.FlatStyle = 'Flat'
  $b.Add_Click($action)
  $form.Controls.Add($b)
}
function Run-Tool($file, $label) {
  $p = Join-Path $work $file
  if (Test-Path $p) { Start-Process powershell -ArgumentList "-ExecutionPolicy Bypass -File `"$p`""; $status.Text = "$label — rising." }
  else { $status.Text = "$label is not on this machine yet." }
}
New-PhiButton 'PLAY STARFIELD PHI — the whole circuit' 110 { Run-Tool 'phi-launch-bridge.ps1' 'STARFIELD PHI' }
New-PhiButton 'Xbox Systems — align' 182 { Run-Tool 'phi-xbox-systems.ps1' 'Xbox Systems' }
New-PhiButton 'Vortex — mods seat' 254 {
  $v = Get-StartApps | Where-Object { $_.Name -match 'Vortex' } | Select-Object -First 1
  if ($v) { Start-Process explorer.exe "shell:AppsFolder\$($v.AppID)"; $status.Text = 'Vortex — open.' } else { $status.Text = 'Vortex not found.' }
}
New-PhiButton 'Braid Keeper — Fibonacci anyons' 326 { Run-Tool 'phi-anyons-keeper.ps1' 'Braid Keeper' }
New-PhiButton 'TON 618 CORE — her state phases' 398 { Run-Tool 'phi-ton618-core.ps1' 'TON 618 CORE' }
New-PhiButton 'NVIDIA — G-Assist beside the game' 470 {
  $n = Get-StartApps | Where-Object { $_.Name -match 'NVIDIA' } | Select-Object -First 1
  if ($n) { Start-Process explorer.exe "shell:AppsFolder\$($n.AppID)"; $status.Text = 'NVIDIA — open.' } else { $status.Text = 'NVIDIA App not found.' }
}
[void]$form.ShowDialog()
