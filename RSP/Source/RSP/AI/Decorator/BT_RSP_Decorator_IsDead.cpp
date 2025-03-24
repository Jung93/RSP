// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorator/BT_RSP_Decorator_IsDead.h"
#include "RSP_Character.h"
#include "AI/RSP_AIController.h"

bool UBT_RSP_Decorator_IsDead::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (!result)
		return false;

	auto curPawn = Cast<ARSP_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!curPawn->IsValidLowLevel())
		return false;

	return curPawn->IsDead();
}
