// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RSP_Enemy.h"
#include "RSP_Boss.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_Boss : public ARSP_Enemy
{
	GENERATED_BODY()
	

public:
	ARSP_Boss();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
