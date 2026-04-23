// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Anim/BaseAnimInstance.h"
#include "VarvaraLinkedAnimLayer.generated.h"

/**
 * 
 */
class UVarvaraAnimInstance;
UCLASS()
class VARVARAA_API UVarvaraLinkedAnimLayer : public UBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UVarvaraAnimInstance* GetVarvaraAnimInstance() const;
	
};
