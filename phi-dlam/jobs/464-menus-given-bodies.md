<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MENUS GIVEN BODIES 464 - A DIM WORLD, GOLD BUTTONS, AND A TITLE GUARD (Ground read whole from job 459: both menus build honestly in code, titles and buttons and bindings all present, but nothing gives them a body: no backdrop behind the box, and the buttons carry the engine default style, which is near invisible, so when Start pauses the world the menu floats as faint text on a frozen frame and reads exactly as Tyree named it, a freeze. The boot region also confirms the stacking fault: the main menu widget stands on the player controller from BeginPlay and TogglePauseMenu carries no guard, so Start at the title stacks a pause over the title. This job gives the menus bodies in three count gated edits, each file backed up first. One, in VEILGameMode cpp, TogglePauseMenu returns at once while the main menu widget stands, so the title is the title and Start there pauses nothing. Two, in both menu cpps, a Border include lands, a dim backdrop border at 72 percent black fills the canvas behind the box, and every button takes a dark gold background so the menu reads as a menu from across the room. Three, the counts verify and the build runs the standing way with its Result line riding the verdict. With job 458 focus seat already landed, the pause now opens visible, on Resume, over a dimmed world. If a gate misses, SKIP prints and nothing builds. Every variable carries the mb464 prefix.) ==='
$mb464gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$mb464pause = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILPauseMenu.cpp'
$mb464main = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILMainMenu.cpp'
$mb464ok = $true
$mb464gl = @(Get-Content $mb464gm)
$mb464sig = @(); for ($mb464i = 0; $mb464i -lt $mb464gl.Count; $mb464i++) { if ($mb464gl[$mb464i] -match 'void AVEILPlayerController::TogglePauseMenu\(\)') { $mb464sig += $mb464i } }
Write-Output ('GM SIG=' + $mb464sig.Count); if ($mb464sig.Count -ne 1) { $mb464ok = $false }
function MenuBody464($mb464path) {
  $mb464L = @(Get-Content $mb464path)
  $mb464inc = @($mb464L | Where-Object { $_ -match '#include "Components/Button.h"' }).Count
  $mb464root = @($mb464L | Where-Object { $_ -match 'RootWidget = Canvas;' }).Count
  $mb464btn = @($mb464L | Where-Object { $_ -match 'ConstructWidget<UButton>' }).Count
  Write-Output ((Split-Path $mb464path -Leaf) + ' inc=' + $mb464inc + ' root=' + $mb464root + ' btn=' + $mb464btn)
  return (($mb464inc -eq 1) -and ($mb464root -eq 1) -and ($mb464btn -eq 1))
}
if (-not (MenuBody464 $mb464pause)) { $mb464ok = $false }
if (-not (MenuBody464 $mb464main)) { $mb464ok = $false }
if (-not $mb464ok) { Write-Output 'PHI MB464 VERDICT: MENUS BODIES SKIP gates closed'; Write-Output 'JOB 464 DONE'; return }
Copy-Item $mb464gm ($mb464gm + '.phi-backup-464') -Force
Copy-Item $mb464pause ($mb464pause + '.phi-backup-464') -Force
Copy-Item $mb464main ($mb464main + '.phi-backup-464') -Force
$mb464newG = @()
for ($mb464a = 0; $mb464a -lt $mb464gl.Count; $mb464a++) {
  $mb464newG += $mb464gl[$mb464a]
  if ($mb464a -eq $mb464sig[0] + 1) { $mb464newG += "`t// Title stands: while the main menu is up, Start summons nothing."; $mb464newG += "`tif (MainMenuWidget) { return; }" }
}
Set-Content -Path $mb464gm -Value $mb464newG
function ApplyBody464($mb464path) {
  $mb464L = @(Get-Content $mb464path)
  $mb464dim = @(
  "`tUBorder* Dim = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT(""Dim""));",
  "`tDim->SetBrushColor(FLinearColor(0.f, 0.f, 0.f, 0.72f));",
  "`tUCanvasPanelSlot* DimSlot = Canvas->AddChildToCanvas(Dim);",
  "`tDimSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));",
  "`tDimSlot->SetOffsets(FMargin(0.f));"
  )
  $mb464out = @()
  foreach ($mb464line in $mb464L) {
    $mb464out += $mb464line
    if ($mb464line -match '#include "Components/Button.h"') { $mb464out += '#include "Components/Border.h"' }
    if ($mb464line -match 'RootWidget = Canvas;') { foreach ($mb464d in $mb464dim) { $mb464out += $mb464d } }
    if ($mb464line -match 'ConstructWidget<UButton>') { $mb464out += "`t`tButton->SetBackgroundColor(FLinearColor(0.13f, 0.10f, 0.02f, 0.95f));" }
  }
  Set-Content -Path $mb464path -Value $mb464out
}
ApplyBody464 $mb464pause
ApplyBody464 $mb464main
$mb464v1 = ([regex]::Matches((Get-Content $mb464gm -Raw), 'MainMenuWidget\) \{ return; \}')).Count
$mb464v2 = ([regex]::Matches((Get-Content $mb464pause -Raw), 'SetBrushColo[r]')).Count
$mb464v3 = ([regex]::Matches((Get-Content $mb464main -Raw), 'SetBrushColo[r]')).Count
$mb464v4 = ([regex]::Matches((Get-Content $mb464pause -Raw), 'SetBackgroundColo[r]')).Count
$mb464v5 = ([regex]::Matches((Get-Content $mb464main -Raw), 'SetBackgroundColo[r]')).Count
Write-Output ('VERIFY guard=' + $mb464v1 + ' dimPause=' + $mb464v2 + ' dimMain=' + $mb464v3 + ' tintPause=' + $mb464v4 + ' tintMain=' + $mb464v5)
$mb464buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$mb464uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$mb464log = 'D:\VEIL-OMNI\Saved\build464.log'
& $mb464buildbat VEILEditor Win64 Development -Project="$mb464uproj" -WaitMutex -NoHotReload *> "$mb464log"
$mb464result = @(Select-String -Path $mb464log -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
foreach ($mb464r in $mb464result) { Write-Output ('BUILD ' + $mb464r.Line.Trim()) }
Write-Output ('PHI MB464 VERDICT: MENUS BODIES guard=' + $mb464v1 + ' dims=' + ($mb464v2 + $mb464v3) + ' tints=' + ($mb464v4 + $mb464v5))
Write-Output 'JOB 464 DONE'
```
