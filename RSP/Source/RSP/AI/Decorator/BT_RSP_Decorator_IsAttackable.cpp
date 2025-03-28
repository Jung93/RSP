// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorator/BT_RSP_Decorator_IsAttackable.h"
#include "AI/RSP_AIController.h"
#include "RSP_Player.h"
#include "RSP_Enemy.h"
#include "RSP_Companion.h"

#include "BehaviorTree/BlackboardComponent.h"
bool UBT_RSP_Decorator_IsAttackable::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (!result)
		return false;

	auto curPawn = Cast<ARSP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	auto player = Cast<ARSP_Player>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Player"))));
	auto companion = Cast<ARSP_Companion>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Companion"))));

	if (!curPawn->IsValidLowLevel())
		return false;


	if (player->IsValidLowLevel())
	{
		float distance = player->GetDistanceTo(curPawn);

		return distance <= curPawn->GetAttackRange();

	}
	else if (companion->IsValidLowLevel())
	{
		float distance = companion->GetDistanceTo(curPawn);
		return distance <= curPawn->GetAttackRange();
	}

	return false;
}

