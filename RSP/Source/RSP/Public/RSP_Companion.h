// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RSP_Character.h"
#include "RSP_Companion.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_Companion : public ARSP_Character
{
	GENERATED_BODY()
	
public:
	ARSP_Companion();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void Attack_Hit() override;
	void Attack();

	void TakeExp(class ARSP_Enemy* enemy);

};
