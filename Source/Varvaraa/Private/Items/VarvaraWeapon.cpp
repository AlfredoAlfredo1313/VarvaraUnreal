// Gabriel Mosz All Rights Reserved


#include "Items/VarvaraWeapon.h"

void AVarvaraWeapon::AssignGrantedWeaponAbilities(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	OutGrantedAbilitySpecHandle = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AVarvaraWeapon::GetGrantedWeaponAbilities() const
{
	return OutGrantedAbilitySpecHandle;
}
