// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_MoveTo.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/RSP_AIController.h"

#include "RSP_Player.h"
#include "RSP_Enemy.h"
#include "RSP_Companion.h"
#include "RSP_Character.h"

#include "Kismet/KismetMathLibrary.h"

UBT_RSP_Task_MoveTo::UBT_RSP_Task_MoveTo()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBT_RSP_Task_MoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto curPawn = Cast<ARSP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	auto character = Cast<ARSP_Character>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	if (!curPawn->IsValidLowLevel())
		return EBTNodeResult::Failed;

	if (character->IsValidLowLevel())
	{
		if (!curPawn->IsAttacking())
		{
			float distance = character->GetDistanceTo(curPawn);

			if (distance <= curPawn->GetAttackRange())
			{
				auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), character->GetActorLocation());
				curPawn->SetActorRotation(quat);
				curPawn->Attack();
			}
		}

	}

	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

void UBT_RSP_Task_MoveTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto curPawn = Cast<ARSP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	auto character = Cast<ARSP_Character>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	if (!curPawn->IsValidLowLevel())
		return;

	if (character->IsValidLowLevel())
	{
		if (!curPawn->IsAttacking())
		{
			float distance = character->GetDistanceTo(curPawn);

			if (distance <= curPawn->GetAttackRange())
			{
				auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), character->GetActorLocation());
				curPawn->SetActorRotation(quat);
				curPawn->Attack();
			}
		}
	}

	return;
}
