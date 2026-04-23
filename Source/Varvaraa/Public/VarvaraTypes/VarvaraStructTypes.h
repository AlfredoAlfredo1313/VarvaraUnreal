// Gabriel Mosz All Rights Reserved

#pragma once

#include "VarvaraStructTypes.generated.h"

class UVarvaraLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UVarvaraLinkedAnimLayer> WeaponAnimLayerToLink;
};