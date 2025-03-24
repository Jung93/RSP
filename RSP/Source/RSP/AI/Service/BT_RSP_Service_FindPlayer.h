// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BT_RSP_Service_FindPlayer.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API UBT_RSP_Service_FindPlayer : public UBTService
{
	GENERATED_BODY()
	
public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
