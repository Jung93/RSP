// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_Attack.h"

#include "AI/RSP_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"

#include "Kismet/KismetMathLibrary.h"
#include "RSP_Enemy.h"
#include "RSP_Player.h"

EBTNodeResult::Type UBT_RSP_Task_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    auto result = Super::ExecuteTask(OwnerComp, NodeMemory);

    auto curPawn = Cast<ARSP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());

    if (!curPawn->IsValidLowLevel())
        return result;

    if (curPawn->IsAttacking())
        return result;

    auto player = Cast<ARSP_Player>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Player"))));

    if (!player->IsValidLowLevel())
        return EBTNodeResult::Failed;

    auto quat = UKismetMathLibrary::FindLookAtRotation(curPawn->GetActorLocation(), player->GetActorLocation());

    curPawn->SetActorRotation(quat);
    curPawn->Attack();

    return EBTNodeResult::Succeeded;
}
