<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 570 - SAFE CPP CRASHFIX AND GAMESTATE STAGE (Ground: The post-reads safe C++ arrived after jobs 558 559 560, and its crash guard answers the named address-zero fault at Tick 394, so this job stages only the crash guard and the fixed game state in the correct folders with the include retargeted to the fixed class, no missing-class ini, no summary write outside the project, backup first, brace balance, then build. GodmodeSafe and Vault actor stage next after this build proves the core. Every variable carries the p570 prefix.) ==='
$p570h1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_CrashFix_AddressZero.h'
$p570c1 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_CrashFix_AddressZero.cpp'
$p570h2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\PHI_GameState_Fixed.h'
$p570c2 = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\PHI_GameState_Fixed.cpp'
$p570backup = 'D:\VEIL-OMNI\Saved\backup570'
New-Item -ItemType Directory -Path $p570backup -Force | Out-Null
if (Test-Path $p570h1) { Copy-Item -Path $p570h1 -Destination (Join-Path $p570backup 'PHI_CrashFix_AddressZero.h') -Force; Write-Output 'BACKUP HEADER 1 DONE' }
if (Test-Path $p570c1) { Copy-Item -Path $p570c1 -Destination (Join-Path $p570backup 'PHI_CrashFix_AddressZero.cpp') -Force; Write-Output 'BACKUP SOURCE 1 DONE' }
if (Test-Path $p570h2) { Copy-Item -Path $p570h2 -Destination (Join-Path $p570backup 'PHI_GameState_Fixed.h') -Force; Write-Output 'BACKUP HEADER 2 DONE' }
if (Test-Path $p570c2) { Copy-Item -Path $p570c2 -Destination (Join-Path $p570backup 'PHI_GameState_Fixed.cpp') -Force; Write-Output 'BACKUP SOURCE 2 DONE' }
Write-Output 'INI SKIPPED MISSING CLASSES'
Write-Output 'GODMODE VAULT STAGE NEXT'
$p570h1t = @'
#pragma once
#include "CoreMinimal.h"
#include "PHI_CrashFix_AddressZero.generated.h"
UCLASS()
class VEIL_API UPHI_CrashFix_AddressZero : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="PHI|Crash")
    static bool IsValidPawnForGodmode(APawn* Pawn);
    UFUNCTION(BlueprintCallable, Category="PHI|Crash")
    static bool IsValidWorldForProgression(UWorld* World);
    UFUNCTION(BlueprintCallable, Category="PHI|Crash")
    static void GuardedAdvanceProgression(UObject* WorldContext, int32 Stage, float Percent);
};
'@
$p570c1t = @'
#include "Systems/PHI_CrashFix_AddressZero.h"
#include "Game/PHI_GameState_Fixed.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
bool UPHI_CrashFix_AddressZero::IsValidPawnForGodmode(APawn* Pawn)
{
    if (!Pawn) { return false; }
    if (!Pawn->IsValidLowLevel()) { return false; }
    if (Pawn->IsPendingKillPending()) { return false; }
    AController* Ctrl = Pawn->GetController();
    if (!Ctrl) { return false; }
    if (!Ctrl->IsValidLowLevel()) { return false; }
    if (ACharacter* Char = Cast<ACharacter>(Pawn))
    {
        UCharacterMovementComponent* Move = Char->GetCharacterMovement();
        if (!Move) { return false; }
        if (!Move->IsValidLowLevel()) { return false; }
    }
    return true;
}
bool UPHI_CrashFix_AddressZero::IsValidWorldForProgression(UWorld* World)
{
    if (!World) { return false; }
    if (!World->IsValidLowLevel()) { return false; }
    if (World->IsPendingKillPending()) { return false; }
    if (!World->GetGameState()) { return false; }
    return true;
}
void UPHI_CrashFix_AddressZero::GuardedAdvanceProgression(UObject* WorldContext, int32 Stage, float Percent)
{
    if (!WorldContext) { return; }
    if (!WorldContext->IsValidLowLevel()) { return; }
    UWorld* World = WorldContext->GetWorld();
    if (!IsValidWorldForProgression(World)) { return; }
    AGameStateBase* GS = UGameplayStatics::GetGameState(WorldContext);
    if (!GS) { return; }
    if (!GS->IsValidLowLevel()) { return; }
    if (APHI_GameState_Fixed* PHI = Cast<APHI_GameState_Fixed>(GS))
    {
        if (!PHI->IsValidLowLevel()) { return; }
        PHI->AdvanceProgression(Stage, Percent);
    }
}
'@
$p570h2t = @'
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PHI_GameState_Fixed.generated.h"
UCLASS()
class VEIL_API APHI_GameState_Fixed : public AGameStateBase
{
    GENERATED_BODY()
public:
    APHI_GameState_Fixed();
    UPROPERTY(BlueprintReadOnly)
    float ProgressionPercent;
    UPROPERTY(BlueprintReadOnly)
    int32 CurrentStage;
    UFUNCTION(BlueprintCallable)
    void AdvanceProgression(int32 Stage, float Percent);
    UFUNCTION(BlueprintCallable)
    void AddGameplayNeed(FString Need);
};
'@
$p570c2t = @'
#include "Game/PHI_GameState_Fixed.h"
APHI_GameState_Fixed::APHI_GameState_Fixed() : ProgressionPercent(0.f), CurrentStage(0) {}
void APHI_GameState_Fixed::AdvanceProgression(int32 Stage, float Percent)
{
    if (!IsValidLowLevel()) { return; }
    if (IsPendingKillPending()) { return; }
    if (Stage < CurrentStage) { return; }
    CurrentStage = Stage;
    ProgressionPercent = FMath::Clamp(Percent, 0.f, 100.f);
    UE_LOG(LogTemp, Log, TEXT("PHI Progress %d -> %.0f%%"), Stage, ProgressionPercent);
    if (GEngine)
    {
        if (GEngine->GetCurrentPlayWorld())
        {
            GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Emerald, FString::Printf(TEXT("PHI %.0f%%"), ProgressionPercent));
        }
    }
}
void APHI_GameState_Fixed::AddGameplayNeed(FString Need)
{
    if (!IsValidLowLevel()) { return; }
    UE_LOG(LogTemp, Log, TEXT("PHI Gameplay Need: %s - interact climb push"), *Need);
}
'@
[IO.File]::WriteAllText($p570h1, $p570h1t)
[IO.File]::WriteAllText($p570c1, $p570c1t)
[IO.File]::WriteAllText($p570h2, $p570h2t)
[IO.File]::WriteAllText($p570c2, $p570c2t)
Write-Output 'CRASHFIX HEADER WRITTEN'
Write-Output 'CRASHFIX SOURCE WRITTEN'
Write-Output 'GAMESTATE HEADER WRITTEN'
Write-Output 'GAMESTATE SOURCE WRITTEN'
$p570t1 = Get-Content $p570h1 -Raw
$p570t2 = Get-Content $p570c1 -Raw
$p570t3 = Get-Content $p570h2 -Raw
$p570t4 = Get-Content $p570c2 -Raw
$p570open = ([regex]::Matches($p570t1, '\{')).Count + ([regex]::Matches($p570t2, '\{')).Count + ([regex]::Matches($p570t3, '\{')).Count + ([regex]::Matches($p570t4, '\{')).Count
$p570close = ([regex]::Matches($p570t1, '\}')).Count + ([regex]::Matches($p570t2, '\}')).Count + ([regex]::Matches($p570t3, '\}')).Count + ([regex]::Matches($p570t4, '\}')).Count
Write-Output ('BRACE OPEN ' + $p570open + ' CLOSE ' + $p570close)
$p570uproj = 'D:\VEIL-OMNI\VEIL.uproject'
if ($p570open -eq $p570close) {
  $p570buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p570log = 'D:\VEIL-OMNI\Saved\build570.log'
  & $p570buildbat VEILEditor Win64 Development -Project="$p570uproj" -WaitMutex -NoHotReload *> "$p570log"
  $p570res = @(Select-String -Path $p570log -Pattern 'Result:' | Select-Object -Last 1)
  if ($p570res.Count -gt 0) { Write-Output ('BUILD ' + $p570res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
} else {
  if (Test-Path (Join-Path $p570backup 'PHI_CrashFix_AddressZero.h')) { Copy-Item -Path (Join-Path $p570backup 'PHI_CrashFix_AddressZero.h') -Destination $p570h1 -Force }
  if (Test-Path (Join-Path $p570backup 'PHI_CrashFix_AddressZero.cpp')) { Copy-Item -Path (Join-Path $p570backup 'PHI_CrashFix_AddressZero.cpp') -Destination $p570c1 -Force }
  if (Test-Path (Join-Path $p570backup 'PHI_GameState_Fixed.h')) { Copy-Item -Path (Join-Path $p570backup 'PHI_GameState_Fixed.h') -Destination $p570h2 -Force }
  if (Test-Path (Join-Path $p570backup 'PHI_GameState_Fixed.cpp')) { Copy-Item -Path (Join-Path $p570backup 'PHI_GameState_Fixed.cpp') -Destination $p570c2 -Force }
  Write-Output 'GATE FAIL BRACE RESTORED BUILD SKIPPED'
}
Write-Output 'PHI P570 VERDICT: SAFE CPP CRASHFIX AND GAMESTATE STAGE ABOVE'
Write-Output 'JOB 570 DONE'
```
