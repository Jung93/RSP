// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_AttackEnemy.h"
#include "AI/RSP_AIController.h"
#include "RSP_Companion.h"
#include "RSP_Enemy.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UBT_RSP_Task_AttackEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto result = Super::ExecuteTask(OwnerComp, NodeMemory);
	auto curPawn = Cast<ARSP_Companion>(OwnerComp.GetAIOwner()->GetPawn());


	if (!curPawn->IsValidLowLevel() || curPawn->IsAttacking())
		return result;

	auto enemy = Cast<ARSP_Enemy>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Enemy"))));

	if (!enemy->IsValidLowLevel())
		return EBTNodeResult::Failed;

	auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), enemy->GetActorLocation());

	curPawn->SetActorRotation(quat);
	curPawn->Attack();

	return EBTNodeResult::Succeeded;
}
