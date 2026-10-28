<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 525 - THE DRESSING RUNS (Ground: job 522 staged the dressing script and its folded session outlasted the launch window, so the dressing never ran - its page is missing and the district save still stands at the rig hour. The script itself stands written on disk in the project saved folder. This job launches it through the editor command hand, detached, then polls inside itself for the dressing page to appear - the page is the proof, written by the script own hand with the true asset count, the folder census, and every placed mesh. If the page lands inside the bound, the job prints it whole in this same run. If the editor command process still works when the bound ends, the job prints that state instead. Every variable carries the p525 prefix.) ==='
$p525py = 'D:\VEIL-OMNI\Saved\dress522.py'
Write-Output ('SCRIPT EXISTS=' + (Test-Path $p525py))
$p525wait = 0
while ((Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue) -and $p525wait -lt 12) { Start-Sleep -Seconds 10; $p525wait = $p525wait + 1 }
Write-Output ('LOCK WAIT LOOPS=' + $p525wait)
$p525cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p525proc = Start-Process -FilePath $p525cmd -ArgumentList @('"D:\VEIL-OMNI\VEIL.uproject"', '-run=pythonscript', ('-script="' + $p525py + '"'), '-unattended', '-nopause', '-nosplash') -PassThru
Write-Output ('DRESS LAUNCHED pid=' + $p525proc.Id)
$p525page = 'D:\VEIL-OMNI\dress522.txt'
$p525poll = 0
while (-not (Test-Path $p525page) -and $p525poll -lt 13) { Start-Sleep -Seconds 10; $p525poll = $p525poll + 1 }
Write-Output ('PAGE POLLS=' + $p525poll + ' cmdExited=' + $p525proc.HasExited)
if (Test-Path $p525page) {
  Get-Content $p525page | ForEach-Object { Write-Output ('DRESS ' + $_) }
  Write-Output 'PHI P525 VERDICT: DRESSING LANDED AND PRINTED'
} else {
  Write-Output 'PHI P525 VERDICT: DRESSING STILL RUNNING AT BOUND'
}
Write-Output 'JOB 525 DONE'
```
