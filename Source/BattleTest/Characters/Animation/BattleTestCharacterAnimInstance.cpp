// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleTestCharacterAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBattleTestCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UBattleTestCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// The preview editor and pawn replacement can both temporarily leave the
	// animation instance without an owning character, so reacquire it safely.
	if (!IsValid(OwningCharacter))
	{
		OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
	}

	if (!IsValid(OwningCharacter))
	{
		GroundSpeed = 0.0f;
		bIsFalling = false;
		bIsAccelerating = false;
		bShouldMove = false;
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	const UCharacterMovementComponent* MovementComponent =
		OwningCharacter->GetCharacterMovement();

	if (!IsValid(MovementComponent))
	{
		bIsFalling = false;
		bIsAccelerating = false;
		bShouldMove = false;
		return;
	}

	bIsFalling = MovementComponent->IsFalling();
	bIsAccelerating = !MovementComponent->GetCurrentAcceleration().IsNearlyZero();
	bShouldMove = GroundSpeed > 3.0f && bIsAccelerating;
}
