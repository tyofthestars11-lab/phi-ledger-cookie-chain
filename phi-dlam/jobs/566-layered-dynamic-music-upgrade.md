<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 566 - LAYERED DYNAMIC MUSIC UPGRADE (Ground: Tyree refined the music order to dynamic award-caliber music like games and movies that win awards, so this job upgrades the 563 manager from single-stem switching to layered stems playing together with smooth volume crossfades, region motifs, and a Warden duel mix, censuses the audio plugins and the existing progression tracking, and builds with gates first. Voice clips stay untouched. Every variable carries the p566 prefix.) ==='
$p566uproj = 'D:\VEIL-OMNI\VEIL.uproject'
if (Test-Path $p566uproj) {
  $p566json = Get-Content $p566uproj -Raw | ConvertFrom-Json
  foreach ($p566pl in $p566json.Plugins) { Write-Output ('PLUGIN ' + $p566pl.Name) }
} else { Write-Output 'NO UPROJECT FOUND' }
$p566srcroot = 'D:\VEIL-OMNI\Source\VEIL'
if (Test-Path $p566srcroot) {
  $p566prog = @(Get-ChildItem -Path $p566srcroot -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*GameState*' -or $_.Name -like '*Quest*' })
  foreach ($p566pf in $p566prog) { Write-Output ('PROGRESSION FILE ' + $p566pf.FullName) }
  foreach ($p566pf in $p566prog) {
    @(Select-String -Path $p566pf.FullName -Pattern 'Stage' | Select-Object -First 20) | ForEach-Object { Write-Output ('STAGE LINE ' + $_.Line.Trim()) }
  }
} else { Write-Output 'NO SOURCE FOLDER FOUND' }
$p566hpath = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_DynamicMusic.h'
$p566cpppath = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_DynamicMusic.cpp'
$p566backup = 'D:\VEIL-OMNI\Saved\backup566'
New-Item -ItemType Directory -Path $p566backup -Force | Out-Null
if (Test-Path $p566hpath) { Copy-Item -Path $p566hpath -Destination (Join-Path $p566backup 'PHI_DynamicMusic.h') -Force; Write-Output 'BACKUP HEADER DONE' }
if (Test-Path $p566cpppath) { Copy-Item -Path $p566cpppath -Destination (Join-Path $p566backup 'PHI_DynamicMusic.cpp') -Force; Write-Output 'BACKUP SOURCE DONE' }
$p566h = @'
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PHI_DynamicMusic.generated.h"
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VEIL_API UPHI_DynamicMusicComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPHI_DynamicMusicComponent();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    class USoundWave* ExploreStem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    class USoundWave* TensionStem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    class USoundWave* CombatStem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    class USoundWave* DiscoveryStem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    class USoundWave* TriumphStem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    int32 MusicState;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PHI|Music")
    int32 Region;
    UFUNCTION(BlueprintCallable, Category="PHI|Music")
    void SetMusicState(int32 NewState);
    UFUNCTION(BlueprintCallable, Category="PHI|Music")
    void SetRegion(int32 NewRegion);
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
    virtual void BeginPlay() override;
private:
    TArray<class UAudioComponent*> LayerAudios;
    TArray<float> TargetVolumes;
    TArray<float> CurrentVolumes;
    float CrossfadeRate;
    void UpdateTargets();
    void PlayAllStems();
};
'@
$p566cpp = @'
#include "Systems/PHI_DynamicMusic.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
UPHI_DynamicMusicComponent::UPHI_DynamicMusicComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    MusicState = 0;
    Region = 0;
    CrossfadeRate = 0.5f;
    ExploreStem = nullptr;
    TensionStem = nullptr;
    CombatStem = nullptr;
    DiscoveryStem = nullptr;
    TriumphStem = nullptr;
}
void UPHI_DynamicMusicComponent::BeginPlay()
{
    Super::BeginPlay();
    PlayAllStems();
    UpdateTargets();
}
void UPHI_DynamicMusicComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    for (int32 i = 0; i < LayerAudios.Num(); i++)
    {
        if (LayerAudios[i] == nullptr) { continue; }
        if (i >= CurrentVolumes.Num() || i >= TargetVolumes.Num()) { continue; }
        float diff = TargetVolumes[i] - CurrentVolumes[i];
        float step = CrossfadeRate * DeltaTime;
        if (diff > step) { CurrentVolumes[i] += step; }
        else if (diff < -step) { CurrentVolumes[i] -= step; }
        else { CurrentVolumes[i] = TargetVolumes[i]; }
        LayerAudios[i]->SetVolumeMultiplier(CurrentVolumes[i]);
    }
}
void UPHI_DynamicMusicComponent::SetMusicState(int32 NewState)
{
    MusicState = NewState;
    UpdateTargets();
}
void UPHI_DynamicMusicComponent::SetRegion(int32 NewRegion)
{
    Region = NewRegion;
    UpdateTargets();
}
void UPHI_DynamicMusicComponent::UpdateTargets()
{
    TargetVolumes.Empty();
    TargetVolumes.Add(0.0f);
    TargetVolumes.Add(0.0f);
    TargetVolumes.Add(0.0f);
    TargetVolumes.Add(0.0f);
    TargetVolumes.Add(0.0f);
    if (MusicState == 0) { TargetVolumes[0] = 1.0f; }
    else if (MusicState == 1) { TargetVolumes[1] = 1.0f; TargetVolumes[0] = 0.3f; }
    else if (MusicState == 2) { TargetVolumes[2] = 1.0f; TargetVolumes[1] = 0.5f; }
    else if (MusicState == 3) { TargetVolumes[3] = 1.0f; TargetVolumes[0] = 0.4f; }
    else if (MusicState == 4) { TargetVolumes[4] = 1.0f; TargetVolumes[0] = 0.3f; }
    else if (MusicState == 5) { TargetVolumes[2] = 1.0f; TargetVolumes[4] = 0.6f; TargetVolumes[1] = 0.5f; }
    if (Region == 0) { if (TargetVolumes[0] < 0.6f) { TargetVolumes[0] = 0.6f; } }
    else if (Region == 1) { if (TargetVolumes[3] < 0.6f) { TargetVolumes[3] = 0.6f; } }
    else if (Region == 2) { if (TargetVolumes[1] < 0.6f) { TargetVolumes[1] = 0.6f; } }
    else if (Region == 3) { if (TargetVolumes[3] < 0.6f) { TargetVolumes[3] = 0.6f; } }
    else if (Region == 4) { if (TargetVolumes[1] < 0.6f) { TargetVolumes[1] = 0.6f; } }
    else if (Region == 5) { if (TargetVolumes[4] < 0.6f) { TargetVolumes[4] = 0.6f; } }
}
void UPHI_DynamicMusicComponent::PlayAllStems()
{
    LayerAudios.Empty();
    CurrentVolumes.Empty();
    USoundWave* stems[5] = { ExploreStem, TensionStem, CombatStem, DiscoveryStem, TriumphStem };
    for (int32 i = 0; i < 5; i++)
    {
        if (stems[i] == nullptr) { LayerAudios.Add(nullptr); CurrentVolumes.Add(0.0f); continue; }
        UAudioComponent* comp = UGameplayStatics::SpawnSound2D(GetWorld(), stems[i]);
        if (comp != nullptr) { comp->SetVolumeMultiplier(0.0f); }
        LayerAudios.Add(comp);
        CurrentVolumes.Add(0.0f);
    }
}
'@
[IO.File]::WriteAllText($p566hpath, $p566h)
[IO.File]::WriteAllText($p566cpppath, $p566cpp)
Write-Output 'MANAGER HEADER WRITTEN'
Write-Output 'MANAGER SOURCE WRITTEN'
$p566htext = Get-Content $p566hpath -Raw
$p566ctext = Get-Content $p566cpppath -Raw
$p566open = ([regex]::Matches($p566ctext, '\{')).Count + ([regex]::Matches($p566htext, '\{')).Count
$p566close = ([regex]::Matches($p566ctext, '\}')).Count + ([regex]::Matches($p566htext, '\}')).Count
Write-Output ('BRACE OPEN ' + $p566open + ' CLOSE ' + $p566close)
Write-Output 'LAYER TABLE Explore Tension Combat Discovery Triumph'
Write-Output 'LAYER STATE 0 Explore full, others silent'
Write-Output 'LAYER STATE 1 Tension full, Explore low'
Write-Output 'LAYER STATE 2 Combat full, Tension half'
Write-Output 'LAYER STATE 3 Discovery full, Explore low'
Write-Output 'LAYER STATE 4 Triumph full, Explore low'
Write-Output 'LAYER STATE 5 Warden Combat full, Triumph high, Tension half'
Write-Output 'REGION MAP Hub Explore Nest Discovery Spire Tension OmniDistrict Discovery MegastructureDeep Tension Beacon Triumph'
Write-Output 'INSTRUMENT Layered AudioComponents with volume crossfade, MetaSound and Quartz status printed in plugin census above'
if ($p566open -eq $p566close) {
  $p566buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p566log = 'D:\VEIL-OMNI\Saved\build566.log'
  & $p566buildbat VEILEditor Win64 Development -Project="$p566uproj" -WaitMutex -NoHotReload *> "$p566log"
  $p566res = @(Select-String -Path $p566log -Pattern 'Result:' | Select-Object -Last 1)
  if ($p566res.Count -gt 0) { Write-Output ('BUILD ' + $p566res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
} else {
  if (Test-Path (Join-Path $p566backup 'PHI_DynamicMusic.h')) { Copy-Item -Path (Join-Path $p566backup 'PHI_DynamicMusic.h') -Destination $p566hpath -Force }
  if (Test-Path (Join-Path $p566backup 'PHI_DynamicMusic.cpp')) { Copy-Item -Path (Join-Path $p566backup 'PHI_DynamicMusic.cpp') -Destination $p566cpppath -Force }
  Write-Output 'GATE FAIL BRACE RESTORED BUILD SKIPPED'
}
Write-Output 'PHI P566 VERDICT: LAYERED DYNAMIC MUSIC UPGRADE ABOVE'
Write-Output 'JOB 566 DONE'
```
