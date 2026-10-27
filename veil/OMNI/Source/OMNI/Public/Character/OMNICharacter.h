// OMNI: THE LAST SIGNAL - player character.
// Third-person movement, sprint, jump, dodge, aim + hitscan fire, health,
// interact trace. Enhanced Input throughout (UE 5.8).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OMNICharacter.generated.h"

class UCameraComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOMNIHealthChanged, float, NewHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOMNICharacterDied);

UENUM(BlueprintType)
enum class EOMNICombatState : uint8
{
	Exploring,
	Aiming,
	Dodging,
	Dead
};

UCLASS()
class OMNI_API AOMNICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOMNICharacter();

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	// ---- Health ----
	UPROPERTY(BlueprintAssignable, Category = "OMNI|Health")
	FOMNIHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Health")
	FOMNICharacterDied OnDied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Health")
	float Health = 100.f;

	UFUNCTION(BlueprintCallable, Category = "OMNI|Health")
	void Heal(float Amount);

	UFUNCTION(BlueprintPure, Category = "OMNI|Health")
	bool IsAlive() const { return Health > 0.f; }

	// ---- God Mode: on the menus, on the console, in the damage gate ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|GodMode")
	bool bGodMode = false;

	UFUNCTION(Exec, BlueprintCallable, Category = "OMNI|GodMode")
	void ToggleGodMode();

	UFUNCTION(BlueprintPure, Category = "OMNI|GodMode")
	bool IsGodMode() const { return bGodMode; }

	// ---- Combat ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Combat")
	EOMNICombatState CombatState = EOMNICombatState::Exploring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float WeaponDamage = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float WeaponRange = 6000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float FireCooldown = 0.22f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float DodgeDistance = 550.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Combat")
	float DodgeCooldown = 0.9f;

	// ---- Movement tuning ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float WalkSpeed = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float SprintSpeed = 750.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Movement")
	float AimWalkSpeed = 220.f;

protected:
	virtual void BeginPlay() override;

	// ---- Components ----
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	// ---- Enhanced Input assets (assign in BP_PlayerCharacter) ----
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OMNI|Input")
	TObjectPtr<UInputAction> InteractAction;

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

	bool bFirstPerson = false;
	void ToggleCameraMode();
	TObjectPtr<UStaticMeshComponent> RunnerBody;
	TObjectPtr<UStaticMeshComponent> RunnerVisor;

	void ApplySpeed();
};
