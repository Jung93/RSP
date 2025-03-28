// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/BT_RSP_Service_CheckRange.h"
#include "AI/RSP_AIController.h"
#include "RSP_Enemy.h"
#include "RSP_Player.h"
#include "RSP_Companion.h"

#include "BehaviorTree/BlackboardComponent.h"

void UBT_RSP_Service_CheckRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto curPawn = Cast<ARSP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	auto player = Cast<ARSP_Player>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Player"))));
	auto companion = Cast<ARSP_Companion>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Companion"))));

	if (!curPawn->IsValidLowLevel())
		return;

	float distance = 0.0;
	if (player->IsValidLowLevel())
	{
		distance = player->GetDistanceTo(curPawn);

		if (distance <= curPawn->GetAttackRange())
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName(TEXT("IsAttackable")), true);
			return;
		}

		OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName(TEXT("IsAttackable")), false);
		return;
	}
	else if (companion->IsValidLowLevel())
	{
		distance = companion->GetDistanceTo(curPawn);
		if (distance <= curPawn->GetAttackRange())
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName(TEXT("IsAttackable")), true);
			return;
		}

		OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName(TEXT("IsAttackable")), false);
		return;
	}


}
