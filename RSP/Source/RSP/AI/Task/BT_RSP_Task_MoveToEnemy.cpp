// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_MoveToEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/RSP_AIController.h"

#include "RSP_Companion.h"
#include "RSP_Enemy.h"

#include "Kismet/KismetMathLibrary.h"

UBT_RSP_Task_MoveToEnemy::UBT_RSP_Task_MoveToEnemy()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBT_RSP_Task_MoveToEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto curPawn = Cast<ARSP_Companion>(OwnerComp.GetAIOwner()->GetPawn());
	auto enemy = Cast<ARSP_Enemy>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	if (!curPawn->IsValidLowLevel())
		return EBTNodeResult::Failed;

	if (enemy->IsValidLowLevel())
	{
		if (!curPawn->IsAttacking())
		{
			float distance = enemy->GetDistanceTo(curPawn);

			if (distance <= curPawn->GetAttackRange())
			{
				auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), enemy->GetActorLocation());
				curPawn->SetActorRotation(quat);
				curPawn->Attack();
			}
		}

	}

	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

void UBT_RSP_Task_MoveToEnemy::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto curPawn = Cast<ARSP_Companion>(OwnerComp.GetAIOwner()->GetPawn());
	auto enemy = Cast<ARSP_Enemy>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	if (!curPawn->IsValidLowLevel())
		return;

	if (enemy->IsValidLowLevel())
	{
		if (!curPawn->IsAttacking())
		{
			float distance = enemy->GetDistanceTo(curPawn);

			if (distance <= curPawn->GetAttackRange())
			{
				auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), enemy->GetActorLocation());
				curPawn->SetActorRotation(quat);
				curPawn->Attack();
			}
		}
	}

	return;
}
