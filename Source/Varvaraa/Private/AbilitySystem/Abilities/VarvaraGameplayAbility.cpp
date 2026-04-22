// Gabriel Mosz All Rights Reserved


#include "AbilitySystem/Abilities/VarvaraGameplayAbility.h"

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
		CachedVarvaraController = Cast<AVarvaraController>(GetActorInfo().AvatarActor);
	}
	return CachedVarvaraController.IsValid()? CachedVarvaraController.Get() : nullptr;
}

UVarvaraCombatComponent* UVarvaraGameplayAbility::GetCombatComponentFromActorInfo()
{
	return GetVarvaraCharacterFromActorInfo()->GetCombatController();
}
