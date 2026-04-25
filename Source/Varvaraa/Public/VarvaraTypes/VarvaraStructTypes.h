// Gabriel Mosz All Rights Reserved

#pragma once
#include "GameplayTagContainer.h"

#include "VarvaraStructTypes.generated.h"

class UInputMappingContext;
class UVarvaraGameplayAbility;
class UVarvaraLinkedAnimLayer;

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

USTRUCT(BlueprintType)
struct FVarvaraWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UVarvaraLinkedAnimLayer> WeaponAnimLayerToLink;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FVarvaraAbilitySet> WeaponAbilitySet;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;
};