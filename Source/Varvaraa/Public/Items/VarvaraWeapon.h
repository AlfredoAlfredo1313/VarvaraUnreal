// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseWeapon.h"
#include "VarvaraTypes/VarvaraStructTypes.h"
#include "VarvaraWeapon.generated.h"
/**
 * 
 */
UCLASS()
class VARVARAA_API AVarvaraWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FWarriorHeroWeaponData HeroWeaponData;
};
