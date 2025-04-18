// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "RSP_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_PlayerState : public APlayerState , public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ARSP_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<class URSP_AbilitySystemComponent> AbilitySystemComponent;
};
