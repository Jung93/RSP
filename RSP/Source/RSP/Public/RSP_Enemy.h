// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RSP_Character.h"
#include "RSP_StatComponent.h"
#include "RSP_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_Enemy : public ARSP_Character
{
	GENERATED_BODY()
public:
	ARSP_Enemy();
	virtual void Attack_Hit() override;
	int32 GetExp() { return _statComponent->GetDropExp(); }
	int32 GetGold() { return _statComponent->GetDropGold(); }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
