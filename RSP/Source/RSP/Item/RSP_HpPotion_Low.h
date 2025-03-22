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
	virtual void PostInitializeComponents() override;

	virtual void OnOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult) override;

protected:
	FString name = TEXT("HpPotion_Low");

};
