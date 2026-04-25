// Gabriel Mosz All Rights Reserved


#include "AbilitySystem/Abilities/VarvaraGameplayAbility.h"

#include "Anim/Hero/VarvaraAnimInstance.h"
#include "Characters/VarvaraCharacter.h"
#include "Controllers/VarvaraController.h"

AVarvaraCharacter* UVarvaraGameplayAbility::GetVarvaraCharacterFromActorInfo()
{
	if (!CachedVarvaraCharacter.IsValid())
	{
		CachedVarvaraCharacter = Cast<AVarvaraCharacter>(GetActorInfo().AvatarActor);
	}
	return CachedVarvaraCharacter.IsValid()? CachedVarvaraCharacter.Get() : nullptr;
}

AVarvaraController* UVarvaraGameplayAbility::GetVarvaraControllerFromActorInfo()
{
	if (!CachedVarvaraController.IsValid())
	{
		CachedVarvaraController = Cast<AVarvaraController>(GetActorInfo().PlayerController);
	}
	return CachedVarvaraController.IsValid()? CachedVarvaraController.Get() : nullptr;
}

UVarvaraCombatComponent* UVarvaraGameplayAbility::GetCombatComponentFromActorInfo()
{
	return GetVarvaraCharacterFromActorInfo()->GetCombatController();
}

UVarvaraAnimInstance* UVarvaraGameplayAbility::GetVarvaraAnimInstanceFromActorInfo() const
{
	return Cast<UVarvaraAnimInstance>(GetOwningComponentFromActorInfo()->GetAnimInstance());
}
