// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Service/BT_RSP_Service_FindEnemy.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"


#include "AI/RSP_AIController.h"
#include "RSP_Companion.h"
#include "RSP_Enemy.h"

#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"


void UBT_RSP_Service_FindEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto curPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (!curPawn->IsValidLowLevel())
		return;

	FVector pos = curPawn->GetActorLocation();
	float sphereRaidus = 700.0f;

	TArray<FOverlapResult> overlapResults;
	FCollisionQueryParams qParams(NAME_None, false, curPawn);

	bool result = GetWorld()->OverlapMultiByChannel(
		overlapResults,
		pos,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(sphereRaidus),
		qParams
	);

	DrawDebugSphere(GetWorld(), pos, sphereRaidus, 30, FColor::Green, false, 0.3f);

	if (!result)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Enemy")), nullptr);
		return;
	}
	else
	{
		for (auto& overlapResult : overlapResults)
		{
			auto enemy = Cast<ARSP_Enemy>(overlapResult.GetActor());

			if (enemy->IsValidLowLevel())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Enemy")), enemy);
				DrawDebugSphere(GetWorld(), pos, sphereRaidus, 30, FColor::Red, false, 0.3f);
				return;
			}
		}

		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Enemy")), nullptr);
		return;
	}

}
