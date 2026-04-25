// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/StartUpData/DataAsset_StartUpBase.h"
#include "DataAsset_VarvaraStartUpData.generated.h"

struct FVarvaraAbilitySet;
class UVarvaraGameplayAbility;



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
