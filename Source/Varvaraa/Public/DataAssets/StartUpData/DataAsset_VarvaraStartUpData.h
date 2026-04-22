// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/StartUpData/DataAsset_StartUpBase.h"
#include "DataAsset_VarvaraStartUpData.generated.h"

class UVarvaraGameplayAbility;

USTRUCT(BlueprintType)
struct FVarvaraAbilitySet
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UVarvaraGameplayAbility> AbilityToGrant;

	bool IsValid () const;
};

/**
 * 
 */
UCLASS()
class VARVARAA_API UDataAsset_VarvaraStartUpData : public UDataAsset_StartUpBase
{
	GENERATED_BODY()
	private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FVarvaraAbilitySet> StartUpAbilitySets;


	virtual void GiveAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel) override;
};
