// Gabriel Mosz All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"

#include "DebugHelper.h"
#include "GameplayTagContainer.h"
#include "Items/BaseWeapon.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InTagToRegister, ABaseWeapon* InWeaponToRegister, bool bRegisterAsCurrentEquip)
{
	checkf(!M_CharacterCarriedWeapons.Contains(InTagToRegister), TEXT("A weapon named %s ja comeu tua esposa"), *InTagToRegister.ToString());
	check(InWeaponToRegister);
	M_CharacterCarriedWeapons.Emplace(InTagToRegister, InWeaponToRegister);
	if (bRegisterAsCurrentEquip)
		CurrentEquippedWeaponTag = InTagToRegister;
	const FString string = FString::Printf(TEXT("Arma %s foi registrada com Tag %s"), *InWeaponToRegister->GetName() ,*InTagToRegister.ToString());
	Debug::Print(string);
}

ABaseWeapon* UPawnCombatComponent::GetCharacterWeaponFromTag(FGameplayTag InWeaponTagToGet) const
{
	if (ABaseWeapon* const* FoundWeapon = M_CharacterCarriedWeapons.Find(InWeaponTagToGet))
	{
		return *FoundWeapon;
	}
	return nullptr;
}

ABaseWeapon* UPawnCombatComponent::GetCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
		return nullptr;
	return GetCharacterWeaponFromTag(CurrentEquippedWeaponTag);
}
