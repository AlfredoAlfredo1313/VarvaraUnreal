// Gabriel Mosz All Rights Reserved


#include "Anim/Hero/VarvaraAnimInstance.h"

void UVarvaraAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwnerCharacter)
	{
		VarvaraCharacter = Cast<AVarvaraCharacter>(OwnerCharacter);
	}
}

void UVarvaraAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bNeverRelax)
	{
		if (IdleElapsedTime>0.1)
			IdleElapsedTime=0;
		return;
	}
	if (bHasAcceleration)
	{
		if (bShouldRelax)
		{
			IdleElapsedTime = 0;
			bShouldRelax = false;
		}
		return;
	}
	IdleElapsedTime += DeltaSeconds;
	if (IdleElapsedTime >= EnterRelaxThreshold && !bShouldRelax)
		bShouldRelax = true;
}


