// Gabriel Mosz All Rights Reserved


#include "Components/Combat/VarvaraCombatComponent.h"

#include "Items/VarvaraWeapon.h"

AVarvaraWeapon* UVarvaraCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return  Cast<AVarvaraWeapon>(GetCharacterWeaponFromTag(InWeaponTag));
}
