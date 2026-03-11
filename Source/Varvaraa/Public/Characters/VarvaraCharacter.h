// Gabriel Mosz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "VarvaraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;

UCLASS()
class VARVARAA_API AVarvaraCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	public:
	AVarvaraCharacter();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	FVector LookEuler;
	
	void Input_Move(const FInputActionValue& MoveInput);
	void Input_Look(const FInputActionValue& LookInput);
#pragma endregion 
	
};
