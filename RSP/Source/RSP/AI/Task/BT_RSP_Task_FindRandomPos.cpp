// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_FindRandomPos.h"

#include "AI/RSP_AIController.h"
#include "NavigationSystem.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBT_RSP_Task_FindRandomPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto curPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (!curPawn->IsValidLowLevel())
		return EBTNodeResult::Type();

	FVector pos = curPawn->GetActorLocation();

	auto nav = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	if (!nav->IsValidLowLevel())
		return EBTNodeResult::Type::Failed;

	FNavLocation randomLocation;
	if (nav->GetRandomPointInNavigableRadius(pos, 300.0f, randomLocation))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandomPos")), randomLocation.Location);

		return EBTNodeResult::Type::Succeeded;
	}

	return EBTNodeResult::Type::Failed;
}
