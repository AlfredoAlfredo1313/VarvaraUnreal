// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "VarvaraTypes/VarvaraStructTypes.h"
#include "BaseAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class VARVARAA_API UBaseAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "Abilities", meta = (ApplyLevel = "1"))
	void GrantVarvaraWeaponAbilities(const TArray<FVarvaraAbilitySet>& InWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void RemoveGrantedWeaponAbilities(UPARAM(Ref) TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandle);
	
	
	
};
