// Gabriel Mosz All Rights Reserved


#include "Characters/VarvaraCharacter.h"

#include "DebugHelper.h"

#include "VarvaraGamePlayTags.h"
#include "Components/Input/VarvaraInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Components/CapsuleComponent.h"
#include "Components/Combat/VarvaraCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpBase.h"

AVarvaraCharacter::AVarvaraCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.f, 90.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	CombatComponent = CreateDefaultSubobject<UVarvaraCombatComponent>(TEXT("CombatController"));
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 200.0f;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AVarvaraCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to InputConfigDataAsset"));
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	check(Subsystem);
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	UVarvaraInputComponent* VarvaraInputComponent = CastChecked<UVarvaraInputComponent>(PlayerInputComponent);
	VarvaraInputComponent->BindNativeInputAction(InputConfigDataAsset, VarvaraGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	VarvaraInputComponent->BindNativeInputAction(InputConfigDataAsset, VarvaraGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AVarvaraCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AVarvaraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVarvaraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveAbilitySystemComponent(AbilitySystemComponent);
		}
	}
}

void AVarvaraCharacter::Input_Move(const FInputActionValue& MoveInput)
{
	const FVector2D MovementVector = MoveInput.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	if (MovementVector.Y != 0.f)
	{
		/*
		 *Isso é o
			cameraForward = m_Camera.transform.forward;
			cameraRight = m_Camera.transform.right;
			cameraForward.y = 0f;
			cameraRight.y = 0f;
			cameraForward.Normalize();
			cameraRight.Normalize();
			Vector3 desiredDir = cameraForward * input.y + cameraRight * input.x;
		*/
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
		
	}
	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AVarvaraCharacter::Input_Look(const FInputActionValue& LookInput)
{
	/*
	 *	(x, y)
	 *  x -> Yaw
	 *	y -> Pitch
	 */
	const FVector2D LookVector = LookInput.Get<FVector2D>() * 1.5;
	if (LookVector.Y != 0.f)
	{
		AddControllerPitchInput(-LookVector.Y);
	}
	if (LookVector.X != 0.f)
	{
		AddControllerYawInput(LookVector.X);
	}
	
	
}
