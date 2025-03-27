// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorator/BT_RSP_Decorator_IsComAttackable.h"
#include "RSP_Companion.h"
#include "RSP_Enemy.h"

#include "AI/RSP_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UBT_RSP_Decorator_IsComAttackable::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (!result)
		return false;

	auto curPawn = Cast<ARSP_Companion>(OwnerComp.GetAIOwner()->GetPawn());
	auto enemy = Cast<ARSP_Enemy>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Enemy"))));

	if (!curPawn->IsValidLowLevel() || !enemy->IsValidLowLevel())
		return false;

	float distance = enemy->GetDistanceTo(curPawn);
	static float LastValidTime = 0.0f;

	if (distance < curPawn->GetAttackRange())
	{
		LastValidTime = GetWorld()->GetTimeSeconds();
		return true;
	}

	if (GetWorld()->GetTimeSeconds() - LastValidTime < 1.0f)
	{
		return true;
	}

	return false;
}
