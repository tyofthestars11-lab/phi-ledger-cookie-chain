// OMNI RPG: PATH OF LIGHT - WARDEN PRIME implementation.
#include "AI/OMNIWardenPrime.h"

#include "GameFramework/CharacterMovementComponent.h"

AOMNIWardenPrime::AOMNIWardenPrime()
{
	// The duel: twelve times a street machine's frame, a heavier hand,
	// a longer eye. Spawned at 1.7 scale by the quest system.
	MaxHealth = 900.f;
	Health = MaxHealth;
	WeaponDamage = 18.f;
	SightRange = 3200.f;
	AttackRange = 1600.f;
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}
