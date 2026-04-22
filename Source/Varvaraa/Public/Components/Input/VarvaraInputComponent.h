// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "VarvaraInputComponent.generated.h"

class UDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class VARVARAA_API UVarvaraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Callback);

	template<class UserObject, typename CallbackFunc>
	void BindNativeAbilityAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedCall, CallbackFunc InputReleasedCall);
	
};

template <class UserObject, typename CallbackFunc>
inline void UVarvaraInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Callback)
{
	checkf(InInputConfig, TEXT("Input config cagou"));
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Callback);
	}
}

template <class UserObject, typename CallbackFunc>
void UVarvaraInputComponent::BindNativeAbilityAction(const UDataAsset_InputConfig* InInputConfig,
	UserObject* ContextObject, CallbackFunc InputPressedCall, CallbackFunc InputReleasedCall)
{
	checkf(InInputConfig, TEXT("Input config cagou"));
	for (const FVarvaraInputConfig& AbilityInput : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInput.IsValid()) continue;
		BindAction(AbilityInput.InputAction, ETriggerEvent::Started, ContextObject, InputPressedCall, AbilityInput.InputTag);
		BindAction(AbilityInput.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedCall, AbilityInput.InputTag);
	}
}
