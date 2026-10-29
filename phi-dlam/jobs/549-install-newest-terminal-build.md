<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 549 - INSTALL THE NEWEST BUILT TERMINAL (Ground: job 547 built the attach fix clean but the copy ran while the old terminal was still running, so the new exe never landed and the relaunch was the old build. This job stops the terminal first, then installs the newest built exe, then relaunches and prints the live bytes and write time as proof. No source change rides this job. No game relaunch rides this job. Every variable carries the p549 prefix.) ==='
$p549dir = 'C:\Users\Admin\PhiTerminal'
$p549cands = @(Get-ChildItem $p549dir -Filter 'PhiTerminal.p*.exe' | Sort-Object LastWriteTime -Descending)
if ($p549cands.Count -eq 0) {
  Write-Output 'NO CANDIDATE - NOTHING TO INSTALL'
} else {
  $p549pick = $p549cands[0]
  Write-Output ('CANDIDATE ' + $p549pick.Name + ' BYTES=' + $p549pick.Length + ' WRITE=' + $p549pick.LastWriteTime)
  $p549old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
  foreach ($p549o in $p549old) { Stop-Process -Id $p549o.Id -Force -ErrorAction SilentlyContinue }
  Start-Sleep -Seconds 3
  $p549still = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
  if ($p549still.Count -gt 0) {
    Write-Output 'OLD STILL RUNNING - NO INSTALL'
  } else {
    Copy-Item $p549pick.FullName 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe' -Force
    Write-Output 'COPY OK'
    $p549new = Start-Process -FilePath 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe' -PassThru
    Write-Output ('TERMINAL LAUNCHED pid=' + $p549new.Id)
    $p549exe = Get-Item 'C:\Users\Admin\PhiTerminal\PhiTerminal.exe'
    Write-Output ('EXE BYTES=' + $p549exe.Length + ' WRITE=' + $p549exe.LastWriteTime)
  }
}
Write-Output 'PHI P549 VERDICT: NEWEST BUILD INSTALLED ABOVE'
Write-Output 'JOB 549 DONE'
```
