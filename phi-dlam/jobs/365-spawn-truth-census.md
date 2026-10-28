<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SPAWN TRUTH CENSUS 365 - CAPSULE, MESH PHYSICS, FLOOR COLLISION, ONE READ (Authored from Tyrees three photos of the merged build, read whole in the side chat: blue void, no floor, no UI, Countess center-frame in freefall, inverted, grey and dark, limbs in a tumble, not walking. That settles the fault class - pawn and floor interface, spawn equals fall - and three candidate values were named as UNVERIFIED THEORY with discriminating tests. Two of the three already carry measured reads from this lane: job 328 read the guaranteed slab in both parents - component QUERY_AND_PHYSICS on BlockAll, and the Cube mesh BodySetup carrying simple shapes box=1 - and jobs 333 to 335 read the packaged pawn at capEnabled=3, capProfile=Pawn, moveMode=3. The value never measured anywhere is the mesh physics state at spawn, and the merged base at D VEIL-OMNI has never had its own per-map floor census, because job 363 printed DONE after its first map. THIS JOB, merged base only, one motion: one, print the VEILCharacter and GameMode source lines where capsule, collision, mesh physics and movement live. Two, census floor collision per map in separate commandlets - VEILDistrict, OMNIWorld, VEILWorld - PlayerStart, every column actor with its component collision and profile, and the mesh BodySetup simple shape counts, the 328 read pattern, one commandlet per map so no single map ends the census. Three, census the skeletal mesh assets and character Blueprints for physics asset and the mesh simulate physics default. Four, instrument VEILCharacter BeginPlay and Tick with PHI SPAWN TRUTH and PHI TICK TRUTH log blocks - capsule enabled and profile, movement mode, mesh IsSimulatingPhysics and physics asset at spawn, then mesh versus capsule divergence and mesh pitch and roll at ticks 5, 30, 60 and 120 - backup first, anchors counted, the write verified by read-back in the same job, compile the editor target, run both game maps in game mode, print the truth lines from the log. If an anchor misses, the job prints it and stops before compile, and the census sections stand either way. The instrument is log-only and stands in source until the fix job removes it. OMNI-UE is not touched.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 365 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Write-Output '--- SECTION 1: SOURCE TRUTH ---'
$cppItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.cpp' -File | Select-Object -First 1
$hdrItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.h' -File | Select-Object -First 1
if (-not $cppItem) { Write-Output 'VEILCHARACTER CPP NOT FOUND'; Write-Output 'JOB 365 STOPPED'; return }
Write-Output ("CPP: " + $cppItem.FullName + " bytes=" + $cppItem.Length)
Select-String -Path $cppItem.FullName -Pattern 'Capsule|SimulatePhysics|SetSimulate|CollisionProfile|CollisionEnabled|MovementMode|BeginPlay|Super::Tick|GetMesh|PhysicsAsset' | ForEach-Object { ("SRC {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output
if ($hdrItem) { Write-Output ("HDR: " + $hdrItem.FullName + " bytes=" + $hdrItem.Length); Select-String -Path $hdrItem.FullName -Pattern 'Capsule|SimulatePhysics|Collision|Mesh|Tick|BeginPlay' | ForEach-Object { ("HDR {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output }
$gmItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILGameMode.cpp' -File | Select-Object -First 1
if ($gmItem) { Write-Output ("GAMEMODE: " + $gmItem.FullName); Select-String -Path $gmItem.FullName -Pattern 'DefaultPawnClass|VEILCharacter|SpawnActor|PlayerStart' | ForEach-Object { ("GM {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output }
Write-Output '--- SECTION 2: PER-MAP FLOOR CENSUS ---'
$pyA = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHMgKyAnXG4nKQpsZXMgPSB1bnJlYWwuZ2V0X2VkaXRvcl9zdWJzeXN0ZW0odW5yZWFsLkxldmVsRWRpdG9yU3Vic3lzdGVtKQpwZiA9IG9wZW4oTUFQUEFUSEZJTEUsICdyJykKbWFwcGF0aCA9IHBmLnJlYWQoKS5zdHJpcCgpCnBmLmNsb3NlKCkKdygnUEhJIEZMT09SMzY1IG1hcDogJyArIG1hcHBhdGgpCnRyeToKICAgIGxlcy5sb2FkX2xldmVsKG1hcHBhdGgpCiAgICB3KCdQSEkgRkxPT1IzNjUgbGV2ZWwgbG9hZGVkJykKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIEZMT09SMzY1IExPQUQgRVJST1I6ICcgKyBzdHIoZSkpCnRyeToKICAgIHdvcmxkID0gdW5yZWFsLkVkaXRvckxldmVsTGlicmFyeS5nZXRfZWRpdG9yX3dvcmxkKCkKICAgIGx2bHMgPSB3b3JsZC5nZXRfZWRpdG9yX3Byb3BlcnR5KCdsZXZlbHMnKQogICAgdygnUEhJIEZMT09SMzY1IHdvcmxkIGxldmVscyBjb3VudD0nICsgc3RyKGxlbihsdmxzKSkpCiAgICBmb3IgbHYgaW4gbHZsczoKICAgICAgICB0cnk6CiAgICAgICAgICAgIHcoJ1BISSBGTE9PUjM2NSBsZXZlbCBwa2c6ICcgKyBsdi5nZXRfb3V0ZXJtb3N0KCkuZ2V0X3BhdGhfbmFtZSgpKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZTI6CiAgICAgICAgICAgIHcoJ1BISSBGTE9PUjM2NSBsZXZlbCBwa2cgZXJyb3I6ICcgKyBzdHIoZTIpKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgRkxPT1IzNjUgbGV2ZWxzIHJlYWQgZXJyb3I6ICcgKyBzdHIoZSkpCmFjdG9ycyA9IHVucmVhbC5FZGl0b3JMZXZlbExpYnJhcnkuZ2V0X2FsbF9sZXZlbF9hY3RvcnMoKQp3KCdQSEkgRkxPT1IzNjUgYWN0b3JzPScgKyBzdHIobGVuKGFjdG9ycykpKQpzcGF3biA9IE5vbmUKZm9yIGEgaW4gYWN0b3JzOgogICAgY2xzID0gYS5nZXRfY2xhc3MoKS5nZXRfbmFtZSgpCiAgICBpZiAnUGxheWVyU3RhcnQnIGluIGNsczoKICAgICAgICBzcGF3biA9IGEuZ2V0X2FjdG9yX2xvY2F0aW9uKCkKICAgICAgICB3KCdQSEkgRkxPT1IzNjUgUExBWUVSU1RBUlQgbG9jIFg9JS4xZiBZPSUuMWYgWj0lLjFmJyAlIChzcGF3bi54LCBzcGF3bi55LCBzcGF3bi56KSkKaWYgc3Bhd24gaXMgTm9uZToKICAgIHcoJ1BISSBGTE9PUjM2NSBQTEFZRVJTVEFSVCBOT05FJykKZWxzZToKICAgIGZvciBhIGluIGFjdG9yczoKICAgICAgICBjb21wID0gYS5nZXRfY29tcG9uZW50X2J5X2NsYXNzKHVucmVhbC5TdGF0aWNNZXNoQ29tcG9uZW50KQogICAgICAgIGlmIG5vdCBjb21wOgogICAgICAgICAgICBjb250aW51ZQogICAgICAgIGIgPSBhLmdldF9jb21wb25lbnRzX2JvdW5kaW5nX2JveChUcnVlKQogICAgICAgIGNvbnRhaW5zID0gKGIubWluLnggPD0gc3Bhd24ueCA8PSBiLm1heC54KSBhbmQgKGIubWluLnkgPD0gc3Bhd24ueSA8PSBiLm1heC55KQogICAgICAgIGxhYiA9IHN0cihhLmdldF9hY3Rvcl9sYWJlbCgpKQogICAgICAgIGlmIGNvbnRhaW5zIG9yICdQSElfJyBpbiBsYWI6CiAgICAgICAgICAgIG1lc2ggPSBjb21wLmdldF9lZGl0b3JfcHJvcGVydHkoJ3N0YXRpY19tZXNoJykKICAgICAgICAgICAgdygnUEhJIEZMT09SMzY1IEFDVE9SIG5hbWU9JyArIGEuZ2V0X25hbWUoKSArICcgbGFiZWw9JyArIGxhYiArICcgdG9wPScgKyBmb3JtYXQoYi5tYXgueiwgJy4xZicpICsgJyBiYXNlPScgKyBmb3JtYXQoYi5taW4ueiwgJy4xZicpICsgJyBjb2x1bW49JyArIHN0cihjb250YWlucykgKyAnIGNvbGxpc2lvbj0nICsgc3RyKGNvbXAuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29sbGlzaW9uX2VuYWJsZWQnKSkgKyAnIHByb2ZpbGU9JyArIHN0cihjb21wLmdldF9jb2xsaXNpb25fcHJvZmlsZV9uYW1lKCkpICsgJyBtZXNoPScgKyAobWVzaC5nZXRfcGF0aF9uYW1lKCkgaWYgbWVzaCBlbHNlICdub25lJykpCiAgICAgICAgICAgIGlmIG1lc2g6CiAgICAgICAgICAgICAgICB0cnk6CiAgICAgICAgICAgICAgICAgICAgYnMgPSBtZXNoLmdldF9lZGl0b3JfcHJvcGVydHkoJ2JvZHlfc2V0dXAnKQogICAgICAgICAgICAgICAgICAgIGFnZyA9IGJzLmdldF9lZGl0b3JfcHJvcGVydHkoJ2FnZ19nZW9tJykKICAgICAgICAgICAgICAgICAgICB3KCdQSEkgRkxPT1IzNjUgU0hBUEVTIGJveD0lZCBzcGhlcmU9JWQgY2Fwc3VsZT0lZCBjb252ZXg9JWQgdHJhY2VmbGFnPSVzJyAlIChsZW4oYWdnLmdldF9lZGl0b3JfcHJvcGVydHkoJ2JveF9lbGVtcycpKSwgbGVuKGFnZy5nZXRfZWRpdG9yX3Byb3BlcnR5KCdzcGhlcmVfZWxlbXMnKSksIGxlbihhZ2cuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnc3BoeWxfZWxlbXMnKSksIGxlbihhZ2cuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29udmV4X2VsZW1zJykpLCBzdHIoYnMuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29sbGlzaW9uX3RyYWNlX2ZsYWcnKSkpKQogICAgICAgICAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICAgICAgICAgIHcoJ1BISSBGTE9PUjM2NSBTSEFQRVMgcmVhZCBlcnJvcjogJyArIHN0cihlKSkKdygnUEhJIEZMT09SMzY1IENPTVBMRVRFJykKb3V0LmNsb3NlKCkK'))
foreach ($mapname in @('VEILDistrict','OMNIWorld','VEILWorld')) {
  $gpath = '/Game/Maps/' + $mapname
  Set-Content "$base\Saved\phi_mappath365.txt" -Value $gpath -Encoding ASCII
  $outf = "$base\Saved\phi_floor365_$mapname.txt"
  $py = $pyA.Replace('MAPPATHFILE', "'$base\Saved\phi_mappath365.txt'").Replace('OUTFILE', "'$outf'")
  Set-Content "$base\Saved\phi_floor365.py" -Value $py -Encoding UTF8
  Remove-Item $outf -ErrorAction SilentlyContinue
  & $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_floor365.py" -unattended -nopause -nosplash *> "$base\Saved\floor365_$mapname.log"
  if (Test-Path $outf) { Get-Content $outf | Write-Output } else { Write-Output ("NO FLOOR OUTPUT FILE FOR " + $mapname); Select-String -Path "$base\Saved\floor365_$mapname.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output }
}
Write-Output '--- SECTION 3: MESH AND BLUEPRINT CENSUS ---'
$pyB = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHMgKyAnXG4nKQphciA9IHVucmVhbC5Bc3NldFJlZ2lzdHJ5SGVscGVycy5nZXRfYXNzZXRfcmVnaXN0cnkoKQphc3NldHMgPSBhci5nZXRfYXNzZXRzX2J5X3BhdGgoJy9HYW1lJywgVHJ1ZSkKdygnUEhJIEFTU0VUMzY1IHRvdGFsPScgKyBzdHIobGVuKGFzc2V0cykpKQpmb3IgYWQgaW4gYXNzZXRzOgogICAgdHJ5OgogICAgICAgIGNscyA9IHN0cihhZC5hc3NldF9jbGFzc19wYXRoLmFzc2V0X25hbWUpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIGNscyA9ICcnCiAgICBuYW1lID0gc3RyKGFkLmFzc2V0X25hbWUpCiAgICBpZiBjbHMgPT0gJ1NrZWxldGFsTWVzaCc6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBvYmogPSBhZC5nZXRfYXNzZXQoKQogICAgICAgICAgICBwYSA9IG9iai5nZXRfZWRpdG9yX3Byb3BlcnR5KCdwaHlzaWNzX2Fzc2V0JykKICAgICAgICAgICAgc2sgPSBvYmouZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnc2tlbGV0b24nKQogICAgICAgICAgICB3KCdQSEkgQVNTRVQzNjUgU0tFTE1FU0ggJyArIHN0cihhZC5wYWNrYWdlX25hbWUpICsgJyBwaHlzaWNzX2Fzc2V0PScgKyAocGEuZ2V0X3BhdGhfbmFtZSgpIGlmIHBhIGVsc2UgJ25vbmUnKSArICcgc2tlbGV0b249JyArIChzay5nZXRfcGF0aF9uYW1lKCkgaWYgc2sgZWxzZSAnbm9uZScpKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgdygnUEhJIEFTU0VUMzY1IFNLRUxNRVNIIHJlYWQgZXJyb3IgJyArIG5hbWUgKyAnOiAnICsgc3RyKGUpKQogICAgaWYgY2xzID09ICdCbHVlcHJpbnQnIGFuZCAoJ0NoYXJhY3RlcicgaW4gbmFtZSBvciAnQ291bnRlc3MnIGluIG5hbWUgb3IgJ1Bhd24nIGluIG5hbWUpOgogICAgICAgIHRyeToKICAgICAgICAgICAgYnAgPSBhZC5nZXRfYXNzZXQoKQogICAgICAgICAgICBnYyA9IGJwLmdldF9lZGl0b3JfcHJvcGVydHkoJ2dlbmVyYXRlZF9jbGFzcycpCiAgICAgICAgICAgIGNkbyA9IGdjLmdldF9kZWZhdWx0X29iamVjdCgpCiAgICAgICAgICAgIG1lc2ggPSBjZG8uZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnbWVzaCcpCiAgICAgICAgICAgIGNhcCA9IGNkby5nZXRfZWRpdG9yX3Byb3BlcnR5KCdjYXBzdWxlX2NvbXBvbmVudCcpCiAgICAgICAgICAgIHRyeToKICAgICAgICAgICAgICAgIHNpbSA9IHN0cihtZXNoLmdldF9lZGl0b3JfcHJvcGVydHkoJ3NpbXVsYXRlX3BoeXNpY3MnKSkKICAgICAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlMzoKICAgICAgICAgICAgICAgIHNpbSA9ICdyZWFkIGVycm9yOiAnICsgc3RyKGUzKQogICAgICAgICAgICB3KCdQSEkgQVNTRVQzNjUgQlAgJyArIHN0cihhZC5wYWNrYWdlX25hbWUpICsgJyBtZXNoX3NpbXVsYXRlX3BoeXNpY3M9JyArIHNpbSArICcgY2FwX2NvbGxpc2lvbj0nICsgc3RyKGNhcC5nZXRfZWRpdG9yX3Byb3BlcnR5KCdjb2xsaXNpb25fZW5hYmxlZCcpKSArICcgY2FwX3Byb2ZpbGU9JyArIHN0cihjYXAuZ2V0X2NvbGxpc2lvbl9wcm9maWxlX25hbWUoKSkpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgQVNTRVQzNjUgQlAgcmVhZCBlcnJvciAnICsgbmFtZSArICc6ICcgKyBzdHIoZSkpCncoJ1BISSBBU1NFVDM2NSBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$outB = "$base\Saved\phi_asset365.txt"
$py = $pyB.Replace('OUTFILE', "'$outB'")
Set-Content "$base\Saved\phi_asset365.py" -Value $py -Encoding UTF8
Remove-Item $outB -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_asset365.py" -unattended -nopause -nosplash *> "$base\Saved\asset365.log"
if (Test-Path $outB) { Get-Content $outB | Write-Output } else { Write-Output 'NO ASSET OUTPUT FILE'; Select-String -Path "$base\Saved\asset365.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output }
Write-Output '--- SECTION 4: INSTRUMENT, COMPILE, RUN ---'
$cpp = $cppItem.FullName
Copy-Item $cpp "$cpp.phi-backup-365" -Force
Write-Output 'CPP BACKED UP (.phi-backup-365)'
$src = [System.IO.File]::ReadAllText($cpp)
$spawnBlock = @'
    // PHI SPAWN TRUTH 365 - one-shot spawn state read
    {
        UCapsuleComponent* Cap365 = GetCapsuleComponent();
        USkeletalMeshComponent* Mesh365 = GetMesh();
        UCharacterMovementComponent* Move365 = GetCharacterMovement();
        UE_LOG(LogTemp, Warning, TEXT("PHI SPAWN TRUTH name=%s capEnabled=%d capProfile=%s moveMode=%d meshSim=%d meshPhysAsset=%s"), *GetName(), (int32)Cap365->GetCollisionEnabled(), *Cap365->GetCollisionProfileName().ToString(), Move365 ? (int32)Move365->MovementMode : -1, (Mesh365 && Mesh365->IsSimulatingPhysics()) ? 1 : 0, (Mesh365 && Mesh365->GetPhysicsAsset()) ? *Mesh365->GetPhysicsAsset()->GetName() : TEXT("none"));
    }
'@
$tickBlock = @'
    // PHI TICK TRUTH 365 - mesh versus capsule divergence read
    {
        static int32 PhiTick365 = 0;
        PhiTick365++;
        if (PhiTick365 == 5 || PhiTick365 == 30 || PhiTick365 == 60 || PhiTick365 == 120)
        {
            const FVector CapW365 = GetCapsuleComponent()->GetComponentLocation();
            const FVector MeshW365 = GetMesh()->GetComponentLocation();
            const FRotator MeshR365 = GetMesh()->GetComponentRotation();
            const FFindFloorResult& Fl365 = GetCharacterMovement()->CurrentFloor;
            UE_LOG(LogTemp, Warning, TEXT("PHI TICK TRUTH name=%s tick=%d capZ=%.1f meshZ=%.1f delta=%.1f meshPitch=%.1f meshRoll=%.1f meshSim=%d moveMode=%d floorBlock=%d floorActor=%s"), *GetName(), PhiTick365, CapW365.Z, MeshW365.Z, (MeshW365 - CapW365).Size(), MeshR365.Pitch, MeshR365.Roll, GetMesh()->IsSimulatingPhysics() ? 1 : 0, (int32)GetCharacterMovement()->MovementMode, Fl365.bBlockingHit ? 1 : 0, Fl365.HitResult.GetActor() ? *Fl365.HitResult.GetActor()->GetName() : TEXT("none"));
        }
    }
'@
$bpIdx = $src.IndexOf('AVEILCharacter::BeginPlay')
$spIdx = -1
if ($bpIdx -ge 0) { $spIdx = $src.IndexOf('Super::BeginPlay();', $bpIdx) }
if ($spIdx -lt 0) { Write-Output 'BEGINPLAY ANCHOR MISS - no compile runs.'; Write-Output 'JOB 365 STOPPED AFTER CENSUS'; return }
$insAt = $spIdx + 'Super::BeginPlay();'.Length
$src = $src.Substring(0, $insAt) + "`r`n" + $spawnBlock + $src.Substring($insAt)
$tkIdx = $src.IndexOf('AVEILCharacter::Tick')
$stIdx = -1
if ($tkIdx -ge 0) { $stIdx = $src.IndexOf('Super::Tick(', $tkIdx) }
if ($stIdx -lt 0) { Write-Output 'TICK ANCHOR MISS - nothing written.'; Write-Output 'JOB 365 STOPPED AFTER CENSUS'; return }
$semi = $src.IndexOf(';', $stIdx)
$src = $src.Substring(0, $semi + 1) + "`r`n" + $tickBlock + $src.Substring($semi + 1)
[System.IO.File]::WriteAllText($cpp, $src)
$check = [System.IO.File]::ReadAllText($cpp)
if ($check.Contains('PHI SPAWN TRUTH') -and $check.Contains('PHI TICK TRUTH')) { Write-Output 'INSTRUMENT PATCHED + VERIFIED in file' } else { Write-Output 'PATCH VERIFY FAILED - no build runs.'; Write-Output 'JOB 365 STOPPED AFTER CENSUS'; return }
$target365 = -join ([char[]](86,69,73,76,69,100,105,116,111,114))
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$blog = "$base\Saved\spawnbuild365.log"
$p = Start-Process $buildbat -ArgumentList @($target365,'Win64','Development',"-Project=$uproj",'-WaitMutex','-NoHotReload') -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $blog -RedirectStandardError "$blog.errlog"
Write-Output ("BUILD exit: " + $p.ExitCode)
Select-String -Path $blog -Pattern 'error C[0-9]+|error :|Result:|Total time' -ErrorAction SilentlyContinue | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
if ($p.ExitCode -ne 0) { Write-Output 'BUILD FAILED - no game runs.'; Write-Output 'JOB 365 STOPPED AFTER BUILD'; return }
foreach ($mapname in @('VEILDistrict','OMNIWorld')) {
  Write-Output ("--- GAME RUN: " + $mapname + " ---")
  $gp = Start-Process $edexe -ArgumentList @($uproj, ("/Game/Maps/" + $mapname), '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 45
  if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'GAME RUN STOPPED AFTER 45s CAPTURE' } else { Write-Output ("GAME EXITED EARLY code=" + $gp.ExitCode) }
  Start-Sleep -Seconds 3
  $logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logf) { Write-Output ("LOG: " + $logf.FullName); $hits = Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH' -ErrorAction SilentlyContinue; if ($hits) { $hits | Select-Object -Last 24 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO TRUTH LINES IN LOG'; Select-String -Path $logf.FullName -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output } } else { Write-Output 'NO LOG FILE FOUND' }
}
Write-Output 'INSTRUMENT STANDS IN SOURCE - log only, no behavior change, rides until the fix job removes it.'
Write-Output 'JOB 365 DONE'
```
