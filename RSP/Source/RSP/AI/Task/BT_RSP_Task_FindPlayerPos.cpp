// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BT_RSP_Task_FindPlayerPos.h"

#include "AI/RSP_AIController.h"
#include "NavigationSystem.h"

#include "RSP_Companion.h"
#include "RSP_Player.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBT_RSP_Task_FindPlayerPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto curPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (!curPawn->IsValidLowLevel())
		return EBTNodeResult::Type();

	FVector pos = curPawn->GetActorLocation();

	auto player = Cast<ARSP_Player>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Player"))));

	if (!player->IsValidLowLevel())
		return EBTNodeResult::Type::Failed;

	FVector playerLocation = player->GetActorLocation();

	float stopDistance = 400.0f;
	FVector targetLocation = FVector(
		playerLocation.X + FMath::RandRange(-200.0f, 200.0f),
		playerLocation.Y + FMath::RandRange(-200.0f, 200.0f),
		playerLocation.Z
	);

	float DistanceSquared = FVector::DistSquared(pos, playerLocation);

	if (DistanceSquared > FMath::Square(stopDistance))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandomPos")), targetLocation);
		return EBTNodeResult::Type::Succeeded;
	}
	else
	{
		return EBTNodeResult::Type::Failed; 
	}

}
