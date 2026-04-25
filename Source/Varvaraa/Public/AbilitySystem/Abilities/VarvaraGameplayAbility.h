// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseGameplayAbility.h"
#include "VarvaraGameplayAbility.generated.h"

class AVarvaraController;
class UVarvaraCombatComponent;
class AVarvaraCharacter;
class UVarvaraAnimInstance;
/**
 * 
 */
UCLASS()
class VARVARAA_API UVarvaraGameplayAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()
public:	
	UFUNCTION(BlueprintPure, Category = "Abilities")
	AVarvaraCharacter* GetVarvaraCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Abilities")
	AVarvaraController* GetVarvaraControllerFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Abilities")
	UVarvaraCombatComponent* GetCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Abilities")
	UVarvaraAnimInstance* GetVarvaraAnimInstanceFromActorInfo() const;
private:
	TWeakObjectPtr<AVarvaraCharacter> CachedVarvaraCharacter;
	TWeakObjectPtr<AVarvaraController> CachedVarvaraController;
};
