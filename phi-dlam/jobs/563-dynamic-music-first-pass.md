<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 563 - DYNAMIC MUSIC FIRST PASS (Ground: Tyree ordered game audio, background music first plus ambient and effects, so this job censuses existing audio, authors five loop-ready stem WAV files from the free grid default with nothing bought, and seats a dynamic music manager in the correct Systems folders with backup first, no build in this job, build rides the next job. Voice clips stay untouched. Every variable carries the p563 prefix.) ==='
$p563content = 'D:\VEIL-OMNI\Content'
$p563audioDir = 'D:\VEIL-OMNI\Content\PHI\Audio'
if (Test-Path $p563content) {
  $p563folders = Get-ChildItem -Path $p563content -Directory -ErrorAction SilentlyContinue
  foreach ($p563f in $p563folders) { Write-Output ('CENSUS FOLDER ' + $p563f.Name) }
  $p563wav = @(Get-ChildItem -Path $p563content -Recurse -Filter '*.wav' -File -ErrorAction SilentlyContinue)
  Write-Output ('AUDIO WAV COUNT ' + $p563wav.Count)
  foreach ($p563w in $p563wav) { Write-Output ('AUDIO WAV FILE ' + $p563w.FullName) }
  $p563audiodirs = @(Get-ChildItem -Path $p563content -Recurse -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*Audio*' -or $_.Name -like '*Music*' -or $_.Name -like '*Sound*' -or $_.Name -like '*Voice*' })
  foreach ($p563d in $p563audiodirs) { Write-Output ('AUDIO DIR ' + $p563d.FullName) }
} else { Write-Output 'NO CONTENT FOLDER FOUND' }
$p563b64 = 'aW1wb3J0IHdhdmUsIG1hdGgsIHN0cnVjdApTUiA9IDIyMDUwCkRVUiA9IDQKTiA9IFNSICogRFVSClBISSA9IDEuNjE4MDMzOTg4NzQ5ODk1Ck9VVCA9ICJEOlxcVkVJTC1PTU5JXFxDb250ZW50XFxQSElcXEF1ZGlvXFwiCmltcG9ydCBvcwpvcy5tYWtlZGlycyhPVVQsIGV4aXN0X29rPVRydWUpCmRlZiB3cml0ZV9zdGVtKG5hbWUsIGZyZXFfbGlzdCk6CiAgICBmcmFtZXMgPSBbXQogICAgc2VnID0gTiAvLyBsZW4oZnJlcV9saXN0KQogICAgZm9yIGlkeCwgZnJlcXMgaW4gZW51bWVyYXRlKGZyZXFfbGlzdCk6CiAgICAgICAgZm9yIGkgaW4gcmFuZ2Uoc2VnKToKICAgICAgICAgICAgdCA9IGkgLyBTUgogICAgICAgICAgICB2ID0gMC4wCiAgICAgICAgICAgIGZvciBmIGluIGZyZXFzOgogICAgICAgICAgICAgICAgdiArPSBtYXRoLnNpbigyLjAgKiBtYXRoLnBpICogZiAqIHQpCiAgICAgICAgICAgIHYgPSB2IC8gbWF4KDEsIGxlbihmcmVxcykpCiAgICAgICAgICAgIGVudiA9IDEuMAogICAgICAgICAgICBpZiBpIDwgMjIwNToKICAgICAgICAgICAgICAgIGVudiA9IGkgLyAyMjA1CiAgICAgICAgICAgIGlmIGkgPiBzZWcgLSAyMjA1OgogICAgICAgICAgICAgICAgZW52ID0gKHNlZyAtIGkpIC8gMjIwNQogICAgICAgICAgICBmcmFtZXMuYXBwZW5kKGludChtYXgoLTEuMCwgbWluKDEuMCwgdiAqIGVudiAqIDAuOCkpICogMzI3NjcpKQogICAgd2hpbGUgbGVuKGZyYW1lcykgPCBOOgogICAgICAgIGZyYW1lcy5hcHBlbmQoMCkKICAgIGZyYW1lcyA9IGZyYW1lc1s6Tl0KICAgIHdpdGggd2F2ZS5vcGVuKE9VVCArIG5hbWUsICJ3YiIpIGFzIHc6CiAgICAgICAgdy5zZXRuY2hhbm5lbHMoMSkKICAgICAgICB3LnNldHNhbXB3aWR0aCgyKQogICAgICAgIHcuc2V0ZnJhbWVyYXRlKFNSKQogICAgICAgIHcud3JpdGVmcmFtZXMoc3RydWN0LnBhY2soIjwiICsgImgiICogbGVuKGZyYW1lcyksICpmcmFtZXMpKQogICAgcHJpbnQoIlRSQUNLICIgKyBuYW1lICsgIiBTQU1QTEVTICIgKyBzdHIobGVuKGZyYW1lcykpKQp3cml0ZV9zdGVtKCJQSElfRXhwbG9yZS53YXYiLCBbWzE0Ni44MywgMjIwLjAsIDI5My42Nl0sIFsxMTYuNTQsIDIzMy4wOF0sIFsxNzQuNjEsIDI2MS42M10sIFsxMzAuODEsIDE5Ni4wLCAyNjEuNjNdXSkKd3JpdGVfc3RlbSgiUEhJX1RlbnNpb24ud2F2IiwgW1s1NS4wLCA1OC4yN10sIFs1NS4wLCA1OC4yN10sIFs1NS4wLCA1OC4yN10sIFs1NS4wLCA1OC4yN11dKQp3cml0ZV9zdGVtKCJQSElfQ29tYmF0LndhdiIsIFtbMTEwLjAsIDIyMC4wXSwgWzExMC4wLCAyMjAuMF0sIFsxMTAuMCwgMjIwLjBdLCBbMTEwLjAsIDIyMC4wXV0pCndyaXRlX3N0ZW0oIlBISV9EaXNjb3Zlcnkud2F2IiwgW1syNjEuNjNdLCBbMjYxLjYzICogUEhJXSwgWzI2MS42MyAqIFBISSAqIFBISV0sIFsyNjEuNjMgKiBQSEkgKiBQSEkgKiBQSEldXSkKd3JpdGVfc3RlbSgiUEhJX1RyaXVtcGgud2F2IiwgW1syNjEuNjMsIDMyOS42MywgMzkyLjBdLCBbMzQ5LjIzLCA0NDAuMF0sIFszOTIuMCwgNDkzLjg4XSwgWzUyMy4yNSwgNjU5LjI1XV0pCnByaW50KCJTVEVNUyBET05FIikK'
$p563py = 'D:\VEIL-OMNI\Saved\music563.py'
[IO.File]::WriteAllBytes($p563py, [Convert]::FromBase64String($p563b64))
$p563python = 'C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe'
if (Test-Path $p563python) {
  & $p563python $p563py
} else { Write-Output 'NO PYTHON FOUND' }
if (Test-Path $p563audioDir) {
  $p563stems = Get-ChildItem -Path $p563audioDir -Filter '*.wav' -File -ErrorAction SilentlyContinue
  foreach ($p563s in $p563stems) { Write-Output ('TRACK FILE ' + $p563s.Name + ' BYTES ' + $p563s.Length) }
} else { Write-Output 'NO STEM FOLDER FOUND' }
Write-Output 'SEAT Explore Hub District exploration'
Write-Output 'SEAT Tension Spire and Megastructure Deep tension'
Write-Output 'SEAT Combat Warden arena and faction combat'
Write-Output 'SEAT Discovery fragments and cache discovery'
Write-Output 'SEAT Triumph Warden clear and quest complete'
$p563hpath = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_DynamicMusic.h'
$p563cpppath = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_DynamicMusic.cpp'
$p563backup = 'D:\VEIL-OMNI\Saved\backup563'
New-Item -ItemType Directory -Path $p563backup -Force | Out-Null
if (Test-Path $p563hpath) { Copy-Item -Path $p563hpath -Destination (Join-Path $p563backup 'PHI_DynamicMusic.h') -Force; Write-Output 'BACKUP HEADER DONE' }
if (Test-Path $p563cpppath) { Copy-Item -Path $p563cpppath -Destination (Join-Path $p563backup 'PHI_DynamicMusic.cpp') -Force; Write-Output 'BACKUP SOURCE DONE' }
$p563h = @'
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
    UFUNCTION(BlueprintCallable, Category="PHI|Music")
    void SetMusicState(int32 NewState);
protected:
    virtual void BeginPlay() override;
private:
    class UAudioComponent* CurrentAudio;
    void PlayStem(class USoundWave* Stem);
};
'@
$p563cpp = @'
#include "Systems/PHI_DynamicMusic.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
UPHI_DynamicMusicComponent::UPHI_DynamicMusicComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MusicState = 0;
    CurrentAudio = nullptr;
    ExploreStem = nullptr;
    TensionStem = nullptr;
    CombatStem = nullptr;
    DiscoveryStem = nullptr;
    TriumphStem = nullptr;
}
void UPHI_DynamicMusicComponent::BeginPlay()
{
    Super::BeginPlay();
    PlayStem(ExploreStem);
}
void UPHI_DynamicMusicComponent::SetMusicState(int32 NewState)
{
    if (NewState == MusicState) { return; }
    MusicState = NewState;
    if (NewState == 0) { PlayStem(ExploreStem); }
    else if (NewState == 1) { PlayStem(TensionStem); }
    else if (NewState == 2) { PlayStem(CombatStem); }
    else if (NewState == 3) { PlayStem(DiscoveryStem); }
    else if (NewState == 4) { PlayStem(TriumphStem); }
}
void UPHI_DynamicMusicComponent::PlayStem(USoundWave* Stem)
{
    if (Stem == nullptr) { return; }
    if (CurrentAudio != nullptr) { CurrentAudio->FadeOut(1.0f, 0.0f); CurrentAudio = nullptr; }
    CurrentAudio = UGameplayStatics::SpawnSound2D(GetWorld(), Stem);
    if (CurrentAudio != nullptr) { CurrentAudio->FadeIn(1.0f, 1.0f); }
}
'@
[IO.File]::WriteAllText($p563hpath, $p563h)
[IO.File]::WriteAllText($p563cpppath, $p563cpp)
Write-Output 'MANAGER HEADER WRITTEN'
Write-Output 'MANAGER SOURCE WRITTEN'
$p563htext = Get-Content $p563hpath -Raw
$p563ctext = Get-Content $p563cpppath -Raw
$p563open = ([regex]::Matches($p563ctext, '\{')).Count + ([regex]::Matches($p563htext, '\{')).Count
$p563close = ([regex]::Matches($p563ctext, '\}')).Count + ([regex]::Matches($p563htext, '\}')).Count
Write-Output ('BRACE OPEN ' + $p563open + ' CLOSE ' + $p563close)
Write-Output 'PHI P563 VERDICT: DYNAMIC MUSIC FIRST PASS ABOVE'
Write-Output 'JOB 563 DONE'
```
