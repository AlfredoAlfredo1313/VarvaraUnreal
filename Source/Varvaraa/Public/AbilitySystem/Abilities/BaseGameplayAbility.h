// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

UENUM(BlueprintType)
enum EAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**		
 * 
 */
UCLASS()
class VARVARAA_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~Begin GameplayAbility Interface
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	//~End GameplayAbility Interface
	//Teste
	
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TEnumAsByte<EAbilityActivationPolicy> ActivationPolicy = OnTriggered;
	
};
