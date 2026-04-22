// Gabriel Mosz All Rights Reserved


#include "AbilitySystem/BaseAbilitySystemComponent.h"

#include "DebugHelper.h"

void UBaseAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	for (FGameplayAbilitySpec AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTag(InInputTag)) continue;
		if (TryActivateAbility(AbilitySpec.Handle))
		{
			Debug::Print("Foi rapaziada");
		}
		else
		{
			Debug::Print("Foi nada");
		}
	}
}

void UBaseAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
