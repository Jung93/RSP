// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/RSP_InvenComponent.h"
#include "RSP_StoreComponent.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_StoreComponent : public URSP_InvenComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	URSP_StoreComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

};
