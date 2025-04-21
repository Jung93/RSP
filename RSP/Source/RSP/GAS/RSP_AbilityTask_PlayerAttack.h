// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/RSP_AbilityTask.h"
#include "RSP_AbilityTask_PlayerAttack.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_AbilityTask_PlayerAttack : public URSP_AbilityTask
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Tasks", meta = (DisplayName = "Play Combo Montage", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility"))
	static URSP_AbilityTask_PlayerAttack* PlayerAttack(
		UGameplayAbility* OwningAbility,
		FName TaskInstanceName,
		UAnimMontage* MontageToPlay,
		int32 SectionNum,
		float Rate = 1.0f);

	virtual void Activate() override;
protected:
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
