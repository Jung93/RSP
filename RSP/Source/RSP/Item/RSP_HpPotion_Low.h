// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RSP_Item.h"
#include "RSP_HpPotion_Low.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_HpPotion_Low : public ARSP_Item
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void ActivateItemEffect(AActor* actor) override;
protected:
	FString name = TEXT("HpPotion_Low");

};
