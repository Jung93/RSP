// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void ARSP_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (subSystem) {
		subSystem->AddMappingContext(_inputMappingContext, 0);
	}
}

void ARSP_PlayerController::ShowUI()
{
	bShowMouseCursor = true;
}

void ARSP_PlayerController::HideUI()
{
	bShowMouseCursor = false;
}
