// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Anim/CharacterAnimInstance.h"
#include "Characters/VarvaraCharacter.h"
#include "VarvaraAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class VARVARAA_API UVarvaraAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	AVarvaraCharacter* VarvaraCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldRelax;
	
	float IdleElapsedTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxThreshold = 10;
};
		