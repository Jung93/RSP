// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_AttackByBoss.h"

#include "AI/RSP_AIController.h"
#include "RSP_Boss.h"
#include "RSP_Player.h"
#include "RSP_Companion.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UBT_RSP_Task_AttackByBoss::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    auto result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto curPawn = Cast<ARSP_Boss>(OwnerComp.GetAIOwner()->GetPawn());

	if (!curPawn->IsValidLowLevel())
		return result;

    if (curPawn->IsAttacking())
        return result;

    auto player = Cast<ARSP_Player>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Player"))));
    auto companion = Cast<ARSP_Companion>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Companion"))));


    if (player->IsValidLowLevel())
    {
        auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), player->GetActorLocation());
        curPawn->SetActorRotation(quat);
        curPawn->Attack();

        return EBTNodeResult::Succeeded;
    }
    else if (companion->IsValidLowLevel())
    {
        auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), companion->GetActorLocation());
        curPawn->SetActorRotation(quat);
        curPawn->Attack();
        return EBTNodeResult::Succeeded;

    }

    return EBTNodeResult::Failed;

}
