<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 667 - STOP POPPING WINDOW SILENT DRAIN (Ground: Tyree word popping window super fast random yet not fixed told earlier. This job makes the drain task windowless so no blank window flashes, by switching its action to a windowless launcher and setting its hidden flag with the correct namespace. If the switch fails, the backed up task is restored and the job prints that plainly. No map, no icon, no cook, no game file touched.) ==='
$p667backup = 'D:\VEIL-OMNI\Saved\backup-drain667.xml'
$p667vbs = 'D:\VEIL-OMNI\Saved\hidden-drain667.vbs'
$p667new = 'D:\VEIL-OMNI\Saved\drain667-windowless.xml'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /xml > $p667backup 2>&1
Write-Output 'DRAIN667 BACKUP DONE'
schtasks /query /fo list /v 2>&1 | Select-String -Pattern 'TaskName|Task To Run|Next Run Time|Status' | ForEach-Object { Write-Output ('TASK667 ' + $_.Line.Trim()) }
$v667lines = @(
'Set shell = CreateObject("WScript.Shell")',
'shell.Run "powershell -WindowStyle Hidden -NoProfile -ExecutionPolicy Bypass -File C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1", 0, False'
)
$v667lines | Set-Content -Path $p667vbs -Encoding ASCII
Write-Output 'DRAIN667 VBS WRITTEN'
try {
  $x667 = [xml](Get-Content $p667backup)
  $ns667 = $x667.DocumentElement.NamespaceURI
  $cmd667 = $x667.Task.Actions.Exec.Command
  $arg667 = $x667.Task.Actions.Exec.Arguments
  Write-Output ('DRAIN667 OLD COMMAND ' + $cmd667)
  Write-Output ('DRAIN667 OLD ARGS ' + $arg667)
  $x667.Task.Actions.Exec.Command = 'wscript.exe'
  $x667.Task.Actions.Exec.Arguments = '//B //Nologo "' + $p667vbs + '"'
  $set667 = $x667.Task.Settings
  if ($set667.Hidden) { $set667.Hidden = 'true' } else { $hid667 = $x667.CreateElement('Hidden', $ns667); $hid667.InnerText = 'true'; $set667.AppendChild($hid667) | Out-Null }
  $x667.Save($p667new)
  Write-Output 'DRAIN667 NEW XML SAVED'
  schtasks /create /tn 'PHI-DLAM-HiddenDrain' /xml $p667new /f 2>&1
  Write-Output 'DRAIN667 CREATE ATTEMPT DONE'
} catch { Write-Output ('DRAIN667 SWITCH FAILED ' + $_.Exception.Message) }
Write-Output 'DRAIN667 STATUS AFTER'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /xml 2>&1 | Select-String -Pattern 'Command|Arguments|Hidden' | ForEach-Object { Write-Output ('DRAIN667 AFTER ' + $_.Line.Trim()) }
Write-Output 'JOB 667 DONE'
```
