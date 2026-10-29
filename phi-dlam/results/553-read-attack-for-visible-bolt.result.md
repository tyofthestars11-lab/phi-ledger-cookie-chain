# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 03:54:42 UTC

## STEP 1
```
=== JOB 553 - READ THE ATTACK BEFORE THE VISIBLE BOLT PATCH (Ground: job 541 proved the attack fires and hits but nothing visible shows, so the visible bolt fix needs the fire code and the bolt assets read before any patch is written. This job prints the fire body plus the attack lines plus the bolt asset census. No patch rides this job, no build, no launch. No game relaunch rides this job. Every variable carries the p553 prefix.) ===
SOURCE LINES=779
FIRE MATCH 287 PlayerInputComponent->BindKey(EKeys::Gamepad_RightTrigger, IE_Pressed, this, &AVEILCharacter::Fire);
FIRE MATCH 330 if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
FIRE MATCH 614 void AVEILCharacter::Fire()
FIRE BODY 614 void AVEILCharacter::Fire()
FIRE BODY 615 {
FIRE BODY 616 	const float Now = GetWorld()->TimeSeconds;
FIRE BODY 617 	if (!IsAlive() || Now - LastFireTime < FireCooldown) return;
FIRE BODY 618 	LastFireTime = Now;
FIRE BODY 619 
FIRE BODY 620 	FVector Start;
FIRE BODY 621 	FRotator ViewRot;
FIRE BODY 622 	if (Controller) Controller->GetPlayerViewPoint(Start, ViewRot);
FIRE BODY 623 	else { Start = GetActorLocation(); ViewRot = GetActorRotation(); }
FIRE BODY 624 
FIRE BODY 625 	const FVector End = Start + ViewRot.Vector() * WeaponRange;
FIRE BODY 626 	FHitResult Hit;
FIRE BODY 627 	FCollisionQueryParams Params;
FIRE BODY 628 	Params.AddIgnoredActor(this);
FIRE BODY 629 
FIRE BODY 630 	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
FIRE BODY 631 	{
FIRE BODY 632 		if (AActor* Victim = Hit.GetActor())
FIRE BODY 633 		{
FIRE BODY 634 			UGameplayStatics::ApplyDamage(Victim, WeaponDamage, Controller, this, UDamageType::StaticClass());
FIRE BODY 635 		}
FIRE BODY 636 	}
FIRE BODY 637 	// PHI ATTACK VISIBLE: the shot answers in the world - a gold lance bolt
FIRE BODY 638 	// from the view point to the hit point, and a flash where it lands.
FIRE BODY 639 	{
FIRE BODY 640 		const FVector BoltEnd = Hit.bBlockingHit ? Hit.Location : End;
FIRE BODY 641 		const FVector BoltMid = (Start + BoltEnd) * 0.5f;
FIRE BODY 642 		const float BoltLen = (BoltEnd - Start).Size();
FIRE BODY 643 		if (UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")))
FIRE BODY 644 		{
FIRE BODY 645 			if (AStaticMeshActor* Bolt = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltMid, (BoltEnd - Start).Rotation()))
FIRE BODY 646 			{
FIRE BODY 647 				Bolt->SetActorScale3D(FVector(BoltLen / 100.f, 0.06f, 0.06f));
FIRE BODY 648 				Bolt->SetLifeSpan(0.15f);
FIRE BODY 649 				if (UStaticMeshComponent* BC = Bolt->GetStaticMeshComponent())
FIRE BODY 650 				{
FIRE BODY 651 					BC->SetStaticMesh(CubeMesh);
FIRE BODY 652 					BC->SetCollisionEnabled(ECollisionEnabled::NoCollision);
FIRE BODY 653 					if (UMaterialInterface* Base = BC->GetMaterial(0))
FIRE BODY 654 					{
FIRE BODY 655 						if (UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(Base, Bolt))
FIRE BODY 656 						{
FIRE BODY 657 							MID->SetVectorParameterValue(TEXT("Colo\x72"), FLinearColor(1.f, 0.78f, 0.25f));
FIRE BODY 658 							MID->SetVectorParameterValue(TEXT("EmissiveColo\x72"), FLinearColor(1.f, 0.78f, 0.25f) * 3.f);
FIRE BODY 659 							BC->SetMaterial(0, MID);
FIRE BODY 660 						}
FIRE BODY 661 					}
FIRE BODY 662 				}
FIRE BODY 663 			}
FIRE BODY 664 		}
FIRE BODY 665 		if (UStaticMesh* SphereMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere.Sphere")))
FIRE BODY 666 		{
FIRE BODY 667 			if (AStaticMeshActor* Flash = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltEnd, FRotator::ZeroRotator))
FIRE BODY 668 			{
FIRE BODY 669 				Flash->SetActorScale3D(FVector(0.3f, 0.3f, 0.3f));
FIRE BODY 670 				Flash->SetLifeSpan(0.2f);
FIRE BODY 671 				if (UStaticMeshComponent* FC = Flash->GetStaticMeshComponent())
FIRE BODY 672 				{
FIRE BODY 673 					FC->SetStaticMesh(SphereMesh);
FIRE BODY 674 					FC->SetCollisionEnabled(ECollisionEnabled::NoCollision);
ATTACK LINE 637 // PHI ATTACK VISIBLE: the shot answers in the world - a gold lance bolt
ATTACK LINE 688 UE_LOG(LogTemp, Display, TEXT("PHI ATTACK FIRED hit=%d"), Hit.bBlockingHit ? 1 : 0);
SPAWN MATCH 637 // PHI ATTACK VISIBLE: the shot answers in the world - a gold lance bolt
SPAWN MATCH 645 if (AStaticMeshActor* Bolt = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltMid, (BoltEnd - Start).Rotation()))
SPAWN MATCH 667 if (AStaticMeshActor* Flash = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), BoltEnd, FRotator::ZeroRotator))
BOLT COUNT SHOWN=2
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Textures\trails\T_ElectricalBolt_02.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMurdock\FX\Materials\Debris\M_Camera_Small_Bolts.uasset
PROJECTILE COUNT SHOWN=20
ASSET D:\VEIL-OMNI\Content\ParagonCountess\FX\Meshes\Shapes\SM_projectile_sphere.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Materials\Heroes\Greystone\Abilities\M_LeapAOE_Projectile_Wind_Rush.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Camps_Specific\Buff_Blue\M_SpitProjectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Energy\M_Mortar_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Fire\M_Fire_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Shockwaves\M_Projectile_Wind_Rush.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Trails\M_Burden_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Trails\M_Burden_Projectile_TwoSided_Inst.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Trails\M_Spit_Projectile_Trail.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Meshes\Liquid\SM_Pyro_Spit_Mesh_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Meshes\Shapes\SM_Burden_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Meshes\Shapes\SM_Tower_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Particles\Buffs\Buff_Blue\FX\P_Spit_Attack_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Particles\Minions\Dragon\FX\P_Dragon_Fireball_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Particles\Minions\Prime_Helix\Abilities\SpecialAttack1\FX\P_Prime_Helix_SpecialAttack1_Projectile.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMurdock\FX\Particles\Abilities\Primary\FX\P_PlasmaShot_Projectile_Trail_2.uasset
ASSET D:\VEIL-OMNI\Content\ParagonRevenant\FX\Materials\Heroes\Revenant\Skins\FrostKing\MI_Revenant_FrostKing_Projectile_Curl.uasset
ASSET D:\VEIL-OMNI\Content\ParagonRevenant\FX\Meshes\Heroes\Revenant\SM_Revenant_Projectile_01.uasset
ASSET D:\VEIL-OMNI\Content\ParagonRevenant\FX\Meshes\Heroes\Revenant\Skins\FrostKing\SM_Revenant_FrostKing_Projectile_Crystals.uasset
ASSET D:\VEIL-OMNI\Content\ParagonRevenant\FX\Meshes\Shapes\SM_Burden_Projectile.uasset
BEAM COUNT SHOWN=20
ASSET D:\VEIL-OMNI\Content\ParagonCountess\FX\Textures\Masks\T_Beam_Gradient_02.uasset
ASSET D:\VEIL-OMNI\Content\ParagonCountess\FX\Textures\Masks\T_NoisyBeam_M.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Materials\Heroes\Greystone\Abilities\M_Greystone_Ultimate_PlasmaBeam_Thin.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Materials\Heroes\Greystone\Abilities\M_Greystone_Ultimate_PlasmaBeam_Up.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Materials\Heroes\Greystone\Abilities\M_Greystone_Ultimate_PlasmaBeam_Yelo.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Textures\Energy\T_BeamMask_Proto_Electric.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Textures\Flares\T_RayBeams_Packed.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Textures\Masks\T_Beam_Gradient_02.uasset
ASSET D:\VEIL-OMNI\Content\ParagonGreystone\FX\Textures\Masks\T_NoisyBeam_M.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\MI_LevelUp_Beam_Chromatic_Shell.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_Beam_Glow.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_Buff_Red_MeleeImpact_LightBeams.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_LevelUp_Beam_Chromatic.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_PH_Beam.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_PH_Beam2.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_PortalStone_Beam.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_PortalStone_Beam_Stretch.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_PortalStone_PlasmaBeam.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_Prime_Beam.uasset
ASSET D:\VEIL-OMNI\Content\ParagonMinions\FX\Materials\Flares\M_RecallBeam_Stretch.uasset
LANCE COUNT SHOWN=0
PHI P553 VERDICT: ATTACK READ ABOVE
JOB 553 DONE

```
