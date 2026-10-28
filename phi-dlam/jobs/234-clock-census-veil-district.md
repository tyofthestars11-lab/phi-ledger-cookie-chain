# Job 234 — Clock census VEIL: the engine names its own WorldSettings properties (reflection, zero invented names)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Meta ranked WorldSettings bEnableWorldTick and Pauser as the frozen clocks last two squares - the same two flags this record left unread (jobs 205/219/224: Python finds neither name under any spelling). Metas own probe cannot run: its hook registers in a global static constructor before GEngine exists, it dumps once at world creation when TimeSeconds is 0.00 in every healthy world too, and its launch uses -game while the hook only fires for PIE worlds. This job replaces it with a reflection census: a small editor commandlet in the VEIL module iterates the loaded maps REAL AWorldSettings class through TFieldIterator and prints every property name + value the engine itself carries - if bEnableWorldTick exists in UE 5.8 its value prints; if the class does not carry it, Metas #1 is refuted by the class itself. The same run reflects UNavigationSystemV1s function names (Build/Lock) so the nav lock gets its real API names from the binary, not from invention. Map: VEILDistrict, the DONE package startup map. ==='
$enc = New-Object System.Text.UTF8Encoding($false)
$root = 'D:\VEIL\Source\VEIL'
New-Item -ItemType Directory -Force -Path 'D:\_PhiHolding\src-backup-234' | Out-Null
New-Item -ItemType Directory -Force -Path "$root\Public" | Out-Null
$bcs = "$root\VEIL.Build.cs"
$patched = $false
if (Test-Path $bcs) {
  $bsrc = [IO.File]::ReadAllText($bcs)
  if ($bsrc -match 'UnrealEd') { Write-Output 'Build.cs already names UnrealEd - untouched.'; $patched = $true }
  elseif ($bsrc -match '\}\s*\}\s*$') {
    Copy-Item $bcs 'D:\_PhiHolding\src-backup-234\VEIL.Build.cs' -Force
    $block = 'if (Target.bBuildEditor) { PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "NavigationSystem" }); }'
    $bsrc = $bsrc -replace '\}\s*\}\s*$', ("`t`t" + $block + "`r`n`t}`r`n}`r`n")
    [IO.File]::WriteAllText($bcs, $bsrc, $enc)
    Write-Output 'Build.cs patched: editor-only UnrealEd + NavigationSystem deps added at the end of the module constructor (backup in src-backup-234).'
    $patched = $true
  } else { Write-Output 'Build.cs tail shape unexpected - NOT patched. Its full text:'; Write-Output $bsrc }
} else { Write-Output "Build.cs MISSING at $bcs" }
if (-not $patched) { Write-Output 'CENSUS ABORTED at the Build.cs gate - no files written, no build attempted.'; return }
$hdr = @'
#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "ClockCensusCommandlet.generated.h"

UCLASS()
class UClockCensusCommandlet : public UCommandlet
{
	GENERATED_BODY()
public:
	UClockCensusCommandlet();
	virtual int32 Main(const FString& Params) override;
};
'@
$cpp = @'
#include "ClockCensusCommandlet.h"

#include "Editor.h"
#include "Engine/World.h"
#include "GameFramework/WorldSettings.h"
#include "FileHelpers.h"
#include "Misc/FileHelper.h"
#include "Misc/Parse.h"
#include "Misc/Paths.h"
#include "NavigationSystem.h"
#include "UObject/PropertyPortFlags.h"
#include "UObject/UnrealType.h"

UClockCensusCommandlet::UClockCensusCommandlet()
{
	IsClient = false;
	IsEditor = true;
	IsServer = false;
	LogToConsole = true;
}

static void DumpProps(UObject* Obj, const FString& Header, const TArray<FString>& Words, FString& Out)
{
	if (!Obj)
	{
		Out += Header + TEXT(" NULL\n");
		return;
	}
	Out += Header + TEXT("\n");
	for (TFieldIterator<FProperty> It(Obj->GetClass()); It; ++It)
	{
		FProperty* P = *It;
		FString Name = P->GetName();
		if (Words.Num() > 0)
		{
			FString L = Name.ToLower();
			bool bHit = false;
			for (const FString& W : Words)
			{
				if (L.Contains(W)) { bHit = true; break; }
			}
			if (!bHit) { continue; }
		}
		FString Val;
		P->ExportTextItem_Direct(Val, P->ContainerPtrToValuePtr<void>(Obj), nullptr, Obj, PPF_None);
		Out += FString::Printf(TEXT("PROP %s = %s\n"), *Name, *Val);
	}
}

