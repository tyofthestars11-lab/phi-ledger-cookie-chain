<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SOURCE CENSUS 494 - THE CHARACTER, THE FLOOR, THE TEXTURE READ (Ordered read: the truth lives in the source, not in theory. This job prints the actual VEILCharacter constructor with its capsule size, collision profile and mesh physics flags, the movement settings in source and header, the floor truth from the game own newest log - the floor diag lines the running game already prints - and the texture pool state from the settings file beside a count of the mesh files standing in Content. Nothing is invented and nothing is fixed in this job: it reads and prints, and the fix seats from these prints. It rides behind job 493, which turns the broken Fab plugin off so the builds compile again. Every variable carries the cc494 prefix.) ==='
$cc494proj = 'D:\VEIL-OMNI'
$cc494cc = Join-Path $cc494proj 'Source\VEIL\Private\Character\VEILCharacter.cpp'
$cc494ch = Join-Path $cc494proj 'Source\VEIL\Public\Character\VEILCharacter.h'
$cc494lines = Get-Content $cc494cc
$cc494sig = -1
for ($cc494i = 0; $cc494i -lt $cc494lines.Count; $cc494i++) { if ($cc494lines[$cc494i] -match 'AVEILCharacter::AVEILCharacte[r]') { $cc494sig = $cc494i; break } }
Write-Output ('CTOR at=' + $cc494sig)
if ($cc494sig -ge 0) {
  $cc494depth = 0; $cc494started = $false
  for ($cc494j = $cc494sig; $cc494j -lt $cc494lines.Count; $cc494j++) {
    Write-Output ('CC ' + ($cc494j + 1) + ': ' + $cc494lines[$cc494j])
    $cc494depth += ([regex]::Matches($cc494lines[$cc494j], '\{')).Count - ([regex]::Matches($cc494lines[$cc494j], '\}')).Count
    if ($cc494lines[$cc494j] -match '\{') { $cc494started = $true }
    if ($cc494started -and $cc494depth -eq 0) { break }
  }
}
foreach ($cc494pat in @('MovementMode', 'MaxWalkSpeed', 'SetMovementMode', 'bUseControllerRotationYaw', 'OrientRotationToMovement')) {
  Select-String -Path $cc494cc -Pattern $cc494pat | ForEach-Object { Write-Output ('MOVE ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
  Select-String -Path $cc494ch -Pattern $cc494pat | ForEach-Object { Write-Output ('MOVEH ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
}
$cc494logs = Get-ChildItem (Join-Path $cc494proj 'Saved\Logs') -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending
if ($cc494logs) {
  $cc494log = $cc494logs[0].FullName
  Write-Output ('LOG ' + $cc494log)
  Select-String -Path $cc494log -Pattern 'FLOOR|onGround|DROP2' | Select-Object -Last 12 | ForEach-Object { Write-Output ('LOGF ' + $_.Line.Trim()) }
  Select-String -Path $cc494log -Pattern 'PAD PROOF' | Select-Object -Last 4 | ForEach-Object { Write-Output ('LOGP ' + $_.Line.Trim()) }
  Select-String -Path $cc494log -Pattern 'over budget|TEXTURE STREAMING|PoolSize' | Select-Object -First 8 | ForEach-Object { Write-Output ('LOGM ' + $_.Line.Trim()) }
  Select-String -Path $cc494log -Pattern 'PHI FACTION BODY|PHI WARDEN BODY|MONUMENT' | Select-Object -Last 8 | ForEach-Object { Write-Output ('LOGB ' + $_.Line.Trim()) }
} else { Write-Output 'LOG NONE' }
$cc494ini = Join-Path $cc494proj 'Config\DefaultEngine.ini'
Select-String -Path $cc494ini -Pattern 'PoolSize|ConsoleVariables' | ForEach-Object { Write-Output ('INI ' + $_.LineNumber + ': ' + $_.Line.Trim()) }
$cc494assets = @(Get-ChildItem (Join-Path $cc494proj 'Content') -Recurse -Filter '*.uasset' -ErrorAction SilentlyContinue)
Write-Output ('CONTENT uasset=' + $cc494assets.Count)
foreach ($cc494pack in @('ParagonCountess', 'ParagonMurdock', 'ParagonRevenant', 'ParagonGreystone', 'ParagonMinions')) {
  $cc494n = @(Get-ChildItem (Join-Path $cc494proj ('Content\' + $cc494pack)) -Recurse -Filter '*.uasset' -ErrorAction SilentlyContinue).Count
  Write-Output ('PACK ' + $cc494pack + '=' + $cc494n)
}
Write-Output 'PHI CC494 VERDICT: CENSUS READ ABOVE'
Write-Output 'JOB 494 DONE'
```
