// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "VarvaraCombatComponent.generated.h"

class AVarvaraWeapon;
/**
 * 
 */
UCLASS()
class VARVARAA_API UVarvaraCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	AVarvaraWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;	
};
