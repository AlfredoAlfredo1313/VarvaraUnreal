// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpBase.generated.h"

class UBaseGameplayAbility;
class UBaseAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class VARVARAA_API UDataAsset_StartUpBase : public UDataAsset
{
	GENERATED_BODY()
	public:
	virtual void GiveAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UBaseGameplayAbility>> ActivateOnGivenAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UBaseGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UBaseGameplayAbility>>& InAbilitiesToGive, UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
