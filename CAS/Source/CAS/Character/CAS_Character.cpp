// Fill out your copyright notice in the Description page of Project Settings.

#include "CASCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "GAS/CAS_AbilitySystemComponent.h"
#include "Character/CAS_PlayerState.h"
#include "GAS/CAS_GamePlayTag.h"

// Sets default values
ACAS_Character::ACAS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ACAS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACAS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACAS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACAS_Character::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ACAS_Character::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACAS_Character::GiveDefaultAbilities()
{
	if (!AbilitySystemComponent) {
		return;
	}
	if (!HasAuthority()) {
		return;
	}
	for (TSubclassOf<UGameplayAbility> abilityClass : DefaultAbilities) {

		FGameplayAbilitySpec abilitySpec = FGameplayAbilitySpec(abilityClass, 1);
		AbilitySystemComponent->GiveAbility(abilitySpec);
	}
}

void ACAS_Character::AddAbilites()
{
	UCAS_AbilitySystemComponent* ASC = Cast<UCAS_AbilitySystemComponent>(AbilitySystemComponent);
	if (!ASC) {
		return;
	}
	ASC->AddCharacterAbilities(DefaultAbilities);
}

UAbilitySystemComponent* ACAS_Character::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACAS_Character::InitAbilitySystemComponent()
{
	ACAS_PlayerState* playerState = GetPlayerState<ACAS_PlayerState>();
	if (!playerState) { return; }

	AbilitySystemComponent = Cast<UCAS_AbilitySystemComponent>(playerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(playerState, this);
	AttributeSet = playerState->GetAttributeSet();
}

void ACAS_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilitySystemComponent();
	AddAbilites();
}


