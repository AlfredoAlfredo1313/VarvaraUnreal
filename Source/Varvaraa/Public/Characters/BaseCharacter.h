// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;
class UBaseAbilitySystemComponent;

UCLASS()
class VARVARAA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBaseAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBaseAttributeSet* AttributeSet; 

public:
	FORCEINLINE UBaseAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }
	FORCEINLINE UBaseAttributeSet* GetAttributeSet() const { return AttributeSet; }
};
