// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BattleTestCharacterAnimInstance.generated.h"

class ACharacter;

/**
 * C++ data source for character animation blueprints.
 *
 * Gameplay and movement remain owned by ACharacter and CharacterMovement.
 * The animation blueprint reads these presentation-friendly values and only
 * decides which pose to display.
 */
UCLASS(Transient, Blueprintable)
class BATTLETEST_API UBattleTestCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	/** Horizontal world-space speed, ignoring vertical jump/fall velocity. */
	UPROPERTY(BlueprintReadOnly, Category = "Animation|Locomotion")
	float GroundSpeed = 0.0f;

	/** True while CharacterMovement is in its falling movement mode. */
	UPROPERTY(BlueprintReadOnly, Category = "Animation|Locomotion")
	bool bIsFalling = false;

	/** True while the character is supplying movement acceleration. */
	UPROPERTY(BlueprintReadOnly, Category = "Animation|Locomotion")
	bool bIsAccelerating = false;

	/** Convenient state-machine condition for leaving the idle pose. */
	UPROPERTY(BlueprintReadOnly, Category = "Animation|Locomotion")
	bool bShouldMove = false;

private:
	/** Cached owner; transient because runtime references must not be serialized. */
	UPROPERTY(Transient)
	TObjectPtr<ACharacter> OwningCharacter;
};
