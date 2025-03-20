// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RSP_AIController.generated.h"

UCLASS()
class RSP_API ARSP_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ARSP_AIController();

	virtual void OnPossess(APawn* pawn) override;
	virtual void OnUnPossess() override;

	UFUNCTION()
	void RandMove();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBlackboardData* _blackboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* _behaviorTree;

private:
	UPROPERTY()
	FTimerHandle _timerHandle;

};
