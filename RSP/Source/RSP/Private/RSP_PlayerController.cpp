// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"

void ARSP_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraManager->ViewPitchMin = -30.0f; 
	PlayerCameraManager->ViewPitchMax = 30.0f;

	UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (subSystem) {
		subSystem->AddMappingContext(_inputMappingContext, 0);
	}
}

void ARSP_PlayerController::ShowUI(UUserWidget* userWidget)
{
	auto pawn = GetPawn();
	if (pawn) {
		pawn->DisableInput(this);

		if (userWidget) {
			FInputModeUIOnly inputMode;
			inputMode.SetWidgetToFocus(userWidget->TakeWidget());
			inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(inputMode);

			bShowMouseCursor = true;
		}
	}
	//PlayerCameraManager->ViewPitchMin = -10.0f;
	//PlayerCameraManager->ViewPitchMax = 10.0f;

	//PlayerCameraManager->ViewYawMin = -90.0f;
	//PlayerCameraManager->ViewYawMax = 90.0f;
}

void ARSP_PlayerController::HideUI()
{
	auto pawn = GetPawn();
	if (pawn) {
		pawn->EnableInput(this);
		FInputModeGameOnly inputMode;
		SetInputMode(inputMode);

		bShowMouseCursor = false;
	}
	//PlayerCameraManager->ViewPitchMin = -30.0f;
	//PlayerCameraManager->ViewPitchMax = 30.0f;

	//PlayerCameraManager->ViewYawMin = -359.0f;
	//PlayerCameraManager->ViewYawMax = 359.0f;
}
