// Gabriel Mosz All Rights Reserved


#include "Anim/BaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/BaseCharacter.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());

	if (OwnerCharacter)
	{
		OwnerMovement = OwnerCharacter->GetCharacterMovement();
	}
}

void UBaseAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter || !OwnerMovement)
		return;
	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwnerMovement->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
