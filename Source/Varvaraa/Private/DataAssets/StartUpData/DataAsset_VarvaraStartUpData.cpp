// Gabriel Mosz All Rights Reserved

#include "DataAssets/StartUpData/DataAsset_VarvaraStartUpData.h"
#include "AbilitySystem/Abilities/VarvaraGameplayAbility.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "VarvaraTypes/VarvaraStructTypes.h"

void UDataAsset_VarvaraStartUpData::GiveAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveAbilitySystemComponent(InASCToGive, ApplyLevel);
	for (FVarvaraAbilitySet AbilitySet : StartUpAbilitySets)
	{
		if (!AbilitySet.IsValid())
			return;
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}



