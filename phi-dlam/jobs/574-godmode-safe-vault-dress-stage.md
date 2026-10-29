<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 574 - GODMODE SAFE AND VAULT DRESS STAGE (Ground: Job 573 proved the core build, so this job stages the VEIL only godmode safe class and the vault dress actor, no external process, no memory write, no map placement yet, wiring next after this build proves. Every variable carries the p574 prefix.) ==='
$p574h1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_GodmodeSafe.h'
$p574c1 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_GodmodeSafe.cpp'
$p574h2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_WorldDress_Vault.h'
$p574c2 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_WorldDress_Vault.cpp'
$p574backup = 'D:\VEIL-OMNI\Saved\backup574'
$p574log574 = 'D:\VEIL-OMNI\Saved\build574.log'
$p574uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p574buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
New-Item -ItemType Directory -Path $p574backup -Force | Out-Null
if (Test-Path $p574h1) { Copy-Item -Path $p574h1 -Destination (Join-Path $p574backup 'PHI_GodmodeSafe.h') -Force }
if (Test-Path $p574c1) { Copy-Item -Path $p574c1 -Destination (Join-Path $p574backup 'PHI_GodmodeSafe.cpp') -Force }
if (Test-Path $p574h2) { Copy-Item -Path $p574h2 -Destination (Join-Path $p574backup 'PHI_WorldDress_Vault.h') -Force }
if (Test-Path $p574c2) { Copy-Item -Path $p574c2 -Destination (Join-Path $p574backup 'PHI_WorldDress_Vault.cpp') -Force }
Write-Output 'BACKUP574 DONE'
Write-Output 'GODMODE VAULT STAGED NOT WIRED'
$p574h1t = @'
#pragma once
#include "CoreMinimal.h"
#include "PHI_GodmodeSafe.generated.h"
class APawn;
UCLASS()
class VEIL_API UPHI_GodmodeSafe : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="PHI|Godmode")
    static void SetGodmode(APawn* Pawn, bool Enable);
    UFUNCTION(BlueprintCallable, Category="PHI|Godmode")
    static bool IsGodmode(APawn* Pawn);
};
'@
$p574c1t = @'
#include "Systems/PHI_GodmodeSafe.h"
#include "GameFramework/Pawn.h"
void UPHI_GodmodeSafe::SetGodmode(APawn* Pawn, bool Enable)
{
    if (!Pawn) { return; }
    if (!Pawn->IsValidLowLevel()) { return; }
    if (Pawn->IsPendingKillPending()) { return; }
    Pawn->SetCanBeDamaged(!Enable);
}
bool UPHI_GodmodeSafe::IsGodmode(APawn* Pawn)
{
    if (!Pawn) { return false; }
    if (!Pawn->IsValidLowLevel()) { return false; }
    return !Pawn->CanBeDamaged();
}
'@
$p574h2t = @'
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PHI_WorldDress_Vault.generated.h"
UCLASS()
class VEIL_API APHI_WorldDress_Vault : public AActor
{
    GENERATED_BODY()
public:
    APHI_WorldDress_Vault();
    virtual void BeginPlay() override;
};
'@
$p574c2t = @'
#include "Systems/PHI_WorldDress_Vault.h"
APHI_WorldDress_Vault::APHI_WorldDress_Vault() {}
void APHI_WorldDress_Vault::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("PHI VAULT DRESS ModularS pack pool 83 placed 24"));
}
'@
[IO.File]::WriteAllText($p574h1, $p574h1t)
[IO.File]::WriteAllText($p574c1, $p574c1t)
[IO.File]::WriteAllText($p574h2, $p574h2t)
[IO.File]::WriteAllText($p574c2, $p574c2t)
Write-Output 'GODMODE HEADER WRITTEN'
Write-Output 'GODMODE SOURCE WRITTEN'
Write-Output 'VAULT HEADER WRITTEN'
Write-Output 'VAULT SOURCE WRITTEN'
$p574t1 = Get-Content $p574h1 -Raw
$p574t2 = Get-Content $p574c1 -Raw
$p574t3 = Get-Content $p574h2 -Raw
$p574t4 = Get-Content $p574c2 -Raw
$p574open = ([regex]::Matches($p574t1, '\{')).Count + ([regex]::Matches($p574t2, '\{')).Count + ([regex]::Matches($p574t3, '\{')).Count + ([regex]::Matches($p574t4, '\{')).Count
$p574close = ([regex]::Matches($p574t1, '\}')).Count + ([regex]::Matches($p574t2, '\}')).Count + ([regex]::Matches($p574t3, '\}')).Count + ([regex]::Matches($p574t4, '\}')).Count
$p574popen = ([regex]::Matches($p574t1, '\(')).Count + ([regex]::Matches($p574t2, '\(')).Count + ([regex]::Matches($p574t3, '\(')).Count + ([regex]::Matches($p574t4, '\(')).Count
$p574pclose = ([regex]::Matches($p574t1, '\)')).Count + ([regex]::Matches($p574t2, '\)')).Count + ([regex]::Matches($p574t3, '\)')).Count + ([regex]::Matches($p574t4, '\)')).Count
Write-Output ('BRACE OPEN ' + $p574open + ' CLOSE ' + $p574close)
Write-Output ('PAREN OPEN ' + $p574popen + ' CLOSE ' + $p574pclose)
Write-Output ('LINES GODMODE ' + (Get-Content $p574h1).Count + ' ' + (Get-Content $p574c1).Count)
Write-Output ('LINES VAULT ' + (Get-Content $p574h2).Count + ' ' + (Get-Content $p574c2).Count)
if (($p574open -eq $p574close) -and ($p574popen -eq $p574pclose)) {
  & $p574buildbat VEILEditor Win64 Development -Project="$p574uproj" -WaitMutex -NoHotReload *> "$p574log574"
  $p574res = @(Select-String -Path $p574log574 -Pattern 'Result:' | Select-Object -Last 1)
  if ($p574res.Count -gt 0) { Write-Output ('BUILD ' + $p574res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
  $p574errs = @(Select-String -Path $p574log574 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p574e in $p574errs) { Write-Output ('LOGERROR ' + $p574e.Line.Trim()) }
} else {
  if (Test-Path (Join-Path $p574backup 'PHI_GodmodeSafe.h')) { Copy-Item -Path (Join-Path $p574backup 'PHI_GodmodeSafe.h') -Destination $p574h1 -Force }
  if (Test-Path (Join-Path $p574backup 'PHI_GodmodeSafe.cpp')) { Copy-Item -Path (Join-Path $p574backup 'PHI_GodmodeSafe.cpp') -Destination $p574c1 -Force }
  if (Test-Path (Join-Path $p574backup 'PHI_WorldDress_Vault.h')) { Copy-Item -Path (Join-Path $p574backup 'PHI_WorldDress_Vault.h') -Destination $p574h2 -Force }
  if (Test-Path (Join-Path $p574backup 'PHI_WorldDress_Vault.cpp')) { Copy-Item -Path (Join-Path $p574backup 'PHI_WorldDress_Vault.cpp') -Destination $p574c2 -Force }
  Write-Output 'GATE FAIL RESTORED'
}
Write-Output 'PHI P574 VERDICT: GODMODE SAFE AND VAULT DRESS STAGE ABOVE'
Write-Output 'JOB 574 DONE'
```
