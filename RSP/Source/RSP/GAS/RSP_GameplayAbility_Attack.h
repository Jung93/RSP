// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/RSP_GameplayAbility.h"
#include "RSP_GameplayAbility_Attack.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_GameplayAbility_Attack : public URSP_GameplayAbility
{
	GENERATED_BODY()
	
public:
	URSP_GameplayAbility_Attack();

protected:
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> AttackMontage;
};
