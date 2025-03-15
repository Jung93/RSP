// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Character.h"

#include "RSP_Enemy.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ARSP_Enemy::ARSP_Enemy()
{
	
}

void ARSP_Enemy::Attack_Hit()
{
}

void ARSP_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

void ARSP_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
