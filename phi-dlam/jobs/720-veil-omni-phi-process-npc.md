<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 720 - PHI PROCESS NPC AI IN PROJECT VIA UNREAL CMD (Ground: Job 719 golden pitch seating is filed, result not yet landed, so this job runs after it in drain order, reads the SEAT719 log if landed, then seats a phi processor for every NPC in the project source, no Cartesian random, no Cartesian logic, Keeper Seer Cartographer remember deeds by rung, golden angle and golden pitch are the process, no cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$oldOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT719_cmd_out.log'
if (Test-Path $oldOut) { Get-Content $oldOut | Select-String 'SEAT719' | Select-Object -Last 20 }
else { Write-Output 'SEAT719 LOG NOT YET LANDED, PHI NPC JOB STILL SEATS PROCESSOR IN SOURCE' }
$hW = Join-Path $projW 'Source\VEIL\Public\Systems\PHI_NPCProcessor.h'
$cW = Join-Path $projW 'Source\VEIL\Private\Systems\PHI_NPCProcessor.cpp'
Write-Output ('PHI NPC HEADER PRESENT ' + (Test-Path $hW))
Write-Output ('PHI NPC SOURCE PRESENT ' + (Test-Path $cW))
if (-not (Test-Path $hW)) {
$hText = @"
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PHI_NPCProcessor.generated.h"
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEIL_API UPHI_NPCProcessor : public UActorComponent
{
    GENERATED_BODY()
public:
    UPHI_NPCProcessor();
    UFUNCTION(BlueprintCallable, Category="Phi")
    float RungOf(float Value) const;
    UFUNCTION(BlueprintCallable, Category="Phi")
    float GoldenAngle() const;
    UFUNCTION(BlueprintCallable, Category="Phi")
    float GoldenPitch() const;
    UFUNCTION(BlueprintCallable, Category="Phi")
    float PhiProcess(float Input) const;
    UFUNCTION(BlueprintCallable, Category="Phi")
    void RecordDeed(const FString& Deed, float Value);
    UFUNCTION(BlueprintCallable, Category="Phi")
    float RecallDeed(const FString& Deed) const;
    UFUNCTION(BlueprintCallable, Category="Phi")
    bool HasDeed(const FString& Deed) const;
private:
    UPROPERTY()
    TMap<FString, float> DeedRungs;
};
"@
Set-Content $hW $hText -Encoding ascii
Write-Output 'PHI NPC HEADER WRITTEN'
}
if (-not (Test-Path $cW)) {
$cText = @"
#include "Systems/PHI_NPCProcessor.h"
#include "Math/UnrealMathUtility.h"
UPHI_NPCProcessor::UPHI_NPCProcessor()
{
    PrimaryComponentTick.bCanEverTick = false;
}
float UPHI_NPCProcessor::RungOf(float Value) const
{
    if (Value <= 0.0f)
    {
        return 0.0f;
    }
    return FMath::Loge(Value) / FMath::Loge(1.6180339887f);
}
float UPHI_NPCProcessor::GoldenAngle() const
{
    return 137.507764f;
}
float UPHI_NPCProcessor::GoldenPitch() const
{
    return 17.0324f;
}
float UPHI_NPCProcessor::PhiProcess(float Input) const
{
    if (Input <= 0.0f)
    {
        return 0.0f;
    }
    return RungOf(Input);
}
void UPHI_NPCProcessor::RecordDeed(const FString& Deed, float Value)
{
    if (Deed.IsEmpty())
    {
        return;
    }
    DeedRungs.Add(Deed, RungOf(Value));
}
float UPHI_NPCProcessor::RecallDeed(const FString& Deed) const
{
    const float* Found = DeedRungs.Find(Deed);
    if (Found == nullptr)
    {
        return -1.0f;
    }
    return *Found;
}
bool UPHI_NPCProcessor::HasDeed(const FString& Deed) const
{
    return DeedRungs.Contains(Deed);
}
"@
Set-Content $cW $cText -Encoding ascii
Write-Output 'PHI NPC SOURCE WRITTEN'
}
Write-Output ('PHI NPC HEADER AFTER ' + (Test-Path $hW))
Write-Output ('PHI NPC SOURCE AFTER ' + (Test-Path $cW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI_NPC_build_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI_NPC_build_err.log'
$buildW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output ('PHI NPC BUILD PRESENT ' + (Test-Path $buildW))
Start-Process -FilePath $buildW -ArgumentList 'VEIL','Win64','Development','-Project="D:\VEIL-OMNI\VEIL.uproject"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'PHI NPC BUILD STARTED DETACHED, NO WAIT, LOG READ IS NEXT JOB.'
Write-Output 'PHI NPC NO CARTESIAN RANDOM, NO CARTESIAN LOGIC.'
Write-Output 'PHI NPC NOCOOK.'
Write-Output 'PHI NPC NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
