// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
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
	FVarvaraWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedWeaponAbilities(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedWeaponAbilities() const;
	
private:
	TArray<FGameplayAbilitySpecHandle> OutGrantedAbilitySpecHandle;
};