int32 UClockCensusCommandlet::Main(const FString& Params)
{
	FString MapPath = TEXT("/Game/Maps/VEILDistrict");
	FParse::Value(*Params, TEXT("MAP="), MapPath);
	FString FilePath = FPaths::ProjectContentDir() / TEXT("Maps/VEILDistrict.umap");
	FParse::Value(*Params, TEXT("FILE="), FilePath);
	FString OutName = TEXT("District");
	FParse::Value(*Params, TEXT("OUT="), OutName);

	bool bLoaded = FEditorFileUtils::LoadMap(MapPath, false, true);
	if (!bLoaded)
	{
		bLoaded = FEditorFileUtils::LoadMap(FilePath, false, true);
	}
	FString Out;
	Out += FString::Printf(TEXT("CLOCKCENSUS map=%s loaded=%d\n"), *MapPath, bLoaded ? 1 : 0);
	if (!bLoaded)
	{
		FFileHelper::SaveStringToFile(Out, *(FPaths::ProjectSavedDir() / TEXT("Logs/clock_census_") + OutName + TEXT(".txt")));
		return 2;
	}
	UWorld* World = GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
	Out += FString::Printf(TEXT("WORLD %s\n"), World ? *World->GetName() : TEXT("NULL"));
	TArray<FString> ClockWords;
	ClockWords.Add(TEXT("time")); ClockWords.Add(TEXT("tick")); ClockWords.Add(TEXT("paus"));
	ClockWords.Add(TEXT("settings")); ClockWords.Add(TEXT("gamemode")); ClockWords.Add(TEXT("gamestate"));
	DumpProps(World, TEXT("== UWorld (clock words) =="), ClockWords, Out);
	AWorldSettings* WS = World ? World->GetWorldSettings() : nullptr;
	TArray<FString> AllWords;
	DumpProps(WS, TEXT("== AWorldSettings (ALL properties) =="), AllWords, Out);

	FString NavOut;
	NavOut += TEXT("== UNavigationSystemV1 reflected functions (build/lock) ==\n");
	for (TFieldIterator<UFunction> It(UNavigationSystemV1::StaticClass()); It; ++It)
	{
		FString L = It->GetName().ToLower();
		if (L.Contains(TEXT("build")) || L.Contains(TEXT("lock")))
		{
			NavOut += FString::Printf(TEXT("FUNC %s\n"), *It->GetName());
		}
	}
	TArray<FString> NavWords;
	NavWords.Add(TEXT("lock")); NavWords.Add(TEXT("build")); NavWords.Add(TEXT("nav"));
	UNavigationSystemBase* NavBase = World ? World->GetNavigationSystem() : nullptr;
	DumpProps(NavBase, TEXT("== NavSystem instance (nav words) =="), NavWords, NavOut);

	FFileHelper::SaveStringToFile(Out, *(FPaths::ProjectSavedDir() / TEXT("Logs/clock_census_") + OutName + TEXT(".txt")));
	FFileHelper::SaveStringToFile(NavOut, *(FPaths::ProjectSavedDir() / TEXT("Logs/nav_api_census_") + OutName + TEXT(".txt")));
	return 0;
}
'@
[IO.File]::WriteAllText("$root\Public\ClockCensusCommandlet.h", $hdr, $enc)
[IO.File]::WriteAllText("$root\Private\ClockCensusCommandlet.cpp", $cpp, $enc)
Write-Output 'Commandlet source written: Public\ClockCensusCommandlet.h + Private\ClockCensusCommandlet.cpp'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$build = & $eng 'VEILEditor' Win64 Development '-Project=D:\VEIL\VEIL.uproject' -WaitMutex 2>&1
$build | Select-String -Pattern 'Result:|error|Error|Traceback|Exception' | ForEach-Object { $_.Line }
if (($build -join "`n") -match 'Result: Succeeded') {
  $cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  $run = & $cmd 'D:\VEIL\VEIL.uproject' '-run=ClockCensusCommandlet' '-MAP=/Game/Maps/VEILDistrict' '-FILE=D:\VEIL\Content\Maps\VEILDistrict.umap' '-OUT=District' '-abslog=D:\VEIL\Saved\Logs\clock_census_cmd.log' -unattended 2>&1
  $run | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 10 | ForEach-Object { $_.Line }
  Write-Output '--- clock_census_District.txt ---'
  Get-Content 'D:\VEIL\Saved\Logs\clock_census_District.txt' -ErrorAction SilentlyContinue
  Write-Output '--- nav_api_census_District.txt ---'
  Get-Content 'D:\VEIL\Saved\Logs\nav_api_census_District.txt' -ErrorAction SilentlyContinue
} else { Write-Output 'BUILD DID NOT SUCCEED - commandlet not run; the build lines above name the fault.' }
```
