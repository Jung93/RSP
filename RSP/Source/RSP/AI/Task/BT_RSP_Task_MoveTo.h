// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BT_RSP_Task_MoveTo.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API UBT_RSP_Task_MoveTo : public UBTTask_MoveTo
{
	GENERATED_BODY()
	
public:

	UBT_RSP_Task_MoveTo();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};
