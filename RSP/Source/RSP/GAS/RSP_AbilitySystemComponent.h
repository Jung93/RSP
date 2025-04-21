// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "RSP_AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void AddCharacterAbilities(const TArray<TSubclassOf<class UGameplayAbility>>& Abilities);
	TArray<FGameplayAbilitySpecHandle> SpecHandles;
	void ActivateAbility(const FGameplayTag& Tag);
private:
	FGameplayAbilitySpec* FindAbilitySpecByTag(const FGameplayTag& Tag);
};
