// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionsComponentBase.h"
#include "PawnCombatComponent.generated.h"

struct FGameplayTag;
class ABaseWeapon;
/**
 * 
 */
UCLASS()
class VARVARAA_API UPawnCombatComponent : public UPawnExtensionsComponentBase
{
	GENERATED_BODY()

	private: 
		TMap<FGameplayTag, ABaseWeapon*> M_CharacterCarriedWeapons;
		
	public:
		UFUNCTION(BlueprintCallable, Category = "Combat")
		void RegisterSpawnedWeapon(FGameplayTag InTagToRegister, ABaseWeapon* InWeaponToRegister, bool bRegisterAsCurrentEquip);

		UFUNCTION(BlueprintCallable, Category = "Combat")
		ABaseWeapon*  GetCharacterWeaponFromTag(FGameplayTag InTag) const;

		UPROPERTY(BlueprintReadWrite, Category = "Combat")
		FGameplayTag CurrentEquippedWeaponTag;

		UFUNCTION(BlueprintCallable, Category = "Combat")
		ABaseWeapon* GetCurrentEquippedWeapon() const;

	
	
};
