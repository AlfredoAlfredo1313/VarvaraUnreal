// Gabriel Mosz All Rights Reserved


#include "AbilitySystem/BaseAbilitySystemComponent.h"

#include "DebugHelper.h"
#include "AbilitySystem/Abilities/VarvaraGameplayAbility.h"

void UBaseAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	for (FGameplayAbilitySpec AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTag(InInputTag)) continue;
		if (!TryActivateAbility(AbilitySpec.Handle))
		{
			Debug::Print("Foi nada");
		}
	}
}

void UBaseAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void UBaseAbilitySystemComponent::GrantVarvaraWeaponAbilities(const TArray<FVarvaraAbilitySet>& InWeaponAbilities,
	int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle)
{
	if (InWeaponAbilities.IsEmpty()) return;

	for (const FVarvaraAbilitySet AbilitySet : InWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;
		FGameplayAbilitySpec AbilitySpec((AbilitySet.AbilityToGrant));
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		OutGrantedAbilitySpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UBaseAbilitySystemComponent::RemoveGrantedWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandle)
{
	if (InGrantedAbilitySpecHandle.Num() == 0) return;
	for (FGameplayAbilitySpecHandle SpecHandle : InGrantedAbilitySpecHandle)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
		
	}
	InGrantedAbilitySpecHandle.Empty();
}
