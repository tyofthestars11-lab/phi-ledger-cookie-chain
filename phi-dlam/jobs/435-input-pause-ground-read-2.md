<!-- PHI-DIRECT -->
```powershell
Write-Output '=== INPUT PAUSE GROUND READ 2 435 - THE ENHANCED INPUT ASSETS AND THE PAUSE FUNCTION READ AT THEIR OWN LINES (Ground read whole from job 432: the character binds Enhanced Input actions, Move, Look, Jump, Sprint, Dodge, Aim, Fire, Interact, each guarded by a null check, and adds a mapping context at BeginPlay; the legacy DefaultInput mappings count is zero, which Enhanced Input does not use, so the open question stands at the assets themselves: whether the InputAction and InputMappingContext assets stand in Content and whether the character properties carry them. Ground from job 431: the Start press lands on TogglePauseMenu, bound at VEILGameMode cpp line 223 to Gamepad_Special_Right, and the pause body at lines 228 to 245 creates the widget and flips the input mode; no SetGamePaused line stands anywhere in the pause print. One, the job prints the VEILCharacter header lines that name InputAction or MappingContext properties, capped at 40. Two, it prints VEILCharacter cpp lines 137 to 200 and 355 to 385 whole, the BeginPlay and mapping context ground and the possession ground. Three, it prints VEILGameMode cpp lines 180 to 250 whole: the player controller BeginPlay, its input setup, and the TogglePauseMenu body entire. Four, it prints VEILPauseMenu cpp whole, capped at 140 lines. Five, it censuses the Content tree for input assets: every uasset whose name carries IA or IMC or Input, with name and size, capped at 60. Six, the verdict in one line: INPUT PAUSE GROUND 2 with the property count and the asset count. This job is read only and every variable carries the ip435 prefix.) ==='
$ip435root = 'D:\VEIL-OMNI'
$ip435src = Join-Path $ip435root 'Source\VEIL'
if (-not (Test-Path $ip435src)) { Write-Output 'INPUT PAUSE GROUND HELD stage=source-missing'; Write-Output 'JOB 435 DONE'; exit 0 }
$ip435charH = Get-ChildItem -Path $ip435src -Recurse -Filter 'VEILCharacter.h' | Select-Object -First 1
$ip435props = @()
if ($ip435charH) { $ip435props = @(Select-String -Path $ip435charH.FullName -Pattern 'InputAction|MappingContext' -ErrorAction SilentlyContinue); $ip435props | Select-Object -First 40 | ForEach-Object { Write-Output ('PROP ' + $_.LineNumber + ': ' + $_.Line.Trim()) } }
Write-Output ('PROP LINES=' + $ip435props.Count)
$ip435charC = Get-ChildItem -Path $ip435src -Recurse -Filter 'VEILCharacter.cpp' | Select-Object -First 1
if ($ip435charC) { $ip435cl = Get-Content $ip435charC.FullName; Write-Output '--- CHARACTER 137-200 ---'; for ($ip435i = 136; $ip435i -lt 200 -and $ip435i -lt $ip435cl.Count; $ip435i++) { Write-Output ('CC ' + ($ip435i + 1) + ': ' + $ip435cl[$ip435i]) }; Write-Output '--- CHARACTER 355-385 ---'; for ($ip435j = 354; $ip435j -lt 385 -and $ip435j -lt $ip435cl.Count; $ip435j++) { Write-Output ('CC ' + ($ip435j + 1) + ': ' + $ip435cl[$ip435j]) } }
$ip435gm = Get-ChildItem -Path $ip435src -Recurse -Filter 'VEILGameMode.cpp' | Select-Object -First 1
if ($ip435gm) { $ip435gl = Get-Content $ip435gm.FullName; Write-Output '--- GAMEMODE 180-250 ---'; for ($ip435k = 179; $ip435k -lt 250 -and $ip435k -lt $ip435gl.Count; $ip435k++) { Write-Output ('GM ' + ($ip435k + 1) + ': ' + $ip435gl[$ip435k]) } }
$ip435pm = Get-ChildItem -Path $ip435src -Recurse -Filter 'VEILPauseMenu.cpp' | Select-Object -First 1
if ($ip435pm) { $ip435pl = Get-Content $ip435pm.FullName; Write-Output ('--- PAUSE MENU CPP lines=' + $ip435pl.Count + ' ---'); $ip435pl | Select-Object -First 140 | ForEach-Object { Write-Output ('PM ' + $_) } }
$ip435content = Join-Path $ip435root 'Content'
$ip435assets = @(Get-ChildItem -Path $ip435content -Recurse -Include *.uasset -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'IA_|IMC_|Input' })
Write-Output ('INPUT ASSETS=' + $ip435assets.Count)
$ip435assets | Select-Object -First 60 | ForEach-Object { Write-Output ('ASSET ' + $_.Name + ' bytes=' + $_.Length + ' dir=' + $_.Directory.Name) }
Write-Output ('PHI IP435 VERDICT: INPUT PAUSE GROUND 2 props=' + $ip435props.Count + ' assets=' + $ip435assets.Count)
Write-Output 'JOB 435 DONE'
```
