// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RSP_Item.h"
#include "RSP_HpPotion_High.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_HpPotion_High : public ARSP_Item
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void ActivateItemEffect(AActor* actor);
protected:
	FString name = TEXT("HpPotion_High");
};
