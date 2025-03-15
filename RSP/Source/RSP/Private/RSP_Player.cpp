// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Character.h"

#include "RSP_Player.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ARSP_Player::ARSP_Player()
{
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));
	_springArm->SetRelativeLocation(FVector(-50, 0, 88));

	
}

void ARSP_Player::Attack_Hit()
{
}

void ARSP_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARSP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent) {
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &ARSP_Player::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &ARSP_Player::Look);
	}
}

void ARSP_Player::Move(const FInputActionValue& value)
{
	//if (_isAttack) { return; }

	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		if (moveVector.Length() > 0.01f) {
			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();

			_vertical = moveVector.Y;
			_horizontal = moveVector.X;

			AddMovementInput(forWard, moveVector.Y * 10);
			AddMovementInput(right, moveVector.X * 10); //10은 임시값 스탯컴포넌트에서 받아와야함 
		}
	}
}

void ARSP_Player::Look(const FInputActionValue& value)
{
	//if (_isInvenOpen) { return; }
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
	}
}

void ARSP_Player::JumpA(const FInputActionValue& value)
{
}

void ARSP_Player::Attack(const FInputActionValue& value)
{
}
