// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "RSP_AbilityTask_attack2.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_AbilityTask_attack2 : public UAbilityTask_PlayMontageAndWait
{
	GENERATED_BODY()
public:

protected:
	virtual void Activate() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> AttackMontage;
	UPROPERTY()
	TArray<FName> ComboSections;
	UPROPERTY()
	int32 SectionNum;
	UPROPERTY()
	float PlayRate = 1.0f; //기본속도
	UPROPERTY()
	int32 CurrentSectionIndex = 0;
};
