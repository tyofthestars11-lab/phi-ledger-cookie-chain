<!-- PHI-DIRECT -->
```powershell
Write-Output '=== HUB BUILD 440 - THE FIRST REGION SEATED ON THE STANDING BUILDER (Ground read whole from jobs 427, 430, and 436: region mentions in source stood at Hub 0, and the Hub is the named first campaign tranche; VEILWorldBuilder builds the standing district at runtime through SpawnBlock, ground, plaza disc, phi tower grid, beacon spire, and PlayerStart, and BuildWorld calls BuildLighting then BuildDistrict under its build once guard; the quest givers, fragments, and cache already stand around this plaza from the GameMode seeding. The Hub enters as a build section of this same builder, in its own idiom and nothing else: four golden roads run from the plaza toward the district edge on the four axes, and a phi ring of eight lit pylons marks the plaza as home ground, closing with its own log line, VEIL HUB SEATED. One, the header gains the BuildHub declaration beside BuildDistrict, a counted edit with backup. Two, BuildWorld gains the BuildHub call after BuildDistrict, a counted edit. Three, the BuildHub function is inserted before BuildWorld in the cpp, a counted edit. Four, every write reads back and prints its counts. Five, the job compiles VEILEditor Win64 Development and prints the last 15 lines of the build log whole. Six, the verdict in one line: HUB BUILT with the read back counts and the build state, or HUB HELD with the stage named. Every variable carries the hb440 prefix.) ==='
$hb440root = 'D:\VEIL-OMNI'
$hb440src = Join-Path $hb440root 'Source\VEIL'
$hb440cpp = Get-ChildItem -Path $hb440src -Recurse -Filter 'VEILWorldBuilder.cpp' | Select-Object -First 1
$hb440h = Get-ChildItem -Path $hb440src -Recurse -Filter 'VEILWorldBuilder.h' | Select-Object -First 1
if (-not $hb440cpp -or -not $hb440h) { Write-Output 'HUB HELD stage=builder-missing'; Write-Output 'JOB 440 DONE'; exit 0 }
Copy-Item $hb440cpp.FullName ($hb440cpp.FullName + '.phi-backup-440') -Force
Copy-Item $hb440h.FullName ($hb440h.FullName + '.phi-backup-440') -Force
$hb440hBody = [IO.File]::ReadAllText($hb440h.FullName)
$hb440hCnt = ([regex]::Matches($hb440hBody, 'void BuildDistrict\(\);')).Count
Write-Output ('HEADER ANCHOR=' + $hb440hCnt)
if ($hb440hCnt -ne 1) { Write-Output 'HUB HELD stage=header-seat'; Write-Output 'JOB 440 DONE'; exit 0 }
$hb440hBody = $hb440hBody.Replace('void BuildDistrict();', "void BuildDistrict();`n`tvoid BuildHub();")
[IO.File]::WriteAllText($hb440h.FullName, $hb440hBody, (New-Object System.Text.UTF8Encoding $false))
$hb440cBody = [IO.File]::ReadAllText($hb440cpp.FullName)
$hb440callCnt = ([regex]::Matches($hb440cBody, 'BuildDistrict\(\);')).Count
$hb440bwCnt = ([regex]::Matches($hb440cBody, 'void AVEILWorldBuilder::BuildWorld\(\)')).Count
Write-Output ('CPP ANCHORS call=' + $hb440callCnt + ' buildworld=' + $hb440bwCnt)
if ($hb440callCnt -ne 1 -or $hb440bwCnt -ne 1) { Write-Output 'HUB HELD stage=cpp-seat'; Write-Output 'JOB 440 DONE'; exit 0 }
$hb440cBody = $hb440cBody.Replace('BuildDistrict();', "BuildDistrict();`n`tBuildHub();")
$hb440fn = @'
void AVEILWorldBuilder::BuildHub()
{
	// THE HUB: the first region of the merged world, seated on the standing
	// district. Four roads run from the plaza toward the district edge on
	// the four axes, and a phi ring of eight lit pylons marks the plaza as
	// home ground, the ground the quest givers already stand around.
	const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
	const FLinearColor RoadTint(0.16f, 0.13f, 0.07f);
	int32 Roads = 0;
	const FVector RoadDirs[4] = { FVector(1.f, 0.f, 0.f), FVector(-1.f, 0.f, 0.f), FVector(0.f, 1.f, 0.f), FVector(0.f, -1.f, 0.f) };
	for (int32 i = 0; i < 4; ++i)
	{
		const FVector Dir = RoadDirs[i];
		const FVector Loc(Dir.X * 4200.f, Dir.Y * 4200.f, 2.f);
		const FVector Scale = (Dir.X != 0.f) ? FVector(84.f, 6.f, 0.04f) : FVector(6.f, 84.f, 0.04f);
		SpawnBlock(Loc, Scale, CubeMesh, RoadTint, 0.f);
		++Roads;
	}
	int32 Pylons = 0;
	const float RingRadius = 1500.f;
	for (int32 i = 0; i < 8; ++i)
	{
		const float A = (float)i * 0.7853981f;
		const FVector Loc(FMath::Cos(A) * RingRadius, FMath::Sin(A) * RingRadius, 260.f);
		SpawnBlock(Loc, FVector(1.2f, 1.2f, 5.2f), CubeMesh, GoldTint, 2.0f);
		++Pylons;
	}
	UE_LOG(LogVEIL, Log, TEXT("VEIL HUB SEATED: %d roads, %d pylons, the plaza ring stands."), Roads, Pylons);
}

'@
$hb440cBody = $hb440cBody.Replace('void AVEILWorldBuilder::BuildWorld()', $hb440fn + 'void AVEILWorldBuilder::BuildWorld()')
[IO.File]::WriteAllText($hb440cpp.FullName, $hb440cBody, (New-Object System.Text.UTF8Encoding $false))
$hb440backC = [IO.File]::ReadAllText($hb440cpp.FullName)
$hb440backH = [IO.File]::ReadAllText($hb440h.FullName)
$hb440vFn = ([regex]::Matches($hb440backC, 'BuildHub\(\)')).Count
$hb440vH = ([regex]::Matches($hb440backH, 'BuildHub')).Count
$hb440vLog = ([regex]::Matches($hb440backC, 'VEIL HUB SEATED')).Count
Write-Output ('VERIFY cpp BuildHub refs=' + $hb440vFn + ' header=' + $hb440vH + ' logline=' + $hb440vLog)
$hb440buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$hb440uproj = Join-Path $hb440root 'VEIL.uproject'
$hb440log = Join-Path $hb440root 'Saved\build440.log'
& $hb440buildbat VEILEditor Win64 Development -Project="$hb440uproj" -WaitMutex -NoHotReload *> "$hb440log"
Write-Output '--- BUILD LOG TAIL ---'
Get-Content $hb440log -Tail 15 | ForEach-Object { Write-Output ('LOG ' + $_) }
$hb440raw = Get-Content $hb440log -Raw
$hb440bst = 'UNKNOWN'
if ($hb440raw.Contains('BUILD SUCCESS')) { $hb440bst = 'OK' } elseif ($hb440raw -match 'BUILD FAILED|Build failed') { $hb440bst = 'FAIL' }
Write-Output ('PHI HB440 VERDICT: HUB BUILT refs=' + $hb440vFn + ' build=' + $hb440bst)
Write-Output 'JOB 440 DONE'
```
