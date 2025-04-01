// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_PlayerController.h"
#include "RSP_Player.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
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
        if (userWidget) {
            FInputModeGameAndUI  inputMode;
            inputMode.SetWidgetToFocus(userWidget->TakeWidget());
            SetInputMode(inputMode);
            bShowMouseCursor = true;
            
            auto player = Cast<ARSP_Player>(pawn);
            if (player) {
                player->SetInvenOpen(true);
            }
            UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
            if (subSystem)
            {                
                subSystem->RemoveMappingContext(_inputMappingContext);                
                subSystem->AddMappingContext(_UIMappingContext, 1);
            }
        }
    }
}

void ARSP_PlayerController::HideUI()
{
    auto pawn = GetPawn();
    if (pawn) {
        FInputModeGameOnly inputMode;
        SetInputMode(inputMode);
        bShowMouseCursor = false;

        auto player = Cast<ARSP_Player>(pawn);
        if (player) {
            player->SetInvenOpen(false);
        }
        UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
        if (subSystem)
        {
            subSystem->RemoveMappingContext(_UIMappingContext);
            subSystem->AddMappingContext(_inputMappingContext, 0);
        }
    }
}

