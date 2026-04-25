// Gabriel Mosz All Rights Reserved


#include "VarvaraTypes/VarvaraStructTypes.h"

#include "AbilitySystem/Abilities/VarvaraGameplayAbility.h"

bool FVarvaraAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
