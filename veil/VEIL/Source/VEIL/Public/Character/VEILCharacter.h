// VEIL: THE LAST SIGNAL - player character.
// Third-person movement, sprint, jump, dodge, aim + hitscan fire, health,
// interact trace. Enhanced Input throughout (UE 5.8).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VEILCharacter.generated.h"

class UCameraComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class USkeletalMesh;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVEILHealthChanged, float, NewHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVEILCharacterDied);

UENUM(BlueprintType)
enum class EVEILCombatState : uint8
{
	Exploring,
	Aiming,
	Dodging,
	Dead
};

UCLASS()
class VEIL_API AVEILCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AVEILCharacter();
	/** Incremented as the first act of Tick - the controller reads it
	 *  to prove whether Tick is ever entered. */
	int32 PhiTickEntryCount = 0;

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	// ---- Health ----
	UPROPERTY(BlueprintAssignable, Category = "VEIL|Health")
	FVEILHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Health")
	FVEILCharacterDied OnDied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Health")
	float Health = 100.f;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Health")
	void Heal(float Amount);

	UFUNCTION(BlueprintPure, Category = "VEIL|Health")
	bool IsAlive() const { return Health > 0.f; }

	// ---- God Mode: on the menus, on the console, in the damage gate ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|GodMode")
	bool bGodMode = false;

	UFUNCTION(Exec, BlueprintCallable, Category = "VEIL|GodMode")
	void ToggleGodMode();

	UFUNCTION(BlueprintPure, Category = "VEIL|GodMode")
	bool IsGodMode() const { return bGodMode; }

	// ---- Combat ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Combat")
	EVEILCombatState CombatState = EVEILCombatState::Exploring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float WeaponDamage = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float WeaponRange = 6000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float FireCooldown = 0.22f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float DodgeDistance = 550.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float DodgeCooldown = 0.9f;

	// ---- Swing + Lance Bolt (VEIL OMNI whole, 2026-10-31) ----
	// Fire() is the lance bolt (hitscan, WeaponDamage, WeaponRange).
	// Swing() is the close melee: Echo Blade / Signal Lance swing,
	// short arc in front of the runner, no projectile asset needed.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float SwingDamage = 35.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float SwingRange = 260.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Combat")
	float SwingCooldown = 0.45f;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Combat")
	void Swing();

	UFUNCTION(BlueprintCallable, Category = "VEIL|Combat")
	void LanceBolt();

	// ---- MetaHuman body (VEIL OMNI, 2026-10-31) ----
	// This is the PLAYER BODY assignment path, not a clothing path.
	// Assign in BP_PlayerCharacter ONLY an assembled MetaHuman body
	// mesh, e.g. a mesh under /Game/MetaHumans/<Name>/Body/.
	// Buff_Black / Buff_Blue / Buff_* are Skeletal Clothing in the
	// MetaHuman Manager (photo 210), NOT a body: assigning a Buff
	// here is not a player character, and a Buff that is still
	// "Asset has not been verified" (0 B) is not a playable body.
	// If this is left empty, AssignMetaHumanBody() does nothing and
	// the Countess mesh (constructor) / primitive runner (fallback)
	// stands, exactly as before. Nothing here verifies, packages,
	// downloads, or assembles a MetaHuman on its own.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|MetaHuman")
	TObjectPtr<USkeletalMesh> MetaHumanBodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|MetaHuman")
	TSubclassOf<UAnimInstance> MetaHumanAnimBlueprintClass;

	UFUNCTION(BlueprintCallable, Category = "VEIL|MetaHuman")
	void AssignMetaHumanBody();

	// ---- Movement tuning ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float WalkSpeed = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float SprintSpeed = 750.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Movement")
	float AimWalkSpeed = 220.f;

protected:
	virtual void BeginPlay() override;

	// ---- Components ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	// ---- Enhanced Input assets (assign in BP_PlayerCharacter) ----
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VEIL|Input")
	TObjectPtr<UInputAction> SwingAction;

	// ---- Input handlers ----
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
	void DoDodge();
	void StartAim();
	void StopAim();
	void Fire();
	void Interact();
	void OnSwingInput();

private:
	/** If no Input assets are assigned in the Blueprint, the game builds its
	 *  own mapping in code: WASD + mouse AND a full Xbox controller map.
	 *  Either way, both control schemes are live from the first frame. */
	void BuildFallbackInput();

	UPROPERTY()
	TObjectPtr<UInputMappingContext> BuiltMappingContext;

	UPROPERTY()
	TArray<TObjectPtr<UInputAction>> BuiltActions;

	bool bSprinting = false;
	bool bAiming = false;
	float LastFireTime = -100.f;
	float LastDodgeTime = -100.f;
	float LastSwingTime = -100.f;

	bool bFirstPerson = false;
	void ToggleCameraMode();
	TObjectPtr<UStaticMeshComponent> RunnerBody;
	TObjectPtr<UStaticMeshComponent> RunnerVisor;

	void ApplySpeed();
};
