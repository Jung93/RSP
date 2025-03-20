// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/RSP_AIController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NavigationSystem.h"

#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

ARSP_AIController::ARSP_AIController()
{
}

void ARSP_AIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	UBlackboardComponent* temp = Blackboard;
	if (UseBlackboard(_blackboard, temp))
	{
		if (RunBehaviorTree(_behaviorTree))
		{
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("BT failed"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BB failed"));
	}
}

void ARSP_AIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ARSP_AIController::RandMove()
{
	auto curPawn = GetPawn();

	if (curPawn->IsValidLowLevel() == false)
		return;

	auto navMesh = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	if (navMesh->IsValidLowLevel() == false)
		return;

	FNavLocation randLocation;

	if (navMesh->GetRandomPointInNavigableRadius(curPawn->GetActorLocation(), 500.0f, randLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, randLocation.Location);
	}
}
